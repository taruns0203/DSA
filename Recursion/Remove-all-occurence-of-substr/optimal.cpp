#include<string>
using namespace std;

class Solution {
public:

    string removeOccre(string &s, string &part){
        int pos = s.find(part); //find is stl function which will give us the start position of the substr

         while(pos != string::npos){
             s.erase(pos,part.length());
             pos = s.find(part);
         }
         return s;
    }
    string removeOccurrences(string s, string part) {

        removeOccre(s, part);
        return s;
        
    }
};