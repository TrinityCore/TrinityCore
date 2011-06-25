/* ScriptData
SDName: Naxxramas
SD%Complete: ??
SDComment: Trash Scripts
SDCategory: Naxxramas
EndScriptData */

#include "ScriptPCH.h"
#include "naxxramas.h"

enum Spells
{
    // Dread Creeper - 15974
    SPELL_VEIL_OF_SHADOW                    = 28440,
    SPELL_VEIL_OF_SHADOW_H                  = 53803,
    // Carrion Spinner - 15975
    SPELL_POISON_SPRAY                      = 30043,
    SPELL_POISON_SPRAY_H                    = 56032,
    SPELL_SPIDER_WEB                        = 28434,
    // Venom Stalker - 15976
    SPELL_POISON_CHARGE                     = 28431,
    SPELL_POISON_CHARGE_H                   = 53809,
    // Crypt Reaver - 15978
    SPELL_NCRR_CLEAVE                       = 40504,
    SPELL_NCRR_FRENZY                       = 56625,
    // Tomb Horror - 15979
    SPELL_CRYPT_SCARAB_SWARM                = 54313,
    SPELL_CRYPT_SCARAB_SWARM_H              = 54317,
    SPELL_CRYPT_SCARABS                     = 54311,
    SPELL_CRYPT_SCARABS_H                   = 54316,
    SPELL_POINTY_SPIKE                      = 28614,
    SPELL_SPIKE_VOLLEY_H                    = 28615,
    // Naxxramas Cultist - 15980
    SPELL_SHADOW_BURST                      = 53850,
    SPELL_SHADOW_BURST_H                    = 53851,
    // Naxxramas Acolyte - 15981
    SPELL_NNA_ARCANE_EXPLOSION              = 56063,
    SPELL_NNA_ARCANE_EXPLOSION_H            = 56067,
    SPELL_NNA_SHADOW_BOLT_VOLLEY            = 56064,
    SPELL_NNA_SHADOW_BOLT_VOLLEY_H          = 56065,
    // Vigilant Shade - 30085
    SPELL_INVISIBLE                         = 55848,
    SPELL_NVS_SHADOW_BOLT_VOLLEY            = 55850,
    SPELL_NVS_SHADOW_BOLT_VOLLEY_H          = 55851,

    // Plague Slime - 16243
    SPELL_PLAGUE_SLIME_BLACK                = 28987, // Change on Taunt
    SPELL_PLAGUE_SLIME_BLUE                 = 28988,
    SPELL_PLAGUE_SLIME_GREEN                = 28989,
    SPELL_PLAGUE_SLIME_RED                  = 28990,
    // Infectious Ghoul - 16244
    SPELL_FLESH_ROT                         = 29915,
    SPELL_FLESH_ROT_H                       = 54709,
    SPELL_NINFG_FRENZY                      = 54701,
    SPELL_REND                              = 54703,
    SPELL_REND_H                            = 54708,
    // Stoneskin Gargoyle - 16168
    SPELL_ACID_VOLLEY                       = 29325,
    SPELL_ACID_VOLLEY_H                     = 54714,
    SPELL_STONESKIN                         = 28995, //Cast on 30%
    SPELL_STONESKIN_H                       = 54722, //Cast on 30%
    // Mutated Grub - 16297
    SPELL_SLIME_BURST                       = 30109,
    SPELL_SLIME_BURST_H                     = 54769,
    // Plague Beast - 16034
    SPELL_PLAGUE_SPRAY                      = 54780,
    SPELL_PLAGUE_SPRAY_H                    = 56538,
    // Frenzied Bat - 16036
    SPELL_FRENZIED_DIVE                     = 54781,
    // Eye Stalk - 16236
    SPELL_NES_MIND_FLAY                     = 29407,
    SPELL_NES_MIND_FLAY_H                   = 54805,

    // Patchwork Golem - 16017
    SPELL_NPWG_CLEAVE                       = 27794,
    SPELL_DISEASE_CLOUD                     = 27793,
    SPELL_EXECUTE                           = 7160,
    SPELL_EXECUTE_H                         = 56426,
    SPELL_WAR_STOMP                         = 27758,
    SPELL_WAR_STOMP_H                       = 56427,
    // Bile Retcher - 16018
    SPELL_BILE_VOMIT                        = 27807,
    SPELL_BILE_VOMIT_H                      = 54326,
    // Mad Scientist - 16020
    SPELL_GREAT_HEAL                        = 28306,
    SPELL_GREAT_HEAL_H                      = 54337,
    SPELL_MANA_BURN                         = 28301,
    SPELL_MANA_BURN_H                       = 54338,
    // Living Monstrosity - 16021
    SPELL_CHAIN_LIGHTNING                   = 28293,
    SPELL_CHAIN_LIGHTNING_H                 = 54334,
    SPELL_LIGHTNING_TOTEM                   = 28294,
    // Surgical Assistant - 16022
    SPELL_NSA_MIND_FLAY                     = 28310,
    SPELL_NSA_MIND_FLAY_H                   = 54339,
    // Embalming Slime - 16024
    SPELL_EMBALMING_CLOUD                   = 28322,
    // Stitched Giant - 16025
    SPELL_KNOCKBACK                         = 28405,
    SPELL_UNSTOPPABLE_ENRAGE                = 54356,
    // Stitched Colossus - 30071
    SPELL_MASSIV_STOMP                      = 55821,
    SPELL_MASSIV_STOMP_H                    = 55826,
    //SPELL_UNSTOPPABLE_ENRAGE                = 54356,
    // Living Poison - 16027
    SPELL_EXPLODE                           = 28433,

