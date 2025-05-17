#include <bits/stdc++.h>
using namespace std;

vector<int> C_time, T_time, W_time, R_time;
float Completion_time(vector<int>& A_time, vector<int>& B_time, vector<int>& order, int n) {
    vector<int> rem_time = B_time;
    vector<bool> started(n, false);
    int complete = 0, time = 0, total = 0;
    while (complete < n) {
        int idx = -1, min_bt = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (A_time[i] <= time && rem_time[i] > 0 && rem_time[i] < min_bt) {
                min_bt = rem_time[i];
                idx = i;
            }
        }
        if (idx == -1) {
            time++;
            continue;
        }
        if (!started[idx]) {
            R_time[idx] = time - A_time[idx];
            started[idx] = true;
        }
        rem_time[idx]--;
        time++;
        if (rem_time[idx] == 0) {
            C_time[idx] = time;
            complete++;
            total += time;
        }
    }
    return float(total) / n;
}
float Turnaround_time(vector<int>& A_time, int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        T_time[i] = C_time[i] - A_time[i];
        sum += T_time[i];
    }
    return float(sum) / n;
}

float Waiting_time(vector<int>& B_time, int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        W_time[i] = T_time[i] - B_time[i];
        sum += W_time[i];
    }
    return float(sum) / n;
}
float Response_time(int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) sum += R_time[i];
    return float(sum) / n;
}
int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    vector<string> PID(n);
    vector<int> A_time(n), B_time(n);
    C_time.resize(n), T_time.resize(n), W_time.resize(n), R_time.resize(n, -1);

    cout << "Enter Process ID: ";
    for (int i = 0; i < n; ++i) cin >> PID[i];

    cout << "Enter Arrival Time: ";
    for (int i = 0; i < n; ++i) cin >> A_time[i];

    cout << "Enter Burst Time: ";
    for (int i = 0; i < n; ++i) cin >> B_time[i];

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);

    float avg_ct = Completion_time(A_time, B_time, order, n);
    float avg_tat = Turnaround_time(A_time, n);
    float avg_wt = Waiting_time(B_time, n);
    float avg_rt = Response_time(n);

    cout << "\nProcess ID       : "; for (auto& id : PID) cout << id << " ";
    cout << "\nCompletion Time  : "; for (auto ct : C_time) cout << ct << " ";
    cout << "\nTurnaround Time  : "; for (auto t : T_time) cout << t << " ";
    cout << "\nWaiting Time     : "; for (auto w : W_time) cout << w << " ";
    cout << "\nResponse Time    : "; for (auto r : R_time) cout << r << " ";

    cout << "\n\nAverage Completion Time : " << avg_ct;
    cout << "\nAverage Turnaround Time : " << avg_tat;
    cout << "\nAverage Waiting Time    : " << avg_wt;
    cout << "\nAverage Response Time   : " << avg_rt << "\n";

    return 0;
}
