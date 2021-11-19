#include "Array_Worker.h"
#include "ex_2.h"
#pragma warning(disable: 4996)
#define MAXLINE3 2000

void print_start_menu()
{
	cout << "Стартовое меню\nВыберите задание\n1.Класс Worker\n2.Файловые и строковые потоки\n3.Шифрование\n4.Выход\n";
}
void print_menu_worker()
{
	cout << "Меню задания Worker\n1.Добавить элемент\n2.Редактировать элемент\n3.Удалить элемент\n4.Вывести всех работников на экран\n5.Вывод фамилий работников на экран в соответствии со стажем\n6.Импорт/экспорт";
}
void print_menu_ex2()
{
	cout << "Меню задания со строковыми и файловыми потоками\nВведите название файла с расширением txt, doc\n";
}
void Array_Worker_test()
{
	int cnt;
	system("cls");
	cout << "Выберите начальный размер массива\n";
	do
	{
		cin >> cnt;
		if (cnt < 0)
		{
			cout << "Массив не может быть отрицательной размерности!\n";
		}
	}
	while (cnt < 0);
	Array_Worker test(cnt);
	int select_worker1;
	do
	{
		system("cls");
		print_menu_worker();
		cin >> select_worker1;
		if (select_worker1 == 1)
		{
			test++;
			
		}
		if (select_worker1 == 2)
		{
			system("cls");
			test.show_element();
			cout << "Какой элемент будем редактировать?\n";
			int select_worker2;
			do
			{
				cin >> select_worker2;
				if (select_worker2 < 0 && select_worker2 > test.get_size())
				{
					cout << "Выбран неверный элемент!\n";
				}
			}
				while (select_worker2 < 0 && select_worker2 > test.get_size());

			cout << "Выбран элемент: " << test[select_worker2];
			cout << "Как будем редактировать элемент?\n1.Полностью\n2.Частично\n";
			int select_worker22;
			do
			{
				cin >> select_worker22;
				if (select_worker22 == 1)
				{
					test[select_worker2].set_last_name();
					test[select_worker2].set_name();
					test[select_worker2].set_middle_name();
					test[select_worker2].set_doljnost();
					test[select_worker2].set_year();
				}
				if (select_worker22 == 2)
				{
					cout << "Что будем редактировать?\n1.Фамилию\n2.Имя\n3.Отчество\n4.Должность\n5.Год начала работы\n";
					int select_worker23;
					do
					{
						cin >> select_worker23;
						if (select_worker23 == 1)
						{
							test[select_worker2].set_last_name();
						}
						if (select_worker23 == 2)
						{
							test[select_worker2].set_name();
						}

						if (select_worker23 == 3)
						{
							test[select_worker2].set_middle_name();
						}
						if (select_worker23 == 4)
						{
							test[select_worker2].set_doljnost();
						}
						if (select_worker23 == 5)
						{
							test[select_worker2].set_year();
						}

						if (select_worker23 != 1 && select_worker23 != 2 && select_worker23 != 3 && select_worker23 != 4 && select_worker23 != 5)
						{
							cout << "Выбрано неверное действие!\n";
						}
					} while (select_worker23 != 1 && select_worker23 != 2 && select_worker23 != 3 && select_worker23 != 4 && select_worker23 != 5);
				}
				if (select_worker22 != 1 && select_worker22 != 2)
				{
					cout << "Выбрано неверное действие!\n";
				}
			} while (select_worker22 != 1 && select_worker22 != 2);

			cout << "Элемент успешно отредактирован!\n";
			system("pause");
		}
		if (select_worker1 == 3)
		{
			test--;
		}

		if (select_worker1 == 4)
		{
			system("cls");
			test.show_element();
			system("pause");
		}

		if (select_worker1 == 5)
		{
			system("cls");
			int select_worker5;
			cout << "Введите стаж\n";
			do
			{
				cin >> select_worker5;

				if (select_worker5 < 0 && select_worker5 > 150)
				{
					cout << "Выбране невозможный стаж!\n";
				}
			}
				while (select_worker5 < 0 && select_worker5 > 150);
			test.search_staj(select_worker5);
			system("pause");
		}

		if (select_worker1 == 6)
		{
			system("cls");
			int select_worker61;
			cout << "1.Импорт\n2.Экспорт\n";
			do
			{
				cin >> select_worker61;
				if (select_worker61 != 1 && select_worker61 != 2)
				{
					cout << "Выбрана неверная позиция!\n";

				}
			}
				while (select_worker61 != 1 && select_worker61 != 2);

			if (select_worker61 == 1)
			{
				system("cls");
				cout << "Выберите формат импорта\n1.txt\n2.doc\n3.xml";
				int select41;
				do
				{
					cin >> select41;
					if (select41 != 1 && select41 != 2 && select41 != 3)
					{
						cout << "Выбран неверный пункт\n";
					}
				} while (select41 != 1 && select41 != 2 && select41 != 3);
				char* filename = (char*)calloc(200, 200 * sizeof(char*));
				cout << "Введите полный путь к файлу включая расширение:\n";
				cin >> filename;
				char* mystrchr = strrchr(filename, '.');

				char razshirenie[4];
				memset(razshirenie, 0, 4);
				for (int i = 0, j = 1; i != 4; i++, j++)
				{
					razshirenie[i] = *(mystrchr + j);
				}


				if (strcmp(razshirenie, "txt") == 0 || strcmp(razshirenie, "doc") == 0 || strcmp(razshirenie, "xml") == 0)
				{
					if (select41 == 1)
					{
						test.load_from_txt_file(filename);
					}
					if (select41 == 2)
					{
						test.load_from_txt_file(filename);
					}
					if (select41 == 3)
					{
						test.load_from_XML_file(filename);
					}
					cout << "Файл успешно прочитан и загружен в контейнер!\n";
					system("pause");
				}
				else
				{

					cout << "Введен неверный формат файла\nДанный формат не поддерживается\n";
					system("pause");

				}
				free(filename);
			}
			if (select_worker61 == 2)
			{
				system("cls");
				cout << "Выберите формат экспорта\n1.txt\n2.doc\n3.xml";
				int select42;
				do
				{
					cin >> select42;
					if (select42 != 1 && select42 != 2 && select42 != 3)
					{
						cout << "Выбран неверный пункт\n";
					}
				} while (select42 != 1 && select42 != 2 && select42 != 3);
				char* filename = (char*)calloc(200, 200 * sizeof(char*));
				cout << "Введите полный путь к файлу включая расширение:\n";
				cin >> filename;
				char* mystrchr = strrchr(filename, '.');

				char razshirenie[4];
				memset(razshirenie, 0, 4);
				for (int i = 0, j = 1; i != 4; i++, j++)
				{
					razshirenie[i] = *(mystrchr + j);
				}


				if (strcmp(razshirenie, "txt") == 0 || strcmp(razshirenie, "doc") == 0 || strcmp(razshirenie, "xml") == 0)
				{

					if (select42 == 1)
					{
						test.save_in_txt_file(filename);
					}
					if (select42 == 2)
					{
						test.save_in_txt_file(filename);
					}
					if (select42 == 3)
					{
						test.save_in_XML_file(filename);
					}
					cout << "Контейнер успешно сохранен в файл!\n";
					system("pause");
				}
				else
				{
					cout << "Введен неверный формат файла\nДанный формат не поддерживается\n";
					system("pause");

				}
				free(filename);
			}
		}

		if (select_worker1 != 1 && select_worker1 != 2 && select_worker1 != 3 && select_worker1 != 4 && select_worker1 != 5 && select_worker1 != 6)
		{
			cout << "Выбрано неверное действие!\n";
			system("pause");
		}
	} while (select_worker1 != 7);
}
void ex_2_test()
{
	system("cls");
	print_menu_ex2();
	string start_filename;
	int flag = 0;
	do
	{
		cin >> start_filename;
		const char* end_filename = start_filename.c_str();
		char razsherenie[4];
		memset(razsherenie, 0, 4);
		int pos = 0;
		for (int i = strlen(end_filename); i > 0; i--)
		{
			if (end_filename[i] == '.')
			{
				pos = i;
				break;
			}
		}
		for (int i = pos+1, j = 0; j != 3; i++, j++)
		{
			razsherenie[j] = end_filename[i];
		}
		
		if (strcmp(razsherenie, "txt") == 0 || strcmp(razsherenie, "doc") == 0)
		{
			flag = 1;
		}
		
		if (flag == 0)
		{
			cout << "Данное расширение не поддерживается!\nВведите другое имя файла\n";
		}

		if (flag == 1)
		{
			read_and_search(end_filename);
		}
	} while (flag != 1);
	
}
void encode(const char* filename)
{
	FILE* file1 = fopen(filename, "rt");
	char* buffer = (char*)calloc(strlen(filename), strlen(filename) * sizeof(char*));
	for (int i = 0; i != strlen(filename); i++)
	{
		if (*(filename + i) == '.')
		{
			break;
		}
		buffer[i] = filename[i];
	}
	char* filename2 = strcat(buffer, ".y0dv");
	FILE* file2 = fopen(filename2, "wt");


	char* stroka = (char*)calloc(MAXLINE3, MAXLINE3 * sizeof(char*));
	memset(stroka, 0, MAXLINE3);
	while (fgets(stroka, MAXLINE3, file1))
	{
		for (int i = 0; i != strlen(stroka); i++)
		{

			stroka[i] ++;

		}
		cout << stroka << endl;;
		fputs(stroka, file2);
	}
	fclose(file1);
	fclose(file2);


}
void decode(const char* filename)
{
	FILE* file1 = fopen(filename, "rt");
	char* buffer = (char*)calloc(strlen(filename), strlen(filename) * sizeof(char*));
	for (int i = 0; i != strlen(filename); i++)
	{
		if (*(filename + i) == '.')
		{
			break;
		}
		buffer[i] = filename[i];
	}
	char* filename2 = strcat(buffer, "RAZ.txt");

	FILE* file2 = fopen(filename2, "wt");
	char* stroka = (char*)calloc(MAXLINE3, MAXLINE3 * sizeof(char*));
	memset(stroka, 0, MAXLINE3);
	while (fgets(stroka, MAXLINE3, file1))
	{
		for (int i = 0; i != strlen(stroka); i++)
		{

			stroka[i]--;

		}
		cout << stroka << endl;
		fputs(stroka, file2);
	}
	fclose(file1);
	fclose(file2);
}

