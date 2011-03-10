/*
 * Copyright (C) 2010 TrinityScript 2
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
#include "eye_of_eternity.h"
#include "WorldPacket.h"
#include "ObjectAccessor.h"

enum
{
    /* Phase 0 */
    SPELL_PORTAL_BEAM              = 56046,
 
    /* Phase 1 */
    SPELL_ARCANE_BREATH            = 56272,
    SPELL_ARCANE_BREATH_H          = 60072,
    SPELL_VORTEX_DUMMY             = 56105,
    SPELL_VORTEX                   = 56266,
    SPELL_VORTEX_AOE_VISUAL        = 55873,
    SPELL_POWER_SPARK              = 56152,
    SPELL_POWER_SPARK_PLAYERS      = 55852,
    SPELL_POWER_SPARK_VISUAL       = 55845,
 
    /* Phase 2 */
    SPELL_ARCANE_STORM             = 61693,
    SPELL_ARCANE_STORM_H           = 61694,
    SPELL_ARCANE_OVERLOAD          = 56432,
    SPELL_ARCANE_BOMB              = 56431,
    SPELL_ARCANE_OVERLOAD_PROTECT  = 56438,
    SPELL_DEEP_BREATH              = 60071, 
    SPELL_SURGE_OF_POWER_BREATH    = 56505,
    SPELL_DESTROY_PLATFORM_PRE     = 58842,
    SPELL_DESTROY_PLATFROM_BOOM    = 59084,

    // Spell of NPCs
    SPELL_ARCANE_SHOCK             = 57058,
    SPELL_ARCANE_SHOCK_H           = 60073,
    SPELL_HASTE                    = 57060,
    SPELL_ARCANE_BARRAGE           = 56397, 
    SPELL_ARCANE_BARRAGE_H         = 63934, 
    BP_BARRAGE0                    = 14138,
    BP_BARRAGE0_H                  = 16965,
 
    /* Phase 3 */
    SPELL_STATIC_FIELD             = 57428, // Summon trigger and cast this on them should be enought
    SPELL_SURGE_OF_POWER           = 57407, // this is on one target
    SPELL_SURGE_OF_POWER_H         = 60936, // this is on unlimited tagets, must limit it in mangos
    SPELL_ARCANE_PULSE             = 57432,

    // Dragons spells
    SPELL_BERSERK                  = 64238,
    SPELL_FLAME_SPIKE              = 56091,
    SPELL_ENGULF_IN_FLAMES         = 56092,
    SPELL_REVIVIFY                 = 57090,
    SPELL_LIFE_BURST               = 57143,
    SPELL_FLAME_SHIELD             = 57108,
    SPELL_BLAZING_SPEED            = 57092,
 
    /* Item and Gobject */
    ITEM_KEY_TO_FOCUSING_IRIS      = 44582,
    ITEM_KEY_TO_FOCUSING_IRIS_H    = 44581,
    GO_FOCUSING_IRIS               = 193958,
    GO_EXIT_PORTAL                 = 193908,


    /* Step 1 */
    NPC_AOE_TRIGGER                = 22517,
    NPC_VORTEX                     = 30090,
    NPC_POWER_SPARK                = 30084,
    NPC_SPARK_PORTAL               = 30118, // For power sparks
    VEHICLE_VORTEX                 = 168,
 
    /* Step 2 */
    NPC_HOVER_DISC                 = 30248, // Maybe wrong, two following NPC flying on them (vehicle)
    DISPLAY_HOVER_DISC             = 26876, // DisplayID of hover disc
    NPC_NEXUS_LORD                 = 30245, // two (?) of them are spawned on beginning of phase 2
    NPC_SCION_OF_ETERNITY          = 30249, // same, but unknow count
    NPC_ARCANE_OVERLOAD            = 30282, // Bubles
    GO_PLATFORM                    = 193070,
 
    /* Step 3 */
    NPC_SURGE_OF_POWER             = 30334, // Because its on three targets, malygos cant cast it by hymself
    NPC_STATIC_FIELD               = 30592, // Trigger for that spell. Hope its fly
 
    /* Step 4 */
    NPC_ALEXSTRASZA                = 32295,  // The Life-Binder
    GO_ALEXSTRASZAS_GIFT           = 193905, // Loot chest
    GO_ALEXSTRASZAS_GIFT_H         = 193967, // Loot chest
      
    CHASE_MOTION_TYPE              = 5,
 
    /* Say SD2 */
    SAY_INTRO1                     = -1616000,
    SAY_INTRO2                     = -1616001,
    SAY_INTRO3                     = -1616002,
    SAY_INTRO4                     = -1616003,
    SAY_INTRO5                     = -1616004,
    SAY_INTRO_PHASE3               = -1616018,
    SAY_AGGRO1                     = -1616005,
    SAY_AGGRO2                     = -1616013,
    SAY_AGGRO3                     = -1616019,
    SAY_VORTEX                     = -1616006,
    WHISPER_POWER_SPARK            = -1616035,
    WHISPER_LOOK_ME                = -1616036,
    SAY_POWER_SPARK_BUFF           = -1616007,
    SAY_KILL1_1                    = -1616008,
    SAY_KILL1_2                    = -1616009,
    SAY_KILL1_3                    = -1616010,
    SAY_KILL2_1                    = -1616020,
    SAY_KILL2_2                    = -1616021,
    SAY_KILL2_3                    = -1616022,
    SAY_KILL3_1                    = -1616023,
    SAY_KILL3_2                    = -1616024,
    SAY_KILL3_3                    = -1616025,
    SAY_END_PHASE1                 = -1616012,
    SAY_END_PHASE2                 = -1616017,
    SAY_ARCANE_PULSE           = -1616014,
    SAY_ARCANE_PULSE_WARN      = -1616015,
    SAY_ARCANE_OVERLOAD        = -1616016,
    SAY_SURGE_OF_POWER         = -1616026,
    SAY_CAST_SPELL1            = -1616027,
    SAY_CAST_SPELL2            = -1616028,
    SAY_CAST_SPELL3            = -1616029,
    SAY_OUTRO1                 = -1616030,
    SAY_OUTRO2                 = -1616031,
    SAY_OUTRO3                 = -1616032,
    SAY_OUTRO4                 = -1616033,
    SAY_OUTRO5                 = -1616034,
 
    SHELL_MIN_X                = 722,
    SHELL_MAX_X                = 768,
    SHELL_MIN_Y                = 1290,
    SHELL_MAX_Y                = 1339,
 
    NEXUS_LORD_COUNT           = 2,
    NEXUS_LORD_COUNT_H         = 4,
    SCION_OF_ETERNITY_COUNT    = 4,
    SCION_OF_ETERNITY_COUNT_H  = 6,
 
    // Phase 1
    PHASE_NOSTART              = 0,
    SUBPHASE_FLY_DOWN1         = 04,
    SUBPHASE_FLY_DOWN2         = 05,
    SUBPHASE_WAIT              = 06,

    // Phase 2
    PHASE_FLOOR                = 1,
    SUBPHASE_VORTEX            = 11,

    PHASE_ADDS                 = 2,
    SUBPHASE_TALK              = 21,

    PHASE_DRAGONS              = 3,
    SUBPHASE_DESTROY_PLATFORM1 = 31,
    SUBPHASE_DESTROY_PLATFORM2 = 32,
    SUBPHASE_DESTROY_PLATFORM3 = 33,

    PHASE_OUTRO                = 4,
    SUBPHASE_STOP_COMBAT       = 41,
    SUBPHASE_DIE               = 42,
};

struct Locations
{
    float x, y, z, o;
    uint32 id;
};

struct LocationsXY
{
    float x, y;
    uint32 id;
};

static Locations GOPositions[]=
{
    {754.346f, 1300.87f, 256.249f, 3.14159f},   // Raid Platform position
    {754.731f, 1300.12f, 266.171f, 5.01343f},   // Focusing iris and Alexstrazas gift
    {724.684f, 1332.92f, 267.234f, -0.802851f}, // Exit Portal
};

static LocationsXY SparkLoc[]=
{
    {681.772f, 1232.393f},
    {815.205f, 1373.234f},
    {680.982f, 1363.125f},
    {827.01f, 1232.649f},
};
 
