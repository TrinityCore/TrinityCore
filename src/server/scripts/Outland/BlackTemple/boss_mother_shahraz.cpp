/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

/* ScriptData
SDName: Boss_Mother_Shahraz
SD%Complete: 80
SDComment: Saber Lash missing, Fatal Attraction slightly incorrect; need to damage only if affected players are within range of each other
SDCategory: Black Temple
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "black_temple.h"

enum MotherShahraz
{
    //Speech'n'Sounds
    SAY_TAUNT               = 0,
    SAY_AGGRO               = 1,
    SAY_SPELL               = 2,
    SAY_SLAY                = 3,
    SAY_ENRAGE              = 4,
    SAY_DEATH               = 5,

    //Spells
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

uint32 PrismaticAuras[]=
{
    40880,                                                  // Shadow
    40882,                                                  // Fire
    40883,                                                  // Nature
    40891,                                                  // Arcane
    40896,                                                  // Frost
    40897,                                                  // Holy
};

struct Locations
{
    float x, y, z;
};

static Locations TeleportPoint[]=
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

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return GetInstanceAI<boss_shahrazAI>(creature);
    }

    struct boss_shahrazAI : public ScriptedAI
    {
        boss_shahrazAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        uint64 TargetGUID[3];
        uint32 BeamTimer;
        uint32 BeamCount;
        uint32 CurrentBeam;
        uint32 PrismaticShieldTimer;
        uint32 FatalAttractionTimer;
        uint32 FatalAttractionExplodeTimer;
        uint32 ShriekTimer;
        uint32 SaberTimer;
        uint32 RandomYellTimer;
        uint32 EnrageTimer;
        uint32 ExplosionCount;

        bool Enraged;

        void Reset() OVERRIDE
        {
            instance->SetBossState(DATA_MOTHER_SHAHRAZ, NOT_STARTED);

            for (uint8 i = 0; i<3; ++i)
                TargetGUID[i] = 0;

            BeamTimer = 20000; // Timers may be incorrect
            BeamCount = 0;
            CurrentBeam = 0;                                    // 0 - Sinister, 1 - Vile, 2 - Wicked, 3 - Sinful
            PrismaticShieldTimer = 0;
            FatalAttractionTimer = 60000;
            FatalAttractionExplodeTimer = 70000;
            ShriekTimer = 30000;
            SaberTimer = 35000;
            RandomYellTimer = urand(70, 111) * 1000;
            EnrageTimer = 600000;
            ExplosionCount = 0;

            Enraged = false;
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            instance->SetBossState(DATA_MOTHER_SHAHRAZ, IN_PROGRESS);

            DoZoneInCombat();
            Talk(SAY_AGGRO);
        }

        void KilledUnit(Unit* /*victim*/) OVERRIDE
        {
            Talk(SAY_SLAY);
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            instance->SetBossState(DATA_MOTHER_SHAHRAZ, DONE);

            Talk(SAY_DEATH);
        }

        void TeleportPlayers()
        {
            uint32 random = rand()%7;
            float X = TeleportPoint[random].x;
            float Y = TeleportPoint[random].y;
            float Z = TeleportPoint[random].z;
            for (uint8 i = 0; i < 3; ++i)
            {
                Unit* unit = SelectTarget(SELECT_TARGET_RANDOM, 1);
                if (unit && unit->IsAlive() && (unit->GetTypeId() == TYPEID_PLAYER))
                {
                    TargetGUID[i] = unit->GetGUID();
                    unit->CastSpell(unit, SPELL_TELEPORT_VISUAL, true);
                    DoTeleportPlayer(unit, X, Y, Z, unit->GetOrientation());
                }
            }
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            if (HealthBelowPct(10) && !Enraged)
            {
                Enraged = true;
                DoCast(me, SPELL_ENRAGE, true);
                Talk(SAY_ENRAGE);
            }

            //Randomly cast one beam.
            if (BeamTimer <= diff)
            {
                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0);
                if (!target || !target->IsAlive())
                    return;

                BeamTimer = 9000;

                switch (CurrentBeam)
                {
                    case 0:
                        DoCast(target, SPELL_BEAM_SINISTER);
                        break;
                    case 1:
                        DoCast(target, SPELL_BEAM_VILE);
                        break;
                    case 2:
                        DoCast(target, SPELL_BEAM_WICKED);
                        break;
                    case 3:
                        DoCast(target, SPELL_BEAM_SINFUL);
                        break;
                }
                ++BeamCount;
                uint32 Beam = CurrentBeam;
                if (BeamCount > 3)
                    while (CurrentBeam == Beam)
                        CurrentBeam = rand()%3;

            } else BeamTimer -= diff;

            // Random Prismatic Shield every 15 seconds.
            if (PrismaticShieldTimer <= diff)
            {
                uint32 random = rand()%6;
                if (PrismaticAuras[random])
                    DoCast(me, PrismaticAuras[random]);
                PrismaticShieldTimer = 15000;
            } else PrismaticShieldTimer -= diff;

            // Select 3 random targets (can select same target more than once), teleport to a random location then make them cast explosions until they get away from each other.
            if (FatalAttractionTimer <= diff)
            {
                ExplosionCount = 0;

                TeleportPlayers();

                Talk(SAY_SPELL);
                FatalAttractionExplodeTimer = 2000;
                FatalAttractionTimer = urand(40, 71) * 1000;
            } else FatalAttractionTimer -= diff;

            if (FatalAttractionExplodeTimer <= diff)
            {
                // Just make them explode three times... they're supposed to keep exploding while they are in range, but it'll take too much code. I'll try to think of an efficient way for it later.
                if (ExplosionCount < 3)
                {
                    for (uint8 i = 0; i < 3; ++i)
                    {
                        if (TargetGUID[i])
                        {
                            if (Unit* unit = Unit::GetUnit(*me, TargetGUID[i]))
                                unit->CastSpell(unit, SPELL_ATTRACTION, true);
                            TargetGUID[i] = 0;
                        }
                    }

                    ++ExplosionCount;
                    FatalAttractionExplodeTimer = 1000;
                }
                else
                {
                    FatalAttractionExplodeTimer = FatalAttractionTimer + 2000;
                    ExplosionCount = 0;
                }
            } else FatalAttractionExplodeTimer -= diff;

            if (ShriekTimer <= diff)
            {
                DoCastVictim(SPELL_SILENCING_SHRIEK);
                ShriekTimer = 25000+rand()%10 * 1000;
            } else ShriekTimer -= diff;

            if (SaberTimer <= diff)
            {
                DoCastVictim(SPELL_SABER_LASH);
                SaberTimer = 25000+rand()%10 * 1000;
            } else SaberTimer -= diff;

            //Enrage
            if (!me->HasAura(SPELL_BERSERK))
            {
                if (EnrageTimer <= diff)
                {
                    DoCast(me, SPELL_BERSERK);
                    Talk(SAY_ENRAGE);
                } else EnrageTimer -= diff;
            }

            //Random taunts
            if (RandomYellTimer <= diff)
            {
                Talk(SAY_TAUNT);
                RandomYellTimer = urand(60, 151) * 1000;
            } else RandomYellTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_mother_shahraz()
{
    new boss_mother_shahraz();
}
