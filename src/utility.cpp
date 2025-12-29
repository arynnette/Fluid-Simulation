#include "utility.h"

namespace utility {
    Vector2 generateVector2WithinBounds() {
        std::mt19937_64 mt_engine(std::random_device{}());

        std::uniform_int_distribution<int> dist_x(1, SCREEN_WIDTH);
        std::uniform_int_distribution<int> dist_y(1, SCREEN_HEIGHT);

        return Vector2 { 
            static_cast<float>(dist_x(mt_engine)),
            static_cast<float>(dist_y(mt_engine))
        };
    };
}