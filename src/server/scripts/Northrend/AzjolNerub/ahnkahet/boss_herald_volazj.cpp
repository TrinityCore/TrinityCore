/*
 * Copyright (C) 2008-2011 by WarHead - United Worlds of MaNGOS - http://www.uwom.de
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "ahnkahet.h"

// Verzerrtes Gesicht - ID 30621-30625 - Jeder Spieler bekommt seine eigene NPC ID gespawnt!
const uint32 VerzerrtesGesicht[5] = { 30621, 30622, 30623, 30624, 30625 };

enum Spells
{
    SPELL_INSANITY                  = 57496, //Dummy
    INSANITY_VISUAL                 = 57561,
    SPELL_INSANITY_TARGET           = 57508,
    SPELL_MIND_FLAY                 = 57941,
    SPELL_SHADOW_BOLT_VOLLEY        = 57942,
    SPELL_SHIVER                    = 57949,
    SPELL_CLONE_PLAYER              = 57507, //casted on player during insanity
    SPELL_INSANITY_PHASING_1        = 57508,
    SPELL_INSANITY_PHASING_2        = 57509,
    SPELL_INSANITY_PHASING_3        = 57510,
    SPELL_INSANITY_PHASING_4        = 57511,
    SPELL_INSANITY_PHASING_5        = 57512,
    SpellTwistedVisageVisualPassive = 57551,
    SpellTwistedVisageDeathVisual   = 57555,
    SpellSummonTwistedVisageSpawnN  = 57506, // Hat keinen sichbaren Effekt! Script Effect = SPELL_CLONE_PLAYER
    SpellSummonTwistedVisageSpawnH  = 59982  // Hat keinen sichbaren Effekt! Script Effect = SPELL_CLONE_PLAYER
};

//not in db
enum Yells
{
    SAY_AGGRO   = -1619030,
    SAY_SLAY_1  = -1619031,
    SAY_SLAY_2  = -1619032,
    SAY_SLAY_3  = -1619033,
    SAY_DEATH_1 = -1619034,
    SAY_DEATH_2 = -1619035,
    SAY_PHASE   = -1619036
};

enum Achievements
{
    ACHIEV_QUICK_DEMISE_START_EVENT = 20382
};

enum VolazjEvents
{
    EVENT_MIND_FLAY = 1,
    EVENT_SHADOW_BOLT_VOLLEY,
    EVENT_SHIVER,
    EVENT_INSANITY
};

enum GesichterEvents
{
    EVENT_RND_CAST = 1
};

// TODO: Spells für die klassen heraus suchen / setzen!
const uint32 KriegerSpells[3]       = { 0, 0, 0 };
const uint32 PaladinSpells[3]       = { 0, 0, 0 };
const uint32 JaegerSpells[3]        = { 0, 0, 0 };
const uint32 SchurkeSpells[3]       = { 0, 0, 0 };
const uint32 PriesterSpells[3]      = { 0, 0, 0 };
const uint32 TodesritterSpells[3]   = { 0, 0, 0 };
const uint32 SchamaneSpells[3]      = { 0, 0, 0 };
const uint32 MagierSpells[3]        = { 0, 0, 0 };
const uint32 HexenmeiterSpells[3]   = { 0, 0, 0 };
const uint32 DruideSpells[3]        = { 0, 0, 0 };

class mob_verzerrtes_gesicht : public CreatureScript
{
    public:
        mob_verzerrtes_gesicht() : CreatureScript("mob_verzerrtes_gesicht") { }

        struct mob_verzerrtes_gesichtAI : public ScriptedAI
        {
            mob_verzerrtes_gesichtAI(Creature * creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
                me->CastSpell(me, SpellTwistedVisageVisualPassive);
                plClass = (Classes)0;
                heal = false;
            }

            void Reset()
            {
                events.Reset();
            }

            void EnterCombat(Unit * /*who*/)
            {
                events.ScheduleEvent(EVENT_RND_CAST, SEKUNDEN_10);
                DoZoneInCombat();
            }

            // Spielerklasse für den NPC setzen
            void SetzeKlasse(Classes _plClass)
            {
                plClass = _plClass;
            }

            // TODO: Entsprechend von plClass die Spells casten!
            void FuehreSpellAus()
            {
                switch(plClass)
                {
                    case CLASS_WARRIOR:
                    case CLASS_PALADIN:
                    case CLASS_ROGUE:
                    case CLASS_DEATH_KNIGHT:
                        break;
                    case CLASS_HUNTER:
                    case CLASS_PRIEST:
                    case CLASS_SHAMAN:
                    case CLASS_MAGE:
                    case CLASS_WARLOCK:
                        break;
                    case CLASS_DRUID:
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                {
                    // Entsprechend der Klasse/Form Fern oder Nahkampf wählen
                    if (Player * chr = GetPlayerAtMinimumRange(1.0f))
                        switch(plClass)
                        {
                            case CLASS_WARRIOR:
                            case CLASS_PALADIN:
                            case CLASS_ROGUE:
                            case CLASS_DEATH_KNIGHT:
                                me->AI()->AttackStart(chr);
                                break;
                            case CLASS_HUNTER:
                            case CLASS_PRIEST:
                            case CLASS_SHAMAN:
                            case CLASS_MAGE:
                            case CLASS_WARLOCK:
                                me->AI()->AttackStart(chr, 20.0f);
                                break;
                            case CLASS_DRUID:
                                if (me->GetShapeshiftForm() == FORM_TREE)
                                    heal = true;
                                if (me->GetShapeshiftForm() == FORM_MOONKIN)
                                    me->AI()->AttackStart(chr, 20.0f);
                                else
                                    me->AI()->AttackStart(chr);
                                break;
                            default:
                                break;
                        }
                    return;
                }

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    if (eventId == EVENT_RND_CAST)
                    {
                        FuehreSpellAus();
                        events.RescheduleEvent(EVENT_RND_CAST, SEKUNDEN_10);
                    }
                }
                DoMeleeAttackIfReady();
            }

            void DamageTaken(Unit * /*attacker*/, uint32 & dmg)
            {
                if (dmg >= me->GetHealth())
                    me->CastSpell(me, SpellTwistedVisageDeathVisual);
            }

        private:
            InstanceScript * instance;
            Classes plClass;
            EventMap events;
            bool heal;
        };

        CreatureAI * GetAI(Creature * creature) const
        {
            return new mob_verzerrtes_gesichtAI(creature);
        }
};

