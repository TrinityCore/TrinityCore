/*
* Copyright (C) 2021 BfaCore Reforged
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

#include "lost_city_of_the_tolvir.h"
#include "ScriptMgr.h"

enum eSpells
{
    // Lockmaw
    SPELL_DUST_FLAIL                    = 81642,
    SPELL_DUST_FLAIL_AURA               = 81646,
    SPELL_VISCOUS_POISON                = 81630,
    SPELL_SCENT_OF_BLOOD_NORMAL         = 81690,
    SPELL_SCENT_OF_BLOOD_HEROIC         = 89998,
    SPELL_VENOMOUS_RAGE                 = 81706,
    // Augh
    SPELL_SMOKE_BOMB                    = 84768,
    SPELL_STEALTHED                     = 84244,
    SPELL_PARALYTIC_BLOW_DART           = 84799,
    SPELL_WHITLWIND                     = 84784,
    // Vicious Croc
    SPELL_VICIOUS_BITE                  = 81677,
    // Add Stalker
    SPELL_SUMMON_CROCOLISK              = 84242,
    SPELL_SUMMON_AUGH_DRAGONS_BREATH    = 84805,
    SPELL_SUMMON_AUGH_WHITLWIND         = 84808,
    SPELL_SUMMON_AUGH_BLOW_DART         = 84809,
};

enum eCreatures
{
    NPC_FRENZIED_CROCOLISK              = 43658,
    NPC_DUST_FLAIL                      = 43655,
};

enum eTexts
{
    AUGH_SAY_INTRO_1                    = 0,
    AUGH_SAY_INTRO_2                    = 1,
    LOCKMAW_EMOTE_FRENZI                = 2,
    AUGH_EMOTE_KILL_CROCK               = 3,
    AUGH_SAY_HOW_YOU_KILL_CROCK         = 4,
    AUGH_SAY_AUGH_SMART                 = 5,
    AUGH_SAY_AUGH_BOSS                  = 6,
    AUGH_SAY_AUGH_STEAL                 = 7,
    AUGH_SAY_AUGH_BAD                   = 8,
    AUGH_SAY_AAA                        = 9,
};

enum ePhases
{
    AUGH_PHASE_NONE                     = 0,
    AUGH_PHASE_ACTIVE                   = 1,
    AUGH_PHASE_STEALTHED                = 2,
    AUGH_PHASE_DISMOUNTED               = 3,
    AUGH_PHASE_DESPAWNED                = 4,
};

enum eEvents
{
    // Vicious Croc
    EVENT_VICIOUS_CROC_UPDATE_THREAT    = 1,
    EVENT_VICIOUS_CROC_VICIOUS_BITE     = 2,
    // Lockmaw
    EVENT_START_DUST_FLAIL              = 3,
    EVENT_VISCOUS_POISON                = 4,
    EVENT_SUMMON_CROCOLISK              = 5,
    EVENT_SUMMON_RANDOM_AUGH_1          = 6,
    EVENT_SUMMON_RANDOM_AUGH_2          = 7,
    // Boss Augh
    EVENT_WHITLWIND                     = 8,
    EVENT_BLOW_DART                     = 9,
    EVENT_DRAGONS_BREATH                = 10,
    EVENT_SMOKE_BOMB                    = 11,
    EVENT_SAY_AAA                       = 12,
};

enum eActions
{
    ACTION_LOCKMAW_IS_DONE              = 1,
};

enum ePoins
{
    POINT_AUGH_BATTLE_POSITION          = 1,
};

const Position AughPos = {-11068.9f, -1668.37f, 0.74569f, 0.74265f};

const uint32 SummonRandomAugh[3]=
{
    SPELL_SUMMON_AUGH_DRAGONS_BREATH,
    SPELL_SUMMON_AUGH_WHITLWIND,
    SPELL_SUMMON_AUGH_BLOW_DART
};

class boss_lockmaw : public CreatureScript
{
public:
    boss_lockmaw() : CreatureScript("boss_lockmaw") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_lockmawAI (creature);
    }

    struct boss_lockmawAI : public ScriptedAI
    {
        boss_lockmawAI(Creature* creature) : ScriptedAI(creature), lSummons(me)
        {
            instance = creature->GetInstanceScript();
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
        }

        SummonList lSummons;
        EventMap events;
        InstanceScript* instance;
        uint8 uiPrevAughId;
        bool Rage;

        void Reset() override
        {
            lSummons.DespawnAll();
            events.Reset();
            Rage = false;
            uiPrevAughId = 0;

            if (instance)
                instance->SetData(DATA_LOCKMAW, NOT_STARTED);
        }

        void EnterCombat(Unit* /*pWho*/) override
        {
            if (instance)
                instance->SetData(DATA_LOCKMAW, IN_PROGRESS);

            events.ScheduleEvent(EVENT_START_DUST_FLAIL, urand(5000, 10000));
            events.ScheduleEvent(EVENT_VISCOUS_POISON, urand(2000, 5000));
            events.ScheduleEvent(EVENT_SUMMON_CROCOLISK, urand(5000, 20000));
        }

        void JustSummoned(Creature* summoned) override
        {
            if (summoned->GetEntry() == NPC_DUST_FLAIL)
            {
                me->SetReactState(REACT_PASSIVE);
                me->AttackStop();
                me->SetFacingToObject(summoned);
                me->CastSpell(me, 81642, false);
                return;
            }

            lSummons.Summon(summoned);
        }

        void JustDied(Unit* /*Killer*/) override
        {
            lSummons.DespawnAll();
            events.Reset();

            if (instance)
            {
                instance->SetData(DATA_LOCKMAW, DONE);

                if (Creature* augh = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_AUGH)))
                    augh->AI()->DoAction(ACTION_LOCKMAW_IS_DONE);
            }
        }

        void SummonAugh()
        {
            if (Creature* stalker = me->FindNearestCreature(45124, 50.0f))
            {

                uint8 roll = urand(0, 2);

                while (roll == uiPrevAughId)
                    roll = urand(0, 2);

                stalker->CastSpell(stalker, SummonRandomAugh[roll], false);
                uiPrevAughId = roll;
            }
            else
            {
                ScriptedAI::EnterEvadeMode();
                return;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (!Rage && me->HealthBelowPct(30))
            {
                Rage = true;
                DoCast(SPELL_VENOMOUS_RAGE);
                Talk(LOCKMAW_EMOTE_FRENZI);
            }

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_START_DUST_FLAIL:
                        me->CastSpell(me, 81652, false);
                        events.ScheduleEvent(EVENT_START_DUST_FLAIL, urand(15000, 30000));
                        break;
                    case EVENT_VISCOUS_POISON:
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 45.0f, true))
                                me->CastSpell(target, SPELL_VISCOUS_POISON, false);

                            events.ScheduleEvent(EVENT_VISCOUS_POISON, urand(3000, 10000));
                        }
                        break;
                    case EVENT_SUMMON_CROCOLISK:
                        {
                            events.ScheduleEvent(EVENT_SUMMON_RANDOM_AUGH_1, 1500);
                            std::list<Creature*> lStalkers;
                            me->GetCreatureListWithEntryInGrid(lStalkers, 45124, 100.0f);
                            me->CastSpell(me, DUNGEON_MODE(SPELL_SCENT_OF_BLOOD_NORMAL, SPELL_SCENT_OF_BLOOD_HEROIC), false);

                            if (lStalkers.empty())
                            {
                                ScriptedAI::EnterEvadeMode();
                                return;
                            }

                            std::list<Creature*>::const_iterator itr = lStalkers.begin();

                            for (int i = 0; i < 4; ++i)
                            {
                                if (itr == lStalkers.end())
                                    itr = lStalkers.begin();

                                if ((*itr) && (*itr)->IsAlive())
                                    (*itr)->CastSpell((*itr), 84242, false);

                                ++itr;
                            }
                        }
                        break;
                    case EVENT_SUMMON_RANDOM_AUGH_1:
                        events.ScheduleEvent(EVENT_SUMMON_RANDOM_AUGH_2, urand(15000, 30000));
                        SummonAugh();
                        break;
                    case EVENT_SUMMON_RANDOM_AUGH_2:
                        events.ScheduleEvent(EVENT_SUMMON_CROCOLISK, urand(5000, 25000));
                        SummonAugh();
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

