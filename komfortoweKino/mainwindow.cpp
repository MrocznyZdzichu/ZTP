#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Interface.h"

#define tempPlot this->ui->widget
#define humPlot this->ui->widget_2
#define co2Plot this->ui->widget_3
#define textBox this->ui->textBrowser
#define table this->ui->tableWidget
#define powerEdit this->ui->lineEdit
#define table2 this->ui->tableWidget_2

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
    this->ui->lineEdit_10->setText("0");
    this->ui->lineEdit_11->setText("0");
    this->ui->lineEdit_12->setText("0");
    this->ui->pushButton_4->setEnabled(0);
    this->ui->pushButton_7->setEnabled(0);

    for (int i = 0; i < table2->columnCount(); i++)
        table2->setColumnWidth(i, 60);
}

MainWindow::~MainWindow()
{
    delete ui;
}

Limits MainWindow::axisLimits(QVector<double> xData, QVector<double> yData)
{
    Limits limits;

    limits.xMin = *std::min_element(xData.begin(), xData.end());
    limits.xMax = *std::max_element(xData.begin(), xData.end());
    limits.yMin = *std::min_element(yData.begin(), yData.end()) - 0.0001;
    limits.yMax = *std::max_element(yData.begin(), yData.end()) + 0.0001;

    return limits;
}

void MainWindow::plotTemperature(QVector<double> xData, QVector<double> yData)
{
    if (tempPlot->graphCount() < 1)
        tempPlot->addGraph(0);

    Limits limits = this->axisLimits(xData, yData);
    tempPlot->xAxis->setLabel("time");
    tempPlot->yAxis->setLabel("temperature");

    tempPlot->xAxis->setRange(limits.xMin, limits.xMax);
    tempPlot->yAxis->setRange(limits.yMin, limits.yMax);

    tempPlot->graph(0)->setData(xData, yData);
    tempPlot->replot();
}

void MainWindow::plotHumidity(QVector<double> xData, QVector<double> yData)
{
    if (humPlot->graphCount() < 1)
        humPlot->addGraph(0);

    Limits limits = this->axisLimits(xData, yData);
    humPlot->xAxis->setLabel("time");
    humPlot->yAxis->setLabel("humidity");

    humPlot->xAxis->setRange(limits.xMin, limits.xMax);
    humPlot->yAxis->setRange(limits.yMin, limits.yMax);

    humPlot->graph(0)->setData(xData, yData);
    humPlot->replot();

}

void MainWindow::plotCO2(QVector<double> xData, QVector<double> yData)
{
    if (co2Plot->graphCount() < 1)
        co2Plot->addGraph(0);

    Limits limits = this->axisLimits(xData, yData);
    co2Plot->xAxis->setLabel("time");
    co2Plot->yAxis->setLabel("CO2 concentration");

    co2Plot->xAxis->setRange(limits.xMin, limits.xMax);
    co2Plot->yAxis->setRange(limits.yMin, limits.yMax);

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
    QString SP = this->ui->lineEdit_10->text();

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

    if (SP == "")
    {
        textBox->setText("Proszę podać wartość zadaną jednostki");
        return;
    }

    if (!this->isTextNumeric(SP) && SP[0] != '-')
    {
        textBox->setText("Wartość zadana jednostki musi być numeryczna");
        return;
    }

    if (SP.toDouble() <= 0)
    {
        textBox->setText("Wartość zadana jednostki powinna być dodatnia");
        return;
    }

    textBox->clear();

    QTableWidgetItem *powerItem = new QTableWidgetItem(power);
    //powerItem->setFlags(powerItem->flags() ^ Qt::ItemIsEditable);
    powerEdit->clear();

    QTableWidgetItem* SPItem = new QTableWidgetItem(SP);
    //SPItem->setFlags(SPItem->flags() ^ Qt::ItemIsEditable);

    this->ui->lineEdit_10->clear();
    powerEdit->clear();

    int newRowNumber = table->rowCount();
    table->setRowCount(newRowNumber+1);

    table->setItem(newRowNumber, 0, SPItem);
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
    bool isInteger = true;
    std::string text = this->ui->lineEdit_2->text().toStdString();
    for (auto character : text)
    {
        if (!std::isdigit(character))
        {
            isInteger = false;
            break;
        }
    }
    if (!isInteger)
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
    InputData simulationParameters = Interface::getInputData();
    Building cinema = Building(simulationParameters);
    cinema.simulate();
    cinema.drawResults();
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
    else
    {
        if (this->ui->lineEdit_4->text().toDouble() > 1)
            this->ui->lineEdit_4->setText("0");
    }
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
    else
    {
        if (this->ui->lineEdit_8->text().toDouble() > 0.21)
            this->ui->lineEdit_8->setText("0.21");
    }
}

