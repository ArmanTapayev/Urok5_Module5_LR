#include<stdio.h>
#include<iostream>
#include<locale.h>
#include<math.h>
#include<time.h>

using namespace std;

void main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	int i, j, n, m;

			/* Разработать программу, реализующую обработку числового
			двухмерного произвольного массива тремя методами сортировки
			(пузырьком, вставкой, выбором).*/

			int A[5][5];
			n = 5;
			m = 5;

			cout << "Исходный массив: " << endl;
			cout << endl;

				for (i = 0; i < n; i++)
				{
					for (j = 0; j < m; j++)
					{
						A[i][j] = 10 + rand() % 50;
						cout << A[i][j] << "\t";

					}
					cout << endl;
				}

				cout << endl;

					cout << "Метод вставками:" << endl;

					for (int i = 0; i < n; i++)
					{
						for (int j = 0; j < m; j++)
						{
							int value = A[i][j]; // запоминаем значение элемента
							int index = j;     // и его индекс

							while ((index > 0) && (A[i][index - 1] > value))
							{
								// смещаем другие элементы к концу массива пока они меньше index
								A[i][index] = A[i][index - 1];
								index--;    // смещаем просмотр к началу массива
							}
							A[i][index] = value; // рассматриваемый элемент помещаем на освободившееся место
						}
					}

					cout << endl;

					for (i = 0; i < n; i++)
					{
						for (j = 0; j < m; j++)
						{
							cout << A[i][j] << "\t";

						}
						cout << endl;
					}

					cout << endl;

					cout << "Метод пузырьком:" << endl;

					for (int i = 0; i < n; i++)
					{
						for (int j = 0; j < m; j++)
						{
							for (int k = m-1; k > j; k--) // для всех элементов после i-ого
							{
								if (A[i][k - 1] > A[i][k]) // если текущий элемент меньше предыдущего
								{
									int temp = A[i][k - 1]; // меняем их местами

										A[i][k - 1] = A[i][k];
										A[i][k] = temp;

								}
							}
						}
					}

					cout << endl;

					for (i = 0; i < n; i++)
					{
						for (j = 0; j < m; j++)
						{
							cout << A[i][j] << "\t";

						}
						cout << endl;
					}

					cout << endl;

					cout << "Метод выбором:" << endl;

					//Организуем цикл для всех элементов кроме последнего
					int min, temp; // для поиска минимального элемента и для обмена
					for (int i = 0; i < n; i++)
					{
						for (int j = 0; j < m; j++)
						{
							for (int k = 0; k < m; k++)
							{
								min = j; // запоминаем индекс текущего элемента
										 // ищем минимальный элемент чтобы поместить на место i-ого

									for (int k = j + 1; k < m; k++)  // для остальных элементов после i-ого
									{
										if (A[i][j] < A[i][min]) // если элемент меньше минимального,
											min = k;       // запоминаем его индекс в min

									}

									temp = A[i][j];      // меняем местами i-ый и минимальный элементы
									A[i][j] = A[i][min];
									A[i][min] = temp;
							}
						}
					}

					cout << endl;

					for (i = 0; i < n; i++)
					{
						for (j = 0; j < m; j++)
						{
							cout << A[i][j] << "\t";

						}
						cout << endl;
					}


		system("pause");

}