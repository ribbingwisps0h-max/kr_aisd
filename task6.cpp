/* Krasavtsev A A
 *
 *
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::runTask6()
{
    QString str = ui->inputNum6->text().trimmed();
    bool ok;
    str.toLongLong(&ok); // Проверка, что введено именно число

    if (!ok || str.isEmpty() || str.contains('-')) {
        ui->resultLabel6->setStyleSheet("color: red;");
        ui->resultLabel6->setText("Введите целое положительное число!");
        return;
    }

    int minDigit = 10; // Цифр больше 9 не бывает
    int minPos = -1;

    // Проходим по строке слева направо
    for (int i = 0; i < str.length(); ++i) {
        // Преобразуем символ в цифру: '5' -> 5
        int currentDigit = str[i].digitValue();

        if (currentDigit < minDigit) {
            minDigit = currentDigit;
            minPos = i + 1; // Человеческая позиция (с 1)
        }
    }

    ui->resultLabel6->setStyleSheet("color: #008000; font-weight: bold;");
    ui->resultLabel6->setText(QString("Наименьшая цифра: %1 на %2-й позиции")
                                  .arg(minDigit).arg(minPos));
}
