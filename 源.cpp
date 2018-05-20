using namespace std;
#include<iostream>
#include<iomanip>
int **LUOXUAN(int n);

int **LUOXUAN(int n) {


	int **n3;
	n3 = new int *[n];
	for (int i = 0; i<n; i++)
		{
	    n3[i] = new int[n];
		}


	if (n == 1) {
		n3[0][0] = 1;
			return n3;
	}

	if (n == 2) {
		n3[0][0] = 1;
		n3[0][1] = 2;
		n3[1][0] = 4;
		n3[1][1] = 3;
		return n3;
	}

	if (n > 2) {
		for (int i = 0; i < (n - 1) * 2; i++) {
			if (i < n) {
				n3[0][i] = i + 1;
			}
			else {
				n3[i + 1 - n][n-1] = i + 1;
			}
		}

		int count = n - 1;
		for (int i = (n - 1) * 4; i >(n - 1) * 2; i--) {
			if (count > 0) {
				n3[(n - 1) * 4 - i + 1][0] = i;
			}
			else {
				n3[n - 1][-count + 1] = i;
			}
			count--;
		}
		int **n_sub = LUOXUAN(n - 2);

		for (int i2 = 0; i2<n - 2; i2++)
			for (int j2 = 0; j2 < n - 2; j2++) {
				n3[1 + i2][1 + j2] = n_sub[i2][j2] + (n - 1) * 4;
			}


		return n3;
	}



}



int main() {

	int NN = 4 ;
	int **n;
	n=LUOXUAN(NN);
	
	for (int i = 0; i <NN; i++)
	{
		for (int j = 0; j < NN; j++)
			cout <<setw(3)<< n[i][j]<<" ";
		cout << endl;
	}
	

	return 0;
}