#include "ThoiGian.h"
#include <iostream>

using namespace std;

ThoiGian::ThoiGian()
{
	gio = 0;
	phut = 0;
	giay = 0;
}

ThoiGian::ThoiGian(int gio, int phut, int giay)
{
	this->gio = gio;
	this->phut = phut;
	this->giay = giay;
}

ThoiGian::ThoiGian(const ThoiGian& tg)
{
	this->gio = tg.gio;
	this->phut = tg.phut;
	this->giay = tg.giay;
}

int ThoiGian::LayGio()
{
	// Lay gio
	return this->gio;
}

int ThoiGian::LayPhut()
{
	// Lay phut
	return this->phut;
}

int ThoiGian::LayGiay()
{
	// Lay giay
	return this->giay;
}

void ThoiGian::KiemTraTangThoiGian(int& gio, int& phut, int& giay)
{
	// Kiem tra thoi gian tang co hop le hay khong
	if (giay >= 60)
	{
		phut++;
		giay = 0;
		if (phut >= 60)
		{
			gio++;
			phut = 0;
		}
		if (gio >= 24)
		{
			gio = 0;
		}
	}
}

void ThoiGian::KiemTraGiamThoiGian(int& gio, int& phut, int& giay)
{
	// Kiem tra giam thoi gian co hop le hay khong
	if (giay <= 0)
	{
		phut--;
		giay = 59;
		if (phut <= 0)
		{
			gio--;
			phut = 59;
		}
		if (gio <= 0)
		{
			gio = 24;
		}
	}
}


void ThoiGian::NhapThoiGian()
{
	cout << "\nNhap gio: ";
	cin >> gio;

	cout << "\nNhap phut: ";
	cin >> phut;

	cout << "\nNhap giay: ";
	cin >> giay;
}

void ThoiGian::XuatThoiGian()
{
	// Xuat thoi gian
	cout << LayGio() << " " << LayPhut() << " " << LayGiay();
}

void ThoiGian::TangThoiGian()
{
	/// Tang thoi gian 1s
	this->giay++;
	KiemTraTangThoiGian(gio, phut, giay);
}

void ThoiGian::GiamThoiGian()
{
	// Giam thoi gian 1s
	this->giay--;
	KiemTraGiamThoiGian(gio, phut, giay);
}
