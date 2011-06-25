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
SDName: Boss_Eredar_Twins
SD%Complete: 100
SDComment:
EndScriptData */

#include "ScriptPCH.h"
#include "sunwell_plateau.h"

enum Quotes
{
    //Alytesh
    YELL_CANFLAGRATION          =   -1580044,
    YELL_SISTER_SACROLASH_DEAD  =   -1580045,
    YELL_ALY_KILL_1             =   -1580046,
    YELL_ALY_KILL_2             =   -1580047,
    YELL_ALY_DEAD               =   -1580048,
    YELL_BERSERK                =   -1580049,

    //Sacrolash
    YELL_SHADOW_NOVA            =   -1580050,
    YELL_SISTER_ALYTHESS_DEAD   =   -1580051,
    YELL_SAC_KILL_1             =   -1580052,
    YELL_SAC_KILL_2             =   -1580053,
    SAY_SAC_DEAD                =   -1580054,
    YELL_ENRAGE                 =   -1580055,

    //Intro
    YELL_INTRO_SAC_1            =   -1580056,
    YELL_INTRO_ALY_2            =   -1580057,
    YELL_INTRO_SAC_3            =   -1580058,
    YELL_INTRO_ALY_4            =   -1580059,
    YELL_INTRO_SAC_5            =   -1580060,
    YELL_INTRO_ALY_6            =   -1580061,
    YELL_INTRO_SAC_7            =   -1580062,
    YELL_INTRO_ALY_8            =   -1580063,

    //Emote
    EMOTE_SHADOW_NOVA           =   -1580064,
    EMOTE_CONFLAGRATION         =   -1580065
};

enum Spells
{
    SPELL_SUNWELL_RADIANCE  =   45769,
    //Lady Sacrolash spells
    SPELL_DARK_TOUCHED      =   45347,
    SPELL_SHADOW_BLADES     =   45248, //10 secs
    SPELL_DARK_STRIKE       =   45271,
    SPELL_SHADOW_NOVA       =   45329, //30-35 secs
    SPELL_CONFOUNDING_BLOW  =   45256, //25 secs

    //Shadow Image spells
    SPELL_SHADOW_FURY       =   45270,
    SPELL_IMAGE_VISUAL      =   45263,

    //Misc spells
    SPELL_ENRAGE            =   46587,
    SPELL_EMPOWER           =   45366,
    SPELL_DARK_FLAME        =   45345,

    //Grand Warlock Alythess spells
    SPELL_PYROGENICS        =   45230, //15secs
    SPELL_FLAME_TOUCHED     =   45348,
    SPELL_CONFLAGRATION     =   45342, //30-35 secs
    SPELL_BLAZE             =   45235, //on main target every 3 secs
    SPELL_FLAME_SEAR        =   46771,
    SPELL_BLAZE_SUMMON      =   45236, //187366 GO
    SPELL_BLAZE_BURN        =   45246
};

enum Twins_Creatures
{
    GRAND_WARLOCK_ALYTHESS  =   25166,
    //MOB_SHADOW_IMAGE        =   25214,
    LADY_SACROLASH          =   25165
};

struct boss_eredar_twinAI : public ScriptedAI
{
    boss_eredar_twinAI(Creature *c) : ScriptedAI(c){}

    uint32 AreaInCombat_Timer;

    void Reset()
    {
        AreaInCombat_Timer = 5000;
    }

    void SendAttacker(Unit* target) // Exploit Fix
    {
        std::list<Creature*> templist;
        float x, y, z;
        me->GetPosition(x, y, z);

        {
            CellPair pair(Trinity::ComputeCellPair(x, y));
            Cell cell(pair);
            cell.data.Part.reserved = ALL_DISTRICT;
            cell.SetNoCreate();

            Trinity::AllFriendlyCreaturesInGrid check(me);
            Trinity::CreatureListSearcher<Trinity::AllFriendlyCreaturesInGrid> searcher(me, templist, check);

            TypeContainerVisitor<Trinity::CreatureListSearcher<Trinity::AllFriendlyCreaturesInGrid>, GridTypeMapContainer> cSearcher(searcher);

            cell.Visit(pair, cSearcher, *(me->GetMap()));
        }

        if(!templist.size())
            return;

        for(std::list<Creature*>::iterator i = templist.begin(); i != templist.end(); ++i)
        {
            if((*i) && me->IsWithinDistInMap((*i),10))
            {
                if(!(*i)->isInCombat() && !me->getVictim())
                    (*i)->AI()->AttackStart(target);
            }
        }
    }

