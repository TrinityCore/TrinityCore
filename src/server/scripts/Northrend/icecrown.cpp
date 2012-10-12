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

/* ScriptData
SDName: Icecrown
SD%Complete: 100
SDComment: Quest support: 12807
SDCategory: Icecrown
EndScriptData */

/* ContentData
npc_arete
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SpellAuras.h"

//global define faction in cpp
#define FACTION_FRIENDLY        = 35
#define FACTION_HOSTILE         = 14

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

enum eArete
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

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->isQuestGiver())
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

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
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

enum eSquireDavid
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

    bool OnGossipHello(Player* player, Creature* creature)
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

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
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

enum eArgentValiant
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

        void Reset()
        {
            uiChargeTimer = 7000;
            uiShieldBreakerTimer = 10000;
        }

        void MovementInform(uint32 uiType, uint32 /*uiId*/)
        {
            if (uiType != POINT_MOTION_TYPE)
                return;

            me->setFaction(FACTION_HOSTILE);
        }

        void DamageTaken(Unit* doneby, uint32& uiDamage)
        {
            if (uiDamage > me->GetHealth() && doneby->GetTypeId() == TYPEID_PLAYER)
            {
                uiDamage = 0;
                doneby->CastSpell(doneby, SPELL_KILL_CREDIT, true);
                me->setFaction(FACTION_FRIENDLY);
                me->DespawnOrUnsummon(5000);
                me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
                EnterEvadeMode();
            }
        }

        void UpdateAI(const uint32 uiDiff)
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

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_argent_valiantAI(creature);
    }
};

/*######
## npc_guardian_pavilion
######*/

enum eGuardianPavilion
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

    struct npc_guardian_pavilionAI : public Scripted_NoMovementAI
    {
        npc_guardian_pavilionAI(Creature* creature) : Scripted_NoMovementAI(creature) {}

        void MoveInLineOfSight(Unit* who)
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

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_guardian_pavilionAI(creature);
    }
};

/*######
## npc_vereth_the_cunning
######*/

enum eVerethTheCunning
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

        void MoveInLineOfSight(Unit* who)
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

    CreatureAI* GetAI(Creature* creature) const
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

        struct npc_tournament_training_dummyAI : Scripted_NoMovementAI
        {
            npc_tournament_training_dummyAI(Creature* creature) : Scripted_NoMovementAI(creature) {}

            EventMap events;
            bool isVulnerable;

            void Reset()
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

            void EnterEvadeMode()
            {
                if (!_EnterEvadeMode())
                    return;

                Reset();
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage)
            {
                damage = 0;
                events.RescheduleEvent(EVENT_DUMMY_RESET, 10000);
            }

            void SpellHit(Unit* caster, SpellInfo const* spell)
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

            void UpdateAI(uint32 const diff)
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

            void MoveInLineOfSight(Unit* /*who*/){}
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_tournament_training_dummyAI(creature);
        }

};

/*######
## npc_valiant
######*/

enum valiantChampion
{
    SPELL_REFRESH_MOUNT         = 66483,
    SPELL_GIVE_VALIANT_MARK_1   = 62724,
    SPELL_GIVE_VALIANT_MARK_2   = 62770,
    SPELL_GIVE_VALIANT_MARK_3   = 62771,
    SPELL_GIVE_VALIANT_MARK_4   = 62995,
    SPELL_GIVE_VALIANT_MARK_5   = 62996,
    SPELL_GIVE_CHAMPION_MARK    = 63596,
    SPELL_AURA_PERIODIC         = 64223,
    SPELL_BESTED_DARNASSUS      = 64805,
    SPELL_BESTED_GNOMEREGAN     = 64809,
    SPELL_BESTED_IRONFORGE      = 64810,
    SPELL_BESTED_ORGRIMMAR      = 64811,
    SPELL_BESTED_SENJIN         = 64812,
    SPELL_BESTED_SILVERMOON     = 64813,
    SPELL_BESTED_STORMWIND      = 64814,
    SPELL_BESTED_EXODAR         = 64808,
    SPELL_BESTED_UNDERCITY      = 64816,
    SPELL_BESTED_THUNDERBLUFF   = 64815,
    SPELL_AURA_TOURNAMENT_MOUNT = 63034,
};

static const uint32 QuestTheGrandMelee[] = {13665,13745,13750,13756,13761,13767,13772,13777,13782,13787};
static const uint32 QuestAmongTheChampions[] = {13790,13793,13811,13814};

#define GOSSIP_MELEE_FIGHT      "I'am ready to fight!"

class npc_valiant : public CreatureScript
{
public:
   npc_valiant() : CreatureScript("npc_valiant") { }

