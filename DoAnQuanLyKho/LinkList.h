#ifndef LINKLIST_H
#define LINKLIST_H
#include "NODE.h"
#include "loaimathang.h"
template <typename T>
class LinkList
{
private:
	Node<T>* Head, * Tail;
public:
	LinkList();
	Node<T>*& GetHead();
	Node<T>*& GetTail();
	void InsertFirst(Node<T>*);
	void InsertLast(Node<T>*);
	void InsertElement(int, Node<T>*);
	void EraseFirst();
	void EraseLast();
	void EraseElement(int);
	void SwapData(int, int);
	int GetSoluong();
	T operator[](int);
};

template<typename T>
LinkList<T>::LinkList()
{
	Head = Tail = nullptr;
}

template<typename T>
void LinkList<T>::InsertFirst(Node<T>* a)
{
	if (Head == nullptr)
	{
		Head = Tail = a;
	}
	else
	{
		a->GetNext() = Head;
		Head->GetPrev() = a;
		Head = a;
	}
}

template<typename T>
void LinkList<T>::InsertLast(Node<T>* a)
{
	if (Head == nullptr)
	{
		Head = Tail = a;
	}
	else
	{
		Tail->GetNext() = a;
		a->GetPrev() = Tail;
		a->GetNext() = nullptr;
		Tail = a;
	}
}

template <typename T>
Node<T>*& LinkList<T>::GetHead()
{
	return Head;
}

template <typename T>
Node<T>*& LinkList<T>::GetTail()
{
	return Tail;
}

template<typename T>
int LinkList<T>::GetSoluong()
{
	int dem = 0;
	for (Node<T>* a = Head; a != nullptr; a = a->GetNext())
	{
		dem++;
	}
	return dem;
}

template <typename T>
void LinkList<T>::InsertElement(int vitri, Node<T>* a)
{
	if (vitri == 0) InsertFirst(a);
	else if (vitri == GetSoluong() - 1) InsertLast(a);
	else
	{
		Node<loaimathang*>* p = Head;
		while (vitri--) p = p->GetNext();
		Node<loaimathang*>* sau = p->GetNext();
		Node<loaimathang*>* truoc = p->GetPrev();
		truoc->GetNext() = a;
		a->GetPrev() = truoc;
		a->GetNext() = sau;
		sau->GetPrev() = a;
	}
}

template<typename T>
void LinkList<T>::EraseFirst()
{
	if (Head != nullptr)
	{
		Node<T>* a = Head;
		Head = Head->GetNext();
		delete a;
		if (Head != nullptr)
		{
			Head->GetPrev() = nullptr;
		}
	}
}

template<typename T>
void LinkList<T>::EraseLast()
{
	Node<T>* a = Tail;
	(a->GetPrev())->GetNext() = nullptr;
	Tail = a->GetPrev();
	delete a;
}

template <typename T>
void LinkList<T>::EraseElement(int vitri)
{
	Node<loaimathang*>* pos = Head;
	if (vitri == 0)
	{
		EraseFirst();
	}
	else if(vitri == GetSoluong() - 1)
	{
		EraseLast();
	}
	else
	{
		while (vitri--) pos = pos->GetNext();
		Node<loaimathang*>* sau = pos->GetNext();
		Node<loaimathang*>* truoc = pos->GetPrev();
		truoc->GetNext() = sau;
		sau->GetPrev() = truoc;
		delete pos;
		pos = truoc;
	}
}

template<typename T>
void LinkList<T>::SwapData(int node1, int node2)
{
	if (node1 == node2) return;
	int temp1 = node1;
	int temp2 = node2;
	Node<loaimathang*>* p1 = Head;
	while (temp1--) p1 = p1->GetNext();
	Node<loaimathang*>* p2 = Head;
	while (temp2--) p2 = p2->GetNext();
	loaimathang* a = p1->GetData();
	p1->SetData(p2->GetData());
	p2->SetData(a);
}
template<typename T>
T LinkList<T>::operator[](int vitri)
{
	int dem = 0;
	for (Node<T>* a = Head; a != nullptr; a = a->GetNext())
	{
		if (vitri == dem++)
		{
			return a->GetData();
		}
	}
	return Head->GetData();
}
#endif