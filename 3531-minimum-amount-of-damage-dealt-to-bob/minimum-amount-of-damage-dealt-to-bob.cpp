class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {

        vector<pair<int,int>> ratio;
        using ll = long long;
        ll totsum =0;
        
        
        for(int i =0; i<health.size(); i++){
            if(health[i]%power == 0){
                health[i] = health[i]/power;
                ratio.push_back({damage[i], i});
                totsum += damage[i];
            }
            else{
                health[i] = health[i]/power +1;
                ratio.push_back({damage[i], i});
                totsum += damage[i];
            }

        }

         sort(ratio.begin(), ratio.end(), [&](auto &a, auto &b) {
            return (ll)a.first * health[b.second] >
                   (ll)b.first * health[a.second];
        });

        ll sum = 0;
        for(auto &it : ratio){
            sum += totsum*(health[it.second]);
            totsum = totsum-damage[it.second];
        }

        return sum ;



    }
};