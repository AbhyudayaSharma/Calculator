#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QWidget>
#include <QGridLayout>
#include <QMessageBox>

unsigned int MainWindow::buflen = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    hasDecimal = false;

    ui->button_clear->setEnabled(false);

    // Connect the exit button in the file menu
    connect(ui->actionExit, SIGNAL(triggered(bool)), this, SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::appendDisplayedNumber(Number number, bool doUpdate) {
    if (++buflen > 10) {
        emit ui->numDisplay->overflow();
        return;
    }

    ui->button_clear->setEnabled(true);

    switch (number) {
    case ZERO:
        inputData << 0;
        break;
    case ONE:
        inputData << 1;
        break;
    case TWO:
        inputData << 2;
        break;
    case THREE:
        inputData << 3;
        break;
    case FOUR:
        inputData << 4;
        break;
    case FIVE:
        inputData << 5;
        break;
    case SIX:
        inputData << 6;
        break;
    case SEVEN:
        inputData << 7;
        break;
    case EIGHT:
        inputData << 8;
        break;
    case NINE:
        inputData << 9;
        break;
    case DECIMAL:
        hasDecimal = true;
        inputData << ".";
        break;
    default:
        throw std::runtime_error("MainWindow::appendDisplayedNumber : Unknown Number value");
    }

    // Set the display
    if (doUpdate) {
        updateResult();
    }
}

void MainWindow::updateResult() {
    ui->numDisplay->display(inputData.str().c_str());
}

/*--------- SLOTS ----------*/

// Slots for Numerical Button input
void MainWindow::on_button_zero_clicked()
{
    if (buflen) {
        appendDisplayedNumber(ZERO, true);
    }
}

void MainWindow::on_button_one_clicked()
{
    appendDisplayedNumber(ONE, true);
}

void MainWindow::on_button_two_clicked()
{
    appendDisplayedNumber(TWO, true);
}

void MainWindow::on_button_three_clicked()
{
    appendDisplayedNumber(THREE, true);
}

void MainWindow::on_button_four_clicked()
{
    appendDisplayedNumber(FOUR, true);
}

void MainWindow::on_button_five_clicked()
{
    appendDisplayedNumber(FIVE, true);
}

void MainWindow::on_button_six_clicked()
{
    appendDisplayedNumber(SIX, true);
}

void MainWindow::on_button_seven_clicked()
{
    appendDisplayedNumber(SEVEN, true);
}

void MainWindow::on_button_eight_clicked()
{
    appendDisplayedNumber(EIGHT, true);
}

void MainWindow::on_button_nine_clicked()
{
    appendDisplayedNumber(NINE, true);
}

void MainWindow::on_button_decimal_clicked()
{
    if (!hasDecimal) {
        if (!buflen) {
            appendDisplayedNumber(ZERO);
        }
        appendDisplayedNumber(DECIMAL, true);
    } else {
        QMessageBox::information(this, "Decimal Error", "There can be only one decimal point in a number.");
    }
}

// Slot for  clear button
void MainWindow::on_button_clear_clicked()
{
    buflen = 0;
    inputData.str("0");
    hasDecimal = false;
    updateResult();
    ui->button_clear->setEnabled(false);
}

// Handles display overflow
void MainWindow::on_numDisplay_overflow()
{
    const QString ERROR_MESSAGE = "The digit count exceeds the limit of the calculator.\nThe display will be cleared.";
    QMessageBox::information(this, "Overflow", ERROR_MESSAGE);
    ui->button_clear->click();
}


