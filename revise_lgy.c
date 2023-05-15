#include "revise_lgy.h"

int selectNo(){
    printf("\n= = = = = = * MRM * = = = = = =\n");
    printf("| 1. Create Movie data       |\n");
    printf("| 2. Revise Movie data       |\n");
    printf("| 3. Read Movie data list    |\n");
    printf("| 4. Delete Movie data       |\n");
    printf("| 5. Sort rating data list   |\n");
    printf("| 6. Search Movie title info |\n");
    printf("| 7. Save movie.txt file     |\n");
    printf("| 0. Exit                    |\n");
    printf("= = = = = = = = = = = = = = = =\n");
    int no;
    printf("No : ");
    scanf("%d", &no);
    return no;
}

int readStr(FILE* _fp, char *_str, int _buf){
    rewind(stdin);
    char ch;
    int len = 0;
    while ((ch = fgetc(_fp)) != '\n' && ch != EOF)
	if (len < _buf - 1)
	    _str[len++] = ch;
	_str[len] = '\0';
    return len;
}

void createMovie(Movie** _movie, size_t* _movieCnt){
    *(_movie + *_movieCnt) = (Movie*)malloc(sizeof(Movie));
    if(*(_movie + *_movieCnt) == NULL){
        printf("🚨 createMovie Error : malloc failed.\n");
        return;
    }
    printf("\n*=* =* =* =* Movie *= *= *= *=*\n");
    printf("영화 : ");
    readStr(stdin, (*_movie)[*_movieCnt].title, BUF);
    printf("장르 : ");
    readStr(stdin, (*_movie)[*_movieCnt].genre, BUF);
    printf("감독 : ");
    readStr(stdin, (*_movie)[*_movieCnt].director, BUF);
    printf("평점 : ");
    scanf("%f", &(*_movie)[*_movieCnt].rating);
    printf("배급사 : ");
    readStr(stdin, (*_movie)[*_movieCnt].distributor, BUF);
    printf("\n*=* =* =* =* *=*=* *= *= *= *=*\n");
    (*_movieCnt)++;
}

void reviseMovie(Movie* _movie){
    printf("\n*=* =* =* =* Movie *= *= *= *=*\n");
    printf("영화 : ");
    readStr(stdin, _movie->title, BUF);
    printf("장르 : ");
    readStr(stdin, _movie->genre, BUF);
    printf("감독 : ");
    readStr(stdin, _movie->director, BUF);
    printf("평점 : ");
    scanf("%f", &_movie->rating);
    printf("배급사 : ");
    readStr(stdin, _movie->distributor, BUF);
    printf("\n*=* =* =* =* *=*=* *= *= *= *=*\n");
}

void readMovie(Movie** _movie, size_t _movieCnt){
    size_t i = 0;
    printf("\n*=* *=* *=* =* =* =* Movie *= *= *= *=* *=* *=*\n");
    for(; i < _movieCnt; i++){
        if((*_movie)[i].rating == -1.f) continue;
        printf("%s %s %s %.1f %s\n", (*_movie)[i].title, (*_movie)[i].genre, (*_movie)[i].director, (*_movie)[i].rating, (*_movie)[i].distributor);
    }
    printf("*=* *=* *=* =* =* =* *=*=* *= *= *= *=* *=* *=*\n");
    printf("✅ (%zu) readMovie Success.\n", i);
}

void deleteMovie(Movie** _movie, size_t* _movieCnt){
    int dNo;
    printf("\nDelete(No.) : ");
    scanf("%d", &dNo);
    if(dNo < 1 || dNo > *_movieCnt){
        printf("🚨 deleteMovie Error : No delete %d number.\n", dNo);
        return;
    }
    (*_movie)[dNo].rating = -1.f;
    free(*_movie + dNo);
    (*_movieCnt)--;
}

void searchTitle(Movie** _movie, size_t _movieCnt){
    char title[BUF];
    printf("\nSearch(Title) : ");
    readStr(stdin, title, BUF);
    size_t notEqual = 0;
    for(size_t i = 0; i < _movieCnt; i++){
        if(!strcmp((*_movie)[i].title, title)){
            printf("\n*=* *=* *=* =* =* =* Movie *= *= *= *=* *=* *=*\n");
            printf("%s %s %s %.1f %s\n", (*_movie)[i].title, (*_movie)[i].genre, (*_movie)[i].director, (*_movie)[i].rating, (*_movie)[i].distributor);
            printf("*=* *=* *=* =* =* =* *=*=* *= *= *= *=**=* *=*\n");
        }
        else{
            notEqual++;
            if(_movieCnt == notEqual)
                printf("🚨 searchTitle Error : No search title '%s'.\n", title);
        }
    }
}

void allDeleteMovie(Movie** _movie, size_t* _movieCnt){
    while(*_movieCnt){
        if((*_movie)[*_movieCnt].rating != -1.f)
            free(*_movie + *_movieCnt);
        (*_movieCnt)--;
    }
    printf("✅ (%zu) allDeleteMovie Success.\n", *_movieCnt);
}

void Swap(Movie* _movie, int _src, int _dest){
    Movie temp;
    temp = _movie[_src];
    _movie[_src] = _movie[_dest];
    _movie[_dest] = temp;
}

void Sort(Movie* _movie, int _a, int _b){
    if(_a < _b){
        int key = _a;
        int i = _a + 1;
        int j = _b;
        while(i <= j){
            while(i <= _b && _movie[i].rating >= _movie[key].rating) i++;
            while(j > _a && _movie[j].rating <= _movie[key].rating) j--;
            i > j ? Swap(_movie, j, key) : Swap(_movie, i, j);
        }
        Sort(_movie, _a, j - 1);
        Sort(_movie, j + 1, _b);
    }
}

void loadDataFromFile(Movie** _movie, size_t* _movieCnt){
    char buffer[BUF_MAX];
    FILE* fp = fopen("movie.txt", "rt");
    if(fp == NULL){
        printf("🚨 saveDataToFile Error : fopen failed.\n");
        exit(1);
    }
    while(true){
        if(readStr(fp, buffer, BUF_MAX) <= 0) break;
        *(_movie + *_movieCnt) = (Movie*)malloc(sizeof(Movie));
        strcpy((*_movie)[*_movieCnt].title, strtok(buffer, "#"));
        strcpy((*_movie)[*_movieCnt].genre, strtok(NULL, "#"));
        strcpy((*_movie)[*_movieCnt].director, strtok(NULL, "#"));
        (*_movie)[*_movieCnt].rating = atof(strtok(NULL, "#"));
        strcpy((*_movie)[*_movieCnt].distributor, strtok(NULL, "#"));
        (*_movieCnt)++;
    }
    printf("✅ (%zu)loadDataFromFile Success.\n", *_movieCnt);
}

void saveDataToFile(Movie** _movie, size_t _movieCnt){
    FILE* fp = fopen("movie.txt", "at");
    if(fp == NULL){
        printf("🚨 saveDataToFile Error : fopen failed.\n");
        exit(1);
    }
    size_t i = 0;
    for(; i < _movieCnt; i++){
        if((*_movie)[i].rating == -1.f) continue;
        fprintf(fp, "%s#%s#%s#%.1f#%s#\n", (*_movie)[i].title, (*_movie)[i].genre, (*_movie)[i].director, (*_movie)[i].rating, (*_movie)[i].distributor);
    }
    fclose(fp);
    printf("✅ (%zu) saveDataToFile Success.\n", i);
}