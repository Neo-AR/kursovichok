#pragma once
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>

const int N = 7; // Размер графа

class Graph {
private:
    int directedMatrix[N][N];    // для ориентированного графа
    int undirectedMatrix[N][N];  // для неориентированного графа
    bool used[N];               // посещенные вершины

public:
    // Конструктор
    Graph();

    // Инициализация графа
    void initGraph();

    // Очистка массива used
    void clearUsed();

    // Заполнение матриц
    void fillDirectedMatrix();
    void fillUndirectedMatrix();

    // Печать матрицы
    void printMatrix(int mat[N][N], const std::string& title) const;

    // Геттеры для матриц (для использования в функциях)
    const int (*getDirectedMatrix())[N] { return directedMatrix; }
    const int (*getUndirectedMatrix())[N] { return undirectedMatrix; }

    // Геттер для массива used
    bool* getUsedArray() { return used; }
};

#endif