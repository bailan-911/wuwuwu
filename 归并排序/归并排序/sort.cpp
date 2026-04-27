#include<iostream>
#include<vector>
using namespace std;
//有2个vector数组，原始数组（会被直接修改，最终得到合并后的有序结果）
//临时数组（用来保存原始数据的副本，避免在合并过程中被覆盖）
vector<int> temp(4,0);
void sort(vector<int>& v, vector<int>& temp, int low, int mid, int high);
void mergesort(vector<int> & v,vector<int>& temp,int low,int high)
{
	if (low >= high) return;//递归的终止条件
	int mid = (low + high) / 2;
	mergesort(v, temp,low, mid);
	mergesort(v,temp, mid + 1, high);
	sort(v,temp,low,mid,high);
}
void sort(vector<int>& v, vector<int>& temp,int low,int mid,int high)
{
	if (low == 0 && high == 1);
/*left = startIndex（指向左边开头）
 right = middleIndex + 1（指向右边开头）
循环 k 从 startIndex 到 endIndex，每次将较小值写回 v[k] */
	int left = low;
	int right = mid + 1;
	//将原始数组的数据复制
	for (int i = low;i <= high;i++)
	{
		temp[i] = v[i];
	}//对一段数组进行归并
	for (int k = low;k <= high;k++)
	{
		if (left > mid)v[k] = temp[right++];//  // 左边已取完 → 只取右边剩余元素
		else if (right > high)v[k] = temp[left++];// // 右边已取完 → 只取左边剩余元素
		else if (temp[left] > temp[right]) v[k] = temp[right++];//   右边当前元素更小 → 取右边
		else v[k] = temp[left++];//左边元素 ≤ 右边元素 → 取左边（保证稳定性）
		
	}
}
int main()
{
	vector<int> v = { 5,2,3,1 };

	for (int x : v) cout << x << " ";
	mergesort(v, temp,0,v.size()-1 );
	for (int x : v) cout << x << " ";
}