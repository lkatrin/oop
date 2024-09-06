#include <stdio.h>
#include <string.h>

// Структура для менеджера
struct Manager {
    int manager_id;
    const char *name;
    const char *city;
    double comm;
};

// Структура для торговли
struct Trade {
    struct Manager managers[100]; // Массив менеджеров
    int manager_count;            // Количество менеджеров
};

// Функция для добавления менеджера в структуру Trade
void add_manager(struct Trade *trade, int manager_id, const char *name, const char *city, double comm) {
    struct Manager man = {manager_id, name, city, comm};
    trade->managers[trade->manager_count++] = man;
}

// Функция для вывода менеджеров из Коврова
void print_kovrov_managers(struct Trade *trade) {
    printf("Ковровские продавцы:\n");
    for (int i = 0; i < trade->manager_count; i++) {
        if (strcmp(trade->managers[i].city, "Ковров") == 0) {
            printf("id=%d, name=%s, city=%s, comm=%.2f\n", 
                   trade->managers[i].manager_id, trade->managers[i].name, trade->managers[i].city, trade->managers[i].comm);
        }
    }
}

int main() {
    struct Trade trade = { .manager_count = 0 };
    
    // Добавляем менеджеров
    add_manager(&trade, 1001, "Иванов", "Ковров", 0.13);
    add_manager(&trade, 1002, "Петров", "Владимир", 0.13);
    add_manager(&trade, 1003, "Симонян", "Москва", 0.10);
    
    // Печатаем менеджеров из Коврова
    print_kovrov_managers(&trade);

    return 0;
}
