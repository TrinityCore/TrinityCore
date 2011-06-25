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
SDName: Black_Temple
SD%Complete: 95
SDComment: Spirit of Olum: Player Teleporter to Seer Kanai Teleport after defeating Naj'entus and Supremus. TODO: Find proper gossip.
SDCategory: Black Temple
EndScriptData */

/* ContentData
npc_spirit_of_olum
EndContentData */

#include "ScriptPCH.h"
#include "black_temple.h"

/*###
# npc_spirit_of_olum
####*/

#define SPELL_TELEPORT      41566                           // s41566 - Teleport to Ashtongue NPC's
#define GOSSIP_OLUM1        "Teleport me to the other Ashtongue Deathsworn"

class npc_spirit_of_olum : public CreatureScript
{
public:
    npc_spirit_of_olum() : CreatureScript("npc_spirit_of_olum") { }

    bool OnGossipHello (Player* player, Creature* _Creature)
    {
        InstanceScript* pInstance = _Creature->GetInstanceScript();

        if(pInstance && (pInstance->GetData(DATA_SUPREMUSEVENT) >= DONE) && (pInstance->GetData(DATA_HIGHWARLORDNAJENTUSEVENT) >= DONE))
            player->ADD_GOSSIP_ITEM(0, GOSSIP_OLUM1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(_Creature), _Creature->GetGUID());
        return true;
    }

    bool OnGossipSelect (Player* player, Creature* _Creature, uint32 sender, uint32 action)
    {
        if(action == GOSSIP_ACTION_INFO_DEF + 1)
            player->CLOSE_GOSSIP_MENU();

        player->InterruptNonMeleeSpells(false);
        player->CastSpell(player, SPELL_TELEPORT, false);
        return true;
    }
};


/*#############
# Trash Mobs
###############*/

struct  mob_black_temple_tashAI : public ScriptedAI
{
    mob_black_temple_tashAI(Creature *c) : ScriptedAI(c){}

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
            Trinity::CreatureListSearcher<Trinity::AllFriendlyCreaturesInGrid> searcher(me,templist, check);

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

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim() )
            return;

        if(AreaInCombat_Timer <= diff)
        {
            DoAttackerAreaInCombat(me->getVictim(), 100);
            AreaInCombat_Timer = 5000;
        }else AreaInCombat_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

#define ASH_FACTION_FRIENDLY            1820
#define ASH_FACTION_UNFRIENDLY          1813

struct  mob_black_temple_ashtongueAI : public mob_black_temple_tashAI
{
    mob_black_temple_ashtongueAI(Creature *c) : mob_black_temple_tashAI(c)
    {
        pInstance = c->GetInstanceScript();
    }

    InstanceScript *pInstance;
    uint32 friendlyCheck_Timer;

    void Reset()
    {
        friendlyCheck_Timer = 5000;
        if(AkamasShemenEventFinished())
        {
            if(me->getFaction() != ASH_FACTION_FRIENDLY)
                me->setFaction(ASH_FACTION_FRIENDLY);
            
        }else
        {
            if(me->getFaction() != ASH_FACTION_UNFRIENDLY)
                me->setFaction(ASH_FACTION_UNFRIENDLY);
        }

        mob_black_temple_tashAI::Reset();
    }

    bool AkamasShemenEventFinished()
    {
        if(pInstance)
           return (pInstance->GetData(DATA_SHADEOFAKAMAEVENT) == DONE);
        return false;
    }

    void CheckAkamaEvent(const uint32 diff)
    {
        if(me->getFaction() != ASH_FACTION_FRIENDLY)
        {
            if(friendlyCheck_Timer)
            {
                if(AkamasShemenEventFinished())
                {
                    me->setFaction(ASH_FACTION_FRIENDLY);

                    if(me->isInCombat())
                        me->AI()->EnterEvadeMode();
                }
                friendlyCheck_Timer = 5000;
            }else friendlyCheck_Timer -=diff;
        }
    }
};

#define SPELL_CRASHING_WAVE                     40100
#define SPELL_VILE_SLIME                        40099
#define ENTRY_AQUEOUS_SPAWN                     22883

#define SPELL_SLUDGE_NOVA                       40102
#define SPELL_MERGE                             40106

#define ENTRY_AQUEOUS_LORD                      22878

#define SPELL_FREE_FRIEND                       40081
#define SPELL_BOOMING_VOICE                     40080

#define SPELL_CLEAVE                            15284
#define SPELL_LIGHTNING_PROD                    40066

#define SPELL_ELECTRIC_SPUR                     40076
#define ENTRY_LEVIATHAN                         22884

#define SPELL_TAIL_SWEEP                        40077
#define SPELL_POISON_SPIT                       40078
#define SPELL_DEBILITATIN_SPRAY                 40079

#define SPELL_FORKED_LIGHTNING                  40088
#define SPELL_HURRICANE                         40090
#define SPELL_SUMMON_GEYSER                     40091

#define SPELL_GEYSER_DAMAGE                     40089

#define SPELL_HOLY_NOVA                         40096
#define SPELL_RESTORATION                       40097

#define SPELL_SHELL_SHIELD                      40087
#define SPELL_WATER_SPIT                        40086
#define SPELL_HARPOONERS_MARK                   40084

#define SPELL_HOOKED_NET                        40082
#define SPELL_SPEAR_THROW                       40083

#define SPELL_DISGRUNTLED                       40851
#define SPELL_FURY                              40845

#define SPELL_THROW_PICK                        40844
#define ENTRY_TASKMASTER                        23028

#define SPELL_SKY_STALKER_SHOOT                 40873
#define SPELL_IMMOLATION_ARROW                  40872

#define SPELL_DOOMBOLT                          40876
#define SPELL_WIND_REAVER_FIREBOLT              40877
#define SPELL_FREEZE                            40875

#define SPELL_FIXATE                            40892
#define SPELL_CLEAVE                            15284
#define SPELL_JAB                               40895

#define SPELL_ILLIDARI_FLAMES                   40938
#define SPELL_ILLIDARI_FLAMES_TRIGGER           40939
#define SPELL_RAIN_OF_CHAOS                     40946
#define SPELL_RAIN_OF_CHAOS_TRIGGER             40948
#define SPELL_WAR_STOMP                         40936

#define SPELL_ILLI_CURSE_OF_MENDING             39647
#define SPELL_ILLI_FEAR                         41150
#define SPELL_ILLI_SHADOW_INFERNO               39645
#define SPELL_ILLI_SHADOW_INFERNO_DMG           39646
#define SPELL_ILLI_SUMMON_SHADOWFIEND_OPTIC     39649
#define SPELL_ILLI_SUMMON_SHADOWFIEND_EFFEKT    41159

#define SPELL_CLOAK_OF_SHADOW                   39666
#define SPELL_ILLI_GOUGE                        24698
#define SPELL_SHADOWSTEP                        41176

//#define SPELL_CLEAVE                            15284
#define SPELL_CONCUSSION_BLOW                   32588
#define SPELL_CONCUSSIVE_THROW                  41182
#define SPELL_FRENZY                            34970

#define SPELL_CHARGE_RAGE                       39575
#define SPELL_SPIRIT_BOND                       39578

#define ENTRY_ASHTONGUE_PRIMALIST               22847

#define SPELL_PRIMALIST_SHOOT                   41188
#define SPELL_MULTI_SHOOT                       41187
#define SPELL_WYVERN_STING                      41186
#define SPELL_SWEEPING_WING_CLIP                39584

#define SPELL_SUMMON_FERAL_SPIRIT               39535
#define ENTRY_FERAL_SPIRIT                      22849

#define SPELL_BLOODLUST                         41185
#define SPELL_CHAIN_HEAL                        41114
#define SPELL_FLAME_SHOCK                       41115
#define SPELL_FROST_SHOCK                       41116

#define SPELL_CYCLONE_TOTEM                     39589
#define SPELL_SEARING_TOTEM                     39588
#define SPELL_WINDFURY_TOTEM                    39586

#define ENTRY_CYCLONE_TOTEM                     22894
#define ENTRY_SEARING_TOTEM                     22896
#define ENTRY_WINDFURY_TOTEM                    22897

#define SPELL_CYCLONE_TOTEM_EFFEKT              39594 // Max Targets need improfments

#define SPELL_SEARING_TOTEM_ATTACK              39593

#define SPELL_STEALTH                           34189
#define SPELL_BLIND                             34654
#define SPELL_MINDNUMBING_POISON                41190
#define SPELL_INSTANT_POISON                    41189

#define SPELL_LIGHTNING_BOLT                    41184
#define SPELL_CHAIN_LIGHTNING                   41183
#define SPELL_LIGHTNING_SHIELD                  41151

#define SPELL_SUMMON_STORM_FURY                 39534
#define ENTRY_STORM_FURY                        22848

#define SPELL_STORM_BLINK_OPTICAL               39581
#define SPELL_STORM_BLINK_DAMAGE                39582

//#define SPELL_CLEAVE                            15284
#define SPELL_SONIC_STRIKE                      41168

#define SPELL_BANISH                            39674
#define SPELL_CURSE_OF_AGONY                    39672
#define SPELL_FEL_IMMOLATE                      39670
#define SPELL_RAIN_OF_CHAOS_ILLIDARI_DEFILER    39671

#define SPELL_SKELETON_SHOT                     41171
#define SPELL_SUMMON_SKELETON                   41174
#define SPELL_RAPID_SHOT                        41173
#define SPELL_CURSE_OF_THE_BLEAKHEART           41170
#define SPELL_CURSE_OF_THE_BLEAKHEART_PROC      41356
#define SPELL_ILLIDARI_HEARTSEEKER_SHOT         41169

#define SPELL_DEMENTIA                          41404
#define SPELL_CONFUSION                         41397

#define ENTRY_IMAGE_OF_DEMENTIA                 23436

#define SPELL_DEMENTIA_WHIRLWIND                41399

#define SPELL_CURSE_OF_VITALITY                 41351

#define ENTRY_SISTER_OF_PAIN                    22956
#define ENTRY_SISTER_OF_PLEASURE                22964

#define SPELL_SHARED_BONDS_SCRIPT               41362
#define SPELL_SHARED_BONDS_EFFEKT               41363

//Pain
#define SPELL_LASH_OF_PAIN                      41353
#define SPELL_PAINFULL_RAGE                     41369
#define SPELL_SIS_SHADOWWORD_PAIN               41355
#define SPELL_SHELL_OF_PAIN                     41371

//Pleasure
#define SPELL_SIS_GREATER_HEAL                  41378
#define SPELL_SIS_HOLY_NOVA                     41380
#define SPELL_SHELL_OF_LIFE                     41381

#define SPELL_LOVE_TRAP                         41338
#define SPELL_CONC_POLYMORPH                    41334

#define SPELL_INFATUATION                       41345
#define SPELL_COURT_POISONOUS_THROW             41346

#define SPELL_KIDNEY_SHOT                       41389
#define SPELL_UPPERCUT                          41388

#define SPELL_ATTENDANT_KICK                    41395
#define SPELL_ATTENDANT_SLEEP                   41396

#define SPELL_SOUL_BLAST                        41245

#define SPELL_SOUL_ANGER                        41986

#define SPELL_CONSUMING_STRIKES                 41248

#define SPELL_ILLI_BLIZZARD                     41382
#define SPELL_ILLI_FIREBALL                     41383
#define SPELL_ILLI_FLAMESTRIKE                  41379
#define SPELL_ILLI_FROSTBOLT                    41384
    
#define SPELL_ILLI_DIVINE_SHIELD                41367
#define SPELL_ILLI_HAMMER_OF_JUSTICE            13005
#define SPELL_ILLI_JUDGEMENT                    41368

#define SPELL_ILLI_VANISH                       39667
#define SPELL_ILLI_PARALYZING_POISON            3609

#define SPELL_ILLI_HEAL                         41372
#define SPELL_ILLI_HOLY_SMITE                   41370
#define SPELL_ILLI_SHIELD                       41373

#define SPELL_ILLI_SHADOW_FORM                  29406
#define SPELL_ILLI_MIND_BLAST                   41374
#define SPELL_ILLI_SHADOWWORD_DEATH             41375

#define SPELL_L1_ARCANE_CHARGE                  41357
#define SPELL_L4_ARCANE_CHARGE                  41348
#define SPELL_L4_ARCANE_CHARGE_DMG              41349
#define SPELL_L5_ARCANE_CHARGE                  41360

#define SPELL_HAND_ENRAGE                       38166

#define SPELL_BLOOD_BOLT_SCRIPT                 41072
#define SPELL_BLOOD_BOLT_EFFECT                 41065 // Need Core Support
#define SPELL_BLOOD_SIPHON                      41068

#define SPELL_SOLDIER_STRIKE                    11976

#define SPELL_ABSORPTION                        41034 // Doesnt Trigger yet
#define SPELL_CHAOTIC_CHARGE                    41033
#define SPELL_CHAOTIC_CHARGE_DMG                41039 // Damage must be equal charges

#define SPELL_SM_DEATH_COIL                     41070
#define SPELL_SM_DEMON_ARMOR                    13787
#define SPELL_SM_SHADOW_BOLT                    41069
#define SPELL_SM_RAISE_DEATH                    41071 // Don't use
#define SPELL_SM_SUMMON_SKELETON                41074
#define ENTRY_SHADOWMOON_FALLEN                 23371

#define SPELL_SM_WHIRLING_WEAPON                41053
#define SPELL_SM_CHAOTIC_LIGHT                  41063

#define SPELL_WHIRLING                          41056

#define SPELL_SMHM_FREEZING_TRAP                41085
#define SPELL_SMHM_SHOOT                        41093
#define SPELL_SMHM_SILENCING_SHOT               41084
#define SPELL_SMHM_RIDING_HOUND                 39906
#define SPELL_SMHM_VOLLEY                       41091
#define SPELL_SMHM_WING_CLIP                    32908
#define ENTRY_SHADOWMOON_RIDING_HOUND           23083

#define SPELL_SMRH_CHARGE                       25821
#define SPELL_SMRH_CARNIVOROUS_BITE             41092
#define SPELL_SMRH_ENRAGE                       8599

#define SPELL_WB_IGNORED                        39544
#define SPELL_WB_CLEAVE                         15496

// Berserker Stance
#define SPELL_SMWM_BERSERKER_STANCE             41100
#define SPELL_SMWM_BERSERKER_AURA               41107
#define SPELL_SMWM_WHIRLWIND                    41097
#define SPELL_SMWM_MULTILATE                    41103
// Battle Stance
#define SPELL_SMWM_BATTLE_STANCE                41099
#define SPELL_SMWM_BATTLE_AURA                  41106
#define SPELL_SMWM_KNOCK_AWAY                   18813
// Devensive Stance
#define SPELL_SMWM_DEFENSIVE_STANCE             41101
#define SPELL_SMWM_DEFENSIVE_AURA               41105
#define SPELL_SMWM_SHIELD_WALL                  41104

