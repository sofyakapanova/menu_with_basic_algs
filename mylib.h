#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int summing(int* A, int n) {
	int sum = 0, i;
	for (i = 0; i < n; i++) { sum += A[i]; }
	return sum;
}

void minimum(int* a, int n, int& min, int& l) {
	min = a[0]; l = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < min) { min = a[i]; l = i; }
	}
}

void bestlist(string* names, string* best, int n, int& k) {
	k = 0;
	for (int i = 0; i < n; i++)
	{
		if ((names[i])[0] == 'a') {
			best[k] = names[i];

			k++;
		}
	}
	
}

int linsearch(string* name, string contrl, int n) {
	int l = -1; int i = 0;
	while ((l == -1) && (i < n))
	{
		if (name[i] == contrl) { l = i; }
		i++;
	}
	return l;
}

int binsearch(string* name, string contrl, int n)
{
	int start, finish, midle;
	int l = -1, i = 0;
	start = 0;
	finish = n - 1;
	while ((l == -1) && (start <= finish))
	{
		midle = (start + finish) / 2;
		if (name[midle] == contrl) { l = midle; }
		if (name[midle] < contrl) { start = midle + 1; }
		if (name[midle] > contrl) { finish = midle - 1; }
	}
	return l;
}

void list_no_repeats(int& k, int n, string* name, string* list)
{
	k = 0;
	int i, l, j;
	for (i = 0; i < n; i++)
	{
		l = -1;
		j = 0;
		while ((l == -1) && (j < k))
		{
			if (list[j] == name[i]) { l = j; }
			j++;
		}
		if (l == -1)
		{
			list[k] = name[i];
			k++;
		}
	}
}

void listreit(string* name, string* list, int& k, int n, int* reit)
{
	int i, j, l;
	k = 0;
	for (i = 0; i < n; i++)
	{
		l = -1;
		j = 0;
		while ((l == -1) && (j < k))
		{
			if (list[j] == name[i]) { l = j; }
			j++;
		}
		if (l == -1)
		{
			list[k] = name[i];
			reit[k++] = 1;
		}
		else { reit[l]++; }
	}
}

void listch(string* name, string* list, int& k, int n, float* sum, float* ch)
{
	int i, j, l;
	k = 0;
	for (i = 0; i < n; i++)
	{
		l = -1;
		j = 0;
		while ((l == -1) && (j < k))
		{
			if (list[j] == name[i]) { l = j; }
			j++;
		}
		if (l == -1)
		{
			list[k] = name[i];
			sum[k++] = ch[i];
		}
		else { sum[l] += ch[i]; }
	}
}

void probel(string* w, string t, int& k, string st, string pr)
{
	t = st;
	t += pr;
	int l = -1;
	k = 0;
	while (t.size() > 0)
	{
		l = t.find(' ');
		if (l > 0 && t[l - 1] != ' ')
		{
			w[k] = t.substr(0, l);
			k++;
		}
		t.erase(0, l + 1);
	}
}

void delenie(string* w, int& k, string st)
{
	char t[200];
	string zn = " !.,?/:\0";
	int l, i, p;
	k = 0;
	l = 0;
	st += ' ';

	for (i = 0; i < st.size(); i++) {
		p = zn.find(st[i]);
		if (p < 0 || p > zn.size())
		{
			t[l] = st[i];
			l++;
		}
		else
		{
			if (l > 0)
			{
				t[l++] = '\0';
				w[k] = t;
				k++;
				l = 0;
			}
			if (st[i] != ' ') {
				w[k] = st[i]; //w[k++][1] = '\0';
				k++;
			}
		}
	}
}
