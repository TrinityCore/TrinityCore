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
#include "ulduar.h"

enum Yells
{
    // Sara
    SAY_SARA_PREFIGHT_1                         = -1603310,
    SAY_SARA_PREFIGHT_2                         = -1603311,
    SAY_SARA_AGGRO_1                            = -1603312,
    SAY_SARA_AGGRO_2                            = -1603313,
    SAY_SARA_AGGRO_3                            = -1603314,
    SAY_SARA_SLAY_1                             = -1603315,
    SAY_SARA_SLAY_2                             = -1603316,
    WHISP_SARA_INSANITY                         = -1603317,
    SAY_SARA_PHASE2_1                           = -1603318,
    SAY_SARA_PHASE2_2                           = -1603319,

    // Yogg-Saron
    SAY_PHASE2_1                                = -1603330,
    SAY_PHASE2_2                                = -1603331,
    SAY_PHASE2_3                                = -1603332,
    SAY_PHASE2_4                                = -1603333,
    SAY_PHASE2_5                                = -1603334,
    SAY_PHASE3                                  = -1603335,
    SAY_VISION                                  = -1603336,
    SAY_SLAY_1                                  = -1603337,
    SAY_SLAY_2                                  = -1603338,
    WHISP_INSANITY_1                            = -1603339,
    WHISP_INSANITY_2                            = -1603340,
    SAY_DEATH                                   = -1603341,
};

enum Spells
{
    // ============ needs more info ============ //
    SPELL_SANITY_PERIODIC                   = 63786,  // periodic
    SPELL_SANITY                            = 63050,  // debuff
    SPELL_ILLUSION_ROOM                     = 63988,
    SPELL_CANCEL_ILLUSION_ROOM_AURA         = 63993,
    SPELL_TELEPORT_BACK_TO_MAIN_ROOM        = 63992,
    SPELL_DEATH_RAY_ORIGIN_VISUAL           = 63893,
    SPELL_INSANE_PERIODIC                   = 64554,  // periodic
    SPELL_INSANE_PERIODIC_2                 = 64555,  // triggered by SPELL_INSANE_PERIODIC
    SPELL_CLEAR_INSANE                      = 63122,
    SPELL_INSANE                            = 63120,  // mind control
    SPELL_INSANE_VISUAL                     = 64464,
    SPELL_SHATTERED_ILLUSION_2              = 65238,

    // Sara / Yogg-Saron
    SPELL_SUMMON_OMINOUS_CLOUD              = 60987,
    SPELL_PHASE_3_TRANSFORM                 = 63895,
    SPELL_IMMORTAL_GUARDIAN                 = 64158,
    SPELL_SHATTERED_ILLUSION                = 64173,

    // Illusions / Tentacles
    SPELL_REVEALED_TENTACLE                 = 64012,

    // Ominous Cloud
    SPELL_OMINOUS_CLOUD                     = 60977,  // periodic, one of visual effects
    SPELL_OMINOUS_CLOUD_2                   = 60978,  // triggered by SPELL_OMINOUS_CLOUD, one of visual effects
    SPELL_OMINOUS_CLOUD_3                   = 60984,  // periodic
    SPELL_DARK_LIGHTNING                    = 60985,  // triggered by SPELL_OMINOUS_CLOUD_3, damage
    SPELL_SUMMON_GUARDIAN_1                 = 63031,  // periodic
    SPELL_SUMMON_GUARDIAN_2                 = 62978,  // periodic
    SPELL_SUMMON_GUARDIAN_3                 = 62979,  // triggered by 2 spells above (and when player touches the Cloud)
    // ========================================= //

    // Sara
    SPELL_SARAS_FERVOR                      = 63138,
    //SPELL_SARAS_FERVOR_2                    = 63747,
    SPELL_SARAS_BLESSING                    = 63134,
    //SPELL_SARAS_BLESSING_2                  = 63745,
    SPELL_SARAS_ANGER                       = 63147,
    //SPELL_SARAS_ANGER_2                     = 63744,
    SPELL_PSYCHOSIS                         = 65301,
    //SPELL_PSYCHOSIS_H                       = 63795,
    SPELL_MALADY_OF_THE_MIND                = 63830,
    SPELL_MALADY_OF_THE_MIND_JUMP           = 63881,
    SPELL_BRAIN_LINK                        = 63802,
    SPELL_BRAIN_LINK_DAMAGE                 = 63803,  // red beam
    SPELL_BRAIN_LINK_NO_DAMAGE              = 63804,  // yellow beam
    SPELL_DEATH_RAY                         = 63891,
    SPELL_SHADOWY_BARRIER_SARA              = 64775,

