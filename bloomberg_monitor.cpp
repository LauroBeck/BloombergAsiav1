#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <map>

// Sector definitions based on your Bloomberg GICS Sector map
enum class Sector {
    InteractiveMedia,
    Software,
    BroadlineRetail,
    Telecomm,
    MetalsMining,
    InformationTech
};

struct MarketTick {
    std::string ticker;
    double price;
    double change_percent;
    Sector sector;
};

struct SectorMargin {
    Sector sector;
    std::string name;
    double q424_margin;
    double q425_forecast;
};

class BloombergMonitor {
private:
    std::vector<MarketTick> active_ticks;
    std::map<Sector, SectorMargin> margin_projections;

public:
    BloombergMonitor() {
        // Initializing margins based on your bar chart data
        margin_projections[Sector::InteractiveMedia] = {Sector::InteractiveMedia, "Interactive Media", 19.2, 29.5};
        margin_projections[Sector::Software]         = {Sector::Software, "Software", 14.8, 22.0};
        margin_projections[Sector::BroadlineRetail]  = {Sector::BroadlineRetail, "Broadline Retail", 12.5, 18.2};
    }

    void addTick(const MarketTick& tick) {
        active_ticks.push_back(tick);
    }

    void runTelemetryReport() {
        std::cout << "\033[1;32m--- BLOOMBERG TERMINAL CLONE: 2026-04-06 ---\033[0m" << std::endl;
        std::cout << std::left << std::setw(10) << "TICKER" 
                  << std::setw(10) << "PRICE" 
                  << std::setw(12) << "CHANGE %" 
                  << "FORECAST MARGIN (Q425)" << std::endl;
        std::cout << std::string(70, '-') << std::endl;

        for (const auto& tick : active_ticks) {
            double forecast = margin_projections.count(tick.sector) ? 
                              margin_projections[tick.sector].q425_forecast : 0.0;

            std::cout << std::left << std::setw(10) << tick.ticker 
                      << std::fixed << std::setprecision(2) << "$" << std::setw(9) << tick.price;
            
            // Colorize based on change
            if (tick.change_percent >= 0) std::cout << "\033[32m+";
            else std::cout << "\033[31m";
            
            std::cout << std::setw(11) << tick.change_percent << "%\033[0m ";
            
            std::cout << (forecast > 0 ? std::to_string(forecast).substr(0,4) + "%" : "N/A");
            
            if (tick.change_percent > 5.0) {
                std::cout << " \033[1;31m[BREAKOUT]\033[0m";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    BloombergMonitor terminal;

    // Loading data from your provided screenshots
    terminal.addTick({"STX", 453.30, 5.58, Sector::InformationTech});
    terminal.addTick({"WDC", 304.15, 3.11, Sector::InformationTech});
    terminal.addTick({"SPX", 6611.99, 0.45, Sector::InformationTech});

    terminal.runTelemetryReport();

    return 0;
}
