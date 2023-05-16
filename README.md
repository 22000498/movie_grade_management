# 2023-1 Open Source Software Lab 팀 프로젝트

![](https://cdn.pixabay.com/photo/2016/01/22/08/17/banner-1155437_1280.png)

### 영화 평점 관리 CRUD 프로그램 입니다.

## Getting Started
```zsh 
% git clone https://github.com/22000498/movie_rating_management.git
% make clean
% make
% ./movie
```
### Development Environment
Apple clang version 14.0.0 (clang-1400.0.29.202)

### Struct
```C
typedef struct Movie {
    char title[BUF];
    char genre[BUF];
    char director[BUF];
    float rating;
    char distributor[BUF];
} Movie;
```
영화 제목, 장르, 감독, 평점, 배급사에 대한 정보를 담은 구조체입니다.
### Function 
`int selectNo();`
`int readStr(FILE* _fp, char* _str, int _buf);`
`void createMovie(Movie** _movie, size_t* _movieCnt);`
`void reviseMovie(Movie* _movie);`
`void readMovie(Movie* _movie, size_t _movieCnt);`
`void deleteMovie(Movie* _movie, size_t* _movieCnt, size_t dNo);`
`void allDeleteMovie(Movie** _movie, size_t* _movieCnt);`
`void searchTitle(Movie** _movie, size_t _movieCnt);`
`void loadDataFromFile(Movie** _movie, size_t* _movieCnt);`
`void saveDataToFile(Movie** _movie, size_t _movieCnt);`
`void Swap(Movie* _movie, int _sour, int _dest);`
`void Sort(Movie* _movie, int _a, int _b);`

## Tech Stack
<img src="https://img.shields.io/badge/c-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"> <img src="https://img.shields.io/badge/git-F05032?style=for-the-badge&logo=git&logoColor=white">

## Git Workflow

`main`, `khs`, `lgy`

## Authors
* [Kim-Hyun-Seung](https://github.com/Kim-Hyun-Seung) : 한동대학교 전산전자공학부 22000202 김현승

  - [X] Collaborators
  
* [22000498](https://github.com/22000498) : 한동대학교 전산전자공학부 22000498 이건요

  - [X] Repo Owner
  
  - [X] README.md 작성
  
  - [X] github Issues, Discussions, Projects, WIKI 작성

  - [X] git Workflow

  - [X] movie_rating_management with SLL 프로그램 구현

  - [X] movie_rating_management with SLL library 분리
  
  - [X] movie_rating_management with DA 프로그램 구현
  
  - [X] movie_rating_management with DA library 분리

  - [X] movie_rating_management with DA Makefile 작성

## License
