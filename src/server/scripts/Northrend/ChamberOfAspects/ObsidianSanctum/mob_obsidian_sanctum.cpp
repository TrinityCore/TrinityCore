/* ScriptData
SDName: Naxxramas
SD%Complete: ??
SDComment: Trash Scripts
SDCategory: Naxxramas
EndScriptData */

#include "ScriptPCH.h"
#include "obsidian_sanctum.h"

enum Spells
{
    // Onyx Blaze Mistress
    SPELL_CONJURE_FLAME_ORB     = 57753,
    SPELL_FLAME_SHOCK           = 39529,
    SPELL_FLAME_SHOCK_H         = 58940,
    SPELL_RAIN_OF_FIRE          = 57757,
    SPELL_RAIN_OF_FIRE_H        = 58936,
    // Onyx Brood General
    SPELL_AVENGING_FURY         = 57742,
    SPELL_DEVOTION_AURA         = 57740, // Permanent
    SPELL_DEVOTION_AURA_H       = 58944, // Permanent
    SPELL_DRACONIC_RAGE         = 57733,
    SPELL_DRACONIC_RAGE_H       = 58942,
    SPELL_MORTAL_STRIKE         = 13737,
    // Onyx Flight Captain
    SPELL_HAMMER_DROP           = 57759,
    SPELL_PUMMEL                = 58953,
    // Onyx Sanctum Guardian
    SPELL_CURSE_OF_MENDING      = 39647, // Permanent
    SPELL_CURSE_OF_MENDING_H    = 58948, // Permanent
    SPELL_FRENZY                = 53801,
    SPELL_SHOCKWAVE             = 57728,
    SPELL_SHOCKWAVE_H           = 58947
};

struct mob_obsidian_sanctum_trashAI : public ScriptedAI
{
    mob_obsidian_sanctum_trashAI(Creature *c) : ScriptedAI(c)
    {
        if(c->GetMap()->IsDungeon())
            pInstance = c->GetInstanceScript();

        c->setActive(true);
    }

    InstanceScript* pInstance;
    uint32 AreaInCombat_Timer;
    uint32 SartharionCheck_Timer;

    void Reset()
    {
        AreaInCombat_Timer = 5000;
        SartharionCheck_Timer = 5000;
    }

    void SendAttacker(Unit* target) // Exploit Fix
    {
        std::list<Creature*> templist;
        float x, y, z;
        me->GetPosition(x, y, z);

        {
            CellPair pair(Trinity::ComputeCellPair(x, y));
            Cell cell(pair);
            cell.data.Part.reserved = ALL_DISTRICT;
            cell.SetNoCreate();

            Trinity::AllFriendlyCreaturesInGrid check(me);
            Trinity::CreatureListSearcher<Trinity::AllFriendlyCreaturesInGrid> searcher(me, templist, check);

            TypeContainerVisitor<Trinity::CreatureListSearcher<Trinity::AllFriendlyCreaturesInGrid>, GridTypeMapContainer> cSearcher(searcher);

            cell.Visit(pair, cSearcher, *(me->GetMap()));
        }

        if(!templist.size())
            return;

        for(std::list<Creature*>::iterator i = templist.begin(); i != templist.end(); ++i)
        {
            if((*i) && me->IsWithinDistInMap((*i),10))
            {
                if(!(*i)->isInCombat() && !me->getVictim())
                    (*i)->AI()->AttackStart(target);
            }
        }
    }

    void EnterCombat(Unit *who)
    {
        DoAttackerAreaInCombat(who, 100);
        Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
        if(ptarget)
            SendAttacker(ptarget);
    }
    void KilledUnit(Unit *victim){}
    void JustDied(Unit *victim){}

    Creature* FindNearestCreature(uint32 entry, float range)
    {
        Creature *creature = NULL;
        Trinity::NearestCreatureEntryWithLiveStateInObjectRangeCheck checker(*me, entry, true, range);
        Trinity::CreatureLastSearcher<Trinity::NearestCreatureEntryWithLiveStateInObjectRangeCheck> searcher(me, creature, checker);
        me->VisitNearbyObject(range, searcher);
        return creature;
    }

