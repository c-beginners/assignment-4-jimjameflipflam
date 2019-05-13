#include <iostream>
#include <string>
#include <vector>
bool compareString(const int i,const std::string& line,const std::string cmp);
std::vector<std::string> split(const std::string& line,const std::string& cmp, const int tokens);
int main(){
    std::string line;
    std::vector<std::string> words;
	std::string cmp = " ";
	const int tokens = 2;
	getline(std::cin, line);

	words = split(line, cmp, tokens);

	for(const auto& i: words){
		std::cout << i;
	}
}
std::vector<std::string> split(const std::string& line,const std::string& cmp, const int tokens)
{
	std::vector<std::string> words;
	std::string word= "";
	int j = 0;
	for(int i = 0; line[i] != '\0' && j < tokens; i++){
		if(compareString(i, line, cmp)){
			j++;
			words.push_back(word);
			word = "";
			i += cmp.size();
		}
		word += line[i];
	}
	if(word != cmp && j != tokens)
		words.push_back(word);
	
	return words;
}

bool compareString(const int i,const std::string& line,const std::string cmp)
{
	std::string tempString = "";
	const int cmpSize = cmp.size();
	int k = i;
	for(int j = 0; j < cmpSize; k++, j++){
		tempString += line[k];
	}
	return (tempString == cmp);
}
