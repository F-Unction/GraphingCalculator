/*
	  <GraphingCalculator. A software for drawing function image.>
	Copyright (C) 2020  F_Unction

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <string>
#include <set>
#include <vector>
#include <deque>
#include <stack>
#include <sstream>
#include <algorithm>

#include <cmath>
#include <random> 
#include <functional>

//useful numbers in math
#define M_E        2.71828182845904523536   // e
#define M_LOG2E    1.44269504088896340736   // log2(e)
#define M_LOG10E   0.434294481903251827651  // log10(e)
#define M_LN2      0.693147180559945309417  // ln(2)
#define M_LN10     2.30258509299404568402   // ln(10)
#define M_PI       3.14159265358979323846   // pi
#define M_PI_2     1.57079632679489661923   // pi/2
#define M_PI_4     0.785398163397448309616  // pi/4
#define M_1_PI     0.318309886183790671538  // 1/pi
#define M_2_PI     0.636619772367581343076  // 2/pi
#define M_2_SQRTPI 1.12837916709551257390   // 2/sqrt(pi)
#define M_SQRT2    1.41421356237309504880   // sqrt(2)
#define M_SQRT1_2  0.707106781186547524401  // 1/sqrt(2)

using namespace std;

struct expVarSettings //变量属性
{
	string exp;//变量名
	double value;//值

	expVarSettings(const string& iName, double iValue) \
		:exp(iName), value(iValue) {}

};

const vector<expVarSettings> expVarSet = { \
expVarSettings("PI",M_PI),\
expVarSettings("E", M_E),\
};


enum expOperators :short //运算符种类
{
	lbracket = 1/*左括号*/, rbracket/*右括号*/, plus, minus, times, divided, power, mod
};

struct expOperatorSettings //运算符属性
{
	expOperators opr;
	short priority;//优先级
	string exp;//字符串表示
	std::function<double(double, double)> func;//调用的函数

	expOperatorSettings(expOperators iOpr, short iPriority, const string& iExp, std::function<double(double, double)> iFunc) \
		:opr(iOpr), priority(iPriority), exp(iExp), func(iFunc) {}
	expOperatorSettings(expOperators iOpr, short iPriority, const string& iExp) :opr(iOpr), priority(iPriority), exp(iExp)
	{
	}
	expOperatorSettings(expOperators iOpr) :opr(iOpr)
	{
	}

	bool operator==(const expOperatorSettings& rhs) const
	{
		return opr == rhs.opr;
	}
	bool operator<(const expOperatorSettings& rhs) const
	{
		return opr < rhs.opr;
	}

};

/*
运算符优先级
  0 ( 左括号 //排除
  0 ) 右括号 //排除
- 1   函数
- 2 ^ 幂运算
- 3 * 乘
- 3 / 除
- 3 % 取余
- 4 + 加
- 4 - 减
- 5 < 小于
- 5 <= 小于等于
- 5 > 大于
- 5 >= 大于等于
- 6 == 等于
- 6 != 不等于
- 7 && 逻辑与
- 8 || 逻辑或
*/

const set<expOperatorSettings> expOprSet = { \
expOperatorSettings(expOperators::lbracket, 0, "("), \
expOperatorSettings(expOperators::rbracket, 0, ")"), \
expOperatorSettings(expOperators::times, -3, "*", [](double x, double y)
 {
return x * y;
}), \
expOperatorSettings(expOperators::divided, -3, "/", [](double x, double y)
 {
return x / y;
}), \
expOperatorSettings(expOperators::plus,-4,"+", [](double x, double y)
 {
return x + y;
}),\
expOperatorSettings(expOperators::minus, -4, "-", [](double x, double y)
 {
return x - y;
}), \
expOperatorSettings(expOperators::power, -2, "^", [](double x, double y)
 {
return std::pow(x,y);
}), \
expOperatorSettings(expOperators::mod, -3, "%", [](double x, double y)
 {
return double(int(x) % int(y));
}), \
};

typedef unsigned long expFunctionId;
struct expFunctionSettings //函数属性
{
	static expFunctionId allocator;

	const expFunctionId id;//自动分配id
	string exp;//函数名
	size_t argCount;//参数个数
	std::function <double(deque<double>&)> func;//调用的函数

	expFunctionSettings(const string& iName, size_t iArgCount, std::function<double(deque<double>&)> iFunc) \
		:id(++allocator), exp(iName), argCount(iArgCount), func(iFunc) {}
	expFunctionSettings(const expFunctionId iId) : id(iId)
	{
	}

