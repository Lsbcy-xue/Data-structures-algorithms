//
// Created by Ximen Chuixue on 10/1/22.
//

#ifndef DATASTRUCTURE_ALGORITHM_SQLIST_H
#define DATASTRUCTURE_ALGORITHM_SQLIST_H
#include <iostream>
#include <cstdlib>

int size = 0;
using namespace std;
typedef int elementType;        //Define the list elements data type.
typedef struct dynamicList{
    elementType * temp;         //The pointer which pointing to the dynamic array.
    int length;                 //The length of the dynamic array.
}dynamicList, *pList;           //Define the type of dynamicList, and the pointer type of it.

void printList(pList const &temp);          //Printing out all the element in the dynamic array.
bool initialList(pList &temp, int size);    //Initialize the list.
bool insertElement(pList &temp, int index, elementType const &element);     //Insert the element to the position 'index'.
bool deleteElement(pList &temp, int index, elementType &element);           //Delete the element which the position is index, then return the element that delete.
bool isEmpty(pList const &temp);            //Judge the list whether empty or not.
bool isFull(pList const &temp);             //Judge the list whether full or not.
bool getElement(pList const &temp, int index, elementType &element);        //Input the location, then return the element.
pList createList(int size);                 //Create the list than return a pointer.
bool destroyList(pList &temp);              //free the memory which list located.
int locatedElement(pList const &temp, elementType const &element);          //Input the element, then return the position.
int lengthList(pList const &temp);          //Return the length of the list.
void showMenu(int &index);                    //The function choosing menu.
void test();                    //The test function.

void showMenu(int &index){
    cout << "===================================================== \n";
    cout << " \t\t MENU \t \n ";
    cout << "===================================================== \n";
    cout << " 1.Start and create a list \n";
    cout << " 2.Insert element \n";
    cout << " 3.Delete element \n";
    cout << " 4.Print the list \n";
    cout << " 5.Locating the element \n";
    cout << " 6.Get the length \n";
    cout << " 7.Get the element \n";
    cout << " (Enter any number to quit the system) \n";
    cout << "===================================================== \n";
    cout << "===================================================== \n";
    cin >> index;
}

void test(){
    pList temp;
    elementType element;
    int index, position;
    index = 1;

    while (index <= 7 && index >=1){
        showMenu(index);
        switch (index) {
            case 1:
                cout << "Please enter the size of the list." << endl;
                cin >> size;
                temp = createList(size);
                initialList(temp, size);
                printList(temp);
                break;
            case 2:
                cout << "Please enter the position you want to insert: " << endl;
                cin >> position;
                cout << endl << "Please enter the data number: " << endl;
                cin >> element;
                insertElement(temp, position, element);
                printList(temp);
                break;
            case 3:
                cout << "Please enter the position you want to delete: " << endl;
                cin >> position;
                deleteElement(temp, position, element);
                cout << "The deleted element is: " << element << ". " << endl;
                printList(temp);
                break;
            case 4:
                printList(temp);
                break;
            case 5:
                cout << endl << "Please enter the located number: " << endl;
                cin >> element;
                cout << "The location is: " << locatedElement(temp, element) << ". " << endl;
                break;
            case 6:
                cout << "The length of the list is: " << lengthList(temp) << ". " << endl;
                break;
            case 7:
                cout << "Please enter the position you want to get: " << endl;
                cin >> position;
                getElement(temp, position, element);
                cout << "The element is: " << element << ". " << endl;
                break;
            default:
                cout << "Quiting....." << endl;
                break;
        }
    }
    destroyList(temp);
}

pList createList(int size){
    if (size <= 0){
        cout << "Invalid size value, please try again." << endl;
        return NULL;
    }
    auto temp = (pList)malloc(sizeof(dynamicList));
    temp->temp = (elementType*)malloc(sizeof(elementType)*size);
    temp->length = 0;
    return temp;
}

bool destroyList(pList &temp){
    if (temp == NULL){
        cout << "The list doesn't exits." << endl;
        return false;
    }
    free(temp->temp);
    free(temp);
    return true;
}

bool initialList(pList &temp, int size){
    if (temp == NULL){
        cout << "The list hasn't initialized. " << endl;
        return false;
    }
    cout << "Please enter the integers: " << endl;
    for (int i = 0; i < size; ++i) {
        cin >> temp->temp[i];
        temp->length++;
    }
    cout << "The list created successfully." <<endl;
    return true;
}

void printList(pList const &temp){
    if(temp == NULL){
        cout << "The list doesn't exits." << endl;
        return;
    }
    cout << "Printing..." << endl;
    for (int i = 0; i < temp->length; ++i) {
        cout << '\t' << temp->temp[i] ;
    }
    cout << endl;
    cout << "Printed." << endl;
}

bool insertElement(pList &temp, int index, elementType const &element){
    if (temp == NULL){
        cout << "The list doesn't exits." << endl;
        return false;
    }
    else if(index <= 0 || index > 1 + temp->length){
        cout << "The position is invalid." << endl;
        return false;
    }
    else if(isFull(temp)){
        temp = (pList) realloc(temp,sizeof (elementType));
        size++;
    }
    for (int i = temp->length; i >= index - 1; --i) {
        temp->temp[i] = temp->temp[i - 1];
    }
    temp->temp[index - 1] = element;
    temp->length++;
    return true;
}

bool deleteElement(pList &temp, int index, elementType &element){
    if (temp == NULL){
        cout << "The list doesn't exits." << endl;
        return false;
    }
    else if(index <= 0 || index > temp->length){
        cout << "The position is invalid." << endl;
        return false;
    }
    else if(isEmpty(temp)){
        cout << "The list is empty." << endl;
        return false;
    }
    element = temp->temp[index - 1];
    for (int i = index - 1; i < temp->length - 1; ++i) {
        temp->temp[i] = temp->temp[i + 1];
    }
    temp->length--;
    return true;
}

bool isFull(pList const &temp){
    if (size <= temp->length)
        return true;
    else
        return false;
}

bool isEmpty(pList const &temp){
    if (temp->length == 0){
        return true;
    }
    return false;
}

bool getElement(pList const &temp, int index, elementType &element){
    if (temp == NULL){
        cout << "The list doesn't exits." << endl;
        return false;
    }
    else if(index <= 0 || index > temp->length){
        cout << "The position is invalid." << endl;
        return false;
    }
    else if(isEmpty(temp)){
        cout << "The list is empty." << endl;
        return false;
    }
    element = temp->temp[index - 1];
    return true;
}

int locatedElement(pList const &temp, elementType const &element){
    if (temp == NULL){
        cout << "The list doesn't exits." << endl;
        return false;
    }
    else if(isEmpty(temp)){
        cout << "The list is empty." << endl;
        return false;
    }
    for (int i = 0; i < temp->length; ++i) {
        if (temp->temp[i] == element){
            return ++i;
        }
    }
    cout << "Can't find it." << endl;
    return false;
}

int lengthList(pList const &temp){
    return temp->length;
}

#endif //DATASTRUCTURE_ALGORITHM_SQLIST_H
