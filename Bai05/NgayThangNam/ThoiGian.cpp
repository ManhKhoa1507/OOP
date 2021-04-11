#include "ThoiGian.h"
#include<iostream>

using namespace std;

ThoiGian::ThoiGian()
{
	ngay = 0;
	thang = 0;
	nam = 0;
}

ThoiGian::ThoiGian(int ngay, int thang, int nam)
{
	this->ngay = ngay;
	this->thang = thang;
	this->nam = nam;
}
ThoiGian::ThoiGian(const ThoiGian& tg)
{
	this->ngay = tg.ngay;
	this->thang = tg.thang;
	this->nam = tg.nam;
}

void ThoiGian::Nhap()
{
	cout << "\nNhap ngay: ";
	cin >> ngay;

	cout << "\nNhap thang: ";
	cin >> thang;
	
	cout << "\nNhap nam: ";
	cin >> nam;
}

void ThoiGian::Xuat()
{
	cout << ngay << " " << thang << " " << nam << "\n";
}

int ThoiGian::LayNgay()
{
	return this->ngay;
}

int ThoiGian::LayThang()
{
	return this->thang;
}

int ThoiGian::LayNam()
{
	return this->nam;
}

int ThoiGian::KiemTraNamNhuan(int nam)
{
	// nam nhuan la nam chia het cho 4 va chia het cho 400 
	//		va khong chia het cho 100

	// Tinh nam tu 400 
	if ((nam % 4 == 0) && (nam % 400 == 0))
	{
		return 1;
	}

	else
	{
		if (nam % 100 == 0) return 0;
		if (nam % 4 == 0) return 1;
	}

	// Khong phai nam nhuan 
	return 0;
}

void ThoiGian::DatNam(int nam)
{
	this->nam = nam;
}

void ThoiGian::DatThang(int thang)
{
	this->thang = thang;
}

void ThoiGian::DatNgay(int ngay)
{
	this->ngay = ngay;
}

ThoiGian ThoiGian::TangNam(ThoiGian& T, int& ch)
{
	// Ham tang thoi gian them 1 nam
	// tang nam neu thang la 12 va ngay = 31
	if (T.LayNgay() == 31 && T.LayThang() == 12)
	{
		int nam = T.LayNam() + 1;

		this->DatNam(nam);
		this->DatThang(1);
		this->DatNgay(1);

		ch++;
	}

	return T;
}

void ThoiGian::TangMotThang(ThoiGian& T,int &ch)
{
	// tang thoi gian them 1 thang

	int thang = T.LayThang() + 1;
	this->DatThang(thang);
	this->DatNgay(1);
	ch++;
}

void ThoiGian::TangMotNgay(ThoiGian& T)
{
	int ngay = T.LayNgay() + 1;
	this->DatNgay(ngay);
}

ThoiGian ThoiGian::TangThang(ThoiGian& T, int& ch)
{
	// ham tang thoi gian them 1 thang

	// tang thang co 31 ngay neu ngay hien tai la cuoi thang
	if (T.LayNgay() == 31 && (T.LayThang() == 1 || T.LayThang() == 3 || T.LayThang() == 5 ||
		T.LayThang() == 7 || T.LayThang() == 8 || T.LayThang() == 10 || T.LayThang() == 12))
	{
		TangMotThang(T,ch);
	}

	// tang thang co 30 ngay neu ngay hien tai la cuoi thang
	if (T.LayNgay() == 30 && (T.LayThang() == 4 || T.LayThang() == 6 
		|| T.LayThang() == 9 || T.LayThang() == 11))
	{
		TangMotThang(T,ch);
	}

	return T;
}


ThoiGian ThoiGian::TangNgay(ThoiGian& T, int& ch)
{
	// ham tang thoi gian them 1 ngay

	// tang ngay neu chua cuoi thang & ngay thuoc thang co 31 ngay
	if (T.LayNgay() < 31 && (T.LayThang() == 1 || T.LayThang() == 3 || T.LayThang() == 5
		|| T.LayThang() == 7 || T.LayThang() == 8 || T.LayThang() == 10 || T.LayThang() == 12))
	{
		TangMotNgay(T);
	}

	// tang ngay neu chua cuoi thang & ngay thuoc thang co 30 ngay
	if (T.LayNgay() < 30 && (T.LayThang() == 4 || T.LayThang() == 6 || T.LayThang() == 9 || T.LayThang() == 11))
	{
		TangMotNgay(T);
	}

	// tang ngay trong thang 2 va nam nhuan 
	if ((KiemTraNamNhuan(T.LayNam()) == 1) && T.LayThang() == 2 && T.LayNgay() < 29)
	{
		TangMotNgay(T);
	}
	// tang ngay trong thang 2 va nam khong nhuan
	if ((KiemTraNamNhuan(T.LayNam()) == 0) && T.LayThang() == 2 && T.LayNgay() < 28)
	{
		TangMotNgay(T);
	}
	return T;
}

void ThoiGian::TangThoiGian(ThoiGian& T)
{
	int ch = 0;
	// ham tim ngay ke tiep
	// ket qua tra ve ngay tiep theo
	if (KiemTraNamNhuan(T.LayNam()) == 1)
	{
		if (T.LayThang() == 2 && T.LayNgay() == 29)
		{
			// tang thang neu ngay la 29 thang 2 cua nam nhuan
			TangMotThang(T,ch);
		}

		else
		{
			// tang ngay thang nam 
			TangNam(T, ch);
			if (ch == 0) TangThang(T, ch);
			if (ch == 0) TangNgay(T, ch);
		}
	}

	// Khong phai nam nhuan
	else
	{
		if (T.LayThang() == 2 && T.LayNgay() == 28)
		{
			// tang thang neu la nam khong nhuan
			TangMotThang(T,ch);
		}

		else
		{
			TangNam(T, ch);

			if (ch == 0) TangThang(T, ch);
			if (ch == 0) TangNgay(T, ch);
		}
	}
}

