#include <iostream>
using namespace std;

int fibonacci(int n);
void printSequence(int n);
int countEven(int n);
int sumSequence(int n);

int main(){
    int choice;
    int n;

    do{
        cout << "===========================================\n"
         << "\tFIBONACCI SEQUENCE ANALYZER\n"
         << "===========================================\n"
         << "1 - Display first n Fibonacci terms\n"
         << "2 - Find Fibonacci term at index n\n"
         << "3 - Count even terms among the first n\n"
         << "4 - Sum first n Fibonacci terms\n"
         << "0 - Exit\n"
         << "> ";
        cin >> choice;

        switch(choice){
            case 1:
                do{
                    cout << "\nEnter a value from 1 to 20: ";
                    cin >> n;

                    if(n > 20 || n < 0){
                         cout << "Invalid number; retry\n";
                    }
                }while(!(n > 0 && n < 21));
            
                printSequence(n);
                break;
            case 2:
                do{
                    cout << "\nEnter a value from 1 to 20: ";
                    cin >> n;

                    if(n > 20 || n < 0){
                        cout << "Invalid number; retry\n";
                    }else{
                        cout << "F(" << n << ") = " << fibonacci(n) << "\n"; 
                    }
                }while(!(n > -1 && n < 21));
    
                break;
            case 3:
                 do{
                    cout << "\nEnter a value from 1 to 20: ";
                    cin >> n;

                    if(n > 20 || n < 0){
                        cout << "Invalid number; retry\n";
                    }
                }while(!(n > 0 && n < 21));
    
                cout << "Even count = " << countEven(n) << '\n';
                break;
            case 4:
                 do{
                    cout << "\nEnter a value from 1 to 20: ";
                    cin >> n;

                    if(n > 20 || n < 0){
                        cout << "Invalid number; retry\n";
                    }
                }while(!(n > 0 && n < 21));

                cout << "Sum = " << sumSequence(n) << '\n';
                break;
            case 0:
                cout << "Thank you for using the program!";
                return 0;
                break;
            default:
                cout << "Invalid number; retry\n";
                break;
        }
    }while(!(choice > -1 && choice < 4));
    
    return 0;
}

int fibonacci(int n){
    if(n == 0){
        return 0;
    }else if(n == 1){
        return 1;
    }else{
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int countEven(int n){
    int evenCount = 0;

    for(int i = 0; i < n; i++){
        if(fibonacci(i) % 2 == 0){
            evenCount++;
        }
    }
    return evenCount;
}

int sumSequence(int n){
    int sum = 0;

    for(int i = 0; i < n; i++){
        sum += fibonacci(i);
    }
    return sum;
}

void printSequence(int n){
    cout << "Sequence = ";

    for(int i = 0; i < n; i++){
        cout << fibonacci(i);

        if(i < n - 1){
            cout << " ";
        }
    }
    cout << '\n';
}