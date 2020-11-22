#include <algorithm>
#include <vector>
#include <deque>
#include <stack>
#include <queue>

void DFS_recursion(int start, vector<int> graph[], bool check){
    // check for visit
    check[start] = true;

    for(int i=0; i<graph[start].size(); i++){
        int next = graph[start][i];

        // if next is not visited, keep DFS
        if(check[next] == false) DFS_recursion(next, graph, check);
    }
}

void DFS_stack(int start, vector<int> graph[], bool check){
    stack<int> s;
    s.push(start);
    check[start] = true;

    while(!s.empty()){
        int cur_node = s.top();
        s.pop();

        for(int i=0; i<graph[cur_node].size(); i++){
            int next_node = graph[cur_node][i];

            if(check[next_node] == false){
                check[next_node] == true;

                s.push(cur_node);
                s.push(next_node);
                break;
            }
        }
    }
}


void BFS(int start, vector<int> graph[], bool check){
    queue<int> q;

    q.push(start);
    check[start] = true;

    while(!q.empty()){
        int tmp = q.front();
        q.pop();

        for(int i=0; i<graph[tmp].size(); i++){
            if(check[graph[tmp][i]] == false){
                q.push(graph[tmp][i]);
                check[graph[tmp][i]] = true;
            }
        }
    }
}