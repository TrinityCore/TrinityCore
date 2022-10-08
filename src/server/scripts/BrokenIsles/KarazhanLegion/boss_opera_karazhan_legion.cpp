/*
 * Copyright (C) 2017-2019 AshamaneProject <https://github.com/AshamaneProject>
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
#include "GameObject.h"
#include "Creature.h"
#include "ScriptedCreature.h"
#include "Unit.h"
#include "SpellHistory.h"
#include "AreaTriggerTemplate.h"
#include "ScriptedGossip.h"
#include "SpellMgr.h"
#include "Cell.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "AreaTriggerAI.h"
#include "AreaTrigger.h"
#include "karazhan_legion.h"

enum Spells
{
    // Tae Knee
    SPELL_DASHING_FLAME_GALE                = 227449,
    SPELL_DASHING_FLAME_MISSILE             = 227453,
    SPELL_DASHING_FLAME_GALE_TRIGGER        = 227467,
    SPELL_DASHING_FLAME_GALE_DMG            = 227480,
    SPELL_BURNING_LEG_SWEEP                 = 227568,
    SPELL_POISONOUS_SHANK                   = 227319,
    SPELL_POISONOUS_SHANK_DMG               = 227325,

    // Mrrgria
    SPELL_BUBBLE_BLAST                      = 227420,
    SPELL_BUBBLE_BLAST_DMG                  = 227434,
    SPELL_THUNDER_RITUAL                    = 227777,
    SPELL_THUNDER_RITUAL_DMG                = 227780,
    SPELL_WASH_AWAY                         = 227783,
    SPELL_WASH_AWAY_AREA                    = 227790,
    SPELL_WASH_AWAY_DMG                     = 227799,

    // Coggleston
    SPELL_SPECTRAL_SERVICE                  = 232156,
    SPELL_EMINENCE                          = 228729,
    SPELL_KARA_KAZHAM                       = 232153,
    SPELL_DINNER_BELL                       = 227987,
    SPELL_DENT_ARMOR                        = 227985,

    // Silver Fork
    SPELL_BLOODY_JAB                        = 232135,
    SPELL_FLASHING_FORKS                    = 232142,

    // Babblet
    SPELL_SEVERE_DUSTING                    = 228221,
    SPELL_SEVERE_DUSTING_AREA               = 228213,
    SPELL_SEVERE_DUSTING_DMG                = 228215,
    SPELL_SULTRY_HEAT                       = 228225,

    // Luminore
    SPELL_BURNING_BLAZE                     = 228193,
    SPELL_BURNING_BLAZE_DMG                 = 228200,
    SPELL_HEAT_WAVE                         = 228025,

    // Mrs Cauldrons
    SPELL_SOUP_SPRAY                        = 228011,
    SPELL_DRENCHED                          = 228013,
    SPELL_LEFTOVERS                         = 228019,
    SPELL_LEFTOVERS_MISSILE                 = 228015,

    // Galindre
    SPELL_MAGIC_MAGNIFICENT_IMMUNITY        = 227346,
    SPELL_MAGIC_MAGNIFICENT_AOE             = 227776,
    SPELL_FLASHY_BOLT                       = 227341,
    SPELL_WONDROUS_RADIANCE                 = 227410,
    SPELL_WIKKET_BOND                       = 231869,

    // Elfyra
    SPELL_DEFY_GRAVITY                      = 227447,
    SPELL_DEFY_GRAVITY_AREA                 = 227444,
    SPELL_DEFY_GRAVITY_DMG                  = 227405,
    SPELL_DREARY_BOLT                       = 227543,
    SPELL_SUMMON_ASSISTANTS                 = 227477,
    SPELL_THROW_STUFF                       = 227461,
};

enum Events
{
    // Coggleston
    EVENT_KARA_KAZHAM                       = 1,
    EVENT_DENT_ARMOR                        = 2,
    EVENT_DINNER_BELL                       = 3,

    // Babblet
    EVENT_SEVERE_DUSTING                    = 1,

    // Luminore
    EVENT_BURNING_BLAZE                     = 1,
    EVENT_HEAT_WAVE                         = 2,

    // Mrs Cauldrons
    EVENT_SOUP_SPRAY                        = 1,
    EVENT_LEFTOVERS                         = 2,

    // Galindre
    EVENT_MAGIC_MAFNIFICENT                 = 1,
    EVENT_FLASHY_BOLT                       = 2,
    EVENT_WONDROUS_RADIANCE                 = 3,

    // Elfyra
    EVENT_DEFY_GRAVITY                      = 4,
    EVENT_DREARY_BOLT                       = 5,
    EVENT_SUMMON_ASSISTANT                  = 6,
    EVENT_THROW_STUFF                       = 7,

    // Toe Knee
    EVENT_BURNING_LEG_SWEEP                 = 8,
    EVENT_DASHING_FLAME_GALE                = 9,
    EVENT_POISONOUS_SHANK                   = 10,
    EVENT_DASHING_FLAME_GALE_DMG            = 11,

    // Mrrgria
    EVENT_THUNDER_RITUAL                    = 12,
    EVENT_WASH_AWAY                         = 13,
    EVENT_BUBBLE_BLAST                      = 14,

    // Flashing Fork
    EVENT_FLASHING_FORK                     = 15,
    EVENT_BLOODY_JAB                        = 16
};

enum Adds
{
    NPC_WINGED_ASSISTANT                    = 114324,
    NPC_GANG_RUFFIAN                        = 114265,
    NPC_SHORELINE_TIDESPEAKER               = 114266
};

enum Says
{
    // Coggleston
    SAY_COGGLESTON_AGGRO                    = 0,
    SAY_KARA_KHAZAN                         = 1,
    SAY_COGGLESTON_KILL                     = 2,
    SAY_COGGLESTON_WIPE                     = 3,
    SAY_COGGLESTON_DEATH                    = 4,
    SAY_COGGLESTON_CONVER_1                 = 5,
    SAY_COGGLESTON_CONVER_2                 = 6,

    // Luminore
    SAY_LUMINORE_HEAT_WAVE                  = 0,
    SAY_LUMINORE_KILL                       = 1,
    SAY_LUMINORE_DEATH                      = 2,

    // Bablet
    SAY_BABLET_KILL                         = 0,
    SAY_BABLET_DEATH                        = 1,

    // Mrs Cauldron
    SAY_MRS_CAULDRON_SOUP_SPRAY             = 0,
    SAY_MRS_CAULDRON_KILL                   = 1,
    SAY_MRS_CAULDRON_DEATH                  = 2,

    // Toe Knee
    SAY_TOE_AGGRO                           = 0,
    SAY_TOE_THIRD_PHASE                     = 1,
    SAY_TOE_DASHING_GALE                    = 2,
    SAY_TOE_BURNING_LEG                     = 3,
    SAY_TOE_KILL                            = 4,
    SAY_TOE_WIPE                            = 5,
    SAY_TOE_DEATH                           = 6,

    //Galindre
    SAY_GALINDRE_INTRO_0                    = 0,
    SAY_GALINDRE_INTRO_1                    = 1,
    SAY_GALINDRE_INTRO_2                    = 2,
    SAY_GALINDRE_AGGRO                      = 3,
    SAY_MAGIC_MAGNIFICENT                   = 4,
    SAY_GALINDRE_KILL                       = 5,

    // Elfyra
    SAY_ELFIRA_INTRO_0                      = 0,
    SAY_ELFIRA_INTRO_1                      = 1,
    SAY_ELFIRA_AGGRO                        = 2,
    SAY_DEFY_GRAVITY                        = 3,
    SAY_SUMMON_ASSISTANTS                   = 4,
    SAY_ELFYRA_KILL                         = 5,
    SAY_ELFYRA_DEATH                        = 6
};

enum Actions
{
    ACTION_MINION_DEAD                      = 1,
    ACTION_OPERA_SELECT                     = 2,
    ACTION_DASHING_FLAME                    = 3,
    ACTION_THE_FINS                         = 4,
    ACTION_SOMEWHERE                        = 5
};

enum Data
{
    DATA_MARKED_PLAYER                      = 1,
    DATA_DASHING_FLAME                      = 2
};

const Position SpawnPositions[] =
{
    { -10883.400f, -1752.550f, 90.559f, 3.74f }, // Coggleston
    { -10888.200f, -1751.589f, 90.559f, 3.62f }, // Luminore
    { -10892.200f, -1749.479f, 90.559f, 3.74f }, // Babblet
    { -10884.700f, -1757.010f, 90.560f, 3.74f }, // Mrs Cauldrons
    { -10903.299f, -1752.550f, 90.559f, 3.60f }, // Bella
    { -10906.299f, -1754.219f, 90.558f, 0.55f }, // Brute
    { -10891.736f, -1762.435f, 90.476f, 4.64f }, // Elfyra
    { -10895.954f, -1757.203f, 90.476f, 4.63f }, // Galyndra
    { -10901.641f, -1756.986f, 90.477f, 6.16f }, // Tae Knee
    { -10880.361f, -1759.517f, 90.477f, 3.02f }, // Mrrgria
    { -10908.245f, -1759.737f, 90.477f, 6.17f }, // Third Ruffian
    { -10908.033f, -1756.397f, 90.477f, 6.16f }, // Second Ruffian
    { -10907.834f, -1752.743f, 90.477f, 6.17f }, // First Ruffian
    { -10876.893f, -1754.317f, 90.477f, 3.05f }, // First Speaker
    { -10877.355f, -1759.714f, 90.477f, 3.05f }, // Second Speaker
    { -10877.770f, -1764.238f, 90.477f, 3.05f }, // Third Speaker
};

const Position WavesPositions[] =
{
    { -10873.555f, -1746.415f, 90.477f, 3.05f },
    { -10874.161f, -1752.981f, 90.477f, 3.05f },
    { -10874.775f, -1760.095f, 90.477f, 3.05f },
    { -10875.386f, -1767.180f, 90.477f, 3.05f },
    { -10876.192f, -1775.197f, 90.477f, 3.05f },
    { -10912.737f, -1745.708f, 90.477f, 6.17f },
    { -10913.567f, -1752.946f, 90.477f, 6.17f },
    { -10914.371f, -1759.958f, 90.477f, 6.17f },
    { -10915.249f, -1767.611f, 90.477f, 6.17f },
};

class npc_kara_barnes : public CreatureScript
{
    public:
        npc_kara_barnes() : CreatureScript("npc_kara_barnes")
        {
            _eventChosen = false;
        }

        struct npc_kara_barnes_AI : public ScriptedAI
        {
            explicit npc_kara_barnes_AI(Creature* creature) : ScriptedAI(creature)
            {
                _eventChosen = false;
            }

            void Reset() override
            {
                if (InstanceScript* instance = me->GetInstanceScript())
                    _eventChosen = (instance->GetBossState(DATA_OPERA) == DONE ? true : false);
            }

            void DoAction(int32 action) override
            {
                if (action == ACTION_OPERA_SELECT)
                {
                    if (_eventChosen)
                        return;

                    _operaEvent = me->GetInstanceScript()->GetData(DATA_OPERA_EVENT);
                    _eventChosen = true;

                    if (_operaEvent == OPERA_EVENT_BEATIFUL_BEAST)
                    {
                        me->SummonCreature(BOSS_COGGLESTON, SpawnPositions[0], TEMPSUMMON_MANUAL_DESPAWN);
                        me->SummonCreature(BOSS_LUMINORE, SpawnPositions[1], TEMPSUMMON_MANUAL_DESPAWN);
                        me->SummonCreature(BOSS_BABLET, SpawnPositions[2], TEMPSUMMON_MANUAL_DESPAWN);
                        me->SummonCreature(BOSS_MRS_CAULDRONS, SpawnPositions[3], TEMPSUMMON_MANUAL_DESPAWN);
                    }
                    else if (_operaEvent == OPERA_EVENT_WIKKET)
                    {
                        me->SummonCreature(BOSS_GALINDRE, SpawnPositions[6], TEMPSUMMON_MANUAL_DESPAWN);
                        me->SummonCreature(BOSS_ELFYRA, SpawnPositions[7], TEMPSUMMON_MANUAL_DESPAWN);
                    }
                    else if (_operaEvent == OPERA_EVENT_WESTFALL_STORY)
                    {
                        me->SummonCreature(BOSS_TOE_KNEE, SpawnPositions[8], TEMPSUMMON_MANUAL_DESPAWN);
                        me->SummonCreature(BOSS_MRRGRIA, SpawnPositions[9], TEMPSUMMON_MANUAL_DESPAWN);

                        for (uint8 i = 10; i < 13; ++i)
                            me->SummonCreature(NPC_GANG_RUFFIAN, SpawnPositions[i], TEMPSUMMON_MANUAL_DESPAWN);

                        for (uint8 i = 13; i < 16; ++i)
                            me->SummonCreature(NPC_SHORELINE_TIDESPEAKER, SpawnPositions[i], TEMPSUMMON_MANUAL_DESPAWN);
                    }
                }
            }

            private:
                bool _eventChosen;
                uint8 _operaEvent;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_kara_barnes_AI(creature);
        }

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            if (!player || !creature)
                return false;

            player->PrepareGossipMenu(creature, creature->GetCreatureTemplate()->GossipMenuId, false);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I'm not a actor", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
        {
            ClearGossipMenuFor(player);
            CloseGossipMenuFor(player);

            if (creature->GetInstanceScript()->GetBossState(DATA_OPERA) == DONE)
                return true;

            if (action == GOSSIP_ACTION_INFO_DEF + 1)
                creature->GetAI()->DoAction(ACTION_OPERA_SELECT);

            return true;
        }

        private:
            bool _eventChosen;
};

class boss_opera_toe_knee : public CreatureScript
{
    public:
        boss_opera_toe_knee() : CreatureScript("boss_opera_toe_knee") { }

        struct boss_opera_toe_knee_AI : public BossAI
        {
            explicit boss_opera_toe_knee_AI(Creature* creature) : BossAI(creature, DATA_OPERA) { }

            void EnterCombat(Unit* /**/) override
            {
                Talk(SAY_TOE_AGGRO);
                _secondPhase = false;
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                _EnterCombat();
                events.ScheduleEvent(EVENT_BURNING_LEG_SWEEP, 5s);
            }

            void JustDied(Unit* /**/) override
            {
                Talk(SAY_TOE_DEATH);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                me->RemoveAllAreaTriggers();
                _JustDied();
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim && victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_TOE_KILL);
            }

            void RespawnMinions()
            {
                std::list<Creature*> minions;

                me->GetCreatureListWithEntryInGrid(minions, NPC_GANG_RUFFIAN);
                me->GetCreatureListWithEntryInGrid(minions, NPC_SHORELINE_TIDESPEAKER);
                me->GetCreatureListWithEntryInGrid(minions, BOSS_MRRGRIA);

                for (auto & it : minions)
                {
                    if (it->isDead())
                        it->Respawn();

                    it->AI()->EnterEvadeMode(EVADE_REASON_OTHER);
                }
            }

            void EnterEvadeMode(EvadeReason why) override
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                me->SetReactState(REACT_AGGRESSIVE);
                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC));
                me->RemoveAllAreaTriggers();
                CreatureAI::EnterEvadeMode(why);
            }

            void JustReachedHome() override
            {
                Talk(SAY_TOE_WIPE);
                _JustReachedHome();
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type == POINT_MOTION_TYPE && id == 0)
                    me->SetEmoteState(Emote::EMOTE_STATE_KNEEL);
            }

            void DamageTaken(Unit* /**/, uint32 & /**/) override
            {
                if (me->HealthBelowPct(50) && !_secondPhase)
                {
                    _secondPhase = true;
                    events.Reset();
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                    me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC));
                    me->SetReactState(REACT_PASSIVE);
                    me->AttackStop();
                    me->GetMotionMaster()->MovePoint(0, me->GetHomePosition());

                    Creature* mrrgria = me->FindNearestCreature(BOSS_MRRGRIA, 250.f);

                    if (mrrgria)
                        mrrgria->GetAI()->DoAction(ACTION_THE_FINS);
                }
            }

            void SetGUID(ObjectGuid guid, int32 id) override
            {
                if (id == DATA_DASHING_FLAME)
                    _targets.push_back(guid);
            }

            void DoAction(int32 action) override
            {
                if (action == ACTION_DASHING_FLAME)
                    events.ScheduleEvent(EVENT_DASHING_FLAME_GALE_DMG, 500ms);
                else if (action == ACTION_SOMEWHERE)
                {
                    Talk(SAY_TOE_THIRD_PHASE);
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                    me->SetEmoteState(Emote::EMOTE_STATE_NONE);
                    me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC));
                    me->SetReactState(REACT_AGGRESSIVE);
                    events.ScheduleEvent(EVENT_BURNING_LEG_SWEEP, 8s);
                }
            }

            void ExecuteEvent(uint32 eventId) override
            {
                me->GetSpellHistory()->ResetAllCooldowns();
                switch (eventId)
                {
                    case EVENT_BURNING_LEG_SWEEP:
                    {
                        if (roll_chance_i(50))
                            Talk(SAY_TOE_BURNING_LEG);

                        DoCastSelf(SPELL_BURNING_LEG_SWEEP);
                        events.ScheduleEvent(EVENT_DASHING_FLAME_GALE, 5s);
                        events.ScheduleEvent(EVENT_BURNING_LEG_SWEEP, 25s);
                        break;
                    }

                    case EVENT_DASHING_FLAME_GALE:
                    {
                        if (roll_chance_i(50))
                            Talk(SAY_TOE_DASHING_GALE);

                        me->CastSpell(me, SPELL_DASHING_FLAME_GALE, false);
                        break;
                    }

                    case EVENT_DASHING_FLAME_GALE_DMG:
                    {
                        if (!_targets.empty())
                        {
                            ObjectGuid targetGUID = _targets.back();
                            _targets.pop_back();

                            if (Unit* target = ObjectAccessor::GetPlayer(*me, targetGUID))
                                DoCast(target, SPELL_DASHING_FLAME_MISSILE);

                            events.ScheduleEvent(EVENT_DASHING_FLAME_GALE_DMG, 500ms);
                        }
                        break;
                    }

                    default : break;
                }
            }

            private:
                bool _secondPhase;
                std::list<ObjectGuid> _targets;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_opera_toe_knee_AI(creature);
        }
};

