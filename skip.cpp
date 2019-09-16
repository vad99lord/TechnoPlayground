#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

vector <int> sort_squares(vector <int>& seq, vector <int>& seq1, vector <int>& seq2, vector <int>& seq3)
{	
	for (int i = 0; i < seq.size(); i++)
	{
		if (seq[i] < 0)
		{
			seq1.push_back(seq[i]);
		}
		if (seq[i] >= 0)
		{
			seq2.push_back(seq[i]);
		}
	}	
	
	int j = seq2.size();
	int k = seq1.size();
	int k1 = k - 1;

	if (j < k)
	{
		int i=0;
		while (i<j)
		{
			if (abs(seq2[i]) <= abs(seq1[k1-i]))
			{
				seq3.push_back(seq2[i]* seq2[i]);
				seq3.push_back(seq1[k1 - i]* seq1[k1 - i]); 
			}
			if (abs(seq2[i]) > abs(seq1[k1 - i]))
			{
				seq3.push_back(seq1[k1 - i]* seq1[k1 - i]);
				seq3.push_back(seq2[i]* seq2[i]); 
			}
			i++;
		}
		while (i < k)
		{
			seq3.push_back(seq1[k1 - i] * seq1[k1 - i]); 
			i++;
		}
	}

	if (k < j)
	{
		int i = 0;
		while (i < k)
		{
			if (abs(seq2[i]) <= abs(seq1[k1 - i]))
			{
				seq3.push_back(seq2[i] * seq2[i]);
				seq3.push_back(seq1[k1 - i] * seq1[k1 - i]); 
			}
			if (abs(seq2[i]) > abs(seq1[k1 - i]))
			{
				seq3.push_back(seq1[k1 - i] * seq1[k1 - i]);
				seq3.push_back(seq2[i] * seq2[i]); 
			}
			i++;
		}
		while (i < j)
		{
			seq3.push_back(seq2[i] * seq2[i]); 
			i++;
		}
	}
	
	if (k == j)
	{
		int i = 0;
		while (i < k)
		{
			if (abs(seq2[i]) <= abs(seq1[k1 - i]))
			{
				seq3.push_back(seq2[i] * seq2[i]);
				seq3.push_back(seq1[k1 - i] * seq1[k1 - i]);
			}
			if (abs(seq2[i]) > abs(seq1[k1 - i]))
			{
				seq3.push_back(seq1[k1 - i] * seq1[k1 - i]);
				seq3.push_back(seq2[i] * seq2[i]); 
			}
			i++;
		}
		
	}
	
				
		
	
	
	for (int i = 0; i < seq1.size(); i++) {
		cout << seq1[i] << ' ';
	}
	cout << endl;
	for (int i = 0; i < seq2.size(); i++) {
		cout << seq2[i] << ' ';
	}
	cout << endl;

	return seq3;
}

int main()
{
	srand(time(0));

	vector <int> vec = {-40, -30,-20,-15, -10, -9, -6,-5, -2 , -1 , 0 , 1 , 3 , 6, 8, 9, 20, 25, 30 ,45,60,80,100 };
	vector <int> vec1;
	vector <int> vec2;
	vector <int> vec3;
	
	vec3 = sort_squares(vec,vec1,vec2,vec3);
	cout << endl;
	for (int i = 0; i < vec.size(); i++) {
		cout << vec3[i] << ' ';
	}

	cout << endl << "runtime = " << 10000 * clock() / CLOCKS_PER_SEC << endl; // ����� ������ ���������          
	cout << vec3.size() - 1 << endl;
	system("pause");
	return 0;
}
