#include <stdexcept>
#include "./boehmer.hpp"


#include <iostream>
using namespace tick;
/*
To be precise,
for all trades reported to a FINRA TRF (exchange code “D” in TAQ), let Pit be the transaction
price in stock i at time t, and let Zit ≡ 100 * mod(Pit, 0.01) be the fraction of a penny associated
with that transaction price. Zit can take any value in the unit interval [0,1). If Zit is in the interval
(0,0.4), we identify it as a retail sell transaction. If Zit is in the interval (0.6,1), then the transaction
is coded as a retail buy transaction. To be conservative, transactions at a round penny (Zit = 0) or
near the half-penny (0.4 ≤ Zit ≤ 0.6) are not assigned to the retail category.
*/


Boehmer::Boehmer(double tick_size) {
    this->tick_size = 0.01;
}


Boehmer::~Boehmer() {
}


void Boehmer::on_inside(Inside& inside) {
    throw std::runtime_error("should not hit this");
}


void Boehmer::on_trade(Trade& trade) {
    if (trade.ex != "ADF")
        return;
    std::cout << trade.to_string() << std::endl;
}
