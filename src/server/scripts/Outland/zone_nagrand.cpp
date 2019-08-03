/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

/* ScriptData
SDName: Nagrand
SD%Complete: 90
SDComment: Quest support: 9868, 9874, 10085. TextId's unknown for altruis_the_sufferer and greatmother_geyah (npc_text)
SDCategory: Nagrand
EndScriptData */

/* ContentData
npc_maghar_captive
EndContentData */

#include "ScriptMgr.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "MotionMaster.h"
#include "Player.h"
#include "ScriptedEscortAI.h"
#include "ScriptedGossip.h"
#include "SpellInfo.h"
#include "TemporarySummon.h"

/*######
## npc_maghar_captive
#####*/

enum MagharCaptive
{
    SAY_MAG_START               = 0,
    SAY_MAG_NO_ESCAPE           = 0,
    SAY_MAG_MORE                = 1,
    SAY_MAG_MORE_REPLY          = 0,
    SAY_MAG_LIGHTNING           = 2,
    SAY_MAG_SHOCK               = 3,
    SAY_MAG_COMPLETE            = 4,

    SPELL_CHAIN_LIGHTNING       = 16006,
    SPELL_EARTHBIND_TOTEM       = 15786,
    SPELL_FROST_SHOCK           = 12548,
    SPELL_HEALING_WAVE          = 12491,

    QUEST_TOTEM_KARDASH_H       = 9868,

    NPC_MURK_RAIDER             = 18203,
    NPC_MURK_BRUTE              = 18211,
    NPC_MURK_SCAVENGER          = 18207,
    NPC_MURK_PUTRIFIER          = 18202
};

static float m_afAmbushA[]= {-1568.805786f, 8533.873047f, 1.958f};
static float m_afAmbushB[]= {-1491.554321f, 8506.483398f, 1.248f};

class npc_maghar_captive : public CreatureScript
{
public:
    npc_maghar_captive() : CreatureScript("npc_maghar_captive") { }

    struct npc_maghar_captiveAI : public EscortAI
    {
        npc_maghar_captiveAI(Creature* creature) : EscortAI(creature) { Reset(); }

        uint32 ChainLightningTimer;
        uint32 HealTimer;
        uint32 FrostShockTimer;

        void Reset() override
        {
            ChainLightningTimer = 1000;
            HealTimer = 0;
            FrostShockTimer = 6000;
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            DoCast(me, SPELL_EARTHBIND_TOTEM, false);
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (!HasEscortState(STATE_ESCORT_ESCORTING))
                return;

            if (Player* player = GetPlayerForEscort())
            {
                if (player->GetQuestStatus(QUEST_TOTEM_KARDASH_H) != QUEST_STATUS_COMPLETE)
                    player->FailQuest(QUEST_TOTEM_KARDASH_H);
            }
        }

