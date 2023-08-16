type ToBeOrNotToBe = {
    toBe: (val: any) => boolean;
    notToBe: (val: any) => boolean;
};

function expect(val: any): ToBeOrNotToBe {
    let t: ToBeOrNotToBe = {
        toBe: (otherVal) => {
            if(otherVal === val) return true;
            throw "Not Equal";
        },
        notToBe: (otherVal) => {
            if(otherVal !== val) return true;
            throw "Equal";
        }
    }
    
    return t;
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */