#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<random>
#include<queue>

#define infinity INT_MAX

using namespace std;



//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists);
};


class Compare {
public:
    bool operator()(pair<int,int> x, pair<int,int> y)
    {
        return x.first > y.first;
    }
};

ListNode* Solution::mergeKLists(vector<ListNode*>& lists)
{

    priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;

    if(lists.empty())
    {
        return nullptr;
    }
    for(int i=0;i<lists.size();i++)
    {
        if(!lists[i])
        {
            pq.push(make_pair(infinity, i));

        }
        else
        {
            pq.push(make_pair(lists[i]->val, i));
        }

    }

    ListNode * head  = nullptr;

    ListNode * lead  = nullptr;

    pq.push(make_pair(infinity, -1));

    int count = 0;

    while(pq.top().first != infinity)
    {

        cout << pq.top().first << endl;
        auto x = pq.top();
        pq.pop();

        int index = x.second;

        if(count==0)
        {
            ListNode* temp  = new ListNode(x.first);
            head = temp;

            lead = head;
        }
        else
        {
            ListNode* temp  = new ListNode(x.first);
            lead->next = temp;

            lead = lead->next;


        }



        lists[index] = lists[index]->next;



        if(lists[index])
        {
            pq.push(make_pair(lists[index]->val, index));
            cout << "pushing: " << lists[index]->val << endl;
        }
        else
        {
            pq.push(make_pair(infinity, index));
            cout << "pushing: infinity " << endl;
        }

        count++;

    }

    return head;

}







int main(){

vector<

return 0;
}






