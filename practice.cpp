#include <bits/stdc++.h>
using namespace std;

class Student
{
private:
    string password;

protected:
    int english_marks;

public:
    Student()
    {
        english_marks = 0;
        password = "1234";
    }
    string name;
    char section;
    int roll;
    void set_marks(int marks)
    {
        english_marks = marks;
    }
    void set_password(string pass)
    {
        password = pass;
    }
    int get_marks()
    {
        return english_marks;
    }
    void update_marks(string pass, int marks)
    {
        if (password == pass)
            english_marks += marks;
        else
            cout << "Password didn't match";
    }
};

int main()
{
    int n = 5;
    Student arr[n];
    for (int i = 0; i < n; i++)
    {
        int marks;
        cin >> arr[i].name >> arr[i].section >> arr[i].roll >> marks;
        arr[i].set_marks(marks);
    }
    cout << endl;

    int roll, marks;
    string password;
    cin >> roll >> marks >> password;
    bool found = false;

    for (int i = 0; i < n; i++)
    {
        if (roll == arr[i].roll)
        {
            arr[i].update_marks(password, marks);

            found = true;
        }

        // cout << arr[i].name << arr[i].section << arr[i].roll << arr[i].get_marks() << endl;
    }
    if (!found)
        cout << "Student with roll:" << roll << " not found" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i].name << " " << arr[i].section << " " << arr[i].roll << " " << arr[i].get_marks() << endl;
    }
    return 0;
}