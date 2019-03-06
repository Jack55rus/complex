#pragma once

template<typename T> class Comp
{
private:
	T Re;
	T Im;
	
public:
	static int count;
	static int getCount() {
		return count;
	}
	Comp<T>(); //constructor
	~Comp(); // destructor
	Comp<T>(T, T); // for those with both real and imaginary parts
	Comp<T>(T); // for those with only one part
	Comp(Comp const &); // copy constructor
	Comp(Comp &&); // move constructor
	// copy assignment operator and assignment operator are the same thing
	Comp<T>& operator = (const Comp<T>&); // copy assignment operator
	Comp<T>& operator = (Comp<T>&&); // move assignment operator
	Comp<T>& operator +=(const Comp<T>&); // 
	Comp<T>& operator -=(const Comp<T>&);
	Comp<T>& operator *=(const Comp<T>&);
	Comp<T>& operator /=(const Comp<T>&);
	bool operator == (const Comp<T>&);
	Comp<T> operator +(const Comp<T>&) const;
	Comp<T> operator -(const Comp<T>&) const;
	Comp<T> operator *(const Comp<T>&) const;
	Comp<T> operator /(const Comp<T>&) const;
	template<typename U> 
	friend std::ostream& operator <<(std::ostream&, const Comp<U>&);
	template<typename Y>
	friend std::istream& operator >>(std::istream&,  Comp<Y>&);
	T getReal();
	T getImag();
};
