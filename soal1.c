/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 5
 *   Hari dan Tanggal    : Rabu, 13 Mei 2026
 *   Nama (NIM)          : Rafi Arif Putra (13224033)
 *   Nama File           : soal1.c
 *   Deskripsi           : Fungsi yang mencetak sekumpulan kombinasi string kurung dengan panjang n yang valid
 */

// Referensi:
// 1. https://stackoverflow.com/questions/7970617/how-can-i-check-if-char-variable-points-to-empty-string
// 2. https://thevalleyofcode.com/lesson/c-advanced/return-string/
// 3. https://www.geeksforgeeks.org/c/c-program-to-print-all-permutations-of-a-given-string/
// 4. https://stackoverflow.com/questions/47116974/remove-a-substring-from-a-string-in-c

#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#include <stdbool.h>

// Swap value function
void swap(char *x, char *y) 
{ 
    char str; 
    str = *x; 
    *x = *y; 
    *y = str; 
} 

char *strremove(char *str, int i) {
    char *temp;
    if(i == 4){
        return temp;
    }
    char *p, *q, *r;
    if ("()" && (q = r = strstr(str, "()")) != NULL) {
        size_t len = strlen("()");
        while ((r = strstr(p = r + len, "()")) != NULL) {
            while (p < r)
                *q++ = *p++;
        }
        while ((*q++ = *p++) != '\0')
            continue;
    }
    i++;
    strremove(temp, i);
}

void isValid(char *str){
    char* temp = str;
    char* temp2 = strremove(temp, 0);
    if(temp2[0] == '\0'){
        printf("\n%s", str);
    }
    return;
}

// Function to create permutations
void permute(char *a, int l, int r) 
{ 
    int i; 
    char *temp = a;
    if (l == r){
        isValid(a);
    } else{ 
        for (i = l; i <= r; i++) 
        { 
            swap((a + l), (a + i)); 
            permute(a, l + 1, r); 

            //backtrack 
            swap((a + l), (a + i)); 
        } 
    } 
} 

// Main Program
int main(){ 
    int n;
    scanf("%d", &n);
    int n_used = 2*n;

    // Generate parentheses
    char str[n_used];
    for(int i=0; i<n_used; i++){
        str[i] = '(';
        if(i >= n){
            str[i] = ')';
        }
    }

    permute(str, 0, n_used-1); 

    return 0; 
}