    // Ominous Cloud
    SPELL_OMINOUS_CLOUD_VISUAL              = 63084,

    // Guardian of Yogg-Saron
    SPELL_DARK_VOLLEY                       = 63038,
    SPELL_SHADOW_NOVA                       = 62714,
    //SPELL_SHADOW_NOVA_H                     = 65209,
    //SPELL_SHADOW_NOVA_3                     = 65719,

    // Yogg-Saron
    SPELL_EXTINGUISH_ALL_LIFE               = 64166,
    SPELL_DEAFENING_ROAR                    = 64189,
    SPELL_LUNATIC_GAZE                      = 64163,
    //SPELL_LUNATIC_GAZE_DAMAGE               = 64164,
    SPELL_SHADOWY_BARRIER_YOGG              = 63894,
    SPELL_SHADOW_BEACON                     = 64465,
    //SPELL_EMPOWERING_SHADOWS_MISSILE        = 64466,  // triggered by SPELL_SHADOW_BEACON

    // Brain of Yogg-Saron
    SPELL_INDUCE_MADNESS                    = 64059,
    SPELL_BRAIN_HURT_VISUAL                 = 64361,

    // Tentacles (Crusher Tentacle & Corruptor Tentacle only?)
    SPELL_ERUPT                             = 64144,

    // Crusher Tentacle
    SPELL_DIMINISH_POWER                    = 64145,
    SPELL_FOCUSED_ANGER                     = 57688,  // aura
    //SPELL_FOCUSED_ANGER_2                   = 57689,  // triggered by SPELL_FOCUSED_ANGER

    // Constrictor Tentacle
    SPELL_SQUEEZE                           = 64125,
    //SPELL_SQUEEZE_H                         = 64126,

    // Corruptor Tentacle
    SPELL_APATHY                            = 64156,
    SPELL_BLACK_PLAGUE                      = 64153,  // periodic
    //SPELL_BLACK_PLAGUE_STUN                 = 64155,  // triggered
    SPELL_CURSE_OF_DOOM                     = 64157,
    SPELL_DRAINING_POISON                   = 64152,

    // Immortal Guardian
    //SPELL_EMPOWERING_SHADOWS_VISUAL         = 64467,  //? triggered by SPELL_EMPOWERING_SHADOWS_MISSILE on impact, visual? CHECK IT
    SPELL_EMPOWERING_SHADOWS                = 64468,
    //SPELL_EMPOWERING_SHADOWS_H              = 64486,
    SPELL_EMPOWERED                         = 65294,  // buff
    //SPELL_EMPOWERED_2                       = 64161,  //? applies SPELL_EMPOWERED
    SPELL_WEAKENED                          = 64162,  //? triggered by SPELL_TITANIC_STORM_2 on impact
    SPELL_DRAIN_LIFE                        = 64159,
    //SPELL_DRAIN_LIFE_H                      = 64160,

    // Keepers
    SPELL_KEEPER_ACTIVE                     = 62647,

    // Mimiron
    SPELL_SPEED_OF_INVENTION                = 62671,
    SPELL_DESTABILIZATION_MATRIX            = 65210,  //? triggered by SPELL_DESTABILIZATION_MATRIX_2
    //SPELL_DESTABILIZATION_MATRIX_2          = 65206,

    // Freya
    SPELL_RESILIENCE_OF_NATURE              = 62670,
    SPELL_SANITY_WELL_SUMMON                = 64170,  // visual only?

    // Sanity Well
    SPELL_SANITY_WELL_VISUAL                = 63288,  // visual
    SPELL_SANITY_WELL                       = 64169,  // damage reduction

    // Thorim
    SPELL_FURY_OF_THE_STORM                 = 62702,
    SPELL_TITANIC_STORM                     = 64171,  // periodic
    //SPELL_TITANIC_STORM_2                   = 64172,  // triggered by SPELL_TITANIC_STORM

    // Hodir
    SPELL_FORTITUDE_OF_FROST                = 62650,
    SPELL_HODIRS_PROTECTIVE_GAZE            = 64174,
    //SPELL_FLASH_FREEZE                      = 64175,  // freeze players instead of dying

    // Death Orb
    SPELL_DEATH_RAY_WARNING_VISUAL          = 63882,
    SPELL_DEATH_RAY_PERIODIC                = 63883,
    //SPELL_DEATH_RAY_DAMAGE                  = 63884,  // triggered by SPELL_DEATH_RAY_PERIODIC
    SPELL_DEATH_RAY_DAMAGE_VISUAL           = 63886,

