#pragma once
class ThoiGian
{
private :
	int gio;
	int phut;
	int giay;

public :
	ThoiGian();
	ThoiGian(int, int, int);
	ThoiGian(const ThoiGian&);

	void NhapThoiGian();
	void XuatThoiGian();

	void KiemTraTangThoiGian(int&, int&, int&);
	void KiemTraGiamThoiGian(int&, int&, int&);

	int LayGio();
	int LayPhut();
	int LayGiay();

	void TangThoiGian();
	void GiamThoiGian();
};

