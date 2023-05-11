#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crud_khs.h"
int count=0;
int selectMenu(){
    int menu;
    printf("\n*** 점수계산기 ***\n");
    printf("1. 조회 ");
    printf("2. 추가 ");
    printf("3. 수정 ");
    printf("4. 삭제 ");
    printf("5. 저장 ");
    printf("6. 검색 ");
    printf("7. 정렬 ");
    printf("0. 종료\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}
int createMovie(Movie *s){
    printf("영화 이름은? ");
    getchar();
    scanf("%[^\n]s",(s+count)->title); 
    printf("감독은? ");
    getchar();
    scanf("%[^\n]s",((s+count)->director));
    printf("장르는? ");
    getchar();
    scanf("%[^\n]s",((s+count)->genre));
    printf("배급사는? ");
    getchar();
    scanf("%[^\n]s",((s+count)->distributor));
    printf("평점은? ");
    scanf("%f",&(s+count)->rating);
    count+=1;
    printf("=>추가됨");
    return 1;
 }
void listMovie(Movie *s){
    printf("        영화이름     감독    장르    배급사  평점\n");
    printf("===============================\n");
    for(int i=0; i< count ; i++){ 
        if((s+i)->rating==-1){}
        else{
            printf("%d :%10s ",i+1,(s+i)->title);
            printf(" %10s %7s %7s   %.1f \n",(s+i)->director, (s+i)->genre , (s+i)->distributor,(s+i)->rating);
        }
    }
}

int updateMovie(Movie *s){
    int update_num;
    printf("번호는?(취소는 0) : ");
    scanf("%d", &update_num );
    if(update_num == 0){
        return 1;
    }
    else{
        printf("영화 이름은? ");
        getchar();
        scanf("%[^\n]s",(s+update_num-1)->title); 
        printf("감독은? ");
        getchar();
        scanf("%[^\n]s",((s+update_num-1)->director));
        printf("장르는? ");
        getchar();
        scanf("%[^\n]s",((s+update_num-1)->genre));
        printf("배급사는? ");
        getchar();
        scanf("%[^\n]s",((s+update_num-1)->distributor));
        printf("평점은? ");
        scanf("%f",&(s+update_num-1)->rating);
        printf("=>수정완료!!");
        return 1;
    }

}
int deleteMovie(Movie *s){
    int delete_num;
    printf("번호는?(취소는 0) : ");
    scanf("%d",&delete_num);
    if(delete_num == 0){
        return 1;
    }
    else{
        (s+delete_num-1)->rating = -1;
        printf("=>삭제됨");
        return 1;
    }
}
void saveData(Movie *p, int max){
    FILE *fp;
    fp = fopen("Movie.txt","w");
    // printf("%d",max);
    for (int i=0; i < max ; i++){
        if((p+i)->rating == -1) continue;
        // char title[30],director[10], genre[10], distributor[10]; 
        // for (int j=0; j<strlen((p+i)->title); j++) {
        //     if ((p+i)->title[j] == ' ') {
        //         title[j] = '_'; 
        //     } else {
        //         title[j] = p[i].title[j];
        //     }
        // }
        // for (int j=0; j<strlen((p+i)->director); j++) {
        //     if ((p+i)->director[j] == ' ') {
        //         director[j] = '_'; 
        //     } else {
        //         director[j] = p[i].director[j];
        //     }
        // }
        //         for (int j=0; j<strlen((p+i)->genre); j++) {
        //     if ((p+i)->genre[j] == ' ') {
        //         genre[j] = '_'; 
        //     } else {
        //         genre[j] = p[i].genre[j];
        //     }
        // }
        //         for (int j=0; j<strlen((p+i)->distributor); j++) {
        //     if ((p+i)->distributor[j] == ' ') {
        //         distributor[j] = '_'; 
        //     } else {
        //         distributor[j] = p[i].distributor[j];
        //     }
        // }

        fprintf(fp, "%s / %s / %s / %s / %f", (p+i)->title, (p+i)->director,(p+i)->genre,(p+i)->distributor,(p+i)->rating); 
    }
    fclose(fp);
    printf("=> 저장됨! ");
}
// int loadData(Movie *p){
//     int count = 0, i = 0;
//     FILE *fp;
//     fp = fopen("Movie.txt", "rt");
//      if(fp == NULL){
//         printf("=> 파일 없음\n");
//         return 0; 
//     }
//     while(!feof(fp)){ 
//         char line[100];
//         fgets(line, 100, fp); 
//         if (line[0]=='\n'||(feof(fp)&&strlen(line)==0)) continue; 
//         getchar();
//         sscanf(line, "%s %s %s %s %f ", (p+i)->title, (p+i)->director,(p+i)->genre, (p+i)->distributor, (p+i)->rating);

//         i++;
//     }
//     fclose(fp);
//     printf("=> 로딩 성공!\n");
//     return i;
// }
void searchMovie(Movie *s,int max){
    int scnt = 0;
    char search[20];
    printf("검색할 이름? ");
    scanf("%s", search);
    printf("   이름 맛 분위기 가격 가성비 종류\n");
    printf("===============================\n");
    for(int i =0; i <max ; i++){
        if(s[i].rating == -1) continue;
        if(strstr(s[i].title, search)){
            printf("%2d ", i+1);
            readMovie(s[i]);
            scnt++;
    }
 }
    if(scnt == 0) printf("=> 검색된 데이터 없음!");
    printf("\n");
}
void readMovie(Movie s){
    if(s.rating==-1) {}
    else{
            int value;
            printf("%s %s %s",s.title, s.director, s.genre);
            printf(" %s %.1f \n",s.distributor, s.rating);
    }
}
int compare_rating(const void *a, const void *b) {
    const Movie *pa = (const Movie *)a;
    const Movie *pb = (const Movie *)b;
    
    if (pa->rating > pb->rating) return -1;
    if (pa->rating < pb->rating) return 1;
    return 0;
}
int sortMovie(Movie *p, int max){
        qsort(p,max,sizeof(Movie),compare_rating);
    return 1;
}