#include "estee/tick/core/handler.hpp"
#include "estee/tick/trade/trade.hpp"
#include "estee/tick/inside/inside.hpp"


#ifndef TICK_BOEHMER_H
#define TICK_BOEHMER_H
namespace tick {
    class Boehmer : public Handler{
        public:
            // constructor
            Boehmer(double);
            ~Boehmer();

            // member variable
            double tick_size;

            // source method
            void on_trade(Trade&);
            void on_inside(Inside&);
    };
}
#endif