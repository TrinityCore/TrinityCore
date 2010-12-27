/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "ulduar.h"
#include "SpellAuraEffects.h"

enum Yells
{
    SAY_AGGRO                                   = -1603220,
    SAY_SLAY_1                                  = -1603221,
    SAY_SLAY_2                                  = -1603222,
    SAY_DEATH                                   = -1603223,
    SAY_SUMMON                                  = -1603224,
    SAY_SLAG_POT                                = -1603225,
    SAY_SCORCH_1                                = -1603226,
    SAY_SCORCH_2                                = -1603227,
    SAY_BERSERK                                 = -1603228,
    EMOTE_JETS                                  = -1603229,
};

enum Spells
{
    SPELL_FLAME_JETS                         = 62680,
    SPELL_SCORCH                             = 62546,
    SPELL_SLAG_POT                           = 62717,
    SPELL_SLAG_POT_DAMAGE                    = 65722,
    SPELL_SLAG_IMBUED                        = 62836,
    SPELL_ACTIVATE_CONSTRUCT                 = 62488,
    SPELL_STRENGHT                           = 64473,
    SPELL_GRAB                               = 62707,
    SPELL_BERSERK                            = 47008
};

enum Events
{
    EVENT_NONE,
    EVENT_JET,
    EVENT_SCORCH,
    EVENT_SLAG_POT,
    EVENT_GRAB_POT,
    EVENT_CHANGE_POT,
    EVENT_END_POT,
    EVENT_CONSTRUCT,
    EVENT_BERSERK,
    ACTION_REMOVE_BUFF = 20
};

enum eCreatures
{
    NPC_IRON_CONSTRUCT                          = 33121,
    NPC_GROUND_SCORCH                           = 33221
};

enum ConstructSpells
{
    SPELL_HEAT                                  = 65667,
    SPELL_MOLTEN                                = 62373,
    SPELL_BRITTLE                               = 62382,
    SPELL_SHATTER                               = 62383,
    SPELL_GROUND                                = 62548,
};

enum eAchievementData
{
    ACHIEVEMENT_STOKIN_THE_FURNACE_10           = 2930,
    ACHIEVEMENT_STOKIN_THE_FURNACE_25           = 2929,
    ACHIEVEMENT_SHATTERED_10                    = 2925,
    ACHIEVEMENT_SHATTERED_25                    = 2926,
};

#define MAX_ENCOUNTER_TIME                    4 * 60 * 1000

const Position Pos[20] =
{
    {630.366f,216.772f,360.891f,3.001970f},
    {630.594f,231.846f,360.891f,3.124140f},
    {630.435f,337.246f,360.886f,3.211410f},
    {630.493f,313.349f,360.886f,3.054330f},
    {630.444f,321.406f,360.886f,3.124140f},
    {630.366f,247.307f,360.888f,3.211410f},
    {630.698f,305.311f,360.886f,3.001970f},
    {630.500f,224.559f,360.891f,3.054330f},
    {630.668f,239.840f,360.890f,3.159050f},
    {630.384f,329.585f,360.886f,3.159050f},
    {543.220f,313.451f,360.886f,0.104720f},
    {543.356f,329.408f,360.886f,6.248280f},
    {543.076f,247.458f,360.888f,6.213370f},
    {543.117f,232.082f,360.891f,0.069813f},
    {543.161f,305.956f,360.886f,0.157080f},
    {543.277f,321.482f,360.886f,0.052360f},
    {543.316f,337.468f,360.886f,6.195920f},
    {543.280f,239.674f,360.890f,6.265730f},
    {543.265f,217.147f,360.891f,0.174533f},
    {543.256f,224.831f,360.891f,0.122173f}
};

