#define _CRT_SECURE_NO_WARNINGS 1
#ifndef __Mine_Clearance__  
#define __Mine_Clearance__  
#include  <stdio.h>  
#include  <stdlib.h>  
#define M  10//定义炸弹数量  
#define ROW 10//定义棋盘大小 
#define COL 10  

void init(char mine[ROW][COL], char show[ROW][COL], char spread[ROW][COL]);//声明game.c中的函数。  

void displayboard(char show[ROW][COL]);

void displaymine(char mine[ROW][COL]);

void Set_Mine(char mine[ROW][COL], int m);

void sweep_Mine(char mine[ROW][COL], char show[ROW][COL], int x, int y);

int check_win(char mine[ROW][COL], char show[ROW][COL], int m);

void prevent_first_death(char mine[ROW][COL], int x, int y);

int mineNum(char mine[ROW][COL], int x, int y);

void spread(char mine[ROW][COL], char show[ROW][COL], const int x, const int y);  
#endif

