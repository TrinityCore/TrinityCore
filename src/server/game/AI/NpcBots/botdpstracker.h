#ifndef _BOT_DPSTRACKER_H
#define _BOT_DPSTRACKER_H

#include "Define.h"

#include <unordered_map>

class Unit;

class DPSTracker
{
    public:
        DPSTracker();
        ~DPSTracker();

        void Update(uint32 diff);

        void TrackDamage(Unit const* victim, uint32 damage);
        uint32 GetDPSTaken(uint64 guid) const;

    private:
        void _Reset();
        void _Release();
        void _AccumulateDamage(uint64 guid, uint32 damage);
        void _SetActive();

        typedef std::unordered_map<uint64 /*guid*/, uint32* /*dmgarray*/> DamageTakenMap;
        typedef std::unordered_map<uint64 /*guid*/, uint32 /*dps*/> DPSTakenMap;
        DamageTakenMap _damages;
        DPSTakenMap _DPSes;

        uint32 _updateTimer;
        uint32 _inactiveTimer;
        uint32 _trackTimer;
        bool _active;
};

#endif
