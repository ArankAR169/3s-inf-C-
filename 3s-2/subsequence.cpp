﻿#include <iostream>
#include<vector>
#include<string.h>
using namespace std;

void lcsAlgo(char* S1, char* S2, int m, int n) {
    vector<vector<int>>LCS_table;


    // Building the mtrix in bottom-up way
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                LCS_table[i][j] = 0;
            else if (S1[i - 1] == S2[j - 1])
                LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
            else
                LCS_table[i][j] = max(LCS_table[i - 1][j], LCS_table[i][j - 1]);
        }
    }

    int index = LCS_table[m][n];
    char* lcsAlgo = new char[index + 1];
    lcsAlgo[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (S1[i - 1] == S2[j - 1]) {
            lcsAlgo[index - 1] = S1[i - 1];
            i--;
            j--;
            index--;
        }

        else if (LCS_table[i - 1][j] > LCS_table[i][j - 1])
            i--;
        else
            j--;
    }
    cout << "S1 : " << S1 << "\nS2 : " << S2 << "\nLCS: " << lcsAlgo << "\n";
}

int main() {
    char S1[] = "ACADB";
    char S2[] = "CBDA";
    int m = strlen(S1);
    int n = strlen(S2);

    lcsAlgo(S1, S2, m, n);
}