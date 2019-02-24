#include <iostream>
#include <fstream>
using namespace std;

void swapint(int &i, int &j)
{
	int aux=i;
	i = j;
	j = aux;
}

class Domino
{
private:
	struct piesadomino
	{
		int n1, n2;
		int used;
	};
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
			cout << vpiese[i].n1<<" | "<<vpiese[i].n2<<endl;
		}
	}

	void citire(ifstream &input)
	{
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

};





int main()
{
	ifstream input ("piese.txt");
	Domino domino; 
	domino.citire(input);
	domino.sort();
	domino.afisare();
	
	return 0;
}