/*
* Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#include "CreatureGroups.h"
#include "Group.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "ScriptedGossip.h"
#include "Player.h"
#include "battle_for_the_undercity.h"

enum BattleForUndercityHorde
{
    // Spells
    // Thrall
    SPELL_CHAIN_LIGHTNING               = 59517,
    SPELL_LAVA_BURST                    = 59519,
    SPELL_THUNDER                       = 59507,
    SPELL_HEROIC_VANGUARD               = 59506,
    SPELL_WARCHIEFS_BLESSING            = 64670,
    SPELL_TIDAL_WAVE_SUMMON             = 59627,
    // Sylvanas
    SPELL_SONG_OF_SYLVANAS              = 59756,
    SPELL_LEAP_TO_PLATFORM              = 56347,
    // Varimathras
    SPELL_CARION_SWARM                  = 59434,
    SPELL_DRAIN_LIFE                    = 17238,
    SPELL_MIGHT_OF_VARIMATHRAS          = 59424,
    SPELL_SHADOW_BOLT_VOLLEY            = 20741,
    SPELL_AURA_OF_VARIMATHRAS           = 60289,
    SPELL_LEGION_PORTAL                 = 59680,
    SPELL_OPENING_LEGION_PORTALS        = 60224,
    // Other
    SPELL_TIDAL_WAVE                    = 59635,
    SPELL_TIDAY_FURY                    = 59631,
    SPELL_TIDAY_FURY_EFFECT             = 59629,
    SPELL_CALL_OF_AIR                   = 59898,
    SPELL_CYCLONE_FALL                  = 59892,
    SPELL_CALL_OF_EARTH                 = 60207,
    SPELL_PORTAL_COLLAPSE               = 60285,
    SPELL_TELEPORT_SPAWN_VISUAL         = 60427,
    SPELL_SUMMONED_DEMON                = 7741,
    SPELL_DEEP_FREEZE                   = 60511,
    SPELL_GREATER_MASS_TELEPORT         = 60516,
    SPELL_WATER_REVENANT_ENTRANCE       = 55760,

    // NPC's
    NPC_WARSONG_BATTLEGUARD             = 31739,
    NPC_VORTEX                          = 31782,
    NPC_TIDAL_WAVE                      = 31765,
    NPC_WHIRLWIND                       = 31688,
    NPC_CAVE_DUMMY                      = 32200,
    NPC_SLINGER_TRIGGER                 = 31577,
    NPC_OVERLORD_SAURFANG               = 32315,
    NPC_DISTANT_VOICE                   = 31814,

    // GO'S
    GO_BLOCKED_PASSAGE                  = 194935,
    GO_HORDE_BANNER                     = 194004,
    GO_PORTAL_ORGRIMMAR                 = 193427,

    // Misc
    SOUND_LAMENT                        = 10896,

    // Mobs
    NPC_BLIGHT_SPREADER                 = 31831,

    NPC_BLIGHT_ABBERATION               = 31844,

    NPC_VARIMATHRAS                     = 31565,
    NPC_VARIMATHRAS_PORTAL              = 31811,

    NPC_KHANOK                          = 32160,

    NPC_LEGION_OVERLORD                 = 32271,
    NPC_LEGION_INVADER                  = 32269,
    NPC_LEGION_DREADWHISPER             = 32270,

    NPC_VARIAN_H                        = 32303,
    NPC_STORMWIND_ELITE                 = 31639,

    NPC_SAURFANG                        = 32315,

    // Events
    EVENT_UPDATE_INTRO_WORLDSTATE       = 1,
    EVENT_UPDATE_OUTRO_WORLDSTATE       = 2,
    EVENT_START_BATTLE                  = 3,
    EVENT_START_OUTRO_BATTLE            = 4,
    EVENT_TALK_STEPS                    = 5,

    THRALL_SAY_0                        = 0,
    THRALL_SAY_1                        = 1,
    THRALL_SAY_2                        = 2,
    THRALL_SAY_3                        = 3,
    THRALL_SAY_4                        = 4,
    THRALL_SAY_5                        = 5,
    THRALL_SAY_6                        = 6,
    THRALL_SAY_7                        = 7,
    THRALL_SAY_8                        = 8,
    THRALL_SAY_9                        = 9,
    THRALL_SAY_10                       = 10,
    THRALL_SAY_11                       = 11,
    THRALL_SAY_12                       = 12,
    THRALL_SAY_13                       = 13,
    THRALL_SAY_14                       = 14,
    THRALL_SAY_15                       = 15,
    THRALL_SAY_16                       = 16,
    THRALL_SAY_17                       = 17,
    THRALL_SAY_18                       = 18,
    THRALL_SAY_19                       = 19,
    THRALL_SAY_20                       = 20,
    THRALL_SAY_21                       = 21,
    THRALL_SAY_22                       = 22,
    THRALL_SAY_23                       = 23,
    THRALL_SAY_24                       = 24,
    THRALL_SAY_25                       = 25,
    THRALL_SAY_26                       = 26,
    THRALL_SAY_27                       = 27,
    THRALL_SAY_28                       = 28,
    THRALL_SAY_29                       = 29,
    THRALL_SAY_30                       = 30,
    THRALL_SAY_31                       = 31,
    THRALL_SAY_32                       = 32,
    THRALL_SAY_33                       = 33,
    THRALL_SAY_34                       = 34,

    SYLV_SAY_0                          = 0,
    SYLV_SAY_1                          = 1,
    SYLV_SAY_2                          = 2,
    SYLV_SAY_3                          = 3,
    SYLV_SAY_4                          = 4,
    SYLV_SAY_5                          = 5,
    SYLV_SAY_6                          = 6,
    SYLV_SAY_7                          = 7,

    VAR_SAY_0                           = 0,
    VAR_SAY_1                           = 1,
    VAR_SAY_2                           = 2,
    VAR_SAY_3                           = 3,
    VAR_SAY_4                           = 4,
    VAR_SAY_5                           = 5,
    VAR_SAY_6                           = 6,
    VAR_SAY_7                           = 7,
    VAR_SAY_8                           = 8,
    VAR_SAY_9                           = 9,
    VAR_SAY_10                          = 10,
    VAR_SAY_11                          = 11,
    VAR_SAY_12                          = 12,
    VAR_SAY_13                          = 13,
    VAR_SAY_14                          = 14,
    VAR_SAY_15                          = 15,

    DIST_SAY                            = 6,

    VARIAN_SAY_0                        = 0,
    VARIAN_SAY_1                        = 1,
    VARIAN_SAY_2                        = 2,
    VARIAN_SAY_3                        = 3,
    VARIAN_SAY_4                        = 4,

    SAUR_SAY_0                          = 0,
    SAUR_SAY_1                          = 1,
    SAUR_SAY_2                          = 2
};

Position const VortexSpawnPos[2] =
{
    { 1877.590332f, 234.105881f, 60.044224f, 1.286632f },
    { 1877.750122f, 241.220016f, 60.007225f, 1.286632f }
};

Position const HordeBannerSpawnPos[8] =
{
    { 1736.964722f, 239.023056f, 62.685543f, 6.250000f },
    { 1750.710327f, 245.470428f, 65.585114f, 6.250000f },
    { 1750.461182f, 232.408432f, 64.956978f, 6.250000f },
    { 1628.034912f, 249.905167f, 62.853127f, 5.752854f },
    { 1632.215454f, 253.885544f, 62.594212f, 5.752854f },
    { 1587.852173f, 237.403748f, 60.150764f, 0.007666f },
    { 1587.451050f, 243.044586f, 60.150764f, 0.007666f },
    { 1592.733154f, 382.058716f, -62.177578f, 0.007666f }
};

Position const HordeGuardSpawnPos[3] =
{
    { 1593.744385f, 236.263702f, 60.1506650f, 2.591626f },
    { 1534.351196f, 217.998215f, -43.056278f, 4.131000f },
    { 1528.664307f, 208.112366f, -43.056278f, 1.048311f }
};

Position const CycloneSpawnPos[4] =
{
    { 1544.31f, 241.81f, -41.359f, 6.25f },
    { 1544.31f, 241.81f, -20.352f, 6.25f },
    { 1544.31f, 241.81f, -4.9818f, 6.25f },
    { 1544.31f, 241.81f, 23.3281f, 6.25f }
};

Position const PortalSpawnPos[6] =
{
    { 1324.698730f, 355.651215f, -63.661636f, 3.885573f },
    { 1336.103516f, 311.884094f, -63.661366f, 2.892038f },
    { 1303.705811f, 280.090820f, -63.661320f, 1.787766f },
    { 1260.306396f, 292.426483f, -63.661362f, 0.789526f },
    { 1248.817139f, 336.162170f, -63.662071f, 6.024203f },
    { 1281.007446f, 367.944153f, -63.662357f, 4.987479f }
};

Position const WaveTriggerSpawnPos[11] =
{
    { 1736.030762f, 239.754089f, 62.789696f, 6.266412f },
    { 1728.583374f, 258.317963f, 64.148369f, 6.231070f },
    { 1728.036133f, 220.326035f, 64.148544f, 6.205258f },
    { 1595.328491f, 206.539719f, -55.342926f, 1.429556f },
    { 1530.924072f, 249.284439f, -62.179073f, 5.237929f },
    { 1590.065674f, 300.080414f, -62.177605f, 5.795569f },
    { 1562.672485f, 421.463318f, -62.177696f, 5.031369f },
    { 1630.124390f, 421.629456f, -62.177422f, 4.520856f },
    { 1533.639648f, 342.675690f, -62.165802f, 1.394971f },
    { 1653.375610f, 342.042847f, -62.171635f, 1.634523f },
    { 1574.694092f, 389.525970f, -47.180653f, 6.241663f }
};

Position const SpreaderSpawnPos[5] =
{
    { 1768.496216f, 282.439880f, 70.399712f, 4.691685f },
    { 1782.424438f, 281.858643f, 70.399712f, 4.707393f },
    { 1818.824097f, 281.003326f, 70.399658f, 4.695614f },
    { 1781.788940f, 195.228012f, 70.399864f, 1.550095f },
    { 1816.663208f, 195.277527f, 70.399864f, 1.652197f }
};

uint32 HordeWorldStates[12] =
{
    WORLDSTATE_UNDERCITY_CONTROLLED_H,
    WORLDSTATE_BATTLE_TIMER_STATE,
    WORLDSTATE_BATTLE_TIMER,
    WORLDSTATE_BATTLE_BEGUN,
    WORLDSTATE_BATTLING_COURTYARD,
    WORLDSTATE_CONTROLL_COURTYARD,
    WORLDSTATE_BATTLING_INNER_SANCTUM,
    WORLDSTATE_CONTROLL_INNER_SANCTUM,
    WORLDSTATE_BATTLING_ROYAL_QUARTER,
    WORLDSTATE_CONTROLL_ROYAL_QUARTER,
    WORLDSTATE_RESET_BATTLE,
    WORLDSTATE_RESET_TIMER
};

class npc_thrall_battle_undercity : public CreatureScript
{
public:
    npc_thrall_battle_undercity() : CreatureScript("npc_thrall_battle_undercity") { }

    struct npc_thrall_battle_undercityAI : public npc_escortAI
    {
        npc_thrall_battle_undercityAI(Creature* creature) : npc_escortAI(creature), _summons(me)
        {
            zoneScript = me->GetZoneScript();
            phaseMask = me->GetPhaseMask();

            SetDespawnAtEnd(false);
            SetDespawnAtFar(false);
        }

        void Reset() override
        {
            if (!HasEscortState(STATE_ESCORT_ESCORTING))
            {
                _events.Reset();
                _summons.DespawnAll();

                PlayerGUID.Clear();
                VarianGUID.Clear();
                JainaGUID.Clear();
                VarimathrasGUID.Clear();
                TidalWaveGUID.Clear();
                PassageGUID.Clear();
                SaurfangGUID.Clear();
                KhanokGUID.Clear();

                PhaseTimer = 0;
                Step = 0;

                DreadLordCount = 0;

                EventRepeatCount = 5;

                ChainTimer = urand(12000, 15000);
                ThunderTimer = urand(6000, 8000);
                LavaBurstTimer = urand(16000, 20000);

                me->SetStandState(UNIT_STAND_STATE_STAND);
                me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

                if (Creature* Sylvanas = ObjectAccessor::GetCreature(*me, zoneScript->GetGuidData(NPC_SYLVANAS)))
                    Sylvanas->SearchFormation();
            }
        }

        void sGossipSelect(Player* player, uint32 sender, uint32 action) override
        {
            JumpToNextStep(100);
            PlayerGUID = player->GetGUID();
            player->PlayerTalkClass->SendCloseGossip();
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        }

        void WaypointReached(uint32 waypointId) override
        {
            switch (waypointId)
            {
                case 1:
                    SetEscortPaused(true);
                    SetRun(false);
                    me->Dismount();
                    if (Creature* Sylvanas = ObjectAccessor::GetCreature(*me, zoneScript->GetGuidData(NPC_SYLVANAS)))
                        Sylvanas->Dismount();
                    JumpToNextStep(2000);
                    break;
                case 6:
                    SetEscortPaused(true);
                    DespawnCreatures(NPC_VORTEX);
                    JumpToNextStep(2000);
                    break;
                case 7:
                    if (!_summons.empty())
                        SetEscortPaused(true);
                    break;
                case 8:
                    SetRun(false);
                    break;
                case 9:
                    SetEscortPaused(true);
                    JumpToNextStep(3000);
                    break;
                case 13:
                    for (uint8 i = 3; i < 5; ++i)
                    {
                        float x, y, z, orient;
                        HordeBannerSpawnPos[i].GetPosition(x, y, z, orient);
                        me->SummonGameObject(GO_HORDE_BANNER, x, y, z, orient, G3D::Quat(), 120);
                    }
                    break;
                case 15:
                    for (uint8 i = 5; i < 7; ++i)
                    {
                        float x, y, z, orient;
                        HordeBannerSpawnPos[i].GetPosition(x, y, z, orient);
                        me->SummonGameObject(GO_HORDE_BANNER, x, y, z, orient, G3D::Quat(), 120);
                    }
                    me->SummonCreature(NPC_WARSONG_BATTLEGUARD, HordeGuardSpawnPos[0]);
                    break;
                case 17:
                    SetEscortPaused(true);
                    for (uint8 i = 1; i < 3; ++i)
                        me->SummonCreature(NPC_WARSONG_BATTLEGUARD, HordeGuardSpawnPos[i]);
                    JumpToNextStep(3000);
                    break;
                case 19:
                    SetEscortPaused(true);
                    Talk(THRALL_SAY_17);
                    DoUpdateWorldState(WORLDSTATE_BATTLING_INNER_SANCTUM, 1);
                    JumpToNextStep(1500);
                    break;
                case 20:
                    DespawnCreatures(NPC_WARSONG_BATTLEGUARD);
                    me->SummonCreature(NPC_TREACHEROUS_GUARDIAN_H, 1596.074829f, 273.708984f, -55.342854f, 4.594717f);
                    break;
                case 21:
                    SummonTrigger(3);
                    break;
                case 22:
                    SetEscortPaused(true);
                    JumpToNextStep(1500);
                    break;
                case 29:
                    DespawnCreatures(NPC_WAVES_TRIGGER);
                    for (uint8 i = 4; i < 6; ++i)
                        SummonTrigger(i);
                    break;
                case 32:
                    SetEscortPaused(true);
                    DespawnCreatures(NPC_WAVES_TRIGGER);
                    JumpToNextStep(2000);
                    break;
                case 33:
                    SetEscortPaused(true);
                    JumpToNextStep(2000);
                    break;
                case 36:
                    SetEscortPaused(true);
                    JumpToNextStep(1500);
                    break;
                case 38:
                    SetEscortPaused(true);
                    JumpToNextStep(500);
                    break;
                case 44:
                    SetEscortPaused(true);
                    if (Creature* Varimathras = me->SummonCreature(NPC_VARIMATHRAS, 1289.77f, 314.98f, -57.32f, 1.30f))
                    {
                        VarimathrasGUID = Varimathras->GetGUID();
                        Varimathras->GetAI()->SetData(0, 1);
                        Varimathras->CastSpell(Varimathras, SPELL_AURA_OF_VARIMATHRAS, true);
                    }
                    JumpToNextStep(1500);
                    break;
                case 45:
                    SetEscortPaused(true);
                    JumpToNextStep(4000);
                    break;
                case 46:
                    SetEscortPaused(true);
                    JumpToNextStep(7000);
                    break;
                case 47:
                    SetEscortPaused(true);
                    JumpToNextStep(5000);
                    break;
                case 48:
                    SetEscortPaused(true);
                    JumpToNextStep(1000);
                    break;
            }
        }

        void JumpToNextStep(uint32 Timer)
        {
            if (!zoneScript)
                return;

            _events.ScheduleEvent(EVENT_TALK_STEPS, Timer);
            ++Step;
        }

        void DoUpdateWorldState(uint32 uiStateId, uint32 uiStateData)
        {
            Map* map = me->GetMap();
            if (!map)
                return;

            Map::PlayerList const& players = map->GetPlayers();

            if (!players.isEmpty())
                for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                    if (Player* player = itr->GetSource())
                        if ((player->GetZoneId() == ZONE_TRISFAL_GLADES || player->GetZoneId() == ZONE_UNDERCITY)
                            && player->GetPhaseMask() == phaseMask)
                            player->SendUpdateWorldState(uiStateId, uiStateData);

            if (zoneScript)
                zoneScript->SetData(uiStateId, uiStateData);
        }

        void DespawnCreatures(uint32 entry)
        {
            _summons.DespawnEntry(entry);
        }

        void SummonTrigger(uint8 pos)
        {
            if (Creature* WaveTrigger = me->SummonCreature(NPC_WAVES_TRIGGER, WaveTriggerSpawnPos[pos]))
                WaveTrigger->GetAI()->SetData(0, pos + 12);
        }

        void JustSummoned(Creature* summon) override
        {
            _summons.Summon(summon);
        }

        void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
        {
            _summons.Despawn(summon);

            switch (summon->GetEntry())
            {
                case NPC_BLIGHT_ABBERATION:
                {
                    EntryCheckPredicate pred(NPC_WAVES_TRIGGER);
                    _summons.DoAction(0, pred);
                    _summons.DespawnAll();

                    SetEscortPaused(false);
                    DoUpdateWorldState(WORLDSTATE_BATTLING_COURTYARD, 0);
                    DoUpdateWorldState(WORLDSTATE_CONTROLL_COURTYARD, 1);
                    break;
                }
                case NPC_KHANOK:
                {
                    float x, y, z, orient;
                    HordeBannerSpawnPos[7].GetPosition(x, y, z, orient);
                    me->SummonGameObject(GO_HORDE_BANNER, x, y, z, orient, G3D::Quat(), 60);

                    DespawnCreatures(NPC_WAVES_TRIGGER);
                    SetEscortPaused(false);
                    SetRun(false);
                    DoUpdateWorldState(WORLDSTATE_BATTLING_INNER_SANCTUM, 0);
                    DoUpdateWorldState(WORLDSTATE_CONTROLL_INNER_SANCTUM, 1);
                    break;
                }
            }
        }

        void SetData(uint32 /*type*/, uint32 data) override
        {
            switch (data)
            {
                case 0:
                    DespawnCreatures(NPC_WAVES_TRIGGER);
                    break;
                case 1:
                    if (Creature* Khanok = ObjectAccessor::GetCreature(*me, KhanokGUID))
                    {
                        Khanok->SetInCombatWith(me);
                        me->SetInCombatWith(Khanok);
                        Khanok->AddThreat(me, 10000.0f);
                        me->AddThreat(Khanok, 10000.0f);
                        if (Khanok->AI())
                            Khanok->AI()->AttackStart(me);
                        AttackStart(Khanok);
                    }
                    break;
                case 2:
                    if (Creature* Varimathras = ObjectAccessor::GetCreature(*me, VarimathrasGUID))
                        me->GetMotionMaster()->MovePoint(0, *Varimathras);
                    JumpToNextStep(2000);
                    break;
                case 4:
                    if (Creature* Abberation = me->SummonCreature(NPC_BLIGHT_ABBERATION, 1805.87f, 296.87f, 70.40f, 4.68f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 60000))
                    {
                        Abberation->m_CombatDistance = 50.0f;
                        if (Abberation->AI())
                        {
                            Abberation->SetInCombatWith(me);
                            me->SetInCombatWith(Abberation);
                            Abberation->AddThreat(me, 10000.0f);
                            me->AddThreat(Abberation, 10000.0f);
                            Abberation->AI()->AttackStart(me);
                            AttackStart(Abberation);
                        }
                    }
                    break;
                default:
                    break;
            }
        }

        void DoAction(int32 /*action*/) override
        {
            ++DreadLordCount;
            if (DreadLordCount >= 10)
            {
                DespawnCreatures(NPC_WAVES_TRIGGER);
                SummonTrigger(10);
                if (Creature* Khanok = me->SummonCreature(NPC_KHANOK, 1545.863403f, 390.755585f, -66.059479f, 0.206661f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 60000))
                {
                    Khanok->AddUnitState(UNIT_STATE_IGNORE_PATHFINDING);
                    KhanokGUID = Khanok->GetGUID();
                }
            }
        }

        void EnterCombat(Unit* /*victim*/) override
        {
            DoCast(SPELL_HEROIC_VANGUARD);
        }

        bool CanAIAttack(Unit const* victim) const override
        {
            return victim->GetEntry() != NPC_DOOMGUARD_PILLARGER;
        }

        void EnterEvadeMode(EvadeReason /*reason*/) override
        {
            me->DeleteThreatList();
            me->CombatStop(true);
            me->RemoveAurasDueToSpell(SPELL_HEROIC_VANGUARD);
            npc_escortAI::EnterEvadeMode();
        }

        void JustDied(Unit* killer) override
        {
            npc_escortAI::JustDied(killer);

            EntryCheckPredicate pred(NPC_WAVES_TRIGGER);
            _summons.DoAction(0, pred);
            _summons.DespawnAll();

            if (Creature* Sylvanas = ObjectAccessor::GetCreature(*me, zoneScript->GetGuidData(NPC_SYLVANAS)))
            {
                Sylvanas->RemoveAllAuras();
                float homeX, homeY, homeZ, homeOrient;
                Sylvanas->GetRespawnPosition(homeX, homeY, homeZ, &homeOrient);
                Sylvanas->NearTeleportTo(homeX, homeY, homeZ, homeOrient);
                Sylvanas->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_UNK_15);
                if (Sylvanas->AI())
                    Sylvanas->AI()->Reset();
            }

            for (uint32 i = 0; i < 12; ++i)
                DoUpdateWorldState(HordeWorldStates[i], i == 0 ? 1 : 0);
        }

        void UpdateAI(uint32 diff) override
        {
            npc_escortAI::UpdateAI(diff);
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_UPDATE_INTRO_WORLDSTATE:
                    {
                        switch (EventRepeatCount)
                        {
                            case 1:
                                Talk(THRALL_SAY_5);
                                break;
                            case 2:
                                Talk(THRALL_SAY_4);
                                break;
                            case 3:
                                Talk(THRALL_SAY_3);
                                break;
                            case 4:
                                Talk(THRALL_SAY_2);
                                break;
                            default:
                                break;
                        }

                        DoUpdateWorldState(WORLDSTATE_BATTLE_TIMER, EventRepeatCount);
                        if (--EventRepeatCount)
                            _events.ScheduleEvent(EVENT_UPDATE_INTRO_WORLDSTATE, Seconds(60));
                        else
                            _events.ScheduleEvent(EVENT_START_BATTLE, Seconds(60));
                        break;
                    }
                    case EVENT_START_BATTLE:
                        Talk(THRALL_SAY_6);

                        DoUpdateWorldState(WORLDSTATE_BATTLE_TIMER_STATE, 0);
                        DoUpdateWorldState(WORLDSTATE_BATTLE_TIMER, EventRepeatCount);
                        DoUpdateWorldState(WORLDSTATE_BATTLE_BEGUN, 1);

                        DoCast(me, SPELL_WARCHIEFS_BLESSING, false);

                        JumpToNextStep(11000);
                        break;
                    case EVENT_START_OUTRO_BATTLE:
                        DoUpdateWorldState(WORLDSTATE_RESET_TIMER, EventRepeatCount);
                        if (--EventRepeatCount)
                            _events.ScheduleEvent(EVENT_START_OUTRO_BATTLE, 1 * MINUTE * IN_MILLISECONDS);
                        else
                            _events.ScheduleEvent(EVENT_UPDATE_OUTRO_WORLDSTATE, 1 * MINUTE * IN_MILLISECONDS);
                        break;
                    case EVENT_UPDATE_OUTRO_WORLDSTATE:
                        DoUpdateWorldState(WORLDSTATE_RESET_BATTLE, 0);
                        DoUpdateWorldState(WORLDSTATE_RESET_TIMER, EventRepeatCount);
                        DoUpdateWorldState(WORLDSTATE_CONTROLL_ROYAL_QUARTER, 0);
                        DoUpdateWorldState(WORLDSTATE_UNDERCITY_CONTROLLED_H, 1);

                        _summons.DespawnAll();
                        me->RemoveAllAuras();
                        me->setActive(false);
                        float homeX, homeY, homeZ, homeOrient;
                        me->GetRespawnPosition(homeX, homeY, homeZ, &homeOrient);
                        me->NearTeleportTo(homeX, homeY, homeZ, homeOrient);
                        JustRespawned();
                        me->Mount(me->GetCreatureAddon()->mount);
                        if (Creature* Sylvanas = ObjectAccessor::GetCreature(*me, zoneScript->GetGuidData(NPC_SYLVANAS)))
                        {
                            Sylvanas->RemoveAllAuras();
                            float homeX, homeY, homeZ, homeOrient;
                            Sylvanas->GetRespawnPosition(homeX, homeY, homeZ, &homeOrient);
                            Sylvanas->NearTeleportTo(homeX, homeY, homeZ, homeOrient);
                            Sylvanas->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_UNK_15);
                            if (Sylvanas->AI())
                            {
                                Sylvanas->AI()->Reset();
                                Sylvanas->SearchFormation();
                                Sylvanas->Mount(10719);
                            }
                        }
                        break;
                    case EVENT_TALK_STEPS:
                    {
                        switch (Step)
                        {
                            case 1:
                                me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_NONE);
                                Talk(THRALL_SAY_0);
                                DoUpdateWorldState(WORLDSTATE_BATTLE_TIMER_STATE, 1);
                                DoUpdateWorldState(WORLDSTATE_BATTLE_TIMER, EventRepeatCount);
                                --EventRepeatCount;
                                _events.ScheduleEvent(EVENT_UPDATE_INTRO_WORLDSTATE, Seconds(60));
                                JumpToNextStep(7000);
                                break;
                            case 2:
                                Talk(THRALL_SAY_1);
                                break;
                            case 3:
                                Talk(THRALL_SAY_7);
                                Start(true, true, PlayerGUID);
                                break;
                            case 4:
                                me->SetSheath(SHEATH_STATE_MELEE);
                                if (Creature* Sylvanas = ObjectAccessor::GetCreature(*me, zoneScript->GetGuidData(NPC_SYLVANAS)))
                                    Sylvanas->SetSheath(SHEATH_STATE_RANGED);
                                Talk(THRALL_SAY_8);
                                JumpToNextStep(3000);
                                break;
                            case 5:
                                Talk(THRALL_SAY_9);
                                for (uint8 i = 0; i < 2; ++i)
                                    if (Creature* Vortex = me->SummonCreature(NPC_VORTEX, VortexSpawnPos[i]))
                                        Vortex->GetMotionMaster()->MovePath(NPC_VORTEX * 10 + i, false);
                                JumpToNextStep(8000);
                                break;
                            case 6:
                                SetEscortPaused(false);
                                break;
                            case 7:
                                Talk(THRALL_SAY_10);
                                JumpToNextStep(6000);
                                break;
                            case 8:
                                if (Creature* Varimathras = me->SummonCreature(NPC_VARIMATHRAS, 1810.511597f, 236.830002f, 62.753681f))
                                {
                                    Varimathras->SetWalk(true);
                                    VarimathrasGUID = Varimathras->GetGUID();
                                }
                                JumpToNextStep(3000);
                                break;
                            case 9:
                                if (Creature* Varimathras = ObjectAccessor::GetCreature(*me, VarimathrasGUID))
                                    if (Varimathras->AI())
                                        Varimathras->AI()->Talk(VAR_SAY_2);
                                JumpToNextStep(7000);
                                break;
                            case 10:
                                if (Creature* Varimathras = ObjectAccessor::GetCreature(*me, VarimathrasGUID))
                                    if (Varimathras->AI())
                                        Varimathras->AI()->Talk(VAR_SAY_3);
                                JumpToNextStep(10000);
                                break;
                            case 11:
                                if (Creature* Varimathras = ObjectAccessor::GetCreature(*me, VarimathrasGUID))
                                    if (Varimathras->AI())
                                        Varimathras->AI()->Talk(VAR_SAY_4);
                                JumpToNextStep(6000);
                                break;
                            case 12:
                                if (Creature* Varimathras = ObjectAccessor::GetCreature(*me, VarimathrasGUID))
                                    Varimathras->CastSpell(Varimathras, SPELL_LEGION_PORTAL, false);
                                JumpToNextStep(12000);
                                break;
                            case 13:
                                if (Creature* Varimathras = ObjectAccessor::GetCreature(*me, VarimathrasGUID))
                                    Varimathras->GetMotionMaster()->MovePoint(0, 1800.72f, 237.11f, 62.76f);
                                JumpToNextStep(2000);
                                break;
                            case 14:
                            {
                                Talk(THRALL_SAY_11);
                                if (Creature* Varimathras = ObjectAccessor::GetCreature(*me, VarimathrasGUID))
                                    Varimathras->DespawnOrUnsummon();
                                DoCast(SPELL_TIDAL_WAVE_SUMMON);
                                Position pos = me->GetNearPosition(15.0f, 0.0f);
                                pos.SetOrientation(6.25f);
                                if (Creature* TidalWave = me->SummonCreature(NPC_TIDAL_WAVE, pos))
                                    TidalWaveGUID = TidalWave->GetGUID();
                                JumpToNextStep(1000);
                                break;
                            }
                            case 15:
                                if (Creature* TidalWave = ObjectAccessor::GetCreature(*me, TidalWaveGUID))
                                {
                                    TidalWave->AddUnitState(UNIT_STATE_IGNORE_PATHFINDING);
                                    TidalWave->SetSpeed(MOVE_RUN, 1.5f);
                                    TidalWave->CastSpell(TidalWave, SPELL_TIDAY_FURY, true);
                                    TidalWave->CastSpell(TidalWave, SPELL_TIDAL_WAVE, true);
                                    TidalWave->GetMotionMaster()->MovePoint(0, 1741.84f, 238.88f, 62.24f);
                                }
                                JumpToNextStep(8000);
                                break;
                            case 16:
                                SetEscortPaused(false);
                                SetRun(true);
                                Talk(THRALL_SAY_12);
                                DoUpdateWorldState(WORLDSTATE_UNDERCITY_CONTROLLED_H, 0);
                                DoUpdateWorldState(WORLDSTATE_BATTLE_BEGUN, 0);
                                DoUpdateWorldState(WORLDSTATE_BATTLING_COURTYARD, 1);
                                if (Creature* TidalWave = ObjectAccessor::GetCreature(*me, TidalWaveGUID))
                                    TidalWave->DespawnOrUnsummon();
                                //if (Creature* Sylvanas = ObjectAccessor::GetCreature(*me, zoneScript->GetGuidData(NPC_SYLVANAS)))
                                //Sylvanas->m_CombatDistance = 50.0f; /*hack, figure something out*/
                                for (uint8 i = 0; i < 5; ++i)
                                {
                                    if (Creature* Spreader = me->SummonCreature(NPC_BLIGHT_SPREADER, SpreaderSpawnPos[i]))
                                    {
                                        //Spreader->m_CombatDistance = 120.0f; /*hack, figure something out*/
                                        if (Spreader->AI())
                                            Spreader->AI()->AttackStart(me);
                                    }
                                    if (i > 2)
                                        continue;

                                    SummonTrigger(i);
                                }
                                JumpToNextStep(10000);
                                break;
                            case 17:
                                if (Creature* Sylvanas = ObjectAccessor::GetCreature(*me, zoneScript->GetGuidData(NPC_SYLVANAS)))
                                {
                                    Sylvanas->CastSpell(Sylvanas, SPELL_SONG_OF_SYLVANAS, true);
                                    DoPlaySoundToSet(Sylvanas, SOUND_LAMENT);
                                    if (Sylvanas->AI())
                                        Sylvanas->AI()->Talk(SYLV_SAY_0);
                                }
                                break;
                            case 18:
                                Talk(THRALL_SAY_13);
                                for (uint8 i = 0; i < 3; ++i)
                                {
                                    float x, y, z, orient;
                                    HordeBannerSpawnPos[i].GetPosition(x, y, z, orient);
                                    me->SummonGameObject(GO_HORDE_BANNER, x, y, z, orient, G3D::Quat(), 30);
                                }
                                JumpToNextStep(6000);
                                break;
                            case 19:
                                SetEscortPaused(false);
                                break;
                            case 20:
                                Talk(THRALL_SAY_14);
                                JumpToNextStep(4000);
                                break;
                            case 21:
                                if (Creature* Sylvanas = ObjectAccessor::GetCreature(*me, zoneScript->GetGuidData(NPC_SYLVANAS)))
                                    if (Sylvanas->AI())
                                        Sylvanas->AI()->Talk(SYLV_SAY_1);
                                JumpToNextStep(5000);
                                break;
                            case 22:
                                Talk(THRALL_SAY_15);
                                DoCast(SPELL_CALL_OF_AIR);
                                JumpToNextStep(5000);
                                break;
                            case 23:
                                for (uint8 i = 0; i < 4; ++i)
                                    me->SummonCreature(NPC_WHIRLWIND, CycloneSpawnPos[i]);
                                JumpToNextStep(8000);
                                break;
                            case 24:
                                SetRun(true);
                                Talk(THRALL_SAY_16);
                                if (Player* player = ObjectAccessor::GetPlayer(*me, PlayerGUID))
                                {
                                    if (Group* group = player->GetGroup())
                                    {
                                        for (GroupReference* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
                                            if (Player* member = itr->GetSource())
                                                if (member->IsAlive())
                                                    member->CastSpell(player, SPELL_CYCLONE_FALL, true);
                                    }
                                    else
                                        player->CastSpell(player, SPELL_CYCLONE_FALL, true);
                                }
                                JumpToNextStep(5000);
                                break;
                            case 25:
                                me->GetMotionMaster()->MoveJump(1547.29f, 248.38f, -19.62f, 10.0f, 20.0f, 1);
                                if (Creature* Sylvanas = ObjectAccessor::GetCreature(*me, zoneScript->GetGuidData(NPC_SYLVANAS)))
                                {
                                    if (Sylvanas->GetFormation())
                                        Sylvanas->GetFormation()->RemoveMember(Sylvanas);
                                    Sylvanas->GetMotionMaster()->MoveJump(1547.29f, 248.38f, -19.62f, 10.0f, 10.0f, 1);
                                }
                                JumpToNextStep(10000);
                                break;
                            case 26:
                                me->GetMotionMaster()->MoveJump(1537.12f, 240.63f, -41.36f, 10.0f, 20.0f, 2);
                                if (Creature* Sylvanas = ObjectAccessor::GetCreature(*me, zoneScript->GetGuidData(NPC_SYLVANAS)))
                                    Sylvanas->GetMotionMaster()->MoveJump(1537.12f, 240.63f, -41.36f, 10.0f, 10.0f, 2);
                                JumpToNextStep(10000);
                                break;
                            case 27:
                                SetRun(false);
                                if (Player* player = ObjectAccessor::GetPlayer(*me, PlayerGUID))
                                {
                                    if (Group* group = player->GetGroup())
                                    {
                                        for (GroupReference* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
                                            if (Player* member = itr->GetSource())
                                                member->RemoveAurasDueToSpell(SPELL_CYCLONE_FALL);
                                    }
                                    else
                                        player->RemoveAurasDueToSpell(SPELL_CYCLONE_FALL);
                                }
                                if (Creature* Sylvanas = ObjectAccessor::GetCreature(*me, zoneScript->GetGuidData(NPC_SYLVANAS)))
                                    Sylvanas->SearchFormation();
                                SetEscortPaused(false);
                                break;
                            case 28:
                                SetEscortPaused(false);
                                break;
                            case 29:
                                DespawnCreatures(NPC_WHIRLWIND);
                                me->SetFacingTo(0.133856f);
                                if (Creature* Sylvanas = ObjectAccessor::GetCreature(*me, zoneScript->GetGuidData(NPC_SYLVANAS)))
                                    Sylvanas->SetFacingTo(0.133856f);
                                JumpToNextStep(1500);
                                break;
                            case 30:
                                if (Creature* Sylvanas = ObjectAccessor::GetCreature(*me, zoneScript->GetGuidData(NPC_SYLVANAS)))
                                    if (Sylvanas->AI())
                                        Sylvanas->AI()->Talk(SYLV_SAY_2);
                                JumpToNextStep(6500);
                                break;
                            case 31:
                                if (Creature* Sylvanas = ObjectAccessor::GetCreature(*me, zoneScript->GetGuidData(NPC_SYLVANAS)))
                                    if (Sylvanas->AI())
                                        Sylvanas->AI()->Talk(SYLV_SAY_3);
                                JumpToNextStep(8500);
                                break;
                            case 32:
                                Talk(THRALL_SAY_18);
                                JumpToNextStep(8000);
                                break;
                            case 33:
                                if (Creature* Sylvanas = ObjectAccessor::GetCreature(*me, zoneScript->GetGuidData(NPC_SYLVANAS)))
                                    if (Sylvanas->AI())
                                        Sylvanas->AI()->Talk(SYLV_SAY_4);
                                JumpToNextStep(1100);
                                break;
                            case 34:
                                SetEscortPaused(false);
                                break;
                            case 35:
                                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY2H);
                                if (Creature* Sylvanas = ObjectAccessor::GetCreature(*me, zoneScript->GetGuidData(NPC_SYLVANAS)))
                                {
                                    Sylvanas->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY2H);
                                    if (Sylvanas->AI())
                                        Sylvanas->AI()->Talk(SYLV_SAY_5);
                                }
                                JumpToNextStep(6000);
                                break;
                            case 36:
                                if (Creature* Varimathras = me->SummonCreature(NPC_VARIMATHRAS, 1596.60f, 419.62f, -45.41f, 4.66f))
                                {
                                    if (Varimathras->AI())
                                        Varimathras->AI()->Talk(VAR_SAY_5);
                                    Varimathras->SetWalk(true);
                                    VarimathrasGUID = Varimathras->GetGUID();
                                }
                                JumpToNextStep(4000);
                                break;
                            case 37:
                                if (Creature* Varimathras = ObjectAccessor::GetCreature(*me, VarimathrasGUID))
                                {
                                    if (Varimathras->AI())
                                        Varimathras->AI()->Talk(VAR_SAY_6);
                                    Varimathras->CastSpell(Varimathras, SPELL_LEGION_PORTAL, false);
                                }
                                JumpToNextStep(4000);
                                break;
                            case 38:
                                if (Creature* Varimathras = ObjectAccessor::GetCreature(*me, VarimathrasGUID))
                                {
                                    Position pos = Varimathras->GetNearPosition(5.0f, static_cast<float>(M_PI));
                                    Varimathras->GetMotionMaster()->MovePoint(0, pos);
                                }
                                JumpToNextStep(2000);
                                break;
                            case 39:
                                if (Creature* Varimathras = ObjectAccessor::GetCreature(*me, VarimathrasGUID))
                                    Varimathras->DespawnOrUnsummon();
                                if (Creature* Sylvanas = ObjectAccessor::GetCreature(*me, zoneScript->GetGuidData(NPC_SYLVANAS)))
                                    Sylvanas->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_NONE);
                                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_NONE);
                                DespawnCreatures(NPC_WAVES_TRIGGER);
                                for (uint8 i = 6; i < 11; ++i)
                                    SummonTrigger(i);
                                break;
                            case 40:
                                Talk(THRALL_SAY_19);
                                JumpToNextStep(5000);
                                break;
                            case 41:
                                Talk(THRALL_SAY_20);
                                JumpToNextStep(6000);
                                break;
                            case 42:
                                SetEscortPaused(false);
                                break;
                            case 43:
                                if (Creature* Sylvanas = ObjectAccessor::GetCreature(*me, zoneScript->GetGuidData(NPC_SYLVANAS)))
                                    if (Sylvanas->AI())
                                        Sylvanas->AI()->Talk(SYLV_SAY_6);
                                JumpToNextStep(4000);
                                break;
                            case 44:
                                if (Creature* Varimathras = DoSpawnCreature(NPC_VARIMATHRAS, 0.0f, 0.0f, 20.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 10000))
                                {
                                    if (Varimathras->AI())
                                        Varimathras->AI()->Talk(VAR_SAY_7);
                                    Varimathras->SetVisible(false);
                                }
                                me->SummonCreature(NPC_CAVE_DUMMY, 1442.34f, 398.28f, -57.86f, 5.42f);
                                if (GameObject* Passage = me->SummonGameObject(GO_BLOCKED_PASSAGE, 1442.34f, 398.28f, -57.86f, 5.42f, G3D::Quat(), 300))
                                {
                                    PassageGUID = Passage->GetGUID();
                                    Passage->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                                }
                                JumpToNextStep(3000);
                                break;
                            case 45:
                                SetEscortPaused(false);
                                break;
                            case 46:
                                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY2H);
                                if (Creature* Sylvanas = ObjectAccessor::GetCreature(*me, zoneScript->GetGuidData(NPC_SYLVANAS)))
                                    Sylvanas->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY2H);
                                JumpToNextStep(3000);
                                break;
                            case 47:
                                Talk(THRALL_SAY_21);
                                JumpToNextStep(10000);
                                break;
                            case 48:
                                Talk(THRALL_SAY_22);
                                DoCast(SPELL_CALL_OF_EARTH);
                                JumpToNextStep(6000);
                                break;
                            case 49:
                                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_NONE);
                                if (Creature* Sylvanas = ObjectAccessor::GetCreature(*me, zoneScript->GetGuidData(NPC_SYLVANAS)))
                                    Sylvanas->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_NONE);
                                DoUpdateWorldState(WORLDSTATE_BATTLING_ROYAL_QUARTER, 1);
                                if (GameObject* Passage = ObjectAccessor::GetGameObject(*me, PassageGUID))
                                    Passage->UseDoorOrButton();
                                JumpToNextStep(3000);
                                break;
                            case 50:
                                if (GameObject* Passage = ObjectAccessor::GetGameObject(*me, PassageGUID))
                                    Passage->Delete();
                                DespawnCreatures(NPC_CAVE_DUMMY);
                                JumpToNextStep(3000);
                                break;
                            case 51:
                                Talk(THRALL_SAY_23);
                                SetRun(true);
                                SetEscortPaused(false);
                                break;
                            case 52:
                                Talk(THRALL_SAY_24);
                                JumpToNextStep(4000);
                                break;
                            case 53:
                                if (Creature* Varimathras = ObjectAccessor::GetCreature(*me, VarimathrasGUID))
                                {
                                    Varimathras->AI()->Talk(VAR_SAY_8);
                                    Varimathras->GetAI()->SetData(0, 2);
                                }
                                break;
                            case 54:
                                Talk(THRALL_SAY_25);
                                JumpToNextStep(4500);
                                break;
                            case 55:
                                Talk(THRALL_SAY_26);
                                JumpToNextStep(6000);
                                break;
                            case 56:
                                if (Creature* Sylvanas = ObjectAccessor::GetCreature(*me, zoneScript->GetGuidData(NPC_SYLVANAS)))
                                    if (Sylvanas->GetFormation())
                                        Sylvanas->GetFormation()->RemoveMember(Sylvanas);
                                SetRun(true);
                                SetEscortPaused(false);
                                break;
                            case 57:
                                if (Creature* Sylvanas = ObjectAccessor::GetCreature(*me, zoneScript->GetGuidData(NPC_SYLVANAS)))
                                    me->SetFacingToObject(Sylvanas);
                                JumpToNextStep(1500);
                                break;
                            case 58:
                                Talk(THRALL_SAY_27);
                                JumpToNextStep(4000);
                                break;
                            case 59:
                                if (Creature* Sylvanas = ObjectAccessor::GetCreature(*me, zoneScript->GetGuidData(NPC_SYLVANAS)))
                                    Sylvanas->CastSpell(Sylvanas, SPELL_LEAP_TO_PLATFORM, true);
                                JumpToNextStep(6000);
                                break;
                            case 60:
                                if (Creature* Sylvanas = ObjectAccessor::GetCreature(*me, zoneScript->GetGuidData(NPC_SYLVANAS)))
                                    Sylvanas->AI()->Talk(SYLV_SAY_7);
                                JumpToNextStep(500);
                                break;
                            case 61:
                                if (Creature* Sylvanas = ObjectAccessor::GetCreature(*me, zoneScript->GetGuidData(NPC_SYLVANAS)))
                                    me->SetFacingToObject(Sylvanas);
                                JumpToNextStep(8000);
                                break;
                            case 62:
                                Talk(THRALL_SAY_28);
                                SetRun(false);
                                SetEscortPaused(false);
                                JumpToNextStep(5000);
                                break;
                            case 63:
                                if (Creature* Sylvanas = ObjectAccessor::GetCreature(*me, zoneScript->GetGuidData(NPC_SYLVANAS)))
                                {
                                    Sylvanas->SetWalk(true);
                                    Sylvanas->GetMotionMaster()->MovePoint(2, 1300.53f, 341.01f, -60.08f);
                                }
                                break;
                            case 64:
                            {
                                if (Creature* Varian = me->SummonCreature(NPC_VARIAN_H, 1312.927490f, 396.034393f, -62.858009f, 4.392927f))
                                {
                                    VarianGUID = Varian->GetGUID();

                                    for (uint8 i = 0; i < 10; ++i)
                                    {
                                        float angle = (M_PI / 10) * i - M_PI;
                                        Position pos = Varian->GetNearPosition(2.0f, angle);
                                        if (Creature* StormwindElite = me->SummonCreature(NPC_STORMWIND_ELITE, pos))
                                        {
                                            StormwindElite->SetFacingTo(Varian->GetOrientation());
                                            StormwindElite->GetMotionMaster()->MoveFollow(Varian, 1.0f, Varian->GetAngle(StormwindElite));
                                        }
                                    }
                                }
                                Talk(THRALL_SAY_29);
                                Position pos = me->GetNearPosition(5.0f, 0.0f);
                                me->GetMotionMaster()->MoveJump(pos, 10.0f, 10.0f);
                                if (Creature* Sylvanas = ObjectAccessor::GetCreature(*me, zoneScript->GetGuidData(NPC_SYLVANAS)))
                                {
                                    pos = Sylvanas->GetNearPosition(5.0f, 0.0f);
                                    Sylvanas->GetMotionMaster()->MoveJump(pos, 10.0f, 10.0f);
                                }
                                JumpToNextStep(6000);
                                break;
                            }
                            case 65:
                                if (Creature* Varian = ObjectAccessor::GetCreature(*me, VarianGUID))
                                    Varian->GetMotionMaster()->MovePoint(0, 1302.529f, 359.509f, -67.295f);
                                JumpToNextStep(8000);
                                break;
                            case 66:
                                if (Creature* Varian = ObjectAccessor::GetCreature(*me, VarianGUID))
                                    if (Varian->AI())
                                        Varian->AI()->Talk(VARIAN_SAY_0);
                                JumpToNextStep(17000);
                                break;
                            case 67:
                                if (Creature* Varian = ObjectAccessor::GetCreature(*me, VarianGUID))
                                    if (Varian->AI())
                                        Varian->AI()->Talk(VARIAN_SAY_1);
                                JumpToNextStep(13000);
                                break;
                            case 68:
                                if (Creature* Varian = ObjectAccessor::GetCreature(*me, VarianGUID))
                                    if (Varian->AI())
                                        Varian->AI()->Talk(VARIAN_SAY_2);
                                JumpToNextStep(17000);
                                break;
                            case 69:
                                if (Creature* Varian = ObjectAccessor::GetCreature(*me, VarianGUID))
                                    if (Varian->AI())
                                        Varian->AI()->Talk(VARIAN_SAY_3);
                                JumpToNextStep(12000);
                                break;
                            case 70:
                                if (Creature* Varian = ObjectAccessor::GetCreature(*me, VarianGUID))
                                    if (Varian->AI())
                                        Varian->AI()->Talk(VARIAN_SAY_4);
                                for (SummonList::iterator itr = _summons.begin(); itr != _summons.end(); ++itr)
                                    if (Creature* summon = ObjectAccessor::GetCreature(*me, *itr))
                                    {
                                        summon->Dismount();
                                        summon->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_UNK_15 | UNIT_FLAG_PACIFIED);
                                        if (summon->AI())
                                            summon->AI()->AttackStart(me);
                                    }
                                JumpToNextStep(10000);
                                break;
                            case 71:
                                if (Creature* Jaina = me->SummonCreature(NPC_JAINA_PROUDMORE, 1305.02f, 370.15f, -67.29f, 4.33f))
                                {
                                    JainaGUID = Jaina->GetGUID();
                                    Jaina->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_UNK_15 | UNIT_FLAG_PACIFIED);
                                }
                                JumpToNextStep(1000);
                                break;
                            case 72:
                                if (Creature* Jaina = ObjectAccessor::GetCreature(*me, JainaGUID))
                                    if (Jaina->AI())
                                        Jaina->AI()->Talk(3);
                                JumpToNextStep(8000);
                                break;
                            case 73:
                                if (Creature* Jaina = ObjectAccessor::GetCreature(*me, JainaGUID))
                                    Jaina->GetMotionMaster()->MovePoint(1, 1299.30f, 348.18f, -65.02f);
                                JumpToNextStep(10000);
                                break;
                            case 74:
                                if (Creature* Jaina = ObjectAccessor::GetCreature(*me, JainaGUID))
                                    Jaina->CastSpell(Jaina, SPELL_DEEP_FREEZE, false);
                                JumpToNextStep(5000);
                                break;
                            case 75:
                                if (Creature* Jaina = ObjectAccessor::GetCreature(*me, JainaGUID))
                                    if (Jaina->AI())
                                        Jaina->AI()->Talk(4);
                                JumpToNextStep(7000);
                                break;
                            case 76:
                                if (Creature* Jaina = ObjectAccessor::GetCreature(*me, JainaGUID))
                                    Jaina->CastSpell(Jaina, SPELL_GREATER_MASS_TELEPORT, false);
                                JumpToNextStep(4500);
                                break;
                            case 77:
                                DespawnCreatures(NPC_VARIAN_H);
                                DespawnCreatures(NPC_STORMWIND_ELITE);
                                JumpToNextStep(4000);
                                break;
                            case 78:
                                me->setActive(true);
                                DespawnCreatures(NPC_JAINA_PROUDMORE);
                                EventRepeatCount = 5;
                                DoUpdateWorldState(WORLDSTATE_CONTROLL_COURTYARD, 0);
                                DoUpdateWorldState(WORLDSTATE_CONTROLL_INNER_SANCTUM, 0);
                                DoUpdateWorldState(WORLDSTATE_BATTLING_ROYAL_QUARTER, 0);
                                DoUpdateWorldState(WORLDSTATE_CONTROLL_ROYAL_QUARTER, 1);
                                DoUpdateWorldState(WORLDSTATE_RESET_BATTLE, 1);
                                DoUpdateWorldState(WORLDSTATE_RESET_TIMER, EventRepeatCount);
                                --EventRepeatCount;
                                _events.ScheduleEvent(EVENT_START_OUTRO_BATTLE, 1 * MINUTE * IN_MILLISECONDS);
                                JumpToNextStep(4000);
                                break;
                            case 79:
                                me->SummonGameObject(GO_PORTAL_ORGRIMMAR, 1289.77f, 314.98f, -57.32f, 1.30f, G3D::Quat(), 300);
                                SetRun(false);
                                Talk(THRALL_SAY_30);
                                SetEscortPaused(false);
                                break;
                            case 80:
                                Talk(THRALL_SAY_31);
                                JumpToNextStep(15000);
                                break;
                            case 81:
                                SetEscortPaused(false);
                                break;
                            case 82:
                                me->SetFacingTo(1.239064f);
                                JumpToNextStep(1000);
                                break;
                            case 83:
                                Talk(THRALL_SAY_32);
                                me->SetStandState(UNIT_STAND_STATE_SIT);
                                JumpToNextStep(3000);
                                me->SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                                break;
                            case 84:
                                if (Creature* Saurfang = me->SummonCreature(NPC_SAURFANG, 1302.25f, 338.33f, -60.083f, 1.02f))
                                {
                                    SaurfangGUID = Saurfang->GetGUID();
                                    Saurfang->SetWalk(true);
                                    Position pos = Saurfang->GetNearPosition(5.0f, 0.0f);
                                    Saurfang->GetMotionMaster()->MoveJump(pos, 10.0f, 10.0f);
                                }
                                JumpToNextStep(1000);
                                break;
                            case 85:
                                if (Creature* Saurfang = ObjectAccessor::GetCreature(*me, SaurfangGUID))
                                    Saurfang->GetMotionMaster()->MovePoint(1, 1303.50f, 352.05f, -65.63f);
                                JumpToNextStep(6000);
                                break;
                            case 86:
                                if (Creature* Saurfang = ObjectAccessor::GetCreature(*me, SaurfangGUID))
                                {
                                    Saurfang->SetStandState(UNIT_STAND_STATE_SIT);
                                    if (Saurfang->AI())
                                        Saurfang->AI()->Talk(SAUR_SAY_0);
                                }
                                JumpToNextStep(5000);
                                break;
                            case 87:
                                if (Creature* Saurfang = ObjectAccessor::GetCreature(*me, SaurfangGUID))
                                    if (Saurfang->AI())
                                        Saurfang->AI()->Talk(SAUR_SAY_1);
                                JumpToNextStep(7000);
                                break;
                            case 88:
                                if (Creature* Saurfang = ObjectAccessor::GetCreature(*me, SaurfangGUID))
                                    if (Saurfang->AI())
                                        Saurfang->AI()->Talk(SAUR_SAY_2);
                                JumpToNextStep(4000);
                                break;
                            case 89:
                                Talk(THRALL_SAY_34);
                                JumpToNextStep(5000);
                                break;
                            case 90:
                                Talk(THRALL_SAY_33);
                                break;
                        }
                        break;
                    }
                }
            }


            if (!UpdateVictim())
                return;

            /* ToDo: move this to eventmap */
            if (ChainTimer <= diff)
            {
                DoCastVictim(SPELL_CHAIN_LIGHTNING);
                ChainTimer = urand(20000, 25000);
            }
            else
                ChainTimer -= diff;

            if (ThunderTimer <= diff)
            {
                DoCastVictim(SPELL_THUNDER);
                ThunderTimer = urand(12000, 18000);
            }
            else
                ThunderTimer -= diff;

            if (LavaBurstTimer <= diff)
            {
                DoCastVictim(SPELL_LAVA_BURST);
                LavaBurstTimer = urand(26000, 30000);
            }
            else
                LavaBurstTimer -= diff;

            DoMeleeAttackIfReady();
        }
    private:
        ZoneScript* zoneScript;

        EventMap _events;

        SummonList _summons;

        ObjectGuid PlayerGUID;
        ObjectGuid VarianGUID;
        ObjectGuid JainaGUID;
        ObjectGuid VarimathrasGUID;
        ObjectGuid TidalWaveGUID;
        ObjectGuid PassageGUID;
        ObjectGuid SaurfangGUID;
        ObjectGuid KhanokGUID;

        uint32 phaseMask;
        uint32 PhaseTimer;
        uint8 Step;
        uint8 EventRepeatCount;

        int32 DreadLordCount;

        uint32 ChainTimer;
        uint32 ThunderTimer;
        uint32 LavaBurstTimer;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_thrall_battle_undercityAI(creature);
    }
};

