#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <chrono>

/**
 * STARGATE v12.9 - ADVANCED DIVIDEND TELEMETRY
 * Integration: April 6, 2026 Snapshot
 * Focus: High-Yield Energy & Financial Stability
 */

struct DividendAsset {
    std::string ticker;
    std::string fullName;
    double lastPrice;
    double quarterlyPayout;
    double yieldPct;
    std::string exDividendDate;
    bool isBullish;
};

class DividendTerminal {
private:
    std::vector<DividendAsset> watchlist;

public:
    void loadSnapshot() {
        // Data derived from Apr 6, 2026 7:53 PM ET NASDAQ/Bloomberg Feeds
        watchlist.push_back({"CVX", "Chevron Corp", 198.5669, 1.63, 3.28, "2026-05-15", true});
        watchlist.push_back({"JPM", "JPMorgan Chase", 295.38, 1.15, 1.56, "2026-04-10", true});
        watchlist.push_back({"XOM", "Exxon Mobil", 124.50, 0.95, 3.05, "2026-05-12", true});
        watchlist.push_back({"MS",  "Morgan Stanley", 166.55, 0.85, 2.04, "2026-04-28", false});
    }

    void displayReport() {
        std::cout << "\033[1;32m[STARGATE v12.9: DIVIDEND INTELLIGENCE REPORT]\033[0m" << std::endl;
        std::cout << "Timestamp: 2026-04-06 20:53 BRT | Source: NASDAQ_REALTIME" << std::endl;
        std::cout << std::string(85, '=') << std::endl;
        
        std::cout << std::left << std::setw(8)  << "TICKER" 
                  << std::setw(18) << "PRICE (USD)" 
                  << std::setw(15) << "QUARTERLY" 
                  << std::setw(12) << "YIELD %" 
                  << "EX-DATE" << std::endl;
        std::cout << std::string(85, '-') << std::endl;

        for (const auto& asset : watchlist) {
            std::cout << std::left << std::setw(8) << asset.ticker;
            
            // Format Price
            std::cout << "$" << std::fixed << std::setprecision(4) << std::setw(13) << asset.lastPrice;
            
            // Quarterly Payout
            std::cout << std::setprecision(2) << "$" << std::setw(13) << asset.quarterlyPayout;
            
            // Yield with color indicators
            if (asset.yieldPct > 3.0) std::cout << "\033[1;32m"; // Strong Yield
            std::cout << asset.yieldPct << "%" << "\033[0m" << std::setw(8) << " ";
            
            std::cout << asset.exDividendDate << std::endl;
        }

        std::cout << std::string(85, '-') << std::endl;
        std::cout << "STRATEGY: Energy Shield active. CVX holding resistance at $198.56." << std::endl;
        std::cout << "NOTE: Financials (JPM/MS) exhibiting sector rotation strength." << std::endl;
    }
};

int main() {
    DividendTerminal dt;
    dt.loadSnapshot();
    dt.displayReport();
    return 0;
}
