#include<iostream>
#include<stdlib.h>
using namespace std;
struct Record {
    int rollNo;
    float CGPA;
    Record* next;
};

void insert (Record** head){
    Record* ptr = (Record*)malloc(sizeof(Record));
    cout << "Enter Roll no of the Student : ";
    cin >> ptr->rollNo;
    cout << "Enter CGPA of Student : ";
    cin >> ptr->CGPA;
    ptr->next = NULL;
    if (*head == NULL){
        *head = ptr;
        (*head)->next = *head;
        return;
    }
    Record* curr = *head;
    while (curr->next != *head){
        curr = curr->next;
    }
    curr->next = ptr;
    ptr->next = *head;
    
}

void search (Record* head){
    if (head == NULL){
        cout << "List is Empty" << endl;
        return;
    }
    int toSearch;
    cout << "Enter Roll no you want to Search : ";
    cin >> toSearch;
    if (head->rollNo == toSearch){
        cout << "CGPA of Student is " << head->CGPA << endl;
        return;
    }
    Record* curr = head->next;
    while (curr != head){
        if (curr->rollNo == toSearch){
            cout << "CGPA of the student is " << curr->CGPA << endl;
            return;
        }
        curr = curr->next;
    }
    if (curr == head){
        cout << "Roll no not Found in the List" << endl;
    }
}

void print (Record* head){
    if (head == NULL){
        cout << "List is Empty" << endl;
        return;
    }
    if (head == head->next){
        cout << "CGPA of Roll no "<<head->rollNo<< " is "<<head->CGPA<< endl;
        return;
    }
    Record* curr = head;
    do {
        cout << "CGPA of Roll no "<<curr->rollNo<< " is "<<curr->CGPA<< endl;
        curr = curr->next;
    } while (curr != head);
}

void deleteElement (Record** head){
    if (*head == NULL){
        cout << "List is Empty "<< endl;
        return;
    }
    int toDelete;
    cout << "Enter Roll no of Student which you want to Delete : ";
    cin >> toDelete;
    if ((*head)->next == *head){
        if ((*head)->rollNo == toDelete){
            free(*head);
            *head = NULL;
            cout << "Deleted Successfully"<< endl;
        } else {
            cout << "Roll no not Found in the List"<<endl;
        }
        return;
    } 
    Record* last = *head;
    while (last->next != *head){
        last = last->next;
    }
    Record* curr = *head;
    if (toDelete == (*head)->rollNo){
        *head = (*head)->next;
        free(curr);
        last->next = *head;
        cout << "Deleted successfully  " << endl;
        return;
    }
    Record* prev = *head;
    curr = prev->next;
    while(curr != *head){
        if (curr->rollNo == toDelete){
            prev->next = curr->next;
            free(curr);
            cout << "Deleted successfully  " << endl;
            return;
        }
        prev = prev->next;
        curr = curr->next;
    }
    if (curr == *head){
        cout << "Roll no Not found in the List"<<endl;
    }
}

void deleteList (Record** head){
    if (*head == NULL){
        cout << "List is empty " << endl;
        return;
    }
    if ((*head)->next == *head){
        free(*head);
        *head = NULL;
        cout << "Whole List Deleted "<<endl;
        return;
    }
    Record* last = *head;
    while (last->next != *head){
        last = last->next;
    }
    Record* curr = *head;
    while (*head != last){
        *head = (*head)->next;
        free(curr);
        curr = *head;
    }
    free(*head);
    *head = NULL;
    cout << "Whole List deleted"<<endl;
}

int main (){
    Record* head = NULL;
    int n;
    do {
        cout << "Enter 1 to Insert data " << endl << "Enter 2 to search data " << endl << "Enter 3 to print all Records" << endl << "Enter 4 to Delete a Record " << endl << "Enter 5 to Delete whole List " << endl << "Enter 6 to Quit" << endl;
        cin >> n;
        if (n == 1){
            insert (&head);
        } else if (n == 2){
            search (head);
        } else if (n == 3){
            print(head);
        }  else if (n == 4){
            deleteElement(&head);
        } else if (n == 5){
            deleteList(&head);
        }
    } while (n != 6);
}