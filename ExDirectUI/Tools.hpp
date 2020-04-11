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

#include <WinUser.h>
#include <wingdi.h>
#include <Windows.h>
#include "../help/ExDirectUI4.h"
#include <vector>

#define RGB2ARGB(rgb,a)((ARGB)(BYTE(GetRValue(rgb)) <<16|BYTE(GetGValue(rgb))<<8| BYTE(GetBValue(rgb))|(a<<24)))

struct ListItem
{
	wstring text;
	int color;
	int depth;
	int x1;
	int y1;
	int y2;
};

extern vector<ListItem> listItems;

 double GetDPI(HWND hWnd)
{
	return GetDeviceCaps(GetDC(hWnd), 88) / 96.0;
}

 void AddListItem(wstring text, int color, int depth, int x1, int y1, int y2)
{
	ListItem li;
	li.text = text;
	li.color = color;
	li.depth = depth;
	li.x1 = x1;
	li.y1 = y1;
	li.y2 = y2;
	listItems.push_back(li);
}

 string wstring2string(wstring wstr)
{
	string result;
	//获取缓冲区大小，并申请空间，缓冲区大小事按字节计算的  
	int len = WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), wstr.size(), NULL, 0, NULL, NULL);
	char* buffer = new char[len + 1];
	//宽字节编码转换成多字节编码  
	WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), wstr.size(), buffer, len, NULL, NULL);
	buffer[len] = '\0';
	//删除缓冲区并返回值  
	result.append(buffer);
	delete[] buffer;
	return result;
}

string allreplace(string given, string a, string b)
{
	string ret = given;
replace:
	if (ret.find(a, 0) == string::npos)
	{
		return ret;
	}
	ret = ret.replace(ret.find(a, 0), a.size(), b);
	goto replace;
}

int Ex_ObjGetTop(HEXOBJ hObj)
{
	RECT tmp;
	Ex_ObjGetRect(hObj, &tmp);
	return tmp.top;
}
