#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int row = text1.size() + 1;
        int col = text2.size() + 1;
        //dp[i][j]的含义是text1的前i与text2的前j个字符里的lcs;设立状态

        int** dp = new int* [row];//申请二维dp表
        for (int i = 0;i < row;i++)
        {
            dp[i] = new int[col];
        }
        for (int i = 0;i < row;i++)
        {
            for (int j = 0;j < col;j++)
            {
                if (i == 0) dp[0][j] = 0;
                else if (j == 0)dp[i][0] = 0;
                //如果当前text1[x]与text2[y]处字符相等，则观察矩阵中往对角线上的一个元素并加1；
                else if (text1[i-1] == text2[j-1]) dp[i][j] = dp[i - 1][j - 1]+1;/*dp的索引如dp[1][2]指向字符串的第一个字符text[0]
                                                                                   与text2[1]的前i，j处的lcs*/
                else   dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                cout << dp[i][j];
            }
        }
        int result = dp[row - 1][col - 1];
        for (int k = 0;k < row;k++)
        {
            delete[] dp[k];
        }
        delete[]dp;
        return result;
    }
};
int main()
{
    string text1 = "abc";
    string text2 = "def";
    Solution sol;
    sol.longestCommonSubsequence(text1, text2);
}