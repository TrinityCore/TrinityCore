/*
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

/* ScriptData
SDName: Yogg-Saron
SDAuthor: PrinceCreed
SD%Complete: 90
SDComments: Hodir's Protective Gaze and Mimiron's Destabilization Matrix don't work.
EndScriptData */

#include "ScriptMgr.h"
#include "ulduar.h"

enum Sara_Yells
{
    SAY_SARA_PREFIGHT_1                         = -1603310,
    SAY_SARA_PREFIGHT_2                         = -1603311,
    SAY_SARA_AGGRO_1                            = -1603312,
    SAY_SARA_AGGRO_2                            = -1603313,
    SAY_SARA_AGGRO_3                            = -1603314,
    SAY_SARA_SLAY_1                             = -1603315,
    SAY_SARA_SLAY_2                             = -1603316,
    WHISP_SARA_INSANITY                         = -1603317,
    SAY_SARA_PHASE2_1                           = -1603318,
    SAY_SARA_PHASE2_2                           = -1603319
};

enum YoggSaron_Yells
{
    SAY_PHASE2_1                                = -1603330,
    SAY_PHASE2_2                                = -1603331,
    SAY_PHASE2_3                                = -1603332,
    SAY_PHASE2_4                                = -1603333,
    SAY_PHASE2_5                                = -1603334,
    SAY_PHASE3                                  = -1603335,
    SAY_VISION                                  = -1603336,
    SAY_LUNATIC_GAZE                            = -1603337,
    SAY_DEAFENING_ROAR                          = -1603338,
    WHISP_INSANITY_1                            = -1603339,
    WHISP_INSANITY_2                            = -1603340,
    SAY_DEATH                                   = -1603341,
    EMOTE_PORTALS                               = -1603342,
    EMOTE_OPEN_CHAMBER                          = -1603343,
    EMOTE_EMPOWERING                            = -1603344
};

enum Achievements
{
    ACHIEV_TIMED_START_EVENT                    = 21001,
};

#define GOSSIP_KEEPER_HELP                      "I need your help."

enum Keepers_Yells
{
    SAY_MIMIRON_HELP                            = -1603259,
    SAY_FREYA_HELP                              = -1603189,
    SAY_THORIM_HELP                             = -1603287,
    SAY_HODIR_HELP                              = -1603217,
};

enum Phases
{
    PHASE_NULL = 0,
    PHASE_1,
    PHASE_2,
    PHASE_3
};

Phases phase;

enum Npcs
{
    NPC_IMAGE_OF_FREYA                          = 33241,
    NPC_IMAGE_OF_THORIM                         = 33242,
    NPC_IMAGE_OF_MIMIRON                        = 33244,
    NPC_IMAGE_OF_HODIR                          = 33213,
    
    NPC_SANITY_WELL                             = 33991,
    NPC_SARA                                    = 33134,
    NPC_YOGG_SARON                              = 33288,
    NPC_YOGG_SARON_VOICE                        = 33280,
    
    NPC_GUARDIAN_OF_YOGGSARON                   = 33136,
    NPC_OMINOUS_CLOUD                           = 33292,
    NPC_DEATH_ORB                               = 33882,
    NPC_CRUSHER_TENTACLE                        = 33966,
    NPC_CONSTRICTOR_TENTACLE                    = 33983,
    NPC_CORRUPTOR_TENTACLE                      = 33985,
    
    NPC_PORTAL_STORMWIND                        = 34072,
    NPC_PORTAL_CHAMBER                          = 34122,
    NPC_PORTAL_ICECROWN                         = 34123,

    NPC_LAUGHING_SKULL                          = 33990,
    NPC_INFLUENCE_TENTACLE                      = 33943,
    NPC_IMMORTAL_GUARDIAN                       = 33988,

    NPC_YOGG_SARON_BRAIN                        = 33890,
    NPC_SUIT_OF_ARMOR                           = 33433,
    NPC_RUBY_CONSORT                            = 33716,
    NPC_AZURE_CONSORT                           = 33717,
    NPC_EMERALD_CONSORT                         = 33719,
    NPC_OBSIDIAN_CONSORT                        = 33720,
    NPC_DEATHSWORN_ZEALOT                       = 33567,
    
    GOB_CHAMBER_DOOR                            = 194635,
    GOB_ICECROWN_DOOR                           = 194636,
    GOB_STORMWIND_DOOR                          = 194637
};

enum Spells
{
    // Sara
    SPELL_SARA_ANGER                            = 63147,
    SPELL_SARA_BLESSING                         = 63134,
    SPELL_SARA_FERVOR                           = 63138,
    SPELL_SHADOWY_BARRIED                       = 64775,
    SPELL_BRAIN_LINK                            = 63802,
    SPELL_DEATH_RAY_DAMAGE                      = 63883,
    SPELL_DEATH_RAY_DAMAGE_VISUAL               = 63886,
    SPELL_DEATH_RAY_WARNING_VISUAL              = 63882,
    SPELL_PSYCHOSIS                             = 63795,
    SPELL_MALADY_OF_THE_MIND                    = 63830,
    
    // Guardian of Yogg Saron
    SPELL_SUMMON_GUARDIAN                       = 63031,
    SPELL_INSTANT_SUMMON_GUARDIAN               = 62979,
    SPELL_OMINOUS_CLOUD                         = 60984,
    SPELL_OMINOUS_CLOUD_VISUAL                  = 63084,
    SPELL_DARK_VOLLEY                           = 63038,
    SPELL_SHADOW_NOVA_10                        = 62714,
    SPELL_SHADOW_NOVA_25                        = 65209,
    
    // Yogg Saron
    SPELL_SANITY                                = 63050,
    SPELL_INSANE                                = 63120,
    SPELL_YOGG_SARON_TRANSFORMATION             = 63895,
    SPELL_CRUSHER_TENTACLE_SUMMON               = 64139,
    SPELL_CORRUPTOR_TENTACLE_SUMMON             = 64143,
    SPELL_CONSTRICTOR_TENTACLE_SUMMON           = 64133,
    SPELL_IMMORTAL_GUARDIAN_SUMMON              = 64158,
    SPELL_SHADOWY_BARRIER_LARGE                 = 63894,
    
    // Tentacles
    SPELL_ERUPT                                 = 64144,
    
    // Crusher Tentacle
    SPELL_DIMINISH_POWER                        = 64145,
    SPELL_FOCUSED_ANGER                         = 57688,
    
    // Corruptor Tentacle
    SPELL_APATHY                                = 64156,
    SPELL_BLACK_PLAGUE                          = 64153,
    SPELL_CURSE_OF_DOOM                         = 64157,
    SPELL_DRAINING_POISON                       = 64152,
    
    // Constrictor Tentacle
    SPELL_SQUEEZE_10                            = 64125,
    SPELL_SQUEEZE_25                            = 64126,
    
    // Influence Tentacle
    SPELL_GRIM_REPRISAL                         = 63305,
    SPELL_TENTACLE_VOID_ZONE                    = 64384,
    
    // Brain of Yogg Saron
    SPELL_INDUCE_MADNESS                        = 64059,
    SPELL_SHATTERED_ILLUSION                    = 64173,
    SPELL_BRAIN_HURT                            = 64361,
    SPELL_ILLUSION_ROOM                         = 63988,
    
    // Laughing skull
    SPELL_LUNATIC_GAZE                          = 64167,
    
    // Yogg Saron
    SPELL_LUNATIC_GAZE_P3                       = 64163,
    SPELL_SHADOW_BEACON                         = 64465,
    SPELL_DEAFENING_ROAR                        = 64189,
    SPELL_EXTINGUISH_ALL_LIFE                   = 64166,
    SPELL_EMPOWERING_SHADOWS                    = 64468,
    SPELL_MAWS_OF_THE_OLD_GOD                   = 64184,
    
    // Immortal Guardian
    SPELL_EMPOWERED                             = 65294,
    SPELL_DRAIN_LIFE_10                         = 64159,
    SPELL_DRAIN_LIFE_25                         = 64160
};

enum Keepers_Spells
{
    SPELL_KEEPER_ACTIVE                         = 62647,
    
    // Freya
    SPELL_RESILIENCE_OF_NATURE                  = 62670,
    SPELL_SANITY_WELL_SPAWN                     = 64170,
    SPELL_SANITY_WELL_VISUAL                    = 63288,
    SPELL_SANITY_WELL                           = 64169,
    
