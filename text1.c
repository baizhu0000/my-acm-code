#include <stdio.h>
#include <string.h>
#define maxn 105
int az[maxn] = {0}, ad[maxn] = {0}, bz[maxn] = {0}, bd[maxn] = {0};
int ansz[maxn] = {0}, ansd[maxn] = {0};
int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}
int main() {
    char a[maxn], b[maxn];
    scanf("%s%s", a, b);
    
    int m = -1, n = -1;
    for (int i = 0; i < maxn; i++) {
        if (a[i] == '.') {
            m = i; 
            break;
        }
        if (a[i] == '\0') {
            m = -1; 
            break;
        }
    }
    for (int i = 0; i < maxn; i++) {
        if (b[i] == '.') {
            n = i; 
            break;
        }
        if (b[i] == '\0') {
            n = -1; 
            break;
        }
    }
    int num = 0, lenaz = 0, lenbz = 0;
    if (m == -1) {
        for (int i = strlen(a) - 1; i >= 0; i--) {
            az[num] = a[i] - '0';
            num++;
        }
        lenaz = num;
    } else {
        for (int i = m - 1; i >= 0; i--) {
            az[num] = a[i] - '0';
            num++;
        }
        lenaz = num;
    }
    num = 0;
    if (n == -1) {
        for (int i = strlen(b) - 1; i >= 0; i--) {
            bz[num] = b[i] - '0';
            num++;
        }
        lenbz = num;
    } else {
        for (int i = n - 1; i >= 0; i--) {
            bz[num] = b[i] - '0';
            num++;
        }
        lenbz = num;
    }
    num = 0;
    int lenad = 0, lenbd = 0;
    if (m == -1) {
        lenad = 0;
    } else {
        for (int i = m + 1; i < strlen(a); i++) {
            ad[num] = a[i] - '0';
            num++;
        }
        lenad = num;
    }
    num = 0;
    if (n == -1) {
        lenbd = 0;
    } else {
        for (int i = n + 1; i < strlen(b); i++) {
            bd[num] = b[i] - '0';
            num++;
        }
        lenbd = num;
    }
    int maxz = max(lenaz, lenbz);
    int maxd = max(lenad, lenbd);
    int carry = 0;
    if (maxd > 0) {
        for (int i = maxd - 1; i >= 0; i--) {
            int da = 0;
            int db = 0;
            if (i < lenad) {
                da = ad[i];
            } else {
                da = 0;
            }
            
            if (i < lenbd) {
                db = bd[i];
            } else {
                db = 0;
            }    
            int sum = da + db + carry;
            ansd[i] = sum % 10;
            carry = sum / 10;
        }
    }
    for (int i = 0; i < maxz; i++) {
        int da = 0;
        int db = 0;
        
        if (i < lenaz) {
            da = az[i];
        } else {
            da = 0;
        }
        
        if (i < lenbz) {
            db = bz[i];
        } else {
            db = 0;
        }
        int sum = da + db + carry;
        ansz[i] = sum % 10;
        carry = sum / 10;
    }
    int len = maxz;
    if (carry > 0) {
        ansz[len] = carry;
        len++;
    }
    int start = len - 1;
    if (start < 0 && maxd == 0) {
        printf("0\n");
        return 0;
    }
    while (start > 0 && ansz[start] == 0) {
        start = start - 1;
    }
    for (int i = start; i >= 0; i--) {
        printf("%d", ansz[i]);
    }
    if (maxd > 0) {
        printf(".");
        
        for (int i = 0; i < maxd; i++) {
            printf("%d", ansd[i]);
        }
    }
    printf("\n");
    return 0;
}