/*
 * Copyright (C) 2008-2011 by WarHead - United Worlds of MaNGOS - http://www.uwom.de
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
SDName: Npcs_Special
SD%Complete: 100
SDComment: To be used for special NPCs that are located globally.
SDCategory: NPCs
EndScriptData
*/

/* ContentData
npc_air_force_bots       80%    support for misc (invisible) guard bots in areas where player allowed to fly. Summon guards after a preset time if tagged by spell
npc_lunaclaw_spirit      80%    support for quests 6001/6002 (Body and Heart)
npc_chicken_cluck       100%    support for quest 3861 (Cluck!)
npc_dancing_flames      100%    midsummer event NPC
npc_garments_of_quests   80%    NPC's related to all Garments of-quests 5621, 5624, 5625, 5648, 565
npc_injured_patient     100%    patients for triage-quests (6622 and 6624)
npc_doctor              100%    Gustaf Vanhowzen and Gregory Victor, quest 6622 and 6624 (Triage)
npc_kingdom_of_dalaran_quests   Misc NPC's gossip option related to quests 12791, 12794 and 12796
npc_mount_vendor        100%    Regular mount vendors all over the world. Display gossip if player doesn't meet the requirements to buy
npc_rogue_trainer        80%    Scripted trainers, so they are able to offer item 17126 for class quest 6681
npc_sayge               100%    Darkmoon event fortune teller, buff player based on answers given
npc_snake_trap_serpents  80%    AI for snakes that summoned by Snake Trap
npc_shadowfiend         100%   restore 5% of owner's mana when shadowfiend die from damage
npc_locksmith            75%    list of keys needs to be confirmed
EndContentData */

#include "ScriptPCH.h"
#include "ScriptedEscortAI.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "World.h"
#include "ReputationMgr.h"
#include "Config.h"

void LearnAllSkillRecipes(Player * player, uint32 skill_id)
{
    uint32 classmask = player->getClassMask();

    for (uint32 j = 0; j < sSkillLineAbilityStore.GetNumRows(); ++j)
    {
        SkillLineAbilityEntry const *skillLine = sSkillLineAbilityStore.LookupEntry(j);
        if (!skillLine)
            continue;

        // wrong skill
        if (skillLine->skillId != skill_id)
            continue;

        // not high rank
        if (skillLine->forward_spellid)
            continue;

        // skip racial skills
        if (skillLine->racemask != 0)
            continue;

        // skip wrong class skills
        if (skillLine->classmask && (skillLine->classmask & classmask) == 0)
            continue;

        SpellEntry const* spellInfo = sSpellStore.LookupEntry(skillLine->spellId);
        if (!spellInfo)
            continue;

        player->learnSpell(skillLine->spellId, false);
    }
}
// ------------------------------------------------------------------------------------------------------------
// Feuerrufer 60000
// ------------------------------------------------------------------------------------------------------------
#define SPELL_RAKETENBUENDEL_ZUENDER    26299   // Zünder für Raketenbündel herstellen - 2 Secs. cast - NUR EINMAL BEIM START CASTEN!!!

#define FirecallerSpellsCnt 15
const uint32 FirecallerSpells[FirecallerSpellsCnt] =
{
    6668,   // Rotes Feuerwerk - 2.5 Secs. cooldown
    11540,  // Blaues Feuerwerk - 2.5 Secs. cooldown
    11541,  // Grünes Feuerwerk - 2.5 Secs. cooldown
    11542,  // Rotes Streifen-Feuerwerk - 2.5 Secs. cooldown
    11543,  // Rot - Weiß - Blau Feuerwerk - 2.5 Secs. cooldown
    11544,  // Gelbe Rosen - Feuerwerk - 2.5 Secs. cooldown
    19823,  // Feuernova - Visual - kein Schaden
    30161,  // Lila Feuerwerk - 30 Secs. cooldown
    30237,  // Astralflimmern - Visual
    34602,  // Explosion - kein Schaden
    42075,  // Headless Horseman - Visual - Large Fire
    45153,  // Liebesrakete
    46235,  // Schwarzes Loch 2 - Visual
    46829,  // Ribbon Pole Firework and Flame Patch
    55420   // Feuerwerk von Dalaran - 5 Secs. Duration
};

enum FirecallerSpellsIdx
{
    ROTES_FEUERWERK = 0,
    BLAUES_FEUERWERK,
    GRUENES_FEUERWERK,
    ROTE_STREIFEN_FEUERWERK,
    ROT_WEISS_BLAU_FEUERWERK,
    GELBE_ROSEN_FEUERWERK,
    FEUERNOVA,
    LILA_FEUERWERK,
    ASTRALFLIMMERN,
    EXPLOSION,
    GROSSES_FEUER,
    LIEBESRAKETE,
    SCHWARZES_LOCH,
    RIBBON_POLE,
    DALARAN_FEUERWERK
};

#define FirecallerTargetSpellsCnt 4
const uint32 FirecallerTargetSpells[FirecallerTargetSpellsCnt] =
{
    45729,  // Bodenblüte - Reichweite 20Y (needs target!)
    45971,  // Bodenraketen - Reichweite 150Y - self oder target
    49872,  // Raketenschuss - 10-70Y - needs target!
    75419   // Versengen - 30Y - NUR GEGEN GM ANWENDEN!!! (needs target!)
};

enum FirecallerTargetSpellsIdx
{
    BODENBLUETE = 0,
    BODENRAKETE,
    RAKETENSCHUSS,
    VERSENGEN
};

#define FirecallerClusterCnt 15
const uint32 FirecallerCluster[FirecallerClusterCnt] =
{
    26304,  // Blaues Raketenbündel - 10 Secs. Duration
    26325,  // Grünes Raketenbündel - 10 Secs. Duration
    26326,  // Lila Raketenbündel - 10 Secs. Duration
    26327,  // Rotes Raketenbündel - 10 Secs. Duration
    26328,  // Weißes Raketenbündel - 10 Secs. Duration
    26329,  // Gelbes Raketenbündel - 10 Secs. Duration
    26488,  // Großes blaues Raketenbündel - 10 Secs. Duration
    26490,  // Großes grünes Raketenbündel - 10 Secs. Duration
    26516,  // Großes lila Raketenbündel - 10 Secs. Duration
    26517,  // Großes rotes Raketenbündel - 10 Secs. Duration
    26518,  // Großes weißes Raketenbündel - 10 Secs. Duration
    26519,  // Großes gelbes Raketenbündel - 10 Secs. Duration
    42813,  // Blaue Rakete von Theramore - 5 Secs. Duration
    42815,  // Gelbe Rakete von Theramore - 5 Secs. Duration
    42816   // Lila Rakete von Theramore - 5 Secs. Duration
};

enum FirecallerClusterIdx
{
    BLAU_CLUSTER = 0,
    GRUEN_CLUSTER,
    LILA_CLUSTER,
    ROT_CLUSTER,
    WEISS_CLUSTER,
    GELB_CLUSTER,
    BLAU_GROSS,
    GRUEN_GROSS,
    LILA_GROSS,
    ROT_GROSS,
    WEISS_GROSS,
    GELB_GROSS,
    RAKETE_BLAU,
    RAKETE_GELB,
    RAKETE_LILA
};

#define FirecallerJokesCnt 17
const uint32 FirecallerJokes[FirecallerJokesCnt] =
{
    24708,  // Piratenkostüm - 100Y - m
    24709,  // Piratenkostüm - 100Y - f
    24710,  // Ninjakostüm - 100Y - m
    24711,  // Ninjakostüm - 100Y - f
    24712,  // Lepragnomkostüm - 100Y - m
    24713,  // Lepragnomkostüm - 100Y - f
    24723,  // Skelettkostüm - 100Y
    24735,  // Geistkostüm - 100Y - m
    24736,  // Geistkostüm - 100Y - f
    24740,  // Irrwischkostüm - 100Y
    26157,  // PX-238 Winterwundervolt - self
    26272,  // PX-238 Winterwundervolt - self
    26273,  // PX-238 Winterwundervolt - self
    26274,  // PX-238 Winterwundervolt - self
    43906,  // Frosch im Hals - 40Y
    45684,  // Verwandlung: Pfiffi Wackelspross - self
    61781   // Truthahnfedern - 40Y
};

enum FirecallerJokesIdx
{
    PIRAT_MANN = 0,
    PIRAT_FRAU,
    NINJA_MANN,
    NINJA_FRAU,
    LEPRAGNOM_MANN,
    LEPRAGNOM_FRAU,
    SKELETT,
    GEIST_MANN,
    GEIST_FRAU,
    IRRWISCH,
    PX_238_1,
    PX_238_2,
    PX_238_3,
    PX_238_4,
    FROSCH_IM_HALS,
    PFIFFI_WACKELSPROSS,
    TRUTHAHN
};

// To find all pet items...
// SELECT `entry`,`spellid_2` FROM `item_template` WHERE `class`=15 AND `subclass`=2 AND `spellid_2`!=0;

#define FirecallerPresentsCnt 148
const uint32 FirecallerPresents[FirecallerPresentsCnt][2] =
{   // Item,Spell
    {4401,4055},{8485,10673},{8486,10674},{8487,10676},{8488,10678},{8489,10679},{8490,10677},{8491,10675},{8492,10683},{8494,10682},{8495,10684},{8496,10680},{8497,10711},{8498,10698},{8499,10697},
    {8500,10707},{8501,10706},{10360,10714},{10361,10716},{10392,10717},{10393,10688},{10394,10709},{10398,12243},{10822,10695},{11023,10685},{11026,10704},{11027,10703},{11110,13548},{11474,15067},
    {11825,15048},{11826,15049},{13582,17709},{13583,17707},{13584,17708},{15996,19772},{18964,23429},{19054,23530},{19055,23531},{19450,23811},{20371,24696},{20769,25162},{21168,25849},{21277,26010},
    {22114,27241},{22235,27570},{22781,28505},{23002,28738},{23007,28739},{23015,28740},{23083,28871},{23712,30152},{23713,30156},{25535,32298},{27445,33050},{29363,35156},{29364,35239},{29901,35907},
    {29902,35909},{29903,35910},{29904,35911},{29953,36027},{29956,36028},{29957,36029},{29958,36031},{29960,36034},{32233,39709},{32498,40405},{32588,40549},{33154,42609},{33816,43697},{33818,43698},
    {33993,43918},{34425,54187},{34478,45082},{34492,45125},{34493,45127},{34518,45174},{34519,45175},{34535,10696},{35349,46425},{35350,46426},{35504,46599},{37297,48406},{37298,48408},{38050,49964},
    {38628,51716},{38658,51851},{39286,52615},{39656,53082},{39896,61348},{39898,61351},{39899,61349},{39973,53316},{40653,40990},{41133,55068},{43517,61357},{43698,59250},{44721,61350},{44723,61357},
    {44738,61472},{44819,61855},{44822,10713},{44841,61991},{44965,62491},{44970,62508},{44971,62510},{44973,62513},{44974,62516},{44980,62542},{44982,62564},{44983,62561},{44984,62562},{44998,62609},
    {45002,62674},{45022,62746},{45180,63318},{45606,63712},{45942,64351},{46398,65358},{46544,65382},{46545,65381},{46707,44369},{46767,65682},{46802,66030},{46820,66096},{46821,66096},{48112,67413},
    {48114,67414},{48116,67415},{48118,67416},{48120,67417},{48122,67418},{48124,67419},{48126,67420},{49287,68767},{49343,68810},{49362,69002},{49646,69452},{49662,69535},{49663,69536},{49665,69541},
    {49693,69677},{49912,70613},{50446,71840},{54436,75134},{54847,75906},{56806,78381}
};

#define FirecallerSoundsCnt 3
const uint32 FirecallerSounds[FirecallerSoundsCnt][5] =
{
    // Welcome
    {11966, 0, 0, 0, 0},
    // Abschied
    {11968, 0, 0, 0, 0},
    // Random
    {11962, 11965, 11967, 11975, 11976}
};

enum FirecallerSoundsIdx
{
    WILLKOMMEN = 0,
    ABSCHIED,
    ZUFAELLIG
};

enum FirecallerEvents
{
    EVENT_START = 1,
    EVENT_STOP,
    EVENT_SOUND,
    EVENT_CAST,
    EVENT_TARGET,
    EVENT_CLUSTER,
    EVENT_PRESENT_1,
    EVENT_PRESENT_2,
    EVENT_PRESENT_3,
    EVENT_JOKE
};

class npc_uwom_firecaller : public CreatureScript
{
public:
    npc_uwom_firecaller() : CreatureScript("npc_uwom_firecaller") { }

    struct npc_uwom_firecallerAI : public ScriptedAI
    {
        npc_uwom_firecallerAI(Creature * creature) : ScriptedAI(creature)
        {
            events.Reset();
            events.ScheduleEvent(EVENT_START, 60 * IN_MILLISECONDS);

            bericht.append("Feuerrufer-Bericht über die verschenkten Items. ;)");
            bericht.append("\n\n");

            SpielerGUIDSet.clear();
            PetListe.clear();
        }

        void Reset()
        {
        }

        void LadePetListe()
        {
            QueryResult result = WorldDatabase.PQuery("SELECT `entry`,`spellid_2` FROM `item_template` WHERE `class`=15 AND `subclass`=2 AND `spellid_2`!=0");
            if (!result)
            {
                sLog->outErrorDb("FEUERRUFER: Kann die Pets nicht laden!");
                return;
            }

            uint32 cnt = 0;

            do
            {
                Field * fields = result->Fetch();
                if (fields[0].GetUInt32() && fields[1].GetUInt32())
                {
                    PetListe[fields[0].GetUInt32()] = fields[1].GetUInt32();
                    ++cnt;
                }
            } while (result->NextRow());

            sLog->outString("FEUERRUFER: Habe %u gültige Pets gefunden und geladen.", cnt);
        }

        void MoveInLineOfSight(Unit * who)
        {
            if (!who || !who->isValid() || who->GetTypeId() != TYPEID_PLAYER)
                return;

            Player * chr = who->ToPlayer();
            if (!chr || !chr->isValid())
                return;

            if (SpielerGUIDSet.find(chr->GetGUID()) == SpielerGUIDSet.end())
                SpielerGUIDSet.insert(chr->GetGUID());
        }

        void SchreibeBericht(std::string str)
        {
            std::string tmpfile = sWorld->GetDataPath().c_str();
            tmpfile.append("log/feuerrufer.log");

            if (FILE * reportfile = fopen(tmpfile.c_str(), "w"))
            {
                sLog->outString("FEUERUFER: %s", str.c_str());
                fputs(str.c_str(), reportfile);
                fclose(reportfile);
            }
            else
            {
                sLog->outError("FEUERUFER: KANN %s NICHT ERSTELLEN!", tmpfile.c_str());
                sLog->outError("FEUERUFER: %s", str.c_str());
            }
        }

        Player * FindeSpieler(float range = 50.0f)
        {
            if (SpielerGUIDSet.empty())
                return NULL;

            for (std::set<uint64>::iterator itr = SpielerGUIDSet.begin(); itr != SpielerGUIDSet.end(); ++itr)
            {
                for (uint32 i=0; i<=urand(0, SpielerGUIDSet.size()-1); ++i)
                    if (++itr == SpielerGUIDSet.end()) { --itr; break; }

                Player * chr = sObjectAccessor->FindPlayer(*itr);
                if (!chr)
                {
                    SpielerGUIDSet.erase(itr);
                    continue;
                }
                if (chr->isValid() && chr->isAlive() && !chr->IsMounted() && me->IsWithinDistInMap(chr, range))
                    return chr;
            }
            return NULL;
        }

        bool BeschenkeZiel(Player * chr, uint8 cnt)
        {
            if (!chr)
                return false;

            if (chr->GetSession()->GetSecurity() < SEC_ANWAERTER)
            {
                for (uint8 i=0; i<FirecallerPresentsCnt; ++i)
                {   // Wenn der Spieler das zu gebende Item schon hat / kennt, nicht doppelt geben!
                    if (!chr->HasItemCount(FirecallerPresents[i][0], 1, true) && !chr->HasSpell(FirecallerPresents[i][1]))
                    {
                        char buffer[6];
                        time_t localtime = time(NULL);

                        sprintf(buffer, "%u", FirecallerPresents[i][0]);
                        addItem(chr, FirecallerPresents[i][0],1,true,false,true);
                        // Bericht schreiben, damit wir wissen, wer welches Geschenk bekommen hat. ;)
                        switch(cnt)
                        {
                            case 1: bericht.append("Das 1. Item http://de.wowhead.com/item="); break;
                            case 2: bericht.append("Das 2. Item http://de.wowhead.com/item="); break;
                            case 3: bericht.append("Das 3. Item http://de.wowhead.com/item="); break;
                        }
                        bericht.append(buffer);
                        bericht.append(" ging an: ");
                        bericht.append(chr->GetName());
                        bericht.append(". Dies geschah am ");
                        bericht.append(TimeToTimestampStr(localtime, GERMAN).c_str());
                        bericht.append(" Uhr.");
                        bericht.append("\n");

                        return true;
                    }
                }
            }
            return false;
        }

        void VerzauberZiel(Player * chr)
        {
            if (!chr)
                return;

            uint8 i = urand(0,FirecallerJokesCnt-1);

            switch(i)
            {
                case PIRAT_MANN:
                case PIRAT_FRAU:
                case NINJA_MANN:
                case NINJA_FRAU:
                case LEPRAGNOM_MANN:
                case LEPRAGNOM_FRAU:
                case SKELETT:
                case GEIST_MANN:
                case GEIST_FRAU:
                case IRRWISCH:
                    for (uint8 j=0; j<FirecallerJokesCnt; ++j)
                        if (chr->HasAura(FirecallerJokes[j]))
                            chr->RemoveAurasDueToSpell(FirecallerJokes[j]);

                    if (me->GetDistance(chr) <= 100.0f)
                        DoCast(chr, FirecallerJokes[i], true);
                    break;
                case PX_238_1:
                case PX_238_2:
                case PX_238_3:
                case PX_238_4:
                case PFIFFI_WACKELSPROSS:
                    for (uint8 j=0; j<FirecallerJokesCnt; ++j)
                        if (chr->HasAura(FirecallerJokes[j]))
                            chr->RemoveAurasDueToSpell(FirecallerJokes[j]);

                    chr->CastSpell(chr, FirecallerJokes[i], true);
                    break;
                case FROSCH_IM_HALS:
                case TRUTHAHN:
                    for (uint8 j=0; j<FirecallerJokesCnt; ++j)
                        if (chr->HasAura(FirecallerJokes[j]))
                            chr->RemoveAurasDueToSpell(FirecallerJokes[j]);

                    if (me->GetDistance(chr) <= 40.0f)
                        DoCast(chr, FirecallerJokes[i], true);
                    break;
            }
        }

        void StartEvent()
        {
            DoPlaySoundToSet(me, FirecallerSounds[WILLKOMMEN][0]);

            DoCast(me, SPELL_RAKETENBUENDEL_ZUENDER, true);
            DoCast(FirecallerSpells[FEUERNOVA]);

            me->GetMotionMaster()->MoveRandom(10.0f);

            events.ScheduleEvent(EVENT_STOP, 1740 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_SOUND, urand(SEKUNDEN_10, SEKUNDEN_60));
            events.ScheduleEvent(EVENT_CAST, 3 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_TARGET, urand(SEKUNDEN_10, SEKUNDEN_60));
            events.ScheduleEvent(EVENT_CLUSTER, urand(SEKUNDEN_10, SEKUNDEN_60));
            events.ScheduleEvent(EVENT_PRESENT_1, urand(MINUTEN_10, MINUTEN_15));
            events.ScheduleEvent(EVENT_JOKE, urand(SEKUNDEN_10, SEKUNDEN_60));
        }

        void StopEvent()
        {
            DoPlaySoundToSet(me, FirecallerSounds[ABSCHIED][0]);
            DoCast(FirecallerSpells[EXPLOSION]);

            if (bericht.size() < 60)
                bericht.append("Leider war diesmal niemand zum Event erschienen! :-(");

            SchreibeBericht(bericht);

            me->ForcedDespawn(8 * IN_MILLISECONDS);
        }

        uint32 ZufallsZauberHolen()
        {
            uint32 Zauber = urand(0,FirecallerSpellsCnt-1);

            if (Zauber == FirecallerSpells[GROSSES_FEUER] || Zauber == FirecallerSpells[SCHWARZES_LOCH])
                me->RemoveAllAuras();

            return Zauber;
        }

        void UpdateAI(const uint32 diff)
        {
            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_START:
                        StartEvent();
                        break;
                    case EVENT_PRESENT_1:
                        if (!BeschenkeZiel(FindeSpieler(), 1))
                            events.RescheduleEvent(EVENT_PRESENT_1, urand(SEKUNDEN_10, SEKUNDEN_30));
                        else
                        {
                            events.CancelEvent(EVENT_PRESENT_1);
                            events.ScheduleEvent(EVENT_PRESENT_2, urand(MINUTEN_05, MINUTEN_10));
                        }
                        break;
                    case EVENT_PRESENT_2:
                        if (!BeschenkeZiel(FindeSpieler(), 2))
                            events.RescheduleEvent(EVENT_PRESENT_2, urand(SEKUNDEN_10, SEKUNDEN_30));
                        else
                        {
                            events.CancelEvent(EVENT_PRESENT_2);
                            events.ScheduleEvent(EVENT_PRESENT_3, urand(MINUTEN_05, MINUTEN_10));
                        }
                        break;
                    case EVENT_PRESENT_3:
                        if (!BeschenkeZiel(FindeSpieler(), 3))
                            events.RescheduleEvent(EVENT_PRESENT_3, urand(SEKUNDEN_10, SEKUNDEN_30));
                        else
                            events.CancelEvent(EVENT_PRESENT_3);
                        break;
                    case EVENT_SOUND:
                        DoPlaySoundToSet(me, FirecallerSounds[ZUFAELLIG][urand(0,4)]);
                        events.RescheduleEvent(EVENT_SOUND, urand(SEKUNDEN_60, 3 * SEKUNDEN_60));
                        break;
                    case EVENT_CAST:
                        DoCast(FirecallerSpells[ZufallsZauberHolen()]);
                        events.RescheduleEvent(EVENT_CAST, 3 * IN_MILLISECONDS);
                        break;
                    case EVENT_TARGET:
                        if (Player * chr = FindeSpieler())
                        {
                            me->setFaction(14);
                            if (chr->GetSession()->GetSecurity() > SEC_VETERAN)
                                DoCast(chr, FirecallerTargetSpells[VERSENGEN]);
                            else
                                DoCast(chr, FirecallerTargetSpells[urand(BODENBLUETE, RAKETENSCHUSS)]);
                            me->setFaction(35);
                        }
                        events.RescheduleEvent(EVENT_TARGET, urand(SEKUNDEN_30, SEKUNDEN_60));
                        break;
                    case EVENT_CLUSTER:
                        DoCast(FirecallerCluster[urand(0,FirecallerClusterCnt-1)]);
                        events.RescheduleEvent(EVENT_CLUSTER, urand(SEKUNDEN_10, SEKUNDEN_30));
                        break;
                    case EVENT_JOKE:
                        VerzauberZiel(FindeSpieler());
                        events.RescheduleEvent(EVENT_JOKE, urand(SEKUNDEN_30, SEKUNDEN_60));
                        break;
                    case EVENT_STOP:
                        StopEvent();
                        break;
                }
            }
        }
        private:
            EventMap events;
            std::string bericht;
            std::set<uint64> SpielerGUIDSet;
            std::map<uint32, uint32> PetListe;
    };

    CreatureAI * GetAI(Creature * creature) const
    {
        return new npc_uwom_firecallerAI(creature);
    }
};

// ------------------------------------------------------------------------------------------------------------
// Flugmeister sowie Add Skripte - http://de.wowhead.com/npcs?filter=cr=21;crs=1;crv=0#0+1
// ------------------------------------------------------------------------------------------------------------
#define SPELL_NET   38661 // Immobilizes an enemy for 8 sec.

class npc_flugmeister : public CreatureScript
{
public:
    npc_flugmeister() : CreatureScript("npc_flugmeister") { }

