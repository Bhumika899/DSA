// Structure to bundle meeting details together
struct Meeting {
    int start;
    int finish;
    int id; // 1-based index
};

class Solution {
public:
    // Custom comparator function must be 'static' to be used inside a class method
    static bool meetingComparator(const Meeting& m1, const Meeting& m2) {
        if (m1.finish != m2.finish) {
            return m1.finish < m2.finish;
        }
        return m1.id < m2.id;
    }

    vector<int> maxMeetings(vector<int>& s, vector<int>& f) {
        int n = s.size();
        vector<Meeting> meetings(n);

        // 1. Combine data
        for (int i = 0; i < n; i++) {
            meetings[i].start = s[i];
            meetings[i].finish = f[i];
            meetings[i].id = i + 1; 
        }

        // 2. Sort using the custom static comparator
        sort(meetings.begin(), meetings.end(), meetingComparator);

        vector<int> selected_indices;
        int last_finish_time = -1;

        // 3. Greedy selection
        for (int i = 0; i < n; i++) {
            if (meetings[i].start > last_finish_time) {
                selected_indices.push_back(meetings[i].id);
                last_finish_time = meetings[i].finish;
            }
        }

        // 4. Sort final result indices
        sort(selected_indices.begin(), selected_indices.end());

        return selected_indices;
    }
};
