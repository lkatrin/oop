#include <stdio.h>

// Структура для заказа
struct Order {
    int order_id;
    int manager_id;
    int client_id;
    const char *order_date;
    double amount;
};

int main() {
    struct Order order = 3001, 1007, 2001, "2006-10-03", 18.69};
    printf("order_id=%d, manager_id=%d, client_id=%d, order_date=%s, amount=%.2f\n", 
           order.order_id, order.manager_id, order.client_id, order.order_date, order.amount);

    return 0;
}