    struct npc_flugmeisterAI : public ScriptedAI
    {
        npc_flugmeisterAI(Creature* c) : ScriptedAI(c)
        {
            switch(me->GetEntry())
            {
                // Surristrasz
                case 24795:
                    add1 = 26088;
                    add2 = 26088;
                    break;
                // Drachenfalkenmeister
                case 26560:
                case 30269:
                    add1 = 25175;
                    add2 = 25175;
                    break;
                // Fledermausführer
                case 2226:
                case 2389:
                case 4551:
                case 12636:
                case 16189:
                case 16192:
                case 24155:
                case 26844:
                case 26845:
                case 27344:
                    add1 = 14965;
                    add2 = 14965;
                    break;
                // Hippogryphenmeister
                case 1233:
                case 3838:
                case 3841:
                case 4267:
                case 4319:
                case 4407:
                case 6706:
                case 8019:
                case 10897:
                case 11138:
                case 12577:
                case 12578:
                case 15177:
                case 17554:
                case 17555:
                case 18785:
                case 18788:
                case 18789:
                case 18937:
                case 22485:
                case 22935:
                case 26881:
                case 30271:
                    add1 = 9527;
                    add2 = 9527;
                    break;
                // Greifenmeister
                case 352:
                case 523:
                case 931:
                case 1571:
                case 1572:
                case 1573:
                case 1574:
                case 1575:
                case 2299:
                case 2409:
                case 2432:
                case 2835:
                case 2859:
                case 2941:
                case 4321:
                case 7823:
                case 8018:
                case 8609:
                case 12596:
                case 12617:
                case 18939:
                case 16822:
                case 18809:
                case 18931:
                case 20234:
                case 21107:
                case 23736:
                case 23859:
                case 24061:
                case 24366:
                case 26876:
                case 26877:
                case 26878:
                case 26879:
                case 26880:
                    add1 = 9526;
                    add2 = 9526;
                    break;
                // Windreitermeister
                case 1387:
                case 2851:
                case 2858:
                case 2861:
                case 2995:
                case 3305:
                case 3310:
                case 3615:
                case 4312:
                case 4314:
                case 4317:
                case 6026:
                case 6726:
                case 7824:
                case 8020:
                case 8610:
                case 10378:
                case 11139:
                case 11899:
                case 11900:
                case 11901:
                case 12616:
                case 12740:
                case 13177:
                case 14242:
                case 15178:
                case 16587:
                case 18791:
                case 18807:
                case 18808:
                case 18930:
                case 18942:
                case 18953:
                case 19317:
                case 19558:
                case 20762:
                case 24032:
                case 26566:
                case 26847:
                case 26850:
                case 26852:
                case 26853:
                case 29762:
                    add1 = 20489;
                    add2 = 20489;
                    break;
                // Flugmeister
                case 10583:
                case 16227:
                case 18938:
                case 18940:
                case 19581:
                case 19583:
                case 20515:
                case 21766:
                case 22216:
                case 22455:
                case 22931:
                case 23612:
                case 24851:
                case 26602:
                case 26851:
                case 27046:
                case 28195:
                case 28196:
                case 28197:
                case 28574:
                case 28615:
                case 28618:
                case 28623:
                case 28624:
                case 28674:
                case 29480:
                case 29721:
                case 29750:
                case 29757:
                case 29950:
                case 29951:
                case 30314:
                case 30433:
                case 30569:
                case 30869:
                case 30870:
                case 31069:
                case 31078:
                case 32571:
                case 33849:
                case 37888:
                    add1 = 9526;
                    add2 = 20489;
                    break;
            }
        }

        uint32 add1,
            add2,
            Net_Timer;

        bool done;

        void Reset()
        {
            Net_Timer = 1000;
            done = false;

            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISARM, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_INTERRUPT, true);
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_INTERRUPT_CAST, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SILENCE, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DAZE, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SLEEP, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_BANISH, true);
            me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_NATURE, true);
        }

        void SpawnHelper()
        {
            uint32 DSpwTime = 10000;
            float X=0.0f, Y=0.0f, Z=0.0f, A=0.0f;
            TempSummonType DSpwType = TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT;

            for (uint8 i=0; i<10; ++i)
            {
                Creature* Spawned = NULL;
                me->GetContactPoint(me, X, Y, Z, float(urand(5,15)));

                switch(i)
                {
                    case 0: Spawned = me->SummonCreature(add1, X, Y, Z+float(urand(1,10)), A, DSpwType, DSpwTime); break;
                    case 1: Spawned = me->SummonCreature(add2, X, Y, Z+float(urand(1,5)), A, DSpwType, DSpwTime); break;
                    case 2: Spawned = me->SummonCreature(add1, X, Y, Z+float(urand(1,10)), A, DSpwType, DSpwTime); break;
                    case 3: Spawned = me->SummonCreature(add2, X, Y, Z+float(urand(1,5)), A, DSpwType, DSpwTime); break;
                    case 4: Spawned = me->SummonCreature(add1, X, Y, Z+float(urand(1,10)), A, DSpwType, DSpwTime); break;
                    case 5: Spawned = me->SummonCreature(add2, X, Y, Z+float(urand(1,5)), A, DSpwType, DSpwTime); break;
                    case 6: Spawned = me->SummonCreature(add1, X, Y, Z+float(urand(1,10)), A, DSpwType, DSpwTime); break;
                    case 7: Spawned = me->SummonCreature(add2, X, Y, Z+float(urand(1,5)), A, DSpwType, DSpwTime); break;
                    case 8: Spawned = me->SummonCreature(add1, X, Y, Z+float(urand(1,10)), A, DSpwType, DSpwTime); break;
                    case 9: Spawned = me->SummonCreature(add2, X, Y, Z+float(urand(1,5)), A, DSpwType, DSpwTime); break;
                }

                if (Spawned)
                {
                    Spawned->setFaction(me->getFaction());
                    Spawned->AI()->AttackStart(me->getVictim());
                }
            }
            done = true;
        }

        void MoveInLineOfSight(Unit *who) { return; }

        void AttackStart(Unit* who)
        {
            if (!done)
                SpawnHelper();

            ScriptedAI::AttackStart(who);
        }

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (Net_Timer < diff)
            {
                DoCast(me->getVictim(), SPELL_NET);
                Net_Timer = 8000;
            }
            else
                Net_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    bool OnGossipHello(Player *pPlayer, Creature *pCreature)
    {
        if (pCreature->isQuestGiver())
            pPlayer->PrepareQuestMenu(pCreature->GetGUID());

        if (pCreature->isTrainer())
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, GOSSIP_TEXT_TRAIN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRAIN);

        if (pCreature->isVendor())
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);

        if (pCreature->isAuctioner())
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, GOSSIP_TEXT_AUCTIONHOUSE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_AUCTION);

        if (pCreature->isTaxi())
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TAXI, "Ich benötige einen Flug.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TAXI);

        pPlayer->SEND_GOSSIP_MENU(68, pCreature->GetGUID());

        return true;
    }

    void SendDefaultMenu(Player* pPlayer, Creature* pCreature, uint32 uiAction)
    {
        switch (uiAction)
        {
            // Standard-Aktionen
            case GOSSIP_ACTION_TRAIN:
                pPlayer->GetSession()->SendTrainerList(pCreature->GetGUID());
                break;
            case GOSSIP_ACTION_TRADE:
                pPlayer->GetSession()->SendListInventory(pCreature->GetGUID());
                break;
            case GOSSIP_ACTION_AUCTION:
                pPlayer->GetSession()->SendAuctionHello(pCreature->GetGUID(), pCreature);
                break;
            case GOSSIP_ACTION_TAXI:
                pPlayer->GetSession()->SendTaxiMenu(pCreature);
                break;
        }
    }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();

        switch(uiSender)
        {
            case GOSSIP_SENDER_MAIN: SendDefaultMenu(pPlayer, pCreature, uiAction); break;
        }
        return true;
    }

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_flugmeisterAI(creature);
    }
};

#define SPELL_WING_BUFFET   31475

class npc_flugmeister_adds : public CreatureScript
{
public:
    npc_flugmeister_adds() : CreatureScript("npc_flugmeister_adds") { }

    struct npc_flugmeister_addsAI : public ScriptedAI
    {
        npc_flugmeister_addsAI(Creature *c) : ScriptedAI(c) { }

        uint32 WingTimer;

        void Reset()
        {
            WingTimer = 10000;

            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISARM, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_INTERRUPT, true);
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_INTERRUPT_CAST, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SILENCE, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DAZE, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SLEEP, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_BANISH, true);
            me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_NATURE, true);

            me->SetHover(true);
            me->SetSpeed(MOVE_FLIGHT, 1.50f, true);
            me->SetSpeed(MOVE_FLIGHT_BACK, 1.50f, true);
        }

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (WingTimer < diff)
            {
                DoCast(me, SPELL_WING_BUFFET);
                WingTimer = urand(10000,60000);
            }
            else
                WingTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_flugmeister_addsAI(creature);
    }
};

// ------------------------------------------------------------------------------------------------------------
// UWoM's GM-Pimper 60001
// ------------------------------------------------------------------------------------------------------------

// To find all mount items...
// SELECT `entry`,`spellid_2` FROM `item_template` WHERE `class`=15 AND `subclass`=5 AND `spellid_2`!=0;

#define HordeFactionCnt 16
uint32 HordeFaction[HordeFactionCnt] = {530,729,1052,76,911,510,1067,941,1124,1064,947,81,922,68,1085,889};

#define AllyFactionCnt  17
uint32 AllyFaction[AllyFactionCnt] = {1037,69,930,1068,54,946,47,978,890,730,72,1126,509,1094,1050,471,589};

#define WorldFactionCnt 43
uint32 WorldFaction[WorldFactionCnt] = {1106,529,1012,87,21,910,609,942,909,577,1104,369,92,749,989,1090,1098,1011,93,1015,1038,470,349,1031,1077,809,970,70,932,933,1073,1105,990,934,935,1119,967,1091,59,576,270,1156,1094};

// To find all Horde mounts...
// SELECT `entry`,`spellid_2` FROM `item_template` WHERE `class`=15 AND `subclass`=5 AND `spellid_2`!=0 AND `AllowableRace`=690;

#define HordeMountsCnt  92
uint32 HordeMounts[HordeMountsCnt][2] =
{
    {1132,580},{5665,6653},{5668,6654},{8586,16084},{8588,8395},{8591,10796},{8592,10799},{12330,16080},{12351,16081},{13317,17450},{13331,17462},{13332,17463},{13333,17464},{13334,17465},{15277,18989},{15290,18990},
    {15292,18991},{15293,18992},{18245,22724},{18246,22721},{18247,22718},{18248,22722},{18788,23241},{18789,23242},{18790,23243},{18791,23246},{18793,23247},{18794,23249},{18795,23248},{18796,23250},{18797,23251},
    {18798,23252},{25474,32243},{25475,32244},{25476,32245},{25477,32246},{25531,32295},{25532,32296},{25533,32297},{28927,34795},{28936,33660},{29102,34896},{29103,34897},{29104,34898},{29105,34899},{29220,35020},
    {29221,35022},{29222,35018},{29223,35025},{29224,35027},{29466,22718},{29469,22724},{29470,22722},{29472,22721},{31829,39315},{31831,39317},{31833,39318},{31835,39319},{34129,35028},{41508,55531},{44077,59788},
    {44080,59797},{44083,61467},{44086,61469},{44224,60119},{44226,60116},{44231,59793},{44234,61447},{44690,61230},{45592,63641},{45593,63635},{45595,63640},{45596,63642},{45597,63643},{46099,64658},{46100,64657},
    {46102,64659},{46308,64977},{46743,65644},{46746,65645},{46749,65646},{46750,65641},{46751,65639},{46755,65641},{46757,65646},{46760,65644},{46761,65639},{46764,65645},{46816,66091},{47101,66846},{49046,68056},
    {49098,68188}
};

// To find all Ally mounts...
// SELECT `entry`,`spellid_2` FROM `item_template` WHERE `class`=15 AND `subclass`=5 AND `spellid_2`!=0 AND `AllowableRace`=1101;

#define AllyMountsCnt   94
uint32 AllyMounts[AllyMountsCnt][2] =
{
    {2411,470},{2414,472},{5655,6648},{5656,458},{5864,6777},{5872,6899},{5873,6898},{8563,10873},{8595,10969},{8629,10793},{8631,8394},{8632,10789},{12302,16056},{12303,16055},{12353,16083},{12354,16082},{13086,17229},
    {13321,17453},{13322,17454},{13326,15779},{13327,17459},{13328,17461},{13329,17460},{18241,22717},{18242,22723},{18243,22719},{18244,22720},{18766,23221},{18767,23219},{18772,23225},{18773,23223},{18774,23222},
    {18776,23227},{18777,23229},{18778,23228},{18785,23240},{18786,23238},{18787,23239},{18902,23338},{25470,32235},{25471,32239},{25472,32240},{25473,32242},{25527,32289},{25528,32290},{25529,32292},{28481,34406},
    {29227,34896},{29229,34898},{29230,34899},{29231,34897},{29465,22719},{29467,22720},{29468,22717},{29471,22723},{29743,35711},{29744,35710},{29745,35713},{29746,35712},{29747,35714},{31830,39315},{31832,39317},
    {31834,39318},{31836,39319},{35906,48027},{43956,59785},{43958,59799},{43959,61465},{43961,61470},{44223,60118},{44225,60114},{44230,59791},{44235,61425},{44413,60424},{44689,61229},{45125,63232},{45586,63636},
    {45589,63638},{45590,63639},{45591,63637},{46744,65638},{46745,65637},{46747,65642},{46748,65643},{46752,65640},{46756,65637},{46758,65640},{46759,65638},{46762,65643},{46763,65642},{46815,66090},{47100,66847},
    {49044,68057},{49096,68187}
};

// To find all mounts for both sides...
// SELECT `entry`,`spellid_2` FROM `item_template` WHERE `class`=15 AND `subclass`=5 AND `spellid_2`!=0 AND `AllowableRace`=-1;

#define BothSideMountsCnt   83
uint32 BothSideMounts[BothSideMountsCnt][2] =
{
    {13325,17458},{13335,17481},{19029,23509},{19030,23510},{19872,24242},{19902,24252},{21176,26656},{21218,25953},{21321,26054},{21323,26056},{21324,26055},{30480,36702},{30609,37015},{32314,39798},{32316,39801},
    {32317,39800},{32318,39802},{32319,39803},{32458,40192},{32768,41252},{32857,41513},{32858,41514},{32859,41515},{32860,41516},{32861,41517},{32862,41518},{33224,42776},{33809,43688},{33976,43899},{33977,43900},
    {33999,43927},{34092,44744},{35225,46197},{35226,46199},{35513,46628},{37676,49193},{37719,49322},{37828,49379},{38576,51412},{43516,58615},{43951,59569},{43952,59567},{43953,59568},{43954,59571},{43955,59570},
    {43962,54753},{43986,59650},{44151,59996},{44160,59961},{44164,59976},{44168,60002},{44175,60021},{44177,60024},{44178,60025},{44557,60975},{44558,61309},{44707,61294},{44842,61997},{44843,61996},{45693,63796},
    {45725,63844},{45801,63956},{45802,63963},{46109,64731},{46171,65439},{46708,64927},{46813,66087},{46814,66088},{47179,66906},{47180,67466},{49282,51412},{49283,42776},{49285,46197},{49286,46199},{49290,65917},
    {49636,69395},{50250,71342},{51954,72808},{51955,72807},{52200,73313},{54069,74856},{54797,75596},{54860,75973}
};

#define GOSSIP_GM_PIMPER_01 "Merkt Ihr denn nicht, dass ich genervt bin!? Oder könnt Ihr einfach nur nicht lesen? Ich bin für GM zuständig, nicht für Truthähnchen!"

#define GOSSIP_GM_PIMPER_02 "Ey Mann, was hast du so unter dem Ladentisch!?"
#define GOSSIP_GM_PIMPER_03 "Ein paar Jobs würden mir ganz gut tun."
#define GOSSIP_GM_PIMPER_11 "Ich möchte sooooooooo gerne gross und stark sein! *siehpimperschmachtendan*"
#define GOSSIP_GM_PIMPER_12 "Kannst du mit deinen Käsemessern nur rumfuchteln, oder kannste mir auch was beibringen, Drache?!"

#define GOSSIP_GM_PIMPER_04 "Kannste mir n bisschen Gold pumpen, Alter?"
#define GOSSIP_GM_PIMPER_05 "Ich bin neu hier, und habe noch nicht einmal vernünftige Taschen."
#define GOSSIP_GM_PIMPER_06 "Rück sofort alle deine Mini-Pets raus, oder es knallt!"
#define GOSSIP_GM_PIMPER_07 "Ich könnte da so das eine oder andere Mount für meine Fraktion gebrauchen!"
#define GOSSIP_GM_PIMPER_08 "Ey Drachen, sag mal... wie sieht's denn mit Mounts für beide Seiten aus!?"
#define GOSSIP_GM_PIMPER_09 "Meine Truppe und ich brauchen unbedingt mal wieder n paar Schrottis!"
#define GOSSIP_GM_PIMPER_10 "Also mein Ruf hier in der Gegend lässt ein wenig zu wünschen übrig."

#define MAX_GM_GOLD_ADD 1000000000

enum PIMPER_SPELL_ENUM
{
    SPELL_ALCHEMY_GRAND_MASTER          = 51304,
    SPELL_BLACKSMITHING_GRAND_MASTER    = 51300,
    SPELL_COOKING_GRAND_MASTER          = 51296,
    SPELL_ENCHANTING_GRAND_MASTER       = 51313,
    SPELL_ENGINEERING_GRAND_MASTER      = 51306,
    SPELL_FIRAT_AID_GRAND_MASTER        = 45542,
    SPELL_HERB_GATHERING_GRAND_MASTER   = 50300,
    SPELL_INSCRIPTION_GRAND_MASTER      = 45363,
    SPELL_JEWELCRAFTING_GRAND_MASTER    = 51311,
    SPELL_LEATHERWORKING_GRAND_MASTER   = 51302,
    SPELL_TAILORING_GRAND_MASTER        = 51309,
    SPELL_MINING_GRAND_MASTER           = 50310,
    SPELL_FISHING_GRAND_MASTER          = 51294,
    SPELL_SKINNING_GRAND_MASTER         = 50305,
    SPELL_COLD_WEATHER_FLYING_PASSIVE   = 54197,
    SPELL_TURKEY_FEATHERS               = 61781
};

enum PIMPER_ITEM_ENUM
{
    ITEM_FORORS_CRATE               = 23162,
    ITEM_SCRAPBOT_CONSTRUCTION_KIT  = 40769
};

class npc_uwom_gm_pimper : public CreatureScript
{
public:
    npc_uwom_gm_pimper() : CreatureScript("npc_uwom_gm_pimper") {}

