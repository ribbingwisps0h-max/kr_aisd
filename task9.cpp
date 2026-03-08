/* Krasavtsev A A
 *
 *
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>

void MainWindow::runTask9() {
    // 1. Считываем массив X
    QStringList list = ui->inputX_9->text().split(QRegularExpression("[\t ,]+"), Qt::SkipEmptyParts);
    std::vector<int> X;
    for (const QString &s : std::as_const(list)) X.push_back(s.toInt());

    int k = ui->inputK_9->text().toInt();

    if (X.empty()) {
        ui->resultArea9->setText("Массив пуст!");
        return;
    }

    // --- А: Произведение кратных 7 ---
    long long prod7 = 1;
    bool found7 = false;
    for (int n : X) {
        if (n % 7 == 0 && n != 0) {
            prod7 *= n;
            found7 = true;
        }
    }
    if (!found7) prod7 = 0;

    // --- Б: Элементы между первым и последним четными ---
    int firstEven = -1, lastEven = -1;
    for (int i = 0; i < X.size(); ++i) {
        if (X[i] % 2 == 0) {
            if (firstEven == -1) firstEven = i;
            lastEven = i;
        }
    }
    int countBetween = (firstEven != -1 && firstEven != lastEven) ? (lastEven - firstEven - 1) : 0;

    // --- В: Массив Y (первые k положительных) ---
    std::vector<int> Y;
    for (int n : X) {
        if (n > 0 && Y.size() < (size_t)k) Y.push_back(n);
    }

    // // --- Г: Удаление ближайшего к среднему ---
    // double avg = std::accumulate(X.begin(), X.end(), 0.0) / X.size();
    // auto itToRemove = std::min_element(X.begin(), X.end(), [avg](int a, int b) {
    //     return std::abs(a - avg) < std::abs(b - avg);
    // });

    // QString removedVal = QString::number(*itToRemove);
    // X.erase(itToRemove);
    // --- Г: Удаление ближайшего к среднему ---
    double avg = std::accumulate(X.begin(), X.end(), 0.0) / X.size();

    // 1. Находим саму минимальную разницу
    double minDiff = std::abs(X[0] - avg);
    for (int n : X) {
        if (std::abs(n - avg) < minDiff) {
            minDiff = std::abs(n - avg);
        }
    }

    // 2. Находим значение числа, которое дает эту разницу (для вывода)
    int valueToRemove = 0;
    for (int n : X) {
        if (std::abs(n - avg) == minDiff) {
            valueToRemove = n;
            break;
        }
    }

    // 3. Удаляем ВСЕ элементы, у которых такая же разница (используем идиому erase-remove)
    X.erase(std::remove_if(X.begin(), X.end(), [avg, minDiff](int n) {
                return std::abs(n - avg) == minDiff;
            }), X.end());

    QString removedVal = QString::number(valueToRemove);

    // --- ВЫВОД ---
    ui->resultArea9->clear();
    ui->resultArea9->setStyleSheet("color: green; font-weight: bold;");
    ui->resultArea9->append(QString("1. Произведение кратных 7: %1").arg(prod7));
    ui->resultArea9->append(QString("2. Элементов между чётными: %1").arg(countBetween));

    QString strY = "3. Массив Y: ";
    for (int n : Y) strY += QString::number(n) + " ";
    ui->resultArea9->append(strY);

    ui->resultArea9->append(QString("4. Удалено число %1 (ближайшее к ср.арифм %2)").arg(removedVal).arg(avg, 0, 'f', 2));


    QString strX = "Итоговый массив X: ";
    for (int n : X) strX += QString::number(n) + " ";
    ui->resultArea9->append(strX);
}
