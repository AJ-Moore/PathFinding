/*
	Stack Class Declaration
	Dev By Allan Moore 04/2014
	21017984
	Buckinghamshire New University 
*/

#ifndef _STACK 
#define _STACK 

template <class T> 
class Stack{
public:
	Stack(int MaxSize); 
	~Stack(); 
	void push(T Obj); 
	int getCount();
	T pop(); 
	T peek(); 
	bool isEmpty(); 
	bool isFull(); 
private:
	Stack(); 
	int maxSize; 
	T* data; 
	int top; 
};

template <class T> 
Stack<T>::Stack(){
}

template <class T> 
Stack<T>::Stack(int MaxSize){
	this->maxSize = MaxSize; 
	this->data = new T[MaxSize]; 
	top = -1; 
}

template <class T> 
Stack<T>::~Stack(){
	delete this->data; this->data = nullptr; 
}

///Returns the amount of elements in the stack. 
template <class T>
int Stack<T>::getCount(){
	return this->top + 1;
}

template <class T> 
void Stack<T>::push(T Obj){
	if (!this->isFull())
		this->data[++this->top] = Obj;
}

template <class T> 
T Stack<T>::pop(){
	if (!this->isEmpty())
		return this->data[this->top--];
}

template <class T>
T Stack<T>::peek(){
	if (!this->isEmpty())
		return this->data[this->top];
}

template <class T> 
bool Stack<T>::isFull(){
	return (top == this->maxSize -1);
}

template <class T> 
bool Stack<T>::isEmpty(){
	return (top == -1);
}

#endif