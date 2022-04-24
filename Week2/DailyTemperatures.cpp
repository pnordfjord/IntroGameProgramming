// problem from https://leetcode.com/problems/daily-temperatures/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int tempSize = temperatures.size();
        vector<int> answer(tempSize);
        for (int i = 0; i < tempSize; ++i){
            for(int j = i+1; j < tempSize; ++j){
                if (temperatures[j] > temperatures[i]){
                    answer[i] = j-i;
                    break;
                }
            }
            if (answer[i] == NULL) {
                answer[i] = 0;
            }
        }
        return answer;
    }
};