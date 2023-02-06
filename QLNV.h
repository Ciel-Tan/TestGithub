#include "NhanVien.h"

using namespace std;

class QLNV
{
private:
    NhanVien *C;
    int n;

public:
    QLNV(int = 1);

    ~QLNV();

    int getL();

    void setL(const int &);

    void renew_ofsize(const int &);

    void init();

    void display();

    void addMiddle(const NhanVien &, int);

    void findofID(string);

    int findofID2(string);

    void delete_atpos(string);

    void sort_bySalindex(bool cmp(float, float));

    void update();

    void file_initEMP();

    void writef();

    void menu_emp();
};