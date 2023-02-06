
#include <string>
#include "Customer.h"
#include "shopmanage.h"
#include "ArrayofFinance.h"

using std::string;

class Receipt
{
private:
    int MAHD;

public:
    Receipt();

    ~Receipt();
    int getMAHD();

    void setMAHD();

    void HD_print(QLCAT *, QLDOG *, Customer *, int[], int[], FinanceManage &);

    void HD_OUT(QLCAT *, QLDOG *, Customer *, int[], int[], FinanceManage &);
};