#include <iostream>
#include "support.h"
#include "nhapthongtinruou1.h"
//#include "menu.h"
class TimSanPham
{
public:
	void timTheoThongTin(int x, int y, node *head, int sobang);
	void LocTheoTen(int x, int y, node *head);
	void LocTheoMa(int x, int y, node *head);
	void LocTheoGia(int x, int y, node *head);
};

void displaybox(int x, int y, int height, int width);
void MenuCuaHam(int x, int y);
void inBangThongTieuDe(int x, int y, int sobang);
void thanhsangMenuCuaXemThongTinRuou(int x, int y);
void SaveFileGioHang(node *head);
void themGioHang(int x, int y, node *&head, node *&GioHang, int sobang)
{ // can lay gia tri sobang de xoa bang cu
	xoaduoi(0, y, sobang + 2);
	gotoxy(0, 0);
	int dem = 0;
	int TongThanhToan = 0;
	node *tempGioHang = new node;
	node *GiuNodehead = new node; // xoa node head vi node head dang nhan gia tri rac
	GiuNodehead->copy(GioHang);
	GioHang = GioHang->next;
	//	GioHang=GioHang->next;
	tempGioHang = GioHang;
	while (tempGioHang != NULL)
	{
		dem++;
		TongThanhToan = TongThanhToan + tempGioHang->getgiaban();
		tempGioHang = tempGioHang->next;
	}
	gotoxy(7, 7);
	cout << "TONG THANH TOAN:";
	cout << TongThanhToan;
	textcolor(3);
	InBangDanhSachDaSapXep(3, y + 6, GioHang, dem);
	GiuNodehead->next = GioHang; // cap nhat lai node dau nhan gia tri rac
	GioHang = GiuNodehead;
	gotoxy(60, 7);
	string MaSanPham;
	cout << "NHAP MA SAN PHAM BAN MUON XOA:";
	getline(cin, MaSanPham);
	//	node *tempHead = new node;
	//	tempHead= head;
	//	while(tempHead!=NULL){
	//		tempHead->display();
	//		tempHead=tempHead->next;
	//	}
	tempGioHang = GioHang->next;
	int i = 2;
	dem = 0;
	while (tempGioHang != NULL)
	{
		if (tempGioHang->getmma() == MaSanPham)
		{
			tempGioHang->deletenode(GioHang, i);
			break;
		}
		i++;
		dem++;
		tempGioHang = tempGioHang->next;
	}
	tempGioHang = GioHang->next;
	xoaduoi(0, y + 8, dem + 1);
	InBangDanhSachDaSapXep(3, y + 6, tempGioHang, dem);
}
void TimSanPham::LocTheoGia(int x, int y, node *head)
{
	string giaduoi, giatren;
	SetBGColor(3);
	displaybox(x + 20, y, 3, 15);
	do
	{
		gotoxy(x + 23, y + 1);
		for (int i = 0; i < giaduoi.length(); i++)
		{
			cout << " ";
		}
		gotoxy(x + 23, y + 1);
		getline(cin, giaduoi);
	} while (isNumber(giaduoi) == false);
	int gia = stoi(giaduoi);
	SetBGColor(3);
	displaybox(x + 40, y, 3, 15);
	do
	{
		gotoxy(x + 30, y + 1);
		for (int i = 0; i < giatren.length(); i++)
		{
			cout << " ";
		}
		gotoxy(x + 23, y + 1);
		getline(cin, giatren);
	} while (isNumber(giatren) == false);
	long long giatrenint = stoi(giatren);
	int dem = 0;
	node *temp = new node;
	temp = head;
	while (temp != NULL)
	{ // lay gia tri dem de in bang
		if (temp->getgiaban() >= gia || temp->getgiaban() <= giatrenint)
		{
			dem++;
		}
		temp = temp->next;
	}
	inBangThongTieuDe(3, y + 6, dem);
	int i = 1;
	temp = head; // dat lai temp = head vi khi chay xong temp se ve nuLL
	while (temp != NULL)
	{
		if (temp->getgiaban() >= gia || temp->getgiaban() <= giatrenint)
		{
			temp->printTheoHang(6, y + 7 + i * 3);
			i++;
		}
		temp = temp->next;
	}
}
void TimSanPham::LocTheoMa(int x, int y, node *head)
{
	string MaCanTim;
	SetBGColor(3);
	displaybox(x + 20, y, 3, 15);
	gotoxy(x + 23, y + 1);
	getline(cin, MaCanTim);
	node *temp = new node;
	temp = head;
	//	headData=&holdData;
	node *copy = new node;
	int dem = 0;
	while (temp != NULL)
	{
		if (MaCanTim == temp->getmma())
		{
			dem++;
		}

		temp = temp->next;
	}
	inBangThongTieuDe(3, y + 6, dem);
	temp = head;
	int i = 1;
	while (temp != NULL)
	{
		if (MaCanTim == temp->getmma())
		{
			copy->copy(temp);
			temp->printTheoHang(6, y + 7 + i * 3);
			i++;
		}

		temp = temp->next;
	}
}
void SaveFileGioHang(node *a)
{
	ofstream FileOut;
	node *head = new node;
	head = a;
	FileOut.open("giohang.txt", ios_base::out | std::ios::app);
	while (head != NULL)
	{
		FileOut << "- Ma ruou :" << head->getmma();
		FileOut << endl
				<< "- Ten san pham :" << head->gettensp();
		FileOut << endl
				<< "- Xuat xu :" << head->getxuatxu();
		FileOut << endl
				<< "- Dung tich :" << head->getdungtich();
		FileOut << endl
				<< "- Nong do :" << head->getnongdo();
		FileOut << endl
				<< "- Gia ban :" << head->getgiaban();
		// FileOut << endl << "- Vi tri : " << a.m_Vitri;
		FileOut << endl
				<< "##########" << endl;
		head = head->next;
	}
	FileOut.close();
}
void TimSanPham::LocTheoTen(int x, int y, node *head)
{
	string TenCanTim;
	SetBGColor(3);
	displaybox(x + 20, y, 3, 15);
	gotoxy(x + 23, y + 1);
	getline(cin, TenCanTim);
	node *temp = new node;
	temp = head;
	//	headData=&holdData;
	node *copy = new node;
	int dem = 0;
	while (temp != NULL)
	{
		if (temp->gettensp().find(TenCanTim) != 18446744073709551615)
		{
			dem++;
		}

		temp = temp->next;
	}
	inBangThongTieuDe(3, y + 6, dem);
	temp = head;
	int i = 1;
	while (temp != NULL)
	{
		if (temp->gettensp().find(TenCanTim) != 18446744073709551615)
		{
			copy->copy(temp);
			temp->printTheoHang(6, y + 7 + i * 3);
			i++;
		}

		temp = temp->next;
	}

	//	InBangDanhSachDaSapXep(3,y+6,holdData,3);
}
void TimSanPham::timTheoThongTin(int x, int y, node *head, int sobang)
{
	xoaduoi(0, y, sobang + 2);
	string str[3];
	gotoxy(0, 0);
	str[0] = "LOC THEO TEN      ";
	str[1] = "LOC THEO MA       ";
	str[2] = "LOC THEO KHOANG GIA      ";
	SetBGColor(3);
	displaybox(x, y, 7, 20);
	gotoxy(x + 1, y + 1);
	cout << str[0];
	gotoxy(x + 1, y + 3);
	cout << str[1];
	gotoxy(x + 1, y + 5);
	cout << str[2];
	cout << str[3];
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
				this->LocTheoTen(x, y, head);
				check = false;
				break;
			}
			if (y == ycucu + 2)
			{
				this->LocTheoMa(x, y, head);
				check = false;
				break;
			}
			if (y == ycucu + 4)
			{
				this->LocTheoGia(x, y, head);
				check = false;
				break;
			}
		}
	}
}
void Timten(node *&head, string tensp, node *&GioHang)
{ // GioHang dang nhan gia tri rac khi chay vi khong khoi tao gio hang = NULL duoc nen phai xoa node dau di
	node *temp = new node;
	node *tempGioHang = new node;
	tempGioHang = GioHang;
	int i = 1;
	node *copy = new node;
	temp = head;
	while (temp != NULL)
	{
		if (tensp == temp->data.tensp)
		{
			copy->copy(temp);
			if (tempGioHang == NULL)
			{
				GioHang = copy;
				tempGioHang->next = NULL;
			}
			else
			{
				while (tempGioHang->next != NULL)
				{
					tempGioHang = tempGioHang->next;
				}
				tempGioHang->next = copy;
				copy->next = NULL;
			}
			head->deletenode(head, i); // ham nay bi loi, can xet lai vi tri cua node do trong danh sach llien ket
			gotoxy(0, 6);
			cout << "da tim thay";
			break;
		}
		i++;
		temp = temp->next;
	}
}
void TimTheoMa(node *&head, string ma, node *&GioHang)
{
	node *temp = new node;
	node *tempGioHang = new node;
	tempGioHang = GioHang;
	int i = 1;
	node *copy = new node;
	temp = head;
	while (temp != NULL)
	{
		if (ma == temp->data.ma)
		{
			copy->copy(temp);
			if (tempGioHang == NULL)
			{
				GioHang = copy;
				tempGioHang->next = NULL;
			}
			else
			{
				while (tempGioHang->next != NULL)
				{
					tempGioHang = tempGioHang->next;
				}
				tempGioHang->next = copy;
				copy->next = NULL;
			}
			head->deletenode(head, i);
			gotoxy(0, 6);
			cout << "da tim thay";
			break;
		}
		i++;
		temp = temp->next;
	}
}

