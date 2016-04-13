/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

#include "ScriptedCreature.h"
#include "mogu_shan_vault.h"
#include "ScriptMgr.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "CreatureAI.h"
#include "MoveSplineInit.h"

#define SPELL_INACTIVE 118205
#define SPELL_ACTIVATION_VISUAL 118212
enum spells
{
    SPELL_SPIRIT_BOLT           = 121224,
    SPELL_GROUND_SLAM           = 121087,
    SPELL_PETRIFICATION         = 125090,
    SPELL_PETRIFIED             = 125092,
    SPELL_FULLY_PETRIFIED       = 115877,
    SPELL_MONSTROUS_BITE        = 125096,
    SPELL_SUNDERING_BITE        = 116970,
    SPELL_PROTECTIVE_FENZY      = 116982,
    SPELL_SHATTERING_STONE      = 116977,
    SPELL_FOCUSED_ASSAULT       = 116990
};

class mob_cursed_mogu_sculture : public CreatureScript
{
    public:
        mob_cursed_mogu_sculture() : CreatureScript("mob_cursed_mogu_sculture") {}

        struct mob_cursed_mogu_scultureAI : public ScriptedAI
        {
            mob_cursed_mogu_scultureAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            InstanceScript* pInstance;
            EventMap events;
            uint32 spiritBoltTimer;
            uint32 groundSlamTimer;

            Creature* GetCho()
            {
                if (pInstance)
                    return me->GetMap()->GetCreature(pInstance->GetData64(NPC_LOREWALKER_CHO));
                else
                    return NULL;
            }

            void Reset()
            {
                spiritBoltTimer = urand(10000, 40000);
                groundSlamTimer = urand(40000, 60000);

                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);

                if (me->GetEntry() == 61334)
                {
                    me->AddAura(120613, me); // Pose
                    me->AddAura(120661, me); // Bronze
                }
                else if (me->GetEntry() == 61989)
                {
                    me->AddAura(120650, me); // Pose
                    me->AddAura(120663, me); // Pierre
                }
            }

            void MoveInLineOfSight(Unit* who)
            {
                if (who->GetTypeId() != TYPEID_PLAYER)
                    return;

                if (!me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE))
                    return;

                if (me->IsWithinDistInMap(who, 20.0f))
                {
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
                    me->RemoveAurasDueToSpell(120661);
                    me->RemoveAurasDueToSpell(120613);
                    me->RemoveAurasDueToSpell(120650);
                    me->RemoveAurasDueToSpell(120663);
                    AttackStart(who);
                }
            }

            void EnterCombat(Unit* attacker)
            {
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
                me->RemoveAurasDueToSpell(120661);
                me->RemoveAurasDueToSpell(120613);
                me->RemoveAurasDueToSpell(120650);
                me->RemoveAurasDueToSpell(120663);
            }

            void JustDied(Unit* killer)
            {
                if (!GetClosestCreatureWithEntry(me, me->GetEntry(), 50.0f, true))
                {
                    Creature* Feng = GetClosestCreatureWithEntry(me, 60009, 100.0f, true);
                    if (Feng && Feng->AI())
                        Feng->AI()->Talk(7);
                }

                if (me->GetEntry() == 61989)
                {
                    if (Creature* lorewalkerCho = GetClosestCreatureWithEntry(me, 61348, 100.0f, true))
                    {
                        if (lorewalkerCho->AI())
                        {
                            if (lorewalkerCho->GetPositionX() >= 3963.0f && lorewalkerCho->GetPositionX() <= 3966.0f &&
                                lorewalkerCho->GetPositionY() >= 1340.5f && lorewalkerCho->GetPositionY() <= 1342.5f &&
                                lorewalkerCho->GetPositionZ() >= 460.0f && lorewalkerCho->GetPositionZ() <= 463.0f)
                            {
                                lorewalkerCho->AI()->DoAction(ACTION_CONTINUE_ESCORT);
                                lorewalkerCho->AI()->Talk(7);
                            }
                        }
                    }
                }
                else
                    return;
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (spiritBoltTimer <= diff)
                {
                    if (Unit* target = me->SelectNearestTarget(5.0f))
                        if (!target->IsFriendlyTo(me))
                            me->CastSpell(target, SPELL_SPIRIT_BOLT, true);
                    spiritBoltTimer = urand(10000, 30000);
                }
                else
                    spiritBoltTimer -= diff;
                 
                if (groundSlamTimer <= diff)
                {
                    if (Unit* target = me->SelectNearestTarget(5.0f))
                        if (!target->IsFriendlyTo(me))
                            me->CastSpell(target, SPELL_GROUND_SLAM, true);
                    groundSlamTimer = urand(40000, 60000);
                }
                else
                    groundSlamTimer -= diff;

                DoMeleeAttackIfReady();
            }
            
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_cursed_mogu_scultureAI(creature);
        }
};

float quilenNewY[2] = {1170.0f, 1240.0f};

enum enormousQuilenEvent
{
    EVENT_MONSTROUS_BITE = 1,
    EVENT_NEXT_MOVEMENT  = 2
};

class mob_enormous_stone_quilen : public CreatureScript
{
    public:
        mob_enormous_stone_quilen() : CreatureScript("mob_enormous_stone_quilen") {}

        struct mob_enormous_stone_quilenAI : public ScriptedAI
        {
            mob_enormous_stone_quilenAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
                prevPosition = 1;

                if (me->GetPositionX() > 3900)
                    prevPosition = 2;

