#include <string>
#include <unordered_set>

bool IsUniqueHash(std::string str){
    // Hash set implementation - O(N) Runtime
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
    printf("Is string unique? %b\n", IsUniqueHash("abc"));
    printf("Is string unique? %b\n", IsUnique("aab"));
}