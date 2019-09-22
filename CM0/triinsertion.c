#include <stdio.h>
#include <stdlib.h>

void inserer(int T[], int x, int e);
void TriInserRec(int T[], int d, int f);
void TriInserIter(int T[], int d, int f);
void printTableau(int T[], int size);

int main()
{
	int T[10] = {0};

	// On définit la sentinelle : à défaut de l'infini, on met le plus petit nombre écrivable sur 4 octets
	T[0] = -2147483648;

	// On peuple le tableau
	T[1] = 20;
	T[2] = 19;
	T[3] = 18;
	T[4] = 17;
	T[5] = 2;
	T[6] = 14;
	T[7] = 9;
	T[8] = 3;
	T[9] = 1;

	printTableau(T, 10);

	/* TriInserRec(T, 1, 10); */
	TriInserIter(T, 1, 10);

	printTableau(T, 10);

	return 0;
}

void inserer(int T[], int x, int e)
{
	int k = e;

	while (T[k] > x) {
		T[k+1] = T[k];
		k--;
	}

	T[k+1] = x;
}

// On a le choix entre la version récursive et itérative. On se permet d'implémenter les deux
// Même si on ne se permettra pas d'utiliser la récursive

void TriInserRec(int T[], int d, int f)
{
	if (d < f) {
		TriInserRec(T, d, f - 1);
		inserer(T, T[f], f - 1);
	}
}

void TriInserIter(int T[], int d, int f)
{
	for (int i = d + 1; i < f; ++i) {
		inserer(T, T[i], i - 1);
	}
}

void printTableau(int T[], int size)
{
	for (int i = 0; i < size; ++i) {
		printf("%d ", T[i]);
	}

	printf("\n");
}
