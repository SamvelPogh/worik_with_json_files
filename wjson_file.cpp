#include <iostream>
#include  <string>
#include <fstream>  
#include <nlohmann/json.hpp> //library for working with json files
using json = nlohmann::json; //making variable  Json type

std::ifstream read_f("jsonsrc.json"); //open file for reading
std::ofstream write_file("end.json"); //open file for writing

json data = json::parse(read_f);  //parse information from json file to variable type json
json end_;



//creating struct for saving information about people
struct person {
	std::string name;
	int age;
	std::string addres;
};



//function that takes an argument of type json, places it in a vector and returns us a vector of type person
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

//a function that receives an argument of type vector<person>, adds the ages of all objects together, then divides by their number and returns the average age
int avarg_age(std::vector<person> x) {
	int end_sum=0;
	for (int i = 0; i < x.size();++i) {
		end_sum += x[i].age;
	}
	end_sum /= x.size();
	return end_sum;
}

//function that receives an argument of type person and compares the average age with the age of all objects and returns the names of objects whose age exceeds the average age of the whole
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
//assign the value returned by the avarg_age function to the average age of the json type variable
	end_["avarage"] = avarg_age(pars_tovec(data));
	
      //we assign the value returned by the find function to the average age of the json type variable
	  end_["names"] = find(pars_tovec(data), avarg_age(pars_tovec(data)));
	  
	//puts the contents of end_ into the file
	  write_file << end_;	
}
