#include<iostream>
#include <vector>
#include <thread> 
#include <chrono>
#include <cstdlib>
using namespace std;

bool login(int &pin, int p_o_s){
    cout << "enter the password: " << endl;
    cin >> pin;
    if(pin == p_o_s){
      return true ;
    }
    return false;
}

bool cash(int money_exist, int &m_to_wisdraw){
     cout << "enter the price: " << endl;
     cin >> m_to_wisdraw;
     if(money_exist >= m_to_wisdraw){
         return true;
     }
     return false;
}

int main(){
    int pin, p_o_s, money_exist, m_to_wisdraw, choose,put;
    cout << "******************welcome to the ATM machine***************" << endl;
    cout << "please register first to your account" << endl;
    p_o_s = 123;
    money_exist = 1000;
    bool pin_right = login(pin, p_o_s);
 
    if (pin_right){
        while (true){ 
            cout << "choose what you want to do" << endl;
            cout << "1- withdraw" << endl;
            cout << "2- put" << endl;
            cout << "3- inform" << endl;
            cout << "4- exit" << endl;
            cin >> choose;
    
            if(choose == 1){
                if(cash(money_exist, m_to_wisdraw)){
                    money_exist = money_exist - m_to_wisdraw; 
                    
                    cout << "you took " << m_to_wisdraw << " pounds and you have now " << money_exist << " pounds" << endl;
                    this_thread::sleep_for(chrono::seconds(4));
                    system("cls");
                } else {
                    cout << "Not enough money!" << endl;
                    this_thread::sleep_for(chrono::seconds(4));
                    system("cls");
                }
            }
            else if (choose == 2) {
               cout<<"how much money do you want to put? "<<endl;
               cin>>put;
               money_exist += put;
               cout<<"your money was: "<<money_exist - put<<" and now is: "<<money_exist<<endl;
               this_thread::sleep_for(chrono::seconds(4));
                system("cls");

            }
            else if (choose == 3) {
              
                cout << "Your current balance is: " << money_exist << " pounds" << endl;
                this_thread::sleep_for(chrono::seconds(4));
                system("cls");
            }
            else if (choose == 4){
                break;
            }
            else {
                cout << "Invalid choice!" << endl;
            }
        }
    } else {
        cout << "Wrong PIN code!" << endl;
    }
}