	bool operator==(const expFunctionSettings& rhs) const
	{
		return id == rhs.id;
	}
	bool operator<(const expFunctionSettings& rhs) const
	{
		return id < rhs.id;
	}

};
expFunctionId expFunctionSettings::allocator = 0;

//FunctionsInit{
	/*Random Init*/
random_device randSeed;
default_random_engine randEngine(randSeed());
//}
const set<expFunctionSettings> expFuncSet = { \
//正弦函数
expFunctionSettings("sin", 1, [](deque<double>& args)
 {
return sin(args[0]);
}),\
//余弦函数
expFunctionSettings("cos", 1, [](deque<double>& args)
 {
return cos(args[0]);
}),\
//正切函数
expFunctionSettings("tan", 1, [](deque<double>& args)
 {
return tan(args[0]);
}),\
//反正弦函数，结果介于[-PI/2,PI/2]
expFunctionSettings("arcsin", 1, [](deque<double>& args)
 {
return asin(args[0]);
}), \
//反余弦函数，结果介于[0,PI]
expFunctionSettings("arccos", 1, [](deque<double>& args)
 {
return acos(args[0]);
}), \
//反正切函数（主值），结果介于[-PI/2,PI/2]
expFunctionSettings("arctan", 1, [](deque<double>& args)
 {
return atan(args[0]);
}), \
//以10为底的对数函数
expFunctionSettings("lg", 1, [](deque<double>& args)
 {
return log10(args[0]);
}), \
//自然对数函数
expFunctionSettings("ln", 1, [](deque<double>& args)
 {
return log(args[0]);
}), \
//对数函数,arg[0]为真数，arg[1]为底数
expFunctionSettings("log", 2, [](deque<double>& args)
 {
return log(args[0]) / log(args[1]);
}), \
//绝对值函数
expFunctionSettings("abs", 1, [](deque<double>& args)
 {
return abs(args[0]);
}), \
//高斯函数,返回不比x大的最大整数
expFunctionSettings("int", 1, [](deque<double>& args)
 {
return floor(args[0]);
}), \
//开平方函数
expFunctionSettings("sqrt", 1, [](deque<double>& args)
 {
return sqrt(args[0]);
}), \
//返回[arg[0],arg[1])中的整数随机值  !!不要忘记srand()
expFunctionSettings("rand", 2, [](deque<double>& args)->double
 {
\
  uniform_int_distribution <> randRange(args[0],args[1]); return double(randRange(randEngine));
}), \
};


enum expType :char
{
	num = 1, opr, func
};

class expUnit //算数表达式，波兰或逆波兰表达式中的一个基本单位
{
private:
	expType type;

	union expValue
	{
		double num; expOperators opr; expFunctionId func;
	};
	expValue value;

public:
	expUnit(double iNum) :type(num)
	{
		value.num = iNum;
	}
	expUnit(expOperators iOpr) :type(opr)
	{
		value.opr = iOpr;
	}
	expUnit(expFunctionId iFunc) :type(func)
	{
		value.func = iFunc;
	}

	void set(double iNum)
	{
		type = num; value.num = iNum;
	}
	void set(expOperators iOpr)
	{
		type = opr; value.opr = iOpr;
	}
	void set(expFunctionId iFunc)
	{
		type = func; value.func = iFunc;
	}

	expType getType() const
	{
		return type;
	}
	expValue getValue() const
	{
		return value;
	}
};

/*从字符串的某个位置开始尝试取出数字，若取出则把位置变更到数字之后，返回是否取出
!!需保证（stringstream&）stream已经被赋予(string::iterator&)pos所指向的字符串(string&)exp
*/
bool expGetNumber(stringstream& stream, string& exp, string::iterator& pos, expUnit& output)
{
	if (*pos >= '0' && *pos <= '9')
	{
		stream.seekg(distance(exp.begin(), pos));

		double tmpNum;
		stream >> tmpNum;
		streampos spos;
		if ((spos = stream.tellg()) != (streampos)(-1))
			pos = exp.begin() + spos;
		else pos = exp.end();
		output.set(tmpNum);

		return true;
	}
	else return false;
}

