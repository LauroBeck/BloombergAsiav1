#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <map>

// Data-oriented structures for Bloomberg telemetry
enum class Sector { IT, Media, Software, Retail, Metals, Index };

struct Instrument {
    std::string ticker;
    double price;
    double change;
    Sector sector;
};

int main() {
    // Current Snapshot from Bloomberg "The Close" 2026-04-06
    std::vector<Instrument> watchlist = {
        {"STX", 453.30, 5.58, Sector::IT},
        {"WDC", 304.15, 3.11, Sector::IT},
        {"SPX", 6611.99, 0.45, Sector::Index},
        {"INDU", 46669.82, 0.36, Sector::Index},
        {"IBOV", 188279.30, 0.12, Sector::Index}
    };

    // Margin Projections from Bar Chart (Q424 -> Q425)
    std::map<Sector, std::pair<double, double>> margins = {
        {Sector::Media, {19.2, 29.5}},
        {Sector::Software, {14.8, 22.0}},
        {Sector::Retail, {12.5, 18.2}}
    };

    std::cout << "\033[1;32mBloomberg Terminal | Market Close Telemetry | 2026-04-06\033[0m\n";
    std::cout << std::string(75, '-') << "\n";
    std::cout << std::left << std::setw(10) << "TICKER" 
              << std::setw(12) << "PRICE" 
              << std::setw(10) << "CHANGE%" 
              << "STATUS/NOTES" << "\n";
    std::cout << std::string(75, '-') << "\n";

    for (const auto& i : watchlist) {
        std::cout << std::left << std::setw(10) << i.ticker 
                  << std::fixed << std::setprecision(2) << std::setw(12) << i.price
                  << (i.change > 0 ? "+" : "") << std::setw(9) << i.change << "% ";

        // Signal Logic
        if (i.change > 5.0) {
            std::cout << "\033[1;31m[BREAKOUT DETECTED]\033[0m";
        } else if (i.change > 0.40) {
            std::cout << "\033[1;33m[STRENGTH]\033[0m";
        }
        
        std::cout << std::endl;
    }

    std::cout << "\n\033[1;34mSector Margin Forecast (Q425 Target):\033[0m\n";
    for (auto const& [sector, val] : margins) {
        std::cout << "Sector Shift: " << val.first << "% -> " << val.second << "%\n";
    }

    return 0;
}
