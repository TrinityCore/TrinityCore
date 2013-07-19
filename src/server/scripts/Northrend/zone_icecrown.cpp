/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SpellAuras.h"
#include "Player.h"
#include "TemporarySummon.h"
#include "CombatAI.h"

/*######
## npc_arete
######*/

#define GOSSIP_ARETE_ITEM1 "Lord-Commander, I would hear your tale."
#define GOSSIP_ARETE_ITEM2 "<You nod slightly but do not complete the motion as the Lord-Commander narrows his eyes before he continues.>"
#define GOSSIP_ARETE_ITEM3 "I thought that they now called themselves the Scarlet Onslaught?"
#define GOSSIP_ARETE_ITEM4 "Where did the grand admiral go?"
#define GOSSIP_ARETE_ITEM5 "That's fine. When do I start?"
#define GOSSIP_ARETE_ITEM6 "Let's finish this!"
#define GOSSIP_ARETE_ITEM7 "That's quite a tale, Lord-Commander."

enum Arete
{
    GOSSIP_TEXTID_ARETE1        = 13525,
    GOSSIP_TEXTID_ARETE2        = 13526,
    GOSSIP_TEXTID_ARETE3        = 13527,
    GOSSIP_TEXTID_ARETE4        = 13528,
    GOSSIP_TEXTID_ARETE5        = 13529,
    GOSSIP_TEXTID_ARETE6        = 13530,
    GOSSIP_TEXTID_ARETE7        = 13531,

    QUEST_THE_STORY_THUS_FAR    = 12807
};

class npc_arete : public CreatureScript
{
public:
    npc_arete() : CreatureScript("npc_arete") { }

    bool OnGossipHello(Player* player, Creature* creature) OVERRIDE
    {
        if (creature->IsQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (player->GetQuestStatus(QUEST_THE_STORY_THUS_FAR) == QUEST_STATUS_INCOMPLETE)
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ARETE_ITEM1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_ARETE1, creature->GetGUID());
            return true;
        }

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) OVERRIDE
    {
        player->PlayerTalkClass->ClearMenus();
        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ARETE_ITEM2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_ARETE2, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+2:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ARETE_ITEM3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
                player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_ARETE3, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+3:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ARETE_ITEM4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
                player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_ARETE4, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+4:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ARETE_ITEM5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
                player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_ARETE5, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+5:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ARETE_ITEM6, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
                player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_ARETE6, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+6:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ARETE_ITEM7, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
                player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_ARETE7, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+7:
                player->CLOSE_GOSSIP_MENU();
                player->AreaExploredOrEventHappens(QUEST_THE_STORY_THUS_FAR);
                break;
        }

        return true;
    }
};

/*######
## npc_squire_david
######*/

enum SquireDavid
{
    QUEST_THE_ASPIRANT_S_CHALLENGE_H                    = 13680,
    QUEST_THE_ASPIRANT_S_CHALLENGE_A                    = 13679,

    NPC_ARGENT_VALIANT                                  = 33448,

    GOSSIP_TEXTID_SQUIRE                                = 14407
};

#define GOSSIP_SQUIRE_ITEM_1 "I am ready to fight!"
#define GOSSIP_SQUIRE_ITEM_2 "How do the Argent Crusader raiders fight?"

class npc_squire_david : public CreatureScript
{
public:
    npc_squire_david() : CreatureScript("npc_squire_david") { }

    bool OnGossipHello(Player* player, Creature* creature) OVERRIDE
    {
        if (player->GetQuestStatus(QUEST_THE_ASPIRANT_S_CHALLENGE_H) == QUEST_STATUS_INCOMPLETE ||
            player->GetQuestStatus(QUEST_THE_ASPIRANT_S_CHALLENGE_A) == QUEST_STATUS_INCOMPLETE)//We need more info about it.
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SQUIRE_ITEM_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SQUIRE_ITEM_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
        }

        player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_SQUIRE, creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) OVERRIDE
    {
        player->PlayerTalkClass->ClearMenus();
        if (action == GOSSIP_ACTION_INFO_DEF+1)
        {
            player->CLOSE_GOSSIP_MENU();
            creature->SummonCreature(NPC_ARGENT_VALIANT, 8575.451f, 952.472f, 547.554f, 0.38f);
        }
        return true;
    }
};

/*######
## npc_argent_valiant
######*/

enum ArgentValiant
{
    SPELL_CHARGE                = 63010,
    SPELL_SHIELD_BREAKER        = 65147,
    SPELL_KILL_CREDIT           = 63049
};

class npc_argent_valiant : public CreatureScript
{
public:
    npc_argent_valiant() : CreatureScript("npc_argent_valiant") { }

    struct npc_argent_valiantAI : public ScriptedAI
    {
        npc_argent_valiantAI(Creature* creature) : ScriptedAI(creature)
        {
            creature->GetMotionMaster()->MovePoint(0, 8599.258f, 963.951f, 547.553f);
            creature->setFaction(35); //wrong faction in db?
        }

