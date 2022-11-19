#pragma once
#include "mathang.h"
class Mathangthuocla:public mathang
{
private:
	string nicotin;
public:
	void Nhapfile();
	void Xuatfile();
	void Nhap();
	void Xuat();
	string GetNiCoTin();
	string GetDoCon();
	string GetDoRuou();
	string GetCalories();
	void SetNiCoTin(string);
	void SetDoCon(string);
	void SetCalo(string);
	void SetDoRuou(string);
	Mathangthuocla* operator=(mathang* a);
};

