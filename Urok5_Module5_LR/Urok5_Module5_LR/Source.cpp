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

			/* ����������� ���������, ����������� ��������� ���������
			����������� ������������� ������� ����� �������� ����������
			(���������, ��������, �������).*/

			int A[5][5];
			n = 5;
			m = 5;

			cout << "�������� ������: " << endl;
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

					cout << "����� ���������:" << endl;

					for (int i = 0; i < n; i++)
					{
						for (int j = 0; j < m; j++)
						{
							int value = A[i][j]; // ���������� �������� ��������
							int index = j;     // � ��� ������

							while ((index > 0) && (A[i][index - 1] > value))
							{
								// ������� ������ �������� � ����� ������� ���� ��� ������ index
								A[i][index] = A[i][index - 1];
								index--;    // ������� �������� � ������ �������
							}
							A[i][index] = value; // ��������������� ������� �������� �� �������������� �����
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

					cout << "����� ���������:" << endl;

					for (int i = 0; i < n; i++)
					{
						for (int j = 0; j < m; j++)
						{
							for (int k = m-1; k > j; k--) // ��� ���� ��������� ����� i-���
							{
								if (A[i][k - 1] > A[i][k]) // ���� ������� ������� ������ �����������
								{
									int temp = A[i][k - 1]; // ������ �� �������

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

					cout << "����� �������:" << endl;

					//���������� ���� ��� ���� ��������� ����� ����������
					int min, temp; // ��� ������ ������������ �������� � ��� ������
					for (int i = 0; i < n; i++)
					{
						for (int j = 0; j < m; j++)
						{
							for (int k = 0; k < m; k++)
							{
								min = j; // ���������� ������ �������� ��������
										 // ���� ����������� ������� ����� ��������� �� ����� i-���

									for (int k = j + 1; k < m; k++)  // ��� ��������� ��������� ����� i-���
									{
										if (A[i][j] < A[i][min]) // ���� ������� ������ ������������,
											min = k;       // ���������� ��� ������ � min

									}

									temp = A[i][j];      // ������ ������� i-�� � ����������� ��������
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