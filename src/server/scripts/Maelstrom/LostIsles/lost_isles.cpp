/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2011 - 2012 ArkCORE <http://www.arkania.net/>
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
#include "ScriptedEscortAI.h"
#include "ScriptedGossip.h"
#include "SpellMgr.h"
#include "Player.h"
#include "GameObject.h"
#include "GridNotifiers.h"
#include "CellImpl.h"
#include "GridNotifiersImpl.h"
#include "Creature.h"
#include "Vehicle.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "Item.h"
#include "WorldSession.h"

#define SAY_D_A "Ecrouabouille, what are you doing sitting there? You do not recognize the one who is lying?"
#define SAY_D_B  "That's $ N! It is only thanks to $ he: she, if we still breath instead of being pieces of rind grids has Kezan."
#define SAY_D_C  "That's $ N! Sorry, doc, I thought $ ghe death:she death; !"
#define SAY_D_D  "Remains back, I'm $ ghe: she; revive! Hoping that this soggy defibrillator will not kill us all!"
#define SAY_D_E  "Caution! OFF!"
#define SAY_D_F "That's all I can do. C'' is a $ ghe: she; to react now. You hear me, $ N? Come on, wake up now! Do not go to the Light!"
#define SAY_D_G  "You made the right choice. We need you so much, $ N. Try not to get killed here. "
#define SAY_D_H  "There are other survivors that I must attend. I'll see you on the shore."

#define GIZMO 36600
#define SPELL_DEAD_STILL 69010

enum Texts
{
    SAY_GYRO = 0
};

class npc_Zapnozzle : public CreatureScript
{
public:
    npc_Zapnozzle() : CreatureScript("npc_Zapnozzle") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_ZapnozzleAI(creature);
    }

    bool OnQuestReward(Player* player, Creature* creature, const Quest *_Quest, uint32 ) override
    {
        if (_Quest->GetQuestId() == 14239)
            creature->AI()->DoAction(1);
        return true;
    }

    struct npc_ZapnozzleAI : public ScriptedAI
    {
        npc_ZapnozzleAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override
        {
            eventTalk = 0;
            eventTalk2 = 0;
            mui_talk = 2000;
            mui_talk2 = 2000;
            isEventInProgress = false;
            start = false;
        }

        void DoAction(const int32 param) override
        {
            if (param == 1)
                isEventInProgress = true;
        }

        void SpellHit(Unit* caster, const SpellInfo* spell) override
        {
        }

        void JustReachedHome() override
        {

        }

        void WaypointReached(uint32)
        {

        }


        void MovementInform(uint32 /*type*/, uint32 id) override
        {
            if (id == 1)
                me->DespawnOrUnsummon();
        }

        void UpdateAI(const uint32 diff) override
        {
            if (!isEventInProgress)
            {
                if (mui_talk <= diff)
                {
                    mui_talk = 6000;
                    if (!start)
                        player = me->SelectNearestPlayer(10);
                    if (!player)
                        return;
                    if (!start)
                    {
                        if (!player->HasAura(SPELL_DEAD_STILL))
                            return;
                        else
                            start = true;
                    }
                    switch (eventTalk)
                    {
                    case 0 :
                        me->Say(SAY_D_A, LANG_UNIVERSAL, player);
                        break;
                    case 1 :
                        me->Say(SAY_D_B, LANG_UNIVERSAL, player);
                        break;
                    case 2 :
                        if (Creature *c = me->FindNearestCreature(GIZMO, 10))
                            c->Say(SAY_D_C, LANG_UNIVERSAL, player);
                        break;
                    case 3 :
                        me->Say(SAY_D_D, LANG_UNIVERSAL, player);
                        me->CastSpell(player, 54732, true);
                        break;
                    default :
                        break;
                    }
                    eventTalk++;
                }
                else
                    mui_talk -= diff;
            }
            if (!isEventInProgress)
                return;
            if (mui_talk2 <= diff)
            {
                mui_talk2 = 6000;
                if (!start)
                    player = me->SelectNearestPlayer(10);
                if (!player)
                    return;
                switch(eventTalk2)
                {
                case 0 :
                    me->Say(SAY_D_E, LANG_UNIVERSAL, player);
                    me->CastSpell(player, 54732, true);
                    player->RemoveAurasDueToSpell(SPELL_DEAD_STILL);
                    player->SetPhaseMask(1, true);
                    break;
                case 1 :
                    me->Say(SAY_D_F, LANG_UNIVERSAL, player);
                    break;
                case 2 :
                    me->Say(SAY_D_G, LANG_UNIVERSAL, player);
                    break;
                case 3 :
                    me->CastSpell(player, 54732, true);
                    me->Say(SAY_D_H, LANG_UNIVERSAL, player);
                    mui_talk2 = 2000;
                    break;
                case 4 :
                    me->SetSpeed(MOVE_SWIM, 2);
                    me->GetMotionMaster()->MovePoint(1, 578.49f, 3132.37f, 0.26f);
                    break;
                default :
                    eventTalk2 = 0;
                    isEventInProgress = false;
                    eventTalk = 0;
                    start = false;
                    break;
                }
                eventTalk2++;
            }
            else
                mui_talk2 -= diff;
        }

    private :
        bool isEventInProgress, start;
        uint32 mui_talk, mui_talk2;
        unsigned int eventTalk, eventTalk2;
        Player *player;
    };
};

class npc_Mechumide : public CreatureScript
{
public:
    npc_Mechumide() : CreatureScript("npc_Mechumide") { }

    bool OnQuestAccept(Player* player, Creature* creature, Quest const*_Quest) override
    {
        if (_Quest->GetQuestId() == 14021)
        {
            if (Creature *mineur = player->SummonCreature(35810, player->GetPositionX() + 2, player->GetPositionY(),  player->GetPositionZ() + 2,  player->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN))
                if (Creature *chariot = player->SummonCreature(35814, player->GetPositionX() - 2, player->GetPositionY(),  player->GetPositionZ() + 2,  player->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN))
                {
                    mineur->AddUnitState(UNIT_STATE_IGNORE_PATHFINDING);
                    chariot->AddUnitState(UNIT_STATE_IGNORE_PATHFINDING);
                    mineur->CastSpell(chariot, 68122, true);
                    chariot->GetMotionMaster()->MoveFollow(mineur, 1.0f, 1.0f);
                    mineur->Say("Ok, here we go. You cover me, okay?", LANG_UNIVERSAL, 0);
                    CAST_AI(npc_escortAI, (mineur->AI()))->Start(true, true, player->GetGUID(), _Quest);
                }
        }
        return true;
    }
};

class npc_mineur_gob : public CreatureScript
{
public:
    npc_mineur_gob() : CreatureScript("npc_mineur_gob") { }

    struct npc_mineur_gobAI : public npc_escortAI
    {
        npc_mineur_gobAI(Creature* creature) : npc_escortAI(creature) {}

        void AttackStart(Unit* /*who*/) override {}
        void EnterCombat(Unit* /*who*/) override {}
        void EnterEvadeMode(EvadeReason /*why*/) override {}

        void Reset() override {}

