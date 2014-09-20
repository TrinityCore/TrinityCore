#pragma once

using namespace std;

class Player;

namespace ai
{
    class Engine;

	class RangePair {
	public:
		RangePair() {
			min = -1.0f;
			max = -1.0f;
		}

	public:
		float min;
		float max;

	public:
		void probe(float d) {
			if (min < 0 || min > d)
				min = d;

			if (max < 0 || max < d)
				max = d;
		}
	};

	class FleePoint {
	public:
		FleePoint(float x, float y, float z) {
			this->x = x;
			this->y = y;
			this->z = z;
		}

    public:
        bool isReasonable();
        bool isBetterByCreatures(FleePoint* other);
        bool isBetterByAll(FleePoint* other);

	public:
		float x;
		float y;
		float z;

		RangePair toCreatures;
		RangePair toAllPlayers;
		RangePair toMeleePlayers;
		RangePair toRangedPlayers;
	};

	class FleeManager
	{
	public:
		FleeManager(Player* bot, float maxAllowedDistance, float followAngle) {
			this->bot = bot;
			this->maxAllowedDistance = maxAllowedDistance;
			this->followAngle = followAngle;
		}

	public:
		bool CalculateDestination(float* rx, float* ry, float* rz);

	private:
		void calculatePossibleDestinations(list<FleePoint*> &points);
		void calculateDistanceToPlayers(FleePoint *point);
		void calculateDistanceToCreatures(FleePoint *point);
		void cleanup(list<FleePoint*> &points);
		FleePoint* selectOptimalDestination(list<FleePoint*> &points);
		bool isReasonable(FleePoint* point);
		bool isBetterThan(FleePoint* point, FleePoint* other);

	private:
		Player* bot;
		float maxAllowedDistance;
		float followAngle;
	};

};
