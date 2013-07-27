/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
SDName: Argent Challenge Encounter.
SD%Complete: 50 %
SDComment: AI for Argent Soldiers are not implemented. AI from bosses need more improvements.
SDCategory: Trial of the Champion
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "trial_of_the_champion.h"
#include "ScriptedEscortAI.h"
/*
enum Yells
{
    // Eadric the Pure
    SAY_INTRO                   = 0,
    SAY_AGGRO                   = 1,
    EMOTE_RADIANCE              = 2,
    EMOTE_HAMMER_RIGHTEOUS      = 3,
    SAY_HAMMER_RIGHTEOUS        = 4,
    SAY_KILL_PLAYER             = 5,
    SAY_DEFEATED                = 6,

    // Argent Confessor Paletress
    SAY_INTRO_1                 = 0,
    SAY_INTRO_2                 = 1,
    SAY_AGGRO                   = 2,
    SAY_MEMORY_SUMMON           = 3,
    SAY_MEMORY_DEATH            = 4,
    SAY_KILL_PLAYER             = 5,
    SAY_DEFEATED                = 6,

    // Memory of X
    EMOTE_WAKING_NIGHTMARE      = 0
};
*/
enum Spells
{
    // Eadric the Pure
    SPELL_EADRIC_ACHIEVEMENT    = 68197,
    SPELL_HAMMER_JUSTICE        = 66863,
    SPELL_HAMMER_RIGHTEOUS      = 66867,
    SPELL_RADIANCE              = 66935,
    SPELL_VENGEANCE             = 66865,

    //Paletress
    SPELL_SMITE                 = 66536,
    SPELL_SMITE_H               = 67674,
    SPELL_HOLY_FIRE             = 66538,
    SPELL_HOLY_FIRE_H           = 67676,
    SPELL_RENEW                 = 66537,
    SPELL_RENEW_H               = 67675,
    SPELL_HOLY_NOVA             = 66546,
    SPELL_SHIELD                = 66515,
    SPELL_CONFESS               = 66680,
    SPELL_SUMMON_MEMORY         = 66545,

    //Memory
    SPELL_OLD_WOUNDS            = 66620,
    SPELL_OLD_WOUNDS_H          = 67679,
    SPELL_SHADOWS_PAST          = 66619,
    SPELL_SHADOWS_PAST_H        = 67678,
    SPELL_WAKING_NIGHTMARE      = 66552,
    SPELL_WAKING_NIGHTMARE_H    = 67677
};

class OrientationCheck : public std::unary_function<Unit*, bool>
{
    public:
        explicit OrientationCheck(Unit* _caster) : caster(_caster) { }
        bool operator()(WorldObject* object)
        {
            return !object->isInFront(caster, 2.5f) || !object->IsWithinDist(caster, 40.0f);
        }

    private:
        Unit* caster;
};

class spell_eadric_radiance : public SpellScriptLoader
{
    public:
        spell_eadric_radiance() : SpellScriptLoader("spell_eadric_radiance") { }
        class spell_eadric_radiance_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_eadric_radiance_SpellScript);

            void FilterTargets(std::list<WorldObject*>& unitList)
            {
                unitList.remove_if(OrientationCheck(GetCaster()));
            }

            void Register() OVERRIDE
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_eadric_radiance_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_eadric_radiance_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_eadric_radiance_SpellScript();
        }
};

class boss_eadric : public CreatureScript
{
public:
    boss_eadric() : CreatureScript("boss_eadric") { }
    struct boss_eadricAI : public ScriptedAI
    {
        boss_eadricAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
            creature->SetReactState(REACT_PASSIVE);
            creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        }

        InstanceScript* instance;

        uint32 uiVenganceTimer;
        uint32 uiRadianceTimer;
        uint32 uiHammerJusticeTimer;
        uint32 uiResetTimer;

        bool bDone;

        void Reset() OVERRIDE
        {
            uiVenganceTimer = 10000;
            uiRadianceTimer = 16000;
            uiHammerJusticeTimer = 25000;
            uiResetTimer = 5000;

            bDone = false;
        }

        void DamageTaken(Unit* /*done_by*/, uint32 &damage) OVERRIDE
        {
            if (damage >= me->GetHealth())
            {
                damage = 0;
                EnterEvadeMode();
                me->setFaction(35);
                bDone = true;
            }
        }

        void MovementInform(uint32 MovementType, uint32 /*Data*/) OVERRIDE
        {
            if (MovementType != POINT_MOTION_TYPE)
                return;

            if (instance)
                instance->SetData(BOSS_ARGENT_CHALLENGE_E, DONE);

            me->DisappearAndDie();
        }

