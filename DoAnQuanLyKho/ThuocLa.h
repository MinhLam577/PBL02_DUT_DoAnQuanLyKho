#ifndef THUOCLA_H
#define THUOCLA_H
#include "loaimathang.h"
class ThuocLa:public loaimathang
{	 
private:
	string nicotin;
public:
	void NhapFile();
	void XuatFile();
	void Xuat();
	void SetNiCoTin(string a);
};
#endif




