#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

// Function to simulate checking network connectivity and rate it
int rate_network_connectivity(const std::string& sim_name) {
    // Simulate connectivity ratings for each provider
    if (sim_name == "Verizon" || sim_name == "Vodafone" || sim_name == "Telstra") {
        return 10;  // Excellent connectivity (10/10)
    } else if (sim_name == "T-Mobile" || sim_name == "AT&T" || sim_name == "Orange") {
        return 8;   // Good connectivity (8/10)
    } else if (sim_name == "Airtel" || sim_name == "Jio") {
        return 7;   // Moderate connectivity (7/10)
    } else if (sim_name == "No Network") {
        return 0;   // No connectivity (0/10)
    }
    return 5;   // Default rating (5/10) for others
}

// Function to rate the data price
std::string rate_data_price(double price) {
    if (price < 3.0) {
        return "Cheap";
    } else if (price <= 10.0) {
        return "Average";
    } else {
        return "Expensive";
    }
}

// Function to get SIM suggestions based on location with network connectivity and data price
std::vector<std::string> get_sim_suggestions(const std::string& location) {
    // Define SIM suggestions for various locations with their data prices
    std::unordered_map<std::string, std::vector<std::pair<std::string, double>>> sim_map = {
        {"North America", {{"Verizon", 10.0}, {"T-Mobile", 8.5}, {"AT&T", 7.0}}},
        {"South America", {{"Claro", 6.0}, {"Movistar", 5.5}, {"TIM", 5.0}}},
        {"Europe", {{"Vodafone", 12.0}, {"Orange", 11.0}, {"T-Mobile", 9.5}}},
        {"Africa", {{"MTN", 3.0}, {"Airtel", 2.5}, {"Orange", 2.0}}},
        {"Asia", {{"Airtel", 4.0}, {"Jio", 3.5}, {"China Mobile", 3.0}}},
        {"Oceania", {{"Telstra", 15.0}, {"Optus", 14.0}, {"Vodafone Australia", 13.5}}},
        {"India", {{"Airtel", 2.0}, {"Jio", 1.5}, {"Vi", 1.8}, {"BSNL", 2.5}}},
        
        // Popular Cities and States of India with SIM providers and data prices
        {"Delhi", {{"Airtel", 2.0}, {"Jio", 1.5}, {"Vi", 1.8}, {"BSNL", 2.5}}},
        {"Mumbai", {{"Airtel", 2.5}, {"Jio", 2.0}, {"Vi", 2.2}, {"BSNL", 2.0}}},
        {"Kolkata", {{"Airtel", 2.0}, {"Jio", 1.5}, {"Vi", 1.8}, {"BSNL", 2.5}}},
        {"Chennai", {{"Airtel", 2.0}, {"Jio", 1.8}, {"Vi", 2.2}, {"BSNL", 2.0}}},
        {"Hyderabad", {{"Airtel", 2.0}, {"Jio", 1.8}, {"Vi", 2.1}, {"BSNL", 2.3}}},
        {"Bengaluru", {{"Airtel", 2.5}, {"Jio", 2.2}, {"Vi", 2.0}, {"BSNL", 2.0}}},
        {"Pune", {{"Airtel", 2.0}, {"Jio", 1.8}, {"Vi", 2.1}, {"BSNL", 2.5}}},
        {"Jaipur", {{"Airtel", 2.5}, {"Jio", 2.0}, {"Vi", 2.2}, {"BSNL", 2.0}}},
        {"Lucknow", {{"Airtel", 2.0}, {"Jio", 1.5}, {"Vi", 1.8}, {"BSNL", 2.5}}},
        {"Surat", {{"Airtel", 2.5}, {"Jio", 2.0}, {"Vi", 2.1}, {"BSNL", 2.0}}},
        {"Ahmedabad", {{"Airtel", 2.0}, {"Jio", 1.8}, {"Vi", 2.0}, {"BSNL", 2.5}}},
        {"Chandigarh", {{"Airtel", 2.0}, {"Jio", 1.5}, {"Vi", 1.8}, {"BSNL", 2.5}}},
        {"Bhopal", {{"Airtel", 2.0}, {"Jio", 1.8}, {"Vi", 2.0}, {"BSNL", 2.5}}},
        {"Indore", {{"Airtel", 2.0}, {"Jio", 1.5}, {"Vi", 1.8}, {"BSNL", 2.5}}},
        {"Vadodara", {{"Airtel", 2.5}, {"Jio", 2.0}, {"Vi", 2.2}, {"BSNL", 2.0}}},
        {"Patna", {{"Airtel", 2.0}, {"Jio", 1.8}, {"Vi", 2.0}, {"BSNL", 2.5}}},
        {"Goa", {{"Airtel", 2.0}, {"Jio", 1.5}, {"Vi", 1.8}, {"BSNL", 2.5}}},
        {"Ranchi", {{"Airtel", 2.0}, {"Jio", 1.8}, {"Vi", 2.0}, {"BSNL", 2.5}}},
        {"Nagpur", {{"Airtel", 2.0}, {"Jio", 1.5}, {"Vi", 1.8}, {"BSNL", 2.5}}},
        {"Bhubaneswar", {{"Airtel", 2.0}, {"Jio", 1.5}, {"BSNL", 2.5}}},
        {"Dhanbad", {{"Airtel", 2.5}, {"Jio", 2.0}, {"Vi", 2.2}}},
        
        // Added more popular countries
        {"United States", {{"Verizon", 10.0}, {"T-Mobile", 8.5}, {"AT&T", 7.0}}},
        {"Canada", {{"Telus", 10.0}, {"Rogers", 9.0}, {"Bell", 8.5}}},
        {"United Kingdom", {{"EE", 12.0}, {"Vodafone", 11.5}, {"Three", 9.5}}},
        {"Australia", {{"Telstra", 15.0}, {"Optus", 14.0}, {"Vodafone Australia", 13.5}}},
        {"Germany", {{"Deutsche Telekom", 10.0}, {"Vodafone", 9.0}, {"O2", 8.5}}},
        {"France", {{"Orange", 12.0}, {"SFR", 11.0}, {"Bouygues", 10.0}}},
        {"Italy", {{"TIM", 8.0}, {"Vodafone", 7.5}, {"Wind", 7.0}}},
        {"Japan", {{"NTT Docomo", 10.0}, {"SoftBank", 9.5}, {"AU", 9.0}}},
        {"South Korea", {{"SK Telecom", 10.0}, {"KT", 9.5}, {"LG U+", 9.0}}},
        {"Brazil", {{"Claro", 6.0}, {"TIM", 5.5}, {"Oi", 5.0}}},
        {"Mexico", {{"Telcel", 6.5}, {"Movistar", 5.5}, {"AT&T", 5.0}}},
        {"Russia", {{"MTS", 7.5}, {"Beeline", 7.0}, {"Megafon", 6.5}}},
        {"China", {{"China Mobile", 8.0}, {"China Unicom", 7.5}, {"China Telecom", 7.0}}},
        {"Spain", {{"Movistar", 8.5}, {"Vodafone", 8.0}, {"Orange", 7.5}}},
        {"Singapore", {{"Singtel", 9.0}, {"StarHub", 8.5}, {"M1", 8.0}}}
    };

    // Check if location matches a country or specific city
    if (sim_map.find(location) != sim_map.end()) {
        std::vector<std::string> result;
        for (const auto& sim : sim_map[location]) {
            int network_rating = rate_network_connectivity(sim.first);  // Network rating
            std::string price_rating = rate_data_price(sim.second);     // Data price rating

            // Construct the output string with network rating and data price
            std::string output = sim.first + " - Network Connectivity: " + std::to_string(network_rating) + "/10 - Data Price: $" + std::to_string(sim.second) + " (" + price_rating + ")";
            result.push_back(output);
        }
        return result;
    }

    // Default response if location is not found
    return {"SIM information not available for this location"};
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Please provide a location as a command-line argument.\n";
        return 1;
    }

    std::string location = argv[1];
    std::vector<std::string> sims = get_sim_suggestions(location);

    std::cout << "SIM Suggestions for " << location << ":\n";
    for (const auto& sim : sims) {
        std::cout << "- " << sim << "\n";
    }

    return 0;
}