class boss_opera_mrrgria : public CreatureScript
{
    public:
        boss_opera_mrrgria() : CreatureScript("boss_opera_mrrgria") { }

        struct boss_opera_mrrgria_AI : public BossAI
        {
            explicit boss_opera_mrrgria_AI(Creature* creature) : BossAI(creature, DATA_OPERA) { }

            void Reset() override
            {
                _thirdPhase = false;
                me->SetReactState(REACT_PASSIVE);
                me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC));
                _Reset();
            }

            void DoAction(int32 action) override
            {
                if (action == ACTION_THE_FINS)
                {
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC));
                    DoZoneInCombat();
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                    events.ScheduleEvent(EVENT_THUNDER_RITUAL, 10s);
                    events.ScheduleEvent(EVENT_WASH_AWAY, 23s);

                    std::list<Creature*> adds;

                    me->GetCreatureListWithEntryInGrid(adds, NPC_SHORELINE_TIDESPEAKER, 100.f);

                    for (auto & it : adds)
                        it->AI()->DoAction(ACTION_THE_FINS);
                }
            }

            void EnterCombat(Unit* /**/) override
            {
                _EnterCombat();
            }

            void DamageTaken(Unit* /**/, uint32 & /**/) override
            {
                if (me->HealthBelowPct(50) && !_thirdPhase)
                {
                    _thirdPhase = true;

                    Creature* mrrgria = me->FindNearestCreature(BOSS_TOE_KNEE, 250.f);

                    if (mrrgria)
                        mrrgria->GetAI()->DoAction(ACTION_SOMEWHERE);
                }
            }

            void JustDied(Unit* /**/) override
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                me->RemoveAllAreaTriggers();
                summons.DespawnAll();
            }

            void EnterEvadeMode(EvadeReason why) override
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                me->RemoveAllAreaTriggers();
                CreatureAI::EnterEvadeMode(why);
            }

            void ExecuteEvent(uint32 eventId) override
            {
                switch (eventId)
                {
                    case EVENT_THUNDER_RITUAL:
                    {
                        DoCast(me, SPELL_THUNDER_RITUAL);
                        events.ScheduleEvent(EVENT_THUNDER_RITUAL, 15s, 20s);
                        break;
                    }

                    case EVENT_WASH_AWAY:
                    {
                        DoCast(me, SPELL_WASH_AWAY);
                        events.ScheduleEvent(EVENT_WASH_AWAY, 23s);
                        break;
                    }
                }
            }

            private:
                bool _thirdPhase;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_opera_mrrgria_AI(creature);
        }
};