void sapxep(int x, int y, node *head, int sobang)
{
	string str[4];
	str[0] = "THEO GIA          ";
	str[1] = "NONG DO           ";
	str[2] = "DUNG TICH         ";
	str[3] = "THEO TEN          ";
	SetBGColor(3);
	displaybox(x, y, 9, 20);
	gotoxy(x + 1, y + 1);
	cout << str[0];
	gotoxy(x + 1, y + 3);
	cout << str[1];
	gotoxy(x + 1, y + 5);
	cout << str[2];
	gotoxy(x + 1, y + 7);
	cout << str[3];
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
				y = ycucu + 6;
				i = 3;
			}
			else
			{
				y = y - 2;
				i--;
			}
			break;
		case 80: // phim xuong
			if (y >= ycucu + 6)
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
			{ // theo gia
				xoaduoi(0, ycucu, sobang + 2);
				XapXepData(3, ycucu + 5, head, sobang);
				InBangDanhSachDaSapXep(3, y + 6, head, sobang);
				check = false;
			}
			if (y == ycucu + 2)
			{ // nong do
				xoaduoi(0, ycucu, sobang + 2);
				XapXepTheoNongdo(3, ycucu + 4, head);
				InBangDanhSachDaSapXep(3, y + 4, head, sobang);
				check = false;
			}
			if (y == ycucu + 4)
			{ // dung tich
				xoaduoi(0, ycucu, sobang);
				XapXepTheoDungTich(3, ycucu + 4, head);
				InBangDanhSachDaSapXep(3, y + 3, head, sobang);
				check = false;
			}
		}
	}
}

