#pragma once
#include<string>
#include<string.h>
#include<iostream>
#include<locale>

using namespace std;

class String
{
private :
	string str="";

public:
	String();
	String(string);
	String(const String&);

	void Nhap();
	void Xuat();

	int TinhChieuDai();
	
	String NoiChuoi(String, String);
	void DaoChuoi();

	void InHoa();
	void VietThuong();
};

