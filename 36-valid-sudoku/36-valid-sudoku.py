class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        """
        Indexing a box:
            box_len = sqrt(9)
            idx = (r // box_len) * box_len + (c // box_len)
        
        Approach 1:
            O(n^2), both time and space
            row = [[0]] * N; col =[[0]] * N; box = [[0]] * N
            for r in row:
                for c in col:
                    pos = board[r][c] - 1 #from 0 to 8
                    
                    //check row
                    if bool(row[r][pos]): return false
                    row[r][pos] = 1
                    
                    //check col
                    if bool(row[c][pos]): return false
                    row[c][pos] = 1
                    
                    //check box
                    idx = (r // box_len) * box_len + (c // box_len) 
                    if bool(box[idx][pos]): return false
                    row[idx][pos] = 1
            return true
            
        Approach 2: Same time, but space == O(N); Use bitmasking
                row = [0] * N; col =[0] * N; box = [0] * N
                ...
                if row[r] & (1 << pos): ret false
                row[r] |= (1 << pos)
                ...
        """
        board_len = len(board)
        box_len = sqrt(board_len)
        row = [0] * board_len; col =[0] * board_len; box = [0] * board_len
        for r in range(board_len):
            for c in range(board_len):
                if board[r][c] == '.': continue
                pos = int(board[r][c]) - 1
                box_idx = int((r // box_len) * box_len + (c // box_len))
                
                if row[r] & (1 << pos): return False
                if col[c] & (1 << pos): return False
                if box[box_idx] & (1 << pos): return False
                
                row[r] |= 1 << pos
                col[c] |= 1 << pos
                box[box_idx] |= 1 << pos
        return True