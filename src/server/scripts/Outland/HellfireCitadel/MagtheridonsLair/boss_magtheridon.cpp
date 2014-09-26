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
SDName: Boss_Magtheridon
SD%Complete: 60
SDComment: In Development
SDCategory: Hellfire Citadel, Magtheridon's lair
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "magtheridons_lair.h"
#include "Player.h"
#include "SpellInfo.h"

enum Yells
{
    SAY_TAUNT                  = 0,
    SAY_FREED                  = 1,
    SAY_AGGRO                  = 2,
    SAY_BANISH                 = 3,
    SAY_CHAMBER_DESTROY        = 4,
    SAY_PLAYER_KILLED          = 5,
    SAY_DEATH                  = 6
};

enum Emotes
{
    EMOTE_BERSERK              = 7,
    EMOTE_BLASTNOVA            = 8,
    EMOTE_BEGIN                = 9
};

enum Creatures
{
    NPC_MAGTHERIDON    = 17257,
    NPC_ROOM           = 17516,
    NPC_CHANNELLER     = 17256,
    NPC_ABYSSAL        = 17454,
};

enum Spells
{
    SPELL_BLASTNOVA            = 30616,
    SPELL_CLEAVE               = 30619,
    SPELL_QUAKE_TRIGGER        = 30657, //must be cast with 30561 as the proc spell
    SPELL_QUAKE_KNOCKBACK      = 30571,
    SPELL_BLAZE_TARGET         = 30541,
    SPELL_BLAZE_TRAP           = 30542,
    SPELL_DEBRIS_KNOCKDOWN     = 36449,
    SPELL_DEBRIS_VISUAL        = 30632,
    SPELL_DEBRIS_DAMAGE        = 30631, //core bug, does not support target 8
    SPELL_CAMERA_SHAKE         = 36455,
    SPELL_BERSERK              = 27680,
    SPELL_SHADOW_CAGE          = 30168,
    SPELL_SHADOW_GRASP         = 30410,
    SPELL_SHADOW_GRASP_VISUAL  = 30166,
    SPELL_MIND_EXHAUSTION      = 44032, //Cast by the cubes when channeling ends
    SPELL_SHADOW_CAGE_C        = 30205,
    SPELL_SHADOW_GRASP_C       = 30207,
    SPELL_SHADOW_BOLT_VOLLEY   = 30510,
    SPELL_DARK_MENDING         = 30528,
    SPELL_FEAR                 = 30530, //39176
    SPELL_BURNING_ABYSSAL      = 30511,
    SPELL_SOUL_TRANSFER        = 30531, //core bug, does not support target 7
    SPELL_FIRE_BLAST           = 37110,
};

//count of clickers needed to interrupt blast nova
#define CLICKERS_COUNT              5

typedef std::map<ObjectGuid, ObjectGuid> CubeMap;

class npc_abyssal : public CreatureScript
{
    public:

        npc_abyssal()
            : CreatureScript("npc_abyssal")
        {
        }

        struct npc_abyssalAI : public ScriptedAI
        {
            npc_abyssalAI(Creature* creature) : ScriptedAI(creature)
            {
                Initialize();
                trigger = 0;
                Despawn_Timer = 60000;
            }

            void Initialize()
            {
                FireBlast_Timer = 6000;
            }

            uint32 FireBlast_Timer;
            uint32 Despawn_Timer;
            uint32 trigger;

            void Reset() override
            {
                Initialize();
            }

            void SpellHit(Unit*, const SpellInfo* spell) override
            {
                if (trigger == 2 && spell->Id == SPELL_BLAZE_TARGET)
                {
                    DoCast(me, SPELL_BLAZE_TRAP, true);
                    me->SetVisible(false);
                    Despawn_Timer = 130000;
                }
            }

            void SetTrigger(uint32 _trigger)
            {
                trigger = _trigger;
                me->SetDisplayId(11686);
                if (trigger == 1) //debris
                {
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    DoCast(me, SPELL_DEBRIS_VISUAL, true);
                    FireBlast_Timer = 5000;
                    Despawn_Timer = 10000;
                }
            }

            void EnterCombat(Unit* /*who*/) override
            {
                DoZoneInCombat();
            }
            void AttackStart(Unit* who) override
            {
                if (!trigger)
                    ScriptedAI::AttackStart(who);
            }
            void MoveInLineOfSight(Unit* who) override