class npc_tidal_wave : public CreatureScript
{
public:
    npc_tidal_wave() : CreatureScript("npc_tidal_wave") { }

    struct npc_tidal_waveAI : public ScriptedAI
    {
        npc_tidal_waveAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            DoCast(SPELL_WATER_REVENANT_ENTRANCE);
        }

        void SpellHitTarget(Unit* target, SpellInfo const* spellInfo) override
        {
            if (spellInfo->Id != SPELL_TIDAY_FURY_EFFECT)
                return;

            if (Creature* creature = target->ToCreature())
                creature->DespawnOrUnsummon(5000);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_tidal_waveAI(creature);
    }
};

// !refactor entire thing below

class npc_varimathras_battle_undercity : public CreatureScript
{
public:
    npc_varimathras_battle_undercity() : CreatureScript("npc_varimathras_battle_undercity") { }

    struct npc_varimathras_battle_undercityAI : public ScriptedAI
    {
        npc_varimathras_battle_undercityAI(Creature* creature) : ScriptedAI(creature), _summons(me) { }

        void Reset() override
        {
            _summons.DespawnAll();
            Portals.clear();

            StartEvent = false;
            EventTimer = 54000;
            WaveTimer = 6000;
            WaveCount = 0;
            EventPhase = 0;

            CarrionSwarmTimer = urand(15500, 30000);
            DrainLifeTimer = urand(12500, 15000);
            ShadowBoltVolleyTimer = urand(5000, 10000);
        }

