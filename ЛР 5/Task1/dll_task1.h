#ifndef dll_task1_H
#define dll_task1_H

namespace dll_func{

__declspec(dllexport) int Sum(int a, int b);
__declspec(dllexport) int Sub(int a, int b);
__declspec(dllexport) int Rule_A(int i, int j);
__declspec(dllexport) int Rule_B(int i, int j);
__declspec(dllexport) void Show_matrix(int *matrix[], int n);
__declspec(dllexport) int Perimetr_Sum(int *matrix[], int n);
__declspec(dllexport) void Show_Results(int s1, int s2);
__declspec(dllexport) void Space();

};

#endif // dll_task1_H
