#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <memory>
#include <type_traits>

class CSVReader
{
	std::string fileName;
 
    public:
        CSVReader(std::string filename) :
                fileName(filename)
        { }

        void get(std::unique_ptr<std::vector<std::vector<int>>> &);
        void set(std::string & fileName);
};

void CSVReader::set(std::string & fileName){
    this->fileName = fileName;
}

void CSVReader::get(std::unique_ptr<std::vector<std::vector<int>>> & dataList)
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

        dataList->push_back(parsedRow);
    }
	// Close the File
	file.close();
}


class tabu_search{

    std::unique_ptr<CSVReader> flowRead = std::make_unique<CSVReader>("Flow.csv");
    std::unique_ptr<CSVReader> distanceRead = std::make_unique<CSVReader>("Distance.csv");

    std::unique_ptr<std::vector<std::vector<int>>> flowMatrix = std::make_unique<std::vector<std::vector<int> > >();
    std::unique_ptr<std::vector<std::vector<int>>> DistanceMatrix = std::make_unique<std::vector<std::vector<int> > >();

    int tabu_list_size;
    std::unique_ptr<std::vector<int> > state = std::make_unique<std::vector<int>>(20);

    std::unique_ptr<std::vector<std::vector<int> > > recency_frequency_matrix = std::make_unique<std::vector<std::vector<int> > >(20, std::vector<int>(20, 0));
    
    int best_score;

    int find_cost();

    template <typename T>
    void print_matrix(const T& matrix);

    public:
        tabu_search(const int & tabu_list);
        void move(const int & index1, const int & index2);

};