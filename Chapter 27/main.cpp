//#include <cmath>
//#include <iostream>
//
//double mySqrt(double x)
//{
//	if (x < 0.0)
//		throw "Can not take sqrt of negative number";
//
//	return std::sqrt(x);
//}
//
//int main()
//{
//	std::cout << "Enter a number: ";
//	double x{};
//	std::cin >> x;
//
//	try
//	{
//		double d = mySqrt(x);
//		std::cout << "The sqrt of " << x << " is " << d << '\n';
//	}
//	catch (const char* exception)
//	{
//		std::cerr << "Error: " << exception << std::endl;
//	}
//
//	return 0;
//}

//#include <iostream>
//
//struct GameSession
//{
//	// Game session data here
//};
//
//void runGame(GameSession&)
//{
//	throw 1;
//}
//
//void saveGame(GameSession&)
//{
//	// Save user's game here
//}
//
//int main()
//{
//	GameSession session{};
//
//	try
//	{
//		runGame(session);
//	}
//	catch (...)
//	{
//		std::cerr << "Abnormal termination\n";
//	}
//
//	saveGame(session);
//
//	return 0;
//}

//#include <iostream>
//
//struct GameSession
//{
//	// Game Session data here
//};
//
//void runGame(GameSession&)
//{
//	throw 1;
//}
//
//void saveGame(GameSession&)
//{
//
//}
//
//class DummyException
//{
//	DummyException() = delete;
//};
//
//int main()
//{
//	GameSession session{};
//
//	try
//	{
//		runGame(session);
//	}
//#ifndef NDEBUG
//	catch (...)
//	{
//		std::cerr << "Abnormal termination\n";
//	}
//#else
//	catch (DummyException)
//	{
//	}
//#endif
//
//	saveGame(session);
//
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <string_view>
//
//class ArrayException
//{
//private:
//	std::string m_error;
//
//public:
//	ArrayException(std::string_view error)
//		: m_error{ error }
//	{
//	}
//
//	const std::string& getError() const { return m_error; }
//};
//
//class IntArray
//{
//private:
//	int m_data[3]{};
//
//public:
//	IntArray() {};
//
//	int getLength() const { return 3; }
//
//	int& operator[](const int index)
//	{
//		if (index < 0 || index >= getLength())
//			throw ArrayException{ "Invalid index" };
//
//		return m_data[index];
//	}
//};
//
//int main()
//{
//	IntArray array;
//
//	try
//	{
//		int value{ array[5] };
//	}
//	catch (const ArrayException& exception)
//	{
//		std::cerr << "An array exception occurred (" << exception.getError() << ")\n";
//	}
//}

//#include <iostream>
//
//class Base
//{
//public:
//	Base() {}
//};
//
//class Derived : public Base
//{
//public:
//	Derived() {}
//};
//
//int main()
//{
//	try
//	{
//		throw Base();
//	}
//	catch (const Derived& derived)
//	{
//		std::cerr << "caught Derived";
//	}
//	catch (const Base& base)
//	{
//		std::cerr << "caught Base";
//	}
//
//	return 0;
//}

//#include <cstddef>
//#include <exception>
//#include <iostream>
//#include <limits>
//#include <string>
//
//int main()
//{
//	try
//	{
//		std::string s;
//		s.resize(std::numeric_limits<std::size_t>::max());
//	}
//	catch (const std::exception& exception)
//	{
//		std::cerr << "Standard exception: " << exception.what() << '\n';
//	}
//
//	return 0; 
//}

//#include <exception> // for std::exception
//#include <iostream>
//#include <string>
//#include <string_view>
//
//class ArrayException : public std::exception
//{
//private:
//	std::string m_error{}; // handle our own string
//
//public:
//	ArrayException(std::string_view error)
//		: m_error{ error }
//	{
//	}
//
//	// std::exception::what() returns a const char*, so we must as well
//	const char* what() const noexcept override { return m_error.c_str(); }
//};
//
//class IntArray
//{
//private:
//	int m_data[3]{}; // assume array is length 3 for simplicity
//
//public:
//	IntArray() {}
//
//	int getLength() const { return 3; }
//
//	int& operator[](const int index)
//	{
//		if (index < 0 || index >= getLength())
//			throw ArrayException("Invalid index");
//
//		return m_data[index];
//	}
//
//};
//
//int main()
//{
//	IntArray array;
//
//	try
//	{
//		int value{ array[5] };
//	}
//	catch (const ArrayException& exception) // derived catch blocks go first
//	{
//		std::cerr << "An array exception occurred (" << exception.what() << ")\n";
//	}
//	catch (const std::exception& exception)
//	{
//		std::cerr << "Some other std::exception occurred (" << exception.what() << ")\n";
//	}
//}

