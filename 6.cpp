#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

class Person {
public:
    char name[50];
    char dob[15];
    char telephone[15];

    bool operator==(const Person& p1) {
        return (strcmp(name, p1.name) == 0);
    }

    bool operator<(const Person& p1) {
        return (strcmp(name, p1.name) < 0);
    }
};

vector<Person> people;

void print(Person& p);
void display();
void insert();
void search();
void dlt();
bool compareByName(const Person& p1, const Person& p2);

int main() {
    int ch;
    do {
        cout << "\n* * * * * Menu * * * * *";
        cout << "\n1.Insert";
        cout << "\n2.Display";
        cout << "\n3.Search";
        cout << "\n4.Sort by Name";
        cout << "\n5.Delete";
        cout << "\n6.Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                insert();
                break;

            case 2:
                display();
                break;

            case 3:
                search();
                break;

            case 4:
                sort(people.begin(), people.end(), compareByName);
                cout << "\n\n Sorted on Name : ";
                display();
                break;

            case 5:
                dlt();
                break;

            case 6:
                exit(0);
        }

    } while (ch != 7);

    return 0;
}

void insert() {
    Person p;
    cout << "\nEnter Person Name: ";
    cin.ignore(); // Ignore newline character left in the buffer
    cin.getline(p.name, 50);
    cout << "\nEnter Date of Birth (DOB) in DD/MM/YYYY format: ";
    cin.getline(p.dob, 15);
    cout << "\nEnter Telephone Number: ";
    cin.getline(p.telephone, 15);
    people.push_back(p);
}

void display() {
    for_each(people.begin(), people.end(), print);
}

void print(Person& p) {
    cout << "\n";
    cout << "\nPerson Name: " << p.name;
    cout << "\nDate of Birth (DOB): " << p.dob;
    cout << "\nTelephone Number: " << p.telephone;
    cout << "\n\n";
}

void search() {
    vector<Person>::iterator p;
    Person searchPerson;
    cout << "\nEnter Person Name to search: ";
    cin.ignore();
    cin.getline(searchPerson.name, 50);
    p = find(people.begin(), people.end(), searchPerson);

    if (p == people.end()) {
        cout << "\nNot found!!!";
    } else {
        cout << "\nFound!!!";
    }
}

void dlt() {
    vector<Person>::iterator p;
    Person deletePerson;
    cout << "\nEnter Person Name to delete: ";
    cin.ignore();
    cin.getline(deletePerson.name, 50);
    p = find(people.begin(), people.end(), deletePerson);

    if (p == people.end()) {
        cout << "\nNot found!!!";
    } else {
        people.erase(p);
        cout << "\nDeleted!!!";
    }
}

bool compareByName(const Person& p1, const Person& p2) {
    return (strcmp(p1.name, p2.name) < 0);
}