class boss_ignis : public CreatureScript
{
public:
    boss_ignis() : CreatureScript("boss_ignis") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_ignis_AI (pCreature);
    }

    struct boss_ignis_AI : public BossAI
    {
        boss_ignis_AI(Creature *pCreature) : BossAI(pCreature, TYPE_IGNIS), vehicle(me->GetVehicleKit())
        {
            assert(vehicle);
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_ID, 49560, true); // Death Grip jump effect
        }

        Vehicle *vehicle;

        std::vector<Creature*> triggers;

        bool Shattered;
        uint64 SlagPotGUID;
        uint32 EncounterTime;
        uint32 ConstructTimer;

        void Reset()
        {
            _Reset();
            if (vehicle)
                vehicle->RemoveAllPassengers();
        }

        void EnterCombat(Unit* /*who*/)
        {
            _EnterCombat();
            DoScriptText(SAY_AGGRO, me);
            events.ScheduleEvent(EVENT_JET, 30000);
            events.ScheduleEvent(EVENT_SCORCH, 25000);
            events.ScheduleEvent(EVENT_SLAG_POT, 35000);
            events.ScheduleEvent(EVENT_CONSTRUCT, 15000);
            events.ScheduleEvent(EVENT_END_POT, 40000);
            events.ScheduleEvent(EVENT_BERSERK, 480000);
            SlagPotGUID = 0;
            EncounterTime = 0;
            ConstructTimer = 0;
            Shattered = false;
        }

        void JustDied(Unit* /*victim*/)
        {
            _JustDied();
            DoScriptText(SAY_DEATH, me);

            // Achievements
            if (instance)
            {
                // Shattered
                if (Shattered)
                    instance->DoCompleteAchievement(RAID_MODE(ACHIEVEMENT_SHATTERED_10,ACHIEVEMENT_SHATTERED_25));
                // Stokin' the Furnace
                if (EncounterTime <= MAX_ENCOUNTER_TIME)
                    instance->DoCompleteAchievement(RAID_MODE(ACHIEVEMENT_STOKIN_THE_FURNACE_10,ACHIEVEMENT_STOKIN_THE_FURNACE_25));
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            EncounterTime += diff;
            ConstructTimer += diff;

            while(uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_JET:
                        me->MonsterTextEmote(EMOTE_JETS, 0, true);
                        DoCastAOE(SPELL_FLAME_JETS);
                        events.RescheduleEvent(EVENT_JET,urand(35000,40000));
                        break;
                    case EVENT_SLAG_POT:
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        {
                            DoScriptText(SAY_SLAG_POT, me);
                            SlagPotGUID = pTarget->GetGUID();
                            DoCast(pTarget, SPELL_GRAB);
                            events.DelayEvents(3000);
                            events.ScheduleEvent(EVENT_GRAB_POT, 500);
                        }
                        events.RescheduleEvent(EVENT_SLAG_POT,RAID_MODE(30000, 15000));
                        break;
                    case EVENT_GRAB_POT:
                        if (Unit* SlagPotTarget = Unit::GetUnit(*me, SlagPotGUID))
                        {
                            SlagPotTarget->EnterVehicle(me, 0);
                            events.CancelEvent(EVENT_GRAB_POT);
                            events.ScheduleEvent(EVENT_CHANGE_POT, 1000);
                        }
                        break;
                    case EVENT_CHANGE_POT:
                        if (Unit* SlagPotTarget = Unit::GetUnit(*me, SlagPotGUID))
                        {
                            SlagPotTarget->AddAura(SPELL_SLAG_POT, SlagPotTarget);
                            SlagPotTarget->EnterVehicle(me, 1);
                            events.CancelEvent(EVENT_CHANGE_POT);
                            events.ScheduleEvent(EVENT_END_POT, 10000);
                        }
                        break;
                    case EVENT_END_POT:
                        if (Unit* SlagPotTarget = Unit::GetUnit(*me, SlagPotGUID))
                        {
                            SlagPotTarget->ExitVehicle();
                            SlagPotTarget = NULL;
                            SlagPotGUID = NULL;
                            events.CancelEvent(EVENT_END_POT);
                        }
                        break;
                    case EVENT_SCORCH:
                        DoScriptText(RAND(SAY_SCORCH_1, SAY_SCORCH_2), me);
                        if (Unit *pTarget = me->getVictim())
                            me->SummonCreature(NPC_GROUND_SCORCH, pTarget->GetPositionX(), pTarget->GetPositionY(), pTarget->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 45000);
                        DoCast(SPELL_SCORCH);
                        events.RescheduleEvent(EVENT_SCORCH,25000);
                        break;
                    case EVENT_CONSTRUCT:
                        DoScriptText(SAY_SUMMON, me);
                        DoSummon(NPC_IRON_CONSTRUCT, Pos[rand()%20], 30000, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT);
                        DoCast(SPELL_STRENGHT);
                        DoCast(me, SPELL_ACTIVATE_CONSTRUCT);
                        events.RescheduleEvent(EVENT_CONSTRUCT,RAID_MODE(40000, 30000));
                        break;
                    case EVENT_BERSERK:
                        DoCast(me, SPELL_BERSERK, true);
                        DoScriptText(SAY_BERSERK, me);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }

        void KilledUnit(Unit* /*victim*/)
        {
            if (!(rand()%5))
                DoScriptText(RAND(SAY_SLAY_1, SAY_SLAY_2), me);
        }

        void JustSummoned(Creature *summon)
        {
            if (summon->GetEntry() == NPC_IRON_CONSTRUCT)
            {
                summon->setFaction(16);
                summon->SetReactState(REACT_AGGRESSIVE);
                summon->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED | UNIT_FLAG_STUNNED | UNIT_FLAG_DISABLE_MOVE);
            }
            summon->AI()->AttackStart(me->getVictim());
            summon->AI()->DoZoneInCombat();
            summons.Summon(summon);
        }

        void DoAction(const int32 action)
        {
            switch(action)
            {
                case ACTION_REMOVE_BUFF:
                    me->RemoveAuraFromStack(SPELL_STRENGHT);
                    // Shattered Achievement
                    if (ConstructTimer >= 5000)
                        ConstructTimer = 0;
                    else
                        Shattered = true;
                    break;
            }
        }
    };
};