    bool OnGossipHello(Player *pPlayer, Creature *pCreature)
    {
        if (pPlayer->GetSession()->GetSecurity() < SEC_ANWAERTER)
        {
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_GM_PIMPER_01, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            pPlayer->SEND_GOSSIP_MENU(13674, pCreature->GetGUID());
        }
        else
        {
            if (pCreature->isQuestGiver())  pPlayer->PrepareQuestMenu(pCreature->GetGUID());
            if (pCreature->isTrainer())     pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_TEXT_TRAIN,          GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRAIN);
            if (pCreature->isVendor())      pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR,    GOSSIP_TEXT_BROWSE_GOODS,   GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);
            if (pCreature->isAuctioner())   pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, GOSSIP_TEXT_AUCTIONHOUSE,   GOSSIP_SENDER_MAIN, GOSSIP_ACTION_AUCTION);

            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR,    GOSSIP_GM_PIMPER_02,    GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_GM_PIMPER_03,    GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_GM_PIMPER_11,    GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_GM_PIMPER_12,    GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);

            pPlayer->SEND_GOSSIP_MENU(14141, pCreature->GetGUID());
        }
        return true;
    }

    void SendDefaultMenu(Player* pPlayer, Creature* pCreature, uint32 uiAction)
    {
        switch (uiAction)
        {
            // User
            case GOSSIP_ACTION_INFO_DEF + 1:
                pPlayer->CLOSE_GOSSIP_MENU();
                break;

            // Standard-Aktionen
            case GOSSIP_ACTION_TRAIN:
                pPlayer->GetSession()->SendTrainerList(pCreature->GetGUID());
                break;
            case GOSSIP_ACTION_TRADE:
                pPlayer->GetSession()->SendListInventory(pCreature->GetGUID());
                break;
            case GOSSIP_ACTION_AUCTION:
                pCreature->setFaction(pPlayer->getFaction());
                pPlayer->GetSession()->SendAuctionHello(pCreature->GetGUID(), pCreature);
                pCreature->setFaction(35);
                break;

            // Unterm Ladentisch
            case GOSSIP_ACTION_INFO_DEF + 2:
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, GOSSIP_GM_PIMPER_04,    GOSSIP_SENDER_SEC_BANK, GOSSIP_ACTION_INFO_DEF + 4);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR,    GOSSIP_GM_PIMPER_05,    GOSSIP_SENDER_SEC_BANK, GOSSIP_ACTION_INFO_DEF + 5);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR,    GOSSIP_GM_PIMPER_06,    GOSSIP_SENDER_SEC_BANK, GOSSIP_ACTION_INFO_DEF + 6);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR,    GOSSIP_GM_PIMPER_07,    GOSSIP_SENDER_SEC_BANK, GOSSIP_ACTION_INFO_DEF + 7);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR,    GOSSIP_GM_PIMPER_08,    GOSSIP_SENDER_SEC_BANK, GOSSIP_ACTION_INFO_DEF + 8);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR,    GOSSIP_GM_PIMPER_09,    GOSSIP_SENDER_SEC_BANK, GOSSIP_ACTION_INFO_DEF + 9);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_GM_PIMPER_10,    GOSSIP_SENDER_SEC_BANK, GOSSIP_ACTION_INFO_DEF + 10);
                pPlayer->SEND_GOSSIP_MENU(14208, pCreature->GetGUID());
                break;

            // Ein paar Jobs
            case GOSSIP_ACTION_INFO_DEF + 3:
                if ((pPlayer->GetFreePrimaryProfessionPoints() == 0 && pPlayer->GetSession()->GetSecurity() >= SEC_HGM) || (pPlayer->GetFreePrimaryProfessionPoints() > 0))
                {
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_TEXT_ALCHEMY,        GOSSIP_SENDER_SEC_PROFTRAIN,    GOSSIP_ACTION_INFO_DEF + 11);
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_TEXT_BLACKSMITHING,  GOSSIP_SENDER_SEC_PROFTRAIN,    GOSSIP_ACTION_INFO_DEF + 12);
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_TEXT_COOKING,        GOSSIP_SENDER_SEC_PROFTRAIN,    GOSSIP_ACTION_INFO_DEF + 13);
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_TEXT_ENCHANTING,     GOSSIP_SENDER_SEC_PROFTRAIN,    GOSSIP_ACTION_INFO_DEF + 14);
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_TEXT_ENGINEERING,    GOSSIP_SENDER_SEC_PROFTRAIN,    GOSSIP_ACTION_INFO_DEF + 15);
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_TEXT_FIRSTAID,       GOSSIP_SENDER_SEC_PROFTRAIN,    GOSSIP_ACTION_INFO_DEF + 16);
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_TEXT_HERBALISM,      GOSSIP_SENDER_SEC_PROFTRAIN,    GOSSIP_ACTION_INFO_DEF + 17);
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_TEXT_INSCRIPTION,    GOSSIP_SENDER_SEC_PROFTRAIN,    GOSSIP_ACTION_INFO_DEF + 18);
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_TEXT_JEWELCRAFTING,  GOSSIP_SENDER_SEC_PROFTRAIN,    GOSSIP_ACTION_INFO_DEF + 19);
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_TEXT_LEATHERWORKING, GOSSIP_SENDER_SEC_PROFTRAIN,    GOSSIP_ACTION_INFO_DEF + 20);
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_TEXT_TAILORING,      GOSSIP_SENDER_SEC_PROFTRAIN,    GOSSIP_ACTION_INFO_DEF + 21);
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_TEXT_MINING,         GOSSIP_SENDER_SEC_PROFTRAIN,    GOSSIP_ACTION_INFO_DEF + 22);
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_TEXT_FISHING,        GOSSIP_SENDER_SEC_PROFTRAIN,    GOSSIP_ACTION_INFO_DEF + 23);
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_TEXT_SKINNING,       GOSSIP_SENDER_SEC_PROFTRAIN,    GOSSIP_ACTION_INFO_DEF + 24);
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_TEXT_RIDING,         GOSSIP_SENDER_SEC_PROFTRAIN,    GOSSIP_ACTION_INFO_DEF + 25);

                    if (pPlayer->GetSession()->GetSecurity() >= SEC_OGM)
                        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_TEXT_ALL_PROFS,      GOSSIP_SENDER_SEC_PROFTRAIN,    GOSSIP_ACTION_INFO_DEF + 26);

                    pPlayer->SEND_GOSSIP_MENU(9331, pCreature->GetGUID());
                }
                else if (pPlayer->GetFreePrimaryProfessionPoints() == 0 && pPlayer->GetSession()->GetSecurity() < SEC_HGM)
                {
                    pPlayer->GetSession()->SendNotification("Dein GM-Level erlaubt nicht mehr primäre Berufe.");

                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_TEXT_COOKING,        GOSSIP_SENDER_SEC_PROFTRAIN,    GOSSIP_ACTION_INFO_DEF + 13);
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_TEXT_FIRSTAID,       GOSSIP_SENDER_SEC_PROFTRAIN,    GOSSIP_ACTION_INFO_DEF + 16);
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_TEXT_FISHING,        GOSSIP_SENDER_SEC_PROFTRAIN,    GOSSIP_ACTION_INFO_DEF + 23);
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_TEXT_RIDING,         GOSSIP_SENDER_SEC_PROFTRAIN,    GOSSIP_ACTION_INFO_DEF + 25);

                    pPlayer->SEND_GOSSIP_MENU(9331, pCreature->GetGUID());
                }
                break;

            // Leveln
            case GOSSIP_ACTION_INFO_DEF + 4:
                pPlayer->GiveLevel(DEFAULT_MAX_LEVEL);
                pPlayer->CLOSE_GOSSIP_MENU();
                break;

            // Maxskill
            case GOSSIP_ACTION_INFO_DEF + 5:
                pPlayer->UpdateSkillsToMaxSkillsForLevel();
                pPlayer->CLOSE_GOSSIP_MENU();
            break;
        }
    }

    void SendActionMenu(Player* pPlayer, Creature* pCreature, uint32 uiAction)
    {
        switch(uiAction)
        {
            // Gold
            case GOSSIP_ACTION_INFO_DEF + 4:
                if (pPlayer->GetSession()->GetSecurity() < SEC_HGM && pPlayer->GetMoney() >= MAX_GM_GOLD_ADD)
                    pPlayer->GetSession()->SendNotification("Mit deinem GM-Level bekommst du nicht mehr Gold.");
                else
                    pPlayer->ModifyMoney(+MAX_GM_GOLD_ADD); // 100K Gold
                pPlayer->CLOSE_GOSSIP_MENU();
                break;

            // Koffer
            case GOSSIP_ACTION_INFO_DEF + 5:
                if (pPlayer->HasItemCount(ITEM_FORORS_CRATE, 11, true))
                    pPlayer->GetSession()->SendNotification("Du hast bereits 11 GM-Koffer!");
                else
                    ((ScriptedAI*)pCreature)->addItem(pPlayer, ITEM_FORORS_CRATE, 11); // 11 Koffer
                pPlayer->CLOSE_GOSSIP_MENU();
                break;

            // Mini-Pets
            case GOSSIP_ACTION_INFO_DEF + 6:
                for (uint8 i=0; i<FirecallerPresentsCnt; ++i)
                    if (!pPlayer->HasSpell(FirecallerPresents[i][1]))
                        pPlayer->learnSpell(FirecallerPresents[i][1], false);
                pPlayer->CLOSE_GOSSIP_MENU();
                break;

            // Mounts (Ally/Horde)
            case GOSSIP_ACTION_INFO_DEF + 7:
                if (pPlayer->GetTeam() == ALLIANCE)
                {
                    for (uint8 i=0; i<AllyMountsCnt; ++i)
                        if (!pPlayer->HasSpell(AllyMounts[i][1]))
                            pPlayer->learnSpell(AllyMounts[i][1], false);
                }
                else
                {
                    for (uint8 i=0; i<HordeMountsCnt; ++i)
                        if (!pPlayer->HasSpell(HordeMounts[i][1]))
                            pPlayer->learnSpell(HordeMounts[i][1], false);
                }
                pPlayer->CLOSE_GOSSIP_MENU();
                break;

            // Mounts (Both Side)
            case GOSSIP_ACTION_INFO_DEF + 8:
                for (uint8 i=0; i<BothSideMountsCnt; ++i)
                    if (!pPlayer->HasSpell(BothSideMounts[i][1]))
                            pPlayer->learnSpell(BothSideMounts[i][1], false);
                pPlayer->CLOSE_GOSSIP_MENU();
                break;

            // Schrottis
            case GOSSIP_ACTION_INFO_DEF + 9:
                if (pPlayer->HasItemCount(ITEM_SCRAPBOT_CONSTRUCTION_KIT, 40, true))
                    pPlayer->GetSession()->SendNotification("Mehr als 40 Schrottis gibbet nit.");
                else
                    ((ScriptedAI*)pCreature)->addItem(pPlayer, ITEM_SCRAPBOT_CONSTRUCTION_KIT, 20); // 20 Schrottis
                pPlayer->CLOSE_GOSSIP_MENU();
                break;

            // Ruf
            case GOSSIP_ACTION_INFO_DEF + 10:
                if (pPlayer->GetTeam() == ALLIANCE)
                {
                    for (uint8 i=0; i<AllyFactionCnt; ++i)
                    {
                        FactionEntry const* fe = sFactionStore.LookupEntry(AllyFaction[i]);
                        pPlayer->GetReputationMgr().ModifyReputation(fe, ReputationMgr::Reputation_Cap);
                    }
                }
                else
                {
                    for (uint8 i=0; i<HordeFactionCnt; ++i)
                    {
                        FactionEntry const* fe = sFactionStore.LookupEntry(HordeFaction[i]);
                        pPlayer->GetReputationMgr().ModifyReputation(fe, ReputationMgr::Reputation_Cap);
                    }
                }
                for (uint8 i=0; i<WorldFactionCnt; ++i)
                {
                    FactionEntry const* fe = sFactionStore.LookupEntry(WorldFaction[i]);
                    pPlayer->GetReputationMgr().ModifyReputation(fe, ReputationMgr::Reputation_Cap);
                }
                pPlayer->CLOSE_GOSSIP_MENU();
                break;
            // -----------------------------------------------------------------------------------
            // -------------------------------------- BERUFE -------------------------------------
            // -----------------------------------------------------------------------------------
            // Alchimie
            case GOSSIP_ACTION_INFO_DEF + 11:
                if (!pPlayer->HasSpell(SPELL_ALCHEMY_GRAND_MASTER))
                {
                    pPlayer->learnSpellHighRank(SPELL_ALCHEMY_GRAND_MASTER);
                    pPlayer->SetSkill(SKILL_ALCHEMY, 1, pPlayer->GetPureMaxSkillValue(SKILL_ALCHEMY), pPlayer->GetPureMaxSkillValue(SKILL_ALCHEMY));
                    LearnAllSkillRecipes(pPlayer, SKILL_ALCHEMY);
                }
                else
                    if (pPlayer->HasSpell(SPELL_ALCHEMY_GRAND_MASTER))
                        LearnAllSkillRecipes(pPlayer, SKILL_ALCHEMY);
                pPlayer->CLOSE_GOSSIP_MENU();
                break;
            // Schmieden
            case GOSSIP_ACTION_INFO_DEF + 12:
                if (!pPlayer->HasSpell(SPELL_BLACKSMITHING_GRAND_MASTER))
                {
                    pPlayer->learnSpellHighRank(SPELL_BLACKSMITHING_GRAND_MASTER);
                    pPlayer->SetSkill(SKILL_BLACKSMITHING, 1, pPlayer->GetPureMaxSkillValue(SKILL_BLACKSMITHING), pPlayer->GetPureMaxSkillValue(SKILL_BLACKSMITHING));
                    LearnAllSkillRecipes(pPlayer, SKILL_BLACKSMITHING);
                }
                else
                    if (pPlayer->HasSpell(SPELL_BLACKSMITHING_GRAND_MASTER))
                        LearnAllSkillRecipes(pPlayer, SKILL_BLACKSMITHING);
                pPlayer->CLOSE_GOSSIP_MENU();
                break;
            // Kochen
            case GOSSIP_ACTION_INFO_DEF + 13:
                if (!pPlayer->HasSpell(SPELL_COOKING_GRAND_MASTER))
                {
                    pPlayer->learnSpellHighRank(SPELL_COOKING_GRAND_MASTER);
                    pPlayer->SetSkill(SKILL_COOKING, 1, pPlayer->GetPureMaxSkillValue(SKILL_COOKING), pPlayer->GetPureMaxSkillValue(SKILL_COOKING));
                    LearnAllSkillRecipes(pPlayer, SKILL_COOKING);
                }
                else
                    if (pPlayer->HasSpell(SPELL_COOKING_GRAND_MASTER))
                        LearnAllSkillRecipes(pPlayer, SKILL_COOKING);
                pPlayer->CLOSE_GOSSIP_MENU();
                break;
            // Verzaubern
            case GOSSIP_ACTION_INFO_DEF + 14:
                if (!pPlayer->HasSpell(SPELL_ENCHANTING_GRAND_MASTER))
                {
                    pPlayer->learnSpellHighRank(SPELL_ENCHANTING_GRAND_MASTER);
                    pPlayer->SetSkill(SKILL_ENCHANTING, 1, pPlayer->GetPureMaxSkillValue(SKILL_ENCHANTING), pPlayer->GetPureMaxSkillValue(SKILL_ENCHANTING));
                    LearnAllSkillRecipes(pPlayer, SKILL_ENCHANTING);
                }
                else
                    if (pPlayer->HasSpell(SPELL_ENCHANTING_GRAND_MASTER))
                        LearnAllSkillRecipes(pPlayer, SKILL_ENCHANTING);
                pPlayer->CLOSE_GOSSIP_MENU();
                break;
            // Ingenieurwesen
            case GOSSIP_ACTION_INFO_DEF + 15:
                if (!pPlayer->HasSpell(SPELL_ENGINEERING_GRAND_MASTER))
                {
                    pPlayer->learnSpellHighRank(SPELL_ENGINEERING_GRAND_MASTER);
                    pPlayer->SetSkill(SKILL_ENGINERING, 1, pPlayer->GetPureMaxSkillValue(SKILL_ENGINERING), pPlayer->GetPureMaxSkillValue(SKILL_ENGINERING));
                    LearnAllSkillRecipes(pPlayer, SKILL_ENGINERING);
                }
                else
                    if (pPlayer->HasSpell(SPELL_ENGINEERING_GRAND_MASTER))
                        LearnAllSkillRecipes(pPlayer, SKILL_ENGINERING);
                pPlayer->CLOSE_GOSSIP_MENU();
                break;
            // Erste Hilfe
            case GOSSIP_ACTION_INFO_DEF + 16:
                if (!pPlayer->HasSpell(SPELL_FIRAT_AID_GRAND_MASTER))
                {
                    pPlayer->learnSpellHighRank(SPELL_FIRAT_AID_GRAND_MASTER);
                    pPlayer->SetSkill(SKILL_FIRST_AID, 1, pPlayer->GetPureMaxSkillValue(SKILL_FIRST_AID), pPlayer->GetPureMaxSkillValue(SKILL_FIRST_AID));
                }
                pPlayer->CLOSE_GOSSIP_MENU();
                break;
            // Kräuterkunde
            case GOSSIP_ACTION_INFO_DEF + 17:
                if (!pPlayer->HasSpell(SPELL_HERB_GATHERING_GRAND_MASTER))
                {
                    pPlayer->learnSpellHighRank(SPELL_HERB_GATHERING_GRAND_MASTER);
                    pPlayer->SetSkill(SKILL_HERBALISM, 1, pPlayer->GetPureMaxSkillValue(SKILL_HERBALISM), pPlayer->GetPureMaxSkillValue(SKILL_HERBALISM));
                }
                pPlayer->CLOSE_GOSSIP_MENU();
                break;
            // Inschriftenkunde
            case GOSSIP_ACTION_INFO_DEF + 18:
                if (!pPlayer->HasSpell(SPELL_INSCRIPTION_GRAND_MASTER))
                {
                    pPlayer->learnSpellHighRank(SPELL_INSCRIPTION_GRAND_MASTER);
                    pPlayer->SetSkill(SKILL_INSCRIPTION, 1, pPlayer->GetPureMaxSkillValue(SKILL_INSCRIPTION), pPlayer->GetPureMaxSkillValue(SKILL_INSCRIPTION));
                    LearnAllSkillRecipes(pPlayer, SKILL_INSCRIPTION);
                }
                else
                    if (pPlayer->HasSpell(SPELL_INSCRIPTION_GRAND_MASTER))
                        LearnAllSkillRecipes(pPlayer, SKILL_INSCRIPTION);
                pPlayer->CLOSE_GOSSIP_MENU();
                break;
            // Juwelenschleifen
            case GOSSIP_ACTION_INFO_DEF + 19:
                if (!pPlayer->HasSpell(SPELL_JEWELCRAFTING_GRAND_MASTER))
                {
                    pPlayer->learnSpellHighRank(SPELL_JEWELCRAFTING_GRAND_MASTER);
                    pPlayer->SetSkill(SKILL_JEWELCRAFTING, 1, pPlayer->GetPureMaxSkillValue(SKILL_JEWELCRAFTING), pPlayer->GetPureMaxSkillValue(SKILL_JEWELCRAFTING));
                    LearnAllSkillRecipes(pPlayer, SKILL_JEWELCRAFTING);
                }
                else
                    if (pPlayer->HasSpell(SPELL_JEWELCRAFTING_GRAND_MASTER))
                        LearnAllSkillRecipes(pPlayer, SKILL_JEWELCRAFTING);
                pPlayer->CLOSE_GOSSIP_MENU();
                break;
            // Lederverarbeitung
            case GOSSIP_ACTION_INFO_DEF + 20:
                if (!pPlayer->HasSpell(SPELL_LEATHERWORKING_GRAND_MASTER))
                {
                    pPlayer->learnSpellHighRank(SPELL_LEATHERWORKING_GRAND_MASTER);
                    pPlayer->SetSkill(SKILL_LEATHERWORKING, 1, pPlayer->GetPureMaxSkillValue(SKILL_LEATHERWORKING), pPlayer->GetPureMaxSkillValue(SKILL_LEATHERWORKING));
                    LearnAllSkillRecipes(pPlayer, SKILL_LEATHERWORKING);
                }
                else
                    if (pPlayer->HasSpell(SPELL_LEATHERWORKING_GRAND_MASTER))
                        LearnAllSkillRecipes(pPlayer, SKILL_LEATHERWORKING);
                pPlayer->CLOSE_GOSSIP_MENU();
                break;
            // Schneidern
            case GOSSIP_ACTION_INFO_DEF + 21:
                if (!pPlayer->HasSpell(SPELL_TAILORING_GRAND_MASTER))
                {
                    pPlayer->learnSpellHighRank(SPELL_TAILORING_GRAND_MASTER);
                    pPlayer->SetSkill(SKILL_TAILORING, 1, pPlayer->GetPureMaxSkillValue(SKILL_TAILORING), pPlayer->GetPureMaxSkillValue(SKILL_TAILORING));
                    LearnAllSkillRecipes(pPlayer, SKILL_TAILORING);
                }
                else
                    if (pPlayer->HasSpell(SPELL_TAILORING_GRAND_MASTER))
                        LearnAllSkillRecipes(pPlayer, SKILL_TAILORING);
                pPlayer->CLOSE_GOSSIP_MENU();
                break;
            // Bergbau
            case GOSSIP_ACTION_INFO_DEF + 22:
                if (!pPlayer->HasSpell(SPELL_MINING_GRAND_MASTER))
                {
                    pPlayer->learnSpellHighRank(SPELL_MINING_GRAND_MASTER);
                    pPlayer->SetSkill(SKILL_MINING, 1, pPlayer->GetPureMaxSkillValue(SKILL_MINING), pPlayer->GetPureMaxSkillValue(SKILL_MINING));
                }
                pPlayer->CLOSE_GOSSIP_MENU();
                break;
            // Angeln
            case GOSSIP_ACTION_INFO_DEF + 23:
                if (!pPlayer->HasSpell(SPELL_FISHING_GRAND_MASTER))
                {
                    pPlayer->learnSpellHighRank(SPELL_FISHING_GRAND_MASTER);
                    pPlayer->SetSkill(SKILL_FISHING, 1, pPlayer->GetPureMaxSkillValue(SKILL_FISHING), pPlayer->GetPureMaxSkillValue(SKILL_FISHING));
                }
                pPlayer->CLOSE_GOSSIP_MENU();
                break;
            // Kürschnern
            case GOSSIP_ACTION_INFO_DEF + 24:
                if (!pPlayer->HasSpell(SPELL_SKINNING_GRAND_MASTER))
                {
                    pPlayer->learnSpellHighRank(SPELL_SKINNING_GRAND_MASTER);
                    pPlayer->SetSkill(SKILL_SKINNING, 1, pPlayer->GetPureMaxSkillValue(SKILL_SKINNING), pPlayer->GetPureMaxSkillValue(SKILL_SKINNING));
                }
                pPlayer->CLOSE_GOSSIP_MENU();
                break;
            // Reiten
            case GOSSIP_ACTION_INFO_DEF + 25:
                if (!pPlayer->HasSpell(SPELL_COLD_WEATHER_FLYING_PASSIVE))
                {
                    pPlayer->learnSpellHighRank(SPELL_COLD_WEATHER_FLYING_PASSIVE);
                    pPlayer->SetSkill(SKILL_RIDING, 1, pPlayer->GetPureMaxSkillValue(SKILL_RIDING), pPlayer->GetPureMaxSkillValue(SKILL_RIDING));
                }
                pPlayer->CLOSE_GOSSIP_MENU();
                break;
            // Alle Berufe
            case GOSSIP_ACTION_INFO_DEF + 26:
                if (pPlayer->GetSession()->GetSecurity() >= SEC_OGM)
                {
                    // Alchimie
                    if (!pPlayer->HasSpell(SPELL_ALCHEMY_GRAND_MASTER))
                    {
                        pPlayer->learnSpellHighRank(SPELL_ALCHEMY_GRAND_MASTER);
                        pPlayer->SetSkill(SKILL_ALCHEMY, 1, pPlayer->GetPureMaxSkillValue(SKILL_ALCHEMY), pPlayer->GetPureMaxSkillValue(SKILL_ALCHEMY));
                        LearnAllSkillRecipes(pPlayer, SKILL_ALCHEMY);
                    }
                    else
                        if (pPlayer->HasSpell(SPELL_ALCHEMY_GRAND_MASTER))
                            LearnAllSkillRecipes(pPlayer, SKILL_ALCHEMY);
                    // Schmieden
                    if (!pPlayer->HasSpell(SPELL_BLACKSMITHING_GRAND_MASTER))
                    {
                        pPlayer->learnSpellHighRank(SPELL_BLACKSMITHING_GRAND_MASTER);
                        pPlayer->SetSkill(SKILL_BLACKSMITHING, 1, pPlayer->GetPureMaxSkillValue(SKILL_BLACKSMITHING), pPlayer->GetPureMaxSkillValue(SKILL_BLACKSMITHING));
                        LearnAllSkillRecipes(pPlayer, SKILL_BLACKSMITHING);
                    }
                    else
                        if (pPlayer->HasSpell(SPELL_BLACKSMITHING_GRAND_MASTER))
                            LearnAllSkillRecipes(pPlayer, SKILL_BLACKSMITHING);
                    // Kochen
                    if (!pPlayer->HasSpell(SPELL_COOKING_GRAND_MASTER))
                    {
                        pPlayer->learnSpellHighRank(SPELL_COOKING_GRAND_MASTER);
                        pPlayer->SetSkill(SKILL_COOKING, 1, pPlayer->GetPureMaxSkillValue(SKILL_COOKING), pPlayer->GetPureMaxSkillValue(SKILL_COOKING));
                        LearnAllSkillRecipes(pPlayer, SKILL_COOKING);
                    }
                    else
                        if (pPlayer->HasSpell(SPELL_COOKING_GRAND_MASTER))
                            LearnAllSkillRecipes(pPlayer, SKILL_COOKING);
                    // Verzaubern
                    if (!pPlayer->HasSpell(SPELL_ENCHANTING_GRAND_MASTER))
                    {
                        pPlayer->learnSpellHighRank(SPELL_ENCHANTING_GRAND_MASTER);
                        pPlayer->SetSkill(SKILL_ENCHANTING, 1, pPlayer->GetPureMaxSkillValue(SKILL_ENCHANTING), pPlayer->GetPureMaxSkillValue(SKILL_ENCHANTING));
                        LearnAllSkillRecipes(pPlayer, SKILL_ENCHANTING);
                    }
                    else
                        if (pPlayer->HasSpell(SPELL_ENCHANTING_GRAND_MASTER))
                            LearnAllSkillRecipes(pPlayer, SKILL_ENCHANTING);
                    // Ingenieurwesen
                    if (!pPlayer->HasSpell(SPELL_ENGINEERING_GRAND_MASTER))
                    {
                        pPlayer->learnSpellHighRank(SPELL_ENGINEERING_GRAND_MASTER);
                        pPlayer->SetSkill(SKILL_ENGINERING, 1, pPlayer->GetPureMaxSkillValue(SKILL_ENGINERING), pPlayer->GetPureMaxSkillValue(SKILL_ENGINERING));
                        LearnAllSkillRecipes(pPlayer, SKILL_ENGINERING);
                    }
                    else
                        if (pPlayer->HasSpell(SPELL_ENGINEERING_GRAND_MASTER))
                            LearnAllSkillRecipes(pPlayer, SKILL_ENGINERING);
                    // Erste Hilfe
                    if (!pPlayer->HasSpell(SPELL_FIRAT_AID_GRAND_MASTER))
                    {
                        pPlayer->learnSpellHighRank(SPELL_FIRAT_AID_GRAND_MASTER);
                        pPlayer->SetSkill(SKILL_FIRST_AID, 1, pPlayer->GetPureMaxSkillValue(SKILL_FIRST_AID), pPlayer->GetPureMaxSkillValue(SKILL_FIRST_AID));
                    }
                    // Kräuterkunde
                    if (!pPlayer->HasSpell(SPELL_HERB_GATHERING_GRAND_MASTER))
                    {
                        pPlayer->learnSpellHighRank(SPELL_HERB_GATHERING_GRAND_MASTER);
                        pPlayer->SetSkill(SKILL_HERBALISM, 1, pPlayer->GetPureMaxSkillValue(SKILL_HERBALISM), pPlayer->GetPureMaxSkillValue(SKILL_HERBALISM));
                    }
                    // Inschriftenkunde
                    if (!pPlayer->HasSpell(SPELL_INSCRIPTION_GRAND_MASTER))
                    {
                        pPlayer->learnSpellHighRank(SPELL_INSCRIPTION_GRAND_MASTER);
                        pPlayer->SetSkill(SKILL_INSCRIPTION, 1, pPlayer->GetPureMaxSkillValue(SKILL_INSCRIPTION), pPlayer->GetPureMaxSkillValue(SKILL_INSCRIPTION));
                        LearnAllSkillRecipes(pPlayer, SKILL_INSCRIPTION);
                    }
                    else
                        if (pPlayer->HasSpell(SPELL_INSCRIPTION_GRAND_MASTER))
                            LearnAllSkillRecipes(pPlayer, SKILL_INSCRIPTION);
                    // Juwelenschleifen
                    if (!pPlayer->HasSpell(SPELL_JEWELCRAFTING_GRAND_MASTER))
                    {
                        pPlayer->learnSpellHighRank(SPELL_JEWELCRAFTING_GRAND_MASTER);
                        pPlayer->SetSkill(SKILL_JEWELCRAFTING, 1, pPlayer->GetPureMaxSkillValue(SKILL_JEWELCRAFTING), pPlayer->GetPureMaxSkillValue(SKILL_JEWELCRAFTING));
                        LearnAllSkillRecipes(pPlayer, SKILL_JEWELCRAFTING);
                    }
                    else
                        if (pPlayer->HasSpell(SPELL_JEWELCRAFTING_GRAND_MASTER))
                            LearnAllSkillRecipes(pPlayer, SKILL_JEWELCRAFTING);
                    // Lederverarbeitung
                    if (!pPlayer->HasSpell(SPELL_LEATHERWORKING_GRAND_MASTER))
                    {
                        pPlayer->learnSpellHighRank(SPELL_LEATHERWORKING_GRAND_MASTER);
                        pPlayer->SetSkill(SKILL_LEATHERWORKING, 1, pPlayer->GetPureMaxSkillValue(SKILL_LEATHERWORKING), pPlayer->GetPureMaxSkillValue(SKILL_LEATHERWORKING));
                        LearnAllSkillRecipes(pPlayer, SKILL_LEATHERWORKING);
                    }
                    else
                        if (pPlayer->HasSpell(SPELL_LEATHERWORKING_GRAND_MASTER))
                            LearnAllSkillRecipes(pPlayer, SKILL_LEATHERWORKING);
                    // Schneidern
                    if (!pPlayer->HasSpell(SPELL_TAILORING_GRAND_MASTER))
                    {
                        pPlayer->learnSpellHighRank(SPELL_TAILORING_GRAND_MASTER);
                        pPlayer->SetSkill(SKILL_TAILORING, 1, pPlayer->GetPureMaxSkillValue(SKILL_TAILORING), pPlayer->GetPureMaxSkillValue(SKILL_TAILORING));
                        LearnAllSkillRecipes(pPlayer, SKILL_TAILORING);
                    }
                    else
                        if (pPlayer->HasSpell(SPELL_TAILORING_GRAND_MASTER))
                            LearnAllSkillRecipes(pPlayer, SKILL_TAILORING);
                    // Bergbau
                    if (!pPlayer->HasSpell(SPELL_MINING_GRAND_MASTER))
                    {
                        pPlayer->learnSpellHighRank(SPELL_MINING_GRAND_MASTER);
                        pPlayer->SetSkill(SKILL_MINING, 1, pPlayer->GetPureMaxSkillValue(SKILL_MINING), pPlayer->GetPureMaxSkillValue(SKILL_MINING));
                    }
                    // Angeln
                    if (!pPlayer->HasSpell(SPELL_FISHING_GRAND_MASTER))
                    {
                        pPlayer->learnSpellHighRank(SPELL_FISHING_GRAND_MASTER);
                        pPlayer->SetSkill(SKILL_FISHING, 1, pPlayer->GetPureMaxSkillValue(SKILL_FISHING), pPlayer->GetPureMaxSkillValue(SKILL_FISHING));
                    }
                    // Kürschnern
                    if (!pPlayer->HasSpell(SPELL_SKINNING_GRAND_MASTER))
                    {
                        pPlayer->learnSpellHighRank(SPELL_SKINNING_GRAND_MASTER);
                        pPlayer->SetSkill(SKILL_SKINNING, 1, pPlayer->GetPureMaxSkillValue(SKILL_SKINNING), pPlayer->GetPureMaxSkillValue(SKILL_SKINNING));
                    }
                    // Reiten
                    if (!pPlayer->HasSpell(SPELL_COLD_WEATHER_FLYING_PASSIVE))
                    {
                        pPlayer->learnSpellHighRank(SPELL_COLD_WEATHER_FLYING_PASSIVE);
                        pPlayer->SetSkill(SKILL_RIDING, 1, pPlayer->GetPureMaxSkillValue(SKILL_RIDING), pPlayer->GetPureMaxSkillValue(SKILL_RIDING));
                    }
                }
                pPlayer->CLOSE_GOSSIP_MENU();
                break;
        }
    }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();

        switch(uiSender)
        {
            case GOSSIP_SENDER_MAIN:
                if (pPlayer->GetSession()->GetSecurity() < SEC_ANWAERTER)
                    pCreature->CastSpell(pPlayer, SPELL_TURKEY_FEATHERS, true); // Truthahnfedern
                SendDefaultMenu(pPlayer, pCreature, uiAction);
                break;
            case GOSSIP_SENDER_SEC_BANK:
            case GOSSIP_SENDER_SEC_PROFTRAIN:
                SendActionMenu(pPlayer, pCreature, uiAction);
                break;
        }
        return true;
    }
};

// ------------------------------------------------------------------------------------------------------------
// UWoM's User-Pimper 60002
// ------------------------------------------------------------------------------------------------------------

