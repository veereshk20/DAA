#include <iostream>
#include <vector>
#include <algorithm>

void greedy_schedule(std::vector<int>& arrival_times, std::vector<int>& execution_times) {
    int n = arrival_times.size();
    std::vector<std::pair<int, int>> jobs;

    for (int i = 0; i < n; i++) {
        jobs.push_back({arrival_times[i], execution_times[i]});
    }

    std::sort(jobs.begin(), jobs.end());

    std::vector<int> p1_schedule, p2_schedule;
    int p1_time = 0, p2_time = 0;
    float waiting_time = 0;

    for (int i = 0; i < n; i++) {
        if (p1_time <= p2_time) {
            p1_schedule.push_back(jobs[i].second);
            waiting_time += p1_time;
            p1_time += jobs[i].second;
        } else {
            p2_schedule.push_back(jobs[i].second);
            waiting_time += p2_time;
            p2_time += jobs[i].second;
        }
    }

    std::cout << "Processor 1 Schedule:" << std::endl;
    for (const auto& time : p1_schedule) {
        std::cout << time << " ";
    }
    std::cout << std::endl;

    std::cout << "Processor 2 Schedule:" << std::endl;
    for (const auto& time : p2_schedule) {
        std::cout << time << " ";
    }
    std::cout << std::endl;

    std::cout << "Average Waiting Time: " << waiting_time / n << std::endl;
}

int main() {
    std::vector<int> arrival_times = {1,2,0,4};
    std::vector<int> execution_times = {1,2,1,3};

    greedy_schedule(arrival_times, execution_times);

    return 0;
}
