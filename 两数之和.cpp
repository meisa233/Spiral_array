using namespace std;
#include<iostream>
#include<vector>
#include<stdio.h>
#include<string>
#include<stdlib.h>

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int length = nums.size();
		vector<int> result(2);
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < length; j++) {
				if (i != j) {
					if (nums[i] + nums[j] == target)
					{
						result[0] = i;
						result[1] = j;
						return result;
					}
				}
			}
		}
	}
};
int main() {
	string a;//输入的数组
	cin >> a;
	int target;//输入的目标值
	cin >> target;

	int length = a.length();//计算数组长度
	string b;//用于转换去掉了“[”和“]”的值
	b = a.substr(1, length - 2);//截取子串

	char * c = new char[length-2];//创建一个动态的字符串数组，用于将b子串转换到c中
	vector<int> d;//用于将输入的字符串转换到整型数组中

	int num=0;//用来暂存数

	for (int i = 0; i < b.length(); i++) {
		c[i] = b[i];//将string型的数据转换到char型数组中
	}

	for (int i = 0; i < b.length(); i++) {
		if (c[i] != ',') {
			num= ((int)c[i]-48)+num*10;
		}
		else {
			d.push_back(num);
			num = 0;
		}
		
	}
	d.push_back(num);//由于最后一个数还没有进入，需要进行这一步操作
	Solution ex;//调用类

	vector<int>  result = ex.twoSum(d, target);//输入数据

	cout << "[" << result[0] << "," << result[1] << "]";

	return 0;
}
