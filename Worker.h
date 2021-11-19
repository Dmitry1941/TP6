#pragma once
#include <iostream>
#include <string>
#include <assert.h>
using namespace std;
#pragma warning(disable: 4996)
class Worker
{
private:
	string last_name = "NULL";
	string middle_name = "NULL";
	string name = "NULL";
	string doljnost = "NULL";
	int year = -1;

public:
	void set_last_name();
		string get_last_name();

		void set_middle_name();

		string get_middle_name();

		void set_name();

		string get_name();

		void set_doljnost();
		string  get_doljnost();
		void set_year();

		int get_year();

		Worker();
		Worker(int a);

		friend ostream& operator << (ostream& out, Worker& example);

		string AboutMe();
		string save_from_txt();

		string convert_from_XML();

		void set_last_name(char* last_name);

		void set_name(char* name);

		void set_middle_name(char* middle_name);

		void set_doljnost(char* doljnost);

		void set_year(char* year);
		~Worker();

};