                nextMovementTimer = 0;
                me->SetWalk(true);
                me->GetMotionMaster()->MovePoint(prevPosition, me->GetPositionX(), quilenNewY[prevPosition - 1], me->GetPositionZ());
            }

            InstanceScript* pInstance;
            EventMap events;
            uint32 nextMovementTimer;
            uint8 prevPosition;

            void Reset()
            {
                events.ScheduleEvent(EVENT_MONSTROUS_BITE, urand (3000, 5000));
            }

            void JustReachedHome()
            {
                prevPosition = 1;

                if (me->GetPositionX() > 3900)
                    prevPosition = 2;

                nextMovementTimer = 0;
                me->SetWalk(true);
                me->GetMotionMaster()->MovePoint(prevPosition, me->GetPositionX(), quilenNewY[prevPosition - 1], me->GetPositionZ());
            }

            void MovementInform(uint32 typeId, uint32 pointId)
            {
                if (typeId != POINT_MOTION_TYPE)
                    return;

                if (me->IsInCombat())
                    return;

                prevPosition = pointId;
                nextMovementTimer = 500;
            }

            void EnterCombat(Unit* attacker)
            {
                me->SetWalk(false);
                //me->AddAura(SPELL_PETRIFICATION, me);
            }

            void UpdateAI(uint32 diff)
            {
                if (nextMovementTimer)
                {
                    if (nextMovementTimer <= diff)
                    {
                        me->GetMotionMaster()->MovePoint(prevPosition == 2 ? 1: 2, me->GetPositionX(), quilenNewY[prevPosition == 2 ? 0: 1], me->GetPositionZ());
                        nextMovementTimer = 0;
                    }
                    else
                        nextMovementTimer -= diff;
                }

                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_MONSTROUS_BITE:
                        {
                            if (Unit* target = me->SelectNearestTarget(5.0f))
                            {
                                if (!target->IsFriendlyTo(me))
                                    me->CastSpell(target, SPELL_MONSTROUS_BITE, true);
                            }
                            events.ScheduleEvent(EVENT_MONSTROUS_BITE, urand(6000, 8000));
                            break;
                        }
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_enormous_stone_quilenAI(creature);
        }
};

enum eQuilenEvents
{
    EVENT_SUNDERING_BITE    = 1,
    EVENT_SHATTERING_STONE  = 2,
    EVENT_fOCUSED_ASSAULT   = 3
};

class mob_stone_quilen : public CreatureScript
{
    public:
        mob_stone_quilen() : CreatureScript("mob_stone_quilen") {}

        struct mob_stone_quilenAI : public ScriptedAI
        {
            mob_stone_quilenAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            InstanceScript* pInstance;
            EventMap events;

            void Reset()
            {
                events.Reset();

                events.ScheduleEvent(EVENT_SUNDERING_BITE,   urand (5000, 6000));
                events.ScheduleEvent(EVENT_SHATTERING_STONE, urand (10000, 12000));
                events.ScheduleEvent(EVENT_fOCUSED_ASSAULT,  urand (500, 5000));
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (!me->HasAura(SPELL_PROTECTIVE_FENZY) && me->HealthBelowPct(10))
                    me->CastSpell(me, SPELL_PROTECTIVE_FENZY, true);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SUNDERING_BITE:
                        {
                            if (Unit* target = me->SelectNearestTarget(5.0f))
                                me->CastSpell(target, SPELL_SUNDERING_BITE, true);

                            events.ScheduleEvent(EVENT_SUNDERING_BITE,   urand (5000, 6000));
                            break;
                        }
                        case EVENT_SHATTERING_STONE:
                        {
                            if (Unit* target = me->SelectNearestTarget(5.0f))
                                me->CastSpell(target, SPELL_SHATTERING_STONE, true);

                            events.ScheduleEvent(EVENT_SHATTERING_STONE, urand (10000, 12000));
                            break;
                        }
                        case EVENT_fOCUSED_ASSAULT:
                        {
                            if (Unit* target = me->SelectNearestTarget(5.0f))
                                me->AddAura(SPELL_FOCUSED_ASSAULT, target);

                            events.ScheduleEvent(EVENT_fOCUSED_ASSAULT,  urand (500, 5000));
                            break;
                        }
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_stone_quilenAI(creature);
        }
};

enum eSkullCharger
{
    SPELL_TROLL_RUSH    = 116006,
    EVENT_TROLL_RUSH    = 1
};

class mob_zandalari_skullcharger : public CreatureScript
{
    public:
        mob_zandalari_skullcharger() : CreatureScript("mob_zandalari_skullcharger") {}

        struct mob_zandalari_skullchargerAI : public ScriptedAI
        {
            mob_zandalari_skullchargerAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            InstanceScript* pInstance;
            EventMap events;

            void Reset()
            {
                events.Reset();

                events.ScheduleEvent(EVENT_TROLL_RUSH, urand (5000, 6000));
            }

            void EnterCombat(Unit* attacker)
            {
                if (Creature* lorewalkerCho = GetClosestCreatureWithEntry(me, 61348, 150.0f, true))
                {
                    if (lorewalkerCho->AI())
                    {
                        lorewalkerCho->AI()->DoAction(ACTION_SAY_ZANDALARI_BEGIN);
                    }
                }
            }

