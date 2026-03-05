#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>

// Вспомогательная функция: расчет среднего значения цифр одного числа
double MainWindow::getAvgDigits(int n) {
    n = abs(n); // Работаем с положительным значением
    if (n == 0) return 0.0;

    int sum = 0;
    int count = 0;

    while (n > 0) {
        sum += n % 10;
        count++;
        n /= 10;
    }
    return (double)sum / count;
}

void MainWindow::runTask7() {
    // Считываем всю строку и разбиваем её на части по пробелам/запятым
    QString input = ui->inputSeq7->text();
    QStringList list = input.split(QRegularExpression("[, \t]+"), Qt::SkipEmptyParts);

    ui->resultArea7->clear();
    ui->resultArea7->append("Результаты:");
    ui->resultArea7->setStyleSheet("padding: 10px; color: #008000;");

    for (const QString &str : std::as_const(list)) {
        bool ok;
        int num = str.toInt(&ok);
        if (ok) {
            double avg = getAvgDigits(num);
            ui->resultArea7->insertPlainText(QString("Число %1 -> Средняя цифра: %2 ")
                                        .arg(num)
                                        .arg(avg, 0, 'f', 2));

        }
    }
}
