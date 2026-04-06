#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

/**
 * STARGATE v12.9 - REAL-TIME ALERT MODULE
 * Integration: Support Level Monitoring & Sector Pivot Detection
 * Mission: BloombergAsiav1 / Rio-SP Operations
 */

struct MarketSignal {
    std::string ticker;
    double current_price;
    double support_floor;
    std::string alert_msg;
};

class AlertSystem {
public:
    void evaluate(const std::vector<MarketSignal>& signals) {
        std::cout << "\033[1;31m[STARGATE v12.9: ALERT SYSTEM - MISSION MONITOR]\033[0m" << std::endl;
        std::cout << "Target: Support Floors & Institutional Stability\n";
        std::cout << std::string(85, '=') << std::endl;
        std::cout << std::left << std::setw(10) << "TICKER" 
                  << std::setw(15) << "CURRENT" 
                  << std::setw(15) << "SUPPORT" 
                  << "STATUS_SIGNAL" << std::endl;
        std::cout << std::string(85, '-') << std::endl;

        for (const auto& s : signals) {
            std::cout << std::left << std::setw(10) << s.ticker 
                      << "$" << std::fixed << std::setprecision(4) << std::setw(14) << s.current_price
                      << "$" << std::setw(14) << s.support_floor;

            if (s.current_price <= s.support_floor) {
                std::cout << "\033[1;31m[CRITICAL_BREAKOUT_DOWN]\033[0m";
            } else if (s.current_price <= s.support_floor * 1.01) {
                std::cout << "\033[1;33m[TESTING_SUPPORT]\033[0m";
            } else {
                std::cout << "\033[1;32m[HOLDING_RESISTANCE]\033[0m";
            }
            std::cout << "\n  \033[3m>> " << s.alert_msg << "\033[0m\n" << std::endl;
        }
        std::cout << std::string(85, '=') << std::endl;
        std::cout << "Alert Status: MONITORING_ACTIVE | Registry: BloombergAsiav1\n";
    }
};

int main() {
    AlertSystem st_alerts;

    // Derived from 20:53 BRT Telemetry
    std::vector<MarketSignal> active_session = {
        {"CVX", 198.5669, 198.0000, "Energy Shield Floor - Critical for Dividends"},
        {"JPM", 295.3800, 290.0000, "Banking Anchor - Watch for sector rotation inflow"},
        {"NDX", 24192.17, 24000.00, "BigTech Ceiling - High volatility alert"},
        {"MS",  166.5500, 165.0000, "Financial Sector stability pivot"}
    };

    st_alerts.evaluate(active_session);

    return 0;
}
