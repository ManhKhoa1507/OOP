#include<iostream>
#include "ThoiGian.h"

using namespace std;

int main()
{
	ThoiGian hienTai, tuongLai, quaKhu;

	//Nhap thoi gian
	hienTai.NhapThoiGian();
	
	//Tang thoi gian 
	tuongLai = hienTai;
	tuongLai.TangThoiGian();
	cout << "\nTang thoi gian them 1s: ";
	tuongLai.XuatThoiGian();

	// Giam thoi gian
	quaKhu = hienTai;
	cout << "\nGiam thoi gian 1s: ";
	quaKhu.GiamThoiGian();
	quaKhu.XuatThoiGian();
	
	return 0;
}