class boss_opera_coggleston : public CreatureScript
{
    public:
        boss_opera_coggleston() : CreatureScript("boss_opera_coggleston") { }

        struct boss_opera_coggleston_AI : public BossAI
        {
            explicit boss_opera_coggleston_AI(Creature* creature) : BossAI(creature, DATA_OPERA)
            {
                me->CastSpell(me, SPELL_SPECTRAL_SERVICE, true);
            }

            void Reset()
            {
                _minionsDead = 0;
                _Reset();
            }

            void DoAction(int32 action) override
            {
                if (action == ACTION_MINION_DEAD)
                {
                    _minionsDead++;

                    std::list<Creature*> servants;

                    servants.push_back(me);

                    if (auto* bablet = me->FindNearestCreature(BOSS_BABLET, 250.f, true))
                        servants.push_back(bablet);

                    if (auto* luminore = me->FindNearestCreature(BOSS_LUMINORE, 250.f, true))
                        servants.push_back(luminore);

                    if (auto* mrsCauldrons = me->FindNearestCreature(BOSS_MRS_CAULDRONS, 250.f, true))
                        servants.push_back(mrsCauldrons);

                    std::for_each(servants.begin(), servants.end(), [] (auto* target)
                    {
                        target->CastSpell(target, SPELL_EMINENCE, true);
                    });

                    if (_minionsDead >= 3)
                    {
                        me->RemoveAurasDueToSpell(SPELL_SPECTRAL_SERVICE);
                        events.ScheduleEvent(EVENT_KARA_KAZHAM, 3s);
                        events.ScheduleEvent(EVENT_DENT_ARMOR, 15s);
                        events.ScheduleEvent(EVENT_DINNER_BELL, 10s);
                    }
                }
            }

