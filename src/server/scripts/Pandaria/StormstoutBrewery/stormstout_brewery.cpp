/*
 * Copyright (C) 2022 BfaCore Reforged
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

#include "stormstout_brewery.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"

enum eHabaneroBeer
{
    NPC_BARREL              = 56731,
    SPELL_GUSHING_BREW_BVIS = 114379, // Gushing Brew beam visual (The Great Wheel).
    SPELL_PROC_EXPLOSION    = 106787
};

enum Spells
{
    // FRIENDLY
    SPELL_AUNTIE_VISUAL = 115618, // Auntie Stormstout visual.
    SPELL_GUSHING_BREW_A = 114380, // Gushing Brew aura (NPC that has beam cast on).
    SPELL_LEAKING_BEER_B_A = 146604, // Dummy for NPC on Keg.
    SPELL_BEER_PUDDLE_VIS = 112960, // Beer on ground visual.

    // HOSTILE

    // Aqua Dancer - Once killed, their deaths will damage the Sodden Hozen Brawlers for half their health.
    SPELL_AQUATIC_ILLUSION = 107044, // Gives Sodden Hozen Brawler SPELL_WATER_STRIKE.
    SPELL_AQUAT_ILLUSION_R = 114655, // Removal damage.

    // Fiery Trickster - Once killed, their deaths will damage the Inflamed Hozen Brawlers for half their health.
    SPELL_FIERY_ILLUSION = 107175, // Gives Inflamed Hozen Brawler SPELL_FIRE_STRIKE.
    SPELL_FIERY_ILLUSION_R = 114656, // Removal damage.

    // Sodded Hozen Brawler
    SPELL_WATER_STRIKE = 107046,

    // Inflamed Hozen Brawler
    SPELL_FIRE_STRIKE = 107176,

    // Hozen Bouncer - 2 bouncers only, after Ook-Ook. After yells they run, crash into each other, die.
    SPELL_HOZEN_DOORGUARD = 107019,

    // Sleepy Hozen Brawler, Drunken Hozen Brawler.
    SPELL_COSMETIC_SLEEP = 124557, // Used by Sleepy.
    SPELL_UPPERCUT = 80182,

    SPELL_SPICY_EXPLOSION = 107205,

    SPELL_BREW_BARREL_EXPL = 107351, // Barrel monkey explosion.

    // Stout Brew Alemental
    SPELL_BREW_BOLT = 115652,
    SPELL_BLACKOUT_BREW = 106851,
    SPELL_BLACKOUT_DRUNK = 106857, // At 10 stacks of SPELL_BLACKOUT_BREW.

    // Sudsy Brew Alemental
    SPELL_BREW_BOLT2 = 115650,
    SPELL_SUDS = 116178, // Creates NPC_POOL_OF_SUDS at target location.
    AURA_SUDS = 116179, // Periodic dmg trigger aura.
    SPELL_SUDS_DUMMY_VIS = 119418, // Tooltip: "Can summon puddles of suds."

    // Unruly Alemental
    SPELL_BREW_BOLT3 = 118104,
    SPELL_BREWHAHA = 118099,

    // Bubbling Brew Alemental
    SPELL_BREW_BOLT4 = 116155,
    SPELL_BUBBLE_SHIELD = 128708,

    // Fizzy Brew Alemental
    // Uses SPELL_BREW_BOLT2.
    SPELL_CARBONATION_M = 116162, // Missile.
    SPELL_CARBONATION_S = 116164, // Creates NPC_CARBONATION_POOL at target location.
    AURA_CARBONATION = 116168, // Periodic dmg trigger aura.

    // Bloated Brew Alemental
    // Uses SPELL_BREW_BOLT.
    SPELL_BLOAT = 106546,

    // Yeasty Brew Alemental
    // Uses SPELL_BREW_BOLT4.
    // Uses Ferment in boss script.
};

enum Events
{
    // Trash

    EVENT_UPPERCUT = 1,
    EVENT_WATER_STRIKE,
    EVENT_FIRE_STRIKE,

    EVENT_BREW_BOLT,
    EVENT_BLACKOUT_BREW,
    EVENT_BREW_BOLT2,
    EVENT_SUDS,
    EVENT_BREW_BOLT3,
    EVENT_CARBONATION,
    EVENT_BLOAT,
    EVENT_BUBBLE_SHIELD,
    EVENT_BREW_BOLT4,

    // Hozen Bouncer
    EVENT_CHECK_OOK,
    EVENT_SAY_OOK_KILLED,
    EVENT_SAY_MEANS,
    EVENT_SAY_NEW_OOK,
    EVENT_SAY_PARTY,
    EVENT_RUN_AND_CRASH,
    EVENT_BOUNCER_DIE,

    // Chen Stormstout / Auntie Stormstout intro event
    EVENT_AUNTIE_ENTRANCE_SAY_1,
    EVENT_CHEN_ENTRANCE_SAY_1,
    EVENT_AUNTIE_ENTRANCE_SAY_2,
    EVENT_CHEN_ENTRANCE_SAY_2,
    EVENT_AUNTIE_ENTRANCE_SAY_3,
    EVENT_CHEN_ENTRANCE_SAY_3,
    EVENT_AUNTIE_ENTRANCE_SAY_4,
    EVENT_CHEN_ENTRANCE_SAY_4,
    EVENT_AUNTIE_ENTRANCE_SAY_5,
    EVENT_CHEN_ENTRANCE_SAY_5,
    EVENT_AUNTIE_ENTRANCE_SAY_6,
    EVENT_CHEN_ENTRANCE_SAY_6,
    EVENT_CHEN_ENTRANCE_SAY_7,

    // Ancestral Brewmaster
    EVENT_SPEAK_HOPTALLUS_1,
    EVENT_SPEAK_HOPTALLUS_2,
    EVENT_SPEAK_RANDOM
};

enum AncestralBrewmasterYells
{
    SAY_ABM_HOPTALLUS_1 = 0, // Whatzit... are they... what are they doin' to our alementals?
    SAY_ABM_HOPTALLUS_2 = 0, // Hey... hey YOU! Those are OUR flying... beer monsters?
};

class spell_stormstout_brewery_habanero_beer: public SpellScriptLoader
{
    public:
        spell_stormstout_brewery_habanero_beer() : SpellScriptLoader("spell_stormstout_brewery_habanero_beer") { }

        class spell_stormstout_brewery_habanero_beer_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_stormstout_brewery_habanero_beer_SpellScript);

            void HandleInstaKill(SpellEffIndex /*effIndex*/)
            {
                if (!GetCaster())
                    return;

                std::list<Creature*> creatureList;

                GetCaster()->GetCreatureListWithEntryInGrid(creatureList, NPC_BARREL, 10.0f);

                GetCaster()->RemoveAurasDueToSpell(SPELL_PROC_EXPLOSION);

                for (auto barrel : creatureList)
                {
                    if (barrel->HasAura(SPELL_PROC_EXPLOSION))
                    {
                        barrel->RemoveAurasDueToSpell(SPELL_PROC_EXPLOSION);
                        barrel->CastSpell(barrel, GetSpellInfo()->Id, true);
                    }
                }
            }

            void HandleAfterCast()
            {
                if (Unit* caster = GetCaster())
                    if (caster->ToCreature())
                        caster->ToCreature()->ForcedDespawn(1000);
            }

            void Register() override
            {
                OnEffectHit += SpellEffectFn(spell_stormstout_brewery_habanero_beer_SpellScript::HandleInstaKill, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
                AfterCast += SpellCastFn(spell_stormstout_brewery_habanero_beer_SpellScript::HandleAfterCast);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_stormstout_brewery_habanero_beer_SpellScript();
        }
};

