#ifndef nhapthongtinruou1
#define nhapthongtinruou1
//#include "menu.h"
#include <iostream>
#include "support.h"
#include "dangnhap.h"

void nhapthongtin(int &sobang);							   // ham nay lay so luong bang tu nguoi dung
void inbangmenunhapthongtinruou(int x, int y, int sobang); // ham chinh
void insobangthongtincanthem(int x, int y, int dem);	   // tao ra so bang theo so luong nguoi dung nhap vao
// void xulikitu(int x,int y,string str[]);
void setbackground(int x, int y);
void displaythongtin(int x, int y);
void xoaduoi(int x, int y, int sobang); // dung de xoa bang ghi them
void inbangtieude(int x, int y);		// int tieu de bang ruou

bool isNumber(const string &str)
{
	for (char const &c : str)
	{
		if (std::isdigit(c) == 0)
			return false;
	}
	return true;
}
typedef struct data
{
	string ma;
	string tensp;
	string xuatxu;
	float dungtich;
	float nongdo;
	float giaban;
	float soluong;
} data;
class node
{
private:
protected:
	int soluongcanmua;
	data data;

public:
	void setSoLuongCanMua(int soluongcanmua)
	{
		this->soluongcanmua = soluongcanmua;
	}
	void setMa(string ma)
	{
		this->data.ma = ma;
	}
	void setDungtich(float Dungtich)
	{
		this->data.dungtich = Dungtich;
	}
	void setNongdo(float Nongdo)
	{
		this->data.nongdo = Nongdo;
	}
	void setGiaban(float Giaban)
	{
		this->data.giaban = Giaban;
	}
	void setXuatxu(string Xuatxu)
	{
		this->data.xuatxu = Xuatxu;
	}
	void setTensp(string Tensp)
	{
		this->data.tensp = Tensp;
	}
	void setSoLuong(int soluong)
	{
		this->data.soluong = soluong;
	}
	//	data data;
	int getsoluongcanmua() const
	{
		return this->soluongcanmua;
	}
	float getSoLuong() const
	{
		return this->data.soluong;
	}
	string getmma() const
	{
		return this->data.ma;
	}
	string gettensp() const
	{
		return this->data.tensp;
	}
	string getxuatxu() const
	{
		return this->data.xuatxu;
	}
	float getdungtich() const
	{
		return this->data.dungtich;
	}
	float getnongdo() const
	{
		return this->data.nongdo;
	}
	float getgiaban() const
	{
		return this->data.giaban;
	}
	node *next;
	node()
	{ // khoi tao constructor default
		this->next = NULL;
		this->data.ma = "0";
		this->data.tensp = "";
		//	this->data.nongdo=0;
		this->data.xuatxu = "";
		//	this->data.giaban=0;
		this->data.soluong = 0;
	}

