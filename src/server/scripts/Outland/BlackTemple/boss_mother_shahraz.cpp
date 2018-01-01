/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
SDName: Boss_Mother_Shahraz
SD%Complete: 80
SDComment: Fatal Attraction slightly incorrect; need to damage only if affected players are within range of each other
SDCategory: Black Temple
EndScriptData */

#include "ScriptMgr.h"
#include "black_temple.h"
#include "Containers.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"

enum Texts
{
    //Speech'n'Sounds
    SAY_TAUNT    = 0,
    SAY_AGGRO    = 1,
    SAY_SPELL    = 2,
    SAY_SLAY     = 3,
    SAY_ENRAGE   = 4,
    SAY_DEATH    = 5
};

enum Spells
{
    SPELL_BEAM_SINISTER     = 40859,
    SPELL_BEAM_VILE         = 40860,
    SPELL_BEAM_WICKED       = 40861,
    SPELL_BEAM_SINFUL       = 40827,
    SPELL_ATTRACTION        = 40871,
    SPELL_SILENCING_SHRIEK  = 40823,
    SPELL_ENRAGE            = 23537,
    SPELL_SABER_LASH        = 40810, //43267
    SPELL_SABER_LASH_IMM    = 43690,
    SPELL_TELEPORT_VISUAL   = 40869,
    SPELL_BERSERK           = 45078
};

enum Events
{
    EVENT_RANDOM_BEAM       = 1,
    EVENT_PRISMATIC_SHIELD,
    EVENT_FATAL_ATTRACTION,
    EVENT_FATAL_ATTRACTION_EXPLOSION,
    EVENT_SABER_SLASH,
    EVENT_SILENCING_SHRIEK,
    EVENT_RANDOM_TAUNT,
    EVENT_BERSERK
};

enum Beams
{
    SINISTER_BEAM,
    VILE_BEAM,
    WICKED_BEAM,
    SINFUL_BEAM
};

uint32 PrismaticAuras[]=
{
    40880,                                                  // Shadow
    40882,                                                  // Fire
    40883,                                                  // Nature
    40891,                                                  // Arcane
    40896,                                                  // Frost
    40897,                                                  // Holy
};

Position const TeleportPoint[]=
{
    {959.996f, 212.576f, 193.843f},
    {932.537f, 231.813f, 193.838f},
    {958.675f, 254.767f, 193.822f},
    {946.955f, 201.316f, 192.535f},
    {944.294f, 149.676f, 197.551f},
    {930.548f, 284.888f, 193.367f},
    {965.997f, 278.398f, 195.777f}
};

class boss_mother_shahraz : public CreatureScript
{
public:
    boss_mother_shahraz() : CreatureScript("boss_mother_shahraz") { }

    struct boss_shahrazAI : public BossAI
    {
        boss_shahrazAI(Creature* creature) : BossAI(creature, DATA_MOTHER_SHAHRAZ)
        {
            Initialize();
        }

        void Initialize()
        {
            for (uint8 i = 0; i < 3; ++i)
                TargetGUID[i].Clear();

            BeamCount = 0;
            CurrentBeam = SINISTER_BEAM;   // 0 - Sinister, 1 - Vile, 2 - Wicked, 3 - Sinful
            ExplosionCount = 0;
            Enraged = false;
        }

        void Reset() override
        {
            Initialize();
            _Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            events.ScheduleEvent(EVENT_RANDOM_BEAM, 20000); // Timers may be incorrect
            events.ScheduleEvent(EVENT_FATAL_ATTRACTION, 60000);
            events.ScheduleEvent(EVENT_FATAL_ATTRACTION_EXPLOSION, 70000);
            events.ScheduleEvent(EVENT_SILENCING_SHRIEK, 30000);
            events.ScheduleEvent(EVENT_SABER_SLASH, 35000);
            events.ScheduleEvent(EVENT_RANDOM_TAUNT, urand(70000, 111000));
            events.ScheduleEvent(EVENT_PRISMATIC_SHIELD, 1000);
            events.ScheduleEvent(EVENT_BERSERK, 600000);
            Talk(SAY_AGGRO);
        }

        void KilledUnit(Unit* /*victim*/) override
        {
            Talk(SAY_SLAY);
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
            Talk(SAY_DEATH);
        }

