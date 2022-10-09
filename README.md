# Data structure and algorithm
---
---
 The totally beginer to write some basic data structure and alogorithm. If you like it, please clink the star at the right side corner, thank you so much.

All the code is basic on C/C++, might some time I will add some OOP content.

The code will be:
```C++
#include "iostream"         //Include basic input output stream.
using namespace std;
typedef int elementType;    //Personalized the element type of linked list.
class Node{
public:
    elementType Data;       //The data part of the Node.
    class Node* Next;       //The pointer part of the Node, using to express the logic relationship.
    Node () : Data (0), Next(nullptr) {}        //Constructor of the Node, using to initialize the Node.
    friend ostream& operator<<(std::ostream &os, Node* node);       //Friend function in order to overload
                                                                    // the operator "<<" to convince output.
};
typedef Node* tempNode;     //Custom the pointer type of Node.

ostream& operator<<(std::ostream &os, Node* node){   //Parameter 1: the stander ostream;
    node = node->Next;                               //Parameter 2: the pointer of Node.
    int count = 0;                  //Format the output. Counting the output times.
    os << "Printing..." << endl;
    while(node != nullptr){         //Using the loop to output hole linked list.
        os << node->Data << "\t";   //Print the data part of the Node.
        count++;                    //Increasing the count.
        if (count == 10){           //Has already output 10 data, then change the line.
            os << endl;             //Change the line.
            count = 0;              //Reset the count variable value.
        }
        node = node->Next;          //Output the next one.
    }
    os << endl
    << "Printing over." << endl;
    return os;                      //Return the stander ostream.
}
```


Because I'm just a rookie about code, if have any bug, welcome to message with me.
