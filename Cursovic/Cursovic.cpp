#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using namespace std;

const int N = 7;
int matrix[N][N];  // для ориентированного графа
int matrix2[N][N]; // для неориентированного графа
bool used[N];
vector<int> comp;

// Функция очистки массива used
void clearUsed() {
    for (int i = 0; i < N; ++i) {
        used[i] = false;
    }
}

// Функция для печати матрицы
void printMatrix(int mat[N][N], const string& title) {
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
void fillDirectedMatrix() {
    // Инициализируем матрицу нулями
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = 0;
        }
    }

    // Заполняем случайными значениями
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue; // пропускаем петли

            int R = rand() % 100;
            if (R > 50) { // 50% вероятность создания ребра
                matrix[i][j] = 1;
            }
        }
    }

    printMatrix(matrix, "Матрица смежности для ориентированного графа");
}

// Заполнение матрицы для неориентированного графа
void fillUndirectedMatrix() {
    // Инициализируем матрицу нулями
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix2[i][j] = 0;
        }
    }

    // Заполняем случайными значениями (симметричная матрица)
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) { // начинаем с i+1, чтобы избежать петель
            int R = rand() % 100;
            if (R > 50) { // 50% вероятность создания ребра
                matrix2[i][j] = matrix2[j][i] = 1;
            }
        }
    }

    printMatrix(matrix2, "Матрица смежности для неориентированного графа");
}

// DFS для ориентированного графа
void DFSDirected(int v) {
    comp.push_back(v);
    used[v] = true;
    for (int i = 0; i < N; i++) {
        if (matrix[v][i] != 0 && !used[i]) {
            DFSDirected(i);
        }
    }
}

// DFS для неориентированного графа
void DFSUndirected(int v) {
    comp.push_back(v);
    used[v] = true;
    for (int i = 0; i < N; i++) {
        if (matrix2[v][i] != 0 && !used[i]) {
            DFSUndirected(i);
        }
    }
}

// Поиск компонент связности для ориентированного графа
void findConnectedComponentsDirected() {
    clearUsed();
    cout << "Компоненты связности для ориентированного графа:\n";

    for (int i = 0; i < N; ++i) {
        if (!used[i]) {
            comp.clear();
            DFSDirected(i);

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
void findConnectedComponentsUndirected() {
    clearUsed();
    cout << "Компоненты связности для неориентированного графа:\n";

    for (int i = 0; i < N; ++i) {
        if (!used[i]) {
            comp.clear();
            DFSUndirected(i);

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

// Основное меню
void showMenu() {
    int choice;

    cout << "\n========================================\n";
    cout << "        Анализ компонент связности\n";
    cout << "========================================\n";
    cout << "1. Неориентированный граф\n";
    cout << "2. Ориентированный граф\n";
    cout << "3. Выход\n";
    cout << "========================================\n";

    while (true) {
        cout << "\nВведите цифру (1-3): ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Ошибка ввода! Пожалуйста, введите число.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
        case 1:
            fillUndirectedMatrix();
            findConnectedComponentsUndirected();
            break;

        case 2:
            fillDirectedMatrix();
            findConnectedComponentsDirected();
            break;

        case 3:
            cout << "Завершение работы программы...\n";
            exit(0);

        default:
            cout << "Неверный выбор! Пожалуйста, введите цифру от 1 до 3.\n";
            continue;
        }

        // Спросить, хочет ли пользователь продолжить
        char continueChoice;
        cout << "\nХотите выполнить еще один анализ? (y/n): ";
        cin >> continueChoice;

        if (continueChoice == 'n' || continueChoice == 'N') {
            cout << "Завершение работы программы...\n";
            exit(0);
        }

        // Очистка экрана (опционально)
        system("cls");
        // Повторно показать меню
        showMenu();
        break;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Инициализация генератора случайных чисел
    srand(static_cast<unsigned int>(time(0)));

    // Основной цикл программы
    showMenu();

    return 0;
}