#include <iostream>
#include <fstream>
using namespace std;
// 1|6 6|3 3|4 4|6 
void swapint(int &i, int &j)
{
	int aux=i;
	i = j;
	j = aux;
}

typedef struct 
{
	int n1, n2;
	int used;

	
}piesadomino;

ostream& operator<<(ostream& os, piesadomino &pd)
{
	os << pd.n1 << '|' << pd.n2 << endl;
	return os;
}

class Domino
{
private:
	
	int nr_piese = 28;

	piesadomino vpiese[28];

	static int compDomino(const void *a, const void *b)
	{
		piesadomino *d1 = (piesadomino *)a;
		piesadomino *d2 = (piesadomino *)b;

		if (d1->n1 == d2->n1)
			return d1->n2 - d2->n2;
		return d1->n1 - d2->n1;
	}
	
public:

	void afisare()
	{
		for (int i = 0; i < nr_piese; i++)
		{
			cout << vpiese[i];
		}
	}

	void citire(const char path[])
	{
		ifstream input(path);
		for (int i = 0; i < nr_piese; i++)
		{
			input >> vpiese[i].n1;
			input >> vpiese[i].n2;
			if (vpiese[i].n1 > vpiese[i].n2)
				swapint(vpiese[i].n1, vpiese[i].n2);
		}
	}

	void sort()
	{
		qsort(vpiese,nr_piese,sizeof(piesadomino), compDomino);
	}

	piesadomino &operator[] (int i)
	{
		return vpiese[i];
	}

	int size()
	{
		return nr_piese;
	}
};


int cerc_domino(Domino domino)
{
	int* vfrec = new int[domino.size()]();
	for (int i=0; i < domino.size(); i++)
	{
		vfrec[domino[i].n1]++;
		vfrec[domino[i].n2]++;
	}
	for (int i=0; i < domino.size(); i++)
	{
		if (vfrec[i] % 2 != 0)
			return 0;
	}


	return 1;
}


int main()
{
	Domino domino; 
	domino.citire("piese.txt");
	domino.sort();
	//domino.afisare();

	cout << cerc_domino(domino);
	

	return 0;
}