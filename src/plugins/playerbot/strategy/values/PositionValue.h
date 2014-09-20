#pragma once
#include "../Value.h"

namespace ai
{
    class Position
    {
    public:
        Position() : valueSet(false) {}
        void Set(double x, double y, double z) { this->x = x; this->y = y; this->z = z; this->valueSet = true; }
        void Reset() { valueSet = false; }
        bool isSet() { return valueSet; }

        double x, y, z;
        bool valueSet;
    };

    class PositionValue : public ManualSetValue<Position&>, public Qualified
	{
	public:
        PositionValue(PlayerbotAI* ai);

	private:
        Position position;
    };
}
