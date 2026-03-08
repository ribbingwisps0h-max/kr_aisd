/* Krasavtsev A A
 *
 *
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <complex>
#include <vector>

typedef std::complex<double> Complex;
typedef std::vector<std::vector<Complex>> ComplexMatrix;

// Вспомогательная функция для умножения матриц
ComplexMatrix multiply(const ComplexMatrix& A, const ComplexMatrix& B, int m) {
    ComplexMatrix res(m, std::vector<Complex>(m, 0));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k < m; k++)
                res[i][j] += A[i][k] * B[k][j];
    return res;
}

void MainWindow::runTask15() {
    int m = ui->matrixM->value();
    ComplexMatrix F(m, std::vector<Complex>(m));
    ComplexMatrix FT(m, std::vector<Complex>(m));

    // 1. Считываем F и сразу создаем FT (транспонированную)
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            QString val = ui->complexTable->item(i, j)->text();
            // Упрощенный парсинг (здесь лучше добавить проверку формата)
            // Допустим, вводим "1,2" где 1-re, 2-im
            double re = val.section(',', 0, 0).toDouble();
            double im = val.section(',', 1, 1).toDouble();
            F[i][j] = Complex(re, im);
            FT[j][i] = Complex(re, im);
        }
    }

    // 2. Вычисляем B = FT - (2i * F)
    ComplexMatrix B(m, std::vector<Complex>(m));
    Complex twoI(0, 2);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            B[i][j] = FT[i][j] - (twoI * F[i][j]);
        }
    }

    // 3. Возводим в квадрат (Матричное умножение B * B)
    ComplexMatrix B2 = multiply(B, B, m);

    // 4. Умножаем на -3.3 и выводим
    ui->resultArea15->clear();
    for (int i = 0; i < m; i++) {
        QString rowStr;
        for (int j = 0; j < m; j++) {
            Complex c = B2[i][j] * (-3.3);
            rowStr += QString("(%1, %2i)  ").arg(c.real(), 0, 'f', 2).arg(c.imag(), 0, 'f', 2);
        }
        ui->resultArea15->append(rowStr);
    }
}
