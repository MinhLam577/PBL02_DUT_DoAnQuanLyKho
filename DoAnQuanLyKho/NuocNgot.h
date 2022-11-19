#pragma once
#include "loaimathang.h"
class NuocNgot:public loaimathang
{
private:
	string Calories;
public:
	void NhapFile();
	void XuatFile();
	void Xuat();
	void SetCalo(string);
};

