#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <fstream>

#define FILE "register.txt"

using namespace std;
class Bank {
 
    // Private variables used inside class
private:
    string name;
    int accnumber;
    char type[10];
    int amount = 0;
    int tot = 0;
    int pin;
 
    // Public variables
public:
    // Function to set the person's data
    void setvalue()
    {
        char ch[2];
        cout << "Enter name\n";
        cin.ignore();
 
        // To use space in string
        getline(cin, name);
 
        cout << "Enter Account number\n";
        cin >> accnumber;
        cout << "Enter Account type: Saving or Current?\n";
        cin >> type;
        cout << "Generate your pin number\n";
        cin >> pin;
        cout << "Deposit Initial Balance (>=1000 for Saving and <=3000 for Current)\n";
        cin >> tot;
        if(tot<1000)
        {
          cout << "Error!! Please follow above rules for your account type\n";
          cout << "Go back to start\n";
        }
          else if(tot>3000)
          {
              cout << "Error!! Please follow above rules for your account type\n";
              cout << "Go back to start\n";
          }
        else
        {
            cout << "Welcome!! Your account was Created\n";
        }
        cout<<"\nPress Enter to continue...";
	    cin.ignore();
	    cin.getline(ch, 2, '\n');
    }
 
    // Function to display the required data
    void showdata()
    {
        char ch[2];
        cout << "Name:" << name << endl;
        cout << "Account No:" << accnumber << endl;
        cout << "Account type:" << type << endl;
        cout << "Balance:" << tot<< endl;
        cout<<"\nPress Enter to continue...";
	    cin.ignore();
	    cin.getline(ch, 2, '\n');
    }
 
    // Function to deposit the amount in ATM
    void deposit()
    {
        int acc_no;
        int Pin;
        char ch[2];
        cout<< "Enter the Account Number\n";
        cin>> acc_no;
        cout<< "Enter the Pin Number\n";
        cin>>Pin;
        if(acc_no==accnumber && Pin==pin)
        {
            cout << "\nEnter amount to be Deposited\n";
            cin >> amount;
            tot+= amount;
            amount= 0;
        }
        else
            cout << "\nInvalid Credentials!\n";
        cout<<"\n\n\n\nPress Enter to continue...";
	    cin.ignore();
	    cin.getline(ch, 2, '\n');
    }
 
    // Function to show the balance amount
    void showbal()
    {
        char ch[2];
        cout << "\nTotal balance is: " << tot;
        cout<<"\n\n\n\nPress Enter to continue...";
	    cin.ignore();
	    cin.getline(ch, 2, '\n');
    }
    
    // Function to change pin number
    void pinchang()
    {
       int OpinNo, CpinNo;
       char ch[2];
       cout <<"Enter your old pin number\n";
       cin >> OpinNo;
       if(OpinNo==pin)
        {
            cout <<"Enter new pin number\n";
            cin >> CpinNo;
            pin= CpinNo;
            cout <<"Congrats!! Your Pin number is Updated...\n";
        }
        else
        {
            cout << "\nInvalid Pin No!\n";
        }
       cout<<"\n\n\n\nPress Enter to continue...";
	   cin.ignore();
	   cin.getline(ch, 2, '\n');
    }

    // Function to withdraw the amount in ATM
    void withdrawl()
    {
        int pin_no;
        int a;
        char chr;
        char ch[2];
        cout<<"Firstly Do you want Receipt?\n" << "Enter Y for Yes: Enter N for No\n";
        cin>>ch;
           if (chr=='Y'|| chr=='y')
			{
				cout<< "Here your details\n";
			}
			else
			{
		
			}
        cout << "Enter your Pin number\n";
        cin>> pin_no;
        if(pin_no==pin)
        {
            cout << "Enter amount to withdraw\n";
            cin >> a;
            if(a<=tot)
            {
                cout << "Withdrawal successful!\n";
                tot -= a;
                cout << "Available Balance is\n" << tot;
            }
            else
                cout << "Account does not have enough balance!\n";
        }
        cout<<"\n\n\n\nPress Enter to continue...";
	    cin.ignore();
	    cin.getline(ch, 2, '\n');
    }

// Function using File handing to read, write & store account details

void showReg()
{
	system("cls");
	Bank obj;
	int i=0;
	ifstream in;
	in.open("register.txt", ios::in);
	in.read((char *)&obj, sizeof(obj));
	while(!in.eof())
	{
		cout<<"Entry no. "<<++i<<": \n";
		obj.showdata();
		cout<<endl<<endl;
		in.read((char *)&obj, sizeof(obj));
	}
	in.close();
	cout<<"\n\n\nTotal number of entries so far: "<<i;
	char ch[2];
	cout<<"\n\n\n\nPress Enter to continue...";
	cin.ignore();
	cin.getline(ch, 2, '\n');	
}


// 	atm a;

// 	ifstream file1;

// 	// Open file in read mode
// 	file1.open("aaa.txt", ios::in);
// 	if (!file1) {
// 		cout << "Error in opening file..";
// 		return 0;
// 	}

// 	// Read data from file
// 	file1.read((char*)&a, sizeof(a));
// 	while (!file1.eof()) {

// 		// Display data on monitor
// 		a.showData();
// 		file1.read((char*)&a, sizeof(a));
// 	}

// 	// Close the file
// 	file1.close();
// 	return 0;
// }

    // Function to cancel the process in ATM
    void canl()
    {
        cout<< "\nTHANK YOU FOR VISTING\n";
    }
};
 
// Driver Code
int main()
{
    
    // Give color in program
    system("color A0");
    
    // Object of class
    Bank b;
    int choice;
 
    // Infinite while loop to choose
    // options everytime
    system("cls");
    while (1) {
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~"
             << "~~~~~~~~~~~~~"
             << "~ WELCOME TO UCO BANK ~~~~~~~~~~~~~~~~~~"
             << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
             << "~~~~~~~~~\n\n";
         
         // It gives current date & time
         time_t timetoday;
         time(&timetoday);
         cout << "TODAY THE DATE and TIME ;\n" <<asctime(localtime(&timetoday));
         cout << "\n";

        cout << "\t1. Create an Account.\n";
        cout << "\t2. Deposit Money.\n";
        cout << "\t3. Change Pin Number.\n";
        cout << "\t4. Show Account Preview.\n";
        cout << "\t5. Withdraw Money.\n";
        cout << "\t6. Show Register file.\n";
        cout << "\t7. Total balance.\n";
        cout << "\t8. Exit ATM.\n";
        cout << "\nSelect the Option (1-8).\n";
        cin >>choice;
        system("cls");
 
        // Choices to select from
        switch (choice)
        {
        case 1:
            b.setvalue();
            break;
        case 2:
            b.deposit();
            break;
        case 3:
            b.pinchang();
            break;
        case 4:
            b.showdata();
            break;
        case 5:
            b.withdrawl ();
            break;
        case 6:
            b.showReg();
            break;
        case 7:
            b.showbal ();
            break;
        case 8:
            b.canl();
            exit(1);
        default:
            cout << "\nInvalid choice\n";
        }
    }
}