        void JustSummoned(Creature* summon) override
        {
            _summons.Summon(summon);

            if (summon->GetEntry() == NPC_VARIMATHRAS_PORTAL)
                Portals.push_back(summon->GetGUID());
        }

        void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
        {
            _summons.Despawn(summon);
        }

        void SummonedCreatureDespawn(Creature* summon) override
        {
            _summons.Despawn(summon);

            if (summon->GetEntry() == NPC_VARIMATHRAS_PORTAL)
                Portals.erase(std::remove(Portals.begin(), Portals.end(), summon->GetGUID()), Portals.end());
        }

        void IsSummonedBy(Unit* summoner) override
        {
            ThrallGUID = summoner->GetGUID();
        }

        void EnterCombat(Unit* target) override
        {
            DoCast(SPELL_MIGHT_OF_VARIMATHRAS);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(VAR_SAY_15);
            _summons.DespawnAll();
            if (Creature* Thrall = ObjectAccessor::GetCreature(*me, ThrallGUID))
                Thrall->GetAI()->SetData(0, 2);
        }

        void SetData(uint32 type, uint32 data) override
        {
            switch (data)
            {
                case 1:
                    for (uint8 i = 0; i < 6; ++i)
                        if (Creature* Portal = me->SummonCreature(NPC_VARIMATHRAS_PORTAL, PortalSpawnPos[i]))
                            Portal->CastSpell(me, SPELL_OPENING_LEGION_PORTALS, true);
                    break;
                case 2:
                    StartEvent = true;
                    break;
            }
        }

