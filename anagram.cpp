#include <iostream>
#include <cctype>
using namespace std;

//Find whether two strings are anagrams.  Disregard spaces and capitalization.
//Params:
//  str1 = 1st string to compare
//  str2 = 2nd string to compare
bool isAnagram( char *str1,  char *str2) {
    //Find string lengths, assuming can't include string.h and utilize strlen()
    int str1_len=0;
    int str2_len=0;
    int str1_len_real=0;
    int str2_len_real=0;
    
    char ch = *str1;
    while(ch){
        //convert to lower case 
        *str1 = tolower(*str1);
        //find real length of string, including spaces
        str1_len_real+=1;
        //find length of string, excluding spaces
        if (*str1 != ' ') {str1_len+=1;} 
        ch = *(++str1);
    }
    ch = *str2;
    while(ch) {
        //convert to lower case 
        *str2 = tolower(*str2);
        //find real length of string, including spaces
        str2_len_real+=1;
        //find length of string, excluding spaces
        if (*str2 != ' ') {str2_len+=1;}
        ch = *(++str2);
    }
    
    //reset string pointers
    str1 -= str1_len_real;
    str2 -= str2_len_real;
    
    if(str1_len != str2_len) {
        return false;
    }
    else {
        if(str1_len==0) {return true;}
        else if (str1_len==1) {
            return str1[0] == str2[0];
        }
        else{
            int letters[256];
            for(int i=0; i<256; i++) { letters[i]=0; }
            
            for(int i=0; i<str1_len_real; i++) {
                if (str1[i] != ' ') { letters[str1[i]] += 1; }
            }
            
            for(int i=0; i<str2_len_real; i++) {
                if (str2[i] != ' ') { letters[str2[i]] -= 1; }
            }
            
            for(int i=0; i<256; i++) {
                if ( letters[i] != 0 ) { return false; }
            }
            return true;
        }
    }
}

int main()
{
    char test1[] = "";
    char test2[] = "a";
    char test3[] = "ab";
    char test4[] = "ba";
    char test5[] = "ca";
    char test6[] = "soundgarden";
    char test7[] = "nudedragons";
    char test8[] = "Desperation";
    char test9[] = "A rope ends it";

    cout << "0 length: " << isAnagram(test1, test1) << endl;
    cout << "<> lenghts: " << isAnagram(test1, test2) << endl;
    cout << "anagram: " << isAnagram(test2, test2) << endl;
    cout << "anagram: " << isAnagram(test3, test4) << endl;
    cout << "not anagram: " << isAnagram(test3, test5) << endl;
    cout << "anagram: " << isAnagram(test6, test7) << endl;
    cout << "anagram: " << isAnagram(test8, test9) << endl;
    return 0;
}
