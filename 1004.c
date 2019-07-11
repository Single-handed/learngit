#include<stdio.h>

int main()
{
    int n;
    int a[101][101];
    scanf("%d", &n);
    
    int i, j;/* 遍历二维数组使用的下标变量 */
    int r, c;/* 填充二维数组值使用的下标变量 */
    int num;/* 填充二维数组的变量，范围是1到n的平方 */

    /* 初始化二维数组：填充0 */
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }

    num = 1;
    r = 0, c = n - 1;/* 从右上角第一个元素为1 */
    a[r][c] = num;
    /* 四个方向填充二维数组，填充的值的范围是1～n*n */
    while (num < n*n) {
        /* 右上到右下。下标没有越界并且没有被填充过即值为0，则填充为num */
        while ((r + 1 < n) && a[r + 1][c] == 0) {
            r++;
            num++;
            a[r][c] = num;
        }

        /* 右下到左下 */
        while ((c - 1 >= 0) && a[r][c - 1] == 0) {
            c--;
            num++;
            a[r][c] = num;
        }

        /* 左下到左上 */
        while ((r - 1 >= 0) && a[r - 1][c] == 0) {
            r--;
            num++;
            a[r][c] = num;
        }

        /* 左上到右上 */
        while ((c + 1 < n) && a[r][c + 1] == 0) {
            c++;
            num++;
            a[r][c] = num;
        }
    }

    /* 输出填充完的二维数组 */
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            /* 3阶及以下的二维数组输出需要占2格 */
            if (n <= 3) {
                /* 如果是一行中的最后一个元素则要换行 */
                if (j == n-1) {
                    printf("%2d\n", a[i][j]);
                    break;
                } 

                printf("%2d ", a[i][j]);
            } else {
                if (j == n-1) {
                    printf("%d\n", a[i][j]);
                    break;
                }

                printf("%d ", a[i][j]);
            }
        }
    }

    return 0;
}
