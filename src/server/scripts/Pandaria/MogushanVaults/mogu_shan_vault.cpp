/*
 * Copyright 2021 FuzionCore Project
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

enum eSpells
{
    SPELL_SPIRIT_BOLT               = 121224,
    SPELL_GROUND_SLAM               = 121087,
    SPELL_PETRIFICATION             = 125090,
    SPELL_PETRIFIED                 = 125092,
    SPELL_FULLY_PETRIFIED           = 115877,
    SPELL_MONSTROUS_BITE            = 125096,
    SPELL_SUNDERING_BITE            = 116970,
    SPELL_PROTECTIVE_FENZY          = 116982,
    SPELL_SHATTERING_STONE          = 116977,
    SPELL_FOCUSED_ASSAULT           = 116990,
    SPELL_POSE_1                    = 120650,
    SPELL_POSE_2                    = 120613,
    SPELL_STONE                     = 120663,
    SPELL_BRONZE                    = 120661,
    SPELL_GHOST_ESSENCE             = 120764,
    SPELL_INACTIVE                  = 118205,
    SPELL_ACTIVATION_VISUAL         = 118212,
    SPELL_CHARGED_SHADOWS           = 117685,
    SPELL_SHADOW_BLAST              = 119365,
    SPELL_ANNIHILATE                = 119521,
    SPELL_COWARDICE                 = 119635,
    SPELL_VOLLEY                    = 119554,
    SPELL_TROLL_RUSH                = 116006,
    SPELL_CRUSHING_ATTACKS          = 119514,
    SPELL_SHOOT                     = 119524,
    SPELL_ENRAGE                    = 119629,
    SPELL_REFLECTIVE_SHIELDS        = 119630,
    SPELL_FLESH_TO_STONE            = 118552,
    SPELL_STONE_BLOCK               = 118529,
    SPELL_FORCEFUL_SWING            = 126955,
    SPELL_TOUCH_OF_NALAK_SHA        = 126958,
    SPELL_WARDEN_S_FURY             = 126970,
    SPELL_ENHANCED_RECONSTRUCTION   = 126980,
    SPELL_RECONSTRUCTING            = 126985
};

enum eEvents
{
    EVENT_CURSED_MOGU_SPIRIT_BOLT,
    EVENT_CURSED_MOGU_GROUND_SLAM,
    EVENT_CURSED_MOGU_ATTACK,
    EVENT_ENORMOUS_QUILEN_BITE,
    EVENT_QUILEN_SUNDERING_BITE,
    EVENT_QUILEN_SHATTERING_STONE,
    EVENT_QUILEN_FOCUSED_ASSAULT,
    EVENT_ZANDALARI_TROLL_RUSH,
    EVENT_ZIAN_CHARGED_SHADOWS,
    EVENT_SORCERER_SHADOW_BLAST,
    EVENT_QIANG_ANNIHILATE,
    EVENT_QIANG_START_SECOND_FIGHT,
    EVENT_MOUNTED_MOGU_CRUSHING_ATTACKS,
    EVENT_SUBETAI_VOLLEY,
    EVENT_SUBETAI_START_THIRD_COMBAT,
    EVENT_MOGU_ARCHER_SHOOT,
    EVENT_MENG_START_FOURTH_COMBAT,
    EVENT_MENG_COWARDICE,
    EVENT_KINGS_GUARD_ENRAGE,
    EVENT_KINGS_GUARD_REFLECTIVE_SHIELDS,
    EVENT_SECRET_FLESH_TO_STONE,
    EVENT_SECRET_STONE_BLOCK,
    EVENT_WARDEN_FORCEFUL_SWING,
    EVENT_WARDEN_TOUCH_OF_NALAK_SHA,
    EVENT_WARDEN_WARDEN_S_FURY,
    EVENT_KEEPER_ENHANCED_RECONSTRUCTION,
    EVENT_KEEPER_RECONSTRUCTING
};

enum eEquipIds
{
    EQUIP_ZIAN_STAFF            = 76369,
    EQUIP_QIANG_POLEARM         = 86777,
    EQUIP_MOUNTED_MOGU_WEAPON   = 80132,
    EQUIP_SUBETAI_SWORD         = 80283,
    EQUIP_SUBETAI_BOW           = 60790
};

enum eTrashsActions
{
    ACTION_CURSED_MOGU_ATTACK_PLAYER = 1
};

void StartNextFight(uint32 p_PreviousAdd, uint32 p_NextAdd, uint32 p_PreviousBoss, uint32 p_NextBoss, uint32 p_Action, uint32 /*p_NextAction*/, Creature* me)
{
    std::list<Creature*> l_CreatureList;
    me->GetCreatureListWithEntryInGrid(l_CreatureList, p_PreviousAdd, 200.0f);

    for (Creature* l_Creature : l_CreatureList)
    {
        if (l_Creature->IsAlive() && l_Creature == me)
            return;
    }

    me->AI()->DoAction(p_Action);

    if (Creature* l_Boss = GetClosestCreatureWithEntry(me, p_PreviousBoss, 200.0f))
    {
        if (l_Boss->GetAI())
            l_Boss->AI()->DoAction(p_Action);
    }

    l_CreatureList.clear();
    me->GetCreatureListWithEntryInGrid(l_CreatureList, p_NextAdd, 200.0f);

    for (Creature* l_Creature : l_CreatureList)
        l_Creature->AI()->DoAction(ACTION_BEFORE_COMBAT);

    if (Creature* l_Boss = GetClosestCreatureWithEntry(me, p_NextBoss, 200.0f))
    {
        if (l_Boss->GetAI())
            l_Boss->AI()->DoAction(ACTION_BEFORE_COMBAT);
    }
}

// 61334 / 61989 - Cursed Mogu Sculpture
class mob_cursed_mogu_sculpture : public CreatureScript
{
    public:
        mob_cursed_mogu_sculpture() : CreatureScript("mob_cursed_mogu_sculture") {}

        struct mob_cursed_mogu_sculptureAI : public ScriptedAI
        {
            mob_cursed_mogu_sculptureAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            InstanceScript* pInstance;
            EventMap events;
            bool activationDone;
            ObjectGuid playerActivate;

            Creature* GetCho()
            {
                if (pInstance)
                    return pInstance->GetCreature(NPC_LOREWALKER_CHO);
                else
                    return NULL;
            }

            void Reset() override
            {
                events.Reset();

                playerActivate = ObjectGuid::Empty;
                activationDone = false;

                me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE));
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->SetReactState(REACT_PASSIVE);
                me->AI()->SetCanSeeEvenInPassiveMode(true);
                me->RemoveAurasDueToSpell(SPELL_GHOST_ESSENCE);

