#pragma once
#include "../Value.h"

namespace ai
{
    class Position
    {
    public:
        Position() : valueSet(false), x(0), y(0), z(0) {}
        Position(const Position &other) : valueSet(other.valueSet), x(other.x), y(other.y), z(other.z) {}
        void Set(double x, double y, double z) { this->x = x; this->y = y; this->z = z; this->valueSet = true; }
        void Reset() { valueSet = false; }
        bool isSet() { return valueSet; }

        double x, y, z;
        bool valueSet;
    };

    typedef map<string, Position> PositionMap;

    class PositionValue : public ManualSetValue<PositionMap&>
	{
	public:
        PositionValue(PlayerbotAI* ai);

	private:
        PositionMap positions;
    };
}
