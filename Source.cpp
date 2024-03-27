#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#include <wincon.h>
#include "mylib.h"
using namespace std;

int menu(string* name_punct, int n)
{
	int number = 0; char code;
	do
	{
		setlocale(LC_ALL, "Rus");
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN);
		for (int i = 0; i < n; i++) {
			if (i == number)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_BLUE);
				cout << name_punct[i] << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN);
			}
			else { cout << name_punct[i] << endl; }
		}
		code = _getch();
		if (code == 0) { code = _getch(); }
		if (code == 72)
		{
			number--;
			if (number < 0) { number = n - 1; }
		}
		if (code == 80)
		{
			number++;
			if (number == n) { number = 0; }
		}
	} while (code != 13);
	return number;
}

int main()
{
	system("cls");
	string namepunct[11];
	int n = 11; char vihod; int number;
	namepunct[n - 1] = "выход";
	namepunct[0] = "суммирование чисел";
	namepunct[1] = "поиск минимума";
	namepunct[2] = "отбор хороших";
	namepunct[3] = "линейный поиск";
	namepunct[4] = "бинарный поик";
	namepunct[5] = "список без повторов";
	namepunct[6] = "список без повторов с рейтингом";
	namepunct[7] = "список без повторов с хар-кой";
	namepunct[8] = "деление строки на слова (1 разделитель)";
	namepunct[9] = "дел-е строки на слова (разные разделители)";
	do
	{
		number = menu(namepunct, n);
		system("cls");
		switch (number)
		{
		case 0:
		{
			int N, sum;
			int* A;
			cout << "введи к-во чисел: ";
			cin >> N;
			A = new int[N];
			cout << "введи числа: ";
			for (int i = 0; i < N; i++) cin >> A[i];
			sum = summing(A, N);
			cout << " сумма = " << sum << endl;
			vihod = _getch();
			delete[] A;
			break;
		}
		case 1:
		{
			int n, min, l;
			int* a;
			cout << "Vvedi n: ";
			cin >> n;
			a = new int[n];
			cout << "введи массив: ";
			for (int i = 0; i < n; i++) { cin >> a[i]; }
			minimum(a, n, min, l);
			cout << "минимум = "   << min << " его номер = " << l << endl;
			vihod = _getch();
			delete[] a;
			break;
		}
		case 2: {
			int n;
			cout << "Enter n: ";
			cin >> n;
			string* names = new string [n];
			string* best = new string [n];
			cout << endl << "Enter words" << endl;
			for (int i = 0; i < n; i++)
			{
				cin >> names[i];
			}
			int k;
			bestlist(names, best, n, k);
			cout << "Best list" << endl;
			for (int i = 0; i < k; i++)
			{
				cout << best[i] << endl;
			}
			cout << endl;
			vihod = _getch();
			break;
		}

		case 3:
		{
			int i, l, k, n;
			string* name;
			string contrl;
			string tmp;
			cout << "Press n: ";
			cin >> n;
			name = new string[n];
			cout << "Press list: ";
			for (i = 0; i < n; i++)
			{
				cin >> tmp;
				name[i] = tmp;
			}
			cout << "Press find name: ";
			cin >> tmp;
			contrl = tmp;
			l = linsearch(name, contrl, n);
			cout << "искомое слово нашлось под номером" << l << endl;
			vihod = _getch();
			delete[] name;
			break;
		}

		case 4:
		{
			int i, l, k, n, start, finish, midle;
			string* name;
			string contrl;
			string tmp;
			cout << "Press n: ";
			cin >> n;
			name = new string[n];
			cout << "Press uporyad list\n";
			for (i = 0; i < n; i++)
			{
				cin >> tmp;
				name[i] = tmp;
			}
			cout << "Press find name: ";
			cin >> tmp;
			contrl = tmp;
			l = binsearch(name, contrl, n);
			cout << "искомое слово нашлось под номером " << l << endl;
			vihod = _getch();
			delete[] name;
			break;
		}

		case 5:
		{
			string* name, * list;
			int n, k, i, l, j, t;
			string tmp;
			cout << "Press n: ";
			cin >> n;
			name = new string[n];
			list = new string[n];
			cout << "Press data\n";
			for (i = 0; i < n; i++)
			{
				cin >> tmp;
				name[i] = tmp;
			}
			list_no_repeats(k, n, name, list);
			cout << "\nList without repeat \n";
			for (i = 0; i < k; i++) { cout << list[i] << endl; }
			vihod = _getch();
			delete[] name;
			delete[] list;
			break;
		}

		case 6:
		{
			string* name, * list;
			int* reit;
			int n, k, i, l, j, t;
			string tmp;
			cout << "Press n: ";
			cin >> n;
			name = new string[n];
			list = new string[n];
			reit = new int[n];
			cout << "Press data\n";
			for (i = 0; i < n; i++)
			{
				cin >> tmp;
				name[i] = tmp;
			}
			listreit(name, list, k, n, reit);
			cout << "\nсписок без повторений с рейтингом: \n";
			for (i = 0; i < k; i++) { cout << list[i] << "  " << reit[i] << endl; }
			vihod = _getch();
			delete[] name;
			delete[] list;
			delete[] reit;
			break;
		}

		case 7:
		{
			string* name, * list;
			float* sum, * ch;
			int n, k, i, l, j, t;
			string tmp;
			cout << "Press n\n"; 
			cin >> n;
			name = new string[n];
			list = new string[n];
			ch = new float[n];
			sum = new float[n];
			cout << "Press data\n";
			for (i = 0; i < n; i++)
			{
				cin >> tmp;
				name[i] = tmp;
				cout << "Press info: ";
				cin >> ch[i];
			}
			listch(name, list, k, n, sum, ch);
			cout << "\nList with her data: \n";
			for (i = 0; i < k; i++) { cout << list[i] << "  " << sum[i] << endl; }
			vihod = _getch();
			delete[] name;
			delete[] list;
			delete[] sum;
			delete[] ch;
			break;
		}

		case 8:
		{
			string st, pr;
			string t;
			pr[0] = ' ';// pr[1] = '\0';
			string* w;
			int k = 0, l, i, strk;
			cout << "Vvedite stroky: ";
			getline(cin, st);
			st += ' ';
			w = new string[st.size()];
			probel(w, t, k, st, pr);
			cout << "\nSlova stroki: \n";
			for (i = 0; i < k; i++) { cout << w[i] << endl; }
			vihod = _getch();
			delete[] w;
			break;
		}

		case 9:
		{
			string t;
			string st, pr;
			pr[0] = ' '; //pr[1] = '\0';
			string* w;
			int k, l, i, p;
			cout << "Vvedite stroky: ";
			getline(cin, st);
			w = new string[st.size() / 2 + 2];
			delenie(w, k, st);
			cout << "\nSlova stroki: \n";
			for (i = 0; i < k; i++) { cout << w[i] << endl; }
			vihod = _getch();
			delete[] w;
			break;
		}

		}

	} while (number != n - 1);
	printf("Test obrabotki menu\n");
	return 0;
}
