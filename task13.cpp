#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QFileDialog>

// 2. Логика подсчета предложений
void MainWindow::runTask13() {
    QString text = ui->fileContent13->toPlainText();
    if (text.isEmpty()) {
        ui->resultLabel13->setText("Файл пуст или не выбран.");
        return;
    }

    int sentenceCount = 0;
    bool inMarkGroup = false; // Флаг для обработки идущих подряд знаков (..., !!!, ?!)

    for (int i = 0; i < text.length(); ++i) {
        QChar c = text[i];

        // Проверяем, является ли символ знаком конца предложения
        if (c == '.' || c == '!' || c == '?') {
            if (!inMarkGroup) {
                sentenceCount++;
                inMarkGroup = true; // Началась группа знаков
            }
        } else {
            // Если встретили любой другой символ (букву, пробел), сбрасываем флаг группы
            inMarkGroup = false;
        }
    }

    ui->resultLabel13->setStyleSheet("color: blue; font-weight: bold;");
    ui->resultLabel13->setText(QString("Количество предложений в тексте: %1").arg(sentenceCount));
}

void MainWindow::on_btnOpenFile13_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this, "Открыть текстовый файл", "", "Text Files (*.txt)");

    if (fileName.isEmpty()) return;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        ui->resultLabel13->setText("Ошибка открытия файла!");
        return;
    }

    QTextStream in(&file);
    QString content = in.readAll();
    ui->fileContent13->setPlainText(content);
    ui->fileNameLabel13->setText(fileName);
    file.close();
}


