#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <map>
#include <cmath>

// Data-Oriented structures for Institutional Telemetry
enum class AssetClass { 
    InvestmentBank, 
    CustodyBank, 
    CommercialBank, 
    Index,
    StorageHardware 
};

struct FinancialInstrument {
    std::string ticker;
    std::string name;
    double price;
    double change_pct;
    AssetClass type;
};

class InstitutionalTerminal {
private:
    std::vector<FinancialInstrument> registry;

public:
    void ingest(const FinancialInstrument& data) {
        registry.push_back(data);
    }

    void displayHeader() {
        std::cout << "\033[1;34m" << std::string(85, '=') << "\n";
        std::cout << " BLOOMBERG PROFESSIONAL: INSTITUTIONAL MONITORING [2026-04-06]\n";
        std::cout << std::string(85, '=') << "\033[0m\n";
        std::cout << std::left << std::setw(10) << "TICKER" 
                  << std::setw(25) << "INSTITUTION" 
                  << std::setw(15) << "PRICE" 
                  << std::setw(12) << "CHG %" 
                  << "SIGNAL" << std::endl;
        std::cout << std::string(85, '-') << std::endl;
    }

    void run() {
        displayHeader();
        for (const auto& i : registry) {
            std::cout << std::left << std::setw(10) << i.ticker 
                      << std::setw(25) << i.name 
                      << std::fixed << std::setprecision(2) << "$" << std::setw(14) << i.price;
            
            // Logic for Colorized P/L
            if (i.change_pct >= 0) {
                std::cout << "\033[32m+" << std::setw(10) << std::to_string(i.change_pct).substr(0,4) + "%" << "\033[0m";
            } else {
                std::cout << "\033[31m" << std::setw(11) << std::to_string(i.change_pct).substr(0,5) + "%" << "\033[0m";
            }
            
            // Intelligence Signals based on volatility and breakout thresholds
            if (i.change_pct > 5.0) {
                std::cout << " \033[1;31m[BREAKOUT]\033[0m";
            } else if (std::abs(i.change_pct) > 0.5 && i.type == AssetClass::Index) {
                std::cout << " \033[1;33m[VOL_SHIFT]\033[0m";
            } else if (i.change_pct > 0.8 && i.type == AssetClass::CustodyBank) {
                std::cout << " \033[1;36m[ACCUMULATION]\033[0m";
            }
            
            std::cout << std::endl;
        }
        std::cout << std::string(85, '-') << std::endl;
        std::cout << "\033[1;30mStatus: GLOBAL_CASH_FLOW_4Q25_READY | System: STARGATE_V12.9\033[0m\n";
    }
};

int main() {
    InstitutionalTerminal terminal;

    // Captured Telemetry: April 6, 2026
    terminal.ingest({"GS",   "Goldman Sachs",    861.99,   -0.12, AssetClass::InvestmentBank});
    terminal.ingest({"JPM",  "JPMorgan Chase",   295.38,    0.32, AssetClass::CommercialBank});
    terminal.ingest({"BK",   "BNY Mellon",       122.13,    0.96, AssetClass::CustodyBank});
    terminal.ingest({"MS",   "Morgan Stanley",   166.74,    0.43, AssetClass::InvestmentBank});
    terminal.ingest({"STX",  "Seagate Tech",     453.30,    5.58, AssetClass::StorageHardware});
    terminal.ingest({"SPX",  "S&P 500",          6611.99,   0.45, AssetClass::Index});
    terminal.ingest({"NDX",  "Nasdaq 100",       21996.34,  0.54, AssetClass::Index});

    terminal.run();

    return 0;
}