#define GOSSIP_USER_PIMPER_01 "Ey Mann, was hast du so unter dem Ladentisch!?"
#define GOSSIP_USER_PIMPER_02 "Ein paar Jobs würden mir ganz gut tun."
#define GOSSIP_USER_PIMPER_03 "Ich möchte gerne meine Skills maximieren."
#define GOSSIP_USER_PIMPER_04 "Rück sofort alle deine Mini-Pets raus, oder es knallt!"
#define GOSSIP_USER_PIMPER_05 "Also mein Ruf hier in der Gegend lässt ein wenig zu wünschen übrig."
#define GOSSIP_USER_PIMPER_06 "Sag mal, hast du auch Rezepte zu den Berufen!?"
#define GOSSIP_USER_PIMPER_07 "Was kosten mich eure Dienste (Preisliste)!?"

#define COST_STRING_USER_PIMPER_PETS    "'Alle' Minipets lernen: "
#define COST_STRING_USER_PIMPER_REP     "'Alle' Fraktionen ehrfürchtig: "
#define COST_STRING_USER_PIMPER_PROF    "1 Beruf lernen (inkl. max. Skill): "
#define COST_STRING_USER_PIMPER_RECIPES "Alle Rezepte für 1 Beruf lernen: "
#define COST_STRING_USER_PIMPER_SKILL   "'Alle' Fähigkeiten auf max. Skill: "

#define PIMPER_NOT_ENOUGH   "Du hast leider nicht genug %s für diesen Dienst!"
#define PIMPER_PROF_MAX     "Du musst den Beruf auf Maximum haben!"
#define PIMPER_PROF_LIMIT   "Du hast bereits das Maximum an Berufen!"

struct UserPimper_PriceSetup
{
    uint8 Cost_Type;                // 0 = Money - 1 = Honor - 2 = Arena Points - 3 = Item

    uint32 Costs_Item;              // Used (must be set) if Cost_Type == 3
    uint32 Costs_AllMiniPets;       // Costs (amount) to learn all mini pets
    uint32 Costs_Reputation;        // Costs (amount) to max. all factions (Horde/Ally and world factions)
    uint32 Costs_Profession;        // Costs (amount) to learn a profession as grand master and get max. skill for it
    uint32 Costs_AllRecipes;        // Costs (amount) to learn all recipes for one profession
    uint32 Costs_MaxSkill;          // Costs (amount) to set the max. skill for one profession

    bool PresentsAllowed;

    // Cost strings for the gossip
    std::string str_Item;
    std::string str_AllMiniPets;
    std::string str_Reputation;
    std::string str_Profession;
    std::string str_AllRecipes;
    std::string str_MaxSkill;
    std::string str_bottom;
};

class npc_uwom_user_pimper : public CreatureScript
{
public:
    npc_uwom_user_pimper() : CreatureScript("npc_uwom_user_pimper") { }

    struct npc_uwom_user_pimperAI : public ScriptedAI
    {
        npc_uwom_user_pimperAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            ps.Cost_Type = sConfig->GetIntDefault("UserPimper.Costs.Type", 1);
            ps.Costs_Item = sConfig->GetIntDefault("UserPimper.Costs.Item", 0);

            ps.Costs_AllMiniPets = sConfig->GetIntDefault("UserPimper.Costs.MiniPets", 1000000);
            ps.Costs_Reputation = sConfig->GetIntDefault("UserPimper.Costs.Reputation", 500000);
            ps.Costs_Profession = sConfig->GetIntDefault("UserPimper.Costs.Profession", 200000);
            ps.Costs_AllRecipes = sConfig->GetIntDefault("UserPimper.Costs.Recipes", 50000);
            ps.Costs_MaxSkill = sConfig->GetIntDefault("UserPimper.Costs.MaxSkill", 50000);

            ps.PresentsAllowed = sConfig->GetBoolDefault("UserPimper.PresentsAllowed", false);

            if (ps.Cost_Type == 3)
            {
                item = sObjectMgr->GetItemTemplate(ps.Costs_Item);
                if (item)
                    ps.str_Item = item->Name1;
            }
            else
                item = NULL;

            if (ps.Cost_Type == 0)
            {
                ps.Costs_AllMiniPets = ps.Costs_AllMiniPets*GOLD;
                ps.Costs_Reputation = ps.Costs_Reputation*GOLD;
                ps.Costs_Profession = ps.Costs_Profession*GOLD;
                ps.Costs_AllRecipes = ps.Costs_AllRecipes*GOLD;
                ps.Costs_MaxSkill = ps.Costs_MaxSkill*GOLD;
            }
            InitStrings();
        }

        UserPimper_PriceSetup ps;
        ItemTemplate const* item;

        void Reset() {}

        void InitStrings()
        {
            char* tmpchars = (char*)malloc(32);
            std::string tmpstr;

            if (ps.Cost_Type == 0)
            {
                sprintf(tmpchars, "%i", ps.Costs_AllMiniPets/GOLD);
                tmpstr.append(COST_STRING_USER_PIMPER_PETS).append(tmpchars);
                ps.str_AllMiniPets = tmpstr;
                tmpstr.clear();

                sprintf(tmpchars, "%i", ps.Costs_Reputation/GOLD);
                tmpstr.append(COST_STRING_USER_PIMPER_REP).append(tmpchars);
                ps.str_Reputation = tmpstr;
                tmpstr.clear();

                sprintf(tmpchars, "%i", ps.Costs_Profession/GOLD);
                tmpstr.append(COST_STRING_USER_PIMPER_PROF).append(tmpchars);
                ps.str_Profession = tmpstr;
                tmpstr.clear();

                sprintf(tmpchars, "%i", ps.Costs_AllRecipes/GOLD);
                tmpstr.append(COST_STRING_USER_PIMPER_RECIPES).append(tmpchars);
                ps.str_AllRecipes = tmpstr;
                tmpstr.clear();

                sprintf(tmpchars, "%i", ps.Costs_MaxSkill/GOLD);
                tmpstr.append(COST_STRING_USER_PIMPER_SKILL).append(tmpchars);
                ps.str_MaxSkill = tmpstr;
                tmpstr.clear();
            }
            else
            {
                sprintf(tmpchars, "%i", ps.Costs_AllMiniPets);
                tmpstr.append(COST_STRING_USER_PIMPER_PETS).append(tmpchars);
                ps.str_AllMiniPets = tmpstr;
                tmpstr.clear();

                sprintf(tmpchars, "%i", ps.Costs_Reputation);
                tmpstr.append(COST_STRING_USER_PIMPER_REP).append(tmpchars);
                ps.str_Reputation = tmpstr;
                tmpstr.clear();

                sprintf(tmpchars, "%i", ps.Costs_Profession);
                tmpstr.append(COST_STRING_USER_PIMPER_PROF).append(tmpchars);
                ps.str_Profession = tmpstr;
                tmpstr.clear();

                sprintf(tmpchars, "%i", ps.Costs_AllRecipes);
                tmpstr.append(COST_STRING_USER_PIMPER_RECIPES).append(tmpchars);
                ps.str_AllRecipes = tmpstr;
                tmpstr.clear();

                sprintf(tmpchars, "%i", ps.Costs_MaxSkill);
                tmpstr.append(COST_STRING_USER_PIMPER_SKILL).append(tmpchars);
                ps.str_MaxSkill = tmpstr;
                tmpstr.clear();
            }
            ps.str_bottom.append("Alle Preise sind in ");

            switch(ps.Cost_Type)
            {
                case 0: ps.str_bottom.append("Gold."); break;
                case 1: ps.str_bottom.append("Ehre."); break;
                case 2: ps.str_bottom.append("Arenapunkten."); break;
                case 3:
                    if (item)
                        ps.str_bottom.append(ps.str_Item).append(".");
                    else
                        ps.str_bottom.append("ITEM NOT FOUND.");
                    break;
            }
            free(tmpchars);
        }

        bool HasEnough(Player* pl, int32 amount)
        {
            if (!pl || !pl->IsInWorld())
                return false;

            switch(ps.Cost_Type)
            {
                case 0:
                    if (pl->GetMoney() < static_cast<uint32>(amount))
                        pl->GetSession()->SendNotification(PIMPER_NOT_ENOUGH, "Gold");
                    else
                        return true;
                    break;
                case 1:
                    if (pl->GetHonorPoints() < static_cast<uint32>(amount))
                        pl->GetSession()->SendNotification(PIMPER_NOT_ENOUGH, "Ehre");
                    else
                        return true;
                    break;
                case 2:
                    if (pl->GetArenaPoints() < static_cast<uint32>(amount))
                        pl->GetSession()->SendNotification(PIMPER_NOT_ENOUGH, "Arenapunkte");
                    else
                        return true;
                    break;
                case 3:
                    if (pl->GetItemCount(ps.Costs_Item) < static_cast<uint32>(amount))
                        if (item)
                            pl->GetSession()->SendNotification(PIMPER_NOT_ENOUGH, item->Name1);
                    else
                        return true;
                    break;
            }
            return false;
        }

        bool SubstructCurrency(Player* pl, int32 amount)
        {
            if (!pl || !pl->IsInWorld())
                return false;

            switch(ps.Cost_Type)
            {
                case 0:
                    if (HasEnough(pl, amount))
                        pl->ModifyMoney(-amount);
                    else
                        return false;
                    break;
                case 1:
                    if (HasEnough(pl, amount))
                        pl->ModifyHonorPoints(-amount);
                    else
                        return false;
                    break;
                case 2:
                    if (HasEnough(pl, amount))
                        pl->ModifyArenaPoints(-amount);
                    else
                        return false;
                    break;
                case 3:
                    if (HasEnough(pl, amount))
                        pl->DestroyItemCount(ps.Costs_Item, amount, true);
                    else
                        return false;
                    break;
            }
            return true;
        }

        bool CanGetPresent(Player* pl, uint32 item, uint32 spell)
        {
            if (!pl || !pl->IsInWorld())
                return false;

            return (!pl->HasItemCount(item, 1, true) && !pl->HasSpell(spell));
        }

        std::string GetPlaytimeString(uint32 total_playtime_secs)
        {
            std::ostringstream ss;

            ss << ("Deine Spielzeit: ");

            if (GetPlaytimeDays(total_playtime_secs) > 0)
                ss << uint32(GetPlaytimeDays(total_playtime_secs)) << (" Tage(e) ");
            if (GetPlaytimeHours(total_playtime_secs) > 0)
                ss << uint32(GetPlaytimeHours(total_playtime_secs)) << (" Stunde(n)");

            return ss.str();
        }

        uint32 GetPlaytimeHours(uint32 total_playtime_secs) { return total_playtime_secs%DAY/HOUR; }
        uint32 GetPlaytimeDays(uint32 total_playtime_secs) { return total_playtime_secs/DAY; }
        uint32 GetPlaytimeWeeks(uint32 total_playtime_secs) { return total_playtime_secs/WEEK; }
        uint32 GetPlaytimeMonth(uint32 total_playtime_secs) { return total_playtime_secs/MONTH; }
    };

    bool OnGossipHello(Player *pPlayer, Creature *pCreature)
    {
        if (!pPlayer || !pPlayer->IsInWorld())
            return false;

        npc_uwom_user_pimperAI *ai = CAST_AI(npc_uwom_user_pimperAI, pCreature->AI());

        if (!ai)
            return false;

        uint32 total_playtime_secs = pPlayer->GetTotalPlayedTime(); // Sekunden!

        if (ai->ps.PresentsAllowed && ai->GetPlaytimeMonth(total_playtime_secs) >= 1) // Ab 1 Monat Spielzeit
        {
            if (ai->CanGetPresent(pPlayer, 49665, 69541)) // Pandarenmönch
                ai->addItem(pPlayer, 49665, 1, true, false, true);
            if (ai->CanGetPresent(pPlayer, 45693, 63796)) // Mimirons Kopf
                ai->addItem(pPlayer, 45693, 1, true, false, true);
        }

        if (ai->ps.PresentsAllowed && ai->GetPlaytimeMonth(total_playtime_secs) >= 2) // Ab 2 Monate Spielzeit
        {
            if (ai->CanGetPresent(pPlayer, 49343, 68810)) // Spektraltigerjunges
                ai->addItem(pPlayer, 49343, 1, true, false, true);
            if (ai->CanGetPresent(pPlayer, 45802, 63963)) // Zügel des rostigen Protodrachen
                ai->addItem(pPlayer, 45802, 1, true, false, true);
        }

        if (ai->ps.PresentsAllowed && ai->GetPlaytimeMonth(total_playtime_secs) >= 3) // Ab 3 Monate Spielzeit
        {
            if (ai->CanGetPresent(pPlayer, 49283, 42776)) // Zügel des Spektraltigers
                ai->addItem(pPlayer, 49283, 1, true, false, true);
            if (ai->CanGetPresent(pPlayer, 45801, 63956)) // Zügel des eisenbeschlagenen Protodrachen
                ai->addItem(pPlayer, 45801, 1, true, false, true);
        }

        if (pCreature->isQuestGiver())  pPlayer->PrepareQuestMenu(pCreature->GetGUID());
        if (pCreature->isTrainer())     pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_TEXT_TRAIN,          GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRAIN);
        if (pCreature->isVendor())      pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR,    GOSSIP_TEXT_BROWSE_GOODS,   GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);
        if (pCreature->isAuctioner())   pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, GOSSIP_TEXT_AUCTIONHOUSE,   GOSSIP_SENDER_MAIN, GOSSIP_ACTION_AUCTION);

        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR,    GOSSIP_USER_PIMPER_01,    GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR,    GOSSIP_USER_PIMPER_07,    GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);

        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, ai->GetPlaytimeString(total_playtime_secs), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 8);

        pPlayer->SEND_GOSSIP_MENU(1100000, pCreature->GetGUID());

        switch(urand(0,1))
        {
            case 0: pCreature->CastSpell(pPlayer, SPELL_TURKEY_FEATHERS, true); break; // Truthahnfedern
            case 1: pPlayer->SetDisplayId(15369); break; // Murloc Baby
        }

        return true;
    }

    void SendDefaultMenu(Player* pPlayer, Creature* pCreature, uint32 uiAction)
    {
        npc_uwom_user_pimperAI *ai = CAST_AI(npc_uwom_user_pimperAI, pCreature->AI());

        if (!ai)
            return;

        switch (uiAction)
        {   // Standard-Aktionen
            case GOSSIP_ACTION_TRAIN:
                pPlayer->GetSession()->SendTrainerList(pCreature->GetGUID());
                break;
            case GOSSIP_ACTION_TRADE:
                pPlayer->GetSession()->SendListInventory(pCreature->GetGUID());
                break;
            case GOSSIP_ACTION_AUCTION:
                pCreature->setFaction(pPlayer->getFaction());
                pPlayer->GetSession()->SendAuctionHello(pCreature->GetGUID(), pCreature);
                pCreature->setFaction(35);
                break;

            // Unterm Ladentisch
            case GOSSIP_ACTION_INFO_DEF + 1:
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_USER_PIMPER_02,    GOSSIP_SENDER_MAIN,             GOSSIP_ACTION_INFO_DEF + 2);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_USER_PIMPER_03,    GOSSIP_SENDER_MAIN,             GOSSIP_ACTION_INFO_DEF + 3);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR,    GOSSIP_USER_PIMPER_04,    GOSSIP_SENDER_SEC_BANK,         GOSSIP_ACTION_INFO_DEF + 4);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_USER_PIMPER_05,    GOSSIP_SENDER_SEC_PROFTRAIN,    GOSSIP_ACTION_INFO_DEF + 5);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_USER_PIMPER_06,    GOSSIP_SENDER_MAIN,             GOSSIP_ACTION_INFO_DEF + 6);
                pPlayer->SEND_GOSSIP_MENU(1100001, pCreature->GetGUID());
                break;

            // Ein paar Jobs
            case GOSSIP_ACTION_INFO_DEF + 2:
                if (pPlayer->GetFreePrimaryProfessionPoints() > 0)
                {
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_TEXT_ALCHEMY,        GOSSIP_SENDER_SEC_PROFTRAIN,    GOSSIP_ACTION_INFO_DEF + 11);
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_TEXT_BLACKSMITHING,  GOSSIP_SENDER_SEC_PROFTRAIN,    GOSSIP_ACTION_INFO_DEF + 12);
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_TEXT_COOKING,        GOSSIP_SENDER_SEC_PROFTRAIN,    GOSSIP_ACTION_INFO_DEF + 13);
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_TEXT_ENCHANTING,     GOSSIP_SENDER_SEC_PROFTRAIN,    GOSSIP_ACTION_INFO_DEF + 14);
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_TEXT_ENGINEERING,    GOSSIP_SENDER_SEC_PROFTRAIN,    GOSSIP_ACTION_INFO_DEF + 15);
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_TEXT_FIRSTAID,       GOSSIP_SENDER_SEC_PROFTRAIN,    GOSSIP_ACTION_INFO_DEF + 16);
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_TEXT_HERBALISM,      GOSSIP_SENDER_SEC_PROFTRAIN,    GOSSIP_ACTION_INFO_DEF + 17);
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_TEXT_INSCRIPTION,    GOSSIP_SENDER_SEC_PROFTRAIN,    GOSSIP_ACTION_INFO_DEF + 18);
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_TEXT_JEWELCRAFTING,  GOSSIP_SENDER_SEC_PROFTRAIN,    GOSSIP_ACTION_INFO_DEF + 19);
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_TEXT_LEATHERWORKING, GOSSIP_SENDER_SEC_PROFTRAIN,    GOSSIP_ACTION_INFO_DEF + 20);
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_TEXT_TAILORING,      GOSSIP_SENDER_SEC_PROFTRAIN,    GOSSIP_ACTION_INFO_DEF + 21);
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_TEXT_MINING,         GOSSIP_SENDER_SEC_PROFTRAIN,    GOSSIP_ACTION_INFO_DEF + 22);
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_TEXT_FISHING,        GOSSIP_SENDER_SEC_PROFTRAIN,    GOSSIP_ACTION_INFO_DEF + 23);
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_TEXT_SKINNING,       GOSSIP_SENDER_SEC_PROFTRAIN,    GOSSIP_ACTION_INFO_DEF + 24);

                    pPlayer->SEND_GOSSIP_MENU(4328, pCreature->GetGUID());
                }
                else
                {
                    pPlayer->GetSession()->SendNotification(PIMPER_PROF_LIMIT);
                    pPlayer->CLOSE_GOSSIP_MENU();
                }
                break;

            // Maxskill
            case GOSSIP_ACTION_INFO_DEF + 3:
                if (ai->SubstructCurrency(pPlayer, ai->ps.Costs_MaxSkill))
                    pPlayer->UpdateSkillsToMaxSkillsForLevel();
                pPlayer->CLOSE_GOSSIP_MENU();
                break;

            // Rezepte für Jobs
            case GOSSIP_ACTION_INFO_DEF + 6:
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_TEXT_ALCHEMY,        GOSSIP_SENDER_SEC_PROFTRAIN,    GOSSIP_ACTION_INFO_DEF + 30);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_TEXT_BLACKSMITHING,  GOSSIP_SENDER_SEC_PROFTRAIN,    GOSSIP_ACTION_INFO_DEF + 31);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_TEXT_COOKING,        GOSSIP_SENDER_SEC_PROFTRAIN,    GOSSIP_ACTION_INFO_DEF + 32);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_TEXT_ENCHANTING,     GOSSIP_SENDER_SEC_PROFTRAIN,    GOSSIP_ACTION_INFO_DEF + 33);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_TEXT_ENGINEERING,    GOSSIP_SENDER_SEC_PROFTRAIN,    GOSSIP_ACTION_INFO_DEF + 34);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_TEXT_INSCRIPTION,    GOSSIP_SENDER_SEC_PROFTRAIN,    GOSSIP_ACTION_INFO_DEF + 35);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_TEXT_JEWELCRAFTING,  GOSSIP_SENDER_SEC_PROFTRAIN,    GOSSIP_ACTION_INFO_DEF + 36);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_TEXT_LEATHERWORKING, GOSSIP_SENDER_SEC_PROFTRAIN,    GOSSIP_ACTION_INFO_DEF + 37);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,   GOSSIP_TEXT_TAILORING,      GOSSIP_SENDER_SEC_PROFTRAIN,    GOSSIP_ACTION_INFO_DEF + 38);

                pPlayer->SEND_GOSSIP_MENU(1100002, pCreature->GetGUID());
                break;

            // Preisliste
            case GOSSIP_ACTION_INFO_DEF + 7:
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, ai->ps.str_AllMiniPets,  GOSSIP_SENDER_INFO, GOSSIP_ACTION_INFO_DEF + 39);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, ai->ps.str_Reputation,   GOSSIP_SENDER_INFO, GOSSIP_ACTION_INFO_DEF + 40);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, ai->ps.str_Profession,   GOSSIP_SENDER_INFO, GOSSIP_ACTION_INFO_DEF + 41);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, ai->ps.str_AllRecipes,   GOSSIP_SENDER_INFO, GOSSIP_ACTION_INFO_DEF + 42);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, ai->ps.str_MaxSkill,     GOSSIP_SENDER_INFO, GOSSIP_ACTION_INFO_DEF + 43);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "",                      GOSSIP_SENDER_INFO, GOSSIP_ACTION_INFO_DEF + 44);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, ai->ps.str_bottom,       GOSSIP_SENDER_INFO, GOSSIP_ACTION_INFO_DEF + 45);

                pPlayer->SEND_GOSSIP_MENU(1100003, pCreature->GetGUID());
                break;
        }
    }

    void SendActionMenu(Player* pPlayer, Creature* pCreature, uint32 uiAction)
    {
        npc_uwom_user_pimperAI *ai = CAST_AI(npc_uwom_user_pimperAI, pCreature->AI());

        if (!ai)
            return;

        switch(uiAction)
        {
            // Mini-Pets
            case GOSSIP_ACTION_INFO_DEF + 4:
                if (ai->SubstructCurrency(pPlayer, ai->ps.Costs_AllMiniPets))
                {
                    for (uint8 i=0; i<FirecallerPresentsCnt; ++i)
                        if (!pPlayer->HasSpell(FirecallerPresents[i][1]))
                            pPlayer->learnSpell(FirecallerPresents[i][1], false);
                }
                break;

            // Ruf
            case GOSSIP_ACTION_INFO_DEF + 5:
                if (ai->SubstructCurrency(pPlayer, ai->ps.Costs_Reputation))
                {
                    if (pPlayer->GetTeam() == ALLIANCE)
                    {
                        for (uint8 i=0; i<AllyFactionCnt; ++i)
                        {
                            FactionEntry const* fe = sFactionStore.LookupEntry(AllyFaction[i]);
                            pPlayer->GetReputationMgr().ModifyReputation(fe, ReputationMgr::Reputation_Cap);
                        }
                    }
                    else
                    {
                        for (uint8 i=0; i<HordeFactionCnt; ++i)
                        {
                            FactionEntry const* fe = sFactionStore.LookupEntry(HordeFaction[i]);
                            pPlayer->GetReputationMgr().ModifyReputation(fe, ReputationMgr::Reputation_Cap);
                        }
                    }
                    for (uint8 i=0; i<WorldFactionCnt; ++i)
                    {
                        FactionEntry const* fe = sFactionStore.LookupEntry(WorldFaction[i]);
                        pPlayer->GetReputationMgr().ModifyReputation(fe, ReputationMgr::Reputation_Cap);
                    }
                }
                break;

            // Preisliste
            case GOSSIP_ACTION_INFO_DEF + 39:
            case GOSSIP_ACTION_INFO_DEF + 40:
            case GOSSIP_ACTION_INFO_DEF + 41:
            case GOSSIP_ACTION_INFO_DEF + 42:
            case GOSSIP_ACTION_INFO_DEF + 43:
            case GOSSIP_ACTION_INFO_DEF + 44:
            case GOSSIP_ACTION_INFO_DEF + 45:
                break;
            // -----------------------------------------------------------------------------------
            // -------------------------------------- BERUFE -------------------------------------
            // -----------------------------------------------------------------------------------
            // Alchimie
            case GOSSIP_ACTION_INFO_DEF + 11:
                if (!pPlayer->HasSpell(SPELL_ALCHEMY_GRAND_MASTER) && ai->SubstructCurrency(pPlayer, ai->ps.Costs_Profession))
                {
                    pPlayer->learnSpellHighRank(SPELL_ALCHEMY_GRAND_MASTER);
                    pPlayer->SetSkill(SKILL_ALCHEMY, 1, pPlayer->GetPureMaxSkillValue(SKILL_ALCHEMY), pPlayer->GetPureMaxSkillValue(SKILL_ALCHEMY));
                }
                break;
            // Schmieden
            case GOSSIP_ACTION_INFO_DEF + 12:
                if (!pPlayer->HasSpell(SPELL_BLACKSMITHING_GRAND_MASTER) && ai->SubstructCurrency(pPlayer, ai->ps.Costs_Profession))
                {
                    pPlayer->learnSpellHighRank(SPELL_BLACKSMITHING_GRAND_MASTER);
                    pPlayer->SetSkill(SKILL_BLACKSMITHING, 1, pPlayer->GetPureMaxSkillValue(SKILL_BLACKSMITHING), pPlayer->GetPureMaxSkillValue(SKILL_BLACKSMITHING));
                }
                break;
            // Kochen
            case GOSSIP_ACTION_INFO_DEF + 13:
                if (!pPlayer->HasSpell(SPELL_COOKING_GRAND_MASTER) && ai->SubstructCurrency(pPlayer, ai->ps.Costs_Profession))
                {
                    pPlayer->learnSpellHighRank(SPELL_COOKING_GRAND_MASTER);
                    pPlayer->SetSkill(SKILL_COOKING, 1, pPlayer->GetPureMaxSkillValue(SKILL_COOKING), pPlayer->GetPureMaxSkillValue(SKILL_COOKING));
                }
                break;
            // Verzaubern
            case GOSSIP_ACTION_INFO_DEF + 14:
                if (!pPlayer->HasSpell(SPELL_ENCHANTING_GRAND_MASTER) && ai->SubstructCurrency(pPlayer, ai->ps.Costs_Profession))
                {
                    pPlayer->learnSpellHighRank(SPELL_ENCHANTING_GRAND_MASTER);
                    pPlayer->SetSkill(SKILL_ENCHANTING, 1, pPlayer->GetPureMaxSkillValue(SKILL_ENCHANTING), pPlayer->GetPureMaxSkillValue(SKILL_ENCHANTING));
                }
                break;
            // Ingenieurwesen
            case GOSSIP_ACTION_INFO_DEF + 15:
                if (!pPlayer->HasSpell(SPELL_ENGINEERING_GRAND_MASTER) && ai->SubstructCurrency(pPlayer, ai->ps.Costs_Profession))
                {
                    pPlayer->learnSpellHighRank(SPELL_ENGINEERING_GRAND_MASTER);
                    pPlayer->SetSkill(SKILL_ENGINERING, 1, pPlayer->GetPureMaxSkillValue(SKILL_ENGINERING), pPlayer->GetPureMaxSkillValue(SKILL_ENGINERING));
                }
                break;
            // Erste Hilfe
            case GOSSIP_ACTION_INFO_DEF + 16:
                if (!pPlayer->HasSpell(SPELL_FIRAT_AID_GRAND_MASTER) && ai->SubstructCurrency(pPlayer, ai->ps.Costs_Profession))
                {
                    pPlayer->learnSpellHighRank(SPELL_FIRAT_AID_GRAND_MASTER);
                    pPlayer->SetSkill(SKILL_FIRST_AID, 1, pPlayer->GetPureMaxSkillValue(SKILL_FIRST_AID), pPlayer->GetPureMaxSkillValue(SKILL_FIRST_AID));
                }
                break;
            // Kräuterkunde
            case GOSSIP_ACTION_INFO_DEF + 17:
                if (!pPlayer->HasSpell(SPELL_HERB_GATHERING_GRAND_MASTER) && ai->SubstructCurrency(pPlayer, ai->ps.Costs_Profession))
                {
                    pPlayer->learnSpellHighRank(SPELL_HERB_GATHERING_GRAND_MASTER);
                    pPlayer->SetSkill(SKILL_HERBALISM, 1, pPlayer->GetPureMaxSkillValue(SKILL_HERBALISM), pPlayer->GetPureMaxSkillValue(SKILL_HERBALISM));
                }
                break;
            // Inschriftenkunde
            case GOSSIP_ACTION_INFO_DEF + 18:
                if (!pPlayer->HasSpell(SPELL_INSCRIPTION_GRAND_MASTER) && ai->SubstructCurrency(pPlayer, ai->ps.Costs_Profession))
                {
                    pPlayer->learnSpellHighRank(SPELL_INSCRIPTION_GRAND_MASTER);
                    pPlayer->SetSkill(SKILL_INSCRIPTION, 1, pPlayer->GetPureMaxSkillValue(SKILL_INSCRIPTION), pPlayer->GetPureMaxSkillValue(SKILL_INSCRIPTION));
                }
                break;
            // Juwelenschleifen
            case GOSSIP_ACTION_INFO_DEF + 19:
                if (!pPlayer->HasSpell(SPELL_JEWELCRAFTING_GRAND_MASTER) && ai->SubstructCurrency(pPlayer, ai->ps.Costs_Profession))
                {
                    pPlayer->learnSpellHighRank(SPELL_JEWELCRAFTING_GRAND_MASTER);
                    pPlayer->SetSkill(SKILL_JEWELCRAFTING, 1, pPlayer->GetPureMaxSkillValue(SKILL_JEWELCRAFTING), pPlayer->GetPureMaxSkillValue(SKILL_JEWELCRAFTING));
                }
                break;
            // Lederverarbeitung
            case GOSSIP_ACTION_INFO_DEF + 20:
                if (!pPlayer->HasSpell(SPELL_LEATHERWORKING_GRAND_MASTER) && ai->SubstructCurrency(pPlayer, ai->ps.Costs_Profession))
                {
                    pPlayer->learnSpellHighRank(SPELL_LEATHERWORKING_GRAND_MASTER);
                    pPlayer->SetSkill(SKILL_LEATHERWORKING, 1, pPlayer->GetPureMaxSkillValue(SKILL_LEATHERWORKING), pPlayer->GetPureMaxSkillValue(SKILL_LEATHERWORKING));
                }
                break;
            // Schneidern
            case GOSSIP_ACTION_INFO_DEF + 21:
                if (!pPlayer->HasSpell(SPELL_TAILORING_GRAND_MASTER) && ai->SubstructCurrency(pPlayer, ai->ps.Costs_Profession))
                {
                    pPlayer->learnSpellHighRank(SPELL_TAILORING_GRAND_MASTER);
                    pPlayer->SetSkill(SKILL_TAILORING, 1, pPlayer->GetPureMaxSkillValue(SKILL_TAILORING), pPlayer->GetPureMaxSkillValue(SKILL_TAILORING));
                }
                break;
            // Bergbau
            case GOSSIP_ACTION_INFO_DEF + 22:
                if (!pPlayer->HasSpell(SPELL_MINING_GRAND_MASTER) && ai->SubstructCurrency(pPlayer, ai->ps.Costs_Profession))
                {
                    pPlayer->learnSpellHighRank(SPELL_MINING_GRAND_MASTER);
                    pPlayer->SetSkill(SKILL_MINING, 1, pPlayer->GetPureMaxSkillValue(SKILL_MINING), pPlayer->GetPureMaxSkillValue(SKILL_MINING));
                }
                break;
            // Angeln
            case GOSSIP_ACTION_INFO_DEF + 23:
                if (!pPlayer->HasSpell(SPELL_FISHING_GRAND_MASTER) && ai->SubstructCurrency(pPlayer, ai->ps.Costs_Profession))
                {
                    pPlayer->learnSpellHighRank(SPELL_FISHING_GRAND_MASTER);
                    pPlayer->SetSkill(SKILL_FISHING, 1, pPlayer->GetPureMaxSkillValue(SKILL_FISHING), pPlayer->GetPureMaxSkillValue(SKILL_FISHING));
                }
                break;
            // Kürschnern
            case GOSSIP_ACTION_INFO_DEF + 24:
                if (!pPlayer->HasSpell(SPELL_SKINNING_GRAND_MASTER) && ai->SubstructCurrency(pPlayer, ai->ps.Costs_Profession))
                {
                    pPlayer->learnSpellHighRank(SPELL_SKINNING_GRAND_MASTER);
                    pPlayer->SetSkill(SKILL_SKINNING, 1, pPlayer->GetPureMaxSkillValue(SKILL_SKINNING), pPlayer->GetPureMaxSkillValue(SKILL_SKINNING));
                }
                break;
            // -----------------------------------------------------------------------------------
            // --------------------------------- REZEPTE FÜR BERUFE ------------------------------
            // -----------------------------------------------------------------------------------
            // Alchimie
            case GOSSIP_ACTION_INFO_DEF + 30:
                if (pPlayer->HasSkill(SKILL_ALCHEMY) && pPlayer->GetSkillValue(SKILL_ALCHEMY) >= pPlayer->GetPureMaxSkillValue(SKILL_ALCHEMY) && ai->SubstructCurrency(pPlayer, ai->ps.Costs_AllRecipes))
                    LearnAllSkillRecipes(pPlayer, SKILL_ALCHEMY);
                else
                    pPlayer->GetSession()->SendNotification(PIMPER_PROF_MAX);
                break;
            // Schmieden
            case GOSSIP_ACTION_INFO_DEF + 31:
                if (pPlayer->HasSkill(SKILL_BLACKSMITHING) && pPlayer->GetSkillValue(SKILL_BLACKSMITHING) >= pPlayer->GetPureMaxSkillValue(SKILL_BLACKSMITHING) && ai->SubstructCurrency(pPlayer, ai->ps.Costs_AllRecipes))
                    LearnAllSkillRecipes(pPlayer, SKILL_BLACKSMITHING);
                else
                    pPlayer->GetSession()->SendNotification(PIMPER_PROF_MAX);
                break;
            // Kochen
            case GOSSIP_ACTION_INFO_DEF + 32:
                if (pPlayer->HasSkill(SKILL_COOKING) && pPlayer->GetSkillValue(SKILL_COOKING) >= pPlayer->GetPureMaxSkillValue(SKILL_COOKING) && ai->SubstructCurrency(pPlayer, ai->ps.Costs_AllRecipes))
                    LearnAllSkillRecipes(pPlayer, SKILL_COOKING);
                else
                    pPlayer->GetSession()->SendNotification(PIMPER_PROF_MAX);
                break;
            // Verzaubern
            case GOSSIP_ACTION_INFO_DEF + 33:
                if (pPlayer->HasSkill(SKILL_ENCHANTING) && pPlayer->GetSkillValue(SKILL_ENCHANTING) >= pPlayer->GetPureMaxSkillValue(SKILL_ENCHANTING) && ai->SubstructCurrency(pPlayer, ai->ps.Costs_AllRecipes))
                    LearnAllSkillRecipes(pPlayer, SKILL_ENCHANTING);
                else
                    pPlayer->GetSession()->SendNotification(PIMPER_PROF_MAX);
                break;
            // Ingenieurwesen
            case GOSSIP_ACTION_INFO_DEF + 34:
                if (pPlayer->HasSkill(SKILL_ENGINERING) && pPlayer->GetSkillValue(SKILL_ENGINERING) >= pPlayer->GetPureMaxSkillValue(SKILL_ENGINERING) && ai->SubstructCurrency(pPlayer, ai->ps.Costs_AllRecipes))
                    LearnAllSkillRecipes(pPlayer, SKILL_ENGINERING);
                else
                    pPlayer->GetSession()->SendNotification(PIMPER_PROF_MAX);
                break;
            // Inschriftenkunde
            case GOSSIP_ACTION_INFO_DEF + 35:
                if (pPlayer->HasSkill(SKILL_INSCRIPTION) && pPlayer->GetSkillValue(SKILL_INSCRIPTION) >= pPlayer->GetPureMaxSkillValue(SKILL_INSCRIPTION) && ai->SubstructCurrency(pPlayer, ai->ps.Costs_AllRecipes))
                    LearnAllSkillRecipes(pPlayer, SKILL_INSCRIPTION);
                else
                    pPlayer->GetSession()->SendNotification(PIMPER_PROF_MAX);
                break;
            // Juwelenschleifen
            case GOSSIP_ACTION_INFO_DEF + 36:
                if (pPlayer->HasSkill(SKILL_JEWELCRAFTING) && pPlayer->GetSkillValue(SKILL_JEWELCRAFTING) >= pPlayer->GetPureMaxSkillValue(SKILL_JEWELCRAFTING) && ai->SubstructCurrency(pPlayer, ai->ps.Costs_AllRecipes))
                    LearnAllSkillRecipes(pPlayer, SKILL_JEWELCRAFTING);
                else
                    pPlayer->GetSession()->SendNotification(PIMPER_PROF_MAX);
                break;
            // Lederverarbeitung
            case GOSSIP_ACTION_INFO_DEF + 37:
                if (pPlayer->HasSkill(SKILL_LEATHERWORKING) && pPlayer->GetSkillValue(SKILL_LEATHERWORKING) >= pPlayer->GetPureMaxSkillValue(SKILL_LEATHERWORKING) && ai->SubstructCurrency(pPlayer, ai->ps.Costs_AllRecipes))
                    LearnAllSkillRecipes(pPlayer, SKILL_LEATHERWORKING);
                else
                    pPlayer->GetSession()->SendNotification(PIMPER_PROF_MAX);
                break;
            // Schneidern
            case GOSSIP_ACTION_INFO_DEF + 38:
                if (pPlayer->HasSkill(SKILL_TAILORING) && pPlayer->GetSkillValue(SKILL_TAILORING) >= pPlayer->GetPureMaxSkillValue(SKILL_TAILORING) && ai->SubstructCurrency(pPlayer, ai->ps.Costs_AllRecipes))
                    LearnAllSkillRecipes(pPlayer, SKILL_TAILORING);
                else
                    pPlayer->GetSession()->SendNotification(PIMPER_PROF_MAX);
                break;
        }
        pPlayer->CLOSE_GOSSIP_MENU();
    }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();

        switch(uiSender)
        {
            case GOSSIP_SENDER_MAIN: SendDefaultMenu(pPlayer, pCreature, uiAction); break;
            case GOSSIP_SENDER_SEC_BANK:
            case GOSSIP_SENDER_SEC_PROFTRAIN: SendActionMenu(pPlayer, pCreature, uiAction); break;
        }
        return true;
    }

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_uwom_user_pimperAI(creature);
    }
};

