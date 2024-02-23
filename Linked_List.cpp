#include<iostream>
#include<stdlib.h>
using namespace std;
struct Record {
    int rollNo;
    float CGPA;
    Record* next;
};

Record* head = NULL;
void insert (){
    Record* ptr = (Record*)malloc(sizeof(Record));
    cout << "Enter Roll no of the Student : ";
    cin >> ptr->rollNo;
    cout << "Enter CGPA of Student : ";
    cin >> ptr->CGPA;
    ptr->next = NULL;
    if (head == NULL){
        head = ptr;
        return;
    }
    Record* curr = head;
    while (curr->next != NULL){
        curr = curr->next;
    }
    curr->next = ptr;
}

void search (){
    if (head == NULL){
        cout << "List is Empty" << endl;
        return;
    }
    int toSearch;
    cout << "Enter Roll no you want to Search : ";
    cin >> toSearch;
    Record* curr = head;
    while (curr != NULL){
        if (curr->rollNo == toSearch){
            cout << "CGPA of the student is " << curr->CGPA << endl;
            return;
        }
        curr = curr->next;
    }
    if (curr  == NULL){
        cout << "Roll no not Found in the List" << endl;
    }
}

void print (){
    if (head == NULL){
        cout << "List is Empty" << endl;
        return;
    }
    Record* curr = head;
    while (curr != NULL){
        cout << "CGPA of Roll no "<<curr->rollNo<< " is "<<curr->CGPA<< endl;
        curr = curr->next;
    }
}

void deleteElement (){
    if (head == NULL){
        cout << "List is Empty "<< endl;
        return;
    }
    int toDelete;
    cout << "Enter Roll no of Student which you want to Delete : ";
    cin >> toDelete;
    Record* curr = head;
    if (toDelete == curr->rollNo){
        head = head->next;
        free(curr);
        cout << "Deleted successfully  " << endl;
        return;
    }
    Record* prev = head;
    curr = prev->next;
    while(curr != NULL){
        if (curr->rollNo == toDelete){
            prev->next = curr->next;
            free(curr);
            cout << "Deleted successfully  " << endl;
            return;
        }
        prev = prev->next;
        curr = curr->next;
    }
    if (curr == NULL){
        cout << "Roll no Not found in the List " << endl;
    }
}

void deleteList (){
    if (head == NULL){
        cout << "List is empty " << endl;
        return;
    }
    Record* curr = head;
    while (head != NULL){
        head = head->next;
        free(curr);
        curr = head;
    }
    cout << "Whole List Deleted "<< endl;
}

int main (){
    int n;
    do {
        cout << "Enter 1 to Insert data " << endl << "Enter 2 to search data " << endl << "Enter 3 to print all Records" << endl << "Enter 4 to Delete a Record " << endl << "Enter 5 to Delete whole List " << endl << "Enter 6 to Quit" << endl;
        cin >> n;
        if (n == 1){
            insert ();
        } else if (n == 2){
            search ();
        } else if (n == 3){
            print();
        }  else if (n == 4){
            deleteElement();
        } else if (n == 5){
            deleteList();
        }
    } while (n != 6);
}