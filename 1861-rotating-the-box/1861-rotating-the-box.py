class Solution:
    def rotateTheBox(self, boxGrid: List[List[str]]) -> List[List[str]]:
        m=len(boxGrid)
        n=len(boxGrid[0])
        rotated=[[None]*m for _ in range(n)]

        for i in range(m):
            for j in range(n):
                rotated[j][m-1-i]=boxGrid[i][j] 

        for col in range(m):
            empty=n-1
            for row in range(n-1,-1,-1):
                if rotated[row][col]=='*':
                    empty=row-1
                elif rotated[row][col]=='#':
                    rotated[row][col]='.'
                    rotated[empty][col]='#'

                    empty-=1

        return rotated
