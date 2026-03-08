/* Krasavtsev A A
 *
 *
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <algorithm>
#include <vector>

// Вспомогательная функция для суммы цифр
int MainWindow::sumOfDigits(long long n) {
    int sum = 0;
    n = std::abs(n);
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void MainWindow::runTask10() {
    // 1. Считываем входные строки
    QStringList listX = ui->inputX_10->text().split(QRegularExpression("[\t ,]+"), Qt::SkipEmptyParts);
    QStringList listY = ui->inputY_10->text().split(QRegularExpression("[\t ,]+"), Qt::SkipEmptyParts);

    std::vector<long long> Z;

    // 2. Перевод из 5-ричной (X) в 10-ричную
    for (const QString &s : std::as_const(listX)) {
        bool ok;
        long long val = s.toLongLong(&ok, 5);
        if (ok) Z.push_back(val);
    }

    // 3. Перевод из 6-ричной (Y) в 10-ричную
    for (const QString &s : std::as_const(listY)) {
        bool ok;
        long long val = s.toLongLong(&ok, 6);
        if (ok) Z.push_back(val);
    }

    // 4. Фильтруем: ищем числа с нечётной суммой цифр
    std::vector<long long> filtered;
    for (long long val : Z) {
        if (sumOfDigits(val) % 2 != 0) {
            filtered.push_back(val);
        }
    }

    // 5. Сортируем по убыванию
    std::sort(filtered.begin(), filtered.end(), std::greater<long long>());

    // --- ВЫВОД ---
    ui->resultArea10->clear();
    ui->resultArea10->setStyleSheet("color: green; font-weight: bold;");
    QString strZ = "Массив Z (в 10-й СС): ";
    for (long long n : Z) strZ += QString::number(n) + " ";
    ui->resultArea10->append(strZ + "\n");

    ui->resultArea10->append("5 наибольших с нечётной суммой цифр:");

    int count = std::min((int)filtered.size(), 5);
    if (count == 0) {
        ui->resultArea10->append("Подходящие числа не найдены.");
    } else {
        for (int i = 0; i < count; ++i) {
            ui->resultArea10->append(QString("%1. %2 (сумма цифр: %3)")
                                         .arg(i + 1).arg(filtered[i]).arg(sumOfDigits(filtered[i])));
        }
    }
}
