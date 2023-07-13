#include <bits/stdc++.h>
#include <fstream>
using namespace std;

class Shop
{
    int total_income;

public:
    string product_name[10];
    int product_price[10];
    int product_quantity[10];
    Shop()
    {
        total_income = 0;
    }
    int getter()
    {
        return total_income;
    }
    void setter(int income)
    {
        total_income += income;
    }
    Shop(string *product_name, int *product_price, int *product_quantity, int size)
    {
        for (int i = 0; i < size; i++)
        {
            this->product_name[i] = product_name[i];
            this->product_price[i] = product_price[i];
            this->product_quantity[i] = product_quantity[i];
            this->total_income = 0;
        }
    }
};

Shop *create_product_list()
{
    ifstream inputFile;
    inputFile.open("input.txt");
    if (!inputFile.is_open())
        return 0;
    cout << "Number of products: ";
    int n;
    string product_name[n];
    int product_price[n], product_quantity[n];
    inputFile >> n;
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "Product " << i + 1 << " Name: ";
        inputFile >> product_name[i];
        cout << endl;

        cout << "Product " << i + 1 << " Price: ";
        inputFile >> product_price[i];
        cout << endl;

        cout << "Product " << i + 1 << " Quantity: ";
        inputFile >> product_quantity[i];
        cout << endl;
    }
    cout << endl;

    Shop *products = new Shop(product_name, product_price, product_quantity, n);

    return products;
}
void display_product(Shop *products)
{
    int n = 3;
    cout << "\t\tBUY PRODUCT" << endl;
    cout << "\t--------------------------" << endl;

    cout << "Product Index\t";
    for (int i = 1; i <= n; i++)
    {
        cout << "\t" << i;
    }
    cout << endl;
    cout << "Product Name\t";
    for (int i = 0; i < n; i++)
    {
        cout << "\t" << products->product_name[i];
    }
    cout << endl;
    cout << "Product Price\t";
    for (int i = 0; i < n; i++)
    {
        cout << "\t" << products->product_price[i];
    }
    cout << endl;
    cout << "Product Quantity";
    for (int i = 0; i < n; i++)
    {
        cout << "\t" << products->product_quantity[i];
    }
    cout << endl;
}

void success_msg(Shop *products, int option, int quantity)
{
    cout << products->product_name[option - 1] << " bought " << quantity << " pc successfully" << endl;
    cout << "Your total income: " << products->getter() << endl
         << endl
         << endl;
}

int buy_product(Shop *products, int option, int quantity)
{
    int n = 3;
    for (int i = 0; i < n; i++)
    {
        if (i + 1 == option)
        {
            if (products->product_quantity[i] > quantity)
            {
                products->product_quantity[i] -= quantity;
                products->setter(products->product_price[i] * quantity);
                success_msg(products, option, quantity);
            }
            else
            {
                cout << endl
                     << "Due to high demand, Currently this product is very limited." << endl
                     << "Please try less quantity !" << endl
                     << endl;
                return 0;
            }
        }
    }
}

int main()
{
    Shop *products = create_product_list();
    display_product(products);
Flag:
    int option, quantity;
    cout << endl;
    cout << "Which product do you want? From 1 to 3: ";
    cin >> option;

    cout << "What is the quantity that you want of " << products->product_name[option - 1] << ": ";
    cin >> quantity;

    buy_product(products, option, quantity);

    // cout << products->product_name[option - 1] << " bought " << quantity << " pc successfully" << endl;
    // cout << "Your total income: " << products->getter() << endl
    //      << endl
    //      << endl;

    display_product(products);

    goto Flag;

    return 0;
}