// ------------------------------------------------------------------------------------------------------------
// Hati 60003
// ------------------------------------------------------------------------------------------------------------
enum HATI_ENUM
{
    SOUND_AGGRO             = 11176,
    SOUND_SLAY1             = 11177,
    SOUND_SLAY2             = 11178,
    SOUND_SLAY3             = 11183,

    SPELL_DURCHBOHREN       = 58666
};

class npc_hati : public CreatureScript
{
public:
    npc_hati() : CreatureScript("npc_hati") { }

    struct npc_hatiAI : public ScriptedAI
    {
        npc_hatiAI(Creature * c) : ScriptedAI(c) {}

        uint32 bohrentimer;

        void Reset()
        {
            bohrentimer = urand(5000,10000);
        }

        void KilledUnit(Unit * /*Victim*/)
        {
            switch(urand(0,2))
            {
                case 0: DoPlaySoundToSet(me, SOUND_SLAY1); break;
                case 1: DoPlaySoundToSet(me, SOUND_SLAY2); break;
                case 2: DoPlaySoundToSet(me, SOUND_SLAY3); break;
            }
        }

        void MoveInLineOfSight(Unit * who)
        {
            if (!who)
                return;

            Unit * pTarget = who;

            // Keine NPCs angreifen, die nicht zu einem Spieler gehören!
            if (who->GetTypeId() == TYPEID_UNIT && !who->GetOwner())
                return;

            if (pTarget->GetTypeId() == TYPEID_PLAYER)
                if (pTarget->ToPlayer()->GetSession()->GetSecurity() > SEC_VETERAN) // Nur Spieler angreifen, die keine GMs sind!
                    return;

            ScriptedAI::MoveInLineOfSight(pTarget);
        }

        void EnterCombat(Unit * /*who*/)
        {
            DoPlaySoundToSet(me, SOUND_AGGRO);
        }

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            if (bohrentimer <= diff)
            {
                DoCast(me->getVictim(), SPELL_DURCHBOHREN);
                bohrentimer = urand(5000,10000);
            }
            else
                bohrentimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI * GetAI(Creature * creature) const
    {
        return new npc_hatiAI(creature);
    }
};

/*########
# npc_air_force_bots
#########*/

enum SpawnType
{
    SPAWNTYPE_TRIPWIRE_ROOFTOP,                             // no warning, summon Creature at smaller range
    SPAWNTYPE_ALARMBOT,                                     // cast guards mark and summon npc - if player shows up with that buff duration < 5 seconds attack
};

struct SpawnAssociation
{
    uint32 m_uiThisCreatureEntry;
    uint32 m_uiSpawnedCreatureEntry;
    SpawnType m_SpawnType;
};

enum eEnums
{
    SPELL_GUARDS_MARK               = 38067,
    AURA_DURATION_TIME_LEFT         = 5000
};

const float RANGE_TRIPWIRE          = 15.0f;
const float RANGE_GUARDS_MARK       = 50.0f;

SpawnAssociation m_aSpawnAssociations[] =
{
    {2614,  15241, SPAWNTYPE_ALARMBOT},                     //Air Force Alarm Bot (Alliance)
    {2615,  15242, SPAWNTYPE_ALARMBOT},                     //Air Force Alarm Bot (Horde)
    {21974, 21976, SPAWNTYPE_ALARMBOT},                     //Air Force Alarm Bot (Area 52)
    {21993, 15242, SPAWNTYPE_ALARMBOT},                     //Air Force Guard Post (Horde - Bat Rider)
    {21996, 15241, SPAWNTYPE_ALARMBOT},                     //Air Force Guard Post (Alliance - Gryphon)
    {21997, 21976, SPAWNTYPE_ALARMBOT},                     //Air Force Guard Post (Goblin - Area 52 - Zeppelin)
    {21999, 15241, SPAWNTYPE_TRIPWIRE_ROOFTOP},             //Air Force Trip Wire - Rooftop (Alliance)
    {22001, 15242, SPAWNTYPE_TRIPWIRE_ROOFTOP},             //Air Force Trip Wire - Rooftop (Horde)
    {22002, 15242, SPAWNTYPE_TRIPWIRE_ROOFTOP},             //Air Force Trip Wire - Ground (Horde)
    {22003, 15241, SPAWNTYPE_TRIPWIRE_ROOFTOP},             //Air Force Trip Wire - Ground (Alliance)
    {22063, 21976, SPAWNTYPE_TRIPWIRE_ROOFTOP},             //Air Force Trip Wire - Rooftop (Goblin - Area 52)
    {22065, 22064, SPAWNTYPE_ALARMBOT},                     //Air Force Guard Post (Ethereal - Stormspire)
    {22066, 22067, SPAWNTYPE_ALARMBOT},                     //Air Force Guard Post (Scryer - Dragonhawk)
    {22068, 22064, SPAWNTYPE_TRIPWIRE_ROOFTOP},             //Air Force Trip Wire - Rooftop (Ethereal - Stormspire)
    {22069, 22064, SPAWNTYPE_ALARMBOT},                     //Air Force Alarm Bot (Stormspire)
    {22070, 22067, SPAWNTYPE_TRIPWIRE_ROOFTOP},             //Air Force Trip Wire - Rooftop (Scryer)
    {22071, 22067, SPAWNTYPE_ALARMBOT},                     //Air Force Alarm Bot (Scryer)
    {22078, 22077, SPAWNTYPE_ALARMBOT},                     //Air Force Alarm Bot (Aldor)
    {22079, 22077, SPAWNTYPE_ALARMBOT},                     //Air Force Guard Post (Aldor - Gryphon)
    {22080, 22077, SPAWNTYPE_TRIPWIRE_ROOFTOP},             //Air Force Trip Wire - Rooftop (Aldor)
    {22086, 22085, SPAWNTYPE_ALARMBOT},                     //Air Force Alarm Bot (Sporeggar)
    {22087, 22085, SPAWNTYPE_ALARMBOT},                     //Air Force Guard Post (Sporeggar - Spore Bat)
    {22088, 22085, SPAWNTYPE_TRIPWIRE_ROOFTOP},             //Air Force Trip Wire - Rooftop (Sporeggar)
    {22090, 22089, SPAWNTYPE_ALARMBOT},                     //Air Force Guard Post (Toshley's Station - Flying Machine)
    {22124, 22122, SPAWNTYPE_ALARMBOT},                     //Air Force Alarm Bot (Cenarion)
    {22125, 22122, SPAWNTYPE_ALARMBOT},                     //Air Force Guard Post (Cenarion - Stormcrow)
    {22126, 22122, SPAWNTYPE_ALARMBOT}                      //Air Force Trip Wire - Rooftop (Cenarion Expedition)
};

class npc_air_force_bots : public CreatureScript
{
public:
    npc_air_force_bots() : CreatureScript("npc_air_force_bots") { }

    struct npc_air_force_botsAI : public ScriptedAI
    {
        npc_air_force_botsAI(Creature* creature) : ScriptedAI(creature)
        {
            m_pSpawnAssoc = NULL;
            m_uiSpawnedGUID = 0;

            // find the correct spawnhandling
            static uint32 uiEntryCount = sizeof(m_aSpawnAssociations)/sizeof(SpawnAssociation);

            for (uint8 i=0; i<uiEntryCount; ++i)
            {
                if (m_aSpawnAssociations[i].m_uiThisCreatureEntry == creature->GetEntry())
                {
                    m_pSpawnAssoc = &m_aSpawnAssociations[i];
                    break;
                }
            }

            if (!m_pSpawnAssoc)
                sLog->outErrorDb("TCSR: Creature template entry %u has ScriptName npc_air_force_bots, but it's not handled by that script", creature->GetEntry());
            else
            {
                CreatureTemplate const* spawnedTemplate = sObjectMgr->GetCreatureTemplate(m_pSpawnAssoc->m_uiSpawnedCreatureEntry);

                if (!spawnedTemplate)
                {
                    m_pSpawnAssoc = NULL;
                    sLog->outErrorDb("TCSR: Creature template entry %u does not exist in DB, which is required by npc_air_force_bots", m_pSpawnAssoc->m_uiSpawnedCreatureEntry);
                    return;
                }
            }
        }

        SpawnAssociation* m_pSpawnAssoc;
        uint64 m_uiSpawnedGUID;

        void Reset() {}

        Creature* SummonGuard()
        {
            Creature* summoned = me->SummonCreature(m_pSpawnAssoc->m_uiSpawnedCreatureEntry, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 300000);

            if (summoned)
                m_uiSpawnedGUID = summoned->GetGUID();
            else
            {
                sLog->outErrorDb("TCSR: npc_air_force_bots: wasn't able to spawn Creature %u", m_pSpawnAssoc->m_uiSpawnedCreatureEntry);
                m_pSpawnAssoc = NULL;
            }

            return summoned;
        }

        Creature* GetSummonedGuard()
        {
            Creature* creature = Unit::GetCreature(*me, m_uiSpawnedGUID);

            if (creature && creature->isAlive())
                return creature;

            return NULL;
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (!m_pSpawnAssoc)
                return;

            if (who->isTargetableForAttack() && me->IsHostileTo(who))
            {
                Player* playerTarget = who->GetTypeId() == TYPEID_PLAYER ? CAST_PLR(who) : NULL;

                // airforce guards only spawn for players
                if (!playerTarget)
                    return;

                Creature* pLastSpawnedGuard = m_uiSpawnedGUID == 0 ? NULL : GetSummonedGuard();

                // prevent calling Unit::GetUnit at next MoveInLineOfSight call - speedup
                if (!pLastSpawnedGuard)
                    m_uiSpawnedGUID = 0;

                switch(m_pSpawnAssoc->m_SpawnType)
                {
                    case SPAWNTYPE_ALARMBOT:
                    {
                        if (!who->IsWithinDistInMap(me, RANGE_GUARDS_MARK))
                            return;

                        Aura* pMarkAura = who->GetAura(SPELL_GUARDS_MARK);
                        if (pMarkAura)
                        {
                            // the target wasn't able to move out of our range within 25 seconds
                            if (!pLastSpawnedGuard)
                            {
                                pLastSpawnedGuard = SummonGuard();

                                if (!pLastSpawnedGuard)
                                    return;
                            }

                            if (pMarkAura->GetDuration() < AURA_DURATION_TIME_LEFT)
                            {
                                if (!pLastSpawnedGuard->getVictim())
                                    pLastSpawnedGuard->AI()->AttackStart(who);
                            }
                        }
                        else
                        {
                            if (!pLastSpawnedGuard)
                                pLastSpawnedGuard = SummonGuard();

                            if (!pLastSpawnedGuard)
                                return;

                            pLastSpawnedGuard->CastSpell(who, SPELL_GUARDS_MARK, true);
                        }
                        break;
                    }
                    case SPAWNTYPE_TRIPWIRE_ROOFTOP:
                    {
                        if (!who->IsWithinDistInMap(me, RANGE_TRIPWIRE))
                            return;

                        if (!pLastSpawnedGuard)
                            pLastSpawnedGuard = SummonGuard();

                        if (!pLastSpawnedGuard)
                            return;

                        // ROOFTOP only triggers if the player is on the ground
                        if (!playerTarget->IsFlying())
                        {
                            if (!pLastSpawnedGuard->getVictim())
                                pLastSpawnedGuard->AI()->AttackStart(who);
                        }
                        break;
                    }
                }
            }
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_air_force_botsAI(creature);
    }
};

/*######
## npc_lunaclaw_spirit
######*/

enum
{
    QUEST_BODY_HEART_A      = 6001,
    QUEST_BODY_HEART_H      = 6002,

    TEXT_ID_DEFAULT         = 4714,
    TEXT_ID_PROGRESS        = 4715
};

#define GOSSIP_ITEM_GRANT   "You have thought well, spirit. I ask you to grant me the strength of your body and the strength of your heart."

class npc_lunaclaw_spirit : public CreatureScript
{
public:
    npc_lunaclaw_spirit() : CreatureScript("npc_lunaclaw_spirit") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (player->GetQuestStatus(QUEST_BODY_HEART_A) == QUEST_STATUS_INCOMPLETE || player->GetQuestStatus(QUEST_BODY_HEART_H) == QUEST_STATUS_INCOMPLETE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_GRANT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        player->SEND_GOSSIP_MENU(TEXT_ID_DEFAULT, creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();
        if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
        {
            player->SEND_GOSSIP_MENU(TEXT_ID_PROGRESS, creature->GetGUID());
            player->AreaExploredOrEventHappens(player->GetTeam() == ALLIANCE ? QUEST_BODY_HEART_A : QUEST_BODY_HEART_H);
        }
        return true;
    }
};

/*########
# npc_chicken_cluck
#########*/

#define EMOTE_HELLO         -1070004
#define EMOTE_CLUCK_TEXT    -1070006

#define QUEST_CLUCK         3861
#define FACTION_FRIENDLY    35
#define FACTION_CHICKEN     31

class npc_chicken_cluck : public CreatureScript
{
public:
    npc_chicken_cluck() : CreatureScript("npc_chicken_cluck") { }

    struct npc_chicken_cluckAI : public ScriptedAI
    {
        npc_chicken_cluckAI(Creature *c) : ScriptedAI(c) {}

