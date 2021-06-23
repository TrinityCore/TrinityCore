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
#include "LootMgr.h"
#include "GameObject.h"
#include "Player.h"
#include "ObjectMgr.h"
#include "jade_forest.h"

#define REPUTATION_ORDER_OF_THE_CLOUD_SERPENT 1271
#define GOSSIP_TEXT_I 12585
#define GOSSIP_CHOICE_2 "Let's see which one of us is the better student. I challenge you to a duel !"
#define GOSSIP_CHOICE_1 "Challenge the Patriarch."

// Shadow of Doubt - 57389
class mob_shadow_of_doubt : public CreatureScript
{
    public:
        mob_shadow_of_doubt() : CreatureScript("mob_shadow_of_doubt") {}

        struct mob_shadow_of_doubtAI : public ScriptedAI
        {
            mob_shadow_of_doubtAI(Creature* creature) : ScriptedAI(creature) {}

            EventMap events;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_DEAFENED, 30000);
                events.ScheduleEvent(EVENT_GROWING_DOUBT, 9000);
                events.ScheduleEvent(EVENT_SHA_BOLT, 15000);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_DEAFENED:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_DEAFENED, false);
                            events.ScheduleEvent(EVENT_DEAFENED, 30000);
                            break;
                        case EVENT_GROWING_DOUBT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_GROWING_DOUBT, false);
                            events.ScheduleEvent(EVENT_GROWING_DOUBT, 9000);
                            break;
                        case EVENT_SHA_BOLT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_SHA_BOLT, false);
                            events.ScheduleEvent(EVENT_SHA_BOLT, 15000);
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
            return new mob_shadow_of_doubtAI(creature);
        }
};

// Kor'nas Nightsavage - 50338
class mob_kor_nas_nightsavage : public CreatureScript
{
    public:
        mob_kor_nas_nightsavage() : CreatureScript("mob_kor_nas_nightsavage") {}

        struct mob_kor_nas_nightsavageAI : public ScriptedAI
        {
            mob_kor_nas_nightsavageAI(Creature* creature) : ScriptedAI(creature) {}

            EventMap events;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_SHADOWBOLT, 50000);
                events.ScheduleEvent(EVENT_VOIDCLOUD, 15000);
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
                            events.ScheduleEvent(EVENT_SHADOWBOLT, 70000);
                            break;
                        case EVENT_VOIDCLOUD:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_VOIDCLOUD, false);
                            events.ScheduleEvent(EVENT_VOIDCLOUD, 35000);
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
            return new mob_kor_nas_nightsavageAI(creature);
        }
};

// Krax'ik - 50363
class mob_krax_ik : public CreatureScript
{
    public:
        mob_krax_ik() : CreatureScript("mob_krax_ik") {}

        struct mob_krax_ikAI : public ScriptedAI
        {
            mob_krax_ikAI(Creature* creature) : ScriptedAI(creature) {}

            EventMap events;

            void Reset() override
            {
                events.Reset();

                me->CastSpell(me, SPELL_STEALTH, true);

                events.ScheduleEvent(EVENT_TORNADO, 5000);
                events.ScheduleEvent(EVENT_BLADE_FURY, 25000);
                events.ScheduleEvent(EVENT_WINDSONG, 30000);
            }

            void EnterCombat(Unit* /*attacker*/) override
            {
                me->RemoveAurasDueToSpell(SPELL_STEALTH);
            }

            void JustSummoned(Creature* summon) override
            {
                if (summon->GetEntry() == 64267)
                {
                    summon->DespawnOrUnsummon(15000);
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
                        case EVENT_TORNADO:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_TORNADO, false);
                            events.ScheduleEvent(EVENT_TORNADO, 70000);
                            break;
                        case EVENT_BLADE_FURY:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_BLADE_FURY, false);
                            events.ScheduleEvent(EVENT_BLADE_FURY, 20000);
                            break;
                        case EVENT_WINDSONG:
                            me->CastSpell(me, SPELL_WINDSONG, false);
                            events.ScheduleEvent(EVENT_WINDSONG, 30000);
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
            return new mob_krax_ikAI(creature);
        }
};

// Mister Ferocious - 50823
class mob_mister_ferocious : public CreatureScript
{
    public:
        mob_mister_ferocious() : CreatureScript("mob_mister_ferocious") {}

        struct mob_mister_ferociousAI : public ScriptedAI
        {
            mob_mister_ferociousAI(Creature* creature) : ScriptedAI(creature) {}

            EventMap events;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_GOING_BANANAS, 12000);
                events.ScheduleEvent(EVENT_BANANARANG, 8000);
                events.ScheduleEvent(EVENT_TOSS_FILTH, 15000);
            }

            void JustSummoned(Creature* summon) override
            {
                summon->DespawnOrUnsummon(12000);
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
                        case EVENT_GOING_BANANAS:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_GOING_BANANAS, false);
                            events.ScheduleEvent(EVENT_GOING_BANANAS, 10000);
                            break;
                        case EVENT_BANANARANG:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_BANANARANG, false);
                            events.ScheduleEvent(EVENT_BANANARANG, 20000);
                            break;
                        case EVENT_TOSS_FILTH:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_TOSS_FILTH, false);
                            events.ScheduleEvent(EVENT_TOSS_FILTH, 15000);
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
            return new mob_mister_ferociousAI(creature);
        }
};

// Akkalar - 66937
class mob_akkalar : public CreatureScript
{
    public:
        mob_akkalar() : CreatureScript("mob_akkalar") {}

        struct mob_akkalarAI : public ScriptedAI
        {
            mob_akkalarAI(Creature* creature) : ScriptedAI(creature) {}

            EventMap events;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_BOUCLIER_D_EAU, 10000);
                events.ScheduleEvent(EVENT_BOUCLIER_D_EAU_2, 20000);
                events.ScheduleEvent(EVENT_BOUCLIER_DE_TERRE, 30000);
                events.ScheduleEvent(EVENT_CARAPACE_BOUCLIER, 40000);
                events.ScheduleEvent(EVENT_MOT_DE_POUVOIR, 50000);
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
                        case EVENT_BOUCLIER_D_EAU:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_BOUCLIER_D_EAU, false);
                            events.ScheduleEvent(EVENT_BOUCLIER_D_EAU, 62000);
                            break;
                        case EVENT_BOUCLIER_D_EAU_2:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_BOUCLIER_D_EAU_2, false);
                            events.ScheduleEvent(EVENT_BOUCLIER_D_EAU_2, 70000);
                            break;
                        case EVENT_BOUCLIER_DE_TERRE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_BOUCLIER_DE_TERRE, false);
                            events.ScheduleEvent(EVENT_BOUCLIER_DE_TERRE, 80000);
                            break;
                        case EVENT_CARAPACE_BOUCLIER:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_CARAPACE_BOUCLIER, false);
                            events.ScheduleEvent(EVENT_CARAPACE_BOUCLIER, 90000);
                            break;
                        case EVENT_MOT_DE_POUVOIR:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_MOT_DE_POUVOIR, false);
                            events.ScheduleEvent(EVENT_MOT_DE_POUVOIR, 100000);
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
            return new mob_akkalarAI(creature);
        }
};