    // Deathcharger Steed - 16067
    SPELL_CHARGE                            = 55317,
    // Death Knight Captain - 16145
    SPELL_UNHOLY_PRESENCE                   = 55222,
    SPELL_PLAGUE_STRIKE                     = 55255,
    SPELL_PLAGUE_STRIKE_H                   = 55321,
    SPELL_RAISE_DEATH                       = 28353,
    // Death Knight - 16146
    SPELL_BLOOD_PRESENCE                    = 55212,
    SPELL_DEATH_COIL_HEAL                   = 55210,
    SPELL_DEATH_COIL_DAMAGE                 = 55209,
    SPELL_DEATH_COIL_DAMAGE_H               = 55320,
    SPELL_HYSTERIA                          = 55213,
    // Risen Squire- 16154
    SPELL_PIERCE_ARMOR                      = 55318,
    // Dark Touched Warrior - 16156
    SPELL_NDTW_WHIRLWIND                    = 55266,
    // Death Knight Cavalier - 16163
    SPELL_DISMOUNT_DEATHCHARGER             = 55294, // on Death
    SPELL_BONE_ARMOR                        = 55315,
    SPELL_BONE_ARMOR_H                      = 55336,
    SPELL_ICY_TOUCH                         = 55313,
    SPELL_ICY_TOUCH_H                       = 55331,
    SPELL_STRANGUKATE                       = 55314,
    SPELL_STRANGULATE_H                     = 55334,
    // Shade of Naxxramas - 16164
    SPELL_SUMMON_PORTAL_OF_SHADOWS          = 28383,
    SPELL_SHADOW_BOLT_VOLLEY                = 28407,
    SPELL_SHADOW_BOLT_VOLLEY_H              = 55323,
    // Necro Knight - 16165
    // Bony Construct - 16167
    SPELL_BRUTAL_SWIPE                      = 55319,
    SPELL_BRUTAL_SWIPE_H                    = 55324,
    // Skeletal Smith - 16193
    SPELL_DISARM                            = 6713,
    SPELL_CRUSH_ARMOR                       = 33661,
    // Unholy Axe - 16194
    SPELL_MORTAL_STRIKE                     = 16856,
    SPELL_NUA_WHIRLWIND                     = 55463,
    // Unholy Staff - 16215
    SPELL_NUS_ARCANE_EXPLOSION              = 28450,
    SPELL_NUS_ARCANE_EXPLOSION_H            = 55467,
    SPELL_FROST_NOVA                        = 29849,
    SPELL_POLYMORPH                         = 29848,
    // Unholy Swords - 16216
    SPELL_NUS_CLEAVE                        = 15284,
    SPELL_THRASH                            = 3391,
};

struct mob_naxxramas_trashAI : public ScriptedAI
{
    mob_naxxramas_trashAI(Creature *c) : ScriptedAI(c)
    {
        if(c->GetMap()->IsDungeon())
            pInstance = c->GetInstanceScript();
    }

    InstanceScript* pInstance;
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

    void EnterCombat(Unit *who)
    {
        DoAttackerAreaInCombat(who, 100);
        Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0);
        if(target)
            SendAttacker(target);
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
        if(me->IsNonMeleeSpellCasted(false) && !triggered) return false;

