#pragma once

using namespace std;

namespace ai
{
    enum LootStrategy
    {
        LOOTSTRATEGY_QUEST = 1,
        LOOTSTRATEGY_SKILL = 2,
        LOOTSTRATEGY_GRAY = 3,
        LOOTSTRATEGY_NORMAL = 4,
        LOOTSTRATEGY_ALL = 5
    };

    class LootObject
    {
    public:
        LootObject() {}
        LootObject(Player* bot, ObjectGuid guid);
        LootObject(const LootObject& other);

    public:
        bool IsEmpty() { return !guid; }
        bool IsLootPossible(Player* bot);
        void Refresh(Player* bot, ObjectGuid guid);
        WorldObject* GetWorldObject(Player* bot);
        ObjectGuid guid;

        uint32 skillId;
        uint32 reqSkillValue;
        uint32 reqItem;
    };

    class LootTarget
    {
    public:
        LootTarget(ObjectGuid guid);
        LootTarget(LootTarget const& other);

    public:
        LootTarget& operator=(LootTarget const& other);
        bool operator< (const LootTarget& other) const;

    public:
        ObjectGuid guid;
        time_t asOfTime;
    };

    class LootTargetList : public set<LootTarget>
    {
    public:
        void shrink(time_t fromTime);
    };

    class LootObjectStack
    {
    public:
        LootObjectStack(Player* bot) : bot(bot) {}

    public:
        bool Add(ObjectGuid guid);
        void Remove(ObjectGuid guid);
        void Clear();
        bool CanLoot(float maxDistance);
        LootObject GetLoot(float maxDistance = 0);

    private:
        vector<LootObject> OrderByDistance(float maxDistance = 0);

    private:
        Player* bot;
        LootTargetList availableLoot;
    };

};
