/*
 * Copyright (C) 2017-2019 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2016 Firestorm Servers <https://firestorm-servers.com>
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "krasarang_wilds.h"
#include "SpellScript.h"

#define CHECK_STATUS(a) (player->GetQuestStatus(a) == QUEST_STATUS_INCOMPLETE)
#define GOSSIP_CHOICE_1 "Let's fight !"
#define GOSSIP_CHOICE "<Reach out to touch Chi-Ji.>"

// Arness the Scale - 50787
class mob_arness_the_scale : public CreatureScript
{
    public:
        mob_arness_the_scale() : CreatureScript("mob_arness_the_scale") {}

        struct mob_arness_the_scaleAI : public ScriptedAI
        {
            mob_arness_the_scaleAI(Creature* creature) : ScriptedAI(creature) {}

            EventMap events;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_GRAPPLING_HOOK, 40000);
                events.ScheduleEvent(EVENT_VANISH, 20000);
                events.ScheduleEvent(EVENT_VICIOUS_REND, 15000);
            }

            void UpdateAI(uint32 diff) override
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
                        case EVENT_GRAPPLING_HOOK:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_GRAPPLING_HOOK, false);
                            events.ScheduleEvent(EVENT_GRAPPLING_HOOK, 40000);
                            break;
                        case EVENT_VANISH:
                            me->CastSpell(me, SPELL_VANISH, false);
                            events.ScheduleEvent(EVENT_VANISH, 40000);
                            break;
                        case EVENT_VICIOUS_REND:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_VICIOUS_REND, false);
                            events.ScheduleEvent(EVENT_VICIOUS_REND, 40000);
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
            return new mob_arness_the_scaleAI(creature);
        }
};

// Gaarn the Toxic - 50340
class mob_gaarn_the_toxic : public CreatureScript
{
    public:
        mob_gaarn_the_toxic() : CreatureScript("mob_gaarn_the_toxic") {}

        struct mob_gaarn_the_toxicAI : public ScriptedAI
        {
            mob_gaarn_the_toxicAI(Creature* creature) : ScriptedAI(creature) {}

            EventMap events;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_SHADOWBOLT, 15000);
                events.ScheduleEvent(EVENT_VOIDCLOUD, 70000);
            }

            void UpdateAI(uint32 diff) override
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
                        case EVENT_SHADOWBOLT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_SHADOWBOLT, false);
                            events.ScheduleEvent(EVENT_SHADOWBOLT, 15000);
                            break;
                        case EVENT_VOIDCLOUD:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_VOIDCLOUD, false);
                            events.ScheduleEvent(EVENT_VOIDCLOUD, 70000);
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
            return new mob_gaarn_the_toxicAI(creature);
        }
};

// Qu Nas - 50352
class mob_qu_nas : public CreatureScript
{
    public:
        mob_qu_nas() : CreatureScript("mob_qu_nas") {}

        struct mob_qu_nasAI : public ScriptedAI
        {
            mob_qu_nasAI(Creature* creature) : ScriptedAI(creature) {}

            EventMap events;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_DEVASTATING_ARC, 25000);
                events.ScheduleEvent(EVENT_SUMMON_QUILEN, 15000);
                events.ScheduleEvent(EVENT_TITANIC_STRENGTH, 70000);
            }

            void UpdateAI(uint32 diff) override
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
                        case EVENT_DEVASTATING_ARC:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_DEVASTATING_ARC, false);
                            events.ScheduleEvent(EVENT_DEVASTATING_ARC, 30000);
                            break;
                        case EVENT_SUMMON_QUILEN:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_SUMMON_QUILEN, false);
                            events.ScheduleEvent(EVENT_SUMMON_QUILEN, 80000);
                            break;
                        case EVENT_TITANIC_STRENGTH:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_TITANIC_STRENGTH, false);
                            events.ScheduleEvent(EVENT_TITANIC_STRENGTH, 55000);
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
            return new mob_qu_nasAI(creature);
        }
};

// Torik Ethis - 50388
class mob_torik_ethis : public CreatureScript
{
    public:
        mob_torik_ethis() : CreatureScript("mob_torik_ethis") {}

        struct mob_torik_ethisAI : public ScriptedAI
        {
            mob_torik_ethisAI(Creature* creature) : ScriptedAI(creature) {}

            EventMap events;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_BLADE_FURY, 8000);
                events.ScheduleEvent(EVENT_TORNADO, 40000);
                events.ScheduleEvent(EVENT_WINDSONG, 32000);
            }

            void JustSummoned(Creature* summon) override
            {
                if (summon->GetEntry() == MOB_TORNADO)
                {
                    summon->AddAura(SPELL_TORNADO_DMG, summon);
                    summon->SetReactState(REACT_PASSIVE);
                    summon->GetMotionMaster()->MoveRandom(20.0f);
                }
            }

            void UpdateAI(uint32 diff) override
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
                        case EVENT_BLADE_FURY:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_BLADE_FURY, false);
                            events.ScheduleEvent(EVENT_BLADE_FURY, 8000);
                            break;
                        case EVENT_TORNADO:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_TORNADO, false);
                            events.ScheduleEvent(EVENT_TORNADO, 40000);
                            break;
                        case EVENT_WINDSONG:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_WINDSONG, false);
                            events.ScheduleEvent(EVENT_WINDSONG, 32000);
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
            return new mob_torik_ethisAI(creature);
        }
};

// Go Kan - 50331
class mob_go_kan : public CreatureScript
{
    public:
        mob_go_kan() : CreatureScript("mob_go_kan") {}

        struct mob_go_kanAI : public ScriptedAI
        {
            mob_go_kanAI(Creature* creature) : ScriptedAI(creature) {}

            EventMap events;

            void Reset() override
            {
                me->SetStandState(UNIT_STAND_STATE_SIT);
                events.Reset();
                events.ScheduleEvent(EVENT_BELLOWING_RAGE, 8000);
                events.ScheduleEvent(EVENT_RUSHING_CHARGE, 17000);
                events.ScheduleEvent(EVENT_YAUNGOL_STOMP, 25000);
            }

            void EnterCombat(Unit* /*who*/) override
            {
                me->SetStandState(UNIT_STAND_STATE_STAND);
            }

            void UpdateAI(uint32 diff) override
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
                        case EVENT_BELLOWING_RAGE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_BELLOWING_RAGE, false);
                            events.ScheduleEvent(EVENT_BELLOWING_RAGE, 35000);
                            break;
                        case EVENT_RUSHING_CHARGE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_RUSHING_CHARGE, false);
                            events.ScheduleEvent(EVENT_RUSHING_CHARGE, 35000);
                            break;
                        case EVENT_YAUNGOL_STOMP:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_YAUNGOL_STOMP, false);
                            events.ScheduleEvent(EVENT_YAUNGOL_STOMP, 35000);
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
            return new mob_go_kanAI(creature);
        }
};

// Spirit of the Crane - 60487
class mob_spirit_of_the_crane : public CreatureScript
{
    public:
        mob_spirit_of_the_crane() : CreatureScript("mob_spirit_of_the_crane") {}

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            if (player->GetQuestStatus(30716) == QUEST_STATUS_INCOMPLETE)
            {
                player->KilledMonsterCredit(60487);
                creature->DespawnOrUnsummon();
            }