        DoCast(victim,spellId,triggered);
        return true;
    }

    bool TryDoCastAOE(uint32 spellId, bool triggered = false)
    {
        if(me->IsNonMeleeSpellCasted(false) && !triggered) return false;

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

class mob_naxxramas_trash : public CreatureScript
{
public:
    mob_naxxramas_trash() : CreatureScript("mob_naxxramas_trash") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        switch(pCreature->GetEntry())
        {
        case 15974: return new mob_dread_creeperAI (pCreature);
        case 15975: return new mob_carrion_spinnerAI (pCreature);
        case 15976: return new mob_venom_stalkerAI (pCreature);
        case 15978: return new mob_crypt_reaverAI (pCreature);
        case 15979: return new mob_tomb_horrorAI (pCreature);
        case 15980: return new mob_naxxramas_cultistAI (pCreature);
        case 15981: return new mob_naxxramas_acolyteAI (pCreature);
        case 30085: return new mob_vigilant_shadeAI (pCreature);

        case 16243: return new mob_plague_slimeAI (pCreature);
        case 16244: return new mob_infectious_ghoulAI (pCreature);
        case 16168: return new mob_stoneskin_gargoyleAI (pCreature);
        case 16297: return new mob_mutated_grubAI (pCreature);
        case 16306: return new mob_frenzied_batAI (pCreature);
        case 16236: return new mob_eye_stalkAI (pCreature);

        case 16017: return new mob_patchwork_golemAI (pCreature);
        case 16018: return new mob_bile_retcherAI (pCreature);
        case 16020: return new mob_mad_scientistAI (pCreature);
        case 16021: return new mob_living_monstrosityAI (pCreature);
        case 16022: return new mob_surgical_assistantAI (pCreature);
        case 16024: return new mob_embalming_slimeAI (pCreature);
        case 16025: return new mob_stitched_giantAI (pCreature);
        case 30071: return new mob_stitched_colossusAI (pCreature);
        case 16027: return new mob_living_poisonAI (pCreature);

        case 16067: return new mob_deathcharger_steedAI (pCreature);
        case 16145: return new mob_death_knight_captainAI (pCreature);
        case 16146: return new mob_death_knightAI (pCreature);
        case 16154: return new mob_risen_squireAI (pCreature);
        case 16156: return new mob_dark_touched_warriorAI (pCreature);
        case 16163: return new mob_death_knight_cavalierAI (pCreature);
        case 16164: return new mob_shade_of_naxxramasAI (pCreature);
        case 16167: return new mob_bony_constructAI  (pCreature);
        case 16193: return new mob_skeletal_smithAI (pCreature);
        case 16194: return new mob_unholy_axeAI (pCreature);
        case 16215: return new mob_unholy_staffAI (pCreature);
        case 16216: return new mob_unholy_swordsAI (pCreature);
        default: return new mob_dread_creeperAI (pCreature);
        }
    }
    // Dread Creeper - 15974
    struct mob_dread_creeperAI : mob_naxxramas_trashAI 
    {
        mob_dread_creeperAI(Creature *c) : mob_naxxramas_trashAI(c){}

        uint32 uiVeilOfShadow_Timer;

        void Reset()
        {
            uiVeilOfShadow_Timer = 1000;

            mob_naxxramas_trashAI::Reset();
        }
        
        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(uiVeilOfShadow_Timer <= diff)
            {
                if(TryDoCastAOE(RAID_MODE(SPELL_VEIL_OF_SHADOW,SPELL_VEIL_OF_SHADOW_H)))
                    uiVeilOfShadow_Timer = 15000;
            }else uiVeilOfShadow_Timer -= diff;

            mob_naxxramas_trashAI::UpdateAI(diff);
        }
    };
    // Carrion Spinner - 15975
    struct mob_carrion_spinnerAI : mob_naxxramas_trashAI 
    {
        mob_carrion_spinnerAI(Creature *c) : mob_naxxramas_trashAI(c){}

        uint32 uiSpiderWeb_Timer;
        uint32 uiPoisonSpray_Timer;

        void Reset()
        {
            uiSpiderWeb_Timer = 1000;
            uiPoisonSpray_Timer = 10000;
            mob_naxxramas_trashAI::Reset();
        }
        
        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(uiSpiderWeb_Timer <= diff)
            {
                if(TryDoCast(me->getVictim(),SPELL_SPIDER_WEB))
                    uiSpiderWeb_Timer = 15000;
            }else uiSpiderWeb_Timer -= diff;

            if(uiPoisonSpray_Timer <= diff)
            {
                if(TryDoCast(me->getVictim(),SPELL_POISON_SPRAY))
                    uiPoisonSpray_Timer = 10000;
            }else uiPoisonSpray_Timer -= diff;

            mob_naxxramas_trashAI::UpdateAI(diff);
        }
    };
    // Venom Stalker - 15976
    struct mob_venom_stalkerAI : mob_naxxramas_trashAI 
    {
        mob_venom_stalkerAI(Creature *c) : mob_naxxramas_trashAI(c){}

        uint32 uiPoisonCharge_Timer;

        void Reset()
        {
            uiPoisonCharge_Timer = 5000;

            mob_naxxramas_trashAI::Reset();
        }
        
        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(uiPoisonCharge_Timer <= diff)
            {
                if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM,0,40,true))
                    if(TryDoCast(target,RAID_MODE(SPELL_POISON_CHARGE,SPELL_POISON_CHARGE_H)))
                        uiPoisonCharge_Timer = 15000;
            }else uiPoisonCharge_Timer -= diff;

            mob_naxxramas_trashAI::UpdateAI(diff);
        }
    };
    // Crypt Reaver - 15978
    struct mob_crypt_reaverAI : mob_naxxramas_trashAI 
    {
        mob_crypt_reaverAI(Creature *c) : mob_naxxramas_trashAI(c){}

        uint32 uiCleave_Timer;

        void Reset()
        {
            uiCleave_Timer = 1000;

            mob_naxxramas_trashAI::Reset();
        }
        
        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(uiCleave_Timer <= diff)
            {
                if(TryDoCast(me->getVictim(),SPELL_NCRR_CLEAVE))
                    uiCleave_Timer = 6000;
            }else uiCleave_Timer -= diff;

            if(HealthBelowPct(30))
            {
                if(!me->HasAuraEffect(SPELL_NCRR_FRENZY,0))
                    TryDoCast(me,SPELL_NCRR_FRENZY);
            }

            mob_naxxramas_trashAI::UpdateAI(diff);
        }
    };
    // Tomb Horror - 15979
    struct mob_tomb_horrorAI : mob_naxxramas_trashAI 
    {
        mob_tomb_horrorAI(Creature *c) : mob_naxxramas_trashAI(c){}

        uint32 uiCryptScarabs_Timer;
        uint32 uiCryptScarabSwarm_Timer;

        void Reset()
        {
            uiCryptScarabs_Timer = 2000;
            uiCryptScarabSwarm_Timer = 10000;

            mob_naxxramas_trashAI::Reset();
        }
        
        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(uiCryptScarabs_Timer <= diff)
            {
                if(TryDoCast(me->getVictim(),RAID_MODE(SPELL_CRYPT_SCARABS,SPELL_CRYPT_SCARABS_H)))
                    uiCryptScarabs_Timer = 3000;
            }else uiCryptScarabs_Timer -= diff;

            if(uiCryptScarabSwarm_Timer <= diff)
            {
                if(TryDoCastAOE(RAID_MODE(SPELL_CRYPT_SCARAB_SWARM_H,SPELL_CRYPT_SCARAB_SWARM_H)))
                    uiCryptScarabSwarm_Timer = 15000;
            }else uiCryptScarabSwarm_Timer -= diff;

            mob_naxxramas_trashAI::UpdateAI(diff);
        }
    };
    // Naxxramas Cultist - 15980
    struct mob_naxxramas_cultistAI : mob_naxxramas_trashAI 
    {
        mob_naxxramas_cultistAI(Creature *c) : mob_naxxramas_trashAI(c){}

        uint32 uiShadowBurst_Timer;

        void Reset()
        {
            uiShadowBurst_Timer = 2000;

            mob_naxxramas_trashAI::Reset();
        }
        
        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(uiShadowBurst_Timer <= diff)
            {
                if(TryDoCastAOE(RAID_MODE(SPELL_SHADOW_BURST,SPELL_SHADOW_BURST_H)))
                    uiShadowBurst_Timer = 5000;
            }else uiShadowBurst_Timer -= diff;

            mob_naxxramas_trashAI::UpdateAI(diff);
        }
    };
    // Naxxramas Acolyte - 15981
    struct mob_naxxramas_acolyteAI : mob_naxxramas_trashAI 
    {
        mob_naxxramas_acolyteAI(Creature *c) : mob_naxxramas_trashAI(c){}

        uint32 uiArcaneExplosion_Timer;
        uint32 uiShadowBoltVolley_Timer;

        void Reset()
        {
            uiArcaneExplosion_Timer = urand(2000,5000);
            uiShadowBoltVolley_Timer = urand(2000,5000);

            mob_naxxramas_trashAI::Reset();
        }
        
        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(uiArcaneExplosion_Timer <= diff)
            {
                if(TryDoCastAOE(RAID_MODE(SPELL_NNA_ARCANE_EXPLOSION,SPELL_NNA_ARCANE_EXPLOSION_H)))
                    uiArcaneExplosion_Timer = urand(5000,10000);
            }else uiArcaneExplosion_Timer -= diff;

            if(uiShadowBoltVolley_Timer <= diff)
            {
                if(TryDoCastAOE(RAID_MODE(SPELL_NNA_SHADOW_BOLT_VOLLEY,SPELL_NNA_SHADOW_BOLT_VOLLEY_H)))
                    uiShadowBoltVolley_Timer = urand(5000,10000);
            }else uiShadowBoltVolley_Timer -= diff;

            mob_naxxramas_trashAI::UpdateAI(diff);
        }
    };
    // Vigilant Shade - 30085
    struct mob_vigilant_shadeAI : mob_naxxramas_trashAI 
    {
        mob_vigilant_shadeAI(Creature *c) : mob_naxxramas_trashAI(c){}

        uint32 uiShadowBoltVolley_Timer;

        void Reset()
        {
            DoCast(me,SPELL_INVISIBLE);

            uiShadowBoltVolley_Timer = urand(2000,5000);

            mob_naxxramas_trashAI::Reset();
        }

        void EnterCombat(Unit * /*who*/)
        {
            me->RemoveAurasDueToSpell(SPELL_INVISIBLE);
        }
        
        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(uiShadowBoltVolley_Timer <= diff)
            {
                if(TryDoCastAOE(RAID_MODE(SPELL_NVS_SHADOW_BOLT_VOLLEY,SPELL_NVS_SHADOW_BOLT_VOLLEY_H)))
                    uiShadowBoltVolley_Timer = urand(5000,10000);
            }else uiShadowBoltVolley_Timer -= diff;

            mob_naxxramas_trashAI::UpdateAI(diff);
        }
    };
    // Plague Slime - 16243
    struct mob_plague_slimeAI : mob_naxxramas_trashAI 
    {
        mob_plague_slimeAI(Creature *c) : mob_naxxramas_trashAI(c){}

        uint32 uiTauntCheck_Timer;
        uint32 CurrentSpell;
        uint64 TankGuid;

        void Reset()
        {
            uiTauntCheck_Timer = 1000;
            CurrentSpell = 0;
            TankGuid = 0;
            mob_naxxramas_trashAI::Reset();
        }

        void EnterCombat(Unit * who)
        {
            TankGuid = who->GetGUID();

            CurrentSpell = RAND(SPELL_PLAGUE_SLIME_BLACK,SPELL_PLAGUE_SLIME_BLUE,SPELL_PLAGUE_SLIME_GREEN,SPELL_PLAGUE_SLIME_RED);
            DoCast(me,CurrentSpell,true);

            mob_naxxramas_trashAI::EnterCombat(who);
        }
        
        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(uiTauntCheck_Timer <= diff)
            {
                if(me->getVictim() && TankGuid != me->getVictim()->GetGUID())
                {
                    TankGuid = me->getVictim()->GetGUID();

                    uint32 NewSpell = 0;
                    do 
                    {
                        NewSpell = RAND(SPELL_PLAGUE_SLIME_BLACK,SPELL_PLAGUE_SLIME_BLUE,SPELL_PLAGUE_SLIME_GREEN,SPELL_PLAGUE_SLIME_RED);
                    }while (NewSpell == CurrentSpell);
                    CurrentSpell = NewSpell;
                    DoCast(me,CurrentSpell,true);
                }
                uiTauntCheck_Timer = 10000;
            }else uiTauntCheck_Timer -= diff;

            mob_naxxramas_trashAI::UpdateAI(diff);
        }
    };
    // Infectious Ghoul - 16244
    struct mob_infectious_ghoulAI : mob_naxxramas_trashAI 
    {
        mob_infectious_ghoulAI(Creature *c) : mob_naxxramas_trashAI(c){}

        uint32 uiFleshRot_Timer;
        uint32 uiRend_Timer;

        void Reset()
        {
            uiFleshRot_Timer = 3000;
            uiRend_Timer = 7000;

            mob_naxxramas_trashAI::Reset();
        }
        
        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(uiFleshRot_Timer <= diff)
            {
                if(TryDoCast(me->getVictim(),RAID_MODE(SPELL_FLESH_ROT,SPELL_FLESH_ROT_H)))
                    uiFleshRot_Timer = 18000;
            }else uiFleshRot_Timer -= diff;

            if(uiRend_Timer <= diff)
            {
                if(TryDoCast(me->getVictim(),RAID_MODE(SPELL_REND,SPELL_REND_H)))
                    uiRend_Timer = 20000;
            }else uiRend_Timer -= diff;

            if(HealthBelowPct(30))
            {
                if(!me->HasAuraEffect(SPELL_NINFG_FRENZY,0))
                    TryDoCast(me,SPELL_NINFG_FRENZY);
            }

            mob_naxxramas_trashAI::UpdateAI(diff);
        }
    };
    // Stoneskin Gargoyle - 16168
    struct mob_stoneskin_gargoyleAI : mob_naxxramas_trashAI 
    {
        mob_stoneskin_gargoyleAI(Creature *c) : mob_naxxramas_trashAI(c){}

        uint32 uiAcidVolley_Timer;

        void Reset()
        {
            uiAcidVolley_Timer = 1000;

            mob_naxxramas_trashAI::Reset();
        }

        void SpellHit(Unit *target, const SpellEntry *spell)
        {
            if(target == me && spell->Id == RAID_MODE(SPELL_STONESKIN,SPELL_STONESKIN_H))
                me->SetStandState(UNIT_STAND_STATE_SUBMERGED);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if (me->HasAuraEffect(RAID_MODE(SPELL_STONESKIN,SPELL_STONESKIN_H),0))
                return;
            else if(me->getStandState() == UNIT_STAND_STATE_SUBMERGED)
                     me->SetStandState(UNIT_STAND_STATE_STAND);

            if(uiAcidVolley_Timer <= diff)
            {
                if(TryDoCastAOE(RAID_MODE(SPELL_ACID_VOLLEY,SPELL_ACID_VOLLEY_H)))
                    uiAcidVolley_Timer = 12000;
            }else uiAcidVolley_Timer -= diff;

            if(HealthBelowPct(30))
            {
                TryDoCast(me,RAID_MODE(SPELL_STONESKIN,SPELL_STONESKIN_H));
            }

            mob_naxxramas_trashAI::UpdateAI(diff);
        }
    };
    // Mutated Grub - 16297
    struct mob_mutated_grubAI : mob_naxxramas_trashAI 
    {
        mob_mutated_grubAI(Creature *c) : mob_naxxramas_trashAI(c){}

        uint32 uiSlimeBurst_Timer;

        void Reset()
        {
            uiSlimeBurst_Timer = 3000;

            mob_naxxramas_trashAI::Reset();
        }
        
        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(uiSlimeBurst_Timer <= diff)
            {
                if(TryDoCastAOE(RAID_MODE(SPELL_SLIME_BURST,SPELL_SLIME_BURST_H)))
                    uiSlimeBurst_Timer = 3000;
            }else uiSlimeBurst_Timer -= diff;

            mob_naxxramas_trashAI::UpdateAI(diff);
        }
    };
    // Frenzied Bat - 16036
    struct mob_frenzied_batAI : mob_naxxramas_trashAI 
    {
        mob_frenzied_batAI(Creature *c) : mob_naxxramas_trashAI(c){}

        uint32 uiFrenziedDive_Timer;

        void Reset()
        {
            uiFrenziedDive_Timer = 1000;

            mob_naxxramas_trashAI::Reset();
        }
        
        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(uiFrenziedDive_Timer <= diff)
            {
                if(TryDoCast(me->getVictim(),SPELL_FRENZIED_DIVE))
                    uiFrenziedDive_Timer = 3000;
            }else uiFrenziedDive_Timer -= diff;

            mob_naxxramas_trashAI::UpdateAI(diff);
        }
    };
    // Eye Stalk - 16236
    struct mob_eye_stalkAI : mob_naxxramas_trashAI 
    {
        mob_eye_stalkAI(Creature *c) : mob_naxxramas_trashAI(c){}

        uint32 uiMindFlay_Timer;

        void Reset()
        {
            uiMindFlay_Timer = 3000;

            mob_naxxramas_trashAI::Reset();
        }

        void AttackStart(Unit* who)
        {
            ScriptedAI::AttackStartNoMove(who);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(uiMindFlay_Timer <= diff)
            {
                if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM,0,40,true))
                    if(TryDoCast(target,RAID_MODE(SPELL_NES_MIND_FLAY, SPELL_NES_MIND_FLAY_H)))
                        uiMindFlay_Timer = 3000;
            }else uiMindFlay_Timer -= diff;

            mob_naxxramas_trashAI::UpdateAI(diff);
        }
    };
    // Patchwork Golem - 16017
    struct mob_patchwork_golemAI : mob_naxxramas_trashAI 
    {
        mob_patchwork_golemAI(Creature *c) : mob_naxxramas_trashAI(c){}

        uint32 uiCleave_Timer;
        uint32 uiExecture_Timer;
        uint32 uiWarStomp_Timer;

        void Reset()
        {
            DoCast(me,SPELL_DISEASE_CLOUD);

            uiCleave_Timer = 1000;
            uiExecture_Timer = 10000;
            uiWarStomp_Timer = 10000;

            mob_naxxramas_trashAI::Reset();
        }
        
        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(uiCleave_Timer <= diff)
            {
                if(TryDoCast(me->getVictim(),SPELL_NPWG_CLEAVE))
                    uiCleave_Timer = 5000;
            }else uiCleave_Timer -= diff;

            if(uiWarStomp_Timer <= diff)
            {
                if(TryDoCastAOE(RAID_MODE(SPELL_WAR_STOMP,SPELL_WAR_STOMP_H)))
                    uiWarStomp_Timer = urand(10000,15000);
            }else uiWarStomp_Timer -= diff;

            if(uiExecture_Timer <= diff)
            {
                if(me->getVictim() && me->getVictim()->HealthBelowPct(20))
                    if(TryDoCast(me->getVictim(),RAID_MODE(SPELL_EXECUTE,SPELL_EXECUTE_H)))
                        uiExecture_Timer = 10000;
            }else uiExecture_Timer -= diff;

            mob_naxxramas_trashAI::UpdateAI(diff);
        }
    };
    // Bile Retcher - 16018
    struct mob_bile_retcherAI : mob_naxxramas_trashAI 
    {
        mob_bile_retcherAI(Creature *c) : mob_naxxramas_trashAI(c){}

        uint32 uiBileVomit_Timer;

        void Reset()
        {
            uiBileVomit_Timer = 1000;

            mob_naxxramas_trashAI::Reset();
        }
        
        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(uiBileVomit_Timer <= diff)
            {
                if(TryDoCast(me->getVictim(),RAID_MODE(SPELL_BILE_VOMIT,SPELL_BILE_VOMIT_H)))
                    uiBileVomit_Timer = 20000;
            }else uiBileVomit_Timer -= diff;

            mob_naxxramas_trashAI::UpdateAI(diff);
        }
    };
    // Mad Scientist - 16020
    struct mob_mad_scientistAI : mob_naxxramas_trashAI 
    {
        mob_mad_scientistAI(Creature *c) : mob_naxxramas_trashAI(c){}

        uint32 uiHeal_Timer;
        uint32 uiManaBurn_Timer;

        void Reset()
        {
            uiHeal_Timer = 15000;
            uiManaBurn_Timer = 10000;

            mob_naxxramas_trashAI::Reset();
        }
        
        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(uiHeal_Timer <= diff)
            {
                Unit* target = DoSelectLowestHpFriendly(40);
                if(!target) target = me;
                
                if(TryDoCast(target,RAID_MODE(SPELL_GREAT_HEAL,SPELL_GREAT_HEAL_H)))
                    uiHeal_Timer = urand(15000,30000);
            }else uiHeal_Timer -= diff;

            if(uiManaBurn_Timer <= diff)
            {
                if(Unit *target = SelectTarget(SELECT_TARGET_RANDOM,0,40,true))
                {
                    if(target->getPowerType() == POWER_MANA)
                        if(TryDoCast(me->getVictim(),RAID_MODE(SPELL_MANA_BURN,SPELL_MANA_BURN_H)))
                            uiManaBurn_Timer = urand(10000,20000);
                }
            }else uiManaBurn_Timer -= diff;

            mob_naxxramas_trashAI::UpdateAI(diff);
        }
    };
    // Living Monstrosity - 16021
    struct mob_living_monstrosityAI : mob_naxxramas_trashAI 
    {
        mob_living_monstrosityAI(Creature *c) : mob_naxxramas_trashAI(c){}

        uint32 uiChainLightning_Timer;
        uint32 uiTotem_Timer;

        void Reset()
        {
            uiChainLightning_Timer = 5000;
            uiTotem_Timer = 10000;

            mob_naxxramas_trashAI::Reset();
        }
        
        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(uiChainLightning_Timer <= diff)
            {
                if(TryDoCast(me->getVictim(),RAID_MODE(SPELL_CHAIN_LIGHTNING,SPELL_CHAIN_LIGHTNING_H)))
                    uiChainLightning_Timer = urand(20000,30000);
            }else uiChainLightning_Timer -= diff;

            if(uiTotem_Timer <= diff)
            {
                if(TryDoCastAOE(SPELL_LIGHTNING_TOTEM))
                    uiTotem_Timer = urand(10000,20000);
            }else uiTotem_Timer -= diff;

            mob_naxxramas_trashAI::UpdateAI(diff);
        }
    };
    // Surgical Assistant - 16022
    struct mob_surgical_assistantAI : mob_naxxramas_trashAI 
    {
        mob_surgical_assistantAI(Creature *c) : mob_naxxramas_trashAI(c){}

        uint32 uiMindFlay_Timer;

        void Reset()
        {
            uiMindFlay_Timer = 10000;

            mob_naxxramas_trashAI::Reset();
        }
        
        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(uiMindFlay_Timer <= diff)
            {
                if(TryDoCast(me->getVictim(),RAID_MODE(SPELL_NSA_MIND_FLAY,SPELL_NSA_MIND_FLAY_H)))
                    uiMindFlay_Timer = urand(15000,25000);
            }else uiMindFlay_Timer -= diff;

            mob_naxxramas_trashAI::UpdateAI(diff);
        }
    };
    // Embalming Slime - 16024
    struct mob_embalming_slimeAI : mob_naxxramas_trashAI 
    {
        mob_embalming_slimeAI(Creature *c) : mob_naxxramas_trashAI(c){}

        uint32 uiCloud_Timer;

        void Reset()
        {
            uiCloud_Timer = 3000;

            mob_naxxramas_trashAI::Reset();
        }
        
        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(uiCloud_Timer <= diff)
            {
                if(TryDoCastAOE(SPELL_EMBALMING_CLOUD))
                    uiCloud_Timer = 3000;
            }else uiCloud_Timer -= diff;

            mob_naxxramas_trashAI::UpdateAI(diff);
        }
    };
    // Stitched Giant - 16025
    struct mob_stitched_giantAI : mob_naxxramas_trashAI 
    {
        mob_stitched_giantAI(Creature *c) : mob_naxxramas_trashAI(c){}

        uint32 uiKnockback_Timer;
        uint32 uiUnstoppableEnrage_Timer;

        void Reset()
        {
            uiKnockback_Timer = 3000;

            mob_naxxramas_trashAI::Reset();
        }
        
        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(uiKnockback_Timer <= diff)
            {
                if(TryDoCastAOE(SPELL_KNOCKBACK))
                    uiKnockback_Timer = urand(10000,20000);
            }else uiKnockback_Timer -= diff;

            if(HealthBelowPct(30))
            {
                if(!me->HasAuraEffect(SPELL_UNSTOPPABLE_ENRAGE,0))
                    TryDoCast(me,SPELL_UNSTOPPABLE_ENRAGE);
            }

            mob_naxxramas_trashAI::UpdateAI(diff);
        }
    };
    // Stitched Colossus - 30071
    struct mob_stitched_colossusAI : mob_naxxramas_trashAI 
    {
        mob_stitched_colossusAI(Creature *c) : mob_naxxramas_trashAI(c){}

        uint32 uiKnockback_Timer;
        uint32 uiUnstoppableEnrage_Timer;

        void Reset()
        {
            uiKnockback_Timer = 3000;

            mob_naxxramas_trashAI::Reset();
        }
        
        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(uiKnockback_Timer <= diff)
            {
                if(TryDoCastAOE(RAID_MODE(SPELL_MASSIV_STOMP,SPELL_MASSIV_STOMP_H)))
                    uiKnockback_Timer = urand(10000,20000);
            }else uiKnockback_Timer -= diff;

            if(HealthBelowPct(30))
            {
                if(!me->HasAuraEffect(SPELL_UNSTOPPABLE_ENRAGE,0))
                    TryDoCast(me,SPELL_UNSTOPPABLE_ENRAGE);
            }

            mob_naxxramas_trashAI::UpdateAI(diff);
        }
    };
    // Living Poison - 16027
    struct mob_living_poisonAI : mob_naxxramas_trashAI 
    {
        mob_living_poisonAI(Creature *c) : mob_naxxramas_trashAI(c){}

        void Reset()
        {
            mob_naxxramas_trashAI::Reset();
            //me->SetReactState(REACT_PASSIVE);
        }

        void MoveInLineOfSight(Unit *target)
        {
            if(target->ToPlayer() && me->GetDistance2d(target) <= 3)
                DoCast(me,SPELL_EXPLODE,true);
        }

        void AttackStart(Unit* /*attacker*/)
        {
            return;
        }
        
        void UpdateAI(const uint32 diff)
        {
            return;
        }
    };
    // Deathcharger Steed - 16067
    struct mob_deathcharger_steedAI : mob_naxxramas_trashAI 
    {
        mob_deathcharger_steedAI(Creature *c) : mob_naxxramas_trashAI(c){}

        uint32 uiCharge_Timer;

        void Reset()
        {
            uiCharge_Timer = 1000;

            mob_naxxramas_trashAI::Reset();
        }
        
        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(uiCharge_Timer <= diff)
            {
                if(Unit *target = SelectTarget(SELECT_TARGET_RANDOM,0,40,true))
                    if(TryDoCast(target,SPELL_CHARGE))
                        uiCharge_Timer = 10000;
            }else uiCharge_Timer -= diff;

            mob_naxxramas_trashAI::UpdateAI(diff);
        }
    };
    // Death Knight Captain - 16145
    struct mob_death_knight_captainAI : mob_naxxramas_trashAI 
    {
        mob_death_knight_captainAI(Creature *c) : mob_naxxramas_trashAI(c){}

        uint32 uiStrike_Timer;
        uint32 uiRaiseDeath_Timer;

        void Reset()
        {
            uiStrike_Timer = 1000;
            uiRaiseDeath_Timer = 15000;

            mob_naxxramas_trashAI::Reset();
        }

        void EnterCombat(Unit *who)
        {
            DoCast(SPELL_UNHOLY_PRESENCE);

            mob_naxxramas_trashAI::EnterCombat(who);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(uiStrike_Timer <= diff)
            {
                if(TryDoCast(me->getVictim(),RAID_MODE(SPELL_PLAGUE_STRIKE,SPELL_PLAGUE_STRIKE_H)))
                    uiStrike_Timer = urand(5000,10000);
            }else uiStrike_Timer -= diff;

            if(uiRaiseDeath_Timer <= diff)
            {
                if(TryDoCast(me->getVictim(),RAID_MODE(SPELL_PLAGUE_STRIKE,SPELL_PLAGUE_STRIKE_H)))
                    uiRaiseDeath_Timer = urand(10000,20000);
            }else uiRaiseDeath_Timer -= diff;

            mob_naxxramas_trashAI::UpdateAI(diff);
        }
    };
    // Death Knight - 16146
    struct mob_death_knightAI : mob_naxxramas_trashAI 
    {
        mob_death_knightAI(Creature *c) : mob_naxxramas_trashAI(c){}

        uint32 uiDeathCoil_Timer;
        uint32 uiHysteria_Timer;

        void Reset()
        {
            uiDeathCoil_Timer = 10000;
            uiHysteria_Timer = 5000;

            mob_naxxramas_trashAI::Reset();
        }

        void EnterCombat(Unit *who)
        {
            DoCast(SPELL_BLOOD_PRESENCE);

            mob_naxxramas_trashAI::EnterCombat(who);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(uiDeathCoil_Timer <= diff)
            {
                if(rand()%2 == 0)
                {
                    Unit *target = DoSelectLowestHpFriendly(40);
                    if(!target) target = me;

                    if(TryDoCast(target,SPELL_DEATH_COIL_HEAL))
                        uiDeathCoil_Timer = 10000;
                }else
                {
                    if(Unit *target = SelectTarget(SELECT_TARGET_RANDOM,0,40,true))
                        if(TryDoCast(target,RAID_MODE(SPELL_DEATH_COIL_DAMAGE,SPELL_DEATH_COIL_DAMAGE_H)))
                            uiDeathCoil_Timer = 10000;
                }
            }else uiDeathCoil_Timer -= diff;

            if(uiHysteria_Timer <= diff)
            {
                if(Unit *target = DoSelectLowestHpFriendly(40))
                    if(TryDoCast(target,SPELL_HYSTERIA))
                        uiHysteria_Timer = urand(5000,15000);
            }else uiHysteria_Timer -= diff;

            mob_naxxramas_trashAI::UpdateAI(diff);
        }
    };
    // Risen Squire- 16154
    struct mob_risen_squireAI : mob_naxxramas_trashAI 
    {
        mob_risen_squireAI(Creature *c) : mob_naxxramas_trashAI(c){}

        uint32 uiPieceArmor_Timer;

        void Reset()
        {
            uiPieceArmor_Timer = 3000;

            mob_naxxramas_trashAI::Reset();
        }
        
        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(uiPieceArmor_Timer <= diff)
            {
                if(TryDoCast(me->getVictim(),SPELL_PIERCE_ARMOR))
                    uiPieceArmor_Timer = urand(5000,10000);
            }else uiPieceArmor_Timer -= diff;

            mob_naxxramas_trashAI::UpdateAI(diff);
        }
    };
    // Dark Touched Warrior - 16156
    struct mob_dark_touched_warriorAI : mob_naxxramas_trashAI 
    {
        mob_dark_touched_warriorAI(Creature *c) : mob_naxxramas_trashAI(c){}

        uint32 uiWhirlwind_Timer;

        void Reset()
        {
            uiWhirlwind_Timer = urand(10000,15000);

            mob_naxxramas_trashAI::Reset();
        }
        
        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(uiWhirlwind_Timer <= diff)
            {
                if(TryDoCastAOE(SPELL_NDTW_WHIRLWIND))
                    uiWhirlwind_Timer = urand(15000,20000);
            }else uiWhirlwind_Timer -= diff;

            mob_naxxramas_trashAI::UpdateAI(diff);
        }
    };
    // Death Knight Cavalier - 16163
    struct mob_death_knight_cavalierAI : mob_naxxramas_trashAI 
    {
        mob_death_knight_cavalierAI(Creature *c) : mob_naxxramas_trashAI(c){}

        uint32 uiBoneArmor_Timer;
        uint32 uiIcyTouch_Timer;
        uint32 uiStrangulate_Timer;

        void Reset()
        {
            uiBoneArmor_Timer = urand(30000,60000);
            uiIcyTouch_Timer = 10000;
            uiStrangulate_Timer = 15000;

            mob_naxxramas_trashAI::Reset();
        }

        void JustDied(Unit *victim)
        {
            me->InterruptNonMeleeSpells(false);
            DoCast(me,SPELL_DISMOUNT_DEATHCHARGER,true);

            mob_naxxramas_trashAI::JustDied(victim);
        }
        
        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(uiBoneArmor_Timer <= diff)
            {
                if(TryDoCast(me,RAID_MODE(SPELL_BONE_ARMOR,SPELL_BONE_ARMOR_H)))
                    uiBoneArmor_Timer = urand(20000,40000);
            }else uiBoneArmor_Timer -= diff;

            if(uiIcyTouch_Timer <= diff)
            {
                if(TryDoCast(me->getVictim(),RAID_MODE(SPELL_ICY_TOUCH,SPELL_ICY_TOUCH_H)))
                    uiIcyTouch_Timer = urand(10000,15000);
            }else uiIcyTouch_Timer -= diff;

            if(uiStrangulate_Timer <= diff)
            {
                if(TryDoCast(me->getVictim(),RAID_MODE(SPELL_STRANGUKATE,SPELL_STRANGULATE_H)))
                    uiStrangulate_Timer = urand(10000,15000);
            }else uiStrangulate_Timer -= diff;

            mob_naxxramas_trashAI::UpdateAI(diff);
        }
    };
    // Shade of Naxxramas - 16164
    struct mob_shade_of_naxxramasAI : mob_naxxramas_trashAI 
    {
        mob_shade_of_naxxramasAI(Creature *c) : mob_naxxramas_trashAI(c){}

        uint32 uiVolley_Timer;
        uint32 uiSummonPortal_Timer;

        void Reset()
        {
            uiVolley_Timer = 1000;
            uiSummonPortal_Timer = 1000;

            mob_naxxramas_trashAI::Reset();
        }
        
        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(uiVolley_Timer <= diff)
            {
                if(TryDoCastAOE(RAID_MODE(SPELL_SHADOW_BOLT_VOLLEY,SPELL_SHADOW_BOLT_VOLLEY_H)))
                    uiVolley_Timer = urand(5000,10000);
            }else uiVolley_Timer -= diff;

            if(uiSummonPortal_Timer <= diff)
            {
                if(TryDoCastAOE(SPELL_SUMMON_PORTAL_OF_SHADOWS))
                    uiSummonPortal_Timer = urand(25000,30000);
            }else uiSummonPortal_Timer -= diff;

            mob_naxxramas_trashAI::UpdateAI(diff);
        }
    };
    // Bony Construct - 16167
    struct mob_bony_constructAI : mob_naxxramas_trashAI 
    {
        mob_bony_constructAI(Creature *c) : mob_naxxramas_trashAI(c){}

        uint32 uiBrutalSwipe_Timer;

        void Reset()
        {
            uiBrutalSwipe_Timer = 1000;

            mob_naxxramas_trashAI::Reset();
        }
        
        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(uiBrutalSwipe_Timer <= diff)
            {
                if(TryDoCast(me->getVictim(),RAID_MODE(SPELL_BRUTAL_SWIPE,SPELL_BRUTAL_SWIPE_H)))
                    uiBrutalSwipe_Timer = urand(3000,70000);
            }else uiBrutalSwipe_Timer -= diff;

            mob_naxxramas_trashAI::UpdateAI(diff);
        }
    };
    // Skeletal Smith - 16193
    struct mob_skeletal_smithAI : mob_naxxramas_trashAI 
    {
        mob_skeletal_smithAI(Creature *c) : mob_naxxramas_trashAI(c){}

        uint32 uiDisarm_Timer;
        uint32 uiCrushArmor_Timer;

        void Reset()
        {
            uiDisarm_Timer = urand(5000,7000);
            uiCrushArmor_Timer = 5000;

            mob_naxxramas_trashAI::Reset();
        }
        
        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(uiDisarm_Timer <= diff)
            {
                if(TryDoCast(me->getVictim(),SPELL_DISARM))
                    uiDisarm_Timer = urand(7500,12500);
            }else uiDisarm_Timer -= diff;

            if(uiCrushArmor_Timer <= diff)
            {
                if(TryDoCast(me->getVictim(),SPELL_CRUSH_ARMOR))
                    uiCrushArmor_Timer = urand(5000,10000);
            }else uiCrushArmor_Timer -= diff;

            mob_naxxramas_trashAI::UpdateAI(diff);
        }
    };
    // Unholy Axe - 16194
    struct mob_unholy_axeAI : mob_naxxramas_trashAI 
    {
        mob_unholy_axeAI(Creature *c) : mob_naxxramas_trashAI(c){}

        uint32 uiStrike_Timer;
        uint32 uiWhirlwind_Timer;

        void Reset()
        {
            uiStrike_Timer = urand(5000,7000);
            uiWhirlwind_Timer = 7000;

            mob_naxxramas_trashAI::Reset();
        }
        
        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(uiStrike_Timer <= diff)
            {
                if(TryDoCast(me->getVictim(),SPELL_MORTAL_STRIKE))
                    uiStrike_Timer = urand(2000,5000);
            }else uiStrike_Timer -= diff;

            if(uiWhirlwind_Timer <= diff)
            {
                if(TryDoCast(me,SPELL_NUA_WHIRLWIND))
                    uiWhirlwind_Timer = urand(5000,10000);
            }else uiWhirlwind_Timer -= diff;

            mob_naxxramas_trashAI::UpdateAI(diff);
        }
    };
    // Unholy Staff - 16215
    struct mob_unholy_staffAI : mob_naxxramas_trashAI 
    {
        mob_unholy_staffAI(Creature *c) : mob_naxxramas_trashAI(c){}

        uint32 uiExplosion_Timer;
        uint32 uiNova_Timer;
        uint32 uiPolymorph_Timer;

        void Reset()
        {
            uiExplosion_Timer = urand(5000,7000);
            uiNova_Timer = 12000;
            uiPolymorph_Timer = 5000;

            mob_naxxramas_trashAI::Reset();
        }
        
        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(uiExplosion_Timer <= diff)
            {
                if(TryDoCast(me->getVictim(),RAID_MODE(SPELL_NUS_ARCANE_EXPLOSION,SPELL_NUS_ARCANE_EXPLOSION_H)))
                    uiExplosion_Timer = urand(5000,10000);
            }else uiExplosion_Timer -= diff;

            if(uiNova_Timer <= diff)
            {
                if(TryDoCast(me,SPELL_FROST_NOVA))
                    uiNova_Timer = urand(7000,12000);
            }else uiNova_Timer -= diff;

            if(uiPolymorph_Timer <= diff)
            {
                if(Unit *target = SelectTarget(SELECT_TARGET_RANDOM,0,40,true))
                    if(TryDoCast(me,SPELL_POLYMORPH))
                        uiPolymorph_Timer = 10000;
            }else uiPolymorph_Timer -= diff;

            mob_naxxramas_trashAI::UpdateAI(diff);
        }
    };
    // Unholy Swords - 16216
    struct mob_unholy_swordsAI : mob_naxxramas_trashAI 
    {
        mob_unholy_swordsAI(Creature *c) : mob_naxxramas_trashAI(c){}

        uint32 uiCleave_Timer;
        uint32 uiThrash_Timer;

        void Reset()
        {
            uiCleave_Timer = urand(5000,7000);
            uiThrash_Timer = 1000;

            mob_naxxramas_trashAI::Reset();
        }
        
        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(uiCleave_Timer <= diff)
            {
                if(TryDoCast(me->getVictim(),SPELL_NUS_CLEAVE))
                    uiCleave_Timer = urand(2000,5000);
            }else uiCleave_Timer -= diff;

            if(uiThrash_Timer <= diff)
            {
                if(TryDoCast(me,SPELL_THRASH))
                    uiThrash_Timer = 5000;
            }else uiThrash_Timer -= diff;

            mob_naxxramas_trashAI::UpdateAI(diff);
        }
    };
};

