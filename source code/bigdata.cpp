#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <utility>


using namespace std;



struct NODE{

	double x, y;
	int t;

};


struct PATH{

	int num;// 记录轨迹数目

	int bianhao;

	NODE node[500];

	pair<double, double> goal;

	int label;

};



istream&  operator>>(istream & in, PATH & b){

	string de;

	char go[100];

	in >> b.bianhao;

	in >> de;

	int pos;

	int cnt = 0;

	char ss[100];

	while (true){


		pos = de.find(';');

		string temp = de.substr(0, pos);




		for (int i = 0; i < temp.length(); i++){

			ss[i] = temp[i];

		}

		ss[temp.length()] = '\0';


		sscanf(ss, "%lf,%lf,%d", &b.node[cnt].x, &b.node[cnt].y, &b.node[cnt].t);

		cnt++;


		if (pos == de.length() - 1) {

			break;

		}

		else de = de.substr(pos + 1, de.length() - pos - 1);


	}

	// 这里有问题

	string temp;

	in >> temp;




	for (int i = 0; i < temp.length(); i++){

		go[i] = temp[i];

	}


	go[temp.length()] = '\0';



	double goalx, goaly;

	sscanf(go, "%lf,%lf", &goalx, &goaly);


	b.goal = make_pair(goalx, goaly);



	b.num = cnt - 1;


	in >> b.label;




	return in;

}






int main(){


	ifstream cin("test1.txt");


	PATH path[50];

	int cnt = 0; // 用来记录总共有多少组数据

	while (cin >> path[cnt])cnt++;


	/*


	path 数组记录的是所有的轨迹

	
	在这里处理数据，输出向量特征  到文件，构成train_data,test_data 也同样处理，不过没有标签，可以自己随便赋值，反正不重要


	  最后使用 libsvm 来得到结果




	*/


	return 0;

}