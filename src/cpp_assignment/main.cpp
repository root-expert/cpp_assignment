#include <iostream>
#include "ppm/ppm.h"
#include "Image.h"
#include "FilterLinear.h"
#include "FilterGamma.h"
#include "FilterBlur.h"

using namespace std;

int main(int argc, char* argv[]) {
	std::string name, path, filename, extension;
	name = argv[argc - 1];

	// If there is no extension exit!
	if (name.find(".") == std::string::npos) {
		std::cerr << "Not a valid filename. No extension given!" << std::endl;
		return 1;
	}
	// Returns .ppm extension
	extension = name.substr(name.find_last_of("."));
	// Returns the path with / in the end
	path = name.substr(0, name.find_last_of("/") + 1);
	//Returns ImageXX.ppm
	filename = name.substr(name.find_last_of("/") + 1);
	// Remove .ppm extension. Returns ImageXX
	filename = filename.substr(0, filename.find_last_of("."));

	image::Image image;
	bool loaded = image.load(path + filename, extension);
	if (!loaded)
		return 1;

	int i = 0;
	while (i < (argc - 1)) {
		if (strcmp(argv[i], "-f") == 0) {
			i++;
			if (strcmp(argv[i], "linear") == 0) {
				// Check if arguments are valid
				if (!isdigit(*argv[i + 1]) || !isdigit(*argv[i + 2]) || !isdigit(*argv[i + 3])
					|| !isdigit(*argv[i + 4]) || !isdigit(*argv[i + 5]) || !isdigit(*argv[i + 6])) {
					cerr << "Wrong arguments!" << endl;
					return 1;
				}
				// A vector RGB
				float a_r = atof(argv[i + 1]);
				float a_g = atof(argv[i + 2]);
				float a_b = atof(argv[i + 3]);
				
				// C vector RGB
				float c_r = atof(argv[i + 4]);
				float c_g = atof(argv[i + 5]);
				float c_b = atof(argv[i + 6]);
				
				Color a_vector(a_r, a_g, a_b);
				Color c_vector(c_r, c_g, c_b);

				image::FilterLinear linear(a_vector, c_vector);
				image = linear << image;
			} else if (strcmp(argv[i], "gamma") == 0) {
				// Check if arguments are valid
				if (!isdigit(*argv[i + 1])) {
					cerr << "Wrong arguments" << endl;
					return 1;
				}
				// Gamma value
				float g = atof(argv[i + 1]);

				image::FilterGamma gamma(g);
				image = gamma << image;
			}
			else if (strcmp(argv[i], "blur") == 0) {
				int N = atoi(argv[i + 1]);

				image::FilterBlur blur(N);
				image = blur << image;
			}
		}
		else //Next argument
			i++;
	}

	bool saved = image.save(path + "filtered_" + filename, extension);
	if (!saved) {
		std::cerr << "Failed" << std::endl;
		return 1;
	}
	std::cout << "Image filtered!" << std::endl;
	return 0;
}