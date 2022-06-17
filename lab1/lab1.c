#define E 0.001 
#define PI 3.1415

double abs_v( double x ) {
	if ( x > 0 ) return x;
	else return -1 * x;
}


double sin_acc( double x ) {
	double tmp = x;
	double sum = tmp;
	int n = 0;
    
	while (abs_v(tmp) > E) {
		n++;
		tmp = tmp * (-1) * (x * x) / (2 * n) / (2 * n + 1);
		sum += tmp;
	}

	return sum;
}


int test_sin() {
	int r = 0;

	r = r || (abs_v(abs_v(sin_acc(0)) - 0 >= E)));
	r = r || (abs_v(abs_v(sin_acc(PI/2)) - 1 >= E));
	r = r || (abs_v(abs_v(sin_acc(PI)) - 0 >= E));
	r = r || (abs_v(abs_v(sin_acc(3 * PI/2)) - 1>= E));
	r = r || (abs_v(abs_v(sin_acc(2 * PI)) - 0 >= E));
    
    // wrong:
    r = r || (abs_v(abs_v(sin_acc(PI/3)) - 0.866) >= E);

	return r;
}


int main() {
	return test_sin();
}