   struct npc_valiantAI : public ScriptedAI
   {
       npc_valiantAI(Creature* creature) : ScriptedAI(creature) {}

       uint32 uiChargeTimer;
       uint32 uiShieldBreakerTimer;
       uint64 guidAttacker;
       bool chargeing;

       void Reset()
       {
           uiChargeTimer = 7*IN_MILLISECONDS;
           uiShieldBreakerTimer = 10*IN_MILLISECONDS;

           me->setFaction(FACTION_FRIENDLY);
       }

       void EnterCombat(Unit* attacker)
       {
           guidAttacker = attacker->GetGUID();
           DoCast(me,SPELL_AURA_PERIODIC,true);
           if (Aura* aur = me->AddAura(SPELL_RANGED_DEFEND,me))
               aur->ModStackAmount(1);
       }

       void MovementInform(uint32 uiType, uint32 uiId)
       {
           if (uiType != POINT_MOTION_TYPE)
               return;

           if (uiId != 1)
               return;

           chargeing = false;

           DoCastVictim(SPELL_CHARGE);
           if (me->getVictim())
               me->GetMotionMaster()->MoveChase(me->getVictim());
       }

       void DamageTaken(Unit* doneby, uint32& uiDamage)
       {
           if (uiDamage > me->GetHealth() && doneby->GetTypeId() == TYPEID_PLAYER)
           {
               uiDamage = 0;

               if (doneby->HasAura(SPELL_AURA_TOURNAMENT_MOUNT))
               {
                   switch(me->GetEntry())
                   {
                       case 33559: // Darnassus
                       case 33562: // Exodar
                       case 33558: // Gnomeregan
                       case 33564: // Ironforge
                       case 33306: // Orgrimmar
                       case 33285: // Sen'jin
                       case 33382: // Silvermoon
                       case 33561: // Stormwind
                       case 33383: // Thunder Bluff
                       case 33384: // Undercity
                       {
                           doneby->CastSpell(doneby,SPELL_GIVE_VALIANT_MARK_1,true);
                           break;
                       }
                       case 33738: // Darnassus
                       case 33739: // Exodar
                       case 33740: // Gnomeregan
                       case 33743: // Ironforge
                       case 33744: // Orgrimmar
                       case 33745: // Sen'jin
                       case 33746: // Silvermoon
                       case 33747: // Stormwind
                       case 33748: // Thunder Bluff
                       case 33749: // Undercity
                       {
                           doneby->CastSpell(doneby,SPELL_GIVE_CHAMPION_MARK,true);
                           break;
                       }
                   }

                   switch(me->GetEntry())
                   {
                       case 33738: // Darnassus
                           doneby->CastSpell(doneby,SPELL_BESTED_DARNASSUS,true); break;
                       case 33739: // Exodar
                           doneby->CastSpell(doneby,SPELL_BESTED_EXODAR,true); break;
                       case 33740: // Gnomeregan
                           doneby->CastSpell(doneby,SPELL_BESTED_GNOMEREGAN,true); break;
                       case 33743: // Ironforge
                           doneby->CastSpell(doneby,SPELL_BESTED_IRONFORGE,true); break;
                       case 33744: // Orgrimmar
                           doneby->CastSpell(doneby,SPELL_BESTED_ORGRIMMAR,true); break;
                       case 33745: // Sen'jin
                           doneby->CastSpell(doneby,SPELL_BESTED_SENJIN,true); break;
                       case 33746: // Silvermoon
                           doneby->CastSpell(doneby,SPELL_BESTED_SILVERMOON,true); break;
                       case 33747: // Stormwind
                           doneby->CastSpell(doneby,SPELL_BESTED_STORMWIND,true); break;
                       case 33748: // Thunder Bluff
                           doneby->CastSpell(doneby,SPELL_BESTED_THUNDERBLUFF,true); break;
                       case 33749: // Undercity
                           doneby->CastSpell(doneby,SPELL_BESTED_UNDERCITY,true); break;
                   }
               }

               me->setFaction(FACTION_FRIENDLY);
               EnterEvadeMode();
               me->CastSpell(me,SPELL_REFRESH_MOUNT,true);
           }
       }