/*为expGetOperator()和expGetFunction()服务，匹配表达式中的运算符或函数
!!匹配算法为非贪心算法，此时多字符运算符可能被屏蔽无法匹配
*/
template<class T>
class expMatch
{
	const string& expr;
	const string::iterator pos;
public:
	expMatch(const string& iExpr, const string::iterator& iPos) :expr(iExpr), pos(iPos)
	{
	}
	bool operator()(const T& lhs)
	{
		string::const_iterator lhsPos = lhs.exp.begin();

		for (string::const_iterator tmpPos = pos; tmpPos != expr.end() && lhsPos != lhs.exp.end(); ++tmpPos, ++lhsPos)
		{
			if (*tmpPos != *lhsPos)break;
		}
		return lhsPos == lhs.exp.end();
	}
};

//从字符串的某个位置开始尝试取出运算符，若取出则把位置变更到运算符之后，返回是否取出
bool expGetOperator(string& exp, string::iterator& pos, expUnit& output)
{
	auto foundPos = find_if(expOprSet.begin(), expOprSet.end(), expMatch<expOperatorSettings>(exp, pos));
	if (foundPos != expOprSet.end())
	{
		pos += foundPos->exp.size();
		output.set(foundPos->opr);

		return true;
	}
	else return false;
}

//从字符串的某个位置开始尝试取出函数名，若取出则把位置变更到函数名之后，返回是否取出
bool expGetFunction(string& exp, string::iterator& pos, expUnit& output)
{
	auto foundPos = find_if(expFuncSet.begin(), expFuncSet.end(), expMatch<expFunctionSettings>(exp, pos));
	if (foundPos != expFuncSet.end())
	{
		pos += foundPos->exp.size();
		output.set(foundPos->id);

		return true;
	}
	else return false;
}

//从字符串的某个位置开始尝试取出变量名，若取出则把位置变更到变量名之后，返回是否取出
bool expGetVar(string& exp, string::iterator& pos, expUnit& output)
{
	auto foundPos = find_if(expVarSet.begin(), expVarSet.end(), expMatch<expVarSettings>(exp, pos));
	if (foundPos != expVarSet.end())
	{
		pos += foundPos->exp.size();
		output.set(foundPos->value);//被读入后，变量被当作数处理

		return true;
	}
	else return false;
}

//忽略表达式中的空格或其他可以忽略的字符组
bool expGetSpace(string& exp, string::iterator& pos)
{
	size_t i;
	for (i = 0; pos != exp.end() && (*pos == ' ' || *pos == ','); ++pos, ++i);
	return i > 0;
}


//输入算术表达式（字符串），检查正确性，并生成算术表达式（结构数组）,返回完成状态
bool expStrToN(string& input, vector<expUnit>& output)
{
	stringstream numStream(input);
	string::iterator nowPos = input.begin();
	expUnit tmpUnit(0.0);
	int bracketCount = 0; //括号计数器，遇左括号加一，遇右括号减一

	while (nowPos != input.end())
	{
		if (expGetSpace(input, nowPos));
		else if (expGetNumber(numStream, input, nowPos, tmpUnit))
		{
			output.push_back(tmpUnit);
		}
		else if (expGetVar(input, nowPos, tmpUnit))
		{
			output.push_back(tmpUnit);
		}
		else if (expGetOperator(input, nowPos, tmpUnit))
		{
			if (!output.empty())
			{
				vector<expUnit>::iterator oLastUnit = output.end() - 1;
				if (oLastUnit->getType() == expType::opr)
				{
					if (oLastUnit->getValue().opr != expOperators::lbracket && \
						oLastUnit->getValue().opr != expOperators::rbracket && \
						tmpUnit.getValue().opr != expOperators::lbracket && \
						tmpUnit.getValue().opr != expOperators::rbracket)
						return false; //运算符（除左右括号）不相邻检查失败
				}
				else if (oLastUnit->getType() == expType::func)
				{
					if (tmpUnit.getValue().opr != expOperators::lbracket && \
						tmpUnit.getValue().opr != expOperators::rbracket)
						return false;//运算符（除左右括号）前不能临有函数
				}
			}
			output.push_back(tmpUnit);
			if (tmpUnit.getValue().opr == expOperators::lbracket)bracketCount += 1;
			else if (tmpUnit.getValue().opr == expOperators::rbracket)bracketCount -= 1;
		}
		else if (expGetFunction(input, nowPos, tmpUnit))
		{
			if (!output.empty())
			{
				vector<expUnit>::iterator oLastUnit = output.end() - 1;
				if (oLastUnit->getType() == expType::num || oLastUnit->getType() == expType::func)
					return false;//函数前不能临有数字或函数
			}
			output.push_back(tmpUnit);
		}
		else return false;
	}


	if (bracketCount != 0) return false; //括号合理性检查失败

	return true;
}

