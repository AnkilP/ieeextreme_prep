#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

class CSVReader
{
	std::string fileName;
 
    public:
        CSVReader(std::string filename) :
                fileName(filename)
        { }
        void get(std::vector<std::vector<int>> &);
};

void CSVReader::get(std::vector<std::vector<int>> & dataList)
{
	std::ifstream file(fileName);
 
	std::string line;

	while(std::getline(file,line))
    {
        std::stringstream lineStream(line);
        std::string cell;
        std::vector<int> parsedRow;
        while(std::getline(lineStream,cell,','))
        {
            parsedRow.push_back(std::stoi(cell));
        }

        dataList.push_back(parsedRow);
    }
	// Close the File
	file.close();
}


class tabu_search{

    public:
        tabu_search(std::string fileName, );


};