            return true;
        }
};

// Champion of Chi Ji - 60546
class mob_champion_of_chi_ji : public CreatureScript
{
    public:
        mob_champion_of_chi_ji() : CreatureScript("mob_champion_of_chi_ji") {}

        struct mob_champion_of_chi_jiAI : public ScriptedAI
        {
            mob_champion_of_chi_jiAI(Creature* creature) : ScriptedAI(creature) {}

            EventMap events;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_CHI_TORPEDO, 4000);
                events.ScheduleEvent(EVENT_HUNDRED_HAND_SLAP, 17000);
                events.ScheduleEvent(EVENT_SPINNING_CRANE_KICK, 27000);
                events.ScheduleEvent(EVENT_UPPERCUT, 35000);
            }

            void MoveInLineOfSight(Unit* who) override // Dynamic Aggro !
            {
                if (Player* pAttacker = who->ToPlayer())
                {
                    if (pAttacker->GetQuestStatus(30740) == QUEST_STATUS_INCOMPLETE)
                    {
                        if (me->GetDistance(who) >= 10.0f && me->GetDistance(who) <= 40.0f)
                            me->CastSpell(who, SPELL_FLYING_SERPENT_KICK, false);
                    }
                }
            }

            void UpdateAI(uint32 diff) override
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
                        case EVENT_CHI_TORPEDO:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_CHI_TORPEDO, false);
                            events.ScheduleEvent(EVENT_CHI_TORPEDO, 40000);
                            break;
                        case EVENT_HUNDRED_HAND_SLAP:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_HUNDRED_HAND_SLAP, false);
                            events.ScheduleEvent(EVENT_HUNDRED_HAND_SLAP, 40000);
                            break;
                        case EVENT_SPINNING_CRANE_KICK:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_SPINNING_CRANE_KICK, false);
                            events.ScheduleEvent(EVENT_SPINNING_CRANE_KICK, 40000);
                            break;
                        case EVENT_UPPERCUT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_UPPERCUT, false);
                            events.ScheduleEvent(EVENT_UPPERCUT, 40000);
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
            return new mob_champion_of_chi_jiAI(creature);
        }
};

// Chi Torpedo - 119539
class spell_chi_torpedo_periodic: public SpellScriptLoader
{
    public:
        spell_chi_torpedo_periodic() : SpellScriptLoader("spell_chi_torpedo_periodic") { }

        class spell_chi_torpedo_periodic_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_chi_torpedo_periodic_AuraScript);

            void OnTick(AuraEffect const* /*aurEff*/)
            {
                if (Unit* caster = GetCaster())
                {
                    if (Unit* target = caster->GetVictim())
                    {
                        caster->CastSpell(target, 119520, true);
                    }
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_chi_torpedo_periodic_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_chi_torpedo_periodic_AuraScript();
        }
};

// Andruin Wrynn - 59608
class mob_anduin_wrynn : public CreatureScript
{
    public:
        mob_anduin_wrynn() : CreatureScript("mob_anduin_wrynn") {}

        bool OnQuestAccept(Player* p_Player, Creature* /*p_Creature*/, Quest const* p_Quest) override
        {
            if (p_Quest->GetQuestId() == QuestInTheHouseOfTheRedCrane)
                p_Player->SummonCreature(NPC_ANDUIN_WRYNN, p_Player->GetPositionX(), p_Player->GetPositionY(), p_Player->GetPositionZ(), 0.0f);

            return true;
        }
};

// Andruin Wrynn - 66975
class mob_anduin_wrynn_escort : public CreatureScript
{
    public:
        mob_anduin_wrynn_escort() : CreatureScript("mob_anduin_wrynn_escort") {}

        struct mob_anduin_wrynn_escortAI : public ScriptedAI
        {
            mob_anduin_wrynn_escortAI(Creature* creature) : ScriptedAI(creature)
            {
                m_playerGUID = ObjectGuid::Empty;
            }

            ObjectGuid m_playerGUID;
            EventMap m_Events;

            void IsSummonedBy(Unit* p_Summoner) override
            {
                m_Events.Reset();

                if (Player* l_Plr = p_Summoner->ToPlayer())
                {
                    if (l_Plr->GetQuestStatus(QuestInTheHouseOfTheRedCrane) == QUEST_STATUS_INCOMPLETE)
                    {
                        me->GetMotionMaster()->MoveFollow(l_Plr, 2.0f, 2.0f, MOTION_SLOT_ACTIVE);
                        m_playerGUID = l_Plr->GetGUID();
                        m_Events.ScheduleEvent(EVENT_CHECK_TARGET, 1000);
                    }
                }
            }

            void UpdateAI(uint32 p_Diff) override
            {
                m_Events.Update(p_Diff);

                if (m_Events.ExecuteEvent() == EVENT_CHECK_TARGET)
                {
                    if (Player* l_Summoner = ObjectAccessor::FindPlayer(m_playerGUID))
                    {
                        if (Unit* l_Target = l_Summoner->GetVictim())
                        {
                            if (Creature* l_Creature = l_Target->ToCreature())
                            {
                                if (l_Creature->GetEntry() == 59651)
                                {
                                    me->Attack(l_Target, true);
                                    DoMeleeAttackIfReady();
                                }
                            }
                        }

                        m_Events.ScheduleEvent(EVENT_CHECK_TARGET, 1000);
                    }
                    else
                        me->DespawnOrUnsummon();

                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_anduin_wrynn_escortAI(creature);
        }
};

// Chi Ji - 59653
class npc_chi_ji : public CreatureScript
{
    public:
        npc_chi_ji() : CreatureScript("npc_chi_ji") {}

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            if (player->GetQuestStatus(30273) == QUEST_STATUS_INCOMPLETE)
            {
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_CHOICE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                SendGossipMenuFor(player, 30003, creature->GetGUID());
            }

            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
        {
            player->PlayerTalkClass->ClearMenus();

            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                CloseGossipMenuFor(player);
                creature->DespawnOrUnsummon();
                player->SummonCreature(59651, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ()); // , 0.0f);
            }

            return true;
        }
};

// Sha of Despair - 59651
class mob_sha_of_despair : public CreatureScript
{
    public:
        mob_sha_of_despair() : CreatureScript("mob_sha_of_despair") {}

        struct mob_sha_of_despairAI : public ScriptedAI
        {
            mob_sha_of_despairAI(Creature* creature) : ScriptedAI(creature) {}

            void JustDied(Unit* /*killer*/) override
            {
                me->DespawnOrUnsummon();
                me->SummonCreature(59653, -1813.46f, 1052.33f, -31.115f, 0.0f, TEMPSUMMON_MANUAL_DESPAWN);

                std::list<Creature*> creatureList;
                me->GetCreatureListWithEntryInGrid(creatureList, 66975, 40.0f);

                for (auto creature: creatureList)
                    creature->DespawnOrUnsummon();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_sha_of_despairAI(creature);
        }
};

// Thelonius - 60506
class npc_thelonius : public CreatureScript
{
    public:
        npc_thelonius() : CreatureScript("npc_thelonius") {}