            void JustDied(Unit* killer)
            {
                if (Creature* lorewalkerCho = GetClosestCreatureWithEntry(me, 61348, 150.0f, true))
                {
                    if (lorewalkerCho->AI())
                    {
                        if (lorewalkerCho->GetPositionX() == 4128.93f && lorewalkerCho->GetPositionY() == 1351.51f && lorewalkerCho->GetPositionZ() == 461.886f)
                        {
                            lorewalkerCho->AI()->DoAction(ACTION_SAY_ZANDALARI_DEATH);
                            lorewalkerCho->AI()->DoAction(ACTION_CONTINUE_ESCORT);
                        }
                    }
                }
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_TROLL_RUSH:
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST))
                            {
                                me->CastSpell(target, SPELL_TROLL_RUSH, true);
                                me->GetMotionMaster()->MoveChase(target);
                            }
                            events.ScheduleEvent(EVENT_TROLL_RUSH,   urand (5000, 6000));
                            break;
                        }

                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_zandalari_skullchargerAI(creature);
        }
};

class spell_mogu_petrification : public SpellScriptLoader
{
    public:
        spell_mogu_petrification() : SpellScriptLoader("spell_mogu_petrification") { }

        class spell_mogu_petrification_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mogu_petrification_AuraScript);

            uint32 stack;

            void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                {
                    if (Unit* target = GetTarget())
                    {
                        if (target->HasAura(SPELL_PETRIFIED))
                        {
                            stack = GetTarget()->GetAura(SPELL_PETRIFIED)->GetStackAmount();

                            if (stack >= 100)
                                target->AddAura(SPELL_FULLY_PETRIFIED, target);
                        }
                    }
                }
            }

            void Register()
            {
                OnEffectApply += AuraEffectApplyFn(spell_mogu_petrification_AuraScript::OnApply, EFFECT_0, SPELL_AURA_MOD_DECREASE_SPEED, AURA_EFFECT_HANDLE_REAPPLY);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_mogu_petrification_AuraScript();
        }
};

#define GOSSIP_CHOICE_1  "What are you waiting for ? Let's go investigate !"

enum eChoTexts
{
    INTRO_01           =  0,
    INTRO_02           =  1,
    INTRO_03           =  2,
    INTRO_04           =  3,
    INTRO_05           =  4,
    INTRO_06           =  5,
    INTRO_07           =  6,
    INTRO_08           =  7,
    FENG_01            =  8,
    FENG_02            =  9,
    FENG_03            = 10,
    ZANDALARI_01       = 11,
    ZANDALARI_02       = 12,
    SPIRIT_KINGS_01    = 13
};

enum eChoEvents
{
    EVENT_START_FIRST_COMBAT = 1
};

class npc_lorewalker_cho : public CreatureScript
{
public:
    npc_lorewalker_cho() : CreatureScript("npc_lorewalker_cho")
    {
    }

        bool OnGossipHello(Player* player, Creature* creature)
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_CHOICE_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->SEND_GOSSIP_MENU(30003, creature->GetGUID());

            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
        {
            player->PlayerTalkClass->ClearMenus();

            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                player->CLOSE_GOSSIP_MENU();
                creature->AI()->DoAction(ACTION_CONTINUE_ESCORT);
            }

