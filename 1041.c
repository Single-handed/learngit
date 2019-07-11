#include<stdio.h>

/* 定义记录项结构体 */
typedef struct record{
    char pno[20];/* 员工ID */
    int sh;/* 签到时间小时 */
    int sm;/* 分钟 */
    int ss;/* 秒数 */
    int eh;/* 签退时间小时 */
    int em;/* 分钟 */
    int es;/* 秒数 */
} record_r;

int main()
{
    int N, M;
    int sts[1000], ets[1000];/* 存放所有员工签到和签退时间总秒数的数组 */
    scanf("%d", &N);
    
    struct record p[1001];
    for (int i = 0; i < N; i++) {
        scanf("%d", &M);
        for (int j = 0; j < M; j++) {
            scanf("%s %d:%d:%d %d:%d:%d", p[j].pno, &p[j].sh, &p[j].sm, &p[j].ss, &p[j].eh, &p[j].em, &p[j].es);
            sts[j] = (p[j].sh * 60 + p[j].sm) * 60 + p[j].ss;/* 计算签到时间总秒数 */
            ets[j] = (p[j].eh * 60 + p[j].em) * 60 + p[j].es;/* 计算签退时间总秒数 */
        }

        int min, max;
        int min_index, max_index;/* 最早签到和最晚签退的下标 */
    
        min_index = max_index = 0;
        min = sts[0], max = ets[0];
        for (int i = 1; i < M; i++) {
            /* 最早签到的下标 */
            if (min > sts[i]) {
                min = sts[i];
                min_index = i;
            }

            /* 最晚签退的下标 */
            if (max < ets[i]) {
                max = ets[i];
                max_index = i;
            }
        }

        printf("%s %s\n", p[min_index].pno, p[max_index].pno);
    }
    
    return 0;
}
