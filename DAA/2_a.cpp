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
