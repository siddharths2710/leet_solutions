class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        v1_list, v2_list = version1.split('.'), version2.split('.')
        l1, l2 = len(v1_list), len(v2_list)
        i, compare = 0, 0
        while not compare and i < l1 and i < l2:
            if int(v1_list[i]) > int(v2_list[i]): compare = 1
            elif int(v1_list[i]) < int(v2_list[i]): compare = -1
            i += 1
        while not compare and i < l1:
            if int(v1_list[i]) > 0: compare = 1
            i += 1
        while not compare and i < l2:
            if int(v2_list[i]) > 0: compare = -1
            i += 1
        return compare