#pragma once
#include "../Value.h"

namespace ai
{
    class CraftData
    {
    public:
        CraftData() : itemId(0) {}
        CraftData(const CraftData& other) : itemId(other.itemId)
        {
            required.insert(other.required.begin(), other.required.end());
            obtained.insert(other.obtained.begin(), other.obtained.end());
        }

    public:
        uint32 itemId;
        map<uint32, int> required, obtained;

    public:
        bool IsEmpty() { return itemId == 0; }
        void Reset() { itemId = 0; }
        bool IsRequired(uint32 item) { return required.find(item) != required.end(); }
        bool IsFulfilled()
        {
            for (map<uint32, int>::iterator i = required.begin(); i != required.end(); ++i)
            {
                uint32 item = i->first;
                if (obtained[item] < i->second)
                    return false;
            }

            return true;
        }
        void AddObtained(uint32 itemId, uint32 count)
        {
            if (IsRequired(itemId))
            {
                obtained[itemId] += count;
            }
        }
        void Crafted(uint32 count)
        {
            for (map<uint32, int>::iterator i = required.begin(); i != required.end(); ++i)
            {
                uint32 item = i->first;
                if (obtained[item] >= required[item] * count)
                {
                    obtained[item] -= required[item] * count;
                }
            }
        }
    };

    class CraftValue : public ManualSetValue<CraftData&>
	{
	public:
        CraftValue(PlayerbotAI* ai) : ManualSetValue<CraftData&>(ai, data) {}

	private:
        CraftData data;
    };
}
