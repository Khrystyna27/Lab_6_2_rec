// Лабораторна робота № 6.2
// Опрацювання одновимірного масиву рекурсивним способом
// Обчислення середнього арифметичного непарних елементів
// Варіант 30
 
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
 
using namespace std;
 
// Рекурсивно заповнює масив випадковими числами з діапазону [Low; High].
// a - масив; size - кількість елементів;
// Low, High - межі діапазону значень (параметри-значення);
// i - індекс поточного елемента (початкове значення - 0)
void Create(int* a, const int size, const int Low, const int High, int i)
{
   a[i] = Low + rand() % (High - Low + 1);        // дія з тіла циклу
   if (i < size - 1)                              // умова продовження рекурсії
       Create(a, size, Low, High, i + 1);         // рекурсивний виклик
}
 
// Рекурсивно виводить елементи масиву в один рядок (кожен елемент - 4 позиції).
// a - масив; size - кількість елементів; i - індекс поточного елемента
void Print(int* a, const int size, int i)
{
   cout << setw(4) << a[i];
   if (i < size - 1)                              // умова продовження рекурсії
       Print(a, size, i + 1);                     // рекурсивний виклик
   else
       cout << endl;                              // дія після циклу: кінець рядка
}
 
// Перевіряє, чи число непарне (враховує і від'ємні числа).
// x - значення елемента масиву
bool IsOdd(const int x)
{
   return x % 2 != 0;
}
 
// Рекурсивно повертає кількість непарних елементів масиву.
// a - масив; size - кількість елементів; i - індекс поточного елемента
int CountOdd(int* a, const int size, int i)
{
   if (i < size)
   {
       if (IsOdd(a[i]))
           return 1 + CountOdd(a, size, i + 1);   // елемент непарний - додаємо 1
       else
           return CountOdd(a, size, i + 1);
   }
   else
       return 0;                                  // базова задача: елементів більше немає
}
 
// Рекурсивно повертає суму непарних елементів масиву.
// a - масив; size - кількість елементів; i - індекс поточного елемента
int SumOdd(int* a, const int size, int i)
{
   if (i < size)
   {
       if (IsOdd(a[i]))
           return a[i] + SumOdd(a, size, i + 1);  // елемент непарний - додаємо його
       else
           return SumOdd(a, size, i + 1);
   }
   else
       return 0;                                  // базова задача: елементів більше немає
}
 
// Обчислює середнє арифметичне непарних елементів масиву
// (за допомогою рекурсивних функцій CountOdd і SumOdd).
// a - масив; size - кількість елементів;
// mean - середнє арифметичне (вихідний параметр-посилання).
// Результат функції: true - середнє обчислено;
// false - у масиві немає непарних елементів (середнє не існує)
bool MeanOdd(int* a, const int size, double& mean)
{
   int k = CountOdd(a, size, 0); // кількість непарних елементів
   if (k == 0)
       return false;
   mean = (double)SumOdd(a, size, 0) / k;
   return true;
}
 
int main()
{
   srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
 
   const int n = 15;    // кількість елементів масиву
   const int Low = -20; // нижня межа діапазону значень
   const int High = 30; // верхня межа діапазону значень
   int a[n];
 
   Create(a, n, Low, High, 0);
   cout << "Масив:" << endl;
   Print(a, n, 0);
 
   double mean; // середнє арифметичне непарних елементів
   if (MeanOdd(a, n, mean))
       cout << "Середнє арифметичне непарних елементів = "
            << fixed << setprecision(2) << mean << endl;
   else
       cout << "У масиві немає непарних елементів" << endl;
 
   return 0;
}
