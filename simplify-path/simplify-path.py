class Solution:
    def simplifyPath(self, path: str) -> str:
        final_path = []
        for i in path.split("/"):
            if i == '..' and final_path:
                final_path.pop(-1)
            elif i and not (i == "." or i == ".."):
                final_path.append(i)
        return "/" + "/".join(final_path)