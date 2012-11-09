/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
#include "ScriptPCH.h"
#include "halls_of_origination.h"

class OrientationCheck : public std::unary_function<Unit*, bool>
{
    public:
        explicit OrientationCheck(Unit* _caster) : caster(_caster) { }
        bool operator() (Unit* unit)
        {
            return !unit->isInFront(caster, 40.0f);
        }

    private:
        Unit* caster;
};

enum Texts
{
    SAY_AGGRO         = 0,
    SAY_SUPERNOVA     = 1,
    SAY_KILL_1        = 2,
    SAY_KILL_2        = 3,
    SAY_DEATH_1       = 4,
    SAY_DEATH_2       = 5,
};

enum Spells
{
    SPELL_SUPERNOVA             = 74136,
    SPELL_ASTRAL_RAIN           = 74370,
    SPELL_CELESTIAL_CALL_P1     = 74362,
    SPELL_CELESTIAL_CALL_P2     = 74355,
    SPELL_CELESTIAL_CALL_P3     = 74364,
    SPELL_VEIL_OF_SKY_P1        = 74133,
    SPELL_VEIL_OF_SKY_P2        = 74372,
    SPELL_VEIL_OF_SKY_P3        = 74373,
};

class boss_isiset : public CreatureScript
{
    public:
        boss_isiset() : CreatureScript("boss_isiset") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_isisetAI(creature);
        }

        struct boss_isisetAI : public ScriptedAI
        {
            boss_isisetAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
                SetCombatMovement(true);
            }

            std::list<uint64> SummonList;

            InstanceScript* instance;

            uint32 SupernovaTimer;
            uint32 AstralRainTimer;
            uint32 CelestialCallPhase3Timer;
            uint32 CelestialCallPhase2Timer;
            uint32 CelestialCallPhase1Timer;
            uint32 VeilOfSkyPhase3Timer;
            uint32 VeilOfSkyPhase2Timer;
            uint32 VeilOfSkyPhase1Timer;
            uint32 Phase;
            bool Phased;

            bool AstralRain, VeilOfSky, CelestialCall;

            void EnterCombat(Unit *who)
            {
                //Talk(SAY_AGGRO, 0, 0);
            }

            void KilledUnit(Unit* victim)
            {
                //Talk(RAND(SAY_KILL_1, SAY_KILL_2));
            }

            void JustDied(Unit* Killer)
            {
                //Talk(RAND(SAY_DEATH_1, SAY_DEATH_2));
            }

            void Reset()
            {
                RemoveSummons();
                SupernovaTimer = 15000+rand()%5000;
                AstralRainTimer = 10000;
                CelestialCallPhase3Timer = 25000;
                CelestialCallPhase2Timer = 25000;
                CelestialCallPhase1Timer = 25000;
                VeilOfSkyPhase3Timer = 20000;
                VeilOfSkyPhase2Timer = 20000;
                VeilOfSkyPhase1Timer = 20000;
                Phased = false;
                AstralRain = true;
                VeilOfSky = true;
                CelestialCall = true;
                Phase = 0;
            }

            void SummonedCreatureDespawn(Creature* summon)
            {
                switch (summon->GetEntry())
                {
                    case 39720: // Astral Rain
                        AstralRain = false;
                        break;
                    case 39721: // Celestial Call
                        CelestialCall = false;
                        break;
                    case 39722: // Veil of Sky
                        VeilOfSky = false;
                        break;
                }
                RemoveSummons();
            }

            void RemoveSummons()
            {
                if (SummonList.empty())
                    return;

                for (std::list<uint64>::const_iterator itr = SummonList.begin(); itr != SummonList.end(); ++itr)
                {
                    if (Creature* temp = Unit::GetCreature(*me, *itr))
                        if (temp)
                            temp->DisappearAndDie();
                }
                SummonList.clear();
            }

            void JustSummoned(Creature* summon)
            {
                SummonList.push_back(summon->GetGUID());
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if ((me->GetHealth() * 100 / me->GetMaxHealth() <= 66) && Phase == 0)
                {
                    Phase = 1;
                    Phased = true;
                    Position pos;
                    me->GetPosition(&pos);
                    me->SummonCreature(39720, pos, TEMPSUMMON_CORPSE_DESPAWN, 1000);
                    me->SummonCreature(39721, pos, TEMPSUMMON_CORPSE_DESPAWN, 1000);
                    me->SummonCreature(39722, pos, TEMPSUMMON_CORPSE_DESPAWN, 1000);
                }

                if ((me->GetHealth() * 100 / me->GetMaxHealth() <= 33) && Phase == 1)
                {
                    Phase = 2;
                    Phased = true;
                    Position pos;
                    me->GetPosition(&pos);
                    if (AstralRain == true)
                        me->SummonCreature(39720, pos, TEMPSUMMON_CORPSE_DESPAWN, 1000);
                    if (CelestialCall == true)
                        me->SummonCreature(39721, pos, TEMPSUMMON_CORPSE_DESPAWN, 1000);
                    if (VeilOfSky == true)
                        me->SummonCreature(39722, pos, TEMPSUMMON_CORPSE_DESPAWN, 1000);
                }

                if (Phase == 0)
                {
                    if (CelestialCallPhase1Timer <= diff && Phased == false && CelestialCall == true)
                    {
                        DoCast(me, SPELL_CELESTIAL_CALL_P1);
                        CelestialCallPhase1Timer = 45000;
                    }
                    else CelestialCallPhase1Timer -= diff;

                    if (VeilOfSkyPhase1Timer <= diff && Phased == false && VeilOfSky == true)
                    {
                        DoCast(me, SPELL_VEIL_OF_SKY_P1);
                        VeilOfSkyPhase1Timer = 45000;
                    }
                    else VeilOfSkyPhase1Timer -= diff;
                }

                if (Phase == 1)
                {
                    if (CelestialCallPhase2Timer <= diff && Phased == false && CelestialCall == true)
                    {
                        DoCast(me, SPELL_CELESTIAL_CALL_P2);
                        CelestialCallPhase2Timer = 45000;
                    }
                    else CelestialCallPhase2Timer -= diff;

                    if (VeilOfSkyPhase2Timer <= diff && Phased == false && VeilOfSky == true)
                    {
                        DoCast(me, SPELL_VEIL_OF_SKY_P2);
                        VeilOfSkyPhase2Timer = 45000;
                    }
                    else VeilOfSkyPhase2Timer -= diff;
                }

                if (Phase == 2)
                {
                    if (CelestialCallPhase3Timer <= diff && Phased == false && CelestialCall == true)
                    {
                        DoCast(me, SPELL_CELESTIAL_CALL_P3);
                        CelestialCallPhase3Timer = 45000;
                    }
                    else CelestialCallPhase3Timer -= diff;

                    if (VeilOfSkyPhase3Timer <= diff && Phased == false && VeilOfSky == true)
                    {
                        DoCast(me, SPELL_VEIL_OF_SKY_P3);
                        VeilOfSkyPhase3Timer = 45000;
                    }
                    else VeilOfSkyPhase3Timer -= diff;
                }

                if (SupernovaTimer <= diff && Phased == false)
                {
                    //Talk(SAY_SUPERNOVA);
                    DoCast(me->getVictim(), SPELL_SUPERNOVA);
                    SupernovaTimer = 15000+rand()%5000;
                }
                else SupernovaTimer -= diff;

                if (AstralRainTimer <= diff && Phased == false && CelestialCall == true)
                {
                    DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true), SPELL_ASTRAL_RAIN);
                    AstralRainTimer = 10000;
                }
                else AstralRainTimer -= diff;

                DoMeleeAttackIfReady();
            }
        };
};

class spell_isiset_supernova : public SpellScriptLoader
{
    public:
        spell_isiset_supernova() : SpellScriptLoader("spell_isiset_supernova") { }
        class spell_isiset_supernova_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_isiset_supernova_SpellScript);
            void FilterTargets(std::list<Unit*>& unitList)
            {
                unitList.remove_if(OrientationCheck(GetCaster()));
            }

            void Register()
            {
                //OnUnitTargetSelect += SpellUnitTargetFn(spell_isiset_supernova_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_AREA_ENEMY_SRC);
                //OnUnitTargetSelect += SpellUnitTargetFn(spell_isiset_supernova_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_AREA_ENEMY_SRC);
            }
        };

        SpellScript *GetSpellScript() const
        {
            return new spell_isiset_supernova_SpellScript();
        }
};

void AddSC_boss_isiset()
{
    new boss_isiset();
    new spell_isiset_supernova();
}