        void WaypointReached(uint32 i) override
        {
            SetRun(false);
            switch(i)
            {
            case 6:
                me->Say("We touch the jackpot with this place!", LANG_UNIVERSAL, 0);
                //me->LoadEquipment(2901, true);
                me->HandleEmoteCommand(467);
                break;
            case 9:
                me->Say("Wow, what is that all these cave paintings? Oh, I hear monkeys, the?", LANG_UNIVERSAL, 0);
                //me->LoadEquipment(2901, true);
                me->HandleEmoteCommand(467);
                break;
            case 13:
                me->Say("Move to the next.", LANG_UNIVERSAL, 0);
                break;
            case 12:
                //me->LoadEquipment(2901, true);
                me->HandleEmoteCommand(467);
                break;
            case 17:
                //me->LoadEquipment(2901, true);
                me->HandleEmoteCommand(467);
                break;
            case 18:
                if (Player *player = me->SelectNearestPlayer(20))
                {
                    me->Say("It will suffice for now. I can go it alone. Thank you for escorting me, $ N.", LANG_UNIVERSAL, player);
                    player->KilledMonsterCredit(35816);
                }
                else
                    me->Say("It will suffice for now. I can go it alone. Thank you for escorting me, $ N.", LANG_UNIVERSAL, 0);
                if (Creature *c = me->FindNearestCreature(35814, 10))
                    c->DespawnOrUnsummon();
                break;
            default:
                break;
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
        }

        void OnCharmed(bool /*apply*/) override
        {
        }

        void SetHoldState(bool bOnHold)
        {
            SetEscortPaused(bOnHold);
        }

        void UpdateEscortAI(const uint32 diff) override
        {
            if (m_ui_attack <= diff)
            {
                if (Creature *cb = me->FindNearestCreature(35812, 10, true))
                    SetHoldState(true);
                else
                    SetHoldState(false);
                m_ui_attack = 1000;
            }
            else m_ui_attack -= diff;

            DoMeleeAttackIfReady();
        }

    private :
        uint32 m_ui_attack;
        uint32 krennansay;
        bool AfterJump;

  };

  CreatureAI* GetAI(Creature* creature) const override
  {
    return new npc_mineur_gobAI(creature);
  }

};

#define FLASH_EFFECT 70649

class spell_68281 : public SpellScriptLoader
{
public:
    spell_68281() : SpellScriptLoader("spell_68281") { }

    class  spell_68281SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_68281SpellScript);

        bool Validate(SpellInfo const* spellEntry) override
        {
            st = false;
            st2 = false;
            return true;
        }

        bool Load() override
        {
            return true;
        }

        void HandleBeforeHit(SpellMissInfo /*missInfo*/)
        {
            if (st2)
                return;

            if (GetCastItem())
                if (Unit* caster = GetCastItem()->GetOwner())
                    caster->CastSpell(caster, FLASH_EFFECT, true);
            st2 = true;
        }

        void HandleAfterHit()
        {
            if (st)
                return;
            st = true;
        }

        void Unload() override
        {
            if (GetCastItem())
                if (Unit* caster = GetCastItem()->GetOwner())
                    caster->RemoveAura(FLASH_EFFECT);
        }

    private :
        bool st, st2;

        void Register() override
        {
            BeforeHit += BeforeSpellHitFn(spell_68281SpellScript::HandleBeforeHit);
            AfterHit += SpellHitFn(spell_68281SpellScript::HandleAfterHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_68281SpellScript();
    }
};

class npc_singe_bombe : public CreatureScript
{
public:
    npc_singe_bombe() : CreatureScript("npc_singe_bombe") { }

    struct npc_singe_bombeAI : public ScriptedAI
    {
        npc_singe_bombeAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override
        {
            mui_rocket = 45000;
            canCastRocket = true;
            isActive = true;
            isRandomMoving = false;
        }

        void DoAction(const int32 param) override
        {
            isActive = false;
            canCastRocket = false;
            me->CastSpell(me, 67919, true);
        }

        void SpellHit(Unit* caster, const SpellInfo* spell) override
        {
            if (spell->Id == 67917)
            {
                isActive = false;
                canCastRocket = false;
                if (me->IsNonMeleeSpellCast(true))
                    me->InterruptNonMeleeSpells(true);
                if (Creature *t = me->SummonCreature(me->GetEntry(), me->GetPositionX(), me->GetPositionY(),  me->GetPositionZ(),
                                                     me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN))
                {
                    t->AI()->DoAction(0);
                    t->DespawnOrUnsummon(3000);
                }
                me->DespawnOrUnsummon();
            }
        }

        void JustReachedHome() override
        {

        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (!who->ToPlayer())
                return ;
            if (!me->IsWithinDistInMap(who, 20.0f))
                return ;
            if (canCastRocket)
                me->CastSpell(me, 8858, true);
        }

        void UpdateAI(const uint32 diff) override
        {
            if (!isActive)
                return;
            if (mui_rocket <= diff)
            {
                canCastRocket = true;
                mui_rocket = urand(30000, 45000);
                if (!isRandomMoving)
                {
                    me->GetMotionMaster()->MoveRandom(10.0f);
                    isRandomMoving = true;
                }
            }
            else
                mui_rocket -= diff;
        }

    private:
        uint32 mui_rocket;
        bool canCastRocket;
        bool isActive;
        bool isRandomMoving;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_singe_bombeAI (creature);
    }
};

class spell_weed_whacker : public SpellScriptLoader
{
public:
    spell_weed_whacker() : SpellScriptLoader("spell_weed_whacker") { }

    class spell_weed_whacker_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_weed_whacker_SpellScript);

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (GetCastItem())
                if (Unit* caster = GetCastItem()->GetOwner())
                    if (caster->GetTypeId() == TYPEID_PLAYER)
                    {
                        Player *player = caster->ToPlayer();
                        if (player->HasAura(68212))
                            player->RemoveAura(68212);
                        else if (player->GetQuestStatus(14236) == QUEST_STATUS_INCOMPLETE)
                            player->CastSpell(player, 68212, true);
                    }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_weed_whacker_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_weed_whacker_SpellScript();
    }
};

class npc_lianne_gobelin : public CreatureScript
{
public:
    npc_lianne_gobelin() : CreatureScript("npc_lianne_gobelin") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_lianne_gobelinAI(creature);
    }

    struct npc_lianne_gobelinAI : public ScriptedAI
    {
        npc_lianne_gobelinAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        void Reset() override
        {
            if (me->GetVehicleKit())
                if (Creature *c = me->FindNearestCreature(36042, 10))
                    c->CastCustomSpell(VEHICLE_SPELL_RIDE_HARDCODED, SPELLVALUE_BASE_POINT0, 1, me, false);
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (Creature *c = me->FindNearestCreature(36042, 100))
                c->ToCreature()->AI()->Talk(irand(0, 7));
        }

        void UpdateAI(const uint32 diff) override
        {
        }
    };
};

class npc_killag_sangrecroc : public CreatureScript
{
public:
    npc_killag_sangrecroc() : CreatureScript("npc_killag_sangrecroc") { }

    bool OnQuestAccept(Player* player, Creature* creature, const Quest *_Quest) override
    {
        if (_Quest->GetQuestId() == 14240)
        {
            if (Creature *t = player->SummonCreature(36585, player->GetPositionX(), player->GetPositionY(),  player->GetPositionZ(),
                                                     player->GetOrientation(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300*IN_MILLISECONDS))
            {
                player->CastCustomSpell(VEHICLE_SPELL_RIDE_HARDCODED, SPELLVALUE_BASE_POINT0, 1, t, false);
                CAST_AI(npc_escortAI, (t->AI()))->Start(false, true, player->GetGUID(), _Quest);
            }
        }
        if (_Quest->GetQuestId() == 14238)
        {
            player->RemoveAura(68338);
            player->RemoveAura(69303);
            for (Unit::ControlList::iterator itr = player->m_Controlled.begin(); itr != player->m_Controlled.end(); ++itr)
                if ((*itr)->GetTypeId() == TYPEID_UNIT && (*itr)->GetEntry() == 36100)
                    (*itr)->ToCreature()->DespawnOrUnsummon();
        }
        return true;
    }

    bool OnQuestReward(Player* player, Creature* creature, const Quest *_Quest, uint32 ) override
    {
        if (_Quest->GetQuestId() == 14238)
        {
            player->RemoveAura(68338);
            player->RemoveAura(69303);
            for (Unit::ControlList::iterator itr = player->m_Controlled.begin(); itr != player->m_Controlled.end(); ++itr)
                if ((*itr)->GetTypeId() == TYPEID_UNIT && (*itr)->GetEntry() == 36100)
                    (*itr)->ToCreature()->DespawnOrUnsummon();
        }
        return true;
    }
};

class npc_pant_gob : public CreatureScript
{
public:
    npc_pant_gob() : CreatureScript("npc_pant_gob") { }

