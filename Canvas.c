// 成语游戏画布
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "CountTime.c"

int Height = 24;

// 移动光标到指定位置
void gotoxy(int x, int y) {
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// 画布边框
void drawBorder(int x, int y, int width, int height) {
    gotoxy(x, y);
    printf("+");
    for (int i = 0; i < width - 2; i++) {
        printf("-");
    }
    printf("+");
    for (int i = 0; i < height - 2; i++) {
        gotoxy(x, y + 1 + i);
        printf("|");
        gotoxy(x + width - 1, y + 1 + i);
        printf("|");
    }
    gotoxy(x, y + height - 1);
    printf("+");
    for (int i = 0; i < width - 2; i++) {
        printf("-");
    }
    printf("+");
}

// 居中显示欢迎界面
void welcome() {
    system("cls");
    drawBorder(1, 1, 80, Height);
    gotoxy(36, Height/2);
    printf("欢迎来到成语游戏");
    gotoxy(36, Height/2 + 1);
    printf("游戏开始，请按任意键开始");
    getch();
}

// 显示规则
void showRule() {
    system("cls");
    drawBorder(1, 1, 80, Height);
    gotoxy(3, 4);
    printf("游戏规则：");
    gotoxy(3, 6);
    printf("1. 本游戏为成语游戏，游戏开始后，您将看到一个问题。");
    gotoxy(6, 8);
    printf("请根据问题，选择对应的答案。");
    gotoxy(3, 10);
    printf("2. 本游戏有三种题型，分别为：");
    gotoxy(3, 12);
    printf("a. 单词填空，选择最合适的单词。");
    gotoxy(3, 14);
    printf("b. 显示一个成语的释义，选择最合适的选项。");
    gotoxy(3, 16);
    printf("c. 显示一个成语的抗疫新译，选择最合适的选项。");
    gotoxy(3, 18);
    printf("您只需要输入a、b、c中的一个字母即可，或输入q退出游戏。");
    gotoxy(3, 22);
    // 等待用户翻页
    printf("按下任意键继续......");
    getch();
    // 清屏
    system("cls");
    // 重新画边框
    drawBorder(1, 1, 80, Height);
    gotoxy(3, 4);
    printf("游戏规则：");
    gotoxy(3, 6);
    printf("3. 游戏为得分制，每个问题有三个答案，分别对应A、B、C。");
    gotoxy(6, 8);
    printf("您只需要根据您的选择，选择对应的答案即可。");
    gotoxy(3, 10);
    printf("4. 答对一题得5分，答错不得分。得分为100分时，胜利！");
    gotoxy(3, 12);
    printf("5. 游戏结束后，您将看到游戏结果，包括您的错题数和游戏时间。");
    gotoxy(3, 19);
    printf("按下任意键开始游戏......");
    getch();
}

// 输入框
void gotoInputBox(int height) {
    gotoxy(1, height+2);
}

// 在右上角显示时间
_Noreturn void showTime() {
    while (1) {
        if (getTime() > timeCount) {
            gotoxy(60, 2);
            countTime();
            gotoInputBox(Height);
        }
    }
}

// 右上角显示答对题数
void showRightNum(int rightNum) {
    gotoxy(60, 3);
    printf("答对题数：%d", rightNum);
}

// 右上角显示答错题数
void showWrongNum(int wrongNum) {
    gotoxy(60, 4);
    printf("答错题数：%d", wrongNum);
}