            void RespawnMinions()
            {
                std::list<Creature*> servants;

                if (auto* bablet = me->FindNearestCreature(BOSS_BABLET, 500.f, false))
                    servants.push_back(bablet);

                if (auto* luminore = me->FindNearestCreature(BOSS_LUMINORE, 500.f, false))
                    servants.push_back(luminore);

                if (auto* mrsCauldrons = me->FindNearestCreature(BOSS_MRS_CAULDRONS, 500.f, false))
                    servants.push_back(mrsCauldrons);

                for (auto & it : servants)
                {
                    if (it->isDead())
                        it->Respawn(true);

                    if (it->GetEntry() == BOSS_BABLET)
                        it->GetMotionMaster()->MovePoint(0, SpawnPositions[2]);
                    else if (it->GetEntry() == BOSS_LUMINORE)
                        it->GetMotionMaster()->MovePoint(0, SpawnPositions[1]);
                    else if (it->GetEntry() == BOSS_MRS_CAULDRONS)
                        it->GetMotionMaster()->MovePoint(0, SpawnPositions[3]);
                }
            }

            void EnterCombat(Unit* /**/) override
            {
                Talk(SAY_COGGLESTON_AGGRO);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                _minionsDead = 0;
                _EnterCombat();
            }

            void JustReachedHome() override
            {
                me->CastSpell(me, SPELL_SPECTRAL_SERVICE, true);
                _JustReachedHome();
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim && victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_COGGLESTON_KILL);
            }

            void JustDied(Unit* /**/) override
            {
                Talk(SAY_COGGLESTON_KILL);
                me->RemoveAllAreaTriggers();
                _JustDied();
            }

            void EnterEvadeMode(EvadeReason why) override
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                me->RemoveAurasDueToSpell(SPELL_EMINENCE);
                RespawnMinions();
                me->RemoveAllAreaTriggers();
                CreatureAI::EnterEvadeMode(why);
            }

            void ExecuteEvent(uint32 eventId) override
            {
                switch (eventId)
                {
                    case EVENT_DINNER_BELL:
                    {
                        DoCast(me, SPELL_DINNER_BELL);
                        events.ScheduleEvent(EVENT_DINNER_BELL, 20s);
                        break;
                    }

                    case EVENT_KARA_KAZHAM:
                    {
                        Talk(SAY_KARA_KHAZAN);
                        DoCast(me, SPELL_KARA_KAZHAM);
                        events.ScheduleEvent(EVENT_KARA_KAZHAM, 30s);
                        break;
                    }

                    case EVENT_DENT_ARMOR:
                    {
                        DoCastVictim(SPELL_DENT_ARMOR);
                        events.ScheduleEvent(EVENT_DENT_ARMOR, 15s);
                        break;
                    }
                }
            }

            private:
                uint8 _minionsDead;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_opera_coggleston_AI(creature);
        }

};

class boss_opera_luminore : public CreatureScript
{
    public:
        boss_opera_luminore() : CreatureScript("boss_opera_luminore") { }

        struct boss_opera_luminore_AI : public BossAI
        {
            explicit boss_opera_luminore_AI(Creature* creature) : BossAI(creature, DATA_OPERA) { }

            void EnterCombat(Unit* /**/) override
            {
                _EnterCombat();
                events.ScheduleEvent(EVENT_BURNING_BLAZE, 2s);
                events.ScheduleEvent(EVENT_HEAT_WAVE, 30s);
            }

            void JustDied(Unit* /**/) override
            {
                Talk(SAY_LUMINORE_DEATH);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                me->RemoveAllAreaTriggers();
                Creature* coggleston = me->FindNearestCreature(BOSS_COGGLESTON, 250.f, true);

                if (coggleston)
                    coggleston->GetAI()->DoAction(ACTION_MINION_DEAD);
            }

            void EnterEvadeMode(EvadeReason why) override
            {
                Creature* coggleston = me->FindNearestCreature(BOSS_COGGLESTON, 250.f, true);

                if (coggleston)
                    coggleston->AI()->EnterEvadeMode();

                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                me->RemoveAurasDueToSpell(SPELL_EMINENCE);
                me->RemoveAllAreaTriggers();
                CreatureAI::EnterEvadeMode(why);
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim && victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_LUMINORE_KILL);
            }

            void ExecuteEvent(uint32 eventId) override
            {
                if (eventId == EVENT_BURNING_BLAZE)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                        DoCast(target, SPELL_BURNING_BLAZE);
                    events.ScheduleEvent(EVENT_BURNING_BLAZE, 3s);
                }
                else if (eventId == EVENT_HEAT_WAVE)
                {
                    Talk(SAY_LUMINORE_HEAT_WAVE);
                    DoCastSelf(SPELL_HEAT_WAVE);
                    events.ScheduleEvent(EVENT_HEAT_WAVE, 30s);
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_opera_luminore_AI(creature);
        }
};