    struct npc_pant_gobAI : public npc_escortAI
    {
        npc_pant_gobAI(Creature* creature) : npc_escortAI(creature) {}

        void AttackStart(Unit* /*who*/) override {}
        void EnterCombat(Unit* /*who*/) override {}
        void EnterEvadeMode(EvadeReason /*why*/) override {}

        void Reset() override
        {
        }

        void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
                Start(false, true, who->GetGUID());
        }

        void WaypointReached(uint32 i) override
        {
            SetRun(true);
            switch(i)
            {
            case 17:
                me->DespawnOrUnsummon();
                break;
            default:
                break;
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
        }

        void OnCharmed(bool /*apply*/) override
        {
        }

        void UpdateAI(const uint32 diff) override
        {
            npc_escortAI::UpdateAI(diff);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_pant_gobAI (creature);
    }
};

class npc_gyrocoptere_quest_giver : public CreatureScript
{
public:
    npc_gyrocoptere_quest_giver() : CreatureScript("npc_gyrocoptere_quest_giver") { }

    bool OnQuestAccept(Player* player, Creature* creature, const Quest *_Quest) override
    {
        if (_Quest->GetQuestId() == 14242)
        {
            if (Creature *t = player->SummonCreature(39074, creature->GetPositionX(), creature->GetPositionY(),  creature->GetPositionZ(),
                                                     creature->GetOrientation(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300*IN_MILLISECONDS))
            {
                player->CastCustomSpell(VEHICLE_SPELL_RIDE_HARDCODED, SPELLVALUE_BASE_POINT0, 1, t, false);
                CAST_AI(npc_escortAI, (t->AI()))->Start(false, true, player->GetGUID(), _Quest);
                t->AI()->Talk(SAY_GYRO, player);
            }
        }
        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (player->GetQuestStatus(14242) != QUEST_STATUS_NONE)
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Would you take a gyrocopter?", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        else if (creature->IsQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());
        SendGossipMenuFor(player, player->GetGossipTextId(creature), creature->GetGUID());
        return true;
    }

};

class npc_girocoptere : public CreatureScript
{
public:
    npc_girocoptere() : CreatureScript("npc_girocoptere") { }

    struct npc_girocoptereAI : public npc_escortAI
    {
        npc_girocoptereAI(Creature* creature) : npc_escortAI(creature) {}

        void AttackStart(Unit* /*who*/) override {}
        void EnterCombat(Unit* /*who*/) override {}
        void EnterEvadeMode(EvadeReason /*why*/) override {}

        void Reset() override
        {
            _checkQuest = 1000;
            isBoarded = false;
        }

        void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
        {
            me->SetCanFly(true);
            me->SetSpeed(MOVE_FLIGHT, 3.0f);
        }

        void WaypointReached(uint32 i) override
        {
            me->SetCanFly(true);
            switch(i)
            {
            case 19:
                me->GetVehicleKit()->RemoveAllPassengers();
                me->DespawnOrUnsummon();
                break;
            default:
                break;
            }
        }

        void JustDied(Unit* /*killer*/) override
        {

        }

        void OnCharmed(bool /*apply*/) override
        {
        }

        void UpdateAI(const uint32 diff) override
        {
            npc_escortAI::UpdateAI(diff);
        }

        void UpdateEscortAI(const uint32 diff) override
        {
        }

    private :
        uint32 _checkQuest;
        bool isBoarded;

    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_girocoptereAI (creature);
    }
};

class npc_tornade_gob : public CreatureScript
{
public:
    npc_tornade_gob() : CreatureScript("npc_tornade_gob") { }

    struct npc_tornade_gobAI : public npc_escortAI
    {
        npc_tornade_gobAI(Creature* creature) : npc_escortAI(creature) {}

        void AttackStart(Unit* /*who*/) override {}
        void EnterCombat(Unit* /*who*/) override {}
        void EnterEvadeMode(EvadeReason /*why*/) override {}

        void Reset() override
        {
            _checkQuest = 1000;
            _checkDespawn = 1000;
            isBoarded = false;
            isBoarded2 = false;
        }

        void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
        {
            if (apply)
            {
                me->SetCanFly(true);
                me->SetSpeed(MOVE_FLIGHT, 3.0f);
                isBoarded = true;
                me->AddAura(68436, me);
                Start(false, true, who->GetGUID(), NULL, false, true);
            }
            else
                me->RemoveAura(68436);
        }

        void WaypointReached(uint32 i) override
        {
            me->SetCanFly(true);
        }

        void JustDied(Unit* /*killer*/) override
        {
        }

        void OnCharmed(bool /*apply*/) override
        {
        }

        void UpdateAI(const uint32 diff) override
        {
            npc_escortAI::UpdateAI(diff);
        }

        void UpdateEscortAI(const uint32 diff) override
        {
            if (isBoarded)
            {
                if (isBoarded2)
                {
                    if (_checkDespawn <= diff)
                    {
                        me->GetVehicleKit()->RemoveAllPassengers();
                        me->DespawnOrUnsummon();
                        _checkDespawn = 1000;
                    }
                    else
                        _checkDespawn -= diff;
                }
                else
                {
                    if (_checkQuest <= diff)
                    {
                        if (me->GetVehicleKit())
                            if (Unit *u = me->GetVehicleKit()->GetPassenger(0))
                                if (u->GetTypeId() == TYPEID_PLAYER)
                                {
                                    Player *player = u->ToPlayer();
                                    if (player->GetQuestStatus(14243) == QUEST_STATUS_COMPLETE)
                                    {
                                        isBoarded2 = true;
                                        _checkDespawn = 70000;
                                        SetEscortPaused(true);
                                        me->GetMotionMaster()->MovePoint(1, 862.0f, 2778.87f, 114.0f);
                                    }
                                }
                        _checkQuest = 1000;
                    }
                    else
                        _checkQuest -= diff;
                }
            }
        }

    private :
        uint32 _checkQuest;
        uint32 _checkDespawn;
        bool isBoarded;
        bool isBoarded2;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_tornade_gobAI (creature);
    }
};

class gob_fronde_gobelin : public GameObjectScript
{
public:
    gob_fronde_gobelin() : GameObjectScript("gob_fronde_gobelin") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        if (player->GetQuestStatus(14244) != QUEST_STATUS_NONE)
        {
            if (Creature *t = player->SummonCreature(36514, go->GetPositionX(), go->GetPositionY(),  go->GetPositionZ() + 7,  go->GetOrientation(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300*IN_MILLISECONDS))
                player->CastCustomSpell(VEHICLE_SPELL_RIDE_HARDCODED, SPELLVALUE_BASE_POINT0, 1, t, false);
            return true;
        }
        return true;
    }
};


class npc_fusee_gob : public CreatureScript
{
public:
    npc_fusee_gob() : CreatureScript("npc_fusee_gob") { }

    struct npc_fusee_gobAI : public npc_escortAI
    {
        npc_fusee_gobAI(Creature* creature) : npc_escortAI(creature) {}

        void AttackStart(Unit* /*who*/) override {}
        void EnterCombat(Unit* /*who*/) override {}
        void EnterEvadeMode(EvadeReason /*why*/) override {}

        void Reset() override
        {
            me->SetCanFly(true);
        }

        void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
        {
            if (apply)
                Start(false, true, who->GetGUID());
            me->SetCanFly(true);
            me->SetSpeed(MOVE_FLIGHT, 5.0f);
        }