                switch (me->GetEntry())
                {
                    case NPC_CURSED_MOGU_SCULPTURE_1:
                        me->AddAura(SPELL_POSE_1, me);
                        me->AddAura(SPELL_STONE, me);
                        break;
                    case NPC_CURSED_MOGU_SCULPTURE_2:
                        me->AddAura(SPELL_POSE_2, me);
                        me->AddAura(SPELL_BRONZE, me);
                        break;
                    default:
                        break;
                }
            }

            void EnterCombat(Unit* /*p_Attacker*/) override
            {
                events.Reset();
                events.ScheduleEvent(EVENT_CURSED_MOGU_SPIRIT_BOLT, 15000);
                events.ScheduleEvent(EVENT_CURSED_MOGU_GROUND_SLAM, 25000);
                if (me->GetEntry() == NPC_CURSED_MOGU_SCULPTURE_1)
                    events.ScheduleEvent(EVENT_CURSED_MOGU_ATTACK,  2000);
            }

            void MoveInLineOfSight(Unit* who) override
            {
                if (!pInstance)
                    return;

                if (!who->IsWithinDist(me, 15.0f))
                    return;

                if (who->IsPlayer())
                {
                    playerActivate = who->GetGUID();
                    switch (me->GetEntry())
                    {
                        case NPC_CURSED_MOGU_SCULPTURE_2:
                        {
                            if (activationDone)
                                return;

                            if (pInstance)
                                if (Creature* ghostEssence = pInstance->GetCreature(NPC_GHOST_ESSENCE))
                                    ghostEssence->CastSpell(ghostEssence, SPELL_GHOST_ESSENCE, false);
                            break;
                        }
                        case NPC_CURSED_MOGU_SCULPTURE_1:
                        {
                            me->SetReactState(REACT_AGGRESSIVE);
                            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE));
                            me->RemoveAurasDueToSpell(SPELL_BRONZE);
                            me->RemoveAurasDueToSpell(SPELL_POSE_2);
                            me->RemoveAurasDueToSpell(SPELL_POSE_1);
                            me->RemoveAurasDueToSpell(SPELL_STONE);
                            break;
                        }
                    default:
                        break;
                    }

                    activationDone = true;
                }
            }

            void JustDied(Unit* /*p_Killer*/) override
            {
                if (!GetClosestCreatureWithEntry(me, me->GetEntry(), 20.0f, true) && me->GetEntry() == NPC_CURSED_MOGU_SCULPTURE_2)
                {
                    if (Creature* lorewalkerCho = GetClosestCreatureWithEntry(me, NPC_LOREWALKER_CHO, 50.0f, true))
                        lorewalkerCho->AI()->DoAction(ACTION_CONTINUE_ESCORT);
                }
                else if (!GetClosestCreatureWithEntry(me, me->GetEntry(), 50.0f, true) && me->GetEntry() == NPC_CURSED_MOGU_SCULPTURE_1)
                {
                    if (Creature* Feng = GetClosestCreatureWithEntry(me, NPC_FENG, 100.0f, true))
                        Feng->AI()->Talk(7);

                    if (Creature* lorewalkerCho = GetClosestCreatureWithEntry(me, NPC_LOREWALKER_CHO, 100.0f, true))
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

            void DoAction(const int32 action) override
            {
                if (action == ACTION_CURSED_MOGU_ATTACK_PLAYER)
                    if (Player* plr = ObjectAccessor::FindPlayer(playerActivate))
                        me->AI()->AttackStart(plr);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 id = events.ExecuteEvent())
                {
                    switch (id)
                    {
                        case EVENT_CURSED_MOGU_ATTACK:
                            DoAction(ACTION_CURSED_MOGU_ATTACK_PLAYER);
                            break;
                        case EVENT_CURSED_MOGU_SPIRIT_BOLT:
                            if (Unit* target = me->SelectNearestTarget(5.0f))
                                if (!target->IsFriendlyTo(me))
                                    me->CastSpell(target, SPELL_SPIRIT_BOLT, false);

                            events.ScheduleEvent(EVENT_CURSED_MOGU_SPIRIT_BOLT, 15000);
                            break;
                        case EVENT_CURSED_MOGU_GROUND_SLAM:
                            if (Unit* target = me->SelectNearestTarget(5.0f))
                                if (!target->IsFriendlyTo(me))
                                    me->CastSpell(target, SPELL_GROUND_SLAM, false);

                            events.ScheduleEvent(EVENT_CURSED_MOGU_GROUND_SLAM, 25000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_cursed_mogu_sculptureAI(creature);
        }
};

// Ghost Essence - 120764
class spell_ghost_essence : public SpellScript
{
    PrepareSpellScript(spell_ghost_essence);

    void HandleHitTarget(SpellEffIndex /*effIndex*/)
    {
        if (Creature* target = GetHitCreature())
        {
            target->SetReactState(REACT_AGGRESSIVE);
            target->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
            target->RemoveAurasDueToSpell(SPELL_BRONZE);
            target->RemoveAurasDueToSpell(SPELL_POSE_2);
            target->RemoveAurasDueToSpell(SPELL_POSE_1);
            target->RemoveAurasDueToSpell(SPELL_STONE);

            if (target->IsAIEnabled)
                target->GetAI()->DoAction(ACTION_CURSED_MOGU_ATTACK_PLAYER);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_ghost_essence::HandleHitTarget, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};

float quilenNewY[2] = { 1170.0f, 1240.0f };

// 64183 - Enormous Stone Quilen
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
                if (me->IsAlive())
                {
                    if (me->GetPositionX() > 3900)
                        prevPosition = 2;

                    nextMovementTimer = 0;
                    me->SetWalk(true);
                    me->GetMotionMaster()->MovePoint(prevPosition, me->GetPositionX(), quilenNewY[prevPosition - 1], me->GetPositionZ());
                }
            }

            InstanceScript* pInstance;
            EventMap events;
            uint32 nextMovementTimer;
            uint8 prevPosition;

            void Reset() override
            {
                events.ScheduleEvent(EVENT_ENORMOUS_QUILEN_BITE, urand(3000, 5000));
            }

            void JustReachedHome() override
            {
                prevPosition = 1;

                if (me->GetPositionX() > 3900)
                    prevPosition = 2;

                nextMovementTimer = 0;
                me->SetWalk(true);
                me->GetMotionMaster()->MovePoint(prevPosition, me->GetPositionX(), quilenNewY[prevPosition - 1], me->GetPositionZ());
            }

            void MovementInform(uint32 typeId, uint32 pointId) override
            {
                if (typeId != POINT_MOTION_TYPE)
                    return;

                if (me->IsInCombat())
                    return;

                prevPosition = pointId;
                nextMovementTimer = 500;
            }

            void EnterCombat(Unit* /*p_Attacker*/) override
            {
                me->SetWalk(false);
            }

            void UpdateAI(const uint32 diff) override
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
                        case EVENT_ENORMOUS_QUILEN_BITE:
                        {
                            if (Unit* target = me->SelectNearestTarget(5.0f))
                            {
                                if (!target->IsFriendlyTo(me))
                                    me->CastSpell(target, SPELL_MONSTROUS_BITE, true);
                            }
                            events.ScheduleEvent(EVENT_ENORMOUS_QUILEN_BITE, urand(6000, 8000));
                            break;
                        }
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_enormous_stone_quilenAI(creature);
        }
};

// 60576 - Stone Quilen
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

            void Reset() override
            {
                events.Reset();
            }

            void JustDied(Unit* /*killer*/) override
            {
                events.Reset();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                events.ScheduleEvent(EVENT_QUILEN_SUNDERING_BITE,   urand(5000,  6000));
                events.ScheduleEvent(EVENT_QUILEN_SHATTERING_STONE, urand(10000, 12000));
                events.ScheduleEvent(EVENT_QUILEN_FOCUSED_ASSAULT,  urand(500,   5000));

            }

            void UpdateAI(const uint32 /*p_Diff*/) override
            {
                if (!UpdateVictim())
                    return;

                if (!me->HasAura(SPELL_PROTECTIVE_FENZY) && me->HealthBelowPct(10))
                    me->CastSpell(me, SPELL_PROTECTIVE_FENZY, true);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_QUILEN_SUNDERING_BITE:
                        {
                            if (Unit* target = me->SelectNearestTarget(5.0f))
                                me->CastSpell(target, SPELL_SUNDERING_BITE, true);

                            events.ScheduleEvent(EVENT_QUILEN_SUNDERING_BITE, urand(5000, 6000));
                            break;
                        }
                        case EVENT_QUILEN_SHATTERING_STONE:
                        {
                            if (Unit* target = me->SelectNearestTarget(5.0f))
                                me->CastSpell(target, SPELL_SHATTERING_STONE, true);

                            events.ScheduleEvent(EVENT_QUILEN_SHATTERING_STONE, urand(10000, 12000));
                            break;
                        }
                        case EVENT_QUILEN_FOCUSED_ASSAULT:
                        {
                            if (Unit* target = me->SelectNearestTarget(5.0f))
                                me->AddAura(SPELL_FOCUSED_ASSAULT, target);

                            events.ScheduleEvent(EVENT_QUILEN_FOCUSED_ASSAULT,  urand(500, 5000));
                            break;
                        }
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_stone_quilenAI(creature);
        }
};

// 60375 - Zandalari Skullcharger
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

            void Reset() override
            {
                events.Reset();
                if (me->GetEntry() == NPC_ZANDALARI_SKULLCHARGER)
                    events.ScheduleEvent(EVENT_ZANDALARI_TROLL_RUSH, urand(5000, 6000));
            }

            void EnterCombat(Unit* /*p_Attacker*/) override
            {
                if (Creature* lorewalkerCho = GetClosestCreatureWithEntry(me, NPC_LOREWALKER_CHO, 150.0f, true))
                    if (lorewalkerCho->AI())
                        lorewalkerCho->AI()->DoAction(ACTION_SAY_ZANDALARI_BEGIN);
            }

            void JustDied(Unit* /*p_Killer*/) override
            {
                Creature* skullcharger = GetClosestCreatureWithEntry(me, NPC_ZANDALARI_SKULLCHARGER, 80.0f, true);
                Creature* infiltrator  = GetClosestCreatureWithEntry(me, NPC_ZANDALARI_INFILTRATOR,  80.0f, true);
                Creature* firedancer   = GetClosestCreatureWithEntry(me, NPC_ZANDALARI_FIREDANCER,   80.0f, true);
                if (skullcharger || infiltrator || firedancer)
                    return;

                if (Creature* lorewalkerCho = GetClosestCreatureWithEntry(me, NPC_LOREWALKER_CHO, 150.0f, true))
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

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim() || me->GetEntry() != NPC_ZANDALARI_SKULLCHARGER)
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_ZANDALARI_TROLL_RUSH:
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST))
                            {
                                me->CastSpell(target, SPELL_TROLL_RUSH, true);
                                me->GetMotionMaster()->MoveChase(target);
                            }

                            events.ScheduleEvent(EVENT_ZANDALARI_TROLL_RUSH, urand(5000, 6000));
                            break;
                        }
                        default:
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_zandalari_skullchargerAI(creature);
        }
};