        uint32 uiChargeTimer;
        uint32 uiShieldBreakerTimer;

        void Reset() OVERRIDE
        {
            uiChargeTimer = 7000;
            uiShieldBreakerTimer = 10000;
        }

        void MovementInform(uint32 uiType, uint32 /*uiId*/) OVERRIDE
        {
            if (uiType != POINT_MOTION_TYPE)
                return;

            me->setFaction(14);
        }

        void DamageTaken(Unit* pDoneBy, uint32& uiDamage) OVERRIDE
        {
            if (uiDamage > me->GetHealth() && pDoneBy->GetTypeId() == TYPEID_PLAYER)
            {
                uiDamage = 0;
                pDoneBy->CastSpell(pDoneBy, SPELL_KILL_CREDIT, true);
                me->setFaction(35);
                me->DespawnOrUnsummon(5000);
                me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
                EnterEvadeMode();
            }
        }

        void UpdateAI(uint32 uiDiff) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            if (uiChargeTimer <= uiDiff)
            {
                DoCastVictim(SPELL_CHARGE);
                uiChargeTimer = 7000;
            } else uiChargeTimer -= uiDiff;

            if (uiShieldBreakerTimer <= uiDiff)
            {
                DoCastVictim(SPELL_SHIELD_BREAKER);
                uiShieldBreakerTimer = 10000;
            } else uiShieldBreakerTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_argent_valiantAI(creature);
    }
};

/*######
## npc_guardian_pavilion
######*/

enum GuardianPavilion
{
    SPELL_TRESPASSER_H                            = 63987,
    AREA_SUNREAVER_PAVILION                       = 4676,

    AREA_SILVER_COVENANT_PAVILION                 = 4677,
    SPELL_TRESPASSER_A                            = 63986,
};

class npc_guardian_pavilion : public CreatureScript
{
public:
    npc_guardian_pavilion() : CreatureScript("npc_guardian_pavilion") { }

    struct npc_guardian_pavilionAI : public ScriptedAI
    {
        npc_guardian_pavilionAI(Creature* creature) : ScriptedAI(creature)
        {
            SetCombatMovement(false);
        }

        void MoveInLineOfSight(Unit* who) OVERRIDE

        {
            if (me->GetAreaId() != AREA_SUNREAVER_PAVILION && me->GetAreaId() != AREA_SILVER_COVENANT_PAVILION)
                return;

            if (!who || who->GetTypeId() != TYPEID_PLAYER || !me->IsHostileTo(who) || !me->isInBackInMap(who, 5.0f))
                return;

            if (who->HasAura(SPELL_TRESPASSER_H) || who->HasAura(SPELL_TRESPASSER_A))
                return;

            if (who->ToPlayer()->GetTeamId() == TEAM_ALLIANCE)
                who->CastSpell(who, SPELL_TRESPASSER_H, true);
            else
                who->CastSpell(who, SPELL_TRESPASSER_A, true);

        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_guardian_pavilionAI(creature);
    }
};

/*######
## npc_vereth_the_cunning
######*/

enum VerethTheCunning
{
    NPC_GEIST_RETURN_BUNNY_KC   = 31049,
    NPC_LITHE_STALKER           = 30894,
    SPELL_SUBDUED_LITHE_STALKER = 58151,
};

class npc_vereth_the_cunning : public CreatureScript
{
public:
    npc_vereth_the_cunning() : CreatureScript("npc_vereth_the_cunning") { }

    struct npc_vereth_the_cunningAI : public ScriptedAI
    {
        npc_vereth_the_cunningAI(Creature* creature) : ScriptedAI(creature) {}

        void MoveInLineOfSight(Unit* who) OVERRIDE

