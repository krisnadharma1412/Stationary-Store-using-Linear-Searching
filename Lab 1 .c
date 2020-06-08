/* By : 
  
  1. Nama : I Putu Krisna Dhaema Saputra
  2. NIM  : 2301924353
  
*/

//Header File
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

//Fungsi Agar Ketika Program dibuka layarnya Full Screen
void fullscreen()
{  keybd_event(VK_MENU,
               0x38,
                0,
                0);
    keybd_event(VK_RETURN,
                0x1c,
                0,
                0);
    keybd_event(VK_RETURN,
                0x1c,
                KEYEVENTF_KEYUP,
                0);
    keybd_event(VK_MENU,
                0x38,
                KEYEVENTF_KEYUP,
                0);
}

//Deklarasi Struct
struct stationery {
	char code[7];
	char name[6];
	int stock;
	int price;
};

//Input Struct
struct stationery station[4]={
	{"SA001","Pencil",140,7500},
	{"SA004","Eraser",90,5000},
	{"SA009","Pen",120,8000},
	{"SA012","Notes",80,9500}
};

//Fungsi Memunculkan Tabel	
void table(){
	int i;
	printf("\t\t\t\t\t\t\t\t   BAGOES Stationery Store CASHIER\n");
	printf("\t\t\t\t\t\t\t\t   ===============================\n\n\n");
	printf("\t\t\t\t\t\t ______________________________________________________________________\n");
	printf("\t\t\t\t\t\t|No. | Stationery Code | Sationery Name    | Available | Price         |");
	printf("\n\t\t\t\t\t\t|____|_________________|___________________|___________|_______________|");
	for(i=0;i<4;i++){
	printf("\n\t\t\t\t\t\t|0%d. | %s           | %s	           | 	  %3d  | Rp.	%d,- |",i+1,station[i].code,station[i].name,station[i].stock,station[i].price);
	fflush(stdin);	
	}
	printf("\n\t\t\t\t\t\t|______________________________________________________________________|");
}

//Fungsi Linear Searching
int search( char *code){
	int i;
	
	for(i = 0 ; i < 4 ; i++){
			if(strcmp(station[i].code,code) == 0){
				return i;
			}
		}
	return -1;
}

//Fungsi menu ke 1 yaitu sell
void sell(){
	int indeks,stock,total;
	char code[10];
	
	do{
	system("cls");
	table();
	printf("\n\n\t\t\t\t\t\t Input Stationery Code [5 chars]: ");// input stationery code
	gets(code);
		
	if(search(code) == -1){ // searching
		printf("\n\n\t\t\t\t\t\t\t\t   --- The Stationary Code doesn't exist ---");		
		getch();
	    }
	else{
		indeks = search(code);
		
		do{
		system("cls");
		table();
		printf("\n\n\t\t\t\t\t\t Input Stationery Code [5 chars]: %s",code);
		printf("\n\t\t\t\t\t\t Input Quantity [0...%d]: ",station[indeks].stock);
		scanf("%d",&stock);
		fflush(stdin);
		if(stock>station[indeks].stock){
			printf("\n\n\t\t\t\t\t\t\t\t   ...The quantity of stationery is not enough...");
			getch();
			}
		}while(stock>station[indeks].stock);		
		
		total = station[indeks].price * stock;
		printf("\t\t\t\t\t\t Total Price is: Rp %d,-  x  %d  =  Rp %d,-",station[indeks].price,stock,total);
		
		station[indeks].stock = station[indeks].stock - stock; //mengurangi stock pada tabel
		printf("\n\n\t\t\t\t\t\t\t\t       --- Thank You ---");
		getch();
	  }
	}while(search(code) == -1);
}	
		
// Fungsi menu ke 2, menambahkan stock 
void add(){
	int indeks,stock,total;
	char code[10];
	
	do{
	system("cls");
	table();
	printf("\n\n\t\t\t\t\t\t Input Stationery Code [5 chars]: ");// input stationery code
	gets(code);
		
	if(search(code) == -1){ //
		printf("\n\n\t\t\t\t\t\t\t\t   --- The Stationery Code doesn't exist ---");		
		getch();
	 }
	else{
		indeks = search(code);
		
		do{
		system("cls");
		table();
		printf("\n\n\t\t\t\t\t\t Input Stationery Code [5 chars]: %s",code);
		printf("\n\n\t\t\t\t\t\t Input Quantity [0...10]: ");
		scanf("%d",&stock);
		if(stock<0 || stock>10){
			printf("\n\n\t\t\t\t\t\t\t\t Quantity must between 0...10");
		getch();
		}
		}while(stock<0 || stock>10 );
				
		station[indeks].stock = station[indeks].stock + stock; //menambah stock pada tabel
		printf("\n\t\t\t\t\t\t\t\t   --- Adding Stock Success ---");
		getch();
		
	 }
	}while(search(code) == -1);
}

//fungsi main
void main(){
	
	fullscreen();
	system(" color f0"); // mengubah warna background program menjadi putih
	int choice;
	
	do{ 
		system("cls");
		table();	
		printf("\n\n\t\t\t\t\t\t Menu :");
		printf("\n\t\t\t\t\t\t 1. Sell\n");
		printf("\t\t\t\t\t\t 2. Add Stock\n");
		printf("\t\t\t\t\t\t 3. Exit\n");
		printf("\n\t\t\t\t\t\t Input Choice :");
		scanf("%d",&choice);
	
		switch (choice){
			case 1 :{
				system("cls");
				table();
				sell(station);
				break;
				}
			case 2 :{
				system("cls");
				table();
				add(station);
				break;
			}
	
    	}
    
    }while(choice!=3);
    system("cls");
 
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");	
	printf("\t\t\t\t\t     _________ 	    ___     ___	      ____	  __	 ______    ___   ____  ___________      	\n");
	printf("\t\t\t\t\t    |___   ___|    |   |   |   |     /	  \\	 |  |   /      |  |   | /   /  |  ________|      \n");
	printf("\t\t\t\t\t	| |	   |   |___|   |    /  /\\  \\	 |  |  /   /|  |  |   |/   /   | |________\n");
	printf("\t\t\t\t\t	| |	   |   	       |   /  /__\\  \\	 |  | /	  / |  |  |	   <   |_________ |\n");
	printf("\t\t\t\t\t	| |	   |   	___    |  /  ______  \\   |  |/   /  |  |  |   |\\   \\    ________| |\n");
	printf("\t\t\t\t\t	|_|	   |___|   |___| /__/	   \\__\\  |______/   |__|  |___| \\___\\  |__________| \n");

  	getch();
}