enum NaxxTeleporter
{
    MEAXXNA = 0,
    THADDIUS = 1,
    FOURHORSEMEN = 2,
    LOATHEB = 3,
    SAPPHIRON = 4,
};

#define X_BORDER                3000
#define Y_BORDER                -3430
#define Z_BORDER                150

struct Locations
{
    float x,y,z, o;
};

static Locations TeleportPoint[5]=
{
    {3033.94f, -3462.87f, 298.5f, 5.52f}, // Maexxna
    {3033.94f, -3405.92f, 298.5f, 0.78f}, // Thaddius
    {2977.21f, -3405.92f, 298.5f, 2.35f}, // FourHorsemen
    {2977.21f, -3462.87f, 298.5f, 3.91f}, // Loatheb
    {3033.94f, -3462.87f, 298.5f, 5.52f}
};

class mob_naxxramas_teleporter : public CreatureScript
{
public:
    mob_naxxramas_teleporter() : CreatureScript("mob_naxxramas_teleporter") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_naxxramas_teleporterAI (pCreature);
    }

    struct mob_naxxramas_teleporterAI : public ScriptedAI
    {
        mob_naxxramas_teleporterAI(Creature *c) : ScriptedAI(c)
        {
            if(c->GetMap()->IsDungeon())
                pInstance = c->GetInstanceScript();

            type = GetTeleporterType();
        }

        InstanceScript* pInstance;
        NaxxTeleporter type;
        uint32 uiCheck_Timer;

        void Reset()
        {
            uiCheck_Timer = 10000;
        }

        NaxxTeleporter GetTeleporterType()
        {
            if(me->GetPositionZ() < Z_BORDER)
                return SAPPHIRON;

            if(me->GetPositionX() > X_BORDER)
            {
                if(me->GetPositionY() > Y_BORDER)
                    return THADDIUS;
                else return MEAXXNA;
            }else
            {
                if(me->GetPositionY() > Y_BORDER)
                    return FOURHORSEMEN;
                else
                    return LOATHEB;
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if(uiCheck_Timer <= diff)
            {
                if(pInstance)
                {
                    switch(type)
                    {
                    case MEAXXNA:
                        if( pInstance->GetData(BOSS_MAEXXNA) == DONE)
                            me->SetVisible(true);
                        else me->SetVisible(false);
                        break;
                    case THADDIUS:
                        if( pInstance->GetData(BOSS_THADDIUS) == DONE)
                            me->SetVisible(true);
                        else me->SetVisible(false);
                        break;
                    case FOURHORSEMEN:
                        if( pInstance->GetData(BOSS_HORSEMEN) == DONE)
                            me->SetVisible(true);
                        else me->SetVisible(false);
                        break;
                    case LOATHEB:
                        if( pInstance->GetData(BOSS_LOATHEB) == DONE)
                            me->SetVisible(true);
                        else me->SetVisible(false);
                        break;
                    case SAPPHIRON:
                        if( pInstance->GetData(BOSS_SAPPHIRON) != IN_PROGRESS)
                            me->SetVisible(true);
                        else me->SetVisible(false);
                    default: me->SetVisible(false);
                    }
                }
                uiCheck_Timer = 10000;
            }else uiCheck_Timer -= diff;

        }
    };

    bool OnGossipHello(Player *pPlayer, Creature *pCreature)
    {
        pPlayer->ADD_GOSSIP_ITEM(0,"Bringe mich zurueck zum Eingang",GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF+1);

        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->CLOSE_GOSSIP_MENU();

        if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
        {
            if(pCreature && pCreature->AI())
            {
                NaxxTeleporter type = CAST_AI(mob_naxxramas_teleporterAI,pCreature->AI())->type;
                pPlayer->NearTeleportTo(TeleportPoint[type].x,TeleportPoint[type].y,TeleportPoint[type].z,TeleportPoint[type].o);
            }
        }

        return true;
    }
};

void AddSC_mob_naxxramas_trash()
{
    new mob_naxxramas_trash();
    new mob_naxxramas_teleporter();
}