//为expNToRPN()服务。堆栈中运算符或函数的处理
void expNToRPN_OprOrFuncPorc(vector<expUnit>::iterator& iUnit, short nowPriority, \
	stack<expUnit, vector<expUnit>>& unitStack, vector<expUnit>& output)
{
	short topPriority = 0;
	if (unitStack.empty())
		unitStack.push(*iUnit);
	else
	{
		if (unitStack.top().getType() == expType::func)topPriority = -1;
		else topPriority = expOprSet.find(unitStack.top().getValue().opr)->priority;
		if ((unitStack.top().getType() == expType::opr && unitStack.top().getValue().opr == lbracket)\
			|| nowPriority > topPriority)
			unitStack.push(*iUnit);
		else
		{
			output.push_back(unitStack.top());
			unitStack.pop();
			unitStack.push(*iUnit);
		}
	}
}

//输入算术表达式（结构数组），生成逆波兰表达式（结构数组）,返回完成状态
bool expNToRPN(vector<expUnit>& input, vector<expUnit>& output)
{
	stack<expUnit, vector<expUnit>> unitStack;

	for (auto iUnit = input.begin(); iUnit != input.end(); ++iUnit)
	{
		switch (iUnit->getType())
		{
		case expType::num:
			output.push_back(*iUnit);
			break;
		case expType::opr:
			switch (iUnit->getValue().opr)
			{
			case expOperators::lbracket:
				unitStack.push(*iUnit);
				break;
			case expOperators::rbracket:
				while (unitStack.top().getValue().opr != expOperators::lbracket)
				{
					output.push_back(unitStack.top());
					unitStack.pop();
				}
				unitStack.pop();
				break;
			default://除左右括号外的运算符
				short nowPriority = expOprSet.find(iUnit->getValue().opr)->priority;
				expNToRPN_OprOrFuncPorc(iUnit, nowPriority, unitStack, output);
				break;
			}
			break;
		case expType::func:
			//函数优先级设为-1
			expNToRPN_OprOrFuncPorc(iUnit, -1, unitStack, output);
			break;
		default:
			return false;
			break;
		}
	}
	while (!unitStack.empty())
	{
		output.push_back(unitStack.top());
		unitStack.pop();
	}
	return true;
}

//输入逆波兰表达式（结构数组），计算结果，返回完成状态
bool expRPNToResult(vector<expUnit>& input, double& output)
{
	stack<expUnit, vector<expUnit>> unitStack;

	std::function<double(double, double)> oprFunc;
	double lhs, rhs;

	set<expFunctionSettings>::iterator iFuncSettings;
	std::function<double(deque<double>&)> iFuncCall;
	size_t iArgCount;
	deque<double> iArgs;

	for (auto iUnit = input.begin(); iUnit != input.end(); ++iUnit)
	{
		switch (iUnit->getType())
		{
		case expType::num:
			unitStack.push(*iUnit);
			break;
		case expType::opr:
			oprFunc = expOprSet.find(iUnit->getValue().opr)->func;

			if (unitStack.empty())return false;//运算不合理

			rhs = unitStack.top().getValue().num;
			unitStack.pop();
			if (unitStack.empty())
			{
				if (iUnit->getValue().opr != expOperators::plus && iUnit->getValue().opr != expOperators::minus)
					return false;
				lhs = 0;
			}
			else
			{
				lhs = unitStack.top().getValue().num;
				unitStack.pop();
			}

			unitStack.push(expUnit(oprFunc(lhs, rhs)));
			break;
		case expType::func:
			iFuncSettings = expFuncSet.find(iUnit->getValue().func);
			iFuncCall = iFuncSettings->func;
			iArgCount = iFuncSettings->argCount;

			for (size_t i = 0; i < iArgCount; ++i)
			{
				if (unitStack.empty())return false;//参数完整性检查失败
				iArgs.push_front(unitStack.top().getValue().num);
				unitStack.pop();
			}

			unitStack.push(expUnit(iFuncCall(iArgs)));
			iArgs.clear();
			break;
		default:
			break;
		}
	}
	if (unitStack.empty())return false;//堆栈为空

	output = unitStack.top().getValue().num;
	return true;
}

//（公开）主函数，输入算术表达式（字符串），输出结果
bool expCalculate(string& input, double& output)
{
	vector<expUnit> N; //（结构化）算术表达式
	vector<expUnit> RPN; //（结构化）逆波兰表达式

	if (!expStrToN(input, N)) return false;
	if (!expNToRPN(N, RPN)) return false;
	if (!expRPNToResult(RPN, output)) return false;

	return true;
}