        void DoAction(int32 /*action*/) override
        {
            switch (++EventPhase)
            {
                case 1:
                    Talk(VAR_SAY_9);
                    EventTimer = 60000;
                    break;
                case 2:
                    Talk(VAR_SAY_10);
                    EventTimer = 30000;
                    break;
                case 3:
                    Talk(VAR_SAY_11);
                    EventTimer = 30000;
                    break;
                case 4:
                    Talk(VAR_SAY_12);
                    EventTimer = 15000;
                    break;
                case 5:
                    Talk(VAR_SAY_13);
                    EventTimer = 3000;
                    break;
                case 6:
                    Talk(VAR_SAY_14);
                    EventTimer = 6000;
                    break;
            }
        }

        void DestroyPortal()
        {
            if (!Portals.empty())
                if (Creature* RandomPortal = ObjectAccessor::GetCreature(*me, Trinity::Containers::SelectRandomContainerElement(Portals)))
                    RandomPortal->CastSpell(me, SPELL_PORTAL_COLLAPSE, false);
        }

        void SummonMobs()
        {
            WaveTimer = 6000;

            if (!Portals.empty())
                for (auto i : Portals)
                    if (Creature* Portal = ObjectAccessor::GetCreature(*me, i))
                    {
                        uint32 WaveEntry = 0;
                        switch (WaveCount)
                        {
                            case 0:
                                WaveEntry = NPC_LEGION_INVADER;
                                break;
                            case 1:
                                WaveEntry = NPC_LEGION_DREADWHISPER;
                                break;
                            case 2:
                                WaveEntry = RAND(NPC_LEGION_INVADER, NPC_LEGION_DREADWHISPER, NPC_LEGION_OVERLORD);
                                WaveTimer = 12000;
                                break;
                        }

                        if (!WaveEntry)
                            return;

                        ++WaveCount;
                        if (WaveCount > 2)
                            WaveCount = 0;

                        Position pos = Portal->GetNearPosition(2.0f, 0.0f);
                        if (Creature* summon = me->SummonCreature(WaveEntry, pos, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000))
                        {
                            summon->m_CombatDistance = 50.0f;
                            if (Creature* Thrall = ObjectAccessor::GetCreature(*me, ThrallGUID))
                                if (summon->AI())
                                    summon->AI()->AttackStart(Thrall);
                        }
                    }
        }

