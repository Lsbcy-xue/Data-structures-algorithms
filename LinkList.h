//
// Created by Xz on 10/5/22.
//

#ifndef DATA_STRUCTURE_ALGORITHM_LINKLIST_H
#define DATA_STRUCTURE_ALGORITHM_LINKLIST_H
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

void testLinkList();                    //The test function.
bool getInformation(elementType * &pArray, int &size);              //Get the information from the user, which though stander istream.
bool initialNode(tempNode &temp);       //Initial the linked list, which means to create a head node, then set the data to 0, pointer part nullptr.
bool createLinkList(tempNode const &temp, elementType const array[], int const &size);  //After get the information from the user, we will create the linked list.
void destroyLinkList(tempNode &temp);   //Destroy all the memory space that we created for the linked list.
bool insertHead(tempNode const &temp, elementType const &data);     //Insert the element get from the user to the linked list's head.
bool insertTail(tempNode const &temp, elementType const &data);     //Insert the element get from the user to the linked list's tail.
bool insertNode(tempNode const &temp, int const &index, elementType const &data);       //Insert the element to the position user appointed.
bool deleteNode(tempNode const &temp, int const &index, elementType &element);          //Delete the element to the position user appointed.
bool isEmpty(tempNode const &temp);     //Judge the linked list whether empty or not.
elementType lengthLinkList(tempNode const &temp);                   //Return the linked list's length.
bool getElement(tempNode const &temp, int const &index, elementType &element);          //Get the element's data which the position appointed by user.
bool locateElement(tempNode const &temp, int &index, elementType const &element);       //Locating the element which appointed by user.
bool splitLinkList(tempNode const &temp, tempNode &tempL, tempNode &tempR);             //Split the 1 list into 2 list, list L is ordered, list R is counter ordered.
void showMenu(int &index);              //Show all the functions' the system.

void showMenu(int &index){              //Call by reference, output type parameter.
    cout << "===================================================== \n";
    cout << " \t\t MENU \t \n ";
    cout << "===================================================== \n";
    cout << " \t1.Start and create a list \n";
    cout << " \t2.Insert element at head\n";
    cout << " \t3.Insert element at tail\n";
    cout << " \t4.Print the list \n";
    cout << " \t5.Locating the element \n";
    cout << " \t6.Get the length \n";
    cout << " \t7.Get the element \n";
    cout << " \t8.Delete the element \n";
    cout << " \t9.Insert the element\n";
    cout << " \t10.Split to two list\n";
    cout << " \t(Enter any number to quit the system) \n";
    cout << "===================================================== \n";
    cout << "===================================================== \n";
    cin >> index;                       //Get the input from the keyboard, then streaming into the index.
}

void testLinkList(){
    tempNode temp, tempL, tempR;        //Temp for the pointer to the head node; tempL, tempR for the split function.
    int size, index(1), position(0);    //Size for the capability of the dynamic array in getInformation function, createLinkList function;
                                        //index inorder to select functions in menu; position is to get the user's want position, delete or insert.
    elementType element;                //Get the insert element or the element which was deleted.
    elementType * pArray;               //The pointer for dynamic array.

    while (index <= 10 && index >= 1){  //If the index over than 10 or less than 1, quit the loop.
        showMenu(index);             //Call the function shouMenu, print all the functions, then waiting for user to select.
        switch (index) {
            case 1:                     //Start and create a list
                initialNode(temp);
                getInformation(pArray, size);
                createLinkList(temp, pArray, size);
                cout << temp;
                break;
            case 2:                     //Insert element at head
                cout << endl << "Please enter the data number: " << endl;
                cin >> element;
                insertHead(temp, element);
                cout << temp;
                break;
            case 3:                     //Insert element at tail
                cout << endl << "Please enter the data number: " << endl;
                cin >> element;
                insertTail(temp, element);
                cout << temp;
                break;
            case 4:                     //Print the list
                cout << temp;
                break;
            case 5:                     //Locating the element
                cout << endl << "Please enter the number you want locating: " << endl;
                cin >> element;
                position = locateElement(temp, position, element);
                cout << "The location is: " << position << ". " << endl;
                break;
            case 6:                     //Get the length
                cout << "The length of the list is: " << lengthLinkList(temp) << ". " << endl;
                break;
            case 7:                     //Get the element
                cout << "Please enter the position you want to get: " << endl;
                cin >> position;
                getElement(temp, position, element);
                cout << "The element is: " << element << ". " << endl;
                break;
            case 8:                     //Delete the element
                cout << "Please enter the position you want to delete: " << endl;
                cin >> position;
                deleteNode(temp, position, element);
                cout << "The deleted element is: " << element << ". " << endl;
                cout << temp;
                break;
            case 9:                     //Insert the element
                cout << "Please enter the position you want to insert: " << endl;
                cin >> position;
                cout << endl << "Please enter the data number: " << endl;
                cin >> element;
                insertNode(temp, position, element);
                cout << temp;
                break;
            case 10:                    //Split the linked list
                splitLinkList(temp, tempL, tempR);
                cout << "The L1: ";
                cout << tempL;
                cout << "The L2: ";
                cout << tempR;
                break;
            default:
                cout << "Quiting....." << endl;
                break;
        }
    }
    destroyLinkList(temp);          //Destroy the linked list.
}

bool getInformation(elementType * &pArray, int &size){
    cout << "Please enter the size of the list: " << endl;
    cin >> size;
    pArray = new elementType [size];    //Request the memory space at stack.
    if (pArray == nullptr){             //If request not success, return nullptr, quit the function.
        cout << "The memory is full, please try again. " << endl;
        return false;
    }
    for (int i = 0; i < size; ++i) {    //Get the element from the keyboard.
        cout << "Please enter the " << i + 1 << "th element. " << endl;
        cin >> pArray[i];
    }
    cout << "All the elements are input over. " << endl;
    return true;
}

