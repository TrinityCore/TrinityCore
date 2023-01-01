/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/* ScriptData
SDName: Arcatraz
SD%Complete: 60
SDComment: Warden Mellichar, event controller for Skyriss event. Millhouse Manastorm. @todo make better combatAI for Millhouse.
SDCategory: Tempest Keep, The Arcatraz
EndScriptData */

/* ContentData
npc_millhouse_manastorm
npc_warden_mellichar
EndContentData */

#include "ScriptMgr.h"
#include "arcatraz.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ScriptedCreature.h"

/*#####
# npc_millhouse_manastorm
#####*/

enum MillhouseSays
{
    SAY_INTRO_1                = 0,
    SAY_INTRO_2                = 1,
    SAY_WATER                  = 2,
    SAY_BUFFS                  = 3,
    SAY_DRINK                  = 4,
    SAY_READY                  = 5,
    SAY_KILL                   = 6,
    SAY_PYRO                   = 7,
    SAY_ICEBLOCK               = 8,
    SAY_LOWHP                  = 9,
    SAY_DEATH                  = 10,
    SAY_COMPLETE               = 11,
};

enum MillhouseSpells
{
    SPELL_CONJURE_WATER        = 36879,
    SPELL_ARCANE_INTELLECT     = 36880,
    SPELL_ICE_ARMOR            = 36881,
    SPELL_ARCANE_MISSILES      = 33833,
    SPELL_CONE_OF_COLD         = 12611,
    SPELL_FIRE_BLAST           = 13341,
    SPELL_FIREBALL             = 14034,
    SPELL_FROSTBOLT            = 15497,
    SPELL_PYROBLAST            = 33975,
};

struct npc_millhouse_manastorm : public ScriptedAI
{
    npc_millhouse_manastorm(Creature* creature) : ScriptedAI(creature), Init(false)
    {
        Initialize();
        instance = creature->GetInstanceScript();
    }

    void Initialize()
    {
        EventProgress_Timer = 2000;
        LowHp = false;
        Phase = 1;

        Pyroblast_Timer = 1000;
        Fireball_Timer = 2500;
    }

    InstanceScript* instance;

    uint32 EventProgress_Timer;
    uint32 Phase;
    bool Init;
    bool LowHp;

    uint32 Pyroblast_Timer;
    uint32 Fireball_Timer;

    void Reset() override
    {
        Initialize();

        if (instance->GetData(DATA_WARDEN_2) == DONE)
        {
            Init = true;
            me->SetImmuneToNPC(false);
        }

        if (instance->GetBossState(DATA_HARBINGER_SKYRISS) == DONE)
            Talk(SAY_COMPLETE);
    }

    void AttackStart(Unit* who) override
    {
        if (me->Attack(who, true))
        {
            AddThreat(who, 0.0f);
            me->SetInCombatWith(who);
            who->SetInCombatWith(me);
            me->GetMotionMaster()->MoveChase(who, 25.0f);
        }
    }

    void KilledUnit(Unit* who) override
    {
        if (who->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_KILL);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);

        /*for questId 10886 (heroic mode only)
        if (instance->GetBossState(DATA_HARBINGER_SKYRISS) != DONE)
        ->FailQuest();*/
    }

    void UpdateAI(uint32 diff) override
    {
        if (!Init)
        {
            if (EventProgress_Timer <= diff)
            {
                if (Phase < 8)
                {
                    switch (Phase)
                    {
                    case 1:
                        Talk(SAY_INTRO_1);
                        EventProgress_Timer = 18000;
                        break;
                    case 2:
                        Talk(SAY_INTRO_2);
                        EventProgress_Timer = 18000;
                        break;
                    case 3:
                        Talk(SAY_WATER);
                        DoCast(me, SPELL_CONJURE_WATER);
                        EventProgress_Timer = 7000;
                        break;
                    case 4:
                        Talk(SAY_BUFFS);
                        DoCast(me, SPELL_ICE_ARMOR);
                        EventProgress_Timer = 7000;
                        break;
                    case 5:
                        Talk(SAY_DRINK);
                        DoCast(me, SPELL_ARCANE_INTELLECT);
                        EventProgress_Timer = 7000;
                        break;
                    case 6:
                        Talk(SAY_READY);
                        EventProgress_Timer = 6000;
                        break;
                    case 7:
                        instance->SetData(DATA_WARDEN_2, DONE);
                        Init = true;
                        me->SetImmuneToNPC(false);
                        break;
                    }
                    ++Phase;
                }
            }
            else
                EventProgress_Timer -= diff;
        }

        if (!UpdateVictim())
            return;
        if (!LowHp && HealthBelowPct(20))
        {
            Talk(SAY_LOWHP);
            LowHp = true;
        }

        if (Pyroblast_Timer <= diff)
        {
            if (me->IsNonMeleeSpellCast(false))
                return;

            Talk(SAY_PYRO);

            DoCastVictim(SPELL_PYROBLAST);
            Pyroblast_Timer = 40000;
        }
        else
            Pyroblast_Timer -=diff;

        if (Fireball_Timer <= diff)
        {
            DoCastVictim(SPELL_FIREBALL);
            Fireball_Timer = 4000;
        }
        else
            Fireball_Timer -=diff;

        DoMeleeAttackIfReady();
    }
};
/*#####
# npc_warden_mellichar
#####*/

