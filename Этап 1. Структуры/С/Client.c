#include <stdio.h>

// Структура для клиента
struct Client {
    int client_id;
    const char *name;
    const char *city;
    int rating;
    int manager_id;
};

int main() {
    struct Client client = {2001, "Антонов", "Владимир", 100, 1001};
    printf("id=%d, name=%s, city=%s, rating=%d, manager_id=%d\n", client.client_id, client.name, client.city, client.rating, client.manager_id);
    
    return 0;
}