enum Warrior_Stance
{
    BATTLE_STANCE = 0,
    BERSERKER_STANCE = 1,
    DEFENSIVE_STANCE = 2
};

#define SPELL_BEHEMOTH_CHARGE                   41272
#define SPELL_BEHEMOTH_FEL_STOMP                41274
#define SPELL_BEHEMOTH_FIERY_COMET              41277
#define SPELL_BEHEMOTH_METEOR                   41276
#define SPELL_BEHEMOTH_FRENZY                   8269

#define SPELL_INTERVENE                         41198
#define SPELL_BCSD_SHIELD_BASH                  41197
#define SPELL_BCSD_SHIELD_WALL                  41196
#define SPELL_BCSD_SHIELD_THROW                 41213

#define SPELL_BCBF_WHIRLWIND                    41194

#define SPELL_BCBP_BLOOD_DRAIN                  41238
#define SPELL_BCBP_BLOOD_BOLT                   41229
#define SPELL_BCBP_PROPHECY_BLOOD_1             41230
#define SPELL_BCBP_PROPHECY_BLOOD_2             41231
#define SPELL_BCBP_FRENZY                       8269

#define SPELL_CLOUD_OF_DISEASE                  41193
#define SPELL_DISEASE_CLOUD                     41290

#define SPELL_BCB_ENRAGE                        41254
#define SPELL_BCB_FRENZY                        8269

#define SPELL_BCC_ENRAGE                        41251
#define SPELL_BCC_FRENZY                        8269

#define SPELL_BCSP_CHARGE                       36140
#define SPELL_BCSP_CLEAVE                       40505
#define SPELL_BCSP_FRENZY                       8269
#define SPELL_BCSP_MORTAL_WOUND                 25646
#define SPELL_BCSP_STRIKE                       13446
#define SPELL_BCSP_SUNDER_ARMOR                 13444

class npc_black_temple : public CreatureScript
{
public:
    npc_black_temple() : CreatureScript("npc_black_temple") { }

    CreatureAI* GetAI(Creature *_Creature) const
    {
        switch(_Creature->GetEntry())
        {
        case 22878: return new mob_aqueous_lordAI (_Creature);
        case 22883: return new mob_aqueous_spawnAI (_Creature);
        case 22873: return new mob_coilskar_generalAI (_Creature);
        case 22877: return new mob_coilskar_wranglerAI (_Creature);
        case 22884: return new mob_leviathanAI (_Creature);
        case 22875: return new mob_coilskar_sea_callerAI (_Creature);
        case 23080: return new mob_coilskar_geyserAI (_Creature);
        case 22876: return new mob_coilskar_soothsayerAI (_Creature);
        case 22885: return new mob_dragon_turtleAI (_Creature);
        case 22874: return new mob_coilskar_harpoonerAI (_Creature);
        case 23028: return new mob_bonechewer_taskmasterAI (_Creature);
        case 22963: return new mob_bonechewer_workerAI (_Creature);
        case 23030: return new mob_dragonmaw_sky_stalkerAI (_Creature);
        case 23330: return new mob_dragonmaw_wind_reaverAI (_Creature);
        case 22960: return new mob_dragonmaw_wyrmcallerAI (_Creature);
        case 22954: return new mob_illidari_fearbringerAI (_Creature);
        case 22855: return new mob_illidari_nightlordAI (_Creature);
        case 22844: return new mob_ashtongue_battlelordAI (_Creature);
        case 22849: return new mob_ashtongue_feral_spiritAI (_Creature);
        case 22847: return new mob_ashtongue_primalistAI (_Creature);
        case 22845: return new mob_ashtongue_mysticAI (_Creature);
        case 22896: return new mob_ashtongue_searing_totemAI (_Creature);
        case 22894: return new mob_ashtongue_cyclone_totemAI (_Creature);
        case 23374: return new mob_ashtongue_stalkerAI (_Creature);
        case 22846: return new mob_ashtongue_stormcallerAI (_Creature);
        case 22848: return new mob_storm_furyAI (_Creature);
        case 23337: return new mob_illidari_centurionAI (_Creature);
        case 22853: return new mob_illidari_defilerAI (_Creature);
        case 23339: return new mob_illidari_heartseekerAI (_Creature);
        case 22869: return new mob_illidari_boneslicerAI (_Creature);
        case 22957: return new mob_priestess_of_dementiaAI (_Creature);
        case 22962: return new mob_priestess_of_delightAI (_Creature);
        case 22956: return new mob_sister_of_painAI (_Creature);
        case 22964: return new mob_sister_of_pleasureAI (_Creature);
        case 22955: return new mob_charming_courtesanAI (_Creature);
        case 22939: return new mob_temple_concubineAI (_Creature);
        case 22965: return new mob_enslaved_servantAI (_Creature);
        case 22959: return new mob_spellbound_attendantAI (_Creature);
        case 23399: return new mob_suffering_soul_fragmentAI (_Creature);
        case 23398: return new mob_angered_soul_fragmentAI (_Creature);
        case 23401: return new mob_hungering_soul_fragmentAI (_Creature);
        case 23402: return new mob_illidari_battlemageAI (_Creature);
        case 23397: return new mob_illidari_blood_lordAI (_Creature);
        case 23403: return new mob_illidari_assassinAI (_Creature);
        case 23400: return new mob_illidari_archonAI (_Creature);
        case 23394: return new mob_promenade_sentinelAI (_Creature);
        case 23429: return new mob_arcane_charge_L4AI (_Creature);
        case 23172: return new mob_hand_of_gorefiendAI (_Creature);
        case 22945: return new mob_shadowmoon_blood_mageAI (_Creature);
        case 23047: return new mob_shadowmoon_soldierAI (_Creature);
        case 22879: return new mob_shadowmoon_reaverAI (_Creature);
        case 22882: return new mob_shadowmoon_deathshaperAI (_Creature);

        case 22880: return new mob_shadowmoon_championAI (_Creature);
        case 23369: return new mob_whirling_bladeAI (_Creature);
        case 23018: return new mob_shadowmoon_houndmasterAI (_Creature);
        case 23083: return new mob_shadowmoon_riding_houndAI (_Creature);
        case 22953: return new mob_wrathbone_flayerAI (_Creature);
        case 23049: return new mob_shadowmoon_weapon_masterAI (_Creature);
        case 23196: return new mob_bonechewer_behemothAI (_Creature);
        case 23236: return new mob_bonechewer_shield_discipleAI (_Creature);
        case 23235: return new mob_bonechewer_blade_furyAI (_Creature);
        case 23237: return new mob_bonechewer_blood_prophetAI (_Creature);
        case 23232: return new mob_mutant_war_houndAI (_Creature);
        case 23222: return new mob_bonechewer_brawlerAI (_Creature);
        case 23239: return new mob_bonechewer_combatantAI (_Creature);
        case 23223: return new mob_bonechewer_spectatorAI (_Creature);
        default: return new mob_aqueous_lordAI (_Creature);
        }
    }

    struct  mob_aqueous_lordAI : public mob_black_temple_tashAI
    {
        mob_aqueous_lordAI(Creature *c) : mob_black_temple_tashAI(c){}


        uint32 wave_Timer;
        uint32 slime_Timer;
        uint32 spawn_Timer;

