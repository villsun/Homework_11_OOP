#include <iostream>
#include <string>

using namespace std;

namespace exce
{
	class Exception
	{
	private:
		string message;
	public:
		Exception(string message)
		{
			this->message = message;
		}

		const string& what() const
		{
			return message;
		}
	};
}


namespace calc
{
	template <typename T_1, typename T_2>
	class Calculator
	{
	private:
		T_1 number_1;
		T_2 number_2;
	public:
		Calculator(T_1 number_1 = 0, T_2 number_2 = 0)
		{
			this->number_1 = number_1;
			this->number_2 = number_2;
		}
		T_1 Addition()
		{
			if (number_1 == 0 || number_2 == 0)
			{
				throw exce::Exception("And for what?");
			}

			return number_1 + number_2;
		}

		T_2 Multiplication()
		{
			if (number_1 == 1 || number_2 == 1)
			{
				throw exce::Exception("And for what?");
			}
			return number_1 * number_2;
		}
		T_1 Subtraction()
		{
			if (number_1 == 0 || number_2 == 0)
			{
				throw exce::Exception("And for what?");
			}

			return number_1 - number_2;
		}
		double Division()
		{
			if (number_2 == 0)
			{
				throw exce::Exception("You can't do that!");
			}
			return number_1 / 1.0 / number_2;
		}
	};
}


int main()
{
	calc::Calculator<int, double> calculator_1(10, 0);
	try
	{
		cout << calculator_1.Division() << endl;
	}
	catch (const exce::Exception& exception)
	{
		cout << exception.what() << endl;
	}

	return 0;
}