// 125092 - Petrification
class spell_mogu_petrification : public SpellScriptLoader
{
    public:
        spell_mogu_petrification() : SpellScriptLoader("spell_mogu_petrification") { }

        class spell_mogu_petrification_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mogu_petrification_AuraScript);

            uint32 stack;

            void OnApply(AuraEffect const* /*p_AurEff*/, AuraEffectHandleModes /*mode*/)
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

            void Register() override
            {
                OnEffectApply += AuraEffectApplyFn(spell_mogu_petrification_AuraScript::OnApply, EFFECT_0, SPELL_AURA_MOD_DECREASE_SPEED, AURA_EFFECT_HANDLE_REAPPLY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_mogu_petrification_AuraScript();
        }
};

#define GOSSIP_CHOICE_1 "What are you waiting for ? Let's go investigate !"
#define GOSSIP_CHOICE_2 "Go ahead and turn this thing on."

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
    EVENT_START_FIRST_COMBAT = 1,
    EVENT_TALK_1             = 2,
    EVENT_TALK_2             = 3,
    EVENT_TALK_3             = 4,
    EVENT_TALK_4             = 5,
    EVENT_TALK_5             = 6,
    EVENT_TALK_6             = 7,
    EVENT_TALK_7             = 8,
    EVENT_TALK_8             = 9,
    EVENT_TALK_9             = 10,
    EVENT_TALK_10            = 11,
    EVENT_TALK_11            = 12,
    EVENT_TALK_12            = 13
};

// 61348 - Lorewalker Cho
class npc_lorewalker_cho : public CreatureScript
{
    public:
        npc_lorewalker_cho() : CreatureScript("npc_lorewalker_cho") { }

        enum eMisc
        {
            MogushanSecondPart = 528
        };

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            if (creature->GetPositionX() >= 4292.0f && creature->GetPositionX() <= 4294.0f && creature->GetPositionY() >= 1533.0f && creature->GetPositionY() <= 1533.1f)
            {
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_CHOICE_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                SendGossipMenuFor(player, 30003, creature->GetGUID());
            }

            if (creature->GetPositionX() >= 4022.0f && creature->GetPositionX() <= 4023.0f && creature->GetPositionY() >= 1859.0f && creature->GetPositionY() <= 1860.0f)
            {
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_CHOICE_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                SendGossipMenuFor(player, 30008, creature->GetGUID());
            }

            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
        {
            player->PlayerTalkClass->ClearMenus();

            // Launching event before Spirit Kings
            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                CloseGossipMenuFor(player);
                creature->AI()->DoAction(ACTION_CONTINUE_ESCORT);
            }

            // Launching encounter versus Elegon
            if (action == GOSSIP_ACTION_INFO_DEF + 2)
            {
                CloseGossipMenuFor(player);
                creature->AI()->DoAction(ACTION_ELEGON_GOB_ACTIVATION);
            }