    // Laughing Skull
    SPELL_LUNATIC_GAZE_SKULL                = 64167,  // periodic
    //SPELL_LUNATIC_GAZE_SKULL_DAMAGE         = 64168,  // triggered

    // Descend Into Madness
    SPELL_TELEPORT_TO_STORMWIND_ILLUSION    = 63989,
    SPELL_TELEPORT_TO_CHAMBER_ILLUSION      = 63997,
    SPELL_TELEPORT_TO_ICECROWN_ILLUSION     = 63998,

    // Suit of Armor
    SPELL_NONDESCRIPT_1                     = 64013,

    // Dragon Consorts & Deathsworn Zealot
    SPELL_NONDESCTIPT_2                     = 64010,
};

enum 
{
    ACHIEV_TIMED_START_EVENT                      = 21001,
};

class boss_sara : public CreatureScript
{
    public:
        boss_sara() : CreatureScript("boss_sara") { }

        struct boss_saraAI : public ScriptedAI
        {
            boss_saraAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset()
            {
                
            }

            void UpdateAI(uint32 const /*diff*/)
            {
                
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_saraAI(creature);
        }
};

class boss_yoggsaron : public CreatureScript
{
    public:
        boss_yoggsaron() : CreatureScript("boss_yoggsaron") { }

        struct boss_yoggsaronAI : public BossAI
        {
            boss_yoggsaronAI(Creature* creature) : BossAI(creature, BOSS_YOGGSARON)
            {
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetUlduarAI<boss_yoggsaronAI>(creature);
        }
};

class npc_guardian_of_yoggsaron : public CreatureScript
{
    public:
        npc_guardian_of_yoggsaron() : CreatureScript("npc_guardian_of_yoggsaron") { }

        struct npc_guardian_of_yoggsaronAI : public ScriptedAI
        {
            npc_guardian_of_yoggsaronAI(Creature* creature) : ScriptedAI(creature) { }

            void JustDied(Unit* /*killer*/)
            {
                DoCastAOE(SPELL_SHADOW_NOVA);
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_guardian_of_yoggsaronAI(creature);
        }
};

class spell_yoggsaron_malady_of_the_mind : public SpellScriptLoader
{
    public:
        spell_yoggsaron_malady_of_the_mind() : SpellScriptLoader("spell_yoggsaron_malady_of_the_mind") { }

        class spell_yoggsaron_malady_of_the_mind_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_yoggsaron_malady_of_the_mind_AuraScript);

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                switch (GetTargetApplication()->GetRemoveMode())
                {
                    case AURA_REMOVE_BY_ENEMY_SPELL:
                    case AURA_REMOVE_BY_EXPIRE:
                    case AURA_REMOVE_BY_DEATH:
                        break;
                    default:
                        return;
                }

                GetTarget()->CastSpell(GetTarget(), SPELL_MALADY_OF_THE_MIND_JUMP);
            }

            void Register()
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_yoggsaron_malady_of_the_mind_AuraScript::OnRemove, EFFECT_1, SPELL_AURA_MOD_FEAR, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_yoggsaron_malady_of_the_mind_AuraScript();
        }
};

class spell_yoggsaron_brain_link : public SpellScriptLoader
{
    public:
        spell_yoggsaron_brain_link() :  SpellScriptLoader("spell_yoggsaron_brain_link") { }

        class spell_yoggsaron_brain_link_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_yoggsaron_brain_link_AuraScript);

            void OnPeriodic(AuraEffect const* /*aurEff*/)
            {
                // search for second player with Brain Link aura
                if (Map* map = GetTarget()->GetMap())
                {
                    if (map->IsDungeon())
                    {
                        Map::PlayerList const& players = map->GetPlayers();

                        for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                        {
                            Player* plr = itr->getSource();

                            if (plr->HasAura(SPELL_BRAIN_LINK) && plr != GetTarget()->ToPlayer())
                            {
                                if (GetTarget()->GetDistance(plr) > 20.0f)
                                    GetTarget()->CastSpell(plr, SPELL_BRAIN_LINK_DAMAGE);
                                else
                                    GetTarget()->CastSpell(plr, SPELL_BRAIN_LINK_NO_DAMAGE);

                                break;
                            }
                        }
                    }
                }
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_yoggsaron_brain_link_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_yoggsaron_brain_link_AuraScript();
        }
};

void AddSC_boss_yoggsaron()
{
    new boss_sara();
    new boss_yoggsaron();
    new npc_guardian_of_yoggsaron();
    new spell_yoggsaron_brain_link();
    new spell_yoggsaron_malady_of_the_mind();
}
