#include <ostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {
	    private:
		    T* arr;
		    int max;
		    int n;
		    static const int MINSIZE = 2;
		    void resize(int new_size){
			    T* new_arr = new T[new_size];
			    for (int i = 0; i < n; i++){
				    new_arr[i] = arr[i];
			    }
			    delete[] arr;
			    arr = new_arr;
			    max = new_size;
		    }
			    
	
	    public:
		    ListArray(){
			    arr = new T[MINSIZE];
			    max = MINSIZE;
			    n = 0;
		    }

		    ~ListArray(){
			    delete[] arr;
		    }

		    void insert(int pos, T e) override{
			    if(pos<0 || pos>n){
				    throw std::out_of_range("Invalid position");
			    }

			    if(n==max){
				    resize(max*2);
			    }

			    for(int i=n; i>pos; --i){
				    arr[i] = arr[i-1];
			    }

			    arr[pos] = e;
			    ++n;
		    }


		    T operator[](int pos){
		    }
		    friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list);
 };

