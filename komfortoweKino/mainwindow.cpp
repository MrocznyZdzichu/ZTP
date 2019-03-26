#include "mainwindow.h"
#include "ui_mainwindow.h"

#define tempPlot this->ui->widget
#define humPlot this->ui->widget_2
#define co2Plot this->ui->widget_3
#define textBox this->ui->textBrowser
#define table this->ui->tableWidget
#define powerEdit this->ui->lineEdit

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->ui->pushButton_3->setDisabled(1);
    table->setRowCount(0);
    table->setColumnCount(2);

}

MainWindow::~MainWindow()
{
    delete ui;
}

double* MainWindow::axisLimits(QVector<double> xData, QVector<double> yData)
{
    double *limits;
    limits = new double [4];
    limits[0] = *std::min_element(xData.begin(), xData.end());
    limits[1] = *std::max_element(xData.begin(), xData.end());
    limits[2] = *std::min_element(yData.begin(), yData.end());
    limits[3] = *std::max_element(yData.begin(), yData.end());

    return limits;
}

void MainWindow::plotTemperature(QVector<double> xData, QVector<double> yData)
{
    if (tempPlot->graphCount() < 1)
        tempPlot->addGraph(0);

    double* limits = this->axisLimits(xData, yData);
    tempPlot->xAxis->setLabel("time");
    tempPlot->yAxis->setLabel("temperature");

    tempPlot->xAxis->setRange(limits[0], limits[1]);
    tempPlot->yAxis->setRange(limits[2], limits[3]);

    tempPlot->graph(0)->setData(xData, yData);
    tempPlot->replot();
}

void MainWindow::plotHumidity(QVector<double> xData, QVector<double> yData)
{
    if (humPlot->graphCount() < 1)
        humPlot->addGraph(0);

    double* limits = this->axisLimits(xData, yData);
    humPlot->xAxis->setLabel("time");
    humPlot->yAxis->setLabel("humidity");

    tempPlot->xAxis->setRange(limits[0], limits[1]);
    tempPlot->yAxis->setRange(limits[2], limits[3]);

    humPlot->graph(0)->setData(xData, yData);
    humPlot->replot();
}

void MainWindow::plotCO2(QVector<double> xData, QVector<double> yData)
{
    if (co2Plot->graphCount() < 1)
        co2Plot->addGraph(0);

    double* limits = this->axisLimits(xData, yData);
    co2Plot->xAxis->setLabel("time");
    co2Plot->yAxis->setLabel("CO2 concentration");

    tempPlot->xAxis->setRange(limits[0], limits[1]);
    tempPlot->yAxis->setRange(limits[2], limits[3]);

    co2Plot->graph(0)->setData(xData, yData);
    co2Plot->replot();
}

void MainWindow::printComm(QString text)
{
    textBox->clear();
    textBox->setText(text);
}

void MainWindow::on_pushButton_2_clicked()
{
    QString power = powerEdit->text();
    QString mode = this->ui->comboBox->currentText();

    if (power == "")
    {
        textBox->setText("Proszę podać moc jednostki");
        return;
    }

    if (!this->isTextNumeric(power) && power[0] != '-')
    {
        textBox->setText("Moc jednostki musi być numeryczna");
        return;
    }

    if (power.toDouble() <= 0)
    {
        textBox->setText("Moc jednostko powinna być dodatnia");
        return;
    }

    textBox->clear();
    powerEdit->clear();

    int newRowNumber = table->rowCount();

    table->setRowCount(newRowNumber+1);
    table->setItem(newRowNumber, 0, new QTableWidgetItem(mode));
    table->setItem(newRowNumber, 1, new QTableWidgetItem(power));

    if (!this->ui->pushButton_3->isEnabled())
        this->ui->pushButton_3->setEnabled(1);

}

bool MainWindow::isTextNumeric(QString text)
{
    for (auto character : text)
    {
        if (!character.isDigit())
            return false;
    }
    return true;
}
