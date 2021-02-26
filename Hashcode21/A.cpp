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
	file.open("f.txt" );

	int time, no_of_intersections, no_of_streets, no_of_cars, score; 
	file>>time>>no_of_intersections>>no_of_streets>>no_of_cars>>score;

	std::vector<tuple<int, string, int>> street(no_of_streets);

	for(int i=0; i<no_of_streets; ++i)
	{
		file>>get<0>(street[i])>>get<0>(street[i])>>get<1>(street[i])>>get<2>(street[i]);
	}

	for(int i=0; i<no_of_cars ; ++i )
	{
		int temp;  file>>temp; string temp1 ; for(int i=0; i<temp; ++i) file>>temp1;
	}


	sort(street.begin(), street.end());

	ofstream myfile;
  	myfile.open ("output.txt");

  	int count2 = 0; int count=0;
	for(int i=0; i<street.size(); ++i)
	{
	
		if (i == 0) count++;
		else{
			if(get<0>(street[i]) == get<0>(street[i-1])) count++;
			else{
				count2++;
				myfile<<get<0> (street[i-1])<<endl;
				myfile<<count<<endl;
				int j = i;
				while(count-- && (--j>=0) )
					myfile<<get<1> (street[j])<<" "<<1<<endl;
				count  = 1;
			}
		}

	}

	cout<<count2;



	return 0;
}
