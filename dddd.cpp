#include "stm32f10x.h"                  // Device header
#include "stdlib.h" 

static void dot(int row, int col);

int main(void){
RCC->APB2ENR |=(1<<2);
GPIOA->CRL |=GPIO_CRL_MODE;
GPIOA->CRL &=~GPIO_CRL_CNF;
GPIOA->CRH |=GPIO_CRH_MODE;
GPIOA->CRH &=~GPIO_CRH_CNF;
RCC->APB2ENR |=(1<<3);
	
	GPIOB->CRL &=~(1<<0);
	GPIOB->CRL &=~(1<<1);
	GPIOB->CRL &=~(1<<2);
	GPIOB->CRL |=(1<<3);
	
	GPIOB->CRL &=~(1<<16);
	GPIOB->CRL &=~(1<<17);
	GPIOB->CRL &=~(1<<18);
	GPIOB->CRL |=(1<<19);
	
	GPIOB->CRL &=~(1<<20);
	GPIOB->CRL &=~(1<<21);
	GPIOB->CRL &=~(1<<22);
	GPIOB->CRL |=(1<<23);
	
	GPIOB->CRL &=~(1<<24);
	GPIOB->CRL &=~(1<<25);
	GPIOB->CRL &=~(1<<26);
	GPIOB->CRL |=(1<<27);
int row=3;
int col=2;
int br=0,t;
int row1, col1;
broj: row1=rand()%7;
col1=rand()%5;
if(br==0) t=0;
if(br==1)	t=1000;
if(br==2) t=10000;
if(br==3) t=20000;
	if(br==4) t=50000;
while(t<150000){
	
dot(row,col);
	if(row==-1) row=6;
	if(row==7) row=0;
	if(col==-1) col=4;
	if(col==5) col=0;
	if(GPIOB->IDR & GPIO_IDR_IDR0){
	row--;
		while(GPIOB->IDR & GPIO_IDR_IDR0){;}
	}
	if(GPIOB->IDR & GPIO_IDR_IDR4){
	row++;
		while(GPIOB->IDR & GPIO_IDR_IDR4){;}
	}
	if(GPIOB->IDR & GPIO_IDR_IDR5){
	col--;
		while(GPIOB->IDR & GPIO_IDR_IDR5){;}
	}
	if(GPIOB->IDR & GPIO_IDR_IDR6){
	col++;
		while(GPIOB->IDR & GPIO_IDR_IDR6){;}
	}
if(row==row1 && col==col1){
		for(int i=0;i<7;i++){
		for(int j=0;j<5;j++){
		dot(i,j);
			for(int p=0;p<100000;p++);
		}
		}
		for(int p=0;p<1000;p++);
	br++;
	goto broj;
	}
	if(t==149999){
	break;
			
		}
	t++;
	}

	

if(t==149999){
	GPIOA->ODR |=(1<<0);
	GPIOA->ODR |=(1<<1);
	GPIOA->ODR |=(1<<2);
	GPIOA->ODR |=(1<<3);
	GPIOA->ODR |=(1<<4);
	GPIOA->ODR |=(1<<5);
	GPIOA->ODR |=(1<<0);
	GPIOA->ODR |=(1<<1);
	GPIOA->ODR |=(1<<2);
	GPIOA->ODR |=(1<<3);
	GPIOA->ODR |=(1<<4);
	GPIOA->ODR |=(1<<5);
	GPIOA->ODR &=~(1<<8);
	GPIOA->ODR &=~(1<<9);
	GPIOA->ODR &=~(1<<10);
	GPIOA->ODR &=~(1<<11);
	GPIOA->ODR &=~(1<<12);
	GPIOA->ODR &=~(1<<6);
	if(br==0){};
		if (br==1){
		GPIOA->ODR |=(1<<br+7);
		}
		if (br==2){
		GPIOA->ODR |=(1<<br+7);
			GPIOA->ODR |=(1<<br+6);
		}
		if (br==3){
		GPIOA->ODR |=(1<<br+7);
			GPIOA->ODR |=(1<<br+6);
			GPIOA->ODR |=(1<<br+5);
		}
		if (br==4){
		GPIOA->ODR |=(1<<br+7);
			GPIOA->ODR |=(1<<br+6);
			GPIOA->ODR |=(1<<br+5);
			GPIOA->ODR |=(1<<br+4);
		}
		if (br==5){
		GPIOA->ODR |=(1<<br+7);
			GPIOA->ODR |=(1<<br+6);
			GPIOA->ODR |=(1<<br+5);
			GPIOA->ODR |=(1<<br+4);
			GPIOA->ODR |=(1<<br+3);
		}
	
}
}
void dot(int row,int col){
	for(int i=0;i<7;i++){
		
		if(i==row) GPIOA->ODR &=~(1<<i);
		else GPIOA->ODR |=(1<<i);
		for(int j=0;j<5;j++){
		if(j==col) GPIOA->ODR |=(1<<j+8);
			else GPIOA->ODR &=~(1<<j+8);
		}
	
	
	}
	
}