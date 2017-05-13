#include <iostream>
#include <istream>
#include <fstream>
#include <math.h>
#include <sstream>
using namespace std;

#define n 3 //17
#define n_sq 9 //289


int makeFile() {

	ofstream myfile;
	int ans = n_sq + n + 1;
	stringstream ss;
	ss << ans;
	string str = ss.str();
	myfile.open("solFor" + str + "m.txt");

	int count = n + 1;
	//int64_t incidenceArr[n_sq + n + 1][n_sq + n + 1];
	//cout << 0 << " " << 1 << " " << 2 << " ";

	for (int i = 0; i < n + 1; i++)
	{
		int c = 0;
		int b = 0;
		for (int l = 0; l < n_sq + n + 1; l++)
		{

			if (l == 0)
			{
				myfile << 1 << "	";
				//cout << 1;
			}
			else {
				if (i == 0)
				{
					if (l > 0 && l <= n)
					{
						myfile << 1 << "\t";
						//cout << 1;
					}
					else {
						myfile << 0 << "\t";
						//cout << 0;
					}
				}
				else {

					if (i == b)
					{
						myfile << 1 << "\t";
						//cout << 1;
					}
					else {
						myfile << 0 << "\t";
						//cout << 0;
					}

					c++;
					if (c == n) {
						c = 0;
						b++;
					}

				}
			}
		}
		myfile << endl;
		//cout << endl;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			count++;
			//cout << count << " ";
			//cout << i << "x + " << j << endl;
			int x = 0;
			int c = 0;
			int b = 0;
			int y = 0;
			for (int l = 0; l < n_sq + n + 1; l++)
			{

				//cout << 1 << " ";
				if (l >= n + 1) {
					//cout << " " << x << ",";
					y = (i*x + j) % n;
					//cout << y << " ";

					if (y == c)
					{
						myfile << 1 << "\t";
						//cout << 1;
					}
					else {
						myfile << 0 << "\t";
						//cout << 0;
					}

					c++;
					b++;
					if (c == n) {
						c = 0;
						x++;
					}
				}
				else {
					if (l == i + 1)
					{
						myfile << 1 << "\t";
						//cout << 1;
					}
					else {
						myfile << 0 << "\t";
						//cout << 0;
					}
				}
			}
			myfile << endl;
			//cout << endl;
		}

	}


	myfile.close();


	return 0;
}


int readFile() {


	int ans = n_sq + n + 1;
	stringstream ss;
	ss << ans;
	string str = ss.str();
	ifstream infile;

	infile.open("solFor" + str + "m.txt");
	bool incidenceArr[n_sq + n + 1][n_sq + n + 1];
	for (int i = 0; i < n_sq + n + 1; i++)
	{
		for (int j = 0; j < n_sq + n + 1; j++)
		{
			int temp;

			infile >> temp;
			incidenceArr[i][j] = temp;
			//cout << temp << " ";
		}

		//cout << endl;
	}

	infile.close();

	for (int i = 0; i < n_sq + n + 1; i++)
	{
		for (int j = 0; j < n_sq + n + 1; j++)
		{
			cout << incidenceArr[i][j] << " ";
		}

		cout << endl;
	}




	return 0;
}

int main() {

	makeFile();
	readFile();
	
	return 0;
}