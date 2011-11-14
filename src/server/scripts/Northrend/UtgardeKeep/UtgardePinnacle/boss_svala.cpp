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

#include "ScriptPCH.h"
#include "utgarde_pinnacle.h"

enum Spells
{
    SPELL_CALL_FLAMES                             = 48258,
    SPELL_RITUAL_OF_THE_SWORD                     = 48276, //Effect #1 Teleport,  Effect #2 Dummy
    SPELL_SINSTER_STRIKE                          = 15667,
    H_SPELL_SINSTER_STRIKE                        = 59409,
    SPELL_SVALA_TRANSFORMING1                     = 54140,
    SPELL_SVALA_TRANSFORMING2                     = 54205
};
//not in db
enum Yells
{
    SAY_DIALOG_WITH_ARTHAS_1                      = -1575015,
    SAY_DIALOG_WITH_ARTHAS_2                      = -1575016,
    SAY_DIALOG_WITH_ARTHAS_3                      = -1575017,
    SAY_AGGRO                                     = -1575018,
    SAY_SLAY_1                                    = -1575019,
    SAY_SLAY_2                                    = -1575020,
    SAY_SLAY_3                                    = -1575021,
    SAY_DEATH                                     = -1575022,
    SAY_SACRIFICE_PLAYER_1                        = -1575023,
    SAY_SACRIFICE_PLAYER_2                        = -1575024,
    SAY_SACRIFICE_PLAYER_3                        = -1575025,
    SAY_SACRIFICE_PLAYER_4                        = -1575026,
    SAY_SACRIFICE_PLAYER_5                        = -1575027,
    SAY_DIALOG_OF_ARTHAS_1                        = -1575028,
    SAY_DIALOG_OF_ARTHAS_2                        = -1575029
};
enum Creatures
{
    CREATURE_ARTHAS                               = 29280, // Image of Arthas
    CREATURE_SVALA_SORROWGRAVE                    = 26668, // Svala after transformation
    CREATURE_SVALA                                = 29281, // Svala before transformation
    CREATURE_RITUAL_CHANNELER                     = 27281
};
enum ChannelerSpells
{
    //ritual channeler's spells
    SPELL_PARALYZE                                = 48278,
    SPELL_SHADOWS_IN_THE_DARK                     = 59407
};
enum Misc
{
    DATA_SVALA_DISPLAY_ID                         = 25944
};
enum IntroPhase
{
    IDLE,
    INTRO,
    FINISHED
};
enum CombatPhase
{
    NORMAL,
    SACRIFICING
};

static Position RitualChannelerPos[]=
{
    {296.42f, -355.01f, 90.94f, 0.0f},
    {302.36f, -352.01f, 90.54f, 0.0f},
    {291.39f, -350.89f, 90.54f, 0.0f}
};
static Position ArthasPos = { 295.81f, -366.16f, 92.57f, 1.58f };
static Position SvalaPos = { 296.632f, -346.075f, 90.6307f, 1.58f };

