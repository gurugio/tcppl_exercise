#include<iostream>
#include<vector>

using namespace std;



void print_matrix(vector< vector<int> > &m)
{
    for (int i = 0; i < m.size(); i++)
    {
        for (int j = 0; j < m[i].size(); j++)
        {
            cout << m[i][j] << '\t';
        }
        cout << endl;
    }
}

void convert_matrix(vector< vector<int> > *m)
{
    for (int i = 0; i < m->size(); i++)
    {
        for (int j = i+1; j < (*m)[i].size(); j++)
        {
            int t = (*m)[i][j];
            (*m)[i][j] = (*m)[j][i];
            (*m)[j][i] = t;
        }
    }
        
}

int main(void)
{
    vector< vector<int> > mat(5, vector<int>(5));

    for (int i = 0; i < mat.size(); i++)
        for (int j = 0; j < mat[i].size(); j++)
            mat[i][j] = 10*i + j;
    
    print_matrix(mat);

    convert_matrix(&mat);

    print_matrix(mat);
}

