class Robot {
public:
    int index=0;
    bool moved=false;
    vector<vector<int>>path;
    Robot(int width, int height) {
        for(int i=0;i<width;i++)
        {
            path.push_back({i,0,0});
        }
        for(int j=1;j<height;j++)
        {
            path.push_back({width-1,j,1});
        }
        for(int i=width-2;i>=0;i--)
        {
            path.push_back({i,height-1,2});
        }
        for(int j=height-2;j>0;j--)
        {
            path.push_back({0,j,3});
        }
        path[0][2]=3;
    }
    
    void step(int num) {
        moved=true;
        index=(index+num)%path.size();
    }
    
    vector<int> getPos() {
        return {path[index][0],path[index][1]};
    }
    
    string getDir() {
        if(!moved)
        {
            return "East";
        }
        int d=path[index][2];
        if(d==0) return "East";
        else if(d==1) return "North";
        else if(d==2) return "West";
        return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */