// library yang dibutuhkan.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // deklarasi variabel yang digunakan.
    char namaUser[100];
    int user;
    int komputer;
    int skorUser = 0; 
    int skorKomputer = 0;
    int babak = 3;
    int n;

    // inisialisasi seed random (biar program bisa milih no acak & 
    // no yang dipilih biar tidak sama setiap kali program dijalan)
    srand(time(NULL));

    // menu game awal
    printf("<===> Rock, Paper, Scissors Game <===> \n");
    printf("Rules: to become a winner win at least 2 rounds.\n");
    printf("ENTER YOUR NAME : ");

    // fitur untuk user input namanya buat username di dalam game.
    scanf("%s", namaUser);

    // setting untuk babak yang ada di dalam permainan.
    // (menggunakan looping for karena kita sudah tahu mau berapa kali banyak babaknya)
    // (looping ini digunakan supaya dia bisa ngulang otomatis sesuai babak yang set oleh aku)
    for (n = 1; n <= babak; n++) {
        printf("\nRound : %d\n", n);
        printf("Choose one:\n");
        printf("1. Rock\n");
        printf("2. Paper\n");
        printf("3. Scissors\n");
        printf("%s's Pick : ", namaUser);
        scanf("%d", &user);

        // setting untuk memberi tahu user bahwa inputnya invalid.
        // (menggunakan looping while karena kita tidak tahu sampai kapan user input angka yang valid)
        // *masih bagian dari looping for
        while (user > 3|| user < 1) {
            printf("Input Invalid, try again : ");
            scanf("%d", &user);
            continue;
        }

        // digunakan untuk menghasilkan angka acak antara 1 sampai 3. 
        // (% 1 + 3 biar angka acak yang keluar 1-3 tidak termasuk 0)
        // *this one too
        komputer = rand() % 3 + 1;
        
        // deklarasi array yang berisi string pilihan untuk komputer.
        // also this one
        char *result[] = {"Rock", "Paper", "Scissors"}; 
        printf("Computer's Pick: %s\n", result[komputer - 1]);

        // conditional statements untuk menentukan pemenang dan pembaharuan skor tiap ronde.
        // *and of course this one either
        if (user == komputer) {
            printf("Game Draw!\n");
        } else if ((user == 1 && komputer == 3) ||
                   (user == 2 && komputer == 1) ||
                   (user == 3 && komputer == 2)) {
            printf("You won this round!\n");
            skorUser++;
        } else {
            printf("Computer won this round!\n");
            skorKomputer++;
        }
        printf("Score - %s: %d | Computer Score: %d\n", namaUser, skorUser, skorKomputer);
    }
    
    // setting untuk untuk memberi tahu performa user selama game berlangsung.
    printf("\n<===> Final Scores <===>\n");
    printf("%s's Score: %d\n", namaUser, skorUser);
    printf("Computer's Score: %d\n", skorKomputer);
    
    // conditional statement memberikan feedback ke user mengenai hasil akhir permainan.
    if (skorUser > skorKomputer) {
        printf("Congratulations! YOU WIN THE GAME\n");
    } else if (skorUser < skorKomputer) {
        printf("YOU LOSE..\n");
    } else {
        printf("GAME DRAW!\n");
    }
    return 0;
}