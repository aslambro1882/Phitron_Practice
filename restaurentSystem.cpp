#include <bits/stdc++.h>
// #include <iostream>
// #include <string>
using namespace std;

class Restaurant
{
protected:
public:
    int food_item_codes[12];
    string food_item_names[12];
    int food_item_prices[12];
    int total_tax;
    Restaurant(int *food_item_codes, string *food_item_names, int *food_item_prices, int menu_size)
    {
        for (int i = 0; i < menu_size; i++)
        {
            this->food_item_codes[i] = food_item_codes[i];
            this->food_item_names[i] = food_item_names[i];
            this->food_item_prices[i] = food_item_prices[i];
        }
        this->total_tax = 0;
    }
};

/*short comment*/
class Bill : public Restaurant
{

public:
    int choose_item_codes[12];
    int choose_item_quantity[12];
    string choose_item_names[12];
    int choose_item_price[12];
    int choose_item_total[12];
    int table_no;
    double tax;
    double net_total;

    Bill(int *food_item_codes, string *food_item_names, int *food_item_prices, int menu_size, /*--*/ int table_no, int *choose_codes, int *choose_quantity, int order_item_size) : Restaurant(food_item_codes, food_item_names, food_item_prices, menu_size)
    {
        // cout << "menu size: " << menu_size << endl;
        int current_total = 0, i;
        this->table_no = table_no;
        for (i = 0; i < order_item_size; i++)
        {
            for (int j = 0; j < menu_size; j++)
            {
                if (choose_codes[i] == this->food_item_codes[j])
                {
                    this->choose_item_names[i] = this->food_item_names[j];
                    this->choose_item_price[i] = this->food_item_prices[j];
                }
            }

            if (this->choose_item_price[i] == 0)
            {
                cout << endl
                     << "The code you entered is not valid. Please try again!" << endl
                     << endl;
                this->net_total = 0;
                return;
            }
            this->choose_item_codes[i] = choose_codes[i];
            this->choose_item_quantity[i] = choose_quantity[i];
            this->choose_item_total[i] = choose_item_quantity[i] * choose_item_price[i];
            current_total += this->choose_item_total[i];
        }
        this->tax = current_total * 0.05;
        this->net_total = current_total + this->tax;
    }
};

Restaurant *create_restaurent(int *menu_size)
{
    // ifstream inputFile;
    // inputFile.open("input_restaurent.txt");
    // if (!inputFile.is_open())
    //     return 0;
    cin >> *menu_size;
    const int size = *menu_size;
    string food_item_names[size];
    int food_item_codes[size], food_item_prices[size];
    for (int i = 0; i < size; i++)
    {

        cin >> food_item_codes[i];
        cin.ignore();
        getline(cin, food_item_names[i]);
        cin >> food_item_prices[i];
    }
    cout << endl
         << endl;
    Restaurant *menu = new Restaurant(food_item_codes, food_item_names, food_item_prices, size);

    return menu;
}

int display_menu(Restaurant *menu, int size)
{
    cout << "\t\t\t\tMAKE BILL" << endl;
    cout << "\t\t\t----------------------" << endl;
    cout << endl;

    cout << "Item Code\t\t";
    cout << "Item Name\t\t\t";
    cout << "Item Price" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << menu->food_item_codes[i] << "\t\t\t";
        cout << menu->food_item_names[i] << "\t\t";
        cout << menu->food_item_prices[i] << endl;
    }
    cout << endl
         << endl
         << endl;
}

Bill *create_bill(Restaurant *menu, int menu_size, int *order_size)
{
    int table_no, order_item_size;
    cout << "Enter Table No: ";
    cin >> table_no;
    cout << "Enter Number of Items : ";
    cin >> *order_size;
    cout << endl
         << endl
         << endl;
    order_item_size = *order_size;
    int choose_codes[order_item_size], choose_quantity[order_item_size];

    for (int i = 0; i < order_item_size; i++)
    {
        cout << "Enter Item " << i + 1 << " Code : ";
        cin >> choose_codes[i];
        cout << "Enter Item " << i + 1 << " Quantity : ";
        cin >> choose_quantity[i];
    }

    Bill *castomarBill = new Bill(menu->food_item_codes, menu->food_item_names, menu->food_item_prices, menu_size, /*--*/ table_no, choose_codes, choose_quantity, order_item_size);
    return castomarBill;
}

int display_castomarBill(Bill *castomarBill, int order_item_size)
{
    if (castomarBill->net_total == 0)
    {
        // cout << "found error" << endl;
        return 0;
    }
    cout << endl
         << endl;
    cout << "\t\t\t\t\t\tBILL SUMMARY" << endl;
    cout << "\t\t\t\t\t---------------------------" << endl;

    cout << "Table No. : " << castomarBill->table_no << endl;

    cout << "Item Code\t\t";
    cout << "Item Name\t\t";
    cout << "Item Price\t\t";
    cout << "Item Quantity\t\t";
    cout << "Total Price" << endl;

    for (int i = 0; i < order_item_size; i++)
    {
        cout << castomarBill->choose_item_codes[i] << "\t\t\t";
        cout << castomarBill->choose_item_names[i] << "\t";
        cout << castomarBill->choose_item_price[i] << "\t\t\t";
        cout << castomarBill->choose_item_quantity[i] << "\t\t\t";
        cout << castomarBill->choose_item_total[i] << endl;
    }
    cout << "TAX\t\t\t\t\t\t\t\t\t\t\t\t" << fixed << setprecision(2) << castomarBill->tax << endl;
    cout << "--------------------------------------------------------------------------------------------------------------" << endl;
    cout << "NET TOTAL\t\t\t\t\t\t\t\t\t\t\t" << castomarBill->net_total << endl;
}

int main()
{
    int menu_size = 0;
    int order_item_size = 0;

    Restaurant *menu = create_restaurent(&menu_size);
Flag:
    display_menu(menu, menu_size);
    Bill *castomarBill = create_bill(menu, menu_size, &order_item_size);
    display_castomarBill(castomarBill, order_item_size);
    goto Flag;
    return 0;
}