ThoiGian ThoiGian::GiamNam(ThoiGian& T, int& ch)
{
	// Ham giam thoi gian them 1 nam
	// giam nam neu thang la 12 va ngay = 31
	if (T.LayNgay() == 1 && T.LayThang() == 1)
	{
		int nam = T.LayNam() - 1;

		this->DatNam(nam);
		this->DatThang(12);
		this->DatNgay(31);

		ch++;
	}

	return T;
}

void ThoiGian::GiamMotThang(ThoiGian& T, int &ch)
{
	int thang = T.LayThang() - 1;
	this->DatThang(thang);
	this->DatNgay(30);
	ch++;
}

void ThoiGian::GiamMotNgay(ThoiGian& T)
{
	int ngay = T.LayNgay() - 1;
	this->DatNgay(ngay);
}

ThoiGian ThoiGian::GiamThang(ThoiGian& T, int& ch)
{
	// ham giam thoi gian them 1 thang
	// giam thang co 31 ngay neu ngay hien tai la cuoi thang
	if (T.LayNgay() == 1 && (T.LayThang() == 2 || T.LayThang() == 5 ||
		T.LayThang() == 7 || T.LayThang() == 8 || T.LayThang() == 10 || T.LayThang() == 12))
	{
		GiamMotThang(T,ch);
	}

	// tang thang co 30 ngay neu ngay hien tai la cuoi thang
	else if (T.LayNgay() == 1 && (T.LayThang() == 4 || T.LayThang() == 6
		|| T.LayThang() == 9 || T.LayThang() == 11))
	{
		GiamMotThang(T,ch);
	}

	// Giam thang 1
	else if (T.LayNgay() == 1 && (T.LayThang() == 1))
	{
		this->DatThang(12);
		this->DatNgay(31);
		ch++;
	}

	return T;
}


ThoiGian ThoiGian::GiamNgay(ThoiGian& T, int& ch)
{
	// ham tang thoi gian them 1 ngay
	
	// tang ngay neu chua cuoi thang & ngay thuoc thang co 31 ngay
	if (T.LayNgay() <= 31 && (T.LayThang() == 1 || T.LayThang() == 2 || T.LayThang() == 5
		|| T.LayThang() == 7 || T.LayThang() == 8 || T.LayThang() == 10 || T.LayThang() == 12))
	{
		GiamMotNgay(T);
	}

	// tang ngay neu chua cuoi thang & ngay thuoc thang co 30 ngay
	else if (T.LayNgay() <= 30 && (T.LayThang() == 4 || T.LayThang() == 6 || T.LayThang() == 9 || T.LayThang() == 11))
	{
		GiamMotNgay(T);
	}

	// giam ngay trong thang 2 va nam nhuan 
	if ((KiemTraNamNhuan(T.LayNam()) == 1) && T.LayThang() == 2 && T.LayNgay() <= 29)
	{
		GiamMotNgay(T);
	}
	// giam ngay trong thang 2 va nam khong nhuan
	if ((KiemTraNamNhuan(T.LayNam()) == 0) && T.LayThang() == 2 && T.LayNgay() <= 28)
	{
		GiamMotNgay(T);
	}
	return T;
}

void ThoiGian::GiamThoiGian(ThoiGian& T)
{
	int ch = 0;
	// ham tim ngay hom qua
	// ket qua tra ve ngay tiep theo
	if (KiemTraNamNhuan(T.LayNam()) == 1)
	{
		if (T.LayThang() == 3 && T.LayNgay() == 1)
		{
			// giam thang neu ngay la 1 thang 3 cua nam nhuan
			this->DatThang(2);
			this->DatNgay(29);
		}

		else
		{
			// giam ngay thang nam 
			GiamNam(T, ch);
			if (ch == 0) GiamThang(T, ch);
			if (ch == 0) GiamNgay(T, ch);
		}
	}

	// Khong phai nam nhuan
	else
	{
		if (T.LayThang() == 3 && T.LayNgay() == 1)
		{
			// giam thang neu la nam khong nhuan
			this->DatThang(2);
			this->DatNgay(28);
		}

		else
		{
			GiamNam(T, ch);

			if (ch == 0) GiamThang(T, ch);
			if (ch == 0) GiamNgay(T, ch);
		}
	}
}

const char *ThoiGian::TimThu(ThoiGian T)
{
	int JMD;
	JMD = (T.LayNgay() + ((153 * (T.LayThang() + 12 * ((14 - LayThang()) / 12) - 3) + 2) / 5) +
		(365 * (T.LayNam() + 4800 - ((14 - LayThang()) / 12))) +
		((T.LayNam() + 4800 - ((14 - LayThang()) / 12)) / 4) -
		((T.LayNam() + 4800 - ((14 - LayThang()) / 12)) / 100) +
		((T.LayNam() + 4800 - ((14 - LayThang()) / 12)) / 400) - 32045) % 7;
	//cout << JMD;
	const char* weekday[] = { "Thu 2",
	  "Thu 3",
	  "Thu 4",
	  "Thu 5",
	  "Thu 6",
	  "Thu 7",
	  "Chu nhat" };
	return weekday[JMD];
}