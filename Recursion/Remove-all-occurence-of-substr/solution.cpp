#include<string>
using namespace std;

class Solution {
public:

    void removeOccre(string &s, string &part){
        int found = s.find(part); //find is stl function which will give us the start position of the substr

        if(found != string::npos){ //nopos means if the substr is not found

            //part string has been located
            //Please remove it

            string left_part = s.substr(0, found);
            string right_part = s.substr(found+part.size(), s.size());
            s = left_part + right_part;

            removeOccre(s, part);

        } else{
            //base case
            //all the occurences of part has been removed from s.
            return;
        }
    }
    string removeOccurrences(string s, string part) {

        removeOccre(s, part);
        return s;
        
    }
};