	void inputdata(int x, int y);
	void copy(const node *a)
	{
		this->data.dungtich = a->data.dungtich;
		this->data.ma = a->data.ma;
		this->data.xuatxu = a->data.xuatxu;
		this->data.giaban = a->data.giaban;
		this->data.tensp = a->data.tensp;
		this->data.nongdo = a->data.nongdo;
		this->data.soluong = a->data.soluong;
		//	return *this;
	}
	void nhapdulieunhieucot(node *head, int x, int t, int sobang);
	void display();
	void loadfilethongtinruou(node *&a, int n); // doc du lieu tu file
	void SaveFilethongtintamthoi(node *a);
	void deletenode(node *&a, int position);
	void bangxuli(int x, int y, node *&head, int xcu, int ycu, int sobang); // them xoa danh sach lien ket
	void themcuoi(node *&head, int x, int y);
	void SaveFilethongtin(node *a);
	void loadfileDocThu(node *&head, int &demphantu);					  // load file docthu.txt demphantu dung de luu tru so bang
	void inbangdanhsachruouTamThoi(int x, int y, node *head, int sobang); // ho tro in bang thong tin ruou tam thoi sau khi nhap
	void printTheoHang(int x, int y);
	friend void XapXepData(int x, int y, node *&head, int sobang);
	friend void DocDuLieuTuFile(int x, int y, node *&head, int &sobang);
	friend void swapdata(node *&a, node *&b);
	friend void InBangDanhSachDaSapXep(int x, int y, node *head, int sobang);
	friend void XapXepTheoNongdo(int x, int y, node *&head);
	friend void XapXepTheoDungTich(int x, int y, node *&head);
	friend void Timten(node *&head, string, node *&GioHang);
	friend void TimTheoMa(node *&head, string, node *&GioHang);
	~node(){};
};
void swapdata(node *&a, node *&b)
{
	node *temp = new node;
	temp->data.ma = a->data.ma;
	temp->data.tensp = a->data.tensp;
	temp->data.xuatxu = a->data.xuatxu;
	temp->data.dungtich = a->data.dungtich;
	temp->data.nongdo = a->data.nongdo;
	temp->data.giaban = a->data.giaban;
	temp->data.soluong = a->data.soluong;

	a->data.ma = b->data.ma;
	a->data.tensp = b->data.tensp;
	a->data.xuatxu = b->data.xuatxu;
	a->data.dungtich = b->data.dungtich;
	a->data.nongdo = b->data.nongdo;
	a->data.giaban = b->data.giaban;
	a->data.soluong = b->data.soluong;

	b->data.ma = temp->data.ma;
	b->data.tensp = temp->data.tensp;
	b->data.xuatxu = temp->data.xuatxu;
	b->data.dungtich = temp->data.dungtich;
	b->data.nongdo = temp->data.nongdo;
	b->data.giaban = temp->data.giaban;
	b->data.soluong = temp->data.soluong;
}
void node::printTheoHang(int x, int y)
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
void node::loadfileDocThu(node *&head, int &demphantu)
{ // lay du lieu ra
	ifstream inFile;
	demphantu = 0;
	head = new node;
	node *tail = new node;
	string temp;
	head = tail = NULL;
	//	node->next=NULL;
	inFile.open("docthu.txt", ios_base::in);
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
		getline(inFile, a->data.ma); // 1
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
		//
		getline(inFile, temp, ':');
		getline(inFile, temp);
		fflush(stdin);
		a->data.giaban = atoll((char *)temp.c_str());
		//
		getline(inFile, temp, ':');
		fflush(stdin);
		getline(inFile, temp);
		a->data.soluong = atoll((char *)temp.c_str());
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
		//	node->next=a;
		// delete a;
		demphantu++;
	}
	demphantu--;
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
}
void node::inbangdanhsachruouTamThoi(int x, int y, node *a, int sobang)
{ // ham in bang thong tin de khi them xoa co the xem ""HAM CHINH CUA IN THONG TIN DE XEM LAI ""
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
		gotoxy(x + 122, y);
		cout << "SO LUONG";
	}
	//	cout<<sobang;
	insobangthongtincanthem(x, y, sobang);
	node *temp = new node;
	temp = a;
	int i = 1;
	while (temp != NULL)
	{
		node::setMa(to_string(i));
		temp->printTheoHang(x + 3, y + 1 + i * 3);
		temp = temp->next;
		i++;
	}
}

