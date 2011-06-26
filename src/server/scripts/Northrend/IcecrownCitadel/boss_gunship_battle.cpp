/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
 *
 * Copyright (C) Blackcore, Desarrollo completo Blackcore.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 */
 
 /* % Completado: 92 %
  * Requiere datos de posiciones, correcciones y
  * concluir soporte SQL
  * Autor: Equipo de Desarrollo Blackcore
  */

#include "ScriptPCH.h"
#include "icecrown_citadel.h"
#include "MapManager.h"
#include "Transport.h"

/*
BIBLIA :
http://www.wowwiki.com/Gunship_Battle
*/

// Fusileros
#define NPC_ZAFOD_BOOMBOX                                       37184
#define ITEM_GOBLIN_ROCKET_PACK                         49278

const Position SpawnZafodAlliance               =       {0.0f, 0.0f, 0.0f, 0.0f};
const Position SpawnZafodHorde                  =       {0.0f, 0.0f, 0.0f, 0.0f};

#define ZAFOD_BOOMBOX_GOSSIP_GET                        1000
#define ZAFOD_BOOMBOX_GOSSIP_CANCEL                     1001

// Do_Action
#define DO_ACTION_START_GUNSHIP_BATTLE          0
#define DO_ACTION_FINISH_GUNSHIP_BATTLE         1

// tp de fin
const Position DeathbringerRise = { -549.80548f, 2211.19238f, 539.29119f, 6.27718f};

// Spawns de NPCs
#define SPAWN_SERGEANT                                          0
#define SPAWN_DISTANCE_0                                        1       // Soldado con Mortero o Lanza Cohetes
#define SPAWN_CAC                                                       2       // Infante de marina o Saqueador
#define SPAWN_CAST                                                      3       // Hechizero o Mago de batalla
#define SPAWN_DISTANCE_1                                        4       // Fusileros o Lanzadores de hachas

// Zonas de Spawns
const Position SpawnPosAlliance[] =
{
        {0.0f, 0.0f, 0.0f, 0.0f},
        {0.0f, 0.0f, 0.0f, 0.0f},
        {0.0f, 0.0f, 0.0f, 0.0f},
        {0.0f, 0.0f, 0.0f, 0.0f},
        {0.0f, 0.0f, 0.0f, 0.0f}
};
const Position SpawnPosHorde[] =
{
        {0.0f, 0.0f, 0.0f, 0.0f},
        {0.0f, 0.0f, 0.0f, 0.0f},
        {0.0f, 0.0f, 0.0f, 0.0f},
        {0.0f, 0.0f, 0.0f, 0.0f},
        {0.0f, 0.0f, 0.0f, 0.0f}
};

//-----------------------------------------------------------------------
// Alianza :
#define GO_SKYBREAKER                                           192242
#define GO_GUNSHIP_STAIRS_ALLIANCE                      201709  // Acceso innecesario, imposible
#define GO_ALLIANCE_GUNSHIP_PORTAL                      195371  // z Útiles ?
#define NPC_GUNSHIP_CANNON_ALLIANCE                     34929

#define SKYBREAKER_X                                            0
#define SKYBREAKER_Y                                            0
#define SKYBREAKER_Z                                            0
#define SKYBREAKER_RAYON                                        0

#define NPC_MURADIN_BRONZEBEARD                         36948

// Dialogos
#define ALLIANCE_GOSSIP_ACTION_START            10875
#define ALLIANCE_GOSSIP_ACTION_CANCEL           1001
#define ALLIANCE_GOSSIP_ACTION_TP                       1002

const Position PosMuradinBronzebeard[]=
{
    {-472.596f, 2466.8701f, 190.7371f, 6.204f}, // Primera posicion
    {0.0f, 0.0f, 0.0f, 0.0f}                                    // Segunda posicion
};

#define NPC_SKYBREAKER_SERGEANT                         36961
#define NPC_SKYBREAKER_MORTAR_SOLDIER           36978
#define NPC_SKYBREAKER_MARINE                           36950
#define NPC_SKYBREAKER_SORCERER                         37026
#define NPC_SKYBREAKER_RIFLEMAN                         36969

#define AURA_ON_SKYBREAKER                                      70120

//-----------------------------------------------------------------------

//-----------------------------------------------------------------------
// HORDA :
#define GO_OGRIM_HAMMER                                         192241
#define GO_GUNSHIP_STAIRS_HORDE                         202211  // Innecesario.
#define GO_HORDE_GUNSHIP_PORTAL                         196413  // z Útil ?
#define NPC_GUNSHIP_CANNON_HORDE                        34935

#define OGRIM_HAMMER_X                                          0
#define OGRIM_HAMMER_Y                                          0
#define OGRIM_HAMMER_Z                                          0
#define OGRIM_HAMMER_RAYON                                      0

#define NPC_HIGH_OVERLORD_VAROK_SAURFANG        36939

// Dialogos
#define HORDE_GOSSIP_ACTION_START                       10876
#define HORDE_GOSSIP_ACTION_CANCEL                      1004
#define HORDE_GOSSIP_ACTION_TP                          1005

const Position PosHighOverlordVarokSaurfang[]=
{
        {0.0f, 0.0f, 0.0f, 0.0f},       // Primera posicion
    {0.0f, 0.0f, 0.0f, 0.0f}    // Segunda posicion
};

#define NPC_KORKRON_SERGEANT                            36960
#define NPC_KORKRON_ROCKETEER                           36982
#define NPC_KORKRON_REAVER                                      36957
#define NPC_KORKRON_BATTLE_MAGE                         37117
#define NPC_KORKRON_AXETHROWER                          36968

#define AURA_ON_OGRIM_HAMMER                            70121

//-----------------------------------------------------------------------

// CANON_GUNSHIP
#define SPELL_CANNON_BLAST                                      69400
#define SPELL_INCINERATING_BLAST                        69402

// MURADIN BARBABRONCE// ALTO_SENOR_SUPREMO_COLMILLOSAURIO
#define SPELL_CLEAVE                                            15284
#define SPELL_RENDING_THROW                                     70309
#define SPELL_TASTE_OF_BLOOD                            69634

#define AURA_BATTLE_FURY_10                                     72306
#define AURA_BATTLE_FURY_25                                     72307

// TODOS LOS ENEMIGOS TIENEN ESTE HECHIZO EXCEPTO LOS COMANDANTES
#define SPELL_BURNING_PITCH                                     71335

// HECHICERO // MAGO_DE_BATALLA
#define SPELL_BELOW_ZERO                                        69705

// SOLDADO_CON_MORTERO // LANZACOHETES
#define SPELL_ROCKET_ARTILLERY                          69679
#define SPELL_EXPLOSION                                         69680   // Efecto, cuando el cohete explosiona en el suelo.

