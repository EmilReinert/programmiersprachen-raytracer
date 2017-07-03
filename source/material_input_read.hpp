#include <iostream>
#include <fstream>
#include "material.cpp"
#include <string>
#include <vector>
#include "color.hpp"

int main()
{
	std::fstream textinput;
	textinput.open("input_material.txt");
	std::string line;
	std::vector<Material> vec_material;

	if(!textinput.is_open()){
		std::cout<<"duh, file not found";
	}
	
	while(std::getline(textinput, line))
	{		
		//name starts after 16. character
		int i = 16;
		std::string name;
		while(line.at(i) != ' ')
		{
			name.push_back(line[i]);
			++i;
		}
		++i;
		
		std::vector<int> numbers(10);
		for(int j = 0; j < numbers.size(); ++j)
		{		
			//2nd loop with same aim 
			int a = line[i] - '0';
			std::cout << line [i];
			numbers[j] = a;
			i +=2;
		}

		Color c1(numbers[0], numbers[1], numbers[2]);
		Color c2(numbers[3], numbers[4], numbers[5]);
		Color c3(numbers[6], numbers[7], numbers[8]);

		Material material(name, c1, c2, c3, numbers[9]);
		vec_material.push_back(material);
	}

	for (std::vector<Material>::iterator it = vec_material.begin(); it != vec_material.end(); ++it)
	{
		std::cout << ' ' << *it;
		std::cout << '\n';
	}

	return 0;
}