//Also spawn locations for scions of eternity
static LocationsXY VortexLoc[]=
{
    {754, 1311},
    {734, 1334},
    {756, 1339},
    {781, 1329},
    {791, 1311},
    {790, 1283},
    {768, 1264},
    {739, 1261},
    {720, 1280},
    {714, 1299},
    {716, 1318},
    {734, 1334},
    {756, 1339},
    {781, 1329},
    {791, 1311},
    {790, 1283},
    {768, 1264},
    {739, 1261},
    {720, 1280},
    {714, 1299},
    {716, 1318},
};

static Locations OtherLoc[]=
{
    {808, 1301, 268, 0},          // Phase 3 position 
    {749, 1244, 332, 1.544f},      // Vortex FarSight loc
    {754.29f, 1301.18f, 266.17f, 0}, // Center of the platform, ground.
    {823, 1241, 299, 0},          // Alexstrasza's  position
    {749, 1244, 266.17f, 5.33f},       // Aggro position after Subphase fly down
};

#define MAX_VORTEX      21
#define VORTEX_Z        268
#define FLOOR_Z         266.18f
#define FALL_FROM_Z     287.20f
#define AIR_Z           297.24f

class boss_malygos : public CreatureScript
{
public:
    boss_malygos() : CreatureScript("boss_malygos") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_malygosAI (pCreature);
    }

    struct boss_malygosAI : public ScriptedAI
    {
        boss_malygosAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            m_pInstance = (InstanceScript*)pCreature->GetInstanceScript();
            me->setActive(true);
            Reset();
            m_uiIs10Man = RAID_MODE(true, false);
        }
 
        InstanceScript* m_pInstance;
        
        uint64 m_AlexstraszaGUID;
        
        uint8 m_uiPhase; //Fight Phase
        uint8 m_uiSubPhase; //Subphase if needed
        uint8 m_uiSpeechCount;
        uint8 m_uiVortexPhase;
        std::list<uint64> m_lDiscGUIDList;
        std::list<std::pair<uint64, uint64> > m_uiMounts; // Vehicle(GUID)-Player(GUID) pairs
        
        bool m_uiIsDown;
        bool m_uiIsMounted; 
        bool m_uiIs10Man;
        
        uint32 m_uiFallToMountTimer;
        uint32 m_uiEnrageTimer;
        uint32 m_uiSpeechTimer[5];
        uint32 m_uiTimer;
        uint32 m_uiVortexTimer;
        uint32 m_uiArcaneBreathTimer;
        uint32 m_uiPowerSparkTimer;
        uint32 m_uiDeepBreathTimer;
        uint32 m_uiShellTimer;
        uint32 m_uiArcaneStormTimer;
        uint32 m_uiStaticFieldTimer;
        uint32 m_uiArcanePulseTimer;
        uint32 m_uiSurgeOfPowerTimer;
        uint32 m_uiCheckDisksTimer;
        uint32 m_uiWipeCheckTimer;
        uint32 m_uiSurgeVisual;
        
        void Reset()
        {
            if(m_pInstance)
            {
                m_pInstance->SetData(TYPE_MALYGOS, NOT_STARTED);
            }
            else
            {
                me->ForcedDespawn();
            }

            me->SetFlying(true);
            me->setActive(true);
            me->RemoveUnitMovementFlag(MOVEMENTFLAG_LEVITATING);

            m_uiPhase = PHASE_NOSTART;
            m_uiSubPhase = 0;
            m_uiSpeechCount = 0;
            m_uiVortexPhase = 0;
            m_uiMounts.clear();
            
            m_uiIsDown = false;        
            m_uiIsMounted = false; 
                
            m_uiFallToMountTimer = 3000;
            m_uiEnrageTimer = 600000;
            m_uiSpeechTimer[0] = 15000;
            m_uiSpeechTimer[1] = 18000;
            m_uiSpeechTimer[2] = 19000;
            m_uiSpeechTimer[3] = 21000;
            m_uiSpeechTimer[4] = 18000;
            m_uiSpeechTimer[5] = 17000;
            m_uiTimer = 7000;
            m_uiVortexTimer = 10000;
            m_uiArcaneBreathTimer = 15000;
            m_uiPowerSparkTimer = 30000;
            m_uiDeepBreathTimer = 70000;
            m_uiShellTimer = 0;
            m_uiArcaneStormTimer = 15000;
            m_uiStaticFieldTimer = 15000;
            m_uiArcanePulseTimer = 1000;
            m_uiSurgeOfPowerTimer = 30000;
            m_uiCheckDisksTimer = 2500;
            m_uiWipeCheckTimer = 2500;
            m_uiSurgeVisual = 0;
            m_AlexstraszaGUID = 0;
            
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->SetUInt32Value(UNIT_FIELD_BYTES_0, 50331648);
            me->SetUInt32Value(UNIT_FIELD_BYTES_1, 50331648);
            me->SetSpeed(MOVE_FLIGHT, 3.5f, true);
            me->SetSpeed(MOVE_RUN, 3.5f, true);
            me->SetSpeed(MOVE_WALK, 3.5f, true);

            // Despawn all summoned creatures
            DespawnCreatures(NPC_POWER_SPARK, 300.0f);
            DespawnCreatures(NPC_ARCANE_OVERLOAD, 300.0f);
            DespawnCreatures(NPC_NEXUS_LORD, 300.0f);
            DespawnCreatures(NPC_SCION_OF_ETERNITY, 300.0f);
            DespawnCreatures(NPC_HOVER_DISC, 300.0f, true);
            DespawnCreatures(NPC_STATIC_FIELD, 300.0f);
        }

        void MoveInLineOfSight(Unit* who)
        {
            if(who->GetEntry() == NPC_POWER_SPARK && who->GetDistance2d(me->GetPositionX(), me->GetPositionY()) < 30.0f && !who->HasAura(SPELL_POWER_SPARK_PLAYERS))
            {
                who->GetMotionMaster()->MovePoint(1, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ());
            }
        }

        void AttackStart(Unit* pWho)
        {
            if(m_uiPhase != PHASE_FLOOR && m_uiPhase != PHASE_DRAGONS && !me->HasAura(SPELL_BERSERK))
            {
                return;
            }
     
            if (pWho && me->Attack(pWho, true))
            {
                me->AddThreat(pWho, 1.0f);
                me->SetInCombatWith(pWho);
                pWho->SetInCombatWith(me);
                if(m_uiPhase != PHASE_DRAGONS && !me->HasAura(SPELL_BERSERK))
                {
                    me->GetMotionMaster()->MoveChase(pWho);
                }
            }
        }
        void EnterCombat(Unit* pWho)
        {
            me->SetInCombatWithZone();
            me->SetSpeed(MOVE_FLIGHT, 1.0f, true);
            me->SetSpeed(MOVE_RUN, 1.0f, true);
            me->SetSpeed(MOVE_WALK, 1.0f, true);
            m_pInstance->SetData(TYPE_MALYGOS, IN_PROGRESS);
            DoScriptText(SAY_AGGRO1, me);
            
            if(m_pInstance->GetData(TYPE_OUTRO_CHECK) == 1) //Should be enought to trigger outro immediatly
            {
                me->SetFlying(true);

                //Destroy Platform
                CastSpellToTrigger(SPELL_DESTROY_PLATFROM_BOOM, false);
                m_pInstance->SetData(TYPE_DESTROY_PLATFORM, IN_PROGRESS);
                       
                //Mount Players
                PrepareMounts();
                MountPlayers();
                
                m_uiPhase = PHASE_OUTRO;
                m_uiSubPhase = SUBPHASE_STOP_COMBAT;
            }
        }

        void DamageTaken(Unit* pDoneBy, uint32 &uiDamage)
        {
            if (m_uiPhase == PHASE_OUTRO && m_uiSubPhase != SUBPHASE_DIE)
            {
                uiDamage = 0;
                return;
            }
     
            if (uiDamage >= me->GetHealth() && m_uiSubPhase != SUBPHASE_DIE)
            {
                m_uiPhase = PHASE_OUTRO;
                m_uiSubPhase = SUBPHASE_STOP_COMBAT;
                uiDamage = 0;
            }
        }

        void JustDied(Unit* pKiller)
        {
            m_pInstance->SetData(TYPE_MALYGOS, DONE);
            m_pInstance->SetData(TYPE_OUTRO_CHECK, 0);
        }

        void KilledUnit(Unit* pVictim)
        {
            uint8 text = 0;

            switch(m_uiPhase)
            {
                case PHASE_FLOOR:
                    text = urand(0, 2);
                    break;
                case PHASE_ADDS:
                    text = urand(3, 5);
                    break;
                case PHASE_DRAGONS:
                    text = urand(6, 8);
                    break;
                default:
                return;
                break;
            }

            switch(text)
            {
                case 0: DoScriptText(SAY_KILL1_1, me); break;
                case 1: DoScriptText(SAY_KILL1_2, me); break;
                case 2: DoScriptText(SAY_KILL1_3, me); break;
     
                case 3: DoScriptText(SAY_KILL2_1, me); break;
                case 4: DoScriptText(SAY_KILL2_2, me); break;
                case 5: DoScriptText(SAY_KILL2_3, me); break;
     
                case 6: DoScriptText(SAY_KILL3_1, me); break;
                case 7: DoScriptText(SAY_KILL3_2, me); break;
                case 8: DoScriptText(SAY_KILL3_3, me); break;

                default:
                break;
            }

            if(m_uiPhase == PHASE_DRAGONS)
            {
                if(pVictim->GetEntry() == NPC_WYRMREST_SKYTALON)
                {
                    for(std::list<std::pair<uint64, uint64> >::iterator iter = m_uiMounts.begin(); iter != m_uiMounts.end(); ++iter)
                    {
                        if(pVictim->GetGUID() == (*iter).first)
                        {
                            m_uiMounts.erase(iter);
                            return;
                        }
                    }
                }
            }
        }

        void SpellHit(Unit* pCaster, const SpellEntry* pSpell)
        {
            if(pSpell->Id == SPELL_POWER_SPARK && m_uiPhase == PHASE_FLOOR)
            {
                DoScriptText(SAY_POWER_SPARK_BUFF, me);
            }
            else
            {
                if(pSpell->Id == SPELL_POWER_SPARK && m_uiPhase != PHASE_FLOOR)
                {
                    me->RemoveAurasDueToSpell(SPELL_POWER_SPARK);
                }
            }
        }

        void MoveFly(bool up)
        {
            if(up)
            {
                SetCombatMovement(false);
                me->SetFlying(true);
                //me->HandleEmoteCommand(EMOTE_ONESHOT_FLY_SIT_GROUND_UP);
                //me->RemoveUnitMovementFlag(MOVEMENTFLAG_FLYING);
                me->SendMovementFlagUpdate();
                me->GetMotionMaster()->MoveJump(OtherLoc[2].x, OtherLoc[2].y, FLOOR_Z+20, 1.0f, 1.0f);
            }
            else //down
            {
                me->Relocate(OtherLoc[2].x, OtherLoc[2].y, FLOOR_Z);
                me->SendMovementFlagUpdate();
                me->HandleEmoteCommand(EMOTE_ONESHOT_FLY_SIT_GROUND_DOWN);
                me->SetFlying(false);
                SetCombatMovement(true);
            }
        }

        void HoverDisk(Position &pos)
        {
            pos.m_positionZ = FLOOR_Z;
            Creature * pDisc = me->SummonCreature(NPC_HOVER_DISC, pos);
            if(pDisc)
            {
                pDisc->SetSpeed(MOVE_FLIGHT, 3.5f, true);
                pDisc->SetSpeed(MOVE_RUN, 3.5f, true);
                pDisc->SetSpeed(MOVE_WALK, 3.5f, true);
                m_lDiscGUIDList.push_back(pDisc->GetGUID());
            }
        }

        void SummonedCreatureDespawn(Creature* pWho)
        {
            uint32 entry = pWho->GetEntry();
            if ((entry == NPC_SCION_OF_ETERNITY) || (entry == NPC_NEXUS_LORD))
            {
                Position pos;
                pWho->GetPosition(&pos);
                HoverDisk(pos);
            }
        }

        void CastSpellToTrigger(uint32 uiSpellId, bool triggered = true, bool triggerCast = false)
        {      
            if(Creature *pTrigger = me->SummonCreature(NPC_VORTEX, OtherLoc[2].x, OtherLoc[2].y, OtherLoc[2].z, 0, TEMPSUMMON_TIMED_DESPAWN, 10000))
            {
               if(!triggerCast)
               {
                 pTrigger->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                 pTrigger->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                 pTrigger->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                 pTrigger->setFaction(me->getFaction());
                 pTrigger->CastSpell(pTrigger, uiSpellId, triggered);
               }
               else 
               {
                   pTrigger->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                   DoCast(pTrigger, uiSpellId, triggered);
               }
            }      
        }     
        void DoVortex(uint8 phase)
        {
            if(phase == 0)
            {
                MoveFly(true);
            }
            else if(phase == 1)
            {
                CastSpellToTrigger(SPELL_VORTEX_AOE_VISUAL, false);

                Map* pMap = me->GetMap();
                if(!pMap)
                {
                    return;
                }
     
                Map::PlayerList const &lPlayers = pMap->GetPlayers();
                for(Map::PlayerList::const_iterator itr = lPlayers.begin(); itr != lPlayers.end(); ++itr)
                {
                    if(!itr->getSource()->isAlive())
                    {
                        continue;
                    }

                    itr->getSource()->NearTeleportTo(VortexLoc[0].x, VortexLoc[0].y, FALL_FROM_Z, 0); 
                    itr->getSource()->CastSpell(itr->getSource(), SPELL_VORTEX, true, NULL, NULL, me->GetGUID());

                    if(Creature *pVortex = me->SummonCreature(NPC_VORTEX, OtherLoc[1].x, OtherLoc[1].y, OtherLoc[1].z, OtherLoc[1].o, TEMPSUMMON_TIMED_DESPAWN, 11000))
                    {                    
                        pVortex->SetVisible(false);    
                        pVortex->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                    }
                }        
            }
            else if(phase > 1 && phase < 26)
            {
                Map* pMap = me->GetMap();
                if(!pMap)
                {
                    return;
                }

                if(Creature *pVortex = me->SummonCreature(NPC_VORTEX, VortexLoc[phase-1].x, VortexLoc[phase-1].y, VORTEX_Z, 0, TEMPSUMMON_TIMED_DESPAWN, 10000))
                {
                    pVortex->SetVisible(false);
                    pVortex->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                    Map::PlayerList const &lPlayers = pMap->GetPlayers();
                    for(Map::PlayerList::const_iterator itr = lPlayers.begin(); itr != lPlayers.end(); ++itr)
                    {
                        if(!itr->getSource()->isAlive())
                        {
                            continue;
                        }
     
                        float z = itr->getSource()->GetPositionZ() - VORTEX_Z;
                        itr->getSource()->KnockbackFrom(pVortex->GetPositionX(), pVortex->GetPositionY(),-float(pVortex->GetDistance2d(itr->getSource())),7);
                        itr->getSource()->SetFacingToObject(me);
                    }
                }
            }
            else if (phase == 30 || phase == 31)
            {    
                if(phase == 31)
                {
                    me->SetFlying(false);
                    if(me->getVictim())
                    {
                        me->GetMotionMaster()->MoveChase(me->getVictim());
                    }

                    Creature* pVortex = GetClosestCreatureWithEntry(me, NPC_VORTEX, 100.0f);
                    if(pVortex)
                    {
                        pVortex->ForcedDespawn();
                    }
                    
                    m_uiSubPhase = 0;
                    return;
                }

                Map* pMap = me->GetMap();
                if(!pMap)
                {
                    return;
                }

                Map::PlayerList const &lPlayers = pMap->GetPlayers();
                for(Map::PlayerList::const_iterator itr = lPlayers.begin(); itr != lPlayers.end(); ++itr)
                {
                    itr->getSource()->SetUInt64Value(PLAYER_FARSIGHT, 0);
                    itr->getSource()->NearTeleportTo(VortexLoc[0].x, VortexLoc[0].y, FALL_FROM_Z, 0);
                }

                MoveFly(false);
            }
        }

        void PowerSpark(uint8 action)
        {
            if (m_pInstance && m_pInstance->instance)
            {
                Map::PlayerList const &PlayerList = m_pInstance->instance->GetPlayers();
                if (!PlayerList.isEmpty())
                {
                    for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                    {
                        DoScriptText(WHISPER_POWER_SPARK, me, i->getSource());
                    }
                }
            }

            uint8 random = urand(0, 3);
            if(Creature *pSpark = me->SummonCreature(NPC_POWER_SPARK, SparkLoc[random].x, SparkLoc[random].y, FLOOR_Z+10, 0, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 120000))
            {
                pSpark->CastSpell(pSpark, SPELL_POWER_SPARK_VISUAL, false);
                pSpark->GetMotionMaster()->MoveFollow(me, 0, 0);
            }
        }

        void DoSpawnAdds()
        {
            //Nexus lords
            int max_lords = m_uiIs10Man ? NEXUS_LORD_COUNT :NEXUS_LORD_COUNT_H;
            for(int i=0; i < max_lords;i++)
            {
                if(Creature *pLord = me->SummonCreature(NPC_NEXUS_LORD, me->getVictim()->GetPositionX()-5+rand()%10, me->getVictim()->GetPositionY()-5+rand()%10, me->getVictim()->GetPositionZ(), 0, TEMPSUMMON_CORPSE_DESPAWN, 0))
                {
                    pLord->AI()->AttackStart(me->getVictim());
                }
            }

            //Scions of eternity
            int max_scions = m_uiIs10Man ? SCION_OF_ETERNITY_COUNT : SCION_OF_ETERNITY_COUNT_H;
            for(int i=0; i < max_scions;i++)
            {
                uint32 tmp = urand(1, 10);
                if(Creature *pScion = me->SummonCreature(NPC_SCION_OF_ETERNITY, VortexLoc[tmp].x, VortexLoc[tmp].y, FLOOR_Z+10, 0, TEMPSUMMON_CORPSE_DESPAWN, 0))
                {
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    {
                        pScion->AI()->AttackStart(pTarget);
                    }
                }
            }       
        }

        bool IsThereAnyAdd()
        {
            //Search for Nexus lords
            if(GetClosestCreatureWithEntry(me, NPC_NEXUS_LORD, 180.0f))
            {
                return true;
            }
     
            //Search for Scions of eternity
            if(GetClosestCreatureWithEntry(me, NPC_SCION_OF_ETERNITY, 180.0f))
            {
                return true;
            }
			
            return false;
		}

        void DoSpawnShell()
        {
            float x = (float)urand(SHELL_MIN_X,SHELL_MAX_X);
            float y = (float)urand(SHELL_MIN_Y,SHELL_MAX_Y);
            if(Creature *pShell = me->SummonCreature(NPC_ARCANE_OVERLOAD, x, y, FLOOR_Z, 0, TEMPSUMMON_TIMED_DESPAWN, 45000))
            {
                pShell->CastSpell(pShell, SPELL_ARCANE_BOMB, false);
            }
        }

        void PrepareMounts()
        {
            Map *pMap = me->GetMap();
     
            if(!pMap)
            {
                return;
            }
     
            Map::PlayerList const &lPlayers = pMap->GetPlayers();
            if(lPlayers.isEmpty())
            {
                return;
            }
            
            for(Map::PlayerList::const_iterator itr = lPlayers.begin(); itr != lPlayers.end(); ++itr)
            {
                if(Player* pPlayer = itr->getSource())
                { 
                    if(Creature *pTemp = me->SummonCreature(NPC_WYRMREST_SKYTALON, pPlayer->GetPositionX(), pPlayer->GetPositionY(), 210, 0))
                    {
                        //m_uiMounts.push_back(pTemp);
                        m_uiMounts.push_back(std::pair<uint64, uint64>(pTemp->GetGUID(), pPlayer->GetGUID()));
                    }
                }
            }
        }

        void MountPlayers()
        {
            Map *pMap = me->GetMap();
     
            if(!pMap)
            {
                return;
            }
     
            Map::PlayerList const &lPlayers = pMap->GetPlayers();
            if (lPlayers.isEmpty())
            {
                return;
            }
            
            for(std::list<std::pair<uint64, uint64> >::iterator iter = m_uiMounts.begin(); iter != m_uiMounts.end(); ++iter)
            {
                Creature *pTemp = (Creature*)Unit::GetUnit(*me, (*iter).first);
                Player *pPlayer = (Player*)Unit::GetUnit(*me, (*iter).second);

                if(!pTemp)
                {
                    continue;
                }

                if(!pPlayer)
                {
                    continue;
                }

                pTemp->SetCreatorGUID(pPlayer->GetGUID());
                me->AddThreat(pTemp, 1.0f);  // To not leave combat
                pPlayer->EnterVehicle(pTemp, 0);
                pTemp->SetMaxHealth(100000);
                pTemp->SetHealth(100000);
                pTemp->SetFacingToObject(me);
            }
        }

        void DespawnCreatures(uint32 entry, float distance, bool discs = false)
        {
            //Because vehicles cant be found by GetCreatureListWithEntryInGrid()
            if(discs)
            {
                if(m_lDiscGUIDList.empty())
                {
                    return;
                }
                    
                for(std::list<uint64>::iterator iter = m_lDiscGUIDList.begin(); iter != m_lDiscGUIDList.end(); ++iter)
                {
                    Creature* pDisk = ObjectAccessor::GetCreatureOrPetOrVehicle(*me,*iter);
                    if(pDisk)
                    {
                        pDisk->ForcedDespawn();
                    }
                }
                    
                m_lDiscGUIDList.clear();
                return;
            }
     
            std::list<Creature*> m_pCreatures;
            GetCreatureListWithEntryInGrid(m_pCreatures, me, entry, distance);
     
            if (m_pCreatures.empty())
            {
                return;
            }
     
            for(std::list<Creature*>::iterator iter = m_pCreatures.begin(); iter != m_pCreatures.end(); ++iter)
            {
                (*iter)->ForcedDespawn();
            }
        }
                
        //Spell not in DBC, but on retail client recieve its opcode, so..
        void SendDeepBreathCast()
        {
            WorldPacket data(SMSG_SPELL_GO, 50);
            data.append(me->GetPackGUID());
     
            data.append(me->GetPackGUID());
            data << uint8(1);
            data << uint32(SPELL_DEEP_BREATH);
            data << uint32(256);
            data << uint32(getMSTime());
     
            data << uint8(0);
            data << uint8(0);
            data << uint8(0);
     
            me->SendMessageToSet(&data, false);
        }

        void CastSurgeOfPower()
        {
            Creature* SurgeOfPower = NULL;
            
            SurgeOfPower = GetClosestCreatureWithEntry(me, NPC_SURGE_OF_POWER, 200.0f, true);
            if(!SurgeOfPower)
            {
                SurgeOfPower = me->SummonCreature(NPC_SURGE_OF_POWER, 754.29f, 1301.18f, me->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 10000);
                if(!SurgeOfPower)
                {
                    return;
                }
            }

            SurgeOfPower->SetFlying(true);
            SurgeOfPower->SetHealth(100000);
            SurgeOfPower->setFaction(14);
            SurgeOfPower->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
            SurgeOfPower->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            SurgeOfPower->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            SurgeOfPower->SetDisplayId(11686);

            me->CastSpell(SurgeOfPower, 56505, false);

            SurgeOfPower->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        }

        void DoAction(const int32 id)
        {
            if(id == 0)
            {
                m_uiSubPhase = SUBPHASE_FLY_DOWN1;
            }
        }

        void MovementInform(uint32, uint32 id)
        {
            switch (id)
            {
                case 1:
                m_uiSubPhase = SUBPHASE_FLY_DOWN2;
                break;
            }
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (m_uiPhase == PHASE_NOSTART)
            {
                if (m_uiSubPhase == SUBPHASE_WAIT)
                                {
                    return;
                                }

                if (m_uiSubPhase == SUBPHASE_FLY_DOWN1)
                {
                    me->InterruptNonMeleeSpells(false);
                    me->RemoveAurasDueToSpell(SPELL_PORTAL_BEAM);
                    me->GetMotionMaster()->Clear(false);
                    me->GetMotionMaster()->MovePoint(1, OtherLoc[2].x, OtherLoc[2].y, FLOOR_Z+25);
                    m_uiSubPhase = SUBPHASE_WAIT;
                }
                else if (m_uiSubPhase == SUBPHASE_FLY_DOWN2)
                {
                    MoveFly(false);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    m_uiSubPhase = 0;
                    m_uiPhase = PHASE_FLOOR;
                    return;
                }  
                else
                {
                    //Speech
                    if(m_uiSpeechTimer[m_uiSpeechCount] <= uiDiff)
                    {
                        DoScriptText(SAY_INTRO1-m_uiSpeechCount, me);
                        m_uiSpeechCount++;
                                                
                        if (m_uiSpeechCount == 5)
                        {
                            m_uiSpeechCount = 0;
                            m_uiSpeechTimer[0] = 15000;
                            m_uiSpeechTimer[1] = 18000;
                            m_uiSpeechTimer[2] = 19000;
                            m_uiSpeechTimer[3] = 21000;
                            m_uiSpeechTimer[4] = 18000;
                            m_uiSpeechTimer[5] = 17000;
                        }
                    }
                    else
                                        {
                                                m_uiSpeechTimer[m_uiSpeechCount] -= uiDiff;
                                        }
                                        
                    //Random movement over platform
                    if(m_uiTimer <= uiDiff)
                    {
                        uint8 tmp = urand(0,3);
                        me->GetMotionMaster()->MovePoint(0, SparkLoc[tmp].x, SparkLoc[tmp].y, AIR_Z);
                        m_uiTimer = 25000;
                    }
                                        else
                                        {
                                                m_uiTimer -= uiDiff;
                                        }
                }
            }
                        

            if(m_uiPhase == PHASE_DRAGONS)
            {
                if(m_uiWipeCheckTimer < uiDiff)
                {
                    if(m_pInstance)
                    {
                        Map* pMap = me->GetMap();
                        if(!pMap)
                        {
                            return;
                        }

                        bool player_found = false;
                        Map::PlayerList const &lPlayers = pMap->GetPlayers();
                        for(Map::PlayerList::const_iterator itr = lPlayers.begin(); itr != lPlayers.end(); ++itr)
                        {
                            player_found = true;
                            break;
                        }

                        if(!player_found)
                        {
                            Creature* pTrigger = GetClosestCreatureWithEntry(me, 30494, 100.0f);
                            if(pTrigger)
                            {
                                pTrigger->ForcedDespawn();
                            }
                                                        
                            me->AI()->EnterEvadeMode();
                        }
                    }
                    m_uiWipeCheckTimer = 2500;
                }
                                else
                                {
                                        m_uiWipeCheckTimer -= uiDiff;
                                }
            }
     
            if (!UpdateVictim())
            {
                return;
            }

            //Enrage timer.....
            if(m_uiEnrageTimer <= uiDiff)
            {
                DoCast(me, SPELL_BERSERK);
                m_uiEnrageTimer = 600000;
                me->SetSpeed(MOVE_FLIGHT, 3.5f, true);
                me->SetSpeed(MOVE_RUN, 3.5f, true);
                me->SetSpeed(MOVE_WALK, 3.5f, true);
                me->GetMotionMaster()->MoveChase(me->getVictim());
            }
            else
            {
                m_uiEnrageTimer -= uiDiff;
            }
     
            if(m_uiPhase == PHASE_FLOOR)
            {
                if(m_uiSubPhase == SUBPHASE_VORTEX)
                {
                    if(m_uiTimer <= uiDiff)
                    {
                        DoVortex(m_uiVortexPhase);
                        
                        if(m_uiVortexPhase == 1 || m_uiVortexPhase == 11)
                        {
                            if(m_uiVortexPhase == 1)
                                                        {
                                DoCast(me, SPELL_VORTEX_DUMMY);
                                                        }
                                                        
                            m_uiTimer = 300;
                        }
                                                else
                                                {
                            m_uiTimer = 500;
                                                }
     
                        if(m_uiVortexPhase >= MAX_VORTEX && m_uiVortexPhase < 29)
                        {
                            m_uiVortexPhase = 30;
                            DoVortex(m_uiVortexPhase);
                            //PowerSpark(2);
                            if(m_pInstance)
                                                        {
                                m_pInstance->SetData(TYPE_VORTEX, 0);
                                                        }

                            m_uiTimer = 1000;
                            return;
                        }
                                                
                        m_uiVortexPhase++;
                    }
                                        else
                                        {
                                                m_uiTimer -= uiDiff;
                                        }
                    return;
                }
                //Vortex
                if(m_uiVortexTimer <= uiDiff)
                {
                    //PowerSpark(3);
                    if(m_pInstance)
                                        {
                        m_pInstance->SetData(TYPE_VORTEX, 1);
                                        }
                                        
                    MoveFly(true);
                    this->DespawnCreatures(NPC_VORTEX, 200.0f);
                    DoVortex(0);
                    m_uiVortexPhase = 1;
                    m_uiSubPhase = SUBPHASE_VORTEX;
                    m_uiVortexTimer = 56000;
                    m_uiTimer = 6000;
                    DoScriptText(SAY_VORTEX, me);
                    return;
                }
                                else
                                {
                                        m_uiVortexTimer -= uiDiff;
                                }
     
                //Arcane Breath
                if(m_uiArcaneBreathTimer <= uiDiff)
                {
                    DoCast(me, m_uiIs10Man ? SPELL_ARCANE_BREATH : SPELL_ARCANE_BREATH_H);
                    m_uiArcaneBreathTimer = 10000 + urand(2000, 8000);
                }
                                else
                                {
                                        m_uiArcaneBreathTimer -= uiDiff;
                                }
     
                //PowerSpark
                if(m_uiPowerSparkTimer<= uiDiff)
                {
                    PowerSpark(1);
                    m_uiPowerSparkTimer = 30000;
                }
                                else
                                {
                                        m_uiPowerSparkTimer -= uiDiff;
                                }
     
                //Health check
                if(m_uiTimer<= uiDiff)
                {
                    uint8 health = me->GetHealth()*100 / me->GetMaxHealth();                    
                    if(health <= 50)
                    {
                        me->InterruptNonMeleeSpells(true);
                        MoveFly(true);

                        DoScriptText(SAY_END_PHASE1, me);
                        me->GetMotionMaster()->MovePoint(0, OtherLoc[2].x, OtherLoc[2].y, OtherLoc[2].z+40);
                        //Despawn power sparks
                        DespawnCreatures(NPC_POWER_SPARK, 180.0f);
                        m_uiPhase = PHASE_ADDS;
                        m_uiSubPhase = SUBPHASE_TALK;
                        m_uiTimer = 23000;
                        return;
                    }
                                        
                    m_uiTimer = 1500;
                }
                                else
                                {
                                        m_uiTimer -= uiDiff;
                                }

                DoMeleeAttackIfReady();
            }
            else if (m_uiPhase == PHASE_ADDS)
            {
                if(m_uiSubPhase == SUBPHASE_TALK)
                {
                    if(m_uiTimer <= uiDiff)
                    {
                        DoScriptText(SAY_AGGRO2, me);
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        DoSpawnAdds();
                        DoSpawnShell();
                        m_uiShellTimer = 20000;
                        m_uiSubPhase = 0;
                        m_uiTimer = 15000;
                    }
                                        else
                                        {
                                                m_uiTimer -= uiDiff;
                                        }
                    return;
                }
                
                //Arcane overload (bubble)
                if(m_uiShellTimer <= uiDiff)
                {
                    DoSpawnShell();
                    DoScriptText(SAY_ARCANE_OVERLOAD, me);
                    m_uiShellTimer = 20000;
                }
                                else
                                {
                                        m_uiShellTimer -= uiDiff;
                                }
     
                // Deep breath
                if(m_uiDeepBreathTimer <= uiDiff)
                {
                    DoScriptText(SAY_ARCANE_PULSE, me);
                    DoScriptText(SAY_ARCANE_PULSE_WARN, me);
                    SendDeepBreathCast();
                    CastSpellToTrigger(SPELL_SURGE_OF_POWER_BREATH, true, true);
                    CastSurgeOfPower();
                    m_uiSurgeVisual = 3200;
                    m_uiDeepBreathTimer = 60000;
                }
                                else
                                {
                                        m_uiDeepBreathTimer -= uiDiff;
                                }

                if(m_uiSurgeVisual)
                {
                    if(m_uiSurgeVisual <= uiDiff)
                    {
                        Creature* pSurge = GetClosestCreatureWithEntry(me, NPC_SURGE_OF_POWER, 100.0f);
                        if(pSurge)
                        {
                            pSurge->SetSpeed(MOVE_FLIGHT, 10.0f);
                            pSurge->SetSpeed(MOVE_RUN, 10.0f);
                            pSurge->SetSpeed(MOVE_WALK, 10.0f);
                            pSurge->GetMotionMaster()->MovePoint(1, 754.29f, 1301.18f, 266.17f);
                        }
                        m_uiSurgeVisual = 0;
                    }else m_uiSurgeVisual -= uiDiff;
                }
     
                // Arcane Storm
                if(m_uiArcaneStormTimer <= uiDiff)
                {
                    DoCast(me,  m_uiIs10Man ? SPELL_ARCANE_STORM : SPELL_ARCANE_STORM_H);
                    m_uiArcaneStormTimer = 20000;
                }
                                else
                                {
                                        m_uiArcaneStormTimer -= uiDiff;
                                }
     
                if(m_uiTimer <= uiDiff)
                {
                    if(!IsThereAnyAdd())
                    {
                        if(m_pInstance)
                            m_pInstance->SetData(TYPE_PLAYER_HOVER, DATA_DROP_PLAYERS);
                        DespawnCreatures(NPC_HOVER_DISC, 200.0f, true);
                        m_uiPhase = PHASE_DRAGONS;
                        m_uiSubPhase = SUBPHASE_DESTROY_PLATFORM1;
                        DoScriptText(SAY_END_PHASE2, me);
                        CastSpellToTrigger(SPELL_DESTROY_PLATFORM_PRE, false);
                        m_uiTimer = 6500;
                        return;
                    }
                    m_uiTimer = 5000;
                }
                                else
                                {
                                        m_uiTimer -= uiDiff;
                                }
     
                if(me->HasAura(SPELL_BERSERK))
                                {
                    DoMeleeAttackIfReady(); // this is there just for case of enrage
                                }
            }
            else if(m_uiPhase == PHASE_DRAGONS)
            {
                if(m_uiSubPhase == SUBPHASE_DESTROY_PLATFORM1)
                {
                    if(m_uiTimer<= uiDiff)
                    {
                        //Destroy Platform
                        CastSpellToTrigger(SPELL_DESTROY_PLATFROM_BOOM, false);
                        //Despawn bubbles and discs
                        DespawnCreatures(NPC_ARCANE_OVERLOAD, 70.0f);
                        DespawnCreatures(NPC_HOVER_DISC, 70.0f, true);
     
                        m_uiTimer = 2000;
                        m_uiSubPhase = SUBPHASE_DESTROY_PLATFORM2;
                    }
                                        else
                                        {
                                                m_uiTimer -= uiDiff;
                                        }
                    return;
                }
                else if(m_uiSubPhase == SUBPHASE_DESTROY_PLATFORM2)
                {
                    if(m_uiTimer <= uiDiff)
                    {
                        m_pInstance->SetData(TYPE_DESTROY_PLATFORM, IN_PROGRESS);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                                
                        if (Creature* m_uiSafeZone = me->SummonCreature(30494, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 360000)) //safe zone.. raid do not leave combat while mounting
                        {
                            m_uiSafeZone->AI()->AttackStart(me);
                            m_uiSafeZone->SetDisplayId(11686);
                        }
                                                
                        //Prepare Mounts
                        PrepareMounts();
                        me->GetMotionMaster()->MovePoint(0, OtherLoc[0].x, OtherLoc[0].y, OtherLoc[0].z+30);
                        DoScriptText(SAY_INTRO_PHASE3, me);
                        m_uiTimer = 14900;
                        m_uiFallToMountTimer = 1000;
                    }
                                        else
                                        {
                        m_uiTimer -= uiDiff;
                                        }

                    if(!m_uiIsMounted && m_uiFallToMountTimer <= uiDiff)
                    {
                        MountPlayers();
                        m_uiSubPhase = SUBPHASE_DESTROY_PLATFORM3;
                        m_uiIsMounted = true;
                    }
                                        else
                                        {
                        m_uiFallToMountTimer -= uiDiff;
                                        }
                    return;

                }
                                else if(m_uiSubPhase == SUBPHASE_DESTROY_PLATFORM3)
                {
                    if(m_uiTimer<= uiDiff)
                    {
                        m_uiSubPhase = 0;
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        SetCombatMovement(false);
                        me->GetMotionMaster()->Clear(false);        // No moving!
                        me->GetMotionMaster()->MoveIdle();
                        if(Unit *pVehicle = ((Unit*)Unit::GetUnit(*me, me->getVictim()->GetGUID())))
                        {
                            float victim_threat = me->getThreatManager().getThreat(me->getVictim());
                            DoResetThreat();
                            me->AI()->AttackStart(pVehicle);
                            me->AddThreat(pVehicle, victim_threat);
                        }
                        DoScriptText(SAY_AGGRO3, me);
                    }
                                        else
                                        {
                                                m_uiTimer -= uiDiff;
                                        }
                    return;
                }
                //Arcane Pulse
                if(m_uiArcanePulseTimer <= uiDiff)
                {
                    DoCast(me, SPELL_ARCANE_PULSE);
                    m_uiArcanePulseTimer = 1000;
                }
                                else
                                {
                                        m_uiArcanePulseTimer -= uiDiff;
                                }
     
                //Static field
                if(m_uiStaticFieldTimer <= uiDiff)
                {
                    if(Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                        {
                        if(Creature *pField = me->SummonCreature(NPC_STATIC_FIELD, pTarget->GetPositionX(), pTarget->GetPositionY(), pTarget->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 25000))
                        {
                            pField->SetMaxHealth(1000000);
                            pField->SetFlying(true);

                            pField->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                            pField->SetDisplayId(11686);
                            pField->Attack(pTarget, false);
                            pField->CastSpell(pField, SPELL_STATIC_FIELD, true);
                            pField->CastSpell(pField, 42716, true);
                        }
                                        }
                                        
                    DoScriptText(SAY_CAST_SPELL1-urand(0,2), me);
                    m_uiStaticFieldTimer = 10000+rand()%10000;
                }
                                else
                                {
                                        m_uiStaticFieldTimer -= uiDiff;
                                }
     
                //Surge of power
                if(m_uiSurgeOfPowerTimer <= uiDiff)
                {
                    for(int i = 0; i < 1; ++i)
                    {
                        // Use previously stored list of mount GUIDs
                        if(m_uiMounts.empty())
                                                {
                            continue;
                                                }

                        std::list<std::pair<uint64, uint64> >::iterator itr = m_uiMounts.begin();
                        int random = rand() % m_uiMounts.size();

                        for(int j = 0; j < random; ++j)
                                                {
                            ++itr;
                                                }
                        
                        Creature *pTarget = (Creature*)Unit::GetUnit(*me, (*itr).first);
                        Player *pPlayer = (Player*)Unit::GetUnit(*me, (*itr).second);

                        if(!pTarget || pTarget->GetEntry() != NPC_WYRMREST_SKYTALON)
                                                {
                            continue;
                                                }

                        if(!pPlayer)
                                                {
                            continue;
                                                }
         
                        if(i == 0)
                        {
                            DoCast(pTarget, SPELL_SURGE_OF_POWER);
                            DoScriptText(SAY_SURGE_OF_POWER, me);
                            me->MonsterWhisper(WHISPER_LOOK_ME, pPlayer->GetGUID(), true);
                        }
                        // Hit 3 targets on heroic
                        else
                        {
                            if(Creature* pSurge = DoSpawnCreature(NPC_SURGE_OF_POWER, 0, 0, 0, 0, TEMPSUMMON_TIMED_DESPAWN, 10000))
                            {
                                pSurge->SetFlying(true);
                                pSurge->Attack(pTarget, true);
                                pSurge->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                                pSurge->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                pSurge->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                                pSurge->CastSpell(pTarget, SPELL_SURGE_OF_POWER_H, false);
                                pSurge->GetMotionMaster()->MovePoint(1, pSurge->GetPositionX(), pSurge->GetPositionY(), pSurge->GetPositionZ() + 1);
                                me->MonsterWhisper(WHISPER_LOOK_ME, pPlayer->GetGUID(), true);
                            }
                        }
                    }

                    m_uiSurgeOfPowerTimer = 9000+rand()%6000;
                }
                                else
                                {
                                        m_uiSurgeOfPowerTimer -= uiDiff;
                                }
     
                if(me->HasAura(SPELL_BERSERK))
                                {
                    DoMeleeAttackIfReady();
                                }
            }
            //Outro!
            else if(m_uiPhase == PHASE_OUTRO)
            {
                if(m_uiSubPhase == SUBPHASE_STOP_COMBAT)
                {
                    m_pInstance->SetData(TYPE_OUTRO_CHECK, 1);
     
                    if (me->IsNonMeleeSpellCasted(false))
                                        {
                        me->InterruptNonMeleeSpells(false);
                                        }
     
                    me->RemoveAllAuras();
                    SetCombatMovement(false);
     
                    if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() == CHASE_MOTION_TYPE)
                                        {
                       me->GetMotionMaster()->MovementExpired();
                                        }
     
                    DespawnCreatures(NPC_STATIC_FIELD, 120.0f);
                
                    me->SetHealth(1);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    me->GetMotionMaster()->Clear(false);        // No moving!
                    me->GetMotionMaster()->MoveIdle();
                    m_uiSpeechCount = 0;
                    m_uiSpeechTimer[0] = 2000;
                    m_uiSpeechTimer[1] = 8500;
                    m_uiSpeechTimer[2] = 5000;
                    m_uiSpeechTimer[3] = 3000;
                    m_uiSpeechTimer[4] = 22000;
     
                    if(Creature *pTemp = me->SummonCreature(NPC_ALEXSTRASZA, OtherLoc[3].x, OtherLoc[3].y, OtherLoc[3].z+10, 0, TEMPSUMMON_CORPSE_DESPAWN, 0))
                    {
                        pTemp->SetUInt32Value(UNIT_FIELD_BYTES_0, 50331648);
                        pTemp->SetUInt32Value(UNIT_FIELD_BYTES_1, 50331648);
                        pTemp->SetFlying(true);
                        pTemp->SetFacingToObject(me);
                        pTemp->SetVisible(false);
                        m_AlexstraszaGUID = pTemp->GetGUID();
                    }
                    m_uiSubPhase = 0;
                    return;
                }
                if(m_uiSpeechCount >= 5 || m_uiSubPhase == SUBPHASE_DIE)
                                {
                    return;
                                }
     
                if(m_uiSpeechTimer[m_uiSpeechCount] <= uiDiff)
                {
                    Creature* pAlexstrasza = (Creature*)Unit::GetUnit(*me, m_AlexstraszaGUID);
     
                    if(m_uiSpeechCount || pAlexstrasza)
                                        {
                        DoScriptText(SAY_OUTRO1-m_uiSpeechCount, ( m_uiSpeechCount == 0 ) ? me : pAlexstrasza);
                                        }
     
                    switch(m_uiSpeechCount)
                    {
                        case 1:
                            //me->SetVisible(false);
                            pAlexstrasza->SetVisible(true);
                            pAlexstrasza->SetFacingToObject(me->getVictim());
                            break;
                        case 4:
                            m_uiSubPhase = SUBPHASE_DIE;
                            //Summon exit portal, platform and loot
                            me->SummonGameObject(GO_EXIT_PORTAL, GOPositions[2].x, GOPositions[2].y, GOPositions[2].z, GOPositions[2].o, 0, 0, 0, 0, 0);
                            if(GameObject *pGift = pAlexstrasza->SummonGameObject( m_uiIs10Man ? GO_ALEXSTRASZAS_GIFT : GO_ALEXSTRASZAS_GIFT_H, GOPositions[1].x, GOPositions[1].y, GOPositions[1].z+4, GOPositions[2].o, 0, 0, 0, 0, 0))
                                                        {
                                pAlexstrasza->SetFacingToObject(pGift);
                                                        }

                            //Summon platform for the looters to stay on...
                            me->SummonGameObject(190023 , 757.001f, 1297.4f, 267.09f, 2.26684f, 0, 0, 0.905866f, 0.423563f, 600000);

                            Player* pPlayer = GetPlayerAtMinimumRange(1.0f);
                            if(pPlayer)
                                                        {
                                pPlayer->DealDamage(me, me->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                                                        }
                            else
                                                        {
                                me->DealDamage(me, me->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                                                        }
                            break;
                    }
                    m_uiSpeechCount++;
                }else m_uiSpeechTimer[m_uiSpeechCount] -= uiDiff;
                
            }
        }
    };
};

