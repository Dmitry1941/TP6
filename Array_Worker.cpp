#include "Array_Worker.h"
#include <ctime>
#define MAXLINE2 2000
#pragma warning(disable: 4996)
Array_Worker::Array_Worker()
{
	length = 0;
	data = nullptr;
	cout << "Контейнер создан!\n";
}

Array_Worker::Array_Worker(int length)
{
	this->length = length;

	if (length >= 0)
	{
		data = new Worker[length];
		cout << "Контейнер создан!\n";
	}
	else
	{
		data = nullptr;
		cout << "Контейнер не может быть отрицательной длины!\n";
		system("pause");
		exit(1);
	}
}

Array_Worker::~Array_Worker()
{
	erase();
	length = 0;
	free(data);
	cout << "Контейнер удален!\n";
}

void Array_Worker::set_length(int v)
{
	length = v;
}

int Array_Worker::get_size()
{
	return length;
}

void Array_Worker::erase()
{
	delete[] data;
	data = nullptr;
	length = 0;
}

Worker& Array_Worker::operator[](int index)
{
	assert(index >= 0 && index < length);
	return data[index];
}

void Array_Worker::reallocate(int newlength)
{
	erase();
	if (newlength <= 0)
	{
		return;
	}
	data = new Worker[newlength];
	length = newlength;

}

void Array_Worker::resize(int newlength)
{
	if (newlength == length)
	{
		return;
	}
	if (newlength < 0)
	{
		erase();
		return;
	}
	Worker* buffer_data = new Worker[newlength];
	if (length >= 0)
	{
		int count_copy = 0;
		if (newlength > length)
		{
			count_copy = length;
		}
		else
		{
			count_copy = newlength;
		}
		for (int index = 0; index < count_copy; index++)
		{
			buffer_data[index] = data[index];
		}
		delete[] data;
		data = buffer_data;
		length = newlength;

	}
}

void Array_Worker::add(Worker value, int index)
	{
		assert(index >= 0 && index <= length);

		Worker* buffer = new Worker[length + 1];
		for (int i = 0; i < index; i++)
		{
			buffer[i] = data[i];
		}
		buffer[index] = value;
		for (int j = index; j < length; j++)
		{
			buffer[j + 1] = data[j];
		}
		delete[] data;
		data = buffer;
		length++;

	}

void Array_Worker::remove(int index)
	{
		assert(index >= 0 && index < length);

		if (length == 1)
		{
			erase();
			return;
		}
		Worker* buffer = new Worker[length - 1];
		for (int i = 0; i < index; i++)
		{
			buffer[i] = data[i];
		}
		for (int j = index + 1; j < length; j++)
		{
			buffer[j - 1] = data[j];
		}
		delete[] data;
		data = buffer;
		length--;
	}


void Array_Worker::aplh_sort()
{
	
	for (int i = 0; i != length-1; i++)
	{
		for (int j = 0; j < length - i; j++)
		{

			if (strcmp(data[i+1].get_last_name().c_str(), data[i].get_last_name().c_str()) < 0)
			{
				Worker buffer;
				buffer = data[i];
				data[i] = data[i + 1];
				data[i + 1] = buffer;
			}
		}
		
	}
}

void Array_Worker::search_staj(int parametr)
{
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	string data_time = asctime(timeinfo);
	string year_today = data_time.substr(data_time.rfind(' ') + 1);
	int flag = 0;
	for (int i = 0; i != length; i++)
	{
		
		if (data[i].get_year() != -1)
		{
			if (stoi(year_today) - data[i].get_year() >= parametr)
			{
				cout << data[i].get_last_name() << endl;
				flag++;
			}
		}
	}
	if (flag == 0)
	{
		cout << "Таких работников нету!\n";
	}

}

void Array_Worker::save_in_txt_file(char* filename)
{
	try
	{
		FILE* file = fopen(filename, "w");
		for (int i = 0; i < length; i++)
		{
			string buffer_stroka = data[i].save_from_txt();
			//int length_stroka = buffer_stroka.length();


			fputs(buffer_stroka.c_str(), file);
		}
		fclose(file);
	}
	catch (exception ex)
	{
		cout << "File dont save!\n";
		return;
	}
}