    void DoAggroPuls(const uint32 diff)
    {
        if(AreaInCombat_Timer <= diff)
        {
            DoAttackerAreaInCombat(me->getVictim(), 100);
            AreaInCombat_Timer = 5000;
        }else AreaInCombat_Timer -= diff;
    }

    bool TryDoCast(Unit *victim, uint32 spellId, bool triggered = false)
    {
        if(me->IsNonMeleeSpellCasted(false) && !triggered) return false;

        DoCast(victim,spellId,triggered);
        return true;
    }

    bool TryDoCastAOE(uint32 spellId, bool triggered = false)
    {
        if(me->IsNonMeleeSpellCasted(false) && !triggered) return false;

        DoCastAOE(spellId,triggered);
        return true;
    }

    void UpdateAI(const uint32 diff)
    {
        if(!me->getVictim())
        {
            if(SartharionCheck_Timer < diff)
            {
                if(Creature* sarth = Creature::GetCreature((*me),pInstance->GetData64(DATA_SARTHARION)))
                {
                    if(sarth->getVictim())
                        me->AI()->AttackStart(sarth->getVictim());
                }
                SartharionCheck_Timer = 5000;
            }else SartharionCheck_Timer -= diff;
        }

        if (!UpdateVictim() )
            return;

        DoAggroPuls(diff);

        DoMeleeAttackIfReady();
    }
};

