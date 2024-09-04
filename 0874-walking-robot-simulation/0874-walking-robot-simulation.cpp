class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int,int>> obs_maps;
        int orientation = 1;
        int movement[4][4] = {{1,0},{0,1},{-1,0},{0,-1}};
        int x = 0, y = 0, x_max = 0, y_max = 0;
        for(auto &obs:obstacles) {
            obs_maps.insert(pair<int,int>(obs[0],obs[1]));
        }
        int max_distance = 0;
        for(int command:commands) {
            if(command == -1) {
                orientation  = (orientation - 1 +4) % 4;
            }
            else if (command == -2) {
                orientation = (orientation+1)%4;
            }
            else {
                for(int i = 0; i < command; i++) {
                    if (obs_maps.find(pair<int,int>(x+movement[orientation][0], 
                   y+movement[orientation][1])) == obs_maps.end() ) {
                        x += movement[orientation][0];
                        y += movement[orientation][1];
                    }
                    else
                        break;
                }
                if (x*x+y*y >max_distance)
                    max_distance = x*x+y*y;
            }
        }
        return max_distance;
    }
};