    //void DoAttackerAreaInCombat(Unit* attacker, float range, Unit* pUnit = NULL)
    //{
    //    if(!attacker)
    //        attacker = me;

    //    if (!pUnit)
    //        pUnit = me;

    //    Map *map = pUnit->GetMap();

    //    if (!map->IsDungeon())
    //        return;

    //    if (!pUnit->CanHaveThreatList() || pUnit->getThreatManager().isThreatListEmpty())
    //        return;

    //    Map::PlayerList const &PlayerList = map->GetPlayers();
    //    for(Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
    //    {
    //        if (Player* i_pl = i->getSource())
    //            if (i_pl->isAlive() && attacker && attacker->GetDistance(i_pl) <= range )
    //            {
    //                pUnit->SetInCombatWith(i_pl);
    //                i_pl->SetInCombatWith(pUnit);
    //                pUnit->AddThreat(i_pl, 0.0f);
    //            }
    //    }
    //}

    void EnterCombat(Unit *who)
    {
        DoAttackerAreaInCombat(who, 100);
        Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0);
        if(target)
            SendAttacker(target);
    }

    void KilledUnit(Unit *victim){}
    void JustDied(Unit *victim){}
    void CheckRadianceAura()
    {
        if(!me->HasAura(SPELL_SUNWELL_RADIANCE,0))
            DoCast(me,SPELL_SUNWELL_RADIANCE,true);
    }

    void DoAggroPuls(const uint32 diff)
    {
        if(AreaInCombat_Timer <= diff)
        {
            DoAttackerAreaInCombat(me->getVictim(), 100);
            AreaInCombat_Timer = 5000;
        }else AreaInCombat_Timer -= diff;
    }

    bool TryDoCast(Unit *victim, uint32 spellId, bool triggered = false)
    {
        if(me->IsNonMeleeSpellCasted(false)) return false;

        DoCast(victim,spellId,triggered);
        return true;
    }

    bool TryDoCastAOE(uint32 spellId, bool triggered = false)
    {
        if(me->IsNonMeleeSpellCasted(false)) return false;

        DoCastAOE(spellId,triggered);
        return true;
    }

    void HandleTouchedSpells(Unit* target, uint32 TouchedType)
    {
        switch(TouchedType)
        {
        case SPELL_FLAME_TOUCHED:
            if(!target->HasAura(SPELL_DARK_FLAME, 0))
            {
                if(target->HasAura(SPELL_DARK_TOUCHED, 0))
                {
                    target->RemoveAurasDueToSpell(SPELL_DARK_TOUCHED);
                    target->CastSpell(target, SPELL_DARK_FLAME, true, 0, 0, me->GetGUID());
                }else
                {
                    target->CastSpell(target, SPELL_FLAME_TOUCHED, true, 0, 0, me->GetGUID());
                }
            }
            break;
        case SPELL_DARK_TOUCHED:
            if(!target->HasAura(SPELL_DARK_FLAME, 0))
            {
                if(target->HasAura(SPELL_FLAME_TOUCHED, 0))
                {
                    target->RemoveAurasDueToSpell(SPELL_FLAME_TOUCHED);
                    target->CastSpell(target, SPELL_DARK_FLAME, true, 0, 0, me->GetGUID());
                }else target->CastSpell(target, SPELL_DARK_TOUCHED, true, 0, 0, me->GetGUID());
            }
            break;
        }
    }

    void UpdateAI(const uint32 diff){}
};

