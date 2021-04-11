#pragma once
class ThoiGian
{
private :
	int ngay;
	int thang;
	int nam;
	int thu;

public :
	ThoiGian();
	ThoiGian(int, int, int);
	ThoiGian(const ThoiGian&);

	// Nhap xuat
	void Nhap();
	void Xuat();

	// Lay ngay, thang, nam
	int LayNgay();
	int LayThang();
	int LayNam();

	// Dat ngay, thang, nam
	void DatNgay(int);
	void DatThang(int);
	void DatNam(int);

	int KiemTraNamNhuan(int);
	
	// Tang thoi gian them 1 nam
	ThoiGian TangNam(ThoiGian&, int &);
	ThoiGian TangThang(ThoiGian&, int &);
	ThoiGian TangNgay(ThoiGian&, int&);

	void TangThoiGian(ThoiGian &);
	void TangMotThang(ThoiGian&, int&);
	void TangMotNgay(ThoiGian&);

	// Tim ngay hom qua
	ThoiGian GiamNam(ThoiGian&, int&);
	ThoiGian GiamThang(ThoiGian&, int&);
	ThoiGian GiamNgay(ThoiGian&, int&);

	void GiamThoiGian(ThoiGian&);
	void GiamMotThang(ThoiGian&, int&);
	void GiamMotNgay(ThoiGian&);
	
	// tim thu 
	const char* TimThu(ThoiGian);
};