    // Thorim
    SPELL_FURY_OF_THE_STORMS                    = 62702,
    SPELL_TITANIC_STORM                         = 64171,
    SPELL_TITANIC_STORM_EFFECT                  = 64172,
    SPELL_WEAKENED                              = 64162,
    
    // Mimiron
    SPELL_SPEED_OF_INVENTION                    = 62671,
    SPELL_DESTABILIZATION                       = 65210,
    
    // Hodir
    SPELL_FORTITUDE_OF_FROST                    = 62650,
    SPELL_PROTECTIVE_GAZE                       = 64174
};

enum Events
{
    EVENT_NONE,
    EVENT_BERSERK,
    EVENT_FERVOR,
    EVENT_BLESSING,
    EVENT_ANGER,
    EVENT_SUMMON_GUARDIAN,
    EVENT_PSYCHOSIS,
    EVENT_MALADY_OF_THE_MIND,
    EVENT_BRAIN_LINK,
    EVENT_DEATH_RAY,
    EVENT_ILLUSION,
    EVENT_TENTACLES,
    EVENT_LUNATIC_GAZE,
    EVENT_SHADOW_BEACON,
    EVENT_IMMORTAL_GUARDIAN,
    EVENT_DEAFENING_ROAR
};

enum Actions
{
    ACTION_CHAMBER_ILLUSION,
    ACTION_ICECROWN_ILLUSION,
    ACTION_STORMWIND_ILLUSION,
    ACTION_TENTACLE_COUNT,
    ACTION_YOGGSARON_PHASE_3
};

struct SummonLocation
{
    float x,y,z,o;
    uint32 entry;
};

SummonLocation stormwindLocations[]=
{
    // Stormwind Illusion
    {1931.05f, 38.86f, 239.667f, 1.70f, 33433}, // Suit of Armor
    {1909.03f, 44.80f, 239.667f, 0.94f, 33433},
    {1897.92f, 64.40f, 239.667f, 0.17f, 33433},
    {1903.98f, 86.29f, 239.667f, 5.61f, 33433},
    {1923.45f, 97.54f, 239.667f, 4.83f, 33433},
    {1945.17f, 91.73f, 239.667f, 4.07f, 33433},
    {1956.38f, 72.04f, 239.667f, 3.27f, 33433},
    {1950.47f, 50.35f, 239.667f, 2.48f, 33433},
    {1928.65f, 65.71f, 242.376f, 2.09f, 33436}, // Garona
    {1927.21f, 68.26f, 242.376f, 5.22f, 33437}, // King Llane
    {1915.97f, 26.83f, 239.667f, 1.30f, 33990}, // Laughing Skull
    {1901.90f, 74.99f, 239.667f, 6.02f, 33990},
    {1969.02f, 57.13f, 239.667f, 2.87f, 33990},
    {1933.89f, 93.48f, 239.667f, 4.44f, 33990}
};

SummonLocation chamberLocations[]=
{
    // Chamber of the Aspects Illusion
    {2068.97f, -7.30f, 239.760f, 5.85f, 33716}, // Dragons
    {2070.18f,-45.92f, 239.720f, 0.43f, 33716},
    {2113.69f,-65.53f, 239.720f, 1.82f, 33717},
    {2139.57f,-51.13f, 239.750f, 2.40f, 33717},
    {2146.88f,-33.45f, 239.720f, 3.14f, 33720},
    {2146.88f,-16.41f, 239.740f, 3.14f, 33720},
    {2137.49f, -0.26f, 239.720f, 3.83f, 33719},
    {2109.89f, 15.72f, 239.760f, 4.54f, 33719},
    {2064.12f,-58.09f, 239.720f, 0.64f, 33990}, // Laughing Skull
    {2062.18f, 10.04f, 239.803f, 5.51f, 33990},
    {2129.46f, 20.66f, 239.720f, 4.14f, 33990},
    {2130.60f,-68.93f, 239.720f, 2.09f, 33990},
    {2091.82f,-25.39f, 242.647f,  0.0f, 33536}, // Alexstrasza
    {2108.34f,-37.05f, 242.647f, 1.96f, 33535}, // Malygos
    {2109.43f,-14.25f, 242.647f, 4.29f, 33495}, // Ysera
    {2117.95f,-25.46f, 242.647f, 3.14f, 33523}  // Neltharion
};

SummonLocation icecrownLocations[]=
{
    // Icecrown Illusion
    {1955.67f,-133.19f, 240.0f, 5.75f, 33567}, // Deathsworn Zealot
    {1958.09f,-140.64f, 240.0f, 5.75f, 33567},
    {1950.62f,-141.74f, 240.0f, 5.75f, 33567},
    {1897.75f, -99.84f, 240.0f, 2.62f, 33567},
    {1892.86f,-108.44f, 240.0f, 2.62f, 33567},
    {1890.07f,-100.78f, 240.0f, 2.62f, 33567},
    {1910.01f,-137.30f, 240.0f, 4.17f, 33567},
    {1918.60f,-142.42f, 240.0f, 4.17f, 33567},
    {1972.79f,-149.09f, 240.0f, 2.62f, 33990}, // Laughing Skull
    {1941.27f,-169.01f, 240.0f, 1.04f, 33990},
    {1877.66f, -94.06f, 240.0f, 5.78f, 33990},
    {1873.27f,-129.11f, 240.0f, 1.04f, 33990},
    {1907.81f,-152.84f, 240.0f, 4.17f, 33441}, // The Lich King
    {1905.19f,-157.67f, 240.0f, 1.04f, 33442}  // Immolated Champion
};

const Position DeathRayPos[12] =
{
    {1934.73f,-25.43f,327.82f,0},
    {1974.43f,-72.74f,329.10f,0},
    {2016.19f,-16.32f,326.93f,0},
    {1961.54f,  9.78f,327.55f,0},
    {1955.90f,-54.43f,326.33f,0},
    {2011.09f,-54.67f,327.90f,0},
    {2003.48f, -0.03f,326.40f,0},
    {1954.04f,  4.59f,327.63f,0},
    {1943.14f, -5.17f,327.41f,0},
    {1943.72f,-48.29f,327.10f,0},
    {1990.30f,-67.09f,328.40f,0},
    {1980.22f, 12.33f,327.44f,0}
};

const Position PortalPos[10] =
{
    {1956.64f,-25.28f,325.17f,0},
    {1986.71f, -2.74f,325.17f,0},
    {2003.67f,-25.73f,325.07f,0},
    {1983.82f,-48.92f,324.70f,0},
    {1961.22f,-12.52f,325.02f,0},
    {1972.70f, -4.15f,324.89f,0},
    {1998.22f,-10.92f,325.11f,0},
    {1998.22f,-40.10f,324.89f,0},
    {1969.66f,-46.10f,324.87f,0},
    {1959.70f,-37.28f,325.11f,0}
};

const Position TentaclesPos[22] =
{
    {1986.53f, 14.69f,328.08f,4.44f},
    {1974.22f, 17.11f,327.86f,4.56f},
    {1956.55f,  0.83f,326.81f,5.19f},
    {1928.61f,-37.30f,327.74f,0.30f},
    {1939.52f,-45.68f,327.14f,0.26f},
    {1953.44f,-62.17f,327.49f,0.85f},
    {1976.65f,-76.02f,328.89f,1.48f},
    {1993.38f,-61.91f,327.60f,1.27f},
    {2016.65f,-52.52f,327.77f,2.70f},
    {2026.97f,-28.09f,327.98f,3.32f},
    {2022.59f,-16.85f,327.59f,3.37f},
    {1938.22f,-10.54f,328.19f,5.99f},
    {1944.06f,-38.17f,326.84f,0.36f},
    {1973.28f,-62.51f,327.32f,1.44f},
    {1999.19f,-57.96f,327.34f,2.04f},
    {2017.89f,-25.34f,327.12f,3.14f},
    {2000.26f,  4.49f,326.98f,4.15f},
    {2006.91f,-13.70f,326.03f,3.80f},
    {2007.72f,  3.27f,327.28f,4.02f},
    {2002.52f, 16.73f,328.80f,4.07f},
    {1974.55f,  9.30f,326.85f,4.65f},
    {1945.29f,-25.78f,327.12f,    0}
};