// SARGENTO
#define SPELL_BLADESTORM                                        69652
#define SPELL_BLADESTORM_TRIGGER                        69653   // Uso innecesario SPELL_BLADESTORM
#define SPELL_DESPERATE_RESOLVE_10_NM           69647
#define SPELL_DESPERATE_RESOLVE_10_HM           72537
#define SPELL_DESPERATE_RESOLVE_25_NM           72536
#define SPELL_DESPERATE_RESOLVE_25_HM           72538
#define SPELL_WOUNDING_STRIKE_10_NM                     69651
#define SPELL_WOUNDING_STRIKE_10_HM                     72570
#define SPELL_WOUNDING_STRIKE_25_NM                     72569
#define SPELL_WOUNDING_STRIKE_25_HM                     72571

// FUSILEROS
#define SPELL_SHOOT_10_NM                                       70162
#define SPELL_SHOOT_10_HM                                       72567
#define SPELL_SHOOT_25_NM                                       72566
#define SPELL_SHOOT_25_HM                                       72568

// LANZADORES_DE_HACHAS
#define SPELL_HURL_AXE_10_NM                            70161
#define SPELL_HURL_AXE_10_HM                            72540
#define SPELL_HURL_AXE_25_NM                            72539
#define SPELL_HURL_AXE_25_HM                            72541

// BUFFOS_DE_EXPERIENCIA
#define SPELL_EXPERIENCED                                       71188
#define SPELL_VETERAN                                           71193
#define SPELL_ELITE                                                     71195

//-----------------------------------------------------------------------
//------------------------------ GRITOS ----------------------------------
//-----------------------------------------------------------------------
// HORDA ----------------------------------------------------------------
//-----------------------------------------------------------------------
// PRIMERA_ESCUADRA_ASISTIDA
#define SAY_KORKRON_FIRST_SQUAD_0       "Thank the spirits for you, brothers and sisters. The Skybreaker has already left. Quickly now, to Orgrim's Hammer! If you leave soon, you may be able to catch them."
#define SAY_KORKRON_FIRST_SQUAD_1       "This should be helpin'ya!"

// SEGUNDA_ESCUADRA_ASISTIDA
#define SAY_KORKRON_SECOND_SQUAD_0      "Aka'Magosh, brave warriors. The alliance is in great number here."
#define SAY_KORKRON_SECOND_SQUAD_1      "Captain Saurfang will be pleased to see you aboard Orgrim's Hammer. Make haste, we will secure the area until you are ready for take-off."

// COMIENZA_EL_EVENTO
#define YELL_EVENT_BEGIN_HORDE_HIGH_OVERLORD_SAURFANG_0 "Rise up, sons and daughters of the Horde! Today we battle a hated enemy of the Horde! LOK'TAR OGAR! Kor'kron, take us out!"
#define YELL_EVENT_BEGIN_HORDE_HIGH_OVERLORD_SAURFANG_1 "What is that?! Something approaching in the distance!"
#define YELL_EVENT_BEGIN_HORDE_HIGH_OVERLORD_SAURFANG_2 "ALLIANCE GUNSHIP! ALL HANDS ON DECK!"
#define YELL_EVENT_BEGIN_HORDE_MURADIN_BRONZEBEARD_0    "Move yer jalopy or we'll blow it out of the sky, orc! The Horde's got no business here!"
#define YELL_EVENT_BEGIN_HORDE_HIGH_OVERLORD_SAURFANG_3 "You will know our business soon! KOR'KRON, ANNIHILATE THEM!"

// EMBARQUE AL MARTILLO ORGRIMMAR
#define YELL_BOARDING_ORGRIM_S_HAMMER_MURADIN_BRONZEBEARD_0             "Marines, Sergeants, attack!"
#define YELL_BOARDING_ORGRIM_S_HAMMER_HIGH_OVERLORD_SAURFANG_0  "You DARE board my ship? Your death will come swiftly."

// NUEVO_FUSILERO
#define YELL_NEW_RIFLEMEN_MURADIN               "Riflemen, shoot faster!"
// NUEVO_EQUIPO_DE_MORTERO
#define YELL_NEW_MORTAR_TEAM_MURADIN    "Mortar team, reload!"
// NUEVO_MAGO
#define YELL_NEW_MAGE_MURADIN                   "We're taking hull damage, get a sorcerer out here to shut down those cannons!"
// VICTORIA_HORDA
#define YELL_HORDE_VICTORY_SAURFANG             "The Alliance falter. Onward to the Lich King!"
// DERROTA_HORDA
#define YELL_HORDE_DEFEAT_SAURFANG              "Damage control! Put those fires out! You haven't seen the last of the Horde!"

// ALIANZA -------------------------------------------------------------
//-----------------------------------------------------------------------
// PRIMERA_ESCUADRA_ASISTIDA
#define SAY_SKYBREAKER_FIRST_SQUAD_0    "Thank goodness you arrived when you did, heroes. Orgrim's Hammer has already left. Quickly now, to The Skybreaker! If you leave soon, you may be able to catch them."
#define SAY_SKYBREAKER_FIRST_SQUAD_1    "This ought to help!"

// SEGUNDA_ESCUADRA_ASISTIDA
#define SAY_SKYBREAKER_SECOND_SQUAD_0   "You have my thanks. We were outnumbered until you arrived."
#define SAY_SKYBREAKER_SECOND_SQUAD_1   "Captain Muradin is waiting aboard The Skybreaker. We'll secure the area until you are ready for take off."
#define SAY_SKYBREAKER_SECOND_SQUAD_2   "Skybreaker infantry, hold position!"

// COMIENZA_EL_EVENTO
#define YELL_EVENT_BEGIN_ALLIANCE_MURADIN_BRONZEBEARD_0         "Fire up the engines! We got a meetin' with destiny, lads!"
#define YELL_EVENT_BEGIN_ALLIANCE_MURADIN_BRONZEBEARD_1         "Hold on to yer hats!"
#define YELL_EVENT_BEGIN_ALLIANCE_MURADIN_BRONZEBEARD_2         "What in the world is that? Grab me spyglass, crewman!"
#define YELL_EVENT_BEGIN_ALLIANCE_MURADIN_BRONZEBEARD_3         "By me own beard! HORDE SAILIN' IN FAST 'N HOT!"
#define YELL_EVENT_BEGIN_ALLIANCE_MURADIN_BRONZEBEARD_4         "EVASIVE ACTION! MAN THE GUNS!"
#define YELL_EVENT_BEGIN_ALLIANCE_MURADIN_BRONZEBEARD_5         "Cowardly dogs! Ye blindsided us!"
#define YELL_EVENT_BEGIN_ALLIANCE_HIGH_OVERLORD_SAURFANG_0      "This is not your battle, dwarf. Back down or we will be forced to destroy your ship."
#define YELL_EVENT_BEGIN_ALLIANCE_MURADIN_BRONZEBEARD_6         "Not me battle? I dunnae who ye? think ye are, mister, but I got a score to settle with Arthas and yer not gettin' in me way! FIRE ALL GUNS! FIRE! FIRE!"