class npc_frenzied_croc : public CreatureScript
{
public:
    npc_frenzied_croc() : CreatureScript("npc_frenzied_croc") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_frenzied_crocAI (creature);
    }

    struct npc_frenzied_crocAI : public ScriptedAI
    {
        npc_frenzied_crocAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetInCombatWithZone();
            UpdateThreat();
            me->AddAura(SPELL_STEALTHED, me);
            events.ScheduleEvent(EVENT_VICIOUS_CROC_UPDATE_THREAT, 1000);
            events.ScheduleEvent(EVENT_VICIOUS_CROC_VICIOUS_BITE, urand(5000, 10000));
            InstanceScript* instance = creature->GetInstanceScript();

            if (instance)
                if (Creature* lockmaw = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_LOCKMAW)))
                    lockmaw->AI()->JustSummoned(me);
        }

        EventMap events;

        void UpdateThreat()
        {
            Map::PlayerList const &lPlayers = me->GetMap()->GetPlayers();

            if(lPlayers.isEmpty())
                return;

            for(Map::PlayerList::const_iterator itr = lPlayers.begin(); itr != lPlayers.end(); ++itr)
                if(Player* player = itr->GetSource())
                {
                    if (player->HasAura(DUNGEON_MODE(SPELL_SCENT_OF_BLOOD_NORMAL, SPELL_SCENT_OF_BLOOD_HEROIC)))
                        me->AddThreat(player, 100500.0f);
                    else
                        me->getThreatManager().modifyThreatPercent(player, -10);
                }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_VICIOUS_CROC_UPDATE_THREAT:
                        {
                            events.ScheduleEvent(EVENT_VICIOUS_CROC_UPDATE_THREAT, 1000);
                            UpdateThreat();
                        }
                        break;
                    case EVENT_VICIOUS_CROC_VICIOUS_BITE:
                        events.ScheduleEvent(EVENT_VICIOUS_CROC_VICIOUS_BITE, urand(5000, 10000));
                        me->CastSpell(me->GetVictim(), SPELL_VICIOUS_BITE, false);
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

class npc_augh_intro : public CreatureScript
{
public:
    npc_augh_intro() : CreatureScript("npc_augh_intro") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_augh_introAI (creature);
    }

    struct npc_augh_introAI : public ScriptedAI
    {
        npc_augh_introAI(Creature* creature) : ScriptedAI(creature)
        {
            Active = true;
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        bool Active;

        void EnterCombat(Unit* /*pWho*/) override
        {
            if (Active)
                Talk(AUGH_SAY_INTRO_1);
        }

        void UpdateAI(uint32 /*diff*/) override
        {
            if (!UpdateVictim())
                return;

            if (Active)
                if (me->GetHealthPct() <= 90)
                {
                    Active = false;
                    me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                    me->SetReactState(REACT_PASSIVE);
                    me->CombatStop();
                    me->SetControlled(true, UNIT_STATE_ROOT);
                    me->CastSpell(me, SPELL_SMOKE_BOMB, false);
                    Talk(AUGH_SAY_INTRO_2);
                    me->DespawnOrUnsummon(2000);
                }

            DoMeleeAttackIfReady();
        }
    };
};

class npc_augh_blow_dart : public CreatureScript
{
public:
    npc_augh_blow_dart() : CreatureScript("npc_augh_blow_dart") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_augh_blow_dartAI (creature);
    }

    struct npc_augh_blow_dartAI : public ScriptedAI
    {
        npc_augh_blow_dartAI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddAura(SPELL_STEALTHED, me);
            me->SetInCombatWithZone();
            uiEventTimer = 3000;
            uiPhase = AUGH_PHASE_ACTIVE;
            instance = creature->GetInstanceScript();

            if (Unit* target = SelectTarget(SELECT_TARGET_NEAREST, 0, 100.0f, true))
                AttackStart(target);

            if (instance)
                if (Creature* lockmaw = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_LOCKMAW)))
                    lockmaw->AI()->JustSummoned(me);
        }

        InstanceScript* instance;
        uint32 uiEventTimer;
        uint8 uiPhase;

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (uiPhase != AUGH_PHASE_DESPAWNED)
            {
                if (uiEventTimer <= diff)
                {
                    switch(uiPhase)
                    {
                        case AUGH_PHASE_ACTIVE:
                            me->SetControlled(true, UNIT_STATE_ROOT);
                            me->CastSpell(me->GetVictim(), SPELL_PARALYTIC_BLOW_DART, false);
                            me->CastSpell(me, SPELL_SMOKE_BOMB, false);
                            uiPhase = AUGH_PHASE_STEALTHED;
                            uiEventTimer = 1500;
                            break;
                        case AUGH_PHASE_STEALTHED:
                            me->AddAura(SPELL_STEALTHED, me);
                            uiPhase = AUGH_PHASE_DESPAWNED;
                            me->DespawnOrUnsummon(1000);
                            break;
                    }
                }
                else
                    uiEventTimer -= diff;
            }
        }
    };
};