enum WardenSays
{
    YELL_INTRO1         = 0,
    YELL_INTRO2         = 1,
    YELL_RELEASE1       = 2,
    YELL_RELEASE2A      = 3,
    YELL_RELEASE2B      = 4,
    YELL_RELEASE3       = 5,
    YELL_RELEASE4       = 6,
    YELL_WELCOME        = 7,
};

enum WardenUnits
{
    //phase 2(acid mobs)
    ENTRY_TRICKSTER    = 20905,
    ENTRY_PH_HUNTER    = 20906,
    //phase 3
    ENTRY_MILLHOUSE    = 20977,
    //phase 4(acid mobs)
    ENTRY_AKKIRIS      = 20908,
    ENTRY_SULFURON     = 20909,
    //phase 5(acid mobs)
    ENTRY_TW_DRAK      = 20910,
    ENTRY_BL_DRAK      = 20911,
    //phase 6
    ENTRY_SKYRISS      = 20912,
};

enum WardenSpells
{
    //TARGET_SCRIPT
    SPELL_TARGET_ALPHA  = 36856,
    SPELL_TARGET_BETA   = 36854,
    SPELL_TARGET_DELTA  = 36857,
    SPELL_TARGET_GAMMA  = 36858,
    SPELL_TARGET_OMEGA  = 36852,
    SPELL_BUBBLE_VISUAL = 36849,
};

struct npc_warden_mellichar : public ScriptedAI
{
    npc_warden_mellichar(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
        instance = creature->GetInstanceScript();
    }

    void Initialize()
    {
        IsRunning = false;
        CanSpawn = false;

        EventProgress_Timer = 22000;
        Phase = 1;
    }

    InstanceScript* instance;

    bool IsRunning;
    bool CanSpawn;

    uint32 EventProgress_Timer;
    uint32 Phase;

    void Reset() override
    {
        Initialize();

        me->SetUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
        DoCast(me, SPELL_TARGET_OMEGA);

        instance->SetBossState(DATA_HARBINGER_SKYRISS, NOT_STARTED);
    }

    void AttackStart(Unit* /*who*/) override { }

    void MoveInLineOfSight(Unit* who) override
    {
        if (IsRunning)
            return;

        if (!me->GetVictim() && me->CanCreatureAttack(who))
        {
            if (!me->CanFly() && me->GetDistanceZ(who) > CREATURE_Z_ATTACK_RANGE)
                return;
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            float attackRadius = me->GetAttackDistance(who)/10;
            if (me->IsWithinDistInMap(who, attackRadius) && me->IsWithinLOSInMap(who))
                JustEngagedWith(who);
        }
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        Talk(YELL_INTRO1);
        DoCast(me, SPELL_BUBBLE_VISUAL);

        instance->SetBossState(DATA_HARBINGER_SKYRISS, IN_PROGRESS);
        instance->HandleGameObject(instance->GetGuidData(DATA_WARDENS_SHIELD), false);
        IsRunning = true;
    }

