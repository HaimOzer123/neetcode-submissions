#include <vector>
using namespace std;

class Solution {
private:
    static const int TABLE_SIZE = 2048;

    struct Entry {
        int key;
        int value;
        bool used;
    };

    Entry table[TABLE_SIZE];

    int hashFunc(int key) {
        long long x = key;

        if (x < 0) {
            x = -x;
        }

        return x % TABLE_SIZE;
    }

    bool find(int key, int& value) {
        int startIndex = hashFunc(key);

        for (int step = 0; step < TABLE_SIZE; step++) {
            int pos = (startIndex + step) % TABLE_SIZE;

            if (!table[pos].used) {
                return false;
            }

            if (table[pos].key == key) {
                value = table[pos].value;
                return true;
            }
        }

        return false;
    }

    void insert(int key, int value) {
        int startIndex = hashFunc(key);

        for (int step = 0; step < TABLE_SIZE; step++) {
            int pos = (startIndex + step) % TABLE_SIZE;

            if (!table[pos].used) {
                table[pos].key = key;
                table[pos].value = value;
                table[pos].used = true;
                return;
            }
        }
    }

public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // reset hash table
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i].used = false;
        }

        for (int i = 0; i < nums.size(); i++) {

            int complement = target - nums[i];
            int previousIndex;

            if (find(complement, previousIndex)) {
                return {previousIndex, i};
            }

            insert(nums[i], i);
        }

        return {};
    }
};