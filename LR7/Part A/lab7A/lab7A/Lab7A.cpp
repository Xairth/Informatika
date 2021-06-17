#include <iostream>
#include <fstream>
#include <math.h>

#include <windows.h> ///Нужен для смены кодировок и работы кириллицы

#define N 100

using namespace std;

struct mv {
    char type[40], clr[20];
    char sPos[3], ePos[3];
};

void read_move(mv& turn) {
    cin >> turn.type;
    OemToCharA(turn.type, turn.type);
    cin >> turn.clr;
    OemToCharA(turn.clr, turn.clr);
    cin >> turn.sPos;
    OemToCharA(turn.sPos, turn.sPos);
    cin >> turn.ePos;
    OemToCharA(turn.ePos, turn.ePos);
}
void print_move(mv& turn) {
    cout << "Фигура -- " << turn.type << '\n';
    cout << "Цвет -- " << turn.clr << '\n';
    cout << "Начальная позиция -- " << turn.sPos << '\n';
    cout << "Конечная позиция -- " << turn.ePos << '\n';
}
int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Введите данные о ходе:\n(фигура, цвет, начальная и конечные позиции)\n";
    mv turn;
    read_move(turn);
    cout << "Считанный ход:\n";
    print_move(turn);
}