const Position SanityWellPos[10] =
{
    {2008.38f, 35.41f,331.251f,0},
    {1990.63f, 50.35f,332.041f,0},
    {1973.40f, 41.09f,330.989f,0},
    {1973.12f,-90.27f, 330.14f,0},
    {1994.26f,-96.62f, 330.62f,0},
    {2005.41f,-82.88f, 329.50f,0},
    {2042.09f,-41.70f, 329.12f,0},
    {1918.06f, 16.50f, 330.97f,0},
    {1899.59f, -4.87f,332.137f,0},
    {1897.75f,-48.24f, 332.35f,0}
};



/*------------------------------------------------------*
 *                        Sara                          *
 *------------------------------------------------------*/

class boss_sara : public CreatureScript
{
public:
    boss_sara() : CreatureScript("boss_sara") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_sara_AI (pCreature);
    }

    struct boss_sara_AI : public BossAI
    {
        boss_sara_AI(Creature *pCreature) : BossAI(pCreature, BOSS_YOGGSARON)
        {
            me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_RESILIENCE_OF_NATURE, true);
            me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_FURY_OF_THE_STORMS, true);
            me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_SPEED_OF_INVENTION, true);
            me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_FORTITUDE_OF_FROST, true);
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
            me->SetFlying(true);
            wipe = false;
        }

        std::vector<Creature *> ominous_list;
        uint32 uiPhase_timer;
        uint32 uiStep;
        uint8 keepers;
        bool wipe;
        
        void Reset()
        {
            if (instance)
            {
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SANITY);
                // Reset Keepers
                for (uint8 data = DATA_YS_FREYA; data <= DATA_YS_HODIR; ++data)
                {
                    if (Creature *pCreature = Creature::GetCreature((*me), instance->GetData64(data)))
                    {
                        if (pCreature->HasAura(SPELL_KEEPER_ACTIVE))
                        {
                            pCreature->AI()->EnterEvadeMode();
                            pCreature->AddAura(SPELL_KEEPER_ACTIVE, pCreature);
                        }
                    }
                }
                // Reset Yogg-Saron
                for (uint8 data = DATA_YOGGSARON_BRAIN; data <= DATA_YOGGSARON; ++data)
                {
                    if (Creature *pCreature = Creature::GetCreature((*me), instance->GetData64(data)))
                        pCreature->AI()->EnterEvadeMode();
                }
                Map::PlayerList const &players = instance->instance->GetPlayers();
                for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                {
                    Player* pPlayer = itr->getSource();
                    if (!pPlayer)
                        continue;
                            
                    // Phase One wipe
                    if (wipe && phase == PHASE_1)
                    {
                        if (Creature* pVoice = me->SummonCreature(NPC_YOGG_SARON_VOICE,me->GetPositionX(),me->GetPositionY(),me->GetPositionZ(),0,TEMPSUMMON_TIMED_DESPAWN,1000))
                            DoScriptText(WHISP_SARA_INSANITY, pVoice, pPlayer);
                    }
                    // Kills insane players
                    if (pPlayer->HasAura(SPELL_INSANE))
                        me->Kill(pPlayer, true);                
                }
            }
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_NON_ATTACKABLE);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->SetVisible(true);
            me->RestoreDisplayId();
            me->RestoreFaction();
            me->GetMotionMaster()->MoveTargetedHome();
            phase = PHASE_NULL;
            keepers = 0;
            _Reset();
        }
        
        void JustReachedHome()
        {
            ominous_list.clear();
            for (uint8 n = 0; n < 5; n++)
            {
                Position pos;
                me->GetRandomNearPosition(pos, 50);
                if (Creature* OminousCloud = me->SummonCreature(NPC_OMINOUS_CLOUD, pos))
                    ominous_list.push_back(OminousCloud);
            }
        }
        
        void MoveInLineOfSight(Unit *who)
        {
            if (!me->isInCombat() && me->IsWithinDist(who, 70.0f) && who->ToPlayer() && !who->ToPlayer()->isGameMaster())
            {
                me->setFaction(16);
                DoZoneInCombat();
            }
        }
        
        void EnterCombat(Unit *who)
        {
            DoScriptText(RAND(SAY_SARA_AGGRO_1,SAY_SARA_AGGRO_2,SAY_SARA_AGGRO_3), me);
            // Keepers activation
            if (instance)
            {
                for (uint8 data = DATA_YS_FREYA; data <= DATA_YS_HODIR; ++data)
                {
                    if (Creature *pCreature = Creature::GetCreature((*me), instance->GetData64(data)))
                    {
                        if (pCreature->HasAura(SPELL_KEEPER_ACTIVE))
                        {
                            pCreature->SetInCombatWith(me);
                            pCreature->AddThreat(me, 150.0f);
                            ++keepers;
                        }
                    }
                }
                
                if (!ominous_list.empty())
                {
                    for (std::vector<Creature*>::iterator itr = ominous_list.begin(); itr != ominous_list.end(); ++itr)
                    {
                        Creature* pTarget = *itr;
                        if (pTarget)
                            pTarget->AddThreat(me->getVictim(), 0.0f);
                    }
                }
            }
            wipe = true;
            me->RestoreFaction();
            uiStep = 0;
            uiPhase_timer = -1;
            JumpToNextStep(5000);
            phase = PHASE_1;
            events.SetPhase(PHASE_1);
            events.ScheduleEvent(EVENT_FERVOR, urand(6000, 8000), 0, PHASE_1);
            events.ScheduleEvent(EVENT_BLESSING, urand(10000, 12000), 0, PHASE_1);
            events.ScheduleEvent(EVENT_ANGER, urand(15000, 20000), 0, PHASE_1);
            events.ScheduleEvent(EVENT_SUMMON_GUARDIAN, 0, 0, PHASE_1);
        }
        
        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;
                
            events.Update(diff);

            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;
                
            if (phase == PHASE_1)
            {
                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch(eventId)
                    {
                        case EVENT_FERVOR:
                            if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 80, true))
                                DoCast(pTarget, SPELL_SARA_FERVOR);
                            events.ScheduleEvent(EVENT_FERVOR, urand(8000, 10000), 0, PHASE_1);
                            break;
                        case EVENT_BLESSING:
                            if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 80, true))
                                DoCast(pTarget, SPELL_SARA_BLESSING);
                            events.ScheduleEvent(EVENT_BLESSING, urand(10000, 15000), 0, PHASE_1);
                            break;
                        case EVENT_ANGER:
                            if (Creature *pGuardian = me->FindNearestCreature(NPC_GUARDIAN_OF_YOGGSARON,50,true))
                                DoCast(pGuardian, SPELL_SARA_ANGER);
                            events.ScheduleEvent(EVENT_ANGER, urand(15000, 20000), 0, PHASE_1);
                            break;
                        case EVENT_SUMMON_GUARDIAN:
                            if (!ominous_list.empty())
                            {
                                std::vector<Creature*>::iterator itr = (ominous_list.begin()+rand()%ominous_list.size());
                                Creature* pTarget = *itr;
                                if (pTarget)
                                    pTarget->CastSpell(pTarget, SPELL_SUMMON_GUARDIAN, true);
                            }
                            events.ScheduleEvent(EVENT_SUMMON_GUARDIAN, 8000 + urand(6000, 8000)*((float)me->GetHealth()/me->GetMaxHealth()), 0, PHASE_1);
                            break;
                    }
                }
                
                if (uiPhase_timer <= diff)
                {
                    switch (uiStep)
                    {
                        case 1:
                            // Close door
                            _EnterCombat();
                            uiStep = 2;
                            break;
                        default:
                            break;
                    }
                }
                else
                    uiPhase_timer -= diff;
            }
            else if (phase == PHASE_2)
            {
                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch(eventId)
                    {
                        case EVENT_PSYCHOSIS:
                            if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 60, true))
                                DoCast(pTarget, SPELL_PSYCHOSIS);
                            events.ScheduleEvent(EVENT_PSYCHOSIS, urand(4000, 6000), 0, PHASE_2);
                            break;
                        case EVENT_MALADY_OF_THE_MIND:
                            if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 60, true))
                                DoCast(pTarget, SPELL_MALADY_OF_THE_MIND);
                            events.ScheduleEvent(EVENT_MALADY_OF_THE_MIND, urand(15000, 20000), 0, PHASE_2);
                            break;
                        case EVENT_BRAIN_LINK:
                            DoCastAOE(SPELL_BRAIN_LINK);
                            events.ScheduleEvent(EVENT_BRAIN_LINK, 30000, 0, PHASE_2);
                            break;
                        case EVENT_DEATH_RAY:
                            for (uint32 i = 0; i < 4; ++i)
                                me->SummonCreature(NPC_DEATH_ORB, DeathRayPos[rand()%12], TEMPSUMMON_TIMED_DESPAWN, 17000);
                            events.ScheduleEvent(EVENT_DEATH_RAY, 20000, 0, PHASE_2);
                            break;
                    }
                }
                
                if (uiPhase_timer <= diff)
                {
                    switch (uiStep)
                    {
                        case 1:
                            DoScriptText(SAY_PHASE2_1, me);
                            me->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
                            if (!ominous_list.empty())
                            {
                                for (std::vector<Creature*>::iterator itr = ominous_list.begin(); itr != ominous_list.end(); ++itr)
                                {
                                    Creature* pTarget = *itr;
                                    if (pTarget)
                                        pTarget->ForcedDespawn();
                                }
                            }
                            JumpToNextStep(5000);
                            break;
                        case 2:
                            DoScriptText(SAY_PHASE2_2, me);
                            JumpToNextStep(4000);
                            break;
                        case 3:
                            DoScriptText(SAY_PHASE2_3, me);
                            JumpToNextStep(5000);
                            break;
                        case 4:
                            DoScriptText(SAY_PHASE2_4, me);
                            JumpToNextStep(3000);
                            break;
                        case 5:
                            me->SetDisplayId(29182);
                            me->setFaction(16);
                            events.SetPhase(PHASE_2);
                            DoZoneInCombat();
                            me->GetMotionMaster()->MoveJump(me->GetPositionX(),me->GetPositionY(),me->GetPositionZ()+20, 10, 15);
                            me->SummonCreature(NPC_YOGG_SARON,me->GetPositionX(),me->GetPositionY(),me->GetPositionZ(),M_PI,TEMPSUMMON_CORPSE_TIMED_DESPAWN,600000);
                            JumpToNextStep(5000);
                            break;
                        case 6:
                            DoScriptText(RAND(SAY_SARA_PHASE2_1, SAY_SARA_PHASE2_2), me);
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            events.ScheduleEvent(EVENT_PSYCHOSIS, 0, 0, PHASE_2);
                            events.ScheduleEvent(EVENT_MALADY_OF_THE_MIND, urand(4000, 6000), 0, PHASE_2);
                            events.ScheduleEvent(EVENT_BRAIN_LINK, 30000, 0, PHASE_2);
                            events.ScheduleEvent(EVENT_DEATH_RAY, 25000, 0, PHASE_2);
                            uiStep = 7;
                            break;
                        default:
                            break;
                    }
                }
                else
                    uiPhase_timer -= diff;
            }
        }
        
        void DamageTaken(Unit *who, uint32 &damage)
        {
            if (phase == PHASE_1 && damage >= me->GetHealth())
            {
                damage = 0;
                me->SetFullHealth();
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                phase = PHASE_2;
                uiStep = 0;
                uiPhase_timer = -1;
                JumpToNextStep(100);
            }
        }
        
        void JumpToNextStep(uint32 uiTimer)
        {
            uiPhase_timer = uiTimer;
            ++uiStep;
        }
    };

};