bool initialNode(tempNode &temp){
    temp = new Node;
    if (temp == nullptr){   //If request failed, return nullptr, quit the function.
        cout << "The Node initialized fail! " << ". " << endl;
        return false;
    }
    return true;
}

bool createLinkList(tempNode const &temp, elementType const array[], int const &size){
    if (temp == nullptr) {
        cout << "The memory is full, please try again. " << endl;
        return false;
    }
    else{
        for (int i = size - 1; i >= 0; i--) {       //
            auto newNode = new Node;                //
            newNode->Next = temp->Next;             //
            newNode->Data = array[i];               //
            temp->Next = newNode;
            temp->Data++;
        }
        return true;
    }
}

void destroyLinkList(tempNode &temp){
    tempNode previous(temp), current(temp->Next);
    while (current != nullptr){
        delete previous;
        previous = current;
        current = current->Next;
    }
    delete previous;
    temp = nullptr;
}

bool insertHead(tempNode const &temp, elementType const &data){
    if (temp == nullptr){
        cout << "The linked list isn't exits. " << endl;
        return false;
    }
    auto newNode = new Node;
    newNode->Next = temp->Next;
    newNode->Data = data;
    temp->Next = newNode;
    temp->Data++;
    return true;
}

bool insertTail(tempNode const &temp, elementType const &data){
    auto temp1 = temp;
    if (temp == nullptr){
        cout << "The linked list isn't exits. " << endl;
        return false;
    }
    while (temp1->Next != nullptr){
        temp1 = temp1->Next;
    }
    auto newNode = new Node;
    newNode->Next = nullptr;
    newNode->Data = data;
    temp1->Next = newNode;
    return true;
}

bool insertNode(tempNode const &temp, int const &index, elementType const &data){
    if (temp == nullptr){
        cout << "The linked list isn't exits. " << endl;
        return false;
    }
    else if (temp->Data < index){
        cout << "The delete position invalid." << endl;
        return false;
    }
    tempNode current = temp->Next;
    tempNode previous = temp;
    int count(1);
    while (current != nullptr && count < index) {
        previous = current;
        current = current->Next;
        count++;
    }
    auto newNode = new Node;
    newNode->Next = current;
    newNode->Data = data;
    previous->Next = newNode;
    return true;
}

bool deleteNode(tempNode const &temp, int const &index, elementType &element){
    if (temp == nullptr){
        cout << "The linked list isn't exits. " << endl;
        return false;
    }
    else if (temp->Data < index){
        cout << "The delete position invalid." << endl;
        return false;
    }
    else if (isEmpty(temp)){
        cout << "The linked list is empty." << endl;
        return false;
    }
    tempNode current = temp->Next;
    tempNode previous = temp;
    int count(1);
    while (current != nullptr && count < index) {
        previous = current;
        current = current->Next;
        count++;
    }
    element = current->Data;
    previous->Next = current->Next;
    delete current;
    return true;
}

bool isEmpty(tempNode const &temp){
    if (temp->Next == nullptr){
        return true;
    }
    else if (temp == nullptr){
        cout << "The linked list isn't exits. " << endl;
        return false;
    }
    return false;
}

elementType lengthLinkList(tempNode const &temp){
    return temp->Data;
}

bool getElement(tempNode const &temp, int const &index, elementType &element){
    if (temp == nullptr){
        cout << "The linked list isn't exits. " << endl;
        return false;
    }
    else if (temp->Data < index){
        cout << "The position invalid." << endl;
        return false;
    }
    else if (isEmpty(temp)){
        cout << "The linked list is empty." << endl;
        return false;
    }
    tempNode current = temp->Next;
    int count(1);
    while (current->Next != nullptr && count < index) {
        current = current->Next;
        count++;
    }
    element = current->Data;
    return true;
}

bool locateElement(tempNode const &temp, int &index, elementType const &element){
    if (temp == nullptr){
        cout << "The linked list isn't exits. " << endl;
        return false;
    }
    else if (isEmpty(temp)){
        cout << "The linked list is empty." << endl;
        return false;
    }
    tempNode current = temp->Next;
    int count(1);
    while (current->Next != nullptr && current->Data != element) {
        current = current->Next;
        count++;
    }
    index =count;
    return true;
}

bool splitLinkList(tempNode const &temp, tempNode &tempL, tempNode &tempR){
    if (temp == nullptr){
        cout << "The linked list isn't exits. " << endl;
        return false;
    }
    else if (isEmpty(temp)){
        cout << "The linked list is empty." << endl;
        return false;
    }
    tempNode current(temp->Next->Next), previous(temp->Next), tempLTail, cNext, pNext;
    tempL = temp;
    tempL->Data = 0;
    tempL->Next = nullptr;
    tempR = new Node;
    tempLTail = tempL;
    while (previous != nullptr){
        if (current == nullptr){
            tempLTail->Next = previous;
            tempLTail = previous;
            tempL->Data++;
            break;
        }
        else {
            cNext = current->Next->Next;
            pNext = current->Next;
        }
        tempLTail->Next = previous;
        tempLTail = previous;
        tempL->Data++;
        current->Next = tempR->Next;
        tempR->Next = current;
        tempR->Data++;
        current = cNext;
        previous = pNext;
    }
    tempLTail->Next = nullptr;
    return true;
}

#endif //DATA_STRUCTURE_ALGORITHM_LINKLIST_H
