#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

/* * STARGATE v12.9 - SECTOR GAIN ESTIMATOR
 * Focus: BigTech (Software/AI) & Global Banking
 * Logic: Gartner 2026 IT Spend + JPM/GS Equity Forecasts
 */

struct SectorOutlook {
    std::string sector;
    double current_val;
    double est_growth_pct; // 2026 Full Year Forecast
    std::string catalyst;
};

void run_estimation() {
    // Data Ingest from April 2026 Analysis
    std::vector<SectorOutlook> markets = {
        {"AI_INFRA",    653.40,  31.7, "Data Center Server Acceleration"},
        {"SOFTWARE",    1433.6,  14.7, "Agentic AI Integration (40% Adoption)"},
        {"BIG_BANKS",   295.38,  11.5, "Fee Income + M&A Rebound (JPM/GS)"},
        {"CUSTODY",     122.13,  10.2, "Asset Under Custody (AUC) Expansion"}
    };

    std::cout << "\033[1;36m[STARGATE v12.9 - TECH & BANKING GAIN ESTIMATES]\033[0m\n";
    std::cout << "Context: 2026 Market Outlook (Sturdy 2.8% Global GDP)\n";
    std::cout << std::string(80, '=') << "\n";
    std::cout << std::left << std::setw(12) << "SECTOR" 
              << std::setw(15) << "BASE (B/$)" 
              << std::setw(15) << "EST GAIN %" 
              << std::setw(15) << "PROJECTED" 
              << "CATALYST" << "\n";
    std::cout << std::string(80, '-') << "\n";

    for (const auto& m : markets) {
        double projected = m.current_val * (1 + (m.est_growth_pct / 100.0));
        
        std::cout << std::left << std::setw(12) << m.sector 
                  << std::fixed << std::setprecision(2) << std::setw(15) << m.current_val;
        
        // Color code high-growth sectors (Tech/AI)
        if (m.est_growth_pct > 15.0) std::cout << "\033[1;32m";
        else std::cout << "\033[32m";
        
        std::cout << "+" << std::setw(14) << std::to_string(m.est_growth_pct).substr(0,4) + "%" << "\033[0m"
                  << std::setw(15) << projected 
                  << "\033[3m" << m.catalyst << "\033[0m\n";
    }

    std::cout << std::string(80, '-') << "\n";
    std::cout << "Strategy: BigTech (Growth) paired with Banking (Yield/Stability).\n";
    std::cout << "Alert: IT Spending approaching $6.15 Trillion global cap.\n";
}

int main() {
    run_estimation();
    return 0;
}
