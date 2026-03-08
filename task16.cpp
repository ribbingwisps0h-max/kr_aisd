/* Krasavtsev A A
 *
 *
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"

struct TreeNode {
    int id;           // Номер вершины (1-15)
    int value;        // Число-пометка из таблицы
    std::vector<TreeNode*> children;

    TreeNode(int _id, int _val) : id(_id), value(_val) {}
};

// Рекурсивный поиск узла с заданным значением
TreeNode* findNode(TreeNode* root, int targetValue) {
    if (!root) return nullptr;
    if (root->value == targetValue) return root;
    for (TreeNode* child : root->children) {
        TreeNode* found = findNode(child, targetValue);
        if (found) return found;
    }
    return nullptr;
}

// Рекурсивный сбор всех ID потомков
void collectDescendants(TreeNode* node, QStringList &list) {
    if (!node) return;
    for (TreeNode* child : node->children) {
        list << QString::number(child->id);
        collectDescendants(child, list); // Рекурсивно идем вглубь
    }
}

void MainWindow::runTask16() {
    // 1. Создаем дерево на основе таблицы 1
    // Значения: 10, 22, 16, 11, 45, 25, 25, 4, 10, 7, 8, 25, 10, 1, 9
    int values[] = {0, 10, 22, 16, 11, 45, 25, 25, 4, 10, 7, 8, 25, 10, 1, 9};
    std::vector<TreeNode*> nodes;
    for(int i = 0; i <= 15; ++i) nodes.push_back(new TreeNode(i, values[i]));

    // Устанавливаем связи согласно рисунку
    nodes[1]->children = {nodes[2], nodes[3]};
    nodes[2]->children = {nodes[4], nodes[5]};
    nodes[3]->children = {nodes[6], nodes[7]};
    nodes[4]->children = {nodes[8], nodes[9]};
    nodes[5]->children = {nodes[10], nodes[11]};
    nodes[6]->children = {nodes[12], nodes[13]};
    nodes[7]->children = {nodes[14], nodes[15]};

    // 2. Ищем первую вершину с пометкой 25
    TreeNode* target = findNode(nodes[1], 25);

    ui->resultArea16->clear();
    if (target) {
        ui->resultArea16->append(QString("Найдена вершина №%1 с пометкой 25").arg(target->id));

        // 3. Собираем потомков
        QStringList descendants;
        ::collectDescendants(target, descendants);

        if (descendants.isEmpty()) {
            ui->resultArea16->append("У этой вершины нет потомков.");
        } else {
            ui->resultArea16->append("Номера потомков: " + descendants.join(", "));
        }
    } else {
        ui->resultArea16->append("Вершина с пометкой 25 не найдена.");
    }

    // Чистим память
    for(auto n : nodes) delete n;
}
