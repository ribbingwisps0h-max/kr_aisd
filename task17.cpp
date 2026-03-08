/* Krasavtsev A A
 *
 *
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"


struct StackNode {
    int data;           // Информационная часть
    StackNode* next;    // Адресная часть (указатель на следующий элемент)

    StackNode(int val, StackNode* n = nullptr) : data(val), next(n) {}
};

void MainWindow::runTask17() {
    QStringList list = ui->inputStack->text().split(QRegularExpression("[, \t]+"), Qt::SkipEmptyParts);
    if (list.size() < 5) {
        ui->resultArea17->setText("Ошибка: Введите 5 целых чисел.");
        return;
    }

    // 1. Формирование стека (5 -> 4 -> 3 -> 2 -> 1 -> Nil)
    StackNode* top = nullptr;
    for (int i = 0; i < 5; ++i) {
        top = new StackNode(list[i].toInt(), top);
    }

    auto printStack = [&](StackNode* current) {
        QString res;
        while (current) {
            // Выводим значение и адрес в памяти
            res += QString("[%1 | addr: %2] -> ")
                       .arg(current->data)
                       .arg(reinterpret_cast<uintptr_t>(current), 0, 16);
            current = current->next;
        }
        return res + "Nil";
    };

    ui->resultArea17->clear();
    ui->resultArea17->append("Исходный стек: " + printStack(top));

    // 2. Смена мест 2-го и 5-го элементов через указатели
    // В стеке (5-4-3-2-1): 2-й элемент это '4', 5-й это '1'

    StackNode* p1 = top;          // 1-й (5)
    StackNode* p2 = p1->next;     // 2-й (4)
    StackNode* p3 = p2->next;     // 3-й (3)
    StackNode* p4 = p3->next;     // 4-й (2)
    StackNode* p5 = p4->next;     // 5-й (1)

    // Перестановка:
    // p1 должен указывать на p5
    // p5 должен указывать на p3
    // p4 должен указывать на p2
    // p2 должен указывать на Nil (nullptr)

    p1->next = p5;
    p5->next = p3;
    p4->next = p2;
    p2->next = nullptr;

    ui->resultArea17->append("Стек после перестановки (2-й с 5-м): " + printStack(top));

    // 3. Вывод в обратном порядке с освобождением памяти
    // Чтобы вывести в обратном порядке (1-2-3-4-5), используем вспомогательный вектор
    std::vector<int> out;
    StackNode* temp = top;
    while (temp) {
        out.push_back(temp->data);
        StackNode* toDelete = temp;
        temp = temp->next;
        delete toDelete; // Освобождение памяти
    }

    QString finalOut;
    for (auto it = out.rbegin(); it != out.rend(); ++it) {
        finalOut += QString::number(*it) + " ";
    }
    ui->resultArea17->append("\nИтоговый вывод (в обратном порядке): " + finalOut);
    ui->resultArea17->append("Память освобождена.");
}