int main ()
{
	setlocale(LC_ALL, "Russian");
	int select_first;
	do
	{
		system("cls");
		print_start_menu();
		cin >> select_first;
		if (select_first == 1)
		{
			Array_Worker_test();
		}
		if (select_first == 2)
		{
			ex_2_test();
		}
		if (select_first == 3)
		{
			system("cls");
			cout << "Выберите необходимое действие:\n1.Шифровка\n2.Расшифровка\n";
			int select_third;
			do
			{
				cin >> select_third;
				if (select_third != 1 && select_third != 2)
				{
					cout << "Выбран неверный пункт!\n";
				}
			} while (select_third != 1 && select_third != 2);

			string start_filename;
			int flag = 0;
			do
			{
				cin >> start_filename;
				const char* end_filename = start_filename.c_str();
				char razsherenie[4];
				memset(razsherenie, 0, 4);
				int pos = 0;
				for (int i = strlen(end_filename); i > 0; i--)
				{
					if (end_filename[i] == '.')
					{
						pos = i;
						break;
					}
				}
				for (int i = pos + 1, j = 0; j != 3; i++, j++)
				{
					razsherenie[j] = end_filename[i];
				}

				if (strcmp(razsherenie, "txt") == 0 || strcmp(razsherenie, "doc") == 0 || strcmp(razsherenie, "xml") == 0 || strcmp(razsherenie, "y0dv") == 0)
				{
					flag = 1;
				}

				if (flag == 0)
				{
					cout << "Данное расширение не поддерживается!\nВведите другое имя файла\n";
				}

				if (flag == 1)
				{
					if (select_third == 1)
					{
						encode(end_filename);
						cout << "Файл успшено зашифрован!\n";
					}
					if (select_third == 2)
					{
						decode(end_filename);
						cout << "Файл успешно расшифрован!\n";
					}
				}
			} while (flag != 1);

		}

		if (select_first != 1 && select_first != 2 && select_first != 3 && select_first != 4)
		{
			cout << "Выбрано неверное действие!\n";
		}
	} while (select_first != 4);
	

	return 0;

}