        uint32 ResetFlagTimer;

        void Reset()
        {
            ResetFlagTimer = 120000;
            me->setFaction(FACTION_CHICKEN);
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
        }

        void EnterCombat(Unit* /*who*/) {}

        void UpdateAI(const uint32 diff)
        {
            // Reset flags after a certain time has passed so that the next player has to start the 'event' again
            if (me->HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER))
            {
                if (ResetFlagTimer <= diff)
                {
                    EnterEvadeMode();
                    return;
                } else ResetFlagTimer -= diff;
            }

            if (UpdateVictim())
                DoMeleeAttackIfReady();
        }

        void ReceiveEmote(Player* player, uint32 emote)
        {
            switch(emote)
            {
                case TEXT_EMOTE_CHICKEN:
                    if (player->GetQuestStatus(QUEST_CLUCK) == QUEST_STATUS_NONE && rand()%30 == 1)
                    {
                        me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                        me->setFaction(FACTION_FRIENDLY);
                        DoScriptText(EMOTE_HELLO, me);
                    }
                    break;
                case TEXT_EMOTE_CHEER:
                    if (player->GetQuestStatus(QUEST_CLUCK) == QUEST_STATUS_COMPLETE)
                    {
                        me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                        me->setFaction(FACTION_FRIENDLY);
                        DoScriptText(EMOTE_CLUCK_TEXT, me);
                    }
                    break;
            }
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_chicken_cluckAI(creature);
    }

    bool OnQuestAccept(Player* /*player*/, Creature* creature, const Quest *_Quest)
    {
        if (_Quest->GetQuestId() == QUEST_CLUCK)
            CAST_AI(npc_chicken_cluck::npc_chicken_cluckAI, creature->AI())->Reset();

        return true;
    }

    bool OnQuestComplete(Player* /*player*/, Creature* creature, const Quest *_Quest)
    {
        if (_Quest->GetQuestId() == QUEST_CLUCK)
            CAST_AI(npc_chicken_cluck::npc_chicken_cluckAI, creature->AI())->Reset();

        return true;
    }
};

/*######
## npc_dancing_flames
######*/

#define SPELL_BRAZIER       45423
#define SPELL_SEDUCTION     47057
#define SPELL_FIERY_AURA    45427

class npc_dancing_flames : public CreatureScript
{
public:
    npc_dancing_flames() : CreatureScript("npc_dancing_flames") { }

    struct npc_dancing_flamesAI : public ScriptedAI
    {
        npc_dancing_flamesAI(Creature *c) : ScriptedAI(c) {}

        bool active;
        uint32 can_iteract;

        void Reset()
        {
            active = true;
            can_iteract = 3500;
            DoCast(me, SPELL_BRAZIER, true);
            DoCast(me, SPELL_FIERY_AURA, false);
            float x, y, z;
            me->GetPosition(x, y, z);
            me->Relocate(x, y, z + 0.94f);
            me->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
            me->HandleEmoteCommand(EMOTE_ONESHOT_DANCE);
            WorldPacket data;                       //send update position to client
            me->BuildHeartBeatMsg(&data);
            me->SendMessageToSet(&data, true);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!active)
            {
                if (can_iteract <= diff)
                {
                    active = true;
                    can_iteract = 3500;
                    me->HandleEmoteCommand(EMOTE_ONESHOT_DANCE);
                } else can_iteract -= diff;
            }
        }

        void EnterCombat(Unit* /*who*/){}

        void ReceiveEmote(Player* player, uint32 emote)
        {
            if (me->IsWithinLOS(player->GetPositionX(), player->GetPositionY(), player->GetPositionZ()) && me->IsWithinDistInMap(player, 30.0f))
            {
                me->SetInFront(player);
                active = false;

                WorldPacket data;
                me->BuildHeartBeatMsg(&data);
                me->SendMessageToSet(&data, true);
                switch(emote)
                {
                    case TEXT_EMOTE_KISS:    me->HandleEmoteCommand(EMOTE_ONESHOT_SHY); break;
                    case TEXT_EMOTE_WAVE:    me->HandleEmoteCommand(EMOTE_ONESHOT_WAVE); break;
                    case TEXT_EMOTE_BOW:     me->HandleEmoteCommand(EMOTE_ONESHOT_BOW); break;
                    case TEXT_EMOTE_JOKE:    me->HandleEmoteCommand(EMOTE_ONESHOT_LAUGH); break;
                    case TEXT_EMOTE_DANCE:
                    {
                        if (!player->HasAura(SPELL_SEDUCTION))
                            DoCast(player, SPELL_SEDUCTION, true);
                    }
                    break;
                }
            }
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_dancing_flamesAI(creature);
    }
};

/*######
## Triage quest
######*/

//signed for 9623
#define SAY_DOC1    -1000201
#define SAY_DOC2    -1000202
#define SAY_DOC3    -1000203

#define DOCTOR_ALLIANCE     12939
#define DOCTOR_HORDE        12920
#define ALLIANCE_COORDS     7
#define HORDE_COORDS        6

struct Location
{
    float x, y, z, o;
};

static Location AllianceCoords[]=
{
    {-3757.38f, -4533.05f, 14.16f, 3.62f},                      // Top-far-right bunk as seen from entrance
    {-3754.36f, -4539.13f, 14.16f, 5.13f},                      // Top-far-left bunk
    {-3749.54f, -4540.25f, 14.28f, 3.34f},                      // Far-right bunk
    {-3742.10f, -4536.85f, 14.28f, 3.64f},                      // Right bunk near entrance
    {-3755.89f, -4529.07f, 14.05f, 0.57f},                      // Far-left bunk
    {-3749.51f, -4527.08f, 14.07f, 5.26f},                      // Mid-left bunk
    {-3746.37f, -4525.35f, 14.16f, 5.22f},                      // Left bunk near entrance
};

//alliance run to where
#define A_RUNTOX -3742.96f
#define A_RUNTOY -4531.52f
#define A_RUNTOZ 11.91f

static Location HordeCoords[]=
{
    {-1013.75f, -3492.59f, 62.62f, 4.34f},                      // Left, Behind
    {-1017.72f, -3490.92f, 62.62f, 4.34f},                      // Right, Behind
    {-1015.77f, -3497.15f, 62.82f, 4.34f},                      // Left, Mid
    {-1019.51f, -3495.49f, 62.82f, 4.34f},                      // Right, Mid
    {-1017.25f, -3500.85f, 62.98f, 4.34f},                      // Left, front
    {-1020.95f, -3499.21f, 62.98f, 4.34f}                       // Right, Front
};

//horde run to where
#define H_RUNTOX -1016.44f
#define H_RUNTOY -3508.48f
#define H_RUNTOZ 62.96f

const uint32 AllianceSoldierId[3] =
{
    12938,                                                  // 12938 Injured Alliance Soldier
    12936,                                                  // 12936 Badly injured Alliance Soldier
    12937                                                   // 12937 Critically injured Alliance Soldier
};

const uint32 HordeSoldierId[3] =
{
    12923,                                                  //12923 Injured Soldier
    12924,                                                  //12924 Badly injured Soldier
    12925                                                   //12925 Critically injured Soldier
};

/*######
## npc_doctor (handles both Gustaf Vanhowzen and Gregory Victor)
######*/
class npc_doctor : public CreatureScript
{
public:
    npc_doctor() : CreatureScript("npc_doctor") {}

    struct npc_doctorAI : public ScriptedAI
    {
        npc_doctorAI(Creature *c) : ScriptedAI(c) {}

        uint64 PlayerGUID;

        uint32 SummonPatient_Timer;
        uint32 SummonPatientCount;
        uint32 PatientDiedCount;
        uint32 PatientSavedCount;

        bool Event;

        std::list<uint64> Patients;
        std::vector<Location*> Coordinates;

        void Reset()
        {
            PlayerGUID = 0;

            SummonPatient_Timer = 10000;
            SummonPatientCount = 0;
            PatientDiedCount = 0;
            PatientSavedCount = 0;

            Patients.clear();
            Coordinates.clear();

            Event = false;

            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        }

        void BeginEvent(Player* player)
        {
            PlayerGUID = player->GetGUID();

            SummonPatient_Timer = 10000;
            SummonPatientCount = 0;
            PatientDiedCount = 0;
            PatientSavedCount = 0;

            switch(me->GetEntry())
            {
                case DOCTOR_ALLIANCE:
                    for (uint8 i = 0; i < ALLIANCE_COORDS; ++i)
                        Coordinates.push_back(&AllianceCoords[i]);
                    break;
                case DOCTOR_HORDE:
                    for (uint8 i = 0; i < HORDE_COORDS; ++i)
                        Coordinates.push_back(&HordeCoords[i]);
                    break;
            }

            Event = true;
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        }

        void PatientDied(Location* Point)
        {
            Player* player = Unit::GetPlayer(*me, PlayerGUID);
            if (player && ((player->GetQuestStatus(6624) == QUEST_STATUS_INCOMPLETE) || (player->GetQuestStatus(6622) == QUEST_STATUS_INCOMPLETE)))
            {
                ++PatientDiedCount;

                if (PatientDiedCount > 5 && Event)
                {
                    if (player->GetQuestStatus(6624) == QUEST_STATUS_INCOMPLETE)
                        player->FailQuest(6624);
                    else if (player->GetQuestStatus(6622) == QUEST_STATUS_INCOMPLETE)
                        player->FailQuest(6622);

                    Reset();
                    return;
                }

                Coordinates.push_back(Point);
            }
            else
                // If no player or player abandon quest in progress
                Reset();
        }

        void PatientSaved(Creature* /*soldier*/, Player* player, Location* Point)
        {
            if (player && PlayerGUID == player->GetGUID())
            {
                if ((player->GetQuestStatus(6624) == QUEST_STATUS_INCOMPLETE) || (player->GetQuestStatus(6622) == QUEST_STATUS_INCOMPLETE))
                {
                    ++PatientSavedCount;

                    if (PatientSavedCount == 15)
                    {
                        if (!Patients.empty())
                        {
                            std::list<uint64>::const_iterator itr;
                            for (itr = Patients.begin(); itr != Patients.end(); ++itr)
                            {
                                if (Creature* Patient = Unit::GetCreature((*me), *itr))
                                    Patient->setDeathState(JUST_DIED);
                            }
                        }

                        if (player->GetQuestStatus(6624) == QUEST_STATUS_INCOMPLETE)
                            player->AreaExploredOrEventHappens(6624);
                        else if (player->GetQuestStatus(6622) == QUEST_STATUS_INCOMPLETE)
                            player->AreaExploredOrEventHappens(6622);

                        Reset();
                        return;
                    }

                    Coordinates.push_back(Point);
                }
            }
        }

        void UpdateAI(const uint32 diff);

        void EnterCombat(Unit* /*who*/){}
    };

    bool OnQuestAccept(Player* player, Creature* creature, Quest const *quest)
    {
        if ((quest->GetQuestId() == 6624) || (quest->GetQuestId() == 6622))
            CAST_AI(npc_doctor::npc_doctorAI, creature->AI())->BeginEvent(player);

        return true;
    }

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_doctorAI(creature);
    }
};

/*#####
## npc_injured_patient (handles all the patients, no matter Horde or Alliance)
#####*/

class npc_injured_patient : public CreatureScript
{
public:
    npc_injured_patient() : CreatureScript("npc_injured_patient") { }

    struct npc_injured_patientAI : public ScriptedAI
    {
        npc_injured_patientAI(Creature *c) : ScriptedAI(c) {}

        uint64 Doctorguid;
        Location* Coord;

        void Reset()
        {
            Doctorguid = 0;
            Coord = NULL;

            //no select
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

            //no regen health
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IN_COMBAT);

            //to make them lay with face down
            me->SetUInt32Value(UNIT_FIELD_BYTES_1, UNIT_STAND_STATE_DEAD);

            uint32 mobId = me->GetEntry();

            switch (mobId)
            {                                                   //lower max health
                case 12923:
                case 12938:                                     //Injured Soldier
                    me->SetHealth(me->CountPctFromMaxHealth(75));
                    break;
                case 12924:
                case 12936:                                     //Badly injured Soldier
                    me->SetHealth(me->CountPctFromMaxHealth(50));
                    break;
                case 12925:
                case 12937:                                     //Critically injured Soldier
                    me->SetHealth(me->CountPctFromMaxHealth(25));
                    break;
            }
        }

        void EnterCombat(Unit* /*who*/){}

        void SpellHit(Unit* caster, const SpellInfo *spell)
        {
            if (caster->GetTypeId() == TYPEID_PLAYER && me->isAlive() && spell->Id == 20804)
            {
                if ((CAST_PLR(caster)->GetQuestStatus(6624) == QUEST_STATUS_INCOMPLETE) || (CAST_PLR(caster)->GetQuestStatus(6622) == QUEST_STATUS_INCOMPLETE))
                    if (Doctorguid)
                        if (Creature* Doctor = Unit::GetCreature(*me, Doctorguid))
                            CAST_AI(npc_doctor::npc_doctorAI, Doctor->AI())->PatientSaved(me, CAST_PLR(caster), Coord);

                //make not selectable
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

                //regen health
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IN_COMBAT);

                //stand up
                me->SetUInt32Value(UNIT_FIELD_BYTES_1, UNIT_STAND_STATE_STAND);

                DoScriptText(RAND(SAY_DOC1, SAY_DOC2, SAY_DOC3), me);

                uint32 mobId = me->GetEntry();
                me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);

                switch (mobId)
                {
                    case 12923:
                    case 12924:
                    case 12925:
                        me->GetMotionMaster()->MovePoint(0, H_RUNTOX, H_RUNTOY, H_RUNTOZ);
                        break;
                    case 12936:
                    case 12937:
                    case 12938:
                        me->GetMotionMaster()->MovePoint(0, A_RUNTOX, A_RUNTOY, A_RUNTOZ);
                        break;
                }
            }
        }

        void UpdateAI(const uint32 /*diff*/)
        {
            //lower HP on every world tick makes it a useful counter, not officlone though
            if (me->isAlive() && me->GetHealth() > 6)
            {
                me->ModifyHealth(-5);
            }

            if (me->isAlive() && me->GetHealth() <= 6)
            {
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IN_COMBAT);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->setDeathState(JUST_DIED);
                me->SetFlag(UNIT_DYNAMIC_FLAGS, 32);

                if (Doctorguid)
                {
                    if (Creature* Doctor = Unit::GetCreature((*me), Doctorguid))
                        CAST_AI(npc_doctor::npc_doctorAI, Doctor->AI())->PatientDied(Coord);
                }
            }
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_injured_patientAI(creature);
    }
};

void npc_doctor::npc_doctorAI::UpdateAI(const uint32 diff)
{
    if (Event && SummonPatientCount >= 20)
    {
        Reset();
        return;
    }

    if (Event)
    {
        if (SummonPatient_Timer <= diff)
        {
            if (Coordinates.empty())
                return;

            std::vector<Location*>::iterator itr = Coordinates.begin()+rand()%Coordinates.size();
            uint32 patientEntry = 0;

            switch(me->GetEntry())
            {
            case DOCTOR_ALLIANCE: patientEntry = AllianceSoldierId[rand()%3]; break;
            case DOCTOR_HORDE:    patientEntry = HordeSoldierId[rand()%3]; break;
            default:
                sLog->outError("TSCR: Invalid entry for Triage doctor. Please check your database");
                return;
            }

            if (Location* Point = *itr)
            {
                if (Creature* Patient = me->SummonCreature(patientEntry, Point->x, Point->y, Point->z, Point->o, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000))
                {
                    //303, this flag appear to be required for client side item->spell to work (TARGET_SINGLE_FRIEND)
                    Patient->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PVP_ATTACKABLE);

                    Patients.push_back(Patient->GetGUID());
                    CAST_AI(npc_injured_patient::npc_injured_patientAI, Patient->AI())->Doctorguid = me->GetGUID();

                    if (Point)
                        CAST_AI(npc_injured_patient::npc_injured_patientAI, Patient->AI())->Coord = Point;

                    Coordinates.erase(itr);
                }
            }
            SummonPatient_Timer = 10000;
            ++SummonPatientCount;
        } else SummonPatient_Timer -= diff;
    }
}

/*######
## npc_garments_of_quests
######*/

//TODO: get text for each NPC

enum eGarments
{
    SPELL_LESSER_HEAL_R2    = 2052,
    SPELL_FORTITUDE_R1      = 1243,

    QUEST_MOON              = 5621,
    QUEST_LIGHT_1           = 5624,
    QUEST_LIGHT_2           = 5625,
    QUEST_SPIRIT            = 5648,
    QUEST_DARKNESS          = 5650,

    ENTRY_SHAYA             = 12429,
    ENTRY_ROBERTS           = 12423,
    ENTRY_DOLF              = 12427,
    ENTRY_KORJA             = 12430,
    ENTRY_DG_KEL            = 12428,

    //used by 12429, 12423, 12427, 12430, 12428, but signed for 12429
    SAY_COMMON_HEALED       = -1000164,
    SAY_DG_KEL_THANKS       = -1000165,
    SAY_DG_KEL_GOODBYE      = -1000166,
    SAY_ROBERTS_THANKS      = -1000167,
    SAY_ROBERTS_GOODBYE     = -1000168,
    SAY_KORJA_THANKS        = -1000169,
    SAY_KORJA_GOODBYE       = -1000170,
    SAY_DOLF_THANKS         = -1000171,
    SAY_DOLF_GOODBYE        = -1000172,
    SAY_SHAYA_THANKS        = -1000173,
    SAY_SHAYA_GOODBYE       = -1000174, //signed for 21469
};

class npc_garments_of_quests : public CreatureScript
{
public:
    npc_garments_of_quests() : CreatureScript("npc_garments_of_quests") { }

    struct npc_garments_of_questsAI : public npc_escortAI
    {
        npc_garments_of_questsAI(Creature *c) : npc_escortAI(c) {Reset();}

        uint64 caster;

        bool bIsHealed;
        bool bCanRun;

        uint32 RunAwayTimer;

        void Reset()
        {
            caster = 0;

            bIsHealed = false;
            bCanRun = false;

            RunAwayTimer = 5000;

            me->SetStandState(UNIT_STAND_STATE_KNEEL);
            //expect database to have RegenHealth=0
            me->SetHealth(me->CountPctFromMaxHealth(70));
        }

        void EnterCombat(Unit* /*who*/) {}

        void SpellHit(Unit* pCaster, const SpellInfo *Spell)
        {
            if (Spell->Id == SPELL_LESSER_HEAL_R2 || Spell->Id == SPELL_FORTITUDE_R1)
            {
                //not while in combat
                if (me->isInCombat())
                    return;

                //nothing to be done now
                if (bIsHealed && bCanRun)
                    return;

                if (pCaster->GetTypeId() == TYPEID_PLAYER)
                {
                    switch(me->GetEntry())
                    {
                        case ENTRY_SHAYA:
                            if (CAST_PLR(pCaster)->GetQuestStatus(QUEST_MOON) == QUEST_STATUS_INCOMPLETE)
                            {
                                if (bIsHealed && !bCanRun && Spell->Id == SPELL_FORTITUDE_R1)
                                {
                                    DoScriptText(SAY_SHAYA_THANKS, me, pCaster);
                                    bCanRun = true;
                                }
                                else if (!bIsHealed && Spell->Id == SPELL_LESSER_HEAL_R2)
                                {
                                    caster = pCaster->GetGUID();
                                    me->SetStandState(UNIT_STAND_STATE_STAND);
                                    DoScriptText(SAY_COMMON_HEALED, me, pCaster);
                                    bIsHealed = true;
                                }
                            }
                            break;
                        case ENTRY_ROBERTS:
                            if (CAST_PLR(pCaster)->GetQuestStatus(QUEST_LIGHT_1) == QUEST_STATUS_INCOMPLETE)
                            {
                                if (bIsHealed && !bCanRun && Spell->Id == SPELL_FORTITUDE_R1)
                                {
                                    DoScriptText(SAY_ROBERTS_THANKS, me, pCaster);
                                    bCanRun = true;
                                }
                                else if (!bIsHealed && Spell->Id == SPELL_LESSER_HEAL_R2)
                                {
                                    caster = pCaster->GetGUID();
                                    me->SetStandState(UNIT_STAND_STATE_STAND);
                                    DoScriptText(SAY_COMMON_HEALED, me, pCaster);
                                    bIsHealed = true;
                                }
                            }
                            break;
                        case ENTRY_DOLF:
                            if (CAST_PLR(pCaster)->GetQuestStatus(QUEST_LIGHT_2) == QUEST_STATUS_INCOMPLETE)
                            {
                                if (bIsHealed && !bCanRun && Spell->Id == SPELL_FORTITUDE_R1)
                                {
                                    DoScriptText(SAY_DOLF_THANKS, me, pCaster);
                                    bCanRun = true;
                                }
                                else if (!bIsHealed && Spell->Id == SPELL_LESSER_HEAL_R2)
                                {
                                    caster = pCaster->GetGUID();
                                    me->SetStandState(UNIT_STAND_STATE_STAND);
                                    DoScriptText(SAY_COMMON_HEALED, me, pCaster);
                                    bIsHealed = true;
                                }
                            }
                            break;
                        case ENTRY_KORJA:
                            if (CAST_PLR(pCaster)->GetQuestStatus(QUEST_SPIRIT) == QUEST_STATUS_INCOMPLETE)
                            {
                                if (bIsHealed && !bCanRun && Spell->Id == SPELL_FORTITUDE_R1)
                                {
                                    DoScriptText(SAY_KORJA_THANKS, me, pCaster);
                                    bCanRun = true;
                                }
                                else if (!bIsHealed && Spell->Id == SPELL_LESSER_HEAL_R2)
                                {
                                    caster = pCaster->GetGUID();
                                    me->SetStandState(UNIT_STAND_STATE_STAND);
                                    DoScriptText(SAY_COMMON_HEALED, me, pCaster);
                                    bIsHealed = true;
                                }
                            }
                            break;
                        case ENTRY_DG_KEL:
                            if (CAST_PLR(pCaster)->GetQuestStatus(QUEST_DARKNESS) == QUEST_STATUS_INCOMPLETE)
                            {
                                if (bIsHealed && !bCanRun && Spell->Id == SPELL_FORTITUDE_R1)
                                {
                                    DoScriptText(SAY_DG_KEL_THANKS, me, pCaster);
                                    bCanRun = true;
                                }
                                else if (!bIsHealed && Spell->Id == SPELL_LESSER_HEAL_R2)
                                {
                                    caster = pCaster->GetGUID();
                                    me->SetStandState(UNIT_STAND_STATE_STAND);
                                    DoScriptText(SAY_COMMON_HEALED, me, pCaster);
                                    bIsHealed = true;
                                }
                            }
                            break;
                    }

                    //give quest credit, not expect any special quest objectives
                    if (bCanRun)
                        CAST_PLR(pCaster)->TalkedToCreature(me->GetEntry(), me->GetGUID());
                }
            }
        }

        void WaypointReached(uint32 /*uiPoint*/)
        {
        }

        void UpdateAI(const uint32 diff)
        {
            if (bCanRun && !me->isInCombat())
            {
                if (RunAwayTimer <= diff)
                {
                    if (Unit *pUnit = Unit::GetUnit(*me, caster))
                    {
                        switch(me->GetEntry())
                        {
                            case ENTRY_SHAYA: DoScriptText(SAY_SHAYA_GOODBYE, me, pUnit); break;
                            case ENTRY_ROBERTS: DoScriptText(SAY_ROBERTS_GOODBYE, me, pUnit); break;
                            case ENTRY_DOLF: DoScriptText(SAY_DOLF_GOODBYE, me, pUnit); break;
                            case ENTRY_KORJA: DoScriptText(SAY_KORJA_GOODBYE, me, pUnit); break;
                            case ENTRY_DG_KEL: DoScriptText(SAY_DG_KEL_GOODBYE, me, pUnit); break;
                        }

                        Start(false, true, true);
                    }
                    else
                        EnterEvadeMode();                       //something went wrong

                    RunAwayTimer = 30000;
                } else RunAwayTimer -= diff;
            }

            npc_escortAI::UpdateAI(diff);
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_garments_of_questsAI(creature);
    }
};

/*######
## npc_kingdom_of_dalaran_quests
######*/

enum eKingdomDalaran
{
    SPELL_TELEPORT_DALARAN  = 53360,
    ITEM_KT_SIGNET          = 39740,
    QUEST_MAGICAL_KINGDOM_A = 12794,
    QUEST_MAGICAL_KINGDOM_H = 12791,
    QUEST_MAGICAL_KINGDOM_N = 12796
};

#define GOSSIP_ITEM_TELEPORT_TO "I am ready to be teleported to Dalaran."

class npc_kingdom_of_dalaran_quests : public CreatureScript
{
public:
    npc_kingdom_of_dalaran_quests() : CreatureScript("npc_kingdom_of_dalaran_quests") { }
    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->isQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (player->HasItemCount(ITEM_KT_SIGNET, 1) && (!player->GetQuestRewardStatus(QUEST_MAGICAL_KINGDOM_A) ||
            !player->GetQuestRewardStatus(QUEST_MAGICAL_KINGDOM_H) || !player->GetQuestRewardStatus(QUEST_MAGICAL_KINGDOM_N)))
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_TELEPORT_TO, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*uiSender*/, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();
        if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
        {
            player->CLOSE_GOSSIP_MENU();
            player->CastSpell(player, SPELL_TELEPORT_DALARAN, false);
        }
        return true;
    }
};

/*######
## npc_mount_vendor
######*/

class npc_mount_vendor : public CreatureScript
{
public:
    npc_mount_vendor() : CreatureScript("npc_mount_vendor") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->isQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        bool canBuy;
        canBuy = false;
        uint32 vendor = creature->GetEntry();
        uint8 race = player->getRace();

