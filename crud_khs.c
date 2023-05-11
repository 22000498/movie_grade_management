#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crud_khs.h"
int count=0;
int selectMenu(){
    int menu;
    printf("\n*** �������� ***\n");
    printf("1. ��ȸ ");
    printf("2. �߰� ");
    printf("3. ���� ");
    printf("4. ���� ");
    printf("5. ���� ");
    printf("6. �˻� ");
    printf("7. ���� ");
    printf("0. ����\n");
    printf("=> ���ϴ� �޴���? ");
    scanf("%d", &menu);
    return menu;
}
int createMovie(Movie *s){
    printf("��ȭ �̸���? ");
    getchar();
    scanf("%[^\n]s",(s+count)->title); 
    printf("������? ");
    getchar();
    scanf("%[^\n]s",((s+count)->director));
    printf("�帣��? ");
    getchar();
    scanf("%[^\n]s",((s+count)->genre));
    printf("��޻��? ");
    getchar();
    scanf("%[^\n]s",((s+count)->distributor));
    printf("������? ");
    scanf("%f",&(s+count)->rating);
    count+=1;
    printf("=>�߰���");
    return 1;
 }
void listMovie(Movie *s){
    printf("        ��ȭ�̸�     ����    �帣    ��޻�  ����\n");
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
    printf("��ȣ��?(��Ҵ� 0) : ");
    scanf("%d", &update_num );
    if(update_num == 0){
        return 1;
    }
    else{
        printf("��ȭ �̸���? ");
        getchar();
        scanf("%[^\n]s",(s+update_num-1)->title); 
        printf("������? ");
        getchar();
        scanf("%[^\n]s",((s+update_num-1)->director));
        printf("�帣��? ");
        getchar();
        scanf("%[^\n]s",((s+update_num-1)->genre));
        printf("��޻��? ");
        getchar();
        scanf("%[^\n]s",((s+update_num-1)->distributor));
        printf("������? ");
        scanf("%f",&(s+update_num-1)->rating);
        printf("=>�����Ϸ�!!");
        return 1;
    }

}
int deleteMovie(Movie *s){
    int delete_num;
    printf("��ȣ��?(��Ҵ� 0) : ");
    scanf("%d",&delete_num);
    if(delete_num == 0){
        return 1;
    }
    else{
        (s+delete_num-1)->rating = -1;
        printf("=>������");
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
    printf("=> �����! ");
}
// int loadData(Movie *p){
//     int count = 0, i = 0;
//     FILE *fp;
//     fp = fopen("Movie.txt", "rt");
//      if(fp == NULL){
//         printf("=> ���� ����\n");
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
//     printf("=> �ε� ����!\n");
//     return i;
// }
void searchMovie(Movie *s,int max){
    int scnt = 0;
    char search[20];
    printf("�˻��� �̸�? ");
    scanf("%s", search);
    printf("   �̸� �� ������ ���� ������ ����\n");
    printf("===============================\n");
    for(int i =0; i <max ; i++){
        if(s[i].rating == -1) continue;
        if(strstr(s[i].title, search)){
            printf("%2d ", i+1);
            readMovie(s[i]);
            scnt++;
    }
 }
    if(scnt == 0) printf("=> �˻��� ������ ����!");
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