#include "SoPhuc.h"
#include <iostream>
using namespace std;

void SoPhuc::SetSoPhuc(float thuc, float ao)
{
	// Cap nhat gia tri cho phan thuc va phan ao
	this->phanThuc = thuc;
	this->phanAo = ao;
}

SoPhuc::SoPhuc()
{
	// Gan thuc=0 va ao=0
	SetSoPhuc(0, 0);
}

SoPhuc::SoPhuc(float thuc, float ao)
{
	// Gan this->phanThuc=thuc va this->phanAo=ao
	SetSoPhuc(thuc, ao);
}

void SoPhuc::NhapSoPhuc()
{
	cout << "Moi nhap phan thuc so phuc: ";
	cin >> phanThuc;

	cout << "Moi nhap phan ao so phuc: ";
	cin >> phanAo;
}

void SoPhuc::XuatSoPhuc()
{
	cout << "(" << phanThuc << "," << phanAo << ")";
	cout << endl;
}

SoPhuc SoPhuc::Cong(SoPhuc a, SoPhuc b)
{
	// Tinh tong hai so phuc
	SoPhuc tongSP;

	tongSP.phanThuc = a.phanThuc + b.phanThuc;
	tongSP.phanAo = a.phanAo + b.phanAo;

	return tongSP;
}

SoPhuc SoPhuc::Tru(SoPhuc a, SoPhuc b)
{
	// Tinh hieu hai so phuc
	SoPhuc hieuSP;

	hieuSP.phanThuc = a.phanThuc - b.phanThuc;
	hieuSP.phanAo = a.phanAo - b.phanAo;

	return hieuSP;
}

SoPhuc SoPhuc::Nhan(SoPhuc a, SoPhuc b)
{
	// Tinh tich hai so phuc
	SoPhuc tichSP;

	tichSP.phanThuc = a.phanThuc * b.phanThuc - a.phanAo * b.phanAo;
	tichSP.phanAo = a.phanThuc * b.phanThuc + a.phanAo * b.phanAo;

	return tichSP;
}

SoPhuc SoPhuc::Chia(SoPhuc a, SoPhuc b)
{
	// Tinh thuong hai so phuc
	SoPhuc thuongSP;

	thuongSP.phanThuc = (a.phanThuc * b.phanThuc + a.phanAo * b.phanAo) / (b.phanThuc * b.phanThuc + b.phanAo * b.phanAo);
	thuongSP.phanAo = (b.phanThuc * a.phanAo - a.phanThuc * b.phanAo) / (b.phanThuc * b.phanThuc + b.phanAo * b.phanAo);

	return thuongSP;
}

int main()
{
	SoPhuc a, b;
	SoPhuc tongSP, hieuSP, tichSP, thuongSP;

	// Nhap hai so phuc
	a.NhapSoPhuc();
	b.NhapSoPhuc();

	// Tinh tong hai so phuc
	tongSP = tongSP.Cong(a, b);
	cout << "\nTong hai so phuc la: ";
	tongSP.XuatSoPhuc();

	//Tinh hieu hai so phuc
	hieuSP = hieuSP.Tru(a, b);
	cout << "Hieu hai so phuc la: ";
	hieuSP.XuatSoPhuc();

	// Tinh tich hai so phuc
	tichSP = tichSP.Nhan(a, b);
	cout << "Tich hai so phuc la: ";
	tichSP.XuatSoPhuc();

	// Tinh thuong hai so phuc
	thuongSP = thuongSP.Chia(a, b);
	cout << "Thuong hai so phuc la: ";
	thuongSP.XuatSoPhuc();

	return 0;
}