/* mob_power_spark */
class mob_power_spark : public CreatureScript
{
    public:
        mob_power_spark() : CreatureScript("mob_power_spark") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new mob_power_sparkAI (pCreature);
        }

        struct mob_power_sparkAI : public ScriptedAI
        {
            mob_power_sparkAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                m_pInstance = (InstanceScript*)pCreature->GetInstanceScript();
                Reset();
            }
     
            InstanceScript* m_pInstance;
            bool isDead;
            uint32 m_uiCheckTimer;
            uint64 pMalygosGUID;
     
            void Reset()
            {
                isDead = false;

                Creature* pMalygos = GetClosestCreatureWithEntry(me, NPC_MALYGOS, 200.0f);
                if(pMalygos)
                {
                    pMalygosGUID = pMalygos->GetGUID();
                    me->AddThreat(pMalygos, 10000000.0f);
                    me->Attack(pMalygos, true);
                    AttackStart(pMalygos);
                }
                else
                {
                    pMalygosGUID = 0;
                }

                m_uiCheckTimer = 2500;
                me->SetSpeed(MOVE_WALK, 1.0f);
                me->SetSpeed(MOVE_RUN, 1.0f);
                WorldPacket heart;
                me->BuildHeartBeatMsg(&heart);
                me->SendMessageToSet(&heart, false);
            }

            void MoveInLineOfSight(Unit* pWho) {}
            void EnterCombat(Unit* pWho) {}

            void DamageTaken(Unit* pDoneBy, uint32 &uiDamage)
            {
                if (isDead)
                {
                    uiDamage = 0;
                    return;
                }
     
                if (uiDamage > me->GetHealth())
                {
                    isDead = true;
     
                    if (me->IsNonMeleeSpellCasted(false))
                        me->InterruptNonMeleeSpells(false);
     
                    me->RemoveAllAuras();
                    me->AttackStop();
                    SetCombatMovement(false);
     
                    if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() == CHASE_MOTION_TYPE)
                        me->GetMotionMaster()->MovementExpired();
     
                    uiDamage = 0;
                    m_uiCheckTimer = 250;
                    //me->setFaction(35);
                    me->SetHealth(1);
                    me->AddAura(SPELL_POWER_SPARK_PLAYERS, me);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    me->ForcedDespawn(60000);
                }
            }

            void EnergizePlayers()
            {
                Map* pMap = me->GetMap();
                if(!pMap)
                {
                    return;
                }

                Map::PlayerList const &lPlayers = pMap->GetPlayers();
                for(Map::PlayerList::const_iterator itr = lPlayers.begin(); itr != lPlayers.end(); ++itr)
                {
                    if(!itr->getSource()->isAlive())
                    continue;

                    if(itr->getSource()->IsWithinDist2d(me->GetPositionX(), me->GetPositionY(), 15.0f) && !itr->getSource()->HasAura(55849))
                    {
                        me->AddAura(55849, itr->getSource());
                    }
                }
            }    

        void UpdateAI(const uint32 uiDiff)
        {
            if(isDead)
            {
                if(m_uiCheckTimer < uiDiff)
                {
                    EnergizePlayers();
                    m_uiCheckTimer = 250;
                }else m_uiCheckTimer -= uiDiff;
                return;
            }

            if(m_uiCheckTimer <= uiDiff)
            {
                if(m_pInstance && m_pInstance->GetData(TYPE_VORTEX))
                {
                    me->GetMotionMaster()->MovementExpired();
                    me->GetMotionMaster()->MoveIdle();
                    return;
                }

                if(Creature* pMalygos = (Creature*)Unit::GetUnit(*me, pMalygosGUID))
                {
                    if(!pMalygos->isAlive())
                    {
                        me->ForcedDespawn();
                        return;
                    }

                    if(me->IsWithinDist3d(pMalygos->GetPositionX(), pMalygos->GetPositionY(), pMalygos->GetPositionZ(), 5.0f))
                    {
                        pMalygos->AddAura(SPELL_POWER_SPARK, pMalygos);
                        me->ForcedDespawn();
                    }else
                    {
                        me->GetMotionMaster()->MoveChase(pMalygos, 1.0f, 0.0f);
                    }
                }
                m_uiCheckTimer = 2000;
            }else m_uiCheckTimer -= uiDiff;
        }
        };
};

