func lower(nums []int, target int) int {
    l,r := 0, len(nums)-1
    
    for l<=r {
        mid := (l+r)/2
        
        if nums[mid] < target {
            l = mid+1
        } else {
            r = mid-1
        }
    }
    
    if l==len(nums) || nums[l] != target {
        return -1
    }
    
    return l
}

func upper(nums []int, target int) int {
    l,r := 0, len(nums)-1
    
    for l<=r {
        mid := (l+r)/2
        
        if nums[mid] > target {
            r = mid-1
        } else {
            l = mid+1
        }
    }
    
    if r<0 || nums[r] != target {
        return -1
    }
    
    return r
}

func searchRange(nums []int, target int) []int {
    ans := make([]int, 2)
    
    ans[0] = lower(nums, target)
    ans[1] = upper(nums, target)
    
    return ans
}