class boss_sacrolash : public CreatureScript
{
public:
    boss_sacrolash() : CreatureScript("boss_sacrolash") {}

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_sacrolashAI (pCreature);
    }

    struct boss_sacrolashAI : public boss_eredar_twinAI
    {
        boss_sacrolashAI(Creature *c) : boss_eredar_twinAI(c){
            pInstance = c->GetInstanceScript();
        }

        InstanceScript *pInstance;

        bool InCombat;
        bool SisterDeath;
        bool Enraged;

        uint32 ShadowbladesTimer;
        uint32 ShadownovaTimer;
        uint32 ConfoundingblowTimer;
        uint32 ShadowimageTimer;
        uint32 ConflagrationTimer;
        uint32 EnrageTimer;

        void Reset()
        {
            InCombat = false;
            Enraged = false;

            if(pInstance)
            {
                Unit* Temp =  Unit::GetUnit((*me),pInstance->GetData64(DATA_ALYTHESS));
                if (Temp)
                    if (Temp->isDead())
                    {
                        CAST_CRE(Temp)->Respawn();
                    }else
                    {
                        if(Temp->getVictim())
                        {
                            me->getThreatManager().addThreat(Temp->getVictim(),0.0f);
                            InCombat = true;
                        }
                    }
            }

            if(!InCombat)
            {
                ShadowbladesTimer = 10000;
                ShadownovaTimer = 30000;
                ConfoundingblowTimer = 25000;
                ShadowimageTimer = 20000;
                ConflagrationTimer = 30000;
                EnrageTimer = 360000;

                SisterDeath = false;
            }

            if(pInstance)
                pInstance->SetData(DATA_EREDAR_TWINS_EVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* who)
        {
            boss_eredar_twinAI::EnterCombat(who);

            if(pInstance)
            {
                Unit* Temp =  Unit::GetUnit((*me),pInstance->GetData64(DATA_ALYTHESS));
                if (Temp && Temp->isAlive() && !(Temp->getVictim()))
                    ((Creature*)Temp)->AI()->AttackStart(who);
            }

            if(pInstance)
                pInstance->SetData(DATA_EREDAR_TWINS_EVENT, IN_PROGRESS);
        }

        void KilledUnit(Unit* /*victim*/)
        {
            if(rand()%4 == 0)
            {
                switch (rand()%2)
                {
                case 0: DoScriptText(YELL_SAC_KILL_1, me); break;
                case 1: DoScriptText(YELL_SAC_KILL_2, me); break;
                }
            }
        }

        void JustDied(Unit* /*Killer*/)
        {
            // only if ALY death
            if (SisterDeath)
            {
                DoScriptText(SAY_SAC_DEAD, me);

                if(pInstance)
                    pInstance->SetData(DATA_EREDAR_TWINS_EVENT, DONE);
            }
            else
                me->RemoveFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
        }

        void SpellHitTarget(Unit* target,const SpellEntry* spell)
        {
            switch(spell->Id)
            {
            case SPELL_SHADOW_BLADES:
            case SPELL_SHADOW_NOVA:
            case SPELL_CONFOUNDING_BLOW:
            case SPELL_SHADOW_FURY:
                HandleTouchedSpells(target, SPELL_DARK_TOUCHED);
                break;
            case SPELL_CONFLAGRATION:
                HandleTouchedSpells(target, SPELL_FLAME_TOUCHED);
                break;
            }
        }

        void UpdateAI(const uint32 diff)
        {
            CheckRadianceAura();

            if(!SisterDeath)
            {
                if (pInstance)
                {
                    Creature* Temp = Creature::GetCreature((*me),pInstance->GetData64(DATA_ALYTHESS));
                    if (Temp && Temp->isDead())
                    {
                        DoScriptText(YELL_SISTER_ALYTHESS_DEAD, me);
                        me->InterruptSpell(CURRENT_GENERIC_SPELL);
                        if(TryDoCast(me,SPELL_EMPOWER))
                            SisterDeath = true;
                    }
                }
            }

            if (!UpdateVictim())
                return;

            DoAggroPuls(diff);

            if(SisterDeath)
            {
                if (ConflagrationTimer <= diff)
                {
                    me->InterruptSpell(CURRENT_GENERIC_SPELL);
                    Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 300, true);
                    if(TryDoCast(target, SPELL_CONFLAGRATION))
                        ConflagrationTimer = 30000+(rand()%5000);
                }else ConflagrationTimer -= diff;
            }
            else
            {
                if(ShadownovaTimer <= diff)
                {
                    me->InterruptSpell(CURRENT_GENERIC_SPELL);
                    Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 300, true);
                    if(TryDoCast(target, SPELL_SHADOW_NOVA))
                    {
                        if(!SisterDeath)
                        {
                            DoScriptText(EMOTE_SHADOW_NOVA, me, target);
                            DoScriptText(YELL_SHADOW_NOVA, me);
                        }
                        ShadownovaTimer = 30000+(rand()%5000);
                    }
                }else ShadownovaTimer -=diff;
            }

            if(ConfoundingblowTimer <= diff)
            {
                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 10, true);
                if(TryDoCast(target, SPELL_CONFOUNDING_BLOW))
                    ConfoundingblowTimer = 20000 + (rand()%5000);
            }else ConfoundingblowTimer -=diff;

            if(ShadowimageTimer <= diff)
            {
                Unit* ptarget = NULL;
                Creature* temp = NULL;
                for(int i = 0;i<3;i++)
                {
                    ptarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                    temp = DoSpawnCreature(MOB_SHADOW_IMAGE,0,0,0,0,TEMPSUMMON_CORPSE_DESPAWN,10000);
                    if(temp && ptarget)
                    {
                        temp->AI()->AttackStart(ptarget);
                        temp->getThreatManager().addThreat(ptarget,500000.0f);
                    }
                }
                ShadowimageTimer = 20000;
            }else ShadowimageTimer -=diff;

            if(ShadowbladesTimer <= diff)
            {
                if(TryDoCast(me, SPELL_SHADOW_BLADES))
                    ShadowbladesTimer = 10000;
            }else ShadowbladesTimer -=diff;

            if (EnrageTimer <= diff && !Enraged)
            {
                me->InterruptSpell(CURRENT_GENERIC_SPELL);
                DoScriptText(YELL_ENRAGE, me);
                DoCast(me,SPELL_ENRAGE);
                if(me->HasAura(SPELL_ENRAGE,0))
                    Enraged = true;
            }else EnrageTimer -= diff;

            if( me->isAttackReady() && !me->IsNonMeleeSpellCasted(false))
            {
                //If we are within range melee the target
                if( me->IsWithinMeleeRange(me->getVictim()))
                {
                    HandleTouchedSpells(me->getVictim(), SPELL_DARK_TOUCHED);
                    me->AttackerStateUpdate(me->getVictim());
                    me->resetAttackTimer();
                }
            }
        }
    };
};

