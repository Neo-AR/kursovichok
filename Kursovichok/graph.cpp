#include "graph.h"
#include <cstdlib>
#include <cstdio>

using namespace std;

// Конструктор
Graph::Graph() {
    initGraph();
}

// Инициализация графа
void Graph::initGraph() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            directedMatrix[i][j] = 0;
            undirectedMatrix[i][j] = 0;
        }
        used[i] = false;
    }
}

// Очистка массива used
void Graph::clearUsed() {
    for (int i = 0; i < N; ++i) {
        used[i] = false;
    }
}

// Печать матрицы смежности
void Graph::printMatrix(int mat[N][N], const string& title) const {
    cout << title << ":\n";
    cout << "   ";
    for (int j = 0; j < N; j++) {
        printf("%4d  ", j + 1);
    }
    cout << "\n\n";

    for (int i = 0; i < N; i++) {
        printf(" %d ", i + 1);
        for (int j = 0; j < N; j++) {
            printf("%4d  ", mat[i][j]);
        }
        cout << "\n\n";
    }
    cout << "\n";
}

// Заполнение матрицы для ориентированного графа
void Graph::fillDirectedMatrix() {
    initGraph();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue; // пропускаем петли

            int R = rand() % 100;
            if (R > 50) { // 50% вероятность создания ребра
                directedMatrix[i][j] = 1;
            }
        }
    }

    printMatrix(directedMatrix, "Матрица смежности для ориентированного графа");
}

// Заполнение матрицы для неориентированного графа
void Graph::fillUndirectedMatrix() {
    initGraph();

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) { // начинаем с i+1, чтобы избежать петель
            int R = rand() % 100;
            if (R > 50) { // 50% вероятность создания ребра
                undirectedMatrix[i][j] = 1;
                undirectedMatrix[j][i] = 1;
            }
        }
    }

    printMatrix(undirectedMatrix, "Матрица смежности для неориентированного графа");
}