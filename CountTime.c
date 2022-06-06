#include <time.h>

time_t startTime;
int timeCount;

// 声明函数
void countTime();
void initTime();
int getTime();

// 秒表,每秒调用一次
void countTime() {
    timeCount = getTime();
    printf("游戏已开始：%d秒", timeCount);
}

// 初始化计时器
void initTime() {
    startTime = time(NULL);
}

// 获取当前时间
int getTime() {
    return time(NULL) - startTime;
}