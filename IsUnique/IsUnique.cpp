#include <iostream>
#include <string>
#include <unordered_set>
#include <array>

#define UniqueChars 256 // Extended ASCII has 256 chars
// Using unicode characters would probably cause problems due to the size being assumed as 1

// Book Solutions

bool IsUniqueChars(std::string str){
    // Runtime of O(N). Could argue O(1) since char set is fixed size.
    if(str.size() > UniqueChars) return false;

    bool char_set[256];
    for(int i = 0; i < str.size() - 1; i++){
        int val = int(str[i]);
        if (char_set[val] == true) // Already found this char in string
            return false;
        char_set[val] = true;
    }
    return true;
}

bool IsUniqueCharsBitVector(std::string str){
    if(str.length() > UniqueChars) return false;

    int checker{0};
    for(int i = 0; i < str.length() - 1; i++){
        int val = (unsigned char)str[i] - 'a';
        if((checker & (1 << val)) > 0)
            return false;
        checker |= (1<<val);
    }
    return true;
}

// My Solutions

bool IsUniqueHash(std::string str){
    // Hash set implementation - O(N) Runtime - Actually O(1) runtime because the for loop is constant (UniqueChars)
    if (str.length() > UniqueChars) return false;

    std::unordered_set<char> set;

    for(int i = 0; i < str.length() - 1; i++) {
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

bool IsUnique(std::string str){
    // Brute force solution (No new data structures), Runtime: O(N^2)
    if (str.length() > UniqueChars) return false;

    for(int i = 0; i < str.size() - 1; i++){
        for(int j = 0; j < str.size() - 1; j++){
            if(i == j) continue;
            if(str[i] == str[j]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    std::string notUnique {"abcddef"};
    std::string unique {"abcdef"};

    printf("Hashmap:\t\tIs string unique? %s\n", IsUniqueHash(unique) ? "Yes" : "No");
    printf("Bruteforce:\t\tIs string unique? %s\n", IsUnique(unique) ? "Yes" : "No");
    printf("Book Solution:\tIs string unique? %s\n", IsUniqueChars(unique) ? "Yes" : "No");
    printf("Bit Vector:\t\tIs string unique? %s\n\n", IsUniqueCharsBitVector(unique) ? "Yes" : "No");

    printf("Hashmap:\t\tIs string unique? %s\n", IsUniqueHash(notUnique) ? "Yes" : "No");
    printf("Bruteforce:\t\tIs string unique? %s\n", IsUnique(notUnique) ? "Yes" : "No");
    printf("Book Solution:\tIs string unique? %s\n", IsUniqueChars(notUnique) ? "Yes" : "No");
    printf("Bit Vector:\t\tIs string unique? %s\n", IsUniqueCharsBitVector(notUnique) ? "Yes" : "No");


}