// Grookin Outrunner - 67149
class mob_grookin_outrunner : public CreatureScript
{
    public:
        mob_grookin_outrunner() : CreatureScript("mob_grookin_outrunner") {}

        struct mob_grookin_outrunnerAI : public ScriptedAI
        {
            mob_grookin_outrunnerAI(Creature* creature) : ScriptedAI(creature) {}

            EventMap events;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_SHOOT, 7000);
                events.ScheduleEvent(EVENT_CLEAVE, 12000);
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
                        case EVENT_SHOOT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_SHOOT, false);
                            events.ScheduleEvent(EVENT_SHOOT, 10000);
                            break;
                        case EVENT_CLEAVE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_CLEAVE, false);
                            events.ScheduleEvent(EVENT_CLEAVE, 10000);
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
            return new mob_grookin_outrunnerAI(creature);
        }
};

// Bamboo Python - 59769
class mob_bamboo_python : public CreatureScript
{
    public:
        mob_bamboo_python() : CreatureScript("mob_bamboo_python") {}

        struct mob_bamboo_pythonAI : public ScriptedAI
        {
            mob_bamboo_pythonAI(Creature* creature) : ScriptedAI(creature) {}

            EventMap events;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_SWAMP_FEVER, 7000);
            }

            void EnterCombat(Unit* /*attacker*/) override
            {
                me->RemoveAurasDueToSpell(SPELL_STEALTH);
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
                    if (eventId == EVENT_SWAMP_FEVER)
                    {
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_SWAMP_FEVER, false);
                            events.ScheduleEvent(EVENT_SWAMP_FEVER, 15000);
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_bamboo_pythonAI(creature);
        }
};

// Rakira - 66622
class mob_rakira : public CreatureScript
{
    public:
        mob_rakira() : CreatureScript("mob_rakira") {}

        struct mob_rakiraAI : public ScriptedAI
        {
            mob_rakiraAI(Creature* creature) : ScriptedAI(creature) {}

            EventMap events;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_BLOODY_PREY, 8000);
                events.ScheduleEvent(EVENT_CLAW_RIP, 15000);
                events.ScheduleEvent(EVENT_GROWL, 22000);
                events.ScheduleEvent(EVENT_HOWL_OF_THE_DENMOTHER, 30000);
                events.ScheduleEvent(EVENT_ROAR_OF_COURAGE, 40000);
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
                        case EVENT_BLOODY_PREY:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_BLOODY_PREY, false);
                            events.ScheduleEvent(EVENT_BLOODY_PREY, 10000);
                            break;
                        case EVENT_CLAW_RIP:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_CLAW_RIP, false);
                            events.ScheduleEvent(EVENT_CLAW_RIP, 15000);
                            break;
                        case EVENT_GROWL:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_GROWL, false);
                            events.ScheduleEvent(EVENT_GROWL, 22000);
                            break;
                        case EVENT_HOWL_OF_THE_DENMOTHER:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_HOWL_OF_THE_DENMOTHER, false);
                            events.ScheduleEvent(EVENT_HOWL_OF_THE_DENMOTHER, 30000);
                            break;
                        case EVENT_ROAR_OF_COURAGE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_ROAR_OF_COURAGE, false);
                            events.ScheduleEvent(EVENT_ROAR_OF_COURAGE, 47000);
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
            return new mob_rakiraAI(creature);
        }
};

// Ro'shen - 66617
class mob_ro_shen : public CreatureScript
{
    public:
        mob_ro_shen() : CreatureScript("mob_ro_shen") {}

        struct mob_ro_shenAI : public ScriptedAI
        {
            mob_ro_shenAI(Creature* creature) : ScriptedAI(creature) {}

            EventMap events;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_BLOODY_PREY, 8000);
                events.ScheduleEvent(EVENT_CLAW_RIP, 15000);
                events.ScheduleEvent(EVENT_GROWL, 22000);
                events.ScheduleEvent(EVENT_ROAR_OF_COURAGE, 30000);
                events.ScheduleEvent(EVENT_BLOOD_CRAZED, 40000);
                events.ScheduleEvent(EVENT_BLOODTHIRST, 50000);
                events.ScheduleEvent(EVENT_CLAW_SLASH, 60000);
                events.ScheduleEvent(EVENT_FRENZY, 70000);
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
                        case EVENT_BLOODY_PREY:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_BLOODY_PREY, false);
                            events.ScheduleEvent(EVENT_BLOODY_PREY, 10000);
                            break;
                        case EVENT_CLAW_RIP:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_CLAW_RIP, false);
                            events.ScheduleEvent(EVENT_CLAW_RIP, 15000);
                            break;
                        case EVENT_GROWL:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_GROWL, false);
                            events.ScheduleEvent(EVENT_GROWL, 28000);
                            break;
                        case EVENT_ROAR_OF_COURAGE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_ROAR_OF_COURAGE, false);
                            events.ScheduleEvent(EVENT_ROAR_OF_COURAGE, 70000);
                            break;
                        case EVENT_BLOOD_CRAZED:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_BLOOD_CRAZED, false);
                            events.ScheduleEvent(EVENT_BLOOD_CRAZED, 31000);
                            break;
                        case EVENT_BLOODTHIRST:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_BLOODTHIRST, false);
                            events.ScheduleEvent(EVENT_BLOODTHIRST, 40000);
                            break;
                        case EVENT_CLAW_SLASH:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_CLAW_SLASH, false);
                            events.ScheduleEvent(EVENT_CLAW_SLASH, 25000);
                            break;
                        case EVENT_FRENZY:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_FRENZY, false);
                            events.ScheduleEvent(EVENT_FRENZY, 50000);
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
            return new mob_ro_shenAI(creature);
        }
};

// Sha Remnant - 59434
class mob_sha_reminant : public CreatureScript
{
    public:
        mob_sha_reminant() : CreatureScript("mob_sha_reminant") {}

        struct mob_sha_reminantAI : public ScriptedAI
        {
            mob_sha_reminantAI(Creature* creature) : ScriptedAI(creature) {}

            EventMap events;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_SHADOW_CLAW, 10000);
                events.ScheduleEvent(EVENT_OVERWHELMING_GUILT, 15000);
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
                        case EVENT_SHADOW_CLAW:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_SHADOW_CLAW, false);
                            events.ScheduleEvent(EVENT_SHADOW_CLAW, 10000);
                            break;
                        case EVENT_OVERWHELMING_GUILT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_OVERWHELMING_GUILT, false);
                            events.ScheduleEvent(EVENT_OVERWHELMING_GUILT, 15000);
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
            return new mob_sha_reminantAI(creature);
        }
};

// Pandriarch Windfur - 56206
class mob_pandriarch_windfur : public CreatureScript
{
    public:
        mob_pandriarch_windfur() : CreatureScript("mob_pandriarch_windfur") {}

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_CHOICE_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            SendGossipMenuFor(player, 75009, creature->GetGUID());

            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
        {
            player->PlayerTalkClass->ClearMenus();

            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                if (player->GetQuestStatus(QUEST_GETTING_PERMISSION) == QUEST_STATUS_INCOMPLETE)
                {
                    creature->SetFaction(14);
                    creature->SetReactState(REACT_DEFENSIVE);
                    creature->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                    creature->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
                    creature->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                    creature->AI()->Reset();
                    creature->CombatStart(player, true);
                }

                CloseGossipMenuFor(player);
            }

