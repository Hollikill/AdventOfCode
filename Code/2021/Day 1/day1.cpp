#include <iostream>
#include <fstream>

int main () {
	std::ifstream infile;
	
	infile.open ("input.txt");
	
	int increaseCount = 0;
	
	int previousDepth = 0;
	int currentDepth;
	
	int inputLength;
	
	infile.seekg(0, infile.end);
	inputLength = infile.tellg();
	infile.seekg(0, infile.beg);
	
	//std::cout << std::to_string(inputLength) << std::endl;
	
	while (infile.tellg() < inputLength) {
		char c[10];
		infile.getline(c, 64, '\n');
		
		currentDepth = atoi(c);
		
		if (currentDepth > previousDepth && previousDepth != 0) {
			increaseCount++;
		}
		
		previousDepth = currentDepth;
		
		//std::string temp(c);
		//std::cout << std::to_string(infile.tellg()) << " | " << temp << std::endl;
	}
	
	std::cout << increaseCount;
}