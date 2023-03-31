#include <iostream>
#include <map>
using namespace std;

class Handler{
public:
    virtual void preProcess(){}
    virtual void postProcess(){}
    virtual bool accessAllowed(string username){
        return true;
    }
    virtual void run() = 0;

    virtual ~Handler() = default;
};

class BadHandler : public Handler {
};

// ������ ���������� ��������� ��������
class DummyHandler : public Handler {
public:
    void run() {
        cout << "DummyHandler runs" << endl;
    }
};

// ������ ���������� ��������� ��������
// � ������������ ����������� ���������� ���� �������
class SmartHandler : public Handler {
public:
    void preProcess() {
        cout << "SmartHandler preprocess" << endl;
    }

    void postProcess() {
        cout << "SmartHandler postprocess" << endl;
    }

    bool accessAllowed(string username) {
        return "admin" == username;
    }

    void run() {
        cout << "SmartHandler runs" << endl;
    }
};

// ������ ���������� ��������� ��������
// � �������� ������ �� �����
class HeavyHandler : public Handler {
protected:
    int* data;
public:
    HeavyHandler() {
        data = new int[1000];
    }
    ~HeavyHandler() {
        delete[] data;
    }

    void run() {
        cout << "HeavyHandler runs" << endl;
    }
};

int main()
{
    // ���� �������. ���������� ������ ������������.
    // ... ���������� �����-�� ������, ��������� ��� ������������ ...
    string username = "some_user_name";

    // ���������� �����-�� ������ ��� ������ ������� �����������.
    // ��������, ����� ���������� SomeHandler. ������ ���.
    Handler* h = new HeavyHandler();

    // ����� ��� ����, ������ ��� ���� ����� ������������,
    // ���� ���� � ������� ����� ��������� � ������� �����.

    // ��������� ��������������� ��������
    h->preProcess();
    // ���������, �������� �� ������ ������� ������������
    if(h->accessAllowed(username)) {
        // ���� ������ ��������, ��������� ��������� �������
        h->run();
    }
    // ��������� ����������� ��������
    h->postProcess();

    // ������� ��������� �����������
    delete h;

    return 0;
};
