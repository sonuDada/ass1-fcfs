#include <algorithm>
#include <iostream>
using namespace std;
struct Process {
  int processID;
  int burstTime;
  int arrivalTime;
  int ct;
};
void findWaitingTime(Process processes[], int n, int wt[]) {
  sort(processes, processes + n, [](const Process &a, const Process &b) {
    return a.arrivalTime < b.arrivalTime;
  });
  int ct = 0;
  for (int i = 0; i < n; i++) {
    ct += processes[i].burstTime;
    processes[i].ct = ct;
    wt[i] = ct - processes[i].burstTime - processes[i].arrivalTime;
  }
}
void findTurnAroundTime(Process processes[], int n, int wt[], int tat[]) {
  for (int i = 0; i < n; i++)
    tat[i] = processes[i].burstTime + wt[i];
}

void findavgTime(Process processes[], int n) {
  int wt[n], tat[n], total_wt = 0, total_tat = 0;
  findWaitingTime(processes, n, wt);
  findTurnAroundTime(processes, n, wt, tat);
  cout << "Processes "
       << " Arrival time "
       << " Burst time "
       << " Waiting time "
       << " Turn around time\n";
  for (int i = 0; i < n; i++) {
    total_wt = total_wt + wt[i];
    total_tat = total_tat + tat[i];
    cout << " " << processes[i].processID << "\t\t" << processes[i].arrivalTime
         << "\t\t" << processes[i].burstTime << "\t " << wt[i] << "\t\t "
         << tat[i] << endl;
  }
  cout << "Average waiting time = " << (float)total_wt / (float)n;
  cout << "\nAverage turn around time = " << (float)total_tat / (float)n;
}
int main() {
  int n;
  cout << "Enter the number of processes: ";
  cin >> n;
  Process processes[n];
  cout << "Enter burst time and arrival time for each process:\n";
  for (int i = 0; i < n; i++) {
    cout << "Enter burst time for process " << i + 1 << ": ";
    cin >> processes[i].burstTime;
    cout << "Enter arrival time for process " << i + 1 << ": ";
    cin >> processes[i].arrivalTime;
    processes[i].processID = i + 1;
  }
  findavgTime(processes, n);
  return 0;
}
