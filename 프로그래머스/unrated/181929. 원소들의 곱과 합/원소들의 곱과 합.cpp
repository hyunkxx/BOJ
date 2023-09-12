#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int sum1 = 1;
    int sum2 = 0;
    
    for(int i = 0 ; i < num_list.size(); ++i)
    {
        sum1 *= num_list[i];
        sum2 += num_list[i];
    }
    
    return sum1 < sum2 * sum2 ? 1 : 0;
}