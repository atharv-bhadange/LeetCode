function map(arr: number[], fn: (n: number, i: number) => number): number[] {
    let ans: number[] = [];
    for(let i: number=0; i<arr.length; i++) {
        ans.push(fn(arr[i],i));
    }
    return ans;
};