        void WaypointReached(uint32 waypointId, uint32 /*pathId*/) override
        {
            switch (waypointId)
            {
                case 7:
                    Talk(SAY_MAG_MORE);

                    if (Creature* temp = me->SummonCreature(NPC_MURK_PUTRIFIER, m_afAmbushB[0], m_afAmbushB[1], m_afAmbushB[2], 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000))
                        temp->AI()->Talk(SAY_MAG_MORE_REPLY);

                    me->SummonCreature(NPC_MURK_PUTRIFIER, m_afAmbushB[0]-2.5f, m_afAmbushB[1]-2.5f, m_afAmbushB[2], 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                    me->SummonCreature(NPC_MURK_SCAVENGER, m_afAmbushB[0]+2.5f, m_afAmbushB[1]+2.5f, m_afAmbushB[2], 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                    me->SummonCreature(NPC_MURK_SCAVENGER, m_afAmbushB[0]+2.5f, m_afAmbushB[1]-2.5f, m_afAmbushB[2], 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                    break;
                case 16:
                    Talk(SAY_MAG_COMPLETE);

                    if (Player* player = GetPlayerForEscort())
                        player->GroupEventHappens(QUEST_TOTEM_KARDASH_H, me);

                    SetRun();
                    break;
            }
        }

        void JustSummoned(Creature* summoned) override
        {
            if (summoned->GetEntry() == NPC_MURK_BRUTE)
                summoned->AI()->Talk(SAY_MAG_NO_ESCAPE);

            if (summoned->IsTotem())
                return;

            summoned->SetWalk(false);
            summoned->GetMotionMaster()->MovePoint(0, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ());
            summoned->AI()->AttackStart(me);

        }

        void SpellHitTarget(Unit* /*target*/, SpellInfo const* spell) override
        {
            if (spell->Id == SPELL_CHAIN_LIGHTNING)
            {
                if (rand32() % 10)
                    return;

                Talk(SAY_MAG_LIGHTNING);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            EscortAI::UpdateAI(diff);

            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (ChainLightningTimer <= diff)
            {
                DoCastVictim(SPELL_CHAIN_LIGHTNING);
                ChainLightningTimer = urand(7000, 14000);
            }
            else
                ChainLightningTimer -= diff;

            if (HealthBelowPct(30))
            {
                if (HealTimer <= diff)
                {
                    DoCast(me, SPELL_HEALING_WAVE);
                    HealTimer = 5000;
                }
                else
                    HealTimer -= diff;
            }

            if (FrostShockTimer <= diff)
            {
                DoCastVictim(SPELL_FROST_SHOCK);
                FrostShockTimer = urand(7500, 15000);
            }
            else
                FrostShockTimer -= diff;

            DoMeleeAttackIfReady();
        }

        void QuestAccept(Player* player, Quest const* quest) override
        {
            if (quest->GetQuestId() == QUEST_TOTEM_KARDASH_H)
            {
                me->SetStandState(UNIT_STAND_STATE_STAND);
                me->SetFaction(FACTION_ESCORTEE_H_NEUTRAL_ACTIVE);
                Start(true, false, player->GetGUID(), quest);
                Talk(SAY_MAG_START);

                me->SummonCreature(NPC_MURK_RAIDER, m_afAmbushA[0] + 2.5f, m_afAmbushA[1] - 2.5f, m_afAmbushA[2], 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                me->SummonCreature(NPC_MURK_PUTRIFIER, m_afAmbushA[0] - 2.5f, m_afAmbushA[1] + 2.5f, m_afAmbushA[2], 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                me->SummonCreature(NPC_MURK_BRUTE, m_afAmbushA[0], m_afAmbushA[1], m_afAmbushA[2], 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_maghar_captiveAI(creature);
    }

};

/*######
## go_corkis_prison and npc_corki
######*/

enum CorkiData
{
    // first quest
    QUEST_HELP                                    = 9923,
    NPC_CORKI                                     = 18445,
    NPC_CORKI_CREDIT_1                            = 18369,
    GO_CORKIS_PRISON                              = 182349,
    CORKI_SAY_THANKS                              = 0,
    // 2nd quest
    QUEST_CORKIS_GONE_MISSING_AGAIN               = 9924,
    NPC_CORKI_2                                   = 20812,
    GO_CORKIS_PRISON_2                            = 182350,
    CORKI_SAY_PROMISE                             = 0,
    // 3rd quest
    QUEST_CHOWAR_THE_PILLAGER                     = 9955,
    NPC_CORKI_3                                   = 18369,
    NPC_CORKI_CREDIT_3                            = 18444,
    GO_CORKIS_PRISON_3                            = 182521,
    CORKI_SAY_LAST                                = 0
};

class go_corkis_prison : public GameObjectScript
{
public:
    go_corkis_prison() : GameObjectScript("go_corkis_prison") { }

    struct go_corkis_prisonAI : public GameObjectAI
    {
        go_corkis_prisonAI(GameObject* go) : GameObjectAI(go) { }

        bool GossipHello(Player* player) override
        {
            me->SetGoState(GO_STATE_READY);
            if (me->GetEntry() == GO_CORKIS_PRISON)
            {
                if (Creature* corki = me->FindNearestCreature(NPC_CORKI, 25, true))
                {
                    corki->GetMotionMaster()->MovePoint(1, me->GetPositionX() + 5, me->GetPositionY(), me->GetPositionZ());
                    if (player)
                        player->KilledMonsterCredit(NPC_CORKI_CREDIT_1);
                }
            }

            if (me->GetEntry() == GO_CORKIS_PRISON_2)
            {
                if (Creature* corki = me->FindNearestCreature(NPC_CORKI_2, 25, true))
                {
                    corki->GetMotionMaster()->MovePoint(1, me->GetPositionX() - 5, me->GetPositionY(), me->GetPositionZ());
                    if (player)
                        player->KilledMonsterCredit(NPC_CORKI_2);
                }
            }

            if (me->GetEntry() == GO_CORKIS_PRISON_3)
            {
                if (Creature* corki = me->FindNearestCreature(NPC_CORKI_3, 25, true))
                {
                    corki->GetMotionMaster()->MovePoint(1, me->GetPositionX() + 4, me->GetPositionY(), me->GetPositionZ());
                    if (player)
                        player->KilledMonsterCredit(NPC_CORKI_CREDIT_3);
                }
            }
            return true;
        }
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new go_corkis_prisonAI(go);
    }
};

class npc_corki : public CreatureScript
{
public:
    npc_corki() : CreatureScript("npc_corki") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_corkiAI(creature);
    }

    struct npc_corkiAI : public ScriptedAI
    {
        npc_corkiAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            Say_Timer = 5000;
            ReleasedFromCage = false;
        }

        uint32 Say_Timer;
        bool ReleasedFromCage;

        void Reset() override
        {
            Initialize();
        }

        void UpdateAI(uint32 diff) override
        {
            if (ReleasedFromCage)
            {
                if (Say_Timer <= diff)
                {
                    me->DespawnOrUnsummon();
                    ReleasedFromCage = false;
                }
                else
                    Say_Timer -= diff;
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == POINT_MOTION_TYPE && id == 1)
            {
                Say_Timer = 5000;
                ReleasedFromCage = true;
                if (me->GetEntry() == NPC_CORKI)
                    Talk(CORKI_SAY_THANKS);
                if (me->GetEntry() == NPC_CORKI_2)
                    Talk(CORKI_SAY_PROMISE);
                if (me->GetEntry() == NPC_CORKI_3)
                    Talk(CORKI_SAY_LAST);
            }
        };
    };
};

/*#####
## npc_kurenai_captive
#####*/

enum KurenaiCaptive
{
    SAY_KUR_START                   = 0,
    SAY_KUR_NO_ESCAPE               = 1,
    SAY_KUR_MORE                    = 2,
    SAY_KUR_MORE_TWO                = 3,
    SAY_KUR_LIGHTNING               = 4,
    SAY_KUR_SHOCK                   = 5,
    SAY_KUR_COMPLETE                = 6,

    SPELL_KUR_CHAIN_LIGHTNING       = 16006,
    SPELL_KUR_EARTHBIND_TOTEM       = 15786,
    SPELL_KUR_FROST_SHOCK           = 12548,
    SPELL_KUR_HEALING_WAVE          = 12491,

    QUEST_TOTEM_KARDASH_A           = 9879,

    NPC_KUR_MURK_RAIDER             = 18203,
    NPC_KUR_MURK_BRUTE              = 18211,
    NPC_KUR_MURK_SCAVENGER          = 18207,
    NPC_KUR_MURK_PUTRIFIER          = 18202,
};

static float kurenaiAmbushA[]= {-1568.805786f, 8533.873047f, 1.958f};
static float kurenaiAmbushB[]= {-1491.554321f, 8506.483398f, 1.248f};

class npc_kurenai_captive : public CreatureScript
{
public:
    npc_kurenai_captive() : CreatureScript("npc_kurenai_captive") { }

    struct npc_kurenai_captiveAI : public EscortAI
    {
        npc_kurenai_captiveAI(Creature* creature) : EscortAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            ChainLightningTimer = 1000;
            HealTimer = 0;
            FrostShockTimer = 6000;
        }

        uint32 ChainLightningTimer;
        uint32 HealTimer;
        uint32 FrostShockTimer;

        void Reset() override
        {
            Initialize();
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            DoCast(me, SPELL_KUR_EARTHBIND_TOTEM, false);
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (!HasEscortState(STATE_ESCORT_ESCORTING))
                return;

            if (Player* player = GetPlayerForEscort())
            {
                if (player->GetQuestStatus(QUEST_TOTEM_KARDASH_A) != QUEST_STATUS_COMPLETE)
                    player->FailQuest(QUEST_TOTEM_KARDASH_A);
            }
        }

        void WaypointReached(uint32 waypointId, uint32 /*pathId*/) override
        {
            switch (waypointId)
            {
                case 3:
                {
                    Talk(SAY_KUR_MORE);

                    if (me->SummonCreature(NPC_KUR_MURK_PUTRIFIER, kurenaiAmbushB[0], kurenaiAmbushB[1], kurenaiAmbushB[2], 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000))
                        Talk(SAY_KUR_MORE_TWO);

                    me->SummonCreature(NPC_KUR_MURK_PUTRIFIER, kurenaiAmbushB[0]-2.5f, kurenaiAmbushB[1]-2.5f, kurenaiAmbushB[2], 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                    me->SummonCreature(NPC_KUR_MURK_SCAVENGER, kurenaiAmbushB[0]+2.5f, kurenaiAmbushB[1]+2.5f, kurenaiAmbushB[2], 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                    me->SummonCreature(NPC_KUR_MURK_SCAVENGER, kurenaiAmbushB[0]+2.5f, kurenaiAmbushB[1]-2.5f, kurenaiAmbushB[2], 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                    break;
                }
                case 7:
                {
                    Talk(SAY_KUR_COMPLETE);

                    if (Player* player = GetPlayerForEscort())
                        player->GroupEventHappens(QUEST_TOTEM_KARDASH_A, me);

                    SetRun();
                    break;
                }
            }
        }

        void JustSummoned(Creature* summoned) override
        {
            if (summoned->GetEntry() == NPC_KUR_MURK_BRUTE)
                Talk(SAY_KUR_NO_ESCAPE);

            // This function is for when we summoned enemies to fight - so that does NOT mean we should make our totem count in this!
            if (summoned->IsTotem())
                return;

            summoned->SetWalk(false);
            summoned->GetMotionMaster()->MovePoint(0, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ());
            summoned->AI()->AttackStart(me);
        }

        void SpellHitTarget(Unit* /*target*/, SpellInfo const* spell) override
        {
            if (spell->Id == SPELL_KUR_CHAIN_LIGHTNING)
            {
                if (rand32() % 30)
                    return;

                Talk(SAY_KUR_LIGHTNING);
            }

            if (spell->Id == SPELL_KUR_FROST_SHOCK)
            {
                if (rand32() % 30)
                    return;

                Talk(SAY_KUR_SHOCK);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            EscortAI::UpdateAI(diff);

            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (ChainLightningTimer <= diff)
            {
                DoCastVictim(SPELL_KUR_CHAIN_LIGHTNING);
                ChainLightningTimer = urand(7000, 14000);
            } else ChainLightningTimer -= diff;

            if (HealthBelowPct(30))
            {
                if (HealTimer <= diff)
                {
                    DoCast(me, SPELL_KUR_HEALING_WAVE);
                    HealTimer = 5000;
                } else HealTimer -= diff;
            }

            if (FrostShockTimer <= diff)
            {
                DoCastVictim(SPELL_KUR_FROST_SHOCK);
                FrostShockTimer = urand(7500, 15000);
            } else FrostShockTimer -= diff;

            DoMeleeAttackIfReady();
        }

        void QuestAccept(Player* player, Quest const* quest) override
        {
            if (quest->GetQuestId() == QUEST_TOTEM_KARDASH_A)
            {
                me->SetStandState(UNIT_STAND_STATE_STAND);
                me->SetFaction(FACTION_ESCORTEE_A_NEUTRAL_ACTIVE);
                Start(true, false, player->GetGUID(), quest);
                Talk(SAY_KUR_START);

                me->SummonCreature(NPC_KUR_MURK_RAIDER, kurenaiAmbushA[0] + 2.5f, kurenaiAmbushA[1] - 2.5f, kurenaiAmbushA[2], 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                me->SummonCreature(NPC_KUR_MURK_BRUTE, kurenaiAmbushA[0] - 2.5f, kurenaiAmbushA[1] + 2.5f, kurenaiAmbushA[2], 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                me->SummonCreature(NPC_KUR_MURK_SCAVENGER, kurenaiAmbushA[0], kurenaiAmbushA[1], kurenaiAmbushA[2], 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_kurenai_captiveAI(creature);
    }
};

/*######
## go_warmaul_prison
######*/

enum FindingTheSurvivorsData
{
    QUEST_FINDING_THE_SURVIVORS                     = 9948,
    NPC_MAGHAR_PRISONER                             = 18428,

    SAY_FREE                                        = 0,
};

class go_warmaul_prison : public GameObjectScript
{
    public:
        go_warmaul_prison() : GameObjectScript("go_warmaul_prison") { }

        struct go_warmaul_prisonAI : public GameObjectAI
        {
            go_warmaul_prisonAI(GameObject* go) : GameObjectAI(go) { }

            bool GossipHello(Player* player) override
            {
                me->UseDoorOrButton();
                if (player->GetQuestStatus(QUEST_FINDING_THE_SURVIVORS) != QUEST_STATUS_INCOMPLETE)
                    return false;

                if (Creature* prisoner = me->FindNearestCreature(NPC_MAGHAR_PRISONER, 5.0f))
                {
                    player->KilledMonsterCredit(NPC_MAGHAR_PRISONER);

                    prisoner->AI()->Talk(SAY_FREE, player);
                    prisoner->DespawnOrUnsummon(6000);
                }
                return true;
            }
        };

        GameObjectAI* GetAI(GameObject* go) const override
        {
            return new go_warmaul_prisonAI(go);
        }
};

enum PlantBannerQuests
{
    SPELL_PLANT_WARMAUL_OGRE_BANNER  = 32307,
    SPELL_PLANT_KIL_SORROW_BANNER    = 32314,

    NPC_KIL_SORROW_SPELLBINDER       = 17146,
    NPC_KIL_SORROW_CULTIST           = 17147,
    NPC_KIL_SORROW_DEATHSWORN        = 17148,
    NPC_GISELDA_THE_CRONE            = 18391,
    NPC_WARMAUL_REAVER               = 17138,
    NPC_WARMAUL_SHAMAN               = 18064
};

class npc_nagrand_banner : public CreatureScript
{
public:
    npc_nagrand_banner() : CreatureScript("npc_nagrand_banner") { }

    struct npc_nagrand_bannerAI : public ScriptedAI
    {
        npc_nagrand_bannerAI(Creature* creature) : ScriptedAI(creature), bannered(false)
        {
            scheduler.SetValidator([this]
            {
                return !me->HasUnitState(UNIT_STATE_CASTING);
            });
        }

        void Reset() override
        {
            scheduler.CancelAll();
        }

        void SpellHit(Unit* /*caster*/, SpellInfo const* spellInfo) override
        {
            if (spellInfo->Id == SPELL_PLANT_WARMAUL_OGRE_BANNER || spellInfo->Id == SPELL_PLANT_KIL_SORROW_BANNER)
                bannered = true;
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            scheduler.Update(diff, [this]
            {
                DoMeleeAttackIfReady();
            });
        }

        bool IsBannered()
        {
            return bannered;
        }

    protected:
        TaskScheduler scheduler;

    private:
        bool bannered;
    };

    struct npc_kil_sorrow_spellbinderAI : public npc_nagrand_bannerAI
    {
        enum KilSorrowSpellBinder
        {
            SPELL_ARCANE_MISSILES = 34447,
            SPELL_CHAINS_OF_ICE   = 22744,
            SPELL_COUNTERSPELL    = 31999
        };

        npc_kil_sorrow_spellbinderAI(Creature* creature) : npc_nagrand_bannerAI(creature), has_fled(false), interrupt_cooldown(20000)
        {
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            has_fled = false;
            interrupt_cooldown = 20000;
            scheduler
                .Schedule(Seconds(0), [this](TaskContext ArcaneMissiles)
                {
                    DoCastVictim(SPELL_ARCANE_MISSILES);
                    ArcaneMissiles.Repeat(Milliseconds(2400), Milliseconds(3800));
                })
                .Schedule(Seconds(3), Seconds(6), [this](TaskContext ChainsOfIce)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(target, SPELL_CHAINS_OF_ICE, true);
                    ChainsOfIce.Repeat(Seconds(20),Seconds(25));
                });
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() || !me->GetVictim())
                return;

            interrupt_cooldown += diff;
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (me->EnsureVictim()->HasUnitState(UNIT_STATE_CASTING) && interrupt_cooldown > 25000)
            {
                DoCastVictim(SPELL_COUNTERSPELL);
                interrupt_cooldown = 0;
            }

            scheduler.Update(diff, [this]
            {
                DoMeleeAttackIfReady();
            });
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            if (!has_fled && me->GetHealth() > damage && me->HealthBelowPctDamaged(15, damage))
            {
                me->DoFleeToGetAssistance();
                has_fled = true;
            }
        }

    private:
        bool has_fled;
        uint32 interrupt_cooldown;
    };

    struct npc_kil_sorrow_cultistAI : public npc_nagrand_bannerAI
    {
        enum KilSorrowCultist
        {
            SPELL_MIND_SEAR = 32000
        };

        npc_kil_sorrow_cultistAI(Creature* creature) : npc_nagrand_bannerAI(creature)
        {
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            scheduler
                .Schedule(Milliseconds(4500), [this](TaskContext MindSear)
                {
                    DoCastVictim(SPELL_MIND_SEAR);
                    MindSear.Repeat(Milliseconds(7000), Milliseconds(11000));
                });
        }
    };

    struct npc_kil_sorrow_deathswornAI : public npc_nagrand_bannerAI
    {
        enum KilSorrowDeathsworn
        {
            SPELL_BLOODTHIRST = 31996
        };

        npc_kil_sorrow_deathswornAI(Creature* creature) : npc_nagrand_bannerAI(creature), used_bloodthirst(false)
        {
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            used_bloodthirst = false;
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            if (!used_bloodthirst && me->GetHealth() > damage && me->HealthBelowPctDamaged(50, damage))
            {
                DoCastVictim(SPELL_BLOODTHIRST);
                used_bloodthirst = true;
            }
        }

    private:
        bool used_bloodthirst;
    };

    struct npc_giselda_the_croneAI : public npc_nagrand_bannerAI
    {
        enum GiseldaTheCrone
        {
            SPELL_GISELDA_TRANSFORM_DND = 33316
        };

        npc_giselda_the_croneAI(Creature* creature) : npc_nagrand_bannerAI(creature), used_transform(false)
        {
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            used_transform = false;
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            if (!used_transform && me->GetHealth() > damage && me->HealthBelowPctDamaged(65, damage))
            {
                DoCastVictim(SPELL_GISELDA_TRANSFORM_DND);
                used_transform = true;
            }
        }

    private:
        bool used_transform;
    };

    struct npc_warmaul_shamanAI : public npc_nagrand_bannerAI
    {
        enum WarmaulShaman
        {
            SPELL_SCORCHING_TOTEM = 15038,
            SPELL_FROST_SHOCK     = 12548,
            SPELL_HEALING_WAVE    = 11986
        };

        npc_warmaul_shamanAI(Creature* creature) : npc_nagrand_bannerAI(creature), used_healing(false)
        {
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            used_healing = false;
            scheduler
                .Schedule(Seconds(2), [this](TaskContext /*SearingTotem*/)
                {
                    DoCast(SPELL_SCORCHING_TOTEM);
                })
                .Schedule(Seconds(6), [this](TaskContext FrostShock)
                {
                    DoCastVictim(SPELL_FROST_SHOCK);
                    FrostShock.Repeat(Seconds(12));
                });
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            if (!used_healing && me->GetHealth() > damage && me->HealthBelowPctDamaged(50, damage))
            {
                DoCastSelf(SPELL_HEALING_WAVE);
                used_healing = true;
            }
        }

    private:
        uint32 used_healing;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        switch (creature->GetEntry())
        {
            case NPC_KIL_SORROW_SPELLBINDER:
                return new npc_kil_sorrow_spellbinderAI(creature);
            case NPC_KIL_SORROW_CULTIST:
                return new npc_kil_sorrow_cultistAI(creature);
            case NPC_KIL_SORROW_DEATHSWORN:
                return new npc_kil_sorrow_deathswornAI(creature);
            case NPC_GISELDA_THE_CRONE:
                return new npc_giselda_the_croneAI(creature);
            case NPC_WARMAUL_SHAMAN:
                return new npc_warmaul_shamanAI(creature);
            default:
                return new npc_nagrand_bannerAI(creature);
        }
    }
};

class condition_nagrand_banner : public ConditionScript
{
public:
    condition_nagrand_banner() : ConditionScript("conditition_nagrand_banner") {}

    bool OnConditionCheck(Condition const* condition, ConditionSourceInfo& sourceInfo) override
    {
        WorldObject* target = sourceInfo.mConditionTargets[condition->ConditionTarget];
        if (Creature* creature = target->ToCreature())
        {
            if (npc_nagrand_banner::npc_nagrand_bannerAI *ai = CAST_AI(npc_nagrand_banner::npc_nagrand_bannerAI, creature->AI()))
                return !ai->IsBannered();
        }
        return false;
    }
};

void AddSC_nagrand()
{
    new npc_maghar_captive();
    new npc_corki();
    new go_corkis_prison();
    new npc_kurenai_captive();
    new go_warmaul_prison();
    new npc_nagrand_banner();
    new condition_nagrand_banner();
}