void chonSanPham(int x, int y, node *&head, int sobang, node *&GioHang)
{
	string str[2];
	str[0] = "THEO TEN          ";
	str[1] = "THEO MA           ";
	str[2] = "CHON GAN DUNG     ";
	SetBGColor(3);
	displaybox(x, y, 5, 25); // toa do x yeu cau la 50
	gotoxy(x + 1, y + 1);
	cout << str[0];
	gotoxy(x + 1, y + 3);
	cout << str[1];
	gotoxy(x + 1, y + 5);
	cout << str[2];
	bool kt = true;
	int xcu = x, ycu = y;
	int ycucu = y, xcucu = x;
	char c;
	int i = 0; // index dung de truy cap vao mang
	int icu;
	while (kt)
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
			y = y - 2;
			i--;
			if (i < 0)
			{
				y = ycucu + 2;
				i = 1;
			}
			break;
		case 80: // phim xuong
			y = y + 2;
			i++;
			if (i > 1)
			{
				y = ycucu;
				i = 0;
			}
			break;
		case 13:
			string tensp;
			string ma;
			if (y == ycucu)
			{ // chon theo ten san pham
				setColor(3, 4);
				displaybox(x + 20, y, 3, 20);
				gotoxy(x + 25, y + 1);
				getline(cin, tensp);
				Timten(head, tensp, GioHang);
				int i = 0;
				//	GioHang=GioHang->next;
				//				node *tempGioHang=new node;
				//				tempGioHang = GioHang;
				//				while(tempGioHang!=NULL){
				//					tempGioHang->display();
				//					cout<<"=========================================";
				//					tempGioHang = tempGioHang->next;
				//					i++;
				//				}
				kt = false; // write code in here
				break;
			}
			if (y = ycucu + 2)
			{
				setColor(3, 4);
				displaybox(x + 20, y, 3, 20);
				gotoxy(x + 25, y + 1);
				getline(cin, ma);
				TimTheoMa(head, ma, GioHang);
				kt = false;
				break;
			}
			break;
		}
	}
}

