class Solution(object):
    def subarraysWithKDistinct(self, A, K):
        dicL = collections.defaultdict(int)
        dicR = collections.defaultdict(int)
        res = 0
        l = 0
        r = 0
        for i in range(len(A)):
            dicL[A[i]] += 1
            dicR[A[i]] += 1
            while len(dicL) > K:
                dicL[A[l]] -= 1
                if dicL[A[l]] == 0:
                    del dicL[A[l]]
                l += 1
            while len(dicR) > K-1:
                dicR[A[r]] -= 1
                if dicR[A[r]] == 0:
                    del dicR[A[r]]
                r += 1
            res += r-l
        return res