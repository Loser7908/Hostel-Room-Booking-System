
class hostel
{
private:
    int room_no;
    char name[30];
    char address[50];
    char phone[10];
    int  uni_roll;
    char course[10];
    char branch[10];
    char semester[10];
    char batch[10];

public:
    void main_menu();
    void book_room();
    void search_bar();
    void uni_search();
    void search_roomno();
    void room_alloc();
    void edit_menu();
    int check(int);
    void modify();
    void vacate_room();
    void bill_generate();
    void login();
    void admin();

};
