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
#include "Player.h"
#include "blackwing_lair.h"

enum Emotes
{
    EMOTE_FRENZY                                           = 0,
    EMOTE_SHIMMER                                          = 1,
};

enum Spells
{
    // These spells are actually called elemental shield
    // What they do is decrease all damage by 75% then they increase
    // One school of damage by 1100%
    SPELL_FIRE_VULNERABILITY                               = 22277,
    SPELL_FROST_VULNERABILITY                              = 22278,
    SPELL_SHADOW_VULNERABILITY                             = 22279,
    SPELL_NATURE_VULNERABILITY                             = 22280,
    SPELL_ARCANE_VULNERABILITY                             = 22281,
    // Other spells
    SPELL_INCINERATE                                       = 23308,   //Incinerate 23308, 23309
    SPELL_TIMELAPSE                                        = 23310,   //Time lapse 23310, 23311(old threat mod that was removed in 2.01)
    SPELL_CORROSIVEACID                                    = 23313,   //Corrosive Acid 23313, 23314
    SPELL_IGNITEFLESH                                      = 23315,   //Ignite Flesh 23315, 23316
    SPELL_FROSTBURN                                        = 23187,   //Frost burn 23187, 23189
    // Brood Affliction 23173 - Scripted Spell that cycles through all targets within 100 yards and has a chance to cast one of the afflictions on them
    // Since Scripted spells arn't coded I'll just write a function that does the same thing
    SPELL_BROODAF_BLUE                                     = 23153,   //Blue affliction 23153
    SPELL_BROODAF_BLACK                                    = 23154,   //Black affliction 23154
    SPELL_BROODAF_RED                                      = 23155,   //Red affliction 23155 (23168 on death)
    SPELL_BROODAF_BRONZE                                   = 23170,   //Bronze Affliction  23170
    SPELL_BROODAF_GREEN                                    = 23169,   //Brood Affliction Green 23169
    SPELL_CHROMATIC_MUT_1                                  = 23174,   //Spell cast on player if they get all 5 debuffs
    SPELL_FRENZY                                           = 28371,   //The frenzy spell may be wrong
    SPELL_ENRAGE                                           = 28747
};

enum Events
{
    EVENT_SHIMMER       = 1,
    EVENT_BREATH_1      = 2,
    EVENT_BREATH_2      = 3,
    EVENT_AFFLICTION    = 4,
    EVENT_FRENZY        = 5
};

class boss_chromaggus : public CreatureScript
{
public:
    boss_chromaggus() : CreatureScript("boss_chromaggus") { }

    struct boss_chromaggusAI : public BossAI
    {
        boss_chromaggusAI(Creature* creature) : BossAI(creature, BOSS_CHROMAGGUS)
        {
            // Select the 2 breaths that we are going to use until despawned
            // 5 possiblities for the first breath, 4 for the second, 20 total possiblites
            // This way we don't end up casting 2 of the same breath
            // TL TL would be stupid
            switch (urand(0, 19))
            {
                // B1 - Incin
                case 0:
                    Breath1_Spell = SPELL_INCINERATE;
                    Breath2_Spell = SPELL_TIMELAPSE;
                    break;
                case 1:
                    Breath1_Spell = SPELL_INCINERATE;
                    Breath2_Spell = SPELL_CORROSIVEACID;
                    break;
                case 2:
                    Breath1_Spell = SPELL_INCINERATE;
                    Breath2_Spell = SPELL_IGNITEFLESH;
                    break;
                case 3:
                    Breath1_Spell = SPELL_INCINERATE;
                    Breath2_Spell = SPELL_FROSTBURN;
                    break;

                    // B1 - TL
                case 4:
                    Breath1_Spell = SPELL_TIMELAPSE;
                    Breath2_Spell = SPELL_INCINERATE;
                    break;
                case 5:
                    Breath1_Spell = SPELL_TIMELAPSE;
                    Breath2_Spell = SPELL_CORROSIVEACID;
                    break;
                case 6:
                    Breath1_Spell = SPELL_TIMELAPSE;
                    Breath2_Spell = SPELL_IGNITEFLESH;
                    break;
                case 7:
                    Breath1_Spell = SPELL_TIMELAPSE;
                    Breath2_Spell = SPELL_FROSTBURN;
                    break;

                    //B1 - Acid
                case 8:
                    Breath1_Spell = SPELL_CORROSIVEACID;
                    Breath2_Spell = SPELL_INCINERATE;
                    break;
                case 9:
                    Breath1_Spell = SPELL_CORROSIVEACID;
                    Breath2_Spell = SPELL_TIMELAPSE;
                    break;
                case 10:
                    Breath1_Spell = SPELL_CORROSIVEACID;
                    Breath2_Spell = SPELL_IGNITEFLESH;
                    break;
                case 11:
                    Breath1_Spell = SPELL_CORROSIVEACID;
                    Breath2_Spell = SPELL_FROSTBURN;
                    break;

                    //B1 - Ignite
                case 12:
                    Breath1_Spell = SPELL_IGNITEFLESH;
                    Breath2_Spell = SPELL_INCINERATE;
                    break;
                case 13:
                    Breath1_Spell = SPELL_IGNITEFLESH;
                    Breath2_Spell = SPELL_CORROSIVEACID;
                    break;
                case 14:
                    Breath1_Spell = SPELL_IGNITEFLESH;
                    Breath2_Spell = SPELL_TIMELAPSE;
                    break;
                case 15:
                    Breath1_Spell = SPELL_IGNITEFLESH;
                    Breath2_Spell = SPELL_FROSTBURN;
                    break;

                    //B1 - Frost
                case 16:
                    Breath1_Spell = SPELL_FROSTBURN;
                    Breath2_Spell = SPELL_INCINERATE;
                    break;
                case 17:
                    Breath1_Spell = SPELL_FROSTBURN;
                    Breath2_Spell = SPELL_TIMELAPSE;
                    break;
                case 18:
                    Breath1_Spell = SPELL_FROSTBURN;
                    Breath2_Spell = SPELL_CORROSIVEACID;
                    break;
                case 19:
                    Breath1_Spell = SPELL_FROSTBURN;
                    Breath2_Spell = SPELL_IGNITEFLESH;
                    break;
            };

            EnterEvadeMode();
        }