       void UpdateAI(const uint32 uiDiff)
       {
           if (!UpdateVictim())
               return;

           if (uiChargeTimer <= uiDiff)
           {
               chargeing = true;
               float x,y,z;
               me->GetNearPoint(me, x, y, z, 1.0f, 15.0f, float(2 * M_PI * rand_norm()));
               me->GetMotionMaster()->MovePoint(1,x,y,z);

               uiChargeTimer = 15*IN_MILLISECONDS;
           } else uiChargeTimer -= uiDiff;

           if (uiShieldBreakerTimer <= uiDiff)
           {
               DoCastVictim(SPELL_SHIELD_BREAKER);
               uiShieldBreakerTimer = 10*IN_MILLISECONDS;
           } else uiShieldBreakerTimer -= uiDiff;

           if (me->isAttackReady())
           {
               DoCast(me->getVictim(), SPELL_PLAYER_THRUST, true);
               me->resetAttackTimer();
           }

           if (Player* player = Player::GetPlayer(*me,guidAttacker))
                if (!player->HasAura(SPELL_AURA_TOURNAMENT_MOUNT))
                    EnterEvadeMode();
       }
   };

   CreatureAI *GetAI(Creature* creature) const
   {
       return new npc_valiantAI(creature);
   }

   bool MakeDuel(Player* player, uint32 npcID)
   {
       switch (npcID)
       {
           case 33738: // Darnassus
               return !player->HasAura(SPELL_BESTED_DARNASSUS);
           case 33739: // Exodar
               return !player->HasAura(SPELL_BESTED_EXODAR);
           case 33740: // Gnomeregan
               return !player->HasAura(SPELL_BESTED_GNOMEREGAN);
           case 33743: // Ironforge
               return !player->HasAura(SPELL_BESTED_IRONFORGE);
           case 33744: // Orgrimmar
               return !player->HasAura(SPELL_BESTED_ORGRIMMAR);
           case 33745: // Sen'jin
               return !player->HasAura(SPELL_BESTED_SENJIN);
           case 33746: // Silvermoon
               return !player->HasAura(SPELL_BESTED_SILVERMOON);
           case 33747: // Stormwind
               return !player->HasAura(SPELL_BESTED_STORMWIND);
           case 33748: // Thunder Bluff
               return !player->HasAura(SPELL_BESTED_THUNDERBLUFF);
           case 33749: // Undercity
               return !player->HasAura(SPELL_BESTED_UNDERCITY);
       }
       return true;
   }

   void AddMeleeFightGossip(Player* player)
   {
       if (!player)
           return;

       if (player->HasAura(SPELL_AURA_TOURNAMENT_MOUNT) &&((player->GetQuestStatus(QuestTheGrandMelee[urand(0,9)])) == QUEST_STATUS_INCOMPLETE))
       {
           player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_MELEE_FIGHT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
       }
   }


   bool OnGossipHello(Player* player, Creature* creature)
   {
       switch(creature->GetEntry())
       {
           case 33559: // Darnassus
           case 33562: // Exodar
           case 33558: // Gnomeregan
           case 33564: // Ironforge
           case 33561: // Stormwind
           {
               if (player->GetTeamId() == TEAM_ALLIANCE)
                   AddMeleeFightGossip(player);
               break;
           }
           case 33306: // Orgrimmar
           case 33285: // Sen'jin
           case 33382: // Silvermoon
           case 33383: // Thunder Bluff
           case 33384: // Undercity
           {
               if (player->GetTeamId() == TEAM_HORDE)
                   AddMeleeFightGossip(player);
               break;
           }
           case 33738: // Darnassus
           case 33739: // Exodar
           case 33740: // Gnomeregan
           case 33743: // Ironforge
           case 33744: // Orgrimmar
           case 33745: // Sen'jin
           case 33746: // Silvermoon
           case 33747: // Stormwind
           case 33748: // Thunder Bluff
           case 33749: // Undercity
           {
               if (player->HasAura(SPELL_AURA_TOURNAMENT_MOUNT) && ((player->GetQuestStatus(QuestAmongTheChampions[urand(0,3)])) == QUEST_STATUS_INCOMPLETE))
               {
                   if (MakeDuel(player,creature->GetEntry()))
                       player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_MELEE_FIGHT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
               }
               break;
           }
       }

       player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
       return true;
   }

   bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
   {
       player->PlayerTalkClass->ClearMenus();
       player->CLOSE_GOSSIP_MENU();
       if (uiAction == GOSSIP_ACTION_INFO_DEF + 1)
       {
           creature->setFaction(FACTION_HOSTILE);
           creature->AI()->AttackStart(player->GetVehicleCreatureBase());
           creature->AddThreat(player, 0.0f);
           creature->SetInCombatWith(player);
           player->SetInCombatWith(creature);
           return true;
       }

       if (uiAction == GOSSIP_ACTION_INFO_DEF + 2)
       {
           creature->setFaction(FACTION_HOSTILE);
           creature->AI()->AttackStart(player->GetVehicleCreatureBase());
           creature->AddThreat(player, 0.0f);
           creature->SetInCombatWith(player);
           player->SetInCombatWith(creature);
           return true;
       }
       return true;
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
    new npc_valiant();
}
