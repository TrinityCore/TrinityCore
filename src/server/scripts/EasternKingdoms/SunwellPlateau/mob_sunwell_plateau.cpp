/* ScriptData
SDName: Sunwell Plateau
SD%Complete: ??
SDComment: Trash Scripts
SDCategory: Sunwell Plateau
EndScriptData */

#include "ScriptPCH.h"
#include "sunwell_plateau.h"

/**********************
Script Basis
- Enthält Aggropuls
- Enthält Find Funktion
**********************/
#define SPELL_SUNWELL_RADIANCE                      45769

struct mob_sunwell_plateau_tashAI : public ScriptedAI
{
    mob_sunwell_plateau_tashAI(Creature *c) : ScriptedAI(c){}

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
        Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
        if(ptarget)
            SendAttacker(ptarget);
    }
    void KilledUnit(Unit *victim){}
    void JustDied(Unit *victim){}

    Creature* FindNearestCreature(uint32 entry, float range)
    {
        Creature *creature = NULL;
        Trinity::NearestCreatureEntryWithLiveStateInObjectRangeCheck checker(*me, entry, true, range);
        Trinity::CreatureLastSearcher<Trinity::NearestCreatureEntryWithLiveStateInObjectRangeCheck> searcher(me, creature, checker);
        me->VisitNearbyObject(range, searcher);
        return creature;
    }

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

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim() )
            return;

        DoAggroPuls(diff);

        DoMeleeAttackIfReady();
    }
};
/* Basis End */

//Sunblade Arch Mage
#define SPELL_SBAM_ARCANE_EXPLOSION                 46553
#define SPELL_SBAM_BLINK                            46573
#define SPELL_SBAM_FROST_NOVA                       46555

//Sunblade Cabalist
#define SPELL_SWCA_SUMMON_IMP                       46544
#define SPELL_SWCA_SHADOW_BOLT                      47248
#define SPELL_SWCA_IGNITE_MANA                      46543

//Sunblade Dawn Priest
#define SPELL_SWDP_HOLY_NOVA                        46564
#define SPELL_SWDP_HOLYFORM                         46565
#define SPELL_SWDP_RENEW                            46563

//Sunblade Dusk Priest
#define SPELL_SWKP_MIND_FLAY                        46562
#define SPELL_SWKP_FEAR                             46561
#define SPELL_SWKP_SHADOWWORD_PAIN                  46560

//Sunblade Vindicator
#define SPELL_SWV_CLEAVE                            46559
#define SPELL_SWV_MORTAL_STRIKE                     39171

//Sunblade Dragonhawk
#define SPELL_SBDH_FIRE_BREATH                      47251

//Sunblade Slayer   
#define SPELL_SWSL_SLAYING_SHOT                     46557
#define SPELL_SWSL_SCATTER_SHOT                     46681
#define SPELL_SWSL_SHOOT                            47001

//Sunblade Protector
#define SPELL_SWPT_FEL_LIGHTNING                    46480

//Sunwell Scout
#define SPELL_SWSC_ACTIVATE_PROTECTOR               46475
#define SPELL_SWSC_SINISTER_STRIKE                  46558
#define ENTRY_SUNWELL_PROTECTOR                     25507

//Shadowsword Assassin
#define SPELL_SSA_ASSASSIN_MARK                     46459
#define SPELL_SSA_GREATER_INVISIBILITY              16380
#define SPELL_SSA_SHADOWSTEP                        46463

//Shadowsword Lifeshaper
#define SPELL_SSLS_DRAIN_LIFE                       46466

//Shadowsword Manafiend
#define SPELL_SSMF_ARCANE_EXPLOSION                 46457 //???
#define SPELL_SSMF_DRAIN_MANA                       46453
#define SPELL_SSMF_CHILLING_TOUCH                   46744

//Shadowsword Soulbinder
#define SPELL_SSSB_SUMMON_FELGARD                   46241
#define SPELL_SSSB_SUMMON_INFERNAL                  46229
#define SPELL_SSSB_CURSE_OF_EXHAUSTION              46434
#define SPELL_SSSB_DOMINATION                       46427
#define SPELL_SSSB_FLASH_OF_DARKNESS                46442

//Shadowsword Vanquisher
#define SPELL_SSVQ_MELT_ARMOR                       46469
#define SPELL_SSVQ_CLEAVE                           46468

//Shadowsword Commander
#define SPELL_SSCD_SHIELD_SLAM                      46762
#define SPELL_SSCD_BATTLE_SHOUT                     46763

//Shadowsword Deathbringer
#define SPELL_SSDB_VOLATILE_DISEASE                 46483
#define SPELL_SSDB_DISEASE_BUFFET                   46481

//Shadowsword Guardian
#define SPELL_SSGU_EARTHQUAKE                       46932
#define SPELL_SSGU_EARTHQUAKE_DMG                   46244
#define SPELL_SSGU_BEAR_DOWN                        46239

//Apocalypse Guard
#define SPELL_ACG_CORRUPTING_STRIKE                 45029
#define SPELL_ACG_CLEAVE                            40504
#define SPELL_ACG_DEATH_COIL                        46283
#define SPELL_ACG_INFERNAL_DEFENSE                  46287

//Cataclysm Hound
#define SPELL_CCH_CATACLYSM_BREATH                  46292
#define SPELL_CCH_ENRAGE                            47399

uint32 cataclysm_aura[8] =
{
    46293,
    46294,
    46295,
    46296,
    46297,
    46298,
    46299,
    46300
};

//Chaos Gazer
#define SPELL_CGZ_DRAIN_LIFE                        46291
#define SPELL_CGZ_PETRIFY                           46288
#define SPELL_CGZ_TENTACLE_SWEEP                    46290