// EMBARCANDO_EL_ROMPECIELOS
#define YELL_BOARDING_THE_SKYBREAKER_HIGH_OVERLORD_SAURFANG_0   "Reavers, Sergeants, attack!"
#define YELL_BOARDING_THE_SKYBREAKER_MURADIN_BRONZEBEARD_0              "What's this then?! Ye won't be takin' this son o' Ironforge's vessel without a fight!."

// NUEVO_LANZAHACHAS
#define YELL_NEW_AXETHROWERS_HIGH_OVERLORD_SAURFANG_0   "Axethrowers, hurl faster!"

// NUEVO_FUSILEROS
#define YELL_NEW_ROCKETEERS_HIGH_OVERLORD_SAURFANG_0    "Rocketeers, reload!"

// NUEVO_MAGO_DE_BATALLA
#define YELL_NEW_BATTLE_MAGE_HIGH_OVERLORD_SAURFANG_0   "We're taking hull damage, get a battle-mage out here to shut down those cannons!"

// VICTORIA_ALIANZA
#define YELL_ALLIANCE_VICTORY_MURADIN_BRONZEBEARD_0             "Don't say I didn't warn ya, scoundrels! Onward, brothers and sisters!"

// DERROTA_ALIANZA
#define YELL_ALLIANCE_DEFEAT_MURADIN_BRONZEBEARD_0              "Captain Bartlett, get us out of here! We're taken too much damage to stay afloat!"


//-----------------------------------------------------------------------
#define SPELL_ACHIEVEMENT                                                               72959

//-----------------------------------------------------------------------
#define PHASE_NOT_STARTED       0
#define PHASE_DISTANCE          1
#define PHASE_BOARDING          2
#define PHASE_END                       3

#define EXP_NULL                        0
#define EXP_EXPERIENCED         20000
#define EXP_VETERAN                     40000
#define EXP_ELITE                       80000

//-----------------------------------------------------------------------

void buffExp( ScriptedAI * _script, uint32 timer_Spawn)
{
        if( timer_Spawn < EXP_EXPERIENCED)
                return;
        if( timer_Spawn > EXP_EXPERIENCED && timer_Spawn < EXP_VETERAN) {
                _script->DoCast( _script->me, SPELL_EXPERIENCED);
                return;
        }
        if( timer_Spawn > EXP_VETERAN && timer_Spawn < EXP_ELITE) {
                _script->DoCast( _script->me, SPELL_VETERAN);
                return;
        }
        if( timer_Spawn > EXP_ELITE) {
                _script->DoCast( _script->me, SPELL_ELITE);
                return;
        }
}

class npc_zafod_boombox : public CreatureScript
{
        public:
                npc_zafod_boombox() : CreatureScript("npc_zafod_boombox") { }

                struct npc_zafod_boomboxAI : public ScriptedAI
                {
                        npc_zafod_boomboxAI(Creature* pCreature) : ScriptedAI(pCreature)
            { pInstance = me->GetInstanceScript(); }

                        void UpdateAI( const uint32 diff) { }

                        InstanceScript* pInstance;
                };

                bool OnGossipHello(Player* pPlayer, Creature* pCreature)
        {
                        if ( pCreature->GetInstanceScript()->GetBossState(DATA_GUNSHIP_BATTLE_EVENT) == NOT_STARTED ||
                                 pCreature->GetInstanceScript()->GetBossState(DATA_GUNSHIP_BATTLE_EVENT) == DONE)
                return false;

                        pPlayer->ADD_GOSSIP_ITEM(49278, "Give me one of these machines", 1000, ZAFOD_BOOMBOX_GOSSIP_GET);
                        pPlayer->ADD_GOSSIP_ITEM(0, "Maybe later", 1001, ZAFOD_BOOMBOX_GOSSIP_CANCEL);
                        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());

                        return true;
                }

                bool OnGossipSelect(Player* player, Creature* pCreature, uint32 /*sender*/, uint32 action)
                {
                        player->PlayerTalkClass->ClearMenus();
                        player->CLOSE_GOSSIP_MENU();

                        switch( action) {
                                case    ALLIANCE_GOSSIP_ACTION_START    :
                                                        pCreature->AI()->DoAction( DO_ACTION_START_GUNSHIP_BATTLE); // lancement de la cannonicre !
                                                        return true;
                                case    ALLIANCE_GOSSIP_ACTION_TP               :
                                                        pCreature->AI()->DoAction( DO_ACTION_FINISH_GUNSHIP_BATTLE); // aprcs fin de la cannonicre !
                                                        return true;
                                case    ALLIANCE_GOSSIP_ACTION_CANCEL   :
                                                        return true;
                        };

                        return false;
                }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_zafod_boomboxAI(pCreature);
        }
};

class boss_muradin_bronzebeard : public CreatureScript
{
    public:
        boss_muradin_bronzebeard() : CreatureScript("boss_muradin_bronzebeard") { }

                struct boss_muradin_bronzebardAI : public BossAI
                {
                        boss_muradin_bronzebardAI(Creature* pCreature) : BossAI(pCreature, DATA_GUNSHIP_BATTLE_EVENT)
            {
                                instance->SetBossState( DATA_GUNSHIP_BATTLE_EVENT, NOT_STARTED);

                                instance->SetData( DATA_GUNSHIP_EVENT, PHASE_NOT_STARTED);

                                bDialog = false;
                                dialogID = 0;
                                dialogTimer = 0;
                        }

                        void Reset()
                        {
                                timer_Cleave            =       urand( 8000, 10000);
                                timer_RendingThrow      =       urand( 10000, 12000);
                                timer_TasteOfBlood      =       0;      // -40%

                                bDialog = false;
                                dialogID = 0;
                                dialogTimer = 0;
                        }

                        void DamageTaken(Unit* /*done_by*/, uint32& damage)
                        {
                                if( !bBattleStart)
                                        damage = 0;
                        }

                        void EnterCombat(Unit* /*who*/)
                        {
                        }

