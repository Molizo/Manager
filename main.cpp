#include <iostream>
#include <fstream>
#include <Windows.h>
#include <algorithm>

using namespace std;

ifstream in("manager.in");
ofstream out("manager.out");

struct date
{
	int pornire;
	int durata;
	int relaxare;
}timp [10000];

bool customSort(date a, date b)
{
	return a.pornire > b.pornire || (a.pornire == b.pornire && (a.durata + a.relaxare) > (b.durata + b.relaxare));
}

int main()
{
	char cerinta;int cnt = 0, n,start,end;
	in >> cerinta >> n;
	if(cerinta == 'a')
    {
        for (int i = 0; i < n; i++)
        {
            in >> timp[i].pornire >> timp[i].durata >> timp[i].relaxare;
        }
        sort(timp,timp+n,customSort);
        start=timp[0].pornire;
        end=start+timp[0].durata+timp[0].relaxare;
        for(int i=1;i<n;i++)
        {
            if(timp[i].pornire <= end)
                cnt++;
            else
            {
                start = timp[i].pornire;
                end = start + timp[i].durata + timp[i].relaxare;
            }
        }
        out<<cnt;
    }
	system("pause");
    return 0;
}

