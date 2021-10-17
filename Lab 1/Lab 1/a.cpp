#include<iostream>
namespace A
{
	void test()
	{
		std::cout << "Test from library a\n";
	}

	void test1()
	{
		std::cout << "Test 1 from library a\n";
	}

	std::string getOS()
	{
#ifdef _WIN64
        return "Windows 64-bit";
#elif _WIN32
        return "Windows 32-bit";
#elif __APPLE__ || __MACH__
        return "Mac OSX";
#elif __linux__
        return "Linux";
#elif __unix || __unix__
        return "Unix";
#else
        return "Other";
#endif
	}
}