    void JustSummoned(Creature* summon) override
    {
        DoZoneInCombat(summon);
        if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f, true))
            summon->AI()->AttackStart(target);
    }

    bool CanProgress()
    {
        if (Phase == 7 && instance->GetData(DATA_WARDEN_4) == DONE)
            return true;
        if (Phase == 6 && instance->GetData(DATA_WARDEN_3) == DONE)
            return true;
        if (Phase == 5 && instance->GetData(DATA_WARDEN_2) == DONE)
            return true;
        if (Phase == 4)
            return true;
        if (Phase == 3 && instance->GetData(DATA_WARDEN_1) == DONE)
            return true;
        if (Phase == 2 && instance->GetBossState(DATA_HARBINGER_SKYRISS) == IN_PROGRESS)
            return true;
        if (Phase == 1 && instance->GetBossState(DATA_HARBINGER_SKYRISS) == IN_PROGRESS)
            return true;

        return false;
    }

    void DoPrepareForPhase()
    {
        me->InterruptNonMeleeSpells(true);
        me->RemoveAurasByType(SPELL_AURA_DUMMY);

        switch (Phase)
        {
            case 2:
                DoCast(me, SPELL_TARGET_ALPHA);
                instance->SetData(DATA_WARDEN_1, IN_PROGRESS);
                instance->HandleGameObject(instance->GetGuidData(DATA_WARDENS_SHIELD), false);
                break;
            case 3:
                DoCast(me, SPELL_TARGET_BETA);
                instance->SetData(DATA_WARDEN_2, IN_PROGRESS);
                break;
            case 5:
                DoCast(me, SPELL_TARGET_DELTA);
                instance->SetData(DATA_WARDEN_3, IN_PROGRESS);
                break;
            case 6:
                DoCast(me, SPELL_TARGET_GAMMA);
                instance->SetData(DATA_WARDEN_4, IN_PROGRESS);
                break;
            case 7:
                instance->SetData(DATA_WARDEN_5, IN_PROGRESS);
                break;
        }
        CanSpawn = true;
    }

    void UpdateAI(uint32 diff) override
    {
        if (!IsRunning)
            return;

        if (EventProgress_Timer <= diff)
        {
            if (instance->GetBossState(DATA_HARBINGER_SKYRISS) == FAIL)
            {
                Reset();
                return;
            }

            if (CanSpawn)
            {
                //continue beam omega pod, unless we are about to summon skyriss
                if (Phase != 7)
                    DoCast(me, SPELL_TARGET_OMEGA);

                switch (Phase)
                {
                case 2:
                    switch (urand(0, 1))
                    {
                    case 0:
                        me->SummonCreature(ENTRY_TRICKSTER, 472.231f, -150.86f, 42.6573f, 3.10669f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 10min); // random pos
                        break;
                    case 1:
                        me->SummonCreature(ENTRY_PH_HUNTER, 472.231f, -150.86f, 42.6573f, 3.10669f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 10min); // random pos
                        break;
                    }
                    break;
                case 3:
                    me->SummonCreature(ENTRY_MILLHOUSE, 417.242f, -149.795f, 42.6548f, 0.191986f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 10min); // static pos
                    break;
                case 4:
                    Talk(YELL_RELEASE2B);
                    break;
                case 5:
                    switch (urand(0, 1))
                    {
                    case 0:
                        me->SummonCreature(ENTRY_AKKIRIS, 420.851f, -174.337f, 42.6655f, 0.122173f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 10min); // random pos
                        break;
                    case 1:
                        me->SummonCreature(ENTRY_SULFURON, 420.851f, -174.337f, 42.6655f, 0.122173f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 10min); // random pos
                        break;
                    }
                    break;
                case 6:
                    switch (urand(0, 1))
                    {
                    case 0:
                        me->SummonCreature(ENTRY_TW_DRAK, 470.364f, -174.656f, 42.6753f, 3.59538f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 10min); // random pos
                        break;
                    case 1:
                        me->SummonCreature(ENTRY_BL_DRAK, 470.364f, -174.656f, 42.6753f, 3.59538f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 10min); // random pos
                        break;
                    }
                    break;
                case 7:
                    me->SummonCreature(ENTRY_SKYRISS, 446.086f, -182.506f, 44.0852f, 1.5708f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 10min); // static pos
                    Talk(YELL_WELCOME);
                    break;
                }
                CanSpawn = false;
                ++Phase;
            }
            if (CanProgress())
            {
                switch (Phase)
                {
                case 1:
                    Talk(YELL_INTRO2);
                    EventProgress_Timer = 10000;
                    ++Phase;
                    break;
                case 2:
                    Talk(YELL_RELEASE1);
                    DoPrepareForPhase();
                    EventProgress_Timer = 7000;
                    break;
                case 3:
                    Talk(YELL_RELEASE2A);
                    DoPrepareForPhase();
                    EventProgress_Timer = 10000;
                    break;
                case 4:
                    DoPrepareForPhase();
                    EventProgress_Timer = 15000;
                    break;
                case 5:
                    Talk(YELL_RELEASE3);
                    DoPrepareForPhase();
                    EventProgress_Timer = 15000;
                    break;
                case 6:
                    Talk(YELL_RELEASE4);
                    DoPrepareForPhase();
                    EventProgress_Timer = 15000;
                    break;
                case 7:
                    DoPrepareForPhase();
                    EventProgress_Timer = 15000;
                    break;
                }
            }
        }
        else
            EventProgress_Timer -= diff;
    }
};

void AddSC_arcatraz()
{
    RegisterArcatrazCreatureAI(npc_millhouse_manastorm);
    RegisterArcatrazCreatureAI(npc_warden_mellichar);
}
