#include <bits/stdc++.h>
using namespace std;

vector<int> process;
vector<int> memory;
int p_size,mem_size;

void First_Fit()
{
    int j=0;
    vector<pair<int, int>> ans;
    vector<bool>mem(mem_size, false);

    for (int i = 0; i < p_size; i++)
    {
        bool flag = false;
        for (int j = 0; j < mem_size; j++)
        {
            if (!mem[j] && process[i] <= memory[j])
            {
                ans.push_back({memory[j], process[i]});
                mem[j] = true;
                flag = true;
                break;
            }
        }
        if(!flag)
        {
            cout << "Process " << process[i] << " in Starvation" << endl;
        }
    }
    for (auto x : ans)
    {
        cout << "Memory " << x.first << " allocated to Process " << x.second << endl;
    }
}

void Best_Fit()
{
    vector<pair<int, int>> ans;
    vector<bool> mem(mem_size, false);

    for (int i = 0; i < p_size; i++)
    {
        int best_idx = -1;
        for (int j = 0; j < mem_size; j++)
        {
            if (!mem[j] && process[i] <= memory[j])
            {
                if (best_idx == -1 || memory[j] < memory[best_idx])
                {
                    best_idx = j;
                }
            }
        }
        if (best_idx != -1)
        {
            ans.push_back({memory[best_idx], process[i]});
            mem[best_idx] = true;
        }
        else
        {
            cout << "Process " << process[i] << " in Starvation" << endl;
        }
    }
    for (auto x : ans)
    {
        cout << "Memory " << x.first << " allocated to Process " << x.second << endl;
    }
}

void Worst_Fit()
{
    vector<pair<int, int>> ans;
    vector<bool> mem(mem_size, false);

    for (int i = 0; i < p_size; i++)
    {
        int worst_idx = -1;
        for (int j = 0; j < mem_size; j++)
        {
            if (!mem[j] && process[i] <= memory[j])
            {
                if (worst_idx == -1 || memory[j] > memory[worst_idx])
                {
                    worst_idx = j;
                }
            }
        }
        if (worst_idx != -1)
        {
            ans.push_back({memory[worst_idx], process[i]});
            mem[worst_idx] = true;
        }
        else
        {
            cout << "Process " << process[i] << " in Starvation" << endl;
        }
    }
    for (auto x : ans)
    {
        cout << "Memory " << x.first << " allocated to Process " << x.second << endl;
    }
}

int main()
{
    cout << "Enter size of process and memory: ";
    cin >> p_size >> mem_size;
    process.resize(p_size);
    memory.resize(mem_size);

    cout << "Enter value of processes: ";
    for (int i = 0; i < p_size; i++)
    {
        cin >> process[i];
    }

    cout << "Enter value of memory: ";
    for (int i = 0; i < mem_size; i++)
    {
        cin >> memory[i];
    }

    cout<<endl<<"First Fit : "<<endl;
    First_Fit();
    cout<<endl<<"Best Fit : "<<endl;
    Best_Fit();
    cout<<endl<<"Worst Fit : "<<endl;
    Worst_Fit();

    return 0;
}
