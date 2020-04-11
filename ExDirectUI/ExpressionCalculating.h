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

struct expVarSettings //��������
{
	string exp;//������
	double value;//ֵ

	expVarSettings(const string& iName, double iValue) \
		:exp(iName), value(iValue) {}

};

const vector<expVarSettings> expVarSet = { \
expVarSettings("PI",M_PI),\
expVarSettings("E", M_E),\
};


enum expOperators :short //���������
{
	lbracket = 1/*������*/, rbracket/*������*/, plus, minus, times, divided, power, mod
};

struct expOperatorSettings //���������
{
	expOperators opr;
	short priority;//���ȼ�
	string exp;//�ַ�����ʾ
	std::function<double(double, double)> func;//���õĺ���

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
��������ȼ�
  0 ( ������ //�ų�
  0 ) ������ //�ų�
- 1   ����
- 2 ^ ������
- 3 * ��
- 3 / ��
- 3 % ȡ��
- 4 + ��
- 4 - ��
- 5 < С��
- 5 <= С�ڵ���
- 5 > ����
- 5 >= ���ڵ���
- 6 == ����
- 6 != ������
- 7 && �߼���
- 8 || �߼���
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
struct expFunctionSettings //��������
{
	static expFunctionId allocator;

	const expFunctionId id;//�Զ�����id
	string exp;//������
	size_t argCount;//��������
	std::function <double(deque<double>&)> func;//���õĺ���

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
//���Һ���
expFunctionSettings("sin", 1, [](deque<double>& args)
 {
return sin(args[0]);
}),\
//���Һ���
expFunctionSettings("cos", 1, [](deque<double>& args)
 {
return cos(args[0]);
}),\
//���к���
expFunctionSettings("tan", 1, [](deque<double>& args)
 {
return tan(args[0]);
}),\
//�����Һ������������[-PI/2,PI/2]
expFunctionSettings("arcsin", 1, [](deque<double>& args)
 {
return asin(args[0]);
}), \
//�����Һ������������[0,PI]
expFunctionSettings("arccos", 1, [](deque<double>& args)
 {
return acos(args[0]);
}), \
//�����к�������ֵ�����������[-PI/2,PI/2]
expFunctionSettings("arctan", 1, [](deque<double>& args)
 {
return atan(args[0]);
}), \
//��10Ϊ�׵Ķ�������
expFunctionSettings("lg", 1, [](deque<double>& args)
 {
return log10(args[0]);
}), \
//��Ȼ��������
expFunctionSettings("ln", 1, [](deque<double>& args)
 {
return log(args[0]);
}), \
//��������,arg[0]Ϊ������arg[1]Ϊ����
expFunctionSettings("log", 2, [](deque<double>& args)
 {
return log(args[0]) / log(args[1]);
}), \
//����ֵ����
expFunctionSettings("abs", 1, [](deque<double>& args)
 {
return abs(args[0]);
}), \
//��˹����,���ز���x����������
expFunctionSettings("int", 1, [](deque<double>& args)
 {
return floor(args[0]);
}), \
//��ƽ������
expFunctionSettings("sqrt", 1, [](deque<double>& args)
 {
return sqrt(args[0]);
}), \
//����[arg[0],arg[1])�е��������ֵ  !!��Ҫ����srand()
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

class expUnit //�������ʽ���������沨�����ʽ�е�һ��������λ
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

/*���ַ�����ĳ��λ�ÿ�ʼ����ȡ�����֣���ȡ�����λ�ñ��������֮�󣬷����Ƿ�ȡ��
!!�豣֤��stringstream&��stream�Ѿ�������(string::iterator&)pos��ָ����ַ���(string&)exp
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

/*ΪexpGetOperator()��expGetFunction()����ƥ����ʽ�е����������
!!ƥ���㷨Ϊ��̰���㷨����ʱ���ַ���������ܱ������޷�ƥ��
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

//���ַ�����ĳ��λ�ÿ�ʼ����ȡ�����������ȡ�����λ�ñ���������֮�󣬷����Ƿ�ȡ��
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

//���ַ�����ĳ��λ�ÿ�ʼ����ȡ������������ȡ�����λ�ñ����������֮�󣬷����Ƿ�ȡ��
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

//���ַ�����ĳ��λ�ÿ�ʼ����ȡ������������ȡ�����λ�ñ����������֮�󣬷����Ƿ�ȡ��
bool expGetVar(string& exp, string::iterator& pos, expUnit& output)
{
	auto foundPos = find_if(expVarSet.begin(), expVarSet.end(), expMatch<expVarSettings>(exp, pos));
	if (foundPos != expVarSet.end())
	{
		pos += foundPos->exp.size();
		output.set(foundPos->value);//������󣬱���������������

		return true;
	}
	else return false;
}

//���Ա��ʽ�еĿո���������Ժ��Ե��ַ���
bool expGetSpace(string& exp, string::iterator& pos)
{
	size_t i;
	for (i = 0; pos != exp.end() && (*pos == ' ' || *pos == ','); ++pos, ++i);
	return i > 0;
}


//�����������ʽ���ַ������������ȷ�ԣ��������������ʽ���ṹ���飩,�������״̬
bool expStrToN(string& input, vector<expUnit>& output)
{
	stringstream numStream(input);
	string::iterator nowPos = input.begin();
	expUnit tmpUnit(0.0);
	int bracketCount = 0; //���ż��������������ż�һ���������ż�һ

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
						return false; //����������������ţ������ڼ��ʧ��
				}
				else if (oLastUnit->getType() == expType::func)
				{
					if (tmpUnit.getValue().opr != expOperators::lbracket && \
						tmpUnit.getValue().opr != expOperators::rbracket)
						return false;//����������������ţ�ǰ�������к���
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
					return false;//����ǰ�����������ֻ���
			}
			output.push_back(tmpUnit);
		}
		else return false;
	}


	if (bracketCount != 0) return false; //���ź����Լ��ʧ��

	return true;
}

//ΪexpNToRPN()���񡣶�ջ������������Ĵ���
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

//�����������ʽ���ṹ���飩�������沨�����ʽ���ṹ���飩,�������״̬
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
			default://������������������
				short nowPriority = expOprSet.find(iUnit->getValue().opr)->priority;
				expNToRPN_OprOrFuncPorc(iUnit, nowPriority, unitStack, output);
				break;
			}
			break;
		case expType::func:
			//�������ȼ���Ϊ-1
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

//�����沨�����ʽ���ṹ���飩�����������������״̬
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

			if (unitStack.empty())return false;//���㲻����

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
				if (unitStack.empty())return false;//���������Լ��ʧ��
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
	if (unitStack.empty())return false;//��ջΪ��

	output = unitStack.top().getValue().num;
	return true;
}

//���������������������������ʽ���ַ�������������
bool expCalculate(string& input, double& output)
{
	vector<expUnit> N; //���ṹ�����������ʽ
	vector<expUnit> RPN; //���ṹ�����沨�����ʽ

	if (!expStrToN(input, N)) return false;
	if (!expNToRPN(N, RPN)) return false;
	if (!expRPNToResult(RPN, output)) return false;

	return true;
}
