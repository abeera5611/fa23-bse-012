#include <iostream>
#include <unordered_map>
using namespace std;
/*
struct Nodetype {
    int data;
    Nodetype* next;
    Nodetype(int val) : data(val), next(NULL) {}
};

Nodetype *first = NULL, *last = NULL;

void insert_end() {
    int value;
    cout << "Enter the data in node: ";
    cin >> value;
    Nodetype *p = new Nodetype(value);
    if (first == NULL) {
        first = last = p;
    } else {
        last->next = p;
        last = p;
    }
}

int count_nodes() {
    int count = 0;
        Nodetype *p = first;
    if(first == NULL){
        cout<<"list is empty";
    }

    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

void count_even_odd() {
    int evenCount = 0, oddCount = 0;
    Nodetype *p = first;
    while (p != NULL) {
        if (p->data % 2 == 0)
            evenCount++;
        else
            oddCount++;
        p = p->next;
    }
    cout << "Even count: " << evenCount << "\nOdd count: " << oddCount << endl;
}

bool list_is_empty() {
    return first == NULL;
}

int most_frequent_value() {
    if (first == NULL) {
        cout << "The list is empty. No frequent value." << endl;
        return 0; //
    }

    unordered_map<int, int> freq;
    Nodetype *p = first;
    while (p != NULL) {
        freq[p->data]++;
        p = p->next;
    }

    int maxFreq = 0, mostFrequent = 0;
    for (auto &pair : freq) {
        if (pair.second > maxFreq) {
            maxFreq = pair.second;
            mostFrequent = pair.first;
        }
    }
    return mostFrequent;
}

void find_max_min() {
    if (first == NULL) {
        cout << "The list is empty." << endl;
        return;
    }
    int maxVal = first->data, minVal = first->data;
    Nodetype *p = first->next;  // Start from the second node
    while (p != NULL) {
        maxVal = max(maxVal, p->data);
        minVal = min(minVal, p->data);
        p = p->next;
    }
    cout << "Max: " << maxVal << " Min: " << minVal << endl;
}

int main() {
    cout << "Enter nodes into the linked list.....!! " << endl;

    int n;
    cout << "How many nodes do you want to insert? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        insert_end();
    }

    cout << "Total nodes: " << count_nodes() << endl;
    count_even_odd();
    cout << "Is list empty? " << (list_is_empty() ? "Yes" : "No") << endl;  // Fixed function name
    cout << "Most frequent value: " << most_frequent_value() << endl;
    find_max_min();

    return 0;
}
*/


struct Student {
    int id;
    string name;
    int age;
    char grade;
    Student* next;
};

Student* head = NULL;

// Function to add a student
void add_student() {
    Student* newStudent = new Student;
    cout << "Enter Student ID: ";
    cin >> newStudent->id;
    cout << "Enter Student Name: ";
    cin >> newStudent->name;
    cout << "Enter Age: ";
    cin >> newStudent->age;
    cout << "Enter Grade: ";
    cin >> newStudent->grade;
    newStudent->next = NULL;

    if (head == NULL) {
        head = newStudent;
    } else {
        Student* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newStudent;
    }
}

// Function to delete a student by ID
void delete_student(int id) {
    if (head == NULL) {
        cout << "No students in the list." << endl;
        return;
    }

    if (head->id == id) {
        Student* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Student* temp = head;
    Student* prev = NULL;

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Student ID not found!" << endl;
        return;
    }

    prev->next = temp->next;
    delete temp;
}

// Function to display all students
void print_students() {
    Student* temp = head;
    while (temp != NULL) {
        cout << "ID: " << temp->id << ", Name: " << temp->name << ", Age: " << temp->age << ", Grade: " << temp->grade << endl;
        temp = temp->next;
    }
}

int main() {
    add_student();
    add_student();

    cout << "Student List:" << endl;
    print_students();

    int id;
    cout << "Enter Student ID to delete: ";
    cin >> id;
    delete_student(id);

    cout << "Updated Student List:" << endl;
    print_students();

    return 0;
}


