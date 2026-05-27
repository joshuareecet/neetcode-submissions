class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        l = defaultdict(int)

        for a,b in zip(s,t):
            l[a] += 1
            l[b] -= 1
        for v in l.values():
            if v > 0:
                return False

        return True