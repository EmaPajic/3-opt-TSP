#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>

using namespace std;

#define MAX_CITIES 30
#define MAX_DIST 100
#define MAX_TOUR (MAX_CITIES * MAX_DIST)

struct City
{
	int x, y;
};

City cities[MAX_CITIES];
double best = (double)MAX_TOUR;
int bestIndex;

void init()
{
	int from, to;
	for (from = 0; from < MAX_CITIES; from++)
	{
		cities[from].x = rand() % MAX_DIST;
		cities[from].y = rand() % MAX_DIST;
		cout <<"City "<<from<<": x=" << cities[from].x << ", y=" << cities[from].y << endl;
	}
}

double dist(City a,City b)
{
    int xi = pow(abs(a.x - b.x), 2);
    int yi = pow(abs(a.y - b.y), 2);

	double d = sqrt(xi + yi);
	return d;
}

void threeOpt()
{

	double current;
	double sub=100000000.0;
	double mincur=100000000.0;
	for (int i = 0; i < MAX_CITIES; i++)
	{
		for (int j = i + 2; j < MAX_CITIES; j++)
		{
			for (int k = j + 2; k < MAX_CITIES; k++)
			{
                int casee = 0;
                vector<City> h;
				current = dist(cities[i],cities[i+1]) + dist(cities[j],cities[j + 1]) + dist(cities[k],cities[k + 1]);
				if (current > dist(cities[i],cities[i + 1]) + dist(cities[j],cities[k]) + dist(cities[j + 1],cities[k + 1]))
					{
                       current = dist(cities[i],cities[i + 1]) + dist(cities[j],cities[k]) + dist(cities[j + 1],cities[k + 1]);
                       casee = 1;
					}

				if (current > dist(cities[i],cities[j]) + dist(cities[i + 1],cities[j + 1]) + dist(cities[k],cities[k + 1]))
					{
                        current = dist(cities[i],cities[j]) + dist(cities[i + 1],cities[j + 1]) + dist(cities[k],cities[k + 1]);
                        casee = 2;
					}

				if (current > dist(cities[i],cities[j]) + dist(cities[i + 1],cities[k]) + dist(cities[j + 1],cities[k + 1]))
					{
                       current = dist(cities[i],cities[j]) + dist(cities[i + 1],cities[k]) + dist(cities[j + 1],cities[k + 1]);
                       casee = 3;
					}

				if (current > dist(cities[i],cities[j + 1]) + dist(cities[k],cities[i + 1]) + dist(cities[j],cities[k + 1]))
					{
                        current = dist(cities[i],cities[j + 1]) + dist(cities[k],cities[i + 1]) + dist(cities[j],cities[k + 1]);
                        casee = 4;
					}

				if (current > dist(cities[i],cities[j + 1]) + dist(cities[k],cities[j]) + dist(cities[i + 1],cities[k + 1]))
					{
                        current = dist(cities[i],cities[j + 1]) + dist(cities[k],cities[j]) + dist(cities[i + 1],cities[k + 1]);
                        casee = 5;
					}

				if (current > dist(cities[i],cities[k]) + dist(cities[j + 1],cities[i + 1]) + dist(cities[j],cities[k + 1]))
					{
                        current = dist(cities[i],cities[k]) + dist(cities[j + 1],cities[i + 1]) + dist(cities[j],cities[k + 1]);
                        casee = 6;
					}

				if (current > dist(cities[i],cities[k]) + dist(cities[j + 1],cities[j]) + dist(cities[i + 1],cities[k + 1]))
					{
                        current = dist(cities[i],cities[k]) + dist(cities[j + 1],cities[j]) + dist(cities[i + 1],cities[k + 1]);
                        casee = 7;
					}
					if(casee == 1)
					{
                        for(int l=0;l<j+1;l++) h.push_back(cities[l]);
                        for(int l=k;l>=j+1;l--) h.push_back(cities[l]);
                        for(int l=k+1;l<MAX_CITIES;l++) h.push_back(cities[l]);
					}
					else if(casee == 2)
					{
                        for(int l=0;l<i+1;l++) h.push_back(cities[l]);
                        for(int l=j;l>=i+1;l--) h.push_back(cities[l]);
                        for(int l=j+1;l<MAX_CITIES;l++) h.push_back(cities[l]);
					}
					else if(casee == 3)
					{
                        for(int l=0;l<i+1;l++) h.push_back(cities[l]);
                        for(int l=j+1;l>=i+1;l--) h.push_back(cities[l]);
                        for(int l=k;l>j+1;l--) h.push_back(cities[l]);
                        for(int l=k+1;l<MAX_CITIES;l++) h.push_back(cities[l]);
					}
					else if(casee == 4)
					{
                        for(int l=0;l<i+1;l++) h.push_back(cities[l]);
                        for(int l=j+1;l<k+1;l++) h.push_back(cities[l]);
                        for(int l=i+1;l<j+1;l++) h.push_back(cities[l]);
                        for(int l=k+1;l<MAX_CITIES;l++) h.push_back(cities[l]);
					}
					else if(casee == 5)
					{
                        for(int l=0;l<i+1;l++) h.push_back(cities[l]);
                        for(int l=j+1;l<k+1;l++) h.push_back(cities[l]);
                        for(int l=j;l>=i+1;l--) h.push_back(cities[l]);
                        for(int l=k+1;l<MAX_CITIES;l++) h.push_back(cities[l]);
					}
					else if(casee == 6)
					{
                        for(int l=0;l<i+1;l++) h.push_back(cities[l]);
                        for(int l=k;l>=j+1;l--) h.push_back(cities[l]);
                        for(int l=i+1;l<j+1;l++) h.push_back(cities[l]);
                        for(int l=k+1;l<MAX_CITIES;l++) h.push_back(cities[l]);
					}
					else if(casee == 7)
					{
                        for(int l=0;l<i+1;l++) h.push_back(cities[l]);
                        for(int l=k;l>j+1;l--) h.push_back(cities[l]);
                        for(int l=j+1;l>=i+1;l--) h.push_back(cities[l]);
                        for(int l=k+1;l<MAX_CITIES;l++) h.push_back(cities[l]);
					}
					for(int l=0;l<h.size();l++)
					cities[l]=h[l];
			}
		}
	}
}

int main()
{
	cout << "Koordinate gradova su\n";
	srand(time(nullptr));
	init();
	threeOpt();
    double sum=0.0;
    for(int i=0;i<MAX_CITIES-2;i++)
    {
        sum+=dist(cities[i],cities[i+1]);
    }
    sum+=dist(cities[MAX_CITIES-1],cities[0]);
	cout <<"Najkraci put po trioptimalnoj heuristici je "<< sum << endl;
	return 0;
}