/*------------------------------------------------------*
 *                      Yogg-Saron                      *
 *------------------------------------------------------*/

class boss_yoggsaron : public CreatureScript
{
public:
    boss_yoggsaron() : CreatureScript("boss_yoggsaron") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_yoggsaron_AI (pCreature);
    }

    struct boss_yoggsaron_AI : public BossAI
    {
        boss_yoggsaron_AI(Creature *pCreature) : BossAI(pCreature, BOSS_YOGGSARON)
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED | UNIT_FLAG_DISABLE_MOVE);
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
            DoCast(me, SPELL_SHADOWY_BARRIER_LARGE, true);
            me->SetReactState(REACT_PASSIVE);
            DoScriptText(SAY_PHASE2_5, me);
        }

        uint32 insaneTimer;
        uint8 illusionOrder[3];
        uint8 illusionCount;
        uint8 spawnedTentacles;
        
        void Reset()
        {
            events.Reset();
            summons.DespawnAll();
        }
        
        void EnterCombat(Unit *who)
        {
            _EnterCombat();
            
            // 100% Sanity
            if (instance)
            {
                Map::PlayerList const &players = instance->instance->GetPlayers();
                for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                {
                    Player* pPlayer = itr->getSource();
                    if (pPlayer)
                        me->SetAuraStack(SPELL_SANITY, pPlayer, 100);
                }
                // Spawn Brain of Yogg-Saron
                me->SummonCreature(NPC_YOGG_SARON_BRAIN, 1980.70f, -25.16f, 262.77f, M_PI);
                insaneTimer = 4000;
                illusionCount = 0;
                spawnedTentacles = 0;
                randomizeIllusion();
                events.SetPhase(PHASE_2);
                events.ScheduleEvent(EVENT_TENTACLES, 1000, 0, PHASE_2);
                events.ScheduleEvent(EVENT_ILLUSION, 60000, 0, PHASE_2);
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if(!UpdateVictim())
                return;
                
            events.Update(diff);
            
            if (insaneTimer <= diff)
            {
                if (instance)
                {
                    // Sanity Check
                    Map::PlayerList const &players = instance->instance->GetPlayers();
                    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                    {
                        Player* pPlayer = itr->getSource();
                        
                        if (!pPlayer)
                            continue;
                        
                        if (pPlayer->isDead() || pPlayer->HasAura(SPELL_SANITY) || pPlayer->HasAura(SPELL_INSANE))
                            continue;
                            
                        if (Creature* pVoice = me->SummonCreature(NPC_YOGG_SARON_VOICE,me->GetPositionX(),me->GetPositionY(),me->GetPositionZ(),0,TEMPSUMMON_TIMED_DESPAWN,1000))
                            DoScriptText(RAND(WHISP_INSANITY_1, WHISP_INSANITY_1), pVoice, pPlayer);

                        DoCast(pPlayer, SPELL_INSANE, true);
                    }
                }
                insaneTimer = 4000;
            }
            else insaneTimer -= diff;
                
            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;
                
            if (phase == PHASE_2)
            {
                while(uint32 eventId = events.ExecuteEvent())
                {
                    switch(eventId)
                    {
                        case EVENT_TENTACLES:
                            spawnTentacles();
                            events.ScheduleEvent(EVENT_TENTACLES, urand(25000, 30000), 0, PHASE_2);
                            break;
                        case EVENT_ILLUSION:
                            DoScriptText(SAY_VISION, me);
                            Map::PlayerList const &players = instance->instance->GetPlayers();
                            for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                                DoScriptText(EMOTE_PORTALS, me, itr->getSource());
                            OpenIllusion();
                            events.ScheduleEvent(EVENT_ILLUSION, urand(80000, 85000), 0, PHASE_2);
                            break;

                    }
                }
            }
            else
            {
                while(uint32 eventId = events.ExecuteEvent())
                {
                    switch(eventId)
                    {
                        case EVENT_LUNATIC_GAZE:
                            DoScriptText(SAY_LUNATIC_GAZE, me);
                            DoCast(me, SPELL_LUNATIC_GAZE_P3);
                            events.ScheduleEvent(EVENT_LUNATIC_GAZE, urand(15000, 20000), 0, PHASE_3);
                            break;
                        case EVENT_IMMORTAL_GUARDIAN:
                            Position pos;
                            me->GetRandomNearPosition(pos, 25);
                            me->SummonCreature(NPC_IMMORTAL_GUARDIAN, pos, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000);
                            events.ScheduleEvent(EVENT_IMMORTAL_GUARDIAN, urand(25000, 30000), 0, PHASE_3);
                            break;
                        case EVENT_SHADOW_BEACON:
                            if (Creature *pImmortal = me->FindNearestCreature(NPC_IMMORTAL_GUARDIAN,80,true))
                            {
                                Map::PlayerList const &players = instance->instance->GetPlayers();
                                for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                                    DoScriptText(EMOTE_EMPOWERING, me, itr->getSource());                                me->AddAura(SPELL_SHADOW_BEACON, pImmortal);
                            }
                            events.ScheduleEvent(EVENT_SHADOW_BEACON, 45000, 0, PHASE_3);
                            break;
                        case EVENT_DEAFENING_ROAR:
                            DoScriptText(SAY_DEAFENING_ROAR, me);
                            DoCast(me, SPELL_DEAFENING_ROAR);
                            events.ScheduleEvent(EVENT_DEAFENING_ROAR, urand(20000, 25000), 0, PHASE_3);
                            break;
                    }
                }
            }
        }
        
        void JustDied(Unit *victim)
        {
            DoScriptText(SAY_DEATH, me);
            _JustDied();
            
            if (Unit *pSara = me->ToTempSummon()->GetSummoner())
                pSara->ToCreature()->DisappearAndDie();

            me->SetStandState(UNIT_STAND_STATE_SUBMERGED);
            me->HandleEmoteCommand(EMOTE_ONESHOT_EMERGE);
            
            if (instance)
            {
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SANITY);
            }
        }

        void randomizeIllusion()
        {
            illusionOrder[0] = 0; // Chamber of the Aspects Illusion
            illusionOrder[1] = 1; // Icecrown Illusion
            illusionOrder[2] = 2; // Stormwind Illusion
            
            //Swaps the entire array
            for(uint8 n = 0; n < 3; n++)
            {
                uint8 random = rand() % 2;
                uint8 temp = illusionOrder[random];
                illusionOrder[random] = illusionOrder[n];
                illusionOrder[n] = temp;
            }
        }

        void OpenIllusion()
        {
            switch(illusionCount)
            {
                case 0: illusionHandler(illusionOrder[0]); break;
                case 1: illusionHandler(illusionOrder[1]); break;
                case 2: illusionHandler(illusionOrder[2]); break;
            }

            illusionCount++;
            if(illusionCount > 2)
            {
                illusionCount = 0;
            }
        }

        void illusionHandler(uint8 illusion)
        {
            if (instance)
            {
                switch(illusion)
                {
                    case 0: // Chamber of the Aspects Illusion
                        if (Creature *pBrain = Creature::GetCreature((*me), instance->GetData64(DATA_YOGGSARON_BRAIN)))
                        {
                            pBrain->AI()->Reset();
                            pBrain->AI()->DoAction(ACTION_CHAMBER_ILLUSION);
                            for (int32 i = 0; i < RAID_MODE(4, 10); ++i)
                                me->SummonCreature(NPC_PORTAL_CHAMBER, PortalPos[i], TEMPSUMMON_TIMED_DESPAWN, 30000);
                        }
                        break;
                    case 1: // Icecrown Illusion
                        if (Creature *pBrain = Creature::GetCreature((*me), instance->GetData64(DATA_YOGGSARON_BRAIN)))
                        {
                            pBrain->AI()->Reset();
                            pBrain->AI()->DoAction(ACTION_ICECROWN_ILLUSION);
                            for (int32 i = 0; i < RAID_MODE(4, 10); ++i)
                                me->SummonCreature(NPC_PORTAL_ICECROWN, PortalPos[i], TEMPSUMMON_TIMED_DESPAWN, 30000);
                        }
                        break;
                    case 2: // Stormwind Illusion
                        if (Creature *pBrain = Creature::GetCreature((*me), instance->GetData64(DATA_YOGGSARON_BRAIN)))
                        {
                            pBrain->AI()->Reset();
                            pBrain->AI()->DoAction(ACTION_STORMWIND_ILLUSION);
                            for (int32 i = 0; i < RAID_MODE(4, 10); ++i)
                                me->SummonCreature(NPC_PORTAL_STORMWIND, PortalPos[i], TEMPSUMMON_TIMED_DESPAWN, 30000);
                        }
                        break;
                }
            }
        }

        void spawnTentacles()
        {
            switch(spawnedTentacles)
            {
                case 0:
                    me->SummonCreature(NPC_CRUSHER_TENTACLE, TentaclesPos[rand()%22]);
                case 1:
                case 2:
                    me->SummonCreature(NPC_CORRUPTOR_TENTACLE, TentaclesPos[rand()%22]);
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 60, true))
                    {
                        Position pos;
                        pTarget->GetPosition(&pos);
                        if (Creature* Constrict = me->SummonCreature(NPC_CONSTRICTOR_TENTACLE, pos))
                            pTarget->EnterVehicle(Constrict, 0);
                    }
                    break;
            }

            spawnedTentacles++;
            if(spawnedTentacles > 2)
            {
                spawnedTentacles = 0;
            }
        }

        void DoAction(const int32 action)
        {
            switch (action)
            {
                case ACTION_YOGGSARON_PHASE_3:
                    if (Unit *pSara = me->ToTempSummon()->GetSummoner())
                        pSara->SetVisible(false);
                    DoScriptText(SAY_PHASE3, me);
                    me->RemoveAurasDueToSpell(SPELL_SHADOWY_BARRIER_LARGE);
                    DoCast(me, SPELL_YOGG_SARON_TRANSFORMATION, true);
                    events.SetPhase(PHASE_3);
                    events.ScheduleEvent(EVENT_LUNATIC_GAZE, 15000, 0, PHASE_3);
                    events.ScheduleEvent(EVENT_IMMORTAL_GUARDIAN, 8000, 0, PHASE_3);
                    events.ScheduleEvent(EVENT_SHADOW_BEACON, 45000, 0, PHASE_3);
                    if (GetDifficulty() == RAID_DIFFICULTY_25MAN_NORMAL)
                        events.ScheduleEvent(EVENT_DEAFENING_ROAR, urand(5000, 7000), 0, PHASE_3);
                    break;
            } 
        }
    };

};