        void UpdateAI(uint32 diff) override
        {
            if (StartEvent)
            {
                if (WaveTimer <= diff)
                    SummonMobs();
                else
                    WaveTimer -= diff;

                if (EventTimer <= diff)
                {
                    switch (EventPhase)
                    {
                        case 5:
                            if (Creature* DistantVoice = DoSpawnCreature(NPC_DISTANT_VOICE, 0.0f, 0.0f, 20.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 10000))
                            {
                                if (DistantVoice->AI())
                                    DistantVoice->AI()->Talk(DIST_SAY);
                                DistantVoice->SetVisible(false);
                            }
                            DestroyPortal();
                            EventTimer = 60000;
                            break;
                        case 6:
                            StartEvent = false;
                            me->RemoveAllAuras();
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_NPC);
                            if (Creature* Thrall = ObjectAccessor::GetCreature(*me, ThrallGUID))
                                AttackStart(Thrall);
                            EventTimer = 60000;
                            break;
                        default:
                            DestroyPortal();
                            EventTimer = 60000;
                            break;
                    }
                }
                else
                    EventTimer -= diff;
            }

            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING) || me->GetCurrentSpell(CURRENT_CHANNELED_SPELL))
                return;

            if (CarrionSwarmTimer <= diff)
            {
                DoCastVictim(SPELL_CARION_SWARM);
                CarrionSwarmTimer = urand(21000, 30000);
            }
            else
                CarrionSwarmTimer -= diff;

            if (DrainLifeTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f))
                    DoCast(target, SPELL_DRAIN_LIFE, false);
                DrainLifeTimer = urand(12000, 15000);
            }
            else
                DrainLifeTimer -= diff;

            if (ShadowBoltVolleyTimer <= diff)
            {
                DoCastVictim(SPELL_SHADOW_BOLT_VOLLEY);
                ShadowBoltVolleyTimer = urand(7000, 12000);
            }
            else
                ShadowBoltVolleyTimer -= diff;

            DoMeleeAttackIfReady();
        }
    private:
        SummonList _summons;
        std::vector<ObjectGuid> Portals;

        bool StartEvent;

        ObjectGuid ThrallGUID;
        uint32 EventTimer;
        uint32 WaveTimer;
        uint8 WaveCount;
        uint8 EventPhase;

        uint32 CarrionSwarmTimer;
        uint32 DrainLifeTimer;
        uint32 ShadowBoltVolleyTimer;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_varimathras_battle_undercityAI(creature);
    }
};

