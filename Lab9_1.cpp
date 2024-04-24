// 66070503421 Nutthawut Jaroenchokwittaya
#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include <vector>
using namespace std;

void DFS(vector<vector<int>> adjlist, int startnode, map<int, int> visited1)
{
    stack<int> stt;
    stt.push(startnode);
    visited1[startnode] = 1;
    cout << startnode << " ";
    while (!stt.empty())
    {
        int focusnode = stt.top();
        int i = 0;
        while (1)
        {
            if (visited1[adjlist[focusnode][i]] == 0)
            {
                visited1[adjlist[focusnode][i]] = 1;
                stt.push(adjlist[focusnode][i]);
                focusnode = stt.top();
                cout << focusnode << " ";
                i = 0;
            }
            else
            {
                i++;
            }
            if (i >= adjlist[focusnode].size())
            {
                break;
            }
        }
        stt.pop();
    }
}

void BFS(vector<vector<int>> adjlist, int startnode, map<int, int> visited2)
{
    queue<int> qq;
    qq.push(startnode);
    visited2[startnode] = 1;
    while (!qq.empty())
    {
        int focusnode = qq.front();
        qq.pop();
        cout << focusnode << " ";
        for (int i = 0; i < adjlist[focusnode].size(); i++)
        {
            if (visited2[adjlist[focusnode][i]] == 0)
            {
                visited2[adjlist[focusnode][i]] = 1;
                qq.push(adjlist[focusnode][i]);
            }
        }
    }
}

int main()
{
    int pedge;
    cin >> pedge;
    vector<vector<int>> adjlist(pedge); // assume pedges == nnode
    map<int, int> visited1;
    map<int, int> visited2;
    for (int i = 0; i < pedge; i++)
    {
        int source, destination;
        cin >> source >> destination;
        adjlist[source].push_back(destination);
        adjlist[destination].push_back(source);
        visited1[source] = 0;
        visited1[destination] = 0;
        visited2[source] = 0;
        visited2[destination] = 0;
    }
    int startnode;
    cin >> startnode;
    DFS(adjlist, startnode, visited1);
    cout << endl;
    BFS(adjlist, startnode, visited2);
    return 0;
}