        switch (vendor)
        {
            case 384:                                           //Katie Hunter
            case 1460:                                          //Unger Statforth
            case 2357:                                          //Merideth Carlson
            case 4885:                                          //Gregor MacVince
                if (player->GetReputationRank(72) != REP_EXALTED && race != RACE_HUMAN)
                    player->SEND_GOSSIP_MENU(5855, creature->GetGUID());
                else canBuy = true;
                break;
            case 1261:                                          //Veron Amberstill
                if (player->GetReputationRank(47) != REP_EXALTED && race != RACE_DWARF)
                    player->SEND_GOSSIP_MENU(5856, creature->GetGUID());
                else canBuy = true;
                break;
            case 3362:                                          //Ogunaro Wolfrunner
                if (player->GetReputationRank(76) != REP_EXALTED && race != RACE_ORC)
                    player->SEND_GOSSIP_MENU(5841, creature->GetGUID());
                else canBuy = true;
                break;
            case 3685:                                          //Harb Clawhoof
                if (player->GetReputationRank(81) != REP_EXALTED && race != RACE_TAUREN)
                    player->SEND_GOSSIP_MENU(5843, creature->GetGUID());
                else canBuy = true;
                break;
            case 4730:                                          //Lelanai
                if (player->GetReputationRank(69) != REP_EXALTED && race != RACE_NIGHTELF)
                    player->SEND_GOSSIP_MENU(5844, creature->GetGUID());
                else canBuy = true;
                break;
            case 4731:                                          //Zachariah Post
                if (player->GetReputationRank(68) != REP_EXALTED && race != RACE_UNDEAD_PLAYER)
                    player->SEND_GOSSIP_MENU(5840, creature->GetGUID());
                else canBuy = true;
                break;
            case 7952:                                          //Zjolnir
                if (player->GetReputationRank(530) != REP_EXALTED && race != RACE_TROLL)
                    player->SEND_GOSSIP_MENU(5842, creature->GetGUID());
                else canBuy = true;
                break;
            case 7955:                                          //Milli Featherwhistle
                if (player->GetReputationRank(54) != REP_EXALTED && race != RACE_GNOME)
                    player->SEND_GOSSIP_MENU(5857, creature->GetGUID());
                else canBuy = true;
                break;
            case 16264:                                         //Winaestra
                if (player->GetReputationRank(911) != REP_EXALTED && race != RACE_BLOODELF)
                    player->SEND_GOSSIP_MENU(10305, creature->GetGUID());
                else canBuy = true;
                break;
            case 17584:                                         //Torallius the Pack Handler
                if (player->GetReputationRank(930) != REP_EXALTED && race != RACE_DRAENEI)
                    player->SEND_GOSSIP_MENU(10239, creature->GetGUID());
                else canBuy = true;
                break;
        }

        if (canBuy)
        {
            if (creature->isVendor())
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);
            player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
        }
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();
        if (uiAction == GOSSIP_ACTION_TRADE)
            player->GetSession()->SendListInventory(creature->GetGUID());

        return true;
    }
};

/*######
## npc_rogue_trainer
######*/

#define GOSSIP_HELLO_ROGUE1 "I wish to unlearn my talents"
#define GOSSIP_HELLO_ROGUE2 "<Take the letter>"
#define GOSSIP_HELLO_ROGUE3 "Purchase a Dual Talent Specialization."

class npc_rogue_trainer : public CreatureScript
{
public:
    npc_rogue_trainer() : CreatureScript("npc_rogue_trainer") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->isQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (creature->isTrainer())
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, GOSSIP_TEXT_TRAIN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRAIN);

        if (creature->isCanTrainingAndResetTalentsOf(player))
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, GOSSIP_HELLO_ROGUE1, GOSSIP_SENDER_MAIN, GOSSIP_OPTION_UNLEARNTALENTS);

        if (player->GetSpecsCount() == 1 && creature->isCanTrainingAndResetTalentsOf(player) && player->getLevel() >= sWorld->getIntConfig(CONFIG_MIN_DUALSPEC_LEVEL))
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, GOSSIP_HELLO_ROGUE3, GOSSIP_SENDER_MAIN, GOSSIP_OPTION_LEARNDUALSPEC);

        if (player->getClass() == CLASS_ROGUE && player->getLevel() >= 24 && !player->HasItemCount(17126, 1) && !player->GetQuestRewardStatus(6681))
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_ROGUE2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            player->SEND_GOSSIP_MENU(5996, creature->GetGUID());
        } else
            player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();
        switch(uiAction)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                player->CLOSE_GOSSIP_MENU();
                player->CastSpell(player, 21100, false);
                break;
            case GOSSIP_ACTION_TRAIN:
                player->GetSession()->SendTrainerList(creature->GetGUID());
                break;
            case GOSSIP_OPTION_UNLEARNTALENTS:
                player->CLOSE_GOSSIP_MENU();
                player->SendTalentWipeConfirm(creature->GetGUID());
                break;
            case GOSSIP_OPTION_LEARNDUALSPEC:
                if (player->GetSpecsCount() == 1 && !(player->getLevel() < sWorld->getIntConfig(CONFIG_MIN_DUALSPEC_LEVEL)))
                {
                    if (!player->HasEnoughMoney(10000000))
                    {
                        player->SendBuyError(BUY_ERR_NOT_ENOUGHT_MONEY, 0, 0, 0);
                        player->PlayerTalkClass->SendCloseGossip();
                        break;
                    }
                    else
                    {
                        player->ModifyMoney(-10000000);

                        // Cast spells that teach dual spec
                        // Both are also ImplicitTarget self and must be cast by player
                        player->CastSpell(player, 63680, true, NULL, NULL, player->GetGUID());
                        player->CastSpell(player, 63624, true, NULL, NULL, player->GetGUID());

                        // Should show another Gossip text with "Congratulations..."
                        player->PlayerTalkClass->SendCloseGossip();
                    }
                }
                break;
        }
        return true;
    }
};

/*######
## npc_sayge
######*/

#define SPELL_DMG       23768                               //dmg
#define SPELL_RES       23769                               //res
#define SPELL_ARM       23767                               //arm
#define SPELL_SPI       23738                               //spi
#define SPELL_INT       23766                               //int
#define SPELL_STM       23737                               //stm
#define SPELL_STR       23735                               //str
#define SPELL_AGI       23736                               //agi
#define SPELL_FORTUNE   23765                               //faire fortune

#define GOSSIP_HELLO_SAYGE  "Yes"
#define GOSSIP_SENDACTION_SAYGE1    "Slay the Man"
#define GOSSIP_SENDACTION_SAYGE2    "Turn him over to liege"
#define GOSSIP_SENDACTION_SAYGE3    "Confiscate the corn"
#define GOSSIP_SENDACTION_SAYGE4    "Let him go and have the corn"
#define GOSSIP_SENDACTION_SAYGE5    "Execute your friend painfully"
#define GOSSIP_SENDACTION_SAYGE6    "Execute your friend painlessly"
#define GOSSIP_SENDACTION_SAYGE7    "Let your friend go"
#define GOSSIP_SENDACTION_SAYGE8    "Confront the diplomat"
#define GOSSIP_SENDACTION_SAYGE9    "Show not so quiet defiance"
#define GOSSIP_SENDACTION_SAYGE10   "Remain quiet"
#define GOSSIP_SENDACTION_SAYGE11   "Speak against your brother openly"
#define GOSSIP_SENDACTION_SAYGE12   "Help your brother in"
#define GOSSIP_SENDACTION_SAYGE13   "Keep your brother out without letting him know"
#define GOSSIP_SENDACTION_SAYGE14   "Take credit, keep gold"
#define GOSSIP_SENDACTION_SAYGE15   "Take credit, share the gold"
#define GOSSIP_SENDACTION_SAYGE16   "Let the knight take credit"
#define GOSSIP_SENDACTION_SAYGE17   "Thanks"

class npc_sayge : public CreatureScript
{
public:
    npc_sayge() : CreatureScript("npc_sayge") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->isQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (player->HasSpellCooldown(SPELL_INT) ||
            player->HasSpellCooldown(SPELL_ARM) ||
            player->HasSpellCooldown(SPELL_DMG) ||
            player->HasSpellCooldown(SPELL_RES) ||
            player->HasSpellCooldown(SPELL_STR) ||
            player->HasSpellCooldown(SPELL_AGI) ||
            player->HasSpellCooldown(SPELL_STM) ||
            player->HasSpellCooldown(SPELL_SPI))
            player->SEND_GOSSIP_MENU(7393, creature->GetGUID());
        else
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_SAYGE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            player->SEND_GOSSIP_MENU(7339, creature->GetGUID());
        }

        return true;
    }

    void SendAction(Player* player, Creature* creature, uint32 uiAction)
    {
        switch(uiAction)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SENDACTION_SAYGE1,            GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SENDACTION_SAYGE2,            GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SENDACTION_SAYGE3,            GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+4);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SENDACTION_SAYGE4,            GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+5);
                player->SEND_GOSSIP_MENU(7340, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+2:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SENDACTION_SAYGE5,            GOSSIP_SENDER_MAIN+1, GOSSIP_ACTION_INFO_DEF);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SENDACTION_SAYGE6,            GOSSIP_SENDER_MAIN+2, GOSSIP_ACTION_INFO_DEF);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SENDACTION_SAYGE7,            GOSSIP_SENDER_MAIN+3, GOSSIP_ACTION_INFO_DEF);
                player->SEND_GOSSIP_MENU(7341, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+3:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SENDACTION_SAYGE8,            GOSSIP_SENDER_MAIN+4, GOSSIP_ACTION_INFO_DEF);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SENDACTION_SAYGE9,            GOSSIP_SENDER_MAIN+5, GOSSIP_ACTION_INFO_DEF);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SENDACTION_SAYGE10,           GOSSIP_SENDER_MAIN+2, GOSSIP_ACTION_INFO_DEF);
                player->SEND_GOSSIP_MENU(7361, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+4:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SENDACTION_SAYGE11,           GOSSIP_SENDER_MAIN+6, GOSSIP_ACTION_INFO_DEF);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SENDACTION_SAYGE12,           GOSSIP_SENDER_MAIN+7, GOSSIP_ACTION_INFO_DEF);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SENDACTION_SAYGE13,           GOSSIP_SENDER_MAIN+8, GOSSIP_ACTION_INFO_DEF);
                player->SEND_GOSSIP_MENU(7362, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+5:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SENDACTION_SAYGE14,           GOSSIP_SENDER_MAIN+5, GOSSIP_ACTION_INFO_DEF);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SENDACTION_SAYGE15,           GOSSIP_SENDER_MAIN+4, GOSSIP_ACTION_INFO_DEF);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SENDACTION_SAYGE16,           GOSSIP_SENDER_MAIN+3, GOSSIP_ACTION_INFO_DEF);
                player->SEND_GOSSIP_MENU(7363, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SENDACTION_SAYGE17,           GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+6);
                player->SEND_GOSSIP_MENU(7364, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+6:
                creature->CastSpell(player, SPELL_FORTUNE, false);
                player->SEND_GOSSIP_MENU(7365, creature->GetGUID());
                break;
        }
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 uiSender, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();
        switch(uiSender)
        {
            case GOSSIP_SENDER_MAIN:
                SendAction(player, creature, uiAction);
                break;
            case GOSSIP_SENDER_MAIN+1:
                creature->CastSpell(player, SPELL_DMG, false);
                player->AddSpellCooldown(SPELL_DMG, 0, time(NULL) + 7200);
                SendAction(player, creature, uiAction);
                break;
            case GOSSIP_SENDER_MAIN+2:
                creature->CastSpell(player, SPELL_RES, false);
                player->AddSpellCooldown(SPELL_RES, 0, time(NULL) + 7200);
                SendAction(player, creature, uiAction);
                break;
            case GOSSIP_SENDER_MAIN+3:
                creature->CastSpell(player, SPELL_ARM, false);
                player->AddSpellCooldown(SPELL_ARM, 0, time(NULL) + 7200);
                SendAction(player, creature, uiAction);
                break;
            case GOSSIP_SENDER_MAIN+4:
                creature->CastSpell(player, SPELL_SPI, false);
                player->AddSpellCooldown(SPELL_SPI, 0, time(NULL) + 7200);
                SendAction(player, creature, uiAction);
                break;
            case GOSSIP_SENDER_MAIN+5:
                creature->CastSpell(player, SPELL_INT, false);
                player->AddSpellCooldown(SPELL_INT, 0, time(NULL) + 7200);
                SendAction(player, creature, uiAction);
                break;
            case GOSSIP_SENDER_MAIN+6:
                creature->CastSpell(player, SPELL_STM, false);
                player->AddSpellCooldown(SPELL_STM, 0, time(NULL) + 7200);
                SendAction(player, creature, uiAction);
                break;
            case GOSSIP_SENDER_MAIN+7:
                creature->CastSpell(player, SPELL_STR, false);
                player->AddSpellCooldown(SPELL_STR, 0, time(NULL) + 7200);
                SendAction(player, creature, uiAction);
                break;
            case GOSSIP_SENDER_MAIN+8:
                creature->CastSpell(player, SPELL_AGI, false);
                player->AddSpellCooldown(SPELL_AGI, 0, time(NULL) + 7200);
                SendAction(player, creature, uiAction);
                break;
        }
        return true;
    }
};

class npc_steam_tonk : public CreatureScript
{
public:
    npc_steam_tonk() : CreatureScript("npc_steam_tonk") { }

    struct npc_steam_tonkAI : public ScriptedAI
    {
        npc_steam_tonkAI(Creature *c) : ScriptedAI(c) {}

        void Reset() {}
        void EnterCombat(Unit* /*who*/) {}

        void OnPossess(bool apply)
        {
            if (apply)
            {
                // Initialize the action bar without the melee attack command
                me->InitCharmInfo();
                me->GetCharmInfo()->InitEmptyActionBar(false);

                me->SetReactState(REACT_PASSIVE);
            }
            else
                me->SetReactState(REACT_AGGRESSIVE);
        }

    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_steam_tonkAI(creature);
    }
};

#define SPELL_TONK_MINE_DETONATE 25099

class npc_tonk_mine : public CreatureScript
{
public:
    npc_tonk_mine() : CreatureScript("npc_tonk_mine") { }

    struct npc_tonk_mineAI : public ScriptedAI
    {
        npc_tonk_mineAI(Creature *c) : ScriptedAI(c)
        {
            me->SetReactState(REACT_PASSIVE);
        }

        uint32 ExplosionTimer;

        void Reset()
        {
            ExplosionTimer = 3000;
        }

        void EnterCombat(Unit* /*who*/) {}
        void AttackStart(Unit* /*who*/) {}
        void MoveInLineOfSight(Unit* /*who*/) {}

        void UpdateAI(const uint32 diff)
        {
            if (ExplosionTimer <= diff)
            {
                DoCast(me, SPELL_TONK_MINE_DETONATE, true);
                me->setDeathState(DEAD); // unsummon it
            } else
                ExplosionTimer -= diff;
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_tonk_mineAI(creature);
    }
};

/*####
## npc_brewfest_reveler
####*/

class npc_brewfest_reveler : public CreatureScript
{
public:
    npc_brewfest_reveler() : CreatureScript("npc_brewfest_reveler") { }

    struct npc_brewfest_revelerAI : public ScriptedAI
    {
        npc_brewfest_revelerAI(Creature* c) : ScriptedAI(c) {}
        void ReceiveEmote(Player* player, uint32 emote)
        {
            if (!IsHolidayActive(HOLIDAY_BREWFEST))
                return;

            if (emote == TEXT_EMOTE_DANCE)
                me->CastSpell(player, 41586, false);
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_brewfest_revelerAI(creature);
    }
};

/*####
## npc_winter_reveler
####*/

class npc_winter_reveler : public CreatureScript
{
public:
    npc_winter_reveler() : CreatureScript("npc_winter_reveler") { }

    struct npc_winter_revelerAI : public ScriptedAI
    {
        npc_winter_revelerAI(Creature* c) : ScriptedAI(c) {}
        void ReceiveEmote(Player* player, uint32 emote)
        {
            if (!IsHolidayActive(HOLIDAY_FEAST_OF_WINTER_VEIL))
                return;
            //TODO: check auralist.
            if (player->HasAura(26218))
                return;

            if (emote == TEXT_EMOTE_KISS)
            {
                me->CastSpell(me, 26218, false);
                player->CastSpell(player, 26218, false);
                switch (urand(0, 2))
                {
                    case 0: me->CastSpell(player, 26207, false); break;
                    case 1: me->CastSpell(player, 26206, false); break;
                    case 2: me->CastSpell(player, 45036, false); break;
                }
            }
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_winter_revelerAI(creature);
    }
};

/*####
## npc_snake_trap_serpents
####*/

#define SPELL_MIND_NUMBING_POISON    25810   //Viper
#define SPELL_DEADLY_POISON          34655   //Venomous Snake
#define SPELL_CRIPPLING_POISON       30981   //Viper

#define VENOMOUS_SNAKE_TIMER 1500
#define VIPER_TIMER 3000

#define C_VIPER 19921

#define RAND 5

class npc_snake_trap : public CreatureScript
{
public:
    npc_snake_trap() : CreatureScript("npc_snake_trap_serpents") { }

    struct npc_snake_trap_serpentsAI : public ScriptedAI
    {
        npc_snake_trap_serpentsAI(Creature *c) : ScriptedAI(c) {}

        uint32 SpellTimer;
        bool IsViper;

        void EnterCombat(Unit* /*who*/) {}

        void Reset()
        {
            SpellTimer = 0;

            CreatureTemplate const *Info = me->GetCreatureInfo();

            if (Info->Entry == C_VIPER)
                IsViper = true;
            else
                IsViper = false;

            me->SetMaxHealth(uint32(107 * (me->getLevel() - 40) * 0.025f));
            //Add delta to make them not all hit the same time
            uint32 delta = (rand() % 7) * 100;
            me->SetStatFloatValue(UNIT_FIELD_BASEATTACKTIME, float(Info->baseattacktime + delta));
            me->SetStatFloatValue(UNIT_FIELD_RANGED_ATTACK_POWER , float(Info->attackpower));

            // Start attacking attacker of owner on first ai update after spawn - move in line of sight may choose better target
            if (!me->getVictim() && me->isSummon())
                if (Unit* Owner = me->ToTempSummon()->GetSummoner())
                    if (Owner->getAttackerForHelper())
                        AttackStart(Owner->getAttackerForHelper());
        }

        //Redefined for random target selection:
        void MoveInLineOfSight(Unit *who)
        {
            if (!me->getVictim() && who->isTargetableForAttack() && (me->IsHostileTo(who)) && who->isInAccessiblePlaceFor(me))
            {
                if (me->GetDistanceZ(who) > CREATURE_Z_ATTACK_RANGE)
                    return;

                float attackRadius = me->GetAttackDistance(who);
                if (me->IsWithinDistInMap(who, attackRadius) && me->IsWithinLOSInMap(who))
                {
                    if (!(rand() % RAND))
                    {
                        me->setAttackTimer(BASE_ATTACK, (rand() % 10) * 100);
                        SpellTimer = (rand() % 10) * 100;
                        AttackStart(who);
                    }
                }
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (SpellTimer <= diff)
            {
                if (IsViper) //Viper
                {
                    if (urand(0, 2) == 0) //33% chance to cast
                    {
                        uint32 spell;
                        if (urand(0, 1) == 0)
                            spell = SPELL_MIND_NUMBING_POISON;
                        else
                            spell = SPELL_CRIPPLING_POISON;

                        DoCast(me->getVictim(), spell);
                    }

                    SpellTimer = VIPER_TIMER;
                }
                else //Venomous Snake
                {
                    if (urand(0, 2) == 0) //33% chance to cast
                        DoCast(me->getVictim(), SPELL_DEADLY_POISON);
                    SpellTimer = VENOMOUS_SNAKE_TIMER + (rand() %5)*100;
                }
            } else SpellTimer -= diff;
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_snake_trap_serpentsAI(creature);
    }
};

#define SAY_RANDOM_MOJO0    "Now that's what I call froggy-style!"
#define SAY_RANDOM_MOJO1    "Your lily pad or mine?"
#define SAY_RANDOM_MOJO2    "This won't take long, did it?"
#define SAY_RANDOM_MOJO3    "I thought you'd never ask!"
#define SAY_RANDOM_MOJO4    "I promise not to give you warts..."
#define SAY_RANDOM_MOJO5    "Feelin' a little froggy, are ya?"
#define SAY_RANDOM_MOJO6a   "Listen, "
#define SAY_RANDOM_MOJO6b   ", I know of a little swamp not too far from here...."
#define SAY_RANDOM_MOJO7    "There's just never enough Mojo to go around..."

class mob_mojo : public CreatureScript
{
public:
    mob_mojo() : CreatureScript("mob_mojo") { }

    struct mob_mojoAI : public ScriptedAI
    {
        mob_mojoAI(Creature *c) : ScriptedAI(c) {Reset();}
        uint32 hearts;
        uint64 victimGUID;
        void Reset()
        {
            victimGUID = 0;
            hearts = 15000;
            if (Unit* own = me->GetOwner())
                me->GetMotionMaster()->MoveFollow(own, 0, 0);
        }
        void EnterCombat(Unit* /*who*/){}
        void UpdateAI(const uint32 diff)
        {
            if (me->HasAura(20372))
            {
                if (hearts <= diff)
                {
                    me->RemoveAurasDueToSpell(20372);
                    hearts = 15000;
                } hearts -= diff;
            }
        }
        void ReceiveEmote(Player* player, uint32 emote)
        {
            me->HandleEmoteCommand(emote);
            Unit* own = me->GetOwner();
            if (!own || own->GetTypeId() != TYPEID_PLAYER || CAST_PLR(own)->GetTeam() != player->GetTeam())
                return;
            if (emote == TEXT_EMOTE_KISS)
            {
                std::string whisp = "";
                switch (rand()%8)
                {
                    case 0:whisp.append(SAY_RANDOM_MOJO0);break;
                    case 1:whisp.append(SAY_RANDOM_MOJO1);break;
                    case 2:whisp.append(SAY_RANDOM_MOJO2);break;
                    case 3:whisp.append(SAY_RANDOM_MOJO3);break;
                    case 4:whisp.append(SAY_RANDOM_MOJO4);break;
                    case 5:whisp.append(SAY_RANDOM_MOJO5);break;
                    case 6:
                        whisp.append(SAY_RANDOM_MOJO6a);
                        whisp.append(player->GetName());
                        whisp.append(SAY_RANDOM_MOJO6b);
                        break;
                    case 7:whisp.append(SAY_RANDOM_MOJO7);break;
                }
                me->MonsterWhisper(whisp.c_str(), player->GetGUID());
                if (victimGUID)
                {
                    Player* victim = Unit::GetPlayer(*me, victimGUID);
                    if (victim)
                        victim->RemoveAura(43906);//remove polymorph frog thing
                }
                me->AddAura(43906, player);//add polymorph frog thing
                victimGUID = player->GetGUID();
                DoCast(me, 20372, true);//tag.hearts
                me->GetMotionMaster()->MoveFollow(player, 0, 0);
                hearts = 15000;
            }
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new mob_mojoAI(creature);
    }
};

class npc_mirror_image : public CreatureScript
{
public:
    npc_mirror_image() : CreatureScript("npc_mirror_image") { }

    struct npc_mirror_imageAI : CasterAI
    {
        npc_mirror_imageAI(Creature *c) : CasterAI(c) {}

        void InitializeAI()
        {
            CasterAI::InitializeAI();
            Unit* owner = me->GetOwner();
            if (!owner)
                return;
            // Inherit Master's Threat List (not yet implemented)
            owner->CastSpell((Unit*)NULL, 58838, true);
            // here mirror image casts on summoner spell (not present in client dbc) 49866
            // here should be auras (not present in client dbc): 35657, 35658, 35659, 35660 selfcasted by mirror images (stats related?)
            // Clone Me!
            owner->CastSpell(me, 45204, false);
        }

        // Do not reload Creature templates on evade mode enter - prevent visual lost
        void EnterEvadeMode()
        {
            if (me->IsInEvadeMode() || !me->isAlive())
                return;

            Unit *owner = me->GetCharmerOrOwner();

            me->CombatStop(true);
            if (owner && !me->HasUnitState(UNIT_STAT_FOLLOW))
            {
                me->GetMotionMaster()->Clear(false);
                me->GetMotionMaster()->MoveFollow(owner, PET_FOLLOW_DIST, me->GetFollowAngle(), MOTION_SLOT_ACTIVE);
            }
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_mirror_imageAI(creature);
    }
};

class npc_ebon_gargoyle : public CreatureScript
{
public:
    npc_ebon_gargoyle() : CreatureScript("npc_ebon_gargoyle") { }

    struct npc_ebon_gargoyleAI : CasterAI
    {
        npc_ebon_gargoyleAI(Creature *c) : CasterAI(c) {}

        uint32 despawnTimer;

        void InitializeAI()
        {
            CasterAI::InitializeAI();
            Unit* owner = me->GetOwner();
            if (!owner)
                return;
            // Not needed to be despawned now
            despawnTimer = 0;
            // Find victim of Summon Gargoyle spell
            std::list<Unit*> targets;
            Trinity::AnyUnfriendlyUnitInObjectRangeCheck u_check(me, me, 30);
            Trinity::UnitListSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> searcher(me, targets, u_check);
            me->VisitNearbyObject(30, searcher);
            for (std::list<Unit*>::const_iterator iter = targets.begin(); iter != targets.end(); ++iter)
                if ((*iter)->GetAura(49206, owner->GetGUID()))
                {
                    me->Attack((*iter), false);
                    break;
                }
        }

        void JustDied(Unit* /*killer*/)
        {
            // Stop Feeding Gargoyle when it dies
            if (Unit *owner = me->GetOwner())
                owner->RemoveAurasDueToSpell(50514);
        }