class npc_augh_whirlwind : public CreatureScript
{
public:
    npc_augh_whirlwind() : CreatureScript("npc_augh_whirlwind") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_augh_whirlwindAI (creature);
    }

    struct npc_augh_whirlwindAI : public ScriptedAI
    {
        npc_augh_whirlwindAI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddAura(SPELL_STEALTHED, me);
            me->SetInCombatWithZone();
            uiEventTimer = 2000;
            uiPhase = AUGH_PHASE_NONE;
            instance = creature->GetInstanceScript();

            if (Unit* target = SelectTarget(SELECT_TARGET_NEAREST, 0, 100.0f, true))
            {
                AttackStart(target);
                me->CastSpell(target, 50231, false);
            }

            if (instance)
                if (Creature* lockmaw = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_LOCKMAW)))
                    lockmaw->AI()->JustSummoned(me);
        }

        InstanceScript* instance;
        uint32 uiEventTimer;
        uint8 uiPhase;

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (uiPhase != AUGH_PHASE_DESPAWNED)
            {
                if (uiEventTimer <= diff)
                {
                    switch (uiPhase)
                    {
                        case AUGH_PHASE_NONE:
                        {
                            uiPhase = AUGH_PHASE_ACTIVE;
                            me->RemoveAura(SPELL_STEALTHED);
                            me->AddAura(SPELL_WHITLWIND, me);
                            uiEventTimer = 20000;
                            break;
                        }
                        case AUGH_PHASE_ACTIVE:
                        {
                            uiPhase = AUGH_PHASE_DESPAWNED;
                            me->SetReactState(REACT_PASSIVE);
                            me->AttackStop();
                            me->DespawnOrUnsummon(2000);

                            if (Creature* stalker = me->FindNearestCreature(45124, 50.0f))
                                me->GetMotionMaster()->MoveChase(stalker);

                            break;
                        }
                    }
                }
                else
                    uiEventTimer -= diff;
            }
        }
    };
};

