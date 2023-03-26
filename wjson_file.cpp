#include <iostream>
#include  <string>
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

std::ifstream read_f("jsonsrc.json");
std::ofstream write_file("end.json");

json data = json::parse(read_f);
json end_;




struct person {
	std::string name;
	int age;
	std::string addres;
};




std::vector<person> pars_tovec(json dat) {
	std::vector<person> people;
	for (auto& p : data) {
		person pi;
		pi.name = p["name"];
		pi.addres = p["address"];
		pi.age = p["age"];
		people.push_back(pi);
	}
	return people;

}

int avarg_age(std::vector<person> x) {
	int end_sum=0;
	for (int i = 0; i < x.size();++i) {
		end_sum += x[i].age;
	}
	end_sum /= x.size();
	return end_sum;
}

std::vector<std::string> find(std::vector<person> x, int ever_age) {
	std::vector<std::string> names_bigevg;
	for (int i = 0; i < x.size(); ++i) {
		if (x[i].age > ever_age) {
			names_bigevg.push_back(x[i].name);
		}
	}
	return names_bigevg;
}



int main()
{
	end_["avarage"] = avarg_age(pars_tovec(data));
	  end_["names"] = find(pars_tovec(data), avarg_age(pars_tovec(data)));
	  
	  write_file << end_;	
}
