class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        if not bool(len(intervals)): return 0
        intervals.sort(key=lambda interval: interval[0])
        end_time_heap = []
        heapq.heappush(end_time_heap, intervals[0][1])
        for interval in intervals[1:]:
            if end_time_heap[0] <= interval[0]:
                heapq.heappop(end_time_heap)
            heapq.heappush(end_time_heap, interval[1])
        return len(end_time_heap)