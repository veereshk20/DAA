#include <iostream>
#include <vector>
#include <algorithm>

void scheduleJobs(std::vector<int>& entryTimes, std::vector<int>& workDurations) {
    int numJobs = entryTimes.size();
    std::vector<std::pair<int, std::pair<int, int>>> jobList;

    for (int i = 0; i < numJobs; i++) {
        jobList.push_back({entryTimes[i], {workDurations[i], i}});
    }

    std::sort(jobList.begin(), jobList.end());

    std::vector<int> processor1Jobs, processor2Jobs;
    int timeOnProcessor1 = 0, timeOnProcessor2 = 0;
    float totalWaitTime = 0;

    for (int i = 0; i < numJobs; i++) {
        if (timeOnProcessor1 <= timeOnProcessor2) {
            processor1Jobs.push_back(jobList[i].second.second);
            totalWaitTime += std::max(0, timeOnProcessor1 - jobList[i].first);
            timeOnProcessor1 = std::max(timeOnProcessor1, jobList[i].first) + jobList[i].second.first;
        } else {
            processor2Jobs.push_back(jobList[i].second.second);
            totalWaitTime += std::max(0, timeOnProcessor2 - jobList[i].first);
            timeOnProcessor2 = std::max(timeOnProcessor2, jobList[i].first) + jobList[i].second.first;
        }
    }
    std::cout << totalWaitTime / numJobs << std::endl;
}

int main() {
    int numJobs;
    std::cin >> numJobs;

    std::vector<int> entryTimes(numJobs);
    std::vector<int> workDurations(numJobs);

    for (int i = 0; i < numJobs; ++i) {
        std::cin >> entryTimes[i];
    }

    for (int i = 0; i < numJobs; ++i) {
        std::cin >> workDurations[i];
    }

    scheduleJobs(entryTimes, workDurations);

    return 0;
}








//dfasdfas
#include <iostream>
#include <vector>
#include <algorithm>

struct Task {
    int arrival_time;
    int execution_time;
    int index;
};

bool compareByArrivalTime(const Task& a, const Task& b) {
    return a.arrival_time < b.arrival_time;
}

void scheduleTasks(std::vector<int>& arrival_times, std::vector<int>& execution_times) {
    int n = arrival_times.size();
    std::vector<Task> tasks(n);

    for (int i = 0; i < n; i++) {
        tasks[i].arrival_time = arrival_times[i];
        tasks[i].execution_time = execution_times[i];
        tasks[i].index = i;
    }

    std::sort(tasks.begin(), tasks.end(), compareByArrivalTime);

    std::vector<int> completion_times(n, -1);
    std::vector<int> dp(n);

    completion_times[0] = tasks[0].arrival_time + tasks[0].execution_time;
    dp[0] = completion_times[0] - tasks[0].arrival_time;

    for (int i = 1; i < n; i++) {
        completion_times[i] = std::max(completion_times[i-1], tasks[i].arrival_time) + tasks[i].execution_time;
        dp[i] = completion_times[i] - tasks[i].arrival_time;
    }

    for (int i = n - 1; i >= 0; i--) {
        if (i < n - 1 && dp[i] == dp[i+1]) {
            std::cout << "Task " << tasks[i].index << " starts at " << std::max(completion_times[i] - tasks[i].execution_time, tasks[i].arrival_time) 
                    << " and ends at " << completion_times[i] << std::endl;
        }
        else {
            std::cout << "Task " << tasks[i].index << " starts at " << tasks[i].arrival_time 
                    << " and ends at " << completion_times[i] << std::endl;
        }
    }
}

int main() {
    std::vector<int> arrival_times = {1, 2, 3, 4};
    std::vector<int> execution_times = {2, 1, 2, 1};

    scheduleTasks(arrival_times, execution_times);

    return 0;
}




