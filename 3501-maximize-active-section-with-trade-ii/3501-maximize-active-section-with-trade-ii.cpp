class Solution {
public:
    vector<int> seg;

    void build(int idx, int left, int right, vector<int>& arr) {
        if (left == right) {
            seg[idx] = arr[left];
            return;
        }

        int mid = (left + right) / 2;
        build(idx * 2 + 1, left, mid, arr);
        build(idx * 2 + 2, mid + 1, right, arr);

        seg[idx] = max(seg[idx * 2 + 1], seg[idx * 2 + 2]);
    }

    int query(int idx, int left, int right, int ql, int qr) {
        if (right < ql || left > qr)
            return 0;

        if (ql <= left && right <= qr)
            return seg[idx];

        int mid = (left + right) / 2;

        return max(
            query(idx * 2 + 1, left, mid, ql, qr),
            query(idx * 2 + 2, mid + 1, right, ql, qr)
        );
    }

    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {

        int n = s.size();
        int ones = count(s.begin(), s.end(), '1');

        vector<pair<int,int>> zeroBlocks;

        int i = 0;

        while(i < n){
            if(s[i]=='1'){
                i++;
                continue;
            }

            int st = i;

            while(i<n && s[i]=='0')
                i++;

            zeroBlocks.push_back({st,i-1});
        }

        int blocks = zeroBlocks.size();

        if(blocks < 2)
            return vector<int>(queries.size(), ones);

        vector<int> start(blocks), finish(blocks), length(blocks);

        for(int i=0;i<blocks;i++){
            start[i]=zeroBlocks[i].first;
            finish[i]=zeroBlocks[i].second;
            length[i]=finish[i]-start[i]+1;
        }

        vector<int> adjacent(blocks-1);

        for(int i=0;i<blocks-1;i++)
            adjacent[i]=length[i]+length[i+1];

        seg.assign(4*adjacent.size(),0);

        build(0,0,adjacent.size()-1,adjacent);

        vector<int> ans;

        for(auto &q:queries){

            int L=q[0];
            int R=q[1];

            int first =
                lower_bound(finish.begin(),finish.end(),L)-finish.begin();

            int last =
                upper_bound(start.begin(),start.end(),R)-start.begin()-1;

            int gain=0;

            if(first<last){

                int leftPart =
                    finish[first]-max(start[first],L)+1;

                int rightPart =
                    min(finish[last],R)-start[last]+1;

                if(last-first==1){

                    gain=leftPart+rightPart;

                }else{

                    int candidate1=
                        leftPart+length[first+1];

                    int candidate2=
                        rightPart+length[last-1];

                    int candidate3=
                        query(
                            0,
                            0,
                            adjacent.size()-1,
                            first+1,
                            last-2
                        );

                    gain=max({candidate1,candidate2,candidate3});
                }
            }

            ans.push_back(ones+gain);
        }

        return ans;
    }
};