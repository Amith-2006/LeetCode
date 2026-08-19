class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
    int n = position.size();
    vector<pair<int,int>> cars(n);
    for (int i = 0; i < n; i++) cars[i] = {position[i], speed[i]};
    sort(cars.rbegin(), cars.rend());

    int fleets = 0;
    double lastTime = -1;
    for (auto& [p, s] : cars) {
        double time = (double)(target - p) / s;
        if (time > lastTime) {
            fleets++;
            lastTime = time;
        }
    }
    return fleets;
}
};