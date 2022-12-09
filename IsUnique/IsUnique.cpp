#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using std::string;
/*
Check if each char in a string is unique.
Brute force solution has space complexity of O(N) or O(1) because we don't create new data structures. Runtime: O(N^2)

Could also implement a hash table solution with faster runtime.
*/

bool IsUniqueHash(string str){
    // Complexity directly from cppreference
    std::unordered_set<char> set;

    for(int i = 0; i < str.length(); i++) {
        // This should be O(1), worst case O(N) - linear.
        if(set.contains(str[i])){
            return false;
        }
        else{
            // Average case: O(1), worst case O(size())
            set.insert(str[i]);
        }
    }
    return true;
}

bool IsUnique(string str){
    // Brute force solution - O(N^2)
    for(int i = 0; i < str.size(); i++){
        for(int j = 0; j < str.size(); j++){
            if(i == j) continue;
            if(str[i] == str[j]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    string str = "abc";
    bool unique = 0;
    unique = IsUniqueHash(str);
    std::cout << "Is String Unique? " << unique << std::endl;

    return 0;
}