                        void Spawn( uint32 code)
                        {
                                uint8 spawn = floor( (long double) urand( 0, 5));
                                switch( code) {
                                        case    SPAWN_SERGEANT          :
                                                lSummons.push_back( DoSpawnCreature( NPC_KORKRON_SERGEANT, SpawnPosHorde[spawn].GetPositionX(), SpawnPosHorde[spawn].GetPositionY(), SpawnPosHorde[spawn].GetPositionZ(), SpawnPosHorde[spawn].GetOrientation(), TEMPSUMMON_DEAD_DESPAWN,0));
                                                break;
                                        case    SPAWN_DISTANCE_0        :
                                                lSummons.push_back( DoSpawnCreature( NPC_KORKRON_ROCKETEER, SpawnPosHorde[spawn].GetPositionX(), SpawnPosHorde[spawn].GetPositionY(), SpawnPosHorde[spawn].GetPositionZ(), SpawnPosHorde[spawn].GetOrientation(), TEMPSUMMON_DEAD_DESPAWN,0));
                                                break;
                                        case    SPAWN_CAC                       :
                                                lSummons.push_back( DoSpawnCreature( NPC_KORKRON_REAVER, SpawnPosHorde[spawn].GetPositionX(), SpawnPosHorde[spawn].GetPositionY(), SpawnPosHorde[spawn].GetPositionZ(), SpawnPosHorde[spawn].GetOrientation(), TEMPSUMMON_DEAD_DESPAWN,0));
                                                break;
                                        case    SPAWN_CAST                      :
                                                lSummons.push_back( DoSpawnCreature( NPC_KORKRON_BATTLE_MAGE, SpawnPosHorde[spawn].GetPositionX(), SpawnPosHorde[spawn].GetPositionY(), SpawnPosHorde[spawn].GetPositionZ(), SpawnPosHorde[spawn].GetOrientation(), TEMPSUMMON_DEAD_DESPAWN,0));
                                                break;
                                        case    SPAWN_DISTANCE_1        :
                                                lSummons.push_back( DoSpawnCreature( NPC_KORKRON_AXETHROWER, SpawnPosHorde[spawn].GetPositionX(), SpawnPosHorde[spawn].GetPositionY(), SpawnPosHorde[spawn].GetPositionZ(), SpawnPosHorde[spawn].GetOrientation(), TEMPSUMMON_DEAD_DESPAWN,0));
                                                break;
                                };
                        }

                        void Start()
                        {
                                //zafodBoombox = DoSpawnCreature( NPC_ZAFOD_BOOMBOX, SpawnPosHorde[spawn].GetPositionX(), SpawnPosHorde[spawn].GetPositionY(), SpawnPosHorde[spawn].GetPositionZ(), SpawnPosHorde[spawn].GetOrientation(), TEMPSUMMON_DEAD_DESPAWN,0)
                                
                        }

                        void UpdateAI( const uint32 diff) 
                        {
                                if( bDialog) {
                                        if( dialogTimer <= diff) {
                                                switch( dialogID) {

                                                // START_EVENT
                                                        case    0       :
                                                                me->MonsterYell( YELL_EVENT_BEGIN_ALLIANCE_MURADIN_BRONZEBEARD_0, LANG_UNIVERSAL, 0);
                                                                dialogID = 1;
                                                                dialogTimer = 2000;
                                                                break;
                                                        case    1       :
                                                                me->MonsterYell( YELL_EVENT_BEGIN_ALLIANCE_MURADIN_BRONZEBEARD_1, LANG_UNIVERSAL, 0);
                                                                dialogID = 2;
                                                                dialogTimer = 2000;
                                                                break;
                                                        case    2       :
                                                                me->MonsterYell( YELL_EVENT_BEGIN_ALLIANCE_MURADIN_BRONZEBEARD_2, LANG_UNIVERSAL, 0);
                                                                dialogID = 3;
                                                                dialogTimer = 2000;
                                                                break;
                                                        case    3       :
                                                                me->MonsterYell( YELL_EVENT_BEGIN_ALLIANCE_MURADIN_BRONZEBEARD_3, LANG_UNIVERSAL, 0);
                                                                dialogID = 4;
                                                                dialogTimer = 2000;
                                                                break;
                                                        case    4       :
                                                                me->MonsterYell( YELL_EVENT_BEGIN_ALLIANCE_MURADIN_BRONZEBEARD_4, LANG_UNIVERSAL, 0);
                                                                dialogID = 5;
                                                                dialogTimer = 2000;
                                                                break;
                                                        case    5       :
                                                                me->MonsterYell( YELL_EVENT_BEGIN_ALLIANCE_MURADIN_BRONZEBEARD_5, LANG_UNIVERSAL, 0);
                                                                dialogID = 6;
                                                                dialogTimer = 2000;
                                                                break;
                                                        case    6       :
                                                                if( Creature* pHighOverlordSaurfang = Unit::GetCreature(*me, instance->GetData64( NPC_HIGH_OVERLORD_VAROK_SAURFANG))) {
                                                                        pHighOverlordSaurfang->MonsterYell( YELL_EVENT_BEGIN_ALLIANCE_HIGH_OVERLORD_SAURFANG_0, LANG_UNIVERSAL, 0);
                                                                        dialogID = 7;
                                                                        dialogTimer = 2000;
                                                                }
                                                                break;
                                                        case    7       :
                                                                me->MonsterYell( YELL_EVENT_BEGIN_ALLIANCE_MURADIN_BRONZEBEARD_6, LANG_UNIVERSAL, 0);
                                                                dialogID = 8;
                                                                dialogTimer = 2000;
                                                                break;
                                                        case    8       :
                                                                {
                                                                        Position tp = PosMuradinBronzebeard[1];
                                                                        Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();
                                                                        if( !PlayerList.isEmpty()) {
                                                                                for(Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i) {
                                                                                        if( Player *pCurrent = i->getSource()) {
                                                                                                if( me->GetDistance(pCurrent) <= 100.0f)
                                                                                                        DoTeleportPlayer( pCurrent, tp.GetPositionX(), tp.GetPositionY(), tp.GetPositionZ(), tp.GetOrientation());
                                                                                        }
                                                                                }
                                                                        }

                                                                        me->SetPosition( tp, true);
                                                                        dialogID = 9;
                                                                        dialogTimer = 10000;
                                                                }
                                                                break;

                                                // EMBARQUE_EVENTO
                                                        case    9       :
                                                                if( Creature* pHighOverlordSaurfang = Unit::GetCreature(*me, instance->GetData64( NPC_HIGH_OVERLORD_VAROK_SAURFANG))) {
                                                                        pHighOverlordSaurfang->MonsterYell( YELL_BOARDING_ORGRIM_S_HAMMER_HIGH_OVERLORD_SAURFANG_0, LANG_UNIVERSAL, 0);
                                                                        dialogID = 10;
                                                                        dialogTimer = 2000;
                                                                }
                                                                break;
                                                        case    10      :
                                                                me->MonsterYell( YELL_BOARDING_ORGRIM_S_HAMMER_MURADIN_BRONZEBEARD_0, LANG_UNIVERSAL, 0);
                                                                dialogID = 11;
                                                                dialogTimer = 2000;
                                                                break;
                                                        case    11      :
                                                                // BEGINNING OF THE BATTLE OF ROYALTIES !
                                                                this->Start();
                                                                break;
                                                };
                                        } else dialogTimer -= diff;
                                } else

                                if( bBattleStart) {
                                        if (!UpdateVictim())
                                                return;
                                
                                        if( ( me->GetHealth() / me->GetMaxHealth()) <= 0.4) {
                                                if( timer_TasteOfBlood <= diff) {
                                                        DoCast( me, SPELL_TASTE_OF_BLOOD);
                                                        timer_TasteOfBlood = 120000;
                                                } else timer_TasteOfBlood -= diff;
                                        }
                                
                                        if( timer_Cleave <= diff) {
                                                DoCastVictim( SPELL_CLEAVE);
                                                timer_Cleave = urand( 8000, 10000);
                                        } else timer_Cleave -= diff;

                                        if( timer_RendingThrow <= diff) {
                                                DoCastVictim( SPELL_RENDING_THROW);
                                                timer_RendingThrow = urand( 10000, 12000);
                                        } else timer_RendingThrow -= diff;

                                        DoMeleeAttackIfReady();
                                }
                        }

