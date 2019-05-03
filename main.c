//Generator of permutations without repetitions and derangemetns
#include <stdio.h>

void PrintPermutations(int *x, int size, int n);
void PrintArray(int *x, int size);
void swap(int *x, int *y);
int CheckIfDerangement(int T[], int N);
void PrintDerangements(int *x, int size, int n);
int counter = 0;
FILE *fp;
int main()
{
	fopen_s(&fp, "MP_L1.txt", "w");
	printf("Program which generates permutations without repetitions and derangements from set {1,...,n}\n");
	int choice;
	printf("\nWhat do you want to do:\n1. Print permutations\n2. Print derangements\nYour choice: ");
	scanf_s("%d", &choice);
	int size;
	printf("\nPlease give n: ");
	scanf_s("%d", &size);
	int *tab = malloc(size * sizeof(*tab));
	for (int i = 0; i<size; i++)
		tab[i] = i+1;
	switch (choice) {
	case 1:
	{
		PrintPermutations(tab, size, size);
		printf("Printed %d permutations\n", counter);
		fprintf(fp, "Printed %d permutations\n", counter);
		break;
	}
	case 2:
	{
		PrintDerangements(tab, size, size);
		printf("\n\nPrinted %d derangements\n", counter);
		fprintf(fp,"\n\nPrinted %d derangements\n", counter);
		break;
	}
	default:
	{
		printf("There is no such choice.\nChoose once more\n");
	}
	}
	free(tab);
	fclose(fp);
	system("pause");
	return 0;
}

void PrintArray(int *x, int size)
{
	for (int i = 0; i < size; i++) {
		printf("%d ", x[i]);
		fprintf(fp, "%d ", x[i]);
	}
	printf("\n");
	fprintf(fp, "\n");

}
void PrintPermutations(int *x, int size, int n)
{
	if (size == 1)
	{
			PrintArray(x, n);
			counter++;
			return 0;
		
	}
	for (int i = 0; i<size; i++)
	{
		PrintPermutations(x, size - 1, n);

		if (size % 2 == 1)
			swap(&x[0], &x[size - 1]);
		else
			swap(&x[i], &x[size - 1]);
	}
}
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;

}
int CheckIfDerangement(int tab[], int n)
{
	int *arr = malloc(n * sizeof(*arr));
	for (int i = 0; i<n; i++)	
		arr[i] = i+1;
	for (int i = 0; i<n; i++)		
		if (arr[i] == tab[i]) {
			free(arr);
			return 0;
		}
	free(arr);
	return 1;
}
void PrintDerangements(int *x, int size, int n)
{
	if (size == 1)
	{
		if (CheckIfDerangement(x, n)) {
			PrintArray(x, n);
			counter++;
		}
		return 0;

	}
	for (int i = 0; i<size; i++)
	{
		PrintDerangements(x, size - 1, n);

		if (size % 2 == 1)
			swap(&x[0], &x[size - 1]);
		else
			swap(&x[i], &x[size - 1]);
	}
}

