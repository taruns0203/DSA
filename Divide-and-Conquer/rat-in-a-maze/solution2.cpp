#include <iostream>
#include <vector>
using namespace std;

class Maze{
    public:
        int dx[4] = {1,0,0,-1};
        int dy[4] = {0,-1,1,0};
        char direction[4] = {'D','L','R','U'};
        
    
};

bool isSafe(int x, int y, int row, int col, int arr[][3], vector<vector<bool>> &visited){
    if( ((x>=0 && x <row) && (y >=0 && y<col)) && 
        (arr[x][y] ==1) && 
        (visited[x][y]) ==false){
            return true;
        
    }else{
        return false;
    }
} 

void solveMaze(int arr[3][3], int row, int col, int i, int j, vector<vector<bool>> &visited, vector<string> &path, string output){
    
     Maze mazeObj;
     
    //base case 
    if(i == row-1 && j == col-1){
        //answer found
        path.push_back(output);
        return;
    }
    
    for(int k=0; k<4;k++){
        int newx = i + mazeObj.dx[k];
        int newy = j + mazeObj.dy[k];
        char dir = mazeObj.direction[k];
        
        if(isSafe(newx,newy,row,col,arr,visited)){
            visited[newx][newy] = true;
            solveMaze(arr,row,col,newx,newy, visited,path,output +dir);
            //backtrack
            visited[newx][newy] = false;
        }
    }
    
}
int main()
{
    int maze[3][3] = {{ 1,0,0}, {1,1,0}, {1,1,1}};
    
    if(maze[0][0] ==0){
        cout << "No paths Exists" <<endl;
        return 0;
    }
    
    int row = 3;
    int col = 3;
    
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    
    visited[0][0] =true;
    vector<string> path;
    string output = "";
    
    solveMaze(maze,row,col,0,0,visited, path,output);
    
    cout << "printing the results "<<endl;
    for(auto i:path){
        cout << i << " ";
    }
    
    cout << endl;
    
    if(path.size() == 0){
         cout << "No paths Exists" <<endl;
        return 0;
    }
    

    return 0;
}
