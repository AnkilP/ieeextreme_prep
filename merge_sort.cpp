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
        if(*sub1_it >= *sub2_it){
            ret.append(*sub1_it);
            sub1_it++;
        }
        else{
            while(*sub2_it > *sub1_it && sub2_it != sub2.end()){
                ret.append(*sub2_it);
                sub2_it++;
            }
        }
    }

    //one of the two (or both) arrays must be empty

    if(sub1_it == sub1.end()){
        while(sub2_it != sub2.end()){
            ret.append(*sub2_it);
            sub2_it++;
        }
    }
    else{
        while(sub1_it != sub1.end()){
            ret.append(*sub1_it);
            sub1_it++;
        }
    }

    return ret;
}