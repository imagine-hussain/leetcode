from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        return ( [ [(i, it) for i, it in enumerate(sorted(nums)) if target - it in {num: i for i, num in enumerate(sorted(nums))}][0][0], next( filter( lambda x: x[1] + [(i, it) for i, it in enumerate(sorted(nums)) if target - it in {num: i for i, num in enumerate(sorted(nums))}][0][1] == target and x != [(i, it) for i, it in enumerate(sorted(nums)) if target - it in {num: i for i, num in enumerate(sorted(nums))}][0] , [(i, it) for i, it in enumerate(sorted(nums)) if target - it in {num: i for i, num in enumerate(sorted(nums))}]))[0] ] if len([ [(i, it) for i, it in enumerate(sorted(nums)) if target - it in {num: i for i, num in enumerate(sorted(nums))}][0][0], next( filter( lambda x: x[1] + [(i, it) for i, it in enumerate(sorted(nums)) if target - it in {num: i for i, num in enumerate(sorted(nums))}][0][1] == target and x != [(i, it) for i, it in enumerate(sorted(nums)) if target - it in {num: i for i, num in enumerate(sorted(nums))}][0] , [(i, it) for i, it in enumerate(sorted(nums)) if target - it in {num: i for i, num in enumerate(sorted(nums))}]))[0] ]) > 1 else "no")

    # Hashmap soln
    # def twoSum(self, nums: List[int], target: int) -> List[int]:
    #     hashmap = 
    #     for i, n in enumerate(nums):
    #         if n in hashmap:
    #             hashmap[n].append(i)
    #         else:
    #             hashmap[n] = [i]
    #     for k, n in enumerate(nums):
    #         if (target - n) in hashmap:
    #             for i in hashmap[target - n]:
    #                 if i != k:
    #                     return [k, i]
    #     return "no"

