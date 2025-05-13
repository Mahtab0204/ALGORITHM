#include <bits/stdc++.h>
using namespace std;

vector<int> C_time;
vector<int> T_time;
vector<int> W_time;
vector<int> R_time;

float Completion_time(vector<int>& A_time, vector<int>& B_time, int n)
{
    int sum = 0, total_sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum < A_time[i])
        {
            sum = A_time[i];
        }
        sum += B_time[i];
        C_time.push_back(sum);
        total_sum += sum;
    }
    return float(total_sum) / n;
}

float Turnaround_time(vector<int>& A_time, vector<int>& C_time, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        T_time.push_back(C_time[i] - A_time[i]);
        sum += T_time[i];
    }
    return float(sum) / n;
}

float Waiting_time(vector<int>& B_time, vector<int>& T_time, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        W_time.push_back(T_time[i] - B_time[i]);
        sum += W_time[i];
    }
    return float(sum) / n;
}

float Response_time(vector<int>& A_time, vector<int>& C_time, int n)
{
    R_time.push_back(0);
    int sum = R_time[0];
    for (int i = 1; i < n; i++)
    {
        R_time.push_back(C_time[i - 1] - A_time[i]);
        sum += R_time[i];
    }
    return float(sum) / n;
}

int main()
{
    int n;
    cout << "Enter number of Process : ";
    cin >> n;

    vector<string> PID(n);
    cout << "Enter Process ID : ";
    for (int i = 0; i < n; i++)
    {
        cin >> PID[i];
    }

    vector<int> A_time(n), B_time(n);
    cout << "Enter Arrival Time : ";
    for (int i = 0; i < n; i++)
    {
        cin >> A_time[i];
    }

    cout << "Enter Burst Time : ";
    for (int i = 0; i < n; i++)
    {
        cin >> B_time[i];
    }

    vector<int> process_order(n);
    iota(process_order.begin(), process_order.end(), 0);
    sort(process_order.begin(), process_order.end(), [&](int i, int j)
    {
        return A_time[i] < A_time[j];
    });

    vector<int> A_time_sorted(n), B_time_sorted(n);
    vector<string> PID_sorted(n);
    for (int i = 0; i < n; i++)
    {
        A_time_sorted[i] = A_time[process_order[i]];
        B_time_sorted[i] = B_time[process_order[i]];
        PID_sorted[i] = PID[process_order[i]];
    }

    Completion_time(A_time_sorted, B_time_sorted, n);
    Turnaround_time(A_time_sorted, C_time, n);
    Waiting_time(B_time_sorted, T_time, n);
    Response_time(A_time_sorted, C_time, n);

    cout<<endl<< "Gantt Chart :  |";
    for (auto i : PID_sorted)
    {
        cout << i << " |";
    }
    cout << endl<<endl;
    cout << "Process ID       :  ";
    for (auto i : PID_sorted)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "Completion Time  :  ";
    for (auto i : C_time)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "Turnaround Time  :  ";
    for (auto i : T_time)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "Waiting Time     :  ";
    for (auto i : W_time)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "Response Time    :  ";
    for (auto i : R_time)
    {
        cout << i << " ";
    }
    cout << endl<<endl;

    cout << "Average Completion Time : " << Completion_time(A_time_sorted, B_time_sorted, n) << endl;
    cout << "Average Turnaround Time : " << Turnaround_time(A_time_sorted, C_time, n) << endl;
    cout << "Average Waiting Time    : " << Waiting_time(B_time_sorted, T_time, n) << endl;
    cout << "Average Response Time   : " << Response_time(A_time_sorted, C_time, n) << endl;

    return 0;
}
