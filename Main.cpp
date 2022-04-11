#include "Matrix.hpp"
#include <iostream>
using namespace std;
using namespace zich;
void insertMat(Matrix & mat) {
    while (true) {
        try {
            cin >> mat;
            break;
        } catch (exception &e) {
            cout << " caught exception : " << e.what() << " please enter again the two matrix's one by one" << endl;
        }
    }
}
int main() {
    Matrix a;
    Matrix b;
    int action;
    cout << "Hello this is a matrix world" << endl <<
         "please enter arguments to your mtwo matrix that we will create for you" << endl <<
         "the syntax should be as the following example 1 2 3, 23 2 1, 1 1 1, "
         "meaning for after every number insert space and after each row insert ',' and than space" << endl;
    insertMat(a);
    insertMat(b);
    cout<<"excellent we got this far meaning you got your matrix now you can do couple of action on them"<<endl<<
        "- to add them and see the result type 1"<<endl<<
        "- to multiply them and see the result type 2"<<endl<<
        "- to subtract them and see the result type 3"<<endl<<
        "- to see which one is bigger and see the result type 4"<<endl<<
        "- to exit  the program type 5"<<endl;
    cout<<"please enter your number"<<endl;
    cin>>action;
    while(true){

        switch (action) {
            case 1:
                cout<<(a+b)<<endl;
                break;
            case 2:
                cout<<(a*b)<<endl;
                break;
            case 3:
                cout<<(a-b)<<endl;
                break;
            case 4:
                cout<<"a < b =";
                if(a<b){
                    cout<<"True"<<endl;
                }else{
                    cout<<"False"<<endl;
                }
                break;
            case 5: cout<<"Goodbye";
                break;
            default:
                cout<<"enter one of the the number you were told to"<<endl;
        }
        cin>>action;
        if (action==5){
            cout<<"Goodbye"<<endl;
            break;
        }
    }


}