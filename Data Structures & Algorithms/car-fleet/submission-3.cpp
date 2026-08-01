class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        // Store each car as (position, speed)
        vector<pair<int, int>> cars;
        for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }

        // Sort cars by position (left -> right)
        sort(cars.begin(), cars.end());

        // Stack stores the arrival time of every distinct fleet.
        // Invariant:
        // After processing a car, the stack represents all fleets formed
        // by cars to its right (i.e., closer to the target).
        stack<double> fleets;

        // Process from the car nearest to the target towards the farthest.
        // This way, when examining a car, we already know the fleet
        // immediately ahead that it could potentially catch.
        for (int i = cars.size() - 1; i >= 0; i--) {

            auto [pos, sp] = cars[i];

            // Time required for the current car to reach the target
            double tta = (double)(target - pos) / sp;

            // Case 1:
            // No fleet exists yet -> this car starts the first fleet.
            //
            // Case 2:
            // If this car takes more time to reach the target than the
            //fleet ahead,
            // it cannot catch that fleet, so it starts a new fleet.
            if (fleets.empty() || tta > fleets.top()) {
                fleets.push(tta);
            }

            // Otherwise:
            // Can catch the fleet ahead -> joins that fleet.
            // Current car reaches the target earlier or at the same time
            // as the fleet ahead. Therefore it catches that fleet before
            // the destination and becomes part of it.
            // No push is needed because the fleet's arrival time remains
            // the slower one (already stored on the stack).
        }

        // Each stack entry corresponds to one distinct fleet.
        return fleets.size();
    }
};