// Leaking beer barrel 73186.
class npc_leaking_beer_barrel : public CreatureScript
{
public:
    npc_leaking_beer_barrel() : CreatureScript("npc_leaking_beer_barrel") { }

    struct npc_leaking_beer_barrel_AI : public ScriptedAI
    {
        npc_leaking_beer_barrel_AI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        void InitializeAI()
        {
            //if (!me->IsDead())
             //   Reset();
        }

        void Reset()
        {
            if (Creature* beerBunny = me->FindNearestCreature(NPC_BEER_BARREL_BUNNY, 15.0f, true))
                DoCast(beerBunny, SPELL_GUSHING_BREW_BVIS);
        }

        void UpdateAI(const uint32 diff) { }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_leaking_beer_barrel_AI(creature);
    }
};

// Beer barrel bunny 66215.
class npc_beer_barrel_bunny : public CreatureScript
{
public:
    npc_beer_barrel_bunny() : CreatureScript("npc_beer_barrel_bunny") { }

    struct npc_beer_barrel_bunny_AI : public ScriptedAI
    {
        npc_beer_barrel_bunny_AI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        void InitializeAI()
        {
            if (!me->isDead())
                Reset();
        }

        void Reset()
        {
            me->AddAura(SPELL_GUSHING_BREW_A, me);
        }