        bool OnQuestAccept(Player* player, Creature* /*p_Creature*/, Quest const* quest) override
        {
            switch (quest->GetQuestId())
            {
                case 30725:
                    player->SummonCreature(60530, -2318.079f, 1449.463f, 29.617f, 0.539766f);
                    break;
                case 30739:
                    player->SummonCreature(60545, -2318.079f, 1449.463f, 29.617f, 0.539766f);
                    break;
                case 30727:
                    player->SummonCreature(60533, -2318.079f, 1449.463f, 29.617f, 0.539766f);
                    break;
                case 30732:
                    player->SummonCreature(60538, -2318.079f, 1449.463f, 29.617f, 0.539766f);
                    break;
                case 30728:
                    player->SummonCreature(60534, -2318.079f, 1449.463f, 29.617f, 0.539766f);
                    break;
                case 30737:
                    player->SummonCreature(60543, -2318.079f, 1449.463f, 29.617f, 0.539766f);
                    break;
                case 30734:
                    player->SummonCreature(60540, -2322.529f, 1624.929f, 0.381f, 5.288279f);
                    break;
                case 30730:
                    player->SummonCreature(60536, -2615.302f, 1457.653f, 1.537f, 2.407458f);
                    break;
                case 30729:
                    player->SummonCreature(60535, -2471.108f, 1594.382f, 0.267f, 5.878917f);
                    break;
                case 30731:
                    player->SummonCreature(60537, -2473.856f, 1241.124f, 36.133f, 1.293773f);
                    break;
                case 30735:
                    player->SummonCreature(60541, -2318.079f, 1449.463f, 29.617f, 0.539766f);
                    break;
                case 30726:
                    player->SummonCreature(60532, -2502.585f, 1449.352f, 15.786f, 0.030857f);
                    break;
                case 30738:
                    player->SummonCreature(60544, -2322.529f, 1624.929f, 0.381f, 5.288279f);
                    break;
                case 30733:
                    player->SummonCreature(60539, -2457.983f, 1352.873f, 20.287f, 0.202678f);
                    break;
                case 30736:
                    player->SummonCreature(60542, -2473.856f, 1241.124f, 36.133f, 1.293773f);
                    break;
                default:
                    break;
            }

            return true;
        }
};

//Ella Ravenmane - 60530/60545/60533/60538
class mob_ellia_ravenmane : public CreatureScript
{
    public:
        mob_ellia_ravenmane() : CreatureScript("mob_ellia_ravenmane") {}

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_CHOICE_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            SendGossipMenuFor(player, 69970, creature->GetGUID());

            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
        {
            player->PlayerTalkClass->ClearMenus();

            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                CloseGossipMenuFor(player);

                if (CHECK_STATUS(30725) || CHECK_STATUS(30739) || CHECK_STATUS(30727) || CHECK_STATUS(30732))
                {
                    creature->AI()->SetGUID(player ? player->GetGUID() : ObjectGuid::Empty);
                    creature->SetFaction(14);

                    if (creature->GetAI())
                    {
                        creature->AI()->Reset();
                        creature->AI()->DoAction(ACTION_REMOVE_FLAG);
                    }
                }
            }
            return true;
        }

        struct mob_ellia_ravenmaneAI : public ScriptedAI
        {
            mob_ellia_ravenmaneAI(Creature* creature) : ScriptedAI(creature)
            {
                playerGUID = ObjectGuid::Empty;
            }

            EventMap events;
            ObjectGuid playerGUID;

            void Reset() override
            {
                events.Reset();

                switch (me->GetEntry())
                {
                    case 60530:
                        events.ScheduleEvent(EVENT_JAB, 3000);
                        events.ScheduleEvent(EVENT_KICK, 6000);
                        break;
                    case 60545:
                        events.ScheduleEvent(EVENT_CRY_OUT_IN_DESPAIR, 3000);
                        events.ScheduleEvent(EVENT_SHA_BLAST, 8000);
                        events.ScheduleEvent(EVENT_SHA_SPIKE, 13000);
                        break;
                    case 60533:
                        events.ScheduleEvent(EVENT_FIERCE_JAB, 3000);
                        events.ScheduleEvent(EVENT_FIERCE_KICK, 6000);
                        break;
                    case 60538:
                        events.ScheduleEvent(EVENT_FIERCE_JAB_2, 3000);
                        events.ScheduleEvent(EVENT_FISTS_OF_FURY, 8000);
                        events.ScheduleEvent(EVENT_VICIOUS_KICK, 13000);
                        break;
                    default:
                        break;
                }
            }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                if (Player* player = attacker->ToPlayer())
                {
                    switch (me->GetEntry())
                    {
                        case 60530:
                            if (CHECK_STATUS(30725))
                            {
                                if (damage > me->GetHealth())
                                {
                                    damage = 0;
                                    me->SetFullHealth();
                                    DoAction(ACTION_REINITIALIZE);
                                    player->KilledMonsterCredit(60530);
                                    me->DespawnOrUnsummon();
                                }
                            }
                            break;
                        case 60545:
                            if (CHECK_STATUS(30739))
                            {
                                if (damage > me->GetHealth())
                                {
                                    damage = 0;
                                    me->SetFullHealth();
                                    DoAction(ACTION_REINITIALIZE);
                                    player->KilledMonsterCredit(60545);
                                    me->DespawnOrUnsummon();
                                }
                            }
                            break;
                        case 60533:
                            if (CHECK_STATUS(30727))
                            {
                                if (damage > me->GetHealth())
                                {
                                    damage = 0;
                                    me->SetFullHealth();
                                    DoAction(ACTION_REINITIALIZE);
                                    player->KilledMonsterCredit(60533);
                                    me->DespawnOrUnsummon();
                                }
                            }
                            break;
                        case 60538:
                            if (CHECK_STATUS(30732))
                            {
                                if (damage > me->GetHealth())
                                {
                                    damage = 0;
                                    me->SetFullHealth();
                                    DoAction(ACTION_REINITIALIZE);
                                    player->KilledMonsterCredit(60538);
                                    me->DespawnOrUnsummon();
                                }
                            }
                            break;
                        default:
                            break;

                    }
                }
            }

            void SetGUID(ObjectGuid guid, int32 index) override
            {
                if (index == 0)
                    playerGUID = guid;
            }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                events.ScheduleEvent(EVENT_DESPAWN, 600000);
            }