/*------------------------------------------------------*
 *                 Brain of Yogg-Saron                  *
 *------------------------------------------------------*/

class boss_brain_yoggsaron : public CreatureScript
{
public:
    boss_brain_yoggsaron() : CreatureScript("boss_brain_yoggsaron") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_brain_yoggsaron_AI (pCreature);
    }

    struct boss_brain_yoggsaron_AI : public BossAI
    {
        boss_brain_yoggsaron_AI(Creature *pCreature) : BossAI(pCreature, BOSS_YOGGSARON)
        {
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
            me->SetReactState(REACT_PASSIVE);
            me->SetFlying(true);
        }

        int32 tentacleCount;
        int32 illusion;

        void Reset()
        {
            events.Reset();
            summons.DespawnAll();
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            tentacleCount = 0;
            illusion = 0;
            if (instance)
            {
                for (uint32 i = GOB_CHAMBER_DOOR; i <= GOB_STORMWIND_DOOR; i++)
                {
                    if (GameObject* Door = me->FindNearestGameObject(i, 60))
                        Door->SetGoState(GO_STATE_READY);
                }
            }
        }

        void EnterCombat(Unit *who)
        {
            _EnterCombat();
        }

        void UpdateAI(const uint32 diff)
        {
            if(!UpdateVictim())
                return;

            if (HealthBelowPct(30) && phase == PHASE_2)
            {
                // Enter Phase 3
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                me->InterruptNonMeleeSpells(true);
                DoCast(me, SPELL_BRAIN_HURT, true);
                phase = PHASE_3;
                if (Unit* pYoggSaron = me->ToTempSummon()->GetSummoner())
                    pYoggSaron->ToCreature()->AI()->DoAction(ACTION_YOGGSARON_PHASE_3);
            }
        }
        
        void DoAction(const int32 action)
        {
            switch (action)
            {
                case ACTION_TENTACLE_COUNT:
                    tentacleCount++;
                    if (tentacleCount == 8)
                    {
                        DoCastAOE(SPELL_SHATTERED_ILLUSION, true);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        if (GameObject* pDoor = me->FindNearestGameObject(GOB_CHAMBER_DOOR + illusion, 60))
                            pDoor->SetGoState(GO_STATE_ACTIVE);
                        // The Illusion shatters and a path to the central chamber opens!
                        std::list<Unit*> unitList;
                        me->GetRaidMember(unitList, 80);
                        for (std::list<Unit*>::iterator itr = unitList.begin(); itr != unitList.end(); ++itr)
                            DoScriptText(EMOTE_OPEN_CHAMBER, me, *itr);
                    }
                    break;
                case ACTION_CHAMBER_ILLUSION:
                    illusion = 0;
                    for (uint32 i = 0; i < 16; i++)
                        me->SummonCreature(chamberLocations[i].entry,chamberLocations[i].x,chamberLocations[i].y,chamberLocations[i].z,chamberLocations[i].o);
                    DoCast(SPELL_INDUCE_MADNESS);
                    break;
                case ACTION_ICECROWN_ILLUSION:
                    illusion = 1;
                    for (uint32 i = 0; i < 14; i++)
                        me->SummonCreature(icecrownLocations[i].entry,icecrownLocations[i].x,icecrownLocations[i].y,icecrownLocations[i].z,icecrownLocations[i].o);
                    DoCast(SPELL_INDUCE_MADNESS);
                    break;
                case ACTION_STORMWIND_ILLUSION:
                    illusion = 2;
                    for (uint32 i = 0; i < 14; i++)
                        me->SummonCreature(stormwindLocations[i].entry,stormwindLocations[i].x,stormwindLocations[i].y,stormwindLocations[i].z,stormwindLocations[i].o);
                    DoCast(SPELL_INDUCE_MADNESS);
                    break;
            }
        }
    };

};

