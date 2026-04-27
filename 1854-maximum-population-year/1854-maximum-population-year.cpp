class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int>populationByYear(101,0);
        for(int i=0;i<logs.size();i++)
        {
            populationByYear[logs[i][0]-1950]++;
            populationByYear[logs[i][1]-1950]--;
        }

        int maximumPopulation=0;
        int maximumPopulationyear=1950;
        int currentPopulation=0;
        for(int i=0;i<101;i++)
        {
            currentPopulation+=populationByYear[i];
            if(currentPopulation>maximumPopulation)
            {
                maximumPopulation=currentPopulation;
                maximumPopulationyear=i+1950;
            }
        }
        return maximumPopulationyear;
    }
};