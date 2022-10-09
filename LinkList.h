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
bool reverseList(tempNode const &temp);
bool deleteMaximumNode(tempNode const &temp);
bool sortList(tempNode const &temp);

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
    cout << " \t11.Reverse the list\n";
    cout << " \t12.Delete the maximum element\n";
    cout << " \t13.Sort the list\n";
    cout << " \t(Enter 0 to quit the system) \n";
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

    while (index <= 13 && index >= 1){  //If the index over than 10 or less than 1, quit the loop.
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
            case 11:
                reverseList(temp);
                cout << "The reverse list is: " << endl;
                cout << temp;
                break;
            case 12:
                deleteMaximumNode(temp);
                cout << temp;
                break;
            case 13:
                sortList(temp);
                cout << temp;
                break;
            default:
                cout << "Quiting....." << endl;
                break;
        }
    }
    destroyLinkList(temp);          //Destroy the linked list.
    destroyLinkList(tempR);
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
        for (int i = size - 1; i >= 0; i--) {       //Output the array in reverse order.
            auto newNode = new Node;                //create new Node.
            newNode->Next = temp->Next;             //Head insert.
            newNode->Data = array[i];               //Copy data into the node.
            temp->Next = newNode;                   //Head insert.
            temp->Data++;                           //The length of the linked list +1.
        }
        return true;
    }
}

void destroyLinkList(tempNode &temp){
    tempNode previous(temp), current(temp->Next);   //A pair of pointer.
    while (current != nullptr){                     //When the current is pointing to the null, break the loop.
        delete previous;                            //Delete the previous node.
        previous = current;                         //Move to the next one.
        current = current->Next;
    }
    delete previous;         //Because when the loop break out, the end of the node doesn't delete yet,
    temp = nullptr;          //so we need to delete the end of the node, which is pointed by previous.
}

bool insertHead(tempNode const &temp, elementType const &data){
    if (temp == nullptr){
        cout << "The linked list isn't exits. " << endl;
        return false;
    }
    auto newNode = new Node;
    newNode->Next = temp->Next;     //Linking the new node in front of the 1st node.
    newNode->Data = data;           //Input the data.
    temp->Next = newNode;           //Linking the new node after the head node.
    temp->Data++;                   //The length of the linked list +1.
    return true;
}

bool insertTail(tempNode const &temp, elementType const &data){
    auto temp1 = temp;   //The variable for loop, locating the linked list's tail.
    if (temp == nullptr){
        cout << "The linked list isn't exits. " << endl;
        return false;
    }
    while (temp1->Next != nullptr){
        temp1 = temp1->Next;        //Find the linked list's tail.
    }
    auto newNode = new Node;
    newNode->Next = nullptr;        //Initial the new node.
    newNode->Data = data;
    temp1->Next = newNode;         //Insert at the end of the list.
    return true;
}

