//Steven An 2015
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include "linkedList.h"

using namespace std;
void printPlug();
void printMenu();
string getUsername();
string trimMe(const string input, int/*num of args to trim off*/ pos)
{
    int space, numSpace = 0;
    for(int i = 0; i < input.length(); i++)
    {
        if(isspace(input[i]))
        {
            space = i;
            ++numSpace;
        }
        if(numSpace == pos)
            break;
    }
    if(numSpace < pos)
        return " ";
    return input.substr(space + 1, string::npos); //+1 to clear space as well, npos is EOstring
}
void printer(linkedList<string>* printMe, bool line)
{
    int listSize = printMe->getItemCount();
    for(int i = 0; i < listSize; i++)
    {   
        if(line)
            cout << i + 1 << " : ";
        cout << printMe->getItemAtIndex(i) << endl;
    }
}

int main(int argc, char* argv[])
{
    string input;
    string userName = "user";
    bool line = false;
    if(argc > 1)
    {
        if(strcmp(argv[1],"-u") == 0 && argc == 3)
        {
            userName = argv[2];
        }
        else if(strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
        {
            cout << "Options: " << argv[0] << " -u [username]\n";
            return 0;
        }
        else
        {
            cout << "Usage: " << argv[0] << "-h\n";
            return -1;
        }
    }  
    printPlug();
    printMenu();
    cout << endl;
    linkedList<string>* textBody = new linkedList<string>;
    while(1)
    {
        cout << userName << "@sVim ~ ";
        getline(cin, input);
        if(input[0] == 'q')
        {
            break;
        }
        else if(strcmp(input.c_str(), "exit") == 0)
        {
            cout << "Try 'quit' instead\n";
        }
        else if(input[0] == 'm')
            printMenu();
        else if(input[0] == 'i')
        {
            string toList = trimMe(input, 1);
            textBody->insert(toList);
            cout << "written " << textBody->getItemCount();
            cout << " line\n";           
        }
        else if(input[0] == 'd')
        {
            printer(textBody, line);                  
        }
        else if(input[0] == 'l')
        {
            if(line)
            {
                line = false;
                cout << "line numbers OFF\n";
            }
            else
            {
                line = true;
                cout << "line numbers ON\n";
            }
        }
        else if(input[0] == 'r')
        {
            string toInt = trimMe(input, 1);
            int pos = atoi(toInt.c_str());
            cout << "DELETED LINE: ";
            cout << textBody->removeItemAtIndex(pos + 1);
            cout << endl;
        }
    }
    return 0;
}

void printPlug()
{
    cout << "Welcome to sVim\nWritten by Steven An\nwww.github.com/stevenan93\n";
    cout << "Press m for menu\n";
}

string getUsername()
{
    string user;
    cout << "Please enter in your username: ";
    getline(cin, user);
    return user; 

}

void printMenu()
{
    cout << "---MAIN CONTROLS---\n"
         << "m                  PRINT MENU\n"
         << "i [text]           INSERT TEXT\n"
         << "l                  TOGGLE LINE NUMBER\n"
         << "n [line] [text]    LINE INSERT\n"
         << "d                  DISPLAY\n"
         << "r [line]           DELETE LINE\n"
         << "q                  QUIT\n";
}
