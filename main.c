#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <sys/time.h>



void shift_up(int bsize, char board[][bsize+1], int *score) {
    
    char next_board[bsize+1][bsize+1];
    for (int i = 0; i < bsize; i++) {
        for (int j = 0; j < bsize; j++) {
            next_board[i][j] = '-';
        }
    }

    for (int i = 0; i < bsize; i++) {
        char now = board[0][i];
        int next_b_now = 0;
        int skip = 0;
        for (int j = 1; j < bsize; j++) {
            if (skip) {
                skip = 0;
                continue;
            }
            else {
                if (now != '-' && board[j][i] == now) {
                    next_board[next_b_now][i] = now+1;
                    int num = now - 'a';
                    *score += (int) pow(2, num+2);
                    next_b_now++;
                    now = board[j+1][i];
                    skip = 1;
                }
                else if (now == '-' && board[j][i] != '-') {
                    now = board[j][i];
                }
                else if (now != '-' && board[j][i] != now && board[j][i] != '-') {
                    next_board[next_b_now][i] = now;
                    next_b_now++;
                    now = board[j][i];
                }
            }
        }
        if (!skip) {
            next_board[next_b_now][i] = now;
        }
    }
    
    for (int i = 0; i < bsize; i++) {
        for (int j = 0; j < bsize; j++) {
            board[i][j] = next_board[i][j];
        }
    }
}


void shift_down(int bsize, char board[][bsize+1], int *score) {
    
    char next_board[bsize+1][bsize+1];
    for (int i = 0; i < bsize; i++) {
        for (int j = 0; j < bsize; j++) {
            next_board[i][j] = '-';
        }
    }

    for (int i = 0; i < bsize; i++) {
        char now = board[bsize-1][i];
        int next_b_now = bsize-1;
        int skip = 0;
        for (int j = bsize-1-1; j > -1; j--) {
            if (skip) {
                skip = 0;
                continue;
                //skip = 0;
            }
            else {
                if (now == '-' && board[j][i] == '-') {
                    continue;
                }
                else if (now != '-' && board[j][i] == now) {
                    next_board[next_b_now][i] = now+1;
                    int num = now - 'a';
                    *score += (int) pow(2, num+2);
                    next_b_now--;
                    now = board[j-1][i];
                    skip = 1;
                }
                else if (now == '-' && board[j][i] != '-') {
                    now = board[j][i];
                }
                else if (now != '-' && board[j][i] != now && board[j][i] != '-') {
                    next_board[next_b_now][i] = now;
                    next_b_now--;
                    now = board[j][i];
                }
                else if (now != '-' && board[j][i] != now && board[j][i] == '-') {
                    continue;
                }
            }
        }
        if (!skip) {
            next_board[next_b_now][i] = now;
        }
    }
    
    for (int i = 0; i < bsize; i++) {
        for (int j = 0; j < bsize; j++) {
            board[i][j] = next_board[i][j];
        }
    }
}

void shift_left(int bsize, char board[][bsize+1], int *score) {
    
    char next_board[bsize+1][bsize+1];
    for (int i = 0; i < bsize; i++) {
        for (int j = 0; j < bsize; j++) {
            next_board[i][j] = '-';
        }
    }

    for (int i = 0; i < bsize; i++) {
        char now = board[i][0];
        int next_b_now = 0;
        int skip = 0;
        for (int j = 1; j < bsize; j++) {
            if (skip) {
                skip = 0;
                continue;
                //skip = 0;
            }
            else {
                if (now == '-' && board[i][j] == '-') {
                    continue;
                }
                else if (now != '-' && board[i][j] == now) {
                    next_board[i][next_b_now] = now+1;
                    int num = now - 'a';
                    *score += (int) pow(2, num+2);
                    next_b_now++;
                    now = board[i][j+1];
                    skip = 1;
                }
                else if (now == '-' && board[i][j] != '-') {
                    now = board[i][j];
                }
                else if (now != '-' && board[i][j] != now && board[i][j] != '-') {
                    next_board[i][next_b_now] = now;
                    next_b_now++;
                    now = board[i][j];
                }
                else if (now != '-' && board[i][j] != now && board[i][j] == '-') {
                    continue;
                }
            }
        }
        if (!skip) {
            next_board[i][next_b_now] = now;
        }
    }
    
    for (int i = 0; i < bsize; i++) {
        for (int j = 0; j < bsize; j++) {
            board[i][j] = next_board[i][j];
        }
    }
}

