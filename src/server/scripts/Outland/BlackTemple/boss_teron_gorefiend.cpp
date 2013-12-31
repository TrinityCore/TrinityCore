/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
SDName: Boss_Teron_Gorefiend
SD%Complete: 60
SDComment: Requires Mind Control support for Ghosts.
SDCategory: Black Temple
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "black_temple.h"

enum DoomBlossom
{
    //Speech'n'sound
    SAY_INTRO                       = 0,
    SAY_AGGRO                       = 1,
    SAY_SLAY                        = 2,
    SAY_SPELL                       = 3,
    SAY_SPECIAL                     = 4,
    SAY_ENRAGE                      = 5,
    SAY_DEATH                       = 6,

    //Spells
    SPELL_INCINERATE                = 40239,
    SPELL_CRUSHING_SHADOWS          = 40243,
    SPELL_SHADOWBOLT                = 40185,
    SPELL_PASSIVE_SHADOWFORM        = 40326,
    SPELL_SHADOW_OF_DEATH           = 40251,
    SPELL_BERSERK                   = 45078,
    SPELL_ATROPHY                   = 40327,               // Shadowy Constructs use this when they get within melee range of a player

    CREATURE_DOOM_BLOSSOM           = 23123,
    CREATURE_SHADOWY_CONSTRUCT      = 23111
};

class npc_doom_blossom : public CreatureScript
{
public:
    npc_doom_blossom() : CreatureScript("npc_doom_blossom") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_doom_blossomAI(creature);
    }

    struct npc_doom_blossomAI : public ScriptedAI
    {
        npc_doom_blossomAI(Creature* creature) : ScriptedAI(creature) { }

        uint32 CheckTeronTimer;
        uint32 ShadowBoltTimer;
        uint64 TeronGUID;

        void Reset() OVERRIDE
        {
            CheckTeronTimer = 5000;
            ShadowBoltTimer = 12000;
            TeronGUID = 0;
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE { }
        void AttackStart(Unit* /*who*/) OVERRIDE { }
        void MoveInLineOfSight(Unit* /*who*/) OVERRIDE { }


        void Despawn()
        {
            me->DealDamage(me, me->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
            me->RemoveCorpse();
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (CheckTeronTimer <= diff)
            {
                if (TeronGUID)
                {
                    DoZoneInCombat();

                    Creature* Teron = (Unit::GetCreature((*me), TeronGUID));
                    if ((Teron) && (!Teron->IsAlive() || Teron->IsInEvadeMode()))
                        Despawn();
                }
                else
                    Despawn();

                CheckTeronTimer = 5000;
            } else CheckTeronTimer -= diff;

            if (ShadowBoltTimer < diff && me->IsInCombat())
            {
                DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0), SPELL_SHADOWBOLT);
                ShadowBoltTimer = 10000;
            } else ShadowBoltTimer -= diff;
            return;
        }

        void SetTeronGUID(uint64 guid)
        {
            TeronGUID = guid;
        }
    };
};

class npc_shadowy_construct : public CreatureScript
{
public:
    npc_shadowy_construct() : CreatureScript("npc_shadowy_construct") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_shadowy_constructAI(creature);
    }

    struct npc_shadowy_constructAI : public ScriptedAI
    {
        npc_shadowy_constructAI(Creature* creature) : ScriptedAI(creature) { }

        uint64 GhostGUID;
        uint64 TeronGUID;

        uint32 CheckPlayerTimer;
        uint32 CheckTeronTimer;

        void Reset() OVERRIDE
        {
            GhostGUID = 0;
            TeronGUID = 0;

            CheckPlayerTimer = 2000;
            CheckTeronTimer = 5000;
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE { }

        void MoveInLineOfSight(Unit* who) OVERRIDE

        {
            if (!who || (!who->IsAlive()) || (who->GetGUID() == GhostGUID))
                return;

            ScriptedAI::MoveInLineOfSight(who);
        }

    /* Comment it out for now. NOTE TO FUTURE DEV: UNCOMMENT THIS OUT ONLY AFTER MIND CONTROL IS IMPLEMENTED
        void DamageTaken(Unit* done_by, uint32 &damage) OVERRIDE
        {
            if (done_by->GetGUID() != GhostGUID)
            damage = 0;                                         // Only the ghost can deal damage.
        }
     */

        void CheckPlayers()
        {
            ThreatContainer::StorageType const &threatlist = me->getThreatManager().getThreatList();
            if (threatlist.empty())
                return;                                         // No threat list. Don't continue.
            ThreatContainer::StorageType::const_iterator itr = threatlist.begin();
            std::list<Unit*> targets;
            for (; itr != threatlist.end(); ++itr)
            {
                Unit* unit = Unit::GetUnit(*me, (*itr)->getUnitGuid());
                if (unit && unit->IsAlive())
                    targets.push_back(unit);
            }
            targets.sort(Trinity::ObjectDistanceOrderPred(me));
            Unit* target = targets.front();
            if (target && me->IsWithinDistInMap(target, me->GetAttackDistance(target)))
            {
                DoCast(target, SPELL_ATROPHY);
                me->AI()->AttackStart(target);
            }
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (CheckPlayerTimer <= diff)
            {
                CheckPlayers();
                CheckPlayerTimer = 3000;
            } else CheckPlayerTimer -= diff;

            if (CheckTeronTimer <= diff)
            {
                Creature* Teron = (Unit::GetCreature((*me), TeronGUID));
                if (!Teron || !Teron->IsAlive() || Teron->IsInEvadeMode())
                    me->DealDamage(me, me->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);

                CheckTeronTimer = 5000;
            } else CheckTeronTimer -= diff;
        }
    };
};

