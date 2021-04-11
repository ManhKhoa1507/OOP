#include "String.h"
String::String()
{
	str = "";
}

String::String(string str)
{
	this->str = str;
}

String::String(const String& S)
{
	this->str = S.str;
}

void String::Nhap()
{
	// Ham nhap
	cout << "\nNhap : ";
	cin >> str;
}

void String::Xuat()
{
	// Ham xuat
	cout << str << "\n";
}

int String::TinhChieuDai()
{
	return str.length();
}

String String::NoiChuoi(String chuoiDau, String chuoiCuoi)
{
	String temp;
	temp.str = chuoiDau.str + chuoiCuoi.str;
	return temp;
}

void String::DaoChuoi()
{
	int n = str.length();

	// Swap character starting from two
	// corners
	for (int i = 0; i < n / 2; i++)
	{
		swap(str[i], str[n - i - 1]);
	}
}

void String::InHoa()
{
	String  temp;
	locale loc;
	for (int i = 0; i < str.length(); i++)
	{
		cout << std::toupper(str[i], loc);
	}
}

void String::VietThuong()
{
	String temp;
	locale loc;
	for (int i = 0; i < str.length(); i++)
	{
		cout << tolower(str[i], loc);
	}
}