            return true;
        }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_lorewalker_choAI(creature);
    }

    struct npc_lorewalker_choAI : public npc_escortAI
    {
        npc_lorewalker_choAI(Creature* creature) : npc_escortAI(creature)
        {
            pInstance = creature->GetInstanceScript();
        }

        bool hasSaidIntro;
        bool hasSaidStoneguardDeath;
        bool hasSaidZandalariBegin;
        bool hasSaidZandalariDeath;

        uint32 intro4Timer;

        InstanceScript* pInstance;
        EventMap events;

        void Reset()
        {
            me->RemoveFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

            events.Reset();
            SetDespawnAtFar(false);
            SetDespawnAtEnd(false);
            hasSaidIntro = false;
            hasSaidStoneguardDeath = false;
            hasSaidZandalariBegin = false;
            hasSaidZandalariDeath = false;

            intro4Timer = 0;
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (hasSaidIntro || who->GetTypeId() != TYPEID_PLAYER)
                return;

            if (me->IsWithinDistInMap(who, 30.0f))
            {
                Talk(INTRO_01);
                hasSaidIntro = true;
                Start(false, false, who->GetGUID());
            }
        }

        void WaypointReached(uint32 waypointId)
        {
            switch(waypointId)
            {
                case 0:
                    Talk(INTRO_02);
                    break;
                case 3:
                    Talk(INTRO_03);
                    SetEscortPaused(true);
                    SetRun(true);
                    intro4Timer = 10000;
                    break;
                case 4:
                    Talk(INTRO_05);
                    break;
                case 7:
                    Talk(INTRO_06);
                    SetRun(false);
                    break;
                case 9:
//                    SetRun(false);
                    break;
                case 10:
                    Talk(INTRO_07);
                    break;
                case 12:
                    SetEscortPaused(true);
                    break;
                case 13:
                    Talk(FENG_01);
                    SetEscortPaused(true);
                    break;
                case 19:
                    Talk(FENG_03);
                    SetEscortPaused(true);
                case 21:
                    SetEscortPaused(true);
                    break;
                case 36:
//                    SetRun(false);
                    break;
                case 38:
                    me->SetOrientation(4.68f);
                    me->SetFacingTo(4.68f);
                    me->SetFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    SetEscortPaused(true);
                    break;
                case 39:
                    me->RemoveFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    break;
                case 42:
                {
                    std::list<Creature*> sorcererMoguList;
                    me->GetCreatureListWithEntryInGrid(sorcererMoguList, NPC_SORCERER_MOGU, 100.0f);
            
                    std::list<Creature*> mountedMoguList;
                    me->GetCreatureListWithEntryInGrid(mountedMoguList, NPC_MOUNTED_MOGU, 200.0f);

                    std::list<Creature*> moguArcherList;
                    me->GetCreatureListWithEntryInGrid(moguArcherList, NPC_MOGU_ARCHER, 100.0f);

                    std::list<Creature*> kingsGuardList;
                    me->GetCreatureListWithEntryInGrid(kingsGuardList, NPC_KINGSGUARD, 200.0f);

                    me->SetOrientation(1.51f);
                    me->SetFacingTo(1.51f);
                    SetEscortPaused(true);
                    Talk(SPIRIT_KINGS_01);

                    if (!sorcererMoguList.empty())
                    {
                        for (std::list<Creature*>::const_iterator itr = sorcererMoguList.begin(); itr != sorcererMoguList.end(); ++itr)
                        {
                            if (Creature* sorcererMogu = *itr)
                            {
                                sorcererMogu->AI()->DoAction(ACTION_SET_NATIVE_DISPLAYID);
                                sorcererMogu->AI()->DoAction(ACTION_SET_GHOST_VISUAL);
                                sorcererMogu->AI()->DoAction(ACTION_BEFORE_COMBAT);
                                events.ScheduleEvent(EVENT_START_FIRST_COMBAT,    4000);
                            }
                        }
                    }

                    if (!mountedMoguList.empty())
                    {
                        for (std::list<Creature*>::const_iterator itr = mountedMoguList.begin(); itr != mountedMoguList.end(); ++itr)
                        {
                            if (Creature* mountedMogu = *itr)
                            {
                                mountedMogu->AI()->DoAction(ACTION_SET_NATIVE_DISPLAYID);
                                mountedMogu->AI()->DoAction(ACTION_SET_GHOST_VISUAL);
                            }
                        }
                    }

                    if (!moguArcherList.empty())
                    {
                        for (std::list<Creature*>::const_iterator itr = moguArcherList.begin(); itr != moguArcherList.end(); ++itr)
                        {
                            if (Creature* moguArcher = *itr)
                            {
                                moguArcher->AI()->DoAction(ACTION_SET_NATIVE_DISPLAYID);
                                moguArcher->AI()->DoAction(ACTION_SET_GHOST_VISUAL);
                            }
                        }
                    }

                    if (!kingsGuardList.empty())
                    {
                        for (std::list<Creature*>::const_iterator itr = kingsGuardList.begin(); itr != kingsGuardList.end(); ++itr)
                        {
                            if (Creature* kingsGuard = *itr)
                            {
                                kingsGuard->AI()->DoAction(ACTION_SET_NATIVE_DISPLAYID);
                                kingsGuard->AI()->DoAction(ACTION_SET_GHOST_VISUAL);
                            }
                        }
                    }

                    if (Creature* zian = GetClosestCreatureWithEntry(me, MOB_ZIAN, 200.0f))
                    {
                        if (zian->AI())
                        {
                            zian->AI()->DoAction(ACTION_SET_GHOST_VISUAL);
                            zian->AI()->DoAction(ACTION_SET_NATIVE_DISPLAYID);
                            zian->AI()->DoAction(ACTION_BEFORE_COMBAT);
                            events.ScheduleEvent(EVENT_START_FIRST_COMBAT,    5000);
                        }
                    }

                    if (Creature* meng = GetClosestCreatureWithEntry(me, MOB_MENG, 200.0f))
                    {
                        if (meng->AI())
                            meng->AI()->DoAction(ACTION_SET_GHOST_VISUAL);
                            meng->AI()->DoAction(ACTION_SET_NATIVE_DISPLAYID);
                    }

                    if (Creature* qiang = GetClosestCreatureWithEntry(me, MOB_QIANG, 200.0f))
                    {
                        if (qiang->AI())
                            qiang->AI()->DoAction(ACTION_SET_GHOST_VISUAL);
                            qiang->AI()->DoAction(ACTION_SET_NATIVE_DISPLAYID);
                    }

                    if (Creature* subetai = GetClosestCreatureWithEntry(me, MOB_SUBETAI, 200.0f))
                    {
                        if (subetai->AI())
                            subetai->AI()->DoAction(ACTION_SET_GHOST_VISUAL);
                            subetai->AI()->DoAction(ACTION_SET_NATIVE_DISPLAYID);
                    }

                    break;
                }
                default:
                    break;
            }
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
                case ACTION_CONTINUE_ESCORT:
                    SetEscortPaused(false);
                    break;
                case ACTION_RUN:
                    SetRun(true);
                    break;
                case ACTION_SAY_ZANDALARI_BEGIN:
                    if (!hasSaidZandalariBegin)
                    {
                        Talk(ZANDALARI_01);
                        hasSaidZandalariBegin = true;
                    }
                    break;
                case ACTION_SAY_ZANDALARI_DEATH:
                    if (!hasSaidZandalariDeath)
                    {
                        Talk(ZANDALARI_02);
                        hasSaidZandalariDeath = true;
                    }
                    break;
                default:
                    break;
            }
        }

        void JustSummoned(Creature* summoned)
        {
        }

        void UpdateAI(uint32 diff)
        {
            npc_escortAI::UpdateAI(diff);

            if (intro4Timer)
            {
                if (intro4Timer <= diff)
                {
                    Talk(INTRO_04);
                    intro4Timer = 0;
                }
                else
                    intro4Timer -= diff;
            }

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                std::list<Creature*> sorcererMoguList;
                me->GetCreatureListWithEntryInGrid(sorcererMoguList, NPC_SORCERER_MOGU, 200.0f);

                switch (eventId)
                {
                    case EVENT_START_FIRST_COMBAT:
                        if (Creature* zian = GetClosestCreatureWithEntry(me, MOB_ZIAN, 200.0f))
                        {
                            if (zian->AI())
                                zian->AI()->DoAction(ACTION_START_FIRST_COMBAT);
                        }

                        if (!sorcererMoguList.empty())
                        {
                            for (std::list<Creature*>::const_iterator itr = sorcererMoguList.begin(); itr != sorcererMoguList.end(); ++itr)
                            {
                                if (Creature* sorcererMogu = *itr)
                                {
                                    sorcererMogu->AI()->DoAction(ACTION_START_FIRST_COMBAT);
                                }
                            }
                        }
                                
                        break;
                    default:
                        break;
                }
            }
        }
    };

};