class npc_ominous_cloud : public CreatureScript
{
public:
    npc_ominous_cloud() : CreatureScript("npc_ominous_cloud") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_ominous_cloud_AI (pCreature);
    }

    struct npc_ominous_cloud_AI : public ScriptedAI
    {
        npc_ominous_cloud_AI(Creature* pCreature) : ScriptedAI(pCreature), summons(me) 
        {
            me->GetMotionMaster()->MoveRandom(5);
            me->SetDisplayId(28549);
        }

        SummonList summons;
        bool SummonCooldown;
        int32 uiCooldownTimer;

        void Reset()
        {
            summons.DespawnAll();
            DoCast(me, SPELL_OMINOUS_CLOUD_VISUAL, true);
            SummonCooldown = false;
            uiCooldownTimer = 3000;
        }

        void MoveInLineOfSight(Unit *who)
        {
            if (!SummonCooldown && me->IsWithinDistInMap(who, 6.0f) && who->ToPlayer() && !who->ToPlayer()->isGameMaster())
            {
                DoCast(me, SPELL_INSTANT_SUMMON_GUARDIAN, true);
                SummonCooldown = true;
                uiCooldownTimer = 3000;
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if(!UpdateVictim())
                return;

            if(uiCooldownTimer <= 0)
            {
                SummonCooldown = false;
                uiCooldownTimer = 10000;
            }
            else uiCooldownTimer -= diff;
        }

        void JustSummoned(Creature *summon)
        {
            summons.Summon(summon);
        }
    };

};

class npc_guardian_yoggsaron : public CreatureScript
{
public:
    npc_guardian_yoggsaron() : CreatureScript("npc_guardian_yoggsaron") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_guardian_yoggsaron_AI (pCreature);
    }

    struct npc_guardian_yoggsaron_AI : public ScriptedAI
    {
        npc_guardian_yoggsaron_AI(Creature* pCreature) : ScriptedAI(pCreature) { }

        int32 uiDarkVolleyTimer;

        void Reset()
        {
            DoZoneInCombat();
            uiDarkVolleyTimer = 8000;
        }

        void JustDied(Unit *victim)
        {
            DoCast(me, RAID_MODE(SPELL_SHADOW_NOVA_10, SPELL_SHADOW_NOVA_25), true);
            if (Creature *pSara = me->FindNearestCreature(NPC_SARA, 10.0f, true))
                if (phase == PHASE_1)
                    me->DealDamage(pSara, 25000);
            me->ForcedDespawn(3000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                me->ForcedDespawn();

            if (uiDarkVolleyTimer <= 0)
            {
                DoCast(SPELL_DARK_VOLLEY);
                uiDarkVolleyTimer = urand(10000, 15000);
            }
            else uiDarkVolleyTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

class npc_death_orb : public CreatureScript
{
public:
    npc_death_orb() : CreatureScript("npc_death_orb") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_death_orb_AI (pCreature);
    }

    struct npc_death_orb_AI : public ScriptedAI
    {
        npc_death_orb_AI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            me->SetReactState(REACT_PASSIVE);
            me->SetDisplayId(16946);
            DoCast(SPELL_DEATH_RAY_WARNING_VISUAL);
        }

        int32 RayTimer;

        void Reset()
        {
            RayTimer = 5000;
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (RayTimer <= 0)
            {
                DoCast(SPELL_DEATH_RAY_DAMAGE);
                DoCast(SPELL_DEATH_RAY_DAMAGE_VISUAL);
                me->ClearUnitState(UNIT_STAT_CASTING);
                me->GetMotionMaster()->MoveRandom(10.0f);
                RayTimer = 15000;
            }
            else RayTimer -= diff;
        }
    };

};

class npc_laughing_skull : public CreatureScript
{
public:
    npc_laughing_skull() : CreatureScript("npc_laughing_skull") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_laughing_skull_AI (pCreature);
    }

    struct npc_laughing_skull_AI : public Scripted_NoMovementAI
    {
        npc_laughing_skull_AI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            me->SetDisplayId(15880);
            me->SetReactState(REACT_PASSIVE);
            me->AddAura(SPELL_LUNATIC_GAZE, me);
        }
    };

};

class npc_illusion : public CreatureScript
{
public:
    npc_illusion() : CreatureScript("npc_illusion") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_illusion_AI (pCreature);
    }

    struct npc_illusion_AI : public Scripted_NoMovementAI
    {
        npc_illusion_AI(Creature* pCreature) : Scripted_NoMovementAI(pCreature) { }

        void DamageTaken(Unit *attacker, uint32 &damage)
        {
            if (me->GetEntry() != NPC_INFLUENCE_TENTACLE)
            {
                me->UpdateEntry(NPC_INFLUENCE_TENTACLE);
                DoCast(me, SPELL_GRIM_REPRISAL, true);
                DoCast(me, SPELL_TENTACLE_VOID_ZONE, true);
            }
        }

        void JustDied(Unit *victim)
        {
            if (Unit* pBrain = me->ToTempSummon()->GetSummoner())
                pBrain->ToCreature()->AI()->DoAction(ACTION_TENTACLE_COUNT);
        }
    };

};

class npc_descend_into_madness : public CreatureScript
{
public:
    npc_descend_into_madness() : CreatureScript("npc_descend_into_madness") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_descend_into_madness_AI (pCreature);
    }

    struct npc_descend_into_madness_AI : public PassiveAI
    {
        npc_descend_into_madness_AI(Creature *c) : PassiveAI(c) {}

        void DoAction(const int32 param)
        {
            if (param == EVENT_SPELLCLICK)
            {
                me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                me->ForcedDespawn();
            }
        }
    };

};

class npc_passive_illusion : public CreatureScript
{
public:
    npc_passive_illusion() : CreatureScript("npc_passive_illusion") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_passive_illusion_AI (pCreature);
    }

    struct npc_passive_illusion_AI : public PassiveAI
    {
        npc_passive_illusion_AI(Creature *c) : PassiveAI(c) 
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_NON_ATTACKABLE);
        }
    };

};

/*------------------------------------------------------*
 *                       Tentacles                      *
 *------------------------------------------------------*/

class npc_crusher_tentacle : public CreatureScript
{
public:
    npc_crusher_tentacle() : CreatureScript("npc_crusher_tentacle") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_crusher_tentacle_AI (pCreature);
    }

    struct npc_crusher_tentacle_AI : public Scripted_NoMovementAI
    {
        npc_crusher_tentacle_AI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
        {
            DoCast(me, SPELL_TENTACLE_VOID_ZONE, true);
            DoCast(me, SPELL_ERUPT, true);
            DoCast(me, SPELL_FOCUSED_ANGER, true);
            DoCast(me, SPELL_DIMINISH_POWER, true);
            DiminishTimer = 3000;
        }

        int32 DiminishTimer;

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() || me->HasUnitState(UNIT_STAT_CASTING))
                return;

            if (DiminishTimer <= 0)
            {
                DoCast(me, SPELL_DIMINISH_POWER, true);
                DiminishTimer = 3000;
            }
            else DiminishTimer -= diff;

            DoMeleeAttackIfReady();
        }

        void DamageTaken(Unit *attacker, uint32 &damage)
        {
            if (attacker->IsWithinMeleeRange(me) && me->HasUnitState(UNIT_STAT_CASTING))
                me->InterruptNonMeleeSpells(true, SPELL_DIMINISH_POWER);
        }
    };

};

