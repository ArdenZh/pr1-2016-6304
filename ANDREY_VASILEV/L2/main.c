#include <stdio.h>     
#include "menu.h"    //Подключаем заголовочный файл
int main(){              // c описанием функций menu
	int i, n, ch;
	printf("Число элементов массива: "); 
	scanf("%d", &n);         //Вводим число эл. массива
	int arr[n];
	for (i = 0; i <n; i++){
		printf("arr[%d]= ", i);   //Цикл для заполнения
		scanf("%d", &arr[i]);    // массива значениями
	}
	printf("Номер команды: ");     //Вводим номер команды
	scanf("%d", &ch);	      //  меню
	menu(ch, n, arr);    //передаем значения в функцию
}		    //   menu и получаем результат                
