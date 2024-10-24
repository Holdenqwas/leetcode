function minSubArrayLen(target, nums) {
    if (nums.length == 1) {
        if (nums[0] >= target)
            return 1;
        return 0;
    }
    var i = 0, j = 1;
    var sum = nums[i];
    if (sum == target)
        return 1;
    var minCount = 0;
    var curCount = 0;
    while (i != j) {
        sum += nums[j++];
        if (sum >= target) {
            curCount = j - i;
            if (minCount == 0 || minCount > curCount)
                minCount = curCount;
        }
        while (sum > target) {
            sum -= nums[i++];
            if (sum >= target) {
                curCount = j - i;
                if (minCount == 0 || minCount > curCount)
                    minCount = curCount;
            }
        }
        if (j >= nums.length)
            break;
    }
    return minCount;
}
;
var nums = [2, 3, 1, 2, 4, 3];
var target = 7;
console.log(minSubArrayLen(target, nums));
nums = [1, 4, 4];
target = 4;
console.log(minSubArrayLen(target, nums));
nums = [1, 1, 1, 1, 1, 1, 1, 1];
target = 11;
console.log(minSubArrayLen(target, nums));
nums = [1, 2, 3, 4, 5];
target = 11;
console.log(minSubArrayLen(target, nums));
nums = [10, 2, 3];
target = 6;
console.log(minSubArrayLen(target, nums));
nums = [10, 2, 3];
target = 6;
console.log(minSubArrayLen(target, nums));
