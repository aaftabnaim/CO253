#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// structure to store element and its position
struct ElementPosition {
	int element;
	int position;
};

// function to find minimum number of swaps required to sort
// the array
int minSwaps(int arr[], int n)
{
	// create an array of ElementPosition structures
	struct ElementPosition arrPos[n];
	for (int i = 0; i < n; i++) {
		arrPos[i].element = arr[i];
		arrPos[i].position = i;
	}

	// sort the array by element values to get right
	// position of every element as second element of
	// structure
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arrPos[i].element > arrPos[j].element) {
				struct ElementPosition temp = arrPos[i];
				arrPos[i] = arrPos[j];
				arrPos[j] = temp;
			}
		}
	}

	// initialize a boolean array to keep track of visited
	// elements
	bool vis[n];
	for (int i = 0; i < n; i++) {
		vis[i] = false;
	}

	// initialize result variable
	int ans = 0;

	// traverse array elements
	for (int i = 0; i < n; i++) {
		// already swapped and corrected or already present
		// at correct pos
		if (vis[i] || arrPos[i].position == i) {
			continue;
		}

		// find out the number of elements in this cycle and
		// add in ans
		int cycle_size = 0;
		int j = i;
		while (!vis[j]) {
			vis[j] = true;

			// move to next node
			j = arrPos[j].position;
			cycle_size++;
		}

		// update answer by adding current cycle
		if (cycle_size > 0) {
			ans += (cycle_size - 1);
		}
	}

	// return result
	return ans;
}

// driver code
int main()
{
	int arr[] = { 1, 5, 4, 3, 2 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("%d", minSwaps(arr, n));
	return 0;
}
