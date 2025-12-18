#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include "graph.h"
#include "functions.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Инициализация генератора случайных чисел
    srand(static_cast<unsigned int>(time(0)));

    // Запуск главного меню
    showMainMenu();

    return 0;
}