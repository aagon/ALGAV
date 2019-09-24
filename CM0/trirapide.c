#include <stdio.h>
#include <stdlib.h>


void swap(int *op1, int *op2);
int rearrangement(int T[], int p, int r);
void quicksort(int T[], int p, int r);
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

	quicksort(T, 0, 9);

	printTableau(T, 10);

	return 0;
}

void swap(int *op1, int *op2)
{
	int temp = *op1;
	*op1 = *op2;
	*op2 = temp;
}

int rearrangement(int T[], int p, int r)
{
	int v = T[r];
	int i = p;

	for (int j = p; j < r; ++j) {
		if (T[j] <= v) {
			swap(T + i, T + j);
			++i;
		}
	}

	swap(T + i, T + r);

	return i;
}

void quicksort(int T[], int p, int r)
{
	if (p < r) {
		int q = rearrangement(T, p, r);
		quicksort(T, p, q - 1);
		quicksort(T, q + 1, r);
	}
}

void printTableau(int T[], int size)
{
	for (int i = 0; i < size; ++i) {
		printf("%d ", T[i]);
	}

	printf("\n");
}
