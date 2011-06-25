/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "black_temple.h"

 //Speech'n'sound
#define SAY_INTRO                       -1564037
#define SAY_AGGRO                       -1564038
#define SAY_SLAY1                       -1564039
#define SAY_SLAY2                       -1564040
#define SAY_SPELL1                      -1564041
#define SAY_SPELL2                      -1564042
#define SAY_SPECIAL1                    -1564043
#define SAY_SPECIAL2                    -1564044
#define SAY_ENRAGE                      -1564045
#define SAY_DEATH                       -1564046

//Spells
#define SPELL_INCINERATE                40239
#define SPELL_CRUSHING_SHADOWS          40243
#define SPELL_SUMMON_DOOM_BLOSSOM       40188

#define SPELL_SHADOWBOLT                40185
#define SPELL_PASSIVE_SHADOWFORM        40326

#define SPELL_SHADOW_OF_DEATH           40251
#define SPELL_BERSERK                   45078

#define SPELL_ATROPHY                   40327               // Shadowy Constructs use this when they get within melee range of a player

#define CREATURE_DOOM_BLOSSOM       23123
#define CREATURE_SHADOWY_CONSTRUCT  23111
#define CREATURE_GHOST              23109

//Mindcontrol Spells
#define SPELL_SUMMON_SPIRIT         40266
#define SPELL_SPIRIT_VENGEANCE      40268

#define HIGH                        10.0f

class mob_doom_blossom : public CreatureScript
{
public:
    mob_doom_blossom() : CreatureScript("mob_doom_blossom") { }

    CreatureAI* GetAI(Creature *_Creature) const
    {
        return new mob_doom_blossomAI (_Creature);
    }

    struct  mob_doom_blossomAI : public ScriptedAI
    {
        mob_doom_blossomAI(Creature *c) : ScriptedAI(c) 
        {
            pInstance = c->GetInstanceScript();
        }

        InstanceScript *pInstance;

        uint32 CheckTeronTimer;
        uint32 ShadowBoltTimer;
        uint64 TeronGUID;

        void Reset()
        {
            CheckTeronTimer = 10000;
            ShadowBoltTimer = 2000;

            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

            TeronGUID = 0;
            TeronGUID = pInstance->GetData64(DATA_TERONGOREFIEND);
            Creature* c_Teron = NULL;
            if(TeronGUID!= 0)
                c_Teron = Creature::GetCreature((*me),TeronGUID);

            if(c_Teron)
            {
                me->setFaction(c_Teron->getFaction());
                if(c_Teron->getVictim())
                {
                    me->Attack(c_Teron->getVictim(),false);
                    DoZoneInCombat();

                    float x,y,z;
                    me->GetPosition(x,y,z);
                    me->GetMotionMaster()->MovePoint(0,x,y,z+HIGH);
                }else
                {
                    Despawn();
                }
            }
        }

        void EnterCombat(Unit *who) { }
        void AttackStart(Unit* who) { }
        void MoveInLineOfSight(Unit* who) { }

        void Despawn()
        {
            me->DealDamage(me, me->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
            me->RemoveCorpse();
            return;
        }

        void UpdateAI(const uint32 diff)
        {
            if(CheckTeronTimer < diff)
            {
                if(TeronGUID)
                {
                    DoZoneInCombat();

                    Creature* Teron = Unit::GetCreature((*me), TeronGUID);
                    if((Teron) && (!Teron->isAlive() || !Teron->isInCombat()))
                    {
                        Despawn();
                        return;
                    }
                }
                else
                {
                    Despawn();
                    return;
                }

                CheckTeronTimer = 5000;
            }else CheckTeronTimer -= diff;

            if(ShadowBoltTimer < diff)
            {
                Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                if(ptarget)
                    DoCast(ptarget , SPELL_SHADOWBOLT);
                ShadowBoltTimer = 2000;
            }else ShadowBoltTimer -= diff;

        }

    };
};

class mob_shadowy_construct : public CreatureScript
{
public:
    mob_shadowy_construct() : CreatureScript("mob_shadowy_construct") { }

    CreatureAI* GetAI(Creature *_Creature) const
    {
        return new mob_shadowy_constructAI (_Creature);
    }

    struct  mob_shadowy_constructAI : public ScriptedAI
    {
        mob_shadowy_constructAI(Creature* c) : ScriptedAI(c) 
        {
             pInstance =c->GetInstanceScript();
        }

        InstanceScript *pInstance;