class boss_teron_gorefiend : public CreatureScript
{
public:
    boss_teron_gorefiend() : CreatureScript("boss_teron_gorefiend") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return GetInstanceAI<boss_teron_gorefiendAI>(creature);
    }

    struct boss_teron_gorefiendAI : public ScriptedAI
    {
        boss_teron_gorefiendAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        uint32 IncinerateTimer;
        uint32 SummonDoomBlossomTimer;
        uint32 EnrageTimer;
        uint32 CrushingShadowsTimer;
        uint32 ShadowOfDeathTimer;
        uint32 SummonShadowsTimer;
        uint32 RandomYellTimer;
        uint32 AggroTimer;

        uint64 AggroTargetGUID;
        uint64 GhostGUID;                                       // Player that gets killed by Shadow of Death and gets turned into a ghost

        bool Intro;
        bool Done;

        void Reset() OVERRIDE
        {
            instance->SetBossState(DATA_TERON_GOREFIEND, NOT_STARTED);

            IncinerateTimer = urand(20000, 31000);
            SummonDoomBlossomTimer = 12000;
            EnrageTimer = 600000;
            CrushingShadowsTimer = 22000;
            SummonShadowsTimer = 60000;
            RandomYellTimer = 50000;

            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            // Start off unattackable so that the intro is done properly
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

            AggroTimer = 20000;
            AggroTargetGUID = 0;
            Intro = false;
            Done = false;
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE { }

        void MoveInLineOfSight(Unit* who) OVERRIDE

        {
            if (!Intro && who->GetTypeId() == TYPEID_PLAYER && me->CanCreatureAttack(who))
            {
                if (me->IsWithinDistInMap(who, VISIBLE_RANGE) && me->IsWithinLOSInMap(who))
                {
                    instance->SetBossState(DATA_TERON_GOREFIEND, IN_PROGRESS);

                    me->GetMotionMaster()->Clear(false);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    Talk(SAY_INTRO);
                    me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_TALK);
                    AggroTargetGUID = who->GetGUID();
                    Intro = true;
                }
            }
            if (Done)
                ScriptedAI::MoveInLineOfSight(who);
        }

        void KilledUnit(Unit* /*victim*/) OVERRIDE
        {
            Talk(SAY_SLAY);
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            instance->SetBossState(DATA_TERON_GOREFIEND, DONE);

            Talk(SAY_DEATH);
        }

        float CalculateRandomLocation(float Loc, uint32 radius)
        {
            float coord = Loc;
            switch (urand(0, 1))
            {
                case 0:
                    coord += rand()%radius;
                    break;
                case 1:
                    coord -= rand()%radius;
                    break;
            }
            return coord;
        }

        void SetThreatList(Creature* blossom)
        {
            if (!blossom)
                return;

            ThreatContainer::StorageType const &threatlist = me->getThreatManager().getThreatList();
            ThreatContainer::StorageType::const_iterator i = threatlist.begin();
            for (i = threatlist.begin(); i != threatlist.end(); ++i)
            {
                Unit* unit = Unit::GetUnit(*me, (*i)->getUnitGuid());
                if (unit && unit->IsAlive())
                {
                    float threat = DoGetThreat(unit);
                    blossom->AddThreat(unit, threat);
                }
            }
        }

        void MindControlGhost()
        {
            /************************************************************************/
            /** NOTE FOR FUTURE DEVELOPER: PROPERLY IMPLEMENT THE GHOST PORTION *****/
            /**  ONLY AFTER TrinIty FULLY IMPLEMENTS MIND CONTROL ABILITIES      *****/
            /**   THE CURRENT CODE IN THIS FUNCTION IS ONLY THE BEGINNING OF    *****/
            /**    WHAT IS FULLY NECESSARY FOR GOREFIEND TO BE 100% COMPLETE    *****/
            /************************************************************************/

            Unit* ghost = NULL;
            if (GhostGUID)
                ghost = Unit::GetUnit(*me, GhostGUID);
            if (ghost && ghost->IsAlive() && ghost->HasAura(SPELL_SHADOW_OF_DEATH))
            {
                /*float x, y, z;
                ghost->GetPosition(x, y, z);
                if (Creature* control = me->SummonCreature(CREATURE_GHOST, x, y, z, 0, TEMPSUMMON_TIMED_DESAWN, 30000))
                {
                    if (Player* player = ghost->ToPlayer())
                        player->Possess(control);
                    ghost->DealDamage(ghost, ghost->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL,
                false);
                }*/
                for (uint8 i = 0; i < 4; ++i)
                {
                    Creature* Construct = NULL;
                    float X = CalculateRandomLocation(ghost->GetPositionX(), 10);
                    float Y = CalculateRandomLocation(ghost->GetPositionY(), 10);
                    Construct = me->SummonCreature(CREATURE_SHADOWY_CONSTRUCT, X, Y, ghost->GetPositionZ(), 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 45000);
                    if (Construct)
                    {
                        Construct->CastSpell(Construct, SPELL_PASSIVE_SHADOWFORM, true);
                        SetThreatList(Construct);               // Use same function as Doom Blossom to set Threat List.
                        CAST_AI(npc_shadowy_construct::npc_shadowy_constructAI, Construct->AI())->GhostGUID = GhostGUID;
                        Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1);
                        if (!target)                             // someone's trying to solo.
                            target = me->GetVictim();

                        if (target)
                            Construct->GetMotionMaster()->MoveChase(target);
                    }
                }
            }
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (Intro && !Done)
            {
                if (AggroTimer <= diff)
                {
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    Talk(SAY_AGGRO);
                    me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_NONE);
                    Done = true;
                    if (AggroTargetGUID)
                    {
                        Unit* unit = Unit::GetUnit(*me, AggroTargetGUID);
                        if (unit)
                            AttackStart(unit);

                        DoZoneInCombat();
                    }
                    else
                    {
                        EnterEvadeMode();
                        return;
                    }
                } else AggroTimer -= diff;
            }

            if (!UpdateVictim() || !Done)
                return;

            if (SummonShadowsTimer <= diff)
            {
                //MindControlGhost();

                for (uint8 i = 0; i < 2; ++i)
                {
                    Creature* Shadow = NULL;
                    float X = CalculateRandomLocation(me->GetPositionX(), 10);
                    Shadow = me->SummonCreature(CREATURE_SHADOWY_CONSTRUCT, X, me->GetPositionY(), me->GetPositionZ(), 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 0);
                    if (Shadow)
                    {
                        Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1);
                        if (!target)
                            target = me->GetVictim();

                        if (target)
                            Shadow->AI()->AttackStart(target);
                    }
                }
                SummonShadowsTimer = 60000;
            } else SummonShadowsTimer -= diff;

            if (SummonDoomBlossomTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                {
                    float X = CalculateRandomLocation(target->GetPositionX(), 20);
                    float Y = CalculateRandomLocation(target->GetPositionY(), 20);
                    float Z = target->GetPositionZ();
                    Z = me->GetMap()->GetHeight(me->GetPhaseMask(), X, Y, Z);
                    Creature* DoomBlossom = me->SummonCreature(CREATURE_DOOM_BLOSSOM, X, Y, Z, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 20000);
                    if (DoomBlossom)
                    {
                        DoomBlossom->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        DoomBlossom->setFaction(me->getFaction());
                        DoomBlossom->AddThreat(target, 1.0f);
                        CAST_AI(npc_doom_blossom::npc_doom_blossomAI, DoomBlossom->AI())->SetTeronGUID(me->GetGUID());
                        target->CombatStart(DoomBlossom);
                        SetThreatList(DoomBlossom);
                        SummonDoomBlossomTimer = 35000;
                    }
                }
            } else SummonDoomBlossomTimer -= diff;

            if (IncinerateTimer <= diff)
            {
                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1);
                if (!target)
                    target = me->GetVictim();

                if (target)
                {
                    Talk(SAY_SPECIAL);
                    DoCast(target, SPELL_INCINERATE);
                    IncinerateTimer = urand(20, 51) * 1000;
                }
            } else IncinerateTimer -= diff;

            if (CrushingShadowsTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_CRUSHING_SHADOWS);
                CrushingShadowsTimer = urand(10, 26) * 1000;
            } else CrushingShadowsTimer -= diff;

            /*** NOTE FOR FUTURE DEV: UNCOMMENT BELOW ONLY IF MIND CONTROL IS FULLY IMPLEMENTED **/
            /*if (ShadowOfDeathTimer <= diff)
            {
                Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 1);

                if (!target)
                   target = me->GetVictim();

                if (target && target->IsAlive() && target->GetTypeId() == TYPEID_PLAYER)
                {
                    DoCast(target, SPELL_SHADOW_OF_DEATH);
                    GhostGUID = target->GetGUID();
                    ShadowOfDeathTimer = 30000;
                    SummonShadowsTimer = 53000; // Make it VERY close but slightly less so that we can check if the aura is still on the player
                }
            } else ShadowOfDeathTimer -= diff;*/

            if (RandomYellTimer <= diff)
            {
                Talk(SAY_SPELL);
                RandomYellTimer = urand(50, 101) * 1000;
            } else RandomYellTimer -= diff;

            if (!me->HasAura(SPELL_BERSERK))
            {
                if (EnrageTimer <= diff)
            {
                DoCast(me, SPELL_BERSERK);
                Talk(SAY_ENRAGE);
            } else EnrageTimer -= diff;
            }

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_teron_gorefiend()
{
    new npc_doom_blossom();
    new npc_shadowy_construct();
    new boss_teron_gorefiend();
}