            return true;
        }

        struct npc_lorewalker_choAI : public EscortAI
        {
            npc_lorewalker_choAI(Creature* creature) : EscortAI(creature)
            {
                pInstance = creature->GetInstanceScript();
                SetMaxPlayerDistance(200.0f);
            }

            bool hasSaidIntro;
            bool needToSayStoneGuardDone;
            bool hasSaidStoneguardDeath;
            bool needToSayFengDone;
            bool hasSaidZandalariBegin;
            bool hasSaidZandalariDeath;
            bool hasSaidSecretsKeeperCombat;
            bool hasSaidKeeperDied;
            bool eventInProgress;
            InstanceScript* pInstance;
            EventMap events;

            void Reset() override
            {
                events.Reset();
                SetDespawnAtFar(false);
                SetDespawnAtEnd(false);
                hasSaidIntro = false;
                needToSayStoneGuardDone = true;
                hasSaidStoneguardDeath = false;
                needToSayFengDone = true;
                hasSaidZandalariBegin = false;
                hasSaidZandalariDeath = false;
                hasSaidSecretsKeeperCombat = false;
                hasSaidKeeperDied = false;
                eventInProgress = false;

                /// Setup escort state at Spirit Kings in second LFR part
                /*if (IsLFR())
                {
                    Map::PlayerList const& l_PlrList = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator l_Itr = l_PlrList.begin(); l_Itr != l_PlrList.end(); ++l_Itr)
                    {
                        if (Player* l_Player = l_Itr->GetSource())
                        {
                            uint32 l_DungeonID = l_Player->GetGroup() ? sLFGMgr->GetDungeon(l_Player->GetGroup()->GetGUID()) : 0;
                            if (!l_DungeonID)
                                continue;

                            if (l_DungeonID == eMisc::MogushanSecondPart)
                            {
                                hasSaidIntro = true;
                                Start(false, true, l_Player->GetGUID());

                                if (GetClosestCreatureWithEntry(me, MOB_MENG, 200.0f, true))
                                {
                                    me->SetOrientation(4.68f);
                                    me->SetFacingTo(4.68f);
                                    me->AddNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                                    SetEscortPaused(true);
                                }

                                /// After Spirit Kings event
                                SetNextWaypoint(39);
                            }
                        }
                    }
                }*/
            }

            void MoveInLineOfSight(Unit* who) override
            {
                if (hasSaidIntro || who->GetTypeId() != TYPEID_PLAYER)
                    return;

                if (me->IsWithinDistInMap(who, 50.0f))
                {
                    Talk(INTRO_01);
                    hasSaidIntro = true;
                    Start(false, true, who->GetGUID());
                }
            }

            void WaypointReached(uint32 waypointId) override
            {
                Player* player = GetPlayerForEscort();
                if (!player)
                    return;

                switch (waypointId)
                {
                    // Intro Stone Guard
                    case 0:
                    {
                        if (pInstance->GetBossState(DATA_STONE_GUARD) != DONE)
                            Talk(INTRO_02);
                        break;
                    }
                    // Waiting point until Stone Guard is done
                    case 3:
                    {
                        if (needToSayStoneGuardDone)
                            Talk(INTRO_03);
                        SetEscortPaused(true);
                        SetRun(true);
                        if (pInstance->GetBossState(DATA_STONE_GUARD) == DONE)
                            DoAction(ACTION_OPEN_STONEGUARD_DOOR);
                        break;
                    }
                    // Moving outside of the Stone Guard room
                    case 6:
                        if (needToSayStoneGuardDone)
                            Talk(INTRO_06);
                        break;
                    // Before the 2 first Cursed Mogu Sculptures
                    case 9:
                    {
                        if (GetClosestCreatureWithEntry(me, NPC_CURSED_MOGU_SCULPTURE_2, 100.0f))
                            SetEscortPaused(true);
                        break;
                    }
                    case 10:
                    {
                        if (needToSayStoneGuardDone)
                            Talk(INTRO_07);
                        break;
                    }
                    // Before the line of 5 Cursed Mogu Sculptures, in front of Feng
                    case 12:
                    {
                        if (GetClosestCreatureWithEntry(me, NPC_CURSED_MOGU_SCULPTURE_1, 50.0f, true))
                            SetEscortPaused(true);
                        break;
                    }
                    // Waiting until Feng is done
                    case 13:
                    {
                        if (pInstance->GetBossState(DATA_FENG) != DONE)
                        {
                            Talk(FENG_01);
                            SetEscortPaused(true);
                        }
                        else
                            needToSayFengDone = false;
                        break;
                    }
                    // If the trash before Garajal are done, we don't go on the left side
                    case 18:
                    {
                        /*Creature* skullcharger = GetClosestCreatureWithEntry(me, NPC_ZANDALARI_SKULLCHARGER, 100.0f, true);
                        Creature* infiltrator  = GetClosestCreatureWithEntry(me, NPC_ZANDALARI_INFILTRATOR,  100.0f, true);
                        Creature* firedancer   = GetClosestCreatureWithEntry(me, NPC_ZANDALARI_FIREDANCER,   100.0f, true);
                        if (!skullcharger && !infiltrator && !firedancer)
                            SetNextWaypoint(20);*/
                        break;
                    }
                    // Going on left side and waiting for the trash before Garajal to be done
                    case 19:
                    {
                        if (needToSayFengDone)
                            Talk(FENG_03);
                        SetEscortPaused(true);
                        break;
                    }
                    // Waiting until Garajal is done
                    case 21:
                    {
                        if (pInstance->GetBossState(DATA_GARAJAL) != DONE)
                            SetEscortPaused(true);
                        break;
                    }
                    // Gossip to trigger the event before spirit kings
                    case 38:
                    {
                        if (GetClosestCreatureWithEntry(me, MOB_MENG, 200.0f, true))
                        {
                            me->SetOrientation(4.68f);
                            me->SetFacingTo(4.68f);
                            me->AddNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                            SetEscortPaused(true);
                        }
                        break;
                    }
                    case 39:
                        me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                        break;
                    // Stop and wait for the event, and the for the spirit kings, to be done before restarting
                    case 42:
                    {
                        Creature* mobMeng   = GetClosestCreatureWithEntry(me, MOB_MENG,  200.0f, true);
                        Creature* kingQiang = GetClosestCreatureWithEntry(me, NPC_QIANG, 200.0f, true);
                        // If either event and/or Spirit Kings need to be done
                        if (mobMeng || kingQiang)
                        {
                            me->SetOrientation(1.51f);
                            me->SetFacingTo(1.51f);
                            SetEscortPaused(true);
                            Talk(SPIRIT_KINGS_01);

                            if (mobMeng)
                            {
                                eventInProgress = true;
                                uint32 moguList[4] = {NPC_SORCERER_MOGU, NPC_MOUNTED_MOGU, NPC_MOGU_ARCHER, NPC_KINGSGUARD};

                                for (uint8 i = 0; i < 4; ++i)
                                {
                                    std::list<Creature*> mobList;
                                    me->GetCreatureListWithEntryInGrid(mobList, moguList[i], 100.0f);

                                    for (auto itr : mobList)
                                    {
                                        itr->AI()->DoAction(ACTION_SET_NATIVE_DISPLAYID);
                                        itr->AI()->DoAction(ACTION_SET_GHOST_VISUAL);
                                        if (itr->GetEntry() == NPC_SORCERER_MOGU)
                                        {
                                            itr->AI()->DoAction(ACTION_BEFORE_COMBAT);
                                            events.ScheduleEvent(EVENT_START_FIRST_COMBAT, 4000);
                                        }
                                    }
                                }
                                uint32 mobKings[4] = {MOB_ZIAN, MOB_MENG, MOB_QIANG, MOB_SUBETAI};

                                for (uint8 i = 0; i < 4; ++i)
                                {
                                    if (Creature* king = GetClosestCreatureWithEntry(me, mobKings[i], 200.0f))
                                    {
                                        king->AI()->DoAction(ACTION_SET_GHOST_VISUAL);
                                        king->AI()->DoAction(ACTION_SET_NATIVE_DISPLAYID);
                                        
                                        if (king->GetEntry() == MOB_ZIAN)
                                        {
                                            king->AI()->DoAction(ACTION_BEFORE_COMBAT);
                                        }
                                    }
                                }
                            }
                        }
                        else
                        {
                            if (GameObject* wall = GetClosestGameObjectWithEntry(me, GOB_SPIRIT_KINGS_EXIT, 100.0f))
                                if (wall->GetGoState() == GO_STATE_READY)
                                    wall->SetGoState(GO_STATE_ACTIVE);

                            // If there're no spirit kings still alive (meaning they're vainquished) with wrong BossState, we change it
                            if (pInstance)
                            {
                                if (pInstance->GetBossState(DATA_SPIRIT_KINGS) == NOT_STARTED)
                                {
                                    pInstance->SetBossState(DATA_SPIRIT_KINGS, DONE);
                                    pInstance->SaveToDB();
                                }
                            }
                        }
                        break;
                    }
                    // Saying a passage has appeared in the wall
                    case 43:
                    {
                        Talk(18);
                        break;
                    }
                    case 48:
                    {
                        if (pInstance->GetBossState(DATA_ELEGON) != DONE)
                            Talk(19);
                        break;
                    }
                    // Downstairs, entrance of the last part of the vault - waiting for the trash to be done
                    case 53:
                    {
                        if (GetClosestCreatureWithEntry(me, NPC_MOGU_SECRET_KEEPER, 50.0f, true))
                        {
                            SetEscortPaused(true);
                            Talk(20);
                        }
                        break;
                    }
                    // Crossroads between Elegon and Will Of Emperor : if Elegon is done, we directly go to WOE
                    case 56:
                    {
                        /*if (pInstance->GetBossState(DATA_ELEGON) == DONE)
                            SetNextWaypoint(83);*/
                        break;
                    }
                    // Opening Elegon's door
                    case 60:
                        if (GameObject* door = pInstance->GetGameObject(GOB_ELEGON_DOOR_ENTRANCE))
                            if (door->GetGoState() == GO_STATE_READY)
                                door->SetGoState(GO_STATE_ACTIVE);
                        break;
                    // Stopping for the mob in the stairway to Elegon - waiting for thrash to be done
                    case 62:
                    {
                        if (GetClosestCreatureWithEntry(me, NPC_MOGUSHAN_WARDEN, 100.0f, true))
                            SetEscortPaused(true);
                        break;
                    }
                    // Trash in front of Elegon's console
                    case 67:
                    {
                        if (GetClosestCreatureWithEntry(me, NPC_MOGUSHAN_ENGINE_KEEPER, 300.0f, true) ||
                            GetClosestCreatureWithEntry(me, NPC_MOGUSHAN_ARCANIST,      300.0f, true) ||
                            GetClosestCreatureWithEntry(me, NPC_MOGUSHAN_WARDEN,        300.0f, true) ||
                            GetClosestCreatureWithEntry(me, NPC_MOGUSHAN_WARDEN_2,      300.0f, true))
                        {
                            SetEscortPaused(true);
                            Talk(23);
                        }
                        break;
                    }
                    // Moving to Elegon's console
                    case 69:
                        if (pInstance->GetBossState(DATA_ELEGON) != DONE)
                            Talk(24);
                        break;
                    // Gossip to trigger Elegon's console
                    case 70:
                    {
                        if (pInstance->GetBossState(DATA_ELEGON) != DONE)
                        {
                            me->AddNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                            SetEscortPaused(true);
                        }
                        break;
                    }
                    // Hiding until Elegon is done
                    case 71:
                    {
                        if (pInstance->GetBossState(DATA_ELEGON) != DONE)
                        {
                            me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                            SetEscortPaused(true);
                        }
                        break;
                    }
                    case 72:
                        events.ScheduleEvent(EVENT_TALK_1, 1000);
                        break;
                    // Opening door to Elegon or Will of Emperor
                    case 79:
                    case 83:
                    {
                        if (GameObject* door = pInstance->GetGameObject(waypointId == 79 ? GOB_ELEGON_DOOR_ENTRANCE : GOB_WILL_OF_EMPEROR_ENTRANCE))
                            if (door->GetGoState() == GO_STATE_READY)
                                door->SetGoState(GO_STATE_ACTIVE);
                        break;
                    }
                    case 86:
                    {
                        if (GetClosestCreatureWithEntry(me, NPC_MOGU_SECRET_KEEPER, 50.0f, true))
                            SetEscortPaused(true);
                        break;
                    }
                    case 88:
                        events.ScheduleEvent(EVENT_TALK_6, 1000);
                        break;
                    default:
                        break;
                }
            }

            void DoAction(const int32 action) override
            {
                switch (action)
                {
                    case ACTION_CONTINUE_ESCORT:
                    {
                        SetEscortPaused(false);
                        break;
                    }
                    case ACTION_RUN:
                    {
                        SetRun(true);
                        break;
                    }
                    case ACTION_SAY_ZANDALARI_BEGIN:
                    {
                        if (!hasSaidZandalariBegin)
                        {
                            Talk(ZANDALARI_01);
                            hasSaidZandalariBegin = true;
                        }
                        break;
                    }
                    case ACTION_SAY_ZANDALARI_DEATH:
                    {
                        if (!hasSaidZandalariDeath)
                        {
                            Talk(ZANDALARI_02);
                            hasSaidZandalariDeath = true;
                        }
                        break;
                    }
                    case ACTION_KEEPER_ENTER_COMBAT:
                    {
                        if (!hasSaidSecretsKeeperCombat)
                        {
                            Talk(21);
                            hasSaidSecretsKeeperCombat = true;
                        }
                        break;
                    }
                    case ACTION_KEEPER_DIED:
                    {
                        if (!hasSaidKeeperDied)
                        {
                            Talk(22);
                            SetEscortPaused(false);
                            hasSaidKeeperDied = true;
                        }
                        break;
                    }
                    case ACTION_ELEGON_GOB_ACTIVATION:
                    {
                        // Previous boss not done
                        if (!pInstance->CheckRequiredBosses(DATA_ELEGON))
                            break;
                        else
                        {
                            Talk(25);
                            // Activating console
                            if (GameObject* button = pInstance->GetGameObject(GOB_CELESTIAL_COMMAND))
                            {
                                if (button->GetGoState() == GO_STATE_READY)
                                {
                                    button->Use(me);
                                    button->SetGoState(GO_STATE_ACTIVE);
                                    button->AddFlag(GO_FLAG_NOT_SELECTABLE);
                                }
                            }
                        }
                        break;
                    }
                    case ACTION_TALK_WILL_OF_EMPEROR:
                    {
                        Talk(39);
                        break;
                    }
                    case ACTION_EMPERORS_DEATH:
                    {
                        events.ScheduleEvent(EVENT_TALK_11, 1000);
                        break;
                    }
                    case ACTION_OPEN_STONEGUARD_DOOR:
                    {
                        DoAction(ACTION_CONTINUE_ESCORT);
                        Talk(INTRO_05);
                        hasSaidStoneguardDeath = true;
                        break;
                    }
                    case ACTION_EVENT_WIPE:
                    {
                        uint32 eventMobs[4] = {NPC_SORCERER_MOGU, NPC_MOUNTED_MOGU, NPC_MOGU_ARCHER, NPC_KINGSGUARD};
                        uint32 eventKing[4] = {MOB_ZIAN,          MOB_QIANG,        MOB_SUBETAI,     MOB_MENG};

                        for (uint8 i = 0; i < 4; ++i)
                        {
                            std::list<Creature*> mobList;
                            GetCreatureListWithEntryInGrid(mobList, me, eventMobs[i], 200.0f);

                            Creature* king = GetClosestCreatureWithEntry(me, eventKing[i], 200.0f);
                            if (!king)
                                king = GetClosestCreatureWithEntry(me, eventKing[i], 200.0f, false);

                            if (king)
                                king->Respawn(true);

                            for (Creature* mob : mobList)
                                mob->Respawn(true);

                            me->Respawn(true);
                        }
                        break;
                    }
                    default:
                        break;
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                EscortAI::UpdateAI(diff);

                // Wipe on event: reset all trashs of the events
                if (pInstance)
                {
                    if (pInstance->IsWipe() && eventInProgress)
                    {
                        eventInProgress = false;
                        DoAction(ACTION_EVENT_WIPE);
                        return;
                    }
                }

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_START_FIRST_COMBAT:
                        {
                            if (Creature* zian = GetClosestCreatureWithEntry(me, MOB_ZIAN, 200.0f))
                                if (zian->AI())
                                    zian->AI()->DoAction(ACTION_START_FIRST_COMBAT);

                            std::list<Creature*> sorcererMoguList;
                            me->GetCreatureListWithEntryInGrid(sorcererMoguList, NPC_SORCERER_MOGU, 200.0f);

                            for (auto itr : sorcererMoguList)
                                if (Creature* sorcererMogu = itr)
                                    sorcererMogu->AI()->DoAction(ACTION_START_FIRST_COMBAT);

                            break;
                        }
                        case EVENT_TALK_1:
                            Talk(29);
                            events.ScheduleEvent(EVENT_TALK_2, 4000);
                            break;
                        case EVENT_TALK_2:
                            Talk(30);
                            events.ScheduleEvent(EVENT_TALK_3, 5000);
                            break;
                        case EVENT_TALK_3:
                            Talk(31);
                            events.ScheduleEvent(EVENT_TALK_4, 4000);
                            break;
                        case EVENT_TALK_4:
                            Talk(32);
                            events.ScheduleEvent(EVENT_TALK_5, 7000);
                            break;
                        case EVENT_TALK_5:
                            Talk(33);
                            break;
                        case EVENT_TALK_6:
                            Talk(34);
                            events.ScheduleEvent(EVENT_TALK_7, 10000);
                            break;
                        case EVENT_TALK_7:
                            Talk(35);
                            events.ScheduleEvent(EVENT_TALK_8, 10000);
                            break;
                        case EVENT_TALK_8:
                            Talk(36);
                            events.ScheduleEvent(EVENT_TALK_9, 10000);
                            break;
                        case EVENT_TALK_9:
                            Talk(37);
                            events.ScheduleEvent(EVENT_TALK_10, 10000);
                            break;
                        case EVENT_TALK_10:
                            Talk(38);
                            break;
                        case EVENT_TALK_11:
                            Talk(40);
                            events.ScheduleEvent(EVENT_TALK_12, 10000);
                            break;
                        case EVENT_TALK_12:
                            Talk(41);
                            break;
                        default:
                            break;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_lorewalker_choAI(creature);
        }
};

// 61421 - Zian of the Endless Shadow
class mob_zian : public CreatureScript
{
    public:
        mob_zian() : CreatureScript("mob_zian") { }

        struct mob_zianAI : public ScriptedAI
        {
            mob_zianAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            EventMap events;
            InstanceScript* pInstance;

            void Reset() override
            {
                me->SetDisplayId(11686);
                me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                me->SetReactState(REACT_PASSIVE);
                SetEquipmentSlots(false, 0, 0, 0);

                events.Reset();
            }

            void DoAction(const int32 action) override
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
                        me->SetReactState(REACT_AGGRESSIVE);
                        events.ScheduleEvent(EVENT_ZIAN_CHARGED_SHADOWS, urand(5000, 15000));
                        break;
                    case ACTION_END_FIRST_COMBAT:
                        me->DespawnOrUnsummon();
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_ZIAN_CHARGED_SHADOWS:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_CHARGED_SHADOWS, false);
                            events.ScheduleEvent(EVENT_ZIAN_CHARGED_SHADOWS, urand(5000, 12000));
                            break;
                        default:
                            break;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_zianAI(creature);
        }
};