            void DoAction(int32 action) override
            {
                if (action == ACTION_REMOVE_FLAG)
                {
                    me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                }

                else if (action == ACTION_REINITIALIZE)
                {
                    me->SetFaction(35);
                    me->CombatStop();
                    me->AddNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (Player* player = ObjectAccessor::FindPlayer(playerGUID))
                {
                    if (!player->IsAlive())
                    {
                        DoAction(ACTION_REINITIALIZE);
                        return;
                    }

                    switch (me->GetEntry())
                    {
                        case 60530:
                            if (CHECK_STATUS(30725))
                                me->DespawnOrUnsummon();
                            break;
                        case 60545:
                            if (CHECK_STATUS(30739))
                                me->DespawnOrUnsummon();
                            break;
                        case 60533:
                            if (CHECK_STATUS(30727))
                                me->DespawnOrUnsummon();
                            break;
                        case 60538:
                            if (CHECK_STATUS(30732))
                                me->DespawnOrUnsummon();
                            break;
                        default:
                            break;
                    }
                }

                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        // Entry 60530
                        case EVENT_JAB:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_JAB, false);
                            events.ScheduleEvent(EVENT_JAB, 7000);
                            break;
                        case EVENT_KICK:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_KICK, false);
                            events.ScheduleEvent(EVENT_KICK, 7000);
                            break;
                            // Entry 60545
                        case EVENT_CRY_OUT_IN_DESPAIR:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_CRY_OUT_IN_DESPAIR, false);
                            events.ScheduleEvent(EVENT_CRY_OUT_IN_DESPAIR, 15000);
                            break;
                        case EVENT_SHA_BLAST:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_SHA_BLAST, false);
                            events.ScheduleEvent(EVENT_SHA_BLAST, 15000);
                            break;
                        case EVENT_SHA_SPIKE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_SHA_SPIKE, false);
                            events.ScheduleEvent(EVENT_SHA_SPIKE, 15000);
                            break;
                            // Entry 60533
                        case EVENT_FIERCE_JAB:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_FIERCE_JAB, false);
                            events.ScheduleEvent(EVENT_FIERCE_JAB, 7000);
                            break;
                        case EVENT_FIERCE_KICK:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_FIERCE_KICK, false);
                            events.ScheduleEvent(EVENT_FIERCE_KICK, 7000);
                            break;
                            // Entry 60538
                        case EVENT_FIERCE_JAB_2:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_FIERCE_JAB, false);
                            events.ScheduleEvent(EVENT_FIERCE_JAB_2, 15000);
                            break;
                        case EVENT_FISTS_OF_FURY:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_FISTS_OF_FURY, false);
                            events.ScheduleEvent(EVENT_FISTS_OF_FURY, 15000);
                            break;
                        case EVENT_VICIOUS_KICK:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_VICIOUS_KICK, false);
                            events.ScheduleEvent(EVENT_VICIOUS_KICK, 15000);
                            break;
                        case EVENT_DESPAWN:
                            me->DespawnOrUnsummon();
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
            return new mob_ellia_ravenmaneAI(creature);
        }
};

// Fat Long Fat - 60534/60543
class mob_fat_long_fat : public CreatureScript
{
    public:
        mob_fat_long_fat() : CreatureScript("mob_fat_long_fat") {}

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_CHOICE_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            SendGossipMenuFor(player, 69970, creature->GetGUID());

            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
        {
            player->PlayerTalkClass->ClearMenus();

            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                CloseGossipMenuFor(player);

                if (CHECK_STATUS(30728) || CHECK_STATUS(30737))
                {
                    creature->AI()->SetGUID(player ? player->GetGUID() : ObjectGuid::Empty);
                    creature->SetFaction(14);

                    if (creature->GetAI())
                    {
                        creature->AI()->Reset();
                        creature->AI()->DoAction(ACTION_REMOVE_FLAG);
                    }
                }
            }
            return true;
        }

        struct mob_fat_long_fatAI : public ScriptedAI
        {
            mob_fat_long_fatAI(Creature* creature) : ScriptedAI(creature)
            {
                playerGUID = ObjectGuid::Empty;
            }

            EventMap events;
            ObjectGuid playerGUID;

            void Reset() override
            {
                events.Reset();

                switch (me->GetEntry())
                {
                    case 60534:
                        events.ScheduleEvent(EVENT_BREATH_OF_FIRE, 3000);
                        events.ScheduleEvent(EVENT_STORM_STOUT, 6000);
                        break;
                    case 60543:
                        events.ScheduleEvent(EVENT_FAT_LONG_FLOP, 3000);
                        events.ScheduleEvent(EVENT_BREATH_OF_FIRE_2, 8000);
                        events.ScheduleEvent(EVENT_STORM_STOUT_2, 13000);
                        break;
                    default:
                        break;
                }
            }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                if (Player* player = attacker->ToPlayer())
                {
                    switch (me->GetEntry())
                    {
                        case 60534:
                            if (CHECK_STATUS(30728))
                            {
                                if (damage > me->GetHealth())
                                {
                                    damage = 0;
                                    me->SetFullHealth();
                                    DoAction(ACTION_REINITIALIZE);
                                    player->KilledMonsterCredit(60534);
                                    me->DespawnOrUnsummon();
                                }
                            }
                            break;
                        case 60543:
                            if (CHECK_STATUS(30737))
                            {
                                if (damage > me->GetHealth())
                                {
                                    damage = 0;
                                    me->SetFullHealth();
                                    DoAction(ACTION_REINITIALIZE);
                                    player->KilledMonsterCredit(60543);
                                    me->DespawnOrUnsummon();
                                }
                            }
                            break;
                        default:
                            break;
                    }
                }
            }

            void SetGUID(ObjectGuid guid, int32 index) override
            {
                if (index == 0)
                    playerGUID = guid;
            }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                events.ScheduleEvent(EVENT_DESPAWN, 600000);
            }

            void DoAction(int32 action) override
            {
                if (action == ACTION_REMOVE_FLAG)
                {
                    me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                }

                else if (action == ACTION_REINITIALIZE)
                {
                    me->SetFaction(35);
                    me->CombatStop();
                    me->AddNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (Player* player = ObjectAccessor::FindPlayer(playerGUID))
                {
                    if (!player->IsAlive())
                    {
                        DoAction(ACTION_REINITIALIZE);
                        return;
                    }

                    switch (me->GetEntry())
                    {
                        case 60534:
                            if (!CHECK_STATUS(30728))
                                me->DespawnOrUnsummon();
                            break;
                        case 60543:
                            if (!CHECK_STATUS(30737))
                                me->DespawnOrUnsummon();
                            break;
                        default:
                            break;
                    }
                }

                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        // Entry 60534
                        case EVENT_BREATH_OF_FIRE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_BREATH_OF_FIRE, false);
                            events.ScheduleEvent(EVENT_BREATH_OF_FIRE, 7000);
                            break;
                        case EVENT_STORM_STOUT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_STORM_STOUT, false);
                            events.ScheduleEvent(EVENT_STORM_STOUT, 7000);
                            break;
                            // Entry 60543
                        case EVENT_FAT_LONG_FLOP:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_FAT_LONG_FLOP, false);
                            events.ScheduleEvent(EVENT_FAT_LONG_FLOP, 15000);
                            break;
                        case EVENT_BREATH_OF_FIRE_2:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_BREATH_OF_FIRE, false);
                            events.ScheduleEvent(EVENT_BREATH_OF_FIRE_2, 15000);
                            break;
                        case EVENT_STORM_STOUT_2:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_STORM_STOUT, false);
                            events.ScheduleEvent(EVENT_STORM_STOUT_2, 15000);
                            break;
                        case EVENT_DESPAWN:
                            me->DespawnOrUnsummon();
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
            return new mob_fat_long_fatAI(creature);
        }
};

