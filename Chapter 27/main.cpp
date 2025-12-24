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

#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>

class ArrayException : public std::runtime_error
{
public:
	ArrayException(const std::string& error)
		: std::runtime_error{error}
	{
	}
};

class IntArray
{
private:
	int m_data[3]{};

public:
	IntArray() {}
	int getLength() const { return 3; }
	int& operator[](const int index)
	{
		if (index < 0 || index >= getLength())
			throw ArrayException("Invalid index");

		return m_data[index];
	}
};

int main()
{
	IntArray array;

	try
	{
		int value{ array[5] };
	}
	catch (const ArrayException& exception)
	{
		std::cerr << "An array exception occurred (" << exception.what() << ")\n";
	}
	catch (const std::exception& exception)
	{
		std::cerr << "Some other std::exception occurred (" << exception.what() << "\n";
	}

	return 0;
}