#include <cmath>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

using point_t = std::pair<double, double>;
class Polyline {
public:
    // ����������� � ����������, ���� ����������

    // �������� ��������� ����� � �������
    void addPoint(double x, double y){
        points.push_back({x, y});
    }

    // �������� ��������� ����� � ������� � ������ ������
    unsigned int getNumberOfPoints() const{
        return points.size();
    }

    // �������� ����� ������� � ������ ������
    double getLength() const{
        auto length = 0;
        for(auto i = 0u; i + 1 < points.size(); i++){
            length += std::sqrt((points[i].first - points[i+1].first) * (points[i].first - points[i+1].first)
                            + (points[i].second - points[i + 1].second) * (points[i].second - points[i + 1].second));
        }
        return length;
    }

    // �������� x-���������� i-�� ����� �������, ����� ���������� � ������� ����������
    // (�������������, ��� ����� i ������ ������, ��� ��, ������� ���� getNumberOfPoints())
    double getX(unsigned int i) const{
        return points[i].first;
    }

    // �������� y-���������� i-�� ����� �������, ����� ���������� � ������� ����������
    // (�������������, ��� ����� i ������ ������, ��� ��, ������� ���� getNumberOfPoints())
    double getY(unsigned int i) const{
        return points[i].second;
    }
private:
    std::vector<point_t> points;
};

int main()
{
    Polyline p;
    p.addPoint(0.0, 0.0);
    p.addPoint(1.0, 0.0);
    p.addPoint(1.0, 1.0);
    cout << "Length: " << p.getLength() << endl;
    cout << "Points:" << endl;
    for(unsigned int i = 0; i < p.getNumberOfPoints(); i++) {
        cout << p.getX(i) << " " << p.getY(i) << endl;
    }
    return 0;
}