void displaybox(int x, int y, int height, int width)
{
	for (int i = y; i < height + y; i++)
	{
		for (int j = x; j < width + x; j++)
		{
			gotoxy(j, i);
			cout << " ";
			if (i == y || i == height - 1 + y)
			{
				gotoxy(j, i);
				cout << char(196);
			}
			if (j == x || j == x + width - 1)
			{
				gotoxy(j, i);
				cout << char(179);
			}
			if (j == x + width - 1 && i == y)
			{ // goc tren ben phai
				gotoxy(j, i);
				cout << char(191);
			}
			if (j == x + width - 1 && i == y + height - 1)
			{ // goc tren ben trai
				gotoxy(j, i);
				cout << char(217);
			}
			if (i == y && j == x)
			{ // goc tren ben trai
				gotoxy(j, i);
				cout << char(218);
			}
			if (i == y + height - 1 && j == x)
			{ // goc tren ben phai
				gotoxy(j, i);
				cout << char(192);
			}
		}
	}
}

void thanhsangMenuCuaXemThongTinRuou(int x, int y)
{
	node *head;
	int sobang;
	node *GioHang = new node;
	// GioHang =NULL;
	//	GioHang = nullptr;

	DocDuLieuTuFile(1, 1, head, sobang); // chuyen du lieu tu file sang head de quan li
	string str[5];
	str[0] = "      XAP XEP     ";
	str[1] = "     TIM RUOU     ";
	str[2] = "  CHON SAN PHAM   ";
	str[3] = "     GIO HANG     ";
	str[4] = "     VE MENU      ";
	SetBGColor(10);
	textcolor(0);
	for (int i = y; i < y + 5; i++)
	{
		for (int j = x; j < 120; j++)
		{
			gotoxy(j, i);
			cout << " ";
		}
	}
	SetBGColor(7);
	textcolor(5);
	displaybox(x, y + 1, 3, 20);
	gotoxy(x + 1, y + 2);
	cout << str[0];
	displaybox(x + 25, y + 1, 3, 20);
	gotoxy(x + 26, y + 2);
	cout << str[1];
	displaybox(x + 50, y + 1, 3, 20);
	gotoxy(x + 51, y + 2);
	cout << str[2];
	displaybox(x + 75, y + 1, 3, 20);
	gotoxy(x + 76, y + 2);
	cout << str[3];
	displaybox(x + 100, y + 1, 3, 20);
	gotoxy(x + 101, y + 2);
	cout << str[4];
	//=================================================================================================
	bool kt = true;
	//	bangxuli( x, y);
	int xcu = x, ycu = y;
	char c;
	int i = 0; // index cua mang
	int icu = 0;
	while (kt)
	{
		setColor(7, 5);
		gotoxy(xcu + 1, ycu + 2); //
								  //	cout<<"                  ";		//	cum nay goto lai toan do cu de in lai bang
								  //	gotoxy(xcu,ycu+2);				//
		cout << str[icu];		  //
		icu = i;
		//	gotoxy(x+1,y+2);//tao mau dong dau tien
		setColor(2, 4);
		xcu = x, ycu = y;
		gotoxy(x + 1, y + 2);
		//	cout<<"                  ";
		//	gotoxy(x+4,y+1);
		cout << str[i];
		c = _getch();
		switch (c)
		{
		case 77: // sang trai
			x = x + 25;
			i++;
			if (x >= 110)
			{
				x = x - 25 * 5;
				i = 0;
			}
			break;
		case 75:
			x = x - 25;
			i--;
			if (x < 0)
			{
				x = x + 25 * 5;
				i = 4;
			}
			break;
		case 13: // enter
			if (x == 0)
			{									// sap xep theo gia
				sapxep(0, y + 5, head, sobang); // khi chon san pham thi da xoa trong head nen head se khong con san pham trong gio
				//					node *head;
				//					int sobang;
				//					DocDuLieuTuFile(1,1,head,sobang);
				//					XapXepData(3,y+5,head,sobang);
				//					InBangDanhSachDaSapXep(3,y+5,head,sobang);
				break;
			}
			if (x == 25)
			{
				TimSanPham a;
				a.timTheoThongTin(25, y + 5, head, sobang);
				// write code in here
				break;
			}
			if (x == 50)
			{ // chon san pham
				for (int i = 5; i < 11; i++)
				{ // in de xoa bang cu
					for (int j = 0; j < 110; j++)
					{
						SetBGColor(0);
						gotoxy(j, i);
						cout << " ";
					}
				}
				chonSanPham(50, y + 5, head, sobang, GioHang);
				break;
			}
			if (x == 75)
			{
				themGioHang(0, y + 5, head, GioHang, sobang);
			}
			if (x == 100)
			{
				//	system("cls");
				// menuchinh();
				SetBGColor(0);
				system("cls");
				kt = false;
				break;
			}
		}
	}
}
void XapXepTheoNongdo(int x, int y, node *&head)
{
	node *current = head, *index = NULL;
	int temp;

	if (head == NULL)
	{
		return;
	}
	else
	{
		while (current != NULL)
		{
			// Node index will point to node next to current
			index = current->next;

			while (index != NULL)
			{
				// If current node's data is greater than index's node data, swap the data between them
				if (current->data.nongdo > index->data.nongdo)
				{
					swapdata(current, index);
					//                        node *temp=new node;
					//                        temp=current;
					//                        current=index;
					//                        index=temp;
				}
				index = index->next;
			}
			current = current->next;
		}
	}
}
void XapXepTheoDungTich(int x, int y, node *&head)
{
	node *current = head, *index = NULL;
	int temp;

	if (head == NULL)
	{
		return;
	}
	else
	{
		while (current != NULL)
		{
			// Node index will point to node next to current
			index = current->next;

			while (index != NULL)
			{
				// If current node's data is greater than index's node data, swap the data between them
				if (current->data.dungtich > index->data.dungtich)
				{
					swapdata(current, index);
					//                        node *temp=new node;
					//                        temp=current;
					//                        current=index;
					//                        index=temp;
				}
				index = index->next;
			}
			current = current->next;
		}
	}
}
void XapXepData(int x, int y, node *&head, int sobang)
{
	node *current = head, *index = NULL;
	int temp;

	if (head == NULL)
	{
		return;
	}
	else
	{
		while (current != NULL)
		{
			// Node index will point to node next to current
			index = current->next;

			while (index != NULL)
			{
				// If current node's data is greater than index's node data, swap the data between them
				if (current->data.giaban > index->data.giaban)
				{
					swapdata(current, index);
					//                        node *temp=new node;
					//                        temp=current;
					//                        current=index;
					//                        index=temp;
				}
				index = index->next;
			}
			current = current->next;
		}
		// cout<<"loi me roi";
	}
}
void DocDuLieuTuFile(int x, int y, node *&head, int &sobang)
{ // lay du lieu ra. Nay la ham friend cua class node
	ifstream inFile;
	sobang = 0;
	head = new node;
	node *tail = new node;
	string temp;
	head = tail = NULL;
	//	node->next=NULL;
	inFile.open("data.txt", ios_base::in);
	if (!inFile)
	{
		cout << "Khong tim thay file data.txt" << endl;
		system("pause");
		return;
	}
	//	while(!inFile.eof()){
	while (!inFile.eof())
	{
		node *a = new node;
		getline(inFile, temp, ':');
		//	cout<<temp;
		getline(inFile, a->data.ma);
		getline(inFile, temp, ':');
		getline(inFile, a->data.tensp);

		getline(inFile, temp, ':');
		getline(inFile, a->data.xuatxu);
		getline(inFile, temp, ':');
		getline(inFile, temp);
		fflush(stdin);
		a->data.dungtich = atoll((char *)temp.c_str());

		getline(inFile, temp, ':');
		getline(inFile, temp);
		fflush(stdin);
		a->data.nongdo = atoll((char *)temp.c_str());
		//	cout<<a->data.nongdo<<"a";

		getline(inFile, temp, ':');
		fflush(stdin);
		getline(inFile, temp);

		a->data.giaban = atoll((char *)temp.c_str());
		//	cout<<a->data.giaban<<endl;
		getline(inFile, temp);
		//	cout<<"======================";
		a->next == NULL;
		//		if(head==NULL){
		//			head=a;
		//		}
		//		else {
		//			a->next=head;
		//			head=a;
		//		}
		if (head == NULL)
		{
			head = tail = a;
		}
		else
		{
			tail->next = a;
			tail = a;
		}
		//	node->next=a;
		// delete a;
		sobang++;
	}
	sobang--;
	//	if(head->next!=NULL){
	node *temp1 = new node; // xoa node cuoi cung vi nhan gia tri rac
	temp1 = head;
	while (temp1->next != tail)
	{
		temp1 = temp1->next;
	}
	tail = temp1;
	tail->next = NULL;
	//
	//	}

	inFile.close();
};
void MenuCuaHam(int x, int y)
{ //=====================================================HAM CHINH============================================================
	thanhsangMenuCuaXemThongTinRuou(x, y);
	//	node *head;
	//	int sobang;
	//	DocDuLieuTuFile(1,1,head,sobang);
	//======================
	//	XapXepData(3,y+5,head,sobang);
	//	node *temp=new node ;
	//	temp=head;
	//	while(temp!=NULL){
	//		temp->display();
	//		cout<<"==========================================================="<<endl;
	//		temp=temp->next;
	//	}
	//	InBangDanhSachDaSapXep(3,y,head,sobang);
}
void InBangDanhSachDaSapXep(int x, int y, node *head, int sobang)
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
	}
	//	cout<<sobang;

	insobangthongtincanthem(x, y, sobang);
	node *temp = new node;
	temp = head;
	int i = 1; // i nay de lam cho ham print in dung vi tri trong bang

	while (temp != NULL)
	{
		temp->printTheoHang(x + 3, y + 1 + i * 3);
		temp = temp->next;
		i++;
	}
}
void inBangThongTieuDe(int x, int y, int sobang)
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
	}
	//	cout<<sobang;

	insobangthongtincanthem(x, y, sobang);
}
int main()
{
	thanhsangMenuCuaXemThongTinRuou(0, 0);
}