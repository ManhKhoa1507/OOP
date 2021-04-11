class ToaDo
{
private:
	int hoanhDo;
	int tungDo;
public:
	// Constructor cua ToaDo
	ToaDo();
	ToaDo(int, int);

	// Cap nhat va truy xuat gia tri
	void SetToaDo(int, int);

	// Lay toa do
	int GetHoanhDo();
	int GetTungDo();

	// Nhap xuat toa do va tinh tien
	void NhapToaDo();
	void XuatToaDo();
	void TinhTien();
};