void Array_Worker::load_from_txt_file(char* filename)
{
	int size = 0;

	try
	{
		FILE* file = fopen(filename, "r");

		char* buffer = (char*)calloc(MAXLINE2, MAXLINE2 * sizeof(char*));
		while (!feof(file))
		{
			int cnt_raz = 0;
			
			int cnt_void = 0;
			try
			{
				fgets(buffer, MAXLINE2, file);
				if (strlen(buffer) == 1)
				{
					cnt_void++;
					cnt_raz = 4;
				
					continue;
					
					//system("pause");
				}

				for (int i = 0; i != strlen(buffer); i++)
				{
					if (buffer[i] == '|')
					{
						cnt_raz++;
					}
					
					
				}
				if (cnt_raz == 4 && cnt_void < 2)
				{
					Worker people_buffer;
					char* istr_last_name = strtok(buffer, "|");
					people_buffer.set_last_name(istr_last_name);
					
					char* istr = istr_last_name;

					istr = strtok(NULL, "|");
					
					people_buffer.set_name(istr);
					istr = strtok(NULL, "|");
					people_buffer.set_middle_name(istr);
					istr = strtok(NULL, "|");
					
					people_buffer.set_doljnost(istr);
					istr = strtok(NULL, "|");


					people_buffer.set_year(istr);
					
					this->add(people_buffer, size);
					size++;
					if (size >= length)
					{
						this->resize(length + 1);
					}

				}
				else
				{
					throw - 1;
				}


			}
			catch (exception ex1)
			{
				cout << "File empty!\n";
				return;
			}
			catch (int a)
			{
				cout << "File soderjit lisnuu info!\n";
				return;
			}
		}

	}
	catch (exception ex)
	{
		cout << "File TXT dont open!\n";
		return;
	}
}

void Array_Worker::save_in_XML_file(char* filename)
{
	FILE* file = fopen(filename, "w");
	fputs("<?xml version=""1.0"" encoding = ""UTF-8""?>\n", file);
	fputs("<Array_Worker>\n\n", file);
	for (int i = 0; i != length; i++)
	{
		fputs(data[i].convert_from_XML().c_str(), file);
	}
	fputs("</Array_Worker>\n", file);
	fclose(file);
}

