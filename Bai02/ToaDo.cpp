#include "ToaDo.h"
#include <iostream>
using namespace std;

void ToaDo::SetToaDo(int x, int y)
{
	// Cap nhat hoanh do va tung do
	this->hoanhDo = x;
	this->tungDo = y;
}

ToaDo::ToaDo()
{
	// Gan hoang do va tung do = 0
	SetToaDo(0, 0);
}

ToaDo::ToaDo(int x, int y)
{
	// this->hoanhDo=x va this->tungDo=y
	SetToaDo(x, y);
}

void ToaDo::NhapToaDo()
{
	int hoanh, tung;

	cout << "Nhap hoanh do: ";
	cin >> hoanh;

	cout << "Nhap tung do: ";
	cin >> tung;

	SetToaDo(hoanh, tung);
}

void ToaDo::XuatToaDo()
{
	cout << "(" << GetHoanhDo() << "," << GetTungDo() << ")";
	cout << endl;
}

int ToaDo::GetHoanhDo()
{
	// Lay hoanh do
	return this->hoanhDo;
}

int ToaDo::GetTungDo()
{
	// Lay tung do
	return this->tungDo;
}

void ToaDo::TinhTien()
{
	// Nhap vecto phap tuyen
	int a, b;
	cout << "Nhap toa do vecto phap tuyen: ";
	cin >> a >> b;

	// Tinh tien
	hoanhDo = hoanhDo + a;
	tungDo = tungDo + b;
}

int main()
{
	ToaDo diem;

	diem.NhapToaDo();
	cout << "Hoanh do va tung do la: ";
	diem.XuatToaDo();

	diem.TinhTien();
	cout << "Toa do sau khi tinh tien: ";
	diem.XuatToaDo();

	return 0;
}