class boss_svala : public CreatureScript
{
public:
    boss_svala() : CreatureScript("boss_svala") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_svalaAI (creature);
    }

    struct boss_svalaAI : public ScriptedAI
    {
        boss_svalaAI(Creature* c) : ScriptedAI(c)
        {
            instance = c->GetInstanceScript();
        }

        uint32 uiIntroTimer;

        uint8 uiIntroPhase;

        IntroPhase Phase;

        TempSummon* pArthas;
        uint64 uiArthasGUID;

        InstanceScript* instance;

        void Reset()
        {
            Phase = IDLE;
            uiIntroTimer = 1 * IN_MILLISECONDS;
            uiIntroPhase = 0;
            uiArthasGUID = 0;

            if (instance)
                instance->SetData(DATA_SVALA_SORROWGRAVE_EVENT, NOT_STARTED);
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (!who)
                return;

            if (Phase == IDLE && me->IsValidAttackTarget(who) && me->IsWithinDistInMap(who, 40))
            {
                Phase = INTRO;
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

                if (Creature* pArthas = me->SummonCreature(CREATURE_ARTHAS, ArthasPos, TEMPSUMMON_MANUAL_DESPAWN))
                {
                    pArthas->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                    uiArthasGUID = pArthas->GetGUID();
                }
            }
        }

        void AttackStart(Unit* /*who*/) {}

        void UpdateAI(const uint32 diff)
        {
            if (Phase != INTRO)
                return;

            if (uiIntroTimer <= diff)
            {
                Creature* pArthas = Unit::GetCreature(*me, uiArthasGUID);
                if (!pArthas)
                    return;

                switch (uiIntroPhase)
                {
                    case 0:
                        DoScriptText(SAY_DIALOG_WITH_ARTHAS_1, me);
                        ++uiIntroPhase;
                        uiIntroTimer = 3500;
                        break;
                    case 1:
                        DoScriptText(SAY_DIALOG_OF_ARTHAS_1, pArthas);
                        ++uiIntroPhase;
                        uiIntroTimer = 3500;
                        break;
                    case 2:
                        DoScriptText(SAY_DIALOG_WITH_ARTHAS_2, me);
                        ++uiIntroPhase;
                        uiIntroTimer = 3500;
                        break;
                    case 3:
                        DoScriptText(SAY_DIALOG_OF_ARTHAS_2, pArthas);
                        ++uiIntroPhase;
                        uiIntroTimer = 3500;
                        break;
                    case 4:
                        DoScriptText(SAY_DIALOG_WITH_ARTHAS_3, me);
                        DoCast(me, SPELL_SVALA_TRANSFORMING1);
                        ++uiIntroPhase;
                        uiIntroTimer = 2800;
                        break;
                    case 5:
                        DoCast(me, SPELL_SVALA_TRANSFORMING2);
                        ++uiIntroPhase;
                        uiIntroTimer = 200;
                        break;
                    case 6:
                        if (me->SummonCreature(CREATURE_SVALA_SORROWGRAVE, SvalaPos, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 60*IN_MILLISECONDS))
                        {
                            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                            me->SetDisplayId(DATA_SVALA_DISPLAY_ID);
                            pArthas->DespawnOrUnsummon();
                            uiArthasGUID = 0;
                            Phase = FINISHED;
                        }
                        else
                            Reset();
                        break;
                }
            } else uiIntroTimer -= diff;
        }
    };

};

class mob_ritual_channeler : public CreatureScript
{
public:
    mob_ritual_channeler() : CreatureScript("mob_ritual_channeler") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_ritual_channelerAI(creature);
    }

    struct mob_ritual_channelerAI : public Scripted_NoMovementAI
    {
        mob_ritual_channelerAI(Creature* c) :Scripted_NoMovementAI(c)
        {
            instance = c->GetInstanceScript();
        }

        InstanceScript* instance;

        void Reset()
        {
            DoCast(me, SPELL_SHADOWS_IN_THE_DARK);
        }

        // called by svala sorrowgrave to set guid of victim
        void DoAction(const int32 /*action*/)
        {
            if (instance)
                if (Unit* victim = me->GetUnit(*me, instance->GetData64(DATA_SACRIFICED_PLAYER)))
                    DoCast(victim, SPELL_PARALYZE);
        }

        void EnterCombat(Unit* /*who*/)
        {
        }
    };

};