            return true;
        }

        struct mob_pandriarch_windfurAI : public ScriptedAI
        {
            mob_pandriarch_windfurAI(Creature* creature) : ScriptedAI(creature) {}

            EventMap events;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_THUNDERING_PALM, urand (3000, 7000));
                events.ScheduleEvent(EVENT_WIND_SWORD, urand (8000, 10000));
//                events.ScheduleEvent(EVENT_WINDFUR_PUNCH, urand (13000, 17000));
            }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                if (Player* player = attacker->ToPlayer())
                {
                    if (me->HealthBelowPctDamaged(10, damage))
                    {
                        damage = 0;
                        me->CombatStop();
                        me->GetMotionMaster()->MovePoint(0, 1996.76001f, -2216.780029f, 247.725006f);
                        me->SetFaction(35);
                        me->SetFullHealth();
                        me->AddUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                        me->AddUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
                        me->AddNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                        player->KilledMonsterCredit(NPC_PANDRIARCH_WINDFUR);
                    }

                    if (damage > me->GetHealth())
                        damage = 0;
                }
            }

            void EnterCombat(Unit* who) override
            {
                if (Player* player = who->ToPlayer())
                {
                    if (player->GetQuestStatus(QUEST_GETTING_PERMISSION) == QUEST_STATUS_INCOMPLETE)
                        return;

                    else
                    {
                        me->CombatStop();
                        me->SetFaction(35);
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
                        case EVENT_THUNDERING_PALM:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_THUNDERING_PALM, false);
                            events.ScheduleEvent(EVENT_THUNDERING_PALM, 10000);
                            break;
                        case EVENT_WIND_SWORD:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_WIND_SWORD, false);
                            events.ScheduleEvent(EVENT_WIND_SWORD, 15000);
                            break;
                        case EVENT_WINDFUR_PUNCH:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_WINDFUR_PUNCH, false);
                            events.ScheduleEvent(EVENT_WINDFUR_PUNCH, 15000);
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
            return new mob_pandriarch_windfurAI(creature);
        }
};

// Pandriarch Bramblestaff - 56209
class mob_pandriarch_bramblestaff : public CreatureScript
{
    public:
        mob_pandriarch_bramblestaff() : CreatureScript("mob_pandriarch_bramblestaff") {}

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_CHOICE_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            SendGossipMenuFor(player, 75010, creature->GetGUID());

            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
        {
            player->PlayerTalkClass->ClearMenus();

            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                if (player->GetQuestStatus(QUEST_GETTING_PERMISSION) == QUEST_STATUS_INCOMPLETE)
                {
                    creature->SetFaction(14);
                    creature->SetReactState(REACT_DEFENSIVE);
                    creature->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                    creature->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
                    creature->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                    creature->AI()->Reset();
                    creature->CombatStart(player, true);
                }

                CloseGossipMenuFor(player);
            }

            return true;
        }

        struct mob_pandriarch_bramblestaffAI : public ScriptedAI
        {
            mob_pandriarch_bramblestaffAI(Creature* creature) : ScriptedAI(creature) {}

            EventMap events;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_ROLL, urand (3000, 7000));
                events.ScheduleEvent(EVENT_STAFF_STRIKE, urand (8000, 10000));
                events.ScheduleEvent(EVENT_THROW_BRAMBLESTAFF, urand (13000, 17000));
                // events.ScheduleEvent(EVENT_WHIRLWIND, urand (20000, 23000));
                // events.ScheduleEvent(EVENT_WHIRLWIND_2, urand (24000, 27000));
            }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                if (Player* player = attacker->ToPlayer())
                {
                    if (me->HealthBelowPctDamaged(10, damage) || damage > me->GetHealth())
                    {
                        damage = 0;
                        me->CombatStop();
                        me->GetMotionMaster()->MovePoint(0, 1862.300049f, -2325.060059f, 257.062012f);
                        me->SetFaction(35);
                        me->SetFullHealth();
                        me->AddUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                        me->AddUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
                        me->AddNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                        player->KilledMonsterCredit(NPC_PANDRIARCH_BRAMBLESTAFF);
                    }
                }
            }

            void EnterCombat(Unit* who) override
            {
                if (Player* player = who->ToPlayer())
                {
                    if (player->GetQuestStatus(QUEST_GETTING_PERMISSION) == QUEST_STATUS_INCOMPLETE)
                        return;

                    else
                    {
                        me->CombatStop();
                        me->SetFaction(35);
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
                        case EVENT_ROLL:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_ROLL, false);
                            events.ScheduleEvent(EVENT_ROLL,      10000);
                            break;
                        case EVENT_STAFF_STRIKE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_STAFF_STRIKE, false);
                            events.ScheduleEvent(EVENT_STAFF_STRIKE,      10000);
                            break;
                        case EVENT_THROW_BRAMBLESTAFF:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_THROW_BRAMBLESTAFF, false);
                            events.ScheduleEvent(EVENT_THROW_BRAMBLESTAFF,      10000);
                            break;
                        case EVENT_WHIRLWIND:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_WHIRLWIND, false);
                            events.ScheduleEvent(EVENT_WHIRLWIND,      10000);
                            break;
                        case EVENT_WHIRLWIND_2:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_WHIRLWIND_2, false);
                            events.ScheduleEvent(EVENT_WHIRLWIND_2,      10000);
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
            return new mob_pandriarch_bramblestaffAI(creature);
        }
};

// Pandriarch Goldendraft - 56210
class mob_pandriarch_goldendraft : public CreatureScript
{
    public:
        mob_pandriarch_goldendraft() : CreatureScript("mob_pandriarch_goldendraft") {}

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_CHOICE_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            SendGossipMenuFor(player, 75010, creature->GetGUID());

            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
        {
            player->PlayerTalkClass->ClearMenus();

            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                if (player->GetQuestStatus(QUEST_GETTING_PERMISSION) == QUEST_STATUS_INCOMPLETE)
                {
                    creature->SetFaction(14);
                    creature->SetReactState(REACT_DEFENSIVE);
                    creature->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                    creature->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
                    creature->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                    creature->AI()->Reset();
                    creature->CombatStart(player, true);
                }

                CloseGossipMenuFor(player);
            }

            return true;
        }

        struct mob_pandriarch_goldendraftAI : public ScriptedAI
        {
            mob_pandriarch_goldendraftAI(Creature* creature) : ScriptedAI(creature) {}

            EventMap events;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_EXPLOSIVE_LAGER, urand (3000, 7000));
                events.ScheduleEvent(EVENT_FIRE_ALE, urand (8000, 10000));
            }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                if (Player* player = attacker->ToPlayer())
                {
                    if (me->HealthBelowPctDamaged(10, damage) || damage > me->GetHealth())
                    {
                        damage = 0;
                        me->CombatStop();
                        me->GetMotionMaster()->MovePoint(0, 1942.630005f, -2290.530029f, 240.429001f);
                        me->SetFaction(35);
                        me->SetFullHealth();
                        me->AddUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                        me->AddUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
                        me->AddNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                        player->KilledMonsterCredit(NPC_PANDRIARCH_GOLDENDRAFT);
                    }
                }
            }

            void EnterCombat(Unit* who) override
            {
                if (Player* player = who->ToPlayer())
                {
                    if (player->GetQuestStatus(QUEST_GETTING_PERMISSION) == QUEST_STATUS_INCOMPLETE)
                        return;

                    else
                    {
                        me->CombatStop();
                        me->SetFaction(35);
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
                        case EVENT_EXPLOSIVE_LAGER:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_EXPLOSIVE_LAGER, false);
                            events.ScheduleEvent(EVENT_EXPLOSIVE_LAGER,      10000);
                            break;
                        case EVENT_FIRE_ALE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_FIRE_ALE, false);
                            events.ScheduleEvent(EVENT_FIRE_ALE,      10000);
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
            return new mob_pandriarch_goldendraftAI(creature);
        }
};