void MainWindow::on_lineEdit_7_editingFinished()
{
    if (!this->isTextNumeric(this->ui->lineEdit_7->text()))
        this->ui->lineEdit_7->setText("0");
    else
    {
        if (this->ui->lineEdit_7->text().toDouble() > 1)
            this->ui->lineEdit_7->setText("0");
    }
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
    return table2->rowCount();
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

double* MainWindow::getACSPs()
{
    double* acModes = new double[table->rowCount()];
    for (int i = 0; i < table->rowCount(); i++)
        acModes[i] = table->item(i, 0)->text().toDouble();
    return acModes;
}

int MainWindow::getACCount()
{
    return this->ui->tableWidget->rowCount();
}

void MainWindow::on_lineEdit_10_editingFinished()
{
    QString text = this->ui->lineEdit_10->text();
    if (!this->isTextNumeric(text) || text.at(0) == '-' ||
        text.toDouble() < 0)
        this->ui->lineEdit_10->setText(0);
}

void MainWindow::on_lineEdit_11_editingFinished()
{
    if (!this->isTextNumeric(this->ui->lineEdit_11->text()))
        this->ui->lineEdit_11->setText("0");
}

void MainWindow::on_lineEdit_12_editingFinished()
{
    if (!this->isTextNumeric(this->ui->lineEdit_12->text()))
        this->ui->lineEdit_12->setText("0");
}

void MainWindow::on_pushButton_6_clicked()
{
    QString length, area, speed;

    length =    this->ui->lineEdit_5->text();
    area =      this->ui->lineEdit_11->text();
    speed =     this->ui->lineEdit_12->text();

    if (length == "")
    {
        textBox->setText("Proszę podać długość trasy");
        return;
    }

    if (!this->isTextNumeric(length) && length[0] != '-')
    {
        textBox->setText("Długość trasy musi być numeryczna");
        return;
    }

    if (length.toDouble() <= 0)
    {
        textBox->setText("Długość trasy powinna być dodatnia");
        return;
    }

    if (area == "")
    {
        textBox->setText("Proszę podać pole przekroju");
        return;
    }

    if (!this->isTextNumeric(area) && area[0] != '-')
    {
        textBox->setText("Pole przekroju musi być numeryczna");
        return;
    }

    if (area.toDouble() <= 0)
    {
        textBox->setText("Pole przekroju powinna być dodatnia");
        return;
    }

    if (speed == "")
    {
        textBox->setText("Proszę podać prędkość powietrza");
        return;
    }

    if (!this->isTextNumeric(speed) && speed[0] != '-')
    {
        textBox->setText("Prędkość powietrza musi być numeryczna");
        return;
    }

    if (speed.toDouble() <= 0)
    {
        textBox->setText("Prędkość powietrza powinna być dodatnia");
        return;
    }

    textBox->clear();

    QTableWidgetItem *lengthItem = new QTableWidgetItem(length);
    //lengthItem->setFlags(lengthItem->flags() ^ Qt::ItemIsEditable);

    QTableWidgetItem* areaItem = new QTableWidgetItem(area);
    //areaItem->setFlags(areaItem->flags() ^ Qt::ItemIsEditable);

    QTableWidgetItem* speedItem = new QTableWidgetItem(speed);
    //speedItem->setFlags(speedItem->flags() ^ Qt::ItemIsEditable);

    this->ui->lineEdit_5->clear();
    this->ui->lineEdit_11->clear();
    this->ui->lineEdit_12->clear();

    int newRowNumber = table2->rowCount();
    table2->setRowCount(newRowNumber+1);

    table2->setItem(newRowNumber, 0, lengthItem);
    table2->setItem(newRowNumber, 1, areaItem);
    table2->setItem(newRowNumber, 2, speedItem);

    if (!this->ui->pushButton_7->isEnabled())
        this->ui->pushButton_7->setEnabled(1);
}

void MainWindow::on_pushButton_7_clicked()
{
    if (!table2->selectedItems().size())
        return;

    int selectedRow = table2->selectedItems()[0]->row();
    table2->removeRow(selectedRow);

    if (!table2->rowCount())
        this->ui->pushButton_3->setEnabled(0);
}

double* MainWindow::getVentLengths()
{
    double* VentLengths = new double[table2->rowCount()];
    for (int i = 0; i < table2->rowCount(); i++)
        VentLengths[i] = table2->item(i, 0)->text().toDouble();
    return VentLengths;
}

double* MainWindow::getVentArea()
{
    double* VentArea = new double[table2->rowCount()];
    for (int i = 0; i < table2->rowCount(); i++)
        VentArea[i] = table2->item(i, 1)->text().toDouble();
    return VentArea;
}

double* MainWindow::getVentSpeed()
{
    double* VentSpeed = new double[table2->rowCount()];
    for (int i = 0; i < table2->rowCount(); i++)
        VentSpeed[i] = table2->item(i, 2)->text().toDouble();
    return VentSpeed;
}
