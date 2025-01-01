#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {
	private:
		Node<T>* first;
		int n;

	public:
		ListLinked(){
			first = nullptr;
			n = 0;
		}

		~ListLinked(){
			Node<T>* aux;
			while(first!=nullptr){
				aux = first->next;
				delete first;
				first = aux;
			}
		}
		
		void insert(int pos, T e) override{
			if(pos<0 || pos>n){
				throw std::out_of_range("Posición errónea");
			}

			if(pos == 0){
				first = new Node<T>(e, first);		
			}else{
				Node<T>* prev = first;
				for(int i = 0; i < pos-1; ++i){
					prev = prev->next;
				}
				prev->next = new Node<T>(e, prev->next);
			}
			++n;
		}

		void append(T e) override{
			insert(n, e);
		}

		void prepend(T e) override{
			insert(0, e);
		}

		T remove(int pos) override{
			if(pos<0 || pos>=n){
				throw std::out_of_range("Posición errónea");
			}

			Node<T>* objetivo;
			T elemento_eliminado;
			if(pos==0){
				objetivo = first;
				first = first->next;
			}else{
				Node<T>* prev = first;
				for(int i = 0; i < pos-1; ++i){
					prev = prev->next;
				}
				objetivo = prev->next;
				prev->next = objetivo->next;
			}

			elemento_eliminado = objetivo->data;
			delete objetivo;
			--n;

			return elemento_eliminado;
		}

		T get(int pos) override{
			if(pos<0 || pos>=n){
				throw std::out_of_range("Posición errónea");
			}

			Node<T>* current = first;
			for(int i=0; i<pos; ++i){
				current = current->next;
			}

			return current->data;
		}

		int search(T e) override{
			Node<T>* current = first;
			int pos = 0;

			while(current != nullptr){
				if(current->data == e){
					return pos;
				}
				current = current->next;
				++pos;
			}

			return -1;
		}

		bool empty() override{
			return n==0;
		}

		int size() override{
			return n;
		}

		T operator[](int pos){
			return get(pos);
		}

		friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
			Node<T>* current = list.first;
			out << "ListLinked -> [";

			while(current != nullptr){
				out << current->data;
				if(current->next != nullptr){
					out << ", ";
				}
				current = current->next;
			}

			out << "]";
			return out;
		}
};