class npc_augh_dragons_breath : public CreatureScript
{
public:
    npc_augh_dragons_breath() : CreatureScript("npc_augh_dragons_breath") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_augh_dragons_breathAI (creature);
    }

    struct npc_augh_dragons_breathAI : public ScriptedAI
    {
        npc_augh_dragons_breathAI(Creature* creature) : ScriptedAI(creature)
        {
            uiEventTimer = 300;
            uiPhase = AUGH_PHASE_NONE;
            me->SetInCombatWithZone();
            instance = creature->GetInstanceScript();

            if (instance)
                if (Creature* lockmaw = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_LOCKMAW)))
                {
                    lockmaw->AI()->JustSummoned(me);

                    if (me->IsSummon())
                        if (Unit* summoner = me->ToTempSummon()->GetSummoner())
                            if (Creature* crock = summoner->ToCreature())
                                lockmaw->AI()->JustSummoned(crock);
                }

        }

        InstanceScript* instance;
        uint32 uiEventTimer;
        uint8 uiPhase;

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (uiEventTimer <= diff)
            {
                switch(uiPhase)
                {
                    case AUGH_PHASE_NONE:
                        {
                            uiEventTimer = 5000;
                            uiPhase = AUGH_PHASE_ACTIVE;

                            if (Creature* crock = me->GetVehicleCreatureBase())
                                if (Unit* target = SelectTarget(SELECT_TARGET_NEAREST, 0, 100.0f, true))
                                {
                                    AttackStart(target);
                                    crock->GetMotionMaster()->MoveFollow(target, 0.0f, 0.0f);
                                }
                        }
                        break;
                    case AUGH_PHASE_ACTIVE:
                        {
                            if (Creature* crock = me->GetVehicleCreatureBase())
                            {
                                crock->DespawnOrUnsummon(500);
                                me->ExitVehicle();
                            }

                            uiPhase = AUGH_PHASE_DISMOUNTED;
                            uiEventTimer = 2000;
                        }
                        break;
                    case AUGH_PHASE_DISMOUNTED:
                        uiPhase = AUGH_PHASE_DESPAWNED;
                        uiEventTimer = 2500;
                        me->CastSpell(me->GetVictim(), 83776, false);
                        me->CastSpell(me, SPELL_SMOKE_BOMB, false);
                        break;
                    case AUGH_PHASE_DESPAWNED:
                        me->DespawnOrUnsummon();
                        break;
                }
            }
            else
                uiEventTimer -= diff;
        }
    };
};

