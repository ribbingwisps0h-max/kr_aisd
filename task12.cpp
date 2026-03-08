/* Krasavtsev A A
 *
 *
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include <algorithm>

// Проверка на палиндром
bool MainWindow::isPalindrome(int n) {
    QString s = QString::number(std::abs(n));
    QString rev = s;
    std::reverse(rev.begin(), rev.end());
    return s == rev;
}

// Сумма цифр числа
int MainWindow::getDigitSum(int n) {
    int sum = 0;
    n = std::abs(n);
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void MainWindow::runTask12() {
    QStringList list = ui->inputX_12->text().split(QRegularExpression("[\t ,]+"), Qt::SkipEmptyParts);
    std::vector<int> X;
    for (const QString &s : std::as_const(list)) X.push_back(s.toInt());

    if (X.size() < 2) return;

    // 1. Поиск последнего и предпоследнего палиндромов
    int lastIdx = -1;
    int prevLastIdx = -1;

    for (int i = X.size() - 1; i >= 0; --i) {
        if (isPalindrome(X[i])) {
            if (lastIdx == -1) {
                lastIdx = i;
            } else {
                prevLastIdx = i;
                break;
            }
        }
    }

    ui->resultArea12->clear();
    ui->resultArea12->setStyleSheet("color: green; font-weight: bold;");
    if (lastIdx == -1 || prevLastIdx == -1) {
        ui->resultArea12->setText("Не найдено два числа-палиндрома.");
        return;
    }

    // Определяем границы (между ними)
    int start = prevLastIdx + 1;
    int end = lastIdx; // Интервал [start, end)

    if (start >= end) {
        ui->resultArea12->setText("Между палиндромами нет элементов.");
        return;
    }

    ui->resultArea12->append(QString("Предпоследний палиндром: %1 (индекс %2)")
                                 .arg(X[prevLastIdx]).arg(prevLastIdx));
    ui->resultArea12->append(QString("Последний палиндром: %1 (индекс %2)")
                                 .arg(X[lastIdx]).arg(lastIdx));

    // 2. Сортировка диапазона по убыванию суммы цифр
    std::sort(X.begin() + start, X.begin() + end, [this](int a, int b) {
        return getDigitSum(a) > getDigitSum(b);
    });

    // 3. Вывод результата
    QString res = "Массив после сортировки: ";
    for (int n : X) res += QString::number(n) + " ";
    ui->resultArea12->append("\n" + res);
}