class boss_opera_mrs_cauldrons : public CreatureScript
{
    public:
        boss_opera_mrs_cauldrons() : CreatureScript("boss_opera_mrs_cauldrons") { }

        struct boss_opera_mrs_cauldrons_AI : public BossAI
        {
            explicit boss_opera_mrs_cauldrons_AI(Creature* creature) : BossAI(creature, DATA_OPERA) { }

            void EnterCombat(Unit* /**/) override
            {
                _EnterCombat();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                events.ScheduleEvent(EVENT_LEFTOVERS, 1s);
                events.ScheduleEvent(EVENT_SOUP_SPRAY, 2s);
            }

            void EnterEvadeMode(EvadeReason why) override
            {
                Creature* coggleston = me->FindNearestCreature(BOSS_COGGLESTON, 250.f, true);

                if (coggleston)
                    coggleston->AI()->EnterEvadeMode();

                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                me->RemoveAllAreaTriggers();
                me->RemoveAurasDueToSpell(SPELL_EMINENCE);
                CreatureAI::EnterEvadeMode(why);
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim && victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_MRS_CAULDRON_KILL);
            }

            void JustDied(Unit* /**/) override
            {
                Talk(SAY_MRS_CAULDRON_DEATH);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                me->RemoveAllAreaTriggers();
                Creature* coggleston = me->FindNearestCreature(BOSS_COGGLESTON, 250.f, true);

                if (coggleston)
                    coggleston->GetAI()->DoAction(ACTION_MINION_DEAD);
            }

            void ExecuteEvent(uint32 eventId) override
            {
                switch (eventId)
                {
                    case EVENT_SOUP_SPRAY:
                    {
                        if (roll_chance_i(15))
                            Talk(SAY_MRS_CAULDRON_SOUP_SPRAY);

                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                            DoCast(target, SPELL_SOUP_SPRAY);

                        events.ScheduleEvent(EVENT_SOUP_SPRAY, 2s);
                        break;
                    }

                    case EVENT_LEFTOVERS:
                    {
                        bool founded = false;

                        for (const auto & it : me->GetMap()->GetPlayers())
                        {
                            if (Player* player = it.GetSource())
                            {
                                if (player->GetDistance2d(me) <= 10.f)
                                {
                                    founded = true;
                                    break;
                                }
                            }
                        }

                        if (founded)
                        {
                            DoCast(SPELL_LEFTOVERS);
                            events.ScheduleEvent(EVENT_LEFTOVERS, 18s);
                        }
                        else
                            events.ScheduleEvent(EVENT_LEFTOVERS, 1s);

                        break;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_opera_mrs_cauldrons_AI(creature);
        }
};

class boss_opera_bablet : public CreatureScript
{
    public:
        boss_opera_bablet() : CreatureScript("boss_opera_bablet") { }

        struct boss_opera_bablet_AI : public BossAI
        {
            explicit boss_opera_bablet_AI(Creature* creature) : BossAI(creature, DATA_OPERA) { }

            void EnterCombat(Unit* /**/) override
            {
                _EnterCombat();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                events.ScheduleEvent(EVENT_SEVERE_DUSTING, 1s);
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim && victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_BABLET_KILL);
            }

            void JustDied(Unit* /**/) override
            {
                Talk(SAY_BABLET_DEATH);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                Creature* coggleston = me->FindNearestCreature(BOSS_COGGLESTON, 250.f, true);

                if (coggleston)
                    coggleston->GetAI()->DoAction(ACTION_MINION_DEAD);
            }

            void EnterEvadeMode(EvadeReason why) override
            {
                Creature* coggleston = me->FindNearestCreature(BOSS_COGGLESTON, 250.f, true);

                if (coggleston)
                    coggleston->AI()->EnterEvadeMode();

                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                me->RemoveAurasDueToSpell(SPELL_EMINENCE);
                me->RemoveAllAreaTriggers();
                CreatureAI::EnterEvadeMode(why);
            }

            void ExecuteEvent(uint32 eventId) override
            {
                if (eventId == EVENT_SEVERE_DUSTING)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                        me->CastSpell(target, SPELL_SEVERE_DUSTING, false);

                    events.ScheduleEvent(EVENT_SEVERE_DUSTING, 1s);
                }
            }

            private:
                ObjectGuid _markedGUID;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_opera_bablet_AI(creature);
        }
};

class boss_opera_elfyra : public CreatureScript
{
    public:
        boss_opera_elfyra() : CreatureScript("boss_opera_elfyra") { }

        struct boss_opera_elfyra_AI : public BossAI
        {
            explicit boss_opera_elfyra_AI(Creature* creature) : BossAI(creature, DATA_OPERA) { }

            void KilledUnit(Unit* victim) override
            {
                if (victim && victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_ELFYRA_KILL);
            }

            void DamageTaken(Unit* owner, uint32 & damage) override
            {
                Creature* galindre = me->FindNearestCreature(BOSS_GALINDRE, 250.f);

                if (galindre)
                {
                    if (owner->GetEntry() != BOSS_GALINDRE)
                        me->DealDamage(galindre, damage);
                }
            }

            void EnterCombat(Unit* /**/) override
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                _EnterCombat();
                events.ScheduleEvent(EVENT_DEFY_GRAVITY, 10s, 15s);
                events.ScheduleEvent(EVENT_DREARY_BOLT, 5s);
                events.ScheduleEvent(EVENT_SUMMON_ASSISTANT, 30s);
            }

