#include <iostream>
#include <fstream>
#include <math.h>

#include <windows.h> ///����� ��� ����� ��������� � ������ ���������

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
    cout << "������ -- " << turn.type << '\n';
    cout << "���� -- " << turn.clr << '\n';
    cout << "��������� ������� -- " << turn.sPos << '\n';
    cout << "�������� ������� -- " << turn.ePos << '\n';
}
int main() {
    setlocale(LC_ALL, "Russian");
    cout << "������� ������ � ����:\n(������, ����, ��������� � �������� �������)\n";
    mv turn;
    read_move(turn);
    cout << "��������� ���:\n";
    print_move(turn);
}
