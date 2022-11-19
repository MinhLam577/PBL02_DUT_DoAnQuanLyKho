#ifndef NODE_H
#define NODE_H

template <class T>
class Node
{
private:
	T Data;
	Node* Next;
	Node* Prev;
public:
	Node(T);
	Node<T>*& GetNext();
	Node<T>*& GetPrev();
	T GetData();
	void SetData(T);
};

template <class T>
void Node<T>::SetData(T t)
{
	Data = t;
}

template <class T>
Node<T>::Node(T Value)
{
	Data = Value;
	Next = Prev = nullptr;
}

template <class T>
Node<T>*& Node<T>::GetNext()
{
	return Next;
}

template <class T>
Node<T>*& Node<T>::GetPrev()
{
	return Prev;
}

template <class T>
T Node<T>::GetData()
{
	return Data;
}

#endif