void shift_right(int bsize, char board[][bsize+1], int *score) {
    
    char next_board[bsize+1][bsize+1];
    for (int i = 0; i < bsize; i++) {
        for (int j = 0; j < bsize; j++) {
            next_board[i][j] = '-';
        }
    }

    for (int i = 0; i < bsize; i++) {
        char now = board[i][bsize-1];
        int next_b_now = bsize-1;
        int skip = 0;
        for (int j = bsize-1-1; j > -1; j--) {
            if (skip) {
                skip = 0;
                continue;
                //skip = 0;
            }
            else {
                if (now == '-' && board[i][j] == '-') {
                    continue;
                }
                else if (now != '-' && board[i][j] == now) {
                    next_board[i][next_b_now] = now+1;
                    int num = now - 'a';
                    *score += (int) pow(2, num+2);
                    next_b_now--;
                    now = board[i][j-1];
                    skip = 1;
                }
                else if (now == '-' && board[i][j] != '-') {
                    now = board[i][j];
                }
                else if (now != '-' && board[i][j] != now && board[i][j] != '-') {
                    next_board[i][next_b_now] = now;
                    next_b_now--;
                    now = board[i][j];
                }
                else if (now != '-' && board[i][j] != now && board[i][j] == '-') {
                    continue;
                }
            }
        }
        if (!skip) {
            next_board[i][next_b_now] = now;
        }
    }
    
    for (int i = 0; i < bsize; i++) {
        for (int j = 0; j < bsize; j++) {
            board[i][j] = next_board[i][j];
        }
    }
}

int generate_num(int bsize, char board[][bsize+1]) {
    
    int img_board[bsize+1][bsize+1];
    for (int i = 0; i < bsize; i++) {
        for (int j = 0; j < bsize; j++) {
            img_board[i][j] = 0;
        }
    }

    int count = 0;
    for (int i = 0; i < bsize; i++) {
        for (int j = 0; j < bsize; j++) {
            if (board[i][j] == '-') {
                count++;
                img_board[i][j] = count;
            }
        }
    }

    if (count == 0) {
        return 1;
    }

    else {
        struct timeval nowtime;
        gettimeofday(&nowtime, NULL);
        srand (((int)nowtime.tv_usec) % 65536);
        int numm = (int) rand();
        int num = 1 + (int) numm%count;

        for (int i = 0; i < bsize; i++) {
            for (int j = 0; j < bsize; j++) {
                if (img_board[i][j] == num) {
                    if (numm % 100 < 90) {
                        board[i][j] = 'a';
                    }
                    else if (numm % 100 == 99) {
                        board[i][j] = 'c';
                    }
                    else {
                        board[i][j] = 'b';
                    }
                    break;
                }
            }
        }
        return 0;
    }
}

int judge_2048(int bsize, char board[][bsize+1], int j2048) {
    int flag = 1;
    if (j2048) {
        for (int i = 0; i < bsize; i++) {
            for (int j = 0; j < bsize; j++) {
                if (board[i][j] == 'k') {
                    flag = 0;
                    break;
                }
            }
            if (!flag) {
                break;
            }
        }
        if (flag) {
            return 0;
        }
        else {
            return 1;
        }
    }
    else {
        return 0;
    }
}


int judge_up(int bsize, char board[][bsize+1], char copy_board[][bsize+1], int *dams) {
    for (int i = 0; i < bsize; i++) {
        for (int j = 0; j < bsize; j++) {
            copy_board[i][j] = board[i][j];
        }
    }
    shift_up(bsize, copy_board, dams);
    int flags = 1;
    for (int i = 0; i < bsize; i++) {
        for (int j = 0; j < bsize; j++) {
            if (copy_board[i][j] != board[i][j]){
                flags = 0;
            }
        }
    }
    if (flags) {//上シフトしても無変化
        return 0;
    }
    else {//上シフトして変化する
        return 1;
    }
}