//#include <exception>
//#include <iostream>
//#include <stdexcept>
//#include <string>
//
//class ArrayException : public std::runtime_error
//{
//public:
//	ArrayException(const std::string& error)
//		: std::runtime_error{error}
//	{
//	}
//};
//
//class IntArray
//{
//private:
//	int m_data[3]{};
//
//public:
//	IntArray() {}
//	int getLength() const { return 3; }
//	int& operator[](const int index)
//	{
//		if (index < 0 || index >= getLength())
//			throw ArrayException("Invalid index");
//
//		return m_data[index];
//	}
//};
//
//int main()
//{
//	IntArray array;
//
//	try
//	{
//		int value{ array[5] };
//	}
//	catch (const ArrayException& exception)
//	{
//		std::cerr << "An array exception occurred (" << exception.what() << ")\n";
//	}
//	catch (const std::exception& exception)
//	{
//		std::cerr << "Some other std::exception occurred (" << exception.what() << "\n";
//	}
//
//	return 0;
//}

//#include <iostream>
//class Base
//{
//public:
//	Base() {}
//	virtual void print() { std::cout << "Base"; }
//};
//
//class Derived : public Base
//{
//public:
//	Derived() {}
//	void print() override { std::cout << "Derived"; }
//};
//
//int main()
//{
//	try
//	{
//		try
//		{
//			throw Derived{};
//		}
//		catch (Base& b)
//		{
//			std::cout << "Caught Base b, which is actually a ";
//			b.print();
//			std::cout << '\n';
//			throw;
//		}
//	}
//	catch (Base& b)
//	{
//		std::cout << "Caught Base b, which is actually a ";
//		b.print();
//		std::cout << '\n';
//	}
//
//	return 0;
//}

//#include <iostream>
//
//class A
//{
//private:
//	int m_x;
//public:
//	A(int x) : m_x{ x }
//	{
//		if (x <= 0)
//			throw 1;
//	}
//};
//
//class B : public A
//{
//public:
//	B(int x) try : A{ x }
//	{
//	}
//	catch (...)
//	{
//		std::cerr << "Execution caught\n";
//
//		throw;
//	}
//};
//
//int main()
//{
//	try
//	{
//		B b{ 0 };
//	}
//	catch (int)
//	{
//		std::cout << "Oops\n";
//	}
//
//	return 0;
//}

// h/t to reader yellowEmu for the first draft of this program
//#include <iostream>
//
//class Doomed
//{
//public:
//    ~Doomed()
//    {
//        std::cout << "Doomed destructed\n";
//    }
//};
//
//void thrower()
//{
//    std::cout << "Throwing exception\n";
//    throw 1;
//}
//
//void pt()
//{
//    std::cout << "pt (potentally throwing) called\n";
//    //This object will be destroyed during stack unwinding (if it occurs)
//    Doomed doomed{};
//    thrower();
//    std::cout << "This never prints\n";
//}
//
//void nt() noexcept
//{
//    std::cout << "nt (noexcept) called\n";
//    //This object will be destroyed during stack unwinding (if it occurs)
//    Doomed doomed{};
//    thrower();
//    std::cout << "this never prints\n";
//}
//
//void tester(int c) noexcept
//{
//    std::cout << "tester (noexcept) case " << c << " called\n";
//    try
//    {
//        (c == 1) ? pt() : nt();
//    }
//    catch (...)
//    {
//        std::cout << "tester caught exception\n";
//    }
//}
//
//int main()
//{
//    std::cout << std::unitbuf; // flush buffer after each insertion
//    std::cout << std::boolalpha; // print boolean as true/false
//    tester(1);
//    std::cout << "Test successful\n\n";
//    tester(2);
//    std::cout << "Test successful\n";
//
//    return 0;
//}

#include <iostream>
#include <utility>
#include <stdexcept> 

class MoveClass
{
private:
    int* m_resource{};

public:
    MoveClass() = default;

    MoveClass(int resource)
        : m_resource{ new int{ resource } }
    {
    }

    MoveClass(const MoveClass& that)
    {

        if (that.m_resource != nullptr)
        {
            m_resource = new int{ *that.m_resource };
        }
    }

    MoveClass(MoveClass&& that) noexcept
        : m_resource{ that.m_resource }
    {
        that.m_resource = nullptr;
    }

    ~MoveClass()
    {
        std::cout << "destroying " << *this << '\n';

        delete m_resource;
    }

    friend std::ostream& operator<<(std::ostream& out, const MoveClass& moveClass)
    {
        out << "MoveClass(";

        if (moveClass.m_resource == nullptr)
        {
            out << "empty";
        }
        else
        {
            out << *moveClass.m_resource;
        }

        out << ')';

        return out;
    }
};


class CopyClass
{
public:
    bool m_throw{};

    CopyClass() = default;

    CopyClass(const CopyClass& that)
        : m_throw{ that.m_throw }
    {
        if (m_throw)
        {
            throw std::runtime_error{ "abort!" };
        }
    }
};

int main()
{
    std::pair my_pair{ CopyClass{}, MoveClass{13} };

    std::cout << "my_pair.second: " << my_pair.second << '\n';

    try
    {
        my_pair.first.m_throw = true;

        std::pair moved_pair{ std::move(my_pair) };

        std::cout << "moved pair exists\n";
    }
    catch (const std::exception& ex)
    {
        std::cerr << "Error found: " << ex.what() << '\n';
    }

    std::cout << "my_pair.second: " << my_pair.second << '\n';

    return 0;
}
