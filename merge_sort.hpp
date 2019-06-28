#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>

// template for an overloaded compare
// template <class T>
// bool operator<(const T & obj1, const T & obj2){
//     return obj1 < obj2;
// }

template <class T>
class merge_sort{

    std::vector<T> sorted;
    
    std::vector<T> merge(std::vector<T> &sub1, std::vector<T> &sub2);

    public:

        merge_sort(std::vector<T> & unsorted_array);
        std::vector<T> sort(std::vector<T> &arr);

};