// Big Bao - 58512
class mob_big_bao : public CreatureScript
{
    public:
        mob_big_bao() : CreatureScript("mob_big_bao") {}

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_CHOICE_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            SendGossipMenuFor(player, 75012, creature->GetGUID());

            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
        {
            player->PlayerTalkClass->ClearMenus();

            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                if (player->GetQuestStatus(QUEST_TRAINER_S_CHALLENGE) == QUEST_STATUS_INCOMPLETE)
                {
                    creature->SetFaction(14);
                    creature->SetReactState(REACT_DEFENSIVE);
                    creature->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                    creature->AI()->Reset();
                    creature->CombatStart(player, true);
                }
                CloseGossipMenuFor(player);
            }

            return true;
        }

        struct mob_big_baoAI : public ScriptedAI
        {
            mob_big_baoAI(Creature* creature) : ScriptedAI(creature) {}

            EventMap events;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_FORCE_BURST, 3000);
                events.ScheduleEvent(EVENT_KNOCK_AWAY, 8000);
                events.ScheduleEvent(EVENT_PULL_CLOSE, 13000);
                events.ScheduleEvent(EVENT_WAR_STOMP, 18000);
            }

            void EnterCombat(Unit* who) override
            {
                if (Player* player = who->ToPlayer())
                {
                    if (player->GetQuestStatus(QUEST_TRAINER_S_CHALLENGE) == QUEST_STATUS_INCOMPLETE)
                        player->CastSpell(player, SPELL_RACE_AGAINST_THE_CLOCK);
                    else
                    {
                        me->CombatStop();
                        me->SetFaction(35);
                    }
                }
            }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                if (Player* player = attacker->ToPlayer())
                {
                    if (me->HealthBelowPctDamaged(10, damage) || damage > me->GetHealth())
                    {
                        damage = 0;
                        me->CombatStop();
                        me->GetMotionMaster()->MovePoint(0, 1604.75f, -2562.139893f, 153.134003f);
                        me->SetFaction(35);
                        me->SetFullHealth();
                        me->AddNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                        player->KilledMonsterCredit(MOB_BIG_BAO);
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
                        case EVENT_FORCE_BURST:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_FORCE_BURST, false);
                            events.ScheduleEvent(EVENT_FORCE_BURST, 10000);
                            break;
                        case EVENT_KNOCK_AWAY:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_KNOCK_AWAY, false);
                            events.ScheduleEvent(EVENT_KNOCK_AWAY, 10000);
                            break;
                        case EVENT_PULL_CLOSE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_PULL_CLOSE, false);
                            events.ScheduleEvent(EVENT_PULL_CLOSE, 10000);
                            break;
                        case EVENT_WAR_STOMP:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_FIRE_ALE, false);
                            events.ScheduleEvent(SPELL_WAR_STOMP, 10000);
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
            return new mob_big_baoAI(creature);
        }
};

// Hutia - 69946
class mob_hutia : public CreatureScript
{
    public:
        mob_hutia() : CreatureScript("mob_hutia") {}

        struct mob_hutiatAI : public ScriptedAI
        {
            mob_hutiatAI(Creature* creature) : ScriptedAI(creature) {}

            EventMap events;

            void Reset() override
            {
                events.Reset();

                me->CastSpell(me, SPELL_SPIRIT_MEND, false);
                me->CastSpell(me, SPELL_STRONG_WILL, false);

                events.ScheduleEvent(EVENT_FRENZY_2, 7000);
                events.ScheduleEvent(EVENT_SPIRIT_BEAST_BLESSING, 12000);
                events.ScheduleEvent(EVENT_SPIRIT_HEAL, 19000);
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
                        case EVENT_FRENZY_2:
                            me->CastSpell(me, SPELL_FRENZY_2, false);
                            events.ScheduleEvent(EVENT_FRENZY_2, 30000);
                            break;
                        case EVENT_SPIRIT_BEAST_BLESSING:
                            me->CastSpell(me, SPELL_SPIRIT_BEAST_BLESSING, false);
                            events.ScheduleEvent(EVENT_SPIRIT_BEAST_BLESSING, 40000);
                            break;
                        case EVENT_SPIRIT_HEAL:
                            me->CastSpell(me, SPELL_SPIRIT_HEAL_2, false);
                            events.ScheduleEvent(EVENT_SPIRIT_HEAL, 40000);
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
            return new mob_hutiatAI(creature);
        }
};

// Elder Anli - 58564
class npc_elder_anli : public CreatureScript
{
    public:
        npc_elder_anli() : CreatureScript("npc_elder_anli") {}

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            if (creature->IsQuestGiver())
                player->PrepareQuestMenu(creature->GetGUID());

            if (player->GetQuestStatus(QUEST_RIDING_THE_SKIES_FIRST) == QUEST_STATUS_INCOMPLETE || player->GetQuestStatus(QUEST_RIDING_THE_SKIES_SECOND) == QUEST_STATUS_INCOMPLETE || player->GetQuestStatus(QUEST_RIDING_THE_SKIES_THIRD) == QUEST_STATUS_INCOMPLETE)
                if (player->GetReputationRank(REPUTATION_ORDER_OF_THE_CLOUD_SERPENT) == REP_EXALTED)
                    player->KilledMonsterCredit(NPC_INSTRUCTOR_WINDBLADE);

            player->PlayerTalkClass->SendGossipMenu(GOSSIP_TEXT_I, creature->GetGUID());

            return true;
        }

        bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*sender*/, uint32 /*action*/) override
        {
            player->PlayerTalkClass->GetQuestMenu();

            return true;
        }

        bool OnQuestAccept(Player* player, Creature* /*p_Creature*/, Quest const* quest) override
        {
            if (quest->GetQuestId() == 31717)
                player->SummonCreature(66025, 1559.40f, -2558.67f, 151.244f, 4.83016f);

            else if (quest->GetQuestId() == 31718)
                player->SummonCreature(66026, 1559.40f, -2558.67f, 151.244f, 4.83016f);

            else if (quest->GetQuestId() == 31719)
                player->SummonCreature(66027, 1559.40f, -2558.67f, 151.244f, 4.83016f);

            else if (quest->GetQuestId() == 31720)
                player->SummonCreature(66029, 1559.40f, -2558.67f, 151.244f, 4.83016f);

            else if (quest->GetQuestId() == 31721)
                player->SummonCreature(66028, 1559.40f, -2558.67f, 151.244f, 4.83016f);

            return true;
        }

        bool OnQuestReward(Player* player, Creature* creature, const Quest* quest, uint32 /*option*/) override
        {
            switch (quest->GetQuestId())
            {
                case 30188:
                case 31810:
                case 31811:
                    creature->CastSpell(player, 130487, false);
                    break;
                default:
                    break;
            }

            return true;
        }
};

