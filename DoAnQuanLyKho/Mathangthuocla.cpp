#include "Mathangthuocla.h"
void Mathangthuocla::Nhapfile()
{
	mathang::Nhapfile();
	mathang::filein >> nicotin;
}
void Mathangthuocla::Xuatfile()
{
	mathang::Xuatfile();
	mathang::fileout << "\t\t" << nicotin;
}
void Mathangthuocla::Nhap()
{
	mathang::Nhap();
	bool check = true;
	do {
		mathang::NhapChuoi("\n\t\t\t\t\t\t\t\t\t\t\tNhap vao nong do nicotin: ", nicotin);
		check = mathang::CheckSoThuc(nicotin);
		if (check == false) cout << "\n\t\t\t\t\t\t\t\t\t\t\tNicotin khong hop le. Xin nhap lai\n";
	} while (check == false);
}
void Mathangthuocla::Xuat()
{
	
	ConsoleTable table{ "Id", "TenMatHang", "SoLuong", "DonGia" , "NgaySanXuat", "NgayHetHan", "NiCoTin" };
	table.setStyle(1);
	table += {maMh, tenMh, soluongMh, DonGia, NgaySanXuat, NgayHetHan, nicotin};
	table.setPadding(9);
	cout << table;
}
string Mathangthuocla::GetDoCon(){return "";}
string Mathangthuocla::GetCalories(){return "";}
string Mathangthuocla::GetDoRuou(){return "";}
string Mathangthuocla::GetNiCoTin(){return nicotin;}
void Mathangthuocla::SetNiCoTin(string a){nicotin = a;}
void Mathangthuocla::SetDoCon(string a) {}
void Mathangthuocla::SetCalo(string a) {}
void Mathangthuocla::SetDoRuou(string a) {}
Mathangthuocla* Mathangthuocla::operator=(mathang* a)
{
	Mathangthuocla* k = new Mathangthuocla;
	k->maMh = a->Get_mamh();
	k->tenMh = a->Get_tenmh();
	k->soluongMh = a->Get_soluongmh();
	k->DonGia = a->Get_DonGia();
	k->NgaySanXuat = a->Get_NgaySanXuat();
	k->NgayHetHan = a->Get_NgayHetHan();
	k->nicotin = a->GetNiCoTin();
	return k;
}