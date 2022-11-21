#include <iostream>
#include "support.h"
#include "nhapthongtinruou1.h"
#include "dangnhap.h"
#include "XemThongTinRuouDaNhap.h"
//#include "ChonSanPham.h"
#include "ChonGioHang.h"
void thongtinruou();
void BangMenu(int xx,int yy);
void menuchinh();

void kiemtraphimnhap(int x,int y,string a[]);
void menuchinh(){ 
int h=8;//toa do cua y
int w=22;//toa do cua x
string str[10];//dùng mang dê làm thanh sáng
	SetBGColor(7);
	textcolor(0);
	str[0]="   1)   NHAP THONG TIN RUOU                       ";
	str[1]="   2)   XEM DANH SACH RUOU CON TRONG KHO          ";
	str[2]="   3)   CHON SAN PHAM CHO GIO HANG                "; 
	str[3]="   4)   GIO HANG                                  "; 
	str[4]="   5)   Top 10 loai ruou ban chay nhat            ";

//	str[9]= "                                                                      ";

    BangMenu(15,5);
    	SetBGColor(0);
	for(int i=0;i<11;i++){
		gotoxy(72,h+i);
		cout<<" ";
	}
	SetBGColor(0);
	for(int i=0;i<51;i++){
		gotoxy(w+i,h+11);
		cout<<" ";
	}
    gotoxy(w+20,6);   
	setColor(7,4); 
	cout <<"==MENU CHINH==";
	setColor(14,1);
	gotoxy(w,h);cout << "                                                  ";
	
    gotoxy(w,h+1);cout <<str[0]; 
	gotoxy(w,h+2);cout << "                                                  ";
    gotoxy(w,h+2+1);cout << str[1];//"   2. Xem danh sach ruou con trong kho                                "; 
    gotoxy(w,h+4);cout << "                                                  ";
    gotoxy(w,h+3+2);cout << str[2];//"   3. Xem danh sach ruou da ban                                       ";
	gotoxy(w,h+6);cout << "                                                  "; 
//	gotoxy(w,h+6);cout << "                                                  "; 
    gotoxy(w,h+4+3);cout <<str[3];
	gotoxy(w,h+8);cout << "                                                  "; //"   4. Tim ten khach hang da mua                                       "; 
    gotoxy(w,h+5+4);cout << str[4];//"   5. Tim khach hang theo so dien thoai                               "; 
    //gotoxy(w,h+6);cout <<str[5]; //"   6. Liet ke danh sach cac sach ma 1 doc gia da muon                 "; 
   // gotoxy(w,h+7);cout << str[6];//"   7. Danh sach doc gia muon qua han theo thu tu thoi gian giam dan   ";
//	gotoxy(w,h+8);cout <<str[7]; //"   8. In 10 sach co so luot muon nhieu nhat                           ";
	//gotoxy(w,h+9);cout << str[8];//"   9. Thoat                                                           ";
	gotoxy(w,h+10);cout <<"                                                  ";
	kiemtraphimnhap(w,h+1,str);
}
void kiemtraphimnhap(int x,int y,string a[10]){
	bool kt=true;
	int xcu=x, ycu=y;
	char c;
	int i=0;//index dung de truy cap vao mang 
	int icu;
	while(kt){
		setColor(14,1);//chinh lai mau cu 
		gotoxy(xcu,ycu);
		cout<<a[icu];
		icu=i;
		gotoxy(x,y);//tao mau dong dau tien
		setColor(2,4);
		xcu=x, ycu=y;
		cout<<a[i];
		c=_getch();
		switch(c){
			case 72://phim len
				if(y==9){
					y=17;
					i=4;
				}
				else{
					y=y-2;
					i--;
				}
			break;
			case 80://phim xuong
			if(y==17){
				y=9;
				i=0;
			}
			else {
				y=y+2;
				i++;
			}
			break;
			case 13:
				if(y==9){
					SetBGColor(0);
					system("cls");
					//inbangmenunhapthongtinruou(6,4,5);
					int b;
					inbangmenunhapthongtinruou(6,4,b);
					SetBGColor(0);
					menuchinh();
					kt=true;
				}
				if(y==11){
					SetBGColor(0);
					system("cls");
					xuatthongtin *head=new xuatthongtin;
					int sobang;
					LayDuLieuDaNhap(3,5,head,sobang);//ti chinh lai du lieu
					SetBGColor(0);
					system("cls");
					menuchinh();
					
					kt=true;
				}
				if(y==13){
					SetBGColor(0);
					system("cls");
					thanhsangMenuCuaXemThongTinRuou(0,0);
					menuchinh();
					kt=true;
				}
			break;
				
		}
		
	}
}


void BangMenu( int xx , int yy ){//in bang ngoài cua menu 
	SetBGColor(1);//mau xanh 
	for(int x = 0+xx ; x < 65+xx ; x++ ){
		for( int y = 0+yy ; y < 17+yy ; y++ ){
			gotoxy(x,y);	
			cout<<char(176);
		}
		cout<<endl;
	}
//	gotoxy(32,8);
	SetBGColor(0);
//	textcolor(13);cout << char(15) << ten << char(15);
}
int main(){
	menuchinh();
	
}

