#include<iostream>
#include<string>
#include<vector>
using namespace std;

//定义
const int seq_size = 18;
//array定义方法
int pell_seq[ seq_size];	
//vector定义方法
vector<int> pell_seq[ seq_size];

//初始化
//array指定初始化列表
int elem_seq[seq_size]={
	1,2,3
	4,5,6
	7,8,9
};//此处有分号
//也可以不指定array大小
int elem_seq[]={
	1,2,3
	4,5,6
	7,8,9
}
//vector初始化方法
//用已初始化的array列表作为vector初值
int elem_vals[seq_size]={
	1,2,3
	4,5,6
	7,8,9
};
vector<int> elem_seq(elem_vals,elem_vals+seq_size);

//使用elem_seq
elem_seq.size();//返回elem_seq这个vector所包含的的元素个数

