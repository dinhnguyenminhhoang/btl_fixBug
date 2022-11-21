#include <iostream>
#include "support.h"
#include "nhapthongtinruou1.h"
#include "XemThongTinRuouDaNhap.h"
class GioHang:public node,public xuatthongtin
{

	public:
		void inSanPhamTrongGioHang(int x,int y,node *&GioHang,int &demPhanTu);
};
void inSanPhamTrongGioHang(int x,int y){
	GioHang *a;
	int dem=0;
	node *GioHang = new node;
	a->loadfile("GioHang.txt",GioHang,dem);
}
int main(){
	
}