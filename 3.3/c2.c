#include <stdio.h>
#include <stdint.h>
#include <string.h>

// 打印 32-bit 二进制
void print_binary_32(uint32_t num) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i == 31 || i == 23) { // IEEE 754 格式：符号|指数|尾数
            printf("|");
        }
    }
    printf("\n");
}

// 打印 64-bit 二进制
void print_binary_64(uint64_t num) {
    for (int i = 63; i >= 0; i--) {
        printf("%ld", (num >> i) & 1);
        if (i == 63 || i == 52) { // IEEE 754 格式：符号|指数|尾数
            printf("|");
        }
    }
    printf("\n");
}

// 将整数转换为二进制字符串
void int_to_binary_string(uint64_t num, char *binary_str, int bits) {
    for (int i = bits - 1; i >= 0; i--) {
        binary_str[bits - 1 - i] = (num >> i) & 1 ? '1' : '0';
    }
    binary_str[bits] = '\0';
}

// 计算最大公共子串
void find_longest_common_substring(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int max_length = 0, end_idx = 0;

    int dp[len1 + 1][len2 + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > max_length) {
                    max_length = dp[i][j];
                    end_idx = i;
                }
            }
        }
    }

    if (max_length > 0) {
        printf("最大公共子串: ");
        for (int i = end_idx - max_length; i < end_idx; i++) {
            printf("%c", str1[i]);
        }
        printf(" (长度: %d)\n", max_length);
    } else {
        printf("无公共子串\n");
    }
}

int main() {
    int x = 20250309;
    int neg_x = -x;
    float f_x = (float)x;
    double d_x = (double)x;

    printf("整数 x: %d\n", x);
    printf("负数 -x: %d\n", neg_x);

    // 输出二进制
    printf("\n[int] x: ");
    print_binary_32(*(uint32_t*)&x);
    printf("[int] -x: ");
    print_binary_32(*(uint32_t*)&neg_x);
    
    printf("\n[float] (float)x: %f\nBinary: ", f_x);
    print_binary_32(*(uint32_t*)&f_x);
    
    printf("[double] (double)x: %lf\nBinary: ", d_x);
    print_binary_64(*(uint64_t*)&d_x);

    // 计算最大公共子串
    char bin_x[33], bin_float[33], bin_double[65];
    int_to_binary_string((uint32_t)x, bin_x, 32);
    int_to_binary_string(*(uint32_t*)&f_x, bin_float, 32);
    int_to_binary_string(*(uint64_t*)&d_x, bin_double, 64);

    printf("\n[公共子串计算] |x| 与 (float)x:\n");
    find_longest_common_substring(bin_x, bin_float);

    printf("\n[公共子串计算] |x| 与 (double)x:\n");
    find_longest_common_substring(bin_x, bin_double);

    return 0;
}