#include "NuocNgot.h"
void NuocNgot::NhapFile()
{
	loaimathang::NhapFile();
	loaimathang::filein >> Calories;
}
void NuocNgot::XuatFile()
{
	loaimathang::fileout.open("DanhSachLoaiMatHang.txt", ios_base::app);
	loaimathang::fileout << tenloaiMh << "\n";
	loaimathang::fileout.close();
	loaimathang::fileout.open("loaimathang.txt", ios_base::app);
	loaimathang::fileout << maloaiMh << setw(20) << tenloaiMh << setw(20) << Calories << "\n";
	loaimathang::fileout.close();
	loaimathang::XuatFile();
}
void NuocNgot::Xuat()
{
	cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\tMa loai mat hang: " << maloaiMh << "\n";
	cout << "\n\t\t\t\t\t\t\t\t\t\t\tTen loai mat hang: " << tenloaiMh << "\n";
	cout << "\n\t\t\t\t\t\t\t\t\t\t\tCalo trung binh: " << Calories << "\n";
	cout << "\n\t\t\t\t\t\t\t\t\t\t\tTen cac loai mat hang " << tenloaiMh << "\n\n\n";
	ConsoleTable table{ "Id", "TenMatHang", "SoLuong", "DonGia" , "NgaySanXuat", "NgayHetHan", "Calo"};
	for (int i = 0; i < List_Mh.size(); i++)
	{
		mathang* x = List_Mh[i];
		table += {x->Get_mamh(), x->Get_tenmh(), x->Get_soluongmh(), x->Get_DonGia(), x->Get_NgaySanXuat(), x->Get_NgayHetHan(), x->GetCalories()};
	}
	table.setPadding(10);
	cout << table;
}
void NuocNgot::SetCalo(string a) { Calories = a; }