        void UpdateAI(const uint32 diff) { }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_beer_barrel_bunny_AI(creature);
    }
};

// Ancestral Brewmaster 59075.
class npc_ancestral_brewmaster : public CreatureScript
{
public:
    npc_ancestral_brewmaster() : CreatureScript("npc_ancestral_brewmaster") { }

    struct npc_ancestral_brewmaster_AI : public ScriptedAI
    {
        npc_ancestral_brewmaster_AI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;
        bool said, alone, hasTwo, hasThree;

        void InitializeAI()
        {
           // if (!me->IsDead())
            //    Reset();
        }

        void Reset()
        {
            events.Reset();
            me->SetReactState(REACT_PASSIVE);
            me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE));
            said = false;
            hasTwo = me->FindNearestCreature(NPC_ANCESTRAL_BREWMASTER_2, 4.0f, true) ? true : false;
            hasThree = (hasTwo && me->FindNearestCreature(NPC_ANCESTRAL_BREWMASTER_3, 4.0f, true)) ? true : false;
            alone = (!hasTwo && !hasThree) ? true : false;
        }

        void UpdateAI(const uint32 diff)
        {
            // Check stuff for the Brewmasters after Hoptallus.
            if (!said && hasTwo && instance->GetData(DATA_HOPTALLUS_EVENT) == DONE)
            {
               // if (me->FindNearestPlayer(20.0f, true))
                {
                    if (Creature* Alemental = me->FindNearestCreature(NPC_BLOATED_BREW_ALEMENTAL, 20.0f, true))
                    {
                        if (Alemental->IsInCombat())
                        {
                            events.ScheduleEvent(EVENT_SPEAK_HOPTALLUS_1, 2000);
                            said = true;
                        }
                    }
                }
            }

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_SPEAK_HOPTALLUS_1:
                    Talk(SAY_ABM_HOPTALLUS_1);
                    //me->HandleEmote(EMOTE_ONESHOT_QUESTION);
                    events.ScheduleEvent(EVENT_SPEAK_HOPTALLUS_2, 8000);
                    break;

                case EVENT_SPEAK_HOPTALLUS_2:
                    if (Creature* brewMaster2 = me->FindNearestCreature(NPC_ANCESTRAL_BREWMASTER_2, 5.0f, true))
                    {
                        brewMaster2->AI()->Talk(SAY_ABM_HOPTALLUS_2);
                       // brewMaster2->HandleEmote(EMOTE_ONESHOT_EXCLAMATION);
                    }
                    break;

                case EVENT_SPEAK_RANDOM:
                    break;

                default: break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_ancestral_brewmaster_AI(creature);
    }
};

void AddSC_stormstout_brewery()
{
    new npc_leaking_beer_barrel();
    new spell_stormstout_brewery_habanero_beer();
    new npc_beer_barrel_bunny();
    new npc_ancestral_brewmaster();
}
