
#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"  
void init(char mine[ROW][COL], char show[ROW][COL], char spread[ROW][COL])//初始化棋盘  
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW - 1; i++)//初始化9*9棋盘  
	{
		for (j = 0; j < COL - 1; j++)
		{
			mine[i][j] = ' ';
			show[i][j] = '*';
		}
	}

}
void displayboard(char show[ROW][COL])//打印9*9棋盘  
{
	int i, j;
	printf("  |");
	for (i = 1; i < ROW; i++)
	{
		printf("%d ", i);
	}
	printf("\n—|——————————\n");
	for (i = 0; i < ROW - 1; i++)
	{
		printf("%2d|", i + 1);
		for (j = 0; j < COL - 1; j++)
		{
			printf("%c ", show[i][j]);
		}
		printf("\n");
	}


}
void displaymine(char mine[ROW][COL])             
{


	int i, j;
	printf("  |");
	for (i = 1; i <= 10; i++)
	{
		printf("%d ", i);
	}
	printf("\n--|--------------------\n");
	for (i = 0; i < ROW - 1; i++)
	{
		printf("%2d|", i + 1);
		for (j = 0; j < COL - 1; j++)
		{
			printf("%c ", mine[i][j]);
		}
		printf("\n");
	}



}
void  Set_Mine(char mine[ROW][COL], int m) 
{
	int x, y;
	while (m)
	{

		x = rand() % 10 + 0;
		y = rand() % 10 + 0;

		if (mine[x][y] == ' ')
		{
			mine[x][y] = '$';
			m--;
		}

	}
	m = M;
}
int mineNum(char mine[ROW][COL], int x, int y)  //统计周边8个格子的雷数
{
	int count = 0;

	if (mine[x - 1][y - 1] == '$')
	{
		count++;
	}
	if (mine[x - 1][y] == '$')
	{
		count++;
	}
	if (mine[x - 1][y + 1] == '$')
	{
		count++;
	}
	if (mine[x][y + 1] == '$')
	{
		count++;
	}
	if (mine[x + 1][y + 1] == '$')
	{
		count++;
	}
	if (mine[x + 1][y] == '$')
	{
		count++;
	}
	if (mine[x + 1][y - 1] == '$')
	{
		count++;
	}
	if (mine[x][y - 1] == '$')
	{
		count++;
	}

	return count;
}
void spread(char mine[ROW][COL], char show[ROW][COL], const int x, const int y)   //展开函数  
{
	int ret = 0;    int i = 0;    int j = 0;
	int a = x;    int b = y;

	if ((x >= 0)
		&& (x <= 9)
		&& (y >= 0)
		&& (y <= 9))
	{


		if (mine[x - 1][y - 1] == ' ')                        //如果该区域不是雷  
		{
			a = x - 1;
			b = y - 1;
			ret = mineNum(mine, a, b);                     //返回以该区域为中心雷的数量 

			if (ret == 0)                                 //若在这八个区域中哪个区域的周围8个格子无雷  

			{
				show[a][b] = ' ';                        //如果周围没有雷就向玩家展示‘ ’空格  
				mine[a][b] = '0';                        //将雷盘中的区域改为‘0’可方便测试用  

				spread(mine, show, a, b);              //则将这个区域的坐标赋值给x和y，再次进行展开  

			}
			else
			{
				show[a][b] = '0' + ret;
				mine[a][b] = '0';
			}


		}

		if (mine[x][y - 1] == ' ')                                //以下的另外七个区域同理  
		{
			a = x;
			b = y - 1;
			ret = mineNum(mine, a, b);

			if (ret == 0)
			{
				show[a][b] = ' ';
				mine[a][b] = '0';
				spread(mine, show, a, b);
			}
			else
			{
				show[a][b] = '0' + ret;
				mine[a][b] = '0';
			}

		}

		if (mine[x - 1][y] == ' ')
		{
			a = x - 1;
			b = y;
			ret = mineNum(mine, a, b);
			if (ret == 0)
			{
				show[a][b] = ' ';
				mine[a][b] = '0';
				spread(mine, show, a, b);
			}
			else
			{
				show[a][b] = '0' + ret;
				mine[a][b] = '0';
			}

		}
		if (mine[x + 1][y - 1] == ' ')
		{
			a = x + 1;
			b = y - 1;
			ret = mineNum(mine, a, b);
			if (ret == 0)
			{
				show[a][b] = ' ';
				mine[a][b] = '0';
				spread(mine, show, a, b);
			}
			else
			{
				show[a][b] = '0' + ret;
				mine[a][b] = '0';
			}

		}

		if (mine[x + 1][y] == ' ')
		{
			a = x + 1;
			b = y;
			ret = mineNum(mine, a, b);
			if (ret == 0)
			{
				show[x + 1][y] = ' ';
				mine[a][b] = '0';
				spread(mine, show, a, b);
			}
			else
			{
				show[x + 1][y] = '0' + ret;
				mine[a][b] = '0';
			}
		}
		if (mine[x + 1][y + 1] == ' ')
		{
			a = x + 1;
			b = y + 1;
			ret = mineNum(mine, a, b);
			if (ret == 0)
			{
				show[x + 1][y + 1] = ' ';
				mine[a][b] = '0';
				spread(mine, show, a, b);
			}
			else
			{
				show[x + 1][y + 1] = '0' + ret;
				mine[a][b] = '0';
			}


		}
		if (mine[x][y + 1] == ' ')
		{
			a = x;
			b = y + 1;
			ret = mineNum(mine, a, b);
			if (ret == 0)
			{
				show[x][y + 1] = ' ';
				mine[a][b] = '0';
				spread(mine, show, a, b);
			}
			else
			{
				show[x][y + 1] = '0' + ret;
				mine[a][b] = '0';
			}
		}
		if (mine[x - 1][y + 1] == ' ')
		{
			a = x - 1;
			b = y + 1;
			ret = mineNum(mine, a, b);
			if (ret == 0)
			{
				show[x - 1][y + 1] = ' ';
				mine[a][b] = '0';
				spread(mine, show, a, b);
			}
			else
			{
				show[x - 1][y + 1] = '0' + ret;
				mine[a][b] = '0';
			}

		}

	}
}
void sweep_Mine(char mine[ROW][COL], char show[ROW][COL], int x, int y)   //扫雷函数  
{
	int ret = 0;

	if (mine[x][y] == ' ')      //玩家没有踩到雷，即展示该区域周边的雷数，如果雷数为0就显示空格  
	{
		ret = mineNum(mine, x, y);
		if (ret == 0)
		{
			show[x][y] = ' ';


		}
		else
		{
			show[x][y] = '0' + ret;                           //如果有炸弹就显示炸弹的数量 

		}
		spread(mine, show, x, y);                      //并在此调用展开函数，对周边区域进行展开 

	}
	else if (mine[x][y] == '$')
	{

		show[x][y] = mine[x][y];                             //如果玩家踩到炸弹就显示$

	}

}
void prevent_first_death(char mine[ROW][COL], int x, int y)      //防止玩家第一次被炸死  
{
	int m = 0;    int n = 0;

	if (mine[x][y] == '$')
	{
		do
		{
			m = rand() % 11 + 0;
			n = rand() % 11 + 0;                  //如果玩家踩到雷，就重新随机一个没有雷的地方，将炸弹移动到那里  

			if (mine[m][n] == ' ')
			{
				mine[x][y] = ' ';             //将该区域设置为空格
				mine[m][n] = '$';
				break;
			}
		} while (1);
	}


}
int check_win(char mine[ROW][COL], char show[ROW][COL], int m)  //判断输赢  
{
	int i, j, num;
	num = M;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (show[i][j] == '*')                //如果在展示棋盘上剩余 ‘*’的数量和雷数相同，那么就表示扫雷成功      
			{
				num--;
			}
			else if (show[i][j] == '$')         //如果显示盘上出现了 ‘$’说明玩家踩到了雷
			{
				return 1;
			}
			else if (num == 0)
			{
				return 0;

			}
		}
	}    return -1;
}