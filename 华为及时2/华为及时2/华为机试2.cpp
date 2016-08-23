/*开始时间： 2016-07-18 16:56:40
实现功能：
*/
/*开始时间： 2016-07-18 16:56:40
实现功能：
*/

#include <stdio.h>
#include <string.h>
 
#define MAX 101
 
int Max (int a, int b, int c){
    a = (a > b) ? a : b;
    a = (a > c) ? a : c;
    return a;
}
 
int main(void){
    int n;
    int hash[MAX][MAX][MAX];
    int dp[MAX][MAX][MAX];
    int length;
    int width;
    int height;
    int i;
    int j;
    int k;
    int max;
 
    while (scanf ("%d", &n) != EOF){
        memset (hash, 0, sizeof(hash));
        memset (dp, 0, sizeof(dp));
        for (i=0; i<n; ++i){
            scanf ("%d%d%d", &length, &width, &height);
            ++hash[length][width][height];
        }
        max = 0;
        for (i=1; i<MAX; ++i){
            for (j=1; j<MAX; ++j){
                for (k=1; k<MAX; ++k){
                    dp[i][j][k] = Max (dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]) + hash[i][j][k];
                    if (dp[i][j][k] > max)
                        max = dp[i][j][k];
                }
            }
        }
        printf ("%d\n", max);
    }
    return 0;
}