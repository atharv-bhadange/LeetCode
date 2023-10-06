func integerBreak(n int) int {
    if n <= 3 {
        return n-1
    }
    var q float64 = float64(n/3)
    var rem float64 = float64(n%3)
    
    if rem == 0 {
        return int(math.Pow(3, q))
    }
    if rem == 1 {
        return int(math.Pow(3,q-1)*4)
    }
    
    return int(math.Pow(3, q)*2)
}