class spell_hurl_boulder : public SpellScriptLoader
{
public:
    spell_hurl_boulder() : SpellScriptLoader("spell_hurl_boulder") { }

    class spell_hurl_boulder_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_hurl_boulder_SpellScript);

        void FilterTargets(std::list<WorldObject*>& unitList)
        {
            target = nullptr;

            if (!unitList.empty())
                target = Trinity::Containers::SelectRandomContainerElement(unitList);

            if (target)
            {
                unitList.clear();
                unitList.push_back(target);
            }
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_hurl_boulder_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENTRY);
        }

    private:
        WorldObject* target;

    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_hurl_boulder_SpellScript();
    }
};

class spell_blight_barrel : public SpellScriptLoader
{
public:
    spell_blight_barrel() : SpellScriptLoader("spell_blight_barrel") { }

    class spell_blight_barrel_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_blight_barrel_SpellScript);

        void FilterTargets(std::list<WorldObject*>& unitList)
        {
            target = nullptr;

            if (!unitList.empty())
                target = Trinity::Containers::SelectRandomContainerElement(unitList);

            if (target)
            {
                unitList.clear();
                unitList.push_back(target);
            }
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_blight_barrel_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENTRY);
        }

    private:
        WorldObject* target;

    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_blight_barrel_SpellScript();
    }
};

class spell_portal_collapse : public SpellScriptLoader
{
public:
    spell_portal_collapse() : SpellScriptLoader("spell_portal_collapse") { }

    class spell_portal_collapse_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_portal_collapse_SpellScript);

        void HandleAfterCast()
        {
            if (Unit* caster = GetCaster())
                if (Creature* Portal = caster->ToCreature())
                {
                    if (Creature* Varimathras = Portal->ToTempSummon()->GetSummonerCreatureBase())
                        Varimathras->GetAI()->DoAction(0);

                    Portal->CastSpell(caster, SPELL_TELEPORT_SPAWN_VISUAL, true);
                    Portal->DespawnOrUnsummon(1500);
                }
        }

        void Register() override
        {
            AfterCast += SpellCastFn(spell_portal_collapse_SpellScript::HandleAfterCast);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_portal_collapse_SpellScript();
    }
};

void AddSC_battle_for_undercity_horde()
{
    new npc_thrall_battle_undercity();
    new npc_tidal_wave();
    new npc_varimathras_battle_undercity();
    new spell_hurl_boulder();
    new spell_blight_barrel();
    new spell_portal_collapse();
}