// Huck Wheelbarrow - 60540
class mob_huck_wheelbarrow : public CreatureScript
{
    public:
        mob_huck_wheelbarrow() : CreatureScript("mob_huck_wheelbarrow") {}

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_CHOICE_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            SendGossipMenuFor(player, 69970, creature->GetGUID());

            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
        {
            player->PlayerTalkClass->ClearMenus();

            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                CloseGossipMenuFor(player);

                if (CHECK_STATUS(30734))
                {
                    creature->AI()->SetGUID(player ? player->GetGUID() : ObjectGuid::Empty);
                    creature->SetFaction(14);

                    if (creature->GetAI())
                    {
                        creature->AI()->Reset();
                        creature->AI()->DoAction(ACTION_REMOVE_FLAG);
                    }
                }
            }
            return true;
        }

        struct mob_huck_wheelbarrowAI : public ScriptedAI
        {
            mob_huck_wheelbarrowAI(Creature* creature) : ScriptedAI(creature)
            {
                playerGUID = ObjectGuid::Empty;
            }

            EventMap events;
            ObjectGuid playerGUID;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_WHEELBARROW_ROLL_2, 3000);
                events.ScheduleEvent(EVENT_WHEEL_PUNCH, 8000);
                events.ScheduleEvent(EVENT_ROLLING_THROW, 13000);
            }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                if (Player* player = attacker->ToPlayer())
                {
                    if (CHECK_STATUS(30734))
                    {
                        if (damage > me->GetHealth())
                        {
                            damage = 0;
                            me->SetFullHealth();
                            DoAction(ACTION_REINITIALIZE);
                            player->KilledMonsterCredit(60540);
                            me->DespawnOrUnsummon();
                        }
                    }
                }
            }

            void SetGUID(ObjectGuid guid, int32 index) override
            {
                if (index == 0)
                    playerGUID = guid;
            }

            void IsSummonedBy(Unit* /*summonner*/) override
            {
                events.ScheduleEvent(EVENT_DESPAWN, 600000);
            }

            void DoAction(int32 action) override
            {
                if (action == ACTION_REMOVE_FLAG)
                {
                    me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                }

                else if (action == ACTION_REINITIALIZE)
                {
                    me->SetFaction(35);
                    me->CombatStop();
                    me->AddNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (Player* player = ObjectAccessor::FindPlayer(playerGUID))
                {
                    if (!player->IsAlive())
                    {
                        DoAction(ACTION_REINITIALIZE);
                        return;
                    }

                    if (!CHECK_STATUS(30734))
                        me->DespawnOrUnsummon();
                }

                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_WHEELBARROW_ROLL_2:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_WHEELBARROW_ROLL_2, false);
                            events.ScheduleEvent(EVENT_WHEELBARROW_ROLL_2, 18000);
                            break;
                        case EVENT_WHEEL_PUNCH:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_WHEEL_PUNCH, false);
                            events.ScheduleEvent(EVENT_WHEEL_PUNCH, 18000);
                            break;
                        case EVENT_ROLLING_THROW:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_ROLLING_THROW, false);
                            events.ScheduleEvent(EVENT_ROLLING_THROW, 18000);
                            break;
                        case EVENT_DESPAWN:
                            me->DespawnOrUnsummon();
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
            return new mob_huck_wheelbarrowAI(creature);
        }
};

// Dextrous Izissha - 60536
class mob_dextrous_izissha : public CreatureScript
{
    public:
        mob_dextrous_izissha() : CreatureScript("mob_dextrous_izissha") {}

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_CHOICE_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            SendGossipMenuFor(player, 69970, creature->GetGUID());

            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
        {
            player->PlayerTalkClass->ClearMenus();

            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                CloseGossipMenuFor(player);

                if (CHECK_STATUS(30730))
                {
                    creature->AI()->SetGUID(player ? player->GetGUID() : ObjectGuid::Empty);
                    creature->SetFaction(14);

                    if (creature->GetAI())
                    {
                        creature->AI()->Reset();
                        creature->AI()->DoAction(ACTION_REMOVE_FLAG);
                    }
                }
            }
            return true;
        }

        struct mob_dextrous_izisshaAI : public ScriptedAI
        {
            mob_dextrous_izisshaAI(Creature* creature) : ScriptedAI(creature)
            {
                playerGUID = ObjectGuid::Empty;
            }

            EventMap events;
            ObjectGuid playerGUID;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_EVASION, 3000);
                events.ScheduleEvent(EVENT_FLUID_LIKE_WATR, 8000);
                events.ScheduleEvent(EVENT_STILL_WATERS_RUN_DEEP, 13000);
            }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                if (Player* player = attacker->ToPlayer())
                {
                    if (CHECK_STATUS(30730))
                    {
                        if (damage > me->GetHealth())
                        {
                            damage = 0;
                            me->SetFullHealth();
                            DoAction(ACTION_REINITIALIZE);
                            player->KilledMonsterCredit(60536);
                            me->DespawnOrUnsummon();
                        }
                    }
                }
            }

            void SetGUID(ObjectGuid guid, int32 index) override
            {
                if (index == 0)
                    playerGUID = guid;
            }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                events.ScheduleEvent(EVENT_DESPAWN, 600000);
            }

            void DoAction(int32 action) override
            {
                if (action == ACTION_REMOVE_FLAG)
                {
                    me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                }

                else if (action == ACTION_REINITIALIZE)
                {
                    me->SetFaction(35);
                    me->CombatStop();
                    me->AddNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (Player* player = ObjectAccessor::FindPlayer(playerGUID))
                {
                    if (!player->IsAlive())
                    {
                        DoAction(ACTION_REINITIALIZE);
                        return;
                    }

                    if (!CHECK_STATUS(30730))
                        me->DespawnOrUnsummon();
                }

                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_EVASION:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_EVASION, false);
                            events.ScheduleEvent(EVENT_EVASION, 18000);
                            break;
                        case EVENT_FLUID_LIKE_WATR:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_FLUID_LIKE_WATR, false);
                            events.ScheduleEvent(EVENT_FLUID_LIKE_WATR, 18000);
                            break;
                        case EVENT_STILL_WATERS_RUN_DEEP:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_STILL_WATERS_RUN_DEEP, false);
                            events.ScheduleEvent(EVENT_STILL_WATERS_RUN_DEEP, 18000);
                            break;
                        case EVENT_DESPAWN:
                            me->DespawnOrUnsummon();
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
            return new mob_dextrous_izisshaAI(creature);
        }
};

