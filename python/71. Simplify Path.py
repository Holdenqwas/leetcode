

class Solution:
    def simplifyPath(self, path: str) -> str:
        path_parts = path.split('/')

        arr_path = []
        for part in path_parts:
            if not part or part == '/' or part == '.': continue
        
            if part == '..':
                if arr_path:
                    arr_path.pop()
            else:
                arr_path.append(part)
        
        out_path = '/' + '/'.join(arr_path)
        return out_path
    
sol = Solution()

print(sol.simplifyPath('/home/'), '/home')
print(sol.simplifyPath("/home//foo/"), "/home/foo")
print(sol.simplifyPath("/home/user/Documents/../Pictures"), "/home/user/Pictures")
print(sol.simplifyPath("/../"), "/")
print(sol.simplifyPath("/.../a/../b/c/../d/./"), "/.../b/d")
