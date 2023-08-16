type F = (x: number) => number;

function compose(functions: F[]): F {
    functions.reverse();
	return function(x) {
        functions.forEach(function(val){
            x = val(x);
        })
        return x;
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */