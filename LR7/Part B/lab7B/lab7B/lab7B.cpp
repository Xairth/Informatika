#include <iostream>
#include <fstream>
#include <math.h>

#include <windows.h> ///Нужен для смены кодировок и работы кириллицы

#define N 100
#define nullptr 0

using namespace std;

struct mv {
    char type[40], clr[20];
    char sPos[3], ePos[3];
};
void read_move(mv& turn, ifstream& in) {
    in >> turn.type;
    in >> turn.clr;
    in >> turn.sPos;
    in >> turn.ePos;
}
void print_move(mv& turn) {
    cout << "Фигура -- " << turn.type << '\n';
    cout << "Цвет -- " << turn.clr << '\n';
    cout << "Начальная позиция -- " << turn.sPos << '\n';
    cout << "Конечная позиция -- " << turn.ePos << '\n';
}

struct node {
    mv val;
    node* next;
};
node* new_node(mv val, node* next) {
    node* res = new node;
    res->val = val;
    res->next = next;
    return res;
}
struct list {
    node* first;
    node* last;
    int amount;
};
list create_list(mv first_elem) {
    list res;
    res.first = new_node(first_elem, nullptr);
    res.last = res.first;
    res.amount = 1;
    return res;
}
void add(list& lst, mv elem) {
    if (lst.amount != 0) {
        node* new_nd = new_node(elem, nullptr);
        lst.last->next = new_nd;
        lst.last = new_nd;
        lst.amount++;
    }
    else {
        cout << "...Ошибка\n";
        //...
    }
}
void del(list& lst) {
    if (lst.amount < 2) {
        node* new_first = lst.first->next;
        delete lst.first;
        lst.first = new_first;
        lst.amount--;
    }
}
void wander(list& lst) {
    node* current = lst.first;
    char* last_end_pos = current->val.ePos;
    current = current->next;
    bool was_eaten = false;
    while ((current != nullptr) && (!was_eaten)) {
        if (strcmp(last_end_pos, current->val.sPos) == 0)
            last_end_pos = current->val.ePos;
        else if (strcmp(last_end_pos, current->val.ePos) == 0)
            was_eaten = true;
        current = current->next;
    }
    cout << "Конечная позиция первой фигуры:\n";
    cout << last_end_pos;
}


int main() {
    setlocale(LC_ALL, "Russian");
    mv turn;
    ifstream in("input.txt");
    read_move(turn, in);
    list the_list = create_list(turn);
    while (!in.eof()) {
        read_move(turn, in);
        add(the_list, turn);
    }
    wander(the_list);
}