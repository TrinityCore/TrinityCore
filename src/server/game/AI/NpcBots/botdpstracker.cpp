#include "botdpstracker.h"
/*
Name: bot_dps_tracker
%Complete: 100
Comment: dps taken tracker for NPCBot system by Trickerer (onlysuffering@gmail.com)
DPS trackers may collect data from different bot owners if in party but this overdoing has no significance whatsoever
*/

enum DPSTrackerConstants : uint32
{
    DPS_UPDATE_TIMER        =  500, //recalculate dps every x ms
    MAX_DPS_TRACK_TIME      = 5000, //track damage taken for last x ms
    DPS_INACTIVE_TIMER      = 5000, //reset if combat not active for botparty for x ms
    //maximum tracked damage taken periods of DPS_UPDATE_TIMER during MAX_DPS_TRACK_TIME
    MAX_DAMAGES             = MAX_DPS_TRACK_TIME/DPS_UPDATE_TIMER
};

DPSTracker::DPSTracker()
{
    _updateTimer = 0;
    _inactiveTimer = 0;
    _trackTimer = 0;
    _active = false;
}

DPSTracker::~DPSTracker()
{
    for (DamageTakenMap::const_iterator itr = _damages.begin(); itr != _damages.end(); ++itr)
        delete[] itr->second;

    _damages.clear();
    _DPSes.clear();
}

void DPSTracker::Update(uint32 diff)
{
    if (_active)
    {
        _inactiveTimer += diff;
        _updateTimer += diff;
        _trackTimer += diff;

        if (_inactiveTimer >= DPS_INACTIVE_TIMER)
        {
            _Reset();
        }
        else if (_updateTimer >= DPS_UPDATE_TIMER)
        {
            _updateTimer -= DPS_UPDATE_TIMER;
            _Release();
        }
    }
}

void DPSTracker::_Reset()
{
    if (_active)
    {
        _active = false;

        for (DamageTakenMap::const_iterator itr = _damages.begin(); itr != _damages.end(); ++itr)
            for (uint8 i = 0; i != MAX_DAMAGES; ++i)
                itr->second[i] = 0;
        for (DPSTakenMap::iterator itr = _DPSes.begin(); itr != _DPSes.end(); ++itr)
            itr->second = 0;

        _updateTimer = 0;
        _inactiveTimer = 0;
        _trackTimer = 0;
    }
}

void DPSTracker::_Release()
{
    for (DamageTakenMap::const_iterator itr = _damages.begin(); itr != _damages.end(); ++itr)
    {
        uint32* dmgs = itr->second;
        uint32 total_damage = 0;
        for (uint8 i = 0; i != MAX_DAMAGES; ++i)
            total_damage += dmgs[i];

        _DPSes[itr->first] = uint32(total_damage / (0.001f * std::max<uint32>(1 * IN_MILLISECONDS, std::min<uint32>(_trackTimer, MAX_DPS_TRACK_TIME))));
        //TC_LOG_ERROR("entities.player", "DPSTracker::Release(): guidlow = %u, time = %u, tick damage %u, total %u, dps = %u",
        //    itr->first, _trackTimer, dmgs[0], total_damage, _DPSes[itr->first]);

        //shift
        for (int8 i = MAX_DAMAGES-1; i > 0; --i)
            dmgs[i] = dmgs[i-1];
        dmgs[0] = 0;
    }
}

void DPSTracker::_AccumulateDamage(uint64 guid, uint32 damage)
{
    DamageTakenMap::const_iterator itr = _damages.find(guid);

    if (itr == _damages.end())
    {
        uint32* dmgarray = new uint32[MAX_DAMAGES];
        memset(dmgarray, 0, sizeof(uint32)*MAX_DAMAGES);

        dmgarray[0] = damage;

        _damages[guid] = dmgarray;
        return;
    }

    itr->second[0] += damage;
}
//victim is bot owner, bot, party player or party bot; checked in Unit::DealDamage()
void DPSTracker::TrackDamage(Unit const* victim, uint32 damage)
{
    //TC_LOG_ERROR("entities.player", "DPSTracker::OnDamage(): on %s, damage %u", victim->GetName().c_str(), damage);

    _SetActive();
    _AccumulateDamage(victim->GetGUID().GetRawValue(), damage);
}

void DPSTracker::_SetActive()
{
    _inactiveTimer = 0;
    if (!_active)
        _active = true;
}

uint32 DPSTracker::GetDPSTaken(uint64 guid) const
{
    DPSTakenMap::const_iterator itr = _DPSes.find(guid);
    //TC_LOG_ERROR("entities.player", "DPSTracker::GetDPSTaken(): from %u, damage %u", guid, itr != _DPSes.end() ? itr->second : 0);
    return itr != _DPSes.end() ? itr->second : 0;
}