class npc_constrictor_tentacle : public CreatureScript
{
public:
    npc_constrictor_tentacle() : CreatureScript("npc_constrictor_tentacle") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_constrictor_tentacle_AI (pCreature);
    }

    struct npc_constrictor_tentacle_AI : public Scripted_NoMovementAI
    {
        npc_constrictor_tentacle_AI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
        {
            me->SetReactState(REACT_PASSIVE);
            DoCast(me, SPELL_TENTACLE_VOID_ZONE, true);
        }

        void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply)
        {
            if (apply)
                me->AddAura(RAID_MODE(SPELL_SQUEEZE_10, SPELL_SQUEEZE_25), who);
            else
                who->RemoveAurasDueToSpell(RAID_MODE(SPELL_SQUEEZE_10, SPELL_SQUEEZE_25));
        }
    };

};

class npc_corruptor_tentacle : public CreatureScript
{
public:
    npc_corruptor_tentacle() : CreatureScript("npc_corruptor_tentacle") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_corruptor_tentacle_AI (pCreature);
    }

    struct npc_corruptor_tentacle_AI : public Scripted_NoMovementAI
    {
        npc_corruptor_tentacle_AI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
        {
            DoCast(me, SPELL_TENTACLE_VOID_ZONE, true);
            DoCast(me, SPELL_ERUPT, true);
            ApathyTimer = 0;
            PoisonTimer = 1000;
            PlagueTimer = 2000;
            CurseTimer = 3000;
            // Destabilization Matrix doesn't work
            ApathyTimer = 0;
            PoisonTimer = 4000;
            PlagueTimer = 8000;
            CurseTimer = 12000;
        }

        int32 ApathyTimer;
        int32 PoisonTimer;
        int32 PlagueTimer;
        int32 CurseTimer;

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() || me->HasUnitState(UNIT_STAT_CASTING))
                return;

            if (ApathyTimer <= 0)
            {
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 80, true))
                    DoCast(pTarget, SPELL_APATHY);
                //ApathyTimer = 4000;
                ApathyTimer = 16000;
            }
            else ApathyTimer -= diff;

            if (PoisonTimer <= 0)
            {
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 80, true))
                    DoCast(pTarget, SPELL_DRAINING_POISON);
                //PoisonTimer = 4000;
                PoisonTimer = 16000;
            }
            else PoisonTimer -= diff;

            if (PlagueTimer <= 0)
            {
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 80, true))
                    DoCast(pTarget, SPELL_BLACK_PLAGUE);
                //PlagueTimer = 4000;
                PlagueTimer = 16000;
            }
            else PlagueTimer -= diff;

            if (CurseTimer <= 0)
            {
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 80, true))
                    DoCast(pTarget, SPELL_CURSE_OF_DOOM);
                //CurseTimer = 4000;
                CurseTimer = 16000;
            }
            else CurseTimer -= diff;
        }
    };

};


/*------------------------------------------------------*
 *                  Immortal Guardian                   *
 *------------------------------------------------------*/


class npc_immortal_guardian : public CreatureScript
{
public:
    npc_immortal_guardian() : CreatureScript("npc_immortal_guardian") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_immortal_guardian_AI (pCreature);
    }

    struct npc_immortal_guardian_AI : public ScriptedAI
    {
        npc_immortal_guardian_AI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            me->SetAuraStack(SPELL_EMPOWERED, me, 10);
        }

        int32 uiDrainLifeTimer;

        void Reset()
        {
            uiDrainLifeTimer = 10000;
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (HealthBelowPct(10))
            {
                me->RemoveAurasDueToSpell(SPELL_EMPOWERED);
                me->AddAura(SPELL_WEAKENED, me);
            }
            else
            {
                me->RemoveAurasDueToSpell(SPELL_WEAKENED);
                me->SetAuraStack(SPELL_EMPOWERED, me, ((float)me->GetHealth() / me->GetMaxHealth()) * 10);
            }

            if (uiDrainLifeTimer <= 0)
            {
                DoCast(me->getVictim(), RAID_MODE(SPELL_DRAIN_LIFE_10, SPELL_DRAIN_LIFE_25));
                uiDrainLifeTimer = urand(15000, 20000);
            }
            else uiDrainLifeTimer -= diff;

            DoMeleeAttackIfReady();
        }

        void DamageTaken(Unit* who, uint32 &damage)
        {
            // Immortal Guardians stop taking damage when their health reaches 1%
            if (damage >= me->GetHealth())
            {
                me->SetHealth(me->GetMaxHealth() / 100);
                damage = 0 ;
            }
        }

        void SpellHit(Unit *caster, const SpellEntry *spell)
        {
            // Thorim kills weakened immortal creatures
            if (spell->Id == SPELL_TITANIC_STORM_EFFECT)
            {
                caster->Kill(me, false);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            }
        }
    };

};

/*------------------------------------------------------*
 *                  Images of Keepers                   *
 *------------------------------------------------------*/

class npc_keeper_image : public CreatureScript
{
public:
    npc_keeper_image() : CreatureScript("npc_keeper_image") { }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        InstanceScript* instance = pCreature->GetInstanceScript();

        if (pPlayer)
            pPlayer->CLOSE_GOSSIP_MENU();

        switch (pCreature->GetEntry())
        {
            case NPC_IMAGE_OF_FREYA:
                DoScriptText(SAY_FREYA_HELP, pCreature);
                pCreature->AddAura(SPELL_KEEPER_ACTIVE, pCreature);
                if (Creature *pFreya = pCreature->GetCreature(*pCreature, instance->GetData64(DATA_YS_FREYA)))
                    pFreya->AddAura(SPELL_KEEPER_ACTIVE, pFreya);
                break;
            case NPC_IMAGE_OF_THORIM:
                DoScriptText(SAY_THORIM_HELP, pCreature);
                pCreature->AddAura(SPELL_KEEPER_ACTIVE, pCreature);
                if (Creature *pThorim = pCreature->GetCreature(*pCreature, instance->GetData64(DATA_YS_THORIM)))
                    pThorim->AddAura(SPELL_KEEPER_ACTIVE, pThorim);
                break;
            case NPC_IMAGE_OF_MIMIRON:
                DoScriptText(SAY_MIMIRON_HELP, pCreature);
                pCreature->AddAura(SPELL_KEEPER_ACTIVE, pCreature);
                if (Creature *pMimiron = pCreature->GetCreature(*pCreature, instance->GetData64(DATA_YS_MIMIRON)))
                    pMimiron->AddAura(SPELL_KEEPER_ACTIVE, pMimiron);
                break;
            case NPC_IMAGE_OF_HODIR:
                DoScriptText(SAY_HODIR_HELP, pCreature);
                pCreature->AddAura(SPELL_KEEPER_ACTIVE, pCreature);
                if (Creature *pHodir = pCreature->GetCreature(*pCreature, instance->GetData64(DATA_YS_HODIR)))
                    pHodir->AddAura(SPELL_KEEPER_ACTIVE, pHodir);
                break;
        }
        return true;
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        InstanceScript* instance = pCreature->GetInstanceScript();

        if (instance && pPlayer)
        {
            if (!pCreature->HasAura(SPELL_KEEPER_ACTIVE))
            {
                pPlayer->PrepareQuestMenu(pCreature->GetGUID());
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_KEEPER_HELP, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
                pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
            }
        }
        return true;
    }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_keeper_image_AI (pCreature);
    }

    struct npc_keeper_image_AI : public ScriptedAI
    {
        npc_keeper_image_AI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_NON_ATTACKABLE);
            me->SetReactState(REACT_PASSIVE);
        }
    };

};


