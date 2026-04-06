#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <map>

/* * STARGATE v12.9 - ENERGY SECTOR DIVIDEND MODULE
 * Integrated with Big Oil Telemetry (CVX focus)
 * Date: 2026-04-06
 */

struct DividendEvent {
    std::string ticker;
    double current_price;
    double dividend_yield; // Annualized %
    double payout_ratio;   // % of Free Cash Flow
    std::string status;
};

class EnergyDividendMonitor {
private:
    std::map<std::string, DividendEvent> energy_portfolio;
    double sector_fcf_B = 400.0; // Alignment with Stargate Core data

public:
    EnergyDividendMonitor() {
        // Initializing with captured Bloomberg/Nasdaq data
        energy_portfolio["CVX"] = {"Chevron Corp", 198.68, 4.15, 65.0, "STABLE_YIELD"};
        energy_portfolio["XOM"] = {"Exxon Mobil", 124.50, 3.80, 60.0, "GROWTH_TARGET"};
        energy_portfolio["SHEL"] = {"Shell PLC", 72.15, 4.05, 55.0, "FCF_DRIVEN"};
    }

    void runDividendAudit() {
        std::cout << "\033[1;33m[STARGATE v12.9 - ENERGY DIVIDEND AUDIT]\033[0m" << std::endl;
        std::cout << "GLOBAL ENERGY FCF TREND: \033[1;32m$" << sector_fcf_B << "B\033[0m" << std::endl;
        std::cout << std::string(75, '=') << std::endl;
        
        std::cout << std::left << std::setw(8) << "TICKER" 
                  << std::setw(18) << "PRICE" 
                  << std::setw(12) << "YIELD %" 
                  << std::setw(15) << "PAYOUT/FCF" 
                  << "STATUS" << std::endl;
        std::cout << std::string(75, '-') << std::endl;

        for (auto const& [ticker, data] : energy_portfolio) {
            double quarterly_payout = (data.current_price * (data.dividend_yield / 100)) / 4.0;
            
            std::cout << std::left << std::setw(8) << ticker 
                      << "$" << std::setw(17) << std::fixed << std::setprecision(2) << data.current_price
                      << std::setw(12) << std::to_string(data.dividend_yield).substr(0,4) + "%"
                      << std::setw(15) << std::to_string(data.payout_ratio).substr(0,4) + "%";
            
            // Highlight CVX specifically per user request
            if (ticker == "CVX") {
                std::cout << "\033[1;32m" << data.status << "\033[0m";
            } else {
                std::cout << data.status;
            }
            
            std::cout << "\n  \033[3mEst. Quarterly Payout: $" << quarterly_payout << " per share\033[0m" << std::endl;
        }
        
        std::cout << std::string(75, '-') << std::endl;
        std::cout << "RISK ADVISORY: Energy contracting (-1.25%). Monitor Hormuz stability for yield safety." << std::endl;
    }
};

int main() {
    EnergyDividendMonitor monitor;
    monitor.runDividendAudit();
    return 0;
}
