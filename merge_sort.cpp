#include "merge_sort.hpp"

template <class T>
merge_sort<T>::merge_sort(std::vector<T> & unsorted_array){
    sorted = unsorted_array;
}

template <class T>
std::vector<T> merge_sort<T>::sort(std::vector<T> & sub){
    if(sub.size() == 1){
        return sub;
    }

    std::size_t const middle = sub.size() / 2;
    std::vector<T> sub1(sub.begin(), sub.begin() + middle);
    std::vector<T> sub2(sub.begin() + middle, sub.end());

    sub1 = merge_sort::sort(sub1);
    sub2 = merge_sort::sort(sub2);

    return merge_sort::merge(sub1, sub2);

}

template <class T>
std::vector<T> merge_sort<T>::merge(std::vector<T> & sub1, std::vector<T> & sub2){
    std::vector<T> ret;

    typename std::vector<T>::iterator sub1_it = sub1.begin();
    typename std::vector<T>::iterator sub2_it = sub2.begin();

    while(sub1_it != sub1.end() && sub2_it != sub2.end()){
        if(*sub1_it <= *sub2_it){
            ret.emplace_back(*sub1_it);
            sub1_it++;
        }
        else{
            while(*sub2_it < *sub1_it && sub2_it != sub2.end()){
                ret.emplace_back(*sub2_it);
                sub2_it++;
            }
        }
    }

    //one of the two (or both) arrays must be empty

    if(sub1_it == sub1.end()){
        while(sub2_it != sub2.end()){
            ret.emplace_back(*sub2_it);
            sub2_it++;
        }
    }
    else{
        while(sub1_it != sub1.end()){
            ret.emplace_back(*sub1_it);
            sub1_it++;
        }
    }

    return ret;
}

template <class T>
void merge_sort<T>::print_sort(){
    std::vector<T> sorted_array(merge_sort<T>::sort(this->sorted));

    for(auto it = sorted_array.begin(); it != sorted_array.end(); ++it){
        std::cout << *it << " ";
    }
    std::cout << "\n";
}

int main(){

    std::vector<int> n = {2,5,7,3,4,2,1,8,9,61};

    merge_sort<int> ms(n);
    ms.print_sort();
}