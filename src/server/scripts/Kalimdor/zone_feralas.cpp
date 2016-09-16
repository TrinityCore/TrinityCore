/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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
SDName: Feralas
SD%Complete: 100
SDComment: Quest support: 2767, 2987
SDCategory: Feralas
EndScriptData */

/* ContentData
npc_oox22fe
spell_gordunni_trap
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "ScriptedGossip.h"
#include "SpellScript.h"
#include "Player.h"
#include "WorldSession.h"

/*######
## npc_oox22fe
######*/

enum OOX
{
    SAY_OOX_START           = 0,
    SAY_OOX_AGGRO           = 1,
    SAY_OOX_AMBUSH          = 2,
    SAY_OOX_END             = 3,

    NPC_YETI                = 7848,
    NPC_GORILLA             = 5260,
    NPC_WOODPAW_REAVER      = 5255,
    NPC_WOODPAW_BRUTE       = 5253,
    NPC_WOODPAW_ALPHA       = 5258,
    NPC_WOODPAW_MYSTIC      = 5254,

    QUEST_RESCUE_OOX22FE    = 2767,
    FACTION_ESCORTEE_A      = 774,
    FACTION_ESCORTEE_H      = 775
};

class npc_oox22fe : public CreatureScript
{
public:
    npc_oox22fe() : CreatureScript("npc_oox22fe") { }

    bool OnQuestAccept(Player* player, Creature* creature, const Quest* quest) override
    {
        if (quest->GetQuestId() == QUEST_RESCUE_OOX22FE)
        {
            creature->AI()->Talk(SAY_OOX_START);
            //change that the npc is not lying dead on the ground
            creature->SetStandState(UNIT_STAND_STATE_STAND);

            if (player->GetTeam() == ALLIANCE)
                creature->setFaction(FACTION_ESCORTEE_A);

            if (player->GetTeam() == HORDE)
                creature->setFaction(FACTION_ESCORTEE_H);

            if (npc_escortAI* pEscortAI = CAST_AI(npc_oox22fe::npc_oox22feAI, creature->AI()))
                pEscortAI->Start(true, false, player->GetGUID());

        }
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_oox22feAI(creature);
    }

    struct npc_oox22feAI : public npc_escortAI
    {
        npc_oox22feAI(Creature* creature) : npc_escortAI(creature) { }

        void WaypointReached(uint32 waypointId) override
        {
            switch (waypointId)
            {
                // First Ambush(3 Yetis)
                case 11:
                    Talk(SAY_OOX_AMBUSH);
                    me->SummonCreature(NPC_YETI, -4841.01f, 1593.91f, 73.42f, 3.98f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000);
                    me->SummonCreature(NPC_YETI, -4837.61f, 1568.58f, 78.21f, 3.13f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000);
                    me->SummonCreature(NPC_YETI, -4841.89f, 1569.95f, 76.53f, 0.68f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000);
                    break;
                //Second Ambush(3 Gorillas)
                case 21:
                    Talk(SAY_OOX_AMBUSH);
                    me->SummonCreature(NPC_GORILLA, -4595.81f, 2005.99f, 53.08f, 3.74f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000);
                    me->SummonCreature(NPC_GORILLA, -4597.53f, 2008.31f, 52.70f, 3.78f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000);
                    me->SummonCreature(NPC_GORILLA, -4599.37f, 2010.59f, 52.77f, 3.84f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000);
                    break;
                //Third Ambush(4 Gnolls)
                case 30:
                    Talk(SAY_OOX_AMBUSH);
                    me->SummonCreature(NPC_WOODPAW_REAVER, -4425.14f, 2075.87f, 47.77f, 3.77f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000);
                    me->SummonCreature(NPC_WOODPAW_BRUTE, -4426.68f, 2077.98f, 47.57f, 3.77f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000);
                    me->SummonCreature(NPC_WOODPAW_MYSTIC, -4428.33f, 2080.24f, 47.43f, 3.87f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000);
                    me->SummonCreature(NPC_WOODPAW_ALPHA, -4430.04f, 2075.54f, 46.83f, 3.81f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000);
                    break;
                case 37:
                    Talk(SAY_OOX_END);
                    // Award quest credit
                    if (Player* player = GetPlayerForEscort())
                        player->GroupEventHappens(QUEST_RESCUE_OOX22FE, me);
                    break;
            }
        }

        void Reset() override
        {
            if (!HasEscortState(STATE_ESCORT_ESCORTING))
                me->SetStandState(UNIT_STAND_STATE_DEAD);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            //For an small probability the npc says something when he get aggro
            if (urand(0, 9) > 7)
                Talk(SAY_OOX_AGGRO);
        }

        void JustSummoned(Creature* summoned) override
        {
            summoned->AI()->AttackStart(me);
        }
    };

};

/*######
## spell_gordunni_trap
######*/

enum GordunniTrap
{
    GO_GORDUNNI_DIRT_MOUND = 144064,
};

class spell_gordunni_trap : public SpellScriptLoader
{
    public:
        spell_gordunni_trap() : SpellScriptLoader("spell_gordunni_trap") { }

        class spell_gordunni_trap_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_gordunni_trap_SpellScript);

            void HandleDummy()
            {
                Unit* caster = GetCaster();
                if (GameObject* chest = caster->SummonGameObject(GO_GORDUNNI_DIRT_MOUND, *caster, G3D::Quat(), 0))
                {
                    chest->SetSpellId(GetSpellInfo()->Id);
                    caster->RemoveGameObject(chest, false);
                }
            }

            void Register() override
            {
                OnCast += SpellCastFn(spell_gordunni_trap_SpellScript::HandleDummy);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_gordunni_trap_SpellScript();
        }
};

/*######
## AddSC
######*/

void AddSC_feralas()
{
    new npc_oox22fe();
    new spell_gordunni_trap();
}