            {
                if (!trigger)
                    ScriptedAI::MoveInLineOfSight(who);
            }

            void UpdateAI(uint32 diff) override
            {
                if (trigger)
                {
                    if (trigger == 1)
                    {
                        if (FireBlast_Timer <= diff)
                        {
                            DoCast(me, SPELL_DEBRIS_DAMAGE, true);
                            trigger = 3;
                        }
                        else FireBlast_Timer -= diff;
                    }
                    return;
                }

                if (Despawn_Timer <= diff)
                {
                    me->DespawnOrUnsummon();
                }
                else Despawn_Timer -= diff;

                if (!UpdateVictim())
                    return;

                if (FireBlast_Timer <= diff)
                {
                    DoCastVictim(SPELL_FIRE_BLAST);
                    FireBlast_Timer = 5000 + rand32() % 10000;
                }
                else FireBlast_Timer -= diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_abyssalAI(creature);
        }
};

class boss_magtheridon : public CreatureScript
{
    public:

        boss_magtheridon()
            : CreatureScript("boss_magtheridon")
        {
        }

        struct boss_magtheridonAI : public ScriptedAI
        {
            boss_magtheridonAI(Creature* creature) : ScriptedAI(creature)
            {
                Initialize();
                instance = creature->GetInstanceScript();
                me->SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS, 10);
                me->SetFloatValue(UNIT_FIELD_COMBATREACH, 10);
            }

            void Initialize()
            {
                Berserk_Timer = 1320000;
                Quake_Timer = 40000;
                Debris_Timer = 10000;
                Blaze_Timer = 10000 + rand32() % 20000;
                BlastNova_Timer = 60000;
                Cleave_Timer = 15000;
                RandChat_Timer = 90000;

                Phase3 = false;
                NeedCheckCube = false;
            }

            CubeMap Cube;

            InstanceScript* instance;

            uint32 Berserk_Timer;
            uint32 Quake_Timer;
            uint32 Cleave_Timer;
            uint32 BlastNova_Timer;
            uint32 Blaze_Timer;
            uint32 Debris_Timer;
            uint32 RandChat_Timer;

            bool Phase3;
            bool NeedCheckCube;

            void Reset() override
            {
                Initialize();

                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                me->AddUnitState(UNIT_STATE_STUNNED);
                DoCast(me, SPELL_SHADOW_CAGE_C, true);
            }

            void JustReachedHome() override
            {
                instance->SetData(DATA_MAGTHERIDON_EVENT, NOT_STARTED);
                instance->SetData(DATA_COLLAPSE, false);
            }

            void SetClicker(ObjectGuid cubeGUID, ObjectGuid clickerGUID)
            {
                // to avoid multiclicks from 1 cube
                if (ObjectGuid guid = Cube[cubeGUID])
                    DebuffClicker(ObjectAccessor::GetUnit(*me, guid));
                Cube[cubeGUID] = clickerGUID;
                NeedCheckCube = true;
            }

            //function to interrupt channeling and debuff clicker with mind exh(used if second person clicks with same cube or after dispeling/ending shadow grasp DoT)
            void DebuffClicker(Unit* clicker)
            {
                if (!clicker || !clicker->IsAlive())
                    return;

                clicker->RemoveAurasDueToSpell(SPELL_SHADOW_GRASP); // cannot interrupt triggered spells
                clicker->InterruptNonMeleeSpells(false);
                clicker->CastSpell(clicker, SPELL_MIND_EXHAUSTION, true);
            }

            void NeedCheckCubeStatus()
            {
                uint32 ClickerNum = 0;
                // now checking if every clicker has debuff from manticron(it is dispelable atm rev 6110 : S)
                // if not - apply mind exhaustion and delete from clicker's list
                for (CubeMap::iterator i = Cube.begin(); i != Cube.end(); ++i)
                {
                    Unit* clicker = ObjectAccessor::GetUnit(*me, (*i).second);
                    if (!clicker || !clicker->HasAura(SPELL_SHADOW_GRASP))
                    {
                        DebuffClicker(clicker);
                        (*i).second.Clear();
                    }
                    else
                        ++ClickerNum;
                }

                // if 5 clickers from other cubes apply shadow cage
                if (ClickerNum >= CLICKERS_COUNT && !me->HasAura(SPELL_SHADOW_CAGE))
                {
                    Talk(SAY_BANISH);
                    DoCast(me, SPELL_SHADOW_CAGE, true);
                }
                else
                    if (ClickerNum < CLICKERS_COUNT && me->HasAura(SPELL_SHADOW_CAGE))
                        me->RemoveAurasDueToSpell(SPELL_SHADOW_CAGE);

                if (!ClickerNum)
                    NeedCheckCube = false;
            }

