#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <map>

/* * STARGATE v12.9 - SECTOR ANALYSIS & EMERGING RISKS ENGINE
 * Author: Senior Enterprise Architect
 * Target: Market Dynamics Simulation (2026-04-06)
 */

enum class GICS_Sector { IT, Financials, Energy, HealthCare, ConsumerDisc, StorageHardware };

struct SectorStats {
    std::string name;
    double daily_change;
    double cash_position_B; // Billions
    std::string risk_profile;
};

class StargateMonitor {
private:
    std::map<GICS_Sector, SectorStats> registry;
    double global_fcf_B = 400.0;
    std::string geopolitical_trigger = "STORM_IN_HORMUZ";

public:
    StargateMonitor() {
        registry[GICS_Sector::IT]        = {"Information Tech", 0.49, 0.0, "Bullish_Leader"};
        registry[GICS_Sector::Financials] = {"Financial Institutions", 0.32, 1300.0, "Stable_Peak_Cash"};
        registry[GICS_Sector::StorageHardware] = {"Storage Tech", 5.58, 0.0, "EXPLOSIVE_BREAKOUT"};
        registry[GICS_Sector::Energy]    = {"Energy Sector", -1.25, 0.0, "GEOPOLITICAL_VOLATILITY"};
    }

    void executeAnalysis() {
        std::cout << "\033[1;36m[STARGATE v12.9 - SECTOR INTELLIGENCE REPORT]\033[0m\n";
        std::cout << "GEOPOLITICAL STATUS: \033[1;31mRALLY_STALL (IRAN_TERRITORY_THREATS)\033[0m\n";
        std::cout << "CRITICAL CHOKPOINT: STRAIT_OF_HORMUZ\n";
        std::cout << std::string(75, '=') << "\n";
        
        std::cout << std::left << std::setw(20) << "SECTOR" 
                  << std::setw(12) << "CHG%" 
                  << std::setw(15) << "CASH_POS" 
                  << "RISK_SIGNAL" << "\n";
        std::cout << std::string(75, '-') << "\n";

        for (auto const& [key, val] : registry) {
            std::cout << std::left << std::setw(20) << val.name;
            
            // Color Logic
            if (val.daily_change > 0) std::cout << "\033[32m+" << std::setw(11) << val.daily_change << "%\033[0m";
            else std::cout << "\033[31m" << std::setw(12) << val.daily_change << "%\033[0m";

            std::cout << std::setw(15) << (val.cash_position_B > 0 ? "$" + std::to_string((int)val.cash_position_B) + "B" : "---");
            
            // Signal Highlighting
            if (val.daily_change > 3.0) std::cout << "\033[1;31m[" << val.risk_profile << "]\033[0m";
            else std::cout << val.risk_profile;
            
            std::cout << std::endl;
        }

        std::cout << std::string(75, '-') << "\n";
        std::cout << "MARKET_WIDE_FCF_TREND: \033[1;32m$" << global_fcf_B << "B\033[0m\n";
        std::cout << "STORAGE_WATCH: STX ($453.30) | WDC ($304.15) -> [HARDWARE_LAYERING_ACTIVE]\n";
    }
};

int main() {
    StargateMonitor monitor;
    monitor.executeAnalysis();
    return 0;
}
