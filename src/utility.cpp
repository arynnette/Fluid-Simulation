#include "utility.h"

namespace vectorgen {
    Vector2 generateVector2WithinBounds() {
        std::mt19937_64 mt_engine(std::random_device{}());

        std::uniform_int_distribution<int> dist_x(1, SCREEN_WIDTH);
        std::uniform_int_distribution<int> dist_y(1, SCREEN_HEIGHT);

        return Vector2 { dist_x(mt_engine) / 1.0f, dist_y(mt_engine) / 1.0f };
    };
}