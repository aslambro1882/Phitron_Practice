#include <bits/stdc++.h>
using namespace std;

int main()
{
    string st = "abcsdkfsd342fs";
    string st2 = "xyz";
    // string::reverse_iterator i;
    for (auto i = st.begin(); i != st.end(); i++)
    {
        cout << *i << endl;
    }
    // checking string size
    cout << st.length() << " " << st.size() << endl;
    st.resize(4);
    cout << st.length() << " " << st.size() << endl;
    // removing string
    st.clear();
    cout << st.length() << " " << st.size() << endl;
    // cheching is empty or not
    if (st.empty())
        cout << "Y" << endl;
    else
        cout << "N" << endl;
    // front give the first value and back give the last
    cout << st2.front() << " " << st2.back() << endl;
    // giving value according to idx
    cout << st2[2] << " " << st2.at(2) << endl;
    string a;
    // assing string to a variable;
    a.assign("zasd");
    cout << a << endl;
    // appending value to end
    a.append("maruf");
    cout << a << endl;
    // adding a char to end of string.
    a.push_back('B');
    cout << a << endl;
    // removing last char form string.
    a.pop_back();
    cout << a << endl;
    // insert a substring to a string with position.
    a.insert(1, "sadi");
    cout << a << endl;
    // erase substring wiht arg(first idx, how many char)
    a.erase(1, 5);
    cout << a << endl;
    st.assign("muaruf");
    cout << "st: " << st << " st2: " << st2 << endl;
    // swapping
    swap(st, st2);
    cout << "st: " << st << " st2: " << st2 << endl;
    // finding char wiht idx from begining. if not found return garbage.
    cout << st2.find('u') << endl;
    // finding char wiht idx from ending. if not found return garbage.
    cout << st2.rfind('u') << endl;
    cout << st2.find_first_of('u') << endl;
    cout << st2.find_last_of('u') << endl;
    // find first and last missing idx wiht char.
    cout << st2.find_first_not_of('u') << endl;
    cout << st2.find_last_not_of('u') << endl;
    // get substring from a string wiht arg(first idx,str size);
    cout << st2.substr(1, 3) << endl;

    string s = "ab bc cd de ef fg gh";
    // stringstream takes string and devide string by space to make word.
    // stringstream strm(s);
    stringstream strm;
    strm << s;
    string w;
    while (strm >> w)
    {
        cout << w << endl;
    }
    st2.clear();
    // .capacity return minimum capacity 15
    cout << st2.capacity() << endl;
    //.size return actual size
    cout << st2.size() << endl;

    return 0;
}