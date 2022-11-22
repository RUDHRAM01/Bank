#include<bits/stdc++.h>
#include<time.h>
using namespace std;
int incr = 0;
class bank{
    private :

        string accountNo;
        string password;
        int balance;

    public : 

    string name;

    bank(){
        name = "new-user";
        balance = 0;
    };

    void show_data(){
        cout << "Name : " << name << "            |Account Number : " << accountNo << "             |Balance : " << balance << "\n";
    }

    void withdrawal(int money){
        if(money < 0){
            cout << "You can not enter negative value!";
            return;
        }
        if(money>balance){
            cout << "Your Current Account Balance : " << balance<<"\nInsufficient Balance!\nwe can not Proceed Further\n";
        }else{
            balance = balance - money;
            cout << "Your Transaction Completed \n";
        }
    }

    bool check(string acc_no,string pass){
        if(accountNo == acc_no && password == pass){
            return true;
        }else{
            return false;
        }
    }
   
    void create_new(string name,string password){
        incr++;
        srand(time(0));
        this->accountNo = to_string(rand()+incr);
        this->name = name;
        this->password = password;
        cout << "Please Note Your\nAccount No : " << accountNo<<"\n";
    }

    void depostie(int amount){
        balance += amount;
        cout << "Done!\n";
    }
    
    int show_balance(){
        return balance;
    }
};


int main(){
    vector<bank> user;
    bool k;
    int amount = 0;
    int logout = 0;
    string store;
    string acc_no;
    string pass;
    bank new_user = bank();
    string name;
    int choice,i;

    string admin = "Rudhram";
    string a_password = "rudyS";


    while (1)
    {
        cout << "Hello\n1. Login ( Already have an account )\n2. Signup ( New user )\n3. Login As Admin\n4. Exit\n\nEnter Your Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter your account no : ";
            cin >> acc_no;
            cout << "Password :  ";
            cin >> pass;

            for (i = 0; i < user.size(); i++)
            {
                k = user[i].check(acc_no, pass);
                if (k == true)
                {
                    cout << "yes\n";
                    break;
                }
                else
                {
                    continue;
                }
            }

            if (k == false)
            {
                cout << "Invalid User\n";
                break;
            }
            
            if (k == true)
            {
                store = user[i].name;
                cout << "\nHello " << store << "\n\n";
                while (1)
                {
                    cout << "----------Menu----------\n1. Deposit\n2. Withdrawal\n3. Balance\n4. Logout\n\nEnter Your Choice : ";
                    cin >> choice;
                    switch (choice)
                    {
                    case 1:
                        cout << "Deposit\nEnter Amount : ";
                        cin >> amount;
                        if (amount < 0)
                        {
                            cout << "ERROR! You can not enter negative value\n";
                            break;
                        }
                        user[i].depostie(amount);
                        break;
                    case 2:
                        cout << "Withdrawal\nEnter Amount : ";
                        cin >> amount;
                        user[i].withdrawal(amount);
                        break;
                    case 3:
                        cout << "Balance\nYour Account Balance : " << user[i].show_balance() << "\n";
                        break;
                    case 4:
                        cout << "GOODBYE!\n";
                        logout = 1;
                        break;
                    default:
                        cout << "Enter valid case\n";
                        break;
                    }
                    if (logout == 1)
                    {
                        logout = 0;
                        break;
                    }
                }
            }

            break;
        case 2:
            cout << "Hello\nPlease Enter Reuired Imformation\n";
            cout << "Enter Your Name : ";
            cin >> name;
            cout << "Enter Your Password : ";
            cin >> pass;
            new_user.create_new(name, pass);
            user.push_back(new_user);
            cout << "Done!\n";
            break;
        case 3:
            cout << "Admin\n";
            cout << "Enter User Name : ";
            cin >> name;
            cout << "Enter Password : ";
            cin >> pass;

            if(name == admin && pass == a_password){
                while (1)
                {
                cout << "Hello Rudhram Sir\n";
                cout << "----------Menu----------\n1. Show Users\n2. Logout\n\nEnter Your Choice : ";
                cin >> choice;
                while (1)
                {
                    if(choice == 1){
                        if(user.size() == 0){
                            cout << "No Data Found!\n";
                            break;
                        }
                        for (int i = 0; i < user.size(); i++)
                        {
                            user[i].show_data();
                        }
                        break;   
                    }else if(choice == 2){
                        logout = 1;
                        break;
                    }else{
                        cout << "Please Enter Valid Choice!";
                    }
                } 
                if(logout==1){
                    break;
                }
                } 
            }else{
                cout << "Invalid User!\n";
            }
            break;
        case 4:
            cout << "GOODBYE!\n";
            exit(0);
        default:
            cout << "please enter valid choice\n";
            break;
        }
}
    return 0;
}