//Doomfire Destroyer
#define SPELL_DFD_CREATE_SHARD                      46306
#define SPELL_DOOMFIRE_IMMOLATION                   31722

//Oblivion Mage
#define SPELL_OM_POLYMORPH                          46280
#define SPELL_OM_FLAME_BUFFET                       46279

//Painbringer
#define SPELL_PB_BRING_PAIN                         46277

//Priestess of Torment
#define SPELL_POT_BURN_MANA                         46267
#define SPELL_POT_WHIRLWIND                         46270

//Volatile Fiend
#define SPELL_VF_BURNING_DESTRUCTION                47287
#define SPELL_VF_FELFIRE_FISSION                    45779
#define ENTRY_VOLATILE_FIEND                        25851

class mob_sunwell_plateau_tash : public CreatureScript
{
public:
    mob_sunwell_plateau_tash() : CreatureScript("mob_sunwell_plateau_tash") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        switch(pCreature->GetEntry())
        {
        case 25367: return new mob_sunblade_arch_mageAI (pCreature);
        case 25363: return new mob_sunblade_cabalistAI (pCreature);
        case 25371: return new mob_sunblade_dawn_priestAI (pCreature);
        case 25370: return new mob_sunblade_dusk_priestAI (pCreature);
        case 25369: return new mob_sunblade_vindicatorAI (pCreature);
        case 25867: return new mob_sunblade_dragonhawkAI (pCreature);
        case 25368: return new mob_sunblade_slayerAI (pCreature);
        case 25507: return new mob_sunblade_protectorAI (pCreature);
        case 25372: return new mob_sunblade_scoutAI (pCreature);

        case 25484: return new mob_shadowsword_assassinAI (pCreature);
        case 25506: return new mob_shadowsword_lifeshaperAI (pCreature);
        case 25483: return new mob_shadowsword_manafiendAI (pCreature);
        case 25373: return new mob_shadowsword_soulbinderAI (pCreature);
        case 25486: return new mob_shadowsword_vanquisherAI (pCreature);
        case 25837: return new mob_shadowsword_commanderAI (pCreature);
        case 25485: return new mob_shadowsword_deathbringerAI (pCreature);
        case 25508: return new mob_shadowsword_guardianAI (pCreature);

        case 25593: return new mob_apocalypse_guardAI (pCreature);
        case 25599: return new mob_cataclysm_houndAI (pCreature);
        case 25595: return new mob_chaos_gazerAI (pCreature);
        case 25592: return new mob_doomfire_destroyerAI (pCreature);
        case 25948: return new mob_doomfire_shardAI (pCreature);
        case 25597: return new mob_oblivion_mageAI (pCreature);
        case 25591: return new mob_painbringerAI (pCreature);
        case 25509: return new mob_priestess_of_tormentAI (pCreature);
        case 25851:
        case 25598: return new mob_volatile_fiendAI (pCreature);
        default: return new mob_sunblade_arch_mageAI (pCreature);
        }
    }

    struct mob_sunblade_arch_mageAI : public mob_sunwell_plateau_tashAI
    {
        mob_sunblade_arch_mageAI(Creature *c) : mob_sunwell_plateau_tashAI(c){}


        uint32 explosion_Timer;
        uint32 blink_Timer;
        uint32 nova_Timer;

        void Reset()
        {
            explosion_Timer = 10000+rand()%10000;
            blink_Timer = 10000+rand()%10000;
            nova_Timer = 10000+rand()%10000;

            mob_sunwell_plateau_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            CheckRadianceAura();

            if (!UpdateVictim() )
                return;

            if(explosion_Timer <= diff)
            {
                if(TryDoCastAOE(SPELL_SBAM_ARCANE_EXPLOSION))
                    explosion_Timer = 10000+rand()%10000;
            }else explosion_Timer -= diff;

            if(blink_Timer <= diff)
            {
                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1,100,true);
                if(target)
                    DoCast(target,SPELL_SBAM_BLINK);
                blink_Timer = 20000+rand()%10000;
            }else blink_Timer -= diff;

            if(nova_Timer <= diff)
            {
                if(!me->IsNonMeleeSpellCasted(false))
                {
                    if(TryDoCastAOE(SPELL_SBAM_FROST_NOVA))
                        nova_Timer = 10000+rand()%10000;
                }
            }else nova_Timer -= diff;

            mob_sunwell_plateau_tashAI::UpdateAI(diff);
        }
    };

    struct mob_sunblade_cabalistAI : public mob_sunwell_plateau_tashAI
    {
        mob_sunblade_cabalistAI(Creature *c) : mob_sunwell_plateau_tashAI(c){}


        uint32 bolt_Timer;
        uint32 ignite_Timer;
        uint32 summon_Timer;
        uint32 ImpCounter;

        void Reset()
        {
            bolt_Timer = 2000;
            ignite_Timer = 10000+rand()%10000;
            summon_Timer = 100;

            ImpCounter = 0;

            mob_sunwell_plateau_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            CheckRadianceAura();

            if (!UpdateVictim() )
                return;

            if(summon_Timer <= diff)
            {
                if(!me->IsNonMeleeSpellCasted(false))
                {
                    if(ImpCounter > 0 || (ImpCounter == 0 && FindNearestCreature(26101,10) == NULL))
                    {
                        DoCast(me,SPELL_SWCA_SUMMON_IMP,true);
                        DoCast(me,SPELL_SWCA_SUMMON_IMP);
                    }

                    switch(ImpCounter)
                    {
                    case 0: summon_Timer = 15000; ImpCounter++; break;
                    case 1: summon_Timer = 90000; ImpCounter++; break;
                    default: summon_Timer = 180000; ImpCounter++; break;
                    }
                }
            }else summon_Timer -= diff;

            if(ignite_Timer <= diff)
            {
                if(!me->IsNonMeleeSpellCasted(false))
                {
                    Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1,100,true);
                    if(target && target->getPowerType() == POWER_MANA)
                    {
                        DoCast(target,SPELL_SWCA_IGNITE_MANA);
                        ignite_Timer = 10000+rand()%10000;
                    }else ignite_Timer = 1000;
                }
            }else ignite_Timer -= diff;

            if(bolt_Timer <= diff)
            {
                if(TryDoCast(me->getVictim(),SPELL_SWCA_SHADOW_BOLT))
                    bolt_Timer = 2000;
            }else bolt_Timer -= diff;

            DoAggroPuls(diff);
        }
    };

    struct mob_sunblade_dawn_priestAI : public mob_sunwell_plateau_tashAI
    {
        mob_sunblade_dawn_priestAI(Creature *c) : mob_sunwell_plateau_tashAI(c){}


        uint32 nova_Timer;
        uint32 renew_Timer;

        void Reset()
        {
            nova_Timer = 15000;
            renew_Timer = 10000;

            mob_sunwell_plateau_tashAI::Reset();
        }

        void EnterCombat(Unit *who)
        {
            mob_sunwell_plateau_tashAI::EnterCombat(who);
            DoCast(me,SPELL_SWDP_HOLYFORM);
        }

        void UpdateAI(const uint32 diff)
        {
            CheckRadianceAura();

            if (!UpdateVictim() )
                return;

            if(nova_Timer < diff)
            {
                if(TryDoCastAOE(SPELL_SWDP_HOLY_NOVA))
                    nova_Timer = 15000;
            }else nova_Timer -= diff;

            if(renew_Timer < diff)
            {
                if(!me->IsNonMeleeSpellCasted(false))
                {
                    Unit* target = DoSelectLowestHpFriendly(40);
                    if(!target)
                        target = me;

                    if(target && !target->HasAura(SPELL_SWDP_RENEW,0))
                    {
                        DoCast(target,SPELL_SWDP_RENEW);
                    }
                    renew_Timer = 10000;
                }
            }else renew_Timer -= diff;

            mob_sunwell_plateau_tashAI::UpdateAI(diff);
        }
    };

    struct mob_sunblade_dusk_priestAI : public mob_sunwell_plateau_tashAI
    {
        mob_sunblade_dusk_priestAI(Creature *c) : mob_sunwell_plateau_tashAI(c){}


        uint32 fear_Timer;
        uint32 flay_Timer;
        uint32 pain_Timer;

        void Reset()
        {
            fear_Timer = 12000;
            flay_Timer = 10000;
            pain_Timer = 2000;

            mob_sunwell_plateau_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            CheckRadianceAura();

            if (!UpdateVictim() )
                return;

            if(flay_Timer < diff)
            {
                if(TryDoCastAOE(SPELL_SWKP_MIND_FLAY))
                    flay_Timer = 10000;
            }else flay_Timer -= diff;

            if(pain_Timer < diff)
            {
                if(!me->IsNonMeleeSpellCasted(false))
                {
                    Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                    if(ptarget)
                    {
                        DoCast(ptarget,SPELL_SWKP_SHADOWWORD_PAIN);
                        pain_Timer = 12000;
                    }
                }
            }else pain_Timer -= diff;

            if(fear_Timer < diff)
            {
                if(!me->IsNonMeleeSpellCasted(false))
                {
                    Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                    if(ptarget)
                    {
                        DoCast(ptarget,SPELL_SWKP_FEAR);
                        fear_Timer = 12000;
                    }
                }
            }else fear_Timer -= diff;

            mob_sunwell_plateau_tashAI::UpdateAI(diff);
        }
    };

    struct mob_sunblade_vindicatorAI : public mob_sunwell_plateau_tashAI
    {
        mob_sunblade_vindicatorAI(Creature *c) : mob_sunwell_plateau_tashAI(c){}


        uint32 cleave_Timer;
        uint32 strike_Timer;

        void Reset()
        {
            cleave_Timer = 10000;
            strike_Timer = 15000;

            mob_sunwell_plateau_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            CheckRadianceAura();

            if (!UpdateVictim() )
                return;

            if(cleave_Timer < diff)
            {
                DoCast(me->getVictim(),SPELL_SWV_CLEAVE);
                cleave_Timer = 10000;
            }else cleave_Timer -= diff;

            if(strike_Timer < diff)
            {
                DoCast(me->getVictim(),SPELL_SWV_MORTAL_STRIKE);
                strike_Timer = 15000;
            }else strike_Timer -= diff;

            mob_sunwell_plateau_tashAI::UpdateAI(diff);
        }
    };

    struct mob_sunblade_dragonhawkAI : public mob_sunwell_plateau_tashAI
    {
       mob_sunblade_dragonhawkAI(Creature *c) : mob_sunwell_plateau_tashAI(c){}

        uint32 breath_Timer;

        void Reset()
        {
            breath_Timer = 15000;

            mob_sunwell_plateau_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            CheckRadianceAura();

            if (!UpdateVictim() )
                return;

            if(breath_Timer < diff)
            {
                DoCast(me->getVictim(),000);
                breath_Timer = 10000;
            }else breath_Timer -= diff;

            mob_sunwell_plateau_tashAI::UpdateAI(diff);
        }
    };

    struct mob_sunblade_slayerAI : public mob_sunwell_plateau_tashAI
    {
        mob_sunblade_slayerAI(Creature *c) : mob_sunwell_plateau_tashAI(c){}

        uint32 slaying_Timer;
        uint32 scatter_Timer;
        uint32 shoot_Timer;

        void Reset()
        {
            slaying_Timer = 3000;
            scatter_Timer = 10000;
            shoot_Timer = 100;

            mob_sunwell_plateau_tashAI::Reset();
        }

        void AttackStart(Unit* who)
        {
            ScriptedAI::AttackStartNoMove(who);
        }

        void UpdateAI(const uint32 diff)
        {
            CheckRadianceAura();

            if (!UpdateVictim() )
                return;

            if(slaying_Timer < diff)
            {
                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 50, true);
                if(target)
                {
                    if(TryDoCast(target,SPELL_SWSL_SLAYING_SHOT))
                        slaying_Timer = 10000;
                }
            }else slaying_Timer -= diff;

            if(me->IsWithinMeleeRange(me->getVictim()))
            {
                if(me->GetMotionMaster()->GetCurrentMovementGeneratorType() != TARGETED_MOTION_TYPE)
                    DoStartMovement(me->getVictim());

                DoMeleeAttackIfReady();
            }
            else
            {
                if(me->GetDistance2d(me->getVictim()) > 10)
                    DoStartNoMovement(me->getVictim());
                if(me->GetDistance2d(me->getVictim()) > 30)
                    DoStartMovement(me->getVictim());

                if(scatter_Timer < diff)
                {
                    Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 15, true);
                    if(target)
                    {
                        if(TryDoCast(target,SPELL_SWSL_SCATTER_SHOT))
                            scatter_Timer = 10000;
                    }
                }else scatter_Timer -= diff;

                if(shoot_Timer < diff)
                {
                    DoCast(me->getVictim(),SPELL_SWSL_SHOOT);
                    shoot_Timer = 2500;
                }else shoot_Timer -= diff;
            }
        }
    };

    struct mob_sunblade_protectorAI : public mob_sunwell_plateau_tashAI
    {
        mob_sunblade_protectorAI(Creature *c) : mob_sunwell_plateau_tashAI(c){}

        uint32 ligtning_Timer;
        bool activated;

        void Reset()
        {
            activated = me->GetMotionMaster()->GetCurrentMovementGeneratorType() == WAYPOINT_MOTION_TYPE;

            ligtning_Timer = 5000;

            mob_sunwell_plateau_tashAI::Reset();

            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
        }

        void AttackStart(Unit *who)
        {
            activated = true;
            mob_sunwell_plateau_tashAI::AttackStart(who);
        }

        void MoveInLineOfSight(Unit *who)
        {
            if(activated)
                mob_sunwell_plateau_tashAI::MoveInLineOfSight(who);
        }

        void UpdateAI(const uint32 diff)
        {
            CheckRadianceAura();

            if (!UpdateVictim() )
                return;

            if(ligtning_Timer < diff)
            {
                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 60, true);
                if(!target)
                    target = me->getVictim();

                if(target)
                {
                    DoCast(target,SPELL_SWPT_FEL_LIGHTNING);
                    ligtning_Timer = 10000;
                }
            }else ligtning_Timer -= diff;

            mob_sunwell_plateau_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_sunblade_scoutAI : public mob_sunwell_plateau_tashAI
    {
        mob_sunblade_scoutAI(Creature *c) : mob_sunwell_plateau_tashAI(c){}


        uint32 strike_Timer;
        uint32 activate_Timer;
        uint64 starter;
        uint64 InactivProtector;

        bool isActivating;
        bool spellHit;

        void Reset()
        {
            me->InterruptNonMeleeSpells(false);
            me->RemoveAurasDueToSpell(SPELL_SWSC_ACTIVATE_PROTECTOR);

            strike_Timer = 5000;
            activate_Timer = 5000;

            isActivating = false;
            spellHit = false;

            starter = 0;
            InactivProtector = 0;

            mob_sunwell_plateau_tashAI::Reset();
        }

        void MoveInLineOfSight(Unit *who)
        {
            if(!isActivating)
                mob_sunwell_plateau_tashAI::MoveInLineOfSight(who);
        }

        void AttackStart(Unit* who)
        {
            if(!isActivating)
            {
                if (me->Attack(who, true))
                {
                    me->AddThreat(who, 0.0f);

                    if (!me->isInCombat())
                        EnterCombat(who);

                    if(!isActivating)
                        DoStartMovement(who);
                }
            }
        }


        void EnterCombat(Unit *who)
        {
            Creature* protector = FindNearestCreature(ENTRY_SUNWELL_PROTECTOR,200);
            if(protector)
            {
                InactivProtector = protector->GetGUID();
                float x,y;
                starter = who->GetGUID();
                protector->GetNearPoint2D(x,y,20,me->GetAngle(protector) - M_PI);
                me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                me->GetMotionMaster()->MovePoint(1,x,y,protector->GetPositionZ());
                isActivating = true;
            }
        }

        void MovementInform(uint32 type, uint32 id)
        {
            if(id != 1 || type != POINT_MOTION_TYPE)
                return;

            Creature* protector = Creature::GetCreature((*me),InactivProtector);

            me->GetMotionMaster()->MoveIdle();

            if(protector)
                DoCast(protector,SPELL_SWSC_ACTIVATE_PROTECTOR);
        }

        void SpellHitTarget(Unit *target, const SpellEntry *spell)
        {
            if(!isActivating)
                return;

            // 46476 wird leider nicht getriggert darum dieser Workaround
            if(spell->Id == 46475)
            {
                if(!spellHit)
                {
                    spellHit = true;
                    activate_Timer = 5000;
                }
            }
        }

        void UpdateAI(const uint32 diff)
        {
            CheckRadianceAura();

            if (!UpdateVictim() )
                return;

            if(isActivating)
            {
                if(spellHit)
                    if(activate_Timer < diff)
                    {
                        Unit* attacker = Unit::GetUnit((*me),starter);
                        if(attacker)
                        {
                            if(Creature* protector = Creature::GetCreature((*me),InactivProtector))
                            {
                                ((mob_sunblade_protectorAI*)protector->AI())->activated = true;
                                protector->AI()->AttackStart(attacker);
                            }
                            isActivating = false;
                            spellHit = false;

                            DoStartMovement(attacker);
                        }else DoStartMovement(me->getVictim());

                        activate_Timer = 9999999;
                    }else activate_Timer -= diff;
                return;
            }

            if(strike_Timer < diff)
            {
                DoCast(me->getVictim(),SPELL_SWSC_SINISTER_STRIKE);
                strike_Timer = 5000;
            }else strike_Timer -= diff;

            mob_sunwell_plateau_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_shadowsword_assassinAI : public mob_sunwell_plateau_tashAI
    {
        mob_shadowsword_assassinAI(Creature *c) : mob_sunwell_plateau_tashAI(c){}

        uint32 step_Timer;
        uint64 mark_Target;

        bool marked;

        void Reset()
        {
            step_Timer = 10000;
            mark_Target = 0;
            marked = false;

            DoCast(me,SPELL_SSA_GREATER_INVISIBILITY);

            mob_sunwell_plateau_tashAI::Reset();
        }

        void EnterCombat(Unit *who)
        {
            if(who->GetTypeId() == TYPEID_PLAYER)
            {
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
                me->ApplySpellImmune(0, IMMUNITY_EFFECT,SPELL_EFFECT_ATTACK_ME, true);

                DoCast(who,SPELL_SSA_ASSASSIN_MARK);
                me->getThreatManager().addThreat(who,10000.0f);
                mark_Target = who->GetGUID();
                marked = true;
            }
        }

        void UpdateAI(const uint32 diff)
        {
            CheckRadianceAura();

            if (!UpdateVictim() )
                return;

            if(marked)
                if(Player* player = Unit::GetPlayer(*me, mark_Target))
                {
                    if(!player->HasAura(SPELL_SSA_ASSASSIN_MARK,0))
                    {
                        mark_Target = 0;
                        marked = false;
                        DoResetThreat();

                        me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, false);
                        me->ApplySpellImmune(0, IMMUNITY_EFFECT,SPELL_EFFECT_ATTACK_ME, false);
                    }else me->getThreatManager().addThreat(player,10000.0f);
                }

            if(step_Timer < diff)
            {
                DoCast(me,SPELL_SSA_SHADOWSTEP);
                step_Timer = 10000;
            }else step_Timer -= diff;

            mob_sunwell_plateau_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_shadowsword_lifeshaperAI : public mob_sunwell_plateau_tashAI
    {
        mob_shadowsword_lifeshaperAI(Creature *c) : mob_sunwell_plateau_tashAI(c){}

        uint32 drain_Timer;

        void Reset()
        {
            drain_Timer = 10000;

            mob_sunwell_plateau_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            CheckRadianceAura();

            if (!UpdateVictim() )
                return;

            if(drain_Timer < diff)
            {
                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 50, true);
                if(!target)
                    target = me->getVictim();

                if(target)
                {
                    DoCast(target,SPELL_SSLS_DRAIN_LIFE);
                    drain_Timer = 10000;
                }
            }else drain_Timer -= diff;

            mob_sunwell_plateau_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_shadowsword_manafiendAI : public mob_sunwell_plateau_tashAI
    {
        mob_shadowsword_manafiendAI(Creature *c) : mob_sunwell_plateau_tashAI(c){}

        uint32 drain_Timer;
        uint32 explosion_Timer;

        void Reset()
        {
            drain_Timer = 5000;
            explosion_Timer = 7000;

            DoCast(me,SPELL_SSMF_CHILLING_TOUCH);

            mob_sunwell_plateau_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            CheckRadianceAura();

            if (!UpdateVictim() )
                return;

            if(drain_Timer < diff)
            {
                if(TryDoCastAOE(SPELL_SSMF_DRAIN_MANA))
                    drain_Timer = 10000;
            }else drain_Timer -= diff;

            mob_sunwell_plateau_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_shadowsword_soulbinderAI : public mob_sunwell_plateau_tashAI
    {
        mob_shadowsword_soulbinderAI(Creature *c) : mob_sunwell_plateau_tashAI(c){}

        uint32 curse_Timer;
        uint32 flash_Timer;
        uint32 domination_Timer;

        void Reset()
        {
            curse_Timer = 6000;
            flash_Timer = 10000;
            domination_Timer = 30000;

            mob_sunwell_plateau_tashAI::Reset();
        }

        void EnterCombat (Unit *who)
        {
            if(rand()%2 == 0) DoCast(me,SPELL_SSSB_SUMMON_FELGARD);
            else DoCast(me,SPELL_SSSB_SUMMON_INFERNAL);

            mob_sunwell_plateau_tashAI::EnterCombat(who);
        }

        void UpdateAI(const uint32 diff)
        {
            CheckRadianceAura();

            if (!UpdateVictim() )
                return;

            if(flash_Timer < diff)
            {
                if(TryDoCast(me->getVictim(),SPELL_SSSB_FLASH_OF_DARKNESS))
                    flash_Timer = 10000;
            }else flash_Timer -= diff;

            if(domination_Timer < diff)
            {
                if(TryDoCastAOE(SPELL_SSSB_DOMINATION))
                    domination_Timer = 30000;
            }else domination_Timer -= diff;

            if(curse_Timer < diff)
            {
                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0,50,true);
                if(target)
                {
                    if(TryDoCast(target,SPELL_SSSB_CURSE_OF_EXHAUSTION))
                        curse_Timer = 12000;
                }
            }else curse_Timer -= diff;

            mob_sunwell_plateau_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_shadowsword_vanquisherAI : public mob_sunwell_plateau_tashAI
    {
        mob_shadowsword_vanquisherAI(Creature *c) : mob_sunwell_plateau_tashAI(c){}

        uint32 melt_Timer;
        uint32 cleave_Timer;

        void Reset()
        {
            melt_Timer = 1000;
            cleave_Timer = 10000;

            mob_sunwell_plateau_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            CheckRadianceAura();

            if (!UpdateVictim() )
                return;

            if(cleave_Timer < diff)
            {
                if(TryDoCast(me->getVictim(),SPELL_SSVQ_CLEAVE))
                    cleave_Timer = 10000;
            }else cleave_Timer -= diff;

            if(melt_Timer < diff)
            {
                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 5,true);
                if(target)
                {
                    if(TryDoCast(target,SPELL_SSVQ_MELT_ARMOR))
                        melt_Timer = 5000;
                }
            }else melt_Timer -= diff;

            mob_sunwell_plateau_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_shadowsword_commanderAI : public mob_sunwell_plateau_tashAI
    {
        mob_shadowsword_commanderAI(Creature *c) : mob_sunwell_plateau_tashAI(c){}

        uint32 slam_Timer;
        uint32 shout_Timer;

        void Reset()
        {
            slam_Timer = 6000;
            shout_Timer = 30000;

            mob_sunwell_plateau_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            CheckRadianceAura();

            if (!UpdateVictim() )
                return;

            if(slam_Timer < diff)
            {
                if(TryDoCast(me->getVictim(),SPELL_SSCD_SHIELD_SLAM))
                    slam_Timer = 8000;
            }else slam_Timer -= diff;

            if(shout_Timer < diff)
            {
                if(TryDoCastAOE(SPELL_SSCD_BATTLE_SHOUT))
                    shout_Timer = 30000;

            }else shout_Timer -= diff;

            mob_sunwell_plateau_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_shadowsword_deathbringerAI : public mob_sunwell_plateau_tashAI
    {
        mob_shadowsword_deathbringerAI(Creature *c) : mob_sunwell_plateau_tashAI(c){}


        uint32 disease_Timer;
        uint32 buffet_Timer;

        void Reset()
        {
            disease_Timer = 1000;
            buffet_Timer = 6000;

            mob_sunwell_plateau_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            CheckRadianceAura();

            if (!UpdateVictim() )
                return;

            if(disease_Timer < diff)
            {
                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 5,true);
                if(target)
                {
                    if(TryDoCast(target,SPELL_SSDB_VOLATILE_DISEASE))
                        disease_Timer = 12000;
                }
            }else disease_Timer -= diff;

            if(buffet_Timer < diff)
            {
                if(TryDoCast(me->getVictim(),SPELL_SSDB_DISEASE_BUFFET))
                    buffet_Timer = 10000;
            }else buffet_Timer -= diff;

            mob_sunwell_plateau_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_shadowsword_guardianAI : public mob_sunwell_plateau_tashAI
    {
        mob_shadowsword_guardianAI(Creature *c) : mob_sunwell_plateau_tashAI(c){}

        uint32 bear_Timer;

        void Reset()
        {
            bear_Timer = 10000;

            mob_sunwell_plateau_tashAI::Reset();
        }

        void EnterCombat(Unit *who)
        {
            DoCast(me,SPELL_SSGU_EARTHQUAKE);

            mob_sunwell_plateau_tashAI::EnterCombat(who);
        }

        void UpdateAI(const uint32 diff)
        {
            CheckRadianceAura();

            if (!UpdateVictim() )
                return;

            if(bear_Timer < diff)
            {
                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 50, true);
                if(target)
                {
                    if(TryDoCast(target,SPELL_SSGU_BEAR_DOWN))
                        bear_Timer = 10000;
                }
            }else bear_Timer -= diff;

            mob_sunwell_plateau_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_apocalypse_guardAI : public mob_sunwell_plateau_tashAI
    {
        mob_apocalypse_guardAI(Creature *c) : mob_sunwell_plateau_tashAI(c){}

        bool shielded;

        uint32 coil_Timer;
        uint32 strike_Timer;
        uint32 cleave_Timer;

        void Reset()
        {
            shielded = false;

            coil_Timer = 20000;
            strike_Timer = 12000;
            cleave_Timer = 15000;

            mob_sunwell_plateau_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            CheckRadianceAura();

            if (!UpdateVictim() )
                return;

            if(cleave_Timer < diff)
            {
                DoCast(me->getVictim(),SPELL_ACG_CLEAVE);
                cleave_Timer = 15000;
            }else cleave_Timer -= diff;

            if(strike_Timer < diff)
            {
                DoCast(me->getVictim(),SPELL_ACG_CORRUPTING_STRIKE);
                strike_Timer = 15000;
            }else strike_Timer -= diff;

            if(coil_Timer < diff)
            {
                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50, true);
                if(target)
                {
                    if(TryDoCast(target,SPELL_ACG_DEATH_COIL))
                        coil_Timer = 20000;
                }
            }else coil_Timer -= diff;

            if(!shielded)
                if((me->GetHealth()*100 / me->GetMaxHealth()) <= 10)
                {
                    DoCast(me,SPELL_ACG_INFERNAL_DEFENSE,true);
                    shielded = true;
                }

            mob_sunwell_plateau_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_cataclysm_houndAI : public mob_sunwell_plateau_tashAI
    {
        mob_cataclysm_houndAI(Creature *c) : mob_sunwell_plateau_tashAI(c){}

        uint32 breath_Timer;
        uint32 enrage_Timer;

        void Reset()
        {
            breath_Timer = 18000;
            enrage_Timer = 12000;

            mob_sunwell_plateau_tashAI::Reset();
        }

        void SpellHitTarget(Unit *target, const SpellEntry *spell)
        {
            if(spell->Id == SPELL_CCH_CATACLYSM_BREATH && target->GetTypeId() == TYPEID_PLAYER)
            {
                uint32 miss = 0;

                for(int i = 0; i<8; i++)
                {
                    if(rand()%2 == 0 || miss >= 3)
                        me->CastSpell(target,cataclysm_aura[i],true);
                    else 
                        miss++;
                }
            }
        }

        void UpdateAI(const uint32 diff)
        {
            CheckRadianceAura();

            if (!UpdateVictim() )
                return;

            if(breath_Timer < diff)
            {
                if(TryDoCast(me->getVictim(),SPELL_CCH_CATACLYSM_BREATH))
                    breath_Timer = 60000;
            }else breath_Timer -= diff;

            if(enrage_Timer < diff)
            {
                if(TryDoCast(me,SPELL_CCH_ENRAGE))
                    enrage_Timer = 24000;
            }else enrage_Timer -= diff;

            mob_sunwell_plateau_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_chaos_gazerAI : public mob_sunwell_plateau_tashAI
    {
        mob_chaos_gazerAI(Creature *c) : mob_sunwell_plateau_tashAI(c){}

        uint32 drain_Timer;
        uint32 petrify_Timer;
        uint32 sweep_Timer;

        void Reset()
        {
            drain_Timer = 12000;
            petrify_Timer = 16000;
            sweep_Timer = 5000;

            mob_sunwell_plateau_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            CheckRadianceAura();

            if (!UpdateVictim() )
                return;

            if(sweep_Timer < diff)
            {
                DoCast(me->getVictim(),SPELL_CGZ_TENTACLE_SWEEP);
                sweep_Timer = 5000;
            }else sweep_Timer -= diff;

            if(petrify_Timer < diff)
            {
                DoCast(me->getVictim(),SPELL_CGZ_PETRIFY);
                petrify_Timer = 10000;
            }else petrify_Timer -= diff;

            if(drain_Timer < diff)
            {
                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 30,true);
                if(target)
                {
                    if(TryDoCast(target,SPELL_CGZ_DRAIN_LIFE))
                        drain_Timer = 10000;
                }
            }else drain_Timer -= diff;

            mob_sunwell_plateau_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_doomfire_destroyerAI : public mob_sunwell_plateau_tashAI
    {
        mob_doomfire_destroyerAI(Creature *c) : mob_sunwell_plateau_tashAI(c){}


        uint32 create_Timer;

        void Reset()
        {
            create_Timer = 1000;

            DoCast(me,SPELL_DOOMFIRE_IMMOLATION,true);

            mob_sunwell_plateau_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            CheckRadianceAura();

            if (!UpdateVictim() )
                return;

            if(create_Timer < diff)
            {
                if(TryDoCast(me,SPELL_DFD_CREATE_SHARD))
                    create_Timer = 10000;
            }else create_Timer -= diff;

            mob_sunwell_plateau_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_doomfire_shardAI : public mob_sunwell_plateau_tashAI
    {
        mob_doomfire_shardAI(Creature *c) : mob_sunwell_plateau_tashAI(c){}

        void Reset()
        {
            DoCast(me,SPELL_DOOMFIRE_IMMOLATION,true);

            mob_sunwell_plateau_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            CheckRadianceAura();

            if (!UpdateVictim() )
                return;

            mob_sunwell_plateau_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_oblivion_mageAI : public mob_sunwell_plateau_tashAI
    {
        mob_oblivion_mageAI(Creature *c) : mob_sunwell_plateau_tashAI(c){}

        uint32 polymorph_Timer;
        uint32 buffet_Timer;

        void Reset()
        {
            polymorph_Timer = 12000;
            buffet_Timer = 2000;

            mob_sunwell_plateau_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            CheckRadianceAura();

            if (!UpdateVictim() )
                return;

            if(buffet_Timer < diff)
            {
                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50, true);
                if(target)
                {
                    if(TryDoCast(target,SPELL_OM_FLAME_BUFFET))
                        buffet_Timer = 2000;
                }
            }else buffet_Timer -= diff;

            if(polymorph_Timer < diff)
            {
                Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                if(ptarget)
                {
                    if(TryDoCast(ptarget,SPELL_OM_POLYMORPH))
                        polymorph_Timer = 12000;
                }
            }else polymorph_Timer -= diff;

            DoAggroPuls(diff);
        }
    };

    struct  mob_painbringerAI : public mob_sunwell_plateau_tashAI
    {
        mob_painbringerAI(Creature *c) : mob_sunwell_plateau_tashAI(c){}

        void Reset()
        {
            DoCast(me,SPELL_PB_BRING_PAIN,true);

            mob_sunwell_plateau_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            CheckRadianceAura();

            if (!UpdateVictim() )
                return;

            mob_sunwell_plateau_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_priestess_of_tormentAI : public mob_sunwell_plateau_tashAI
    {
        mob_priestess_of_tormentAI(Creature *c) : mob_sunwell_plateau_tashAI(c){}


        uint32 whirl_Timer;

        void Reset()
        {
            whirl_Timer = 8000;
            DoCast(me,SPELL_POT_BURN_MANA,true);

            mob_sunwell_plateau_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            CheckRadianceAura();

            if (!UpdateVictim() )
                return;

            if(whirl_Timer < diff)
            {
                DoCast(me,SPELL_POT_WHIRLWIND);
                whirl_Timer = 16000;
            }else whirl_Timer -= diff;

            mob_sunwell_plateau_tashAI::UpdateAI(diff);
        }
    };

    struct mob_volatile_fiendAI : public mob_sunwell_plateau_tashAI
    {
        mob_volatile_fiendAI(Creature *c) : mob_sunwell_plateau_tashAI(c){}

        void Reset()
        {
            mob_sunwell_plateau_tashAI::Reset();
        }

        void EnterCombat(Unit *who)
        {
            if(me->GetEntry() == ENTRY_VOLATILE_FIEND)
                DoCast(me,SPELL_VF_BURNING_DESTRUCTION);
        }

        void DamageTaken(Unit *done_by, uint32 &damage) 
        {
            if(me->GetHealth() <= damage)
                DoCastAOE(SPELL_VF_FELFIRE_FISSION,true);
        }

        void UpdateAI(const uint32 diff)
        {
            CheckRadianceAura();

            if (!UpdateVictim() )
                return;

            mob_sunwell_plateau_tashAI::UpdateAI(diff);
        }
    };
};

/*######
## npc_wyrm_sunwell_repairbot
######*/

#define GOSSIP_REPAIR       "Repariere meine Ausruestung."
#define GOSSIP_START        "Bringe mich zum Eingang zurueck."
#define GOSSIP_KALEG        "Teleportiere mich vor Kalecgos."
#define GOSSIP_BRUT         "Teleportiere mich vor Brutallus Felmyst."
#define GOSSIP_TWINS        "Teleportiere mich zu den Eredar twins."
#define GOSSIP_MURU         "Teleportiere mich zu Muru."
#define GOSSIP_KIL          "Teleportiere mich zu KilJaden"

#define GOSSIP_REPAIR_DEAK  "Reparieren deaktiveren"
#define GOSSIP_REPAIR_AKTI  "Reparieren aktivieren"

enum GOSSIP_REPAIRBOT
{
    REPARATUR = 1,
    TELE_KALEG = 3,
    TELE_BRUT = 4,
    TELE_TWINS = 5,
    TELE_MURU = 6,
    TELE_KIL = 7,
    TELE_START = 8,
    DEAK_REPAIR = 10,
    AKTI_REPAIR = 11,
};

float TeleportPoints[6][3] = 
{
    {1744,  920, 16},// Start
    {1700, 1052, 53},// Kalecgos
    {1554,  645, 51},// Brutallus Fellmyst
    {1822,  688, 33},// Eredar Twins
    {1878,  566, 72},// Muru
    {1649,  553, 34},// KilJaden
};

void AddSC_mob_sunwell_plateau()
{
    new mob_sunwell_plateau_tash();
}

/*
update creature_template set scriptname = 'mob_sunblade_arch_mage' where entry = 25367;
update creature_template set scriptname = 'mob_sunblade_cabalist' where entry = 25363;
update creature_template set scriptname = 'mob_sunblade_dawn_priest' where entry = 25371;
update creature_template set scriptname = 'mob_sunblade_dusk_priest' where entry = 25370;
update creature_template set scriptname = 'mob_sunblade_vindicator' where entry = 25369;
update creature_template set scriptname = 'mob_sunblade_dragonhawk' where entry = 25867;
update creature_template set scriptname = 'mob_sunblade_slayer' where entry = 25368;
update creature_template set scriptname = 'mob_sunblade_protector' where entry = 25507;
update creature_template set scriptname = 'mob_sunblade_scout' where entry = 25372;

update creature_template set scriptname = 'mob_shadowsword_assassin' where entry = 25484;
update creature_template set scriptname = 'mob_shadowsword_lifeshaper' where entry = 25506;
update creature_template set scriptname = 'mob_shadowsword_manafiend' where entry = 25483;
update creature_template set scriptname = 'mob_shadowsword_soulbinder' where entry = 25373;
update creature_template set scriptname = 'mob_shadowsword_vanquisher' where entry = 25486;
update creature_template set scriptname = 'mob_shadowsword_commander' where entry = 25837;
update creature_template set scriptname = 'mob_shadowsword_deathbringer' where entry = 25485;
update creature_template set scriptname = 'mob_shadowsword_guardian' where entry = 25508;

update creature_template set scriptname = 'mob_apocalypse_guard' where entry = 25593;
update creature_template set scriptname = 'mob_cataclysm_hound' where entry = 25599;
update creature_template set scriptname = 'mob_chaos_gazer' where entry = 25595;
update creature_template set scriptname = 'mob_doomfire_destroyer' where entry = 25592;
update creature_template set scriptname = 'mob_doomfire_shard' where entry = 25948;
update creature_template set scriptname = 'mob_oblivion_mage' where entry = 25597;
update creature_template set scriptname = 'mob_painbringer' where entry = 25591;
update creature_template set scriptname = 'mob_priestess_of_torment' where entry = 25509;
update creature_template set scriptname = 'mob_volatile_fiend' where entry = 25851;
update creature_template set scriptname = 'mob_volatile_fiend' where entry = 25598;
*/