#include <iostream>
#include <cstdlib>
#include <unistd.h>

#define STACKSIZE 100
#define RET_ERR 1
#define RET_NRML 0

typedef int dt_STACK;

// Class Declaration
template<class T>
class Stack{
	private:
		dt_STACK top;
		T data[STACKSIZE];
	public:
		// Constructor
		Stack();
		Stack(T value);
		void push(T value);
		void pop();
		void onTop();
		void size();
		static bool isEmpty(dt_STACK top_val);
		static bool isFull(dt_STACK top_val);
};

int main(){
	int c1,c2,temp;
	Stack<int> s;
	do{
	std::cout << "===========================" << std::endl
			  << "\tSTACK" << std::endl
			  << "===========================" << std::endl
			  << "1. Push" << std::endl
			  << "2. Pop" << std::endl
			  << "3. Top value in stack" << std::endl
			  << "4. Size of stack" << std::endl
			  << "5. Exit" << std::endl
			  << "============================" << std::endl
			  << "Enter your choice: " ;
	std::cin >> c1;
	switch(c1){
		case 1:
			std::cout << "Enter value which you want to push: ";
			std::cin >> temp;
			s.push(temp);
			sleep(1);
			break;
		case 2:
			s.pop();
			sleep(1);
			break; 
		case 3:
			s.onTop();
			sleep(1);
			break;
		case 4:
			s.size();
			sleep(1);
			break;
		case 5:
			system("clear");
			std::cout << "Exiting the program..." << std::endl;
			sleep(3);
			system("clear");
			exit(1);
		break;
		
		default: 
			std::cerr << ">>\tInvalid Choice" << std::endl;
			sleep(1);
			continue;
	}
	}
	while(c1!=-1);
	return RET_NRML;
}

// Class Initialization

template<class T>
Stack<T>::Stack(){
	top = -1;
}
template<class T>
Stack<T>::Stack(T value){
	top = -1;
	top++;
	data[top] = value;
}
template<class T>
void Stack<T>::push(T value){
	if(isFull(top)){
		std::cerr << ">>\tSTACK OVERFLOW" << std::endl;
		return;
	}
	data[++top] = value;	
	std::cout << ">>\tRecently PUSHED value is " << value << std::endl;
}

template<class T>
void Stack<T>::pop	(){
		if(isEmpty(top)){
		std::cerr << ">>\tSTACK UNDERFLOW" << std::endl;
		return;
	}
	T temp = data[top--];
	std::cout << ">>\tRecently POPPED value is " << temp << std::endl;
}

template<class T>
void Stack<T>::onTop(){
	std::cout << ">>\tTopmost value in stack is " << data[top] << std::endl;
}

template<class T>
void Stack<T>::size(){
	int temp = top;
	std::cout << ">>\tSize of stack is " << ++temp << std::endl;
}
template<class T>
bool Stack<T>::isEmpty(dt_STACK top_val){
	return(top_val == -1);
}

template<class T>
bool Stack<T>::isFull(dt_STACK top_val){
	return(top_val == STACKSIZE - 1);
}

