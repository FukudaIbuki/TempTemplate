#include<iostream>

using std::cout;
using std::cin;
using std::endl;

//テンプレート　型をパラメータにとっていろいろな型に対応できる機能
//　　　　　　　多態性の一つ（同じ関数や、クラスを、いろんな方に対応させられる）

//オーバーロードで書く
//2つの整数のうち大きい方を返す
int myMax(int a, int b);
//2つの単精度実数(float)のうち大きい方を返す
float myMax(float a, float b);
//2つの倍制度実数(double)のうち大きい方を返す
double myMax(double a, double b);

int myMax(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

float myMax(float a, float b)
{
	if (a > b)
		return a;
	else
		return b;
}

double myMax(double a, double b)
{
	if (a > b)
		return a;
	else
		return b;
}

//関数テンプレート
template <typename T>
T tMax(T a, T b) {
	if (a > b)
		return a;
	else
		return b;
}



//tMax<int>(10, 20)
//tMAx<double>(0.6, 0.8);

//クラステンプレート
template <typename T>
class Vec2
{
public:
	T x;
	T y;
	T GetX() { return(x); }
	void SetX(T _x) { x = _x; }
	void PrintVec() { cout << "(x, y) = (" << x << "," << y << ")" << endl; }
	T Length() const { return ((T)sqrt(x * x + y * y)); }
	
	bool operator >(const Vec2<T>& other) {
		return(this->Length() > other.Length());
	}
};
//ベクトルの長さをT型で返すメンバ関数を作る
//ベクトルの長さで比較する>演算子をオーバーロード
//ベクトルの長さを比べて長い方を表示して本当にあっているか確認（tMaxに入れる！)

int main()
{
	//int var1 = 10;
	//int var2 = 20;
	////int res = myMax(var1, var2);
	//int res = tMax<int>(var1, var2);
	//cout << "mayMax 10 20 : " << res << endl;
	//float var3 = 10.6;
	//float var4 = 2.1;
	////float res2 = myMax(var3, var4);
	//float res2 = tMax<float>(var3, var4);
	//cout << "mayMax 10.6  2.1 : " << res2 << endl;
	//double var5 = 0.000062;
	//double var6 = 1e-15; //10のマイナス15乗
	////double res3 = myMax(var5, var6);
	//double res3 = tMax<double>(var5, var6);
	//cout << "mayMax var5 var6 : " << res3 << endl;

	Vec2<int> v1;
	v1.x = 4;
	v1.y = 1;

	Vec2<int> v2;
	v2.x = 1;
	v2.y = 1;

	//if(v1 > v2)
	//	v1.PrintVec();
	//else
	//	v2.PrintVec();

	Vec2<int> res = tMax(v1, v2);
	res.PrintVec();

	return 0;
}