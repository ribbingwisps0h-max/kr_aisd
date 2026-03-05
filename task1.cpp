#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>

void MainWindow::runTask1() {
    bool ok;
    float P = ui->inputP_1->text().toFloat(&ok); // Поле ввода на стр. 1

    if (ok && P > 0) {
        float a = P / 4.0f;
        float d = a * sqrtf(2.0f);
        float S = a * a;

        ui->labelResult_1->setStyleSheet("color: green; font-weight: bold;");
        ui->labelResult_1->setText(QString("Сторона: %1 | Диагональ: %2 | Площадь: %3")
                                       .arg(a).arg(d).arg(S));
    } else {
        ui->labelResult_1->setStyleSheet("color: red;");
        ui->labelResult_1->setText("Ошибка: введите положительное число!");
    }
}