        void Reset()
        {
            wave_Timer = 15000;
            slime_Timer = 7000;
            spawn_Timer = 20000;

            mob_black_temple_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(wave_Timer < diff)
            {
                DoCast(me,SPELL_CRASHING_WAVE);
                wave_Timer = rand()%5000+15000;
            }else wave_Timer -= diff;

            if(slime_Timer < diff)
            {
                DoCast(me->getVictim(),SPELL_VILE_SLIME);
                slime_Timer = rand()%5000+25000;
            }else slime_Timer -= diff;

            if(spawn_Timer < diff)
            {
            
                Creature* temp;

                for(int i = 0; i<2 ; i++)
                {
                    temp = DoSpawnCreature(ENTRY_AQUEOUS_SPAWN,0,0,0,0,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,60000);
                    if(temp)
                        temp->AI()->AttackStart(me->getVictim());
                }
                spawn_Timer = 20000;
            }else spawn_Timer -= diff;

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_aqueous_spawnAI : public mob_black_temple_tashAI
    {
        mob_aqueous_spawnAI(Creature *c) : mob_black_temple_tashAI(c){}

        uint32 nova_Timer;
        uint32 merge_Timer;
        uint64 lord_guid;

        void MoveInLineOfSight(Unit *who)
        {
            if(!me->HasAura(SPELL_MERGE,0))
                mob_black_temple_tashAI::MoveInLineOfSight(who);
        }

        void AttackStart(Unit *who)
        {
            if(!me->HasAura(SPELL_MERGE,0))
                mob_black_temple_tashAI::AttackStart(who);
        }

        void Reset()
        {
            nova_Timer = 5000 + rand()%20000;
            merge_Timer = rand()%50000;
            lord_guid = 0;

            mob_black_temple_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if(me->HasAura(SPELL_MERGE,0))
            {
                if(me->GetUInt64Value(UNIT_FIELD_TARGET) != lord_guid )
                    me->SetUInt64Value(UNIT_FIELD_TARGET, lord_guid);
                return;
            }

            if (!UpdateVictim() )
                return;

            if(nova_Timer < diff)
            {
                DoCast(me,SPELL_SLUDGE_NOVA);
                nova_Timer = rand()%10000+10000;
            }else nova_Timer -= diff;

            if(merge_Timer < diff)
            {
                Creature* lord = FindNearestCreature(ENTRY_AQUEOUS_LORD,30);
                if(lord)
                {
                    if(rand()%2 == 0)
                    {
                        me->SetUInt64Value(UNIT_FIELD_TARGET, lord->GetGUID());
                        lord_guid = lord->GetGUID();
                        me->CastSpell(me,SPELL_MERGE,true);
                    }
                    //DoCast(spawn,SPELL_MERGE,true);
                }
                merge_Timer = rand()%20000 + 10000;

            }else merge_Timer -= diff;


            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_coilskar_generalAI : public mob_black_temple_tashAI
    {
        mob_coilskar_generalAI(Creature *c) : mob_black_temple_tashAI(c){}

        uint32 free_Timer;
        uint32 booming_Timer;

        void Reset()
        {
            free_Timer = 10000;
            booming_Timer = 0;

            mob_black_temple_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(free_Timer < diff)
            {
                DoCast(me,SPELL_FREE_FRIEND);
                free_Timer = rand()%10000+10000;
                booming_Timer = 1000;
            }else free_Timer -= diff;

            if(booming_Timer)
            {
                if(booming_Timer < diff)
                {
                    DoCast(me,SPELL_BOOMING_VOICE);
                    booming_Timer = 0;
                }else booming_Timer -= diff;
            }

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_coilskar_wranglerAI : public mob_black_temple_tashAI
    {
        mob_coilskar_wranglerAI(Creature *c) : mob_black_temple_tashAI(c){}

        uint32 cleave_Timer;
        uint32 lightning_Timer;
        uint32 spur_Timer;

        void Reset()
        {
            cleave_Timer = 10000;
            lightning_Timer = 10000 + rand()%5000;
            spur_Timer = 20000;

            mob_black_temple_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(cleave_Timer < diff)
            {
                DoCast(me->getVictim(),SPELL_CLEAVE);
                cleave_Timer = 5000+rand()%10000;
            }else cleave_Timer -= diff;


            if(lightning_Timer < diff)
            {
                DoCast(me->getVictim(),SPELL_LIGHTNING_PROD);
                lightning_Timer = 15000+rand()%10000;
            }else lightning_Timer -= diff;

            if(spur_Timer < diff)
            {
                Creature* levia = FindNearestCreature(ENTRY_LEVIATHAN,30);
                if(levia && !levia->HasAura(SPELL_ELECTRIC_SPUR,0))
                    DoCast(levia,SPELL_ELECTRIC_SPUR);

                spur_Timer = 30000;
            }else spur_Timer -= diff;

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_leviathanAI : public mob_black_temple_tashAI
    {
        mob_leviathanAI(Creature *c) : mob_black_temple_tashAI(c){}

        uint32 spray_Timer;
        uint32 spit_Timer;
        uint32 tail_Timer;

        void Reset()
        {
            spray_Timer = 15000;
            spit_Timer = 5000;
            tail_Timer = 5000;

            mob_black_temple_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(tail_Timer < diff)
            {
                DoCast(me,SPELL_TAIL_SWEEP,true);
                tail_Timer = 5000;
            }else tail_Timer -= diff;

            if(spray_Timer < diff)
            {
                DoCast(me->getVictim(),SPELL_DEBILITATIN_SPRAY);
                spray_Timer =  5000+rand()%125000;
            }else spray_Timer -= diff;

            if(spit_Timer < diff)
            {
                DoCast(me->getVictim(),SPELL_POISON_SPIT);
                spit_Timer = 5000+rand()%12500;
            }else spit_Timer -= diff;

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_coilskar_sea_callerAI : public mob_black_temple_tashAI
    {
        mob_coilskar_sea_callerAI(Creature *c) : mob_black_temple_tashAI(c){}

        uint32 lightning_Timer;
        uint32 hurricane_Timer;
        uint32 geyser_Timer;

        void Reset()
        {
            lightning_Timer = 10000+rand()%10000;
            geyser_Timer = 10000+rand()%10000;
            hurricane_Timer = 20000+rand()%10000;

            mob_black_temple_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(lightning_Timer < diff)
            {
                DoCast(me->getVictim(),SPELL_FORKED_LIGHTNING);
                lightning_Timer =  5000+rand()%10000;
            }else lightning_Timer -= diff;

            if(hurricane_Timer < diff)
            {
                Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 1);
                if(ptarget)
                {
                    DoCast(ptarget,SPELL_HURRICANE);
                    hurricane_Timer =  20000+rand()%10000;
                }else hurricane_Timer = 4000;
            }else hurricane_Timer -= diff;

            if(geyser_Timer < diff)
            {

                    DoCast(me,SPELL_SUMMON_GEYSER);
                    geyser_Timer = 10000+rand()%10000;
            
            }else geyser_Timer -= diff;

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_coilskar_geyserAI : public ScriptedAI
    {
        mob_coilskar_geyserAI(Creature *c) : ScriptedAI(c){}

        uint32 geyser_Timer;

        void MoveInLineOfSight(Unit *who){}
        void AttackStart(Unit *who){}
        void Reset(){ geyser_Timer = 500; }
        void EnterCombat(Unit *who){}
        void UpdateAI(const uint32 diff)
        {
            if(geyser_Timer < diff)
            {
                DoCast(me,SPELL_GEYSER_DAMAGE);
                geyser_Timer = 50000;
            }else geyser_Timer -= diff;
        }
    };

    struct  mob_coilskar_soothsayerAI : public mob_black_temple_tashAI
    {
        mob_coilskar_soothsayerAI(Creature *c) : mob_black_temple_tashAI(c){}

        uint32 nova_Timer;
        uint32 resto_Timer;

        void Reset()
        {
            nova_Timer = 10000+rand()%10000;
            resto_Timer = 10000+rand()%10000;

            mob_black_temple_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(nova_Timer < diff)
            {
                DoCast(me,SPELL_HOLY_NOVA);
                nova_Timer =  10000+rand()%10000;
            }else nova_Timer -= diff;

            if(resto_Timer < diff)
            {
                Unit* target = DoSelectLowestHpFriendly(40);
                if(!target)
                    target = me;

                bool hasCast = false;

                if(!target->HasAura(SPELL_RESTORATION,0))
                {

                    DoCast(target,SPELL_RESTORATION);
                    resto_Timer =  10000+rand()%5000;
                }else
                    resto_Timer =  1000+rand()%5000;

            }else resto_Timer -= diff;

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_dragon_turtleAI : public mob_black_temple_tashAI
    {
        mob_dragon_turtleAI(Creature *c) : mob_black_temple_tashAI(c){}

        uint32 shield_Timer;
        uint32 spit_Timer;
        uint32 check_Timer;

        uint64 MarkTarget;

        void Reset()
        {
            shield_Timer = 5000;
            spit_Timer = 10000+rand()%10000;
            MarkTarget = 0;
            check_Timer = 5000;

            mob_black_temple_tashAI::Reset();
        }

        void CheckForMark()
        {
            if(MarkTarget == 0)
            {
                Map *map = me->GetMap();
                if(map->IsDungeon())
                {
                    Map::PlayerList const &PlayerList = map->GetPlayers();
                    for(Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                    {
                        if (Player* i_pl = i->getSource())
                            if (i_pl->isAlive())
                            {
                                if(me->HasAura(SPELL_HARPOONERS_MARK,0))
                                {
                                    MarkTarget = me->GetGUID();
                                }
                            }
                    }
                }
            }

            if(MarkTarget != 0)
            {
                Player* target = Unit::GetPlayer(*me,MarkTarget);
                if(target)
                {
                    if(target->HasAura(SPELL_HARPOONERS_MARK,0))
                    {
                        me->SetInCombatWith(target);
                        target->SetInCombatWith(me);
                        me->AddThreat(target, 50000.0f);
                    }else
                    {
                        MarkTarget = 0;
                        DoModifyThreatPercent(target,0);
                    }
                }
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(spit_Timer < diff)
            {
                DoCast(me->getVictim(),SPELL_WATER_SPIT);
                spit_Timer =  10000+rand()%10000;
            }else spit_Timer -= diff;

            if( ((me->GetHealth()*100) / me->GetMaxHealth()) < 50 )
            {
                if(shield_Timer < diff)
                {
                    DoCast(me,SPELL_SHELL_SHIELD);
                    shield_Timer = 20000+rand()%10000;
                }else shield_Timer -= diff;
            }

            if(check_Timer < diff)
            {
                CheckForMark();
                check_Timer = 5000;
            }else check_Timer -= diff;

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_coilskar_harpoonerAI : public mob_black_temple_tashAI
    {
        mob_coilskar_harpoonerAI(Creature *c) : mob_black_temple_tashAI(c){}

        uint32 shoot_Timer;
        uint32 net_Timer;
        uint32 check_Timer;

        bool MarkSet;
        uint64 MarkTarget;

        void Reset()
        {
            shoot_Timer = 2500;
            net_Timer = 10000+rand()%10000;
            MarkSet = false;
            check_Timer = 5000;

            mob_black_temple_tashAI::Reset();
        }

        void AttackStart(Unit* who)
        {
            ScriptedAI::AttackStartNoMove(who);
        }

        void CheckForMark()
        {
            if(MarkTarget == 0)
            {
                Map *map = me->GetMap();
                if(map->IsDungeon())
                {
                    Map::PlayerList const &PlayerList = map->GetPlayers();
                    for(Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                    {
                        if (Player* i_pl = i->getSource())
                            if (i_pl->isAlive())
                            {
                                if(me->HasAura(SPELL_HARPOONERS_MARK,0))
                                {
                                    MarkTarget = me->GetGUID();
                                }
                            }
                    }
                }
            }

            if(MarkTarget != 0)
            {
                Player* target = Unit::GetPlayer(*me,MarkTarget);
                if(target)
                {
                    if(target->HasAura(SPELL_HARPOONERS_MARK,0))
                    {
                        me->SetInCombatWith(target);
                        target->SetInCombatWith(me);
                        me->AddThreat(target, 50000.0f);
                    }else
                    {
                        MarkTarget = 0;
                        DoModifyThreatPercent(target,0);
                    }
                }
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(net_Timer < diff)
            {
                if(me->IsWithinMeleeRange(me->getVictim()))
                    DoCast(me->getVictim(),SPELL_HOOKED_NET);
                net_Timer =  10000+rand()%10000;
            }else net_Timer -= diff;

            if(!MarkSet)
                if( ((me->GetHealth()*100) / me->GetMaxHealth()) < 50 )
                {
                    Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                    if(ptarget)
                    {
                        MarkSet = true;
                        DoCast(ptarget,SPELL_HARPOONERS_MARK);
                    }
                }

            if(check_Timer < diff)
            {
                CheckForMark();
                check_Timer = 5000;
            }else check_Timer -= diff;

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

                if(shoot_Timer < diff)
                {
                    DoCast(me->getVictim(),SPELL_SPEAR_THROW);
                    shoot_Timer = 2500;
                }else shoot_Timer -= diff;
            }
        }
    };

    struct  mob_bonechewer_taskmasterAI : public mob_black_temple_tashAI
    {
        mob_bonechewer_taskmasterAI(Creature *c) : mob_black_temple_tashAI(c){}

        void EnterCombat(Unit* who){ DoCast(me,SPELL_DISGRUNTLED); }
        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };


    struct  mob_bonechewer_workerAI : public mob_black_temple_tashAI
    {
        mob_bonechewer_workerAI(Creature *c) : mob_black_temple_tashAI(c){}

        uint32 throw_Timer;

        void Reset()
        {
            throw_Timer = 1000 + rand()%15000;

            mob_black_temple_tashAI::Reset();
        }

        void JustDied(Unit *killer)
        {
            Creature* taskmaster = FindNearestCreature(ENTRY_TASKMASTER,40);
            if(taskmaster)
                taskmaster->CastSpell(taskmaster,SPELL_FURY,false);
        }

        void SpellHit(Unit* caster, const SpellEntry* spell)
        {
            if(spell->Id == SPELL_DISGRUNTLED)
                me->SetHealth(me->GetMaxHealth());
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(throw_Timer < diff)
            {
                DoCast(me->getVictim(),SPELL_THROW_PICK);
                throw_Timer = 9999999;
            }else throw_Timer -= diff;

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };


    struct  mob_dragonmaw_sky_stalkerAI : public mob_black_temple_tashAI
    {
        mob_dragonmaw_sky_stalkerAI(Creature *c) : mob_black_temple_tashAI(c){}

        uint32 shoot_Timer;
        uint32 arrow_Timer;

        void Reset()
        {
            shoot_Timer = 2500;
            arrow_Timer = 10000+rand()%10000;

            mob_black_temple_tashAI::Reset();
        }

        void AttackStart(Unit* pWho)
        {
            if (!pWho)
                return;

            if (me->Attack(pWho, true))
            {
                DoStartMovement(pWho, 30, M_PI/2);
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(arrow_Timer < diff)
            {

                Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                if(ptarget)
                    DoCast(ptarget,SPELL_IMMOLATION_ARROW);
                arrow_Timer =  10000+rand()%10000;
            }else arrow_Timer -= diff;


            if(shoot_Timer < diff)
            {
                DoCast(me->getVictim(),SPELL_SKY_STALKER_SHOOT);
                shoot_Timer = 2500;
            }else shoot_Timer -= diff;
        }
    };

    struct  mob_dragonmaw_wind_reaverAI : public mob_black_temple_tashAI
    {
        mob_dragonmaw_wind_reaverAI(Creature *c) : mob_black_temple_tashAI(c){}

        uint32 doombolt_Timer;
        uint32 firebolt_Timer;
        uint32 freeze_Timer;

        void Reset()
        {
            firebolt_Timer = 3000;
            doombolt_Timer = 5000+rand()%10000;
            freeze_Timer = 5000+rand()%10000;

            mob_black_temple_tashAI::Reset();
        }

        void AttackStart(Unit* pWho)
        {
            if (!pWho)
                return;

            if (me->Attack(pWho, true))
            {
                DoStartMovement(pWho, 30, me->GetAngle(pWho));
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(freeze_Timer < diff)
            {
                if (!me->IsNonMeleeSpellCasted(false))
                {
                    if(me->IsWithinMeleeRange(me->getVictim()))
                        DoCast(me->getVictim(),SPELL_FREEZE);
                    freeze_Timer =  10000+rand()%10000;
                }
            }else freeze_Timer -= diff;

            if(doombolt_Timer < diff)
            {
                if (!me->IsNonMeleeSpellCasted(false))
                {
                    Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                    if(ptarget)
                        DoCast(ptarget,SPELL_DOOMBOLT);
                    doombolt_Timer =  10000+rand()%10000;
                }
            }else doombolt_Timer -= diff;

            if(firebolt_Timer < diff)
            {
                if (!me->IsNonMeleeSpellCasted(false))
                {
                    DoCast(me->getVictim(),SPELL_WIND_REAVER_FIREBOLT);
                    firebolt_Timer = 3000;
                }
            }else firebolt_Timer -= diff;
        }
    };

    struct  mob_dragonmaw_wyrmcallerAI : public mob_black_temple_tashAI
    {
        mob_dragonmaw_wyrmcallerAI(Creature *c) : mob_black_temple_tashAI(c){}

        uint32 cleave_Timer;
        uint32 fixate_Timer;
        uint32 check_Timer;
        uint32 jab_Timer;

        bool FixateSet;
        uint64 FixateTarget;

        void Reset()
        {
            cleave_Timer = 10000;
            fixate_Timer = 20000;
            jab_Timer = 5000;

            FixateTarget = 0;
            check_Timer = 5000;

            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
            me->ApplySpellImmune(0, IMMUNITY_EFFECT,SPELL_EFFECT_ATTACK_ME, true);

            mob_black_temple_tashAI::Reset();
        }

        void CheckForMark()
        {
            if(FixateTarget == 0)
            {
                Map *map = me->GetMap();
                if(map->IsDungeon())
                {
                    Map::PlayerList const &PlayerList = map->GetPlayers();
                    for(Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                    {
                        if (Player* i_pl = i->getSource())
                            if (i_pl->isAlive())
                            {
                                if(me->HasAura(SPELL_FIXATE,0))
                                {
                                    FixateTarget = me->GetGUID();
                                }
                            }
                    }
                }
            }

            if(FixateTarget != 0)
            {
                Player* target = Unit::GetPlayer(*me,FixateTarget);
                if(target)
                {
                    if(target->HasAura(SPELL_FIXATE,0))
                    {
                        me->SetInCombatWith(target);
                        target->SetInCombatWith(me);
                        me->AddThreat(target, 50000.0f);
                    }else
                    {
                        FixateTarget = 0;
                        DoModifyThreatPercent(target,0);
                    }
                }
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(fixate_Timer < diff)
            {
                Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                if(ptarget)
                    DoCast(ptarget,SPELL_FIXATE);

                fixate_Timer = 30000;
            }else fixate_Timer -= diff;

            if(check_Timer < diff)
            {
                CheckForMark();
                check_Timer = 5000;
            }else check_Timer -= diff;

            if(cleave_Timer < diff)
            {
                DoCast(me->getVictim(),SPELL_CLEAVE);
                cleave_Timer = 5000 + rand()%5000;
            }else cleave_Timer -= diff;

            if(jab_Timer < diff)
            {
                DoCast(me->getVictim(),SPELL_JAB);
                jab_Timer = 5000 + rand()%5000;
            }else jab_Timer -= diff;

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_illidari_fearbringerAI : public mob_black_temple_tashAI
    {
        mob_illidari_fearbringerAI(Creature *c) : mob_black_temple_tashAI(c){}

        uint32 flames_Timer;
        uint32 rain_Timer;
        uint32 stomp_Timer;

        bool isRaining;
        uint32 RainCount;
        uint64 rainTrigger;

        bool isFlaming;

        void Reset()
        {
            stomp_Timer = 5000;
            rain_Timer = 6000;
            flames_Timer = 5000 + rand()%10000;
            isRaining = false;
            RainCount = 0;
            rainTrigger = 0;

            mob_black_temple_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(stomp_Timer < diff)
            {
                DoCast(me,SPELL_WAR_STOMP);
                stomp_Timer = 20000 + rand()%10000;
                if(rand()%2 == 0)
                    rain_Timer = 1000;
            }else stomp_Timer -= diff;

            if(flames_Timer < diff)
            {
                if(!isFlaming)
                {
                    if(!me->IsNonMeleeSpellCasted(false))
                    {
                        DoCast(me->getVictim(),SPELL_ILLIDARI_FLAMES);
                        flames_Timer = 2500;
                        isFlaming = true;
                    }
                }
                else
                {
                    if(!me->HasAura(SPELL_ILLIDARI_FLAMES,0))
                    {
                        isFlaming = false;
                        flames_Timer = 10000 + rand()%10000;
                    }else
                    {
                        int32 damage = 2850 +rand()%300;
                        me->CastCustomSpell(me,SPELL_ILLIDARI_FLAMES_TRIGGER,&damage,NULL,NULL,true);
                        flames_Timer = 1000;
                    }
                }
            }else flames_Timer -= diff;

            if(rain_Timer < diff)
            {
                if(isRaining)
                {
                    if(Creature* c_raintrigger = Creature::GetCreature((*me),rainTrigger))
                    {
                        int32 damage = 3420 +rand()%360;
                        c_raintrigger->CastCustomSpell(c_raintrigger,SPELL_RAIN_OF_CHAOS_TRIGGER,&damage,NULL,NULL,false,0,0,me->GetGUID());

                    }
                    if(RainCount > 2)
                    {
                        rain_Timer = 20000 + rand()%10000;
                        isRaining = false;
                    }else
                    {
                        RainCount++;
                        rain_Timer = 3000;
                    }
                }else
                {
                    if(!me->IsNonMeleeSpellCasted(false))
                    {
                        Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                        if(ptarget)
                        {
                            DoCast(ptarget,SPELL_RAIN_OF_CHAOS);
                            float x,y,z;
                            ptarget->GetPosition(x,y,z);
                            Creature* trigger = me->SummonTrigger(x,y,z,0,10000);
                            rainTrigger = trigger->GetGUID();
                        }

                        RainCount = 0;
                        isRaining = true;
                        rain_Timer = 3000;
                    }
                }
            }else rain_Timer -= diff;

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_illidari_nightlordAI : public mob_black_temple_tashAI
    {
        mob_illidari_nightlordAI(Creature *c) : mob_black_temple_tashAI(c){}

        uint32 curse_Timer;
        uint32 fear_Timer;
        uint32 shadowfiend_Timer;
        uint32 inferno_Timer;

        bool inferno;
        uint32 inferno_tick;

        void Reset()
        {
            fear_Timer = 10000+rand()%10000;
            curse_Timer = 10000+rand()%10000;
            shadowfiend_Timer = 30000;
            inferno_Timer = 20000 + rand()%20000;
            inferno = false;
            inferno_tick = 0;

            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, false);
            me->ApplySpellImmune(0, IMMUNITY_EFFECT,SPELL_EFFECT_ATTACK_ME, false);

            mob_black_temple_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(inferno)
            {
                if(inferno_Timer < diff)
                {
                    int damage = inferno_tick * 1000;
                    me->CastCustomSpell(me,SPELL_ILLI_SHADOW_INFERNO_DMG, &damage, NULL, NULL,false, NULL, NULL, me->GetGUID());
                    inferno_tick++;
                    inferno_Timer = 1000;
                }else inferno_Timer -= diff;

                if(!me->HasAura(SPELL_ILLI_SHADOW_INFERNO,0))
                {
                    inferno_tick = 0;
                    inferno_Timer = 20000+rand()%10000;
                    inferno = false;
                }

                return;
            }else
            {
                if(curse_Timer < diff)
                {
                    Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                    if(ptarget)
                        DoCast(me,SPELL_ILLI_CURSE_OF_MENDING);
                    curse_Timer = 10000+rand()%15000;
                }else curse_Timer -= diff;

                if(fear_Timer < diff)
                {
                    DoCast(me,SPELL_ILLI_FEAR);
                    fear_Timer = 10000+rand()%10000;
                }else fear_Timer -= diff;

                if(shadowfiend_Timer < diff)
                {
                    DoCast(me,SPELL_ILLI_SUMMON_SHADOWFIEND_OPTIC);
                    for(int i = 0 ; i < 5; i++)
                    {
                        DoCast(me,SPELL_ILLI_SUMMON_SHADOWFIEND_EFFEKT,true);
                    }
                    shadowfiend_Timer = 20000+rand()%10000;
                }else shadowfiend_Timer -= diff;

                if(inferno_Timer < diff)
                {
                    DoCast(me,SPELL_ILLI_SHADOW_INFERNO);
                    inferno = true;
                    inferno_Timer = 100;
                    inferno_tick = 1;
                    return;
                }else inferno_Timer -= diff;

                mob_black_temple_tashAI::UpdateAI(diff);
            }
        }
    };

    struct  mob_illidari_boneslicerAI : public mob_black_temple_tashAI
    {
        mob_illidari_boneslicerAI(Creature *c) : mob_black_temple_tashAI(c){}

        uint32 cloak_Timer;
        uint32 gouge_Timer;
        uint32 step_Timer;


        void Reset()
        {
            cloak_Timer = 10000+rand()%10000;
            gouge_Timer = 10000+rand()%10000;
            step_Timer = 10000+rand()%10000;

            mob_black_temple_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(step_Timer < diff)
            {
                Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                if(ptarget)
                    DoCast(me,SPELL_SHADOWSTEP);
                step_Timer = 10000+rand()%10000;
            }else step_Timer -= diff;

            if(cloak_Timer < diff)
            {
                DoCast(me,SPELL_CLOAK_OF_SHADOW);
                cloak_Timer = 10000+rand()%10000;
            }else cloak_Timer -= diff;

            if(gouge_Timer < diff)
            {
                DoCast(me->getVictim(),SPELL_ILLI_GOUGE);
                gouge_Timer = 10000+rand()%10000;
            }else gouge_Timer -= diff;

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_ashtongue_battlelordAI : public mob_black_temple_ashtongueAI
    {
        mob_ashtongue_battlelordAI(Creature *c) : mob_black_temple_ashtongueAI(c){}

        uint32 cleave_Timer;
        uint32 blow_Timer;
        uint32 throw_Timer;
        uint32 frenzy_Timer;

        void Reset()
        {
            cleave_Timer = 5000 + rand()%5000;
            blow_Timer = 10000+ rand()%5000;
            throw_Timer = 12000+ rand()% 5000;
            frenzy_Timer = 20000 - rand()%5000;


            mob_black_temple_ashtongueAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            CheckAkamaEvent(diff);

            if (!UpdateVictim() )
                return;

            if(cleave_Timer < diff)
            {
                DoCast(me->getVictim(),SPELL_CLEAVE);
                cleave_Timer = 5000 + rand()%5000;
            }else cleave_Timer -= diff;

            if(blow_Timer < diff)
            {
                DoCast(me->getVictim(),SPELL_CONCUSSION_BLOW);
                blow_Timer = 5000 + rand()%5000;
            }else blow_Timer -= diff;

            if(throw_Timer < diff)
            {
                Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                if(ptarget && me->GetDistance2d(ptarget) > 10 && me->GetDistance2d(ptarget) < 40 )
                {
                    DoCast(ptarget,SPELL_CONCUSSIVE_THROW);
                    throw_Timer = 10000 + rand()%10000;
                }
            }else throw_Timer -= diff;

            if(!me->HasAura(SPELL_FRENZY,0))
                if(frenzy_Timer < diff)
                {
                    DoCast(me,SPELL_FRENZY);
                    frenzy_Timer = 20000 + rand()%10000;
                }else frenzy_Timer -= diff;


            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_ashtongue_feral_spiritAI : public mob_black_temple_ashtongueAI
    {
        mob_ashtongue_feral_spiritAI(Creature *c) : mob_black_temple_ashtongueAI(c){}

        uint32 rage_Timer;
        uint32 bond_Timer;

        void Reset()
        {
            rage_Timer = 10000 + rand()%5000;
            bond_Timer = 10000+ rand()%10000;

            Creature* master = FindNearestCreature(ENTRY_ASHTONGUE_PRIMALIST,40);
            if(master)
            {
                master->SetPetGUID(me->GetGUID());
                //me-SetOwnerGUID(master->GetGUID());
            }

            mob_black_temple_ashtongueAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            CheckAkamaEvent(diff);

            if (!UpdateVictim() )
                return;

            if(rage_Timer < diff)
            {
                DoCast(me,SPELL_CHARGE_RAGE);
                rage_Timer = 20000 + rand()%20000;
            }else rage_Timer -= diff;

            if(bond_Timer < diff)
            {
                //Creature* master = FindNearestCreature(ENTRY_ASHTONGUE_PRIMALIST,40);
                //if(master)
                //{
                //    master->SetPet((Pet*)me);
                    me->CastSpell(me,SPELL_SPIRIT_BOND,true);
                    //master->CastSpell(master,SPELL_SPIRIT_BOND,true);
                //}
                bond_Timer = 20000 + rand()%20000;
            }else bond_Timer -= diff;

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_ashtongue_primalistAI : public mob_black_temple_ashtongueAI
    {
        mob_ashtongue_primalistAI(Creature *c) : mob_black_temple_ashtongueAI(c){}

        uint32 shoot_Timer;
        uint32 sting_Timer;
        uint32 clip_Timer;
        uint32 multi_Timer;

        void Reset()
        {
            shoot_Timer = 2500;
            sting_Timer = 10000+rand()%10000;
            clip_Timer = 10000+rand()%10000;
            multi_Timer = 10000+rand()%10000;

            mob_black_temple_ashtongueAI::Reset();
        }

        void AttackStart(Unit* who)
        {
            ScriptedAI::AttackStartNoMove(who);
        }

        void EnterCombat(Unit *who)
        {
            Creature* temp = FindNearestCreature(ENTRY_FERAL_SPIRIT,30);
            if(!temp || temp->isDead())
                DoCast(me,SPELL_SUMMON_FERAL_SPIRIT);
        }

        void UpdateAI(const uint32 diff)
        {
            CheckAkamaEvent(diff);

            if (!UpdateVictim() )
                return;

            if(sting_Timer < diff)
            {

                Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                if(ptarget && me->GetDistance2d(ptarget) > 10 && me->GetDistance2d(ptarget) < 35)
                {
                    DoCast(ptarget,SPELL_WYVERN_STING);
                    sting_Timer =  10000+rand()%10000;
                }
            }else sting_Timer -= diff;


            if(multi_Timer < diff)
            {

                Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                if(ptarget && me->GetDistance2d(ptarget) > 10 && me->GetDistance2d(ptarget) < 30)
                {
                    DoCast(ptarget,SPELL_MULTI_SHOOT);
                    multi_Timer =  10000+rand()%10000;
                }
            }else multi_Timer -= diff;


            if(clip_Timer < diff)
            {
                if(me->GetDistance2d( me->getVictim()) < 6)
                    DoCast(me->getVictim(),SPELL_SWEEPING_WING_CLIP);
                clip_Timer =  10000+rand()%10000;
            }else clip_Timer -= diff;

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

                if(shoot_Timer < diff)
                {
                    DoCast(me->getVictim(),SPELL_SKY_STALKER_SHOOT);
                    shoot_Timer = 2500;
                }else shoot_Timer -= diff;
             }

            CheckAkamaEvent(diff);
        }
    };

    struct  mob_ashtongue_mysticAI : public mob_black_temple_ashtongueAI
    {
        mob_ashtongue_mysticAI(Creature *c) : mob_black_temple_ashtongueAI(c){}

        uint32 bloodlust_Timer;
        uint32 heal_Timer;

        uint32 totem_Timer;
        uint32 shock_Timer;

        void Reset()
        {
            bloodlust_Timer = 20000 + rand()%20000;
            heal_Timer = 10000+ rand()%10000;
            shock_Timer = 10000+ rand()%10000;
            totem_Timer = 2000;

            mob_black_temple_ashtongueAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            CheckAkamaEvent(diff);

            if (!UpdateVictim() )
                return;

            if(bloodlust_Timer < diff)
            {
                DoCast(me,SPELL_BLOODLUST);
                bloodlust_Timer = 20000 + rand()%20000;
            }else bloodlust_Timer -= diff;

            if(shock_Timer < diff)
            {
                Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                if(ptarget)
                {
                    switch(rand()%2)
                    {
                    case 0:
                        DoCast(ptarget,SPELL_FLAME_SHOCK);
                        break;
                    case 1:
                        DoCast(ptarget,SPELL_FROST_SHOCK);
                        break;
                    }
                }
                shock_Timer = 5000 + rand()%5000;
            }else shock_Timer -= diff;

            if(totem_Timer < diff)
            {
                Creature* totem;
                bool TotemSummoned = false;

                if(!TotemSummoned)
                {
                    totem = FindNearestCreature(ENTRY_CYCLONE_TOTEM,30);
                    if(!totem)
                        DoCast(me,SPELL_CYCLONE_TOTEM);

                    TotemSummoned = true;
                    totem_Timer = 2000;
                }

                if(!TotemSummoned)
                {
                    totem = FindNearestCreature(ENTRY_SEARING_TOTEM,30);
                    if(!totem)
                        DoCast(me,SPELL_SEARING_TOTEM);

                    TotemSummoned = true;
                    totem_Timer = 2000;
                }

                if(!TotemSummoned)
                {
                    totem = FindNearestCreature(ENTRY_WINDFURY_TOTEM,30);
                    if(!totem)
                        DoCast(me,SPELL_WINDFURY_TOTEM);

                    TotemSummoned = true;
                    totem_Timer = 2000;
                }

                if(!TotemSummoned)
                    totem_Timer = 10000 + rand()%10000;
            }else totem_Timer -= diff;

            if(heal_Timer < diff)
            {
                Unit* target = DoSelectLowestHpFriendly(40);
                if(!target)
                    target = me;

                DoCast(target,SPELL_CHAIN_HEAL);
                heal_Timer = 10000 + rand()%5000;
            }else heal_Timer -= diff;

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_ashtongue_cyclone_totemAI : public NullCreatureAI
    {
        mob_ashtongue_cyclone_totemAI(Creature *c) : NullCreatureAI(c) {}
        void Reset()
        {
            SpellEntry *spellInfo;
            spellInfo = (SpellEntry*)GetSpellStore()->LookupEntry(SPELL_CYCLONE_TOTEM_EFFEKT);
            if(spellInfo)
            {
                spellInfo->MaxAffectedTargets = 5;
                me->CastSpell(me,spellInfo,false);
                //DoCast(me,SPELL_CYCLONE_TOTEM_EFFEKT); 
            }
        }
    };

    struct  mob_ashtongue_searing_totemAI : public NullCreatureAI
    {
        mob_ashtongue_searing_totemAI(Creature *c) : NullCreatureAI(c) {}

        uint32 attack_Timer;
        void Reset()
        {
            attack_Timer = 100;
        }
    
        void UpdateAI(const uint32 diff)
        {
            if(attack_Timer < diff)
            {
                DoCast(me,SPELL_SEARING_TOTEM_ATTACK);
                attack_Timer = 2500;
            }else attack_Timer -= diff;
        }
    };

    struct  mob_ashtongue_stalkerAI : public mob_black_temple_ashtongueAI
    {
        mob_ashtongue_stalkerAI(Creature *c) : mob_black_temple_ashtongueAI(c){}

        uint32 blind_Timer;
        uint32 mpoison_Timer;
        uint32 ipoison_Timer;

        void Reset()
        {
            blind_Timer = 10000 + rand()%5000;
            mpoison_Timer = 5000+ rand()%10000;
            ipoison_Timer = 5000+ rand()%10000;

            DoCast(me,SPELL_STEALTH);

            mob_black_temple_ashtongueAI::Reset();
        }

        void EnterCombat(Unit *who)
        {
            me->RemoveAurasDueToSpell(SPELL_STEALTH);
        }

        void UpdateAI(const uint32 diff)
        {
            CheckAkamaEvent(diff);

            if (!UpdateVictim() )
                return;

            if(blind_Timer < diff)
            {
                DoCast(me->getVictim(),SPELL_BLIND);
                DoModifyThreatPercent(me->getVictim(),50);
                blind_Timer = 15000 + rand()%10000;
            }else blind_Timer -= diff;


            if(mpoison_Timer < diff)
            {
                if(me->getVictim()->getPowerType() == POWER_MANA)
                {
                    DoCast(me->getVictim(),SPELL_MINDNUMBING_POISON);
                }
                    mpoison_Timer = 15000 + rand()%10000;
            }else mpoison_Timer -= diff;

            if(ipoison_Timer < diff)
            {
                DoCast(me->getVictim(),SPELL_INSTANT_POISON);
                ipoison_Timer = 10000 + rand()%5000;
            }else ipoison_Timer -= diff;

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_ashtongue_stormcallerAI : public mob_black_temple_ashtongueAI
    {
        mob_ashtongue_stormcallerAI(Creature *c) : mob_black_temple_ashtongueAI(c){}

        uint32 bolt_timer;
        uint32 chain_Timer;
        uint32 shield_Timer;

        void Reset()
        {
            bolt_timer = 2500;
            chain_Timer = 10000+rand()%10000;
            shield_Timer = 1000;

            mob_black_temple_ashtongueAI::Reset();
        }

        void EnterCombat(Unit *who)
        {
            Creature* temp = FindNearestCreature(ENTRY_STORM_FURY,30);
            if(!temp || temp->isDead())
                DoCast(me,SPELL_SUMMON_STORM_FURY);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(shield_Timer < diff)
            {
                if (!me->IsNonMeleeSpellCasted(false))
                {
                    DoCast(me,SPELL_LIGHTNING_SHIELD);
                    shield_Timer =  30000;
                }
            }else shield_Timer -= diff;

            if(chain_Timer < diff)
            {
                if (!me->IsNonMeleeSpellCasted(false))
                {
                    DoCast(me->getVictim(),SPELL_CHAIN_LIGHTNING);
                    chain_Timer =  10000+rand()%10000;
                }
            }else chain_Timer -= diff;

            if(bolt_timer < diff)
            {
                DoCast(me->getVictim(),SPELL_LIGHTNING_BOLT);
                bolt_timer = 2500;
            }else bolt_timer -= diff;

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_storm_furyAI : public mob_black_temple_ashtongueAI
    {
        mob_storm_furyAI(Creature *c) : mob_black_temple_ashtongueAI(c){}

        uint32 blink_timer;

        void Reset()
        {
            blink_timer = 20000+rand()%10000;

            mob_black_temple_ashtongueAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(blink_timer < diff)
            {
                DoCast(me,SPELL_STORM_BLINK_DAMAGE,true);
                DoCast(me,SPELL_STORM_BLINK_OPTICAL);
                blink_timer =  20000+rand()%10000;
            }else blink_timer -= diff;

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_illidari_centurionAI : public mob_black_temple_tashAI
    {
        mob_illidari_centurionAI(Creature *c) : mob_black_temple_tashAI(c){}

        uint32 cleave_Timer;
        uint32 sonic_Timer;

        void Reset()
        {
            cleave_Timer = 10000 + rand()%5000;
            sonic_Timer = 10000 + rand()%5000;

            mob_black_temple_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(cleave_Timer < diff)
            {
                DoCast(me->getVictim(),SPELL_CLEAVE);
                cleave_Timer = 5000 + rand()%5000;
            }else cleave_Timer -= diff;

            if(sonic_Timer < diff)
            {
                DoCast(me->getVictim(),SPELL_SONIC_STRIKE);
                sonic_Timer = 10000 + rand()%10000;
            }else sonic_Timer -= diff;

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_illidari_defilerAI : public mob_black_temple_tashAI
    {
        mob_illidari_defilerAI(Creature *c) : mob_black_temple_tashAI(c){}

        uint32 banish_Timer;
        uint32 curse_Timer;
        uint32 immolation_Timer;
        uint32 rain_Timer;

        void Reset()
        {
            banish_Timer = 10000 + rand()%10000;
            curse_Timer = 10000 + rand()%10000;
            immolation_Timer = 10000 + rand()%5000;
            rain_Timer = 30000 + rand()%10000;

            mob_black_temple_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(banish_Timer < diff)
            {
                Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 1);
                if(ptarget)
                    DoCast(ptarget,SPELL_BANISH);
                banish_Timer = 15000;
            }else banish_Timer -= diff;

            if(curse_Timer < diff)
            {
                Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                if(ptarget && !ptarget->HasAura(SPELL_CURSE_OF_AGONY,0))
                {
                    DoCast(ptarget,SPELL_CURSE_OF_AGONY);
                    curse_Timer = 10000 + rand()%10000;
                }
            }else curse_Timer -= diff;

            if(immolation_Timer < diff)
            {
                Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                if(ptarget && !ptarget->HasAura(SPELL_FEL_IMMOLATE,0))
                {
                    DoCast(ptarget,SPELL_FEL_IMMOLATE);
                    immolation_Timer = 15000 + rand()%10000;
                }
            }else immolation_Timer -= diff;

            if(rain_Timer < diff)
            {
                Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 1);
                if(ptarget)
                    DoCast(ptarget,SPELL_RAIN_OF_CHAOS_ILLIDARI_DEFILER);
                rain_Timer = 20000 + rand()%10000;
            }else rain_Timer -= diff;


            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_illidari_heartseekerAI : public mob_black_temple_tashAI
    {
        mob_illidari_heartseekerAI(Creature *c) : mob_black_temple_tashAI(c){}

        uint32 skeleton_Timer;
        uint32 bleakheart_Timer;
        uint32 shot_Timer;
        uint32 rapid_Timer;

        void Reset()
        {
            shot_Timer = 2500;
            rapid_Timer = 10000+rand()%10000;
            bleakheart_Timer = 10000+rand()%10000;
            skeleton_Timer = 10000+rand()%10000;

            mob_black_temple_tashAI::Reset();
        }

        void AttackStart(Unit* who)
        {
            ScriptedAI::AttackStartNoMove(who);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(rapid_Timer < diff)
            {
                DoCast(me,SPELL_RAPID_SHOT);
                rapid_Timer =  20000+rand()%10000;
            }else rapid_Timer -= diff;

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

                if(shot_Timer < diff)
                {
                    if (!me->IsNonMeleeSpellCasted(false))
                    {
                        DoCast(me->getVictim(),SPELL_ILLIDARI_HEARTSEEKER_SHOT);
                        shot_Timer = 2500;
                    }
                }else shot_Timer -= diff;
            }
        }
    };

    struct  mob_priestess_of_dementiaAI : public mob_black_temple_tashAI
    {
        mob_priestess_of_dementiaAI(Creature *c) : mob_black_temple_tashAI(c){}

        uint32 dementia_Timer;
        uint32 confusion_Timer;
        uint32 image_Timer;

        void Reset()
        {
            dementia_Timer = 1000;
            confusion_Timer = 10000 + rand()%5000;
            image_Timer = 10000 + rand()%5000;

            mob_black_temple_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(dementia_Timer < diff)
            {
                DoCast(me,SPELL_DEMENTIA);
                dementia_Timer = 30000 + rand()%10000;
            }else dementia_Timer -= diff;

            if(confusion_Timer < diff)
            {
                DoCast(me,SPELL_CONFUSION);
                confusion_Timer = 10000 + rand()%10000;
            }else confusion_Timer -= diff;

            if(image_Timer < diff)
            {

                if(Creature* temp = DoSpawnCreature(ENTRY_IMAGE_OF_DEMENTIA,0,0,0,0,TEMPSUMMON_TIMED_DESPAWN,10000 + rand()%10000))
                {
                    temp->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    temp->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

                    Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                    if(!ptarget) ptarget = me->getVictim();
                    temp->AI()->AttackStart(ptarget);
                    temp->CastSpell(temp,SPELL_DEMENTIA_WHIRLWIND,false);

                    image_Timer = 20000 + rand()%10000;
                }
            }else image_Timer -= diff;

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_priestess_of_delightAI : public mob_black_temple_tashAI
    {
        mob_priestess_of_delightAI(Creature *c) : mob_black_temple_tashAI(c){}

        uint32 curse_Timer;

        void Reset()
        {
            curse_Timer = 10000 + rand()%5000;

            mob_black_temple_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(curse_Timer < diff)
            {
                Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                if(ptarget)
                    DoCast(ptarget,SPELL_CURSE_OF_VITALITY);

                curse_Timer = 10000 + rand()%5000;
            }else curse_Timer -= diff;

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_sister_of_painAI : public mob_black_temple_tashAI
    {
        mob_sister_of_painAI(Creature *c) : mob_black_temple_tashAI(c){}

        uint32 lash_Timer;
        uint32 rage_Timer;
        uint32 shadowword_Timer;
        uint32 shell_Timer;

        void EnterCombat(Unit *who)
        {
            Creature* sister = FindNearestCreature(ENTRY_SISTER_OF_PLEASURE,40);
            if(sister)
            {
                sister->AI()->AttackStart(who);
                DoCast(sister,SPELL_SHARED_BONDS_SCRIPT);
                //DoCast(sister,SPELL_SHARED_BONDS_EFFEKT,true);
            }
        }

        void Reset()
        {
            lash_Timer = 5000 + rand()%10000;
            rage_Timer = 10000 + rand()%10000;
            shadowword_Timer = 10000 + rand()%5000;
            shell_Timer = 10000 + rand()%5000;

            mob_black_temple_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;
        
            if(lash_Timer < diff)
            {
                DoCast(me->getVictim(),SPELL_LASH_OF_PAIN);
                lash_Timer = 5000 + rand()%10000;
            }else lash_Timer -= diff;

            if(rage_Timer < diff)
            {
                DoCast(me,SPELL_PAINFULL_RAGE);
                rage_Timer = 25000 + rand()%10000;
            }else rage_Timer -= diff;

            if(shadowword_Timer < diff)
            {
                Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                if(ptarget)
                    DoCast(ptarget,SPELL_SIS_SHADOWWORD_PAIN);
                shadowword_Timer = 10000 + rand()%8000;
            }else shadowword_Timer -= diff;

            if(shell_Timer < diff)
            {
                DoCast(me,SPELL_SHELL_OF_PAIN);
                shell_Timer = 30000 + rand()%10000;
            }else shell_Timer -= diff;

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_sister_of_pleasureAI : public mob_black_temple_tashAI
    {
        mob_sister_of_pleasureAI(Creature *c) : mob_black_temple_tashAI(c){}

        uint32 heal_Timer;
        uint32 nova_Timer;
        uint32 shell_Timer;

        void EnterCombat(Unit *who)
        {
            Creature* sister = FindNearestCreature(ENTRY_SISTER_OF_PAIN,40);
            if(sister)
            {
                sister->AI()->AttackStart(who);
                DoCast(sister,SPELL_SHARED_BONDS_SCRIPT);
                //DoCast(sister,SPELL_SHARED_BONDS_EFFEKT,true);
            }
        }

        void Reset()
        {
             heal_Timer = 10000 + rand()%5000;
             nova_Timer = 10000 + rand()%5000;
             shell_Timer = 10000 + rand()%5000;

             mob_black_temple_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(heal_Timer < diff)
            {
                Unit* target = DoSelectLowestHpFriendly(35);
                if(!target)
                    target = me;
                DoCast(target,SPELL_SIS_GREATER_HEAL);
                heal_Timer = 20000 + rand()%10000;
            }else heal_Timer -= diff;


            if(nova_Timer < diff)
            {
                DoCast(me,SPELL_SIS_HOLY_NOVA);
                nova_Timer = 20000 + rand()%10000;
            }else nova_Timer -= diff;

            if(shell_Timer < diff)
            {
                DoCast(me,SPELL_SHELL_OF_LIFE);
                shell_Timer = 30000 + rand()%10000;
            }else shell_Timer -= diff;

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_temple_concubineAI : public mob_black_temple_tashAI
    {
        mob_temple_concubineAI(Creature *c) : mob_black_temple_tashAI(c){}

        uint32 trap_Timer;
        uint32 poly_Timer;

        void Reset()
        {
             trap_Timer = 10000 + rand()%5000;
             poly_Timer = 10000 + rand()%5000;

             mob_black_temple_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(trap_Timer < diff)
            {
                DoCast(me->getVictim(),SPELL_LOVE_TRAP);
                trap_Timer = 5000 + rand()%10000;
            }else trap_Timer -= diff;

            if(poly_Timer < diff)
            {
                Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                if(ptarget)
                    DoCast(ptarget,SPELL_CONC_POLYMORPH);
                poly_Timer = 15000;
            }else poly_Timer -= diff;

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_charming_courtesanAI : public mob_black_temple_tashAI
    {
        mob_charming_courtesanAI(Creature *c) : mob_black_temple_tashAI(c){}

        uint32 mc_Timer;
        uint32 throw_Timer;

        void Reset()
        {
             mc_Timer = 20000 + rand()%10000;
             throw_Timer = 10000 + rand()%10000;

             mob_black_temple_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(mc_Timer < diff)
            {
                Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 1);
                if(ptarget)
                    DoCast(ptarget,SPELL_INFATUATION);
                mc_Timer = 30000 + rand()%10000;
            }else mc_Timer -= diff;

            if(throw_Timer < diff)
            {
                Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                if(ptarget)
                    DoCast(ptarget,SPELL_COURT_POISONOUS_THROW);
                throw_Timer = 15000;
            }else throw_Timer -= diff;

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_enslaved_servantAI : public mob_black_temple_tashAI
    {
        mob_enslaved_servantAI(Creature *c) : mob_black_temple_tashAI(c){}

        uint32 shot_Timer;
        uint32 uppercut_Timer;

        void Reset()
        {
             shot_Timer = 15000 + rand()%10000;
             uppercut_Timer = 15000 + rand()%10000;

             mob_black_temple_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(shot_Timer < diff)
            {
                DoCast(me->getVictim(),SPELL_KIDNEY_SHOT);
                shot_Timer = 15000 + rand()%10000;
            }else shot_Timer -= diff;

            if(uppercut_Timer < diff)
            {
                DoCast(me->getVictim(),SPELL_UPPERCUT);
                uppercut_Timer = 15000 + rand()%10000;
            }else uppercut_Timer -= diff;

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_spellbound_attendantAI : public mob_black_temple_tashAI
    {
        mob_spellbound_attendantAI(Creature *c) : mob_black_temple_tashAI(c){}

        uint32 kick_Timer;
        uint32 sleep_Timer;

        void Reset()
        {
             kick_Timer = 15000 + rand()%10000;
             sleep_Timer = 15000 + rand()%10000;

             mob_black_temple_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(kick_Timer < diff)
            {
                DoCast(me->getVictim(),SPELL_ATTENDANT_KICK);
                kick_Timer = 15000 + rand()%10000;
            }else kick_Timer -= diff;

            if(sleep_Timer < diff)
            {
                Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 1);
                if(ptarget)
                    DoCast(ptarget,SPELL_ATTENDANT_SLEEP);
                sleep_Timer = 15000 + rand()%10000;
            }else sleep_Timer -= diff;

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_black_temple_lost_soulAI : public mob_black_temple_tashAI
    {
        mob_black_temple_lost_soulAI(Creature *c) : mob_black_temple_tashAI(c){}

        void JustDied(Unit *who)
        {
            me->RemoveCorpse();
            me->SetRespawnTime(30);
        }
    };

    struct  mob_suffering_soul_fragmentAI : public mob_black_temple_lost_soulAI
    {
        mob_suffering_soul_fragmentAI(Creature *c) : mob_black_temple_lost_soulAI(c){}

        uint32 blast_Timer;

        void Reset()
        {
             blast_Timer = 5000 + rand()%5000;

             mob_black_temple_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(blast_Timer < diff)
            {
                DoCast(me->getVictim(),SPELL_SOUL_BLAST);
                blast_Timer = 10000 + rand()%5000;
            }else blast_Timer -= diff;

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };


    struct  mob_angered_soul_fragmentAI : public mob_black_temple_lost_soulAI
    {
        mob_angered_soul_fragmentAI(Creature *c) : mob_black_temple_lost_soulAI(c){}

        uint32 anger_Timer;

        void Reset()
        {
             anger_Timer = 5000 + rand()%5000;

             mob_black_temple_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(anger_Timer < diff)
            {
                DoCast(me->getVictim(),SPELL_SOUL_ANGER);
                anger_Timer = 10000 + rand()%5000;
            }else anger_Timer -= diff;

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_hungering_soul_fragmentAI : public mob_black_temple_lost_soulAI
    {
        mob_hungering_soul_fragmentAI(Creature *c) : mob_black_temple_lost_soulAI(c){}

        void EnterCombat(Unit *who)
        {
            DoCast(me,SPELL_CONSUMING_STRIKES,true);
        }
        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_illidari_battlemageAI : public mob_black_temple_tashAI
    {
        mob_illidari_battlemageAI(Creature *c) : mob_black_temple_tashAI(c){}

        uint32 frost_Timer;
        uint32 fire_Timer;
        uint32 flame_Timer;
        uint32 blizzard_Timer;

        void Reset()
        {
            frost_Timer = 10000 + rand()%5000;
            fire_Timer = 10000 + rand()%5000;
            blizzard_Timer = 15000 + rand()%10000;
            flame_Timer = 15000 + rand()%10000;

            mob_black_temple_tashAI::Reset();
        }

        void AttackStart(Unit* pWho)
        {
            if (!pWho)
                return;

            if (me->Attack(pWho, true))
            {
                 DoStartMovement(pWho, 20, me->GetAngle(pWho));
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(frost_Timer < diff)
            {
                DoCast(me->getVictim(),SPELL_ILLI_FROSTBOLT);
                frost_Timer = 5000 + rand()%10000;
            }else frost_Timer -= diff;

            if(fire_Timer < diff)
            {
                DoCast(me->getVictim(),SPELL_ILLI_FIREBALL);
                fire_Timer = 5000 + rand()%10000;
            }else fire_Timer -= diff;

            if(blizzard_Timer < diff)
            {
                Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                if(ptarget)
                    DoCast(ptarget,SPELL_ILLI_BLIZZARD);
                blizzard_Timer = 20000 + rand()%10000;
            }else blizzard_Timer -= diff;

            if(flame_Timer < diff)
            {
                Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                if(ptarget)
                    DoCast(ptarget,SPELL_ILLI_FLAMESTRIKE);
                flame_Timer = 15000 + rand()%10000;
            }else flame_Timer -= diff;

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_illidari_blood_lordAI : public mob_black_temple_tashAI
    {
        mob_illidari_blood_lordAI(Creature *c) : mob_black_temple_tashAI(c){}

        uint32 shield_Timer;
        uint32 hammer_Timer;
        uint32 judgement_Timer;

        void Reset()
        {
            shield_Timer = 10000 + rand()%5000;
            hammer_Timer = 10000 + rand()%5000;
            judgement_Timer = 10000 + rand()%5000;

            mob_black_temple_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(shield_Timer < diff)
            {
                DoCast(me,SPELL_ILLI_DIVINE_SHIELD);
                shield_Timer = 30000 + rand()%10000;
            }else shield_Timer -= diff;

            if(hammer_Timer < diff)
            {
                DoCast(me->getVictim(),SPELL_ILLI_HAMMER_OF_JUSTICE);
                hammer_Timer = 5000 + rand()%5000;
            }else hammer_Timer -= diff;

            if(judgement_Timer < diff)
            {
                DoCast(me->getVictim(),SPELL_ILLI_JUDGEMENT);
                judgement_Timer = 10000 + rand()%5000;
            }else judgement_Timer -= diff;

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_illidari_assassinAI : public mob_black_temple_tashAI
    {
        mob_illidari_assassinAI(Creature *c) : mob_black_temple_tashAI(c){}

        uint32 vanish_Timer;
        uint32 poison_Timer;

        void Reset()
        {
            vanish_Timer = 10000 + rand()%10000;
            poison_Timer = 10000 + rand()%5000;

            mob_black_temple_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(vanish_Timer < diff)
            {
                DoCast(me,SPELL_ILLI_VANISH);
                vanish_Timer = 10000 + rand()%10000;
            }else vanish_Timer -= diff;

            if(poison_Timer < diff)
            {
                DoCast(me->getVictim(),SPELL_ILLI_PARALYZING_POISON);
                poison_Timer = 10000 + rand()%10000;
            }else poison_Timer -= diff;

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_illidari_archonAI : public mob_black_temple_tashAI
    {
        mob_illidari_archonAI(Creature *c) : mob_black_temple_tashAI(c){}

        bool shadow;

        uint32 heal_Timer;
        uint32 smite_Timer;
        uint32 shield_Timer;

        uint32 blast_Timer;
        uint32 death_Timer;

        void Reset()
        {
            heal_Timer = 10000 + rand()%10000;
            smite_Timer = 10000 + rand()%5000;
            shield_Timer = 10000 + rand()%10000;

            blast_Timer = 10000 + rand()%5000;
            death_Timer = 20000 + rand()%10000;

            mob_black_temple_tashAI::Reset();
        }

        void EnterCombat(Unit *who)
        {
             shadow = rand()%2 == 0;
             if(shadow)
                DoCast(me,SPELL_ILLI_SHADOW_FORM);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(shadow)
            {
                if(blast_Timer < diff)
                {
                    Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                    if(ptarget)
                        DoCast(ptarget,SPELL_ILLI_MIND_BLAST);
                    blast_Timer = 5000 + rand()%10000;
                }else blast_Timer -= diff;

                if(death_Timer < diff)
                {
                    Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                    if(ptarget)
                        DoCast(ptarget,SPELL_ILLI_SHADOWWORD_DEATH);
                    death_Timer = 30000 + rand()%10000;
                }else death_Timer -= diff;
            }
            else
            {
                if(shield_Timer < diff)
                {
                    Unit* target = DoSelectLowestHpFriendly(35);
                    if(!target) target = me;
                    DoCast(target,SPELL_ILLI_SHIELD);
                    shield_Timer = 30000 + rand()%10000;
                }else shield_Timer -= diff;

                if(heal_Timer < diff)
                {
                    Unit* target = DoSelectLowestHpFriendly(35);
                    if(!target) target = me;
                    DoCast(target,SPELL_ILLI_HEAL);
                    heal_Timer = 10000 + rand()%10000;
                }else heal_Timer -= diff;

                if(smite_Timer < diff)
                {
                    Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                    if(ptarget)
                        DoCast(ptarget,SPELL_ILLI_HOLY_SMITE);
                    smite_Timer = 5000 + rand()%5000;
                }else smite_Timer -= diff;
            }

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_promenade_sentinelAI : public mob_black_temple_tashAI
    {
        mob_promenade_sentinelAI(Creature *c) : mob_black_temple_tashAI(c){}

        uint32 arcaneL1_Timer;
        uint32 arcaneL4_Timer;
        uint32 arcaneL5_Timer;

        void Reset()
        {
            arcaneL1_Timer = 1000;
            arcaneL4_Timer = 10000+ rand()%10000;
            arcaneL5_Timer = 10000+ rand()%10000;

            mob_black_temple_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(arcaneL1_Timer < diff)
            {
                DoCast(me,SPELL_L1_ARCANE_CHARGE,true);
                arcaneL1_Timer = 1000;
            }else arcaneL1_Timer -= diff;

            if(arcaneL4_Timer < diff)
            {
                Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                if(ptarget)
                    DoCast(ptarget,SPELL_L4_ARCANE_CHARGE);
                arcaneL4_Timer = 10000;
            }else arcaneL4_Timer -= diff;

            if(arcaneL5_Timer < diff)
            {
                Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                if(ptarget)
                {
                    int damage = ptarget->GetMaxHealth();
                    me->CastCustomSpell(ptarget, SPELL_L5_ARCANE_CHARGE, &damage, NULL, NULL, false, NULL, NULL, me->GetGUID());
                }
                arcaneL5_Timer = 10000+ rand()%15000;
            }else arcaneL5_Timer -= diff;

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_arcane_charge_L4AI : public ScriptedAI
    {
        mob_arcane_charge_L4AI(Creature *c) : ScriptedAI(c){}

        uint32 charge_Timer;

        void MoveInLineOfSight(Unit *who){}
        void AttackStart(Unit *who){}
        void Reset()
        {
            charge_Timer = 100;
        }
        void EnterCombat(Unit *who){}
        void UpdateAI(const uint32 diff)
        {
            if(charge_Timer < diff)
            {
                DoCast(me,SPELL_L4_ARCANE_CHARGE_DMG,true);
                charge_Timer = 1000;
            }else charge_Timer -= diff;
        }
    };

    struct  mob_hand_of_gorefiendAI : public mob_black_temple_tashAI
    {
        mob_hand_of_gorefiendAI(Creature *c) : mob_black_temple_tashAI(c){}

        void Reset()
        {
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
            me->ApplySpellImmune(0, IMMUNITY_EFFECT,SPELL_EFFECT_ATTACK_ME, true);

            mob_black_temple_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(me->GetHealth() > 0)
                if(((me->GetMaxHealth() * 100) / me->GetHealth()) <= 20)
                {
                    if(!me->HasAura(SPELL_HAND_ENRAGE,0))
                        DoCast(me,SPELL_HAND_ENRAGE);
                }

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_shadowmoon_blood_mageAI : public mob_black_temple_tashAI
    {
        mob_shadowmoon_blood_mageAI(Creature *c) : mob_black_temple_tashAI(c){}

        uint32 bolt_timer;
        uint32 siphon_timer;

        void Reset()
        {
            siphon_timer = 20000 + rand()%10000;
            bolt_timer = 5000 + rand()%5000;

            mob_black_temple_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(bolt_timer < diff)
            {
                Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                if(ptarget)
                    DoCast(ptarget,SPELL_BLOOD_BOLT_SCRIPT);
                bolt_timer = 10000 + rand()%5000;
            }else bolt_timer -= diff;

            if(siphon_timer < diff)
            {
                DoCast(me->getVictim(),SPELL_BLOOD_SIPHON);
                siphon_timer = 30000 + rand()%10000;
            }else siphon_timer -= diff;

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_shadowmoon_soldierAI : public mob_black_temple_tashAI
    {
        mob_shadowmoon_soldierAI(Creature *c) : mob_black_temple_tashAI(c){}

        uint32 strike_Timer;

        void Reset()
        {
            strike_Timer = 5000 + rand()%10000;

            mob_black_temple_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(strike_Timer < diff)
            {
                DoCast(me->getVictim(),SPELL_SOLDIER_STRIKE);
                strike_Timer = 5000 + rand()%5000;
            }else strike_Timer -= diff;

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_shadowmoon_reaverAI : public mob_black_temple_tashAI
    {
        mob_shadowmoon_reaverAI(Creature *c) : mob_black_temple_tashAI(c){}

        uint32 absorption_Timer;
        uint8 AuraStack;

        void Reset()
        {
            absorption_Timer = 10000 + rand()%5000;
            AuraStack = 0;

            mob_black_temple_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(absorption_Timer < diff)
            {
                DoCast(me,SPELL_ABSORPTION);
                absorption_Timer = 20000 + rand()%10000;
            }else absorption_Timer -= diff;

            if(AuraStack > (me->HasAura(SPELL_CHAOTIC_CHARGE,0) ? me->GetAura(SPELL_CHAOTIC_CHARGE,0)->GetStackAmount() : 0))
            {
                int32 damage =  rand()%374 + 2313;
                SpellEntry *spellInfo;
                spellInfo = (SpellEntry*)GetSpellStore()->LookupEntry(SPELL_CHAOTIC_CHARGE_DMG);
                if(spellInfo)
                {
                    spellInfo->MaxAffectedTargets = AuraStack;
                    spellInfo->EffectBasePoints[0] = damage + 1000*AuraStack;
                    me->CastSpell(me,spellInfo,false);
                }
                AuraStack = 0;
            }else
            {
                if(me->HasAura(SPELL_CHAOTIC_CHARGE,0))
                    AuraStack = me->GetAura(SPELL_CHAOTIC_CHARGE,0)->GetStackAmount();
            }


            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_shadowmoon_deathshaperAI : public mob_black_temple_tashAI
    {
        mob_shadowmoon_deathshaperAI(Creature *c) : mob_black_temple_tashAI(c){}

        uint32 coil_Timer;
        uint32 bolt_Timer;
        uint32 death_Timer;
        uint32 armor_Timer;

        void Reset()
        {
            armor_Timer = 500;
            coil_Timer = 10000 + rand()%5000;
            bolt_Timer = 1000 + rand()%5000;
            death_Timer = 10000 + rand()%10000;

            mob_black_temple_tashAI::Reset();
        }

        Creature* GetNextFriendlyCorpse()
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
                return NULL;

            for(std::list<Creature*>::iterator i = templist.begin(); i != templist.end(); ++i)
            {
                if((*i) && me->IsWithinDistInMap((*i),25) && (*i)->isDead())
                    return (*i);
            }

            return NULL;
    
        }

        void UpdateAI(const uint32 diff)
        {
            if(!me->HasAura(SPELL_SM_DEMON_ARMOR,0))
            {
                if(armor_Timer < diff)
                {
                    DoCast(me,SPELL_SM_DEMON_ARMOR);
                    armor_Timer = 20000;
                }else armor_Timer -= diff;
            }

            if (!UpdateVictim() )
                return;

            if(coil_Timer < diff)
            {
                if(!me->IsNonMeleeSpellCasted(false))
                {
                    Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                    if(ptarget)
                        DoCast(ptarget,SPELL_SM_DEATH_COIL);
                    coil_Timer = 10000 + rand()%10000;
                }
            }else coil_Timer -= diff;

            if(bolt_Timer < diff)
            {
                DoCast(me->getVictim(),SPELL_SM_SHADOW_BOLT);
                bolt_Timer = 5000;
            }else bolt_Timer -= diff;

            if(death_Timer < diff)
            {
                Creature* target = GetNextFriendlyCorpse();
                if(target && target->isDead())
                {
                    DoCast(target,SPELL_SM_SUMMON_SKELETON,true);
                    target->RemoveCorpse();
                }
                death_Timer = 20000 + rand()%20000;
            }else death_Timer -= diff;

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_shadowmoon_championAI : public mob_black_temple_tashAI
    {
        mob_shadowmoon_championAI(Creature *c) : mob_black_temple_tashAI(c){}

        uint32 weapon_Timer;
        uint32 light_Timer;

        void Reset()
        {
            weapon_Timer = 20000 + rand()% 10000;
            light_Timer = 5000 + rand()% 5000;

            mob_black_temple_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if( light_Timer < diff)
            {
                if(!me->HasAuraType(SPELL_AURA_MOD_DISARM))
                {
                    Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                    if(ptarget)
                        DoCast(ptarget,SPELL_SM_CHAOTIC_LIGHT);
                    light_Timer = 5000 + rand()%5000;
                }
            }else light_Timer -= diff;

            if( weapon_Timer < diff)
            {
                 DoCast(me->getVictim(),SPELL_SM_WHIRLING_WEAPON);
                 weapon_Timer = 25000 + rand()% 10000;
            }else weapon_Timer -= diff;

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_whirling_bladeAI : public ScriptedAI
    {
        mob_whirling_bladeAI(Creature *c) : ScriptedAI(c){}

        uint32 whirl_Timer;
        uint32 del_Timer;

        void MoveInLineOfSight(Unit *who){}
        void AttackStart(Unit *who){}
        void Reset()
        {
            del_Timer = 14000;
            whirl_Timer = 100;
        }
        void EnterCombat(Unit *who){}
        void UpdateAI(const uint32 diff)
        {
            if(del_Timer < diff)
            {
                me->DealDamage(me,me->GetHealth());
                me->RemoveCorpse();
                del_Timer = 60000;
            }else del_Timer -= diff;

            if(whirl_Timer < diff)
            {
                if(!me->IsNonMeleeSpellCasted(false))
                {
                    DoCast(me,SPELL_WHIRLING);
                    whirl_Timer = 2000;
                }
            }else whirl_Timer -= diff;
        }
    };

    struct  mob_shadowmoon_houndmasterAI : public mob_black_temple_tashAI
    {
        mob_shadowmoon_houndmasterAI(Creature *c) : mob_black_temple_tashAI(c){}

        uint32 shoot_Timer;
        uint32 trap_Timer;
        uint32 clip_Timer;
        uint32 shot_Timer;
        uint32 volley_Timer;

        void Reset()
        {
            shoot_Timer = 2500;
            trap_Timer = 10000 + rand()% 10000;
            clip_Timer = 10000 + rand()% 10000;
            shot_Timer = 10000 + rand()% 10000;
            volley_Timer = 20000 + rand()% 10000;

            mob_black_temple_tashAI::Reset();
        }

        void EnterCombat(Unit *who)
        {
            Creature* hound = FindNearestCreature(ENTRY_SHADOWMOON_RIDING_HOUND,30);
            if(!hound || hound->isDead())
                DoCast(me,SPELL_SMHM_RIDING_HOUND);
            else
                hound->AI()->AttackStart(who);
        }

        void AttackStart(Unit* who)
        {
            ScriptedAI::AttackStartNoMove(who);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(clip_Timer < diff)
            {
                if(me->IsWithinMeleeRange(me->getVictim()))
                    DoCast(me,SPELL_SMHM_WING_CLIP);
                clip_Timer = 10000 + rand()% 10000;
            }else clip_Timer -= diff;

            if(shot_Timer < diff)
            {
                Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                if(ptarget)
                    DoCast(ptarget,SPELL_SMHM_SILENCING_SHOT);
                shot_Timer = 10000 + rand()% 10000;
            }else shot_Timer -= diff;

            if(volley_Timer < diff)
            {
                DoCast(me->getVictim(),SPELL_SMHM_VOLLEY);
                volley_Timer = 20000 + rand()% 10000;
            }else volley_Timer -= diff;

            if(trap_Timer < diff)
            {
                DoCast(me,SPELL_SMHM_FREEZING_TRAP);
                trap_Timer = 30000 + rand()% 10000;
            }else trap_Timer -= diff;

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

                if(shoot_Timer < diff)
                {
                    DoCast(me->getVictim(),SPELL_SMHM_SHOOT);
                    shoot_Timer = 2500;
                }else shoot_Timer -= diff;
            }
        }
    };

    struct  mob_shadowmoon_riding_houndAI : public mob_black_temple_tashAI
    {
        mob_shadowmoon_riding_houndAI(Creature *c) : mob_black_temple_tashAI(c){}

        uint32 charge_Timer;
        uint32 bite_Timer;

        void Reset()
        {
            charge_Timer = 1000 + rand()% 10000;
            bite_Timer = 10000 + rand()% 10000;

            mob_black_temple_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(charge_Timer < diff)
            {
                Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 1);
                if(ptarget)
                    DoCast(ptarget,SPELL_SMRH_CHARGE);
                charge_Timer = 10000 + rand()% 10000;
            }else charge_Timer -= diff;

            if(bite_Timer < diff)
            {
                DoCast(me->getVictim(),SPELL_SMRH_CARNIVOROUS_BITE);
                bite_Timer = 10000 + rand()% 10000;
            }else bite_Timer -= diff;

            if((me->GetHealth() * 100 / me->GetMaxHealth()) < 20)
            {
                if(!me->HasAura(SPELL_SMRH_ENRAGE,0))
                    DoCast(me,SPELL_SMRH_ENRAGE,true);
            }

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_wrathbone_flayerAI : public mob_black_temple_tashAI
    {
        mob_wrathbone_flayerAI(Creature *c) : mob_black_temple_tashAI(c){}

        uint32 ignore_Timer;
        uint32 cleave_Timer;

        void Reset()
        {
            ignore_Timer = 20000+rand()%10000;
            cleave_Timer = 10000+rand()%5000;

            mob_black_temple_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(ignore_Timer < diff)
            {
                DoCast(me->getVictim(),SPELL_WB_IGNORED);
                DoModifyThreatPercent(me->getVictim(),0);
                ignore_Timer = 30000+rand()%10000;
            }else ignore_Timer -= diff;

            if(cleave_Timer < diff)
            {
                DoCast(me->getVictim(),SPELL_WB_CLEAVE);
                cleave_Timer = 10000+rand()%5000;
            }else cleave_Timer -= diff;

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_shadowmoon_weapon_masterAI : public mob_black_temple_tashAI
    {
        mob_shadowmoon_weapon_masterAI(Creature *c) : mob_black_temple_tashAI(c){}

        uint32 stance_Timer;
        uint32 spell_Timer;
        uint32 spell2_Timer;

        Warrior_Stance stance;

        void Reset()
        {
            stance_Timer = 100;

            mob_black_temple_tashAI::Reset();
        }

        void EnterCombat(Unit* who)
        {
            stance = (Warrior_Stance)(rand()%3);
            switch(stance)
                {
                case BATTLE_STANCE:
                    DoCast(me,SPELL_SMWM_BATTLE_STANCE);
                    DoCast(me,SPELL_SMWM_BATTLE_AURA,true);
                    spell_Timer = 1000 + rand()%5000;
                    spell2_Timer = 5000 + rand()%10000;
                    break;
                case BERSERKER_STANCE:
                    DoCast(me,SPELL_SMWM_BERSERKER_STANCE);
                    DoCast(me,SPELL_SMWM_BERSERKER_AURA,true);
                    spell_Timer = 10000;
                    break;
                case DEFENSIVE_STANCE:
                    DoCast(me,SPELL_SMWM_DEFENSIVE_STANCE);
                    DoCast(me,SPELL_SMWM_DEFENSIVE_AURA,true);
                    spell_Timer = 5000;
                    break;
                }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(stance_Timer < diff)
            {
                me->RemoveAurasDueToSpell(SPELL_SMWM_BERSERKER_STANCE);
                me->RemoveAurasDueToSpell(SPELL_SMWM_BERSERKER_AURA);
                me->RemoveAurasDueToSpell(SPELL_SMWM_BATTLE_STANCE);
                me->RemoveAurasDueToSpell(SPELL_SMWM_BATTLE_AURA);
                me->RemoveAurasDueToSpell(SPELL_SMWM_DEFENSIVE_STANCE);
                me->RemoveAurasDueToSpell(SPELL_SMWM_DEFENSIVE_AURA);
                Warrior_Stance oldstance = stance;

                while (stance == oldstance)
                    stance = (Warrior_Stance)(rand()%3);

                switch(stance)
                {
                case BATTLE_STANCE:
                    DoCast(me,SPELL_SMWM_BATTLE_STANCE);
                    DoCast(me,SPELL_SMWM_BATTLE_AURA,true);
                    spell_Timer = 1000 + rand()%5000;
                    spell2_Timer = 5000 + rand()%10000;
                    break;
                case BERSERKER_STANCE:
                    DoCast(me,SPELL_SMWM_BERSERKER_STANCE);
                    DoCast(me,SPELL_SMWM_BERSERKER_AURA,true);
                    spell_Timer = 10000;
                    break;
                case DEFENSIVE_STANCE:
                    DoCast(me,SPELL_SMWM_DEFENSIVE_STANCE);
                    DoCast(me,SPELL_SMWM_DEFENSIVE_AURA,true);
                    spell_Timer = 5000;
                    break;
                }
                stance_Timer = 30000;
            }else stance_Timer -= diff;

            if(spell_Timer < diff)
            {
                switch(stance)
                {
                case BATTLE_STANCE:
                    DoCast(me->getVictim(),SPELL_SMWM_KNOCK_AWAY);
                    spell_Timer = 5000 + rand()%10000;
                    break;
                case BERSERKER_STANCE:
                    DoCast(me,SPELL_SMWM_WHIRLWIND);
                    spell_Timer = 30000;
                    break;
                case DEFENSIVE_STANCE:
                    DoCast(me,SPELL_SMWM_SHIELD_WALL);
                    spell_Timer = 15000;
                    break;
                }
            }else spell_Timer -= diff;

            if(stance == BATTLE_STANCE)
            {
                if(spell2_Timer < diff)
                {
                    DoCast(me->getVictim(),SPELL_SMWM_MULTILATE);
                    spell2_Timer = 5000 + rand()%10000;
                }else spell2_Timer -= diff;
            }

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };


    struct  mob_bonechewer_behemothAI : public mob_black_temple_tashAI
    {
        mob_bonechewer_behemothAI(Creature *c) : mob_black_temple_tashAI(c){ meteor_form = rand()%2 == 0; }

        bool meteor_form;

        uint32 charge_Timer;
        uint32 stomp_Timer;
        uint32 comet_Timer;
        uint32 meteor_Timer;

        uint32 frenzy_Timer;

        void Reset()
        {
            charge_Timer = 10000 + rand()%5000;
            stomp_Timer = 10000 + rand()%5000;

            comet_Timer = 10000 + rand()%5000;
            meteor_Timer = 10000 + rand()%5000;
            frenzy_Timer = 20000 + rand()%10000;

            mob_black_temple_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(meteor_form)
            {
                if(comet_Timer < diff)
                {
                    Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0,40,true);
                
                    if(target && me->GetDistance(target) > 10)
                    {
                        DoCast(target,SPELL_BEHEMOTH_FIERY_COMET);
                        comet_Timer = 10000 + rand()%5000;
                    }
                }else comet_Timer -= diff;

                if(meteor_Timer < diff)
                {
                    Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                    if(ptarget)
                        DoCast(ptarget,SPELL_BEHEMOTH_METEOR);
                    meteor_Timer = 10000 + rand()%5000;
                }else meteor_Timer -= diff;
            }
            else
            {
                if(charge_Timer < diff)
                {
                    Unit *ptarget = SelectTarget(SELECT_TARGET_FARTHEST,0);
                    if(ptarget)
                    {
                        DoCast(ptarget,SPELL_BEHEMOTH_CHARGE);
                        charge_Timer = 10000 + rand()%5000;
                    }
                }else charge_Timer -= diff;

                if(stomp_Timer < diff)
                {
                    DoCast(me,SPELL_BEHEMOTH_FEL_STOMP);
                    stomp_Timer = 5000 + rand()%10000;
                }else stomp_Timer -= diff;
            }

            if(frenzy_Timer < diff)
            {
                DoCast(me,SPELL_BEHEMOTH_FRENZY);
                frenzy_Timer = 30000 + rand()%10000;
            }else frenzy_Timer -= diff;

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_bonechewer_shield_discipleAI : public mob_black_temple_tashAI
    {
        mob_bonechewer_shield_discipleAI(Creature *c) : mob_black_temple_tashAI(c){}

        uint32 intervene_Timer;
        uint32 bash_Timer;
        uint32 wall_Timer;
        uint32 throw_Timer;

        void Reset()
        {
            intervene_Timer = 10000 + rand()%10000;
            bash_Timer = 10000 + rand()%5000;
            wall_Timer = 10000 + rand()%10000;
            throw_Timer = 10000 + rand()%10000;

            mob_black_temple_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(intervene_Timer < diff)
            {
                Unit* target = DoSelectLowestHpFriendly(25);
                if(target && me->GetDistance2d(target) > 10)
                {
                    DoCast(target,SPELL_INTERVENE);
                    intervene_Timer = 20000 + rand()%10000;
                }
            }else intervene_Timer -= diff;

            if(bash_Timer < diff)
            {
                DoCast(me->getVictim(),SPELL_BCSD_SHIELD_BASH);
                bash_Timer = 5000 + rand()%5000;
            }else bash_Timer -= diff;

            if(wall_Timer < diff)
            {
                DoCast(me,SPELL_BCSD_SHIELD_WALL);
                wall_Timer = 20000 + rand()%10000;
            }else wall_Timer -= diff;

            if(throw_Timer < diff)
            {
                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1,40,true);
                if(target && me->GetDistance2d(target) > 5)
                {
                    DoCast(me,SPELL_BCSD_SHIELD_THROW);
                    throw_Timer = 10000 + rand()%20000;
                }
            }else throw_Timer -= diff;

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_bonechewer_blade_furyAI : public mob_black_temple_tashAI
    {
        mob_bonechewer_blade_furyAI(Creature *c) : mob_black_temple_tashAI(c){}

        uint32 whirl_Timer;

        void Reset()
        {
            whirl_Timer = 10000+rand()%10000;

            mob_black_temple_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(whirl_Timer < diff)
            {
                DoCast(me,SPELL_BCBF_WHIRLWIND);
                whirl_Timer = 20000 + rand()%10000;
            }else whirl_Timer -= diff;

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_bonechewer_blood_prophetAI : public mob_black_temple_tashAI
    {
        mob_bonechewer_blood_prophetAI(Creature *c) : mob_black_temple_tashAI(c){}

        uint32 drain_Timer;
        uint32 bolt_Timer;
        uint32 prophecy_Timer;
        uint32 frenzy_Timer;

        void Reset()
        {
            drain_Timer = 10000+rand()%10000;
            bolt_Timer = 50000+rand()%10000;
            prophecy_Timer = 10000+rand()%10000;
            frenzy_Timer = 30000+rand()%10000;

            mob_black_temple_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(drain_Timer < diff)
            {
                DoCast(me->getVictim(),SPELL_BCBP_BLOOD_DRAIN);
                drain_Timer = 20000 + rand()%10000;
            }else drain_Timer -= diff;

            if(prophecy_Timer < diff)
            {
                Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                if(ptarget && !(ptarget->HasAura(SPELL_BCBP_PROPHECY_BLOOD_1,0) || ptarget->HasAura(SPELL_BCBP_PROPHECY_BLOOD_2,0)))
                    DoCast(ptarget, rand()%2 == 0 ? SPELL_BCBP_PROPHECY_BLOOD_1 : SPELL_BCBP_PROPHECY_BLOOD_2);
                prophecy_Timer = 5000 + rand()%5000;
            }else prophecy_Timer -= diff;

            if(bolt_Timer < diff)
            {
                if (!me->IsNonMeleeSpellCasted(false))
                {
                    DoCast(me->getVictim(),SPELL_BCBP_BLOOD_BOLT);
                    bolt_Timer = 5000 + rand()%5000;
                }
            }else bolt_Timer -= diff;

            if(frenzy_Timer < diff)
            {
                DoCast(me,SPELL_BCBP_FRENZY);
                frenzy_Timer  = 30000+rand()%10000;
            }else frenzy_Timer -= diff;

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_mutant_war_houndAI : public mob_black_temple_tashAI
    {
        mob_mutant_war_houndAI(Creature *c) : mob_black_temple_tashAI(c){}

        void Reset()
        {
            DoCast(me,SPELL_DISEASE_CLOUD,true);

            mob_black_temple_tashAI::Reset();
        }

        void JustDied(Unit *victim)
        {
            DoCast(me,SPELL_CLOUD_OF_DISEASE,true);
        }
     

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_bonechewer_brawlerAI : public mob_black_temple_tashAI
    {
        mob_bonechewer_brawlerAI(Creature *c) : mob_black_temple_tashAI(c){}

        uint32 enrage_Timer;
        bool enraged;

        void Reset()
        {
            enrage_Timer = 10000 + rand()%10000;
            enraged = false;

            mob_black_temple_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(enrage_Timer < diff)
            {
                DoCast(me,SPELL_BCB_ENRAGE);
                enrage_Timer = 20000+ rand()%10000;
            }else enrage_Timer -= diff;

            if(!enraged)
                if((me->GetHealth() * 100 / me->GetMaxHealth()) < 20)
                {
                    enraged = true;
                    DoCast(me,SPELL_BCB_FRENZY,true);
                }

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_bonechewer_combatantAI : public mob_black_temple_tashAI
    {
        mob_bonechewer_combatantAI(Creature *c) : mob_black_temple_tashAI(c){}

        uint32 enrage_Timer;
        uint32 enraged;

        void Reset()
        {
            enrage_Timer = 100;

            mob_black_temple_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(enrage_Timer < diff)
            {
                if(!me->HasAura(SPELL_BCC_ENRAGE,0))
                    DoCast(me,SPELL_BCC_ENRAGE);
                enrage_Timer = 30000;
            }else enrage_Timer -= diff;

            if(!enraged)
                if((me->GetHealth() * 100 / me->GetMaxHealth()) < 20)
                {
                    enraged = true;
                    DoCast(me,SPELL_BCC_FRENZY,true);
                }


            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };

    struct  mob_bonechewer_spectatorAI : public mob_black_temple_tashAI
    {
        mob_bonechewer_spectatorAI(Creature *c) : mob_black_temple_tashAI(c){}

        uint32 random_Timer;

        void Reset()
        {
            random_Timer = 10000+ rand()%10000;

            mob_black_temple_tashAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(random_Timer < diff)
            {
                Unit* target;
                switch(rand()%6)
                {
                case 0:
                    target = SelectTarget(SELECT_TARGET_RANDOM, 1,30,true);
                    if(target && me->GetDistance2d(target) > 10)
                        DoCast(target,SPELL_BCSP_CHARGE);
                    break;
                case 1:
                    DoCast(me->getVictim(),SPELL_BCSP_CLEAVE);
                    break;
                case 2:
                    DoCast(me,SPELL_BCSP_FRENZY);
                    break;
                case 3:
                    DoCast(me->getVictim(),SPELL_BCSP_MORTAL_WOUND);
                    break;
                case 4:
                    DoCast(me->getVictim(),SPELL_BCSP_STRIKE);
                    break;
                case 5:
                    DoCast(me->getVictim(),SPELL_BCSP_SUNDER_ARMOR);
                    break;
                }
                random_Timer = 10000+ rand()%10000;
            }else random_Timer -= diff;

            mob_black_temple_tashAI::UpdateAI(diff);
        }
    };
};
void AddSC_black_temple()
{
    new npc_black_temple();
}
    /*
    UPDATE creature_template SET scriptname = 'mob_aqueous_lord' WHERE entry = 22878;
    UPDATE creature_template SET scriptname = 'mob_aqueous_spawn' WHERE entry = 22883;
    UPDATE creature_template SET scriptname = 'mob_coilskar_general' WHERE entry = 22873;
    -- UPDATE `creature_template` SET `mechanic_immune_mask` = 111362047 WHERE `entry` = 22873;
    UPDATE creature_template SET scriptname = 'mob_coilskar_wrangler' WHERE entry = 22877;
    UPDATE creature_template SET scriptname = 'mob_leviathan' WHERE entry = 22884;
    UPDATE creature_template SET scriptname = 'mob_coilskar_sea_caller' WHERE entry = 22875;
    -- UPDATE `creature_template` SET `mechanic_immune_mask` = 33561923 WHERE `entry` = 22875;
    -- update creature_template set minlevel = 73  , maxlevel = 73  , faction_A = 1813  , faction_H = 1813  , unit_flags = 33554434 where entry = 23080;
    UPDATE creature_template SET scriptname = 'mob_coilskar_geyser' WHERE entry = 23080;
    UPDATE creature_template SET scriptname = 'mob_coilskar_soothsayer' WHERE entry = 22876;
    UPDATE creature_template SET scriptname = 'mob_dragon_turtle' WHERE entry = 22885;
    UPDATE creature_template SET scriptname = 'mob_coilskar_harpooner' WHERE entry = 22874;
    UPDATE creature_template SET scriptname = 'mob_bonechewer_taskmaster' WHERE entry = 23028;
    -- insert into spell_script_target values (40851,1,22963);
    UPDATE creature_template SET scriptname = 'mob_bonechewer_worker' WHERE entry = 22963;
    UPDATE creature_template SET scriptname = 'mob_dragonmaw_sky_stalker' WHERE entry = 23030;
    UPDATE creature_template SET scriptname = 'mob_dragonmaw_wind_reaver' WHERE entry = 23330;
    UPDATE creature_template SET scriptname = 'mob_dragonmaw_wyrmcaller' WHERE entry = 22960;
    -- UPDATE `creature_template` SET `mechanic_immune_mask` = 614678523 WHERE `entry` = 22960;
    UPDATE creature_template SET scriptname = 'mob_illidari_fearbringer' WHERE entry = 22954;
    UPDATE creature_template SET scriptname = 'mob_illidari_nightlord' WHERE entry = 22855;
    UPDATE creature_template SET scriptname = 'mob_ashtongue_battlelord' WHERE entry = 22844;
    UPDATE creature_template SET scriptname = 'mob_ashtongue_feral_spirit' WHERE entry = 22849;
    UPDATE creature_template SET scriptname = 'mob_ashtongue_primalist' WHERE entry = 22847;
    UPDATE creature_template SET scriptname = 'mob_ashtongue_mystic' WHERE entry = 22845;
    UPDATE creature_template SET scriptname = 'mob_ashtongue_searing_totem' WHERE entry = 22896;
    UPDATE creature_template SET scriptname = 'mob_ashtongue_cyclone_totem' WHERE entry = 22894;
    UPDATE creature_template SET scriptname = 'mob_ashtongue_stalker' WHERE entry = 23374;
    UPDATE creature_template SET scriptname = 'mob_ashtongue_stormcaller' WHERE entry = 22846;
    UPDATE creature_template SET scriptname = 'mob_storm_fury' WHERE entry = 22848;
    UPDATE creature_template SET scriptname = 'mob_illidari_centurion' WHERE entry = 23337;
    UPDATE creature_template SET scriptname = 'mob_illidari_defiler' WHERE entry = 22853;
    -- UPDATE `creature_template` SET `mechanic_immune_mask` = 33554689 WHERE `entry` = 22853;
    UPDATE creature_template SET scriptname = 'mob_illidari_heartseeker' WHERE entry = 23339;
    UPDATE creature_template SET scriptname = 'mob_illidari_boneslicer' WHERE entry = 22869;
    UPDATE creature_template SET scriptname = "mob_priestess_of_dementia" WHERE entry = 22957;
    -- update `creature_template` SET `minlevel` = 72  , `maxlevel` = 72  , `faction_A` = 1813  , `faction_H` = 1813 WHERE `entry` = 23436;
    UPDATE creature_template SET scriptname = "mob_priestess_of_delight" WHERE entry = 22962;
    UPDATE creature_template SET scriptname = 'mob_sister_of_pain' WHERE entry = 22956;
    UPDATE creature_template SET scriptname = 'mob_sister_of_pleasure' WHERE entry = 22964;
    UPDATE creature_template SET scriptname = 'mob_charming_courtesan' WHERE entry = 22955;
    UPDATE creature_template SET scriptname = 'mob_temple_concubine' WHERE entry = 22939;
    UPDATE creature_template SET scriptname = 'mob_enslaved_servant' WHERE entry = 22965;
    UPDATE creature_template SET scriptname = 'mob_spellbound_attendant' WHERE entry = 22959;

    UPDATE creature_template SET scriptname = 'mob_suffering_soul_fragment' WHERE entry = 23399;
    UPDATE creature_template SET scriptname = 'mob_angered_soul_fragment' WHERE entry = 23398;
    UPDATE creature_template SET scriptname = 'mob_hungering_soul_fragment' WHERE entry = 23401;

    UPDATE creature_template SET scriptname = 'mob_illidari_battlemage' WHERE entry = 23402;
    UPDATE creature_template SET scriptname = 'mob_illidari_blood_lord' WHERE entry = 23397;
    UPDATE creature_template SET scriptname = 'mob_illidari_assassin' WHERE entry = 23403;
    UPDATE creature_template SET scriptname = 'mob_illidari_archon' WHERE entry = 23400;
    UPDATE creature_template SET scriptname = 'mob_promenade_sentinel' WHERE entry = 23394;
    UPDATE creature_template SET scriptname = 'mob_arcane_charge_L4' WHERE entry = 23429;
    -- update `creature_template` SET `minlevel` = 72  , `maxlevel` = 72  , `faction_A` = 16  , `faction_H` = 16 WHERE `entry` = 23429;

    UPDATE creature_template SET scriptname = 'mob_hand_of_gorefiend' WHERE entry = 23172;
    UPDATE creature_template SET scriptname = 'mob_shadowmoon_blood_mage' WHERE entry = 22945;
    UPDATE creature_template SET scriptname = 'mob_shadowmoon_soldier' WHERE entry = 23047;
    UPDATE creature_template SET scriptname = 'mob_shadowmoon_reaver' WHERE entry = 22879;
    UPDATE creature_template SET scriptname = 'mob_shadowmoon_deathshaper' WHERE entry = 22882;
    UPDATE creature_template SET scriptname = 'mob_shadowmoon_champion' WHERE entry = 22880;
    UPDATE creature_template SET scriptname = 'mob_whirling_blade' WHERE entry = 23369;
    -- UPDATE `creature_template` SET `minlevel` = 72  , `maxlevel` = 72  , `faction_A` = 16  , `faction_H` = 16  , `unit_flags` = 33554818 WHERE `entry` = 23369;
    UPDATE creature_template SET scriptname = 'mob_shadowmoon_houndmaster' WHERE entry = 23018;
    UPDATE creature_template SET scriptname = 'mob_shadowmoon_riding_hound' WHERE entry = 23083;
    UPDATE creature_template SET scriptname = 'mob_wrathbone_flayer' WHERE entry = 22953;
    UPDATE creature_template SET scriptname = 'mob_shadowmoon_weapon_master' WHERE entry = 23049;
    -- delete from creature_loot_template where item in (32609,32592,32591,32590,32589,32526) and entry = 23147;
    UPDATE creature_template SET scriptname = 'mob_bonechewer_behemoth' WHERE entry = 23196;
    -- delete from spell_scripts where id = 41213;
    -- insert into spell_scripts (id,delay,command,datalong) values (41213,0,15,41214);
    UPDATE creature_template SET scriptname = 'mob_bonechewer_shield_disciple' WHERE entry = 23236;
    UPDATE creature_template SET scriptname = 'mob_bonechewer_blade_fury' WHERE entry = 23235;
    UPDATE creature_template SET scriptname = 'mob_bonechewer_blood_prophet' WHERE entry = 23237;
    UPDATE creature_template SET scriptname = 'mob_mutant_war_hound' WHERE entry = 23232;
    UPDATE creature_template SET scriptname = 'mob_bonechewer_brawler' WHERE entry = 23222;
    UPDATE creature_template SET scriptname = 'mob_bonechewer_combatant' WHERE entry = 23239;
    UPDATE creature_template SET scriptname = 'mob_bonechewer_spectator' WHERE entry = 23223;
    */
