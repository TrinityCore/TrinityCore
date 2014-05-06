/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2013 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
#include "ScriptedEscortAI.h"
#include "razorfen_kraul.h"
#include "Player.h"
#include "PetAI.h"
#include "SpellScript.h"

enum Willix
{
    SAY_READY                   = 0,
    SAY_POINT                   = 1,
    SAY_AGGRO1                  = 2,
    SAY_BLUELEAF                = 3,
    SAY_DANGER                  = 4,
    SAY_BAD                     = 5,
    SAY_THINK                   = 6,
    SAY_SOON                    = 7,
    SAY_FINALY                  = 8,
    SAY_WIN                     = 9,
    SAY_END                     = 10,

    QUEST_WILLIX_THE_IMPORTER   = 1144,
    ENTRY_BOAR                  = 4514
};

class npc_willix : public CreatureScript
{
public:
    npc_willix() : CreatureScript("npc_willix") { }

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_WILLIX_THE_IMPORTER)
        {
            CAST_AI(npc_escortAI, (creature->AI()))->Start(true, false, player->GetGUID());
            creature->AI()->Talk(SAY_READY, player);
            creature->setFaction(113);
        }

        return true;
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_willixAI(creature);
    }

    struct npc_willixAI : public npc_escortAI
    {
        npc_willixAI(Creature* creature) : npc_escortAI(creature) { }

        void WaypointReached(uint32 waypointId) override
        {
            Player* player = GetPlayerForEscort();
            if (!player)
                return;

            switch (waypointId)
            {
                case 3:
                    me->HandleEmoteCommand(EMOTE_STATE_POINT);
                    Talk(SAY_POINT, player);
                    break;
                case 4:
                    me->SummonCreature(ENTRY_BOAR, 2137.66f, 1843.98f, 48.08f, 1.54f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                    break;
                case 8:
                    Talk(SAY_BLUELEAF, player);
                    break;
                case 9:
                    Talk(SAY_DANGER, player);
                    break;
                case 13:
                    Talk(SAY_BAD, player);
                    break;
                case 14:
                    me->SummonCreature(ENTRY_BOAR, 2078.91f, 1704.54f, 56.77f, 1.54f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                    break;
                case 25:
                    Talk(SAY_THINK, player);
                    break;
                case 31:
                    Talk(SAY_SOON, player);
                    break;
                case 42:
                    Talk(SAY_FINALY, player);
                    break;
                case 43:
                    me->SummonCreature(ENTRY_BOAR, 1956.43f, 1596.97f, 81.75f, 1.54f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                    break;
                case 45:
                    Talk(SAY_WIN, player);
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                    player->GroupEventHappens(QUEST_WILLIX_THE_IMPORTER, me);
                    break;
                case 46:
                    Talk(SAY_END, player);
                    break;
            }
        }

        void Reset() override { }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO1);
        }

        void JustSummoned(Creature* summoned) override
        {
            summoned->AI()->AttackStart(me);
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (Player* player = GetPlayerForEscort())
                player->FailQuest(QUEST_WILLIX_THE_IMPORTER);
        }
    };

};

enum SnufflenoseGopher
{
    NPC_SNUFFLENOSE_GOPHER       = 4781,
    GO_BLUELEAF_TUBBER           = 20920,
    ACTION_FIND_NEW_TUBBER       = 0,
    POINT_TUBBER                 = 0
};

struct DistanceOrder : public std::binary_function<GameObject, GameObject, bool>
{
    DistanceOrder(Creature* me) : me(me) { }

    bool operator() (GameObject* first, GameObject* second)
    {
        return me->GetDistanceOrder(first, second);
    }

    Creature* me;
};

struct npc_snufflenose_gopher : public CreatureScript
{
public:
    npc_snufflenose_gopher() : CreatureScript("npc_snufflenose_gopher") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_snufflenose_gopherAI(creature);
    }

    struct npc_snufflenose_gopherAI : public PetAI
    {
        npc_snufflenose_gopherAI(Creature* creature) : PetAI(creature)
        {
            IsMovementActive = false;
            TargetTubberGUID = 0;
        }

        void Reset() override
        {
            IsMovementActive = false;
            TargetTubberGUID = 0;
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == POINT_MOTION_TYPE && id == POINT_TUBBER)
            {
                if (GameObject* go = me->GetMap()->GetGameObject(TargetTubberGUID))
                {
                    go->SetRespawnTime(5 * MINUTE);
                    go->Refresh();
                    go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_INTERACT_COND);
                }

                IsMovementActive = false;
            }
            else
                PetAI::MovementInform(type, id);
        }

        void DoFindNewTubber()
        {
            std::list<GameObject*> tubbersInRange;
            GetGameObjectListWithEntryInGrid(tubbersInRange, me, GO_BLUELEAF_TUBBER, 40.0f);

            if (tubbersInRange.empty())
                return;

            tubbersInRange.sort(DistanceOrder(me));
            GameObject* nearestTubber = NULL;

            for (std::list<GameObject*>::const_iterator itr = tubbersInRange.begin(); itr != tubbersInRange.end(); ++itr)
            {
                if (!(*itr)->isSpawned() && (*itr)->HasFlag(GAMEOBJECT_FLAGS, GO_FLAG_INTERACT_COND))
                {
                    nearestTubber = *itr;
                    break;
                }
            }

            if (!nearestTubber)
                return;

            TargetTubberGUID = nearestTubber->GetGUID();

            // XFurry was wrong...
            me->GetMotionMaster()->MovePoint(POINT_TUBBER, nearestTubber->GetPositionX(),
                                                           nearestTubber->GetPositionY(),
                                                           nearestTubber->GetPositionZ());
            IsMovementActive = true;
        }

        void UpdateAI(uint32 diff) override
        {
            if (!IsMovementActive)
                PetAI::UpdateAI(diff);
        }

        void DoAction(int32 action) override
        {
            if (action == ACTION_FIND_NEW_TUBBER)
                DoFindNewTubber();
        }


        bool IsMovementActive;
        uint64 TargetTubberGUID;
    };
};

class spell_snufflenose_command : public SpellScriptLoader
{
    public:
        spell_snufflenose_command() : SpellScriptLoader("spell_snufflenose_command") { }

        class spell_snufflenose_commandSpellScript : public SpellScript
        {
            PrepareSpellScript(spell_snufflenose_commandSpellScript);

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            void HandleAfterCast()
            {
                if (Unit* target = GetCaster()->ToPlayer()->GetSelectedUnit())
                    if (target->GetEntry() == NPC_SNUFFLENOSE_GOPHER)
                        target->ToCreature()->AI()->DoAction(ACTION_FIND_NEW_TUBBER);
            }

            void Register() override
            {
                AfterCast += SpellCastFn(spell_snufflenose_commandSpellScript::HandleAfterCast);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_snufflenose_commandSpellScript();
        }
};

void AddSC_razorfen_kraul()
{
    new npc_snufflenose_gopher();
    new npc_willix();
    new spell_snufflenose_command();
}
