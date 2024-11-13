from typing import List
from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        store = defaultdict(list)

        for word in strs:
            key = ''.join(sorted(word))
            store[key].append(word)

        return [value for value in store.values()]

sol = Solution()
strs = ["eat","tea","tan","ate","nat","bat"]
print(sol.groupAnagrams(strs))

strs = [""]
print(sol.groupAnagrams(strs))

strs = ["a"]
print(sol.groupAnagrams(strs))
