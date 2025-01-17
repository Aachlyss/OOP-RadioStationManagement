#include <iostream>
#include <string>
#include <vector>

class RadioStation {
private:
    std::string name;
    float frequency; 
    float quality;   
    std::string state; 
    int userRating;   

    void determineState() {
        if (quality > 45.0f) {
            state = "visible";
        } else if (quality >= 35.0f && quality <= 45.0f) {
            state = "grayed_out";
        } else {
            state = "not_visible";
        }

        if (state == "visible" && userRating >= 115 && userRating <= 240) {
            state = "grayed_out";
        }
    }

public:
    RadioStation(std::string stationName, float freq, float qual, int rating)
        : name(stationName), frequency(freq), quality(qual), userRating(rating) {
        determineState();
    }

    ~RadioStation() {}

    std::string getName() const { return name; }
    float getFrequency() const { return frequency; }
    float getQuality() const { return quality; }
    std::string getState() const { return state; }
    int getUserRating() const { return userRating; }

    void printInfo() const {
        std::cout << "Name: " << name
                  << ", Frequency: " << frequency << " MHz"
                  << ", Quality: " << quality << "%"
                  << ", State: " << state
                  << ", User Rating: " << userRating
                  << std::endl;
    }
};

int main() {
    std::vector<RadioStation> stations;

    std::cout << "Enter details for 6 radio stations:\n";
    for (int i = 0; i < 6; ++i) {
        std::string name;
        float frequency, quality;
        int userRating;

        std::cout << "\nRadio Station " << (i + 1) << ":\n";
        std::cout << "Enter name: ";
        std::cin >> name;
        std::cout << "Enter frequency (MHz): ";
        std::cin >> frequency;
        std::cout << "Enter quality (%): ";
        std::cin >> quality;
        std::cout << "Enter user rating (0-255): ";
        std::cin >> userRating;

        stations.emplace_back(name, frequency, quality, userRating);
    }

    std::cout << "\nAll Radio Stations Information:\n";
    for (const auto& station : stations) {
        station.printInfo();
    }

    std::cout << "\nRadio Stations in 'grayed_out' state:\n";
    for (const auto& station : stations) {
        if (station.getState() == "grayed_out") {
            std::cout << "Name: " << station.getName()
                      << ", Quality: " << station.getQuality() << "%"
                      << std::endl;
        }
    }

    std::cout << "\nFinal State of All Radio Stations:\n";
    for (const auto& station : stations) {
        std::cout << "Name: " << station.getName()
                  << ", State: " << station.getState()
                  << std::endl;
    }

    return 0;
}
