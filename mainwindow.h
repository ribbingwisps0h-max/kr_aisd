#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void runTask1();
    void runTask2();
    void runTask3();
    void runTask4();
    void runTask5();
    void runTask6();
    void runTask7();
    void runTask8();
    void runTask9();
    void runTask10();
    void runTask11();
    void runTask12();

private:
    Ui::MainWindow *ui;
    double getAvgDigits(int n);
    long long toDecimal(QString num, int base);
    QString fromDecimal(long long num, int base);
    int sumOfDigits(long long n);
    bool isPrime(int n);
    bool isDigitsDescending(int n);
    bool isPalindrome(int n);
    int getDigitSum(int n);
};
#endif // MAINWINDOW_H
