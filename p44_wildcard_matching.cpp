#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<random>
#include<stdio.h>

using namespace std;


class Solution {
public:
    bool isMatch(string s, string p);
};

bool Solution::isMatch(string s, string p)
{
    s = ' '+s;
    p = ' '+p;

    bool table[s.size()][p.size()];

    int num = s.size()*p.size();


    for(int i=0;i<s.size();i++)
    {
        for(int j=0;j<p.size();j++)
        {
            table[i][j] = false;
        }
    }


    table[0][0] = true;
    //bool flag = false;

    for(int j =1;j<p.size();j++)
    {
        if(p[j]!='*')
        {
            break;
        }
        else
            table[0][j] =true;
    }

    for(int i =1;i<s.size();i++)
    {
        if(s[i]!='*')
        {
            break;
        }
        else
            table[i][0] =true;
    }


    for(int i = 1;i<s.size(); i++)
    {
        for(int j=1; j<p.size();j++)
        {
            if(s[i]==p[j] || (p[j] == '?') )
            {
                table[i][j] = table[i-1][j-1];
            }
            else if(p[j] ==  '*')
            {
                table[i][j] = table[i-1][j] || table[i][j-1];
            }


        }

    }


    for(int i = 0;i<s.size(); i++)
    {

        for(int j=0; j<p.size();j++)
        {
            cout << table[i][j] << "\t" ;

        }

        cout << "\n";

    }

    return table[s.size()-1][p.size()-1];


}




int main(){

Solution obj;

string s = "zacabz";
string p = "*a?b*";

cout << endl << obj.isMatch(s,p);

return 0;
}

