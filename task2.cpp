/* Krasavtsev A A
 *
 *
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::runTask2()
{
    bool ok;
    // Читаем целое число из поля ввода
    int massGrams = ui->inputM_2->text().toInt(&ok);

    if (ok && massGrams >= 0) {
        int kg = massGrams / 1000;      // Целочисленное деление
        int g = massGrams % 1000;       // Остаток от деления

        ui->resultLabel2->setStyleSheet("color: #008000; font-weight: bold;");
        ui->resultLabel2->setText(QString("Результат: %1 кг %2 г")
                                      .arg(kg).arg(g));
    } else {
        ui->resultLabel2->setStyleSheet("color: red;");
        ui->resultLabel2->setText("Ошибка: введите целое положительное число!");
    }
}
