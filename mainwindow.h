#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <sstream>

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_button_zero_clicked();

    void on_button_one_clicked();

    void on_button_two_clicked();

    void on_button_three_clicked();

    void on_button_four_clicked();

    void on_button_five_clicked();

    void on_button_six_clicked();

    void on_button_seven_clicked();

    void on_button_eight_clicked();

    void on_button_nine_clicked();

    void on_button_decimal_clicked();

    void on_button_clear_clicked();

    void on_numDisplay_overflow();

private:
    enum Number {
        ZERO,
        ONE,
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        DECIMAL
    };

    static unsigned int buflen;

    bool hasDecimal;
    std::stringstream inputData;
    Ui::MainWindow *ui;
    void appendDisplayedNumber(Number number, bool doUpdate = false) noexcept(false);
    void updateResult();

};

#endif // MAINWINDOW_H
