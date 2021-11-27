/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Cameron Parrish
 */

#include "Header.h"


class Name_Value {       
public:    
    string Name;
    int number;         
};

void output(vector<Name_Value> Container, int max) {
    for (int i = 0; i < max; i++) {
        std::cout << "\n\n( " << Container.at(i).Name << " , " << Container.at(i).number << " )\n\n";
    }
}

vector<Name_Value> NameAdd(vector<Name_Value> Container, int i) {
    Name_Value add;

    std::cout << "Enter the Name: ";
    cin >> add.Name;


    for (int j = 0; j < i; j++) {
        if (Container.at(j).Name == add.Name) {
            std::cout << "This name has already been entered. Terminating. ";
            output(Container, i);
            exit(1);
        }
    }

    std::cout << "Enter the Number: ";
    cin >> add.number;

    Container.insert(Container.begin() + i, add);

    

    return Container;
}




int main() {
    vector<Name_Value> Container;
    int i = 0;

    
    while (1) {
        Container = NameAdd(Container, i);
        if (Container.at(i).Name == "NoName" && Container.at(i).number == 0) {
            i += 1;
            break;
        }
            
        i += 1;
    }
    
    
    output(Container, i);
    


    return 0;
}