#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Interface.h"

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

    this->ui->lineEdit_2->setText("0");
    this->ui->lineEdit_3->setText("0");
    this->ui->lineEdit_4->setText("0");
    this->ui->lineEdit_5->setText("0");
    this->ui->lineEdit_6->setText("0");
    this->ui->lineEdit_7->setText("0");
    this->ui->lineEdit_8->setText("0");
    this->ui->lineEdit_9->setText("0");
    this->ui->pushButton_4->setEnabled(0);
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
        textBox->setText("Moc jednostki powinna być dodatnia");
        return;
    }

    textBox->clear();

    QTableWidgetItem *powerItem = new QTableWidgetItem(power);
    powerItem->setFlags(powerItem->flags() ^ Qt::ItemIsEditable);
    powerEdit->clear();

    QTableWidgetItem* modeItem = new QTableWidgetItem(mode);
    modeItem->setFlags(modeItem->flags() ^ Qt::ItemIsEditable);

    int newRowNumber = table->rowCount();
    table->setRowCount(newRowNumber+1);

    table->setItem(newRowNumber, 0, modeItem);
    table->setItem(newRowNumber, 1, powerItem);

    if (!this->ui->pushButton_3->isEnabled())
        this->ui->pushButton_3->setEnabled(1);

}

bool MainWindow::isTextNumeric(QString text)
{
    int i = 0;
    int dotCount = 0;
    for (auto character : text)
    {
        if (i == 0 && (!character.isDigit() && character != '-'))
            return false;
        else
        {
            if (!character.isDigit() && character != '.')
                return false;

            if (character == '.')
                dotCount++;
            if (dotCount > 1)
                return false;
        }
        i++;
    }
    return true;
}

void MainWindow::on_pushButton_3_clicked()
{
    if (!table->selectedItems().size())
        return;

    int selectedRow = table->selectedItems()[0]->row();
    table->removeRow(selectedRow);

    if (!table->rowCount())
        this->ui->pushButton_3->setEnabled(0);
}

void MainWindow::on_lineEdit_2_editingFinished()
{
    if (!this->isTextNumeric(this->ui->lineEdit_2->text()))
        this->ui->lineEdit_2->setText("0");
}

void MainWindow::on_pushButton_5_clicked()
{
    int peopleCount = this->ui->lineEdit_2->text().toInt();
    peopleCount++;
    std::string text = std::to_string(peopleCount);
    this->ui->lineEdit_2->setText(QString::fromStdString(text));

    if (!this->ui->pushButton_4->isEnabled())
        this->ui->pushButton_4->setEnabled(1);
}

void MainWindow::on_pushButton_4_clicked()
{
    int peopleCount = this->ui->lineEdit_2->text().toInt();
    peopleCount--;
    std::string text = std::to_string(peopleCount);
    this->ui->lineEdit_2->setText(QString::fromStdString(text));

    if (this->ui->lineEdit_2->text() == "0")
        this->ui->pushButton_4->setEnabled(0);
}

void MainWindow::on_pushButton_clicked()
{
    if (!this->allFieldsFilled())
    {
        textBox->setText("Prosze uzupełnić wszystkie pola");
        return;
    }

    InputData simulationParameters = Interface::getInputData();
    Building cinema = Building(simulationParameters);
    bool a = true;
}

bool MainWindow::allFieldsFilled()
{
    if     (this->ui->lineEdit_3->text() == "" ||
            this->ui->lineEdit_4->text() == "" ||
            this->ui->lineEdit_5->text() == "" ||
            this->ui->lineEdit_6->text() == "" ||
            this->ui->lineEdit_7->text() == "" ||
            this->ui->lineEdit_8->text() == "")
        return false;
    return true;
}

void MainWindow::on_lineEdit_5_editingFinished()
{
    if (!this->isTextNumeric(this->ui->lineEdit_5->text()))
        this->ui->lineEdit_5->setText("0");
}

void MainWindow::on_lineEdit_3_editingFinished()
{
    if (!this->isTextNumeric(this->ui->lineEdit_3->text()))
        this->ui->lineEdit_3->setText("0");
}

void MainWindow::on_lineEdit_4_editingFinished()
{
    if (!this->isTextNumeric(this->ui->lineEdit_4->text()))
        this->ui->lineEdit_4->setText("0");
}

void MainWindow::on_lineEdit_9_editingFinished()
{
    if (!this->isTextNumeric(this->ui->lineEdit_9->text()))
        this->ui->lineEdit_9->setText("0");
}

void MainWindow::on_lineEdit_8_editingFinished()
{
    if (!this->isTextNumeric(this->ui->lineEdit_8->text()))
        this->ui->lineEdit_8->setText("0");
}

void MainWindow::on_lineEdit_7_editingFinished()
{
    if (!this->isTextNumeric(this->ui->lineEdit_7->text()))
        this->ui->lineEdit_7->setText("0");
}

void MainWindow::on_lineEdit_6_editingFinished()
{
    if (!this->isTextNumeric(this->ui->lineEdit_6->text()))
        this->ui->lineEdit_6->setText("0");
}

int MainWindow::getPeopleCount()
{
    return this->ui->lineEdit_2->text().toInt();
}

int MainWindow::getVentsCount()
{
    return this->ui->lineEdit_5->text().toInt();
}

double MainWindow::getCubature()
{
    return this->ui->lineEdit_9->text().toDouble();
}

double MainWindow::getOuterTemperature()
{
    return this->ui->lineEdit_3->text().toDouble();
}

double MainWindow::getOuterHumidity()
{
    return this->ui->lineEdit_4->text().toDouble();
}

double MainWindow::getStartTemperature()
{
    return this->ui->lineEdit_6->text().toDouble();
}

double MainWindow::getStartHumidity()
{
    return this->ui->lineEdit_7->text().toDouble();
}

double MainWindow::getStartCO2()
{
    return this->ui->lineEdit_8->text().toDouble();
}

double* MainWindow::getACPowers()
{
    double* acPowers = new double[table->rowCount()];
    for (int i = 0; i < table->rowCount(); i++)
        acPowers[i] = table->item(i, 1)->text().toDouble();
    return acPowers;
}

std::string* MainWindow::getACModes()
{
    std::string* acModes = new std::string[table->rowCount()];
    for (int i = 0; i < table->rowCount(); i++)
        acModes[i] = table->item(i, 0)->text().toStdString();
    return acModes;
}

int MainWindow::getACCount()
{
    return this->ui->tableWidget->rowCount();
}
