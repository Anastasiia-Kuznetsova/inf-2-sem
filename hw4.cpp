#include <map>
#include <iostream>
#include<vector>
#include<algorithm>

int main() {
	std::map<std::string, std::map<int, std::string>> data;

	int N;
	std::cin >> N;
	std::string id, loc;
	int time;
	for (auto i = 0; i < N; i++) {
		std::cin >> id >> loc >> time;
		data[id][time] = loc;
	}

	std::cin >> N;
	std::string trash;
	for (auto i = 0; i < N; i++) {
		std::cin >> trash;
		if(trash == "object"){
            std::cin >> id >> time;
            auto data_for_id_it = data.find(id);
            if (data_for_id_it == data.end()) {
                std::cout << "no data" << std::endl;
                continue;
            }
            auto& locs = data_for_id_it->second;
            auto bound = locs.upper_bound(time);
            if (bound == locs.begin()) {
                std::cout << "no data" << std::endl;
            } else {
                std::cout << std::prev(bound)->second << std::endl;
		}
	}
        else if(trash == "location"){
            std::string locf;
            int timef;
            std::cin >> locf >> timef;
            bool a = false;
            std::vector<std::string> ans;
            for (auto const &[id, v1] : data) {
                for (auto const &[time, loc] : v1) {
                    if (loc == locf){a = true;}
                    auto data_for_id_it = data.find(id);
                    auto& locs = data_for_id_it->second;
                    auto bound = locs.upper_bound(timef);
                    if (std::prev(bound)->second == locf) {
                        a = true;
                        if(std::find(ans.begin(), ans.end(), id) == ans.end()) ans.push_back(id);
                    }
                }
            }
            if (!a) std::cout << "no data";
            else if(ans.size() != 0){
                for(auto i = 0u; i < ans.size(); i ++){
                    std::sort (ans.begin(), ans.end());
                    std::cout << ans[i] << ' ';
                }
            }
            std::cout << std::endl;
        }
	}
}
