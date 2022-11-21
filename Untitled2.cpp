
#include <string.h>
#include <fstream>
#include "nhapthongtinruou.h"
node *head1=new node;

void Savefilethongtin(node *a, int n ) {
	node *temp=new node ;
	temp=a;
	ofstream FileOut;
		FileOut << n;
	FileOut.open("thu.txt", ios_base::app );
	while( temp!=NULL) {
		FileOut << endl << "- Ma : " << temp->data.ma;
		FileOut << endl << "-ten san pham : " << temp->data.tensp;
		FileOut << endl << "-Xuat xu : " << temp->data.xuatxu;
		FileOut << endl << "- Dung tich : " << temp->data.dungtich;
		FileOut << endl << "- Nong do : " << temp->data.nongdo;
		FileOut << endl << "- Gia ban : " << temp->data.giaban;
		FileOut << endl << "##########";
		temp=temp->next;
	}
	FileOut.close();
}


void getdata(node *&head,int n ){ //read from files
	ifstream FileIn;
	node *temp=new node;
	temp=head;              
	string chuoingancach, bientam;
	char phimenter;
	FileIn.open("thu.txt", ios_base::in );
	if( !FileIn ) {
		cout << "Khong tim thay file danhmucsach.txt" << endl;
		system("pause");
		return;
	}
		getline( FileIn, bientam );
	//	n = atoi((char*)bientam.c_str());
		//book = new ListSach[n];
		for( int i = 0 ; i < n ; i++ ) {
			// Dich bit seekg(<so bit can dich> , <tu vi tri> );
			getline(FileIn, bientam,':');
			//FileIn.seekg(13,1);
			getline(FileIn,temp->data.ma);
		//	FileIn.seekg(13,1);
			
	//		book[i].m_Sotrang = atoi((char*)bientam.c_str());
	//		FileIn.seekg(12,1);
			getline(FileIn, bientam,':');
			getline(FileIn, temp->data.tensp);
		//	FileIn.seekg(17,1);getline(FileIn, bientam,":");
			getline(FileIn, bientam,':');
			getline(FileIn, temp->data.xuatxu);
			getline(FileIn, bientam,':');
			getline(FileIn, bientam);
			bientam='3';
			temp->data.dungtich=stoi(bientam);
			getline(FileIn, bientam,':');
			getline(FileIn,bientam );
			temp->data.nongdo=stoi(bientam);
			getline(FileIn, bientam,':');
			getline(FileIn, bientam);
			temp->data.giaban=stoi(bientam);
			getline( FileIn, chuoingancach);
			temp->next=new node;//cap phat bo nho dong cho temp-next;
			temp=temp->next;
}
}
void input(node *&head){
	head=new node;
	head->inputdata(1,1);
	head->display();
}
int main() {
	int a;     
	input(head1);
	node *tal;
	input(tal);
	tal=head1->next;
	node *temp=new node;
	temp=head1;
//	head1->display();
//	cout<<endl<<endl<<endl;
//	tal->display();
	do {
		temp->display();
		cout<<"\n";
		temp=temp->next;
		cout<<"ham de ket thuc";
	} while(temp!=NULL);
	Savefilethongtin(head1,a);
//	node *header=new node;
//	node *temp1=new node;
//	
//	getdata(header,8);
//	temp1=header;
//		do {
//		temp1->display();
//		cout<<"\n";
//		temp1=temp1->next;
//		cout<<"=================";
//	} while(temp1->next!=NULL);
             
	
	
	
}

