#include <bits/stdc++.h>

#define IO ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define endl '\n'

// Parameters
//#define sizeM 16
//#define sizeInput 8
//#define num_state_accept 1

using namespace std;

void rwArchive();

/* Format input
#Size of matrix
#Canonical vectors for 0, M0
#Canonical vectors for 1, M1
#Number state of acceptance
#Position state of acceptance
#Size input
#Word Input
*/

/* M0
1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
*/


/* M1
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1
*/

int main()
{
    IO;
    rwArchive(); 

    // Size of the matrix
    int sizeM; cin >> sizeM;
    int matrix_Zero[sizeM][sizeM];
    int matrix_One[sizeM][sizeM];

    // Fill matrix Zero
    for (int i = 0; i < sizeM; i++)
    {
        for (int j = 0; j < sizeM; j++)
        {
            cin >> matrix_Zero[i][j];
        }
    }

    // Fill matrix One
    for (int i = 0; i < sizeM; i++)
    {
        for (int j = 0; j < sizeM; j++)
        {
            cin >> matrix_One[i][j];
        }
    }

    //
    int num_state_accept; cin >> num_state_accept;
    set <int> set_accept;
    for(int i = 0; i < num_state_accept; i++)
    {
        int aux; cin >> aux;
        set_accept.insert(aux);
    }

    // Fill input
    int sizeInput; cin >> sizeInput;
    int vec_input[sizeInput];
    for (int i = 0; i < sizeInput; i++)
    {
        cin >> vec_input[i];
    }

    // Vector with initial state in 1 and fill zero
    int vec_state[sizeM], copy_vec_state[sizeM];
    fill(vec_state, vec_state + sizeM, 0); vec_state[0] = 1;
    fill(copy_vec_state, copy_vec_state + sizeM, 0);

    // Process the input
    for (int k = 0; k < sizeInput; k++)
    {
        int value = vec_input[k];
        //cout << value << " ";
        // If in the position that there is a 0, multiply by the matrix 0
        if (value == 0)
        {
            for (int i = 0; i < sizeM; i++)
            {
                int result = 0;
                for (int j = 0; j < sizeM; j++)
                {
                    int state_Matrix = matrix_Zero[i][j], state_Now = vec_state[j];
                    result |= (state_Now & state_Matrix);
                }
                copy_vec_state[i] = result;
            }
        }

        // If in the position that there is a 1, multiply by the matrix 1
        if (value == 1)
        {
            for (int i = 0; i < sizeM; i++)
            {
                int result = 0;
                for (int j = 0; j < sizeM; j++)
                {
                    int state_Matrix = matrix_One[i][j], state_Now = vec_state[j];
                    result |= (state_Now & state_Matrix);
                }
                copy_vec_state[i] = result;
            }
        }

        // Update the states
        cout << "Vector of states after processing the value "<< value  << endl;
        for (int i = 0; i < sizeM; i++)
        {
            vec_state[i] = copy_vec_state[i];
            cout << vec_state[i] << " ";
        }
        cout << endl;
    }
    //cout << endl;

    // Print answer
    cout << "------------- ANSWER ------------" << endl;
    for (auto state: set_accept)
    {
        if(vec_state[state - 1] == 1){
            cout << "This word is in the languague" << endl;
            return 0;
        }
    }

    cout << "This word isn't in the languague" << endl;

    return 0;
}

void rwArchive()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

// By Sebastian