#include <iostream>
#include <filesystem>
#include "Resolution.h"

// Enables memory leak detection
#define _CRTDBG_MAP_ALLOC

std::vector<std::string> GetFileNames();

int main() {
	// Memory leak detection code
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	// This function call will set a breakpoint at the location of a leaked block
	// Set the parameter to the identifier for a leaked block
	_CrtSetBreakAlloc(-1);

	std::vector<std::string> artFiles = GetFileNames();

	// Menu
	int userInput = -1;
	while(userInput != 0)
	{
		std::cout << "Choose one of the following art files:\n[0] Exit\n";
		std::string toPrint = "";
		for (int i = 0; i < artFiles.size(); i++)
		{
			int val = i + 1;
			toPrint += std::format("[{}] Art {}\n", val, val);
		}
		std::cout << toPrint << "\n\n> ";
		std::cin >> userInput;
		if (userInput <= 0)
		{
			std::cout << "Exit.\n\n";
			break;
		}
		else if (userInput <= artFiles.size())
		{
			std::cout << "Here is your image:\n\n";
			Resolution image(artFiles[userInput - 1]);
			image.Display();
		}
		else
		{
			std::cout << "That is not a valid image.\n";
		}
		system("pause");
		system("cls");
	}
	std::cin.clear();
	std::cout << "\n\n";
	system("pause");
	return 0;
}

std::vector<std::string> GetFileNames()
{
	std::vector<std::string> artFiles;
	const std::filesystem::path path("C:\\Users\\nilit\\FullSailAssignments\\DSA\\DSA_Practical1\\DSA_Practical1");
	for (const std::filesystem::directory_entry& file : std::filesystem::directory_iterator(path))
	{
		if (file.path().extension() == ".art")
			artFiles.push_back(file.path().string());
	}

	return artFiles;
}