// Kher Shan - 56329
class mob_kher_shan : public CreatureScript
{
    public:
        mob_kher_shan() : CreatureScript("mob_kher_shan") {}

        struct mob_kher_shanAI : public ScriptedAI
        {
            mob_kher_shanAI(Creature* creature) : ScriptedAI(creature) {}

            void JustDied(Unit* killer) override
            {
                if (Player* player = killer->ToPlayer())
                    if (player->GetQuestStatus(29924) == QUEST_STATUS_COMPLETE)
                        if (Quest const* quest = sObjectMgr->GetQuestTemplate(29924))
                            player->RewardQuest(quest, LootItemType::Item, 0, nullptr, true);
            }

        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_kher_shanAI(creature);
        }
};

// Pearlfin Aqualyte - 54959/56585/56591/56592
class mob_pearlfin_aqualyte : public CreatureScript
{
    public:
        mob_pearlfin_aqualyte() : CreatureScript("mob_pearlfin_aqualyte") {}

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            if (player->GetQuestStatus(29903) == QUEST_STATUS_INCOMPLETE)
            {
                player->KilledMonsterCredit(56601);
                creature->DespawnOrUnsummon();
            }

            return true;
        }
};

// Pearlfin Villager - 56233
class mob_pearlfin_villager : public CreatureScript
{
    public:
        mob_pearlfin_villager() : CreatureScript("mob_pearlfin_villager") {}

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            if (player->GetQuestStatus(29762) == QUEST_STATUS_INCOMPLETE)
            {
                player->AddItem(79811, 1);
                creature->DespawnOrUnsummon();
            }

            return true;
        }
};

// Elder Lusshan - 54960 ## Instructor Sharpfin - 56690 ## Ot-Temmdo - 56693 ## Pearlkeeper Fujin - 59058
class mob_pearlfin_situation : public CreatureScript
{
    public:
        mob_pearlfin_situation() : CreatureScript("mob_pearlfin_situation") {}

        bool OnGossipHello(Player* player, Creature* creature) override
        {
                switch (creature->GetEntry())
                {
                    case 59058:
                        if (creature->IsQuestGiver())
                            player->PrepareQuestMenu(creature->GetGUID());

                        if (player->GetQuestStatus(29883) == QUEST_STATUS_INCOMPLETE)
                            player->KilledMonsterCredit(59058);

                        player->PlayerTalkClass->SendGossipMenu(GOSSIP_TEXT_I, creature->GetGUID());
                        break;
                    case 56693:
                        if (player->GetQuestStatus(29883) == QUEST_STATUS_INCOMPLETE)
                            player->KilledMonsterCredit(56693);
                        break;
                    case 56690:
                        if (player->GetQuestStatus(29883) == QUEST_STATUS_INCOMPLETE)
                            player->KilledMonsterCredit(56690);
                        break;
                    case 54960:
                        if (creature->IsQuestGiver())
                            player->PrepareQuestMenu(creature->GetGUID());

                        if (player->GetQuestStatus(29883) == QUEST_STATUS_INCOMPLETE)
                            player->KilledMonsterCredit(54960);

                        player->PlayerTalkClass->SendGossipMenu(GOSSIP_TEXT_I, creature->GetGUID());
                        break;
                    default:
                        break;
                }

            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 /*action*/) override
        {
            if (creature->GetEntry() == 59058 || creature->GetEntry() == 54960)
                player->PlayerTalkClass->GetQuestMenu();

            return true;
        }
};

// Hozen Cage - 209586
// Initial LockId : 1979
class gob_hozen_cage : public GameObjectScript
{
    public:
        gob_hozen_cage() : GameObjectScript("gob_hozen_cage") {}

        bool OnGossipHello(Player* player, GameObject* go) override
        {
            if (player->GetQuestStatus(29559) == QUEST_STATUS_INCOMPLETE)
            {
                if (player->HasItemCount(74260, 1))
                {
                    player->KilledMonsterCredit(55201);
                    player->DestroyItemCount(74260, 1, true);
                    go->DestroyForPlayer(player);
                }
            }

            return true;
        }
};

// Widow's Web - 65634
class mob_widow_s_web : public CreatureScript
{
    public:
        mob_widow_s_web() : CreatureScript("mob_widow_s_web") {}

        struct mob_widow_s_webAI : public ScriptedAI
        {
            mob_widow_s_webAI(Creature* creature) : ScriptedAI(creature) {}

            void Reset() override
            {
                me->AddUnitFlag(UNIT_FLAG_REMOVE_CLIENT_CONTROL);
            }

            void JustDied(Unit* killer) override
            {
                if (Player* player = killer->ToPlayer())
                {
                    if (player->GetQuestStatus(31707) == QUEST_STATUS_INCOMPLETE)
                    {
                        me->SummonCreature(65647, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ());
                        player->KilledMonsterCredit(65647);
                    }
                }
            }

        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_widow_s_webAI(creature);
        }
};

// Freed Sri-La Villager - 65647
class mob_freed_sri_la_villager : public CreatureScript
{
    public:
        mob_freed_sri_la_villager() : CreatureScript("mob_freed_sri_la_villager") {}

        struct mob_freed_sri_la_villagerAI : public ScriptedAI
        {
            mob_freed_sri_la_villagerAI(Creature* creature) : ScriptedAI(creature)
            {
                timer = 0;
            }

            uint32 timer;

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                timer = 3000;
            }

            void UpdateAI(uint32 diff) override
            {
                if (timer)
                {
                    if (timer <= diff)
                    {
                        me->DespawnOrUnsummon();
                    }
                    else
                        timer -= diff;
                }
            }

        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_freed_sri_la_villagerAI(creature);
        }
};

// Windward Hatchling - 58220/58243/58244
class mob_windward_hatchling : public CreatureScript
{
    public:
        mob_windward_hatchling() : CreatureScript("mob_windward_hatchling") {}

        struct mob_windward_hatchlingAI : public ScriptedAI
        {
            mob_windward_hatchlingAI(Creature* creature) : ScriptedAI(creature) {}

            void DoAction(int32 action) override
            {
                if (action == ACTION_SET_FLAG)
                    me->AddUnitFlag(UNIT_FLAG_PLAYER_CONTROLLED);
            }

            void Reset() override
            {
                me->SetDefaultMovementType(RANDOM_MOTION_TYPE);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_windward_hatchlingAI(creature);
        }
};

// Custom npc 1 - 690701
class npc_custom_npc : public CreatureScript
{
    public:
        npc_custom_npc() : CreatureScript("npc_custom_npc") {}

        struct npc_custom_npcAI : public ScriptedAI
        {
            npc_custom_npcAI(Creature* creature) : ScriptedAI(creature)
            {
                hasSummoned = false;
            }

            EventMap events;
            bool hasSummoned;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_CHECK_PLAYER, 2000);
            }

