#include <iostream>
#include <fstream>
#include "ppm/ppm.h"

using namespace std;

float* image::ReadPPM(const char* filename, int* w, int* h) {
	ifstream file(filename, ios::binary);

	if (!file.is_open()) {
		cerr << "Could not open file specified! Please check the path and try again..." << endl;
		return nullptr;
	}

	string format;
	int width, height;
	float max_val;

	// Read the file header
	file >> format >> width >> height >> max_val;

	/*cout << format << endl 
		<< width << endl 
		<< height << endl
		<< max_val << endl;*/

	if (format != "P6") {
		cerr << "We support only P6 file foramt!" << endl;
		return nullptr;
	}

	if (max_val > 255) {
		cerr << "We support only 24bit files!" << endl;
		return nullptr;
	}

	int size = 3 * width * height;

	// Asign width and height to w and h pointer respectively to return them.
	*w = width;
	*h = height;

	// Read \n or space or \t and then continue to read the actual data;
	file.get();

	float* data = new float[size];
	for (int i = 0; i < size; i++) {
		data[i] = file.get() / max_val;
	}

	return data;
}

bool image::WritePPM(const float* data, int w, int h, const char* filename) {
	if (data == nullptr)
		return false;

	ofstream file(filename, ios::binary);

	if (!file.is_open()) {
		cerr << "Could not open file for writing!" << endl;
		return false;
	}

	// Write the file header
	file << "P6" << endl
		<< w << endl
		<< h << endl
		<< 255 << endl;

	int size = 3 * w * h;
	for (int i = 0; i < size; i++)
		file.put(data[i] * 255.0f);

	// Delete data after writing them back to file
	delete[] data;

	return true;
}