#define SPELL_CHARGED_SHADOWS 117685

enum eMobZianEvents
{
    EVENT_CHARGED_SHADOWS             = 1
};

#define EQUIP_ZIAN_STAFF    76369

class mob_zian : public CreatureScript
{
    public:
        mob_zian() : CreatureScript("mob_zian")
        {
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_zianAI(creature);
        }

        struct mob_zianAI : public ScriptedAI
        {
            mob_zianAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            EventMap events;
            InstanceScript* pInstance;

            void Reset()
            {
                me->SetDisplayId(11686);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

                events.Reset();
                events.ScheduleEvent(EVENT_CHARGED_SHADOWS,    urand(5000, 15000));
            }

            void DoAction(int32 action)
            {
                switch (action)
                {
                    case ACTION_SET_GHOST_VISUAL:
                        me->AddAura(SPELL_INACTIVE, me);
                        break;
                    case ACTION_SET_NATIVE_DISPLAYID:
                        me->SetDisplayId(41566);
                        SetEquipmentSlots(false, EQUIP_ZIAN_STAFF, 0, EQUIP_NO_CHANGE);
                        break;
                    case ACTION_BEFORE_COMBAT:
                        me->AddAura(SPELL_ACTIVATION_VISUAL, me);
                        break;
                    case ACTION_START_FIRST_COMBAT:
                        me->RemoveAurasDueToSpell(SPELL_ACTIVATION_VISUAL);
                        me->setFaction(14);
                        break;
                    case ACTION_END_FIRST_COMBAT:
                        me->DespawnOrUnsummon();
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 diff)
            {
                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;

                    switch (eventId)
                    {
                        case EVENT_CHARGED_SHADOWS:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_CHARGED_SHADOWS, false);
                            events.ScheduleEvent(EVENT_CHARGED_SHADOWS,       urand(5000, 12000));
                            break;
                        default:
                            break;
                    }
                }
            }
        };
};

#define SPELL_SHADOW_BLAST 119365

enum eSorcererMoguEvents
{
    EVENT_SHADOW_BLAST          = 1
};

class mob_sorcerer_mogu : public CreatureScript
{
    public:
        mob_sorcerer_mogu() : CreatureScript("mob_sorcerer_mogu")
        {
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_sorcerer_moguAI(creature);
        }

        struct mob_sorcerer_moguAI : public ScriptedAI
        {
            mob_sorcerer_moguAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;
            bool allKilled;

            void Reset()
            {
                allKilled = false;

                me->SetDisplayId(11686);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

                events.Reset();
                events.ScheduleEvent(EVENT_SHADOW_BLAST,         5000);
            }