// Julia Bates - 60535
class mob_julia_bates : public CreatureScript
{
    public:
        mob_julia_bates() : CreatureScript("mob_julia_bates") {}

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_CHOICE_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            SendGossipMenuFor(player, 69970, creature->GetGUID());

            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
        {
            player->PlayerTalkClass->ClearMenus();

            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                CloseGossipMenuFor(player);

                if (CHECK_STATUS(30729))
                {
                    creature->AI()->SetGUID(player ? player->GetGUID() : ObjectGuid::Empty);
                    creature->SetFaction(14);

                    if (creature->GetAI())
                    {
                        creature->AI()->Reset();
                        creature->AI()->DoAction(ACTION_REMOVE_FLAG);
                    }
                }
            }
            return true;
        }

        struct mob_julia_batesAI : public ScriptedAI
        {
            mob_julia_batesAI(Creature* creature) : ScriptedAI(creature)
            {
                playerGUID = ObjectGuid::Empty;
            }

            EventMap events;
            ObjectGuid playerGUID;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_HUNDRED_HAND_SLAP, 3000);
                events.ScheduleEvent(EVENT_SOOTHING_MIST, 8000);
            }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                if (Player* player = attacker->ToPlayer())
                {
                    if (CHECK_STATUS(30729))
                    {
                        if (damage > me->GetHealth())
                        {
                            damage = 0;
                            me->SetFullHealth();
                            DoAction(ACTION_REINITIALIZE);
                            player->KilledMonsterCredit(60535);
                            me->DespawnOrUnsummon();
                        }
                    }
                }
            }

            void SetGUID(ObjectGuid guid, int32 index) override
            {
                if (index == 0)
                    playerGUID = guid;
            }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                events.ScheduleEvent(EVENT_DESPAWN, 600000);
            }

            void DoAction(int32 action) override
            {
                if (action == ACTION_REMOVE_FLAG)
                {
                    me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                }

                else if (action == ACTION_REINITIALIZE)
                {
                    me->SetFaction(35);
                    me->CombatStop();
                    me->AddNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (Player* player = ObjectAccessor::FindPlayer(playerGUID))
                {
                    if (!player->IsAlive())
                    {
                        DoAction(ACTION_REINITIALIZE);
                        return;
                    }

                    if (!CHECK_STATUS(30729))
                        me->DespawnOrUnsummon();
                }

                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_HUNDRED_HAND_SLAP:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_HUNDRED_HAND_SLAP, false);
                            events.ScheduleEvent(EVENT_HUNDRED_HAND_SLAP, 7000);
                            break;
                        case EVENT_SOOTHING_MIST:
                            me->CastSpell(me, SPELL_SOOTHING_MIST, false);
                            events.ScheduleEvent(EVENT_SOOTHING_MIST, 7000);
                            break;
                        case EVENT_DESPAWN:
                            me->DespawnOrUnsummon();
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
            return new mob_julia_batesAI(creature);
        }
};

// Kuo-Na Quillpaw - 60537
class mob_kuo_na : public CreatureScript
{
    public:
        mob_kuo_na() : CreatureScript("mob_kuo_na") {}

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_CHOICE_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            SendGossipMenuFor(player, 69970, creature->GetGUID());

            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
        {
            player->PlayerTalkClass->ClearMenus();

            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                CloseGossipMenuFor(player);

                if (CHECK_STATUS(30731))
                {
                    creature->AI()->SetGUID(player ? player->GetGUID() : ObjectGuid::Empty);
                    creature->SetFaction(14);

                    if (creature->GetAI())
                    {
                        creature->AI()->Reset();
                        creature->AI()->DoAction(ACTION_REMOVE_FLAG);
                    }
                }
            }
            return true;
        }

        struct mob_kuo_naAI : public ScriptedAI
        {
            mob_kuo_naAI(Creature* creature) : ScriptedAI(creature)
            {
                playerGUID = ObjectGuid::Empty;
            }

            EventMap events;
            ObjectGuid playerGUID;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_FLYING_SERPENT_KICK_2, 3000);
                events.ScheduleEvent(EVENT_PAW_PUNCH, 8000);
                events.ScheduleEvent(EVENT_UPPERCUT_2, 15000);
            }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                if (Player* player = attacker->ToPlayer())
                {
                    if (CHECK_STATUS(30731))
                    {
                        if (damage > me->GetHealth())
                        {
                            damage = 0;
                            me->SetFullHealth();
                            DoAction(ACTION_REINITIALIZE);
                            player->KilledMonsterCredit(60537);
                            me->DespawnOrUnsummon();
                        }
                    }
                }
            }

            void SetGUID(ObjectGuid guid, int32 index) override
            {
                if (index == 0)
                    playerGUID = guid;
            }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                events.ScheduleEvent(EVENT_DESPAWN, 600000);
            }

            void DoAction(int32 action) override
            {
                if (action == ACTION_REMOVE_FLAG)
                {
                    me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                }

                else if (action == ACTION_REINITIALIZE)
                {
                    me->SetFaction(35);
                    me->CombatStop();
                    me->AddNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (Player* player = ObjectAccessor::FindPlayer(playerGUID))
                {
                    if (!player->IsAlive())
                    {
                        DoAction(ACTION_REINITIALIZE);
                        return;
                    }

                    if (!CHECK_STATUS(30731))
                        me->DespawnOrUnsummon();
                }

                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_FLYING_SERPENT_KICK_2:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_FLYING_SERPENT_KICK, false);
                            events.ScheduleEvent(EVENT_FLYING_SERPENT_KICK_2, 21000);
                            break;
                        case EVENT_PAW_PUNCH:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_PAW_PUNCH, false);
                            events.ScheduleEvent(EVENT_PAW_PUNCH, 21000);
                            break;
                        case EVENT_UPPERCUT_2:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_UPPERCUT, false);
                            events.ScheduleEvent(EVENT_UPPERCUT_2, 21000);
                            break;
                        case EVENT_DESPAWN:
                            me->DespawnOrUnsummon();
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
            return new mob_kuo_naAI(creature);
        }
};

// Mindel Sunspeaker - 60541
class mob_mindel_sunspeaker : public CreatureScript
{
    public:
        mob_mindel_sunspeaker() : CreatureScript("mob_mindel_sunspeaker") {}

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_CHOICE_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            SendGossipMenuFor(player, 69970, creature->GetGUID());

            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
        {
            player->PlayerTalkClass->ClearMenus();

            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                CloseGossipMenuFor(player);

                if (CHECK_STATUS(30735))
                {
                    creature->AI()->SetGUID(player ? player->GetGUID() : ObjectGuid::Empty);
                    creature->SetFaction(14);

                    if (creature->GetAI())
                    {
                        creature->AI()->Reset();
                        creature->AI()->DoAction(ACTION_REMOVE_FLAG);
                    }
                }
            }
            return true;
        }

        struct mob_mindel_sunspeakerAI : public ScriptedAI
        {
            mob_mindel_sunspeakerAI(Creature* creature) : ScriptedAI(creature)
            {
                playerGUID = ObjectGuid::Empty;
            }

            EventMap events;
            ObjectGuid playerGUID;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_SUNFLARE_KICK, 3000);
                events.ScheduleEvent(EVENT_SUNSTRIKE, 8000);
            }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                if (Player* player = attacker->ToPlayer())
                {
                    if (CHECK_STATUS(30735))
                    {
                        if (damage > me->GetHealth())
                        {
                            damage = 0;
                            me->SetFullHealth();
                            DoAction(ACTION_REINITIALIZE);
                            player->KilledMonsterCredit(60541);
                            me->DespawnOrUnsummon();
                        }
                    }
                }
            }

            void SetGUID(ObjectGuid guid, int32 index) override
            {
                if (index == 0)
                    playerGUID = guid;
            }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                events.ScheduleEvent(EVENT_DESPAWN, 600000);
            }

            void DoAction(int32 action) override
            {
                if (action == ACTION_REMOVE_FLAG)
                {
                    me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                }

                else if (action == ACTION_REINITIALIZE)
                {
                    me->SetFaction(35);
                    me->CombatStop();
                    me->AddNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (Player* player = ObjectAccessor::FindPlayer(playerGUID))
                {
                    if (!player->IsAlive())
                    {
                        DoAction(ACTION_REINITIALIZE);
                        return;
                    }

                    if (!CHECK_STATUS(30735))
                        me->DespawnOrUnsummon();
                }

                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SUNFLARE_KICK:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_SUNFLARE_KICK, false);
                            events.ScheduleEvent(EVENT_SUNFLARE_KICK, 12000);
                            break;
                        case EVENT_SUNSTRIKE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_SUNSTRIKE, false);
                            events.ScheduleEvent(EVENT_SUNSTRIKE, 12000);
                            break;
                        case EVENT_DESPAWN:
                            me->DespawnOrUnsummon();
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
            return new mob_mindel_sunspeakerAI(creature);
        }
};

