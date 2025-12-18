#pragma once
#include "functions.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <limits>

using namespace std;

// Функция очистки экрана
void clearScreen() {
    system("cls");
}

// DFS для ориентированного графа
void DFSDirected(Graph& g, int v, vector<int>& comp) {
    comp.push_back(v);
    bool* used = g.getUsedArray();
    used[v] = true;

    const int (*matrix)[N] = g.getDirectedMatrix();
    for (int i = 0; i < N; i++) {
        if (matrix[v][i] != 0 && !used[i]) {
            DFSDirected(g, i, comp);
        }
    }
}

// DFS для неориентированного графа
void DFSUndirected(Graph& g, int v, vector<int>& comp) {
    comp.push_back(v);
    bool* used = g.getUsedArray();
    used[v] = true;

    const int (*matrix)[N] = g.getUndirectedMatrix();
    for (int i = 0; i < N; i++) {
        if (matrix[v][i] != 0 && !used[i]) {
            DFSUndirected(g, i, comp);
        }
    }
}

// Поиск компонент связности для ориентированного графа
void findConnectedComponentsDirected(Graph& g) {
    g.clearUsed();
    cout << "Компоненты связности для ориентированного графа:\n";

    for (int i = 0; i < N; ++i) {
        bool* used = g.getUsedArray();
        if (!used[i]) {
            vector<int> comp;
            DFSDirected(g, i, comp);

            if (comp.size() > 0) {
                cout << "Компонент связности:";
                for (size_t j = 0; j < comp.size(); ++j) {
                    cout << ' ' << comp[j] + 1;
                }
                cout << endl;
            }
        }
    }
}

// Поиск компонент связности для неориентированного графа
void findConnectedComponentsUndirected(Graph& g) {
    g.clearUsed();
    cout << "Компоненты связности для неориентированного графа:\n";

    for (int i = 0; i < N; ++i) {
        bool* used = g.getUsedArray();
        if (!used[i]) {
            vector<int> comp;
            DFSUndirected(g, i, comp);

            if (comp.size() > 0) {
                cout << "Компонент связности:";
                for (size_t j = 0; j < comp.size(); ++j) {
                    cout << ' ' << comp[j] + 1;
                }
                cout << endl;
            }
        }
    }
}

// Анализ ориентированного графа
void analyzeDirectedGraph() {
    Graph g;
    cout << "\n=== АНАЛИЗ ОРИЕНТИРОВАННОГО ГРАФА ===\n";
    g.fillDirectedMatrix();
    findConnectedComponentsDirected(g);
}

// Анализ неориентированного графа
void analyzeUndirectedGraph() {
    Graph g;
    cout << "\n=== АНАЛИЗ НЕОРИЕНТИРОВАННОГО ГРАФА ===\n";
    g.fillUndirectedMatrix();
    findConnectedComponentsUndirected(g);
}

// Главное меню
void showMainMenu() {
    int choice;

    while (true) {
        cout << "\n========================================\n";
        cout << "   РЕАЛИЗАЦИЯ АЛГОРИТМА ПОИСКА В ГЛУБИНУ\n";
        cout << "         для анализа графов\n";
        cout << "========================================\n";
        cout << "1. Анализ неориентированного графа\n";
        cout << "2. Анализ ориентированного графа\n";
        cout << "3. Выход из программы\n";
        cout << "========================================\n";

        cout << "Введите номер операции (1-3): ";

        // Проверка корректности ввода
        if (!(cin >> choice)) {
            cout << "\nОшибка! Введите число от 1 до 3.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
        case 1:
            analyzeUndirectedGraph();
            break;

        case 2:
            analyzeDirectedGraph();
            break;

        case 3:
            cout << "\nЗавершение работы программы...\n";
            exit(0);

        default:
            cout << "\nНеверный выбор! Введите число от 1 до 3.\n";
            continue;
        }

        // Спросить, хочет ли пользователь продолжить
        cout << "\n----------------------------------------\n";
        cout << "Хотите выполнить еще один анализ? (y/n): ";

        char continueChoice;
        cin >> continueChoice;

        if (continueChoice == 'n' || continueChoice == 'N') {
            cout << "\nСпасибо за использование программы!\n";
            exit(0);
        }

        // Очистка экрана
        clearScreen();
    }
}