void Array_Worker::load_from_XML_file(char* filename)
{
	int size = 0;
	int count_massiv = 0;

	int starter_tag = 0;
	int end_tag = 0;
	try
	{
		FILE* file = fopen(filename, "r");
		char* buffer_XML = (char*)calloc(MAXLINE2, MAXLINE2 * sizeof(char*));

		while (!feof(file))
		{

			fgets(buffer_XML, MAXLINE2, file);
			if (strstr(buffer_XML, "<Array_Worker>") != NULL)
			{
				starter_tag++;
			}
			if ((strstr(buffer_XML, "<last_name>") != NULL) && strstr(buffer_XML, "</last_name>") != NULL)
			{

				Worker people;
				int start = 0;
				int end = 0;
				int flag = 0;
				for (int i = 0; i != strlen(buffer_XML); i++)
				{
					if (*(buffer_XML + i) == '>' && flag == 0)
					{
						start = i + 1;
						flag++;
					}
					if (*(buffer_XML + i) == 60)
					{
						end = i;
					}


				}
				char* buffer2 = (char*)calloc(end - start, (end - start) * sizeof(char*));
				for (int i = 0, j = start; j != end; i++, j++)
				{
					*(buffer2 + i) = *(buffer_XML + j);
				}

				people.set_last_name(buffer2);
				if (fgets(buffer_XML, MAXLINE2, file))
				{
					if ((strstr(buffer_XML, "<name>") != NULL && strstr(buffer_XML, "</name>") != NULL))
					{

						start = 0;
						end = 0;
						flag = 0;
						for (int i = 0; i != strlen(buffer_XML); i++)
						{
							if (*(buffer_XML + i) == '>' && flag == 0)
							{
								start = i + 1;
								flag++;
							}
							if (*(buffer_XML + i) == '<')
							{
								end = i;
							}
						}
						free(buffer2);
						buffer2 = (char*)calloc(end - start, (end - start) * sizeof(char*));
						for (int i = 0, j = start; j != end; i++, j++)
						{
							*(buffer2 + i) = *(buffer_XML + j);
						}
						people.set_name(buffer2);


						if (fgets(buffer_XML, MAXLINE2, file))
						{
							if ((strstr(buffer_XML, "<middle_name>") != NULL && strstr(buffer_XML, "</middle_name>") != NULL))
							{

								start = 0;
								end = 0;
								flag = 0;
								for (int i = 0; i != strlen(buffer_XML); i++)
								{
									if (*(buffer_XML + i) == '>' && flag == 0)
									{
										start = i + 1;
										flag++;
									}
									if (*(buffer_XML + i) == '<')
									{
										end = i;
									}
								}
								free(buffer2);
								buffer2 = (char*)calloc(end - start, (end - start) * sizeof(char*));
								for (int i = 0, j = start; j != end; i++, j++)
								{
									*(buffer2 + i) = *(buffer_XML + j);
								}
								people.set_middle_name(buffer2);

								if (fgets(buffer_XML, MAXLINE2, file))
								{
									if ((strstr(buffer_XML, "<doljnost>") != NULL && strstr(buffer_XML, "</doljnost>") != NULL))
									{

										start = 0;
										end = 0;
										flag = 0;
										for (int i = 0; i != strlen(buffer_XML); i++)
										{
											if (*(buffer_XML + i) == '>' && flag == 0)
											{
												start = i + 1;
												flag++;
											}
											if (*(buffer_XML + i) == '<')
											{
												end = i;
											}
										}
										free(buffer2);
										buffer2 = (char*)calloc(end - start, (end - start) * sizeof(char*));
										for (int i = 0, j = start; j != end; i++, j++)
										{
											*(buffer2 + i) = *(buffer_XML + j);
										}
										people.set_doljnost(buffer2);

										if (fgets(buffer_XML, MAXLINE2, file))
										{
											if ((strstr(buffer_XML, "<year>") != NULL && strstr(buffer_XML, "</year>") != NULL))
											{

												start = 0;
												end = 0;
												flag = 0;
												for (int i = 0; i != strlen(buffer_XML); i++)
												{
													if (*(buffer_XML + i) == '>' && flag == 0)
													{
														start = i + 1;
														flag++;
													}
													if (*(buffer_XML + i) == '<')
													{
														end = i;
													}
												}
												free(buffer2);
												buffer2 = (char*)calloc(end - start, (end - start) * sizeof(char*));
												for (int i = 0, j = start; j != end; i++, j++)
												{
													*(buffer2 + i) = *(buffer_XML + j);
												}
												people.set_year(buffer2);
												this->add(people, size);
												size++;
												if (size >= length)
												{
													this->resize(length + 1);
												}
											}
											else
											{
												throw - 1;
											}
										}
										else
										{
											throw - 1;
										}


									}
									else
									{
										throw - 1;
									}
								}
								else
								{
									throw - 1;
								}

							}
							else
							{
								throw - 1;
							}
						}
						else
						{
							throw - 1;

						}




					}
					else
					{
						throw - 1;
					}

				}
				else
				{
					throw - 1;
				}
			}
		}

	

	}
	catch (int a)
	{
		cout << "Файл битый. Нету открывающего, либо закрывающего тега\n";
	}
	catch (exception ex1)
	{
		cout << "File XML dont open!\n";
		return;

	}
}

Array_Worker& Array_Worker::operator++(int value)
{
	system("cls");
	cout << "В массиве сейчас " << length << " элементов\nВыберите позицию нового элемента от 0\n";
	int pos;
	do
	{
		cin >> pos;
		if (pos < 0 || pos > length-1)
		{
			cout << "Выбрана неверная позиция!\n";
		}
	}
		while (pos < 0 || pos > length);
	Worker example(1);
	this->add(example, pos);
	this->aplh_sort();
	cout << "Элемент успешно добавлен!\n";
	system("pause");
	return *this;
}

void Array_Worker::show_element()
{
	aplh_sort();
	cout << "Сейчас в массиве " << length << " элементов\n";
	for (int i = 0; i != length; i++)
	{
		cout << data[i] << endl;
	}

}

Array_Worker& Array_Worker::operator--(int value)
{
	system("cls");
	if (length == 0)
	{
		cout << "Массив пуст!\n";
		return *this;
	}
	cout << "В массиве сейчас " << length << " элементов\nВыберите позицию удаляемого элемента\n";
	int pos;
	do
	{
		cin >> pos;
		if (pos < 0 || pos > length)
		{
			cout << "Выбрана неверная позиция!\n";
		}
	} while (pos < 0 || pos > length);

	this->remove(pos);
	cout << "Элемент успешно удален!\n";
	system("pause");
	return *this;
}