class mob_obsidian_sanctum_trash : public CreatureScript
{
public:
    mob_obsidian_sanctum_trash() : CreatureScript("mob_obsidian_sanctum_trash") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        switch(pCreature->GetEntry())
        {
        case 30681: return new mob_onyx_blaze_mistressAI (pCreature);
        case 30680: return new mob_onyx_brood_generalAI (pCreature);
        case 30682: return new mob_onyx_flight_captainAI (pCreature);
        case 30453: return new mob_onyx_sanctum_guardianAI (pCreature);
        default: return new mob_onyx_sanctum_guardianAI (pCreature);
        }
    }

    struct mob_onyx_blaze_mistressAI: public mob_obsidian_sanctum_trashAI
    {
        mob_onyx_blaze_mistressAI(Creature *c) : mob_obsidian_sanctum_trashAI(c) { }

        uint32 ui_Shock_Timer;
        uint32 ui_Rain_Timer;
        uint32 ui_FlameOrb_Timer;

        void Reset()
        {
            ui_Shock_Timer = urand(5000,10000);
            ui_Rain_Timer =  urand(15000,25000);
            ui_FlameOrb_Timer =  urand(15000,25000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(ui_Shock_Timer <= diff)
            {
                if(TryDoCast(me->getVictim(),RAID_MODE(SPELL_FLAME_SHOCK,SPELL_FLAME_SHOCK_H)))
                    ui_Shock_Timer = urand(2000,7000);
            }else ui_Shock_Timer -= diff;

            if(ui_Rain_Timer <= diff)
            {
                if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1,40,false))
                    if(TryDoCast(target,RAID_MODE(SPELL_RAIN_OF_FIRE,SPELL_RAIN_OF_FIRE_H)))
                        ui_Rain_Timer =  urand(15000,25000);
            }else ui_Rain_Timer -= diff;

            if(ui_FlameOrb_Timer <= diff)
            {
                if(TryDoCastAOE(SPELL_CONJURE_FLAME_ORB))
                    ui_FlameOrb_Timer = urand(15000,25000);
            }else ui_FlameOrb_Timer -= diff;


            mob_obsidian_sanctum_trashAI::UpdateAI(diff);
        }
    };

    struct mob_onyx_brood_generalAI: public mob_obsidian_sanctum_trashAI
    {
        mob_onyx_brood_generalAI(Creature *c) : mob_obsidian_sanctum_trashAI(c) { }

        uint32 ui_Strike_Timer;
        uint32 ui_Fury_Timer;
        uint32 ui_Rage_Timer;

        void Reset()
        {
            ui_Strike_Timer = urand(5000,10000);
            ui_Fury_Timer =  urand(15000,25000);
            ui_Rage_Timer =  urand(30000,45000);
        }

        void EnterCombat(Unit *who)
        {
            mob_obsidian_sanctum_trashAI::EnterCombat(who);

            DoCastAOE(RAID_MODE(SPELL_DEVOTION_AURA,SPELL_DEVOTION_AURA_H));
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(ui_Strike_Timer <= diff)
            {
                if(TryDoCast(me->getVictim(),SPELL_MORTAL_STRIKE))
                    ui_Strike_Timer = urand(2000,7000);
            }else ui_Strike_Timer -= diff;

            if(ui_Rage_Timer <= diff)
            {
                if(TryDoCastAOE(RAID_MODE(SPELL_DRACONIC_RAGE,SPELL_DRACONIC_RAGE_H)))
                    ui_Rage_Timer =  urand(30000,45000);
            }else ui_Rage_Timer -= diff;

            if(ui_Fury_Timer <= diff)
            {
                if(TryDoCastAOE(SPELL_AVENGING_FURY))
                    ui_Fury_Timer = urand(15000,25000);
            }else ui_Fury_Timer -= diff;

            mob_obsidian_sanctum_trashAI::UpdateAI(diff);
        }
    };

    struct mob_onyx_flight_captainAI: public mob_obsidian_sanctum_trashAI
    {
        mob_onyx_flight_captainAI(Creature *c) : mob_obsidian_sanctum_trashAI(c) { }

        uint32 ui_HammerDrop_Timer;
        uint32 ui_Pummel_Timer;

        void Reset()
        {
            ui_HammerDrop_Timer = urand(5000,10000);
            ui_Pummel_Timer = urand(5000,10000);
        }

        void EnterCombat(Unit *who)
        {
            mob_obsidian_sanctum_trashAI::EnterCombat(who);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(ui_HammerDrop_Timer <= diff)
            {
                if(TryDoCast(me->getVictim(),SPELL_HAMMER_DROP))
                    ui_HammerDrop_Timer = urand(5000,10000);
            }else ui_HammerDrop_Timer -= diff;

            if(ui_Pummel_Timer <= diff)
            {
                if(TryDoCast(me->getVictim(),SPELL_PUMMEL))
                    ui_Pummel_Timer =  urand(5000,10000);
            }else ui_Pummel_Timer -= diff;

            mob_obsidian_sanctum_trashAI::UpdateAI(diff);
        }
    };

    struct mob_onyx_sanctum_guardianAI: public mob_obsidian_sanctum_trashAI
    {
        mob_onyx_sanctum_guardianAI(Creature *c) : mob_obsidian_sanctum_trashAI(c) { }

        uint32 ui_Frenzy_Timer;
        uint32 ui_Shockwave_Timer;

        void Reset()
        {
            ui_Shockwave_Timer = urand(10000,15000);
            ui_Frenzy_Timer = urand(25000,35000);
        }

        void EnterCombat(Unit *who)
        {
            mob_obsidian_sanctum_trashAI::EnterCombat(who);

            DoCastAOE(RAID_MODE(SPELL_CURSE_OF_MENDING,SPELL_CURSE_OF_MENDING_H));
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(ui_Shockwave_Timer <= diff)
            {
                if(TryDoCast(me->getVictim(),RAID_MODE(SPELL_SHOCKWAVE,SPELL_SHOCKWAVE_H)))
                    ui_Shockwave_Timer = urand(5000,10000);
            }else ui_Shockwave_Timer -= diff;

            if(ui_Frenzy_Timer <= diff)
            {
                if(TryDoCast(me,SPELL_FRENZY))
                    ui_Frenzy_Timer =  urand(20000,30000);
            }else ui_Frenzy_Timer -= diff;

            mob_obsidian_sanctum_trashAI::UpdateAI(diff);
        }
    };
};

// UPDATE creature_template SET scriptname = 'mob_obsidian_sanctum_trash' WHERE entry in (30681,30680,30682,30453);
void AddSC_mob_obsidian_sanctum()
{
    new mob_obsidian_sanctum_trash();
}