class boss_alythess : public CreatureScript
{
public:
    boss_alythess() : CreatureScript("boss_alythess") {}

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_alythessAI (pCreature);
    }

    struct boss_alythessAI : public boss_eredar_twinAI
    {
        boss_alythessAI(Creature *c) : boss_eredar_twinAI(c){
            pInstance = c->GetInstanceScript();
            IntroStepCounter = 10;
        }

        InstanceScript *pInstance;

        bool InCombat;
        bool SisterDeath;
        bool Enraged;

        uint32 IntroStepCounter;
        uint32 IntroYellTimer;

        uint32 ConflagrationTimer;
        uint32 BlazeTimer;
        uint32 PyrogenicsTimer;
        uint32 ShadownovaTimer;
        uint32 FlamesearTimer;
        uint32 EnrageTimer;

        void Reset()
        {
            InCombat = false;
            Enraged = false;

            if(pInstance)
            {
                Unit* Temp =  Unit::GetUnit((*me),pInstance->GetData64(DATA_SACROLASH));
                if (Temp)
                    if (Temp->isDead())
                    {
                        ((Creature*)Temp)->Respawn();
                    }else
                    {
                        if(Temp->getVictim())
                        {
                            me->getThreatManager().addThreat(Temp->getVictim(),0.0f);
                            InCombat = true;
                        }
                    }
            }

            if(!InCombat)
            {
                ConflagrationTimer = 45000;
                BlazeTimer = 100;
                PyrogenicsTimer = 15000;
                ShadownovaTimer = 40000;
                EnrageTimer = 360000;
                FlamesearTimer = 15000;
                IntroYellTimer = 10000;

                SisterDeath = false;
            }

            if(pInstance)
                pInstance->SetData(DATA_EREDAR_TWINS_EVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* who)
        {
            boss_eredar_twinAI::EnterCombat(who);

            if(pInstance)
            {
                Unit* Temp =  Unit::GetUnit((*me),pInstance->GetData64(DATA_SACROLASH));
                if (Temp && Temp->isAlive() && !(Temp->getVictim()))
                    ((Creature*)Temp)->AI()->AttackStart(who);
            }

            if(pInstance)
                pInstance->SetData(DATA_EREDAR_TWINS_EVENT, IN_PROGRESS);
        }

        void AttackStart(Unit *who)
        {
            ScriptedAI::AttackStartNoMove(who);
        }

        void MoveInLineOfSight(Unit *who)
        {
            if (!who || me->getVictim())
                return;

            if (who->isTargetableForAttack() && who->isInAccessiblePlaceFor(me) && me->IsHostileTo(who))
            {

                float attackRadius = me->GetAttackDistance(who);
                if (me->IsWithinDistInMap(who, attackRadius) && me->GetDistanceZ(who) <= CREATURE_Z_ATTACK_RANGE && me->IsWithinLOSInMap(who))
                {
                    if (!InCombat)
                    {
                        DoStartNoMovement(who);
                        EnterCombat(who);
                        InCombat = true;
                    }
                }
            }
            else if (IntroStepCounter == 10 && me->IsWithinLOSInMap(who)&& me->IsWithinDistInMap(who, 25) )
            {
                IntroStepCounter = 0;
            }
        }

        void KilledUnit(Unit* /*victim*/)
        {
            if(rand()%4 == 0)
            {
                switch (rand()%2)
                {
                case 0: DoScriptText(YELL_ALY_KILL_1, me); break;
                case 1: DoScriptText(YELL_ALY_KILL_2, me); break;
                }
            }
        }

        void JustDied(Unit* /*Killer*/)
        {
            if (SisterDeath)
            {
                DoScriptText(YELL_ALY_DEAD, me);

                if(pInstance)
                    pInstance->SetData(DATA_EREDAR_TWINS_EVENT, DONE);
            }
            else
                me->RemoveFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
        }

        void SpellHitTarget(Unit* target,const SpellEntry* spell)
        {
            switch(spell->Id)
            {

            case SPELL_BLAZE:
                target->CastSpell(target, SPELL_BLAZE_SUMMON, true, 0, 0, me->GetGUID());
            case SPELL_CONFLAGRATION:
            case SPELL_FLAME_SEAR:
            case SPELL_BLAZE_BURN:
                HandleTouchedSpells(target, SPELL_FLAME_TOUCHED);
                break;
            case SPELL_SHADOW_NOVA:
                HandleTouchedSpells(target, SPELL_DARK_TOUCHED);
                break;
            }
        }

        uint32 IntroStep(uint32 step)
        {
            Creature* Sacrolash = (Creature*)Unit::GetUnit((*me),pInstance->GetData64(DATA_SACROLASH));
            switch (step)
            {
            case 0: return 0;
            case 1:
                if(Sacrolash)
                    DoScriptText(YELL_INTRO_SAC_1, Sacrolash);
                return 1000;
            case 2: DoScriptText(YELL_INTRO_ALY_2, me); return 1000;
            case 3:
                if(Sacrolash)
                    DoScriptText(YELL_INTRO_SAC_3, Sacrolash);
                return 2000;
            case 4: DoScriptText(YELL_INTRO_ALY_4, me); return 1000;
            case 5:
                if(Sacrolash)
                    DoScriptText(YELL_INTRO_SAC_5, Sacrolash);
                return 2000;
            case 6: DoScriptText(YELL_INTRO_ALY_6, me); return 1000;
            case 7:
                if(Sacrolash)
                    DoScriptText(YELL_INTRO_SAC_7, Sacrolash);
                return 3000;
            case 8: DoScriptText(YELL_INTRO_ALY_8, me); return 900000;
            }
            return 10000;
        }

        void UpdateAI(const uint32 diff)
        {
            if(IntroStepCounter < 9)
            {
                if(IntroYellTimer <= diff)
                {
                    IntroYellTimer = IntroStep(++IntroStepCounter);
                }else IntroYellTimer -= diff;
            }

            CheckRadianceAura();

            if(!SisterDeath)
            {
                if (pInstance)
                {
                    Creature* Temp = Creature::GetCreature((*me),pInstance->GetData64(DATA_SACROLASH));
                    if (Temp && Temp->isDead())
                    {
                        DoScriptText(YELL_SISTER_SACROLASH_DEAD, me);
                        me->InterruptSpell(CURRENT_GENERIC_SPELL);
                        if(TryDoCast(me, SPELL_EMPOWER))
                            SisterDeath = true;
                    }
                }
            }

            if (!UpdateVictim())
                return;

            DoAggroPuls(diff);

            if(SisterDeath)
            {
                if(ShadownovaTimer <= diff)
                {
                    me->InterruptSpell(CURRENT_GENERIC_SPELL);
                    Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 300, true);
                    if(TryDoCast(target, SPELL_SHADOW_NOVA))
                        ShadownovaTimer= 30000+(rand()%5000);

                }else ShadownovaTimer -=diff;
            }
            else
            {
                if(ConflagrationTimer <= diff)
                {
                        me->InterruptSpell(CURRENT_GENERIC_SPELL);
                        Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 300, true);
                        if(TryDoCast(target, SPELL_CONFLAGRATION))
                        {
                            ConflagrationTimer = 30000+(rand()%5000);

                            if(!SisterDeath)
                            {
                                DoScriptText(EMOTE_CONFLAGRATION, me, target);
                                DoScriptText(YELL_CANFLAGRATION, me);
                            }

                            BlazeTimer = 4000;
                        }
                }else ConflagrationTimer -= diff;
            }

            if(FlamesearTimer <= diff)
            {
                 if(TryDoCast(me, SPELL_FLAME_SEAR))
                    FlamesearTimer = 15000;
            }else FlamesearTimer -=diff;

            if (PyrogenicsTimer <= diff)
            {
                if(TryDoCast(me, SPELL_PYROGENICS,true))
                    PyrogenicsTimer = 15000;
            }else PyrogenicsTimer -= diff;

            if (BlazeTimer <= diff)
            {
                if(TryDoCast(me->getVictim(), SPELL_BLAZE))
                    BlazeTimer = 3800;
            }else BlazeTimer -= diff;

            if (EnrageTimer <= diff && !Enraged)
            {
                me->InterruptSpell(CURRENT_GENERIC_SPELL);
                DoScriptText(YELL_BERSERK, me);
                if(TryDoCast(me, SPELL_ENRAGE))
                    Enraged = true;
            }else EnrageTimer -= diff;
        }
    };
};

