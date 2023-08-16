async function addTwoPromises(promise1: Promise<number>, promise2: Promise<number>): Promise<number> {
    const a: number = await promise1;
    const b: number = await promise2;
    
    return new Promise(resolve => setTimeout(() => resolve(a+b), 5));
};

/**
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
 */