                        void DoAction(const int32 param)
                        {
                                switch( param) {
                                        case    DO_ACTION_START_GUNSHIP_BATTLE  :
                                                health_theSkybreaker = RAID_MODE( 600000, 1200000);
                                                health_ogrimsHammer = RAID_MODE( 600000, 1200000);

                                                instance->SetBossState( DATA_GUNSHIP_BATTLE_EVENT, NOT_STARTED);
                                                instance->SetData( DATA_GUNSHIP_EVENT, PHASE_NOT_STARTED);

                                                bDialog = true;
                                                dialogID = 0;
                                                dialogTimer = 0;
                                                break;

                                        case    DO_ACTION_FINISH_GUNSHIP_BATTLE :
                                                Position tp = DeathbringerRise;
                                                Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();
                                                if( !PlayerList.isEmpty()) {
                                                        for(Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i) {
                                                                if( Player *pCurrent = i->getSource()) {
                                                                        if( me->GetDistance(pCurrent) <= 100.0f)
                                                                                DoTeleportPlayer( pCurrent, tp.GetPositionX(), tp.GetPositionY(), tp.GetPositionZ(), tp.GetOrientation());
                                                                }
                                                        }
                                                }
                                                break;
                                };
                        }

                        uint32 health_theSkybreaker;
                        uint32 health_ogrimsHammer;

                        std::list<Creature*> lSummons;
                        Creature* zafodBoombox;

                        uint32 timer_Cleave;
                        uint32 timer_RendingThrow;
                        uint32 timer_TasteOfBlood;

                        bool bBattleStart;
                        bool bDialog;
                        uint32 dialogID;
                        uint32 dialogTimer;
                };
                
        bool OnGossipHello(Player* pPlayer, Creature* pCreature)
        {
            if ( pPlayer->GetTeamId() == TEAM_HORDE)
                return false;

            InstanceScript* pInstance = pCreature->GetInstanceScript();
            if (pInstance && pInstance->GetBossState(DATA_GUNSHIP_BATTLE_EVENT) == NOT_STARTED)
            {
                                pPlayer->ADD_GOSSIP_ITEM(0, "My allies are in good condition, Muradin, Forward", 10875, ALLIANCE_GOSSIP_ACTION_START);
                                pPlayer->ADD_GOSSIP_ITEM(0, "Return Later", 631, ALLIANCE_GOSSIP_ACTION_CANCEL);
                                pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());

                                return true;
                        }

            if (pInstance && pInstance->GetBossState(DATA_GUNSHIP_BATTLE_EVENT) == DONE)
            {
                                pPlayer->ADD_GOSSIP_ITEM(0, "Go to the top of the Deathbringer", 10876, ALLIANCE_GOSSIP_ACTION_TP);
                                pPlayer->ADD_GOSSIP_ITEM(0, "Return Later", 631, ALLIANCE_GOSSIP_ACTION_CANCEL);
                                pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());

                                return true;
                        }
            return false;
        }

                bool OnGossipSelect(Player* player, Creature* pCreature, uint32 /*sender*/, uint32 action)
                {
                        player->PlayerTalkClass->ClearMenus();
                        player->CLOSE_GOSSIP_MENU();

                        switch( action) {
                                case    ALLIANCE_GOSSIP_ACTION_START    :
                                                        pCreature->AI()->DoAction( DO_ACTION_START_GUNSHIP_BATTLE); // ? Lanzamiento de los Canones !
                                                        return true;
                                case    ALLIANCE_GOSSIP_ACTION_TP               :
                                                        pCreature->AI()->DoAction( DO_ACTION_FINISH_GUNSHIP_BATTLE); // ? Fin de los canones !
                                                        return true;
                                case    ALLIANCE_GOSSIP_ACTION_CANCEL   :
                                                        return true;
                        };

                        return false;
                }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new boss_muradin_bronzebardAI(pCreature);
        }
};

class boss_high_overlord_varok_saurfang : public CreatureScript
{
    public:
                boss_high_overlord_varok_saurfang() : CreatureScript("boss_high_overlord_varok_saurfang") { }

                struct boss_high_overlord_varok_saurfangAI : public BossAI
                {
                        boss_high_overlord_varok_saurfangAI(Creature* pCreature) : BossAI(pCreature, DATA_GUNSHIP_BATTLE_EVENT)
            {
                                instance->SetBossState( DATA_GUNSHIP_BATTLE_EVENT, NOT_STARTED);

                                instance->SetData( DATA_GUNSHIP_EVENT, PHASE_NOT_STARTED);

                                bDialog = false;
                                dialogID = 0;
                                dialogTimer = 0;
                        }

                        void Reset()
                        {
                                timer_Cleave            =       urand( 8000, 10000);
                                timer_RendingThrow      =       urand( 10000, 12000);
                                timer_TasteOfBlood      =       0;      // -40%

                                bDialog = false;
                                dialogID = 0;
                                dialogTimer = 0;
                        }
                        
                        void DamageTaken(Unit* /*done_by*/, uint32& damage)
                        {
                                if( !bBattleStart)
                                        damage = 0;
                        }

                        void EnterCombat(Unit* /*who*/)
                        {
                        }
                        
                        void Spawn( uint32 code)
                        {
                                uint8 spawn = floor( (long double) urand( 0, 5));
                                switch( code) {
                                        case    SPAWN_SERGEANT          :
                                                lSummons.push_back( DoSpawnCreature( NPC_SKYBREAKER_SERGEANT, SpawnPosAlliance[spawn].GetPositionX(), SpawnPosAlliance[spawn].GetPositionY(), SpawnPosAlliance[spawn].GetPositionZ(), SpawnPosAlliance[spawn].GetOrientation(), TEMPSUMMON_DEAD_DESPAWN,0));
                                                break;
                                        case    SPAWN_DISTANCE_0        :
                                                lSummons.push_back( DoSpawnCreature( NPC_SKYBREAKER_MORTAR_SOLDIER, SpawnPosAlliance[spawn].GetPositionX(), SpawnPosAlliance[spawn].GetPositionY(), SpawnPosAlliance[spawn].GetPositionZ(), SpawnPosAlliance[spawn].GetOrientation(), TEMPSUMMON_DEAD_DESPAWN,0));
                                                break;
                                        case    SPAWN_CAC                       :
                                                lSummons.push_back( DoSpawnCreature( NPC_SKYBREAKER_MARINE, SpawnPosAlliance[spawn].GetPositionX(), SpawnPosAlliance[spawn].GetPositionY(), SpawnPosAlliance[spawn].GetPositionZ(), SpawnPosAlliance[spawn].GetOrientation(), TEMPSUMMON_DEAD_DESPAWN,0));
                                                break;
                                        case    SPAWN_CAST                      :
                                                lSummons.push_back( DoSpawnCreature( NPC_SKYBREAKER_SORCERER, SpawnPosAlliance[spawn].GetPositionX(), SpawnPosAlliance[spawn].GetPositionY(), SpawnPosAlliance[spawn].GetPositionZ(), SpawnPosAlliance[spawn].GetOrientation(), TEMPSUMMON_DEAD_DESPAWN,0));
                                                break;
                                        case    SPAWN_DISTANCE_1        :
                                                lSummons.push_back( DoSpawnCreature( NPC_SKYBREAKER_RIFLEMAN, SpawnPosAlliance[spawn].GetPositionX(), SpawnPosAlliance[spawn].GetPositionY(), SpawnPosAlliance[spawn].GetPositionZ(), SpawnPosAlliance[spawn].GetOrientation(), TEMPSUMMON_DEAD_DESPAWN,0));
                                                break;
                                };
                        }

