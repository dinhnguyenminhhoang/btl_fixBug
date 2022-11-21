#ifndef dangnhap
#define dangnhap
#include "support.h"
#include <string>
using namespace std;
void KhungTieuDe(int x , int y , int chieurong , int chieudai , int mauchu , int maunen);
void manhinhdangnhap();
void taokhung(int x,int y,int length,int height);
//void thanhsang(int x,int y,int height,int lenght);
void dichuyendangnhap();
void thanhsang(int x,int y,int height,int lenght,int backgroundcolor,int textcolor){
	setColor(backgroundcolor,textcolor);
	for(int i=0;i<lenght;i++){
		for(int j=0;j<height;j++){
			gotoxy(x+i,y+j);
			cout<<" ";
		}
	}
};
class DangNhap{
	string taikhoan;
	char matkhau[20] ;
	public:
	
		void nhaptaikhoan(int x,int y);
};
void DangNhap::nhaptaikhoan(int x,int y){
	int xcu=x,ycu=y;
	bool kt=true;
	int i=0;
	while(kt){
		thanhsang(x,y,1,28,1,2);//thanh sang cho nhap tai khoan 
		gotoxy(x,y);
		do{
			thanhsang(x,y,1,28,1,2);
			gotoxy(x,y);
			getline(cin,this->taikhoan);
		}while(taikhoan.empty());
		lamlai:
		char a;
	//	matkhau[20]=NULL;
		strcpy(matkhau,"\0");
		thanhsang(x,y+2,1,28,1,2);//thanh sang cho nhap mat khau
		gotoxy(x,y+2);
		//getline(cin,this->matkhau);
		do
    	{
    		a=getch();
    		 if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
            //kiem tra ki tu nhap vao thuoc alphabet
        	{
           		matkhau[i]=a;//lau mat khau
            	i++;
            	cout<<"*";
        	}
        else if(a=='\b' && i>=1)//neu nguoi dung nhan nut xoa
        {
            cout<<"\b \b";//di chuyen ra sau ki tu dang sau con tro
            i--;
        }
        else if(a=='\r'){
        	break;
		}
        else{
        	//matkhau="";
        	inbangthongbao(15,10,"ky tu nhap khong hop le");
        	XoaBangThongBaoLoi(15,10);
        	goto lamlai;
		}
       
    	} while(a!='\r');
    //	gotoxy(1,1);
    //	cout<<this->matkhau;
    	_getch();
		kt=false;
	}
		
		
		
	}

void manhinhdangnhap(){//ham chinh cua ham dang nhap 
	DangNhap a;
	KhungTieuDe(30,0,23,2,2,7);//tao khung tieu de dang nhap
	textcolor(14);
	SetBGColor(0);
	gotoxy(37,1);cout << "DANG NHAP";
	SetBGColor(3);
	taokhung(20,5,43,5);
//	thanhsang(33,6,1,28,8,2);
   	a.nhaptaikhoan(33,6);
	//a.laydulieutunguoidung();
}	
void taokhung(int x,int y,int length,int height){//ham tao khung dang ki dang nhap
	for(int i=0;i<length;i++){
		for(int j=0;j<height;j++){
			if(j==2){
			//	SetBGColor(0);
				gotoxy(x+i,y+j);
				cout<<char(196);
			}
			else if(i<=10){
				SetBGColor(5);
				gotoxy(x+i,y+j);
				cout<<" ";
			}
			else{
			SetBGColor(3);
			gotoxy(x+i,y+j);
			cout<<" ";
		}
		}
		cout<<endl;
	}
		SetBGColor(0);
		gotoxy(x+1,y+1);
		cout<<"Tai Khoan";
		gotoxy(x+1,y+3);
		cout<<"Mat Khau";
		
}
void KhungTieuDe( int x , int y , int chieurong , int chieudai , int mauchu , int maunen ){//khung tieu de dang nhhap
	gotoxy(x , y);
	textcolor(mauchu);
	SetBGColor(maunen);
	for( int i = 0 ; i < chieurong ; i++ ){
		if( i == 0 ){
			cout << char(201);
		}
		else if( i == chieurong - 1 ){
			cout << char(187);
		}
		else{
			cout << char(205);
		}
	}
	for( int i = 1 ; i < chieudai ; i++ ){
		gotoxy(x , y + i);
		cout << char(186);
		gotoxy(x + chieurong - 1 , y + i);
		cout << char(186);
	}
	gotoxy(x , y + chieudai );
	for( int i = 0 ; i < chieurong ; i++ ){
		if( i == 0 ){
			cout << char(200);
		}
		else if( i == chieurong - 1 ){
			cout << char(188);
		}
		else{
			cout << char(205);
		}
	}
}

#endif

