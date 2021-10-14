#include<iostream>
#include<cmath>
#include<conio.h>
#include<windows.h>
#include<iomanip>
#include<time.h>

using namespace std;

int movement_null(short x, short y,int score) {
	for (int i = 0;i <= 90;i++) {
		cout << "=";
	}
	cout << setw(20) << "Score:" << score;
	cout << endl;

	for (int i = 0;i <= 20;i++) {

		if (i == y) {
			cout << "||" << setw(x) << (char)(3) << setw(90 - x) << "||" << endl;
		}
		else
		{
			cout << "||" << setw(89) << "||" << endl;
		}
	}

	for (int i = 0;i <= 90;i++) {
		cout << "=";
	}

	return x, y;
}

int movement(short x, short y, short x_bonus, short y_bonus,int *pscore,short *count_bonus) {
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
		(*count_bonus) = 0;
		system("cls");
		for (int i = 0;i <= 90;i++) {
			cout << "=";
		}
		cout << setw(20) << "Score:" << *pscore;
		cout << endl;
		for (int i = 0;i <= 20;i++) {

			if (i == y) {
				cout << "||" << setw(x) << (char)(3) << setw(89 - x) << "||" << endl;
			}
			else
			{
				cout << "||" << setw(89) << "||" << endl;
			}
		}

		for (int i = 0;i <= 90;i++) {
			cout << "=";
		}
	}
	else {
		(*count_bonus)++;
	}
	
	return x,y,x_bonus,y_bonus;
}

int go() {
	srand(time(NULL));
	
	int a,score=0;
	short x, y, bonus_chance, x_bonus, y_bonus, count_bonus = 0;

	for (int i = 0;i <= 90;i++) {
		cout << "=";
	}
	cout << setw(20) << "Score:" << score;
	cout<< endl;

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
	

	while(true) {
		a = _getch();
		if (count_bonus == 0) {
			bonus_chance = 1 + rand() % 1;

			while (true) {
				if (bonus_chance <= 3) {

					x_bonus = 2 + rand() % 86;
					y_bonus = rand() % 20;
				}
				if ((x_bonus != x && y_bonus != y)||(x_bonus != x && y_bonus == y)||(x_bonus == x && y_bonus != y)) {

					break;
				}
			}
		}

		switch (a)
		{
		case 97://a
				
			if (x == 1) {
				break;
			}
			
			switch (bonus_chance) {
			case 1://есть бонус не на линии

					system("cls");

					x--;
					movement(x,y,x_bonus,y_bonus,&score,&count_bonus);

				break;//есть бонус не на линии

			case 2://бонуса нет

					system("cls");

					x--;

					movement_null(x, y,score);
				break;//бонуса нет
			default:;
				break;
			}

		break;// a

		case 100://d
			
			if (x == 87) {
				break;
			}

			switch (bonus_chance) {
			case 1://есть бонус не на линии

				system("cls");

				x++;

				movement(x, y, x_bonus, y_bonus,&score,&count_bonus);



				break;//есть бонус не на линии

			case 2://бонуса нет

				system("cls");

				x++;

				movement_null(x, y,score);

				break;//бонуса нет
			default:;
				break;
			}

			break;//d

		case 119://w
			
			if (y == 0) {
				break;
			}

			switch (bonus_chance) {
			case 1://есть бонус не на линии

				system("cls");

				y--;

				movement(x, y, x_bonus, y_bonus,&score,&count_bonus);
				


				break;//есть бонус не на линии


			case 2://бонуса нет

				system("cls");

				y--;

				movement_null(x, y,score);

				break;//бонуса нет
			default:;
				break;
			}

			break;//w

		case 115:
			switch (bonus_chance) {
			case 1://есть бонус не на линии

				system("cls");

				y++;

				movement(x, y, x_bonus, y_bonus,&score,&count_bonus);



				break;//есть бонус не на линии

			case 2://бонуса нет

				system("cls");

				y++;

				movement_null(x, y,score);

				break;//бонуса нет
			default:;
				break;
			}

			break;
		}

	}
}
int main() {
	go();

	cout << _getch();
	return 0;
}