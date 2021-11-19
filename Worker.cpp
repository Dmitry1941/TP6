#include "Worker.h"
void Worker::set_last_name()
{
	system("cls");
	//cin.ignore(32767, '\n');
	cout << "Введите фамилию:\n";
	cin >> last_name;
}
string Worker::get_last_name()
{
	return last_name;
}

void Worker::set_middle_name()
{
	system("cls");
	cin.ignore(32767, '\n');
	cout << "Введите отчество:\n";
	cin >> middle_name;
}

string Worker::get_middle_name()
{
	return middle_name;
}

void Worker::set_name()
{
	system("cls");
	cin.ignore(32767, '\n');
	cout << "Введите имя:\n";
	cin >> name;
}

string Worker::get_name()
{
	return name;
}

void Worker::set_doljnost()
{
	system("cls");
	cin.ignore(32767, '\n');
	cout << "Введите должность:\n";
	cin >> doljnost;
}
string  Worker::get_doljnost()
{
	return doljnost;
}
void Worker::set_year()
{
	system("cls");
	int buffer;
	cout << "Введите год поступления на работу\n";
	do
	{
		cin >> buffer;
		if (buffer < 0)
		{
			cout << "Введена некорректная дата\n";
		}

	} while (buffer < 0);
	year = buffer;
}

int Worker::get_year()
{
	return year;
}

Worker::Worker()
{
	last_name = "NULL";
	middle_name = "NULL";
	name = "NULL";
	doljnost = "NULL";
	year = -1;
	cout << "Объект Worker создан!\n";
}
Worker::Worker(int a)
{
	set_last_name();
	set_name();
	set_middle_name();
	set_doljnost();
	set_year();
	cout << "Объект Worker создан!\n";
}

ostream& operator << (ostream& out, Worker& example)
{
	out << example.AboutMe();
	return out;
}

string Worker::AboutMe()
{
	return last_name + " " + name + " " + middle_name + " " + doljnost + " " + to_string(year) + "\n";
}
string Worker::save_from_txt()
{
	return last_name + "|" + name + "|" + middle_name + "|" + doljnost + "|" + to_string(year) + '\n';
}

string Worker::convert_from_XML()
{
	string tag_last_name1 = "<last_name>";
	string tag_last_name2 = "</last_name>";

	string tag_name1 = "<name>";
	string tag_name2 = "</name>";

	string tag_middle_name1 = "<middle_name>";
	string tag_middle_name2 = "</middle_name>";

	string tag_doljnost1 = "<doljnost>";
	string tag_doljnost2 = "</doljnost>";

	string tag_year1 = "<year>";
	string tag_year2 = "</year>";

	return tag_last_name1 + last_name + tag_last_name2 + "\n" + tag_name1 + name + tag_name2 + "\n" + tag_middle_name1 + middle_name + tag_middle_name2 + "\n" + tag_doljnost1 + doljnost + tag_doljnost2 + "\n" + tag_year1 + to_string(year) + tag_year2 + "\n";

}

void Worker::set_last_name(char* last_name)
{
	this->last_name = (string)last_name;
}

void Worker::set_name(char* name)
{
	this->name = (string)name;
}

void Worker::set_middle_name(char* middle_name)
{
	this->middle_name = (string)middle_name;
}

void Worker::set_doljnost(char* doljnost)
{
	this->doljnost = (string)doljnost;
}

void Worker::set_year(char* year)
{
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	string data_time = asctime(timeinfo);
	string year_today = data_time.substr(data_time.rfind(' ') + 1);
	int year_today_int = stoi(year_today);
	if (year_today_int < atoi(year))
	{
		throw - 1;
	}
	else
	{
		this->year = atoi(year);
	}
}
Worker::~Worker()
{
	cout << "Объект Worker удален!\n";
}