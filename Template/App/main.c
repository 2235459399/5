/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 * 文件名  ： main
 * 作者    ： guolingding
 * 版本    ： V1.0.0
 * 时间    ： 2020-10-06
 * 简要    ：   
 ********************************************************************
 * 副本
 *
 *>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/* 头文件 ----------------------------------------------------------------*/
#include<iocc2530.h>

typedef unsigned int UINT;
typedef unsigned char UCHAR;
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* 函数名：Delay
* 参数：UINT
* 返回：void
* 描述：延时函数
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void Delay(UINT uiDelayMs)
{
    UINT uiLoop,uiLoopj;
      
    for(uiLoop = 0; uiLoop < uiDelayMs; ++uiLoop)
    {  
        for(uiLoopj = 0; uiLoopj < 1000; ++uiLoopj)
        {
            asm("NOP");
            asm("NOP");
            asm("NOP");
        }
    } 
    
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 函数名：main
 * 参数：void
 * 返回：void
 * 描述：主函数/入口函数
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void main(void)
{
    CLKCONCMD &= ~0x40;                          //设置系统时钟源为32MHZ晶振
    while(CLKCONSTA & 0x40);                     //等待晶振稳定
    CLKCONCMD &= ~0x47;                          //设置系统主时钟频率为32MHZ
    
    P1DIR = 0X01;
    P1_0  = 1;
    
    while(1)
    {
        Delay(500);
        P1_0 ^= 1;
    }
}


