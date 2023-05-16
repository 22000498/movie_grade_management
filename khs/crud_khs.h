typedef struct {
    char title[30], director[20], genre[20], distributor[20];
    float rating;
}Movie;
int createMovie(Movie *p); // 제품을 추가하는 함수
void listMovie(Movie *p); // 전체 등록된 제품 리스트 출력
void readMovie(Movie p); // 하나의 제품 출력 함수
int updateMovie(Movie *p); //제품을 수정하는 함수 
int deleteMovie(Movie *p); //제품을 제거하는 함수
void saveData(Movie *p, int max); //제품을 저장하는 함수
void searchMovie(Movie *p, int max); // 제품이름 검색
int sortMovie(Movie *p, int max); // 정렬하기
int loadData(Movie *p);
int selectMenu();
