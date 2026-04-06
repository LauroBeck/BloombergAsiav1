#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <map>

/* * STARGATE v12.9 - GEOPOLITICAL RISK DECAY MODULE
 * Scenario: Full Territory Control / End of Conflict
 * Logic: Exponential decay of war-time risk premiums
 */

class StargateRiskEngine {
private:
    bool territory_secured = true;
    bool strait_open = true;
    int days_since_occupation = 0; // T-0: Operation Tonight

public:
    StargateRiskEngine(int days) : days_since_occupation(days) {}

    // core decay logic: 15% initial premium dropping as stability returns
    double calculate_peace_dividend(double current_price) {
        double decay_constant = 0.5; // Aggressive normalization for "End of War"
        double initial_premium = 0.15; 
        
        double risk_premium = initial_premium * std::exp(-decay_constant * days_since_occupation);
        return current_price * (1.0 - risk_premium);
    }

    void runScenario(std::string asset, double price) {
        std::cout << "\033[1;35m[STARGATE v12.9 INTERFACE]\033[0m" << std::endl;
        
        if (territory_secured && strait_open) {
            std::cout << "STATUS: \033[1;32mGLOBAL_SUPPLY_CHAIN_RESTORED\033[0m" << std::endl;
            
            double adjusted_price = calculate_peace_dividend(price);
            double savings = price - adjusted_price;

            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Asset: " << std::left << std::setw(15) << asset << std::endl;
            std::cout << "War-Time Price:  $" << price << std::endl;
            std::cout << "Peace Dividend: -$" << savings << " (Risk Decay)" << std::endl;
            std::cout << "Target Value:    $" << adjusted_price << " [STABILIZED]" << std::endl;
        } else {
            std::cout << "STATUS: \033[1;31mCONFLICT_ACTIVE_PREMIUM_MAINTAINED\033[0m" << std::endl;
        }
        std::cout << "------------------------------------------------" << std::endl;
    }
};

int main(int argc, char* argv[]) {
    // Default to T-0 if no arg provided
    int day_count = (argc > 1) ? std::stoi(argv[1]) : 0;
    
    StargateRiskEngine engine(day_count);

    std::cout << "\n--- SCENARIO: HYPOTHETICAL OCCUPATION T+" << day_count << " ---\n" << std::endl;
    
    // Applying to your monitor targets
    engine.runScenario("BRENT_CRUDE", 124.50);
    engine.runScenario("GOLDMAN_SACHS", 861.99);
    engine.runScenario("JPM_CHASE", 295.38);

    return 0;
}
