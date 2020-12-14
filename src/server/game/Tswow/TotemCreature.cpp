// @tswow-begin
#include "TotemCreature.h"

TotemCreature::TotemCreature(SummonPropertiesEntry const* properties, Unit* owner)
    : Minion(properties, owner, false)
{
    this->m_isTempCreature = true;
    this->InitCharmInfo();
}

void TotemCreature::InitStats(uint32 lifetime)
{
    Minion::InitStats(lifetime);
    SetupTotemStats();
    SetHealth(this->GetMaxHealth());
    // TODO: Can we store this?
    this->SetReactState(REACT_DEFENSIVE);
}

void TotemCreature::SetupTotemStats()
{
    Unit* owner = GetSummonerUnit();
    if(!owner)
    {
        return;
    }

    uint32 petlevel = owner->GetLevel();
    bool isNewLevel = this->GetLevel() != petlevel;
    if (isNewLevel)
    {
        SetLevel(petlevel);
        CreatureTemplate const* cinfo = GetCreatureTemplate();

        // remove elite bonuses included in DB values
        CreatureBaseStats const* stats = sObjectMgr->GetCreatureBaseStats(petlevel, cinfo->unit_class);
        float healthmod = _GetHealthMod(cinfo->rank);
        uint32 basehp = stats->GenerateHealth(cinfo);
        uint32 health = uint32(basehp * healthmod);
        uint32 mana = stats->GenerateMana(cinfo);

        SetCreateHealth(health);
        SetCreateMana(mana);
        SetCreateStat(STAT_STRENGTH, 1);
        SetCreateStat(STAT_AGILITY, 1);
        SetCreateStat(STAT_STAMINA, 1);
        SetCreateStat(STAT_INTELLECT, 1);
        SetCreateStat(STAT_SPIRIT, 1);
        SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, float(petlevel - (petlevel / 4)));
        SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, float(petlevel + (petlevel / 4)));
        UpdateAllStats();
        SetArmor(petlevel*4);

        SetMaxHealth(health);
        this->SetHealth(health);
    }
}

void TotemCreature::Update(uint32 time)
{
    Minion::Update(time);
    SetupTotemStats();
}

// @tswow-end
