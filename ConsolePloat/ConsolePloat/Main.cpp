#include <iostream>
#include <conio.h>
#include <cmath>

#define WIDTH 78 //������ ���� � ��������
#define HEIGHT 25 // ������ ���� � ��������


// �������
double function(double x) {
	double y = sin(x);
	return y;
}

int main() {
	double start = -10, end = 5; // ���������� ������ � ����� ������� �������
	double yMin = -5, yMax = 2; //
	double step = (end - start) / WIDTH; // ��� ���������
	double h = yMax - yMin; // ������ �������

	int curXpos = HEIGHT*(yMax / h); //���������� � ��� �� ��������� � ����
	int curYpos = WIDTH*(start / (end - start) + 1); //���������� � ��� �� ��������� � ����
	char matrix[HEIGHT][WIDTH];  //������������� �������

	//���������� �������
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (i == curXpos) {
				matrix[curXpos][j] = '-'; // � ���
			}

			else if (j == curYpos) {
				matrix[i][curYpos] = '|'; // � ���
			}
			else {
				matrix[i][j] = 0; 
			}
		}
	}

	/*
	*	������� �������� ������� � ������� �� � �������, ��� ���� 
	*	������� �������������� ��� ���� ���� 80 �� 25
	*/
	for (double curPos = start; curPos < end; curPos += step) { 
		double value = function(curPos); //�������� �������

		//������� ������ ��������
		printf("f(%f)=%f\n",curPos,value);

		int y = HEIGHT*(yMax/h) - floor((value)* HEIGHT / h); // ���������� � � ����
		int x = floor((WIDTH * (curPos - start) / (end - start))); // ���������� � � ����

		if (y >= 0 && y < HEIGHT) {
			matrix[y][x] = '+'; // �������, � ����������� (�, �) ���� �����
		}
	}

	//������� ������� � ����
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			char c = matrix[i][j];
			putchar(c);
		}
		putchar('\n');//����� ������
	}

	//���� ������� ������� � �������
	_getch();
	return 0;
}
