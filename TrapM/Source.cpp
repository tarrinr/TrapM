#include "Twin.h"

typedef std::vector<double> vec;

vec gvec(Twin&);
void dvec(Twin&, const vec&);
double trapm(const double&, const int&, const vec&);

int main() {

	Twin t("Trapezoidal Rule");

	double a, b, h;
	int n;
	vec y;

	while (true) {

		t.println("Enter lower bound 'a'.");
		t.display();

		std::cin >> a;
		std::cin.ignore(1000, '\n');
		std::cin.clear();

		t.println("Enter upper bound 'b'.");
		t.display();

		std::cin >> b;
		std::cin.ignore(1000, '\n');
		std::cin.clear();

		t.println("Enter subintervals 'n'.");
		t.display();

		std::cin >> n;
		std::cin.ignore(1000, '\n');
		std::cin.clear();

		h = (b - a) / n;

		t.println("Confirm input:");
		t.println();
		t.println("Lower bound a = ");
		t.print(a);
		t.println("Upper bound b = ");
		t.print(b);
		t.println("Subintervals n = ");
		t.print(n);
		t.println("Subintervals size h = ");
		t.print(h);
		t.println();
		t.println("Enter 'x' to save and continue.");
		t.display();

		char input;
		std::cin >> input;
		std::cin.ignore(1000, '\n');
		std::cin.clear();
		if (input == 'x' || input == 'X') break;
	}

	t.println("Choose an option:");
	t.println();
	t.println("[1] Use built in function f(x).");
	t.println("[2] Enter vector y of n+1 elements.");
	t.display();

	int input;
	std::cin >> input;
	std::cin.ignore(1000, '\n');
	std::cin.clear();

	if (input == 1)
		for (double i = a; i <= b; i+=h)
			y.push_back(4*i*i+6);

	if (input == 2) {

		while (true) {

			t.println("Enter the first element of Vector y.");
			t.println("Example: 2.3");
			t.display();

			double el;
			std::cin >> el;
			std::cin.ignore(1000, '\n');
			std::cin.clear();
			y.push_back(el);

			for (int i = 0; i < n; i++) {
				t.println("Vector y:");
				t.println();
				dvec(t, y);
				t.println("Enter the next element.");
				t.display();

				std::cin >> el;
				std::cin.ignore(1000, '\n');
				std::cin.clear();
				y.push_back(el);
			}

			t.println("Vector y:");
			t.println();
			dvec(t, y);
			t.println("Enter 'x' to save and continue.");
			t.display();

			char save;
			std::cin >> save;
			std::cin.ignore(1000, '\n');
			std::cin.clear();

			if (save == 'x' || save == 'X') break;

			else y.clear();

		}

	}

	double answer = trapm(h, n, y);

	t.println("Integral = ");
	t.print(answer);
	t.println();
	t.println("Press enter to exit. . .");
	t.display();

	std::cin.ignore(1000, '\n');
	std::cin.clear();

	return EXIT_SUCCESS;
}

double trapm(const double& h, const int& n, const vec& y) {

	double sum = y.front() + y.back();

	for (int i = 1; i < int(y.size()) - 1; i++)
		sum += 2 * y[i];

	return .5 * h * sum;

}

vec gvec(Twin& t) {

	vec b;
	double in;
	std::string input;

	std::getline(std::cin, input);
	std::stringstream iss(input);
	iss >> in;
	b.push_back(in);

	while (true) {

		t.println("Vector:");
		t.println();
		dvec(t, b);
		t.println("Enter the next element.");
		t.println("Enter 'x' to save and continue.");
		t.display();

		std::getline(std::cin, input);
		std::stringstream iss(input);
		iss >> in;

		if (input == "x" || input == "X") return b;
		else b.push_back(in);

	}
}

void dvec(Twin& t, const vec& vec) {

	for (auto&& i : vec) {
		t.println("[ ");
		t.print(i);
		t.print(" ]");
	}

	t.println();
}