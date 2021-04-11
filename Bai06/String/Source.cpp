#include<iostream>
#include<string>
#include<locale>
#include"String.h"

using namespace std;

int main()
{
	String chuoiThuNhat, chuoiThuHai;

	chuoiThuNhat.Nhap();
	chuoiThuHai.Nhap();

	// tinh chieu dai cua chuoi
	cout << "Chieu dai cua chuoiThuNhat : " << chuoiThuNhat.TinhChieuDai();
	
	// noi 2 chuoi 
	cout << "\nNoi 2 chuoi :";
	String noiChuoi = noiChuoi.NoiChuoi(chuoiThuNhat, chuoiThuHai);
	noiChuoi.Xuat();

	// dao chuoi
	cout << "\nDao chuoi: ";
	String daoChuoi = chuoiThuNhat;
	daoChuoi.DaoChuoi();
	daoChuoi.Xuat();

	// in hoa
	cout << "\nIn hoa: ";
	String inHoa = chuoiThuNhat;
	inHoa.InHoa();
	
	// in thuong
	cout << "\nIn thuong: ";
	String inThuong = chuoiThuNhat;
	inThuong.VietThuong();

	return 0;
}