        void Reset()
        {
            _Reset();

            CurrentVurln_Spell = 0;     // We use this to store our last vulnerabilty spell so we can remove it later
            Enraged = false;
        }

        void EnterCombat(Unit* /*who*/)
        {
            if (instance && instance->GetBossState(BOSS_FLAMEGOR) != DONE)
            {
                EnterEvadeMode();
                return;
            }
            _EnterCombat();

            events.ScheduleEvent(EVENT_SHIMMER, 0);
            events.ScheduleEvent(EVENT_BREATH_1, 30000);
            events.ScheduleEvent(EVENT_BREATH_2, 60000);
            events.ScheduleEvent(EVENT_AFFLICTION, 10000);
            events.ScheduleEvent(EVENT_FRENZY, 15000);
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SHIMMER:
                        {
                            // Remove old vulnerabilty spell
                            if (CurrentVurln_Spell)
                                me->RemoveAurasDueToSpell(CurrentVurln_Spell);

                            // Cast new random vulnerabilty on self
                            uint32 spell = RAND(SPELL_FIRE_VULNERABILITY, SPELL_FROST_VULNERABILITY, SPELL_SHADOW_VULNERABILITY, SPELL_NATURE_VULNERABILITY, SPELL_ARCANE_VULNERABILITY);
                            DoCast(me, spell);
                            CurrentVurln_Spell = spell;
                            Talk(EMOTE_SHIMMER);
                            events.ScheduleEvent(EVENT_SHIMMER, 45000);
                            break;
                        }
                    case EVENT_BREATH_1:
                            DoCastVictim(Breath1_Spell);
                            events.ScheduleEvent(EVENT_BREATH_1, 60000);
                            break;
                    case EVENT_BREATH_2:
                            DoCastVictim(Breath2_Spell);
                            events.ScheduleEvent(EVENT_BREATH_2, 60000);
                            break;
                    case EVENT_AFFLICTION:
                        {
                            Map::PlayerList const &players = me->GetMap()->GetPlayers();
                            for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                            {
                                if (Player* player = itr->GetSource()->ToPlayer())
                                {
                                    DoCast(player, RAND(SPELL_BROODAF_BLUE, SPELL_BROODAF_BLACK, SPELL_BROODAF_RED, SPELL_BROODAF_BRONZE, SPELL_BROODAF_GREEN), true);

                                        if (player->HasAura(SPELL_BROODAF_BLUE) &&
                                            player->HasAura(SPELL_BROODAF_BLACK) &&
                                            player->HasAura(SPELL_BROODAF_RED) &&
                                            player->HasAura(SPELL_BROODAF_BRONZE) &&
                                            player->HasAura(SPELL_BROODAF_GREEN))
                                        {
                                            DoCast(player, SPELL_CHROMATIC_MUT_1);
                                        }

                                }
                            }
                        }
                        events.ScheduleEvent(EVENT_AFFLICTION, 10000);
                        break;
                    case EVENT_FRENZY:
                        DoCast(me, SPELL_FRENZY);
                        events.ScheduleEvent(EVENT_FRENZY, urand(10000, 15000));
                        break;
                }
            }

            // Enrage if not already enraged and below 20%
            if (!Enraged && HealthBelowPct(20))
            {
                DoCast(me, SPELL_ENRAGE);
                Enraged = true;
            }

            DoMeleeAttackIfReady();
        }

    private:
        uint32 Breath1_Spell;
        uint32 Breath2_Spell;
        uint32 CurrentVurln_Spell;
        bool Enraged;
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_chromaggusAI (creature);
    }
};

void AddSC_boss_chromaggus()
{
    new boss_chromaggus();
}
