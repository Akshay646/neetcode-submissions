class Solution {
public:
    // Trapping Rain Water - prefix/suffix max, O(n) time, O(n) space.
    // NOT brute force (that's O(n^2), rescanning both sides per bar).
    int trap(vector<int>& height) {
        // Water above bar i is capped by the shorter of the two walls
        // around it, since water overflows over the shorter one:
        //     water[i] = min(leftMax, rightMax) - height[i]
        //
        // The usual approach keeps two arrays. One is enough: pass 1's
        // value is already consumed when pass 2 writes, so the same
        // slot is reused. This is the EXCLUSIVE variant - bar i is not
        // treated as its own wall. See the note at the bottom for the
        // inclusive variant.
        int n = height.size();
        vector<int> cappedBars(n);

        // Pass 1: write first, then update -> strict prefix max.
        // cappedBars[i] = max(height[0..i-1]), i.e. the wall to the LEFT.
        // Seeding to 0 (not height[0]) keeps n == 0 safe: nothing is
        // indexed before the loop.
        int leftMax = 0;
        for (int i = 0; i < n; i++) {
            cappedBars[i] = leftMax;
            leftMax = max(leftMax, height[i]);
        }

        // Pass 2: same order -> strict suffix max, folded in as we go.
        // rightMax at the moment of the write = max(height[i+1..n-1]).
        // After this, cappedBars[i] = min(strictLeftMax, strictRightMax)
        // = the shorter of the two real walls around i.
        int rightMax = 0;
        for (int i = n - 1; i >= 0; i--) {
            cappedBars[i] = min(cappedBars[i], rightMax);
            rightMax = max(rightMax, height[i]);
        }

        // Pass 3: accumulate. The clamp is LOAD-BEARING here, not
        // defensive - a bar taller than everything on both sides has
        // min(strictL, strictR) < height[i], so the term goes negative.
        int totalTrappedWater = 0;
        for (int i = 0; i < n; i++) {
            totalTrappedWater += max(0, cappedBars[i] - height[i]);
        }
        return totalTrappedWater;

        // ---- INCLUSIVE variant (same total, only the statement order
        // inside each loop flips) ----
        //   Pass 1: leftMax = max(leftMax, height[i]);
        //           cappedBars[i] = leftMax;          // max(height[0..i])
        //   Pass 2: rightMax = max(rightMax, height[i]);
        //           cappedBars[i] = min(cappedBars[i], rightMax);
        //   Both maxes then contain height[i], so cappedBars[i] >=
        //   height[i] always and pass 3 needs no clamp:
        //           totalTrappedWater += cappedBars[i] - height[i];
        //
        // Why both agree - lattice identity:
        //   min(max(a,h), max(b,h)) - h = max(h, min(a,b)) - h
        //                              = max(0, min(a,b) - h)
        // Inclusive hides the clamp inside the maxes; exclusive makes it
        // explicit at accumulation. Exclusive matches how the problem is
        // stated out loud, so it reads more honestly.
    }
};