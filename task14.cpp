/* Krasavtsev A A
 *
 *
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"


struct Complex {
    double re, im; // Действительная и мнимая части

    // Оператор вычитания
    Complex operator-(const Complex& other) const {
        return {re - other.re, im - other.im};
    }

    // Оператор сложения
    Complex operator+(const Complex& other) const {
        return {re + other.re, im + other.im};
    }

    // Оператор умножения
    Complex operator*(const Complex& other) const {
        return {re * other.re - im * other.im, re * other.im + im * other.re};
    }

    // Оператор деления
    Complex operator/(const Complex& other) const {
        double denom = other.re * other.re + other.im * other.im;
        return {(re * other.re + im * other.im) / denom,
                (im * other.re - re * other.im) / denom};
    }
};

void MainWindow::runTask14() {
    // 1. Считываем данные
    Complex a = {ui->in_a_re->value(), ui->in_a_im->value()};
    Complex b = {ui->in_b_re->value(), ui->in_b_im->value()};
    Complex c = {ui->in_c_re->value(), ui->in_c_im->value()};

    // 2. Вычисляем компоненты формулы
    // Числитель: a - b - c
    Complex num = a - b - c;

    // Знаменатель: a - b^2 + c^3
    Complex b2 = b * b;
    Complex c3 = c * c * c;
    Complex den = a - b2 + c3;

    // 3. Итоговое число d
    if (den.re == 0 && den.im == 0) {
        ui->resTask14->setText("Ошибка: деление на ноль!");
        return;
    }

    Complex d = num / den;

    // 4. Форматированный вывод
    QString sign = (d.im >= 0) ? "+" : "-";
    ui->resTask14->setText(QString("d = %1 %2 %3i")
                               .arg(d.re, 0, 'f', 4)
                               .arg(sign)
                               .arg(std::abs(d.im), 0, 'f', 4));
}