                        void UpdateAI( const uint32 diff) 
                        {
                                if( bDialog) {
                                        if( dialogTimer <= diff) {
                                                switch( dialogID) {

                                                // COMIENZA_EL_EVENTO
                                                        case    0       :
                                                                me->MonsterYell( YELL_EVENT_BEGIN_HORDE_HIGH_OVERLORD_SAURFANG_0, LANG_UNIVERSAL, 0);
                                                                dialogID = 1;
                                                                dialogTimer = 2000;
                                                                break;
                                                        case    1       :
                                                                me->MonsterYell( YELL_EVENT_BEGIN_HORDE_HIGH_OVERLORD_SAURFANG_1, LANG_UNIVERSAL, 0);
                                                                dialogID = 2;
                                                                dialogTimer = 2000;
                                                                break;
                                                        case    2       :
                                                                me->MonsterYell( YELL_EVENT_BEGIN_HORDE_HIGH_OVERLORD_SAURFANG_2, LANG_UNIVERSAL, 0);
                                                                dialogID = 3;
                                                                dialogTimer = 2000;
                                                                break;
                                                        case    3       :
                                                                if( Creature* pMuradinBronzebeard = Unit::GetCreature(*me, instance->GetData64( NPC_MURADIN_BRONZEBEARD))) {
                                                                        pMuradinBronzebeard->MonsterYell( YELL_EVENT_BEGIN_HORDE_MURADIN_BRONZEBEARD_0, LANG_UNIVERSAL, 0);
                                                                        dialogID = 4;
                                                                        dialogTimer = 2000;
                                                                }
                                                                break;
                                                        case    4       :
                                                                me->MonsterYell( YELL_EVENT_BEGIN_HORDE_HIGH_OVERLORD_SAURFANG_3, LANG_UNIVERSAL, 0);
                                                                dialogID = 5;
                                                                dialogTimer = 2000;
                                                                break;
                                                        case    5       :
                                                                {
                                                                        Position tp = PosHighOverlordVarokSaurfang[1];
                                                                        Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();
                                                                        if( !PlayerList.isEmpty()) {
                                                                                for(Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i) {
                                                                                        if( Player *pCurrent = i->getSource()) {
                                                                                                if( me->GetDistance(pCurrent) <= 100.0f)
                                                                                                        DoTeleportPlayer( pCurrent, tp.GetPositionX(), tp.GetPositionY(), tp.GetPositionZ(), tp.GetOrientation());
                                                                                        }
                                                                                }
                                                                        }

                                                                        me->SetPosition( tp, true);
                                                                        dialogID = 6;
                                                                        dialogTimer = 10000;
                                                                }
                                                                break;

                                                // EMBARQUE_EVENTO
                                                        case    6       :
                                                                if( Creature* pMuradinBronzebeard = Unit::GetCreature(*me, instance->GetData64( NPC_MURADIN_BRONZEBEARD))) {
                                                                        pMuradinBronzebeard->MonsterYell( YELL_BOARDING_ORGRIM_S_HAMMER_MURADIN_BRONZEBEARD_0, LANG_UNIVERSAL, 0);
                                                                        dialogID = 7;
                                                                        dialogTimer = 2000;
                                                                }
                                                                break;
                                                        case    7       :
                                                                me->MonsterYell( YELL_BOARDING_ORGRIM_S_HAMMER_HIGH_OVERLORD_SAURFANG_0, LANG_UNIVERSAL, 0);
                                                                dialogID = 8;
                                                                dialogTimer = 2000;
                                                                break;
                                                        case    8       :
                                                                // ? COMIENZO DE LA BATALLA DE LOS CANONES !
                                                                
                                                                
                                                                break;
                                                };
                                        } else dialogTimer -= diff;
                                }

                                if( bBattleStart) {
                                        if (!UpdateVictim())
                                                return;
                                
                                        if( ( me->GetHealth() / me->GetMaxHealth()) <= 0.4) {
                                                if( timer_TasteOfBlood <= diff) {
                                                        DoCast( me, SPELL_TASTE_OF_BLOOD);
                                                        timer_TasteOfBlood = 120000;
                                                } else timer_TasteOfBlood -= diff;
                                        }
                                
                                        if( timer_Cleave <= diff) {
                                                DoCastVictim( SPELL_CLEAVE);
                                                timer_Cleave = urand( 8000, 10000);
                                        } else timer_Cleave -= diff;

                                        if( timer_RendingThrow <= diff) {
                                                DoCastVictim( SPELL_RENDING_THROW);
                                                timer_RendingThrow = urand( 10000, 12000);
                                        } else timer_RendingThrow -= diff;

                                        DoMeleeAttackIfReady();
                                }
                        }

                        void DoAction(const int32 param)
                        {
                                switch( param) {
                                        case    DO_ACTION_START_GUNSHIP_BATTLE  :
                                                health_theSkybreaker = RAID_MODE( 600000, 1200000);
                                                health_ogrimsHammer = RAID_MODE( 600000, 1200000);

                                                instance->SetBossState( DATA_GUNSHIP_BATTLE_EVENT, NOT_STARTED);
                                                instance->SetData( DATA_GUNSHIP_EVENT, PHASE_NOT_STARTED);

                                                bDialog = true;
                                                dialogID = 0;
                                                dialogTimer = 0;
                                                break;

                                        case    DO_ACTION_FINISH_GUNSHIP_BATTLE :
                                                Position tp = DeathbringerRise;
                                                Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();
                                                if( !PlayerList.isEmpty()) {
                                                        for(Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i) {
                                                                if( Player *pCurrent = i->getSource()) {
                                                                        if( me->GetDistance(pCurrent) <= 100.0f)
                                                                                DoTeleportPlayer( pCurrent, tp.GetPositionX(), tp.GetPositionY(), tp.GetPositionZ(), tp.GetOrientation());
                                                                }
                                                        }
                                                }
                                                break;
                                };
                        }

                        uint32 health_theSkybreaker;
                        uint32 health_ogrimsHammer;

