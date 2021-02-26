#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
#include<tuple>
#include<vector>

using namespace std;

int main()
{
	ifstream  file;
	file.open("b.txt" );

	int time, no_of_intersections, no_of_streets, no_of_cars, score; 
	file>>time>>no_of_intersections>>no_of_streets>>no_of_cars>>score;

	std::vector<tuple<int, string, int>> street(no_of_streets);

	for(int i=0; i<no_of_streets; ++i)
	{
		file>>get<0>(street[i])>>get<2>(street[i])>>get<1>(street[i])>>get<0>(street[i]);
	}

	for(int i=0; i<no_of_cars ; ++i )
	{
		int temp;  file>>temp; string temp1 ; for(int i=0; i<temp; ++i) file>>temp1;
	}


	sort(street.begin(), street.end());

	vector<int> ids(100000+5, 0);
	for(int i=0; i<street.size(); ++i)
	{
	
		if(ids[get<2>(street[i])] == 0)
		{
			cout<<get<2>(street[i])<<endl<<1<<endl; 
			cout<<get<1>(street[i])<< " " << 1 << endl;
			ids[get<2>(street[i])]=1;
		}
		
	}



	return 0;
}