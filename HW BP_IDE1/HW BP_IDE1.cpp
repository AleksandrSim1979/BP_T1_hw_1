// HW BP_IDE1.cpp Задача 1. Знакомство с Visual Studio 2022

#include <iostream>
#include <fstream>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void reverse(int* numbers, int size)
{
	for (int j = size-1, i = 0; i <= size-1; i++)
	{
		swap(&numbers[i], &numbers[j]);
	}
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");

	std::ifstream in("in.txt");

	if (!in) 
	{
		std::cout << "Ошибка открытия файла!";

			return -1;
	}
	
	int sizeN;

	in >> sizeN;

	int* N = new int[sizeN];

	for (int i = 0; i < sizeN; i++)

	in >> N[i];

	int sizeM;

	in >> sizeM;

	int* M = new int[sizeM];

	for (int i = 0; i < sizeM; i++)

	in >> M[i];
	
	in.close();

	reverse(M, sizeM); //замена значений в массиве M[]

	reverse(N, sizeN); //замена значений в массиве N[]

	std::ofstream out("out.txt");

	out << sizeM << std::endl;

	for (int i = 0; i < sizeM; i++) 
	{
		out << M[i] << " ";
	}
	out << std::endl;

	out << sizeN << std::endl;

	for (int i = 0; i < sizeN; i++)

		out << N[i] << " ";

	out.close();

	delete[] M;

	delete[] N;

	M = nullptr;

	N = nullptr;

	return 0;
}