        void WaypointReached(uint32 i) override
        {
            if (i == 3)
            {
                me->CastSpell(me, 66127, true);
                me->GetVehicleKit()->RemoveAllPassengers();
                me->DespawnOrUnsummon();
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
        }

        void OnCharmed(bool /*apply*/) override
        {
        }

        void UpdateAI(const uint32 diff) override
        {
            npc_escortAI::UpdateAI(diff);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_fusee_gobAI (creature);
    }
};


class gob_dyn_gobelin : public GameObjectScript
{
public:
    gob_dyn_gobelin() : GameObjectScript("gob_dyn_gobelin") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        if (player->GetQuestStatus(14245) != QUEST_STATUS_NONE)
        {
            player->CastSpell(player, 68935, true);
           if (Creature *t = player->SummonCreature(9100000, go->GetPositionX(), go->GetPositionY(),  go->GetPositionZ() + 2,  go->GetOrientation(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30*IN_MILLISECONDS))
            {
                t->SetPhaseMask(4, true);
                t->CastSpell(t, 71093, true);
                t->CastSpell(t, 71095, true);
                t->CastSpell(t, 71096, true);
                t->CastSpell(t, 71097, true);
            }
            return true;
        }
        return true;
    }
};

class npc_phaseswift : public CreatureScript
{
public:
    npc_phaseswift() : CreatureScript("npc_phaseswift") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_phaseswiftAI(creature);
    }

    struct npc_phaseswiftAI : public ScriptedAI
    {
        npc_phaseswiftAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override
        {
            mui_talk = 5000;
            cnt = 6;
        }

        void DoAction(const int32 param) override
        {
        }

        void SpellHit(Unit* caster, const SpellInfo* spell) override
        {
        }

        void JustReachedHome() override
        {

        }

        void WaypointReached(uint32)
        {

        }


        void MovementInform(uint32 /*type*/, uint32 id) override
        {
        }

        void UpdateAI(const uint32 diff) override
        {
            if (mui_talk <= diff)
            {
                if (Unit *p = me->ToTempSummon()->GetSummoner())
                    if (Player* player = p->ToPlayer())
                    {
                        std::set<uint32> terrainswap;
                        std::set<uint32> phaseId;
                        std::set<uint32> worldMapAreaSwap;
                        terrainswap.insert(661);
                        phaseId.insert(180);
                        player->CastSpell(p->ToPlayer(), 68750, true);
                        player->KilledMonsterCredit(38024);
                        player->GetSession()->SendSetPhaseShift(phaseId, terrainswap, worldMapAreaSwap);
                    }
                me->DespawnOrUnsummon();
                mui_talk = 6000;
            }
            else
                mui_talk -= diff;
        }

    private :
        uint32 mui_talk;
        int cnt;
    };
};

class npc_poule : public CreatureScript
{
public:
    npc_poule() : CreatureScript("npc_poule") { }

    struct npc_pouleAI : public ScriptedAI
    {
        npc_pouleAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override
        {
            me->GetMotionMaster()->MoveRandom(10.0f);
        }

        void DoAction(const int32 param) override
        {
            me->CastSpell(me, 67919, true);
        }

        void SpellHit(Unit* caster, const SpellInfo* spell) override
        {
            if (spell->Id == 67917)
            {
                if (me->IsNonMeleeSpellCast(true))
                    me->InterruptNonMeleeSpells(true);
                if (Creature *t = me->SummonCreature(me->GetEntry(), me->GetPositionX(), me->GetPositionY(),  me->GetPositionZ(),
                                                     me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN))
                {
                    t->AI()->DoAction(0);
                    t->DespawnOrUnsummon(3000);
                }
                me->DespawnOrUnsummon();
            }
        }

        void UpdateAI(const uint32 diff) override
        {
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_pouleAI (creature);
    }
};

#define GO_PIEGE 201972

class spell_egg_gob : public SpellScriptLoader
{
public:
    spell_egg_gob() : SpellScriptLoader("spell_egg_gob") { }

    class spell_egg_gobSpellScript : public SpellScript
    {
        PrepareSpellScript(spell_egg_gobSpellScript);

        bool Validate(SpellInfo const* spellEntry) override
        {
            return true;
        }


        bool Load() override
        {
            if (Unit* caster = GetCastItem()->GetOwner())
            {
                if (GameObject* go = caster->FindNearestGameObject(GO_PIEGE, 5))
                {
                    if (Creature *c = go->FindNearestCreature(38187, 10))
                        c->AI()->DoAction(1);
                }
            }
            return true;
        }


        void HandleActivateGameobject(SpellEffIndex effIndex)
        {

        }


        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_egg_gobSpellScript::HandleActivateGameobject,EFFECT_0,SPELL_EFFECT_ACTIVATE_OBJECT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_egg_gobSpellScript();
    }
};

class npc_raptore_gob : public CreatureScript
{
public:
    npc_raptore_gob() : CreatureScript("npc_raptore_gob") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_raptore_gobAI(creature);
    }

    struct npc_raptore_gobAI : public ScriptedAI
    {
        npc_raptore_gobAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override
        {
            start = true;
            me->GetMotionMaster()->MoveRandom(20);
        }

        void MovementInform(uint32 /*type*/, uint32 id) override
        {
            if (id == 42 && !start)
            {
                if (Player *player = me->SelectNearestPlayer(10))
                    player->SummonGameObject(201974, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0, QuaternionData(), 10*IN_MILLISECONDS);
                me->Kill(me);
            }
        }

        void DoAction(const int32 param) override
        {
            if (param == 1)
            {
                if (GameObject* go = me->FindNearestGameObject(GO_PIEGE, 25))
                {
                    start = false;
                    me->CastSpell(me, 66726, true);
                    me->GetMotionMaster()->MovePoint(42, go->GetPositionX(), go->GetPositionY(), go->GetPositionZ());
                }
            }
        }

        void UpdateAI(const uint32 diff) override
        {
            DoMeleeAttackIfReady();
        }

    private :
        bool start;
    };
};

class SparkSearcher
{
public:
    SparkSearcher(Creature const* source, float range) : _source(source), _range(range) {}

    bool operator()(Unit* unit)
    {
        if (!unit->IsAlive())
            return false;

        switch (unit->GetEntry())
        {
            case 38318:
                break;
            default:
                return false;
        }

        if (!unit->IsWithinDist(_source, _range, false))
            return false;

        return true;
    }

private:
    Creature const* _source;
    float _range;
};

class gob_spark_gobelin : public GameObjectScript
{
public:
    gob_spark_gobelin() : GameObjectScript("gob_spark_gobelin") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        if (player->GetQuestStatus(24817) == QUEST_STATUS_INCOMPLETE)
        {
            if (Creature* t = player->SummonCreature(38318, go->GetPositionX(), go->GetPositionY(),  go->GetPositionZ() + 2,  go->GetOrientation(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30*IN_MILLISECONDS))
            {
                std::list<Unit*> temp;
                SparkSearcher check(t, 100.0f);
                Trinity::UnitListSearcher<SparkSearcher> searcher(t, temp, check);
                Cell::VisitAllObjects(t, searcher, 25.0f);
                for (std::list<Unit*>::iterator itr = temp.begin(); itr != temp.end(); ++itr)
                    if ((*itr)->ToTempSummon())
                        if ((*itr)->ToTempSummon()->GetSummoner())
                            if ((*itr)->ToTempSummon()->GetSummoner()->GetTypeId() == TYPEID_PLAYER)
                                if ((*itr)->ToTempSummon()->GetSummoner()->GetGUID() == player->GetGUID() && (*itr)->GetGUID() != t->GetGUID())
                                    (*itr)->ToTempSummon()->DespawnOrUnsummon();
                player->EnterVehicle(t);
            }
            return true;
        }
        return true;
    }
};

class npc_young_naga_gob : public CreatureScript
{
public:
    npc_young_naga_gob() : CreatureScript("npc_young_naga_gob") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_young_naga_gobAI(creature);
    }

    struct npc_young_naga_gobAI : public ScriptedAI
    {
        npc_young_naga_gobAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override
        {
            ui_findPlayer = 1000;
            me->GetMotionMaster()->MoveRandom(5);
        }

