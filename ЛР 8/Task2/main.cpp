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
    string Database_Name = "base.txt";
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

int main()
{
    int n;

    printf("Input the number of students you want to input:\n");
    scanf("%d", &n);

    Student *Database = new Student[n];
    for (int i = 0; i < n; i++){
        Database[i].Fill_Student();
    }

    return 0;
}
