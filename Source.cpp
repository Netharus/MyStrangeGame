#include<iostream>
#include<cmath>
#include<conio.h>
#include<iomanip>
#include<time.h>

using namespace std;

void control() {
	system("cls");
	cout << "a-left\nd-right\nw-up\ns-down" << endl;
	cout << "For exit press any buttom" << endl;
		_getch();

}
void menu(bool* pflag_exit);
int position_object(short* px_bonus, short* py_bonus, short x, short y) {
	while (true) {

			(*px_bonus) = 2 + rand() % 86;
			(*py_bonus) = rand() % 20;

		if (((*px_bonus) != x && (*py_bonus) != y) || ((*px_bonus) != x && (*py_bonus)== y) || ((*px_bonus) == x && (*py_bonus) != y)) {

			break;
		}
	}
	return 0;
}
int movement_person(short x, short y, short *px_bonus, short *py_bonus, int* pscore, short* pcount_bonus) {
	for (int i = 0;i <= 90;i++) {
		cout << "=";
	}
	cout << setw(20) << "Score:" << *pscore;
	cout << endl;

	if (y == *py_bonus) {
		for (int i = 0;i <= 20;i++) {

			if (i == y && *px_bonus < x) {
				cout << "||" << setw(*px_bonus) << (char)(4) << setw(x - (*px_bonus)) << (char)(3) << setw(89 - (x)) << "||" << endl;
			}
			else
				if (i == y && *px_bonus > x) {
					cout << "||" << setw(x) << (char)(3) << setw(*px_bonus - (x)) << (char)(4) << setw(89 - (*px_bonus)) << "||" << endl;
				}
				else
				{
					cout << "||" << setw(89) << "||" << endl;
				}
		}
	}
	else {
		for (int i = 0;i <= 20;i++) {

			if (*py_bonus == i) {
				cout << "||" << setw(*px_bonus) << (char)(4) << setw(90 - (*px_bonus + 1)) << "||" << endl;
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
	return 0;
}
int movement(short x, short y, int *pscore, short *pcount_bonus, short *px_bonus,short *py_bonus) {
	
	movement_person(x, y, px_bonus, py_bonus, pscore, pcount_bonus);

	if ((x == *px_bonus) && (y == *py_bonus)) {
		(*pscore)++;

		system("cls");
		
		position_object(px_bonus, py_bonus, x, y);
		
		movement_person(x, y, px_bonus, py_bonus, pscore, pcount_bonus);
		
		(*pcount_bonus)++;
	}
	else {
		(*pcount_bonus)++;
	}

	return x, y;
}
int go(bool *pflag_exit,bool *pflag_menu) {
	srand(time(NULL));

	int a, score = 0;
	short x=45, y=10, x_bonus, y_bonus, count_bonus = 0,x_enemy,y_enemy,count_enemy;

	system("cls");
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
	
	while (true) {
		a = _getch();

		if (count_bonus == 0) {
			position_object(&x_bonus,&y_bonus,x,y);
			
		}

		switch (a)
		{
		case 97://a

			if (x == 1) {
				break;
			}		         
			
			system("cls");

				x--;
				movement(x, y,  &score, &count_bonus,&x_bonus,&y_bonus);

			break;// a

		case 100://d

			if (x == 87) {
				break;
			}

			system("cls");

				x++;

				movement(x, y, &score, &count_bonus, &x_bonus, &y_bonus);

			break;//d

		case 119://w

			if (y == 0) {
				break;
			}

			system("cls");

			y--;

			movement(x, y,  &score, &count_bonus, &x_bonus, &y_bonus);
					   			 	
			break;//w

		case 115:

			if (y == 20) {
				break;
			}
			
			system("cls");

			y++;

			movement(x, y,  &score, &count_bonus, &x_bonus, &y_bonus);
					   			 		  		  
			break;
		case 27:
			system("cls");
			*pflag_menu = false;
			menu(pflag_exit);
			break;
		}
		
		
	if (*pflag_exit == true||a==27) {
		break;
	}
	}
	if (*pflag_exit == true||a==27) {
		return 0;
	}
}
void menu(bool *pflag_exit) {
	bool flag=true,flag_end=false,flag_control=false,flag_control_leave=false;
	short choice, buff_choice;
	char a=62, b=0, c=0;

	cout << setw(8) << "Menu" << endl;
	cout << ">1) New game\n2) Control\n3) Exit" << endl;
	

	while (true) {
		if (flag_control_leave == true) {
			system("cls");
			cout << setw(8) << "Menu" << endl;
			cout << "1) New game\n>2) Control\n3) Exit" << endl;
			flag_control_leave = false;
		}
		if (flag == true) {
			buff_choice = 1;
			flag = false;
		}
		flag = false;
		

			for (int i = 0;i <= 2;i++) {
				choice = _getch();
				if (choice == 80) {
					buff_choice++;
					break;
				}
				else if (choice == 72) {
					buff_choice--;
					break;
				}
				else if (choice == 13) {
					if (buff_choice == 1) {
						flag_end = true;
						break;
					}
					if (buff_choice == 2) {
						flag_control = true;
						break;
					}
					if (buff_choice == 3) {
						*pflag_exit = true;
						flag_end = true;
						break;
					}
				}
			}
		
	
		
		if (flag_control == true) {
			control();
			flag_control=false;
			flag_control_leave=true;
			
		}
		else {

			if (flag_end == true) {
				break;
			}
			if (buff_choice > 3) {
				buff_choice = 3;
			}
			if (buff_choice < 1) {
				buff_choice = 1;
			}
			switch (buff_choice) {
			case 1: a = 62;
				b = 0;
				c = 0;
				break;
			case 2: a = 0;
				b = 62;
				c = 0;
				break;
			case 3: a = 0;
				b = 0;
				c = 62;
				break;
			}
			system("cls");
			cout << setw(8) << "Menu\n" << a << "1) New game\n" << b << "2) Control\n" << c << "3) Exit" << endl;
		}
	}
}
int main() {
	bool flag_exit=false,flag_menu=true;

	while (flag_exit == false) {
		if (flag_menu == true) {
			menu(&flag_exit);
		}
		if (flag_exit == true) {
			return 0;
		}
		
		go(&flag_exit,&flag_menu);
		if (flag_exit == true) {
			return 0;
		}
	}

	
	return 0;
}