                        std::list<Creature*> lSummons;

                        uint32 timer_Cleave;
                        uint32 timer_RendingThrow;
                        uint32 timer_TasteOfBlood;
                        
                        bool bBattleStart;
                        bool bDialog;
                        uint32 dialogID;
                        uint32 dialogTimer;
                };
                
        bool OnGossipHello(Player* pPlayer, Creature* pCreature)
        {
            if ( pPlayer->GetTeamId() == TEAM_ALLIANCE)
                return false;

            InstanceScript* pInstance = pCreature->GetInstanceScript();
            if (pInstance && pInstance->GetBossState(DATA_GUNSHIP_BATTLE_EVENT) == NOT_STARTED)
            {
                                pPlayer->ADD_GOSSIP_ITEM(0, "Ready for battle", 631, HORDE_GOSSIP_ACTION_START);
                                pPlayer->ADD_GOSSIP_ITEM(0, "Return Later", 631, HORDE_GOSSIP_ACTION_CANCEL);
                                pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());

                                return true;
                        }

            if (pInstance && pInstance->GetBossState(DATA_GUNSHIP_BATTLE_EVENT) == DONE)
            {
                                pPlayer->ADD_GOSSIP_ITEM(0, "Go to the top of the Deathbringer", 631, HORDE_GOSSIP_ACTION_TP);
                                pPlayer->ADD_GOSSIP_ITEM(0, "Return Later", 631, HORDE_GOSSIP_ACTION_CANCEL);
                                pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());

                                return true;
                        }
            return false;
        }

                bool OnGossipSelect(Player* player, Creature* pCreature, uint32 /*sender*/, uint32 action)
                {
                        player->PlayerTalkClass->ClearMenus();
                        player->CLOSE_GOSSIP_MENU();

                        switch( action) {
                                case    HORDE_GOSSIP_ACTION_START       :
                                                        pCreature->AI()->DoAction( DO_ACTION_START_GUNSHIP_BATTLE); // Comienzo !
                                                        return true;
                                case    HORDE_GOSSIP_ACTION_TP          :
                                                        pCreature->AI()->DoAction( DO_ACTION_FINISH_GUNSHIP_BATTLE); // Fin !
                                                        return true;
                                case    HORDE_GOSSIP_ACTION_CANCEL      :
                                                        return true;
                        };

                        return false;
                }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new boss_high_overlord_varok_saurfangAI(pCreature);
        }
};

class npc_sergeant : public CreatureScript
{
    public:
        npc_sergeant() : CreatureScript("npc_sergeant") { }

                struct npc_sergeantAI : public ScriptedAI
                {
                        npc_sergeantAI(Creature* pCreature) : ScriptedAI(pCreature)
            { pInstance = me->GetInstanceScript(); }

                        void Reset()
                        {
                                timer_Spawn                             =       0;

                                timer_Bladestorm                =       7000;
                                timer_WoundingStrike    =       urand( 10000, 12000);
                                timer_BurningPitch              =       60000;
                                timer_DesperateResolve  =       0; // -40% de Vida
                        }

                        void UpdateAI( const uint32 diff) 
                        {
                                timer_Spawn += diff;
                                buffExp( this, timer_Spawn);
                if (!UpdateVictim())
                    return;

                                if( ( me->GetHealth() / me->GetMaxHealth()) <= 0.4) {
                                        if( timer_DesperateResolve <= diff) {
                                                DoCast( me, RAID_MODE( SPELL_DESPERATE_RESOLVE_10_NM, SPELL_DESPERATE_RESOLVE_25_NM, SPELL_DESPERATE_RESOLVE_10_HM, SPELL_DESPERATE_RESOLVE_25_HM));
                                                timer_DesperateResolve = 120000;
                                        } else timer_DesperateResolve -= diff;
                                }

                                if( timer_Bladestorm <= diff) {
                                        DoCast( me, SPELL_BLADESTORM);
                                        timer_Bladestorm = 7000;
                                } else timer_Bladestorm -= diff;

                                if( timer_BurningPitch <= diff) {
                                        if( Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 10000, true)) {
                                                DoCast( pTarget, SPELL_BURNING_PITCH);
                                                timer_BurningPitch = 60000;
                                        }
                                } else timer_BurningPitch -= diff;

                                if( timer_WoundingStrike <= diff) {
                                        DoCastVictim( RAID_MODE( SPELL_WOUNDING_STRIKE_10_NM, SPELL_WOUNDING_STRIKE_25_NM, SPELL_WOUNDING_STRIKE_10_HM, SPELL_WOUNDING_STRIKE_25_HM));
                                        timer_WoundingStrike = urand( 10000, 12000);
                                } else timer_WoundingStrike -= diff;

                DoMeleeAttackIfReady();
                        }

                        uint32 timer_Bladestorm;
                        uint32 timer_WoundingStrike;
                        uint32 timer_DesperateResolve;
                        uint32 timer_BurningPitch;

                        uint32 timer_Spawn;
            InstanceScript* pInstance;
                };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_sergeantAI(pCreature);
        }
};

class npc_skybreaker_rifleman : public CreatureScript
{
    public:
        npc_skybreaker_rifleman() : CreatureScript("npc_skybreaker_rifleman") { }

                struct npc_skybreaker_riflemanAI : public ScriptedAI
                {
                        npc_skybreaker_riflemanAI(Creature* pCreature) : ScriptedAI(pCreature)
            { pInstance = me->GetInstanceScript(); }

                        void Reset()
                        {
                                timer_Spawn                             =       0;

                                timer_Shoot                             =       urand( 2000, 4000);
                                timer_BurningPitch              =       60000;
                        }

                        void UpdateAI( const uint32 diff)
                        {
                                timer_Spawn += diff;
                                buffExp( this, timer_Spawn);
                if (!UpdateVictim())
                    return;

                                if( timer_BurningPitch <= diff) {
                                        if( Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 10000, true)) {
                                                DoCast( pTarget, SPELL_BURNING_PITCH);
                                                timer_BurningPitch = 60000;
                                        }
                                } else timer_BurningPitch -= diff;

                                if( timer_Shoot <= diff) {
                                        DoCastVictim( RAID_MODE( SPELL_SHOOT_10_NM, SPELL_SHOOT_25_NM, SPELL_SHOOT_10_HM, SPELL_SHOOT_25_HM));
                                        timer_Shoot = urand( 2000, 4000);
                                } else timer_Shoot -= diff;
                        }

                        uint32 timer_Shoot;
                        uint32 timer_BurningPitch;
                        
                        uint32 timer_Spawn;
            InstanceScript* pInstance;
                };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_skybreaker_riflemanAI(pCreature);
        }
};

class npc_korkron_axethrower : public CreatureScript
{
    public:
        npc_korkron_axethrower() : CreatureScript("npc_korkron_axethrower") { }

