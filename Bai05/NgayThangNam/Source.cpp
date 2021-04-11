#include<iostream>
#include "ThoiGian.h"

using namespace std;

int main()
{
	ThoiGian homNay, ngayMai, HomQua;
	// Nhap thoi gian 
	homNay.Nhap();

	// Tang va xuat thoi gian 
	ngayMai = homNay;
	ngayMai.TangThoiGian(homNay);
	cout << "Ngay mai la : ";
	ngayMai.Xuat();

	// Giam va xuat thoi gian
	HomQua = homNay;
	HomQua.GiamThoiGian(homNay);
	cout << "Ngay hom qua la : ";
	HomQua.Xuat();

	// Kiem tra nam nhuan
	if (homNay.KiemTraNamNhuan(homNay.LayNam()) == 1)
	{
		cout << "\nNam nhuan";
	}
	else
	{
		cout << "\nKhong phai nam nhuan";
	}

	// Tim thu
	cout << "\nThu : " << homNay.TimThu(homNay);

	return 0;
}