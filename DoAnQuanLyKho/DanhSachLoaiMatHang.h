#ifndef DANHSACHLOAIMATHANG_H
#define DANHSACHLOAIMATHANG_H
#include "LinkList.h"
#include "ThuocLa.h"
#include "Bia.h"
#include "Ruou.h"
#include "NuocNgot.h"
class DanhSachLoaiMatHang
{
private:
	LinkList<loaimathang*> list_lmh;
public:
	static ifstream filein;
	static ofstream fileout;
	void NhapFile();
	void XuatFile();
	void InsertLoaiMatHang(loaimathang*);
	void NhapThemTuFile();
	void Xuat();
	void EraseLoaiMatHang(string);
	void SapXepLoaiMatHang();
	void SapXepMatHang(int);
	int TimKiemLoaiMatHang(string);
	loaimathang* operator[](int);
	int GetSoLuongLoaiMatHang();
	int TimKiemMatHang(string, int&);
	void SetLoaiMatHang(int, loaimathang*);
	mathang* SetMatHang(int, int, string);
	void NhapThemMatHangMoiVaoKho(mathang*, int, int&);
	mathang* NhapThemSoLuongMatHangDaCoSan(int, string, int&);
	mathang* XuatKho(string, int&);
	void ThongKe(string, vector<int>&, vector<string>&, int&);
};
#endif