            void JustDied(Unit* /**/) override
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                Talk(SAY_ELFYRA_DEATH);
                me->RemoveAllAreaTriggers();
                _JustDied();
            }

            void EnterEvadeMode(EvadeReason why) override
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                me->RemoveAllAreaTriggers();
                CreatureAI::EnterEvadeMode(why);
            }

            void ExecuteEvent(uint32 eventId) override
            {
                switch (eventId)
                {
                    case EVENT_DEFY_GRAVITY:
                    {
                        if (roll_chance_i(33))
                            Talk(SAY_DEFY_GRAVITY);

                        DoCast(me, SPELL_DEFY_GRAVITY);
                        events.ScheduleEvent(EVENT_DEFY_GRAVITY, 10s, 15s);
                        break;
                    }

                    case EVENT_DREARY_BOLT:
                    {
                        DoCastVictim(SPELL_DREARY_BOLT);
                        events.ScheduleEvent(EVENT_DREARY_BOLT, 7s);
                        break;
                    }

                    case EVENT_SUMMON_ASSISTANT:
                    {
                        Talk(SAY_SUMMON_ASSISTANTS);
                        DoCast(me, SPELL_SUMMON_ASSISTANTS);
                        events.ScheduleEvent(EVENT_SUMMON_ASSISTANT, 35s);
                        break;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_opera_elfyra_AI(creature);
        }
};

class boss_opera_galyndre : public CreatureScript
{
    public:
        boss_opera_galyndre() : CreatureScript("boss_opera_galyndre") { }

        struct boss_opera_galyndre_AI : public BossAI
        {
            explicit boss_opera_galyndre_AI(Creature* creature) : BossAI(creature, DATA_OPERA)
            {
                me->CastSpell(me, SPELL_WIKKET_BOND, true);
            }

            void EnterCombat(Unit* /**/) override
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                events.ScheduleEvent(EVENT_WONDROUS_RADIANCE, 10s);
                events.ScheduleEvent(EVENT_MAGIC_MAFNIFICENT, 45s);
                events.ScheduleEvent(EVENT_FLASHY_BOLT, 2s);
            }

            void DamageTaken(Unit* owner, uint32 & damage) override
            {
                Creature* elfyra = me->FindNearestCreature(BOSS_ELFYRA, 250.f);

                if (elfyra)
                {
                    if (owner->GetEntry() != BOSS_ELFYRA)
                        me->DealDamage(elfyra, damage);
                }
            }

            void JustDied(Unit* /**/) override
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                me->RemoveAllAreaTriggers();
                _JustDied();
            }

            void EnterEvadeMode(EvadeReason why) override
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                me->RemoveAllAreaTriggers();
                CreatureAI::EnterEvadeMode(why);
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim && victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_GALINDRE_KILL);
            }

            void ExecuteEvent(uint32 eventId) override
            {
                switch (eventId)
                {
                    case EVENT_MAGIC_MAFNIFICENT:
                    {
                        Talk(SAY_MAGIC_MAGNIFICENT);
                        me->CastSpell(me, SPELL_MAGIC_MAGNIFICENT_IMMUNITY, true);
                        me->CastSpell(me, SPELL_MAGIC_MAGNIFICENT_AOE, false);
                        events.ScheduleEvent(EVENT_MAGIC_MAFNIFICENT, 45s);
                        break;
                    }

                    case EVENT_FLASHY_BOLT:
                    {
                        DoCast(me, SPELL_FLASHY_BOLT);
                        events.ScheduleEvent(EVENT_FLASHY_BOLT, 5s);
                        break;
                    }

                    case EVENT_WONDROUS_RADIANCE:
                    {
                        DoCastVictim(SPELL_WONDROUS_RADIANCE);
                        events.ScheduleEvent(EVENT_WONDROUS_RADIANCE, 10s);
                        break;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_opera_galyndre_AI(creature);
        }
};

class npc_kara_winged_assistant : public CreatureScript
{
    public:
        npc_kara_winged_assistant() : CreatureScript("npc_kara_winged_assistant") { }

        struct npc_kara_winged_assistant_AI : public ScriptedAI
        {
            explicit npc_kara_winged_assistant_AI(Creature* creature) : ScriptedAI(creature) { }

            void Reset()
            {
                _events.Reset();
            }

            void EnterCombat(Unit* /**/) override
            {
                _events.ScheduleEvent(EVENT_THROW_STUFF, 500ms);
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_THROW_STUFF:
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                                DoCast(target, SPELL_THROW_STUFF);

                            _events.ScheduleEvent(EVENT_THROW_STUFF, 2s);
                            break;
                        }
                    }
                }
            }

            private:
                EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_kara_winged_assistant_AI(creature);
        }
};

class npc_kara_gang_ruffian : public CreatureScript
{
    public:
        npc_kara_gang_ruffian() : CreatureScript("npc_kara_gang_ruffian") { }

        struct npc_kara_gang_ruffian_AI : public ScriptedAI
        {
            explicit npc_kara_gang_ruffian_AI(Creature* creature) : ScriptedAI(creature) { }

            void Reset() override
            {
                _events.Reset();
                me->SetEmoteState(Emote::EMOTE_ONESHOT_NONE);
            }

            void EnterCombat(Unit* /**/) override
            {
                DoZoneInCombat();
                _events.ScheduleEvent(EVENT_POISONOUS_SHANK, 10s);
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type == POINT_MOTION_TYPE  && id == 0)
                    me->SetEmoteState(Emote::EMOTE_STATE_DANCE);
            }

            void DamageTaken(Unit* /**/, uint32 & damage) override
            {
                if (me->HealthBelowPctDamaged(2, damage))
                {
                    damage = 0;
                    _events.Reset();
                    me->SetHealth(me->GetMaxHealth() * 0.01f);
                    me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC));
                    me->SetReactState(REACT_PASSIVE);
                    me->GetMotionMaster()->MovePoint(0, me->GetHomePosition());
                }
            }

            void ExecuteEvent(uint32 eventId)
            {
                if (eventId == EVENT_POISONOUS_SHANK)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                        DoCast(target, SPELL_POISONOUS_SHANK);

                    _events.ScheduleEvent(EVENT_POISONOUS_SHANK, 10s);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                    ExecuteEvent(eventId);

                DoMeleeAttackIfReady();
            }
            private:
                EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_kara_gang_ruffian_AI(creature);
        }
};

class npc_kara_flashing_forks : public CreatureScript
{
    public:
        npc_kara_flashing_forks() : CreatureScript("npc_kara_flashing_forks") { }

        struct npc_kara_flashing_forks_AI : public ScriptedAI
        {
            explicit npc_kara_flashing_forks_AI(Creature* creature) : ScriptedAI(creature) { }

            void EnterCombat(Unit* /**/) override
            {
                _events.ScheduleEvent(EVENT_FLASHING_FORK, 2s);
                _events.ScheduleEvent(EVENT_BLOODY_JAB, 8s, 12s);
            }

            void Reset() override
            {
                _events.Reset();
            }

            void ExecuteEvent(uint32 eventId)
            {
                switch (eventId)
                {
                    case EVENT_FLASHING_FORK:
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                            DoCast(target, SPELL_FLASHING_FORKS);

                        _events.ScheduleEvent(EVENT_FLASHING_FORK, 15s, 20s);
                        break;
                    }

                    case EVENT_BLOODY_JAB:
                    {
                        DoCastVictim(SPELL_BLOODY_JAB);
                        _events.ScheduleEvent(EVENT_BLOODY_JAB, 8s, 12s);
                        break;
                    }
                }
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                    ExecuteEvent(eventId);

                DoMeleeAttackIfReady();
            }

            private:
                EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_kara_flashing_forks_AI(creature);
        }
};

class npc_kara_shoreline_speaker : public CreatureScript
{
    public:
        npc_kara_shoreline_speaker() : CreatureScript("npc_kara_shoreline_speaker") { }

        struct npc_kara_shoreline_speaker_AI : public ScriptedAI
        {
            explicit npc_kara_shoreline_speaker_AI(Creature* creature) : ScriptedAI(creature) { }

