class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<char, char> left = {{'N','W'}, {'W','S'}, {'S','E'},{'E','N'}};
        unordered_map<char, char> right = {{'N','E'}, {'E','S'}, {'S','W'}, {'W','N'}};
        set<pair<int, int>> obs;
        for (auto &o : obstacles) {
            obs.insert({o[0], o[1]});
        }
        int x=0,y=0;
        int direction='N';
        int ans=0;
        for(auto cmd:commands)
        {
            if(cmd==-2)
            {
                direction=left[direction];
            }
            else if(cmd==-1)
            {
                direction=right[direction];
            }
            else
            {
                for(int i=0;i<cmd;i++)
                {
                    int nx=x,ny=y;
                    if(direction=='N')
                    {
                        ny+=1;
                    }
                    else if (direction == 'E') {
                    nx += 1;
                    } 
                    else if (direction == 'S') {
                        ny -= 1;
                    } 
                    else {
                        nx -= 1;
                    }
                    if(obs.count({nx,ny}))
                    break;
                    x=nx,y=ny;
                    ans=max(ans,x*x+y*y);
                }
            }
        } 
        return ans;   
    }
};