/* mob_scion_of_eternity */
class mob_scion_of_eternity : public CreatureScript
{
    public:
        mob_scion_of_eternity() : CreatureScript("mob_scion_of_eternity") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new mob_scion_of_eternityAI (pCreature);
        }

        struct mob_scion_of_eternityAI : public ScriptedAI
        {
            mob_scion_of_eternityAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                m_pInstance = (InstanceScript*)pCreature->GetInstanceScript();
                Reset();
                m_uiIs10Man = RAID_MODE(true, false);
            }
        
            bool m_uiIs10Man;

            InstanceScript* m_pInstance;
            uint32 m_uiArcaneBarrageTimer;
            uint32 m_uiMoveTimer;
            uint8 m_uiMovePoint;
     
            void Reset()
            {
                me->SetFlying(true);
                me->SetSpeed(MOVE_WALK, 0.7f, true);
                me->SetSpeed(MOVE_RUN, 0.7f, true);
                me->SetSpeed(MOVE_FLIGHT, 0.7f, true);
                DoNextMovement();
                m_uiMovePoint = 0;
                m_uiMoveTimer = 10000;
                m_uiArcaneBarrageTimer = 5000 + rand()%15000;
                me->SetInCombatWithZone();
            }
                        
            void AttackStart(Unit *pWho)
            {
                if(pWho->GetTypeId() != TYPEID_PLAYER)
                    return;
     
                if (me->Attack(pWho, true))
                {
                    me->AddThreat(pWho, 1.0f);
                    me->SetInCombatWith(pWho);
                    pWho->SetInCombatWith(me);
                    me->GetMotionMaster()->MoveChase(pWho, 15.0f);
                }
            }
        
            void DoNextMovement()
            {
                WorldPacket heart;
                me->BuildHeartBeatMsg(&heart);
                me->SendMessageToSet(&heart, false);
                m_uiMovePoint++;
                float x = (float)urand(SHELL_MIN_X, SHELL_MAX_X);
                float y = (float)urand(SHELL_MIN_Y, SHELL_MAX_Y);
                me->GetMotionMaster()->MovePoint(m_uiMovePoint, x, y, FLOOR_Z+10);
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if(!UpdateVictim())
                {
                    return;
                }
            
                if(m_uiArcaneBarrageTimer <= uiDiff)
                {
                    if(Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    {
                        if(pTarget->GetVehicle())
                        {
                            return;
                        }

                        int32 bpoints0 = RAID_MODE(int32(BP_BARRAGE0), int32(BP_BARRAGE0_H));
                        me->CastCustomSpell(pTarget, m_uiIs10Man ? SPELL_ARCANE_SHOCK : SPELL_ARCANE_SHOCK_H, &bpoints0, 0, 0, false);
                        DoCast(pTarget, SPELL_ARCANE_BARRAGE);  
                    }

                    m_uiArcaneBarrageTimer = 3000 + rand()%7000;
                    DoNextMovement();
                }
                else
                {
                    m_uiArcaneBarrageTimer -= uiDiff;
                }
             
                if(m_uiMoveTimer <= uiDiff)
                {
                    if(m_pInstance->GetData(TYPE_MALYGOS) == NOT_STARTED)
                    {
                        me->ForcedDespawn();
                    }

                    m_uiMoveTimer = 10000;
                    DoNextMovement();
                }
                else
                {
                    m_uiMoveTimer -= uiDiff;
                }
            }
        };
};

