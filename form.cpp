#include<iostream>
#include<fstream>
// #include  <bits/stdc++.h> 
using namespace std;
class temp{
    string  userName, Email, password;
    string searchName, searchPass, searchEmail;
    fstream file;
    public:
     void  login();
     void signup();
     void forgot();

}obj;
int main(){
    char choice;
    cout<<"1.Login"<<endl;
    cout<<"2.Sign Up"<<endl;
    cout<<"3.Forget Password"<<endl;
    cout<<"4.Exit"<<endl;
    cout<<"Enter your Choice :: ";
    cin>>choice;
    switch(choice){
        case '1':
        cin.ignore();
        obj.login();
        break;
        case '2':
        cin.ignore();
        obj.signup();
        break;
        case '3':
        cin.ignore();
        obj.forgot();
        break;
        case '4':
        return 0;
        break;
        default:
        cout<<"Invalid Selection";

    }
}
void temp :: signup(){
    cout<<"Enter your user name"<<endl;
    getline (cin, userName);
    cout<<"Enter your Email address"<<endl;
    getline(cin, Email);
    cout<<"Enter your password"<<endl;
    getline(cin, password);
    
    
    file.open("loginData.txt",ios :: out | ios :: app);
    file<<userName<<"*"<<Email<<"*"<<password<<endl;
    file.close();

}
void temp :: login(){
    cout<<endl;
    cout<<"-----------LOGIN-----------"<<endl;
    cout<<"Enter your UserName :: "<<endl;
    getline(cin, searchName);
    cout<<"Enter your Password :: "<<endl;
    getline(cin, searchPass);
    file.open("loginData.txt", ios :: in);
    getline(file, userName,'*');
    getline(file, Email,'*');
    getline(file, password,'\n');
    while(!file.eof()){
    if(userName==searchName){
        if(password == searchPass){
            cout<<"Account login Successfull..."<<endl;
            cout<<"Username :: "<<userName<<endl;
            cout<<"Email :: "<<Email<<endl;
        }
        else{
            cout<<"Incorrect Credentials"<<endl;
        }
    }
    getline(file, userName,'*');
    getline(file, Email,'*');
    getline(file, password,'\n');


    }
    file.close();
}
void temp :: forgot(){
    cout<<"Enter your Username"<<endl;
    getline(cin, searchName);
    cout<<"Enter your Email"<<endl;
    getline(cin, searchEmail);
    file.open("loginData.txt", ios :: in);
    getline(file, userName,'*');
    getline(file, Email,'*');
    getline(file, password,'*');
    while(!file.eof()){
        if(userName==searchName){
            if(Email==searchEmail){
                cout<<"Your passworrd is :: "<<password<<endl;
            }
            else{
                cout<<"No such Email found.."<<endl;
            }
        }
        else{
            cout<<"No such userName found"<<endl;
        }
    getline(file, userName,'*');
    getline(file, Email,'*');
    getline(file, password,'*');
    }
    file.close();
}