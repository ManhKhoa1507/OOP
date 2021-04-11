// Tao 1 lop phan so
class PhanSo
{
private:
	int tu;
	int mau;
	int UCLN(int, int);

public:
	// Constructor cua PhanSo
	PhanSo();
	PhanSo(int);
	PhanSo(int, int);

	// Cap nhat gia tri cho tu va mau cua phan so
	void SetPhanSo(int, int);
	// Rut gon phan so
	void RutGon();
	// Chuan hoa phan so
	void ChuanHoaPhanSo();

	// Nhap va xuat phan so
	void NhapPhanSo();
	void XuatPhanSo();

	// Cong, tru, nhan, chia hai phan so
	PhanSo Tong(PhanSo, PhanSo);
	PhanSo Tru(PhanSo, PhanSo);
	PhanSo Nhan(PhanSo, PhanSo);
	PhanSo Chia(PhanSo, PhanSo);
};
