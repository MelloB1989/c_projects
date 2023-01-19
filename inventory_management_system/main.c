#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char products[][100] = {"Doritos", "5 star", "Dairy Milk", "Kiss me", "KitKat", "Sneakers", "Cone Icecreams"};//Dataset to store Name of each product
int pr_price[100] = {20, 10, 10, 20, 20, 20, 35};//Dataset to store price of each product
int stock[100] = {100, 269, 396, 169, 469, 126, 169};//Dataset to store the stock of each product
int sales[100] = {96, 69, 96, 69, 96, 69, 96};//Dataset to store the total number of sales
int no_products = 7;

void show_menu();
int register_sale();
int register_product();
int get_pr_stats();
int get_inventory();
void show_alert_message();

int main(){
    int q = 0, choice, id, message_id = 2;
    while(q == 0){
        show_alert_message(message_id);
        show_menu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            message_id = register_product();
            break;
        
        case 2:
            message_id = get_pr_stats();
            break;

        case 3:
            message_id = get_inventory();
            break;

        case 4:
            message_id = register_sale();
            break;

        case 5:
            printf("\nThankyou!\n");
            q = 1;

        default:
            message_id = 3;
            break;
        }
    }
}

void show_menu(){
    printf("\n\n\t\t\t\tCrafted by MelloB\n\n\n\n");
    printf("Choose what you want to do :-)\n\n");
    printf("1.) Register a new product\n");
    printf("2.) Get product details\n");
    printf("3.) Print out the inventory\n");
    printf("4.) Register a new sale\n");
    printf("5.) Exit\n");
    printf("\nYour choice here:-> ");
}

int register_product(){
    int id, prod_price, stock_avail;
    char pr_name[50];
    id = no_products;
    system("clear");
    printf("\n\n\t\t\t\tCrafted by MelloB");
    printf("\n\nEnter product price: ");
    scanf("%d", &prod_price);
    printf("\nEnter stock available and name of product(MAX_LIMIT=50): ");
    scanf("%d\n", &stock_avail);
    fgets(pr_name, 50, stdin);
    strcpy(products[id], pr_name);
    pr_price[id] = prod_price;
    stock[id] = stock_avail;
    sales[id] = 0;
    no_products = no_products + 1;
    return 1;
}

int register_sale(){
    int id, sales;
    system("clear");
    printf("Enter the product ID: ");
    scanf("%d", &id);
    printf("Input the total sale: ");
    scanf("%d", &sales);
    return 4;
}

int get_pr_stats(){
    int id;
    system("clear");
    printf("\n\n\t\t\t\tCrafted by MelloB");
    printf("\n\nEnter the product ID: ");
    scanf("%d", &id);
    printf("\n\n\nProduct name: %s", products[id]);
    printf("\nProduct price: %d/-", pr_price[id]);
    printf("\nTotal sales: %d", sales[id]);
    printf("\nTotal revenue: %d/-", sales[id]*pr_price[id]);
    printf("\nStock left: %d", stock[id]);
    printf("\nUnsold inventory value: %d/-", stock[id]*pr_price[id]);
    return 0;
}

int get_inventory(){
    int id;
    system("clear");
    printf("\n\n\t\t\t\tCrafted by MelloB");
    printf("\n\nPRODUCT ID\t\t\t\tPRODUCT NAME\t\t\t\tPRODUCT PRICE");
    printf("\n");
    for(id=0; id<=no_products-1; id++){
        printf("\n%d\t\t\t\t\t%s\t\t\t\t\t%d", id, products[id], pr_price[id]);
    }
    return 0;
}

void show_alert_message(int message_id){
    if(message_id == 0){
        printf("\n========================================================================================");
    }
    else if(message_id == 1){
        system("clear");
        printf("\nALERT: Product has been added successfully!\n\n");
    }
    else if(message_id == 2){
        printf("\n");
    }
    else if(message_id == 3){
        system("clear");
        printf("\nALERT: Wrong choice! Please try again.\n\n");
    }
    else if(message_id == 4){
        system("clear");
        printf("\nALERT: Sale has been registered!\n\n");
    }
}