class mob_shadow_image : public CreatureScript
{
public:
    mob_shadow_image() : CreatureScript("mob_shadow_image") {}

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_shadow_imageAI (pCreature);
    }

    struct mob_shadow_imageAI : public ScriptedAI
    {
        mob_shadow_imageAI(Creature *c) : ScriptedAI(c) {}

        uint32 ShadowfuryTimer;
        uint32 KillTimer;
        uint32 DarkstrikeTimer;

        void Reset()
        {
            ShadowfuryTimer = 5000 + (rand()%15000);
            DarkstrikeTimer = 3000;
            KillTimer = 15000;
        }

        void EnterCombat(Unit* /*who*/){}

        void SpellHitTarget(Unit* target,const SpellEntry* spell)
        {
            switch(spell->Id)
            {

            case SPELL_SHADOW_FURY:
            case SPELL_DARK_STRIKE:
                if(!target->HasAura(SPELL_DARK_FLAME, 0))
                {
                    if(target->HasAura(SPELL_FLAME_TOUCHED, 0))
                    {
                        target->RemoveAurasDueToSpell(SPELL_FLAME_TOUCHED);
                        target->CastSpell(target, SPELL_DARK_FLAME, true);
                    }else target->CastSpell(target,SPELL_DARK_TOUCHED,true);
                }
                break;
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if(!me->HasAura(SPELL_IMAGE_VISUAL, 0))
                DoCast(me, SPELL_IMAGE_VISUAL);

            if(KillTimer <= diff)
            {
                me->DealDamage(me, me->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                KillTimer = 9999999;
            }else KillTimer -=diff;

            if (!UpdateVictim())
                return;

            if(ShadowfuryTimer <= diff)
            {
                DoCast(me, SPELL_SHADOW_FURY);
                ShadowfuryTimer = 10000;
            }else ShadowfuryTimer -=diff;

            if(DarkstrikeTimer <= diff)
            {
                if(!me->IsNonMeleeSpellCasted(false))
                {
                    //If we are within range melee the target
                    if( me->IsWithinMeleeRange(me->getVictim()))
                        DoCast(me->getVictim(), SPELL_DARK_STRIKE);
                }
                DarkstrikeTimer = 3000;
            }
            else DarkstrikeTimer -= diff;
        }
    };
};

void AddSC_boss_eredar_twins()
{
    new boss_sacrolash();
    new boss_alythess();
    new mob_shadow_image();
}