class boss_augh : public CreatureScript
{
public:
    boss_augh() : CreatureScript("boss_augh") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_aughAI (creature);
    }

    struct boss_aughAI : public ScriptedAI
    {
        boss_aughAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
        }

        InstanceScript* instance;
        EventMap events;
        uint32 uiIntroTimer;
        uint8 uiIntroPhase;
        bool Intro;

        void Reset() override
        {
            events.Reset();
            uiIntroTimer = 1000;
            uiIntroPhase = 1;
            me->SetReactState(REACT_PASSIVE);
            me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);

            if (instance)
            {
                instance->SetData(DATA_AUGH, NOT_STARTED);

                if (instance->GetData(DATA_LOCKMAW) == DONE)
                {
                    me->SetVisible(true);
                    Intro = true;
                }
                else
                {
                    me->SetVisible(false);
                    Intro = false;
                }
            }
        }

        void DoAction(const int32 action) override
        {
            if (action == ACTION_LOCKMAW_IS_DONE)
            {
                uiIntroPhase = 0;
                Intro = true;
                Talk(AUGH_EMOTE_KILL_CROCK);
                me->SetEmoteState(EMOTE_ONESHOT_NONE);
                me->SetVisible(true);
                me->SetHomePosition(AughPos);
                me->GetMotionMaster()->MoveTargetedHome();
            }
        }

        void JustDied(Unit* /*Killer*/) override
        {
            events.Reset();

            if (instance)
                instance->SetData(DATA_AUGH, DONE);
        }

        void EnterCombat(Unit* /*pWho*/) override
        {
            if (instance)
                instance->SetData(DATA_AUGH, IN_PROGRESS);

            Intro = false;
            me->CastSpell(me, 91415, false);
            events.ScheduleEvent(EVENT_WHITLWIND, urand(3000, 15000));
            events.ScheduleEvent(EVENT_BLOW_DART, urand(3000, 10000));
            events.ScheduleEvent(EVENT_DRAGONS_BREATH, urand(3000, 10000));
            events.ScheduleEvent(EVENT_SMOKE_BOMB, urand(3000, 15000));
            events.ScheduleEvent(EVENT_SAY_AAA, urand(15000, 35000));
        }

        void UpdateAI(uint32 diff) override
        {
            if (Intro)
            {
                if (uiIntroTimer <= diff)
                {
                    switch (uiIntroPhase)
                    {
                        case 0:
                            uiIntroTimer = 5000;
                            Talk(AUGH_SAY_HOW_YOU_KILL_CROCK);
                            break;
                        case 1:
                            Talk(AUGH_SAY_AUGH_SMART);
                            uiIntroTimer = 9000;
                            break;
                        case 2:
                        {
                            Talk(AUGH_SAY_AUGH_BOSS);
                            uiIntroTimer = 5000;

                            if (IsHeroic())
                            {
                                me->SetReactState(REACT_AGGRESSIVE);
                                me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                            }
                            break;
                        }
                        case 3:
                            Talk(AUGH_SAY_AUGH_STEAL);
                            uiIntroTimer = 7000;
                            break;
                        case 4:
                            Talk(AUGH_SAY_AUGH_BAD);
                            Intro = false;
                            break;
                    }

                    ++uiIntroPhase;
                }
                else
                    uiIntroTimer -= diff;
            }

            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_WHITLWIND:
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                        {
                            AttackStart(target);
                            me->CastSpell(target, 50231, false);
                        }

                        me->AddAura(91408, me);
                        events.ScheduleEvent(EVENT_WHITLWIND, urand(15000, 30000));
                        break;
                    }
                    case EVENT_BLOW_DART:
                        if (SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                            me->CastSpell(me->GetVictim(), SPELL_PARALYTIC_BLOW_DART, false);

                        events.ScheduleEvent(EVENT_BLOW_DART, urand(5000, 10000));
                        break;
                    case EVENT_DRAGONS_BREATH:
                        me->CastSpell(me->GetVictim(), 83776, false);
                        events.ScheduleEvent(EVENT_DRAGONS_BREATH, urand(5000, 10000));
                        break;
                    case EVENT_SMOKE_BOMB:
                        me->CastSpell(me, SPELL_SMOKE_BOMB, false);
                        events.ScheduleEvent(EVENT_SMOKE_BOMB, urand(7000, 15000));
                        break;
                    case EVENT_SAY_AAA:
                        Talk(AUGH_SAY_AAA);
                        events.ScheduleEvent(EVENT_SAY_AAA, urand(15000, 35000));
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

class spell_dust_flail: public SpellScriptLoader
{
    public:
        spell_dust_flail() : SpellScriptLoader("spell_dust_flail") { }

        class spell_dust_flail_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dust_flail_AuraScript);

            void ExtraEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                    if (Creature* lockmaw = caster->ToCreature())
                        lockmaw->SetReactState(REACT_AGGRESSIVE);
            }

            void Register() override
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_dust_flail_AuraScript::ExtraEffectRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dust_flail_AuraScript();
        }
};

void AddSC_boss_lockmaw_augh()
{
    new boss_lockmaw();
    new npc_frenzied_croc();
    new npc_augh_intro();
    new npc_augh_blow_dart();
    new npc_augh_whirlwind();
    new npc_augh_dragons_breath();
    new boss_augh();

    new spell_dust_flail();
}