            void KilledUnit(Unit* /*victim*/) override
            {
                Talk(SAY_PLAYER_KILLED);
            }

            void JustDied(Unit* /*killer*/) override
            {
                instance->SetData(DATA_MAGTHERIDON_EVENT, DONE);

                Talk(SAY_DEATH);
            }

            void MoveInLineOfSight(Unit* /*who*/) override { }


            void AttackStart(Unit* who) override
            {
                if (!me->HasUnitState(UNIT_STATE_STUNNED))
                    ScriptedAI::AttackStart(who);
            }

            void EnterCombat(Unit* /*who*/) override
            {
                instance->SetData(DATA_MAGTHERIDON_EVENT, IN_PROGRESS);
                DoZoneInCombat();

                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->RemoveAurasDueToSpell(SPELL_SHADOW_CAGE_C);

                Talk(SAY_FREED);
           }

            void UpdateAI(uint32 diff) override
            {
                if (!me->IsInCombat())
                {
                    if (RandChat_Timer <= diff)
                    {
                        Talk(SAY_TAUNT);
                        RandChat_Timer = 90000;
                    }
                    else
                        RandChat_Timer -= diff;
                }

                if (!UpdateVictim())
                    return;

                if (NeedCheckCube) NeedCheckCubeStatus();

                if (Berserk_Timer <= diff)
                {
                    DoCast(me, SPELL_BERSERK, true);
                    Talk(EMOTE_BERSERK);
                    Berserk_Timer = 60000;
                }
                else
                    Berserk_Timer -= diff;

                if (Cleave_Timer <= diff)
                {
                    DoCastVictim(SPELL_CLEAVE);
                    Cleave_Timer = 10000;
                }
                else
                    Cleave_Timer -= diff;

                if (BlastNova_Timer <= diff)
                {
                    // to avoid earthquake interruption
                    if (!me->HasUnitState(UNIT_STATE_STUNNED))
                    {
                        Talk(EMOTE_BLASTNOVA);
                        DoCast(me, SPELL_BLASTNOVA);
                        BlastNova_Timer = 60000;
                    }
                }
                else
                    BlastNova_Timer -= diff;

                if (Quake_Timer <= diff)
                {
                    // to avoid blastnova interruption
                    if (!me->IsNonMeleeSpellCast(false))
                    {
                        DoCast(me, SPELL_QUAKE_TRIGGER, true);
                        Quake_Timer = 50000;
                    }
                }
                else
                    Quake_Timer -= diff;

                if (Blaze_Timer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    {
                        float x, y, z;
                        target->GetPosition(x, y, z);
                        Creature* summon = me->SummonCreature(NPC_ABYSSAL, x, y, z, 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
                        if (summon)
                        {
                            ENSURE_AI(npc_abyssal::npc_abyssalAI, summon->AI())->SetTrigger(2);
                            DoCast(summon, SPELL_BLAZE_TARGET, true);
                            summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        }
                    }
                    Blaze_Timer = urand(20000, 40000);
                }
                else
                    Blaze_Timer -= diff;

                if (!Phase3 && HealthBelowPct(30)
                    && !me->IsNonMeleeSpellCast(false) // blast nova
                    && !me->HasUnitState(UNIT_STATE_STUNNED)) // shadow cage and earthquake
                {
                    Phase3 = true;
                    Talk(SAY_CHAMBER_DESTROY);
                    DoCast(me, SPELL_CAMERA_SHAKE, true);
                    DoCast(me, SPELL_DEBRIS_KNOCKDOWN, true);

                    instance->SetData(DATA_COLLAPSE, true);
                }

                if (Phase3)
                {
                    if (Debris_Timer <= diff)
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        {
                            float x, y, z;
                            target->GetPosition(x, y, z);
                            Creature* summon = me->SummonCreature(NPC_ABYSSAL, x, y, z, 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
                            if (summon)
                                ENSURE_AI(npc_abyssal::npc_abyssalAI, summon->AI())->SetTrigger(1);
                        }
                        Debris_Timer = 10000;
                    }
                    else
                        Debris_Timer -= diff;
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetInstanceAI<boss_magtheridonAI>(creature);
        }
};

class npc_hellfire_channeler : public CreatureScript
{
    public:

        npc_hellfire_channeler()
            : CreatureScript("npc_hellfire_channeler")
        {
        }

        struct npc_hellfire_channelerAI : public ScriptedAI
        {
            npc_hellfire_channelerAI(Creature* creature) : ScriptedAI(creature)
            {
                Initialize();
                instance = creature->GetInstanceScript();
            }

            void Initialize()
            {
                ShadowBoltVolley_Timer = urand(8000, 10000);
                DarkMending_Timer = 10000;
                Fear_Timer = urand(15000, 20000);
                Infernal_Timer = urand(10000, 50000);

                Check_Timer = 5000;
            }

            InstanceScript* instance;

            uint32 ShadowBoltVolley_Timer;
            uint32 DarkMending_Timer;
            uint32 Fear_Timer;
            uint32 Infernal_Timer;

            uint32 Check_Timer;

            void Reset() override
            {
                Initialize();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                instance->SetData(DATA_CHANNELER_EVENT, IN_PROGRESS);

                me->InterruptNonMeleeSpells(false);
                DoZoneInCombat();
            }

            void JustReachedHome() override
            {
                instance->SetData(DATA_CHANNELER_EVENT, NOT_STARTED);

                DoCast(me, SPELL_SHADOW_GRASP_C, false);
            }

            void JustSummoned(Creature* summon) override
            {
                summon->AI()->AttackStart(me->GetVictim());
            }

            void DamageTaken(Unit*, uint32 &damage) override
            {
                if (damage >= me->GetHealth())
                    DoCast(me, SPELL_SOUL_TRANSFER, true);
            }

            void JustDied(Unit* /*killer*/) override
            {
                instance->SetData(DATA_CHANNELER_EVENT, DONE);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (ShadowBoltVolley_Timer <= diff)
                {
                    DoCast(me, SPELL_SHADOW_BOLT_VOLLEY);
                    ShadowBoltVolley_Timer = urand(10000, 20000);
                }
                else
                    ShadowBoltVolley_Timer -= diff;

                if (DarkMending_Timer <= diff)
                {
                    if (HealthBelowPct(50))
                        DoCast(me, SPELL_DARK_MENDING);
                    DarkMending_Timer = 10000 + (rand32() % 10000);
                }
                else
                    DarkMending_Timer -= diff;

                if (Fear_Timer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1))
                        DoCast(target, SPELL_FEAR);
                    Fear_Timer = urand(25000, 40000);
                }
                else
                    Fear_Timer -= diff;

                if (Infernal_Timer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_BURNING_ABYSSAL, true);
                    Infernal_Timer = urand(30000, 40000);
                }
                else
                    Infernal_Timer -= diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetInstanceAI<npc_hellfire_channelerAI>(creature);
        }
};

//Manticron Cube
class go_manticron_cube : public GameObjectScript
{
public:
    go_manticron_cube() : GameObjectScript("go_manticron_cube")
    {
    }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        InstanceScript* instance = go->GetInstanceScript();

        if (!instance)
            return true;

        if (instance->GetData(DATA_MAGTHERIDON_EVENT) != IN_PROGRESS)
            return true;
        Creature* Magtheridon =ObjectAccessor::GetCreature(*go, instance->GetGuidData(DATA_MAGTHERIDON));
        if (!Magtheridon || !Magtheridon->IsAlive())
            return true;

        // if exhausted or already channeling return
        if (player->HasAura(SPELL_MIND_EXHAUSTION) || player->HasAura(SPELL_SHADOW_GRASP))
            return true;

        player->InterruptNonMeleeSpells(false);
        player->CastSpell(player, SPELL_SHADOW_GRASP, true);
        player->CastSpell(player, SPELL_SHADOW_GRASP_VISUAL, false);
        ENSURE_AI(boss_magtheridon::boss_magtheridonAI, Magtheridon->AI())->SetClicker(go->GetGUID(), player->GetGUID());
        return true;
    }
};

void AddSC_boss_magtheridon()
{
    new boss_magtheridon();
    new npc_hellfire_channeler();
    new npc_abyssal();
    new go_manticron_cube();
}

