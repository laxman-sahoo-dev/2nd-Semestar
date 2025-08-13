#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{   
    string input;
    ofstream file("user_input.txt");
    if(file.is_open())
    {
        cout<<"Enter the text to write to the file(type exit ti stop) -"<<endl;
        while(true)
        {
            getline(cin,input);
            if(input=="exit")
                break;
            file<<input<<endl;
        }
        file.close();
        printf("Data written to file successfully\n");
    }
    else{
        cout<<"fiiled open to the file!!";
    }
}