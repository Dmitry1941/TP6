#pragma once
#include "Worker.h"
class Array_Worker
{
private:
	int length;
	Worker* data;
public:
	Array_Worker();
	Array_Worker(int length);
	~Array_Worker();
	void set_length(int v);
	int get_size();
	void erase();
	//void add(Worker value, int index);

	Worker& operator[](int index);
	Array_Worker& operator++(int value);
	Array_Worker& operator--(int value);

	void reallocate(int newlength);

	void resize(int newlength);
	void add(Worker value, int index);
	void show_element();
	void remove(int index);

	void aplh_sort();
	void search_staj(int parametr);
	void save_in_txt_file(char* filename);
	void load_from_txt_file(char* filename);
	void save_in_XML_file(char* filename);
	void load_from_XML_file(char* filename);
};

