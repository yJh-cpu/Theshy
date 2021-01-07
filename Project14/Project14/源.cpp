/**************************************************************************************************
51单片机简易秒表
**************************************************************************************************/

#include <reg51.h>

#define false 0
#define true 1
#define uchar unsigned char	 //0-255
#define uint unsigned int	 		//0-65535
#define ulong unsigned long	//0-4294967295


uchar disCode[10] = { 0x03, 0x9f, 0x25, 0x0d, 0x99, 0x49, 0x41, 0x1f, 0x01, 0x09 }; //段码 0~9
uchar locCode[4] = { 0x01, 0x02, 0x04, 0x08 };					//位码

void displayTime(void);	 //刷新时间显示
void disPlay(uchar num, uchar loc);	 //数码管显示函数
uchar keyscan(void); //键盘扫描函数
void Delay1ms(unsigned int n);	//延时1ms

uchar state;	//状态:0-停止,1-启动,2-暂停
ulong ms = 10066;	//存储毫秒值 单位：10ms  10066 99
uchar fen = 99;	//分钟数
uchar miao;	//秒数
uchar key;

/*******************************************************************************
* 函数名        : T0_INT
* 函数功能        : T0定时器中断10ms
* 输入          : 无
* 输出       : 无
*******************************************************************************/
void T0_INT(void)  interrupt 1
{
	TL0 = (65536 - 9000) / 256;
	TH0 = (65536 - 9000) % 256;
	ms++; //每十ms执行一次
}

/*******************************************************************************
* 函数名         : main
* 函数功能         : 主函数
* 输入          : 无
* 输出       : 无
*******************************************************************************/
void main(void)
{
	TMOD = 0x61; //0110 0001	//方式一
	TL0 = (65536 - 10000) / 256;		// 10ms
	TH0 = (65536 - 10000) % 256;
	TR0 = 1;		//开启T0
	//ET0=1;		//T0中断允许

	EA = 1;	//总中断开启
	while (1)
	{
		key = keyscan();
		displayTime();	 //刷新时间显示
		if (key == 17) //开始键按下
		{
			state = 0;	//将状态设置为启动
			ms = 0;		//清除毫秒
			fen = 0;	//清除分钟
			ET0 = 0;		//T0中断允许

		}
		else if (key == 33){ //暂停
			state = 2; //设置状态为暂停
			ET0 = 0;	//关闭T0中断允许
		}
		else if (key == 65){ //恢复计时
			state = 1; //状态设为启动
			ET0 = 1; 	//T0中断允许
		}
	}
}

/*******************************************************************************
* 函数名         : keyscan
* 函数功能         : 扫描键盘
* 输入          : 无
* 输出       : 键盘按下按键码值
*******************************************************************************/
uchar keyscan(void){
	uchar scancode, tmpcode;
	P1 = 0xf0; //发全0行扫描码
	if ((P1 & 0xf0) != 0xf0){  //若有键按下
		Delay1ms(10);				//延时去抖动
		if ((P1 & 0xf0) != 0xf0){  //延时后再次判断，去除抖动影响
			scancode = 0xfe;
			while ((scancode & 0x10) != 0){ //逐行扫描
				P1 = scancode;   //输出行扫描码
				if ((P1 & 0xf0) != 0xf0){ //本行有键按下
					tmpcode = (P1 & 0xf0) | 0x0f;
					return((~scancode) + (~tmpcode)); //返回特征字节码，为1的位即为对应的行和列
				}
				else{
					scancode = (scancode << 1) | 0x01; //行扫描码左移一位
				}
			}
		}
	}
	return(0); //无键按下，返回0
}

/*******************************************************************************
* 函数名         : displayTime
* 函数功能         : 刷新时间显示
* 输入          : 无
* 输出       : 无
*******************************************************************************/
void displayTime(void)
{
	miao = ms / 100 - fen * 99;
	if (miao > 99)
	{
		miao = 0;
		fen++;
	}
	if (fen > 99){
		fen = 0;
		miao = 0;
		ms = 0;
	}


	disPlay(fen / 10, 0);
	disPlay(fen % 10, 1);
	disPlay(miao / 10, 2);
	disPlay(miao % 10, 3);
}

/*******************************************************************************
* 函数名         : disPlay
* 函数功能         : 数码管显示
* 输入          : num 要显示的数字 loc 要显示的位置
* 输出       : 无
*******************************************************************************/
void disPlay(uchar num, uchar loc)
{
	P0 = 0xff;	//消除重影
	P2 = locCode[loc];	//位码输出
	P0 = disCode[num];	//断码输出
	Delay1ms(1);	//增加显示时间，防止过暗
}

/*******************************************************************************
* 函数名         : Delay1ms
* 函数功能         : 延时函数
* 输入          : 无
* 输出       : 无
*******************************************************************************/
void Delay1ms(unsigned int n)
{
	unsigned char i, j;
	for (; n>0; n--)
	for (i = 0; i<10; i++)
	for (j = 0; j<33; j++);
}