
#include<iostream>
#include<fstream>

using std::string;
using std::cout;
using std::endl;

void replace(string s1, string s2, std::ofstream &ofs, std::ifstream &ifs)
{
	std::string line;
	bool foundt = false;
	while (std::getline(ifs, line)) {
		size_t pos = 0;
		string modifiedLine;
		while (pos < line.length()) {
			size_t found = line.find(s1, pos);
			
			if (found != string::npos) {
				modifiedLine += line.substr(pos, found - pos);
				modifiedLine += s2;
				pos = found + s1.length();
				foundt = true;
			}
			else {
				modifiedLine += line.substr(pos);
				break;
			}
		}
		ofs << modifiedLine << endl;
	}
	if (foundt == false) {
		cout << "The word " << "'" << s1 << "'" << " hasn't been found"<< endl;
	}
}

int main(int argc, char **argv)
{
	if(argc != 4)
	{
		cout << "Problem!: Invalid number of arguments" << endl;
		cout << "usage: replace <file> old_word new_word" << endl;
		return 1;
	}
	string filename = argv[1];
	string s1 = argv[2];
	string s2 = argv[3];
	std::ifstream ifs(filename);
	if(!ifs.is_open())
	{
		cout << "Problem!: Impossible to open the file" << endl;
		return 1;
	}
	std::ofstream ofs(filename + ".replace");
	if(!ofs.is_open())
	{
		cout << "Problem!: Could not open file" << endl;
		return 1;
	}
	replace(s1, s2, ofs, ifs);
	ifs.close();
	ofs.close();
	return 0;
}