        void UpdateAI(const uint32 diff) override
        {
            if (ui_findPlayer <= diff)
            {
                if (Player *player = me->SelectNearestPlayer(10))
                {
                    if (player->HasAura(71914) && player->GetQuestStatus(24864) == QUEST_STATUS_INCOMPLETE)
                    {
                        if (Creature *naga = player->SummonCreature(44589, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 40*IN_MILLISECONDS))
                        {
                            naga->CastSpell(naga, 71917, true);
                            naga->GetMotionMaster()->MoveFollow(player, urand (urand(urand(1, 2), urand(3, 4)), urand(5, 6)),  urand(urand(urand(1, 2), urand(3, 4)), urand(5, 6)));
                            player->KilledMonsterCredit(38413);
                        }
                        me->DespawnOrUnsummon();
                    }
                }
                ui_findPlayer = 1000;
            }
            else
                ui_findPlayer -= diff;

            DoMeleeAttackIfReady();
        }

    private :
        uint32 ui_findPlayer;

    };
};

#define SPELL_CRACK_INVOK 72058

// (Chef des nagas)
#define NAGA_SAY_A "WHO OSE?"
#define NAGA_SAY_B "Small goblins? I remember the creation of your race."
#define NAGA_SAY_C "Your threats do not impress me, nor the naga. Get ready to disappear from this reality."
#define NAGA_SAY_D  "Now, young $ N, you will die!"
//                    (Crack)
//-Quand on rend la quete d'avant
#define QUEST_RENDER_CRACK "I want to let these little demons, $ N. Nagas will never attack until we have grandchildren."

//-Quand on commence la quete
#define QUEST_RESET_CRACK "You are $ gpret, ready to force their leader to get $ gmy friend: my friend; ?"

//Quand on se rend syur place
#define CRACK_PROVOC "Come on, Chief naga, come out of your hiding and surrendered for $ N and Bilgewater Cartel!"
#define CRACK_EVADE "Hula treasure, it smells bad. I am size!"

#define NPC_CRACK 39198

class YoungNagaSearcher
{
public:
    YoungNagaSearcher(Creature const* source, float range) : _source(source), _range(range) {}

    bool operator()(Creature* creature)
    {
        if (!creature->IsAlive())
            return false;

        switch (creature->GetEntry())
        {
            case 44580:
                break;
            case 44579:
                break;
            case 44578:
                break;
            case 38412:
                break;
            default:
                return false;
        }

        if (!creature->IsWithinDist(_source, _range, false))
            return false;

        return true;
    }

private:
    Creature const* _source;
    float _range;
};

class npc_megs_isle_gob : public CreatureScript
{
public:
    npc_megs_isle_gob() : CreatureScript("npc_megs_isle_gob") { }

    bool OnQuestAccept(Player* player, Creature* creature, const Quest *_Quest) override
    {
        if (_Quest->GetQuestId() == 24868)
            player->SummonCreature(NPC_CRACK, player->GetPositionX(), player->GetPositionY(),  player->GetPositionZ(),  player->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
        else if (_Quest->GetQuestId() == 24897)
            player->CastSpell(player, 68481, true);
        return true;
    }

    bool OnQuestReward(Player* player, Creature* creature, const Quest *_Quest, uint32 ) override
    {
        if (_Quest->GetQuestId() == 24864)
        {
            std::list<Creature*> temp;
            YoungNagaSearcher check(creature, 900.0f);
            Trinity::CreatureListSearcher<YoungNagaSearcher> searcher(creature, temp, check);
            Cell::VisitAllObjects(creature, searcher, 900.0f);
            for (std::list<Creature*>::iterator itr = temp.begin(); itr != temp.end(); ++itr)
                if ((*itr)->ToTempSummon())
                    if ((*itr)->ToTempSummon()->GetSummoner())
                        if ((*itr)->ToTempSummon()->GetSummoner()->GetTypeId() == TYPEID_PLAYER)
                            if ((*itr)->ToTempSummon()->GetSummoner()->GetGUID() == player->GetGUID())
                                (*itr)->DespawnOrUnsummon();
        }
        return true;
    }
};


class npc_crack_isle_gob : public CreatureScript
{
public:
  npc_crack_isle_gob() : CreatureScript("npc_crack_isle_gob") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_crack_isle_gobAI(creature);
    }

    struct npc_crack_isle_gobAI : public ScriptedAI
    {
        npc_crack_isle_gobAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override
        {
            playerGUID = ObjectGuid::Empty;
            if (Unit *p = me->ToTempSummon()->GetSummoner())
                if (p->GetTypeId() == TYPEID_PLAYER)
                    playerGUID = p->GetGUID();
            if (playerGUID.IsEmpty())
            {
                me->DespawnOrUnsummon();
                return;
            }
            if (Player *player = ObjectAccessor::GetPlayer(*me, playerGUID))
            {
                me->GetMotionMaster()->MoveFollow(player, 1.0f, 1.0f);
                me->Say(QUEST_RESET_CRACK, LANG_UNIVERSAL, player);
            }
            else
                me->DespawnOrUnsummon();
            ui_findPlayer = 1000;
            start = false;
            event = false;
            combats = false;
            mui_event = 2000;
            event_p = 0;
        }

        void UpdateAI(const uint32 diff) override
        {
            if (!start)
            {
                if (ui_findPlayer <= diff)
                {
                    if (Creature *zone = me->FindNearestCreature(38450, 3))
                    {
                        if (Player* player =  ObjectAccessor::GetPlayer(*me, playerGUID))
                        {
                            me->Say(CRACK_PROVOC, LANG_UNIVERSAL, player);
                            naga = player->SummonCreature(38448, zone->GetPositionX(), zone->GetPositionY(), zone->GetPositionZ() + 2, zone->GetOrientation(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 60 * IN_MILLISECONDS);
                            if (naga)
                                naga->setFaction(35);
                        }
                        zone->DespawnOrUnsummon();
                        start = true;
                        event = true;
                    }
                    ui_findPlayer = 1000;
                }
                else
                    ui_findPlayer -= diff;
            }
            else if (event)
            {
                if (mui_event <= diff)
                {
                    mui_event  = 4000;
                    switch (event_p)
                    {
                    case 0 :
                        if (Player *player =  ObjectAccessor::GetPlayer(*me, playerGUID))
                            naga->Yell(NAGA_SAY_A, LANG_UNIVERSAL, player);
                        break;
                    case 1 :
                        if (Player *player =  ObjectAccessor::GetPlayer(*me, playerGUID))
                            naga->Yell(NAGA_SAY_B, LANG_UNIVERSAL, player);
                        break;
                    case 2 :
                        if (Player *player =  ObjectAccessor::GetPlayer(*me, playerGUID))
                            naga->Yell(NAGA_SAY_C, LANG_UNIVERSAL, player);
                        break;
                    case 3 :
                        if (Player *player =  ObjectAccessor::GetPlayer(*me, playerGUID))
                            naga->Yell(NAGA_SAY_D, LANG_UNIVERSAL, player);
                        break;
                    default :
                        if (Player *player =  ObjectAccessor::GetPlayer(*me, playerGUID))
                            me->Yell(CRACK_EVADE, LANG_UNIVERSAL, player);
                        mui_event = 2000;
                        event = false;
                        combats = true;
                        break;
                    }
                    event_p++;
                }
                else mui_event -= diff;
            }
            else if (combats)
            {
                if (mui_event <= diff)
                {
                    combats = false;
                    naga->setFaction(14);
                    mui_event  = 4000;
                    me->GetMotionMaster()->MovePoint(1, me->GetHomePosition());
                }
                else
                    mui_event -= diff;
            }
            else
            {
                if (mui_event <= diff)
                    me->DespawnOrUnsummon();
                else
                    mui_event -= diff;
            }
        }

    private :
        uint32 ui_findPlayer;
        Creature *naga;
        ObjectGuid playerGUID;
        bool start, event, combats;
        uint32 mui_event;
        int event_p;
    };
};


class npc_canon_gob : public CreatureScript
{
public:
    npc_canon_gob() : CreatureScript("npc_canon_gob") { }

