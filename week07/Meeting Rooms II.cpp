/**
 * Definition of Interval:
 * public class Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this.start = start;
 *         this.end = end;
 *     }
 * }
 */

public class Solution {
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    public int minMeetingRooms(List<Interval> intervals) {
        map<int, int>stats;
        for(auto interval : intervals)
        {
            stats[interval[0]++];
            stats[interval[1]--];
        }
        int curr = 0, min_room = 0;
        for(autro stat : stats)
        {
            curr += stat.second;
            min_room = max(min_room, curr);
        }
        return min_room;

    }
}
