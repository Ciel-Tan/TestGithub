#include "Customer.h"
#include <string>

using std::string;

class QLKH
{
private:
    Customer *D;
    int n;

public:
    QLKH(int = 100);
    ~QLKH();

    int getL();
    void setL(const int &);

    void addtail(Customer *);
    void display();
    void inc_time_atpos(int);
    int find_phone(string);

    string getname_atpos(int);
    int get_timeatpos(int);
    int get_id_atpos(int);
    Date get_dateatpos(int);
    void show_atpos(int);

    void delete1(string);
    void update();
    void find_by_keyword(string);
    void file_readKH();
    void writeF();
    void menu_for_QLKH();
};