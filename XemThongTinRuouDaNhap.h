#ifndef XemThongTinRuouDaNhap
#define XemThongTinRuouDaNhap
//#include <iostream>
#include "support.h"
#include "nhapthongtinruou1.h"

class xuatthongtin : public node
{
private:
	//		data data;
public:
	void loadfile(xuatthongtin *&head, int &demphantu); // dem phan tu de lay so phan tu trong file
	xuatthongtin *next;
	void inbangdanhsachruou(int x, int y, xuatthongtin *a, int sobang);
	void printdata(int x, int y);
	//	void LayDuLieuDaNhap(int x,int y,xuatthongtin *&a,int sobang);
};
void LayDuLieuDaNhap(int x, int y, xuatthongtin *&a, int sobang)
{ //================================================================ham chinh=========================
	a->loadfile(a, sobang);
	a->inbangdanhsachruou(3, y, a, sobang);
	_getch();
}
void xuatthongtin::printdata(int x, int y)
{
	gotoxy(x + 10, y);
	cout << this->data.ma;
	gotoxy(x + 20, y);
	cout << this->data.tensp;
	gotoxy(x + 50, y);
	cout << this->data.xuatxu;
	gotoxy(x + 69, y);
	cout << this->data.dungtich;
	gotoxy(x + 83, y);
	cout << this->data.nongdo;
	gotoxy(x + 97, y);
	cout << this->data.giaban;
	gotoxy(x + 122, y);
	cout << this->data.soluong;
}
void xuatthongtin::loadfile(xuatthongtin *&head, int &demphantu)
{ // lay du lieu ra
	ifstream inFile;
	demphantu = 0;
	head = new xuatthongtin;
	xuatthongtin *tail = new xuatthongtin;
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
		xuatthongtin *a = new xuatthongtin;
		getline(inFile, temp, ':');
		//	cout<<temp;
		getline(inFile, a->data.ma); // 1
		//	cout<<endl<<a->data.ma<<endl;
		getline(inFile, temp, ':');
		getline(inFile, a->data.tensp);
		//	cout<<a->data.tensp<<endl;

		getline(inFile, temp, ':');
		getline(inFile, a->data.xuatxu);
		//	cout<<a->data.xuatxu;
		getline(inFile, temp, ':');
		getline(inFile, temp);
		//	cout<<temp<<endl;
		fflush(stdin);
		a->data.dungtich = atoll((char *)temp.c_str());
		//	cout<<a->data.dungtich<<"t";

		getline(inFile, temp, ':');
		getline(inFile, temp);
		fflush(stdin);
		a->data.nongdo = atoll((char *)temp.c_str());
		//	cout<<a->data.nongdo<<"a";
		getline(inFile, temp, ':');
		getline(inFile, temp);
		fflush(stdin);
		a->data.giaban = atoll((char *)temp.c_str());
		//
		getline(inFile, temp, ':');
		getline(inFile, temp);
		fflush(stdin);
		a->data.soluong = atoll((char *)temp.c_str());
		getline(inFile, temp);
		//
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
		demphantu++;
	}
	demphantu--;
	//	if(head->next!=NULL){
	xuatthongtin *temp1 = new xuatthongtin; // xoa node cuoi cung vi nhan gia tri rac
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
}
void xuatthongtin::inbangdanhsachruou(int x, int y, xuatthongtin *a, int sobang)
{
	for (int i = x; i < 110 + x; i++)
	{
		for (int j = y; j < 3 + y; j++)
		{
			gotoxy(i, j);
			SetBGColor(1);
			if (i == 13 || i == 23 || i == 55 || i == 70 || i == 85 || i == 97 || i == 125)
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
		gotoxy(122, y + 1);
		cout << "SO LUONG";
	}
	//	cout<<sobang;
	insobangthongtincanthem(x, y, sobang);
	xuatthongtin *temp = new xuatthongtin;
	temp = a;
	int i = 1;
	while (temp != NULL)
	{
		temp->printdata(x + 3, y + 1 + i * 3);
		temp = temp->next;
		i++;
	}
}
#endif