            void UpdateAI(uint32 diff) override
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    if (eventId == EVENT_CHECK_PLAYER)
                    {
                        std::list<Player*> playerList;
                        GetPlayerListInGrid(playerList, me, 30.0f);

                        for (auto player: playerList)
                        {
                            if (!hasSummoned)
                            {
                                if (player->GetQuestStatus(30156) == QUEST_STATUS_INCOMPLETE)
                                {
                                    player->SummonCreature(58527, player->GetPositionX() + 1, player->GetPositionY() + 1.5f, player->GetPositionZ() + 1);
                                    player->SummonCreature(58527, player->GetPositionX() + 2, player->GetPositionY() + 2.5f, player->GetPositionZ() - 1);
                                    player->SummonCreature(58527, player->GetPositionX() + 1.5f, player->GetPositionY() + 1, player->GetPositionZ() + 1.5f);

                                    std::list<Creature*> creatureList;
                                    player->GetCreatureListWithEntryInGrid(creatureList, 58527, 4.0f);

                                    for (auto creature: creatureList)
                                    {
                                        creature->GetMotionMaster()->MoveFollow(player, 4.0f, 4.0f, MOTION_SLOT_ACTIVE);
                                    }
                                }

                                hasSummoned = true;
                            }
                        }

                        if (playerList.empty())
                            hasSummoned = false;
                    }

                    events.ScheduleEvent(EVENT_CHECK_PLAYER, 2000);
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_custom_npcAI(creature);
        }
};

// Jade Cloud Serpent - 58527
class mob_jade_cloud_serpent : public CreatureScript
{
    public:
        mob_jade_cloud_serpent() : CreatureScript("mob_jade_cloud_serpent") {}

        struct mob_jade_cloud_serpentAI : public ScriptedAI
        {
            mob_jade_cloud_serpentAI(Creature* creature) : ScriptedAI(creature)
            {
                playerGUID = ObjectGuid::Empty;
            }

            EventMap events;
            ObjectGuid playerGUID;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_CHECK_TARGET, 2000);
            }

            void IsSummonedBy(Unit* summoner) override
            {
                if (Player* player = summoner->ToPlayer())
                    playerGUID = player->GetGUID();
            }

            void SpellHit(Unit* caster, SpellInfo const* spell) override
            {
                if (Player* player = caster->ToPlayer())
                {
                    if (spell->Id == 110455)
                    {
                        me->DespawnOrUnsummon();
                        player->KilledMonsterCredit(58351);
                    }
                }
            }

            void UpdateAI(uint32 diff) override
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    if (eventId == EVENT_CHECK_TARGET)
                    {
                        if (Player* player = ObjectAccessor::GetPlayer(*me, playerGUID))
                        {
                            if (Unit* victim = player->GetVictim())
                            {
                                me->SetInCombatWith(victim);
                                AttackStart(victim);
                                DoMeleeAttackIfReady();
                            }
                        }

                        events.ScheduleEvent(EVENT_CHECK_TARGET, 2000);
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_jade_cloud_serpentAI(creature);
        }
};

// Instructor Windblade - 58420
class mob_instructor_windblade : public CreatureScript
{
    public:
        mob_instructor_windblade() : CreatureScript("mob_instructor_windblade") {}

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            if (creature->IsQuestGiver())
                player->PrepareQuestMenu(creature->GetGUID());

            if (player->GetQuestStatus(30143) == QUEST_STATUS_INCOMPLETE)
                    player->KilledMonsterCredit(58572);

            player->PlayerTalkClass->SendGossipMenu(GOSSIP_TEXT_I, creature->GetGUID());

            return true;
        }

        bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*sender*/, uint32 /*action*/) override
        {
            player->PlayerTalkClass->GetQuestMenu();

            return true;
        }

        bool OnQuestAccept(Player* player, Creature* /*creature*/, Quest const* quest) override
        {
            if (quest->GetQuestId() == 30144) // This quests needs the player to complete it on a mount, but vehicleId is unfindable, so he can complete the quest with any flying mount he already gets.
            {
                player->SummonCreature(58426, 1614.22f, -2733.17f, 172.235f, 4.50949f);
                player->SummonCreature(58426, 1643.95f, -2798.85f, 129.329f, 5.16687f);
                player->SummonCreature(58426, 1647.11f, -2772.71f, 161.497f, 5.72295f);
                player->SummonCreature(58426, 1705.37f, -2815.74f, 141.012f, 5.60907f);
                player->SummonCreature(58426, 1739.69f, -2935.46f, 103.094f, 5.06008f);
                player->SummonCreature(58426, 1853.05f, -2963.5f, 96.546f, 5.59807f);
                player->SummonCreature(58426, 1716.28f, -3080.08f, 39.4494f, 3.61493f);
                player->SummonCreature(58426, 1788.15f, -2927.51f, 112.879f, 1.18805f);
                player->SummonCreature(58426, 1736.29f, -2780.32f, 162.346f, 4.06654f);
                player->SummonCreature(58426, 1752.44f, -2701.74f, 137.955f, 3.12799f);
                player->SummonCreature(58426, 1786.51f, -2722.46f, 142.96f, 0.141875f);
            }

            return true;
        }
};

// Cloud Ring - 58426
class npc_cloud_ring : public CreatureScript
{
    public:
        npc_cloud_ring() : CreatureScript("npc_cloud_ring") {}

        struct npc_cloud_ringcAI : public ScriptedAI
        {
            npc_cloud_ringcAI(Creature* creature) : ScriptedAI(creature)
            {
                playerGUID = ObjectGuid::Empty;
            }

            ObjectGuid playerGUID;

            void Reset() override
            {
                me->SetDisplayId(11686);
                me->AddAura(129282, me);
            }

            void IsSummonedBy(Unit* summoner) override
            {
                if (Player* player = summoner->ToPlayer())
                    playerGUID = player->GetGUID();
            }

            void UpdateAI(uint32 /*diff*/) override
            {
                if (Player* player = ObjectAccessor::GetPlayer(*me, playerGUID))
                {
                    if (player->GetQuestStatus(30144) == QUEST_STATUS_INCOMPLETE)
                    {
                        if (player->GetDistance2d(me) <= 1.0f)
                        {
                            me->DespawnOrUnsummon();
                            player->KilledMonsterCredit(58426);
                        }
                    }

                    else if (player->GetQuestStatus(30144) == QUEST_STATUS_COMPLETE)
                        me->DespawnOrUnsummon();
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_cloud_ringcAI(creature);
        }
};

// Instructor Skythorn - 58228
class npc_instructor_skythorn : public CreatureScript
{
    public:
        npc_instructor_skythorn() : CreatureScript("npc_instructor_skythorn") {}

        bool OnQuestAccept(Player* player, Creature* /*p_Creature*/, Quest const* quest) override
        {
            if (quest->GetQuestId() == 30142)  // Quest "It's A..."
            {
                if (player->HasItemCount(78962, 1))
                {
                    player->DestroyItemCount(78962, 1, false);
                    player->KilledMonsterCredit(58315);
                }

                else if (player->HasItemCount(78960, 1))
                {
                    player->DestroyItemCount(78960, 1, false);
                    player->KilledMonsterCredit(58315);
                }

                else if (player->HasItemCount(78961, 1))
                {
                    player->DestroyItemCount(78961, 1, false);
                    player->KilledMonsterCredit(58315);
                }
            }

            return true;
        }
};

// Big Bao - 66026
class mob_second_big_bao : public CreatureScript
{
    public:
        mob_second_big_bao() : CreatureScript("mob_second_big_bao") {}

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