        {
            ScriptedAI::MoveInLineOfSight(who);

            if (who->GetEntry() == NPC_LITHE_STALKER && me->IsWithinDistInMap(who, 10.0f))
            {
                if (Unit* owner = who->GetCharmer())
                {
                    if (who->HasAura(SPELL_SUBDUED_LITHE_STALKER))
                        {
                            owner->ToPlayer()->KilledMonsterCredit(NPC_GEIST_RETURN_BUNNY_KC, 0);
                            who->ToCreature()->DisappearAndDie();

                    }
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_vereth_the_cunningAI(creature);
    }
};

/*######
* npc_tournament_training_dummy
######*/
enum TournamentDummy
{
    NPC_CHARGE_TARGET         = 33272,
    NPC_MELEE_TARGET          = 33229,
    NPC_RANGED_TARGET         = 33243,

    SPELL_CHARGE_CREDIT       = 62658,
    SPELL_MELEE_CREDIT        = 62672,
    SPELL_RANGED_CREDIT       = 62673,

    SPELL_PLAYER_THRUST       = 62544,
    SPELL_PLAYER_BREAK_SHIELD = 62626,
    SPELL_PLAYER_CHARGE       = 62874,

    SPELL_RANGED_DEFEND       = 62719,
    SPELL_CHARGE_DEFEND       = 64100,
    SPELL_VULNERABLE          = 62665,

    SPELL_COUNTERATTACK       = 62709,

    EVENT_DUMMY_RECAST_DEFEND = 1,
    EVENT_DUMMY_RESET         = 2,
};

class npc_tournament_training_dummy : public CreatureScript
{
    public:
        npc_tournament_training_dummy(): CreatureScript("npc_tournament_training_dummy"){}

        struct npc_tournament_training_dummyAI : ScriptedAI
        {
            npc_tournament_training_dummyAI(Creature* creature) : ScriptedAI(creature)
            {
                SetCombatMovement(false);
            }

            EventMap events;
            bool isVulnerable;

            void Reset() OVERRIDE
            {
                me->SetControlled(true, UNIT_STATE_STUNNED);
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                isVulnerable = false;

                // Cast Defend spells to max stack size
                switch (me->GetEntry())
                {
                    case NPC_CHARGE_TARGET:
                        DoCast(SPELL_CHARGE_DEFEND);
                        break;
                    case NPC_RANGED_TARGET:
                        me->CastCustomSpell(SPELL_RANGED_DEFEND, SPELLVALUE_AURA_STACK, 3, me);
                        break;
                }

                events.Reset();
                events.ScheduleEvent(EVENT_DUMMY_RECAST_DEFEND, 5000);
            }

            void EnterEvadeMode() OVERRIDE
            {
                if (!_EnterEvadeMode())
                    return;

                Reset();
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage) OVERRIDE
            {
                damage = 0;
                events.RescheduleEvent(EVENT_DUMMY_RESET, 10000);
            }

            void SpellHit(Unit* caster, SpellInfo const* spell) OVERRIDE
            {
                switch (me->GetEntry())
                {
                    case NPC_CHARGE_TARGET:
                        if (spell->Id == SPELL_PLAYER_CHARGE)
                            if (isVulnerable)
                                DoCast(caster, SPELL_CHARGE_CREDIT, true);
                        break;
                    case NPC_MELEE_TARGET:
                        if (spell->Id == SPELL_PLAYER_THRUST)
                        {
                            DoCast(caster, SPELL_MELEE_CREDIT, true);

                            if (Unit* target = caster->GetVehicleBase())
                                DoCast(target, SPELL_COUNTERATTACK, true);
                        }
                        break;
                    case NPC_RANGED_TARGET:
                        if (spell->Id == SPELL_PLAYER_BREAK_SHIELD)
                            if (isVulnerable)
                                DoCast(caster, SPELL_RANGED_CREDIT, true);
                        break;
                }

                if (spell->Id == SPELL_PLAYER_BREAK_SHIELD)
                    if (!me->HasAura(SPELL_CHARGE_DEFEND) && !me->HasAura(SPELL_RANGED_DEFEND))
                        isVulnerable = true;
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                events.Update(diff);

                switch (events.ExecuteEvent())
                {
                    case EVENT_DUMMY_RECAST_DEFEND:
                        switch (me->GetEntry())
                        {
                            case NPC_CHARGE_TARGET:
                            {
                                if (!me->HasAura(SPELL_CHARGE_DEFEND))
                                    DoCast(SPELL_CHARGE_DEFEND);
                                break;
                            }
                            case NPC_RANGED_TARGET:
                            {
                                Aura* defend = me->GetAura(SPELL_RANGED_DEFEND);
                                if (!defend || defend->GetStackAmount() < 3 || defend->GetDuration() <= 8000)
                                    DoCast(SPELL_RANGED_DEFEND);
                                break;
                            }
                        }
                        isVulnerable = false;
                        events.ScheduleEvent(EVENT_DUMMY_RECAST_DEFEND, 5000);
                        break;
                    case EVENT_DUMMY_RESET:
                        if (UpdateVictim())
                        {
                            EnterEvadeMode();
                            events.ScheduleEvent(EVENT_DUMMY_RESET, 10000);
                        }
                        break;
                }

                if (!UpdateVictim())
                    return;

                if (!me->HasUnitState(UNIT_STATE_STUNNED))
                    me->SetControlled(true, UNIT_STATE_STUNNED);
            }

            void MoveInLineOfSight(Unit* /*who*/)OVERRIDE {}

        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return new npc_tournament_training_dummyAI(creature);
        }

};

// Battle for Crusaders' Pinnacle
enum BlessedBanner
{
    SPELL_BLESSING_OF_THE_CRUSADE       = 58026,
    SPELL_THREAT_PULSE                  = 58113,
    SPELL_CRUSADERS_SPIRE_VICTORY       = 58084,
    SPELL_TORCH                         = 58121,

    NPC_BLESSED_BANNER                  = 30891,
    NPC_CRUSADER_LORD_DALFORS           = 31003,
    NPC_ARGENT_BATTLE_PRIEST            = 30919,
    NPC_ARGENT_MASON                    = 30900,
    NPC_REANIMATED_CAPTAIN              = 30986,
    NPC_SCOURGE_DRUDGE                  = 30984,
    NPC_HIDEOUS_PLAGEBRINGER            = 30987,
    NPC_HALOF_THE_DEATHBRINGER          = 30989,
    NPC_LK                              = 31013,

    BANNER_SAY                          = 0, // "The Blessed Banner of the Crusade has been planted.\n Defend the banner from all attackers!"
    DALFORS_SAY_PRE_1                   = 0, // "BY THE LIGHT! Those damned monsters! Look at what they've done to our people!"
    DALFORS_SAY_PRE_2                   = 1, // "Burn it down, boys. Burn it all down."
    DALFORS_SAY_START                   = 2, // "Let 'em come. They'll pay for what they've done!"
    DALFORS_YELL_FINISHED               = 3, // "We've done it, lads! We've taken the pinnacle from the Scourge! Report to Father Gustav at once and tell him the good news! We're gonna get to buildin' and settin' up! Go!"
    LK_TALK_1                           = 0, // "Leave no survivors!"
    LK_TALK_2                           = 1, // "Cower before my terrible creations!"
    LK_TALK_3                           = 2, // "Feast my children! Feast upon the flesh of the living!"
    LK_TALK_4                           = 3, // "Lay down your arms and surrender your souls!"

    EVENT_SPAWN                         = 1,
    EVENT_INTRO_1                       = 2,
    EVENT_INTRO_2                       = 3,
    EVENT_INTRO_3                       = 4,
    EVENT_MASON_ACTION                  = 5,
    EVENT_START_FIGHT                   = 6,
    EVENT_WAVE_SPAWN                    = 7,
    EVENT_HALOF                         = 8,
    EVENT_ENDED                         = 9,
};

Position const DalforsPos[3] =
{
    {6458.703f, 403.858f, 490.498f, 3.1205f}, // Dalfors spawn point
    {6422.950f, 423.335f, 510.451f, 0.0f}, // Dalfors intro pos
    {6426.343f, 420.515f, 508.650f, 0.0f}, // Dalfors fight pos
};

Position const Priest1Pos[2] =
{
    {6462.025f, 403.681f, 489.721f, 3.1007f}, // priest1 spawn point
    {6421.480f, 423.576f, 510.781f, 5.7421f}, // priest1 intro pos
};

Position const Priest2Pos[2] =
{
    {6463.969f, 407.198f, 489.240f, 2.2689f}, // priest2 spawn point
    {6419.778f, 421.404f, 510.972f, 5.7421f}, // priest2 intro pos
};

Position const Priest3Pos[2] =
{
    {6464.371f, 400.944f, 489.186f, 6.1610f}, // priest3 spawn point
    {6423.516f, 425.782f, 510.774f, 5.7421f}, // priest3 intro pos
};

Position const Mason1Pos[3] =
{
    {6462.929f, 409.826f, 489.392f, 3.0968f}, // mason1 spawn point
    {6428.163f, 421.960f, 508.297f, 0.0f}, // mason1 intro pos
    {6414.335f, 454.904f, 511.395f, 2.8972f}, // mason1 action pos
};

Position const Mason2Pos[3] =
{
    {6462.650f, 405.670f, 489.576f, 2.9414f}, // mason2 spawn point
    {6426.250f, 419.194f, 508.219f, 0.0f}, // mason2 intro pos
    {6415.014f, 446.849f, 511.395f, 3.1241f}, // mason2 action pos
};

Position const Mason3Pos[3] =
{
    {6462.646f, 401.218f, 489.601f, 2.7864f}, // mason3 spawn point
    {6423.855f, 416.598f, 508.305f, 0.0f}, // mason3 intro pos
    {6417.070f, 438.824f, 511.395f, 3.6651f}, // mason3 action pos
};

class npc_blessed_banner : public CreatureScript
{
public:
    npc_blessed_banner() : CreatureScript("npc_blessed_banner") { }

    struct npc_blessed_bannerAI : public ScriptedAI
    {
        npc_blessed_bannerAI(Creature* creature) : ScriptedAI(creature), Summons(me)
        {
            HalofSpawned = false;
            PhaseCount = 0;
            Summons.DespawnAll();

            SetCombatMovement(false);
        }

        EventMap events;

        bool HalofSpawned;

        uint32 PhaseCount;

        SummonList Summons;

        uint64 guidDalfors;
        uint64 guidPriest[3];
        uint64 guidMason[3];
        uint64 guidHalof;

        void Reset() OVERRIDE
        {
            me->setRegeneratingHealth(false);
            DoCast(SPELL_THREAT_PULSE);
            me->AI()->Talk(BANNER_SAY);
            events.ScheduleEvent(EVENT_SPAWN, 3000);
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE {}

        void MoveInLineOfSight(Unit* /*who*/) OVERRIDE {}


        void JustSummoned(Creature* Summoned) OVERRIDE
        {
            Summons.Summon(Summoned);
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            Summons.DespawnAll();
            me->DespawnOrUnsummon();
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            events.Update(diff);

            switch (events.ExecuteEvent())
            {
                case EVENT_SPAWN:
                    {
                        if (Creature* Dalfors = DoSummon(NPC_CRUSADER_LORD_DALFORS, DalforsPos[0]))
                        {
                            guidDalfors = Dalfors->GetGUID();
                            Dalfors->GetMotionMaster()->MovePoint(0, DalforsPos[1]);
                        }
                        if (Creature* Priest1 = DoSummon(NPC_ARGENT_BATTLE_PRIEST, Priest1Pos[0]))
                        {
                            guidPriest[0] = Priest1->GetGUID();
                            Priest1->GetMotionMaster()->MovePoint(0, Priest1Pos[1]);
                        }
                        if (Creature* Priest2 = DoSummon(NPC_ARGENT_BATTLE_PRIEST, Priest2Pos[0]))
                        {
                            guidPriest[1] = Priest2->GetGUID();
                            Priest2->GetMotionMaster()->MovePoint(0, Priest2Pos[1]);
                        }
                        if (Creature* Priest3 = DoSummon(NPC_ARGENT_BATTLE_PRIEST, Priest3Pos[0]))
                        {
                            guidPriest[2] = Priest3->GetGUID();
                            Priest3->GetMotionMaster()->MovePoint(0, Priest3Pos[1]);
                        }
                        if (Creature* Mason1 = DoSummon(NPC_ARGENT_MASON, Mason1Pos[0]))
                        {
                            guidMason[0] = Mason1->GetGUID();
                            Mason1->GetMotionMaster()->MovePoint(0, Mason1Pos[1]);
                        }
                        if (Creature* Mason2 = DoSummon(NPC_ARGENT_MASON, Mason2Pos[0]))
                        {
                            guidMason[1] = Mason2->GetGUID();
                            Mason2->GetMotionMaster()->MovePoint(0, Mason2Pos[1]);
                        }
                        if (Creature* Mason3 = DoSummon(NPC_ARGENT_MASON, Mason3Pos[0]))
                        {
                            guidMason[2] = Mason3->GetGUID();
                            Mason3->GetMotionMaster()->MovePoint(0, Mason3Pos[1]);
                        }
                        events.ScheduleEvent(EVENT_INTRO_1, 15000);
                    }
                    break;
                case EVENT_INTRO_1:
                    {
                        if (Creature* Dalfors = me->GetCreature(*me, guidDalfors))
                            Dalfors->AI()->Talk(DALFORS_SAY_PRE_1);
                        events.ScheduleEvent(EVENT_INTRO_2, 5000);
                    }
                    break;
                case EVENT_INTRO_2:
                    {
                        if (Creature* Dalfors = me->GetCreature(*me, guidDalfors))
                        {
                            Dalfors->SetFacingTo(6.215f);
                            Dalfors->AI()->Talk(DALFORS_SAY_PRE_2);
                        }
                    events.ScheduleEvent(EVENT_INTRO_3, 5000);
                    }
                    break;
                case EVENT_INTRO_3:
                    {
                        if (Creature* Dalfors = me->GetCreature(*me, guidDalfors))
                        {
                            Dalfors->GetMotionMaster()->MovePoint(0, DalforsPos[2]);
                            Dalfors->SetHomePosition(DalforsPos[2]);
                        }
                        if (Creature* Priest1 = me->GetCreature(*me, guidPriest[0]))
                        {
                            Priest1->SetFacingTo(5.7421f);
                            Priest1->SetHomePosition(Priest1Pos[1]);
                        }
                        if (Creature* Priest2 = me->GetCreature(*me, guidPriest[1]))
                        {
                            Priest2->SetFacingTo(5.7421f);
                            Priest2->SetHomePosition(Priest2Pos[1]);
                        }
                        if (Creature* Priest3 = me->GetCreature(*me, guidPriest[2]))
                        {
                            Priest3->SetFacingTo(5.7421f);
                            Priest3->SetHomePosition(Priest3Pos[1]);
                        }
                        if (Creature* Mason1 = me->GetCreature(*me, guidMason[0]))
                        {
                            Mason1->GetMotionMaster()->MovePoint(0, Mason1Pos[2]);
                            Mason1->SetHomePosition(Mason1Pos[2]);
                        }
                        if (Creature* Mason2 = me->GetCreature(*me, guidMason[1]))
                        {
                            Mason2->GetMotionMaster()->MovePoint(0, Mason2Pos[2]);
                            Mason2->SetHomePosition(Mason2Pos[2]);
                        }
                        if (Creature* Mason3 = me->GetCreature(*me, guidMason[2]))
                        {
                            Mason3->GetMotionMaster()->MovePoint(0, Mason3Pos[2]);
                            Mason3->SetHomePosition(Mason3Pos[2]);
                        }
                        events.ScheduleEvent(EVENT_START_FIGHT, 5000);
                        events.ScheduleEvent(EVENT_MASON_ACTION, 15000);
                    }
                    break;
                case EVENT_MASON_ACTION:
                    {
                        if (Creature* Mason1 = me->GetCreature(*me, guidMason[0]))
                        {
                            Mason1->SetFacingTo(2.8972f);
                            Mason1->AI()->SetData(1, 1); // triggers SAI actions on npc
                        }
                        if (Creature* Mason2 = me->GetCreature(*me, guidMason[1]))
                        {
                            Mason2->SetFacingTo(3.1241f);
                            Mason2->AI()->SetData(1, 1); // triggers SAI actions on npc
                        }
                        if (Creature* Mason3 = me->GetCreature(*me, guidMason[2]))
                        {
                            Mason3->SetFacingTo(3.6651f);
                            Mason3->AI()->SetData(1, 1); // triggers SAI actions on npc
                        }
                    }
                    break;
                case EVENT_START_FIGHT:
                    {
                        if (Creature* LK = GetClosestCreatureWithEntry(me, NPC_LK, 100))
                            LK->AI()->Talk(LK_TALK_1);
                        if (Creature* Dalfors = me->GetCreature(*me, guidDalfors))
                            Dalfors->AI()->Talk(DALFORS_SAY_START);
                        events.ScheduleEvent(EVENT_WAVE_SPAWN, 1000);
                    }
                    break;
                case EVENT_WAVE_SPAWN:
                    {
                        if (PhaseCount == 3)
                        {
                            if (Creature* LK = GetClosestCreatureWithEntry(me, NPC_LK, 100))
                                LK->AI()->Talk(LK_TALK_2);
                        }
                        else if (PhaseCount == 6)
                        {
                            if (Creature* LK = GetClosestCreatureWithEntry(me, NPC_LK, 100))
                                LK->AI()->Talk(LK_TALK_3);
                        }
                        if (Creature* tempsum = DoSummon(NPC_SCOURGE_DRUDGE, Mason3Pos[0]))
                            {
                                tempsum->SetHomePosition(DalforsPos[2]);
                                tempsum->AI()->AttackStart(GetClosestCreatureWithEntry(me, NPC_BLESSED_BANNER, 100));
                            }
                        if (urand(0, 1) == 0)
                        {
                            if (Creature* tempsum = DoSummon(NPC_HIDEOUS_PLAGEBRINGER, Mason1Pos[0]))
                            {
                                tempsum->SetHomePosition(DalforsPos[2]);
                                tempsum->AI()->AttackStart(GetClosestCreatureWithEntry(me, NPC_BLESSED_BANNER, 100));
                            }
                            if (Creature* tempsum = DoSummon(NPC_HIDEOUS_PLAGEBRINGER, Mason2Pos[0]))
                            {
                                tempsum->SetHomePosition(DalforsPos[2]);
                                tempsum->AI()->AttackStart(GetClosestCreatureWithEntry(me, NPC_BLESSED_BANNER, 100));
                            }
                        }
                        else
                        {
                            if (Creature* tempsum = DoSummon(NPC_REANIMATED_CAPTAIN, Mason1Pos[0]))
                            {
                                tempsum->SetHomePosition(DalforsPos[2]);
                                tempsum->AI()->AttackStart(GetClosestCreatureWithEntry(me, NPC_BLESSED_BANNER, 100));
                            }
                            if (Creature* tempsum = DoSummon(NPC_REANIMATED_CAPTAIN, Mason2Pos[0]))
                            {
                                tempsum->SetHomePosition(DalforsPos[2]);
                                tempsum->AI()->AttackStart(GetClosestCreatureWithEntry(me, NPC_BLESSED_BANNER, 100));
                            }
                        }

                        PhaseCount++;

                        if (PhaseCount < 8)
                            events.ScheduleEvent(EVENT_WAVE_SPAWN, urand(10000, 20000));
                        else
                            events.ScheduleEvent(EVENT_HALOF, urand(10000, 20000));
                    }
                    break;
                case EVENT_HALOF:
                    {
                        if (Creature* LK = GetClosestCreatureWithEntry(me, NPC_LK, 100))
                            LK->AI()->Talk(LK_TALK_4);
                        if (Creature* tempsum = DoSummon(NPC_SCOURGE_DRUDGE, Mason1Pos[0]))
                        {
                            tempsum->SetHomePosition(DalforsPos[2]);
                            tempsum->AI()->AttackStart(GetClosestCreatureWithEntry(me, NPC_BLESSED_BANNER, 100));
                        }
                        if (Creature* tempsum = DoSummon(NPC_SCOURGE_DRUDGE, Mason2Pos[0]))
                        {
                            tempsum->SetHomePosition(DalforsPos[2]);
                            tempsum->AI()->AttackStart(GetClosestCreatureWithEntry(me, NPC_BLESSED_BANNER, 100));
                        }
                        if (Creature* tempsum = DoSummon(NPC_HALOF_THE_DEATHBRINGER, DalforsPos[0]))
                        {
                            HalofSpawned = true;
                            guidHalof = tempsum->GetGUID();
                            tempsum->SetHomePosition(DalforsPos[2]);
                            tempsum->AI()->AttackStart(GetClosestCreatureWithEntry(me, NPC_BLESSED_BANNER, 100));
                        }
                    }
                    break;
                case EVENT_ENDED:
                    {
                        Summons.DespawnAll();
                        me->DespawnOrUnsummon();
                    }
                    break;
            }

            if (PhaseCount == 8)
                if (Creature* Halof = me->GetCreature(*me, guidHalof))
                    if (Halof->isDead())
                    {
                        DoCast(me, SPELL_CRUSADERS_SPIRE_VICTORY, true);
                        Summons.DespawnEntry(NPC_HIDEOUS_PLAGEBRINGER);
                        Summons.DespawnEntry(NPC_REANIMATED_CAPTAIN);
                        Summons.DespawnEntry(NPC_SCOURGE_DRUDGE);
                        Summons.DespawnEntry(NPC_HALOF_THE_DEATHBRINGER);
                        if (Creature* Dalfors = me->GetCreature(*me, guidDalfors))
                            Dalfors->AI()->Talk(DALFORS_YELL_FINISHED);
                        events.ScheduleEvent(EVENT_ENDED, 10000);
                    }
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_blessed_bannerAI(creature);
    }
};

/*######
## Borrowed Technology - Id: 13291, The Solution Solution (daily) - Id: 13292, Volatility - Id: 13239, Volatiliy - Id: 13261 (daily)
######*/

enum BorrowedTechnologyAndVolatility
{
    // Spells
    SPELL_GRAB             = 59318,
    SPELL_PING_BUNNY       = 59375,
    SPELL_IMMOLATION       = 54690,
    SPELL_EXPLOSION        = 59335,
    SPELL_RIDE             = 56687,

    // Points
    POINT_GRAB_DECOY       = 1,
    POINT_FLY_AWAY         = 2,

    // Events
    EVENT_FLY_AWAY         = 1
};

class npc_frostbrood_skytalon : public CreatureScript
{
    public:
        npc_frostbrood_skytalon() : CreatureScript("npc_frostbrood_skytalon") { }

        struct npc_frostbrood_skytalonAI : public VehicleAI
        {
            npc_frostbrood_skytalonAI(Creature* creature) : VehicleAI(creature) { }

            EventMap events;

            void IsSummonedBy(Unit* summoner) OVERRIDE
            {
                me->GetMotionMaster()->MovePoint(POINT_GRAB_DECOY, summoner->GetPositionX(), summoner->GetPositionY(), summoner->GetPositionZ());
            }

            void MovementInform(uint32 type, uint32 id) OVERRIDE
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                if (id == POINT_GRAB_DECOY)
                    if (TempSummon* summon = me->ToTempSummon())
                        if (Unit* summoner = summon->GetSummoner())
                            DoCast(summoner, SPELL_GRAB);
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                VehicleAI::UpdateAI(diff);
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    if (eventId == EVENT_FLY_AWAY)
                    {
                        Position randomPosOnRadius;
                        randomPosOnRadius.m_positionZ = (me->GetPositionZ() + 40.0f);
                        me->GetNearPoint2D(randomPosOnRadius.m_positionX, randomPosOnRadius.m_positionY, 40.0f, me->GetAngle(me));
                        me->GetMotionMaster()->MovePoint(POINT_FLY_AWAY, randomPosOnRadius);
                    }
                }
            }

            void SpellHit(Unit* /*caster*/, SpellInfo const* spell) OVERRIDE
            {
                switch (spell->Id)
                {
                    case SPELL_EXPLOSION:
                        DoCast(me, SPELL_IMMOLATION);
                        break;
                    case SPELL_RIDE:
                        DoCastAOE(SPELL_PING_BUNNY);
                        events.ScheduleEvent(EVENT_FLY_AWAY, 100);
                        break;
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return new npc_frostbrood_skytalonAI(creature);
        }
};

/*######
## The Flesh Giant Champion - Id: 13235
######*/
enum FleshGiant
{
    QUEST_FLESH_GIANT_CHAMPION = 13235,

    NPC_MORBIDUS = 30698,
    NPC_LICH_KING = 31301,
    NPC_OLAKIN = 31428,
    NPC_DHAKAR = 31306,

    FACTION_HOSTILE = 14,
    FACTION_BASIC = 2102,

    EVENT_INTRO = 1,
    EVENT_LK_SAY_1 = 2,
    EVENT_LK_SAY_2 = 3,
    EVENT_LK_SAY_3 = 4,
    EVENT_LK_SAY_4 = 5,
    EVENT_LK_SAY_5 = 6,
    EVENT_OUTRO = 7,
    EVENT_START = 8,

    SPELL_SIMPLE_TELEPORT = 64195,

    SAY_DHAKAR_START = 0,
    SAY_LK_1 = 0,
    SAY_LK_2 = 1,
    SAY_LK_3 = 2,
    SAY_LK_4 = 3,
    SAY_LK_5 = 4,
    SAY_OLAKIN_PAY = 0
};

class npc_margrave_dhakar : public CreatureScript
{
    public:
        npc_margrave_dhakar() : CreatureScript("npc_margrave_dhakar") { }

        struct npc_margrave_dhakarAI : public ScriptedAI
        {
            npc_margrave_dhakarAI(Creature* creature) : ScriptedAI(creature) , _summons(me), _lichKingGuid(0) { }

            void Reset() OVERRIDE
            {
                me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_NONE);

                _events.Reset();
                _summons.DespawnAll();
            }

            void sGossipSelect(Player* player, uint32 sender, uint32 action) OVERRIDE
            {
                if (player->GetQuestStatus(QUEST_FLESH_GIANT_CHAMPION) == QUEST_STATUS_INCOMPLETE && !player->IsInCombat())
                {
                    if (me->GetCreatureTemplate()->GossipMenuId == sender && !action)
                    {
                        _events.ScheduleEvent(EVENT_INTRO, 1000);
                        me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    }
                }
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_INTRO:
                        {
                            Talk(SAY_DHAKAR_START);
                            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY2H);

                            if (Creature* morbidus = me->FindNearestCreature(NPC_MORBIDUS, 50.0f, true))
                            {
                                Creature* lichKing = me->SummonCreature(NPC_LICH_KING, morbidus->GetPositionX()+10, morbidus->GetPositionY(), morbidus->GetPositionZ());
                                _lichKingGuid = lichKing->GetGUID();
                                lichKing = me->SummonCreature(NPC_LICH_KING, morbidus->GetPositionX()+10, morbidus->GetPositionY(), morbidus->GetPositionZ());
                                lichKing->SetFacingTo(morbidus->GetOrientation());
                                lichKing->CastSpell(lichKing, SPELL_SIMPLE_TELEPORT, true);
                            }

                            _events.ScheduleEvent(EVENT_LK_SAY_1, 5000);
                            break;
                        }
                        case EVENT_LK_SAY_1:
                        {
                            if (Creature* lichKing = Unit::GetCreature(*me, _lichKingGuid))
                                lichKing->AI()->Talk(SAY_LK_1);
                            _events.ScheduleEvent(EVENT_LK_SAY_2, 5000);
                            break;
                        }
                        case EVENT_LK_SAY_2:
                        {
                            if (Creature* lichKing = Unit::GetCreature(*me, _lichKingGuid))
                                lichKing->AI()->Talk(SAY_LK_2);
                            _events.ScheduleEvent(EVENT_LK_SAY_3, 5000);
                            break;
                        }
                        case EVENT_LK_SAY_3:
                        {
                            if (Creature* lichKing = Unit::GetCreature(*me, _lichKingGuid))
                                lichKing->AI()->Talk(SAY_LK_3);
                            _events.ScheduleEvent(EVENT_LK_SAY_4, 5000);
                            break;
                        }
                        case EVENT_LK_SAY_4:
                        {
                            if (Creature* lichKing = Unit::GetCreature(*me, _lichKingGuid))
                                lichKing->AI()->Talk(SAY_LK_4);
                            _events.ScheduleEvent(EVENT_OUTRO, 12000);
                            break;
                        }
                        case EVENT_LK_SAY_5:
                        {
                            if (Creature* lichKing = Unit::GetCreature(*me, _lichKingGuid))
                                lichKing->AI()->Talk(SAY_LK_5);
                            _events.ScheduleEvent(EVENT_OUTRO, 8000);
                            break;
                        }
                        case EVENT_OUTRO:
                        {
                            if (Creature* olakin = me->FindNearestCreature(NPC_OLAKIN, 50.0f, true))
                                olakin->AI()->Talk(SAY_OLAKIN_PAY);

                            if (Creature* lichKing = Unit::GetCreature(*me, _lichKingGuid))
                                lichKing->DespawnOrUnsummon(0);

                            _events.ScheduleEvent(EVENT_START, 5000);
                            break;
                        }
                        case EVENT_START:
                        {
                            if (Creature* morbidus = me->FindNearestCreature(NPC_MORBIDUS, 50.0f, true))
                            {
                                morbidus->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_DISABLE_MOVE);
                                morbidus->setFaction(FACTION_HOSTILE);
                            }

                            break;
                        }
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap _events;
            uint64 _lichKingGuid;
            SummonList _summons;
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_margrave_dhakarAI(creature);
    }
};

class npc_morbidus : public CreatureScript
{
    public:
        npc_morbidus() : CreatureScript("npc_morbidus") { }

        struct npc_morbidusAI : public ScriptedAI
        {
            npc_morbidusAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset() OVERRIDE
            {
                if (Creature* dhakar = me->FindNearestCreature(NPC_DHAKAR, 50.0f, true))
                    dhakar->AI()->Reset();

                // this will prevent the event to start without morbidus being alive
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->SetReactState(REACT_PASSIVE);
                me->setFaction(FACTION_BASIC);
            }
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return new npc_morbidusAI(creature);
        }
};

void AddSC_icecrown()
{
    new npc_arete;
    new npc_squire_david;
    new npc_argent_valiant;
    new npc_guardian_pavilion;
    new npc_vereth_the_cunning;
    new npc_tournament_training_dummy;
    new npc_blessed_banner();
    new npc_frostbrood_skytalon();
    new npc_margrave_dhakar();
    new npc_morbidus();
}
