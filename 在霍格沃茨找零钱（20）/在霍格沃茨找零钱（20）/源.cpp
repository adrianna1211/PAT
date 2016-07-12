#include <iostream>
#include <math.h>
using namespace std;

int main(){
	long pg, ps, pk;
	long ag, as, ak;
	long diff_g, diff_s, diff_k;
	scanf("%ld.%ld.%ld", &pg, &ps, &pk);
//	cout << pg << ps << pk;
	scanf("%ld.%ld.%ld", &ag, &as, &ak);
	diff_k = ak - pk;
	diff_s = as - ps;
	diff_g = ag - pg;
	if (diff_k < 0) {
		diff_k += 29;
		diff_s--;
	}
	if (diff_s < 0){
		diff_s += 17;
		diff_g--;
	} 
	//Èç¹ûÇ®²»¹»
	if (diff_g < 0){
		diff_k = pk - ak;
		diff_s = ps - as;
		diff_g = pg - ag;
		if (diff_k < 0) {
			diff_k += 29;
			diff_s--;
		}
		if (diff_s < 0){
			diff_s += 17;
			diff_g--;
		}
//		diff_k = -diff_k;
//		diff_s = -diff_s;
		diff_g = -diff_g;

	}
	cout << diff_g << '.' << diff_s << '.' << diff_k << endl;
	return 0;
}