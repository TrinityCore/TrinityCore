/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
SDName: Boss_Exarch_Maladaar
SD%Complete: 95
SDComment: Most of event implemented, some adjustments to timers remain and possibly make some better code for switching his dark side in to better "images" of player.
SDCategory: Auchindoun, Auchenai Crypts
EndScriptData */

/* ContentData
npc_stolen_soul
boss_exarch_maladaar
npc_avatar_of_martyred
EndContentData */

#include "ScriptMgr.h"
#include "auchenai_crypts.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"

enum Spells
{
    SPELL_MOONFIRE              = 37328,
    SPELL_FIREBALL              = 37329,
    SPELL_MIND_FLAY             = 37330,
    SPELL_HEMORRHAGE            = 37331,
    SPELL_FROSTSHOCK            = 37332,
    SPELL_CURSE_OF_AGONY        = 37334,
    SPELL_MORTAL_STRIKE         = 37335,
    SPELL_FREEZING_TRAP         = 37368,
    SPELL_HAMMER_OF_JUSTICE     = 37369,

    // Avatar of Martyred
    SPELL_AV_MORTAL_STRIKE      = 16856,
    SPELL_AV_SUNDER_ARMOR       = 16145
};

class npc_stolen_soul : public CreatureScript
{
public:
    npc_stolen_soul() : CreatureScript("npc_stolen_soul") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetAuchenaiCryptsAI<npc_stolen_soulAI>(creature);
    }

    struct npc_stolen_soulAI : public ScriptedAI
    {
        npc_stolen_soulAI(Creature* creature) : ScriptedAI(creature)
        {
            myClass = CLASS_NONE;
            Class_Timer = 1000;
        }

        uint8 myClass;
        uint32 Class_Timer;

        void Reset() override
        {
            myClass = CLASS_NONE;
            Class_Timer = 1000;
        }

        void JustEngagedWith(Unit* /*who*/) override
        { }

        void SetMyClass(uint8 myclass)
        {
            myClass = myclass;
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (Class_Timer <= diff)
            {
                switch (myClass)
                {
                    case CLASS_WARRIOR:
                        DoCastVictim(SPELL_MORTAL_STRIKE);
                        Class_Timer = 6000;
                        break;
                    case CLASS_PALADIN:
                        DoCastVictim(SPELL_HAMMER_OF_JUSTICE);
                        Class_Timer = 6000;
                        break;
                    case CLASS_HUNTER:
                        DoCastVictim(SPELL_FREEZING_TRAP);
                        Class_Timer = 20000;
                        break;
                    case CLASS_ROGUE:
                        DoCastVictim(SPELL_HEMORRHAGE);
                        Class_Timer = 10000;
                        break;
                    case CLASS_PRIEST:
                        DoCastVictim(SPELL_MIND_FLAY);
                        Class_Timer = 5000;
                        break;
                    case CLASS_SHAMAN:
                        DoCastVictim(SPELL_FROSTSHOCK);
                        Class_Timer = 8000;
                        break;
                    case CLASS_MAGE:
                        DoCastVictim(SPELL_FIREBALL);
                        Class_Timer = 5000;
                        break;
                    case CLASS_WARLOCK:
                        DoCastVictim(SPELL_CURSE_OF_AGONY);
                        Class_Timer = 20000;
                        break;
                    case CLASS_DRUID:
                        DoCastVictim(SPELL_MOONFIRE);
                        Class_Timer = 10000;
                        break;
                }
            } else Class_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

enum ExarchMaladaar
{
    SAY_INTRO                   = 0,
    SAY_SUMMON                  = 1,
    SAY_AGGRO                   = 2,
    SAY_ROAR                    = 3,
    SAY_SLAY                    = 4,
    SAY_DEATH                   = 5,

    SPELL_RIBBON_OF_SOULS       = 32422,
    SPELL_SOUL_SCREAM           = 32421,
    SPELL_STOLEN_SOUL           = 32346,
    SPELL_STOLEN_SOUL_VISUAL    = 32395,
    SPELL_SUMMON_AVATAR         = 32424,

    ENTRY_STOLEN_SOUL           = 18441
};

class boss_exarch_maladaar : public CreatureScript
{
public:
    boss_exarch_maladaar() : CreatureScript("boss_exarch_maladaar") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetAuchenaiCryptsAI<boss_exarch_maladaarAI>(creature);
    }

    struct boss_exarch_maladaarAI : public ScriptedAI
    {
        boss_exarch_maladaarAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            HasTaunted = false;
        }

        void Initialize()
        {
            soulmodel = 0;
            soulholder.Clear();
            soulclass = 0;

            Fear_timer = 15000 + rand32() % 5000;
            Ribbon_of_Souls_timer = 5000;
            StolenSoul_Timer = 25000 + rand32() % 10000;

            Avatar_summoned = false;
        }

        uint32 soulmodel;
        ObjectGuid soulholder;
        uint8 soulclass;

        uint32 Fear_timer;
        uint32 Ribbon_of_Souls_timer;
        uint32 StolenSoul_Timer;

        bool HasTaunted;
        bool Avatar_summoned;

        void Reset() override
        {
            Initialize();
        }

        void MoveInLineOfSight(Unit* who) override

        {
            if (!HasTaunted && me->IsWithinDistInMap(who, 150.0f))
            {
                Talk(SAY_INTRO);
                HasTaunted = true;
            }

            ScriptedAI::MoveInLineOfSight(who);
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);
        }

        void JustSummoned(Creature* summoned) override
        {
            if (summoned->GetEntry() == ENTRY_STOLEN_SOUL)
            {
                //SPELL_STOLEN_SOUL_VISUAL has shapeshift effect, but not implemented feature in Trinity for this spell.
                summoned->CastSpell(summoned, SPELL_STOLEN_SOUL_VISUAL, false);
                summoned->SetDisplayId(soulmodel);
                summoned->SetFaction(me->GetFaction());

                if (Unit* target = ObjectAccessor::GetUnit(*me, soulholder))
                {
                    ENSURE_AI(npc_stolen_soul::npc_stolen_soulAI, summoned->AI())->SetMyClass(soulclass);
                    summoned->AI()->AttackStart(target);
                }
            }
        }

        void KilledUnit(Unit* /*victim*/) override
        {
            if (rand32() % 2)
                return;

            Talk(SAY_SLAY);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);
            //When Exarch Maladar is defeated D'ore appear.
            me->SummonCreature(19412, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 600000);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (!Avatar_summoned && HealthBelowPct(25))
            {
                if (me->IsNonMeleeSpellCast(false))
                    me->InterruptNonMeleeSpells(true);

                Talk(SAY_SUMMON);

                DoCast(me, SPELL_SUMMON_AVATAR);
                Avatar_summoned = true;
                StolenSoul_Timer = 15000 + rand32() % 15000;
            }

            if (StolenSoul_Timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                {
                    if (target->GetTypeId() == TYPEID_PLAYER)
                    {
                        if (me->IsNonMeleeSpellCast(false))
                            me->InterruptNonMeleeSpells(true);

                        Talk(SAY_ROAR);

                        soulmodel = target->GetDisplayId();
                        soulholder = target->GetGUID();
                        soulclass = target->GetClass();

                        DoCast(target, SPELL_STOLEN_SOUL);
                        me->SummonCreature(ENTRY_STOLEN_SOUL, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 10000);

                        StolenSoul_Timer = 20000 + rand32() % 10000;
                    } else StolenSoul_Timer = 1000;
                }
            } else StolenSoul_Timer -= diff;

            if (Ribbon_of_Souls_timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_RIBBON_OF_SOULS);

                Ribbon_of_Souls_timer = 5000 + (rand32() % 20 * 1000);
            } else Ribbon_of_Souls_timer -= diff;

            if (Fear_timer <= diff)
            {
                DoCast(me, SPELL_SOUL_SCREAM);
                Fear_timer = 15000 + rand32() % 15000;
            } else Fear_timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

class npc_avatar_of_martyred : public CreatureScript
{
public:
    npc_avatar_of_martyred() : CreatureScript("npc_avatar_of_martyred") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetAuchenaiCryptsAI<npc_avatar_of_martyredAI>(creature);
    }

    struct npc_avatar_of_martyredAI : public ScriptedAI
    {
        npc_avatar_of_martyredAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            Mortal_Strike_timer = 10000;
        }

        uint32 Mortal_Strike_timer;

        void Reset() override
        {
            Initialize();
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (Mortal_Strike_timer <= diff)
            {
                DoCastVictim(SPELL_AV_MORTAL_STRIKE);
                Mortal_Strike_timer = urand(10, 30) * 1000;
            } else Mortal_Strike_timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_exarch_maladaar()
{
    new boss_exarch_maladaar();
    new npc_avatar_of_martyred();
    new npc_stolen_soul();
}
