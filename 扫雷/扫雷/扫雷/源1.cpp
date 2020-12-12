#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"  
void mune()
{
	printf("******************************************************************\n");
	printf("***************************0.exit*********************************\n");
	printf("***************************1.play*********************************\n");
	printf("******************************************************************\n");
}
void game()
{
	char mine[ROW][COL];
	char show[ROW][COL];
	char spread[ROW][COL];
	int x, y, m;
	int row, col;
	int count = 0;
	int ret;
	row = ROW;
	col = COL;
	m = M;//将定义中的雷数M赋值给m  
	init(mine, show, spread);
	Set_Mine(mine, m);

	//displaymine(mine);//在测试中显示雷  
	do
	{
		displayboard(show);
		count++;
		printf("————————————————");
		printf("开始扫雷>:");
		scanf("%d %d", &x, &y);
		getchar();
		x = x - 1;
		y = y - 1;
		if (count == 1)
		{
			prevent_first_death(mine, x, y);
		}
		sweep_Mine(mine, show, x, y);

		ret = check_win(mine, show, m);
		if (ret == 1)
		{
			displayboard(show);
			printf("————————————————");
			printf("踩到炸弹 GG \n\n");
			break;
		}
		else if (ret == 0)
		{
			displayboard(show);
			printf("————————————————");
			printf("扫雷成功！\n\n ");
			break;
		}

	} while (1);

}
int main()
{
	int n = 0;
	do
	{
		mune();
		printf("——请选择：");
		scanf("%d", &n);
		printf("—————————————————————————————————\n");
		getchar();
		if (n == 1)
		{
			game();
		}
		else if (n == 0)
		{
			break;
		}
		else
		{
			printf("输入有误 重新输入\n");
		}

	} while (1);


	return 0;
}