/* npc_arcane_overload */
class npc_arcane_overload : public CreatureScript
{
    public:
        npc_arcane_overload() : CreatureScript("npc_arcane_overload") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_arcane_overloadAI (pCreature);
        }

        struct npc_arcane_overloadAI : public ScriptedAI
        {
            npc_arcane_overloadAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                m_pInstance = (InstanceScript*)pCreature->GetInstanceScript();
                Reset();
            }
        
            InstanceScript* m_pInstance;
        
            uint32 m_uiProtectTimer;    
            bool m_uiAOCasted;    
            float range;
        
            void Reset()
            {
                m_uiProtectTimer = 1000;
                m_uiAOCasted = false;
                range = 45.0f;
            }
        
            void ProtectAllPlayersInRange(float range)
            {
                  Map* pMap = me->GetMap();
                  if(!pMap)
                  {
                        return;
                  }

                  // The range of the bubble is 12 yards, decreases to 0 yards, linearly, over time.
                  float realRange = (range / 45.0f) * 12.0f;
          
                  Map::PlayerList const &lPlayers = pMap->GetPlayers();
                  for(Map::PlayerList::const_iterator itr = lPlayers.begin(); itr != lPlayers.end(); ++itr)
                  {
                        if(!itr->getSource()->isAlive())
                        {
                            continue;
                        }

                        if(!itr->getSource()->IsWithinDist2d(me->GetPositionX(), me->GetPositionY(), realRange))
                        {
                            // Remove aura if is within 12 yards (So got the aura via it's default aura range)
                            // but isn't in range of the shrunk bubble (So shouldn't get the aura, because it's range already decreased)
                            if(itr->getSource()->IsWithinDist2d(me->GetPositionX(), me->GetPositionY(), 12))
                            {
                                itr->getSource()->RemoveAurasDueToSpell(SPELL_ARCANE_OVERLOAD_PROTECT);
                            }
                        }
                        else 
                        {
                            if(!itr->getSource()->HasAura(SPELL_ARCANE_OVERLOAD_PROTECT))
                            {
                                // Add the aura if still within shrunk bubble range
                                me->AddAura(SPELL_ARCANE_OVERLOAD_PROTECT, itr->getSource());
                            }
                            else
                            {
                                // Refresh aura duration
                                Aura* aur = me->GetAura(SPELL_ARCANE_OVERLOAD_PROTECT);

                                if(aur)
                                {
                                    aur->RefreshDuration();
                                }
                            }
                        }
                  }
              }    
        
                void UpdateAI(const uint32 uiDiff)
                {    
                    if(!m_uiAOCasted)
                    {
                        DoCast(me,SPELL_ARCANE_OVERLOAD);
                        m_uiAOCasted = true;
                    }

                    if(m_uiProtectTimer <= uiDiff)
                    {
                        ProtectAllPlayersInRange(range);
                        range -= 0.5f;
                        m_uiProtectTimer = 250;
                    }
                    else
                    {
                        m_uiProtectTimer -= uiDiff;
                    }
                }
        };
};

