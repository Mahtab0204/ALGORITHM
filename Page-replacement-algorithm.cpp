#include<bits/stdc++.h>
using namespace std;

int main()
{
    int fsize, psize;
    cin >> fsize >> psize;

    queue<int> q;
    for (int i = 0; i < psize; i++)
    {
        int val;
        cin >> val;
        q.push(val);
    }

    vector<int>frame;
    int pageFaults = 0;
    int hits = 0;

    while(!q.empty())
    {
        int currentPage = q.front();
        q.pop();

        auto it = find(frame.begin(), frame.end(), currentPage);

        if (it != frame.end())
        {
            hits++;
        }
        else
        {
            pageFaults++;

          if (frame.size() < fsize)
            {
                frame.push_back(currentPage);
            }
            else
            {
                frame.erase(frame.begin());
                frame.push_back(currentPage);
            }
        }
    }

    cout << "Hit Ratio: " <<((double)hits / psize)*100<<" %"<<endl;
    cout << "Miss Ratio: "<<((double)pageFaults / psize)*100<<" %"<<endl;

    return 0;
}
/*3 12
7 0 1 2 4 6 4 2 1 0 2 0*/
