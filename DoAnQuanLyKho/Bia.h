#pragma once
#include "loaimathang.h"
class Bia:public loaimathang
{
private:
	string nongdocon;
public:
	void NhapFile();
	void XuatFile();
	void Xuat();
	void SetDoCon(string);
};

