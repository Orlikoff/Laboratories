#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;

struct Student_Info {

    char Name[100];
    int Age;
    int Group;
    int Salary;

    Student_Info() {
        //printf("---Creating new student--\n");
        /*
        SetName();
        SetAge();
        SetGroup();
        SetSalary();
        printf("\n");
        */
    }

    void Fill_Student() {
        printf("---Fill the student---\n");
        SetName();
        SetAge();
        SetGroup();
        SetSalary();
        printf("\n");
    }

    void SetName(){
        printf("Input student's name: ");
        scanf("%s", Name);
    }

    void SetAge(){
        printf("Input student's age: ");
        scanf("%d", &Age);
    }

    void SetGroup(){
        printf("Input student's group: ");
        scanf("%d", &Group);
    }

    void SetSalary(){
        printf("Input student's salary: ");
        scanf("%d", &Salary);
    }

    void PrintName(){
        printf("Student's name is: %s\n", Name);
    }

    void PrintAge(){
        printf("Student's age is: %d\n", Age);
    }

    void PrintGroup(){
        printf("Student's Group is: %d\n", Group);
    }

    void PrintSalary(){
        printf("Student's salary is: %d\n", Salary);
    }

    char* GetName(){
        return Name;
    }

    int GetAge(){
        return Age;
    }

    int GetGroup(){
        return Group;
    }

    int GetSalary(){
        return Salary;
    }

};

void Show_Database(Student_Info *Base, int n){
    for (int i = 0; i < n; i++){
        printf("---Printing Student's info---\n");
        Base[i].PrintName();
        Base[i].PrintAge();
        Base[i].PrintGroup();
        Base[i].PrintSalary();
        printf("\n");
    }
}

void Find_Person(Student_Info *Base, int n){
    int option;
    printf("Input the parameter you want to search with:\n1-Age\n2-Group\n3-Salary\nOption: ");
    scanf("%d", &option);
    switch (option){
    /*
    case 1:
        {
        char name[100];
        printf("Input the name you want to find: ");
        scanf("%s", name);
        int position = 0;
        for (int i = 0; i < n; i++){
            position++;
            printf("\nInput: %s \t Database: %s\n", name, Base[i].GetName());
            int c = 0;
            int tru = 0;
            while (name[c] != '\0'){
                c++;
            }
            int k = 0;
            while (Base[i].GetName()[k] != '\0'){
                k++;
            }
            if (c == k){
                int y = 0;
                for (int j = 0; j < c; j++){
                    if (name[j] == Base[i].GetName()[j]){
                        y++;
                    }
                }
                if (c == y){
                    tru = 1;
                }
            }
            if (tru == 1){
                break;
            }
        }
        printf("The student you need is under %d position", position);
        break;
        }
    */
    case 1:
        {
        int age;
        printf("Input the age you want to find: ");
        scanf("%d", &age);
        int position = 0;
        for (int i = 0; i < n; i++){
            position++;
            if (age == Base[i].GetAge()){
                printf("The student you need is under %d position, his name is %s\n", position, Base[i].GetName());
            }
        }
        break;
        }
    case 2:
        {
        int group;
        printf("Input the group you want to find: ");
        scanf("%d", &group);
        int position = 0;
        for (int i = 0; i < n; i++){
            position++;
            if (group == Base[i].GetGroup()){
                printf("The student you need is under %d position, his name is %s\n", position, Base[i].GetName());
            }
        }
        break;
        }
    case 3:
        {
        int salary;
        printf("Input the salary you want to find: ");
        scanf("%d", &salary);
        int position = 0;
        for (int i = 0; i < n; i++){
            position++;
            if (salary == Base[i].GetSalary()){
                printf("The student you need is under %d position, his name is %s\n", position, Base[i].GetName());
            }
        }
        break;
        }
    }
}

void Add_Student(int &n, Student_Info* &Base){
    Student_Info *New_Database = new Student_Info[n+1];
    for (int i = 0; i < n; i++){
        New_Database[i] = Base[i];
    }
    printf("---Now You're to Fill in the fields for new student---\n");
    Student_Info Newbie;
    New_Database[n] = Newbie;
    New_Database[n].Fill_Student();
    n++;
    delete[] Base;
    Base = nullptr;
    Base = New_Database;
}

void Delete_Student(int &n, Student_Info* &Base){
    int pos;
    printf("\nInput the position of the student You want to delete: ");
    scanf("%d", &pos);
    printf("\n");
    Student_Info *New_Database = new Student_Info[n-1];
    for (int i = 0; i < n; i++){
        if (i < pos-1){
            New_Database[i] = Base[i];
        }
        else if (i > pos-1){
            New_Database[i-1] = Base[i];
        }
    }
    n--;
    delete[] Base;
    Base = nullptr;
    Base = New_Database;
}

void Change_Student(int &n, Student_Info* &Base){
    int pos;
    printf("\nInput the position of the student You want to change: ");
    scanf("%d", &pos);
    printf("\n");
    Student_Info *New_Database = new Student_Info[n];
    for (int i = 0; i < n; i++){
        if (i < pos-1){
            New_Database[i] = Base[i];
        }
        else if (i > pos-1){
            New_Database[i-1] = Base[i];
        }
    }
    printf("---Now You're to Fill in the fields for new student---\n");
    Student_Info Newbie;
    New_Database[pos-1] = Newbie;
    New_Database[pos-1].Fill_Student();
    delete[] Base;
    Base = nullptr;
    Base = New_Database;
}

void Sort_Database(int n, Student_Info* &Base, int salary){
    printf("---SORTING LIST---\n");


    for (int i = 0; i < n; i++){
        int local_minimum = Base[i].GetSalary();
        int position = i;
        for (int j = i; j < n; j++){
            if (Base[j].GetSalary() < local_minimum){
                local_minimum = Base[j].GetSalary();
                position = j-i;
            }
        }
        Student_Info a = Base[n-1-i];
        Student_Info b = Base[position];
        Base[n-1-i] = b;
        Base[position] = a;
    }


    printf("---SORTING IS FINISHED---\n");

}

int main()
{
    int n;
    int choice = 0;

    printf("Input number of students in Database: ");
    scanf("%d", &n);

    Student_Info *Database = new Student_Info[n];
    for (int i = 0; i < n; i++){
        Database[i].Fill_Student();
    }

    while (choice != 7){
        printf("\n\n");
        printf("---CHOOSE THE ACTION YOU WANT TO PERFORM---\n");
        printf("1-List the Database\n2-Add Student\n3-Delete Student\n4-Change Student\n5-Find Person\n6-Sort the list(Salary Field)\n7-Exit\n");
        printf("Your option: ");
        scanf("%d", &choice);
        printf("---You have chosen %d option---", choice);
        printf("\n");
        switch (choice){
            case 1:{
                Show_Database(Database, n);
                break;
            }
            case 2:{
                Add_Student(n, Database);
                break;
            }
            case 3:{
                Delete_Student(n, Database);
                break;
            }
            case 4:{
                Change_Student(n, Database);
                break;
            }
            case 5:{
                Find_Person(Database, n);
                break;
            }
            case 6:{
                Sort_Database(n, Database, 200);
                break;
            }
            case 7:{
                break;
            }
        }
    }


    return 0;
}
