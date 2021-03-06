func findPeakElement(nums []int) int {
    l := 0
    r := len(nums) - 1
    for l < r {
        mid := ( l + r ) / 2
        if nums[mid] > nums[mid + 1] {
            if mid == 0 || nums[mid] > nums[mid - 1] {
                return mid
            }
            r = mid
        } else {
            l = mid + 1
        }
    }
    return l
}