#include<iostream>
#include<regex>
using namespace std;

bool passwordChecking(string password)
{
    regex pattern("(?=.*[a-z])(?=.*[0-9])(?=.*[A-Z])(?=.*[!@#$%?/~_+-=])[a-zA-Z0-9!?].{5,11}");
    return regex_match(password,pattern);
}
int main()
{
    string str;
    cout<<"Enter your password:"<<endl;
    cin>>str;
    if(passwordChecking(str))
        cout<<"Your password is valid"<<endl;
    else
        cout<<"Your password is invalid"<<endl;
    return 0;
}