            void DoAction(int32 action)
            {
                switch (action)
                {
                    case ACTION_SET_GHOST_VISUAL:
                        me->AddAura(SPELL_INACTIVE, me);
                        break;
                    case ACTION_SET_NATIVE_DISPLAYID:
                        me->SetDisplayId(40138);
                        break;
                    case ACTION_BEFORE_COMBAT:
                        me->AddAura(SPELL_ACTIVATION_VISUAL, me);
                        break;
                    case ACTION_START_FIRST_COMBAT:
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        me->RemoveAurasDueToSpell(SPELL_ACTIVATION_VISUAL);
                        me->setFaction(14);
                        break;
                    case ACTION_END_FIRST_COMBAT:
                        me->DespawnOrUnsummon();
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 diff)
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    std::list<Creature*> mountedMoguList;
                    me->GetCreatureListWithEntryInGrid(mountedMoguList, NPC_MOUNTED_MOGU, 200.0f);

                    switch (eventId)
                    {
                        case EVENT_SHADOW_BLAST:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_SHADOW_BLAST, false);
                            events.ScheduleEvent(EVENT_SHADOW_BLAST,       urand(8000, 17000));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

#define SPELL_ANNIHILATE 119521

enum eMobQiangEvents
{
    EVENT_ANNIHILATE            = 1,
    EVENT_START_SECOND_COMBAT   = 2
};

#define EQUIP_QIANG_POLEARM    86777

class mob_qiang : public CreatureScript
{
    public:
        mob_qiang() : CreatureScript("mob_qiang")
        {
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_qiangAI(creature);
        }

        struct mob_qiangAI : public ScriptedAI
        {
            mob_qiangAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset()
            {
                me->SetDisplayId(11686);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

                events.Reset();
                events.ScheduleEvent(EVENT_ANNIHILATE,    urand(5000, 15000));
            }

            void DoAction(int32 action)
            {
                switch (action)
                {
                    case ACTION_SET_GHOST_VISUAL:
                        me->AddAura(SPELL_INACTIVE, me);
                        break;
                    case ACTION_SET_NATIVE_DISPLAYID:
                        me->SetDisplayId(41812);
                        SetEquipmentSlots(false, EQUIP_QIANG_POLEARM, 0, EQUIP_NO_CHANGE);
                        break;
                    case ACTION_BEFORE_COMBAT:
                        me->AddAura(SPELL_ACTIVATION_VISUAL, me);
                        break;
                    case ACTION_START_SECOND_COMBAT:
                        me->RemoveAurasDueToSpell(SPELL_ACTIVATION_VISUAL);
                        me->setFaction(14);
                        break;
                    case ACTION_END_SECOND_COMBAT:
                        me->DespawnOrUnsummon();
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 diff)
            {
                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                std::list<Creature*> sorcererMoguList;
                me->GetCreatureListWithEntryInGrid(sorcererMoguList, NPC_SORCERER_MOGU, 200.0f);

                std::list<Creature*> mountedMoguList;
                me->GetCreatureListWithEntryInGrid(mountedMoguList, NPC_MOUNTED_MOGU, 200.0f);

                for (auto sorcererMogu : sorcererMoguList)
                {
                    if (sorcererMogu->IsAlive() && sorcererMogu != me)
                        return;

                    else
                    {
                        sorcererMogu->AI()->DoAction(ACTION_END_FIRST_COMBAT);
                        if (Creature* zian = GetClosestCreatureWithEntry(me, MOB_ZIAN, 200.0f))
                        {
                            if (zian->AI())
                                zian->AI()->DoAction(ACTION_END_FIRST_COMBAT);
                        }
                    }
                }

                if (Creature* qiang = GetClosestCreatureWithEntry(me, MOB_QIANG, 200.0f))
                {
                    if (qiang->AI())
                        qiang->AI()->DoAction(ACTION_BEFORE_COMBAT);
                }

                    for (auto mountedMogu : mountedMoguList)
                        mountedMogu->AI()->DoAction(ACTION_BEFORE_COMBAT);
                    
                events.ScheduleEvent(EVENT_START_SECOND_COMBAT, 5000);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_ANNIHILATE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_ANNIHILATE, false);
                            events.ScheduleEvent(EVENT_ANNIHILATE,       urand(10000, 20000));
                            break;
                        case EVENT_START_SECOND_COMBAT:
                            if (Creature* qiang = GetClosestCreatureWithEntry(me, MOB_QIANG, 200.0f))
                                if (qiang->AI())
                                    qiang->AI()->DoAction(ACTION_START_SECOND_COMBAT);
                            for (auto itr : mountedMoguList)
                                itr->AI()->DoAction(ACTION_START_SECOND_COMBAT);
                            break;
                        default:
                            break;
                    }
                }
            }
        };
};
enum eMountedMoguSpells
{
    SPELL_CRUSHING_ATTACKS      = 119514
};

enum eMountedMoguEvents
{
    EVENT_CRUSHING_ATTACKS      = 1
};

#define EQUIP_MOUNTED_MOGU_WEAPON 80132

class mob_mounted_mogu : public CreatureScript
{
    public:
        mob_mounted_mogu() : CreatureScript("mob_mounted_mogu")
        {
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_mounted_moguAI(creature);
        }

        struct mob_mounted_moguAI : public ScriptedAI
        {
            mob_mounted_moguAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset()
            {
                me->SetDisplayId(11686);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

                events.Reset();
                events.ScheduleEvent(EVENT_CRUSHING_ATTACKS,    urand(5000, 12000));
            }

