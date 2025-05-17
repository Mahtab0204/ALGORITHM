#include <bits/stdc++.h>
using namespace std;

vector<int> C_time, T_time, W_time, R_time;
float Completion_time(vector<int>& A_time, vector<int>& B_time, vector<int>& order, int n) {
    int time = 0, total = 0;
    vector<bool> done(n, false);

    for (int i = 0; i < n; ++i) {
        int idx = -1, min_bt = INT_MAX;
        for (int j = 0; j < n; ++j) {
            if (!done[j] && A_time[j] <= time && B_time[j] < min_bt) {
                min_bt = B_time[j];
                idx = j;
            }
        }
        if (idx == -1) {
            time++;
            i--;
            continue;
        }
        time = max(time, A_time[idx]) + B_time[idx];
        C_time[idx] = time;
        done[idx] = true;
        total += time;
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

float Response_time(vector<int>& A_time, int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        R_time[i] = W_time[i];
        sum += R_time[i];
    }
    return float(sum) / n;
}
int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    vector<string> PID(n);
    vector<int> A_time(n), B_time(n);
    C_time.resize(n), T_time.resize(n), W_time.resize(n), R_time.resize(n);

    cout << "Enter Process ID: ";
    for (int i = 0; i < n; i++) cin >> PID[i];

    cout << "Enter Arrival Time: ";
    for (int i = 0; i < n; i++) cin >> A_time[i];

    cout << "Enter Burst Time: ";
    for (int i = 0; i < n; i++) cin >> B_time[i];

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);

    float avg_ct = Completion_time(A_time, B_time, order, n);
    float avg_tat = Turnaround_time(A_time, n);
    float avg_wt = Waiting_time(B_time, n);
    float avg_rt = Response_time(A_time, n);

    cout << "\nProcess ID       : "; for (auto& id : PID) cout << id << " ";
    cout << "\nCompletion Time  : "; for (auto& ct : C_time) cout << ct << " ";
    cout << "\nTurnaround Time  : "; for (auto& tt : T_time) cout << tt << " ";
    cout << "\nWaiting Time     : "; for (auto& wt : W_time) cout << wt << " ";
    cout << "\nResponse Time    : "; for (auto& rt : R_time) cout << rt << " ";

    cout << "\n\nAverage Completion Time : " << avg_ct;
    cout << "\nAverage Turnaround Time : " << avg_tat;
    cout << "\nAverage Waiting Time    : " << avg_wt;
    cout << "\nAverage Response Time   : " << avg_rt << "\n";

    return 0;
}
