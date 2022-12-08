#ifndef LOAIMATHANG_H
#define LOAIMATHANG_H
#include "Mathangbia.h"
#include "Mathangthuocla.h"
#include "Mathangruou.h"
#include "Mathangnuocngot.h"
#include "MatHangRong.h"
class loaimathang
{
protected:
	string maloaiMh, tenloaiMh;
	vector <mathang*> List_Mh;
public:
	static ifstream filein;
	static ofstream fileout;
	virtual void NhapFile();
	virtual void XuatFile();
	void Nhap();
	void NhapThemMatHang();
	virtual void Xuat();
	int GetSoLuongMatHang();
	string Get_maloaiMh();
	string Get_tenloaiMh();
	void Set_maloaiMh(string);
	void Set_tenloaiMh(string);
	virtual void SetNiCoTin(string);
	virtual void SetDoCon(string);
	virtual void SetDORuou(string);
	virtual void SetCalo(string);
	int NhapThemTuFile(ifstream&);
	void InsertMatHang(int, mathang*);
	void EraseMatHang(int);
	void Max_heapify(int, int);
	void Heapsort(int);
	void SapXepMatHang();
	void SetMatHang(int, mathang*);
	int TimKiemMatHang(string);
	static string Inhoa(string);
	mathang* operator[](int);
};
#endif