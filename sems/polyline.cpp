#include <cmath>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

using point_t = std::pair<double, double>;
class Polyline {
public:
    //  онструктур и деструктор, если необходимы

    // ƒобавить очередную точку в ломаную
    void addPoint(double x, double y){
        points.push_back({x, y});
    }

    // ѕолучить количесто точек в ломаной в данный момент
    unsigned int getNumberOfPoints() const{
        return points.size();
    }

    // ѕолучить длину ломаной в данный момент
    double getLength() const{
        auto length = 0;
        for(auto i = 0u; i + 1 < points.size(); i++){
            length += std::sqrt((points[i].first - points[i+1].first) * (points[i].first - points[i+1].first)
                            + (points[i].second - points[i + 1].second) * (points[i].second - points[i + 1].second));
        }
        return length;
    }

    // ѕолучить x-координату i-ой точки ломаной, точки нумеруютс€ в пор€дке добавлени€
    // (√арантируетс€, что номер i строго меньше, чем то, вернула ваша getNumberOfPoints())
    double getX(unsigned int i) const{
        return points[i].first;
    }

    // ѕолучить y-координату i-ой точки ломаной, точки нумеруютс€ в пор€дке добавлени€
    // (√арантируетс€, что номер i строго меньше, чем то, вернула ваша getNumberOfPoints())
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
