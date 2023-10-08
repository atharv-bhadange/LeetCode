func minProcessingTime(processorTime []int, tasks []int) int {
    sort.Sort(sort.Reverse(sort.IntSlice(tasks)))
    sort.Ints(processorTime)
    fmt.Println(tasks)
    fmt.Println(processorTime)
    
    n:=len(processorTime)
    ans := 0
    for i:=0; i<n; i++ {
        start := i*4
        curr := processorTime[i] + tasks[start]
        for j:=start+1; j<start+4; j++ {
            curr = max(curr, processorTime[i]+tasks[j]) 
        }
        ans = max(ans, curr)
    }
    
    return ans
}

func max(a,b int) int {
    if a < b {
        return b
    }
    return a
}