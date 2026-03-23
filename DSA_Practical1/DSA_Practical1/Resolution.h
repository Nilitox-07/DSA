#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

struct Resolution
{
	int rows = 1;
	int columns = 1;
	std::vector<char*> image;
	Resolution(std::string _path)
	{
		OpenArtFile(_path);
	}
	~Resolution()
	{
		for (char* row : image)
			delete[] row;
	}
	void Display()
	{
		std::string toPrint = "";
		for (char* row : image)
		{
			toPrint += row;
			toPrint += "\n";
		}
		std::cout << toPrint;
	}
private:
	void OpenArtFile(std::string path)
	{
		std::ifstream file(path, std::ios_base::binary);

		if (file.is_open())
		{
			file.read((char*)&rows, sizeof(rows));
			file.read((char*)&columns, sizeof(columns));

			for (int r = 0; r < rows; r++)
			{
				char* line = new char[columns + 1];
				file.read(line, columns);
				line[columns] = '\0';
				image.push_back(line);
			}
			file.close(); 
		}
	}
};