/* mob_nexus_lord */
class mob_nexus_lord : public CreatureScript
{
    public:
        mob_nexus_lord() : CreatureScript("mob_nexus_lord") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new mob_nexus_lordAI (pCreature);
        }
    
        struct mob_nexus_lordAI : public ScriptedAI
        {
            mob_nexus_lordAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                m_pInstance = (InstanceScript*)pCreature->GetInstanceScript();
                Reset();
                m_uiIs10Man = RAID_MODE(true, false);
            }
        
            InstanceScript* m_pInstance;
        
            bool m_uiIs10Man;
        
            uint32 m_uiArcaneShockTimer;
            uint32 m_uiHasteTimer;
            uint32 attackNow;
     
            void Reset()
            {
                me->SetSpeed(MOVE_WALK, 0.7f, true);
                me->SetSpeed(MOVE_RUN, 0.7f, true);
                me->SetSpeed(MOVE_FLIGHT, 0.7f, true);
                m_uiHasteTimer = 20000;
                m_uiArcaneShockTimer = 5000 + rand()%15000;
                attackNow = 4000;
            }

            void UpdateAI(const uint32 uiDiff)
            {        
                if (!UpdateVictim())
                {
                    return;
                }

                if(m_pInstance->GetData(TYPE_MALYGOS) == NOT_STARTED)
                {
                    me->ForcedDespawn();
                }
            
                if(m_uiArcaneShockTimer <= uiDiff)
                {
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    {
                        DoCast(pTarget, m_uiIs10Man ? SPELL_ARCANE_SHOCK : SPELL_ARCANE_SHOCK_H);
                    }

                    m_uiArcaneShockTimer = 3000 + rand()%19000;
                }
                else
                {
                    m_uiArcaneShockTimer -= uiDiff;
                }
            
                if(m_uiHasteTimer <= uiDiff)
                {
                    DoCast(me, SPELL_HASTE);
                    m_uiHasteTimer = 10000 + rand()%10000;
                }
                else
                {
                    m_uiHasteTimer -= uiDiff;
                }

                if(attackNow)
                {
                    if(attackNow < uiDiff)
                    {
                        attackNow = 0;
                    }
                    else
                    {
                        attackNow -= uiDiff;
                    }
                }

                if(!attackNow)
                {
                    DoMeleeAttackIfReady();
                }
                        }
        };
};

class go_malygos_iris : public GameObjectScript
{
    public:
         go_malygos_iris() : GameObjectScript("go_malygos_iris") { }

         bool OnGossipHello(Player *pPlayer, GameObject * pGO)
         {
              if (Creature *malygos = pGO->FindNearestCreature(NPC_MALYGOS, 300.0f, true))
              {
                  if (malygos->AI())
                  {
                      malygos->AI()->DoAction(0);
                      pGO->CastSpell(NULL, 61012);
                      pGO->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_DESTROYED);
                  }
              }
        return true;
        } 
};

void AddSC_boss_malygos()
{
    new boss_malygos();
    new mob_power_spark();
    new mob_scion_of_eternity();
    new mob_nexus_lord();
    new npc_arcane_overload();
    new go_malygos_iris();        
}