        // Fly away when dismissed
        void SpellHit(Unit* source, const SpellInfo *spell)
        {
            if (spell->Id != 50515 || !me->isAlive())
                return;

            Unit *owner = me->GetOwner();

            if (!owner || owner != source)
                return;

            // Stop Fighting
            me->ApplyModFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE, true);
            // Sanctuary
            me->CastSpell(me, 54661, true);
            me->SetReactState(REACT_PASSIVE);

            // Fly Away
            me->AddUnitMovementFlag(MOVEMENTFLAG_CAN_FLY|MOVEMENTFLAG_ASCENDING|MOVEMENTFLAG_FLYING);
            me->SetSpeed(MOVE_FLIGHT, 0.75f, true);
            me->SetSpeed(MOVE_RUN, 0.75f, true);
            float x = me->GetPositionX() + 20 * cos(me->GetOrientation());
            float y = me->GetPositionY() + 20 * sin(me->GetOrientation());
            float z = me->GetPositionZ() + 40;
            me->GetMotionMaster()->Clear(false);
            me->GetMotionMaster()->MovePoint(0, x, y, z);

            // Despawn as soon as possible
            despawnTimer = 4 * IN_MILLISECONDS;
        }

        void UpdateAI(const uint32 diff)
        {
            if (despawnTimer > 0)
            {
                if (despawnTimer > diff)
                    despawnTimer -= diff;
                else
                {
                    me->DespawnOrUnsummon();
                }
                return;
            }
            CasterAI::UpdateAI(diff);
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_ebon_gargoyleAI(creature);
    }
};

class npc_lightwell : public CreatureScript
{
public:
    npc_lightwell() : CreatureScript("npc_lightwell") { }

    struct npc_lightwellAI : public PassiveAI
    {
        npc_lightwellAI(Creature *c) : PassiveAI(c) {}

        void Reset()
        {
            DoCast(me, 59907, false); // Spell for Lightwell Charges
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_lightwellAI(creature);
    }
};

enum eTrainingDummy
{
    NPC_ADVANCED_TARGET_DUMMY                  = 2674,
    NPC_TARGET_DUMMY                           = 2673
};

class npc_training_dummy : public CreatureScript
{
public:
    npc_training_dummy() : CreatureScript("npc_training_dummy") { }

    struct npc_training_dummyAI : Scripted_NoMovementAI
    {
        npc_training_dummyAI(Creature* creature) : Scripted_NoMovementAI(creature)
        {
            uiEntry = creature->GetEntry();
        }

        uint32 uiEntry;
        uint32 uiResetTimer;
        uint32 uiDespawnTimer;

        void Reset()
        {
            me->SetControlled(true, UNIT_STAT_STUNNED);//disable rotate
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);//imune to knock aways like blast wave

            uiResetTimer = 5000;
            uiDespawnTimer = 15000;
        }

        void EnterEvadeMode()
        {
            if (!_EnterEvadeMode())
                return;

            Reset();
        }

        void DamageTaken(Unit* /*done_by*/, uint32 &damage)
        {
            uiResetTimer = 5000;
            damage = 0;
        }

        void EnterCombat(Unit* /*who*/)
        {
            if (uiEntry != NPC_ADVANCED_TARGET_DUMMY && uiEntry != NPC_TARGET_DUMMY)
                return;
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            if (!me->HasUnitState(UNIT_STAT_STUNNED))
                me->SetControlled(true, UNIT_STAT_STUNNED);//disable rotate

            if (uiEntry != NPC_ADVANCED_TARGET_DUMMY && uiEntry != NPC_TARGET_DUMMY)
            {
                if (uiResetTimer <= uiDiff)
                {
                    EnterEvadeMode();
                    uiResetTimer = 5000;
                }
                else
                    uiResetTimer -= uiDiff;
                return;
            }
            else
            {
                if (uiDespawnTimer <= uiDiff)
                    me->DespawnOrUnsummon();
                else
                    uiDespawnTimer -= uiDiff;
            }
        }
        void MoveInLineOfSight(Unit* /*who*/){return;}
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_training_dummyAI(creature);
    }
};

/*######
# npc_shadowfiend
######*/
#define GLYPH_OF_SHADOWFIEND_MANA         58227
#define GLYPH_OF_SHADOWFIEND              58228

class npc_shadowfiend : public CreatureScript
{
public:
    npc_shadowfiend() : CreatureScript("npc_shadowfiend") { }

    struct npc_shadowfiendAI : public ScriptedAI
    {
        npc_shadowfiendAI(Creature* creature) : ScriptedAI(creature) {}

        void DamageTaken(Unit* /*killer*/, uint32 &damage)
        {
            if (me->isSummon())
                if (Unit* owner = me->ToTempSummon()->GetSummoner())
                {
                    if (owner->HasAura(GLYPH_OF_SHADOWFIEND))
                        if (damage >= me->GetHealth())
                            owner->CastSpell(owner, GLYPH_OF_SHADOWFIEND_MANA, true);
                }
        }

        void UpdateAI(const uint32 /*diff*/)
        {
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_shadowfiendAI(creature);
    }
};

/*######
# npc_wormhole
######*/

#define GOSSIP_ENGINEERING1   "Borean Tundra."
#define GOSSIP_ENGINEERING2   "Howling Fjord."
#define GOSSIP_ENGINEERING3   "Sholazar Basin."
#define GOSSIP_ENGINEERING4   "Icecrown."
#define GOSSIP_ENGINEERING5   "Storm Peaks."

enum eWormhole
{
    SPELL_HOWLING_FJORD         = 67838,
    SPELL_SHOLAZAR_BASIN        = 67835,
    SPELL_ICECROWN              = 67836,
    SPELL_STORM_PEAKS           = 67837,

    TEXT_WORMHOLE               = 907
};

class npc_wormhole : public CreatureScript
{
public:
    npc_wormhole() : CreatureScript("npc_wormhole") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->isSummon())
        {
            if (player == creature->ToTempSummon()->GetSummoner())
            {
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ENGINEERING1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ENGINEERING2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ENGINEERING3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ENGINEERING4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+4);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ENGINEERING5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+5);

                player->PlayerTalkClass->SendGossipMenu(TEXT_WORMHOLE, creature->GetGUID());
            }
        }
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*uiSender*/, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();
        bool roll = urand(0, 1);

        switch(uiAction)
        {
            case GOSSIP_ACTION_INFO_DEF + 1: //Borean Tundra
                player->CLOSE_GOSSIP_MENU();
                if (roll) //At the moment we don't have chance on spell_target_position table so we hack this
                    player->TeleportTo(571, 4305.505859f, 5450.839844f, 63.005806f, 0.627286f);
                else
                    player->TeleportTo(571, 3201.936279f, 5630.123535f, 133.658798f, 3.855272f);
                break;
            case GOSSIP_ACTION_INFO_DEF + 2: //Howling Fjord
                player->CLOSE_GOSSIP_MENU();
                player->CastSpell(player, SPELL_HOWLING_FJORD, true);
                break;
            case GOSSIP_ACTION_INFO_DEF + 3: //Sholazar Basin
                player->CLOSE_GOSSIP_MENU();
                player->CastSpell(player, SPELL_SHOLAZAR_BASIN, true);
                break;
            case GOSSIP_ACTION_INFO_DEF + 4: //Icecrown
                player->CLOSE_GOSSIP_MENU();
                player->CastSpell(player, SPELL_ICECROWN, true);
                break;
            case GOSSIP_ACTION_INFO_DEF + 5: //Storm peaks
                player->CLOSE_GOSSIP_MENU();
                player->CastSpell(player, SPELL_STORM_PEAKS, true);
                break;
        }
        return true;
    }
};

/*######
## npc_pet_trainer
######*/

enum ePetTrainer
{
    TEXT_ISHUNTER               = 5838,
    TEXT_NOTHUNTER              = 5839,
    TEXT_PETINFO                = 13474,
    TEXT_CONFIRM                = 7722
};

#define GOSSIP_PET1             "How do I train my pet?"
#define GOSSIP_PET2             "I wish to untrain my pet."
#define GOSSIP_PET_CONFIRM      "Yes, please do."

class npc_pet_trainer : public CreatureScript
{
public:
    npc_pet_trainer() : CreatureScript("npc_pet_trainer") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->isQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (player->getClass() == CLASS_HUNTER)
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_PET1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            if (player->GetPet() && player->GetPet()->getPetType() == HUNTER_PET)
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_PET2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);

            player->PlayerTalkClass->SendGossipMenu(TEXT_ISHUNTER, creature->GetGUID());
            return true;
        }
        player->PlayerTalkClass->SendGossipMenu(TEXT_NOTHUNTER, creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();
        switch(uiAction)
        {
            case GOSSIP_ACTION_INFO_DEF + 1:
                player->PlayerTalkClass->SendGossipMenu(TEXT_PETINFO, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF + 2:
                {
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_PET_CONFIRM, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
                    player->PlayerTalkClass->SendGossipMenu(TEXT_CONFIRM, creature->GetGUID());
                }
                break;
            case GOSSIP_ACTION_INFO_DEF + 3:
                {
                    player->ResetPetTalents();
                    player->CLOSE_GOSSIP_MENU();
                }
                break;
        }
        return true;
    }
};

/*######
## npc_locksmith
######*/

enum eLockSmith
{
    QUEST_HOW_TO_BRAKE_IN_TO_THE_ARCATRAZ = 10704,
    QUEST_DARK_IRON_LEGACY                = 3802,
    QUEST_THE_KEY_TO_SCHOLOMANCE_A        = 5505,
    QUEST_THE_KEY_TO_SCHOLOMANCE_H        = 5511,
    QUEST_HOTTER_THAN_HELL_A              = 10758,
    QUEST_HOTTER_THAN_HELL_H              = 10764,
    QUEST_RETURN_TO_KHAGDAR               = 9837,
    QUEST_CONTAINMENT                     = 13159,

    ITEM_ARCATRAZ_KEY                     = 31084,
    ITEM_SHADOWFORGE_KEY                  = 11000,
    ITEM_SKELETON_KEY                     = 13704,
    ITEM_SHATTERED_HALLS_KEY              = 28395,
    ITEM_THE_MASTERS_KEY                  = 24490,
    ITEM_VIOLET_HOLD_KEY                  = 42482,

    SPELL_ARCATRAZ_KEY                    = 54881,
    SPELL_SHADOWFORGE_KEY                 = 54882,
    SPELL_SKELETON_KEY                    = 54883,
    SPELL_SHATTERED_HALLS_KEY             = 54884,
    SPELL_THE_MASTERS_KEY                 = 54885,
    SPELL_VIOLET_HOLD_KEY                 = 67253
};

#define GOSSIP_LOST_ARCATRAZ_KEY         "I've lost my key to the Arcatraz."
#define GOSSIP_LOST_SHADOWFORGE_KEY      "I've lost my key to the Blackrock Depths."
#define GOSSIP_LOST_SKELETON_KEY         "I've lost my key to the Scholomance."
#define GOSSIP_LOST_SHATTERED_HALLS_KEY  "I've lost my key to the Shattered Halls."
#define GOSSIP_LOST_THE_MASTERS_KEY      "I've lost my key to the Karazhan."
#define GOSSIP_LOST_VIOLET_HOLD_KEY      "I've lost my key to the Violet Hold."

class npc_locksmith : public CreatureScript
{
public:
    npc_locksmith() : CreatureScript("npc_locksmith") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        // Arcatraz Key
        if (player->GetQuestRewardStatus(QUEST_HOW_TO_BRAKE_IN_TO_THE_ARCATRAZ) && !player->HasItemCount(ITEM_ARCATRAZ_KEY, 1, true))
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LOST_ARCATRAZ_KEY, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF +1);

        // Shadowforge Key
        if (player->GetQuestRewardStatus(QUEST_DARK_IRON_LEGACY) && !player->HasItemCount(ITEM_SHADOWFORGE_KEY, 1, true))
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LOST_SHADOWFORGE_KEY, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF +2);

        // Skeleton Key
        if ((player->GetQuestRewardStatus(QUEST_THE_KEY_TO_SCHOLOMANCE_A) || player->GetQuestRewardStatus(QUEST_THE_KEY_TO_SCHOLOMANCE_H)) &&
            !player->HasItemCount(ITEM_SKELETON_KEY, 1, true))
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LOST_SKELETON_KEY, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF +3);

        // Shatered Halls Key
        if ((player->GetQuestRewardStatus(QUEST_HOTTER_THAN_HELL_A) || player->GetQuestRewardStatus(QUEST_HOTTER_THAN_HELL_H)) &&
            !player->HasItemCount(ITEM_SHATTERED_HALLS_KEY, 1, true))
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LOST_SHATTERED_HALLS_KEY, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF +4);

        // Master's Key
        if (player->GetQuestRewardStatus(QUEST_RETURN_TO_KHAGDAR) && !player->HasItemCount(ITEM_THE_MASTERS_KEY, 1, true))
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LOST_THE_MASTERS_KEY, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF +5);

        // Violet Hold Key
        if (player->GetQuestRewardStatus(QUEST_CONTAINMENT) && !player->HasItemCount(ITEM_VIOLET_HOLD_KEY, 1, true))
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LOST_VIOLET_HOLD_KEY, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF +6);

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*uiSender*/, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();
        switch(uiAction)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                player->CLOSE_GOSSIP_MENU();
                player->CastSpell(player, SPELL_ARCATRAZ_KEY, false);
                break;
            case GOSSIP_ACTION_INFO_DEF+2:
                player->CLOSE_GOSSIP_MENU();
                player->CastSpell(player, SPELL_SHADOWFORGE_KEY, false);
                break;
            case GOSSIP_ACTION_INFO_DEF+3:
                player->CLOSE_GOSSIP_MENU();
                player->CastSpell(player, SPELL_SKELETON_KEY, false);
                break;
            case GOSSIP_ACTION_INFO_DEF+4:
                player->CLOSE_GOSSIP_MENU();
                player->CastSpell(player, SPELL_SHATTERED_HALLS_KEY, false);
                break;
            case GOSSIP_ACTION_INFO_DEF+5:
                player->CLOSE_GOSSIP_MENU();
                player->CastSpell(player, SPELL_THE_MASTERS_KEY, false);
                break;
            case GOSSIP_ACTION_INFO_DEF+6:
                player->CLOSE_GOSSIP_MENU();
                player->CastSpell(player, SPELL_VIOLET_HOLD_KEY, false);
                break;
        }
        return true;
    }
};

/*######
## npc_tabard_vendor
######*/

enum
{
    QUEST_TRUE_MASTERS_OF_LIGHT = 9737,
    QUEST_THE_UNWRITTEN_PROPHECY = 9762,
    QUEST_INTO_THE_BREACH = 10259,
    QUEST_BATTLE_OF_THE_CRIMSON_WATCH = 10781,
    QUEST_SHARDS_OF_AHUNE = 11972,

    ACHIEVEMENT_EXPLORE_NORTHREND = 45,
    ACHIEVEMENT_TWENTYFIVE_TABARDS = 1021,
    ACHIEVEMENT_THE_LOREMASTER_A = 1681,
    ACHIEVEMENT_THE_LOREMASTER_H = 1682,

    ITEM_TABARD_OF_THE_HAND = 24344,
    ITEM_TABARD_OF_THE_BLOOD_KNIGHT = 25549,
    ITEM_TABARD_OF_THE_PROTECTOR = 28788,
    ITEM_OFFERING_OF_THE_SHATAR = 31408,
    ITEM_GREEN_TROPHY_TABARD_OF_THE_ILLIDARI = 31404,
    ITEM_PURPLE_TROPHY_TABARD_OF_THE_ILLIDARI = 31405,
    ITEM_TABARD_OF_THE_SUMMER_SKIES = 35279,
    ITEM_TABARD_OF_THE_SUMMER_FLAMES = 35280,
    ITEM_TABARD_OF_THE_ACHIEVER = 40643,
    ITEM_LOREMASTERS_COLORS = 43300,
    ITEM_TABARD_OF_THE_EXPLORER = 43348,

    SPELL_TABARD_OF_THE_BLOOD_KNIGHT = 54974,
    SPELL_TABARD_OF_THE_HAND = 54976,
    SPELL_GREEN_TROPHY_TABARD_OF_THE_ILLIDARI = 54977,
    SPELL_PURPLE_TROPHY_TABARD_OF_THE_ILLIDARI = 54982,
    SPELL_TABARD_OF_THE_ACHIEVER = 55006,
    SPELL_TABARD_OF_THE_PROTECTOR = 55008,
    SPELL_LOREMASTERS_COLORS = 58194,
    SPELL_TABARD_OF_THE_EXPLORER = 58224,
    SPELL_TABARD_OF_SUMMER_SKIES = 62768,
    SPELL_TABARD_OF_SUMMER_FLAMES = 62769
};

#define GOSSIP_LOST_TABARD_OF_BLOOD_KNIGHT "I've lost my Tabard of Blood Knight."
#define GOSSIP_LOST_TABARD_OF_THE_HAND "I've lost my Tabard of the Hand."
#define GOSSIP_LOST_TABARD_OF_THE_PROTECTOR "I've lost my Tabard of the Protector."
#define GOSSIP_LOST_GREEN_TROPHY_TABARD_OF_THE_ILLIDARI "I've lost my Green Trophy Tabard of the Illidari."
#define GOSSIP_LOST_PURPLE_TROPHY_TABARD_OF_THE_ILLIDARI "I've lost my Purple Trophy Tabard of the Illidari."
#define GOSSIP_LOST_TABARD_OF_SUMMER_SKIES "I've lost my Tabard of Summer Skies."
#define GOSSIP_LOST_TABARD_OF_SUMMER_FLAMES "I've lost my Tabard of Summer Flames."
#define GOSSIP_LOST_LOREMASTERS_COLORS "I've lost my Loremaster's Colors."
#define GOSSIP_LOST_TABARD_OF_THE_EXPLORER "I've lost my Tabard of the Explorer."
#define GOSSIP_LOST_TABARD_OF_THE_ACHIEVER "I've lost my Tabard of the Achiever."

class npc_tabard_vendor : public CreatureScript
{
public:
    npc_tabard_vendor() : CreatureScript("npc_tabard_vendor") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        bool m_bLostBloodKnight = false;
        bool m_bLostHand = false;
        bool m_bLostProtector = false;
        bool m_bLostIllidari = false;
        bool m_bLostSummer = false;

        //Tabard of the Blood Knight
        if (player->GetQuestRewardStatus(QUEST_TRUE_MASTERS_OF_LIGHT) && !player->HasItemCount(ITEM_TABARD_OF_THE_BLOOD_KNIGHT, 1, true))
            m_bLostBloodKnight = true;

        //Tabard of the Hand
        if (player->GetQuestRewardStatus(QUEST_THE_UNWRITTEN_PROPHECY) && !player->HasItemCount(ITEM_TABARD_OF_THE_HAND, 1, true))
            m_bLostHand = true;

        //Tabard of the Protector
        if (player->GetQuestRewardStatus(QUEST_INTO_THE_BREACH) && !player->HasItemCount(ITEM_TABARD_OF_THE_PROTECTOR, 1, true))
            m_bLostProtector = true;

        //Green Trophy Tabard of the Illidari
        //Purple Trophy Tabard of the Illidari
        if (player->GetQuestRewardStatus(QUEST_BATTLE_OF_THE_CRIMSON_WATCH) &&
            (!player->HasItemCount(ITEM_GREEN_TROPHY_TABARD_OF_THE_ILLIDARI, 1, true) &&
            !player->HasItemCount(ITEM_PURPLE_TROPHY_TABARD_OF_THE_ILLIDARI, 1, true) &&
            !player->HasItemCount(ITEM_OFFERING_OF_THE_SHATAR, 1, true)))
            m_bLostIllidari = true;

        //Tabard of Summer Skies
        //Tabard of Summer Flames
        if (player->GetQuestRewardStatus(QUEST_SHARDS_OF_AHUNE) &&
            !player->HasItemCount(ITEM_TABARD_OF_THE_SUMMER_SKIES, 1, true) &&
            !player->HasItemCount(ITEM_TABARD_OF_THE_SUMMER_FLAMES, 1, true))
            m_bLostSummer = true;

        if (m_bLostBloodKnight || m_bLostHand || m_bLostProtector || m_bLostIllidari || m_bLostSummer)
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);

            if (m_bLostBloodKnight)
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LOST_TABARD_OF_BLOOD_KNIGHT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF +1);

            if (m_bLostHand)
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LOST_TABARD_OF_THE_HAND, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF +2);

            if (m_bLostProtector)
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LOST_TABARD_OF_THE_PROTECTOR, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);

            if (m_bLostIllidari)
            {
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LOST_GREEN_TROPHY_TABARD_OF_THE_ILLIDARI, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+4);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LOST_PURPLE_TROPHY_TABARD_OF_THE_ILLIDARI, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+5);
            }

            if (m_bLostSummer)
            {
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LOST_TABARD_OF_SUMMER_SKIES, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+6);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LOST_TABARD_OF_SUMMER_FLAMES, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+7);
            }

            player->SEND_GOSSIP_MENU(13583, creature->GetGUID());
        }
        else
            player->GetSession()->SendListInventory(creature->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();
        switch(uiAction)
        {
            case GOSSIP_ACTION_TRADE:
                player->GetSession()->SendListInventory(creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+1:
                player->CLOSE_GOSSIP_MENU();
                player->CastSpell(player, SPELL_TABARD_OF_THE_BLOOD_KNIGHT, false);
                break;
            case GOSSIP_ACTION_INFO_DEF+2:
                player->CLOSE_GOSSIP_MENU();
                player->CastSpell(player, SPELL_TABARD_OF_THE_HAND, false);
                break;
            case GOSSIP_ACTION_INFO_DEF+3:
                player->CLOSE_GOSSIP_MENU();
                player->CastSpell(player, SPELL_TABARD_OF_THE_PROTECTOR, false);
                break;
            case GOSSIP_ACTION_INFO_DEF+4:
                player->CLOSE_GOSSIP_MENU();
                player->CastSpell(player, SPELL_GREEN_TROPHY_TABARD_OF_THE_ILLIDARI, false);
                break;
            case GOSSIP_ACTION_INFO_DEF+5:
                player->CLOSE_GOSSIP_MENU();
                player->CastSpell(player, SPELL_PURPLE_TROPHY_TABARD_OF_THE_ILLIDARI, false);
                break;
            case GOSSIP_ACTION_INFO_DEF+6:
                player->CLOSE_GOSSIP_MENU();
                player->CastSpell(player, SPELL_TABARD_OF_SUMMER_SKIES, false);
                break;
            case GOSSIP_ACTION_INFO_DEF+7:
                player->CLOSE_GOSSIP_MENU();
                player->CastSpell(player, SPELL_TABARD_OF_SUMMER_FLAMES, false);
                break;
        }
        return true;
    }
};

/*######
## npc_experience
######*/

#define EXP_COST                100000//10 00 00 copper (10golds)
#define GOSSIP_TEXT_EXP         14736
#define GOSSIP_XP_OFF            "I no longer wish to gain experience."
#define GOSSIP_XP_ON           "I wish to start gaining experience again."

class npc_experience : public CreatureScript
{
public:
    npc_experience() : CreatureScript("npc_experience") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_XP_OFF, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_XP_ON, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
        player->PlayerTalkClass->SendGossipMenu(GOSSIP_TEXT_EXP, creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*uiSender*/, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();
        bool noXPGain = player->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_NO_XP_GAIN);
        bool doSwitch = false;

        switch(uiAction)
        {
            case GOSSIP_ACTION_INFO_DEF + 1://xp off
                {
                    if (!noXPGain)//does gain xp
                        doSwitch = true;//switch to don't gain xp
                }
                break;
            case GOSSIP_ACTION_INFO_DEF + 2://xp on
                {
                    if (noXPGain)//doesn't gain xp
                        doSwitch = true;//switch to gain xp
                }
                break;
        }
        if (doSwitch)
        {
            if (!player->HasEnoughMoney(EXP_COST))
                player->SendBuyError(BUY_ERR_NOT_ENOUGHT_MONEY, 0, 0, 0);
            else if (noXPGain)
            {
                player->ModifyMoney(-EXP_COST);
                player->RemoveFlag(PLAYER_FLAGS, PLAYER_FLAGS_NO_XP_GAIN);
            }
            else if (!noXPGain)
            {
                player->ModifyMoney(-EXP_COST);
                player->SetFlag(PLAYER_FLAGS, PLAYER_FLAGS_NO_XP_GAIN);
            }
        }
        player->PlayerTalkClass->SendCloseGossip();
        return true;
    }
};

void AddSC_npcs_special()
{
    // Eigene
    new npc_flugmeister;
    new npc_flugmeister_adds;
    new npc_hati;
    new npc_uwom_firecaller;
    new npc_uwom_gm_pimper;
    new npc_uwom_user_pimper;

    // Trinity
    new npc_air_force_bots;
    new npc_lunaclaw_spirit;
    new npc_chicken_cluck;
    new npc_dancing_flames;
    new npc_doctor;
    new npc_injured_patient;
    new npc_garments_of_quests;
    new npc_kingdom_of_dalaran_quests;
    new npc_mount_vendor;
    new npc_rogue_trainer;
    new npc_sayge;
    new npc_steam_tonk;
    new npc_tonk_mine;
    new npc_winter_reveler;
    new npc_brewfest_reveler;
    new npc_snake_trap;
    new npc_mirror_image;
    new npc_ebon_gargoyle;
    new npc_lightwell;
    new mob_mojo;
    new npc_training_dummy;
    new npc_shadowfiend;
    new npc_wormhole;
    new npc_pet_trainer;
    new npc_locksmith;
    new npc_tabard_vendor;
    new npc_experience;
}

