#include <iostream>

using namespace std;

int gcd(int a, int b){
    int temp;

    while ( b != 0){
        temp = b;
        b = a%b;
        a = temp;    
    }

    return a;
}

int main(){
    cout << "최대 공약수를 구해드리겠습니다." <<endl;
    cout << "원하는 두수를 입력해주세요." << endl;
    
    int a, b;

    cin >> a >> b;

    int result = gcd(a, b);

    cout << "최대 공약수는 " << result <<"입니다." << endl;

    return 0;    
}