            void Reset() override
            {
                _events.Reset();
                me->SetReactState(REACT_PASSIVE);
                me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC));
                me->SetEmoteState(Emote::EMOTE_STATE_NONE);
            }

            void EnterCombat(Unit* /**/) override
            {
                DoZoneInCombat();
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (id == 0 && type == POINT_MOTION_TYPE)
                    me->SetEmoteState(Emote::EMOTE_STATE_DANCE);
            }

            void DamageTaken(Unit* /**/, uint32 & damage) override
            {
                if (me->HealthBelowPctDamaged(5, damage))
                {
                    damage = 0;
                    _events.Reset();
                    me->SetHealth(me->GetMaxHealth() * 0.01f);
                    me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC));
                    me->SetReactState(REACT_PASSIVE);
                    me->GetMotionMaster()->MovePoint(0, me->GetHomePosition());
                }
            }

            void DoAction(int32 action) override
            {
                if (action == ACTION_THE_FINS)
                {
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC));
                    _events.ScheduleEvent(EVENT_BUBBLE_BLAST, 10s);
                }
            }

            void ExecuteEvent(uint32 eventId)
            {
                if (eventId == EVENT_BUBBLE_BLAST)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                        DoCast(target, SPELL_BUBBLE_BLAST);

                    _events.ScheduleEvent(EVENT_BUBBLE_BLAST, 10s);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                    ExecuteEvent(eventId);

                DoMeleeAttackIfReady();
            }

            private:
                EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_kara_shoreline_speaker_AI(creature);
        }
};

class spell_opera_magic_magnificient : public SpellScriptLoader
{
    public:
        spell_opera_magic_magnificient() : SpellScriptLoader("spell_opera_magic_magnificient") { }

        class spell_magic_magnificient_SpellScript : public SpellScript
        {
            public:
                PrepareSpellScript(spell_magic_magnificient_SpellScript);

                void HandleBeforeCast()
                {
                    GetCaster()->RemoveAurasDueToSpell(SPELL_MAGIC_MAGNIFICENT_IMMUNITY);
                }

                void FilterTargets(SpellTargets & targets)
                {
                    if (targets.empty())
                        return;

                    targets.remove_if([] (WorldObject*& target)
                    {
                        return target->ToUnit()->HasAura(SPELL_DEFY_GRAVITY_DMG);
                    });
                }

                void Register() override
                {
                    BeforeCast += SpellCastFn(spell_magic_magnificient_SpellScript::HandleBeforeCast);
                    OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_magic_magnificient_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_magic_magnificient_SpellScript();
        }
};

class spell_opera_defy_gravity : public SpellScriptLoader
{
    public:
        spell_opera_defy_gravity() : SpellScriptLoader("spell_opera_defy_gravity") { }

        class spell_defy_gravity_SpellScript : public SpellScript
        {
            public:
                PrepareSpellScript(spell_defy_gravity_SpellScript);

                void HandleDummy(SpellEffIndex /**/)
                {
                    if (!GetHitUnit())
                        return;

                    GetCaster()->CastSpell(GetHitUnit(), SPELL_DEFY_GRAVITY_AREA, true);
                }

                void Register() override
                {
                    OnEffectHitTarget += SpellEffectFn(spell_defy_gravity_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
                }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_defy_gravity_SpellScript();
        }
};

class spell_opera_severe_dusting : public SpellScriptLoader
{
    public:
        spell_opera_severe_dusting() : SpellScriptLoader("spell_opera_severe_dusting") { }

        class spell_severe_dusting_AuraScript : public AuraScript
        {
            public:
                PrepareAuraScript(spell_severe_dusting_AuraScript);

                void HandlePeriodic(AuraEffect const* /**/)
                {
                    if (!GetUnitOwner())
                        return;

                    if (GetCaster()->GetDistance2d(GetUnitOwner()) <= 2.5f)
                    {
                        GetCaster()->CastSpell(GetUnitOwner(), SPELL_SEVERE_DUSTING_DMG, true);
                        GetCaster()->StopMoving();
                        GetCaster()->CastStop();
                    }

                    GetCaster()->GetMotionMaster()->MoveFollow(GetUnitOwner(), 0, 0);
                }

                void HandleOnApply(AuraEffect const* /**/, AuraEffectHandleModes /**/)
                {
                    if (!GetCaster())
                        return;

                    GetCaster()->SetWalk(true);
                }

                void HandleOnRemove(AuraEffect const* /**/, AuraEffectHandleModes /**/)
                {
                    GetCaster()->SetWalk(false);
                    if (Aura* dustArea = GetCaster()->GetAura(SPELL_SEVERE_DUSTING_AREA))
                        GetCaster()->RemoveAura(dustArea);
                }