// Minh Do-Tan - 60532
class mob_minh_do_tan : public CreatureScript
{
    public:
        mob_minh_do_tan() : CreatureScript("mob_minh_do_tan") {}

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_CHOICE_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            SendGossipMenuFor(player, 69970, creature->GetGUID());

            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
        {
            player->PlayerTalkClass->ClearMenus();

            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                CloseGossipMenuFor(player);

                if (CHECK_STATUS(30726))
                {
                    creature->AI()->SetGUID(player ? player->GetGUID() : ObjectGuid::Empty);
                    creature->SetFaction(14);

                    if (creature->GetAI())
                    {
                        creature->AI()->Reset();
                        creature->AI()->DoAction(ACTION_REMOVE_FLAG);
                    }
                }
            }
            return true;
        }

        struct mob_minh_do_tanAI : public ScriptedAI
        {
            mob_minh_do_tanAI(Creature* creature) : ScriptedAI(creature)
            {
                playerGUID = ObjectGuid::Empty;
            }

            EventMap events;
            ObjectGuid playerGUID;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_SUNFLARE_KICK, 3000);
                events.ScheduleEvent(EVENT_SUNSTRIKE, 8000);
            }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                if (Player* player = attacker->ToPlayer())
                {
                    if (CHECK_STATUS(30726))
                    {
                        if (damage > me->GetHealth())
                        {
                            damage = 0;
                            me->SetFullHealth();
                            DoAction(ACTION_REINITIALIZE);
                            player->KilledMonsterCredit(60532);
                            me->DespawnOrUnsummon();
                        }
                    }
                }
            }

            void SetGUID(ObjectGuid guid, int32 index) override
            {
                if (index == 0)
                    playerGUID = guid;
            }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                events.ScheduleEvent(EVENT_DESPAWN, 600000);
            }

            void DoAction(int32 action) override
            {
                if (action == ACTION_REMOVE_FLAG)
                {
                    me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                }

                else if (action == ACTION_REINITIALIZE)
                {
                    me->SetFaction(35);
                    me->CombatStop();
                    me->AddNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (Player* player = ObjectAccessor::FindPlayer(playerGUID))
                {
                    if (!player->IsAlive())
                    {
                        DoAction(ACTION_REINITIALIZE);
                        return;
                    }

                    if (!CHECK_STATUS(30726))
                        me->DespawnOrUnsummon();
                }

                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SPINNING_CRANE_KICK:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_SPINNING_CRANE_KICK, false);
                            events.ScheduleEvent(EVENT_SPINNING_CRANE_KICK, 12000);
                            break;
                        case EVENT_VICIOUS_KICK:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_VICIOUS_KICK, false);
                            events.ScheduleEvent(EVENT_VICIOUS_KICK, 12000);
                            break;
                        case EVENT_DESPAWN:
                            me->DespawnOrUnsummon();
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
            return new mob_minh_do_tanAI(creature);
        }
};

// Thelonius - 60544
class mob_thelonius : public CreatureScript
{
    public:
        mob_thelonius() : CreatureScript("mob_thelonius") {}

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_CHOICE_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            SendGossipMenuFor(player, 69970, creature->GetGUID());

            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
        {
            player->PlayerTalkClass->ClearMenus();

            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                CloseGossipMenuFor(player);

                if (CHECK_STATUS(30738))
                {
                    creature->AI()->SetGUID(player ? player->GetGUID() : ObjectGuid::Empty);
                    creature->SetFaction(14);

                    if (creature->GetAI())
                    {
                        creature->AI()->Reset();
                        creature->AI()->DoAction(ACTION_REMOVE_FLAG);
                    }
                }
            }
            return true;
        }

        struct mob_theloniusAI : public ScriptedAI
        {
            mob_theloniusAI(Creature* creature) : ScriptedAI(creature)
            {
                playerGUID = ObjectGuid::Empty;
            }

            EventMap events;
            ObjectGuid playerGUID;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_UPPERCUT, 3000);
                events.ScheduleEvent(EVENT_SPINNING_CRANE_KICK, 8000);
                events.ScheduleEvent(EVENT_HUNDRED_HAND_SLAP, 13000);
                events.ScheduleEvent(EVENT_FLYING_SERPENT_KICK, 20000);
            }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                if (Player* player = attacker->ToPlayer())
                {
                    if (CHECK_STATUS(30738))
                    {
                        if (damage > me->GetHealth())
                        {
                            damage = 0;
                            me->SetFullHealth();
                            DoAction(ACTION_REINITIALIZE);
                            player->KilledMonsterCredit(60544);
                            me->DespawnOrUnsummon();
                        }
                    }
                }
            }

            void SetGUID(ObjectGuid guid, int32 index) override
            {
                if (index == 0)
                    playerGUID = guid;
            }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                events.ScheduleEvent(EVENT_DESPAWN, 600000);
            }

            void DoAction(int32 action) override
            {
                if (action == ACTION_REMOVE_FLAG)
                {
                    me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                }

                else if (action == ACTION_REINITIALIZE)
                {
                    me->SetFaction(35);
                    me->CombatStop();
                    me->AddNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (Player* player = ObjectAccessor::FindPlayer(playerGUID))
                {
                    if (!player->IsAlive())
                    {
                        DoAction(ACTION_REINITIALIZE);
                        return;
                    }

                    if (!CHECK_STATUS(30738))
                        me->DespawnOrUnsummon();
                }

                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_UPPERCUT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_UPPERCUT, false);
                            events.ScheduleEvent(EVENT_UPPERCUT, 25000);
                            break;
                        case EVENT_SPINNING_CRANE_KICK:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_SPINNING_CRANE_KICK, false);
                            events.ScheduleEvent(EVENT_SPINNING_CRANE_KICK, 25000);
                            break;
                        case EVENT_HUNDRED_HAND_SLAP:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_HUNDRED_HAND_SLAP, false);
                            events.ScheduleEvent(EVENT_HUNDRED_HAND_SLAP, 25000);
                            break;
                        case EVENT_FLYING_SERPENT_KICK:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_FLYING_SERPENT_KICK, false);
                            events.ScheduleEvent(EVENT_FLYING_SERPENT_KICK, 25000);
                            break;
                        case EVENT_DESPAWN:
                            me->DespawnOrUnsummon();
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
            return new mob_theloniusAI(creature);
        }
};

