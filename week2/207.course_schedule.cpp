#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        stack<int> todo;
        vector<vector<int>> incoming(numCourses); // i-th index is prereq for course i
        vector<vector<int>> outgoing(numCourses); // i-th index is all courses `i` is a prereq for

        preProcessCanFinish(prerequisites, incoming, outgoing);

        // Initial stack
        for (int i = 0; i < numCourses; i++) {
            if (incoming[i].size() == 0)
                todo.push(i);
        }

        int done_count = 0;
        vector<bool> done(false, numCourses);
        while (todo.size() > 0) {
            int course = todo.top();
            todo.pop();
            doCourse(course, incoming, outgoing, done, todo);
        }


        return done_count == numCourses;
    }

    void doCourse(int course, vector<vector<int>>& incoming, vector<vector<int>>& outgoing, vector<bool>& done, stack<int>& todo) {

    }

    void preProcessCanFinish(vector<vector<int>> pres, vector<vector<int>>& incoming, vector<vector<int>>& outgoing) {
        for (auto pre : pres) {
            int prereq = pre[0];
            int target = pre[1];
            incoming[target].push_back(prereq);
            outgoing[prereq].push_back(target);
        }
    }

};