class npc_ys_freya : public CreatureScript
{
public:
    npc_ys_freya() : CreatureScript("npc_ys_freya") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_ys_freya_AI (pCreature);
    }

    struct npc_ys_freya_AI : public ScriptedAI
    {
        npc_ys_freya_AI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_FURY_OF_THE_STORMS, true);
            me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_SPEED_OF_INVENTION, true);
            me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_FORTITUDE_OF_FROST, true);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_NON_ATTACKABLE);
            me->SetReactState(REACT_PASSIVE);
        }

        uint32 WellTimer;

        void Reset()
        {
            WellTimer = urand(5000, 10000);
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;
                
            if (!me->HasAura(SPELL_RESILIENCE_OF_NATURE))
                DoCast(me, SPELL_RESILIENCE_OF_NATURE);
                
            if (WellTimer <= uiDiff)
            {
                DoCast(SPELL_SANITY_WELL_SPAWN);
                me->SummonCreature(NPC_SANITY_WELL, SanityWellPos[rand()%10], TEMPSUMMON_TIMED_DESPAWN, 60000);
                WellTimer = 20000;
            }
            else WellTimer -= uiDiff;
        }
    };

};

class npc_sanity_well : public CreatureScript
{
public:
    npc_sanity_well() : CreatureScript("npc_sanity_well") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_sanity_well_AI (pCreature);
    }

    struct npc_sanity_well_AI : public Scripted_NoMovementAI
    {
        npc_sanity_well_AI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
        {
            pInstance = pCreature->GetInstanceScript();
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            me->SetDisplayId(11686);
            DoCast(me, SPELL_SANITY_WELL_VISUAL);
            DoCast(me, SPELL_SANITY_WELL);
            sanityTimer = 2000;
        }

        InstanceScript* pInstance;
        uint32 sanityTimer;

        void UpdateAI(const uint32 uiDiff)
        {
            if (sanityTimer <= uiDiff)
            {
                Map::PlayerList const &players = pInstance->instance->GetPlayers();
                for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                {
                    Player* pPlayer = itr->getSource();
                    if (!pPlayer)
                        continue;
                    // Standing in the well brings you back to your senses, regenerating 20% Sanity every 2 sec
                    if (me->IsWithinDist(pPlayer, 8.0f) && pPlayer->HasAura(SPELL_SANITY_WELL))
                    {
                        if (Aura * aur = pPlayer->GetAura(SPELL_SANITY))
                        {
                            uint32 stack = aur->GetStackAmount() + 20;
                            if (stack > 100)
                                stack = 100;
                            pPlayer->SetAuraStack(SPELL_SANITY, pPlayer, stack);
                        }
                    }
                }
                sanityTimer = 2000;
            }
            else sanityTimer -= uiDiff;
        }
    };

};


class npc_ys_thorim : public CreatureScript
{
public:
    npc_ys_thorim() : CreatureScript("npc_ys_thorim") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_ys_thorim_AI (pCreature);
    }

    struct npc_ys_thorim_AI : public ScriptedAI
    {
        npc_ys_thorim_AI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_RESILIENCE_OF_NATURE, true);
            me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_SPEED_OF_INVENTION, true);
            me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_FORTITUDE_OF_FROST, true);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_NON_ATTACKABLE);
            me->SetReactState(REACT_PASSIVE);
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim() || me->HasUnitState(UNIT_STAT_CASTING))
                return;
                
            if (!me->HasAura(SPELL_FURY_OF_THE_STORMS))
                DoCast(me, SPELL_FURY_OF_THE_STORMS);
                
            if (!me->HasAura(SPELL_TITANIC_STORM) && phase == PHASE_3)
                DoCast(me, SPELL_TITANIC_STORM);
        }
    };

};

class npc_ys_mimiron : public CreatureScript
{
public:
    npc_ys_mimiron() : CreatureScript("npc_ys_mimiron") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_ys_mimiron_AI (pCreature);
    }

    struct npc_ys_mimiron_AI : public ScriptedAI
    {
        npc_ys_mimiron_AI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_RESILIENCE_OF_NATURE, true);
            me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_FURY_OF_THE_STORMS, true);
            me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_FORTITUDE_OF_FROST, true);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_NON_ATTACKABLE);
            me->SetReactState(REACT_PASSIVE);
        }

        uint32 DestabilizeTimer;

        void Reset()
        {
            DestabilizeTimer = 15000;
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            if (!me->HasAura(SPELL_SPEED_OF_INVENTION))
                DoCast(me, SPELL_SPEED_OF_INVENTION);

            if (DestabilizeTimer <= uiDiff)
            {
                //if (phase == PHASE_2)
                    //DoCast(SPELL_DESTABILIZATION);
                DestabilizeTimer = 45000;
            }
            else DestabilizeTimer -= uiDiff;
        }
    };

};

class npc_ys_hodir : public CreatureScript
{
public:
    npc_ys_hodir() : CreatureScript("npc_ys_hodir") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_ys_hodir_AI (pCreature);
    }

    struct npc_ys_hodir_AI : public ScriptedAI
    {
        npc_ys_hodir_AI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_RESILIENCE_OF_NATURE, true);
            me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_FURY_OF_THE_STORMS, true);
            me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_SPEED_OF_INVENTION, true);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_NON_ATTACKABLE);
            me->SetReactState(REACT_PASSIVE);
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            if (!me->HasAura(SPELL_FORTITUDE_OF_FROST))
                DoCast(me, SPELL_FORTITUDE_OF_FROST);
        }
    };

};

class OrientationCheck
{
    public:
        explicit OrientationCheck(Unit* _caster) : caster(_caster) { }

        bool operator() (Unit* unit)
        {
            return !unit->isInFront(caster, 40.0f, 2.5f);
        }

    private:
        Unit* caster;
};

class spell_yoggsaron_lunatic_gaze : public SpellScriptLoader
{
    public:
        spell_yoggsaron_lunatic_gaze() : SpellScriptLoader("spell_yoggsaron_lunatic_gaze") { }

        class spell_yoggsaron_lunatic_gaze_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_yoggsaron_lunatic_gaze_SpellScript);

            void FilterTargets(std::list<Unit*>& unitList)
            {
                unitList.remove_if(OrientationCheck(GetCaster()));
            }

            void Register()
            {
                OnUnitTargetSelect += SpellUnitTargetFn(spell_yoggsaron_lunatic_gaze_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_AREA_ENEMY_SRC);
                OnUnitTargetSelect += SpellUnitTargetFn(spell_yoggsaron_lunatic_gaze_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_AREA_ENEMY_SRC);
            }
        };

        SpellScript *GetSpellScript() const
        {
            return new spell_yoggsaron_lunatic_gaze_SpellScript();
        }
};

class IllusionRoomCheck
{
    public:
        bool operator() (Unit* unit)
        {
            return !unit->HasAura(SPELL_ILLUSION_ROOM);
        }
};

class spell_yoggsaron_induce_madness : public SpellScriptLoader
{
    public:
        spell_yoggsaron_induce_madness() : SpellScriptLoader("spell_yoggsaron_induce_madness") { }

        class spell_yoggsaron_induce_madness_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_yoggsaron_induce_madness_SpellScript);

            void FilterTargets(std::list<Unit*>& unitList)
            {
                unitList.remove_if(IllusionRoomCheck());
            }

            void Register()
            {
                OnUnitTargetSelect += SpellUnitTargetFn(spell_yoggsaron_induce_madness_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_AREA_ENTRY_SRC);
            }
        };

        SpellScript *GetSpellScript() const
        {
            return new spell_yoggsaron_induce_madness_SpellScript();
        }
};

void AddSC_boss_yoggsaron()
{
    new boss_sara();
    new boss_yoggsaron();
    new boss_brain_yoggsaron();
    new npc_ominous_cloud();
    new npc_guardian_yoggsaron();
    new npc_death_orb();
    new npc_laughing_skull();
    new npc_illusion();
    new npc_descend_into_madness();
    new npc_passive_illusion();
    new npc_crusher_tentacle();
    new npc_constrictor_tentacle();
    new npc_corruptor_tentacle();
    new npc_immortal_guardian();
    new npc_keeper_image();
    new npc_ys_freya();
    new npc_sanity_well();
    new npc_ys_thorim();
    new npc_ys_mimiron();
    new npc_ys_hodir();
    new spell_yoggsaron_lunatic_gaze();
    new spell_yoggsaron_induce_madness();
}
