/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
SDName: Ironforge
SD%Complete: 100
SDComment: Quest support: 3702, 25229
SDCategory: Ironforge
EndScriptData */

/* ContentData
npc_royal_historian_archesonus
npc_gnome_citizen
spell_motivate_a_tron
EndContentData */

#include "ScriptPCH.h"

/*######
## npc_royal_historian_archesonus
######*/

#define GOSSIP_ITEM_ROYAL   "I am ready to listen"
#define GOSSIP_ITEM_ROYAL_1 "That is tragic. How did this happen?"
#define GOSSIP_ITEM_ROYAL_2 "Interesting, continue please."
#define GOSSIP_ITEM_ROYAL_3 "Unbelievable! How dare they??"
#define GOSSIP_ITEM_ROYAL_4 "Of course I will help!"

class npc_royal_historian_archesonus : public CreatureScript
{
public:
    npc_royal_historian_archesonus() : CreatureScript("npc_royal_historian_archesonus") { }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        switch (uiAction)
        {
            case GOSSIP_ACTION_INFO_DEF:
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_ROYAL_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                pPlayer->SEND_GOSSIP_MENU(2236, pCreature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+1:
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_ROYAL_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                pPlayer->SEND_GOSSIP_MENU(2237, pCreature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+2:
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_ROYAL_3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
                pPlayer->SEND_GOSSIP_MENU(2238, pCreature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+3:
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_ROYAL_4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
                pPlayer->SEND_GOSSIP_MENU(2239, pCreature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+4:
                pPlayer->CLOSE_GOSSIP_MENU();
                pPlayer->AreaExploredOrEventHappens(3702);
                break;
        }
        return true;
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pCreature->isQuestGiver())
            pPlayer->PrepareQuestMenu(pCreature->GetGUID());

        if (pPlayer->GetQuestStatus(3702) == QUEST_STATUS_INCOMPLETE)
        {
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_ROYAL, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
            pPlayer->SEND_GOSSIP_MENU(2235, pCreature->GetGUID());
        }
        else
            pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());

        return true;
    }

};

/*######
## npc_gnome_citizen
## spell_motivate_a_tron
######*/

enum Spells
{
    SPELL_CITIZEN_AURA                  = 74034,
    SPELL_PETACT_AURA                   = 74071,
    SPELL_QUEST_CREDIT                  = 73960,

    SPELL_MOTIVATE_1                    = 73943,
    SPELL_MOTIVATE_2                    = 74080,

    SPELL_TURNIN                        = 75078,
    SPELL_AOE_TURNIN                    = 73955,
};

enum Creatures
{
    NPC_SPARKNOZZLE                     = 39675,

    NPC_CITIZEN_1                       = 39253,
    NPC_CITIZEN_2                       = 39623,

    NPC_MOTIVATED_CITIZEN_1             = 39466,
    NPC_MOTIVATED_CITIZEN_2             = 39624,
};

enum Points
{
    POINT_SPARKNOZZLE                   = 4026500,
};

enum Texts
{
    SAY_CITIZEN_START                   = 0,
    SAY_CITIZEN_END                     = 1,
};

class npc_gnome_citizen : public CreatureScript
{
    public:
        npc_gnome_citizen() : CreatureScript("npc_gnome_citizen") { }

        struct npc_gnome_citizenAI : public ScriptedAI
        {
            npc_gnome_citizenAI(Creature* creature) : ScriptedAI(creature)
            {
                Reset();
                Player* player = me->GetOwner()->ToPlayer();

                switch (urand(1, 4))
                {
                    case 1:
                        _mountModel = 6569;
                        break;
                    case 2:
                        _mountModel = 9473;
                        break;
                    case 3:
                        _mountModel = 9474;
                        break;
                    case 4:
                        _mountModel = 9475;
                        break;
                }
                if (player)
                    me->GetMotionMaster()->MoveFollow(player, 5.0f, float(rand_norm() + 1.0f) * M_PI / 3.0f * 4.0f);
            }

            void Reset()
            {
                _complete = false;
                me->AddAura(SPELL_CITIZEN_AURA, me);
                DoCast(me, SPELL_PETACT_AURA);
                me->SetReactState(REACT_PASSIVE);
                Talk(SAY_CITIZEN_START);
            }

            void MovementInform(uint32 type, uint32 id)
            {
                if (type != POINT_MOTION_TYPE)
                    return;
                if (id == POINT_SPARKNOZZLE)
                    me->DespawnOrUnsummon();
            }

            void SpellHit(Unit* caster, SpellEntry const* spell)
            {
                if (spell->Id == SPELL_AOE_TURNIN && caster->GetEntry() == NPC_SPARKNOZZLE && !_complete)
                {
                    _complete = true;    // Preventing from giving credit twice
                    DoCast(me, SPELL_TURNIN);
                    DoCast(me, SPELL_QUEST_CREDIT);
                    Talk(SAY_CITIZEN_END);
                    me->GetMotionMaster()->MovePoint(POINT_SPARKNOZZLE, caster->GetPositionX(), caster->GetPositionY(), caster->GetPositionZ());
                }
            }

            void UpdateAI(const uint32 diff)
            {
                Unit* owner = me->GetOwner();

                if (!owner)
                    return;

                if (owner->IsMounted() && !me->IsMounted())
                    me->Mount(_mountModel);
                else if (!owner->IsMounted() && me->IsMounted())
                    me->Unmount();

                me->SetSpeed(MOVE_RUN, owner->GetSpeedRate(MOVE_RUN));
                me->SetSpeed(MOVE_WALK, owner->GetSpeedRate(MOVE_WALK));
            }

        private:
            uint32 _mountModel;
            bool _complete;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_gnome_citizenAI(creature);
        }
};

class spell_motivate_a_tron : public SpellScriptLoader
{
    public:
        spell_motivate_a_tron() : SpellScriptLoader("spell_motivate_a_tron") {}

        class spell_motivate_a_tron_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_motivate_a_tron_SpellScript)
            bool Validate(SpellEntry const* /*spellEntry*/)
            {
                if (!sSpellStore.LookupEntry(SPELL_MOTIVATE_1))
                    return false;
                if (!sSpellStore.LookupEntry(SPELL_MOTIVATE_2))
                    return false;
               return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                if (Unit* target = GetHitUnit())
                {
                    uint32 motivate = 0;
                    if (target->GetEntry() == NPC_CITIZEN_1)
                        motivate = SPELL_MOTIVATE_1;
                    else if (target->GetEntry() == NPC_CITIZEN_2)
                        motivate = SPELL_MOTIVATE_2;
                    if (motivate)
                        caster->CastSpell(target, motivate, true, NULL, NULL, caster->GetGUID());
                }
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_motivate_a_tron_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_motivate_a_tron_SpellScript();
        }
};

void AddSC_ironforge()
{
    new npc_royal_historian_archesonus();
    new npc_gnome_citizen();
    new spell_motivate_a_tron();
}