class npc_iron_construct : public CreatureScript
{
public:
    npc_iron_construct() : CreatureScript("npc_iron_construct") { }

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_iron_constructAI(creature);
    }

    struct npc_iron_constructAI : public ScriptedAI
    {
        npc_iron_constructAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            instance = pCreature->GetInstanceScript();
            pCreature->SetReactState(REACT_PASSIVE);
        }

        InstanceScript* instance;
        bool Brittled;

        void Reset()
        {
            Brittled = false;
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage)
        {
            if (me->HasAura(SPELL_BRITTLE) && damage >= 5000)
            {
                DoCast(SPELL_SHATTER);
                if (Creature *pIgnis = me->GetCreature(*me, instance->GetData64(TYPE_IGNIS)))
                    if (pIgnis->AI())
                        pIgnis->AI()->DoAction(ACTION_REMOVE_BUFF);

                me->ForcedDespawn(1000);
            }
        }

        void UpdateAI(const uint32 /*uiDiff*/)
        {
            if (!UpdateVictim())
                return;

            if (Aura * aur = me->GetAura(SPELL_HEAT))
            {
                if (aur->GetStackAmount() >= 10)
                {
                    me->RemoveAura(SPELL_HEAT);
                    DoCast(SPELL_MOLTEN);
                    Brittled = false;
                }
            }
            // Water pools
            if (me->IsInWater() && !Brittled && me->HasAura(SPELL_MOLTEN))
            {
                DoCast(SPELL_BRITTLE);
                me->RemoveAura(SPELL_MOLTEN);
                Brittled = true;
            }
            DoMeleeAttackIfReady();
        }
    };
};
class npc_scorch_ground : public CreatureScript
{
public:
    npc_scorch_ground() : CreatureScript("npc_scorch_ground") { }

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_scorch_groundAI(creature);
    }

    struct npc_scorch_groundAI : public ScriptedAI
    {
        npc_scorch_groundAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE |UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED);
            pCreature->SetDisplayId(16925); //model 2 in db cannot overwrite wdb fields
        }

        uint64 ConstructGUID;
        uint32 HeatTimer;
        bool Heat;

        void MoveInLineOfSight(Unit* pWho)
        {
            if (!Heat)
            {
                if (pWho->GetEntry() == NPC_IRON_CONSTRUCT)
                {
                    if (!pWho->HasAura(SPELL_HEAT) || !pWho->HasAura(SPELL_MOLTEN))
                    {
                        ConstructGUID = pWho->GetGUID();
                        Heat=true;
                    }
                }
            }
        }

        void Reset()
        {
            Heat=false;
            DoCast(me, SPELL_GROUND);
            ConstructGUID=0;
            HeatTimer=0;
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (Heat)
            {
                if(HeatTimer <= uiDiff)
                {
                    Creature* Construct = me->GetCreature(*me ,ConstructGUID);
                    if (Construct && !Construct->HasAura(SPELL_MOLTEN))
                    {
                        me->AddAura(SPELL_HEAT,Construct);
                        HeatTimer=1000;
                    }
                }
                else
                    HeatTimer -= uiDiff;
            }
        }
    };
};

class spell_ignis_slag_pot : public SpellScriptLoader
{
    public:
        spell_ignis_slag_pot() : SpellScriptLoader("spell_ignis_slag_pot") { }

        class spell_ignis_slag_pot_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_ignis_slag_pot_AuraScript)
            bool Validate(SpellEntry const * /*spellEntry*/)
            {
                if (!sSpellStore.LookupEntry(SPELL_SLAG_POT_DAMAGE))
                    return false;
                if (!sSpellStore.LookupEntry(SPELL_SLAG_POT))
                    return false;
                if (!sSpellStore.LookupEntry(SPELL_SLAG_IMBUED))
                    return false;
                return true;
            }

            void HandleEffectPeriodic(AuraEffect const * aurEff)
            {
                Unit* aurEffCaster = aurEff->GetCaster();
                if (!aurEffCaster)
                    return;

                Unit * target = GetTarget();
                aurEffCaster->CastSpell(target, SPELL_SLAG_POT_DAMAGE, true);
                if (target->isAlive() && !GetDuration())
                     target->CastSpell(target, SPELL_SLAG_IMBUED, true);
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_ignis_slag_pot_AuraScript::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_ignis_slag_pot_AuraScript();
        }
};


void AddSC_boss_ignis()
{
    new boss_ignis();
    new npc_iron_construct();
    new npc_scorch_ground();
    new spell_ignis_slag_pot();
}