    struct npc_canon_gobAI : public npc_escortAI
    {
        npc_canon_gobAI(Creature* creature) : npc_escortAI(creature) {}

        void AttackStart(Unit* /*who*/) override {}
        void EnterCombat(Unit* /*who*/) override {}
        void EnterEvadeMode(EvadeReason /*why*/) override {}

        void Reset() override
        {
            _checkQuest = 1000;
            isBoarded = false;
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            damage = 0;
        }
        void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
        {
        }

        void WaypointReached(uint32 i) override
        {
        }

        void JustDied(Unit* /*killer*/) override
        {
        }

        void OnCharmed(bool /*apply*/) override
        {
        }

        void UpdateAI(const uint32 diff) override
        {
            npc_escortAI::UpdateAI(diff);
        }

        void UpdateEscortAI(const uint32 diff) override
        {
            if (_checkQuest <= diff)
            {
                if (!isBoarded)
                {
                    if (Creature *player = me->FindNearestCreature(38745,1))
                    {
                        player->EnterVehicle(me);
                        isBoarded = true;
                    }
                    else if (Creature *player = me->FindNearestCreature(38409,1))
                    {
                        player->EnterVehicle(me);
                        isBoarded = true;
                    }
                }
                else
                {
                    if (Creature *oomlot = me->FindNearestCreature(38531,80))
                    {
                        me->CastSpell(oomlot, 72206, true);
                        isBoarded = true;
                    }
                }
                _checkQuest = urand(7000, 13333);
            }
            else _checkQuest -= diff;
        }

    private :
        uint32 _checkQuest;
        bool isBoarded;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_canon_gobAI (creature);
    }
};

class npc_oom_isle_gob : public CreatureScript
{
public:
    npc_oom_isle_gob() : CreatureScript("npc_oom_isle_gob") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_oom_isle_gobAI(creature);
    }

    struct npc_oom_isle_gobAI : public ScriptedAI
    {
        npc_oom_isle_gobAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override
        {
        }

        void SpellHit(Unit* caster, const SpellInfo* spell) override
        {
            if (spell->Id == 72207)
                caster->Kill(me);
        }

        void UpdateAI(const uint32 diff) override
        {
            if (!UpdateVictim())
                return ;
            DoMeleeAttackIfReady();
        }

    };
};

class npc_ceint : public CreatureScript
{
public:
    npc_ceint() : CreatureScript("npc_ceint") { }

    bool OnQuestReward(Player* player, Creature* creature, const Quest *_Quest, uint32 ) override
    {
        if (_Quest->GetQuestId() == 24942)
        {
            if (Creature *c = player->FindNearestCreature(38802, 10))
            {
                player->RemoveAura(72889);
                player->RemoveAura(72885);
                c->Kill(c);
            }
        }
        return true;
    }
};

class spell_boot_gob : public SpellScriptLoader
{
public:
    spell_boot_gob() : SpellScriptLoader("spell_boot_gob") { }


    class spell_boot_gobSpellScript : public SpellScript
    {
        PrepareSpellScript(spell_boot_gobSpellScript);

        bool Validate(SpellInfo const* spellEntry) override
        {
            st = false;
            return true;
        }


        bool Load() override
        {
            return true;
        }

        void HandleOnHit()
        {
            if (Unit* caster = GetCastItem()->GetOwner())
                if (caster->GetTypeId() == TYPEID_PLAYER)
                    caster->ToPlayer()->GetMotionMaster()->MoveJump(1480.31f, 1269.97f, 110.0f, 50.0f, 50.0f, 300.0f);
        }

    private :
        bool st;

        void Register() override
        {
            OnHit += SpellHitFn(spell_boot_gobSpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_boot_gobSpellScript();
    }
};

class npc_izzy_airplane : public CreatureScript
{
public:
    npc_izzy_airplane() : CreatureScript("npc_izzy_airplane") { }

    bool OnQuestAccept(Player* player, Creature* creature, const Quest *_Quest) override
    {
        if (_Quest->GetQuestId() == 25023)
        {
            if (Creature *airplane = player->SummonCreature(38929, creature->GetPositionX(), creature->GetPositionY(),  creature->GetPositionZ(),  creature->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN))
            {
                player->CastCustomSpell(VEHICLE_SPELL_RIDE_HARDCODED, SPELLVALUE_BASE_POINT0, 2, airplane, false);
                if (Creature *t = player->SummonCreature(38869, creature->GetPositionX(),  creature->GetPositionY(),  creature->GetPositionZ(), 0.0f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 750000))
                    t->CastCustomSpell(VEHICLE_SPELL_RIDE_HARDCODED, SPELLVALUE_BASE_POINT0, 1, airplane, false);
            }
        }
        return true;
    }
};

class npc_avion_gob : public CreatureScript
{
public:
    npc_avion_gob() : CreatureScript("npc_avion_gob") { }

    struct npc_avion_gobAI : public npc_escortAI
    {
        npc_avion_gobAI(Creature* creature) : npc_escortAI(creature) {}

        void AttackStart(Unit* /*who*/) override {}
        void EnterCombat(Unit* /*who*/) override {}
        void EnterEvadeMode(EvadeReason /*why*/) override {}

        void Reset() override
        {
            me->SetCanFly(true);
            me->SetSpeed(MOVE_FLIGHT, 6.0f);
        }

        void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
                if (apply)
                    Start(false, true, who->GetGUID());
        }

        void WaypointReached(uint32 i) override
        {
            me->SetCanFly(true);
            me->SetSpeed(MOVE_FLIGHT, 6.0f);
            Creature *chipie = me->FindNearestCreature(38869, 5, true);
            if (!chipie)
                return;
            switch(i)
            {
                case 1:
                    if (Player *player = me->SelectNearestPlayer(10))
                        chipie->Say("Hang on $ N! We need makes a clearance here, NOW!", LANG_UNIVERSAL, player);
                    break;
                case 4 :
                    chipie->Say("OH MY GOD! BEHIND YOU!", LANG_UNIVERSAL, 0);
                    break;
                case 8:
                    chipie->Say("WE BURN !!", LANG_UNIVERSAL, 0);
                    break;
                case 17 :
                    Creature *chipie;
                    Player *player;
                    if (Unit *unit = me->GetVehicleKit()->GetPassenger(0))
                        chipie = unit->ToCreature();
                    if (Unit *unit = me->GetVehicleKit()->GetPassenger(1))
                        player = unit->ToPlayer();
                    if (chipie && player)
                    {
                        me->GetVehicleKit()->RemoveAllPassengers();
                        player->CastCustomSpell(VEHICLE_SPELL_RIDE_HARDCODED, SPELLVALUE_BASE_POINT0, 3, me, false);
                        chipie->CastCustomSpell(VEHICLE_SPELL_RIDE_HARDCODED, SPELLVALUE_BASE_POINT0, 1, me, false);
                        me->RemoveAura(73149);
                    }
                    chipie->Say("Climb in the back. We're going. I know where are our old friends the orcs", LANG_UNIVERSAL, 0);
                    break;
                case 26 :
                    me->GetVehicleKit()->RemoveAllPassengers();
                    if (Creature *chip = me->FindNearestCreature(38869, 5, true))
                     chip->DespawnOrUnsummon();
                    me->DespawnOrUnsummon();
                    break;
                default:
                    break;
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
        }

        void OnCharmed(bool /*apply*/) override
        {
        }

        void UpdateAI(const uint32 diff) override
        {
            npc_escortAI::UpdateAI(diff);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_avion_gobAI (creature);
    }
};


class npc_tremblement_volcano : public CreatureScript
{
public:
    npc_tremblement_volcano() : CreatureScript("npc_tremblement_volcano") { }

    struct npc_tremblement_volcanoAI : public ScriptedAI
    {
        npc_tremblement_volcanoAI(Creature* creature) : ScriptedAI(creature) {}

        void AttackStart(Unit* /*who*/) override {}
        void EnterCombat(Unit* /*who*/) override {}
        void EnterEvadeMode(EvadeReason /*why*/) override {}

