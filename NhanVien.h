// #ifndef NHANVIEN_H
// #define NHANVIEN_H

#include <string>
#include <fstream>
using std::ifstream;
using std::string;
class NhanVien
{
private:
    string ID;
    string Name;
    int Age;
    string Gender;
    float HeSoLuong;
    float LuongCoBan;

public:
    NhanVien();

    ~NhanVien();

    string GetID();
    void SetID(const string &);

    string GetName();

    void SetName(const string &);

    int GetAge();

    void SetAge(const int &);

    string GetGender();

    void SetGender(const string &);

    float GetHeSoLuong();

    void SetHeSoLuong(const float &);

    float GetLuongCoBan();

    void SetLuongCoBan(const float &);

    void Input();

    void Output();

    void init(string, string, int, string, float, float);

    NhanVien *operator=(NhanVien *);

    float Salary();
};

// #endif