            void DoAction(int32 action)
            {
                switch (action)
                {
                    case ACTION_SET_GHOST_VISUAL:
                        me->AddAura(SPELL_INACTIVE, me);
                        break;
                    case ACTION_SET_NATIVE_DISPLAYID:
                        me->SetDisplayId(42555);
                        me->SetUInt32Value(UNIT_FIELD_MOUNT_DISPLAY_ID, 41441);
                        SetEquipmentSlots(false, EQUIP_MOUNTED_MOGU_WEAPON, 0, EQUIP_NO_CHANGE);
                        break;
                   case ACTION_BEFORE_COMBAT:
                        me->AddAura(SPELL_ACTIVATION_VISUAL, me);
                        break;
                   case ACTION_START_SECOND_COMBAT:
                        me->RemoveAurasDueToSpell(SPELL_ACTIVATION_VISUAL);
                        me->setFaction(14);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        break;
                   case ACTION_END_SECOND_COMBAT:
                       me->DespawnOrUnsummon();
                       break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CRUSHING_ATTACKS:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_CRUSHING_ATTACKS, false);
                            events.ScheduleEvent(EVENT_CRUSHING_ATTACKS,       25000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

#define SPELL_VOLLEY  119554

enum eMobSubetaiEvents
{
    EVENT_VOLLEY             = 1,
    EVENT_START_THIRD_COMBAT = 2
};

#define EQUIP_SUBETAI_SWORD    80283
#define EQUIP_SUBETAI_BOW      60790

class mob_subetai : public CreatureScript
{
    public:
        mob_subetai() : CreatureScript("mob_subetai")
        {
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_subetaiAI(creature);
        }

        struct mob_subetaiAI : public ScriptedAI
        {
            mob_subetaiAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset()
            {
                me->SetDisplayId(11686);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

                events.Reset();
                events.ScheduleEvent(EVENT_VOLLEY,    urand(5000, 15000));
            }

            void DoAction(int32 action)
            {
                switch (action)
                {
                    case ACTION_SET_GHOST_VISUAL:
                        me->AddAura(SPELL_INACTIVE, me);
                        break;
                    case ACTION_SET_NATIVE_DISPLAYID:
                        me->SetDisplayId(41565);
                        SetEquipmentSlots(false, EQUIP_SUBETAI_SWORD, EQUIP_SUBETAI_SWORD, EQUIP_SUBETAI_BOW);
                        break;
                    case ACTION_BEFORE_COMBAT:
                        me->AddAura(SPELL_ACTIVATION_VISUAL, me);
                        break;
                    case ACTION_START_THIRD_COMBAT:
                        me->RemoveAurasDueToSpell(SPELL_ACTIVATION_VISUAL);
                        me->setFaction(14);
                        break;
                    case ACTION_END_THIRD_COMBAT:
                        me->DespawnOrUnsummon();
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 diff)
            {
                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);
                
                std::list<Creature*> mountedMoguList;
                me->GetCreatureListWithEntryInGrid(mountedMoguList, NPC_MOUNTED_MOGU, 200.0f);
                
                std::list<Creature*> moguArcherList;
                me->GetCreatureListWithEntryInGrid(moguArcherList, NPC_MOGU_ARCHER, 100.0f);

                for (auto mountedMogu : mountedMoguList)
                {
                    if (mountedMogu->IsAlive() && mountedMogu != me)
                        return;

                    else
                    {
                        mountedMogu->AI()->DoAction(ACTION_END_SECOND_COMBAT);
                        if (Creature* qiang = GetClosestCreatureWithEntry(me, MOB_QIANG, 200.0f))
                        {
                            if (qiang->AI())
                                qiang->AI()->DoAction(ACTION_END_SECOND_COMBAT);
                        }
                    }
                }

                if (Creature* subetai = GetClosestCreatureWithEntry(me, MOB_SUBETAI, 200.0f))
                {
                    if (subetai->AI())
                        subetai->AI()->DoAction(ACTION_BEFORE_COMBAT);
                }

                    for (auto moguArcher : moguArcherList)
                        moguArcher->AI()->DoAction(ACTION_BEFORE_COMBAT);
                    
                events.ScheduleEvent(EVENT_START_THIRD_COMBAT, 5000);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_VOLLEY:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_VOLLEY, false);
                            events.ScheduleEvent(EVENT_VOLLEY,       urand(10000, 20000));
                            break;
                        case EVENT_START_THIRD_COMBAT:
                            if (Creature* subetai = GetClosestCreatureWithEntry(me, MOB_SUBETAI, 200.0f))
                                if (subetai->AI())
                                    subetai->AI()->DoAction(ACTION_START_THIRD_COMBAT);
                            for (auto itr : moguArcherList)
                                itr->AI()->DoAction(ACTION_START_THIRD_COMBAT);
                            break;
                        default:
                            break;
                    }
                }
            }
        };
};

enum eMoguArcherSpells
{
    SPELL_SHOOT      = 119524
};

enum eMoguArcherEvents
{
    EVENT_SHOOT          = 1
};

class mob_mogu_archer : public CreatureScript
{
    public:
        mob_mogu_archer() : CreatureScript("mob_mogu_archer")
        {
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_mogu_archerAI(creature);
        }

        struct mob_mogu_archerAI : public ScriptedAI
        {
            mob_mogu_archerAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset()
            {
                me->SetDisplayId(11686);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

                events.Reset();
                events.ScheduleEvent(EVENT_SHOOT,    urand(5000, 12000));
            }

