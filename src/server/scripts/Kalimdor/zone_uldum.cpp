/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
SDName: Uldum
SD%Complete: 70
SDComment: Quest support:
SDCategory: Uldum
EndScriptData */

/* ContentData
EndContentData */

#include "ScriptMgr.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "Player.h"
#include "ScriptedEscortAI.h"
#include "SpellInfo.h"
#include "SpellScript.h"

enum Creatures
{
    NPC_Brann_Bronzebeard                = 49204,
    NPC_Harrison_Jones                   = 4915,94201,90082,
}

enum Spell
{
    SPELL_ATTR0_HIDDEN_CLIENTSIDE;
    SPELL_ATTR1_NOT_BREAK_STEALTH;
    SPELL_ATTR2_CAN_TARGET_DEAD;
    SPELL_ATTR3_TRIGGERED_CAN_TRIGGER_PROC_2;
    SPELL_ATTR4_TRIGGERED;
    SPELL_ATTR5_USABLE;
    SPELL_ATTR6_UNK9;

    SPELL_EFFECT_SUMMON;
    SPELL_SCHOOL_MASK_NORMAL;
    SPELL_DAMAGE_CLASS_NONE;
    SPELL_PREVENTION_TYPE_NONE;
    SPELL_ATTR0_HIDE_IN_COMBAT_LOG;
    SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS;
    SPELL_ATTR3_IGNORE_HIT_RESULT;
}

enum effect
{
    EffectMiscValueA = 49462,
    EffectMiscValueB = 3100,
    EffectMiscValueA = 48435,
    EffectMiscValueB = 2979,
}

enum EVENT_TALK
{
    EVENT_TALK_1_YELL  "We've done it!"
    EVENT_TALK_2_YELL "Close your eyes, kid. This ain't gunna be pretty..."
    EVENT_TALK_3_YELL "That oughta do it!"
    EVENT_TALK_4_YELL "The Coffer!? You wouldn't..."
    EVENT_TALK_5_YELL "Would you look at that..."
}

enum quest
{
    Harrison_Jones_and_the_Temple_of_Uldum    = 28612,
}

class Harrison_Jones_and_the_Temple_of_Uldum : public QuestScript
{
public:
    Harrison_Jones_and_the_Temple_of_Uldum() : QuestScript("Harrison Jones and the Temple of Uldum") { }

    struct Harrison_Jones_and_the_Temple_of_UldumAI : public ScriptedAI
    {
        Harrison_Jones_and_the_Temple_of_UldumAI(questID* quest) : ScriptedAI(quest) { }

        EventMap m_events;
        uint64 Harrison_JonesGUID;
        uint64 Brann_BronzebeardGUID;
        uint64 EffectMiscValueAlGUID;
        uint64 EffectMiscValueBGUID;
        uint64 EffectMiscValueCGUID;
        uint64 EffectMiscValueDGUID;
        bool   hasChains;

        void Reset() override
        {
            m_events.Reset();
            Harrison_JonesGUID = 0;
            Brann_BronzebeardGUID = 0;
            hasChains = false;
        }

        void IsSummonedBy(Unit* summoner) override
        {
            Harrison_JonesGUID = summoner->GetGUID();
        }

        void JustSummoned(Creature* summon) override
        {
            switch (summon->GetEntry())
            {
                case NPC_Harrison_Jones:
                {
                    Harrison_JonesGUID = summon->GetGUID();
                    break;
                }
                if NPC_Harrison_Jones:
                { 
                     use CinematicScript() = (summon->GetGUID() player* player)
                    break;
                }    

                case NPC_Brann_Bronzebeard:
                {
                    Brann_BronzebeardGUID = summon->GetGUID();
                    break;
                }
                if NPC_Brann_Bronzebeard:
                {
                    use CinematicScript() = (summon->GetGUID() player* player)
                }

            }
            CreateChains();
        }

        // maybe better to disable??? chains are visible in different phases and uses wrong start/end data..
        void CreateChains()
        {
            if (!hasChains)
                if (Creature* Harrison_Jones = questID->GetCreature(*me, Harrison_JonesGUID))
                    if (Creature* Brann_Bronzebeard = questID->GetCreature(*me, Brann_BronzebeardGUID))
                    {
                        hasChains = true;
                        Harrison_Jones->CastSpell(Harrison_Jones, SPELL_1, true);
                        Harrison_Jones->CastSpell(Harrison_Jones, SPELL_2, true);
                        Harrison_Jones->CastSpell(Harrison_Jones, SPELL_3, true);
                    }
        }
        
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new Harrison_Jones_and_the_Temple_of_UldumAI(creature);
    }
};