int judge_down(int bsize, char board[][bsize+1], char copy_board[][bsize+1], int *dams) {
    for (int i = 0; i < bsize; i++) {
        for (int j = 0; j < bsize; j++) {
            copy_board[i][j] = board[i][j];
        }
    }
    shift_down(bsize, copy_board, dams);
    int flags = 1;
    for (int i = 0; i < bsize; i++) {
        for (int j = 0; j < bsize; j++) {
            if (copy_board[i][j] != board[i][j]){
                flags = 0;
                break;
            }
        }
        if (!flags) {
            break;
        }
    }
    if (flags) {//下シフトしても無変化
        return 0;
    }
    else {//下シフトして変化する
        return 1;
    }
}

int judge_left(int bsize, char board[][bsize+1], char copy_board[][bsize+1], int *dams) {
    for (int i = 0; i < bsize; i++) {
        for (int j = 0; j < bsize; j++) {
            copy_board[i][j] = board[i][j];
        }
    }
    shift_left(bsize, copy_board, dams);
    int flags = 1;
    for (int i = 0; i < bsize; i++) {
        for (int j = 0; j < bsize; j++) {
            if (copy_board[i][j] != board[i][j]){
                flags = 0;
                break;
            }
        }
        if (!flags) {
            break;
        }
    }
    if (flags) {//左シフトしても無変化
        return 0;
    }
    else {//左シフトして変化する
        return 1;
    }
}

int judge_right(int bsize, char board[][bsize+1], char copy_board[][bsize+1], int *dams) {
    for (int i = 0; i < bsize; i++) {
        for (int j = 0; j < bsize; j++) {
            copy_board[i][j] = board[i][j];
        }
    }
    shift_right(bsize, copy_board, dams);
    int flags = 1;
    for (int i = 0; i < bsize; i++) {
        for (int j = 0; j < bsize; j++) {
            if (copy_board[i][j] != board[i][j]){
                flags = 0;
                break;
            }
        }
        if (!flags) {
            break;
        }
    }
    if (flags) {//右シフトしても無変化
        return 0;
    }
    else {//右シフトして変化する
        return 1;
    }
}

void beautiful_print(int bsize, char board[][bsize+1]) {
    printf("\e[1m");
    int irolist[20] = {136,208,196,200,126,93,63,21,33,45,76,28,64,69,97,88,131,240,232};
    for (int i = 0; i < bsize; i++) {
        int list[bsize+1];
        for (int j = 0; j < bsize; j++) {
            list[j] = -1;
        }
        for (int j = 0; j < bsize; j++) {
            if (board[i][j] != '-' && board[i][j] - 'a' < 20) {
                list[j] = irolist[(int) (board[i][j] - 'a')];
            }
        }
        for (int j = 0; j < bsize; j++) {
            if (list[j] > 0) {
                printf("\e[48;5;%dm", list[j]);
                printf("--------");
                printf("\e[49m");
            }
            else {
                printf("--------");
            }
        }
        printf("\r\n");
        for (int j = 0; j < bsize; j++) {
            if (list[j] > 0) {
                printf("\e[48;5;%dm", list[j]);
                printf("|      |");
                printf("\e[49m");
            }
            else {
                printf("|      |");
            }
        }
        printf("\r\n");
        for (int j = 0; j < bsize; j++) {
            if (board[i][j] == '-') {
                printf("|      |");
            }
            else {
                printf("\e[48;5;%dm", list[j]);
                int num = 1 + board[i][j] - 'a';
                int numm = pow(2, num);
                if (numm / 10 == 0) {
                    printf("|  %d   |", numm);
                }
                else if (numm / 100 == 0) {
                    printf("|  %d  |", numm);
                }
                else if (numm / 1000 == 0) {
                    printf("| %d  |", numm);
                }
                else if (numm / 10000 == 0) {
                    printf("| %d |", numm);
                }
                else if (numm / 100000 == 0) {
                    printf("|%d |", numm);
                }
                else {
                    printf("|%d|", numm);
                }
                printf("\e[49m");
            }
        }
        printf("\r\n");
        for (int j = 0; j < bsize; j++) {
            if (list[j] > 0) {
                printf("\e[48;5;%dm", list[j]);
                printf("|      |");
                printf("\e[49m");
            }
            else {
                printf("|      |");
            }
        }
        printf("\r\n");
        for (int j = 0; j < bsize; j++) {
            if (list[j] > 0) {
                printf("\e[48;5;%dm", list[j]);
                printf("--------");
                printf("\e[49m");
            }
            else {
                printf("--------");
            }
        }
        printf("\r\n");
    }
    printf("\e[0m");
}

