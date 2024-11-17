#include<iostream>
#include<cstdlib>
using namespace std;
//矩阵转置
double *MatT(int row,int col, double *Mat)
{
	double *result = new double[row*col];//结果矩阵
	for (int i = 0; i < row*col; i++)//遍历Mat
	{
		//第x个元素对应row*col阶矩阵的第rowMat行第colMat列
		int x = i + 1;//i从0开始 x从1开始
		int rowMat = 1;
		int colMat = 0;
		while (1)
		{
			if (x - col>0)
			{
				x = x - col;
				rowMat++;
			}
			else
			{
				colMat = x;
				break;
			}
		}
		//上述将一维数组下标i  转化成了自然矩阵行rowMat列colMat
		//转置后为colMat行rowMat列
		//在转化为一维坐标即可j=(colMat-1)*row+rowMat-1
		result[(colMat - 1)*row + rowMat - 1] = Mat[i];
	}
	return result;
}
//求行列式
double det(int n, double *Mat)
{
	if (n == 1)
		return Mat[0];
	double *subMat = new double[(n - 1)*(n - 1)];//创建n-1阶的代数余子式阵subMat    
	int mov = 0;//判断行是否移动   
	double sum = 0.0;//sum为行列式的值  
	for (int Matrow = 0; Matrow<n; Matrow++) // Mat的行数把矩阵Mat(nn)赋值到subMat(n-1)  
	{
		for (int subMatrow = 0; subMatrow<n - 1; subMatrow++)//把Mat阵第一列各元素的代数余子式存到subMat  
		{
			mov = Matrow > subMatrow ? 0 : 1; //subMat中小于Matrow的行，同行赋值，等于的错过，大于的加一  
			for (int j = 0; j<n - 1; j++)  //从Mat的第二列赋值到第n列  
			{
				subMat[subMatrow*(n - 1) + j] = Mat[(subMatrow + mov)*n + j + 1];
			}
		}
		int flag = (Matrow % 2 == 0 ? 1 : -1);//因为列数为0，所以行数是偶数时候，代数余子式为1.  
		sum += flag* Mat[Matrow*n] * det(n - 1, subMat);//Mat第一列各元素与其代数余子式积的和即为行列式
	}
	delete[]subMat;
	return sum;
}
int main()
{
	int n;//阶数
	int i,j;
	cout << "请输入矩阵的阶数" << endl;
	cin >> n;
	double *Mat = new double[n*n];//n阶矩阵Mat
	cout << "请输入这个矩阵" << endl;
	for (i = 0; i <= n*n - 1; i++)
		cin >> Mat[i];
	double *subMat = new double[(n - 1)*(n - 1)];//Mat的(代数)余子式subMat[]
	double *adjointMat = new double[n*n];//Mat的伴随矩阵adjointMat[]
	double detMat;//Mat的行列式
	double *inverseMat = new double[n*n];//Mat的逆矩阵inverseMat[]
	detMat = det(n, Mat);//求Mat的行列式
	if (detMat == 0)
		cout << "该矩阵不可逆!" << endl;
	else
	{
		cout << "该矩阵行列式为" << endl;
		cout << detMat << endl;  
			
		int adjointMat_index=0;
		for (int Mat_i = 1; Mat_i <= n; Mat_i++)
		{
			for (int Mat_j = 1; Mat_j <= n; Mat_j++)
			{
				int M_index = 0;
				//求第Mat_i,Mat_j的余子式Mij
				for (i = 0; i < n*n; i++)//循环Mat的下标选出余子式
				{
					//第x个元素对应n阶矩阵的第row行第col列
					int x = i+1;//i从0开始 x从1开始
					int row=1;
					int col=0;
					while (1)
					{
						if (x - n>0)
						{
							x = x - n;
							row++;
						}
						else
						{
							col = x;
							break;
						}
					}
					if (row != Mat_i && col != Mat_j)
					{
						subMat[M_index] = Mat[i];
						M_index++;
					}
				}			
				adjointMat[adjointMat_index] = (adjointMat_index % 2 == 0 ? 1 : -1)*det(n - 1, subMat);//求伴随矩阵各元素
				adjointMat_index++;
			}
		}
		adjointMat = MatT(n, n, adjointMat);//转置
		cout << "该矩阵的伴随矩阵为" << endl;
		int adMat_index = 0;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				cout << adjointMat[adMat_index] <<"\t";
				adMat_index++;
			}
			cout << endl;
		}
		for (i = 0; i < n*n;i++)
			inverseMat[i] = adjointMat[i] / detMat;
		cout << "该矩阵的逆矩阵为" << endl;
		int inverseMat_index = 0;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				cout << inverseMat[inverseMat_index]<<"\t";
				inverseMat_index++;
			}
			cout << endl;
		}
	}

	delete[]Mat;
	system("pause");
	return 0;
}