class Solution
{
public:
    int findMinDifference(vector<string> &timePoints)
    {

        // convert time string into minutes integer value
        vector<int> minutes;

        for (int i = 0; i < timePoints.size(); i++)
        {
            string current = timePoints[i];

            int hours = stoi(current.substr(0, 2));
            int min = stoi(current.substr(3, 2));

            int totalMinutes = hours * 60 + min;
            minutes.push_back(totalMinutes);
        }

        // Step 2:- Sort
        sort(minutes.begin(), minutes.end());

        // Step -3 - difference and calculate min diff
        int mini = INT_MAX;
        int n = minutes.size();

        for (int i = 0; i < n - 1; i++)
        {
            int diff = minutes[i + 1] - minutes[i];
            mini = min(mini, diff);
        }

        // STEP 4 :-
        int lastDiff = (minutes[0] + 1440) - minutes[n - 1];
        mini = min(mini, lastDiff);

        return mini;
    }
};