// 61250 - Sorcerer Mogu
class mob_sorcerer_mogu : public CreatureScript
{
    public:
        mob_sorcerer_mogu() : CreatureScript("mob_sorcerer_mogu") { }

        struct mob_sorcerer_moguAI : public ScriptedAI
        {
            mob_sorcerer_moguAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;
            bool allKilled;

            void Reset() override
            {
                allKilled = false;

                me->SetDisplayId(11686);
                me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                me->SetReactState(REACT_PASSIVE);

                events.Reset();
            }

            void JustDied(Unit* /*p_Killer*/) override
            {
                StartNextFight(NPC_SORCERER_MOGU, NPC_MOUNTED_MOGU, MOB_ZIAN, MOB_QIANG, ACTION_END_FIRST_COMBAT, ACTION_START_SECOND_COMBAT, me);
            }

            void DoAction(const int32 action) override
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
                        me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                        me->RemoveAurasDueToSpell(SPELL_ACTIVATION_VISUAL);
                        me->SetReactState(REACT_AGGRESSIVE);
                        events.ScheduleEvent(EVENT_SORCERER_SHADOW_BLAST, 5000);
                        break;
                    case ACTION_END_FIRST_COMBAT:
                        me->DespawnOrUnsummon();
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SORCERER_SHADOW_BLAST:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_SHADOW_BLAST, false);
                            events.ScheduleEvent(EVENT_SORCERER_SHADOW_BLAST, urand(8000, 17000));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_sorcerer_moguAI(creature);
        }
};