                void Register() override
                {
                    OnEffectApply += AuraEffectApplyFn(spell_severe_dusting_AuraScript::HandleOnApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
                    OnEffectPeriodic += AuraEffectPeriodicFn(spell_severe_dusting_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
                    OnEffectRemove += AuraEffectRemoveFn(spell_severe_dusting_AuraScript::HandleOnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
                }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_severe_dusting_AuraScript();
        }
};

class spell_opera_summon_assistants : public SpellScriptLoader
{
    public:
        spell_opera_summon_assistants() : SpellScriptLoader("spell_opera_summon_assistants") { }

        class spell_summon_assistants_SpellScript : public SpellScript
        {
            public:
                PrepareSpellScript(spell_summon_assistants_SpellScript);

                void HandleOnCast()
                {
                    if (!GetCaster())
                        return;

                    for (uint8 i = 0; i < 3; ++i)
                        GetCaster()->SummonCreature(NPC_WINGED_ASSISTANT, GetCaster()->GetRandomNearPosition(frand(10.f, 15.f)), TEMPSUMMON_CORPSE_DESPAWN, 5000);
                }

                void Register() override
                {
                    OnCast += SpellCastFn(spell_summon_assistants_SpellScript::HandleOnCast);
                }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_summon_assistants_SpellScript();
        }
};

class spell_opera_dashing_gale : public SpellScriptLoader
{
    public:
        spell_opera_dashing_gale() : SpellScriptLoader("spell_opera_dashing_gale") { }

        class spell_dashing_gale_SpellScript : public SpellScript
        {
            public:
                PrepareSpellScript(spell_dashing_gale_SpellScript);

                void HandleTargets(SpellTargets& targets)
                {
                    if (targets.empty())
                        return;

                    for (auto & it : targets)
                        GetCaster()->GetAI()->SetGUID(it->GetGUID(), DATA_DASHING_FLAME);
                }

                void HandleAfterHit()
                {
                    GetCaster()->GetAI()->DoAction(ACTION_DASHING_FLAME);
                }

                void Register() override
                {
                    OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dashing_gale_SpellScript::HandleTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                    AfterHit += SpellHitFn(spell_dashing_gale_SpellScript::HandleAfterHit);
                }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dashing_gale_SpellScript();
        }
};

class spell_opera_dashing_gale_area : public SpellScriptLoader
{
    public:
        spell_opera_dashing_gale_area() : SpellScriptLoader("spell_opera_dashing_gale_area") { }

        class spell_dashing_gale_area_SpellScript : public SpellScript
        {
            public:
                PrepareSpellScript(spell_dashing_gale_area_SpellScript);

                void HandleOnHit(SpellEffIndex /**/)
                {
                    if (!GetHitUnit())
                        return;

                    GetCaster()->CastSpell(GetHitUnit(), SPELL_DASHING_FLAME_GALE_TRIGGER, true);
                }

                void Register() override
                {
                    OnEffectHitTarget += SpellEffectFn(spell_dashing_gale_area_SpellScript::HandleOnHit, EFFECT_2, SPELL_EFFECT_SCHOOL_DAMAGE);
                }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dashing_gale_area_SpellScript();
        }
};

class spell_opera_thunder_ritual : public SpellScriptLoader
{
    public:
        spell_opera_thunder_ritual() : SpellScriptLoader("spell_opera_thunder_ritual") { }

        class spell_thunder_ritual_AuraScript : public AuraScript
        {
            public:
                PrepareAuraScript(spell_thunder_ritual_AuraScript);

                void HandleOnRemove(AuraEffect const* /**/, AuraEffectHandleModes /**/)
                {
                    if (!GetUnitOwner())
                        return;

                    GetUnitOwner()->CastSpell(GetUnitOwner(), SPELL_THUNDER_RITUAL_DMG, true);
                }

                void Register() override
                {
                    OnEffectRemove += AuraEffectRemoveFn(spell_thunder_ritual_AuraScript::HandleOnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
                }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_thunder_ritual_AuraScript();
        }
};

class spell_opera_wash_away : public SpellScriptLoader
{
    public:
        spell_opera_wash_away() : SpellScriptLoader("spell_opera_wash_away") { }

        class spell_wash_away_SpellScript : public SpellScript
        {
            public:
                PrepareSpellScript(spell_wash_away_SpellScript);

                void HandleOnCast()
                {
                    SpellCastTargets targets;
                    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(SPELL_WASH_AWAY_AREA, GetCaster()->GetMap()->GetDifficultyID());

                    for (auto & it : WavesPositions)
                    {
                        targets.SetDst(it);
                        GetCaster()->CastSpell(targets, spellInfo, nullptr, TRIGGERED_FULL_MASK);
                    }
                }

                void Register() override
                {
                    OnCast += SpellCastFn(spell_wash_away_SpellScript::HandleOnCast);
                }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_wash_away_SpellScript();
        }
};

class at_kara_defy_gravity : public AreaTriggerEntityScript
{
    public:
        at_kara_defy_gravity() : AreaTriggerEntityScript("at_kara_defy_gravity") { }

        struct at_kara_defy_gravity_AI : public AreaTriggerAI
        {
            explicit at_kara_defy_gravity_AI(AreaTrigger* at) : AreaTriggerAI(at)
            {
                _borned = false;
                _timerBorn = 0;
            }

            void OnUnitEnter(Unit* target) override
            {
                if (!_borned)
                    return;

                if (target && target->GetTypeId() == TYPEID_PLAYER)
                {
                    at->GetCaster()->CastSpell(target, SPELL_DEFY_GRAVITY_DMG);
                    at->Remove();
                }
            }

            void OnUpdate(uint32 diff) override
            {
                if (_borned)
                    return;

                _timerBorn += diff;

                if (_timerBorn >= 1500)
                    _borned = true;
            }

            private:
                bool _borned;
                uint32 _timerBorn;
        };

        AreaTriggerAI* GetAI(AreaTrigger* at) const override
        {
            return new at_kara_defy_gravity_AI(at);
        }
};

class at_kara_burning_blaze : public AreaTriggerEntityScript
{
    public:
        at_kara_burning_blaze() : AreaTriggerEntityScript("at_kara_burning_blaze") { }

        struct at_kara_burning_blaze_AI : public AreaTriggerAI
        {
            explicit at_kara_burning_blaze_AI(AreaTrigger* at) : AreaTriggerAI(at) { }

            void OnUnitEnter(Unit* target) override
            {
                if (!target)
                    return;

                if (target->GetEntry() == BOSS_BABLET)
                    target->CastSpell(target, SPELL_SULTRY_HEAT, true);
                else if (target->GetTypeId() == TYPEID_PLAYER)
                {
                    if (target->HasAura(SPELL_DRENCHED))
                        at->Remove();
                    else
                        at->GetCaster()->CastSpell(target, SPELL_BURNING_BLAZE_DMG, true);
                }
            }

            void OnUnitExit(Unit* target) override
            {
                if (target && target->GetTypeId() == TYPEID_PLAYER)
                    target->RemoveAurasDueToSpell(SPELL_BURNING_BLAZE_DMG);
            }
        };

        AreaTriggerAI* GetAI(AreaTrigger* at) const override
        {
            return new at_kara_burning_blaze_AI(at);
        }
};

class at_kara_dashing_gale : public AreaTriggerEntityScript
{
    public:
        at_kara_dashing_gale() : AreaTriggerEntityScript("at_kara_dashing_gale") { }

        struct at_kara_dashing_gale_AI : public AreaTriggerAI
        {
            explicit at_kara_dashing_gale_AI(AreaTrigger* at) : AreaTriggerAI(at) { }

            void OnUnitEnter(Unit* target) override
            {
                if (target && target->GetTypeId() == TYPEID_PLAYER)
                    at->GetCaster()->CastSpell(target, SPELL_DASHING_FLAME_GALE_DMG, true);
            }

            void OnUnitExit(Unit* target) override
            {
                if (target && target->GetTypeId() == TYPEID_PLAYER)
                    target->RemoveAurasDueToSpell(SPELL_DASHING_FLAME_GALE_DMG);
            }
        };

        AreaTriggerAI* GetAI(AreaTrigger* at) const override
        {
            return new at_kara_dashing_gale_AI(at);
        }
};

void AddSC_boss_opera_karazhan_legion()
{
    new npc_kara_barnes();

    // Westfall Story
    new boss_opera_toe_knee();
    new boss_opera_mrrgria();
    new npc_kara_gang_ruffian();
    new npc_kara_shoreline_speaker();
    new spell_opera_dashing_gale();
    new spell_opera_dashing_gale_area();
    new spell_opera_thunder_ritual();
    new spell_opera_wash_away();
    new at_kara_dashing_gale();

    // Beatiful Beast
    new boss_opera_coggleston();
    new boss_opera_bablet();
    new boss_opera_luminore();
    new boss_opera_mrs_cauldrons();
    new npc_kara_flashing_forks();
    new spell_opera_severe_dusting();
    new at_kara_burning_blaze();

    // Wikket
    new boss_opera_elfyra();
    new boss_opera_galyndre();
    new npc_kara_winged_assistant();
    new spell_opera_defy_gravity();
    new spell_opera_summon_assistants();
    new spell_opera_magic_magnificient();
    new at_kara_defy_gravity();
}
