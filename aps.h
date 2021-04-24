#include <iostream>
using namespace std;

template <typename T >
class ArrayList{
	T* elements_list ;
	int default_size_list = 10;
	int length_list = 0;
public:
	ArrayList(){
		elements_list = new T[default_size_list];
	}

	int size(){
	    return length_list;
	}

	bool isEmpty(){
		int size_list = size();
		return size_list ;
	}

	void add(T elem){
		int last_index_list = size();
		elements_list[last_index_list] = elem;
		length_list++;
	}

	bool add(T elem, int index){
		int last_index_list = size();
		if(0 > index || index > last_index_list){
			return false;
		}

		elements_list[index] = elem;
		length_list++;
		return true;
	}

	bool remove(T elem){
		int last_index_list = size();

		for(int i = 0; i < last_index_list; i++){
			if(elements_list[i] == elem){
				for (int j =i;j < last_index_list; j++){
							 elements_list[j] = elements_list[j + 1];
						}
				 length_list--;
				 return true;
			}
		}
		return false;
	}

	bool remove(int index){
		int last_index_list = size();
		if(0 > index || index > last_index_list){
			return false;
		}
		for (int i =index;i < last_index_list; ++i){
			 elements_list[i] = elements_list[i + 1];
		}
		length_list--;
		return true;
	}


	void clear(){
		int last_index_list = size();
		for(int i = 0; i < last_index_list; i++){
			delete &elements_list[i];
		}
		length_list = 0;
	}

	T get(int index){
		try{
			int last_index_list = size();
			if(0 > index || index > last_index_list){
				throw ("A lista não aprensenta o indice indicado");
			}
			return elements_list[index];
		}catch (T) {
			"Ocorreu um erro";
		}
	}

	int indexOf(T elem){
		int last_index_list = size();
		for (int i= 0; i< last_index_list; i++){
			if (elements_list[i] == elem){
				return i;
			}
		}
		return -1;
	}

	void print(){
		int last_index_list = size();
		for (int i= 0; i< last_index_list; i++){
			cout <<"Print ->" <<elements_list[i]<< endl;
		}
	}

	~ArrayList(){
		delete elements_list;
	}
};
