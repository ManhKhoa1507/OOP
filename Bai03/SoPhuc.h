class SoPhuc
{
private:
	float phanThuc;
	float phanAo;
public:
	// Constructor cua SoPhuc
	SoPhuc();
	SoPhuc(float, float);

	// Cap nhat gia tri cho phanThuc va phanAo
	void SetSoPhuc(float, float);

	// Nhap va xuat SoPhuc
	void NhapSoPhuc();
	void XuatSoPhuc();

	// Cong tru nhan chia hai so phuc
	SoPhuc Cong(SoPhuc, SoPhuc);
	SoPhuc Tru(SoPhuc, SoPhuc);
	SoPhuc Nhan(SoPhuc, SoPhuc);
	SoPhuc Chia(SoPhuc, SoPhuc);
};

