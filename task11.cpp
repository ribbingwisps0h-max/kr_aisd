#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>

// Проверка на простое число
bool MainWindow::isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

// Проверка: цифры образуют убывающую последовательность
bool MainWindow::isDigitsDescending(int n) {
    QString s = QString::number(std::abs(n));
    if (s.length() < 2) return true; // Однозначное число формально подходит
    for (int i = 0; i < s.length() - 1; ++i) {
        if (s[i].digitValue() <= s[i+1].digitValue()) return false;
    }
    return true;
}

void MainWindow::runTask11() {
    QStringList list = ui->inputX_11->text().split(QRegularExpression("[\t ,]+"), Qt::SkipEmptyParts);
    std::vector<int> X;
    for (const QString &s : std::as_const(list)) X.push_back(s.toInt());

    if (X.empty()) return;

    // 1. Находим все группы подходящих чисел
    struct Group { int start; int length; };
    std::vector<Group> groups;

    for (int i = 0; i < X.size(); ++i) {
        if (isPrime(X[i]) && isDigitsDescending(X[i])) {
            int start = i;
            while (i < X.size() && isPrime(X[i]) && isDigitsDescending(X[i])) {
                i++;
            }
            groups.push_back({start, i - start});
            i--; // Возвращаемся на шаг назад для цикла for
        }
    }

    ui->resultArea11->clear();
    ui->resultArea11->setStyleSheet("color: green; font-weight: bold;");
    if (groups.empty()) {
        ui->resultArea11->setText("Подходящие группы не найдены.");
        return;
    }

    // 2. Ищем группу минимальной длины
    Group minGroup = groups[0];
    for (const auto &g : groups) {
        if (g.length < minGroup.length) minGroup = g;
    }

    ui->resultArea11->append(QString("Найдена группа мин. длины (%1) на позиции %2")
                                 .arg(minGroup.length).arg(minGroup.start + 1));

    // 3. Удаляем группу
    X.erase(X.begin() + minGroup.start, X.begin() + minGroup.start + minGroup.length);

    // 4. Вывод результата
    QString res = "Массив после удаления: ";
    for (int n : X) res += QString::number(n) + " ";
    ui->resultArea11->append("\n" + res);
}
