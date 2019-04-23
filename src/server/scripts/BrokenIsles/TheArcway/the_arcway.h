#ifndef THE_ARCWAY_H
#define THE_ARCWAY_H

#define ArcwayScriptName "instance_the_arcway"
#define ArcwayMapId 1516
#define ArcwayDataHeaders "ARCWAY"

constexpr uint8 EncounterCount = 5;

enum ArcwayDataTypes
{
    DATA_CORSTILAX              = 0,
    DATA_GENERAL_XAKAL          = 1,
    DATA_NALTIRA                = 2,
    DATA_IVANYR                 = 3,
    DATA_ADVISOR_VANDROS        = 4,

    DATA_NIGHTWELL            = 1,
    DATA_NIGHTWELL_REMOVE    = 2,
};

enum ArcwayCreatureIds
{
    BOSS_ADVISOR_VANDROS    = 98208,
    BOSS_GENERAL_XAKAL      = 98206,
    BOSS_IVANYR             = 98203,
    BOSS_NALTIRA            = 98207,
    NPC_CORSTILAX           = 98205,
    NPC_DESTABILIZED_ORB    = 110863,    // Used in Corstilax encounter.
    NPC_QUARANTINE          = 99560        // Corstilax
};

struct NonMeleeTargetSelector : public std::unary_function<Unit*, bool>
{
    public:
        NonMeleeTargetSelector(Unit* source, bool playerOnly = true) : _source(source), _playerOnly(playerOnly) { }
        bool operator()(Unit const* target) const
        {
             if (!target)
                return false;

            if (_playerOnly && target->GetTypeId() != TYPEID_PLAYER)
                return false;

            return !_source->IsWithinMeleeRange(target);
        }

    private:
        Unit* _source;
        bool _playerOnly;
};

using SpellTargets = std::list<WorldObject*>;

#endif /* THE_ARCWAY_H */