        void Reset() override
        {
            mui_soufle = 2000;
        }

        void JustDied(Unit* killer) override
        {
        }

        void UpdateAI(const uint32 diff) override
        {
            if (mui_soufle <= diff)
            {
                me->CastSpell(me, 69235, true);
                mui_soufle = 3000;
            }
            else
                mui_soufle -= diff;
        }

    private :
        uint32 mui_soufle;

    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_tremblement_volcanoAI (creature);
    }
};

class npc_meteor2_gob : public CreatureScript
{
public:
    npc_meteor2_gob() : CreatureScript("npc_meteor2_gob") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_meteor2_gobAI(creature);
    }

    struct npc_meteor2_gobAI : public ScriptedAI
    {
        npc_meteor2_gobAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override
        {
            _a = urand(15000, 20200);
            _b = 600000;
            _c = 600000;
        }

        void JustReachedHome() override
        {

        }

        void UpdateAI(const uint32 diff) override
        {
            if (_a <= diff)
            {
                me->CastSpell(me, 93668, true);
                _a = urand(15000, 20200);
                _b = 800;
            }
            else _a -= diff;
            if (_b <= diff)
            {
                me->CastSpell(me, 87701, true);
                _b = 600000;
                _c = 500;
            }
            else _b -= diff;
            if (_c <= diff)
            {
                me->CastSpell(me, 69235, true);
                _c = 600000;
            }
            else _c -= diff;
        }

    private :
        uint32 _a, _b, _c;
    };
};

class npc_explosion_volcano : public CreatureScript
{
public:
    npc_explosion_volcano() : CreatureScript("npc_explosion_volcano") { }

    struct npc_explosion_volcanoAI : public ScriptedAI
    {
        npc_explosion_volcanoAI(Creature* creature) : ScriptedAI(creature) {}

        void AttackStart(Unit* /*who*/) override {}
        void EnterCombat(Unit* /*who*/) override {}
        void EnterEvadeMode(EvadeReason /*why*/) override {}

        void Reset() override
        {
            mui_soufle = urand(1100, 2000);
        }

        void JustDied(Unit* killer) override
        {
        }

        void UpdateAI(const uint32 diff) override
        {
            if (mui_soufle <= diff)
            {
                me->CastSpell(me, 73193, true);
                mui_soufle = urand(4000, 5200);
            }
            else
                mui_soufle -= diff;
        }

    private :
        uint32 mui_soufle;

    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_explosion_volcanoAI (creature);
    }
};



class npc_killag_2 : public CreatureScript
{
public:
    npc_killag_2() : CreatureScript("npc_killag_2") { }

    bool OnQuestAccept(Player* player, Creature* creature, const Quest *_Quest) override
    {
        if (_Quest->GetQuestId() == 25100)
        {
            if (Creature *pant = player->SummonCreature(39152, player->GetPositionX(), player->GetPositionY(),
                                                        player->GetPositionZ(),  player->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN))
                player->CastCustomSpell(VEHICLE_SPELL_RIDE_HARDCODED, SPELLVALUE_BASE_POINT0, 1, pant, false);
        }
        return true;
    }
};

class npc_Chariot : public CreatureScript
{
public:
    npc_Chariot() : CreatureScript("npc_Chariot") { }

    bool OnQuestAccept(Player* player, Creature* creature, const Quest *_Quest) override
    {
        if (_Quest->GetQuestId() == 25184)
        {
            if (Creature *chariot = player->SummonCreature(39329, creature->GetPositionX(), creature->GetPositionY(),  creature->GetPositionZ(),  creature->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN))
            {
                int cnt = 1;
                chariot->AddUnitState(UNIT_STATE_IGNORE_PATHFINDING);
                player->CastCustomSpell(VEHICLE_SPELL_RIDE_HARDCODED, SPELLVALUE_BASE_POINT0, 1, chariot, false);
                for (Unit::ControlList::iterator itr = player->m_Controlled.begin(); itr != player->m_Controlled.end(); ++itr)
                    if ((*itr)->GetTypeId() == TYPEID_UNIT && ((*itr)->GetEntry() == 34957 || (*itr)->GetEntry() == 39199 || (*itr)->GetEntry() == 34959 || (*itr)->GetEntry() == 39205))
                    {
                        cnt++;
                        (*itr)->CastCustomSpell(VEHICLE_SPELL_RIDE_HARDCODED, SPELLVALUE_BASE_POINT0, cnt, chariot, false);
                    }
                CAST_AI(npc_escortAI, (chariot->AI()))->Start(false, true, player->GetGUID(), _Quest);
            }
        }
        return true;
    }
};

class npc_Chariot2 : public CreatureScript
{
public:
    npc_Chariot2() : CreatureScript("npc_Chariot2") { }

    struct npc_Chariot2AI : public npc_escortAI
    {
        npc_Chariot2AI(Creature* creature) : npc_escortAI(creature) {}

        uint32 krennansay;
        bool AfterJump;
        void AttackStart(Unit* /*who*/) override {}
        void EnterCombat(Unit* /*who*/) override {}
        void EnterEvadeMode(EvadeReason /*why*/) override {}

        void Reset() override
        {
        }

        void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
        {
            if (who->GetTypeId() == TYPEID_UNIT)
                if (!apply)
                    who->ToCreature()->DespawnOrUnsummon();
        }

        void WaypointReached(uint32 i) override
        {
            switch(i)
            {
            case 12:
                me->GetVehicleKit()->RemoveAllPassengers();
                if (Creature *t = me->SummonCreature(41505, me->GetPositionX(), me->GetPositionY(),  me->GetPositionZ(),  me->GetOrientation(), TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 10*IN_MILLISECONDS))
                {
                    t->CastSpell(t, 93569, true);
                    t->CastSpell(t, 71094, true);
                }
                me->DespawnOrUnsummon();
                if (Unit *player = me->ToTempSummon()->GetSummoner())
                    player->GetMotionMaster()->MoveJump(2354.36f, 1943.21f, 24.0f, 0.0f, 20.0f, 20.0f);
                break;
            default:
                break;
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
        }

        void OnCharmed(bool /*apply*/) override
        {
        }

        void UpdateAI(const uint32 diff) override
        {
            npc_escortAI::UpdateAI(diff);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_Chariot2AI (creature);
    }
};

class gob_red_but : public GameObjectScript
{
public:
    gob_red_but() : GameObjectScript("gob_red_but") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        if (player->GetQuestStatus(25207) == QUEST_STATUS_INCOMPLETE)
        {
            if (player->GetPhaseMask() == 32768)
                return false;
            player->CastSpell(player, 69077, true);
            player->AddAura(90418, player);
            player->KilledMonsterCredit(39393);
            if (Creature *t = player->SummonCreature(41505, 2477.0f, 2082.0f,  14.0f,  go->GetOrientation(), TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 10*IN_MILLISECONDS))
            {
                t->SetPhaseMask(32768, true);
                t->CastSpell(t, 93569, true);
                t->CastSpell(t, 71094, true);
            }
            if (Creature *t = player->SummonCreature(41505, 2499.28f, 2091.48f,  17.0f,  go->GetOrientation(), TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 10*IN_MILLISECONDS))
            {
                t->SetPhaseMask(32768, true);
                t->CastSpell(t, 93569, true);
                t->CastSpell(t, 71094, true);
            }
            if (Creature *t = player->SummonCreature(41505, 2450.424f, 2068.89f,  28.0f,  go->GetOrientation(), TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 10*IN_MILLISECONDS))
            {
                t->SetPhaseMask(32768, true);
                t->SetCanFly(true);
                t->CastSpell(t, 93569, true);
                t->CastSpell(t, 71094, true);
            }
            return true;
        }
        return true;
    }
};

class npc_grilly_2 : public CreatureScript
{
public:
    npc_grilly_2() : CreatureScript("npc_grilly_2") { }

