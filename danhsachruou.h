#ifndef danhsachruou
#define danhsachruou
#include <iostream>
#include "support.h"
#include "nhapthongtinruou1.h"
#include "XemThongTinRuouDaNhap.h"
#include "ChonGioHang.h"

void menuGioHang(int x, int y); // day la ham chinh=================================================
class GioHangMua : public xuatthongtin
{

public:
	void DocfileGioHang(string tenfile, node *&GioHang, int &demphantu); // chong ham
	void displayBangGioHang(node *GioHang, int x, int y);
	void InBangGioHang(int x, int y, node *head, int sobang);
	double getTongGiaBan(node *head);
	friend menuGioHang1(int x, int y, node *head, int sobang);
	void thanhMenuCuaGioHang(int x, int y, node *head);
	void SaveFilethongtinDaBan(string str, node *a);
	friend void menuRuoudaBan(int x, int y, node *&head);
};

void menuRuoudaBan(int x, int y, node *&head)
{
	GioHangMua a;
	int sophantu;
	// gotoxy(40,3);

	a.DocfileGioHang("fileRuouDaBan.txt", head, sophantu);
	displaybox(3, 3, 3, 40);
	gotoxy(4, 4);
	cout << "	TONG DOANH THU:";
	//	cout<<fixed;
	cout << a.getTongGiaBan(head);

	a.InBangGioHang(3, 10, head, sophantu);
	_getch();
}
void GioHangMua::SaveFilethongtinDaBan(string str, node *a)
{
	ofstream FileOut;
	node *head = new node;
	head = a;
	FileOut.open(str, ios_base::out | std::ios::app);
	while (head != NULL)
	{
		FileOut << "- Ma ruou :" << head->getmma();
		FileOut << endl
				<< "- Ten san pham :" << head->gettensp();
		FileOut << endl
				<< "- Xuat xu :" << head->getxuatxu();
		FileOut << endl
				<< "- Dung tich :" << head->getxuatxu();
		FileOut << endl
				<< "- Nong do :" << head->getnongdo();
		FileOut << endl
				<< "- Gia ban :" << head->getgiaban();
		// FileOut << endl
		// 		<< "- So luong  :" << head->getSoLuong();
		FileOut << endl
				<< "##########" << endl;
		head = head->next;
	}
	FileOut.close();
}
void GioHangMua::thanhMenuCuaGioHang(int x, int y, node *head)
{
	string str[3];
	gotoxy(0, 0);
	str[0] = "THANH TOAN    ";
	str[1] = "HUY GIO HANG  ";
	str[2] = "VE MENU       ";
	SetBGColor(3);
	displaybox(x, y, 7, 20);
	gotoxy(x + 1, y + 1);
	cout << str[0];
	gotoxy(x + 1, y + 3);
	cout << str[1];
	gotoxy(x + 1, y + 5);
	cout << str[2];
	//	cout<<str[3];
	bool check = true;
	int xcucu = x;
	int ycucu = y;
	int xcu = x, ycu = y;
	char c;
	int i = 0; // index dung de truy cap vao mang
	int icu;
	while (check)
	{
		setColor(3, 8); // chinh lai mau cu
		gotoxy(xcu + 1, ycu + 1);
		cout << str[icu];
		icu = i;
		gotoxy(x + 1, y + 1); // tao mau dong dau tien
		setColor(2, 4);
		xcu = x, ycu = y;
		cout << str[i];
		c = _getch();
		switch (c)
		{
		case 72: // phim len
			if (y <= ycucu)
			{
				y = ycucu + 4;
				i = 2;
			}
			else
			{
				y = y - 2;
				i--;
			}
			break;
		case 80: // phim xuong
			if (y >= ycucu + 4)
			{
				y = ycucu;
				i = 0;
			}
			else
			{
				y = y + 2;
				i++;
			}
			break;
		case 13:
			if (y == ycucu)
			{
				node *tempHead = new node; // node cuoi nhan gia tri rac nen tien hanh xoa node cuoi
				node *curr = new node;
				tempHead = head;
				while (tempHead->next != NULL)
				{
					curr = tempHead;
					tempHead = tempHead->next;
				}
				curr->next = NULL;
				tempHead = head;
				this->SaveFilethongtinDaBan("fileRuouDaBan.txt", head); // luu danh sach ruou da ban vao file ban ruou
				ofstream FileOut;
				gotoxy(25, 6);
				cout << "Thanh toan thanh cong";
				sleep(2);
				FileOut.open("giohang.txt", ios_base::out);
				string temptr = "\0";
				FileOut << temptr;
				FileOut.close();
				check = false;
				break;
			}
			if (y == ycucu + 2)
			{
				node *tempHead = new node; // node cuoi nhan gia tri rac nen tien hanh xoa node cuoi
				node *curr = new node;
				tempHead = head;
				while (tempHead->next != NULL)
				{
					curr = tempHead;
					tempHead = tempHead->next;
				}
				curr->next = NULL;
				tempHead = head;
				tempHead->SaveFilethongtin(tempHead);
				ofstream FileOut;
				gotoxy(25, 6);
				cout << "Huy Gio Hang thanh cong";
				FileOut.open("giohang.txt", ios_base::out);
				string temptr = "\0";
				FileOut << temptr;
				FileOut.close();
				break;
			}
			if (y == ycucu + 4)
			{
				check = false;
				break;
			}
		default:
			check = true;
			break;
		}
	}
}
double GioHangMua::getTongGiaBan(node *head)
{
	node *temp = new node;
	temp = head;
	float sum = 0;

	while (temp != NULL)
	{

		sum = sum + temp->getgiaban();
		temp = temp->next;
	}
	return sum;
}
void GioHangMua::InBangGioHang(int x, int y, node *a, int sobang)
{
	for (int i = x; i < 110 + x; i++)
	{
		for (int j = y; j < 3 + y; j++)
		{
			gotoxy(i, j);
			SetBGColor(1);
			if (i == 13 || i == 23 || i == 55 || i == 70 || i == 85 || i == 97)
			{
				textcolor(0);
				cout << char(179);
			}
			else
				cout << " " << endl;
		}
		SetBGColor(1);
		textcolor(10);
		gotoxy(8, y + 1);
		cout << "STT";
		gotoxy(17, y + 1);
		cout << "MA";
		gotoxy(34, y + 1);
		cout << "TEN SAN PHAM";
		gotoxy(59, y + 1);
		cout << "XUAT XU";
		gotoxy(72, y + 1);
		cout << "DUNG TICH(ml)";
		gotoxy(88, y + 1);
		cout << "NONG DO";
		gotoxy(103, y + 1);
		cout << "GIA BAN";
		// gotoxy(125, y + 1);
		// cout << "SO LUONG";
	}
	//	cout<<sobang;
	insobangthongtincanthem(x, y, sobang);
	node *temp = new node;
	temp = a;
	//		for(int i=1;i<=sobang+1;i++){//dung de nhap nhieu thanh data vao trong bang thong tin
	//			temp->printdata(x+3,y+1+i*3);
	//			temp=temp->next;
	//		}
	int i = 1;
	while (temp->next != NULL)
	{ // nay se khong truy cap toi giai tri cua node cuoi (node cuoi nhan gia tri rac
		temp->printTheoHang(x + 3, y + 1 + i * 3);
		temp = temp->next;
		i++;
	}
}
void menuGioHang1(int x, int y)
{
	GioHangMua a;
	node *GioHang;
	GioHang = NULL;
	int dem;
	a.DocfileGioHang("giohang.txt", GioHang, dem);
	a.InBangGioHang(3, 10, GioHang, dem);
	setColor(7, 4);
	gotoxy(10, 2);
	cout << "TONG THANH TOAN:" << a.getTongGiaBan(GioHang);
	gotoxy(10, 4);
	cout << "SO LUONG SAN PHAM:" << dem - 1;
	a.thanhMenuCuaGioHang(85, 2, GioHang);
}
// void menuGioHang(int x,int y,node *head,int sobang){
//
// }
void GioHangMua::DocfileGioHang(string tenfile, node *&head, int &demphantu)
{ // lay du lieu ra
	ifstream inFile;
	demphantu = 0;
	head = new node;
	node *tail = new node;
	string temp;
	tail = head = NULL;
	inFile.open(tenfile, ios_base::in);
	if (!inFile)
	{
		cout << "Khong tim thay file giohang.txt" << endl;
		//	system("pause");
		return;
	}
	while (!inFile.eof())
	{
		node *a = new node;
		getline(inFile, temp, ':');
		getline(inFile, temp); // nhan ma
		a->setMa(temp);
		getline(inFile, temp, ':');
		getline(inFile, temp);
		a->setTensp(temp); // nhan ten san pham
		getline(inFile, temp, ':');
		getline(inFile, temp);
		a->setXuatxu(temp); // nhan xuat xu
		getline(inFile, temp, ':');
		getline(inFile, temp);
		fflush(stdin);
		//	a->setDungtich()=atoll((char*)temp.c_str());
		a->setDungtich(atoll((char *)temp.c_str()));

		getline(inFile, temp, ':');
		getline(inFile, temp);
		fflush(stdin);
		a->setNongdo(atoll((char *)temp.c_str()));

		getline(inFile, temp, ':');
		fflush(stdin);
		getline(inFile, temp);

		a->setGiaban(atoll((char *)temp.c_str()));
		// getline(inFile, temp, ':');
		// getline(inFile, temp);
		// fflush(stdin);
		// a->setSoLuong(atoll((char *)temp.c_str()));
		getline(inFile, temp);
		a->next == NULL;
		if (head == NULL)
		{
			head = tail = a;
		}
		else
		{
			tail->next = a;
			tail = a;
		}
		demphantu++;
	}

	inFile.close();
}

#endif