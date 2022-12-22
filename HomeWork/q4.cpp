#include<iostream>
#include<regex>
using namespace std;

bool checkingEmail(string email)
{
    regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(email,pattern);
}
int main()
{
    string str;
    cout<<"Enter your Email-Id:"<<endl;
    cin>>str;
    if(checkingEmail(str))
        cout<<"Your Email-Id is valid"<<endl;
    else
        cout<<"Your Email-Id is invalid"<<endl;
    return 0;
}