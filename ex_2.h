#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#define MAXLINE 1000
#pragma warning(disable: 4996)


void read_and_search(const char* filename) {

	std::ifstream reading;

	try
	{
		reading.open(filename);
		if (!reading.is_open())
		{
			throw - 1;
		}

		
		std::ostringstream buffer;
		while (reading >> buffer.rdbuf());
		std::string original = buffer.str();
		const char* original2 = original.c_str();

		int cnt = 0;
		for (int i = 0; i != strlen(original2); i++)
		{
			if (original2[i] == '\n')
			{
				cnt++;
			}
		}
		int* cnt_pos = (int*)calloc(cnt, cnt * sizeof(int*));
		for (int i = 0, j = 0; i != strlen(original2); i++)
		{
			if (original2[i] == '\n')
			{
				cnt_pos[j] = i;
				j++;
			}
		}


		char** original4 = (char**)calloc(cnt + 1, (cnt + 1) * sizeof(char**));
		for (int i = 0; i != cnt + 1; i++)
		{
			original4[i] = (char*)calloc(strlen(original2), strlen(original2) * sizeof(char*));
			memset(original4[i], 0, strlen(original4[i]));
		}

		for (int i = 0, j = 0, z = 0; i != strlen(original2); i++)
		{
			if (original2[i] == '\n')
			{
				original4[z][j] = original2[i];
				z++;
				j = 0;

			}
			else
			{
				original4[z][j] = original2[i];
				j++;
			}
		}
		for (int i = 0; i != cnt + 1; i++)
		{
			if (strchr(original4[i], ',') == nullptr)
			{
				std::cout << original4[i];
			}
		}
		free(cnt_pos);
		for (int i = 0; i != cnt + 1; i++)
		{
			free(original4[i]);
		}
		free(original4);
		system("pause");
	}
	catch (int a)
	{

		std::cout << "Не удается открыть файл!\n";
		system("pause");
		return;
	}

}

