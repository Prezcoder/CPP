#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& arr) {
	for (uint32_t i = 1; i < arr.size(); ++i) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && key < arr[j]) {
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
	}
}

void merge(std::vector<int>& arr, const std::vector<int>& left, const std::vector<int>& right) {
	uint32_t i = 0, j = 0, k = 0;

	while (i < left.size() && j < right.size()) {
		if (left[i] < right[j]) {
			arr[k] = left[i];
			++i;
		} else {
			arr[k] = right[j];
			++j;
		}
		++k;
	}

	while (i < left.size()) {
		arr[k] = left[i];
		++i;
		++k;
	}

	while (j < right.size()) {
		arr[k] = right[j];
		++j;
		++k;
	}
}

void mergeInsertionSort(std::vector<int>& arr, uint32_t threshold) {
	if (arr.size() > threshold) {
		uint32_t mid = arr.size() / 2;
		std::vector<int> left(arr.begin(), arr.begin() + mid);
		std::vector<int> right(arr.begin() + mid, arr.end());

		mergeInsertionSort(left, threshold);
		mergeInsertionSort(right, threshold);

		merge(arr, left, right);
	} else {
		insertionSort(arr);
	}
}

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " <num1> <num2> ... <numN>" << std::endl;
		return 1;
	}
	std::vector<int> arr;
	for (int i = 1; i < argc; ++i) {
		arr.push_back(std::stoi(argv[i]));
	}

	std::cout << "Tableau non trié : ";
	for (uint32_t i = 0; i < arr.size(); ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	uint32_t threshold = 2;

	mergeInsertionSort(arr, threshold);

	std::cout << "Tableau trié : ";
	for (uint32_t i = 0; i < arr.size(); ++i) {
		std::cout << arr[i] << " ";
	}

	return 0;
}