// 61423 - Qiang the Merciless
class mob_qiang : public CreatureScript
{
    public:
        mob_qiang() : CreatureScript("mob_qiang") { }

        struct mob_qiangAI : public ScriptedAI
        {
            mob_qiangAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset() override
            {
                me->SetDisplayId(11686);
                me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                me->SetReactState(REACT_PASSIVE);
                SetEquipmentSlots(false, 0, 0, 0);

                events.Reset();
            }

            void DoAction(const int32 action) override
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
                        events.ScheduleEvent(EVENT_QIANG_START_SECOND_FIGHT, 5000);
                        break;
                    case ACTION_START_SECOND_COMBAT:
                        me->RemoveAurasDueToSpell(SPELL_ACTIVATION_VISUAL);
                        me->SetReactState(REACT_AGGRESSIVE);
                        events.ScheduleEvent(EVENT_QIANG_ANNIHILATE, urand(5000, 15000));
                        break;
                    case ACTION_END_SECOND_COMBAT:
                        me->DespawnOrUnsummon();
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_QIANG_ANNIHILATE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_ANNIHILATE, false);
                            events.ScheduleEvent(EVENT_QIANG_ANNIHILATE,       urand(10000, 20000));
                            break;
                        case EVENT_QIANG_START_SECOND_FIGHT:
                        {
                            if (Creature* qiang = GetClosestCreatureWithEntry(me, MOB_QIANG, 200.0f))
                            {
                                if (qiang->AI())
                                    qiang->AI()->DoAction(ACTION_START_SECOND_COMBAT);
                            }

                            std::list<Creature*> l_MountedMoguList;
                            GetCreatureListWithEntryInGrid(l_MountedMoguList, me, NPC_MOUNTED_MOGU, 200.0f);

                            for (Creature* l_MountedMogu : l_MountedMoguList)
                            {
                                if (l_MountedMogu->GetAI())
                                    l_MountedMogu->AI()->DoAction(ACTION_START_SECOND_COMBAT);
                            }
                            break;
                        }
                        default:
                            break;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_qiangAI(creature);
        }
};

// 61341 - Mounted Mogu
class mob_mounted_mogu : public CreatureScript
{
    public:
        mob_mounted_mogu() : CreatureScript("mob_mounted_mogu") { }

        struct mob_mounted_moguAI : public ScriptedAI
        {
            mob_mounted_moguAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset() override
            {
                me->SetDisplayId(11686);
                me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                me->SetReactState(REACT_PASSIVE);
                SetEquipmentSlots(false, 0, 0, 0);
                me->Mount(11686);

                events.Reset();
            }

            void JustDied(Unit* /*p_Killer*/) override
            {
                StartNextFight(NPC_MOUNTED_MOGU, NPC_MOGU_ARCHER, MOB_QIANG, MOB_SUBETAI, ACTION_END_SECOND_COMBAT, ACTION_START_THIRD_COMBAT, me);
            }

            void DoAction(const int32 action) override
            {
                switch (action)
                {
                    case ACTION_SET_GHOST_VISUAL:
                        me->AddAura(SPELL_INACTIVE, me);
                        break;
                    case ACTION_SET_NATIVE_DISPLAYID:
                        me->SetDisplayId(42555);
                        me->Mount(41441);
                        SetEquipmentSlots(false, EQUIP_MOUNTED_MOGU_WEAPON, 0, EQUIP_NO_CHANGE);
                        break;
                    case ACTION_BEFORE_COMBAT:
                        me->AddAura(SPELL_ACTIVATION_VISUAL, me);
                        break;
                    case ACTION_START_SECOND_COMBAT:
                        me->RemoveAurasDueToSpell(SPELL_ACTIVATION_VISUAL);
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                        events.ScheduleEvent(EVENT_MOUNTED_MOGU_CRUSHING_ATTACKS, urand(5000, 12000));
                        break;
                    case ACTION_END_SECOND_COMBAT:
                        me->DespawnOrUnsummon();
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(const uint32 diff) override
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
                        case EVENT_MOUNTED_MOGU_CRUSHING_ATTACKS:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_CRUSHING_ATTACKS, false);
                            events.ScheduleEvent(EVENT_MOUNTED_MOGU_CRUSHING_ATTACKS, 25000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_mounted_moguAI(creature);
        }
};

// 61427 - Subetai the Swift
class mob_subetai : public CreatureScript
{
    public:
        mob_subetai() : CreatureScript("mob_subetai") { }

        struct mob_subetaiAI : public ScriptedAI
        {
            mob_subetaiAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset() override
            {
                me->SetDisplayId(11686);
                me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                me->SetReactState(REACT_PASSIVE);
                SetEquipmentSlots(false, 0, 0, 0);

                events.Reset();
            }

            void DoAction(const int32 action) override
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
                        events.ScheduleEvent(EVENT_SUBETAI_START_THIRD_COMBAT, 5000);
                        break;
                    case ACTION_START_THIRD_COMBAT:
                        me->RemoveAurasDueToSpell(SPELL_ACTIVATION_VISUAL);
                        me->SetReactState(REACT_AGGRESSIVE);
                        events.ScheduleEvent(EVENT_SUBETAI_VOLLEY, urand(5000, 15000));
                        break;
                    case ACTION_END_THIRD_COMBAT:
                        me->DespawnOrUnsummon();
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SUBETAI_VOLLEY:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_VOLLEY, false);
                            events.ScheduleEvent(EVENT_SUBETAI_VOLLEY,       urand(10000, 20000));
                            break;
                        case EVENT_SUBETAI_START_THIRD_COMBAT:
                        {
                            if (Creature* subetai = GetClosestCreatureWithEntry(me, MOB_SUBETAI, 200.0f))
                            {
                                if (subetai->AI())
                                    subetai->AI()->DoAction(ACTION_START_THIRD_COMBAT);
                            }

                            std::list<Creature*> l_MoguArcherList;
                            GetCreatureListWithEntryInGrid(l_MoguArcherList, me, NPC_MOGU_ARCHER, 200.0f);

                            for (Creature* l_MoguArcher : l_MoguArcherList)
                            {
                                if (l_MoguArcher->GetAI())
                                    l_MoguArcher->AI()->DoAction(ACTION_START_THIRD_COMBAT);
                            }
                            break;
                        }
                        default:
                            break;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_subetaiAI(creature);
        }
};

// 61345 - Mogu Archer
class mob_mogu_archer : public CreatureScript
{
    public:
        mob_mogu_archer() : CreatureScript("mob_mogu_archer") { }

