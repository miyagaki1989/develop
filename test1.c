#include <stdio.h>
#include <time.h>
#include <sys/time.h>
// time.hとsys/time.hは別物なので注意！

int main(int argc, char *argv[]) {
    /* まず，日時・時刻情報を格納するための変数を宣言 */
    struct timeval myTime;    // time_t構造体を定義．1970年1月1日からの秒数を格納するもの

    /* 時刻取得 */
    gettimeofday(&myTime, NULL);    // 現在時刻を取得してmyTimeに格納．通常のtime_t構造体とsuseconds_tに値が代入される
    //time_st = localtime(&myTime.tv_sec);    // time_t構造体を現地時間でのtm構造体に変換
    long old_tv_usec = 0;
    long diff_tv_usec = 0;
    for (int i = 0; i < 100000001; i++) {
        
        if((i % 100000) == 0){
            gettimeofday(&myTime, NULL);    // 現在時刻を取得してmyTimeに格納．通常のtime_t構造体とsuseconds_tに値が代入される
            diff_tv_usec = myTime.tv_usec - old_tv_usec;
            printf("秒 = %ld, マイクロ秒 = %ld, マイクロ秒差分 = %ld\n", myTime.tv_sec, myTime.tv_usec, diff_tv_usec); //秒とマイクロ秒
            old_tv_usec = myTime.tv_usec;
        }
    }

    clock_t c_start = 0;
    clock_t c_end = 0;
    
    printf("%ld\n", CLOCKS_PER_SEC); //秒とミリ秒
    for (int i = 0; i < 100000001; i++) {
        
        if((i % 100000) == 0){
            c_end = clock();
            diff_tv_usec = c_end - c_start;
            printf("マイクロ秒差分 = %ld\n", diff_tv_usec); //秒とミリ秒
            c_start = clock();
        }
    }
    printf("clock_tサイズ = %ld\n", sizeof(clock_t));
    printf("charサイズ = %ld\n", sizeof(char));
    printf("intサイズ = %ld\n", sizeof(int));
    printf("longサイズ = %ld\n", sizeof(long));
    printf("doubleサイズ = %ld\n", sizeof(double));
    printf("floatサイズ = %ld\n", sizeof(float));



    return 0;
}