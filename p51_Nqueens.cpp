#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;


class Solution {
public:
    vector<vector<string>> solveNQueens(int n);

private:

    void recursiveNQueens(vector<int>& v, int r, int n);
    vector<vector<int>> all_solutions;
};

void Solution::recursiveNQueens(vector<int>& v, int r, int n)
{
    if(r == n)
    {
        all_solutions.push_back(v);
    }
    else
    {
            for(int j=0; j<n; j++)
            {
                bool legal = true;
                for( int i = 0; i<=r-1; i++)
                {
                    if( (v[i] == j) || (v[i] == (j+r-i) ) || (v[i] == (j - r + i) ) )
                    {
                        legal = false;
                    }

                }
                if(legal)
                {
                    v[r] = j;
                    recursiveNQueens(v, r+1,n);
                }



            }
    }
}

vector<vector<string>> Solution::solveNQueens(int n)
{
    vector<int> v(n,0);
    recursiveNQueens(v, 0, n);

    vector<vector<string>> solText;
    string str(n,'.');

    for(int i=0; i< all_solutions.size(); i++)
    {
        vector<string> vv(n,str);
        solText.push_back(vv);

        for(int j=0; j< all_solutions[i].size(); j++)
        {
            int queen_pos = all_solutions[i][j];
            solText[i][j][queen_pos] = 'Q';
        }
    }

    return solText;

}



int main(){


Solution s;

vector<vector<string>> x =  s.solveNQueens(8);

for(int i = 0; i < x.size(); i++)
{
    cout << "Next solution: " << endl;
    for(int j=0;j<x[i].size(); j++)
    {
        cout << x[i][j] <<endl;
    }

}






return 0;
}

