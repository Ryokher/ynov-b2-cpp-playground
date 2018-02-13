#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;
        //code rajouté
        long long A1=(long long)A;
printf("%#llx\r\n", A1);

//How to put the leading '_'
char buf[64];
sprintf(buf, "%+15.2f", B);
char *p=buf;
while(*p ==' ') {*p='_'; ++p;}
puts(buf);
printf("%.9E\r\n", C);
//code rajouté fin
	}
	return 0;

}