    bool OnQuestAccept(Player* player, Creature* creature, const Quest *_Quest) override
    {
        if (_Quest->GetQuestId() == 25213)
        {
            if (Creature *pant = player->SummonCreature(47956, player->GetPositionX(), player->GetPositionY(),
                                                        player->GetPositionZ(),  player->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN))
                player->CastCustomSpell(VEHICLE_SPELL_RIDE_HARDCODED, SPELLVALUE_BASE_POINT0, 1, pant, false);
        }
        return true;
    }
};

class npc_Prince : public CreatureScript
{
public:
    npc_Prince() : CreatureScript("npc_Prince") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_PrinceAI(creature);
    }

    struct npc_PrinceAI : public ScriptedAI
    {
        npc_PrinceAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override
        {
            eventTalk = 0;
            eventTalk2 = 0;
            mui_talk = 2000;
            mui_talk2 = 2000;
            isEventInProgress = false;
            start = false;
            end = false;
            mui1 = 10000;
            mui2 = 30000;
            mui3 = 50000;
            mui4 = 40000;
            mui5 = 60000;
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (isEventInProgress)
                return;
            if (who->ToPlayer())
                return;
            if (!me->IsWithinDistInMap(who, 5.0f))
                return ;
            if (end)
                return;
            if (who->GetEntry() == 39592)
            {
                isEventInProgress = true;
                me->setFaction(14);
                //Talk(-1039585, me);
            }
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            if (end)
            {
                damage = 0;
                return;
            }
            if (damage >= me->GetHealth())
            {
                damage = 0;
                me->setFaction(35);
                //Talk(-1039588, me);
                end = true;
                if (Creature *c = me->FindNearestCreature(39592, 30))
                    c->DespawnOrUnsummon();
                if (Player *pl = me->SelectNearestPlayer(10))
                    pl->KilledMonsterCredit(39582);
            }
        }

        void UpdateAI(const uint32 diff) override
        {
            if (!isEventInProgress)
                return;
            if (end)
            {
                if (mui_talk <= diff)
                {
                    mui_talk = 10000;
                    switch (eventTalk)
                    {
                    case 0 :
                        //          Talk(-1039590, me);
                        break;
                    case 1 :
                        if (Creature *c = me->FindNearestCreature(39594, 30))
                        {
                            //              Talk(-1039591, c);
                        }
                        break;
                    case 2 :
                        //          Talk(-1039589, me);
                        break;
                    case 3 :
                        if (Creature *c = me->FindNearestCreature(39594, 30))
                        {
                            //              Talk(-1039592, c);
                        }
                        break;
                    case 4 :
                        if (Creature *c = me->FindNearestCreature(39594, 30))
                        {
                            //              Talk(-1039593, c);
                        }
                        break;
                    case 5 :
                        me->DespawnOrUnsummon();
                        if (Creature *c = me->FindNearestCreature(39594, 30))
                        {
                            c->DespawnOrUnsummon();
                        }
                        break;
                    default :
                        break;
                    }
                    eventTalk++;
                }
                else
                    mui_talk -= diff;
            }
            else
            {
                if (!me->GetVictim())
                    return;
                if (mui1 <= diff)
                {
                    switch (urand(0, 4))
                    {
                    case 0 :
                        me->CastSpell(me->GetVictim(), 74005, true);
                        //          Talk(-1039583, me);
                        break;
                    case 1 :
                        me->CastSpell(me->GetVictim(), 74000, true);
                        //          Talk(-1039584, me);
                        break;
                    case 2 :
                        me->CastSpell(me->GetVictim(), 74004, true);
                        //          Talk(-1039586, me);
                        break;
                    case 3 :
                        me->CastSpell(me->GetVictim(), 81000, true);
                        //          Talk(-1039582, me);
                        break;
                    case 4 :
                        me->CastSpell(me->GetVictim(), 74003, true);
                        break;
                    default :
                        me->CastSpell(me->GetVictim(), 74003, true);
                        break;
                    }
                    mui1 = 5000;
                }
                else
                    mui1 -= diff;
            }
            DoMeleeAttackIfReady();
        }

    private :
        bool isEventInProgress, start, end;
        uint32 mui_talk, mui_talk2, mui1, mui2, mui3, mui4, mui5;
        unsigned int eventTalk, eventTalk2;
        Player *player;
    };
};


class npc_boot : public CreatureScript
{
public:
  npc_boot() : CreatureScript("npc_boot") { }

  bool OnQuestAccept(Player* player, Creature* creature, const Quest *_Quest) override
  {
    if (_Quest->GetQuestId() == 25265)
    {
        player->AddAura(72971, player);
        player->CastSpell(player, 67789, true);
        player->AddAura(90418, player);
        player->GetMotionMaster()->MoveJump(2352.31f, 2483.97f, 13.0f, 15.0f, 20.0f, 150.0f);
    }

    if (_Quest->GetQuestId() == 25066)
    {
        if (Creature *t = player->SummonCreature(39074, player->GetPositionX(), player->GetPositionY(),  player->GetPositionZ(),
                                                 player->GetOrientation(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3*IN_MILLISECONDS))
        {
            player->CastCustomSpell(VEHICLE_SPELL_RIDE_HARDCODED, SPELLVALUE_BASE_POINT0, 1, t, false);
            t->SetCanFly(true);
            t->SetSpeed(MOVE_FLIGHT, 6.0f);
        }
    }

    if (_Quest->GetQuestId() == 25251)
    {
        if (Creature *t = player->SummonCreature(39592, player->GetPositionX(), player->GetPositionY(),  player->GetPositionZ(),
                                                 player->GetOrientation(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3*IN_MILLISECONDS))
            player->CastCustomSpell(VEHICLE_SPELL_RIDE_HARDCODED, SPELLVALUE_BASE_POINT0, 1, t, false);
    }

    return true;
  }
};

class BootSearcher
{
public:
    bool operator()(WorldObject* object)
    {
        if (!object)
            return true;
        Unit* unit = object->ToUnit();
        if (!unit || !unit->IsAlive() || unit->GetTypeId() == TYPEID_PLAYER)
            return true;

        if (unit->ToCreature())
        {
            switch (unit->ToCreature()->GetEntry())
            {
                case 38753:
                    return false;
                default:
                    break;
            }
        }
        return true;
    }
};

class spell_boot_damage : public SpellScriptLoader
{
public:
    spell_boot_damage() : SpellScriptLoader("spell_boot_damage") { }

    class spell_boot_damage_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_boot_damage_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            targets.remove_if(BootSearcher());
            if (GetCaster())
                if (!GetCaster()->HasAura(72887))
                {
                    GetCaster()->RemoveAura(72885);
                    targets.clear();
                }
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_boot_damage_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_boot_damage_SpellScript();
    }
};

void AddSC_lost_isle()
{
    new npc_Zapnozzle();
    new npc_singe_bombe();
    new npc_mineur_gob();
    new npc_Mechumide();
    new spell_68281();
    new spell_weed_whacker();
    new npc_lianne_gobelin();
    new npc_killag_sangrecroc();
    new npc_pant_gob();
    new npc_gyrocoptere_quest_giver();
    new npc_girocoptere();
    new npc_tornade_gob();
    new gob_fronde_gobelin();
    new npc_fusee_gob();
    new npc_phaseswift();
    new gob_dyn_gobelin();
    new npc_poule();
    new npc_raptore_gob();
    new gob_spark_gobelin();
    new npc_young_naga_gob();
    new npc_megs_isle_gob();
    new npc_crack_isle_gob();
    new npc_canon_gob();
    new spell_boot_damage();
    new spell_boot_gob();
    new npc_oom_isle_gob();
    new npc_ceint();
    new npc_izzy_airplane();
    new npc_avion_gob();
    new npc_meteor2_gob();
    new npc_tremblement_volcano();
    new npc_explosion_volcano();
    new npc_killag_2();
    new npc_Chariot();
    new npc_Chariot2();
    new gob_red_but();
    new npc_grilly_2();
    new npc_Prince();
    new npc_boot();
}
