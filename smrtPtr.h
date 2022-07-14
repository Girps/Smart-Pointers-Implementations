#ifndef SMRT_H

#define SMRT_H



// Template class Handles single data values 
template<typename T>
class SmartPointer
{
	T* ptr; 
	public:
		SmartPointer(T* ptrArg)
			:ptr{ ptrArg }
		{
		}

		~SmartPointer()
		{
			delete ptr;
			ptr = nullptr;
		}

		T* release()
		{
			T* lcl = this->ptr;
			this->ptr = nullptr;
			return lcl;
		}

		T friend operator * (const SmartPointer<T>& Arg)
		{
			return *(Arg.ptr);
		}
		
		T* operator ->() 
		{
			return ptr; 
		}

};

/*Template specialization taking an array of T types */
template<typename T>
class SmartPointer<T []>
{
	T* ptr;
public:
	SmartPointer(T* ptrArg)
		:ptr{ ptrArg }
	{
	}

	~SmartPointer()
	{
		delete[] ptr;
		ptr = nullptr;
	}

	T* release()
	{
		T* lcl = this->ptr;
		this->ptr = nullptr;
		return lcl;
	}

	T friend operator * (const SmartPointer<T[]> & Arg)
	{
		return *(Arg.ptr);
	}

	T& operator [] (int index) 
	{
		return *(this->ptr + index);
	}

	T operator [] (int index) const 
	{
		return *(this->ptr + index);
	}
};

#endif