        struct mob_mogu_archerAI : public ScriptedAI
        {
            mob_mogu_archerAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset() override
            {
                me->SetDisplayId(11686);
                me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                me->SetReactState(REACT_PASSIVE);

                events.Reset();
            }

            void JustDied(Unit* /*p_Killer*/) override
            {
                StartNextFight(NPC_MOGU_ARCHER, NPC_KINGSGUARD, MOB_SUBETAI, MOB_MENG, ACTION_END_THIRD_COMBAT, ACTION_START_FOURTH_COMBAT, me);
            }

            void DoAction(const int32 action) override
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
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                        events.ScheduleEvent(EVENT_MOGU_ARCHER_SHOOT, urand(5000, 12000));
                        break;
                    case ACTION_END_THIRD_COMBAT:
                        me->DespawnOrUnsummon();
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(const uint32 diff) override
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
                        case EVENT_MOGU_ARCHER_SHOOT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_SHOOT, false);
                            events.ScheduleEvent(EVENT_MOGU_ARCHER_SHOOT,       25000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_mogu_archerAI(creature);
        }
};

// 61429 - Meng the Demented
class mob_meng : public CreatureScript
{
    public:
        mob_meng() : CreatureScript("mob_meng") { }

        struct mob_mengAI : public ScriptedAI
        {
            mob_mengAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            EventMap events;
            InstanceScript* pInstance;

            void Reset() override
            {
                me->SetDisplayId(11686);
                me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                me->SetReactState(REACT_PASSIVE);

                events.Reset();
            }

            void DoAction(const int32 action) override
            {
                switch (action)
                {
                    case ACTION_SET_GHOST_VISUAL:
                    {
                        me->AddAura(SPELL_INACTIVE, me);
                        break;
                    }
                    case ACTION_SET_NATIVE_DISPLAYID:
                    {
                        me->SetDisplayId(41813);
                        break;
                    }
                    case ACTION_BEFORE_COMBAT:
                    {
                        me->AddAura(SPELL_ACTIVATION_VISUAL, me);
                        events.ScheduleEvent(EVENT_MENG_START_FOURTH_COMBAT, 5000);
                        break;
                    }
                    case ACTION_START_FOURTH_COMBAT:
                    {
                        me->RemoveAurasDueToSpell(SPELL_ACTIVATION_VISUAL);
                        me->SetReactState(REACT_AGGRESSIVE);
                        events.ScheduleEvent(EVENT_MENG_COWARDICE, 25000);
                        break;
                    }
                    case ACTION_END_FOURTH_COMBAT:
                    {
                        // Stop combat in Cho's script
                        if (Creature* Cho = GetClosestCreatureWithEntry(me, NPC_LOREWALKER_CHO, 200.0f))
                        {
                            CAST_AI(npc_lorewalker_cho::npc_lorewalker_choAI, Cho->AI())->eventInProgress = false;
                            // If Spirit Kings are already down, Cho must go on
                            Creature* sKing = GetClosestCreatureWithEntry(me, NPC_QIANG, 200.0f, true);
                            if (!sKing)
                            {
                                // In case BossState is wrong for Spirit Kings...
                                if (pInstance)
                                {
                                    if (pInstance->GetBossState(DATA_SPIRIT_KINGS) != DONE)
                                    {
                                        pInstance->SetBossState(DATA_SPIRIT_KINGS, DONE);
                                        pInstance->SaveToDB();
                                    }
                                }

                                Cho->AI()->DoAction(ACTION_CONTINUE_ESCORT);
                                Cho->AI()->DoAction(ACTION_RUN);
                            }
                        }
                        me->DespawnOrUnsummon();
                        break;
                    }
                    default:
                        break;
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_MENG_START_FOURTH_COMBAT:
                        {
                            DoAction(ACTION_START_FOURTH_COMBAT);

                            std::list<Creature*> l_KingsGuardsList;
                            GetCreatureListWithEntryInGrid(l_KingsGuardsList, me, NPC_KINGSGUARD, 200.0f);

                            for (Creature* l_KingsGuard : l_KingsGuardsList)
                            {
                                if (l_KingsGuard->GetAI())
                                    l_KingsGuard->AI()->DoAction(ACTION_START_FOURTH_COMBAT);
                            }
                            break;
                        }
                        case EVENT_MENG_COWARDICE:
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_COWARDICE, false);
                            events.ScheduleEvent(EVENT_MENG_COWARDICE, 25000);
                            break;
                        }
                        default:
                            break;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_mengAI(creature);
        }
};

// 61347 - Kingsguard
class mob_kingsguard : public CreatureScript
{
    public:
        mob_kingsguard() : CreatureScript("mob_kingsguard") { }

        struct mob_kingsguardAI : public ScriptedAI
        {
            mob_kingsguardAI(Creature* creature) : ScriptedAI(creature) { }

            EventMap events;

            void Reset() override
            {
                me->SetDisplayId(11686);
                me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                me->SetReactState(REACT_PASSIVE);

                events.Reset();
                events.ScheduleEvent(EVENT_KINGS_GUARD_ENRAGE, urand(5000, 12000));
                events.ScheduleEvent(EVENT_KINGS_GUARD_REFLECTIVE_SHIELDS, urand(15000, 20000));
            }

            void JustDied(Unit* /*p_Killer*/) override
            {
                std::list<Creature*> l_CreatureList;
                me->GetCreatureListWithEntryInGrid(l_CreatureList, me->GetEntry(), 200.0f);

                for (Creature* l_Creature : l_CreatureList)
                {
                    if (l_Creature->IsAlive() && l_Creature == me)
                        return;
                }

                DoAction(ACTION_END_FOURTH_COMBAT);

                if (Creature* l_Meng = GetClosestCreatureWithEntry(me, MOB_MENG, 200.0f))
                {
                    if (l_Meng->AI())
                        l_Meng->AI()->DoAction(ACTION_END_FOURTH_COMBAT);
                }
            }

            void DoAction(const int32 action) override
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
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                        break;
                    case ACTION_END_FOURTH_COMBAT:
                        me->DespawnOrUnsummon();
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_KINGS_GUARD_ENRAGE:
                            me->CastSpell(me, SPELL_ENRAGE, false);
                            events.ScheduleEvent(EVENT_KINGS_GUARD_ENRAGE, 25000);
                            break;
                        case EVENT_KINGS_GUARD_REFLECTIVE_SHIELDS:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_REFLECTIVE_SHIELDS, false);
                            events.ScheduleEvent(EVENT_KINGS_GUARD_REFLECTIVE_SHIELDS, 40000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_kingsguardAI(creature);
        }
};

// 61131 - Mogu'shan Secret-Keeper
class mob_mogu_secret_keeper : public CreatureScript
{
    public:
        mob_mogu_secret_keeper() : CreatureScript("mob_mogu_secret_keeper") { }

        struct mob_mogu_secret_keeperAI : public ScriptedAI
        {
            mob_mogu_secret_keeperAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset() override
            {
                events.Reset();
                events.ScheduleEvent(EVENT_SECRET_FLESH_TO_STONE, urand(5000, 12000));
                events.ScheduleEvent(EVENT_SECRET_STONE_BLOCK, urand(15000, 20000));
            }
            
            void JustDied(Unit* /*p_Killer*/) override
            {
                if (Creature* cho = GetClosestCreatureWithEntry(me, NPC_LOREWALKER_CHO, 60.0f, true))
                {
                    if (cho->GetPositionX() >= 3985.0f && cho->GetPositionX() <= 3986.0f && cho->GetPositionY() >= 1550.0f && cho->GetPositionY() <= 1551.0f)
                        cho->AI()->DoAction(ACTION_CONTINUE_ESCORT);
                    else
                        cho->AI()->DoAction(ACTION_KEEPER_DIED);
                }
            }

