// Password Generator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int n, arr[4], sym, exit1 = 1;
char ch;

class password {
    char* pass;
public :
        password() {
          pass = NULL;
        }
        ~password(){
        	delete pass;
		}
        void generate();
    };
void password::generate() {
    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 0;
    arr[3] = 0;
    system("cls");

    //password length
    cout << "Enter the length of the password : ";
    cin >> n;
    pass = new char(n);

    //options
    cout << "Include Symbols(y : yes ; n : no) : ";
    cin >> ch;
    if (ch == 'y') {
        arr[0] = 1;
    }
    cout << "Include Numbers(y : yes ; n : no) : ";
    cin >> ch;
    if (ch == 'y') {
        arr[1] = 2;
    }
    cout << "Include Uppercase(y : yes ; n : no) : ";
    cin >> ch;
    if (ch == 'y') {
        arr[2] = 3;
    }
    cout << "Include Lowercase(y : yes ; n : no) : ";
    cin >> ch;
    if (ch == 'y') {
        arr[3] = 4;
    }

    //generating password
    for (int i = 0; i < n; i++) {
        
        int option;
        do {
            option = arr[rand() % 4];
        } while (option == 0);

        // randomizing option

        switch (option) {
        case 1:
            // randomizing symbols
            int a;
            a = rand() % 3;
            switch (a) {
            case 0:
                sym = rand() % (47 - 33 + 1) + 33;
                break;
            case 1:
                sym = rand() % (64 - 58 + 1) + 58;
                break;
            case 2:
                sym = rand() % (96 - 91 + 1) + 91;
                break;
            case 3:
                sym = rand() % (126 - 123 + 1) + 123;
                break;
            }
            *(pass + i) = sym;
            break;
        case 2:
            *(pass + i) = rand() % (57 - 48 + 1) + 48;
            break;
        case 3:
            *(pass + i) = rand() % (90 - 65 + 1) + 65;
            break;
        case 4:
            *(pass + i) = rand() % (122 - 97 + 1) + 97;
            break;

        }
    }

    //Printing password
    cout << endl << "Password is : ";
    for (int i = 0; i < n; i++) {
        cout << *(pass + i);
    }

    //delete pass;
}



int main()
{

    password ps;

    
    while (exit1 != 0) {
        
        srand(time(0));

        ps.generate();
        
        //exit condition
        cout << endl << "Enter 0 if you want to exit / anything else for regenerating : ";
        cin >> exit1;
        
   }
    
}
    