class boss_volazj : public CreatureScript
{
public:
    boss_volazj() : CreatureScript("boss_volazj") { }

    struct boss_volazjAI : public ScriptedAI
    {
        boss_volazjAI(Creature * creature) : ScriptedAI(creature), Summons(me)
        {
            pInstance = creature->GetInstanceScript();
            insanityHandled = 0;
        }

        void Reset()
        {
            if (pInstance)
            {
                pInstance->SetData(DATA_HERALD_VOLAZJ, NOT_STARTED);
                pInstance->DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_QUICK_DEMISE_START_EVENT);
            }
            // Visible for all players in insanity
            me->SetPhaseMask((1|16|32|64|128|256), true);
            // Used for Insanity handling
            insanityHandled = 0;

            ResetPlayersPhaseMask();
            // Cleanup
            Summons.DespawnAll();
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->SetControlled(false, UNIT_STAT_STUNNED);
            me->RemoveAurasDueToSpell(INSANITY_VISUAL);
        }

        void EnterCombat(Unit * /*who*/)
        {
            events.ScheduleEvent(EVENT_MIND_FLAY, 8 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_SHADOW_BOLT_VOLLEY, 5 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_SHIVER, 15 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_INSANITY, 15 * IN_MILLISECONDS);

            DoScriptText(SAY_AGGRO, me);

            if (pInstance)
            {
                pInstance->SetData(DATA_HERALD_VOLAZJ, IN_PROGRESS);
                pInstance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_QUICK_DEMISE_START_EVENT);
            }
            DoZoneInCombat();
        }

        void DamageTaken(Unit * /*attacker*/, uint32 & damage)
        {
            if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE))
                damage = 0;
        }

        void SpellHitTarget(Unit * target, const SpellInfo * spell)
        {
            if (spell->Id == SPELL_INSANITY)
            {
                // Not good target or too many players
                if (target->GetTypeId() != TYPEID_PLAYER || insanityHandled > 4)
                    return;
                // First target - start channel visual and set self as unnattackable
                if (!insanityHandled)
                {   // Channel visual
                    DoCast(me, INSANITY_VISUAL, true);
                    // Unattackable
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    me->SetControlled(true, UNIT_STAT_STUNNED);
                }
                // phase mask
                target->CastSpell(target, SPELL_INSANITY_TARGET+insanityHandled, true);
                // summon twisted party members for this target
                Map::PlayerList const & players = me->GetMap()->GetPlayers();
                for (Map::PlayerList::const_iterator i = players.begin(); i != players.end(); ++i)
                {
                    Player * player = i->getSource();
                    if (!player || !player->isAlive())
                        continue;
                    // Summon clone
                    Position pos;
                    player->GetPosition(&pos);
                    me->GetRandomNearPosition(pos, 10.0f);

                    if (Creature * summon = me->SummonCreature(VerzerrtesGesicht[insanityHandled], pos, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1 * IN_MILLISECONDS))
                    {   // clone
                        player->CastSpell(summon, SPELL_CLONE_PLAYER, true);
                        // set phase
                        summon->SetPhaseMask((1<<(4+insanityHandled)), true);
                        // Dem Klone die selbe Waffe in die Hand drücken, und die Klasse mitteilen!
                        if (Item * item = player->GetWeaponForAttack(BASE_ATTACK, true))
                        {
                            CAST_AI(mob_verzerrtes_gesicht::mob_verzerrtes_gesichtAI, summon->AI())->SetEquipmentSlots(false, item->GetEntry());
                            CAST_AI(mob_verzerrtes_gesicht::mob_verzerrtes_gesichtAI, summon->AI())->SetzeKlasse((Classes)player->getClass());
                        }
                    }
                }
                ++insanityHandled;
            }
        }

        void JustSummoned(Creature * summon)
        {
            Summons.Summon(summon);
        }

        void SummonedCreatureDespawn(Creature * summon)
        {
            uint32 phase= summon->GetPhaseMask();
            uint32 nextPhase = 0;
            Summons.Despawn(summon);
            // Check if all summons in this phase killed
            for (SummonList::const_iterator iter = Summons.begin(); iter != Summons.end(); ++iter)
                if (Creature * visage = Unit::GetCreature(*me, *iter))
                {   // Not all are dead
                    if (phase == visage->GetPhaseMask())
                        return;
                    else
                        nextPhase = visage->GetPhaseMask();
                }
            // Roll Insanity
            uint32 spell = GetSpellForPhaseMask(phase);
            uint32 spell2 = GetSpellForPhaseMask(nextPhase);

            Map * pMap = me->GetMap();
            if (!pMap)
                return;

            Map::PlayerList const &PlayerList = pMap->GetPlayers();
            if (!PlayerList.isEmpty())
                for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                    if (Player * player = i->getSource())
                        if (player->HasAura(spell))
                        {
                            player->RemoveAurasDueToSpell(spell);
                            if (spell2) // if there is still some different mask cast spell for it
                                player->CastSpell(player, spell2, true);
                        }
        }

        void ResetPlayersPhaseMask()
        {
            Map::PlayerList const & players = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = players.begin(); i != players.end(); ++i)
            {
                Player * player = i->getSource();
                player->RemoveAurasDueToSpell(GetSpellForPhaseMask(player->GetPhaseMask()));
            }
        }

        uint32 GetSpellForPhaseMask(uint32 phase)
        {
            switch (phase)
            {
                case 16: return SPELL_INSANITY_PHASING_1;
                case 32: return SPELL_INSANITY_PHASING_2;
                case 64: return SPELL_INSANITY_PHASING_3;
                case 128: return SPELL_INSANITY_PHASING_4;
                case 256: return SPELL_INSANITY_PHASING_5;
                default: return 0;
            }
            return 0;
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (insanityHandled)
            {
                if (!Summons.empty())
                    return;

                insanityHandled = 0;
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->SetControlled(false, UNIT_STAT_STUNNED);
                me->RemoveAurasDueToSpell(INSANITY_VISUAL);
            }

            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_MIND_FLAY:
                        DoCastVictim(SPELL_MIND_FLAY);
                        events.RescheduleEvent(EVENT_MIND_FLAY, SEKUNDEN_20);
                        break;
                    case EVENT_SHADOW_BOLT_VOLLEY:
                        DoCastVictim(SPELL_SHADOW_BOLT_VOLLEY);
                        events.RescheduleEvent(EVENT_SHADOW_BOLT_VOLLEY, 5 * IN_MILLISECONDS);
                        break;
                    case EVENT_SHIVER:
                        if (Unit * target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_SHIVER);
                        events.RescheduleEvent(EVENT_SHIVER, 15 * IN_MILLISECONDS);
                        break;
                    case EVENT_INSANITY:
                        DoCast(SPELL_INSANITY);
                        events.RescheduleEvent(EVENT_INSANITY, 15 * IN_MILLISECONDS);
                        break;
                    default:
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }

        void JustDied(Unit * /*killer*/)
        {
            DoScriptText(SAY_DEATH_1, me);

            if (pInstance)
                pInstance->SetData(DATA_HERALD_VOLAZJ, DONE);

            Summons.DespawnAll();
            ResetPlayersPhaseMask();
        }

        void KilledUnit(Unit * /*victim*/)
        {
            DoScriptText(RAND(SAY_SLAY_1, SAY_SLAY_2, SAY_SLAY_3), me);
        }

    private:
        InstanceScript * pInstance;
        SummonList Summons;
        EventMap events;
        uint32 insanityHandled;
    };

    CreatureAI * GetAI(Creature * creature) const
    {
        return new boss_volazjAI(creature);
    }
};

void AddSC_boss_volazj()
{
    new boss_volazj;
    new mob_verzerrtes_gesicht;
}