                if (player->GetQuestStatus(31718) == QUEST_STATUS_INCOMPLETE)
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

        struct mob_second_big_baoAI : public ScriptedAI
        {
            mob_second_big_baoAI(Creature* creature) : ScriptedAI(creature)
            {
                playerGUID = ObjectGuid::Empty;
            }

            ObjectGuid playerGUID;
            EventMap events;

            void Reset() override
            {
                events.Reset();
            }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                if (Player* player = attacker->ToPlayer())
                {
                    if (player->GetQuestStatus(31718) == QUEST_STATUS_INCOMPLETE)
                    {
                        if (damage > me->GetHealth())
                        {
                            damage = 0;
                            me->SetFullHealth();
                            DoAction(ACTION_REINITIALIZE);
                            player->KilledMonsterCredit(58508);
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
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    if (eventId == EVENT_DESPAWN)
                        me->DespawnOrUnsummon();
                }

                if (Player* player = ObjectAccessor::FindPlayer(playerGUID))
                {
                    if (!player->IsAlive())
                    {
                        DoAction(ACTION_REINITIALIZE);
                        events.Reset();
                        return;
                    }

                    if (player->GetQuestStatus(31718) != QUEST_STATUS_INCOMPLETE)
                    {
                        me->DespawnOrUnsummon();
                    }

                    if (me->GetDistance2d(player) >= 25.0f)
                    {
                        me->DespawnOrUnsummon();
                    }
                }

                if (!UpdateVictim())
                    return;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_second_big_baoAI(creature);
        }
};

// Ace Longpaw - 66025
class mob_ace_longpaw : public CreatureScript
{
    public:
        mob_ace_longpaw() : CreatureScript("mob_ace_longpaw") {}

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

                if (player->GetQuestStatus(31717) == QUEST_STATUS_INCOMPLETE)
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

        struct mob_ace_longpawAI : public ScriptedAI
        {
            mob_ace_longpawAI(Creature* creature) : ScriptedAI(creature)
            {
                playerGUID = ObjectGuid::Empty;
            }

            ObjectGuid playerGUID;
            EventMap events;

            void Reset() override
            {
                events.Reset();
            }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                if (Player* player = attacker->ToPlayer())
                {
                    if (player->GetQuestStatus(31717) == QUEST_STATUS_INCOMPLETE)
                    {
                        if (damage > me->GetHealth())
                        {
                            damage = 0;
                            me->SetFullHealth();
                            DoAction(ACTION_REINITIALIZE);
                            player->KilledMonsterCredit(58506);
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
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    if (eventId == EVENT_DESPAWN)
                        me->DespawnOrUnsummon();
                }

                if (Player* player = ObjectAccessor::FindPlayer(playerGUID))
                {
                    if (!player->IsAlive())
                    {
                        DoAction(ACTION_REINITIALIZE);
                        events.Reset();
                        return;
                    }

                    if (player->GetQuestStatus(31717) != QUEST_STATUS_INCOMPLETE)
                    {
                        me->DespawnOrUnsummon();
                    }

                    if (me->GetDistance2d(player) >= 25.0f)
                    {
                        me->DespawnOrUnsummon();
                    }
                }

                if (!UpdateVictim())
                    return;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_ace_longpawAI(creature);
        }
};

// Ningha Darkwheel - 66027
class mob_ningha_darkwheel : public CreatureScript
{
    public:
        mob_ningha_darkwheel() : CreatureScript("mob_ningha_darkwheel") {}

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

                if (player->GetQuestStatus(31719) == QUEST_STATUS_INCOMPLETE)
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

        struct mob_ningha_darkwheelAI : public ScriptedAI
        {
            mob_ningha_darkwheelAI(Creature* creature) : ScriptedAI(creature)
            {
                playerGUID = ObjectGuid::Empty;
            }

            ObjectGuid playerGUID;
            EventMap events;

            void Reset() override
            {
                events.Reset();
            }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                if (Player* player = attacker->ToPlayer())
                {
                    if (player->GetQuestStatus(31719) == QUEST_STATUS_INCOMPLETE)
                    {
                        if (damage > me->GetHealth())
                        {
                            damage = 0;
                            me->SetFullHealth();
                            DoAction(ACTION_REINITIALIZE);
                            player->KilledMonsterCredit(58509);
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
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    if (eventId == EVENT_DESPAWN)
                        me->DespawnOrUnsummon();
                }

                if (Player* player = ObjectAccessor::FindPlayer(playerGUID))
                {
                    if (!player->IsAlive())
                    {
                        DoAction(ACTION_REINITIALIZE);
                        events.Reset();
                        return;
                    }

                    if (player->GetQuestStatus(31719) != QUEST_STATUS_INCOMPLETE)
                    {
                        me->DespawnOrUnsummon();
                    }

                    if (me->GetDistance2d(player) >= 25.0f)
                    {
                        me->DespawnOrUnsummon();
                    }
                }

                if (!UpdateVictim())
                    return;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_ningha_darkwheelAI(creature);
        }
};

// Que-Row Whitebrow - 66028
class mob_qua_row_whitebrow : public CreatureScript
{
    public:
        mob_qua_row_whitebrow() : CreatureScript("mob_qua_row_whitebrow") {}

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

                if (player->GetQuestStatus(31721) == QUEST_STATUS_INCOMPLETE)
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

        struct mob_qua_row_whitebrowAI : public ScriptedAI
        {
            mob_qua_row_whitebrowAI(Creature* creature) : ScriptedAI(creature)
            {
                playerGUID = ObjectGuid::Empty;
            }

            ObjectGuid playerGUID;
            EventMap events;

            void Reset() override
            {
                events.Reset();
            }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                if (Player* player = attacker->ToPlayer())
                {
                    if (player->GetQuestStatus(31721) == QUEST_STATUS_INCOMPLETE)
                    {
                        if (damage > me->GetHealth())
                        {
                            damage = 0;
                            me->SetFullHealth();
                            DoAction(ACTION_REINITIALIZE);
                            player->KilledMonsterCredit(58511);
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
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    if (eventId == EVENT_DESPAWN)
                        me->DespawnOrUnsummon();
                }

                if (Player* player = ObjectAccessor::FindPlayer(playerGUID))
                {
                    if (!player->IsAlive())
                    {
                        DoAction(ACTION_REINITIALIZE);
                        events.Reset();
                        return;
                    }

                    if (player->GetQuestStatus(31721) != QUEST_STATUS_INCOMPLETE)
                    {
                        me->DespawnOrUnsummon();
                    }

                    if (me->GetDistance2d(player) >= 25.0f)
                    {
                        me->DespawnOrUnsummon();
                    }
                }

                if (!UpdateVictim())
                    return;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_qua_row_whitebrowAI(creature);
        }
};

// Suchi The Sweet - 66029
class mob_suchi_the_sweet : public CreatureScript
{
    public:
        mob_suchi_the_sweet() : CreatureScript("mob_suchi_the_sweet") {}

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