void node::themcuoi(node *&head, int x, int y)
{
	node *newNode = new node();
	newNode->inputdata(x, y);
	newNode->next = NULL;
	if (head == NULL)
	{
		head = newNode;
	}
	else
	{
		node *temp = head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = newNode;
	}
}
void node::deletenode(node *&head, int position)
{
	{
		node *temp;
		node *prev;
		temp = head;
		prev = head;
		for (int i = 0; i < position; i++)
		{
			if (i == 0 && position == 1)
			{
				head = head->next;
				free(temp);
			}
			else
			{
				if (i == position - 1 && temp)
				{
					prev->next = temp->next;
					free(temp);
				}
				else
				{
					prev = temp;
					if (prev == NULL)
						break;
					temp = temp->next;
				}
			}
		}
	}
}
void node::SaveFilethongtin(node *a)
{
	ofstream FileOut;
	node *head = new node;
	head = a;
	int i = 1;
	FileOut.open("data.txt", ios_base::out | std::ios::app);
	while (head != NULL)
	{
		node::setMa(to_string(i));
		i++;
		FileOut << "- Ma ruou :" << head->data.ma;
		FileOut << endl
				<< "- Ten san pham :" << head->data.tensp;
		FileOut << endl
				<< "- Xuat xu :" << head->data.xuatxu;
		FileOut << endl
				<< "- Dung tich :" << head->data.dungtich;
		FileOut << endl
				<< "- Nong do :" << head->data.nongdo;
		FileOut << endl
				<< "- Gia ban :" << head->data.giaban;
		FileOut << endl
				<< "- So Luong :" << head->data.soluong;
		FileOut << endl
				<< "##########" << endl;
		head = head->next;
	}
	FileOut.close();
}
void node::SaveFilethongtintamthoi(node *a)
{
	ofstream FileOut;
	node *head = new node;
	head = a;
	int i = 1;
	FileOut.open("docthu.txt", ios_base::out);
	while (head != NULL)
	{
		node::setMa(to_string(i));
		i++;
		FileOut << "- Ma ruou :" << head->data.ma;
		FileOut << endl
				<< "- Ten san pham :" << head->data.tensp;
		FileOut << endl
				<< "- Xuat xu :" << head->data.xuatxu;
		FileOut << endl
				<< "- Dung tich :" << head->data.dungtich;
		FileOut << endl
				<< "- Nong do :" << head->data.nongdo;
		FileOut << endl
				<< "- Gia ban :" << head->data.giaban;
		FileOut << endl
				<< "- So Luong :" << head->data.soluong;
		// FileOut << endl << "- Vi tri : " << a.m_Vitri;
		FileOut << endl
				<< "##########" << endl;
		head = head->next;
	}
	FileOut.close();
}
void node::display()
{
	cout << this->data.ma << endl;
	cout << this->data.tensp << endl;
	cout << this->data.xuatxu << endl;
	cout << this->data.dungtich << endl;
	cout << this->data.nongdo << endl;
	cout << this->data.giaban << endl;
	cout << this->data.soluong;
}
void node::inputdata(int x, int y)
{
	string temp;
	fflush(stdin);
	gotoxy(x + 10, y);
	cout << this->data.ma;
	gotoxy(x + 20, y);
	fflush(stdin);
	getline(cin, data.tensp);
	gotoxy(x + 50, y);
	fflush(stdin);
	getline(cin, data.xuatxu);
	do
	{
		thanhsang(x + 69, y, 1, 10, 7, 0);
		gotoxy(x + 69, y);
		fflush(stdin);
		getline(cin, temp);

	} while (isNumber(temp) == false);
	data.dungtich = stoi(temp); // bat nguoi dung nhap lai neu nguoi dung nhap ky tu
	do
	{
		thanhsang(x + 83, y, 1, 8, 7, 0);
		gotoxy(x + 83, y);
		fflush(stdin);
		getline(cin, temp);
	} while (isNumber(temp) == false); // bat nguoi dung nhap lai neu nguoi dung nhap ky tu
	data.nongdo = stoi(temp);
	do
	{
		thanhsang(x + 97, y, 1, 12, 7, 0);
		gotoxy(x + 97, y);
		fflush(stdin);
		getline(cin, temp);
	} while (isNumber(temp) == false); // bat nguoi dung nhap lai neu nguoi dung nhap ky tu
	data.giaban = stoi(temp);
	do
	{
		thanhsang(x + 111, y, 1, 12, 7, 0);
		gotoxy(x + 111, y);
		fflush(stdin);
		getline(cin, temp);
	} while (isNumber(temp) == false); // bat nguoi dung nhap lai neu nguoi dung nhap ky tu
	data.soluong = stoi(temp);
}
void inbangmenunhapthongtinruou(int x, int y, int sobang)
{ // bang nay in theo chieu doc //nay lam ham chinh==============================================================================================
	nhapthongtin(sobang);
	node *head = new node;
	head = NULL; // new khong cap phat bo nho dong thi se khong input du lieu vao duoc
	for (int i = x; i < 110 + x; i++)
	{
		for (int j = y; j < 3 + y; j++)
		{
			gotoxy(i, j);
			SetBGColor(1);
			if (i == 13 || i == 23 || i == 55 || i == 70 || i == 85 || i == 97 || i == 125 || i == 166)
			{
				textcolor(0);
				cout << char(179);
			}
			else
				cout << " " << endl;
		}
		SetBGColor(1);
		textcolor(10);
		gotoxy(8, 5);
		cout << "STT";
		gotoxy(17, 5);
		cout << "MA";
		gotoxy(34, 5);
		cout << "TEN SAN PHAM";
		gotoxy(59, 5);
		cout << "XUAT XU";
		gotoxy(72, 5);
		cout << "DUNG TICH(ml)";
		gotoxy(88, 5);
		cout << "NONG DO";
		gotoxy(103, 5);
		cout << "GIA BAN";
		gotoxy(122, 5);
		cout << "SO LUONG";
	}
	insobangthongtincanthem(x, y, sobang);
	for (int i = 1; i <= sobang; i++)
	{
		node *b = new node;
		b->setMa(to_string(i));
		b->inputdata(x, y + 1 + i * 3);
		if (head == NULL)
		{
			head = b;
		}
		else
		{
			node *temp = new node;
			temp = head;
			while (temp->next != NULL)
			{ // them vao cuoi danh sach lien ket
				temp = temp->next;
			}
			temp->next = b;
		}
	}
	node *temp = new node; // in thong tin vua nhap vao
	temp = head;
	SetBGColor(0);
	system("cls");
	temp->bangxuli(2, 4, temp, x, y, sobang);
}
void insobangthongtincanthem(int x, int y, int dem)
{
	int sothutu = 1;
	for (int j = y + 3; j < dem * 3 + y + 3; j++)
	{
		for (int i = x; i < x + 110; i++)
		{
			SetBGColor(7);
			if (i == 13 || i == 23 || i == 55 || i == 70 || i == 85 || i == 97 || i == 125)
			{ // in thanh doc
				textcolor(0);
				gotoxy(i, j);
				cout << char(179);
			}
			else if ((j - y - 2) % 3 == 0)
			{ // in thanh ngang
				if (i == x + 4)
				{
					gotoxy(i - 2, j - 1); // in dich lui 2 don vi neu khong se bi ví du in 10 nhung neu bi dè thì chi in 10
					//	SetBGColor(2);
					textcolor(0);
					cout << sothutu;
					sothutu++;
				}
				// 	int count=0;
				SetBGColor(7);
				textcolor(0);
				gotoxy(i, j);
				cout << char(95);
			}
			else
			{

				gotoxy(i, j);
				cout << " ";
			}
		}

		//	cout<<sothutu;
	}
	//	gotoxy(1,1);
}
void nhapthongtin(int &sobang)
{ // in so luong bang mà nguoi dung muôn nhâp
	string temp;
	KhungTieuDe(5, 0, 38, 2, 2, 7);
	gotoxy(6, 1);
	setColor(0, 7);
	cout << "Nhap so luong san pham can nhap";
	KhungTieuDe(55, 0, 10, 2, 2, 7);
	gotoxy(57, 1);
	setColor(0, 7);
	do
	{
		thanhsang(57, 1, 1, 4, 0, 7);
		setColor(0, 7);
		gotoxy(57, 1);
		fflush(stdin);
		getline(cin, temp);
	} while (isNumber(temp) == false);
	sobang = stoi(temp); // chuyen chuoi thanh so
}
//======================================================================================================================================================
void bangxoaphantu(int x, int y, int &n)
{
	string temp;
	gotoxy(x, y + 4);
	cout << "nhap hang ban muon xoa:";
	do
	{
		fflush(stdin);
		getline(cin, temp);
	} while (isNumber(temp) == false);
	n = stoi(temp);
}
void setbackground(int x, int y)
{
	for (int i = y - 1; i < 4 + y; i++)
	{
		for (int j = x - 1; j < 130 + x; j++)
		{
			gotoxy(j, i);
			SetBGColor(5);
			cout << " ";
		}
	}
};
void displaythongtin(int x, int y)
{
	for (int i = y; i < 3 + y; i++)
	{
		for (int j = x; j < 20 + x; j++)
		{
			if (i == y || i == 2 + y)
			{
				gotoxy(j, i);
				cout << char(196);
			}
			if (j == x || j == x + 19)
			{
				gotoxy(j, i);
				cout << char(179);
			}
			if (j == x + 19 && i == y)
			{ // goc tren ben phai
				gotoxy(j, i);
				cout << char(191);
			}
			if (j == x + 19 && i == y + 2)
			{ // goc tren ben trai
				gotoxy(j, i);
				cout << char(217);
			}
			if (i == y && j == x)
			{ // goc tren ben trai
				gotoxy(j, i);
				cout << char(218);
			}
			if (i == y + 2 && j == x)
			{ // goc tren ben phai
				gotoxy(j, i);
				cout << char(192);
			}
		}
	}
}
void node::bangxuli(int x, int y, node *&head, int xmenu, int ymenu, int sobang)
{
	string str[4];
	str[0] = "XOA THONG TIN";
	str[1] = "THEM THONG TIN";
	str[2] = "XEM THONG TIN";
	str[3] = "VE MENU";
	textcolor(7);
	setbackground(x, y);
	displaythongtin(x, y);
	gotoxy(x + 4, y + 1);
	cout << str[0];
	displaythongtin(x + 30, y);
	gotoxy(x + 34, y + 1);
	cout << str[1];
	displaythongtin(x + 60, y);
	gotoxy(x + 64, y + 1);
	cout << str[2];
	displaythongtin(x + 90, y);
	gotoxy(x + 94, y + 1);
	cout << str[3];
	//	xulikitu(x,y,str);
	//	menuchinh();
	bool kt = true;
	//	bangxuli( x, y);
	int xcu = x, ycu = y;
	char c;
	int i = 0; // index cua mang
	int icu = 0;
	while (kt)
	{
		setColor(5, 7);
		gotoxy(xcu + 1, ycu + 1);
		cout << "                  ";
		gotoxy(xcu + 4, ycu + 1);
		cout << str[icu];
		icu = i;
		gotoxy(x, y); // tao mau dong dau tien
		setColor(2, 4);
		xcu = x, ycu = y;
		gotoxy(x + 1, y + 1);
		cout << "                  ";
		gotoxy(x + 4, y + 1);
		cout << str[i];
		c = _getch();
		switch (c)
		{
		case 77: // sang trai
			x = x + 30;
			i++;
			if (x > 110)
			{
				x = x - 30 * 4;
				i = 0;
			}
			break;
		case 75:
			x = x - 30;
			i--;
			if (x < 0)
			{
				x = x + 120;
				i = 3;
			}
			break;
		case 13: // enter
			SetBGColor(7);
			textcolor(1);
			if (x < 30)
			{
				xoaduoi(2, y + 4, sobang);
				SetBGColor(7);
				int n;
				bangxoaphantu(x, y, n);
				head->deletenode(head, n);
				sobang--;
			}
			if (x > 30 && x < 60)
			{
				xoaduoi(2, y + 4, sobang);
				inbangtieude(5, y + 5);
				insobangthongtincanthem(5, y + 5, 1);
				head->themcuoi(head, 6, y + 9);
			}
			if (x > 60 && x < 90)
			{
				xoaduoi(2, y + 4, sobang);
				head->SaveFilethongtintamthoi(head);
				head->loadfileDocThu(head, sobang);
				head->inbangdanhsachruouTamThoi(3, y + 4, head, sobang);
			}
			if (x > 90)
			{
				head->SaveFilethongtin(head);
				SetBGColor(0);
				system("cls");

				kt = false;
			}
			break;
		}
	}
}
void xoaduoi(int x, int y, int sobang)
{
	for (int i = y; i < y + 5 + sobang * 3; i++)
	{
		for (int j = x; j < x + 120; j++)
		{
			SetBGColor(0);
			gotoxy(j, i);
			cout << " ";
		}
	}
}
void inbangtieude(int x, int y)
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
}
#endif
