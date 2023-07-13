#include <bits/stdc++.h>
using namespace std;

class Restaurant
{
public:
    int food_item_codes[12];
    string food_item_names[12];
    int food_item_prices[12];
    int food_number;

private:
    double total_tax;

public:
    Restaurant()
    {
        this->total_tax = 0;
    }
    void set_total_tax(double amount)
    {
        this->total_tax += amount;
    }
    double get_total_tax()
    {
        return this->total_tax;
    }
};

class Table
{
public:
    int table_no;
    int items;
    int itemCode[12];
    int itemQuantity[12];
};

Restaurant *input_food_data(Restaurant *myRest)
{
    int food_number;
    cin >> food_number;
    myRest->food_number = food_number;
    for (int i = 0; i < food_number; i++)
    {
        cin >> myRest->food_item_codes[i];
        fgetc(stdin);
        getline(cin, myRest->food_item_names[i]);
        cin >> myRest->food_item_prices[i];
    }
    return myRest;
}

Table *input_table_data(Table *myTable, Restaurant *myRest)
{
    int table_no, items;
    cout << "Enter Table No : ";
    cin >> table_no;
    cout << "Enter Number of Items : ";
    cin >> items;
    myTable->table_no = table_no;
    myTable->items = items;
    for (int i = 0; i < items; i++)
    {
        bool found = true;
        cout << "Enter Item " << i + 1 << " code : ";
    Flag:
        cin >> myTable->itemCode[i];
        for (int j = 0; j < myRest->food_number; j++)
        {
            if (myTable->itemCode[i] == myRest->food_item_codes[j])
            {
                found = false;
            }
        }
        if (found)
        {
            cout << "Code is not valid. Please try another code: ";
            goto Flag;
        }
        cout << "Enter Item " << i + 1 << " Quantity : ";
        cin >> myTable->itemQuantity[i];
    }
    return myTable;
}

void print_food_info(Restaurant *myRest)
{
    cout << "\t\t\t\t\t\tMAKE BILL" << endl;
    cout << "\t\t\t\t\t-------------------------" << endl;
    cout << "Item Code\t\t\t\t";
    cout << "Item Name\t\t\t\t";
    cout << "Item Price";
    cout << endl;
    for (int i = 0; i < myRest->food_number; i++)
    {
        cout << myRest->food_item_codes[i] << "\t\t\t\t\t" << myRest->food_item_names[i] << "\t\t\t" << myRest->food_item_prices[i] << endl;
    }
}

void print_bill_sum(Restaurant *myRest, Table *myTable)
{
    cout << "\t\t\t\t\t\tBILL SUMMARY" << endl;
    cout << "\t\t\t\t\t-------------------------" << endl;
    cout << "Table No. : " << myTable->table_no << endl;
    cout << "Item Code\t\t\t\t";
    cout << "Item Name\t\t\t";
    cout << "Item Price\t\t";
    cout << "Item Quantity\t";
    cout << "Total Price";
    cout << endl;
    int total_bill = 0;
    for (int i = 0; i < myRest->food_number; i++)
    {
        for (int j = 0; j < myTable->items; j++)
        {
            if (myRest->food_item_codes[i] == myTable->itemCode[j])
            {
                total_bill += myTable->itemQuantity[j] * myRest->food_item_prices[i];
                cout << myRest->food_item_codes[i] << "\t\t\t\t\t" << myRest->food_item_names[i] << "\t\t" << myRest->food_item_prices[i] << "\t\t\t" << myTable->itemQuantity[j] << "\t\t" << myTable->itemQuantity[j] * myRest->food_item_prices[i] << endl;
            }
        }
    }
    double tax_amount = double(total_bill * 5) / 100;
    double net_total = tax_amount + double(total_bill);
    cout << "TAX\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << fixed << setprecision(2) << tax_amount << endl;
    cout << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "NET TOTAL\t\t\t\t\t\t\t\t\t\t\t\t\t" << net_total << " Taka" << endl;
    myRest->set_total_tax(tax_amount);
    cout << endl;
    cout << "Total Tax = " << myRest->get_total_tax() << endl;
}

int main()
{
    Restaurant *myRest = new Restaurant();
    Table *myTable = new Table();
    // input food
    input_food_data(myRest);
    cout << endl;

    // show food info
Flag:
    print_food_info(myRest);
    cout << endl;

    // from user
    input_table_data(myTable, myRest);
    cout << endl;

    // Output Bill
    print_bill_sum(myRest, myTable);
    cout << endl;
    goto Flag;
    return 0;
}
