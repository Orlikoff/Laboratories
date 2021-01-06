#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Student {
private:
    char Name[20];
    char Surname[20];
    char Patronymic[20];
    int Table[4]; //marks: russian, math, physics, english
    string Database_Name = "base.txt"; // Here you can specify the name of the base
public:

    void Fill_Student(){
        SetNSP();
        SetTable();
        ofstream fout(Database_Name, ios::app);
        fout << "----------------------------------------\n";
        fout << Name << " " << Surname << " " << Patronymic << "\n";
        fout << "Russian: " << Table[0] << "\n";
        fout << "Math:    " << Table[1] << "\n";
        fout << "Physics: " << Table[2] << "\n";
        fout << "English: " << Table[3] << "\n";
        fout << "----------------------------------------\n\n";
        fout.close();
    }

    void Fill_Student_File(){
        ofstream fout(Database_Name, ios::app);
        fout << "----------------------------------------\n";
        fout << Name << " " << Surname << " " << Patronymic << "\n";
        fout << "Russian: " << Table[0] << "\n";
        fout << "Math:    " << Table[1] << "\n";
        fout << "Physics: " << Table[2] << "\n";
        fout << "English: " << Table[3] << "\n";
        fout << "----------------------------------------\n\n";
        fout.close();
    }

    void Reset_Database(){
        ofstream fout(Database_Name, ios::trunc);
        fout.close();
    }

    void SetNSP(){
        printf("Input Name, Surname and Patronymic of student:\n");
        scanf("%s %s %s", Name, Surname, Patronymic);
    }

    void SetTable(){
        printf("Input 4 marks(russian, math, physics, english), divide them with ' ':\n");
        scanf("%d %d %d %d", &Table[0], &Table[1], &Table[2], &Table[3]);
    }

    void GetNSP(){
        printf("The NSP of your student is:\n");
        printf("%s %s %s\n", Name, Surname, Patronymic);
    }

    void GetTable(){
        printf("Your student has the next marks:\n");
        for (int i = 0; i < 4; i++){
            printf("%d ", Table[i]);
        }
        printf("\n");
    }

    float Count_Avg(){
        float s = 0;
        for (int i = 0; i < 4; i++){
            s += Table[i];
        }
        s = s/4;
        return s;
    }



};

void Add_Student(int n, Student* Database){
    Student *New_Database = new Student[n+1];
    for (int i = 0; i < n; i++){
        New_Database[i] = Database[i];
    }
    Student Newbie;
    New_Database[n] = Newbie;
    New_Database[n].Fill_Student();
    delete[] Database;
    Database = nullptr;
    Database = New_Database;
}

void Delete_Student(int n, int pos, Student* Database){
    Student *New_Database = new Student[n-1];
    for (int i = 0; i < n; i++){
        if (i < pos - 1){
            New_Database[i] = Database[i];
        }
        else if (i > pos - 1){
            New_Database[i-1] = Database[i];
        }
    }
    //cout << "dolbit normalno" << endl;
    delete[] Database;
    Database = nullptr;
    Database = New_Database;
    Database[0].Reset_Database();
    //cout << "vse zbs";
    if (n-1 > 0){
        for (int i = 0; i < n-1; i++){
        Database[i].GetNSP();
        Database[i].Fill_Student_File();
        }
    }
}

void Change_Student(int n, int pos, Student *Database){
    Student *New_Database = new Student[n];
    for (int i = 0; i < n; i++){
        if (i == pos-1){
            continue;
        }
        New_Database[i] = Database[i];
    }
    Student Newbie;
    New_Database[pos-1] = Newbie;
    New_Database[pos-1].Fill_Student();
    delete[] Database;
    Database = nullptr;
    Database = New_Database;
    Database[0].Reset_Database();
    cout << "vse zbs";
    if (n-1 > 0){
        for (int i = 0; i < n; i++){
        //Database[i].GetNSP();
        Database[i].Fill_Student_File();
        }
    }
}

void Show_Students(int n, Student* Database){
    for (int i = 0; i < n; i++){
        printf("%d student: \n", i+1);
        Database[i].GetNSP();
        Database[i].GetTable();
        printf("\n");
    }
}

int main()
{
    int n;

    printf("Input the number of students you want to input:\n");
    scanf("%d", &n);

    Student *Database = new Student[n];
    for (int i = 0; i < n; i++){
        Database[i].Fill_Student();
    }

    int ans = 10;

    while (ans != 5){
        printf("Choose the option you want:\n1-Add Student\n2-Delete student\n3-Change Student\n4-Show List\n5-Exit\n");
        scanf("%d", &ans);

        switch(ans){
        case 1:{
            Add_Student(n, Database);
            n++;
            cout << "N is: " << n << endl;
        break;
        }

        case 2:{
            int pos;
            printf("Input the position to delete: \n");
            scanf("%d", &pos);
            Delete_Student(n, pos, Database);
            n--;
            cout << "N is: " << n << endl;
        break;
        }

        case 3:{
            int pos;
            printf("Input the position to change: \n");
            scanf("%d", &pos);
            Change_Student(n, pos, Database);
        break;
        }

        case 4:{
            Show_Students(n, Database);
        break;
        }
        }
    }
    return 0;
}