        void UpdateAI(uint32 uiDiff) OVERRIDE
        {
            if (bDone && uiResetTimer <= uiDiff)
            {
                me->GetMotionMaster()->MovePoint(0, 746.87f, 665.87f, 411.75f);
                bDone = false;
            } else uiResetTimer -= uiDiff;

            if (!UpdateVictim())
                return;

            if (uiHammerJusticeTimer <= uiDiff)
            {
                me->InterruptNonMeleeSpells(true);

                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 250, true))
                {
                    if (target && target->IsAlive())
                    {
                        DoCast(target, SPELL_HAMMER_JUSTICE);
                        DoCast(target, SPELL_HAMMER_RIGHTEOUS);
                    }
                }
                uiHammerJusticeTimer = 25000;
            } else uiHammerJusticeTimer -= uiDiff;

            if (uiVenganceTimer <= uiDiff)
            {
                DoCast(me, SPELL_VENGEANCE);

                uiVenganceTimer = 10000;
            } else uiVenganceTimer -= uiDiff;

            if (uiRadianceTimer <= uiDiff)
            {
                DoCastAOE(SPELL_RADIANCE);

                uiRadianceTimer = 16000;
            } else uiRadianceTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new boss_eadricAI(creature);
    }
};

class boss_paletress : public CreatureScript
{
public:
    boss_paletress() : CreatureScript("boss_paletress") { }

    struct boss_paletressAI : public ScriptedAI
    {
        boss_paletressAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();

            MemoryGUID = 0;
            creature->SetReactState(REACT_PASSIVE);
            creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            creature->RestoreFaction();
        }

        InstanceScript* instance;
        uint64 MemoryGUID;

        bool bHealth;
        bool bDone;

        uint32 uiHolyFireTimer;
        uint32 uiHolySmiteTimer;
        uint32 uiRenewTimer;
        uint32 uiResetTimer;

        void Reset() OVERRIDE
        {
            me->RemoveAllAuras();

            uiHolyFireTimer     = urand(9000, 12000);
            uiHolySmiteTimer    = urand(5000, 7000);
            uiRenewTimer        = urand(2000, 5000);

            uiResetTimer        = 7000;

            bHealth = false;
            bDone = false;

            if (Creature* pMemory = Unit::GetCreature(*me, MemoryGUID))
                if (pMemory->IsAlive())
                    pMemory->RemoveFromWorld();
        }

        void SetData(uint32 uiId, uint32 /*uiValue*/) OVERRIDE
        {
            if (uiId == 1)
                me->RemoveAura(SPELL_SHIELD);
        }

        void DamageTaken(Unit* /*done_by*/, uint32 &damage) OVERRIDE
        {
            if (damage >= me->GetHealth())
            {
                damage = 0;
                EnterEvadeMode();
                me->setFaction(35);
                bDone = true;
            }
        }

        void MovementInform(uint32 MovementType, uint32 Point) OVERRIDE
        {
            if (MovementType != POINT_MOTION_TYPE || Point != 0)
                return;

            if (instance)
                instance->SetData(BOSS_ARGENT_CHALLENGE_P, DONE);

            me->DisappearAndDie();
        }

        void UpdateAI(uint32 uiDiff) OVERRIDE
        {
            if (bDone && uiResetTimer <= uiDiff)
            {
                me->GetMotionMaster()->MovePoint(0, 746.87f, 665.87f, 411.75f);
                bDone = false;
            } else uiResetTimer -= uiDiff;

            if (!UpdateVictim())
                return;

            if (uiHolyFireTimer <= uiDiff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 250, true))
                {
                    if (target && target->IsAlive())
                        DoCast(target, SPELL_HOLY_FIRE);
                }
                 if (me->HasAura(SPELL_SHIELD))
                    uiHolyFireTimer = 13000;
                else
                    uiHolyFireTimer = urand(9000, 12000);
            } else uiHolyFireTimer -= uiDiff;

            if (uiHolySmiteTimer <= uiDiff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 250, true))
                {
                    if (target && target->IsAlive())
                        DoCast(target, SPELL_SMITE);
                }
                if (me->HasAura(SPELL_SHIELD))
                    uiHolySmiteTimer = 9000;
                else
                    uiHolySmiteTimer = urand(5000, 7000);
            } else uiHolySmiteTimer -= uiDiff;

            if (me->HasAura(SPELL_SHIELD))
            {
                if (uiRenewTimer <= uiDiff)
                {
                    me->InterruptNonMeleeSpells(true);
                    uint8 uiTarget = urand(0, 1);
                    switch (uiTarget)
                    {
                        case 0:
                            DoCast(me, SPELL_RENEW);
                            break;
                        case 1:
                            if (Creature* pMemory = Unit::GetCreature(*me, MemoryGUID))
                                if (pMemory->IsAlive())
                                    DoCast(pMemory, SPELL_RENEW);
                            break;
                    }
                    uiRenewTimer = urand(15000, 17000);
                } else uiRenewTimer -= uiDiff;
            }

            if (!bHealth && !HealthAbovePct(25))
            {
                me->InterruptNonMeleeSpells(true);
                DoCastAOE(SPELL_HOLY_NOVA, false);
                DoCast(me, SPELL_SHIELD);
                DoCastAOE(SPELL_SUMMON_MEMORY, false);
                DoCastAOE(SPELL_CONFESS, false);

                bHealth = true;
            }

            DoMeleeAttackIfReady();
        }

        void JustSummoned(Creature* summon) OVERRIDE
        {
            MemoryGUID = summon->GetGUID();
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new boss_paletressAI(creature);
    }
};

