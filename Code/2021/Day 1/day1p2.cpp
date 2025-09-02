#include <iostream>
#include <fstream>

int main () {
	std::ifstream infile;
	
	infile.open ("input.txt");
	
	int increaseCount = 0;
	
	int depths[4] = {10000, 10000, 10000, 10000};
	
	int inputLength;
	
	infile.seekg(0, infile.end);
	inputLength = infile.tellg();
	infile.seekg(0, infile.beg);
	
	//std::cout << std::to_string(inputLength) << std::endl;
	
	while (infile.tellg() < inputLength) {
		char c[10];
		infile.getline(c, 64, '\n');
		
		depths[0] = atoi(c);
		
		int sum1 = depths[0] + depths[1] + depths[2];
		int sum2 = depths[1] + depths[2] + depths[3];
		
		if ((sum1 - sum2) > 0) {
			increaseCount++;
		}
		
		for (int i = 4; i > 0; i--) {
			//std::cout << "{" << i << " | " << depths[i-1] << " } ";
			depths[i-1] = depths[i-2];
		}
		
		//std::cout << std::to_string(infile.tellg()) << " | " << c << std::endl;
		std::cout << sum1 << " | " << sum2 << " | " << c << " [ " << (sum1 - sum2) << std::endl;
	}
	
	std::cout << increaseCount;
}