                struct npc_korkron_axethrowerAI : public ScriptedAI
                {
                        npc_korkron_axethrowerAI(Creature* pCreature) : ScriptedAI(pCreature)
            { pInstance = me->GetInstanceScript(); }

                        void Reset()
                        {
                                timer_Spawn                             =       0;

                                timer_HurlAxe                   =       urand( 2000, 4000);
                                timer_BurningPitch              =       60000;
                        }

                        void UpdateAI( const uint32 diff)
                        {
                                timer_Spawn += diff;
                                buffExp( this, timer_Spawn);
                if (!UpdateVictim())
                    return;

                                if( timer_BurningPitch <= diff) {
                                        if( Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 10000, true)) {
                                                DoCast( pTarget, SPELL_BURNING_PITCH);
                                                timer_BurningPitch = 60000;
                                        }
                                } else timer_BurningPitch -= diff;

                                if( timer_HurlAxe <= diff) {
                                        DoCastVictim( RAID_MODE( SPELL_HURL_AXE_10_NM, SPELL_HURL_AXE_25_NM, SPELL_HURL_AXE_10_HM, SPELL_HURL_AXE_25_HM));
                                        timer_HurlAxe = urand( 2000, 4000);
                                } else timer_HurlAxe -= diff;
                        }

                        uint32 timer_HurlAxe;
                        uint32 timer_BurningPitch;
                        
                        uint32 timer_Spawn;
            InstanceScript* pInstance;
                };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_korkron_axethrowerAI(pCreature);
        }
};

class npc_marine_or_reaver : public CreatureScript
{
    public:
        npc_marine_or_reaver() : CreatureScript("npc_marine_or_reaver") { }

                struct npc_marine_or_reaverAI : public ScriptedAI
                {
                        npc_marine_or_reaverAI(Creature* pCreature) : ScriptedAI(pCreature)
            { pInstance = me->GetInstanceScript(); }

                        void Reset()
                        {
                                timer_Spawn                             =       0;

                                timer_BurningPitch              =       60000;
                                timer_DesperateResolve  =       0; // -40% de Vida
                        }

                        void UpdateAI( const uint32 diff)
                        {
                                timer_Spawn += diff;
                                buffExp( this, timer_Spawn);
                if (!UpdateVictim())
                    return;
                                
                                if( ( me->GetHealth() / me->GetMaxHealth()) <= 0.4) {
                                        if( timer_DesperateResolve <= diff) {
                                                DoCast( me, RAID_MODE( SPELL_DESPERATE_RESOLVE_10_NM, SPELL_DESPERATE_RESOLVE_25_NM, SPELL_DESPERATE_RESOLVE_10_HM, SPELL_DESPERATE_RESOLVE_25_HM));
                                                timer_DesperateResolve = 120000;
                                        } else timer_DesperateResolve -= diff;
                                }

                                if( timer_BurningPitch <= diff) {
                                        if( Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 10000, true)) {
                                                DoCast( pTarget, SPELL_BURNING_PITCH);
                                                timer_BurningPitch = 60000;
                                        }
                                } else timer_BurningPitch -= diff;

                DoMeleeAttackIfReady();
                        }

                        uint32 timer_DesperateResolve;
                        uint32 timer_BurningPitch;
                        
                        uint32 timer_Spawn;
            InstanceScript* pInstance;
                };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_marine_or_reaverAI(pCreature);
        }
};

class npc_mortar_soldier_or_rocketeer : public CreatureScript
{
    public:
        npc_mortar_soldier_or_rocketeer() : CreatureScript("npc_mortar_soldier_or_rocketeer") { }

                struct npc_mortar_soldier_or_rocketeerAI : public ScriptedAI
                {
                        npc_mortar_soldier_or_rocketeerAI(Creature* pCreature) : ScriptedAI(pCreature)
            { pInstance = me->GetInstanceScript(); }

                        void Reset()
                        {
                                timer_Spawn                             =       0;

                                timer_RocketArtillery   =       urand( 10000, 15000);
                                timer_BurningPitch              =       60000;
                        }

                        void UpdateAI( const uint32 diff)
                        {
                                timer_Spawn += diff;
                                buffExp( this, timer_Spawn);
                if (!UpdateVictim())
                    return;
                                
                                if( timer_BurningPitch <= diff) {
                                        if( Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 10000, true)) {
                                                DoCast( pTarget, SPELL_BURNING_PITCH);
                                                timer_BurningPitch = 60000;
                                        }
                                } else timer_BurningPitch -= diff;

                                if( timer_RocketArtillery <= diff) {
                                        if( Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 10000, true)) {
                                                DoCast( pTarget, SPELL_ROCKET_ARTILLERY);
                                                timer_RocketArtillery   =       urand( 10000, 15000);
                                        }
                                } else timer_RocketArtillery -= diff;
                        }

                        uint32 timer_RocketArtillery;
                        uint32 timer_BurningPitch;
                        
                        uint32 timer_Spawn;
            InstanceScript* pInstance;
                };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_mortar_soldier_or_rocketeerAI(pCreature);
        }
};

class npc_sorcerer_or_battle_mage : public CreatureScript
{
    public:
        npc_sorcerer_or_battle_mage() : CreatureScript("npc_sorcerer_or_battle_mage") { }

                struct npc_sorcerer_or_battle_mageAI : public ScriptedAI
                {
                        npc_sorcerer_or_battle_mageAI(Creature* pCreature) : ScriptedAI(pCreature)
            { pInstance = me->GetInstanceScript(); }

                        void Reset()
                        {
                                timer_Spawn                             =       0;

                                timer_BurningPitch              =       60000;
                                timer_BelowZero                 =       urand( 10000, 15000);
                        }

                        void UpdateAI( const uint32 diff)
                        {
                                timer_Spawn += diff;
                                buffExp( this, timer_Spawn);
                if (!UpdateVictim())
                    return;
                                
                                if( timer_BurningPitch <= diff) {
                                        if( Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 10000, true)) {
                                                DoCast( pTarget, SPELL_BURNING_PITCH);
                                                timer_BurningPitch = 60000;
                                        }
                                } else timer_BurningPitch -= diff;

                                if( timer_BelowZero <= diff) {
                                        if( Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 10000, true)) {
                                                DoCast( pTarget, SPELL_BELOW_ZERO);
                                                timer_BelowZero = urand( 10000, 15000);
                                        }
                                } else timer_BelowZero -= diff;
                        }

                        uint32 timer_BelowZero;
                        uint32 timer_BurningPitch;
                        
                        uint32 timer_Spawn;
            InstanceScript* pInstance;
                };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_sorcerer_or_battle_mageAI(pCreature);
        }
};

void AddSC_boss_gunship_battle()
{
        new npc_sergeant();
        new npc_zafod_boombox();
        new npc_skybreaker_rifleman();
        new npc_korkron_axethrower();
        new npc_marine_or_reaver();
        new npc_mortar_soldier_or_rocketeer();
        new npc_sorcerer_or_battle_mage();
        new boss_muradin_bronzebeard();
        new boss_high_overlord_varok_saurfang();
}