class npc_memory : public CreatureScript
{
public:
    npc_memory() : CreatureScript("npc_memory") { }

    struct npc_memoryAI : public ScriptedAI
    {
        npc_memoryAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 uiOldWoundsTimer;
        uint32 uiShadowPastTimer;
        uint32 uiWakingNightmare;

        void Reset() OVERRIDE
        {
            uiOldWoundsTimer = 12000;
            uiShadowPastTimer = 5000;
            uiWakingNightmare = 7000;
        }

        void UpdateAI(uint32 uiDiff) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            if (uiOldWoundsTimer <= uiDiff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                {
                    if (target && target->IsAlive())
                        DoCast(target, SPELL_OLD_WOUNDS);
                }
                uiOldWoundsTimer = 12000;
            }else uiOldWoundsTimer -= uiDiff;

            if (uiWakingNightmare <= uiDiff)
            {
                DoCast(me, SPELL_WAKING_NIGHTMARE);
                uiWakingNightmare = 7000;
            }else uiWakingNightmare -= uiDiff;

            if (uiShadowPastTimer <= uiDiff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1))
                {
                    if (target && target->IsAlive())
                        DoCast(target, SPELL_SHADOWS_PAST);
                }
                uiShadowPastTimer = 5000;
            }else uiShadowPastTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            if (TempSummon* summ = me->ToTempSummon())
                if (Unit* summoner = summ->GetSummoner())
                    if (summoner->IsAlive())
                        summoner->GetAI()->SetData(1, 0);
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_memoryAI(creature);
    }
};

class npc_argent_soldier : public CreatureScript
{
public:
    npc_argent_soldier() : CreatureScript("npc_argent_soldier") { }

    // THIS AI NEEDS MORE IMPROVEMENTS
    struct npc_argent_soldierAI : public npc_escortAI
    {
        npc_argent_soldierAI(Creature* creature) : npc_escortAI(creature)
        {
            instance = creature->GetInstanceScript();
            me->SetReactState(REACT_DEFENSIVE);
            SetDespawnAtEnd(false);
            uiWaypoint = 0;
        }

        InstanceScript* instance;

        uint8 uiWaypoint;

        void WaypointReached(uint32 waypointId) OVERRIDE
        {
            if (waypointId == 0)
            {
                switch (uiWaypoint)
                {
                    case 0:
                        me->SetFacingTo(5.81f);
                        break;
                    case 1:
                        me->SetFacingTo(4.60f);
                        break;
                    case 2:
                        me->SetFacingTo(2.79f);
                        break;
                }
            }
        }

        void SetData(uint32 uiType, uint32 /*uiData*/) OVERRIDE
        {
            switch (me->GetEntry())
            {
                case NPC_ARGENT_LIGHWIELDER:
                    switch (uiType)
                    {
                        case 0:
                            AddWaypoint(0, 712.14f, 628.42f, 411.88f);
                            break;
                        case 1:
                            AddWaypoint(0, 742.44f, 650.29f, 411.79f);
                            break;
                        case 2:
                            AddWaypoint(0, 783.33f, 615.29f, 411.84f);
                            break;
                    }
                    break;
                case NPC_ARGENT_MONK:
                    switch (uiType)
                    {
                        case 0:
                            AddWaypoint(0, 713.12f, 632.97f, 411.90f);
                            break;
                        case 1:
                            AddWaypoint(0, 746.73f, 650.24f, 411.56f);
                            break;
                        case 2:
                            AddWaypoint(0, 781.32f, 610.54f, 411.82f);
                            break;
                    }
                    break;
                case NPC_PRIESTESS:
                    switch (uiType)
                    {
                        case 0:
                            AddWaypoint(0, 715.06f, 637.07f, 411.91f);
                            break;
                        case 1:
                            AddWaypoint(0, 750.72f, 650.20f, 411.77f);
                            break;
                        case 2:
                            AddWaypoint(0, 779.77f, 607.03f, 411.81f);
                            break;
                    }
                    break;
            }

            Start(false, true, 0);
            uiWaypoint = uiType;
        }

        void UpdateAI(uint32 uiDiff) OVERRIDE
        {
            npc_escortAI::UpdateAI(uiDiff);

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            if (instance)
                instance->SetData(DATA_ARGENT_SOLDIER_DEFEATED, instance->GetData(DATA_ARGENT_SOLDIER_DEFEATED) + 1);
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_argent_soldierAI(creature);
    }
};

void AddSC_boss_argent_challenge()
{
    new boss_eadric();
    new spell_eadric_radiance();
    new boss_paletress();
    new npc_memory();
    new npc_argent_soldier();
}
