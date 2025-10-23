#include <fstream>
#include <iostream>

int main323()
{
	{
		std::ofstream outf("C:/CS/WEC/WECGL/src/old.txt");

		if (!outf)
		{
			std::cerr << "Sample.txt couldn't be  opened for writing ; ";
			return 1;
		}

		outf << "This is line 1 : writing into old.txt \n ";
		outf << "This is line 2 : writing into old.txt \n";
	}

	std::ifstream inf("C:/CS/WEC/WECGL/src/old.txt");
	std::ofstream outf2("C:/CS/WEC/WECGL/src/new.txt");

	if (!inf)
	{
		std::cerr << "old.txt could not be found for reading\n"; 
		return 1; 
	}

	std::string stringinput{}; 

	if (!outf2)
	{
		std::cerr << "cannot write into new.txt for some reason \n"; 
	}

	while (inf >> stringinput)
	{
		std::cout << stringinput << "\n";
		outf2 << stringinput << "\n";
	}

	return 0; 




	return 0; 
}

