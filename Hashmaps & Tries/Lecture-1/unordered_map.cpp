#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    // creation
    unordered_map<string, int> m;

    // insertion
    pair<string, int> p = make_pair("scorpio", 9);
    m.insert(p);

    // insertion second way
    pair<string, int> p2("alto", 2);
    m.insert(p2);

    // insertion third way
    m["fortuner"] = 10;

    // access the element
    cout << m.at("alto") << endl;
    cout << m.at("scorpio") << endl;
    cout << m["fortuner"] << endl;

    // search first way using count
    cout << m.count("scorpio") << endl; // return 1
    cout << m.count("innova") << endl;  // return 0

    // search second way using find
    if (m.find("fortuner") != m.end())
    { // find returns a iterator
        cout << "Fortuner Found " << endl;
    }
    else
    {
        cout << "Fortuner not Found " << endl;
    }

    // finding the size of map
    cout << "Size is : " << m.size() << endl;

    // suppose we try to access a unknown key using square bracket then the entry will be first created in map with value 0 and the size will be increase by one
    cout << "Unknown hummer : " << m["hummer"] << endl;
    cout << m.size() << endl;

    // Iteration on  map
    cout << "Printing the map : " << endl;

    for (auto i : m)
    {
        cout << i.first << " -> " << i.second << endl;
    }

    return 0;
}