        void TeleportPlayers()
        {
            Position const& random = Trinity::Containers::SelectRandomContainerElement(TeleportPoint);
            float X = random.GetPositionX();
            float Y = random.GetPositionY();
            float Z = random.GetPositionZ();
            for (uint8 i = 0; i < 3; ++i)
            {
                if (Unit* unit = SelectTarget(SELECT_TARGET_RANDOM, 1))
                    if (unit->IsAlive() && unit->GetTypeId() == TYPEID_PLAYER)
                    {
                        TargetGUID[i] = unit->GetGUID();
                        unit->CastSpell(unit, SPELL_TELEPORT_VISUAL, true);
                        DoTeleportPlayer(unit, X, Y, Z, unit->GetOrientation());
                    }
            }
        }

        void DamageTaken(Unit* /*attacker*/, uint32 &damage) override
        {
            if (!Enraged && me->HealthBelowPctDamaged(10, damage))
            {
                Enraged = true;
                DoCast(me, SPELL_ENRAGE, true);
                Talk(SAY_ENRAGE);
            }
        }

        void ExecuteEvent(uint32 eventId) override
        {
            switch (eventId)
            {
                case EVENT_RANDOM_BEAM:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    {
                        switch (CurrentBeam)
                        {
                            case SINISTER_BEAM:
                                DoCast(target, SPELL_BEAM_SINISTER);
                                break;
                            case VILE_BEAM:
                                DoCast(target, SPELL_BEAM_VILE);
                                break;
                            case WICKED_BEAM:
                                DoCast(target, SPELL_BEAM_WICKED);
                                break;
                            case SINFUL_BEAM:
                                DoCast(target, SPELL_BEAM_SINFUL);
                                break;
                            default:
                                break;
                        }

                        ++BeamCount;
                        uint32 Beam = CurrentBeam;
                        if (BeamCount > 3)
                            while (CurrentBeam == Beam)
                                CurrentBeam = urand(0, 3);
                    }
                    events.ScheduleEvent(EVENT_RANDOM_BEAM, 9000);
                    break;
                case EVENT_PRISMATIC_SHIELD:
                    // Random Prismatic Shield every 15 seconds.
                    DoCast(me, PrismaticAuras[urand(0, 5)]);
                    events.ScheduleEvent(EVENT_PRISMATIC_SHIELD, 15000);
                    break;
                case EVENT_FATAL_ATTRACTION:
                    // Select 3 random targets (can select same target more than once), teleport to a random location then make them cast explosions until they get away from each other.
                    ExplosionCount = 0;
                    TeleportPlayers();
                    Talk(SAY_SPELL);
                    events.ScheduleEvent(EVENT_FATAL_ATTRACTION_EXPLOSION, 2000);
                    events.ScheduleEvent(EVENT_FATAL_ATTRACTION, 40000, 71000);
                    break;
                case EVENT_FATAL_ATTRACTION_EXPLOSION:
                    // Just make them explode three times... they're supposed to keep exploding while they are in range, but it'll take too much code. I'll try to think of an efficient way for it later.
                    if (ExplosionCount < 3)
                    {
                        for (uint8 i = 0; i < 3; ++i)
                        {
                            if (!TargetGUID[i].IsEmpty())
                            {
                                if (Unit* unit = ObjectAccessor::GetUnit(*me, TargetGUID[i]))
                                    unit->CastSpell(unit, SPELL_ATTRACTION, true);
                                TargetGUID[i].Clear();
                            }
                        }
                        ++ExplosionCount;
                    }
                    else
                        ExplosionCount = 0;
                    events.ScheduleEvent(EVENT_FATAL_ATTRACTION_EXPLOSION, ExplosionCount < 3 ? 1000 : events.GetTimeUntilEvent(EVENT_FATAL_ATTRACTION) + 2000);
                    break;
                case EVENT_SILENCING_SHRIEK:
                    DoCastVictim(SPELL_SILENCING_SHRIEK);
                    events.ScheduleEvent(EVENT_SILENCING_SHRIEK, urand(25000, 35000));
                    break;
                case EVENT_SABER_SLASH:
                    DoCastVictim(SPELL_SABER_LASH);
                    events.ScheduleEvent(EVENT_SABER_SLASH, urand(25000, 35000));
                    break;
                case EVENT_RANDOM_TAUNT:
                    Talk(SAY_TAUNT);
                    events.ScheduleEvent(EVENT_RANDOM_TAUNT, urand(60000, 151000));
                    break;
                case EVENT_BERSERK:
                    DoCast(me, SPELL_BERSERK);
                    Talk(SAY_ENRAGE);
                    break;
                default:
                    break;
            }
        }

    private:
        ObjectGuid TargetGUID[3];
        uint32 BeamCount;
        uint32 CurrentBeam;
        uint32 ExplosionCount;
        bool Enraged;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetBlackTempleAI<boss_shahrazAI>(creature);
    }
};

void AddSC_boss_mother_shahraz()
{
    new boss_mother_shahraz();
}
