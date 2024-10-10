#ifndef LIST_H
#define LIST_H

template <typename T> 
class List {
	public:
		virtual void insert(int pos, T e) = 0;
		virtual void append(T e) = 0;
		virtual void prepend(T e) = 0;

		T remove(int pos);
		T get(int pos);
		int search(T e);
		bool empty();
		int size();

};

#endif


