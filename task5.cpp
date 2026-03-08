/* Krasavtsev A A
 *
 *
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"

// Глобальные или статические переменные для хранения состояния задачи
static int evenCount = 0;
static int oddCount = 0;

void MainWindow::runTask5()
{
    bool ok;
    int n = ui->inputNum5->text().toInt(&ok);

    if (!ok) {
        ui->resultLabel5->setText("Введите целое число!");
        return;
    }

    if (n == 0) {
        // Конец последовательности - считаем результат
        int total = evenCount + oddCount;
        if (total > 0) {
            double evenPerc = (double)evenCount / total * 100.0;
            double oddPerc = (double)oddCount / total * 100.0;

            ui->resultLabel5->setStyleSheet("color: green; font-weight: bold;");
            ui->resultLabel5->setText(QString("Чётных: %1% | Нечётных: %2%")
                                          .arg(evenPerc, 0, 'f', 1)
                                          .arg(oddPerc, 0, 'f', 1));
        } else {
            ui->resultLabel5->setText("Последовательность пуста.");
        }

        // Сброс счетчиков для нового круга
        evenCount = 0;
        oddCount = 0;
        ui->sequenceDisplay5->clear();
    } else {
        // Добавляем число в статистику
        if (n % 2 == 0) evenCount++;
        else oddCount++;

        ui->sequenceDisplay5->insertPlainText(QString::number(n)+ ',');
        ui->inputNum5->clear();
        ui->resultLabel5->setStyleSheet("color: blue;");
        ui->resultLabel5->setText("Число добавлено. Введите 0 для расчета.");
    }
}
