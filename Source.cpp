#include<iostream>
#include<cmath>
#include<conio.h>
#include<iomanip>
#include<time.h>

using namespace std;

int bonus_position(short* px_bonus, short* py_bonus, short x, short y) {
	while (true) {

			(*px_bonus) = 2 + rand() % 86;
			(*py_bonus) = rand() % 20;

		if (((*px_bonus) != x && (*py_bonus) != y) || ((*px_bonus) != x && (*py_bonus)== y) || ((*px_bonus) == x && (*py_bonus) != y)) {

			break;
		}
	}
	return 0;
}

int movement(short x, short y, short x_bonus, short y_bonus, int *pscore, short *pcount_bonus, short &px_bonus,short &py_bonus) {
	for (int i = 0;i <= 90;i++) {
		cout << "=";
	}
	cout << setw(20) << "Score:" << *pscore;
	cout << endl;

	if (y == y_bonus) {
		for (int i = 0;i <= 20;i++) {

			if (i == y && x_bonus < x) {
				cout << "||" << setw(x_bonus) << (char)(4) << setw(x - (x_bonus)) << (char)(3) << setw(89 - (x)) << "||" << endl;
			}
			else
				if (i == y && x_bonus > x) {
					cout << "||" << setw(x) << (char)(3) << setw(x_bonus - (x)) << (char)(4) << setw(89 - (x_bonus)) << "||" << endl;
				}
				else
				{
					cout << "||" << setw(89) << "||" << endl;
				}
		}
	}
	else {
		for (int i = 0;i <= 20;i++) {

			if (y_bonus == i) {
				cout << "||" << setw(x_bonus) << (char)(4) << setw(90 - (x_bonus + 1)) << "||" << endl;
			}
			else
				if (i == y) {
					cout << "||" << setw(x) << (char)(3) << setw(90 - (x + 1)) << "||" << endl;
				}
				else
				{
					cout << "||" << setw(89) << "||" << endl;
				}
		}
	}
	for (int i = 0;i <= 90;i++) {
		cout << "=";
	}
	if ((x == x_bonus) && (y == y_bonus)) {
		(*pscore)++;
		system("cls");
		bonus_position(&px_bonus, &py_bonus, x, y);
		for (int i = 0;i <= 90;i++) {
			cout << "=";
		}
		cout << setw(20) << "Score:" << *pscore;
		cout << endl;
		if (y == py_bonus) {
			for (int i = 0;i <= 20;i++) {

				if (i == y && px_bonus < x) {
					cout << "||" << setw(px_bonus) << (char)(4) << setw(x - (px_bonus)) << (char)(3) << setw(89 - (x)) << "||" << endl;
				}
				else
					if (i == y && px_bonus > x) {
						cout << "||" << setw(x) << (char)(3) << setw(px_bonus - (x)) << (char)(4) << setw(89 - (px_bonus)) << "||" << endl;
					}
					else
					{
						cout << "||" << setw(89) << "||" << endl;
					}
			}
		}
		else {
			for (int i = 0;i <= 20;i++) {

				if (py_bonus == i) {
					cout << "||" << setw(px_bonus) << (char)(4) << setw(90 - (px_bonus + 1)) << "||" << endl;
				}
				else
					if (i == y) {
						cout << "||" << setw(x) << (char)(3) << setw(90 - (x + 1)) << "||" << endl;
					}
					else
					{
						cout << "||" << setw(89) << "||" << endl;
					}
			}
		}
		for (int i = 0;i <= 90;i++) {
			cout << "=";
		}
		(*pcount_bonus)++;
	}
	else {
		(*pcount_bonus)++;
	}

	return x, y, x_bonus, y_bonus;
}

int go() {
	srand(time(NULL));

	int a, score = 0;
	short x, y, bonus_chance, x_bonus, y_bonus, count_bonus = 0;

	for (int i = 0;i <= 90;i++) {
		cout << "=";
	}
	cout << setw(20) << "Score:" << score;
	cout << endl;

	for (int i = 0;i <= 20;i++) {

		if (i == 10) {
			cout << "||" << setw(45) << (char)(3) << setw(44) << "||" << endl;
		}
		else {
			cout << "||" << setw(89) << "||" << endl;
		}
	}

	for (int i = 0;i <= 90;i++) {
		cout << "=";
	}

	x = 45;
	y = 10;


	while (true) {
		a = _getch();

		if (count_bonus == 0) {
			bonus_position(&x_bonus,&y_bonus,x,y);
			
		}

		switch (a)
		{
		case 97://a

			if (x == 1) {
				break;
			}		         
			
			system("cls");

				x--;
				movement(x, y, x_bonus, y_bonus, &score, &count_bonus,x_bonus,y_bonus);

			break;// a

		case 100://d

			if (x == 87) {
				break;
			}

			system("cls");

				x++;

				movement(x, y, x_bonus, y_bonus, &score, &count_bonus, x_bonus, y_bonus);
							   				 			
			break;//d

		case 119://w

			if (y == 0) {
				break;
			}

			system("cls");

			y--;

			movement(x, y, x_bonus, y_bonus, &score, &count_bonus, x_bonus, y_bonus);
					   			 	
			break;//w

		case 115:

			if (y == 20) {
				break;
			}
			
			system("cls");

			y++;

			movement(x, y, x_bonus, y_bonus, &score, &count_bonus, x_bonus, y_bonus);
					   			 		  		  
			break;
		}

	}
}
int main() {
	go();

	cout << _getch();
	return 0;
}