bool insertNode(tempNode const &temp, int const &index, elementType const &data){
    if (temp == nullptr){
        cout << "The linked list isn't exits. " << endl;
        return false;
    }
    else if (temp->Data < index){       //Determinate whether the position is valid.
        cout << "The delete position invalid." << endl;
        return false;
    }
    tempNode current = temp->Next;      //The pair of pointer, the current is for loop to find the ith node;
    tempNode previous = temp;           //the previous is before 1 of the current, to locate the i-1th node.
    int count(1);                       //Loop assistant variable.
    while (current != nullptr && count < index) {  //To find the ith & i-1th node,
        previous = current;                        //and then insure scope is in the list.
        current = current->Next;
        count++;
    }
    auto newNode = new Node;
    newNode->Next = current;            //Insert the new node after the i-1th node, in front of the ith node.
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
    else if (isEmpty(temp)){   //Determinate the linked list whether the empty or not, if is, we can't do anything.
        cout << "The linked list is empty." << endl;
        return false;
    }
    tempNode current = temp->Next;  //The same logic thought of insert, don't repeat.
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
    while (current->Next != nullptr && count < index) { //Loop to reach the ith node,then return it.
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
    while (current != nullptr && current->Data != element) {
        current = current->Next;        //Loop for find the data in the list.
        count++;
    }
    if (current == nullptr){            //If the current is the nullptr, meaning the element isn't exits.
        cout << "The element doesn't exits. " << endl;
        return false;
    }
    index =count;
    return true;
}

/*
 *                     The Algorithm Logic Over-view:
 * Split into the two linked list, the list left using the original head node,
 * but the list right using the new head node. So the 1st thing we need to traverse
 * the original linked list, the odd nodes into the list left by positive order,
 * the even nodes into the list right, which is inverse order.
 * So, we think that the list left using the tail insert, the list right using
 * head insert.
 * In order to implement this algorithm, we need two the pair of pointer, in which
 * we move the odd one to the list left, the even one to the right list, and also we
 * don't disorient the next node's address.
*/

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
    tempL = temp;           //Protect the original pointer, which is the const pointer.
    tempL->Data = 0;        //Reset the list-left's head node (also reset the length of the list),
    tempL->Next = nullptr;  //and break the henge between head to the 1st node.
    tempR = new Node;       //Construct the new head node for list right.
    tempLTail = tempL;      //The assistant pointer, which always pointing the end of the list left.
    while (previous != nullptr){
        if (current == nullptr){        //If the original list have odd number of the nodes, we need
            tempLTail->Next = previous; //to consider that the end of the node doesn't go to the list
            tempLTail = previous;       //left yet, so we need do that.
            tempL->Data++;              //Linked list's length +1.
            break;
        }
        else if (current->Next != nullptr && current->Next->Next != nullptr){
            cNext = current->Next->Next;    //The pair of pointer to store the information of the original
            pNext = current->Next;          //list, to insure the address will not lose.
        }
        tempLTail->Next = previous;         //List left for tail insert.
        tempLTail = previous;
        tempL->Data++;
        current->Next = tempR->Next;        //List right for head insert.
        tempR->Next = current;
        tempR->Data++;
        if (current == cNext && previous == pNext)
            break;
        current = cNext;
        previous = pNext;
    }
    tempLTail->Next = nullptr;
    return true;
}

bool reverseList(tempNode const &temp){
    if (temp == nullptr){
        cout << "The linked list isn't exits. " << endl;
        return false;
    }
    else if (isEmpty(temp)){
        cout << "The linked list is empty." << endl;
        return false;
    }
    tempNode current = temp->Next;
    tempNode next;
    temp->Next = nullptr;
    while (current != nullptr){
        next = current->Next;
        current->Next = temp->Next;
        temp->Next = current;
        current = next;
    }
    return true;
}

bool deleteMaximumNode(tempNode const &temp){
    if (temp == nullptr){
        cout << "The linked list isn't exits. " << endl;
        return false;
    }
    else if (isEmpty(temp)){
        cout << "The linked list is empty." << endl;
        return false;
    }
    tempNode maximum(temp->Next), current(temp->Next), previous(temp), maximumP(temp->Next);
    while (current != nullptr){
        if (maximum->Data < current->Data){
            maximum = current;
            maximumP = previous;
        }
        previous = previous->Next;
        current = current->Next;
    }
    maximumP->Next = maximum->Next;
    delete maximum;
    return true;
}

bool sortList(tempNode const &temp){
    if (temp == nullptr){
        cout << "The linked list isn't exits. " << endl;
        return false;
    }
    else if (isEmpty(temp)){
        cout << "The linked list is empty." << endl;
        return false;
    }
    tempNode oldP, newP(temp->Next->Next), newS;
    temp->Next->Next = nullptr;
    while (newP != nullptr) {
        newS = newP->Next;
        oldP = temp;
        while (oldP->Next != nullptr && oldP->Next->Data < newP->Data) {
            oldP = oldP->Next;
        }
        newP->Next = oldP->Next;
        oldP->Next = newP;
        newP = newS;
    }
    return true;
}

#endif //DATA_STRUCTURE_ALGORITHM_LINKLIST_H
