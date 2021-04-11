#include "PhanSo.h"
#include <iostream>
using namespace std;

void PhanSo::SetPhanSo(int tu, int mau)
{
	// Gan gia tri tu va mau
	// Khong co gia tri tra ve
	this->tu = tu;
	this->mau = mau;
}

PhanSo::PhanSo()
{
	// Gan tu=0 va mau=1
	// Khong co gia tri tra ve
	SetPhanSo(0, 1);
}

PhanSo::PhanSo(int tu)
{
	// Gan this->tu=tu va mau=1
	// Khong co gia tri tra ve
	SetPhanSo(tu, 1);
}

PhanSo::PhanSo(int tu, int mau)
{
	// Gan this->tu=tu va this->mau=mau
	// Khong co gia tri tra ve
	SetPhanSo(tu, mau);
}

void PhanSo::NhapPhanSo()
{
	cout << "Nhap tu so: ";
	cin >> tu;

	cout << "Nhap mau so: ";
	cin >> mau;
	cout << endl;
}

void PhanSo::XuatPhanSo()
{
	cout << tu << "/" << mau << endl;
}

int PhanSo::UCLN(int tu, int mau)
{
	// Tim UCLN giua tu va mau
	// return mau
	int r;
	while (tu % mau != 0)
	{
		r = tu % mau;
		tu = mau;
		mau = r;
	}
	return mau;
}

void PhanSo::RutGon()
{
	// Rut gon phan so
	float temp = UCLN(tu, mau);
	return SetPhanSo(tu / temp, mau / temp);
}

void PhanSo::ChuanHoaPhanSo()
{
	// Chuan hoa phan so
	// Truong hop tu<0 va mau<0
	if (tu < 0 && mau < 0)
	{
		SetPhanSo(abs(tu), abs(mau));
	}

	// Truong hop tu>0 va mau<0
	if (tu > 0 && mau < 0)
	{
		SetPhanSo(-tu, abs(mau));
	}
}

PhanSo PhanSo::Tong(PhanSo a, PhanSo b)
{
	// Tinh tong hai phan so
	PhanSo tongPS;

	tongPS.tu = a.tu * b.mau + a.tu * b.mau;
	tongPS.mau = a.mau * b.mau;

	return tongPS;
}

PhanSo PhanSo::Tru(PhanSo a, PhanSo b)
{
	// Tinh hieu hai phan so
	PhanSo hieuPS;

	hieuPS.tu = a.tu * b.mau - a.tu * b.mau;
	hieuPS.mau = a.mau * b.mau;

	return hieuPS;
}

PhanSo PhanSo::Nhan(PhanSo a, PhanSo b)
{
	// Tinh tich cua hai phan so
	PhanSo tichPS;

	tichPS.tu = a.tu * b.tu;
	tichPS.mau = a.mau * b.mau;

	return tichPS;
}

PhanSo PhanSo::Chia(PhanSo a, PhanSo b)
{
	// Tinh thuong hai phan so
	PhanSo thuongPS;

	thuongPS.tu = a.tu * b.mau;
	thuongPS.mau = a.mau * b.tu;

	return thuongPS;
}

int main()
{
	PhanSo a, b;
	PhanSo tongPS, hieuPS, tichPS, thuongPS;

	// Nhap phan so a
	a.NhapPhanSo();
	a.ChuanHoaPhanSo();

	// Nhap phan so b
	b.NhapPhanSo();
	b.ChuanHoaPhanSo();

	// Tinh tong hai phan so
	tongPS = tongPS.Tong(a, b);
	tongPS.RutGon();

	cout << "Tong hai phan so la: ";
	tongPS.XuatPhanSo();

	// Tinh hieu hai phan so
	hieuPS = hieuPS.Tru(a, b);
	hieuPS.RutGon();

	cout << "Hieu hai phan so la: ";
	hieuPS.XuatPhanSo();

	// Tinh tich hai phan so
	tichPS = tichPS.Nhan(a, b);
	tichPS.RutGon();

	cout << "Tich hai phan so la: ";
	tichPS.XuatPhanSo();

	// Tinh thuong hai phan so
	thuongPS = thuongPS.Chia(a, b);
	thuongPS.RutGon();

	cout << "Thuong hai phan so la: ";
	thuongPS.XuatPhanSo();

	return 0;
}
