/* Krasavtsev A A
 *
 *
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>

// Перевод ИЗ любой системы В десятичную
long long MainWindow::toDecimal(QString num, int base) {
    bool ok;
    return num.toLongLong(&ok, base); // Встроенная мощь Qt
}

// Перевод ИЗ десятичной В любую систему
QString MainWindow::fromDecimal(long long num, int base) {
    return QString::number(num, base).toUpper(); // Тоже встроенная функция
}

void MainWindow::runTask8() {
    QString strA = ui->inputA_8->text().trimmed();
    QString strB = ui->inputB_8->text().trimmed();

    // Параметры варианта 19
    int p = 2, q = 4, r = 3;

    // 1. Переводим в 10-ю для расчетов
    long long A = toDecimal(strA, p);
    long long B = toDecimal(strB, q);

    // 2. Считаем формулу: B^3 - 2*B + A
    long long C = pow(B, 3) - 2 * B + A;

    // 3. Переводим результат в систему r=3
    QString resR = fromDecimal(C, r);

    // 4. Вывод (Зеленым!)
    ui->resultLabel8->setStyleSheet("color: green; font-weight: bold;");
    ui->resultLabel8->setText(QString("В 10-й системе: %1\nВ 3-й системе (r): %2")
                                  .arg(C).arg(resR));
}
