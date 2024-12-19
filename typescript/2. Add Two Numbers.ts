// https://leetcode.com/problems/add-two-numbers/description/?envType=study-plan-v2&envId=top-interview-150

class ListNode {
    val: number
    next: ListNode | null
    constructor(val?: number, next?: ListNode | null) {
        this.val = (val === undefined ? 0 : val)
        this.next = (next === undefined ? null : next)
    }
}


function addTwoNumbers(l1: ListNode | null, l2: ListNode | null): ListNode | null {
    if (l1 === null) return l2;
    else if (l2 === null) return l1;
    else if (l1 === null && l2 === null) return null;

    let start: ListNode | null = null;
    let cur: ListNode | null = null;
    let needAddOne = 0;

    while (l1 && l2) {
        let value = l1.val + l2.val + needAddOne;
        needAddOne = 0;

        if (value > 9) {
            needAddOne = 1;
            value %= 10;
        }
        if (cur) {
            const temp = new ListNode(value);
            cur.next = temp;
            cur = temp;
        }
        else {
            start = new ListNode(value);
            cur = start;
        }
        l1 = l1.next;
        l2 = l2.next;
    }

    let last: ListNode | null;
    if (l1) {
        last = l1;
    }
    else {
        last = l2;
    }

    if (last) {
        while (needAddOne) {
            let value = last.val + needAddOne;
            needAddOne = 0;

            if (value > 9) {
                needAddOne = 1;
                value %= 10;
            }

            if (cur) {
                const temp = new ListNode(value);
                cur.next = temp;
                cur = temp;
            }
            if (last.next) {
                last = last.next;
            }
            else {
                last = null;
                break;
            }
        }

        if (cur && last) {
            cur.next = last;
        }
    }
    
    if (needAddOne) {
        if (cur) cur.next = new ListNode(1);
    }

    return start;
};


// l1 = [2, 4, 3], l2 = [5, 6, 4]
let l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
let l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
let out = addTwoNumbers(l1, l2);
let str = '708 == ';
while (out) {
    str += out.val;
    out = out.next;
}
console.log(str);

// l1 = [0], l2 = [0]
l1 = new ListNode(0);
l2 = new ListNode(0);
out = addTwoNumbers(l1, l2);
str = '0 == ';
while (out) {
    str += out.val;
    out = out.next;
}
console.log(str);

// l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
l1 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))))));
l2 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))));
out = addTwoNumbers(l1, l2);
str = '89990001 == ';
while (out) {
    str += out.val;
    out = out.next;
}
console.log(str);

// l1 = [5], l2 = [5]
l1 = new ListNode(5);
l2 = new ListNode(5);
out = addTwoNumbers(l1, l2);
str = '01 == ';
while (out) {
    str += out.val;
    out = out.next;
}
console.log(str);

// l1 = [1,8], l2 = [0]
l1 = new ListNode(1, new ListNode(8));
l2 = new ListNode(0);
out = addTwoNumbers(l1, l2);
str = '1,8 == ';
while (out) {
    str += out.val;
    out = out.next;
}
console.log(str);