                if (player->GetQuestStatus(31720) == QUEST_STATUS_INCOMPLETE)
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

        struct mob_suchi_the_sweetAI : public ScriptedAI
        {
            mob_suchi_the_sweetAI(Creature* creature) : ScriptedAI(creature)
            {
                playerGUID = ObjectGuid::Empty;
            }

            ObjectGuid playerGUID;
            EventMap events;

            void Reset() override
            {
                events.Reset();
            }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                if (Player* player = attacker->ToPlayer())
                {
                    if (player->GetQuestStatus(31720) == QUEST_STATUS_INCOMPLETE)
                    {
                        if (damage > me->GetHealth())
                        {
                            damage = 0;
                            me->SetFullHealth();
                            DoAction(ACTION_REINITIALIZE);
                            player->KilledMonsterCredit(58510);
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
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    if (eventId == EVENT_DESPAWN)
                        me->DespawnOrUnsummon();
                }

                if (Player* player = ObjectAccessor::FindPlayer(playerGUID))
                {
                    if (!player->IsAlive())
                    {
                        DoAction(ACTION_REINITIALIZE);
                        events.Reset();
                        return;
                    }

                    if (player->GetQuestStatus(31720) != QUEST_STATUS_INCOMPLETE)
                    {
                        me->DespawnOrUnsummon();
                    }

                    if (me->GetDistance2d(player) >= 25.0f)
                    {
                        me->DespawnOrUnsummon();
                    }
                }

                if (!UpdateVictim())
                    return;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_suchi_the_sweetAI(creature);
        }
};

// Fei - 56784
class npc_fei : public CreatureScript
{
    public:
        npc_fei() : CreatureScript("npc_fei") {}

        bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) override
        {
            if (quest->GetQuestId() == 30000)
            {
                player->GetSceneMgr().PlaySceneByPackageId(202);
                player->KilledMonsterCredit(57243);

                if (Creature* questTaker = GetClosestCreatureWithEntry(creature, 57242, 200.0f, true))
                    player->TeleportTo(870, questTaker->GetPositionX() + 1.4f, questTaker->GetPositionY() + 1.5f, questTaker->GetPositionZ(), 0.0f, 0);
            }

            return true;
        }
};

// Student of Chi-Ji - 60601/60602/60603
class mob_chi_ji_student : public CreatureScript
{
    public:
        mob_chi_ji_student() : CreatureScript("mob_chi_ji_student") {}

        struct mob_chi_ji_studentAI : public ScriptedAI
        {
            mob_chi_ji_studentAI(Creature* creature) : ScriptedAI(creature)
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
                    case 60601:
                        events.ScheduleEvent(EVENT_GIFT_OF_CHI_JI, 3000);
                        events.ScheduleEvent(EVENT_BLESSING_OF_CHI_JI, 6000);
                        events.ScheduleEvent(EVENT_WRATH_OF_CHI_JI, 11000);
                        break;
                    case 60602:
                        events.ScheduleEvent(EVENT_BLACKOUT_KICK, 3000);
                        events.ScheduleEvent(EVENT_FLYING_SERPENT_KICK, 8000);
                        events.ScheduleEvent(EVENT_JAB, 13000);
                        break;
                    case 60603:
                        events.ScheduleEvent(EVENT_MIGHTY_CHOP, 3000);
                        events.ScheduleEvent(EVENT_STRIKE_FROM_THE_HEAVENS, 6000);
                        break;
                    default:
                        break;
                }
            }

            void EnterCombat(Unit* attacker) override
            {
                if (Player* pAttacker = attacker->ToPlayer())
                    playerGUID = pAttacker->GetGUID();
            }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                if (Player* player = attacker->ToPlayer())
                {
                    if (player->GetQuestStatus(30718) == QUEST_STATUS_INCOMPLETE)
                    {
                        if (damage > me->GetHealth())
                        {
                            damage = 0;
                            me->SetFullHealth();
                            DoAction(ACTION_REINITIALIZE);
                            player->KilledMonsterCredit(60601);
                            me->DespawnOrUnsummon();
                        }
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
                        // Entry 60601
                        case EVENT_GIFT_OF_CHI_JI:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT))
                                me->CastSpell(target, SPELL_GIFT_OF_CHI_JI, false);
                            events.ScheduleEvent(EVENT_GIFT_OF_CHI_JI, 7000);
                            break;
                        case EVENT_BLESSING_OF_CHI_JI:
                            me->CastSpell(me, SPELL_BLESSING_OF_CHI_JI, false);
                            events.ScheduleEvent(EVENT_BLESSING_OF_CHI_JI, 7000);
                            break;
                        case EVENT_WRATH_OF_CHI_JI:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_WRATH_OF_CHI_JI, false);
                            events.ScheduleEvent(EVENT_WRATH_OF_CHI_JI, 7000);
                            break;
                            // Entry 60602
                        case EVENT_BLACKOUT_KICK:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_BLACKOUT_KICK, false);
                            events.ScheduleEvent(EVENT_BLACKOUT_KICK, 15000);
                            break;
                        case EVENT_FLYING_SERPENT_KICK:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_FLYING_SERPENT_KICK, false);
                            events.ScheduleEvent(EVENT_FLYING_SERPENT_KICK, 15000);
                            break;
                        case EVENT_JAB:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_JAB, false);
                            events.ScheduleEvent(EVENT_JAB, 15000);
                            break;
                            // Entry 60603
                        case EVENT_MIGHTY_CHOP:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_MIGHTY_CHOP, false);
                            events.ScheduleEvent(EVENT_MIGHTY_CHOP, 7000);
                            break;
                        case EVENT_STRIKE_FROM_THE_HEAVENS:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_STRIKE_FROM_THE_HEAVENS, false);
                            events.ScheduleEvent(EVENT_STRIKE_FROM_THE_HEAVENS, 7000);
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
            return new mob_chi_ji_studentAI(creature);
        }
};

void AddSC_jade_forest()
{
    // Rare mobs
    new mob_kor_nas_nightsavage();
    new mob_krax_ik();
    new mob_mister_ferocious();
    // Elite mobs
    new mob_shadow_of_doubt();
    new mob_akkalar();
    new mob_grookin_outrunner();
    new mob_bamboo_python();
    new mob_rakira();
    new mob_ro_shen();
    new mob_sha_reminant();
    new mob_hutia();
    // Standard Mobs
    new mob_pandriarch_windfur();
    new mob_pandriarch_bramblestaff();
    new mob_pandriarch_goldendraft();
    new mob_big_bao();
    new npc_elder_anli();
    new mob_kher_shan();
    new mob_pearlfin_aqualyte();
    new mob_pearlfin_villager();
    new mob_pearlfin_situation();
    new mob_widow_s_web();
    new mob_freed_sri_la_villager();
    new mob_windward_hatchling();
    new npc_custom_npc();
    new mob_jade_cloud_serpent();
    new mob_instructor_windblade();
    new npc_cloud_ring();
    new npc_instructor_skythorn();
    new mob_second_big_bao();
    new mob_ace_longpaw();
    new mob_ningha_darkwheel();
    new mob_qua_row_whitebrow();
    new mob_suchi_the_sweet();
    new npc_fei();
    new mob_chi_ji_student();
    // Game Objects
    new gob_hozen_cage();
}