            void EnterCombat(Unit* /*p_Attacker*/) override
            {
                if (Creature* cho = GetClosestCreatureWithEntry(me, NPC_LOREWALKER_CHO, 60.0f, true))
                    cho->AI()->DoAction(ACTION_KEEPER_ENTER_COMBAT);
            }

            void UpdateAI(const uint32 diff) override
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
                        case EVENT_SECRET_FLESH_TO_STONE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_FLESH_TO_STONE, false);
                            events.ScheduleEvent(EVENT_SECRET_FLESH_TO_STONE,       25000);
                            break;
                        case EVENT_SECRET_STONE_BLOCK:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_STONE_BLOCK, false);
                            events.ScheduleEvent(EVENT_SECRET_STONE_BLOCK,       40000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_mogu_secret_keeperAI(creature);
        }
};

// 64061 - Mogu'shan Warden
// 64947 - Mogu'shan Warden
// 64063 - Mogu'shan Arcanist
class mob_mogu_warden : public CreatureScript
{
    public:
        mob_mogu_warden() : CreatureScript("mob_mogu_warden") { }

        struct mob_mogu_wardenAI : public ScriptedAI
        {
            mob_mogu_wardenAI(Creature* creature) : ScriptedAI(creature) { }

            EventMap events;
            bool isElegonGuardian;

            void Reset() override
            {
                isElegonGuardian = me->GetPositionZ() < 360.0f;

                events.Reset();
                if (me->GetEntry() != NPC_MOGUSHAN_ARCANIST)
                {
                    events.ScheduleEvent(EVENT_WARDEN_FORCEFUL_SWING, urand(5000, 12000));
                    events.ScheduleEvent(EVENT_WARDEN_TOUCH_OF_NALAK_SHA, urand(15000, 20000));
                    events.ScheduleEvent(EVENT_WARDEN_WARDEN_S_FURY, urand(22000, 28000));
                }
            }
            
            void JustDied(Unit* /*p_Killer*/) override
            {
                // In front of Elegon, we must check all the other trash before making Cho moves
                if (isElegonGuardian)
                {
                    Creature* warden1  = GetClosestCreatureWithEntry(me, NPC_MOGUSHAN_WARDEN,        200.0f);
                    Creature* warden2  = GetClosestCreatureWithEntry(me, NPC_MOGUSHAN_WARDEN_2,      200.0f);
                    Creature* arcanist = GetClosestCreatureWithEntry(me, NPC_MOGUSHAN_ARCANIST,      200.0f);
                    Creature* keeper   = GetClosestCreatureWithEntry(me, NPC_MOGUSHAN_ENGINE_KEEPER, 200.0f);

                    if (!warden1 && !warden2 && !arcanist && !keeper)
                        if (Creature* cho = GetClosestCreatureWithEntry(me, NPC_LOREWALKER_CHO, 300.0f, true))
                            cho->AI()->DoAction(ACTION_CONTINUE_ESCORT);
                }
                // In the stairs to Elegon's room, we just need to check the other warden
                else
                {
                    Creature* otherWarden = GetClosestCreatureWithEntry(me, me->GetEntry() == NPC_MOGUSHAN_WARDEN ? NPC_MOGUSHAN_WARDEN_2 : NPC_MOGUSHAN_WARDEN, 50.0f);
                    if (!otherWarden)
                        if (Creature* cho = GetClosestCreatureWithEntry(me, NPC_LOREWALKER_CHO, 70.0f))
                            cho->AI()->DoAction(ACTION_CONTINUE_ESCORT);
                }
            }

            void UpdateAI(const uint32 diff) override
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
                        case EVENT_WARDEN_FORCEFUL_SWING:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_FORCEFUL_SWING, false);
                            events.ScheduleEvent(EVENT_WARDEN_FORCEFUL_SWING,       30000);
                            break;
                        case EVENT_WARDEN_TOUCH_OF_NALAK_SHA:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_TOUCH_OF_NALAK_SHA, false);
                            events.ScheduleEvent(EVENT_WARDEN_TOUCH_OF_NALAK_SHA,       30000);
                            break;
                        case EVENT_WARDEN_WARDEN_S_FURY:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_WARDEN_S_FURY, false);
                            events.ScheduleEvent(EVENT_WARDEN_WARDEN_S_FURY,       30000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_mogu_wardenAI(creature);
        }
};

// 64068 - Mogu'shan Engine Keeper
class mob_mogu_engine_keeper : public CreatureScript
{
    public:
        mob_mogu_engine_keeper() : CreatureScript("mob_mogu_engine_keeper") { }

        struct mob_mogu_engine_keeperAI : public ScriptedAI
        {
            mob_mogu_engine_keeperAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset() override
            {
                events.Reset();
                events.ScheduleEvent(EVENT_KEEPER_ENHANCED_RECONSTRUCTION, urand(5000, 12000));
                events.ScheduleEvent(EVENT_KEEPER_RECONSTRUCTING, urand(15000, 20000));
            }
            
            void JustDied(Unit* /*p_Killer*/) override
            {
                Creature* warden1  = GetClosestCreatureWithEntry(me, NPC_MOGUSHAN_WARDEN,        300.0f, true);
                Creature* warden2  = GetClosestCreatureWithEntry(me, NPC_MOGUSHAN_WARDEN_2,      300.0f, true);
                Creature* arcanist = GetClosestCreatureWithEntry(me, NPC_MOGUSHAN_ARCANIST,      300.0f, true);
                Creature* keeper   = GetClosestCreatureWithEntry(me, NPC_MOGUSHAN_ENGINE_KEEPER, 300.0f, true);

                if (!warden1 && !warden2 && !arcanist && !keeper)
                    if (Creature* cho = GetClosestCreatureWithEntry(me, NPC_LOREWALKER_CHO, 300.0f, true))
                        cho->AI()->DoAction(ACTION_CONTINUE_ESCORT);
            }

            void UpdateAI(const uint32 diff) override
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
                        case EVENT_KEEPER_ENHANCED_RECONSTRUCTION:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_ENHANCED_RECONSTRUCTION, false);
                            events.ScheduleEvent(EVENT_KEEPER_ENHANCED_RECONSTRUCTION,       30000);
                            break;
                        case EVENT_KEEPER_RECONSTRUCTING:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_RECONSTRUCTING, false);
                            events.ScheduleEvent(EVENT_KEEPER_RECONSTRUCTING,       30000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_mogu_engine_keeperAI(creature);
        }
};

void AddSC_mogu_shan_vault()
{
    new mob_cursed_mogu_sculpture();    // 61334 / 61989 - Cursed Mogu Sculpture
    new spell_ghost_essence();          // 120764 - Ghost Essence
    new mob_enormous_stone_quilen();    // 64183 - Enormous Stone Quilen
    new mob_stone_quilen();             // 60576 - Stone Quilen
    new mob_zandalari_skullcharger();   // 60375 - Zandalari Skullcharger
    new spell_mogu_petrification();     // 125092 - Petrification
    new npc_lorewalker_cho();           // 61348 - Lorewalker Cho
    new mob_sorcerer_mogu();            // 61250 - Sorcerer Mogu
    new mob_mogu_archer();              // 61345 - Mogu Archer
    new mob_mounted_mogu();             // 61341 - Mounted Mogu
    new mob_kingsguard();               // 61347 - Kingsguard
    new mob_subetai();                  // 61427 - Subetai the Swift
    new mob_meng();                     // 61429 - Meng the Demented
    new mob_zian();                     // 61421 - Zian of the Endless Shadow
    new mob_qiang();                    // 61423 - Qiang the Merciless
    new mob_mogu_secret_keeper();       // 61131 - Mogu'shan Secret-Keeper
    new mob_mogu_warden();              // 64061/64947 - Mogu'shan Warden + 64063 - Mogu'shan Arcanist
    new mob_mogu_engine_keeper();       // 64068 - Mogu'shan Engine Keeper
}