class boss_svala_sorrowgrave : public CreatureScript
{
public:
    boss_svala_sorrowgrave() : CreatureScript("boss_svala_sorrowgrave") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_svala_sorrowgraveAI(creature);
    }

    struct boss_svala_sorrowgraveAI : public ScriptedAI
    {
        boss_svala_sorrowgraveAI(Creature* c) : ScriptedAI(c), summons(c)
        {
            instance = c->GetInstanceScript();
        }

        uint32 uiSinsterStrikeTimer;
        uint32 uiCallFlamesTimer;
        uint32 uiRitualOfSwordTimer;
        uint32 uiSacrificeTimer;

        CombatPhase Phase;

        SummonList summons;

        bool bSacrificed;

        InstanceScript* instance;

        void Reset()
        {
            uiSinsterStrikeTimer = 7 * IN_MILLISECONDS;
            uiCallFlamesTimer = 10 * IN_MILLISECONDS;
            uiRitualOfSwordTimer = 20 * IN_MILLISECONDS;
            uiSacrificeTimer = 8 * IN_MILLISECONDS;

            bSacrificed = false;

            Phase = NORMAL;

            DoTeleportTo(296.632f, -346.075f, 90.6307f);
            me->SetUnitMovementFlags(MOVEMENTFLAG_WALKING);

            summons.DespawnAll();

            if (instance)
            {
                instance->SetData(DATA_SVALA_SORROWGRAVE_EVENT, NOT_STARTED);
                instance->SetData64(DATA_SACRIFICED_PLAYER, 0);
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoScriptText(SAY_AGGRO, me);

            if (instance)
                instance->SetData(DATA_SVALA_SORROWGRAVE_EVENT, IN_PROGRESS);
        }

        void JustSummoned(Creature* summon)
        {
            summons.Summon(summon);
        }

        void SummonedCreatureDespawn(Creature* summon)
        {
            summons.Despawn(summon);
        }

        void UpdateAI(const uint32 diff)
        {
            if (Phase == NORMAL)
            {
                //Return since we have no target
                if (!UpdateVictim())
                    return;

                if (uiSinsterStrikeTimer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_SINSTER_STRIKE);
                    uiSinsterStrikeTimer = urand(5 * IN_MILLISECONDS, 9 * IN_MILLISECONDS);
                } else uiSinsterStrikeTimer -= diff;

                if (uiCallFlamesTimer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    {
                        DoCast(target, SPELL_CALL_FLAMES);
                        uiCallFlamesTimer = urand(8 * IN_MILLISECONDS, 12 * IN_MILLISECONDS);
                    }
                } else uiCallFlamesTimer -= diff;

                if (!bSacrificed)
                {
                    if (uiRitualOfSwordTimer <= diff)
                    {
                        if (Unit* pSacrificeTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        {
                            DoScriptText(RAND(SAY_SACRIFICE_PLAYER_1, SAY_SACRIFICE_PLAYER_2, SAY_SACRIFICE_PLAYER_3, SAY_SACRIFICE_PLAYER_4, SAY_SACRIFICE_PLAYER_5), me);
                            DoCast(pSacrificeTarget, SPELL_RITUAL_OF_THE_SWORD);
                            //Spell doesn't teleport
                            DoTeleportPlayer(pSacrificeTarget, 296.632f, -346.075f, 90.63f, 4.6f);
                            me->SetUnitMovementFlags(MOVEMENTFLAG_CAN_FLY);
                            DoTeleportTo(296.632f, -346.075f, 120.85f);
                            Phase = SACRIFICING;
                            if (instance)
                            {
                                instance->SetData64(DATA_SACRIFICED_PLAYER, pSacrificeTarget->GetGUID());

                                for (uint8 i = 0; i < 3; ++i)
                                    if (Creature* summon = me->SummonCreature(CREATURE_RITUAL_CHANNELER, RitualChannelerPos[i], TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 360000))
                                        summon->AI()->DoAction(0);
                            }

                            bSacrificed = true;
                        }
                    } else uiRitualOfSwordTimer -= diff;
                }

                DoMeleeAttackIfReady();
            }
            else  //SACRIFICING
            {
                if (uiSacrificeTimer <= diff)
                {
                    Unit* pSacrificeTarget = instance ? Unit::GetUnit(*me, instance->GetData64(DATA_SACRIFICED_PLAYER)) : NULL;
                    if (instance && !summons.empty() && pSacrificeTarget && pSacrificeTarget->isAlive())
                        me->Kill(pSacrificeTarget, false); // durability damage?

                    //go down
                    Phase = NORMAL;
                    pSacrificeTarget = NULL;
                    me->SetUnitMovementFlags(MOVEMENTFLAG_WALKING);
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        me->GetMotionMaster()->MoveChase(target);

                    uiSacrificeTimer = 8 * IN_MILLISECONDS;
                }
                else uiSacrificeTimer -= diff;
            }
        }

        void KilledUnit(Unit* /*victim*/)
        {
            DoScriptText(RAND(SAY_SLAY_1, SAY_SLAY_2, SAY_SLAY_3), me);
        }

        void JustDied(Unit* killer)
        {
            if (instance)
            {
                Creature* pSvala = Unit::GetCreature((*me), instance->GetData64(DATA_SVALA));
                if (pSvala && pSvala->isAlive())
                    killer->Kill(pSvala);

                instance->SetData(DATA_SVALA_SORROWGRAVE_EVENT, DONE);
            }
            DoScriptText(SAY_DEATH, me);
        }
    };

};

void AddSC_boss_svala()
{
    new boss_svala();
    new mob_ritual_channeler();
    new boss_svala_sorrowgrave();
}