int main () {
   
    system("/bin/stty raw onlcr");  // enterを押さなくてもキー入力を受け付けるようになる

    int bsize;

    /* \rは先頭に戻る(その行の先頭多分) */

    printf("\r\n");
    printf("Press natural number and 'Enter' to decide the size of the board.\r\n");
    printf("If you press 5, 5*5 board will be made.\r\n");
    printf("Notice: the number must be 3 or higher and 7 or lower.\r\n");
    scanf("%d", &bsize);

    if (bsize < 3 || 7 < bsize) {
        printf("\aError!\r\n");
        return -1;
    }

    printf("%d*%d board will be made.\r\n", bsize, bsize);

    char board[bsize+1][bsize+1];
    for (int i = 0; i < bsize; i++) {
        for (int j = 0; j < bsize; j++) {
            board[i][j] = '-';
        }
    }

    char copy_board[bsize+1][bsize+1];

    struct timeval nowtime;
    gettimeofday(&nowtime, NULL);
    srand (((int) nowtime.tv_usec) % 65536);
    int bif = -1;
    for (int i = 0; i < 2; i++) {
        int numm = (int) rand();
        int num = 1 + (int) numm%(bsize*bsize);
        if (bif != num) {
            board[(num-1)/bsize][(num-1)%bsize] = 'a';
        }
        else {
            while (bif == num) {
                int numm = (int) rand();
                int num = 1 + (int) numm%(bsize*bsize);
            }
            board[(num-1)/bsize][(num-1)%bsize] = 'a';
        }
        int bif = num;
    }

    for (int i = 0; i < bsize; i++) {
        for (int j = 0; j < bsize; j++) {
            copy_board[i][j] = board[i][j];
        }
    }

    char before_board[bsize+1][bsize+1];
    int before_score = 0;

    for (int i = 0; i < bsize; i++) {
        for (int j = 0; j < bsize; j++) {
            before_board[i][j] = board[i][j];
        }
    }

    printf("Press any key(except for 'i','k','m','j','d','r','.') to conitnue.\n");

    int c;

    int score = 0;
    int j2048 = 1;
    int damyscore = 0;
    int kyoka = 0;
    int returntime = 0;
    int gameflag = 0;
    int deletetime = 3;

    while((c = getchar()) != '.') {

        system("clear");
        printf("\r\n");
        printf("Press '.' to close\r\n");
        printf("'i' is swipe up\r\n");
        printf("'k' is swipe right\r\n");
        printf("'m' is swipe down\r\n");
        printf("'j' is swipe left\r\n");
        printf("'d' is delete random line and row\r\n");
        printf("'r' is go back to before state(only once)\r\n");
        printf("\r\n");
        
        char type;
        
        if (gameflag == 4) {
            printf("\x1b[31m");
            printf("\aGameOver....\r\n");
            printf("Press '.' to close\r\n");
            printf("\x1b[39m");
        }

        gameflag = 0;

        if (c == 'r') {
            if (returntime) {
                score = before_score;
                for (int i = 0; i < bsize; i++) {
                    for (int j = 0; j < bsize; j++) {
                        board[i][j] = before_board[i][j];
                        copy_board[i][j] = board[i][j];
                    }
                }
                returntime = 0;
            }
            else {
                printf("\e[31m");
                printf("\aYou cannot go back.\r\n");
                printf("\e[39m");
            }
        }
        if (c != 'r') {
            returntime = 1;
        }

        for (int i = 0; i < bsize; i++) {
            for (int j = 0; j < bsize; j++) {
                before_board[i][j] = board[i][j];
            }
        }
        before_score = score;


        if (c == 'd') {
            if (deletetime) {
                int sc = 0;
                deletetime--;
                struct timeval nowtime;
                gettimeofday(&nowtime, NULL);
                srand (((int) nowtime.tv_usec) % 65536);
                int numm = (int) rand();
                int num = 1 + (int) numm%(bsize);
                for (int i = 0; i < bsize; i++) {
                    if (board[i][num] != '-') {
                        sc += (pow(2, (1 + (board[i][num] - 'a'))))*(board[i][num] - 'a');
                        //printf("%d\r\n", sc);
                    }
                    if (board[num][i] != '-') {
                        sc += (pow(2, (1 + (board[num][i] - 'a'))))*(board[num][i] - 'a');
                        //printf("%d\r\n", sc);
                    }
                    board[i][num] = '-';
                    board[num][i] = '-';
                    copy_board[i][num] = '-';
                    copy_board[num][i] = '-';
                }
                if (board[num][num] != '-') {
                    sc -= (pow(2, (1 + (board[num][num] - 'a'))))*(board[num][num] - 'a');
                }
                score -= sc;
                printf("You deleted %d line and row.    You lost %d points.\r\n", num, sc);
            }
            else {
                printf("\x1b[31m");
                printf("\aYou cannot delete because you did it three times.\r\n");
                printf("\x1b[39m");
            }
        }

        else if (c == 'i') {
            if (judge_up(bsize, board, copy_board, &damyscore)) {
                type = 'i';
                kyoka = 1;
                shift_up(bsize, board, &score);
            }
        }

        else if (c == 'k') {
            if (judge_right(bsize, board, copy_board, &damyscore)) {
                type = 'k';
                kyoka = 1;
                shift_right(bsize, board, &score);
            }
        }

        else if (c == 'm') {
            if (judge_down(bsize, board, copy_board, &damyscore)) {
                type = 'm';
                kyoka = 1;
                shift_down(bsize, board, &score);
            }
        }

        else if (c == 'j') {
            if (judge_left(bsize, board, copy_board, &damyscore)) {
                type = 'j';
                kyoka = 1;
                shift_left(bsize, board, &score);
            }
        }
        

        if (type == 'i' || type == 'k' || type == 'm' || type == 'j') {
            if (kyoka) {
                generate_num(bsize, board);
                kyoka = 0;
            }
        }
        
        if (judge_up(bsize, board, copy_board, &damyscore)) {
            printf("you can    shift up    (type 'i')\r\n");
        }
        else {
            gameflag++;
            printf("you cannot shift up\r\n");
        }
        if (judge_right(bsize, board, copy_board, &damyscore)) {
            printf("you can    shift right (type 'k')\r\n");
        }
        else {
            gameflag++;
            printf("you cannot shift right\r\n");
        }
        if (judge_down(bsize, board, copy_board, &damyscore)) {
            printf("you can    shift down  (type 'm')\r\n");
        }
        else {
            gameflag++;
            printf("you cannot shift down\r\n");
        }
        if (judge_left(bsize, board, copy_board, &damyscore)) {
            printf("you can    shift left  (type 'j')\r\n");
        }
        else {
            gameflag++;
            printf("you cannot shift left\r\n");
        }

        printf("\r\n");

        printf("Your score is ");
        printf("\x1b[35m");
        printf("\x1b[1m");
        printf("%d.", score);
        printf("\x1b[39m");
        printf("\x1b[0m");
        printf("      You can delete %d time.", deletetime);
        printf("\r\n");

        printf("\r\n");

        beautiful_print(bsize, board);

        printf("You pressed '%c'\r\n", c);

        if (judge_2048(bsize, board, j2048)) {
            printf("\x1b[36m");
            printf("\aCongratulation!! You succeeded in making 2048!!\r\n");
            printf("\x1b[39m");
            j2048 = 0;
        }
    }

    system("/bin/stty cooked");  // 後始末

    return 0;
}
