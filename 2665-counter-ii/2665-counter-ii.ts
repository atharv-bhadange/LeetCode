type ReturnObj = {
    increment: () => number,
    decrement: () => number,
    reset: () => number,
}

function createCounter(init: number): ReturnObj {
    let x: number = init;
    let r: ReturnObj = {
        increment: () => ++x,
        decrement: () => --x,
        reset: function() {
            x = init;
            return x;
        }
    }

    return r;
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */