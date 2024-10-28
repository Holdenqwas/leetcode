function lengthOfLongestSubstring(s: string): number {
    if (s.length < 2) return s.length;
    let maxLength = 1;
    let map = new Map<string, number>();
    map.set(s[0], 0);

    let start = 0;
    let cur : number | undefined = 0;
    for (let i = 1; i < s.length; i++) {
        if (map.has(s[i])) {
            cur = map.get(s[i]);
            if (cur != undefined){
                while (start <= cur) {
                    map.delete(s[start++]);
                }
            }
        }
        map.set(s[i], i);
        if (map.size > maxLength) maxLength = map.size;
    }
    return maxLength;
};


// console.log("Output = ", lengthOfLongestSubstring("abcabcbb"), "Correct aswer = 3");
// console.log("Output = ", lengthOfLongestSubstring("bbbbb"), "Correct aswer = 1");
// console.log("Output = ", lengthOfLongestSubstring("pwwkew"), "Correct aswer = 3");
console.log("Output = ", lengthOfLongestSubstring("bpfbhmipx"), "Correct aswer = 7");
