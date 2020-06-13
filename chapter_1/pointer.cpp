
int ival = 1024;
int *pi;

ival;
&ival;
int *pi = &ival;
*pi;//提领pi，访问所指向的对象

//未指向任何对象的指针，地址值为0，null指针
int *pi = 0;
if( pi && *pi != 1024)//
		*pi = 1024;
//检验是否是空指针
if(!pi)

//6个vector对象（代表6种数列）
vector<int> fibonacci, lucas, pell, triangular, square, pentagonal;
//一个指向元素类型为int的vector
vector<int> *pv = 0;
pv = &fionacci;
pv = &lucas;
//但这种方法牺牲了透明性
//将每个数列的内存地址存入某个vector中，通过索引访问
const int seq_cnt = 6;
//每一个指针数组大小都为seq_cnt
//每个指针都指向vector<int>对象
vector<int> *seq_addrs[seq_cnt] = {
	 &fibonacci, &lucas, &pell, 
	 &triangular, &square, &pentagonal
};
//seq_addrs是个指针，类型是vector<int> *
//seq_addrs[0]所持有的值是fibooacci vector的地址
//因此可以通过索引值来访问各个vector

vector<int> *current_vec = 0;
//...
for( int ix=0; ix < seq_cnt ; ++ix )
{
	current_vec = seq_addrs[ ix ];
	//所有要显示的元素都通过current_vec间接访问
}

//随机数
#include<cstdlib>

srand(seq_cnt);//伪随机数生成
seq_index = rand() % seq_cnt;
current_vec = seq_addrs[seq_index];

//使用class object的指针和使用内置类型的指针不同之处在于
//class object关联了一组可以调用（invoke）的操作（operation）
//举例：检查fibonacci vector的第二个元素是否为1可能会这么写
if( !fibonacci.empty() && 
	(fibonacci[1] == 1 ) )
//dot是成员选择运算符（member selection operator），选择想要进行的操作

