/* Krasavtsev A A
 *
 *
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath> // Для функции pow

void MainWindow::runTask4()
{
    long long P = 0; // Используем long long для точности, хотя сумма тут небольшая

    // Цикл от 0 до 10 включительно
    for (int i = 0; i <= 10; ++i) {
        P += pow(2, i);
    }

    // Вывод результата
    ui->resultLabel4->setStyleSheet("color: #008000; font-weight: bold; font-size: 16px;");
    ui->resultLabel4->setText(QString("Результат P = %1").arg(P));
}
