using namespace std;
#include<iostream>
#include<iomanip>
int **LUOXUAN(int n);

int **LUOXUAN(int n) {


	int **n3;//用于返回的数组指针
	n3 = new int *[n];//开辟一个二维动态数组
	for (int i = 0; i<n; i++)
		{
	    n3[i] = new int[n];
		}


	if (n == 1) {//当矩阵为1x1的矩阵时
		n3[0][0] = 1;
			return n3;
	}

	if (n == 2) {//当矩阵为2x2的矩阵时
		n3[0][0] = 1;
		n3[0][1] = 2;
		n3[1][0] = 4;
		n3[1][1] = 3;
		return n3;
	}

	if (n > 2) {//当输入的n大于2x2维时
/*第一圈的数是1~(n-1)*4，我们先对一半的数即(n-1)*2进行矩阵上的复制*/
		for (int i = 0; i < (n - 1) * 2; i++) {
			if (i < n) {//对第一行进行赋值
				n3[0][i] = i + 1;
			}
			else {//对方阵中最右边的一列进行赋值
				n3[i + 1 - n][n-1] = i + 1;
			}
		}

		int count = n - 1;//计数器
		for (int i = (n - 1) * 4; i >(n - 1) * 2; i--) {
			if (count > 0) {//对最左侧的一列进行赋值（除了第一行
				n3[(n - 1) * 4 - i + 1][0] = i;
			}
			else {//完成对最左侧的一列的赋值之后对最后一行进行赋值
				n3[n - 1][-count + 1] = i;
			}
			count--;
		}
		int **n_sub = LUOXUAN(n - 2);//除了最外面一圈的情况，内部的采用递归的形式

		for (int i2 = 0; i2<n - 2; i2++)
			for (int j2 = 0; j2 < n - 2; j2++) {
				n3[1 + i2][1 + j2] = n_sub[i2][j2] + (n - 1) * 4;//注意内部的数要变大
			}
		//释放空间
		for (int i = 0; i<n-2; i++)
		{
			delete[] n_sub[i];
		}
		delete[] n_sub;

		return n3;
	}

}

int main() {

	int NN = 6 ;//输入的NN值 用于表示矩阵的维数是NN x NN
	int **n;
	n=LUOXUAN(NN);
	
	for (int i = 0; i <NN; i++)
	{
		for (int j = 0; j < NN; j++)
			cout <<setw(3)<< n[i][j]<<" ";//setw(3)用于对齐格式
		cout << endl;
	}
	//释放空间
	for (int i = 0; i<NN; i++)
	{
		delete[] n[i];
	}
	delete[] n;

	return 0;
}
