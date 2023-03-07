#include <vector>

using namespace std;

class NaiveSolution
{
public:
    long long minimumTime(vector<int> &time, int totalTrips)
    {
        long long count = 1;
        int n_trips = 0;

        while (n_trips < totalTrips)
        {
            for (int i = 0; i < time.size(); i++)
                if (count % time[i] == 0)
                    n_trips += 1;

            count++;
        }

        return count - 1;
    }
};

class Solution
{
public:
    long long minimumTime(vector<int> &time, int totalTrips)
    {
        // Binary search solution based on the observation that
        // the number of trips over time is "sorted".
        int i;
        long long center;
        long long n_trips;
        long long lower_bound;
        long long upper_bound;
        long long min_time = time[0];

        for (i = 1; i < time.size(); i++)
            if (time[i] < min_time)
                min_time = time[i];

        lower_bound = min_time;
        upper_bound = min_time * totalTrips;

        while (lower_bound < upper_bound)
        {
            center = (lower_bound + upper_bound) / 2;

            n_trips = 0;
            for (i = 0; i < time.size(); i++)
                n_trips += center / time[i];

            if (n_trips >= totalTrips)
                upper_bound = center;
            else
                lower_bound = center + 1;
        }

        return lower_bound;
    }
};

int main()
{
    // add testes
    return 0;
}
