/* Krasavtsev A A
 *
 *
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::runTask3()
{
    bool okX, okY;
    double x = ui->inputX->text().toDouble(&okX);
    double y = ui->inputY->text().toDouble(&okY);

    if (okX && okY) {
        // Проверка внешних границ
        bool inOuter = (x >= -3.0 && x <= 3.0 && y >= -1.0 && y <= 5.0);
        // Проверка внутренних границ (строго внутри белой области)
        bool inInner = (x > -2.0 && x < 2.0 && y > 0.0 && y < 4.0);

        if (inOuter && !inInner) {
            ui->resultLabel3->setStyleSheet("color: green; font-weight: bold;");
            ui->resultLabel3->setText("Результат: Точка ПРИНАДЛЕЖИТ области");
        } else {
            ui->resultLabel3->setStyleSheet("color: blue; font-weight: bold;");
            ui->resultLabel3->setText("Результат: Точка НЕ принадлежит области");
        }
    } else {
        ui->resultLabel3->setStyleSheet("color: red;");
        ui->resultLabel3->setText("Ошибка: введите корректные координаты!");
    }
}
