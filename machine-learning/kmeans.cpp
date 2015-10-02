//kmeans implementation
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <stdlib.h>

#define k 3

using namespace std;
//typedef vector<double> Sample;
struct Point{
	float x;
	float y;
};

//计算点到聚类中心的距离并计算出最小值

//计算聚类中心的位置，不断迭代。

//平面欧几里得距离
float Edistance(Point n1, Point n2){
	float dist = sqrt((n2.x-n1.x)*(n2.x-n1.x)+(n2.y-n1.y)*(n2.y-n1.y));
	return dist;
}

//计算距离从而得出样本属于k个簇中的哪个簇
int BelongCluster(Point means[], Point n){
	float d = Edistance(means[0], n);
	float tmp;
	int lable=0;
	for(int i; i<k; i++)
	{
		tmp=Edistance(means[i],n);
		if(tmp<=d)
		{
			d=tmp;
			lable=i;	
		}
	}
	return lable;
}

//计算所有簇的质心也就是均值
Point getMeans(vector<Point> mcluster){
	int num = mcluster.size();
	Point t;
	for(int i=0;i<num;i++)
	{
		t.x += mcluster[i].x;
		t.y += mcluster[i].y;
	}
	t.x = t.x / num;
	t.y = t.y / num;
	return t;
}

//计算平方误差（算法终止条件）
float Var(vector<Point> vcluster[], Point mean[]){
	double var = 0;
	for(int i = 0;i < k;i++)
	{
		vector<Point> t = vcluster[i];
		for(int j;j < t.size();j++)
		{
			var += Edistance(t[j],mean[i]);
		}
	}
	return var;
}

//算法核心
void Kmeans(vector<Point> points){
	//创建k个簇和k个中心点
	vector<Point> clusters[k];
	Point means[k];
	//初始化质心
	for(int i=0;i<k; i++)
	{
		means[i].x = points[i].x;
		means[i].y = points[i].y;
	}
	//根据默认质心给簇中的点定标签
	int lable;
	for(int i=0;i!=points.size();i++)
	{
		lable = BelongCluster(means,points[i]);
		clusters[lable].push_back(points[i]);
	}
	//更新质心和簇
	double oleVar = -1;
	double newVar = Var(clusters,means);
	while(abs(newVar - oldVar) >= 1)
	{
		//更新
		for(int i=0;i < k;i++)
		{
		
		}
		for(int i=0;i<k;i++)
		{
			clusters[i].clear();
		}
		for(int i=0;i!=points.size();i++)
		{
			lable=BelongCluster(means,points[i]);
			clusters[lable].push_back(points[i]);
		}
	}

}