        uint64 GhostGUID;
        uint64 TeronGUID;

        uint32 CheckPlayerTimer;
        uint32 CheckTeronTimer;
        uint32 reset_Timer;

        void Reset()
        {
            GhostGUID = 0;
            TeronGUID = 0;

            CheckPlayerTimer = 2000;
            CheckTeronTimer = 5000;
            reset_Timer = 10000;

            me->CastSpell(me,40334,true);
        }

        void EnterCombat(Unit* who) { }

        void MoveInLineOfSight(Unit *who)
        {
            //if(!who || (!who->isAlive()) || (who->GetGUID() == GhostGUID))
            //    return;

            ScriptedAI::MoveInLineOfSight(who);
        }

    #pragma region Sinnloses Zeug

    /* Comment it out for now. NOTE TO FUTURE DEV: UNCOMMENT THIS OUT ONLY AFTER MIND CONTROL IS IMPLEMENTED
        void DamageTaken(Unit* done_by, uint32 &damage)
        {
            if(done_by->GetGUID() != GhostGUID)
            damage = 0;                                         // Only the ghost can deal damage.
        }
     */

        //void CheckPlayers()
        //{
        //    std::list<HostileReference*>& m_threatlist = me->getThreatManager().getThreatList();
        //    if(m_threatlist.empty())
        //        return;                                         // No threat list. Don't continue.
        //    std::list<HostileReference*>::iterator itr = m_threatlist.begin();
        //    std::list<Unit*> targets;
        //    for( ; itr != m_threatlist.end(); ++itr)
        //    {
        //        Unit* pUnit = Unit::GetUnit((*me), (*itr)->getUnitGuid());
        //        if(pUnit && pUnit->isAlive())
        //            targets.push_back(pUnit);
        //    }
        //    targets.sort(TargetDistanceOrder(me));
        //    Unit* target = targets.front();
        //    if(target && me->IsWithinDistInMap(target, me->GetAttackDistance(target)))
        //    {
        //        DoCast(target, SPELL_ATROPHY);
        //        me->AI()->AttackStart(target);
        //    }
        //}

    #pragma endregion

