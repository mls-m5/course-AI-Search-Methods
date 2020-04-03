// Copyright Mattias Larsson Sköld 2020

#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <vector>

struct City {
    std::string name;
    double x;
    double y;
    std::vector<City *> connections;
};

typedef std::vector<std::unique_ptr<City>> CityList;

using namespace std;

auto findCity(const CityList &cities, std::string_view name) -> City * {
    for (auto &city : cities) {
        if (city->name == name) {
            return city.get();
        }
    }
    throw runtime_error("could not find city "s + string(name));
}

//! Load connections from a stream/file and apply to a list of cities
//! @param cities           Both used for lookup and for output
auto loadConnections(istream &stream, CityList &cities) -> void {
    string line;
    while (getline(stream, line)) {
        if (line.empty()) {
            continue;
        }
        //        cout << "Route: " << line << endl;

        istringstream ss(line);
        string cityName;
        vector<City *> route;
        while (ss >> cityName) {
            route.push_back(findCity(cities, cityName));
        }

        for (size_t i = 1; i < route.size(); ++i) {
            route.at(i)->connections.push_back(route.at(i - 1));
            route.at(i - 1)->connections.push_back(route.at(i));
        }
    }
}

ostream &operator<<(ostream &stream, const City &city) {
    cout << city.name << " " << city.x << "," << city.y << "\n";
    cout << "\t";
    for (auto c : city.connections) {
        cout << c->name << " ";
    }
    cout << "\n";
    return stream;
}

ostream &operator<<(ostream &stream, const CityList &cities) {
    for (auto &city : cities) {
        stream << *city;
    }
    return stream;
}

auto loadCities(std::istream &stream) -> CityList {
    string line;
    CityList cities;
    while (getline(stream, line)) {
        if (line.empty()) {
            continue;
        }
        else if (line == "Routes:") {
            break;
        }

        City city;
        istringstream ss(line);
        getline(ss, city.name, '\t');
        string value;
        getline(ss, value, '\t');
        city.x = stod(value);
        getline(ss, value, '\t');
        city.y = stod(value);

        cities.push_back(make_unique<City>(city));

        //        cout << "city: " << line << endl;
    }

    loadConnections(stream, cities);

    return cities;
}

auto main(int /*argc*/, char * * /*argv*/) -> int {
    ifstream file("data/data.txt");

    if (!file.is_open()) {
        throw runtime_error("file could not be opened");
    }

    cout << "load\n";

    string line;

    getline(file, line); // Throw away first line

    auto cities = loadCities(file);

    cout << "load finished... \n";

    cout << cities;
}