// Tukka-Tuk - 60539
class mob_tukka_tuk : public CreatureScript
{
    public:
        mob_tukka_tuk() : CreatureScript("mob_tukka_tuk") {}

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_CHOICE_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            SendGossipMenuFor(player, 69970, creature->GetGUID());

            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
        {
            player->PlayerTalkClass->ClearMenus();

            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                CloseGossipMenuFor(player);

                if (CHECK_STATUS(30733))
                {
                    creature->AI()->SetGUID(player ? player->GetGUID() : ObjectGuid::Empty);
                    creature->SetFaction(14);

                    if (creature->GetAI())
                    {
                        creature->AI()->Reset();
                        creature->AI()->DoAction(ACTION_REMOVE_FLAG);
                    }
                }
            }
            return true;
        }

        struct mob_tukka_tukAI : public ScriptedAI
        {
            mob_tukka_tukAI(Creature* creature) : ScriptedAI(creature)
            {
                playerGUID = ObjectGuid::Empty;
            }

            EventMap events;
            ObjectGuid playerGUID;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_POUND_YOU, 3000);
                events.ScheduleEvent(EVENT_KICK_YOU, 8000);
                events.ScheduleEvent(EVENT_PUNCH_YOU, 13000);
            }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                if (Player* player = attacker->ToPlayer())
                {
                    if (CHECK_STATUS(30733))
                    {
                        if (damage > me->GetHealth())
                        {
                            damage = 0;
                            me->SetFullHealth();
                            DoAction(ACTION_REINITIALIZE);
                            player->KilledMonsterCredit(60539);
                            me->DespawnOrUnsummon();
                        }
                    }
                }
            }

            void SetGUID(ObjectGuid guid, int32 index) override
            {
                if (index == 0)
                    playerGUID = guid;
            }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                events.ScheduleEvent(EVENT_DESPAWN, 600000);
            }

            void DoAction(int32 action) override
            {
                if (action == ACTION_REMOVE_FLAG)
                {
                    me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                }

                else if (action == ACTION_REINITIALIZE)
                {
                    me->SetFaction(35);
                    me->CombatStop();
                    me->AddNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (Player* player = ObjectAccessor::FindPlayer(playerGUID))
                {
                    if (!player->IsAlive())
                    {
                        DoAction(ACTION_REINITIALIZE);
                        return;
                    }

                    if (!CHECK_STATUS(30733))
                        me->DespawnOrUnsummon();
                }

                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_POUND_YOU:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_POUND_YOU, false);
                            events.ScheduleEvent(EVENT_POUND_YOU, 20000);
                            break;
                        case EVENT_KICK_YOU:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_KICK_YOU, false);
                            events.ScheduleEvent(EVENT_KICK_YOU, 20000);
                            break;
                        case EVENT_PUNCH_YOU:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_PUNCH_YOU, false);
                            events.ScheduleEvent(EVENT_PUNCH_YOU, 20000);
                            break;
                        case EVENT_DESPAWN:
                            me->DespawnOrUnsummon();
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
            return new mob_tukka_tukAI(creature);
        }
};

// Yan Quillpaw - 60542
class mob_yan_quillpaw : public CreatureScript
{
    public:
        mob_yan_quillpaw() : CreatureScript("mob_yan_quillpaw") {}

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_CHOICE_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            SendGossipMenuFor(player, 69970, creature->GetGUID());

            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
        {
            player->PlayerTalkClass->ClearMenus();

            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                CloseGossipMenuFor(player);

                if (CHECK_STATUS(30736))
                {
                    creature->AI()->SetGUID(player ? player->GetGUID() : ObjectGuid::Empty);
                    creature->SetFaction(14);

                    if (creature->GetAI())
                    {
                        creature->AI()->Reset();
                        creature->AI()->DoAction(ACTION_REMOVE_FLAG);
                    }
                }
            }
            return true;
        }

        struct mob_yan_quillpawAI : public ScriptedAI
        {
            mob_yan_quillpawAI(Creature* creature) : ScriptedAI(creature)
            {
                playerGUID = ObjectGuid::Empty;
            }

            EventMap events;
            ObjectGuid playerGUID;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_UPPERCUT, 3000);
                events.ScheduleEvent(EVENT_FLYING_SERPENT_KICK, 8000);
                events.ScheduleEvent(EVENT_PAW_PUNCH, 13000);
            }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                if (Player* player = attacker->ToPlayer())
                {
                    if (CHECK_STATUS(30736))
                    {
                        if (damage > me->GetHealth())
                        {
                            damage = 0;
                            me->SetFullHealth();
                            DoAction(ACTION_REINITIALIZE);
                            player->KilledMonsterCredit(60542);
                            me->DespawnOrUnsummon();
                        }
                    }
                }
            }

            void SetGUID(ObjectGuid guid, int32 index) override
            {
                if (index == 0)
                    playerGUID = guid;
            }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                events.ScheduleEvent(EVENT_DESPAWN, 600000);
            }

            void DoAction(int32 action) override
            {
                if (action == ACTION_REMOVE_FLAG)
                {
                    me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                }

                else if (action == ACTION_REINITIALIZE)
                {
                    me->SetFaction(35);
                    me->CombatStop();
                    me->AddNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (Player* player = ObjectAccessor::FindPlayer(playerGUID))
                {
                    if (!player->IsAlive())
                    {
                        DoAction(ACTION_REINITIALIZE);
                        return;
                    }

                    if (!CHECK_STATUS(30736))
                        me->DespawnOrUnsummon();
                }

                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_UPPERCUT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_UPPERCUT, false);
                            events.ScheduleEvent(EVENT_UPPERCUT, 20000);
                            break;
                        case EVENT_FLYING_SERPENT_KICK:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_FLYING_SERPENT_KICK, false);
                            events.ScheduleEvent(EVENT_FLYING_SERPENT_KICK, 20000);
                            break;
                        case EVENT_PAW_PUNCH:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_PAW_PUNCH, false);
                            events.ScheduleEvent(EVENT_PAW_PUNCH, 20000);
                            break;
                        case EVENT_DESPAWN:
                            me->DespawnOrUnsummon();
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
            return new mob_yan_quillpawAI(creature);
        }
};

void AddSC_krasarang_wilds()
{
    new mob_gaarn_the_toxic();
    new mob_arness_the_scale();
    new mob_qu_nas();
    new mob_torik_ethis();
    new mob_go_kan();
    new mob_spirit_of_the_crane();
    new mob_champion_of_chi_ji();
    new spell_chi_torpedo_periodic();
    new mob_anduin_wrynn();
    new mob_anduin_wrynn_escort();
    new npc_chi_ji();
    new mob_sha_of_despair();
    new npc_thelonius();
    new mob_ellia_ravenmane();
    new mob_fat_long_fat();
    new mob_huck_wheelbarrow();
    new mob_dextrous_izissha();
    new mob_julia_bates();
    new mob_kuo_na();
    new mob_mindel_sunspeaker();
    new mob_minh_do_tan();
    new mob_thelonius();
    new mob_tukka_tuk();
    new mob_yan_quillpaw();
}