            void DoAction(int32 action)
            {
                switch (action)
                {
                    case ACTION_SET_GHOST_VISUAL:
                        me->AddAura(SPELL_INACTIVE, me);
                        break;
                    case ACTION_SET_NATIVE_DISPLAYID:
                        me->SetDisplayId(41498);
                        break;
                    case ACTION_BEFORE_COMBAT:
                        me->AddAura(SPELL_ACTIVATION_VISUAL, me);
                        break;
                    case ACTION_START_THIRD_COMBAT:
                        me->RemoveAurasDueToSpell(SPELL_ACTIVATION_VISUAL);
                        me->setFaction(14);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        break;
                    case ACTION_END_THIRD_COMBAT:
                        me->DespawnOrUnsummon();
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SHOOT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_SHOOT, false);
                            events.ScheduleEvent(EVENT_SHOOT,       25000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

#define SPELL_COWARDICE 119635

enum eMengEvents
{
    EVENT_START_FOURTH_COMBAT   = 1,
    EVENT_COWARDICE             = 2
};

class mob_meng : public CreatureScript
{
    public:
        mob_meng() : CreatureScript("mob_meng")
        {
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_mengAI(creature);
        }

        struct mob_mengAI : public ScriptedAI
        {
            mob_mengAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset()
            {
                me->SetDisplayId(11686);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

                events.Reset();
            }
            void DoAction(int32 action)
            {
                switch (action)
                {
                    case ACTION_SET_GHOST_VISUAL:
                        me->AddAura(SPELL_INACTIVE, me);
                        break;
                    case ACTION_SET_NATIVE_DISPLAYID:
                        me->SetDisplayId(41813);
                        break;
                    case ACTION_BEFORE_COMBAT:
                        me->AddAura(SPELL_ACTIVATION_VISUAL, me);
                        break;
                    case ACTION_START_FOURTH_COMBAT:
                        me->RemoveAurasDueToSpell(SPELL_ACTIVATION_VISUAL);
                        me->setFaction(14);
                        break;
                    case ACTION_END_FOURTH_COMBAT:
                        me->DespawnOrUnsummon();
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 diff)
            {
                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);
                
                std::list<Creature*> kingsGuardList;
                me->GetCreatureListWithEntryInGrid(kingsGuardList, NPC_KINGSGUARD, 200.0f);
                
                std::list<Creature*> moguArcherList;
                me->GetCreatureListWithEntryInGrid(moguArcherList, NPC_MOGU_ARCHER, 100.0f);

                for (auto moguArcher : moguArcherList)
                {
                    if (moguArcher->IsAlive() && moguArcher != me)
                        return;

                    else
                    {
                        moguArcher->AI()->DoAction(ACTION_END_THIRD_COMBAT);
                        if (Creature* subetai = GetClosestCreatureWithEntry(me, MOB_SUBETAI, 200.0f))
                        {
                            if (subetai->AI())
                                subetai->AI()->DoAction(ACTION_END_THIRD_COMBAT);
                        }
                    }
                }

                if (Creature* meng = GetClosestCreatureWithEntry(me, MOB_MENG, 200.0f))
                {
                    if (meng->AI())
                        meng->AI()->DoAction(ACTION_BEFORE_COMBAT);
                }

                    for (auto kingsGuard : kingsGuardList)
                        kingsGuard->AI()->DoAction(ACTION_BEFORE_COMBAT);
                    
                events.ScheduleEvent(EVENT_START_FOURTH_COMBAT, 5000);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_START_FOURTH_COMBAT:
                            if (Creature* meng = GetClosestCreatureWithEntry(me, MOB_MENG, 200.0f))
                                if (meng->AI())
                                    meng->AI()->DoAction(ACTION_START_FOURTH_COMBAT);
                            for (auto itr : kingsGuardList)
                                itr->AI()->DoAction(ACTION_START_FOURTH_COMBAT);
                            break;
                        case EVENT_COWARDICE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_COWARDICE, false);
                            events.ScheduleEvent(EVENT_COWARDICE,       25000);
                            break;
                        default:
                            break;
                    }
                }
            }
        };
};

enum eKingsguardSpells
{
    SPELL_ENRAGE             = 119629,
    SPELL_REFLECTIVE_SHIELDS = 119630
};

enum eKingsguardEvents
{
    EVENT_ENRAGE             = 1,
    EVENT_REFLECTIVE_SHIELDS = 2
};

class mob_kingsguard : public CreatureScript
{
    public:
        mob_kingsguard() : CreatureScript("mob_kingsguard")
        {
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_kingsguardAI(creature);
        }

        struct mob_kingsguardAI : public ScriptedAI
        {
            mob_kingsguardAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void JustDied(Unit* killer)
            {
                DoAction(ACTION_END_FOURTH_COMBAT);
                if (Creature* meng = GetClosestCreatureWithEntry(me, MOB_MENG, 200.0f))
                    if (meng->AI())
                        meng->AI()->DoAction(ACTION_END_FOURTH_COMBAT);
            }

            void Reset()
            {
                me->SetDisplayId(11686);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

                events.Reset();
                events.ScheduleEvent(EVENT_ENRAGE,    urand(5000, 12000));
                events.ScheduleEvent(EVENT_REFLECTIVE_SHIELDS,    urand(15000, 20000));
            }

            void DoAction(int32 action)
            {
                switch (action)
                {
                    case ACTION_SET_GHOST_VISUAL:
                        me->AddAura(SPELL_INACTIVE, me);
                        break;
                    case ACTION_SET_NATIVE_DISPLAYID:
                        me->SetDisplayId(41498);
                        break;
                    case ACTION_BEFORE_COMBAT:
                        me->AddAura(SPELL_ACTIVATION_VISUAL, me);
                        break;
                    case ACTION_START_FOURTH_COMBAT:
                        me->RemoveAurasDueToSpell(SPELL_ACTIVATION_VISUAL);
                        me->setFaction(14);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        break;
                    case ACTION_END_FOURTH_COMBAT:
                        me->DespawnOrUnsummon();
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_ENRAGE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_ENRAGE, false);
                            events.ScheduleEvent(EVENT_ENRAGE,       25000);
                            break;
                        case EVENT_REFLECTIVE_SHIELDS:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_REFLECTIVE_SHIELDS, false);
                            events.ScheduleEvent(EVENT_REFLECTIVE_SHIELDS,       40000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

void AddSC_mogu_shan_vault()
{
    new mob_cursed_mogu_sculture();
    new mob_enormous_stone_quilen();
    new mob_stone_quilen();
    new mob_zandalari_skullcharger();
    new spell_mogu_petrification();
    new npc_lorewalker_cho();
    new mob_sorcerer_mogu();
    new mob_mogu_archer();
    new mob_mounted_mogu();
    new mob_kingsguard();
    new mob_subetai();
    new mob_meng();
    new mob_zian();
    new mob_qiang();
}