#ifndef support
#define support
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;
void setFullScreen();
void exitFullScreen();
void textcolor(WORD color); 
void SetBGColor(WORD color);
void setColor( int maunen , int mauchu);
void DocFileKhoiDau( char *tenfile );

	

void textcolor(WORD color) 
{ 
    HANDLE hConsoleOutput; 
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE); 

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info; 
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info); 

    WORD wAttributes = screen_buffer_info.wAttributes; 
    color &= 0x000f; 
    wAttributes &= 0xfff0; 
    wAttributes |= color; 

    SetConsoleTextAttribute(hConsoleOutput, wAttributes); 
}


void SetBGColor(WORD color) 
{ 
    HANDLE hConsoleOutput; 
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE); 

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info; 
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info); 

    WORD wAttributes = screen_buffer_info.wAttributes; 
    color &= 0x000f; 
    color <<= 4; 
    wAttributes &= 0xff0f; 
    wAttributes |= color; 

    SetConsoleTextAttribute(hConsoleOutput, wAttributes); 
}

void setColor(int maunen, int mauchu)
{
	SetBGColor(maunen);
	textcolor(mauchu);
}
void DocFileKhoiDau( char *tenfile ){
	string s;
	int dem = 0;
	ifstream fin(tenfile);
	while( getline( fin , s )){
		dem++;
		if( dem <= 5){
			textcolor(15);
			SetBGColor(1);
		}
		else if( dem >= 14 && dem < 18 ){
			textcolor(15);
			SetBGColor(1);
		}
		else if( dem >= 18 ){
			textcolor(0);
			SetBGColor(0);
		}
		else if( dem > 2 && dem < 14 ){
			textcolor(12);
			SetBGColor(0);
		}
		s.erase( s.begin() + s.length() );
		cout << s << endl;
	}
	fin.close();
}
void docfilechao(char *tenfile){
		 FILE* ptr;
    char ch;
 	int dem=0;
    // Opening file in reading mode
    ptr = fopen(tenfile, "r");
 
    if (NULL == ptr) {
        cout<<"file can't be opened \n";
    }
 
    // Printing what is written in file
    // character by character using loop.
    do {
    	textcolor(1+(rand()%12));//in mau ngau nhien
        ch = fgetc(ptr);
       	cout<<ch;
 
        // Checking if character is not EOF.
        // If it is EOF stop eading.
    } while (ch != EOF);
 
    // Closing the file
    fclose(ptr);
}
void gotoxy(short int x,short int y) 
{ 
    HANDLE hConsoleOutput; 
    COORD Cursor_an_Pos = { x,y}; 
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos); 
}

void LoadFileDuLieu(){
	gotoxy(49,0);cout << "LOADING...";
	for( int i = 0 ; i <= 50 ; i++ ){
		textcolor(10);
		gotoxy(30 + i,1);cout << char(219);
		textcolor(15);
		gotoxy(55,2);cout << i * 2 << "%";
		Sleep(10);
	}
	textcolor(14);
	gotoxy(45,2);cout << "FINISH";
	Sleep(1);
}
void inbangthongbao(int x,int y,string noidung){
	for(int i=y;i<4+y;i++){
		for(int j=x;j<40+x;j++){
			setColor(14,0);
			//in theo hang ngang
			if(i==y || i==y+3){
				gotoxy(j,i);
				cout<<char(205);
			}
			else if(j==x || j==39+x){
				gotoxy(j,i);
				cout<<char(186);
			}
		
			else{
			
			setColor(14,12);
			gotoxy(j,i);
			cout<<" ";
		}
		 	gotoxy(x,y);
		 	cout<<char(201);//in chong cac goc cua man hinh 
		 	gotoxy(x,y+3);
		 	cout<<char(200);
		 	gotoxy(x+39,y);
		 	cout<<char(187);
		 	gotoxy(x+39,y+3);
		 	cout<<char(188);
		 	gotoxy(x+15,y+1);
		 	setColor(14,12);
		 	cout<<char(127)<<"CANH BAO";
		 	gotoxy(x+2,y+2);
		 	cout<<noidung;
		}
	}
		Sleep(1500);
}
void XoaBangThongBaoLoi(int x,int y){
	for( int i = y ; i < 4+y ; i++ ){
		for( int j = x ; j <x+40 ; j++ ){
			gotoxy(j,i);
			SetBGColor(0);
			cout << " ";
		}
	}
	SetBGColor(8);
	textcolor(0);
}
#endif
