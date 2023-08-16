type Fn = (...args: any[]) => any

function once(fn: Fn): Fn {
let f: boolean = true;
    
  return function (...args) {
    if(f) {
        f = false;
        return fn(...args);
    }
    else
        return undefined;
  };
}

/**
 * let fn = (a,b,c) => (a + b + c)
 * let onceFn = once(fn)
 *
 * onceFn(1,2,3); // 6
 * onceFn(2,3,6); // returns undefined without calling fn
 */