        void UpdateAI(const uint32 diff)
        {
            if(!UpdateVictim())
                return;

            if(reset_Timer < diff)
            {
                if(rand()%3 == 0)
                {
                    DoResetThreat();
                    if(Unit* target = SelectTarget(SELECT_TARGET_FARTHEST,1, 300, true))
                    {
                        me->Attack(target,true);
                        me->getThreatManager().addThreat(target,5000);
                    }
                }
                reset_Timer = 10000;
            }else reset_Timer -= diff;

            if(CheckPlayerTimer < diff)
            {
                DoCast(me->getVictim(), SPELL_ATROPHY);
                CheckPlayerTimer = 3000;
            }else CheckPlayerTimer -= diff;

            if(CheckTeronTimer < diff)
            {
                Creature* Teron = (Unit::GetCreature((*me), TeronGUID));
            
                if(pInstance->GetData(DATA_TERONGOREFIENDEVENT) != IN_PROGRESS)
                {
                    me->DealDamage(me, me->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                    return;
                }
                DoResetThreat();
                CheckTeronTimer = 5000;
            }else CheckTeronTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

class boss_teron_gorefiend : public CreatureScript
{
public:
    boss_teron_gorefiend() : CreatureScript("boss_teron_gorefiend") { }

    CreatureAI* GetAI(Creature *_Creature) const
    {
        return new boss_teron_gorefiendAI (_Creature);
    }

    struct  boss_teron_gorefiendAI : public ScriptedAI
    {
        boss_teron_gorefiendAI(Creature *c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
        }

        InstanceScript* pInstance;

        uint32 IncinerateTimer;
        uint32 SummonDoomBlossomTimer;
        uint32 EnrageTimer;
        uint32 CrushingShadowsTimer;
        uint32 ShadowOfDeathTimer;
        uint32 SummonShadowsTimer;
        uint32 RandomYellTimer;
        uint32 AggroTimer;
        uint32 pulse_Timer;

        uint64 AggroTargetGUID;
        uint64 GhostGUID;                                       // Player that gets killed by Shadow of Death and gets turned into a ghost

        std::list<uint64> shadowtargets;

        bool Intro;

        void Reset()
        {
            if(pInstance)
                pInstance->SetData(DATA_TERONGOREFIENDEVENT, NOT_STARTED);

            IncinerateTimer = 20000 + rand()%11000;
            SummonDoomBlossomTimer = 12000;
            EnrageTimer = 600000;
            CrushingShadowsTimer = 22000;
            SummonShadowsTimer = 1000;
            ShadowOfDeathTimer = 30000;
            RandomYellTimer = 50000;

            shadowtargets.clear();

            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            // Start off unattackable so that the intro is done properly
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

            AggroTimer = 20000;
            AggroTargetGUID = 0;
            Intro = false;

            pulse_Timer = 10000;
        }

        void EnterCombat(Unit *who)
        {
            if(pInstance)
                pInstance->SetData(DATA_TERONGOREFIENDEVENT, IN_PROGRESS);
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

        void MoveInLineOfSight(Unit *who)
        {
            if(!who || (!who->isAlive()))
                return;

            if(who->isTargetableForAttack() && who->isInAccessiblePlaceFor(me) && me->IsHostileTo(who))
            {
                float attackRadius = me->GetAttackDistance(who);

                if (me->IsWithinDistInMap(who, attackRadius) && me->GetDistanceZ(who) <= CREATURE_Z_ATTACK_RANGE && me->IsWithinLOSInMap(who))
                {
                    //if(who->HasStealthAura())
                    //    who->RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH);

                    me->AddThreat(who, 1.0f);
                }

                if(!me->isInCombat() && !Intro && me->IsWithinDistInMap(who, 30.0f) && (who->GetTypeId() == TYPEID_PLAYER))
                {
                    if(pInstance)
                        pInstance->SetData(DATA_TERONGOREFIENDEVENT, IN_PROGRESS);

                    me->GetMotionMaster()->Clear(false);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    DoScriptText(SAY_INTRO, me);
                    me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_TALK);
                    AggroTargetGUID = who->GetGUID();
                    Intro = true;
                    return;
                }
            }

            if(!Intro)
                ScriptedAI::MoveInLineOfSight(who);
        }

        void KilledUnit(Unit *victim)
        {
            switch(rand()%2)
            {
            case 0: DoScriptText(SAY_SLAY1, me); break;
            case 1: DoScriptText(SAY_SLAY2, me); break;
            }
        }

        void JustDied(Unit *victim)
        {
            if(pInstance)
                pInstance->SetData(DATA_TERONGOREFIENDEVENT, DONE);

            DoScriptText(SAY_DEATH, me);
        }

        float CalculateRandomLocation(float Loc, uint32 radius)
        {
            float coord = Loc;
            switch(rand()%2)
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

        //void MindControlGhost()
        //{
        //    /************************************************************************/
        //    /** NOTE FOR FUTURE DEVELOPER: PROPERLY IMPLEMENT THE GHOST PORTION *****/
        //    /**  ONLY AFTER TrinIty FULLY IMPLEMENTS MIND CONTROL ABILITIES      *****/
        //    /**   THE CURRENT CODE IN THIS FUNCTION IS ONLY THE BEGINNING OF    *****/
        //    /**    WHAT IS FULLY NECESSARY FOR GOREFIEND TO BE 100% COMPLETE    *****/
        //    /************************************************************************/

        //    Unit* Ghost = NULL;
        //    if(GhostGUID)
        //        Ghost = Unit::GetUnit((*me), GhostGUID);
        //    if(Ghost && Ghost->isAlive() && Ghost->HasAura(SPELL_SHADOW_OF_DEATH, 0))
        //    {
        //        float x,y,z;
        //        Ghost->GetPosition(x,y,z);
        //        Creature* control = me->SummonCreature(CREATURE_GHOST, x, y, z, 0, TEMPSUMMON_TIMED_DESPAWN, 30000);
        //        if(control)
        //        {
        //            control->SetCharmedOrPossessedBy(Ghost,true);
        //            //((Player*)Ghost)->Possess(control);
        //            Ghost->DealDamage(Ghost, Ghost->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL,
        //        false);
        //        }
        //        for(uint8 i = 0; i < 4; ++i)
        //        {
        //            Creature* Construct = NULL;
        //            float X = CalculateRandomLocation(Ghost->GetPositionX(), 10);
        //            float Y = CalculateRandomLocation(Ghost->GetPositionY(), 10);
        //            Construct = me->SummonCreature(CREATURE_SHADOWY_CONSTRUCT, X, Y, Ghost->GetPositionZ(), 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 45000);
        //            if(Construct)
        //            {
        //                Construct->CastSpell(Construct, SPELL_PASSIVE_SHADOWFORM, true);
        //                SetThreatList(Construct);               // Use same function as Doom Blossom to set Threat List.
        //                ((mob_shadowy_constructAI*)Construct->AI())->GhostGUID = GhostGUID;
        //                Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 1);
        //                if(!ptarget)                             // someone's trying to solo.
        //                    ptarget = me->getVictim();

        //                if(ptarget)
        //                    Construct->GetMotionMaster()->MoveChase(ptarget);
        //            }
        //        }
        //    }
        //}

        //void DoAttackerAreaInCombat(Unit* attacker, float range, Unit* pUnit = NULL)
        //{
        //    if (!attacker)
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
        //            if (i_pl->isAlive() && attacker->GetDistance(i_pl) <= range )
        //            {
        //                pUnit->SetInCombatWith(i_pl);
        //                i_pl->SetInCombatWith(pUnit);
        //                pUnit->AddThreat(i_pl, 0.0f);
        //            }
        //    }
        //}

        void SpellHitTarget(Unit *target, const SpellEntry *spell)
        {
            if(spell->Id != SPELL_SHADOW_OF_DEATH)
                return;

            if(target && target->GetTypeId() == TYPEID_PLAYER)
                shadowtargets.push_back(target->GetGUID());

        }

        void UpdateAI(const uint32 diff)
        {
            if(Intro)
            {
                if(AggroTimer < diff)
                {
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    DoScriptText(SAY_AGGRO, me);
                    me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_NONE);
                    Intro = false;
                    if(AggroTargetGUID)
                    {
                        Unit* pUnit = Unit::GetUnit((*me), AggroTargetGUID);
                        if(pUnit)
                            AttackStart(pUnit);

                        DoZoneInCombat();
                    }
                    else
                    {
                        EnterEvadeMode();
                        return;
                    }
                }else AggroTimer -= diff;
            }

            if(!UpdateVictim() || Intro)
                return;

            if(pulse_Timer < diff)
            {
                DoAttackerAreaInCombat(me->getVictim(),50);
                pulse_Timer = 10000;
            }else pulse_Timer -= diff;

            //if(SummonShadowsTimer < diff)
            //{
            //    MindControlGhost();

            //    for(uint8 i = 0; i < 2; ++i)
            //    {
            //        Creature* Shadow = NULL;
            //        float X = CalculateRandomLocation(me->GetPositionX(), 10);
            //        //Shadow = me->SummonCreature(CREATURE_SHADOWY_CONSTRUCT, X, me->GetPositionY(), me->GetPositionZ(), 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 0);
            //        if(Shadow)
            //        {
            //            Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 1);
            //            if(!ptarget)
            //                ptarget = me->getVictim();

            //            if(ptarget)
            //                Shadow->AI()->AttackStart(ptarget);
            //        }
            //    }
            //    SummonShadowsTimer = 60000;
            //}else SummonShadowsTimer -= diff;

            if(SummonDoomBlossomTimer < diff)
            {
                if (Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                {
                    if(TryDoCast(ptarget,SPELL_SUMMON_DOOM_BLOSSOM))
                        SummonDoomBlossomTimer = 35000;
                }
            }else SummonDoomBlossomTimer -= diff;

            if(IncinerateTimer < diff)
            {
                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 300, true);
                if(!target)
                    target = me->getVictim();

                if(target)
                {
                    if(TryDoCast(target, SPELL_INCINERATE))
                    {
                        switch(rand()%2)
                        {
                        case 0: DoScriptText(SAY_SPECIAL1, me); break;
                        case 1: DoScriptText(SAY_SPECIAL2, me); break;
                        }
                        IncinerateTimer = 10000 + (rand()%10) * 1000;
                    }
                }
            }else IncinerateTimer -= diff;

            if(CrushingShadowsTimer < diff)
            {
                if(!me->IsNonMeleeSpellCasted(false))
                {
                    SpellEntry *spellInfo;
                    spellInfo = (SpellEntry*)GetSpellStore()->LookupEntry(SPELL_CRUSHING_SHADOWS);
                    if(spellInfo)
                    {
                        spellInfo->MaxAffectedTargets = 5;
                        me->CastSpell(me,spellInfo,false);
                    }
                    CrushingShadowsTimer = 10000 + rand()%5000;
                }
            }else CrushingShadowsTimer -= diff;

            if(ShadowOfDeathTimer < diff)
            {
                if(!me->IsNonMeleeSpellCasted(false))
                {
                    Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 300, true);

                    if(!target)
                       target = me->getVictim();

                    if(target && target->isAlive() && target->GetTypeId() == TYPEID_PLAYER && !target->HasAura(SPELL_SHADOW_OF_DEATH,1) )
                    {
                        // Custom ... becaus Effekt is not needed
                        SpellEntry *spellInfo;
                        spellInfo = (SpellEntry*)GetSpellStore()->LookupEntry(SPELL_SHADOW_OF_DEATH);
                        if(spellInfo)
                        {
                            spellInfo->Effect[0] = 0;
                            me->CastSpell(target,spellInfo,false);
                        }

                        //DoCast(target, SPELL_SHADOW_OF_DEATH);
                    
                        //me->CastCustomSpell(target,SPELL_SHADOW_OF_DEATH,NULL,NULL,NULL,false);
                        /*GhostGUID = target->GetGUID();*/
                        ShadowOfDeathTimer = 30000;
                        //SummonShadowsTimer = 53000; // Make it VERY close but slightly less so that we can check if the aura is still on the player
                    }
                }
            }else ShadowOfDeathTimer -= diff;

            if(SummonShadowsTimer < diff)
            {
                if(!shadowtargets.empty())
                {

                    std::list<uint64> del_player;
                    del_player.clear();
                    for(std::list<uint64>::iterator itr = shadowtargets.begin(); itr != shadowtargets.end(); ++itr)
                    {
                        Player* temp = Unit::GetPlayer(*me,*itr);
                        if(temp)
                        {
                            if(temp->isDead() || !temp->HasAuraEffect(SPELL_SHADOW_OF_DEATH,1))
                            {
                                float x,y,z;
                                temp->GetPosition(x,y,z);
                                Unit *ptarget;
                                Creature* c_temp;

                                c_temp = me->SummonCreature(CREATURE_SHADOWY_CONSTRUCT, x+3 ,y+3 , z , 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 0);
                                ptarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                                if(!ptarget) ptarget = me->getVictim();
                                if(ptarget) c_temp->Attack(ptarget,true);

                                c_temp = me->SummonCreature(CREATURE_SHADOWY_CONSTRUCT, x-3 ,y+3 , z , 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 0);
                                ptarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                                if(!ptarget) ptarget = me->getVictim();
                                if(ptarget) c_temp->Attack(ptarget,true);

                                c_temp = me->SummonCreature(CREATURE_SHADOWY_CONSTRUCT, x+3 ,y-3 , z , 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 0);
                                ptarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                                if(!ptarget) ptarget = me->getVictim();
                                if(ptarget) c_temp->Attack(ptarget,true);

                                c_temp = me->SummonCreature(CREATURE_SHADOWY_CONSTRUCT, x-3 ,y-3 , z , 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 0);
                                ptarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                                if(!ptarget) ptarget = me->getVictim();
                                if(ptarget) c_temp->Attack(ptarget,true);

                                del_player.push_back(*itr);
                            }
                        }/*else
                            del_player.push_back(*itr);*/
                        //Auskommentieren fixt ALT+F4 Exploit 
                    }
                    for(std::list<uint64>::iterator itr = del_player.begin(); itr != del_player.end(); ++itr)
                    {
                        shadowtargets.remove(*itr);
                        Player* sacrifice = Unit::GetPlayer(*me,*itr);
                        if(sacrifice && sacrifice->isAlive())
                        {
                            me->DealDamage(sacrifice,sacrifice->GetHealth());
                        }
                    }
                }
                SummonShadowsTimer = 1000;
            }else SummonShadowsTimer -= diff;

            if(RandomYellTimer < diff)
            {
                switch(rand()%2)
                {
                case 0: DoScriptText(SAY_SPELL1, me); break;
                case 1: DoScriptText(SAY_SPELL2, me); break;
                }
                RandomYellTimer = 50000 + rand()%51 * 1000;
            }else RandomYellTimer -= diff;

            if(!me->HasAura(SPELL_BERSERK, 0))
            {
                if(EnrageTimer < diff)
                {
                    DoCast(me, SPELL_BERSERK);
                    DoScriptText(SAY_ENRAGE, me);
                }else EnrageTimer -= diff;
            }

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_teron_gorefiend()
{
    new mob_doom_blossom();
    new mob_shadowy_construct();
    new boss_teron_gorefiend();
}

