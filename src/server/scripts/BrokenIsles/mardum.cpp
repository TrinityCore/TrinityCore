/*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 3 of the License, or (at your
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

enum MardumBroadcastTexts
{
    SEVIS_TALK_ASHTONGUE_ONE = 0,
};

enum MardumQuests
{
    QUEST_ENTER_THE_ILLIDARI_ASHTONGUE = 40378,
};

enum MardumQuestObjectives
{
    OBJECTIVE_FIRST_SUMMONED_GUARDIAN = 280769
};

enum MardumCreatures
{
    CREATURE_FIRST_SUMMONED_GUARDIAN = 97831
};

class npc_sevis_brightflame_1 : public CreatureScript
{
public:
    npc_sevis_brightflame_1() : CreatureScript("npc_sevis_brightflame_1") { }

    struct npc_sevis_brightflame_1AI : public ScriptedAI
    {
        npc_sevis_brightflame_1AI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
        }

        void Reset() override
        {
        }

        void EnterCombat(Unit* /*who*/) override { }

        void MoveInLineOfSight(Unit* who) override
        {
            if (Player* player = who->ToPlayer())
                if (me->IsWithinDistInMap(who, 15.0f) && !player->GetQuestRewardStatus(QUEST_ENTER_THE_ILLIDARI_ASHTONGUE) && player->GetQuestStatus(QUEST_ENTER_THE_ILLIDARI_ASHTONGUE) == QUEST_STATUS_INCOMPLETE)
                {
                    Quest const* qInfo = sObjectMgr->GetQuestTemplate(QUEST_ENTER_THE_ILLIDARI_ASHTONGUE);
                    if (!qInfo)
                        return;

                    for (QuestObjective const& obj : qInfo->GetObjectives())
                    {
                        if (obj.ID == OBJECTIVE_FIRST_SUMMONED_GUARDIAN)
                            if (!player->IsQuestObjectiveComplete(qInfo, obj))
                            {
                                Talk(SEVIS_TALK_ASHTONGUE_ONE, who);
                                player->KilledMonsterCredit(CREATURE_FIRST_SUMMONED_GUARDIAN);
                            }
                    }
                    
                }
        }

        void IsSummonedBy(Unit* summoner)
        {
           /* if (Player* player = summoner->ToPlayer())
                me->SetCharmerGUID(player->GetGUID());*/
        }

        void SpellHit(Unit* Caster, const SpellInfo* Spell) override
        {
        }

        void UpdateAI(uint32 diff) override
        {
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_sevis_brightflame_1AI(creature);
    }
};


void AddSC_mardum()
{
    new npc_sevis_brightflame_1;
}