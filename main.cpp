# quickSort

#include <iostream>
#include <sstream>

using namespace std;

bool read_numbers(int & n, int * array)
{
	string string;
	getline(cin, string);
	istringstream stream(string);
	bool success = true;
	for (int i = 0; i < n; ++i) {
		if (!(stream >> array[i])) {
			success = false;
			break;
		}
	}
	return success;
}


void quicksort(int * array, int left, int right)
{
	int i = left, j = right;
	int x = array[j];
	int col = right - left + 1;

	if (col > 1) {
	while (i < j) {
		if (array[i] > x && i < j) {
			if (i == j - 1) {
				swap(array[i], array[j]);
				j--;
			}
			else{
				swap(array[j], array[j - 1]);
				swap(array[i], array[j]);
				j--;
			}
		}
		else i++;
	}
		quicksort(array, left, j - 1);
		quicksort(array, j + 1, right);
	}
}

int main() {
	int n;
	string str;
	getline(cin, str);
	istringstream stream(str);
	if (stream >> n) {
		int * array = new int[n];
		if (read_numbers(n, array)) {

			quicksort(array, 0, n - 1);

			for (int i = 0; i < n; i++) {
				cout << array[i] << " ";
			}
			delete [] array;

		}
		else {
			cout << "An error has occured while reading input data.";
			delete [] array;
		}
	}
	else {
		cout << "An error has occured while reading input data.";
	}

	cin.get();
	cin.get();
	return 0;
}
