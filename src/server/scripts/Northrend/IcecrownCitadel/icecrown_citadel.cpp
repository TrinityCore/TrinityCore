/*
 * Copyright (C) 2008-2011 by WarHead - United Worlds of MaNGOS - http://www.uwom.de
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

// Weekly quest support
// * Deprogramming                (DONE)
// * Securing the Ramparts        (DONE)
// * Residue Rendezvous           (DONE)
// * Blood Quickening             (DONE)
// * Respite for a Tormented Soul

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "SpellAuraEffects.h"
#include "SmartAI.h"
#include "icecrown_citadel.h"
#include "CreatureGroups.h"

enum TODESGEWEIHTER_WAECHTER_POS
{
    TODESGEWEIHTER_WAECHTER_Y_FALLE_1 = 2137, // guid 200987 - x,y -194.007f,2137.95f
    TODESGEWEIHTER_WAECHTER_Y_FALLE_2 = 2290, // guid 201043 - x,y -193.786f,2290.22f
    TODESGEWEIHTER_WAECHTER_Y_FALLE_3 = 2242, // guid 201130 - x,y -300.354f,2242.18f
    TODESGEWEIHTER_WAECHTER_Y_FALLE_4 = 2182  // guid 201108 - x,y -300.566,2182.6f
};

enum eFALLEN_ADDS_WEG_INDEX
{
    SPAWNPUNKT = 0,
    HOME // 10 Sek. hier warten, dann Wegpunkte ablaufen!
};

// Wegpunkte für den Spawn der Adds aus den Fallen GO_SPIRIT_ALARM_5 + GO_SPIRIT_ALARM_6
const Position FallenAddsWegPunkte[2] =
{
    { 4360.740234f, 2982.070068f, 360.593994f, 0 },
    { 4357.551758f, 3023.074463f, 360.518707f, 1.539818f },
};

enum ICC_RAID_TRASH_NPCS_UND_SPELLS
{
        DIE_VERDAMMTEN                                                  = 37011,
        DIE_VERDAMMTEN_KNOCHENWIRBEL                                    = 70960,
        DIE_VERDAMMTEN_ZERSCHMETTERTE_KNOCHEN                           = 70961,

        DIENER_DES_THRONS                                               = 36724,
        DIENER_DES_THRONS_GLETSCHEREXPLOSION                            = 71029,

        TODESGEWEIHTER_WAECHTER                                         = 37007,
        TODESGEWEIHTER_WAECHTER_SAEBELHIEB                              = 71021,
        TODESGEWEIHTER_WAECHTER_UNTERBRECHENDER_SCHREI                  = 71022,
        TODESGEWEIHTER_WAECHTER_STEINGESTALT                            = 70733,

        URALTER_SKELETT_SOLDAT                                          = 37012,
        URALTER_SKELETT_SOLDAT_SCHILDHIEB                               = 70964,

        BRUTHUETER_DER_NERUBAR                                          = 36725,
        BRUTHUETER_DER_NERUBAR_DUNKLE_BESSERUNG                         = 71020,
        BRUTHUETER_DER_NERUBAR_FANGNETZ                                 = 70980,
        BRUTHUETER_DER_NERUBAR_GRUFTSKARABAEEN                          = 70965,

        AUFERSTANDENER_DIENER_DER_TODESSPRECHER                         = 36844,
        AUFERSTANDENER_DIENER_DER_TODESSPRECHER_VERZEHRENDE_SCHATTEN    = 69405,
#define AUFERSTANDENER_DIENER_DER_TODESSPRECHER_CHAOSBLITZ              RAID_MODE(69576,71108,69576,71108)
#define AUFERSTANDENER_DIENER_DER_TODESSPRECHER_FLUCH_DER_PEIN          RAID_MODE(69404,71112,69404,71112)

        ZELOT_DER_TODESSPRECHER                                         = 36808,
        ZELOT_DER_TODESSPRECHER_SCHATTENSPALTEN                         = 69492,

        DIENER_DER_TODESSPRECHER                                        = 36805,
        DIENER_DER_TODESSPRECHER_VERZEHRENDE_SCHATTEN                   = 69405,
#define DIENER_DER_TODESSPRECHER_CHAOSBLITZ                             RAID_MODE(69576,71108,69576,71108)
#define DIENER_DER_TODESSPRECHER_FLUCH_DER_PEIN                         RAID_MODE(69404,71112,69404,71112)

        JUENGER_DER_TODESSPRECHER                                       = 36807,
        JUENGER_DER_TODESSPRECHER_DUNKLER_SEGEN                         = 69391,
        JUENGER_DER_TODESSPRECHER_SCHATTENBLITZ                         = 69387,
#define JUENGER_DER_TODESSPRECHER_SCHATTENHEILUNG                       RAID_MODE(69389,71107,69389,71107)

        KNECHT_DER_TODESSPRECHER                                        = 36811,
        KNECHT_DER_TODESSPRECHER_SCHATTENBLITZ                          = 69387,
#define KNECHT_DER_TODESSPRECHER_SCHATTENNOVA                           RAID_MODE(69355,71106,69355,71106)

        HOHEPRIESTER_DER_TODESSPRECHER                                  = 36829,
        HOHEPRIESTER_DER_TODESSPRECHER_AURA_DER_DUNKELHEIT              = 69491,
        HOHEPRIESTER_DER_TODESSPRECHER_DUNKLE_ABRECHNUNG                = 69483,

        BOTIN_DER_VALKYR                                                = 37098,
#define BOTIN_DER_VALKYR_ABGETRENNTE_ESSENZ                             RAID_MODE(71906,71942,71906,71942)

        VERSEUCHTE_MONSTROSITAET                                        = 37022,
        VERSEUCHTE_MONSTROSITAET_GEISSELHAKEN                           = 71140,
        VERSEUCHTE_MONSTROSITAET_SEUCHENWOLKE                           = 71150,
        VERSEUCHTE_MONSTROSITAET_SPALTEN                                = 40504,

        EITERNDER_SCHRECKEN                                             = 10404,
        EITERNDER_SCHRECKEN_SEUCHENBOMBE                                = 71088,
#define EITERNDER_SCHRECKEN_SPRUDELNDER_EITER                           RAID_MODE(71089,71090,71089,71090)

        SEUCHENWISSENSCHAFTLER                                          = 37023,
        SEUCHENWISSENSCHAFTLER_MUTATIONSAUSLOESENDES_SPRAY              = 71103,
        SEUCHENWISSENSCHAFTLER_SEUCHENSCHLAG                            = 73079,
        SEUCHENWISSENSCHAFTLER_SEUCHENSTROM                             = 69871,

        RACHSUECHTIGER_FLEISCHERNTER                                    = 37038,
        RACHSUECHTIGER_FLEISCHERNTER_EINGESPRUNGENER_GESICHTSZERMALMER  = 71164,

        VERWESENDER_KOLOSS                                              = 36880,
#define VERWESENDER_KOLOSS_MASSIVES_STAMPFEN                            RAID_MODE(71114,71115,71114,71115)

        SINISTRER_ERZMAGIER                                             = 37664,
        SINISTRER_ERZMAGIER_ESSENZ_ENTZIEHEN                            = 70299,
        SINISTRER_ERZMAGIER_VERWANDLUNG_SPINNE                          = 70410,
#define SINISTRER_ERZMAGIER_DRUCKWELLE                                  RAID_MODE(70407,71151,70407,71151)
#define SINISTRER_ERZMAGIER_FEUERBALL                                   RAID_MODE(70409,71153,70409,71153)
#define SINISTRER_ERZMAGIER_MAGIE_VERSTAERKEN                           RAID_MODE(70408,72336,70408,72336)

        SINISTRER_ADLIGER                                               = 37663,
        SINISTRER_ADLIGER_ESSENZ_ENTZIEHEN                              = 70299,
        SINISTRER_ADLIGER_KETTEN_DES_SCHATTENS                          = 70645,
#define SINISTRER_ADLIGER_SCHATTENBLITZ                                 RAID_MODE(72960,72961,72960,72961)

        SINISTRER_BLUTRITTER                                            = 37595,
        SINISTRER_BLUTRITTER_ESSENZ_ENTZIEHEN                           = 70299,
        SINISTRER_BLUTRITTER_BLUTSPIEGEL                                = 70450,
        SINISTRER_BLUTRITTER_UNHEILIGER_STOSS                           = 70437,
        SINISTRER_BLUTRITTER_VAMPIRAURA                                 = 71736,

        SINISTRER_BERATER                                               = 37571,
        SINISTRER_BERATER_UMHUELLUNG_DES_SCHUTZES                       = 72065,
        SINISTRER_BERATER_UMHUELLUNG_DES_ZAUBERSCHUTZES                 = 72066,
#define SINISTRER_BERATER_LICHKLATSCHER                                 RAID_MODE(72057,72421,72057,72421)

        SINISTRER_LEUTNANT                                              = 37665,
        SINISTRER_LEUTNANT_VAMPIRFLUCH                                  = 70423,
#define SINISTRER_LEUTNANT_FLEISCHZERREISSEN                            RAID_MODE(70435,71154,70435,71154)

        SINISTRER_TAKTIKER                                              = 37666,
        SINISTRER_TAKTIKER_BLUTENTZUG                                   = 70432,
        SINISTRER_TAKTIKER_UNHEILIGER_STOSS                             = 70437,

        SINISTRER_KOMMANDANT                                            = 37662,
        SINISTRER_KOMMANDANT_SCHLACHTRUF                                = 70750,
#define SINISTRER_KOMMANDANT_VAMPIRANSTURM                              RAID_MODE(70449,71155,70449,71155)

        RASENDE_MONSTROSITAET                                           = 37546,
        RASENDE_MONSTROSITAET_SPALTEN                                   = 70191,
        RASENDE_MONSTROSITAET_WUTANFALL                                 = 70371,

        BASTIONSGARGOYLE                                                = 37544,
        BASTIONSGARGOYLE_GIFT_SPUCKEN                                   = 70189,

        BASTIONSDIENER                                                  = 37545,
        BASTIONSDIENER_GHOULSCHLITZEN                                   = 70396,
        BASTIONSDIENER_KANNIBALISMUS                                    = 70363,

        BASTIONSFROSTWYRM                                               = 37230,
        BASTIONSFROSTWYRM_SPALTEN                                       = 70361,
#define BASTIONSFROSTWYRM_BLIZZARD                                      RAID_MODE(70362,71118,70362,71118)
#define BASTIONSFROSTWYRM_FROSTATEM                                     RAID_MODE(70116,72641,70116,72641)

        TIERFUEHRER_DER_FROSTWAECHTER                                   = 37531,
        TIERFUEHRER_DER_FROSTWAECHTER_WELPEN_BEFEHLIGEN                 = 71357,
#define TIERFUEHRER_DER_FROSTWAECHTER_ERSCHUETTENDER_SCHOCK             RAID_MODE(71337,71338,71337,71338)
};

enum eICC_Raid_Events
{
    EVENT_NONE,
    EVENT_DIENER_DES_THRONS_GLETSCHEREXPLOSION,
    EVENT_TODESGEWEIHTER_WAECHTER_SAEBELHIEB,
    EVENT_TODESGEWEIHTER_WAECHTER_UNTERBRECHENDER_SCHREI,
    EVENT_URALTER_SKELETT_SOLDAT_SCHILDHIEB,
    EVENT_BRUTHUETER_DER_NERUBAR_DUNKLE_BESSERUNG,
    EVENT_BRUTHUETER_DER_NERUBAR_FANGNETZ,
    EVENT_BRUTHUETER_DER_NERUBAR_GRUFTSKARABAEEN,
    EVENT_AUFERSTANDENER_DIENER_DER_TODESSPRECHER_VERZEHRENDE_SCHATTEN,
    EVENT_AUFERSTANDENER_DIENER_DER_TODESSPRECHER_CHAOSBLITZ,
    EVENT_AUFERSTANDENER_DIENER_DER_TODESSPRECHER_FLUCH_DER_PEIN,
    EVENT_ZELOT_DER_TODESSPRECHER_SCHATTENSPALTEN,
    EVENT_DIENER_DER_TODESSPRECHER_VERZEHRENDE_SCHATTEN,
    EVENT_DIENER_DER_TODESSPRECHER_CHAOSBLITZ,
    EVENT_DIENER_DER_TODESSPRECHER_FLUCH_DER_PEIN,
    EVENT_JUENGER_DER_TODESSPRECHER_DUNKLER_SEGEN,
    EVENT_JUENGER_DER_TODESSPRECHER_SCHATTENBLITZ,
    EVENT_JUENGER_DER_TODESSPRECHER_SCHATTENHEILUNG,
    EVENT_KNECHT_DER_TODESSPRECHER_SCHATTENBLITZ,
    EVENT_KNECHT_DER_TODESSPRECHER_SCHATTENNOVA,
    EVENT_HOHEPRIESTER_DER_TODESSPRECHER_DUNKLE_ABRECHNUNG,
    EVENT_BOTIN_DER_VALKYR_ABGETRENNTE_ESSENZ,
    EVENT_VERSEUCHTE_MONSTROSITAET_GEISSELHAKEN,
    EVENT_VERSEUCHTE_MONSTROSITAET_SEUCHENWOLKE,
    EVENT_VERSEUCHTE_MONSTROSITAET_SPALTEN,
    EVENT_EITERNDER_SCHRECKEN_SPRUDELNDER_EITER,
    EVENT_SEUCHENWISSENSCHAFTLER_SEUCHENSTROM,
    EVENT_SEUCHENWISSENSCHAFTLER_MUTATIONSAUSLOESENDES_SPRAY,
    EVENT_SEUCHENWISSENSCHAFTLER_SEUCHENSCHLAG,
    EVENT_RACHSUECHTIGER_FLEISCHERNTER_EINGESPRUNGENER_GESICHTSZERMALMER,
    EVENT_VERWESENDER_KOLOSS_MASSIVES_STAMPFEN,
    EVENT_SINISTRER_ERZMAGIER_VERWANDLUNG_SPINNE,
    EVENT_SINISTRER_ERZMAGIER_DRUCKWELLE,
    EVENT_SINISTRER_ERZMAGIER_FEUERBALL,
    EVENT_SINISTRER_ERZMAGIER_MAGIE_VERSTAERKEN,
    EVENT_SINISTRER_ADLIGER_KETTEN_DES_SCHATTENS,
    EVENT_SINISTRER_ADLIGER_SCHATTENBLITZ,
    EVENT_SINISTRER_BLUTRITTER_BLUTSPIEGEL,
    EVENT_SINISTRER_BLUTRITTER_UNHEILIGER_STOSS,
    EVENT_SINISTRER_BERATER_UMHUELLUNG_DES_SCHUTZES,
    EVENT_SINISTRER_BERATER_UMHUELLUNG_DES_ZAUBERSCHUTZES,
    EVENT_SINISTRER_BERATER_LICHKLATSCHER,
    EVENT_SINISTRER_LEUTNANT_VAMPIRFLUCH,
    EVENT_SINISTRER_LEUTNANT_FLEISCHZERREISSEN,
    EVENT_SINISTRER_TAKTIKER_BLUTENTZUG,
    EVENT_SINISTRER_TAKTIKER_UNHEILIGER_STOSS,
    EVENT_SINISTRER_KOMMANDANT_VAMPIRANSTURM,
    EVENT_RASENDE_MONSTROSITAET_SPALTEN,
    EVENT_BASTIONSGARGOYLE_GIFT_SPUCKEN,
    EVENT_BASTIONSDIENER_GHOULSCHLITZEN,
    EVENT_BASTIONSFROSTWYRM_SPALTEN,
    EVENT_BASTIONSFROSTWYRM_BLIZZARD,
    EVENT_BASTIONSFROSTWYRM_FROSTATEM,
    EVENT_TIERFUEHRER_DER_FROSTWAECHTER_WELPEN_BEFEHLIGEN,
    EVENT_TIERFUEHRER_DER_FROSTWAECHTER_ERSCHUETTENDER_SCHOCK
};

class mob_icc_raid_trash : public CreatureScript
{
public:
    mob_icc_raid_trash() : CreatureScript("mob_icc_raid_trash") { }

    struct mob_icc_raid_trashAI: public ScriptedAI
    {
        mob_icc_raid_trashAI(Creature *c) : ScriptedAI(c)
        {
            switch(me->GetEntry())
            {
                case TODESGEWEIHTER_WAECHTER:
                    if (me->GetMap()->IsDungeon())
                    {
                        me->StopMoving();
                        me->GetMotionMaster()->MoveIdle();
                        me->AddAura(TODESGEWEIHTER_WAECHTER_STEINGESTALT, me);
                    }
                    break;
            }
        }

        EventMap events;

        bool DieVerdammtenKnochenwirbel,
            DieVerdammtenZerschmKnochen,
            EiternderSchreckenBombe,
            RasendeMonstrositaetWut,
            BastionsdienerKannibalismus;

        void Reset()
        {
            DieVerdammtenKnochenwirbel = false;
            DieVerdammtenZerschmKnochen = false;
            EiternderSchreckenBombe = false;
            RasendeMonstrositaetWut = false;
            BastionsdienerKannibalismus = false;

            events.Reset();

            events.ScheduleEvent(EVENT_SEUCHENWISSENSCHAFTLER_SEUCHENSTROM, urand(5000,10000));

            switch(me->GetEntry())
            {
                case SINISTRER_ERZMAGIER:
                case SINISTRER_ADLIGER:
                case SINISTRER_BLUTRITTER:
                    DoCast(SINISTRER_ERZMAGIER_ESSENZ_ENTZIEHEN);
                    break;
                case TODESGEWEIHTER_WAECHTER:
                    if (!me->GetMap()->IsDungeon())
                        me->RemoveAurasDueToSpell(TODESGEWEIHTER_WAECHTER_STEINGESTALT);
                    break;
            }
        }

        void JustReachedHome()
        {
            switch(me->GetEntry())
            {
                case SINISTRER_ERZMAGIER:
                case SINISTRER_ADLIGER:
                case SINISTRER_BLUTRITTER:
                    DoCast(SINISTRER_ERZMAGIER_ESSENZ_ENTZIEHEN);
                    break;
            }
        }

        // Für NPCs die auch Outdoor genutzt werden sollen!
        void MoveInLineOfSight(Unit * who)
        {
            if (!who)
                return;

            if (!me->GetMap()->IsDungeon())
            {
                Unit * pTarget = who;
                // Keine NPCs angreifen, die nicht zu einem Spieler gehören!
                if (who->GetTypeId() == TYPEID_UNIT && !who->GetOwner())
                    return;

                if (pTarget->GetTypeId() == TYPEID_PLAYER)
                    if (pTarget->ToPlayer()->GetSession()->GetSecurity() > SEC_VETERAN) // Nur Spieler angreifen, die keine GMs sind!
                        return;
            }
            ScriptedAI::MoveInLineOfSight(who);
        }

        void DamageTaken(Unit * /*pDoneBy*/, uint32 & uiDamage)
        {
            switch(me->GetEntry())
            {
                case DIE_VERDAMMTEN:
                    if (!DieVerdammtenZerschmKnochen && uiDamage >= me->GetHealth())
                    {
                        DoCast(me, DIE_VERDAMMTEN_ZERSCHMETTERTE_KNOCHEN, true);
                        DieVerdammtenZerschmKnochen = true;
                        uiDamage = 0;
                    }
                    if (!DieVerdammtenKnochenwirbel && me->HealthBelowPctDamaged(urand(25,75), uiDamage))
                    {
                        me->AddAura(DIE_VERDAMMTEN_KNOCHENWIRBEL, me);
                        DieVerdammtenKnochenwirbel = true;
                    }
                    break;
                case EITERNDER_SCHRECKEN:
                    if (!EiternderSchreckenBombe && me->HealthBelowPctDamaged(20, uiDamage))
                    {
                        DoCast(EITERNDER_SCHRECKEN_SEUCHENBOMBE);
                        EiternderSchreckenBombe = true;
                    }
                    break;
                case RASENDE_MONSTROSITAET:
                    if (!RasendeMonstrositaetWut && me->HealthBelowPctDamaged(50, uiDamage))
                    {
                        DoCast(RASENDE_MONSTROSITAET_WUTANFALL);
                        RasendeMonstrositaetWut = true;
                    }
                    break;
                case BASTIONSDIENER:
                    if (!BastionsdienerKannibalismus && me->HealthBelowPctDamaged(50, uiDamage))
                    {
                        DoCastVictim(BASTIONSDIENER_KANNIBALISMUS);
                        BastionsdienerKannibalismus = true;
                    }
                    break;
            }
        }

        void JustDied(Unit* /*killer*/)
        {
            if (InstanceScript* pInstance = me->GetInstanceScript())
                pInstance->SetData(DATA_KILL_CREDIT, Quest_A_Feast_of_Souls);
        }

        void EnterCombat(Unit* who)
        {
            if (!who)
                return;

            events.ScheduleEvent(EVENT_DIENER_DES_THRONS_GLETSCHEREXPLOSION, urand(1000,3000));
            events.ScheduleEvent(EVENT_TODESGEWEIHTER_WAECHTER_SAEBELHIEB, urand(3000,5000));
            events.ScheduleEvent(EVENT_TODESGEWEIHTER_WAECHTER_UNTERBRECHENDER_SCHREI, 10000);
            events.ScheduleEvent(EVENT_URALTER_SKELETT_SOLDAT_SCHILDHIEB, urand(1000,5000));
            events.ScheduleEvent(EVENT_BRUTHUETER_DER_NERUBAR_DUNKLE_BESSERUNG, urand(10000,20000));
            events.ScheduleEvent(EVENT_BRUTHUETER_DER_NERUBAR_FANGNETZ, urand(5000,10000));
            events.ScheduleEvent(EVENT_BRUTHUETER_DER_NERUBAR_GRUFTSKARABAEEN, 1000);
            events.ScheduleEvent(EVENT_AUFERSTANDENER_DIENER_DER_TODESSPRECHER_VERZEHRENDE_SCHATTEN, 1000);
            events.ScheduleEvent(EVENT_AUFERSTANDENER_DIENER_DER_TODESSPRECHER_CHAOSBLITZ, 5000);
            events.ScheduleEvent(EVENT_AUFERSTANDENER_DIENER_DER_TODESSPRECHER_FLUCH_DER_PEIN, 100);
            events.ScheduleEvent(EVENT_ZELOT_DER_TODESSPRECHER_SCHATTENSPALTEN, 3000);
            events.ScheduleEvent(EVENT_DIENER_DER_TODESSPRECHER_VERZEHRENDE_SCHATTEN, 1000);
            events.ScheduleEvent(EVENT_DIENER_DER_TODESSPRECHER_CHAOSBLITZ, 5000);
            events.ScheduleEvent(EVENT_DIENER_DER_TODESSPRECHER_FLUCH_DER_PEIN, 100);
            events.ScheduleEvent(EVENT_JUENGER_DER_TODESSPRECHER_DUNKLER_SEGEN, 100);
            events.ScheduleEvent(EVENT_JUENGER_DER_TODESSPRECHER_SCHATTENBLITZ, urand(1000,3000));
            events.ScheduleEvent(EVENT_JUENGER_DER_TODESSPRECHER_SCHATTENHEILUNG, urand(5000,10000));
            events.ScheduleEvent(EVENT_KNECHT_DER_TODESSPRECHER_SCHATTENBLITZ, 100);
            events.ScheduleEvent(EVENT_KNECHT_DER_TODESSPRECHER_SCHATTENNOVA, urand(5000,10000));
            events.ScheduleEvent(EVENT_HOHEPRIESTER_DER_TODESSPRECHER_DUNKLE_ABRECHNUNG, 5000);
            events.ScheduleEvent(EVENT_BOTIN_DER_VALKYR_ABGETRENNTE_ESSENZ, 10000);
            events.ScheduleEvent(EVENT_VERSEUCHTE_MONSTROSITAET_GEISSELHAKEN, urand(100,5000));
            events.ScheduleEvent(EVENT_VERSEUCHTE_MONSTROSITAET_SEUCHENWOLKE, urand(5000,10000));
            events.ScheduleEvent(EVENT_VERSEUCHTE_MONSTROSITAET_SPALTEN, urand(3000,5000));
            events.ScheduleEvent(EVENT_EITERNDER_SCHRECKEN_SPRUDELNDER_EITER, urand(5000,10000));
            events.ScheduleEvent(EVENT_SEUCHENWISSENSCHAFTLER_MUTATIONSAUSLOESENDES_SPRAY, urand(5000,10000));
            events.ScheduleEvent(EVENT_SEUCHENWISSENSCHAFTLER_SEUCHENSCHLAG, urand(5000,10000));
            events.ScheduleEvent(EVENT_RACHSUECHTIGER_FLEISCHERNTER_EINGESPRUNGENER_GESICHTSZERMALMER, urand(1000,20000));
            events.ScheduleEvent(EVENT_VERWESENDER_KOLOSS_MASSIVES_STAMPFEN, urand(5000,10000));
            events.ScheduleEvent(EVENT_SINISTRER_ERZMAGIER_VERWANDLUNG_SPINNE, urand(5000,10000));
            events.ScheduleEvent(EVENT_SINISTRER_ERZMAGIER_DRUCKWELLE, urand(10000,15000));
            events.ScheduleEvent(EVENT_SINISTRER_ERZMAGIER_FEUERBALL, 1000);
            events.ScheduleEvent(EVENT_SINISTRER_ERZMAGIER_MAGIE_VERSTAERKEN, 100);
            events.ScheduleEvent(EVENT_SINISTRER_ADLIGER_KETTEN_DES_SCHATTENS, 100);
            events.ScheduleEvent(EVENT_SINISTRER_ADLIGER_SCHATTENBLITZ, 1000);
            events.ScheduleEvent(EVENT_SINISTRER_BLUTRITTER_BLUTSPIEGEL, 1000);
            events.ScheduleEvent(EVENT_SINISTRER_BLUTRITTER_UNHEILIGER_STOSS, urand(3000,5000));
            events.ScheduleEvent(EVENT_SINISTRER_BERATER_UMHUELLUNG_DES_SCHUTZES, urand(5000,20000));
            events.ScheduleEvent(EVENT_SINISTRER_BERATER_UMHUELLUNG_DES_ZAUBERSCHUTZES, urand(5000,20000));
            events.ScheduleEvent(EVENT_SINISTRER_BERATER_LICHKLATSCHER, urand(5000,10000));
            events.ScheduleEvent(EVENT_SINISTRER_LEUTNANT_VAMPIRFLUCH, 100);
            events.ScheduleEvent(EVENT_SINISTRER_LEUTNANT_FLEISCHZERREISSEN, urand(3000,5000));
            events.ScheduleEvent(EVENT_SINISTRER_TAKTIKER_BLUTENTZUG, urand(5000,20000));
            events.ScheduleEvent(EVENT_SINISTRER_TAKTIKER_UNHEILIGER_STOSS, urand(3000,5000));
            events.ScheduleEvent(EVENT_SINISTRER_KOMMANDANT_VAMPIRANSTURM, urand(5000,20000));
            events.ScheduleEvent(EVENT_RASENDE_MONSTROSITAET_SPALTEN, urand(5000,8000));
            events.ScheduleEvent(EVENT_BASTIONSGARGOYLE_GIFT_SPUCKEN, urand(100,1000));
            events.ScheduleEvent(EVENT_BASTIONSDIENER_GHOULSCHLITZEN, urand(3000,5000));
            events.ScheduleEvent(EVENT_BASTIONSFROSTWYRM_SPALTEN, urand(3000,5000));
            events.ScheduleEvent(EVENT_BASTIONSFROSTWYRM_BLIZZARD, urand(8000,12000));
            events.ScheduleEvent(EVENT_BASTIONSFROSTWYRM_FROSTATEM, urand(5000,8000));
            events.ScheduleEvent(EVENT_TIERFUEHRER_DER_FROSTWAECHTER_WELPEN_BEFEHLIGEN, urand(5000,10000));
            events.ScheduleEvent(EVENT_TIERFUEHRER_DER_FROSTWAECHTER_ERSCHUETTENDER_SCHOCK, urand(3000,5000));

            switch(me->GetEntry())
            {
                case HOHEPRIESTER_DER_TODESSPRECHER: DoCast(HOHEPRIESTER_DER_TODESSPRECHER_AURA_DER_DUNKELHEIT); break;
                case SINISTRER_BLUTRITTER: DoCast(SINISTRER_BLUTRITTER_VAMPIRAURA); break;
                case SINISTRER_KOMMANDANT: DoCast(SINISTRER_KOMMANDANT_SCHLACHTRUF); break;
                case TODESGEWEIHTER_WAECHTER: me->RemoveAurasDueToSpell(TODESGEWEIHTER_WAECHTER_STEINGESTALT); break;
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
            {
                switch(me->GetEntry())
                {
                    case SEUCHENWISSENSCHAFTLER:
                        events.Update(diff);

                        if (me->HasUnitState(UNIT_STAT_CASTING))
                            return;

                        while (uint32 eventId = events.ExecuteEvent())
                        {
                            if (eventId == EVENT_SEUCHENWISSENSCHAFTLER_SEUCHENSTROM)
                            {
                                // Wird nur auf die Eiternden Schrecken gecastet dieser Spell, und auch nur außerhalb des Kampfes!
                                if (Creature * Schrecken = GetClosestCreatureWithEntry(me, EITERNDER_SCHRECKEN, 80.0f, true))
                                {
                                    me->SetFacing(0, Schrecken);
                                    DoCast(Schrecken->ToUnit(), SEUCHENWISSENSCHAFTLER_SEUCHENSTROM);
                                }
                                events.RescheduleEvent(EVENT_SEUCHENWISSENSCHAFTLER_SEUCHENSTROM, urand(35000,45000));
                            }
                        }
                        break;
                }
                return;
            }

            switch(me->GetEntry())
            {
                // Diese NPC dürfen niemals weiter als bis zur Treppe des Vorraumes folgen!
                case DIE_VERDAMMTEN:
                case DIENER_DES_THRONS:
                case URALTER_SKELETT_SOLDAT:
                case BRUTHUETER_DER_NERUBAR:
                case TODESGEWEIHTER_WAECHTER:
                    if (me->GetPositionX() > -117.0f)
                        me->AI()->EnterEvadeMode();
                    break;
                default:
                    break;
            }

            events.Update(diff);

            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch(me->GetEntry())
                {
                    case DIENER_DES_THRONS:
                        if (eventId == EVENT_DIENER_DES_THRONS_GLETSCHEREXPLOSION)
                        {
                            DoCast(DIENER_DES_THRONS_GLETSCHEREXPLOSION);
                            events.RescheduleEvent(EVENT_DIENER_DES_THRONS_GLETSCHEREXPLOSION, 10000);
                        }
                        break;
                    case TODESGEWEIHTER_WAECHTER:
                        switch(eventId)
                        {
                            case EVENT_TODESGEWEIHTER_WAECHTER_SAEBELHIEB:
                                DoCast(TODESGEWEIHTER_WAECHTER_SAEBELHIEB);
                                events.RescheduleEvent(EVENT_TODESGEWEIHTER_WAECHTER_SAEBELHIEB, urand(5000,8000));
                                break;
                            case EVENT_TODESGEWEIHTER_WAECHTER_UNTERBRECHENDER_SCHREI:
                                DoCast(TODESGEWEIHTER_WAECHTER_UNTERBRECHENDER_SCHREI);
                                events.RescheduleEvent(EVENT_TODESGEWEIHTER_WAECHTER_UNTERBRECHENDER_SCHREI, 20000);
                                break;
                        }
                        break;
                    case URALTER_SKELETT_SOLDAT:
                        if (eventId == EVENT_URALTER_SKELETT_SOLDAT_SCHILDHIEB)
                        {
                            DoCast(URALTER_SKELETT_SOLDAT_SCHILDHIEB);
                            events.RescheduleEvent(EVENT_URALTER_SKELETT_SOLDAT_SCHILDHIEB, urand(5000,8000));
                        }
                        break;
                    case BRUTHUETER_DER_NERUBAR:
                        switch(eventId)
                        {
                            case EVENT_BRUTHUETER_DER_NERUBAR_DUNKLE_BESSERUNG:
                                if (Unit* pTarget = DoSelectLowestHpFriendly(40, 50000))
                                    DoCast(pTarget, BRUTHUETER_DER_NERUBAR_DUNKLE_BESSERUNG, true);
                                else
                                    DoCast(me, BRUTHUETER_DER_NERUBAR_DUNKLE_BESSERUNG, true);
                                events.RescheduleEvent(EVENT_BRUTHUETER_DER_NERUBAR_DUNKLE_BESSERUNG, urand(10000,20000));
                                break;
                            case EVENT_BRUTHUETER_DER_NERUBAR_FANGNETZ:
                                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, me->GetMaxCastRange(), true))
                                    DoCast(pTarget, BRUTHUETER_DER_NERUBAR_FANGNETZ, true);
                                events.RescheduleEvent(EVENT_BRUTHUETER_DER_NERUBAR_FANGNETZ, 10000);
                                break;
                            case EVENT_BRUTHUETER_DER_NERUBAR_GRUFTSKARABAEEN:
                                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, me->GetMaxCastRange(), true))
                                    DoCast(pTarget, BRUTHUETER_DER_NERUBAR_GRUFTSKARABAEEN, true);
                                events.RescheduleEvent(EVENT_BRUTHUETER_DER_NERUBAR_GRUFTSKARABAEEN, urand(10000,15000));
                                break;
                        }
                        break;
                    case AUFERSTANDENER_DIENER_DER_TODESSPRECHER:
                        switch(eventId)
                        {
                            case EVENT_AUFERSTANDENER_DIENER_DER_TODESSPRECHER_VERZEHRENDE_SCHATTEN:
                                DoCast(AUFERSTANDENER_DIENER_DER_TODESSPRECHER_VERZEHRENDE_SCHATTEN);
                                events.RescheduleEvent(EVENT_AUFERSTANDENER_DIENER_DER_TODESSPRECHER_VERZEHRENDE_SCHATTEN, 19000);
                                break;
                            case EVENT_AUFERSTANDENER_DIENER_DER_TODESSPRECHER_CHAOSBLITZ:
                                DoCast(AUFERSTANDENER_DIENER_DER_TODESSPRECHER_CHAOSBLITZ);
                                events.RescheduleEvent(EVENT_AUFERSTANDENER_DIENER_DER_TODESSPRECHER_CHAOSBLITZ, 10000);
                                break;
                            case EVENT_AUFERSTANDENER_DIENER_DER_TODESSPRECHER_FLUCH_DER_PEIN:
                                DoCast(AUFERSTANDENER_DIENER_DER_TODESSPRECHER_FLUCH_DER_PEIN);
                                events.RescheduleEvent(EVENT_AUFERSTANDENER_DIENER_DER_TODESSPRECHER_FLUCH_DER_PEIN, 23000);
                                break;
                        }
                        break;
                    case ZELOT_DER_TODESSPRECHER:
                        if (eventId == EVENT_ZELOT_DER_TODESSPRECHER_SCHATTENSPALTEN)
                        {
                            DoCast(ZELOT_DER_TODESSPRECHER_SCHATTENSPALTEN);
                            events.RescheduleEvent(EVENT_ZELOT_DER_TODESSPRECHER_SCHATTENSPALTEN, urand(6100,8000));
                        }
                        break;
                    case DIENER_DER_TODESSPRECHER:
                        switch(eventId)
                        {
                            case EVENT_DIENER_DER_TODESSPRECHER_VERZEHRENDE_SCHATTEN:
                                DoCast(DIENER_DER_TODESSPRECHER_VERZEHRENDE_SCHATTEN);
                                events.RescheduleEvent(EVENT_DIENER_DER_TODESSPRECHER_VERZEHRENDE_SCHATTEN, 19000);
                                break;
                            case EVENT_DIENER_DER_TODESSPRECHER_CHAOSBLITZ:
                                DoCast(DIENER_DER_TODESSPRECHER_CHAOSBLITZ);
                                events.RescheduleEvent(EVENT_DIENER_DER_TODESSPRECHER_CHAOSBLITZ, 10000);
                                break;
                            case EVENT_DIENER_DER_TODESSPRECHER_FLUCH_DER_PEIN:
                                DoCast(DIENER_DER_TODESSPRECHER_FLUCH_DER_PEIN);
                                events.RescheduleEvent(EVENT_DIENER_DER_TODESSPRECHER_FLUCH_DER_PEIN, 23000);
                                break;
                        }
                        break;
                    case JUENGER_DER_TODESSPRECHER:
                        switch(eventId)
                        {
                            case EVENT_JUENGER_DER_TODESSPRECHER_DUNKLER_SEGEN:
                                if (Unit* pTarget = DoSelectLowestHpFriendly(30, 1))
                                    DoCast(pTarget, JUENGER_DER_TODESSPRECHER_DUNKLER_SEGEN, true);
                                else
                                    DoCast(me, JUENGER_DER_TODESSPRECHER_DUNKLER_SEGEN, true);
                                events.RescheduleEvent(EVENT_JUENGER_DER_TODESSPRECHER_DUNKLER_SEGEN, urand(10000,15000));
                                break;
                            case EVENT_JUENGER_DER_TODESSPRECHER_SCHATTENBLITZ:
                                DoCast(JUENGER_DER_TODESSPRECHER_SCHATTENBLITZ);
                                events.RescheduleEvent(EVENT_JUENGER_DER_TODESSPRECHER_SCHATTENBLITZ, urand(6000,8000));
                                break;
                            case EVENT_JUENGER_DER_TODESSPRECHER_SCHATTENHEILUNG:
                                if (Unit* pTarget = DoSelectLowestHpFriendly(30, 90000))
                                    DoCast(pTarget, JUENGER_DER_TODESSPRECHER_SCHATTENHEILUNG, true);
                                else
                                    DoCast(me, JUENGER_DER_TODESSPRECHER_SCHATTENHEILUNG, true);
                                events.RescheduleEvent(EVENT_JUENGER_DER_TODESSPRECHER_SCHATTENHEILUNG, urand(10000,15000));
                                break;
                        }
                        break;
                    case KNECHT_DER_TODESSPRECHER:
                        switch(eventId)
                        {
                            case EVENT_KNECHT_DER_TODESSPRECHER_SCHATTENBLITZ:
                                DoCast(KNECHT_DER_TODESSPRECHER_SCHATTENBLITZ);
                                events.RescheduleEvent(EVENT_KNECHT_DER_TODESSPRECHER_SCHATTENBLITZ, urand(5000,10000));
                                break;
                            case EVENT_KNECHT_DER_TODESSPRECHER_SCHATTENNOVA:
                                DoCast(KNECHT_DER_TODESSPRECHER_SCHATTENNOVA);
                                events.RescheduleEvent(EVENT_KNECHT_DER_TODESSPRECHER_SCHATTENNOVA, urand(10000,15000));
                                break;
                        }
                        break;
                    case HOHEPRIESTER_DER_TODESSPRECHER:
                        if (eventId == EVENT_HOHEPRIESTER_DER_TODESSPRECHER_DUNKLE_ABRECHNUNG)
                        {
                            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, me->GetMaxCastRange(), true))
                                DoCast(pTarget, HOHEPRIESTER_DER_TODESSPRECHER_DUNKLE_ABRECHNUNG, true);
                            events.RescheduleEvent(EVENT_HOHEPRIESTER_DER_TODESSPRECHER_DUNKLE_ABRECHNUNG, 15000);
                        }
                        break;
                    case BOTIN_DER_VALKYR:
                        if (eventId == EVENT_BOTIN_DER_VALKYR_ABGETRENNTE_ESSENZ)
                        {
                            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(pTarget, BOTIN_DER_VALKYR_ABGETRENNTE_ESSENZ, true);
                            events.RescheduleEvent(EVENT_BOTIN_DER_VALKYR_ABGETRENNTE_ESSENZ, 6000);
                        }
                        break;
                    case VERSEUCHTE_MONSTROSITAET:
                        switch(eventId)
                        {
                            case EVENT_VERSEUCHTE_MONSTROSITAET_GEISSELHAKEN:
                                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                    DoCast(pTarget, VERSEUCHTE_MONSTROSITAET_GEISSELHAKEN, true);
                                events.RescheduleEvent(EVENT_VERSEUCHTE_MONSTROSITAET_GEISSELHAKEN, urand(10000,15000));
                                break;
                            case EVENT_VERSEUCHTE_MONSTROSITAET_SEUCHENWOLKE:
                                DoCast(VERSEUCHTE_MONSTROSITAET_SEUCHENWOLKE);
                                events.RescheduleEvent(EVENT_VERSEUCHTE_MONSTROSITAET_SEUCHENWOLKE, urand(10000,15000));
                                break;
                            case EVENT_VERSEUCHTE_MONSTROSITAET_SPALTEN:
                                DoCast(VERSEUCHTE_MONSTROSITAET_SPALTEN);
                                events.RescheduleEvent(EVENT_VERSEUCHTE_MONSTROSITAET_SPALTEN, urand(3000,5000));
                                break;
                        }
                        break;
                    case EITERNDER_SCHRECKEN:
                        if (eventId == EVENT_EITERNDER_SCHRECKEN_SPRUDELNDER_EITER)
                        {
                            DoCast(EITERNDER_SCHRECKEN_SPRUDELNDER_EITER);
                            events.RescheduleEvent(EVENT_EITERNDER_SCHRECKEN_SPRUDELNDER_EITER, urand(10000,20000));
                        }
                        break;
                    case SEUCHENWISSENSCHAFTLER:
                        switch(eventId)
                        {
                            case EVENT_SEUCHENWISSENSCHAFTLER_MUTATIONSAUSLOESENDES_SPRAY:
                                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, me->GetMaxCastRange(), true))
                                    DoCast(pTarget, SEUCHENWISSENSCHAFTLER_MUTATIONSAUSLOESENDES_SPRAY);
                                events.RescheduleEvent(EVENT_SEUCHENWISSENSCHAFTLER_MUTATIONSAUSLOESENDES_SPRAY, urand(8000,10000));
                                break;
                            case EVENT_SEUCHENWISSENSCHAFTLER_SEUCHENSCHLAG:
                                DoCastVictim(SEUCHENWISSENSCHAFTLER_SEUCHENSCHLAG);
                                events.RescheduleEvent(EVENT_SEUCHENWISSENSCHAFTLER_SEUCHENSCHLAG, urand(5000,10000));
                                break;
                        }
                        break;
                    case RACHSUECHTIGER_FLEISCHERNTER:
                        if (eventId == EVENT_RACHSUECHTIGER_FLEISCHERNTER_EINGESPRUNGENER_GESICHTSZERMALMER)
                        {
                            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1))
                                DoCast(pTarget, RACHSUECHTIGER_FLEISCHERNTER_EINGESPRUNGENER_GESICHTSZERMALMER, true);
                            events.RescheduleEvent(EVENT_RACHSUECHTIGER_FLEISCHERNTER_EINGESPRUNGENER_GESICHTSZERMALMER, urand(10000,20000));
                        }
                        break;
                    case VERWESENDER_KOLOSS:
                        if (eventId == EVENT_VERWESENDER_KOLOSS_MASSIVES_STAMPFEN)
                        {
                            DoCast(VERWESENDER_KOLOSS_MASSIVES_STAMPFEN);
                            events.RescheduleEvent(EVENT_VERWESENDER_KOLOSS_MASSIVES_STAMPFEN, urand(5000,10000));
                        }
                        break;
                    case SINISTRER_ERZMAGIER:
                        switch(eventId)
                        {
                            case EVENT_SINISTRER_ERZMAGIER_VERWANDLUNG_SPINNE:
                                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1, me->GetMaxCastRange(), true))
                                    DoCast(pTarget, SINISTRER_ERZMAGIER_VERWANDLUNG_SPINNE, true);
                                events.RescheduleEvent(EVENT_SINISTRER_ERZMAGIER_VERWANDLUNG_SPINNE, urand(10000,15000));
                                break;
                            case EVENT_SINISTRER_ERZMAGIER_DRUCKWELLE:
                                DoCast(SINISTRER_ERZMAGIER_DRUCKWELLE);
                                events.RescheduleEvent(EVENT_SINISTRER_ERZMAGIER_DRUCKWELLE, urand(10000,15000));
                                break;
                            case EVENT_SINISTRER_ERZMAGIER_FEUERBALL:
                                DoCast(SINISTRER_ERZMAGIER_FEUERBALL);
                                events.RescheduleEvent(EVENT_SINISTRER_ERZMAGIER_FEUERBALL, urand(8000,13000));
                                break;
                            case EVENT_SINISTRER_ERZMAGIER_MAGIE_VERSTAERKEN:
                                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                    DoCast(pTarget, SINISTRER_ERZMAGIER_MAGIE_VERSTAERKEN, true);
                                events.RescheduleEvent(EVENT_SINISTRER_ERZMAGIER_MAGIE_VERSTAERKEN, urand(10000,15000));
                                break;
                        }
                        break;
                    case SINISTRER_ADLIGER:
                        switch(eventId)
                        {
                            case EVENT_SINISTRER_ADLIGER_KETTEN_DES_SCHATTENS:
                                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1, me->GetMaxCastRange(), true))
                                    DoCast(pTarget, SINISTRER_ADLIGER_KETTEN_DES_SCHATTENS, true);
                                events.RescheduleEvent(EVENT_SINISTRER_ADLIGER_KETTEN_DES_SCHATTENS, urand(10000,20000));
                                break;
                            case EVENT_SINISTRER_ADLIGER_SCHATTENBLITZ:
                                DoCast(SINISTRER_ADLIGER_SCHATTENBLITZ);
                                events.RescheduleEvent(EVENT_SINISTRER_ADLIGER_SCHATTENBLITZ, urand(5000,10000));
                                break;
                        }
                        break;
                    case SINISTRER_BLUTRITTER:
                        switch(eventId)
                        {
                            case EVENT_SINISTRER_BLUTRITTER_BLUTSPIEGEL:
                                DoCastVictim(SINISTRER_BLUTRITTER_BLUTSPIEGEL, true);
                                events.RescheduleEvent(EVENT_SINISTRER_BLUTRITTER_BLUTSPIEGEL, urand(10000,20000));
                                break;
                            case EVENT_SINISTRER_BLUTRITTER_UNHEILIGER_STOSS:
                                DoCastVictim(SINISTRER_BLUTRITTER_UNHEILIGER_STOSS, true);
                                events.RescheduleEvent(EVENT_SINISTRER_BLUTRITTER_UNHEILIGER_STOSS, urand(5000,8000));
                                break;
                        }
                        break;
                    case SINISTRER_BERATER:
                        switch(eventId)
                        {
                            case EVENT_SINISTRER_BERATER_UMHUELLUNG_DES_SCHUTZES:
                                if (Unit* pTarget = DoSelectLowestHpFriendly(40, 1))
                                    DoCast(pTarget, SINISTRER_BERATER_UMHUELLUNG_DES_SCHUTZES, true);
                                else
                                    DoCast(me, SINISTRER_BERATER_UMHUELLUNG_DES_SCHUTZES, true);
                                events.RescheduleEvent(EVENT_SINISTRER_BERATER_UMHUELLUNG_DES_SCHUTZES, urand(5000,10000));
                                break;
                            case EVENT_SINISTRER_BERATER_UMHUELLUNG_DES_ZAUBERSCHUTZES:
                                if (Unit* pTarget = DoSelectLowestHpFriendly(40, 1))
                                    DoCast(pTarget, SINISTRER_BERATER_UMHUELLUNG_DES_ZAUBERSCHUTZES, true);
                                else
                                    DoCast(me, SINISTRER_BERATER_UMHUELLUNG_DES_ZAUBERSCHUTZES, true);
                                events.RescheduleEvent(EVENT_SINISTRER_BERATER_UMHUELLUNG_DES_ZAUBERSCHUTZES, urand(5000,10000));
                                break;
                            case EVENT_SINISTRER_BERATER_LICHKLATSCHER:
                                DoCastVictim(SINISTRER_BERATER_LICHKLATSCHER, true);
                                events.RescheduleEvent(EVENT_SINISTRER_BERATER_LICHKLATSCHER, urand(5000,10000));
                                break;
                        }
                        break;
                    case SINISTRER_LEUTNANT:
                        switch(eventId)
                        {
                            case EVENT_SINISTRER_LEUTNANT_VAMPIRFLUCH:
                                DoCastVictim(SINISTRER_LEUTNANT_VAMPIRFLUCH, true);
                                events.RescheduleEvent(EVENT_SINISTRER_LEUTNANT_VAMPIRFLUCH, urand(10000,20000));
                                break;
                            case EVENT_SINISTRER_LEUTNANT_FLEISCHZERREISSEN:
                                DoCastVictim(SINISTRER_LEUTNANT_FLEISCHZERREISSEN, true);
                                events.RescheduleEvent(EVENT_SINISTRER_LEUTNANT_FLEISCHZERREISSEN, urand(5000,10000));
                                break;
                        }
                        break;
                    case SINISTRER_TAKTIKER:
                        switch(eventId)
                        {
                            case EVENT_SINISTRER_TAKTIKER_BLUTENTZUG:
                                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1))
                                    DoCast(pTarget, SINISTRER_TAKTIKER_BLUTENTZUG, true);
                                events.RescheduleEvent(EVENT_SINISTRER_TAKTIKER_BLUTENTZUG, urand(5000,20000));
                                break;
                            case EVENT_SINISTRER_TAKTIKER_UNHEILIGER_STOSS:
                                DoCastVictim(SINISTRER_TAKTIKER_UNHEILIGER_STOSS, true);
                                events.RescheduleEvent(EVENT_SINISTRER_TAKTIKER_UNHEILIGER_STOSS, urand(3000,5000));
                                break;
                        }
                        break;
                    case SINISTRER_KOMMANDANT:
                        if (eventId == EVENT_SINISTRER_KOMMANDANT_VAMPIRANSTURM)
                        {
                            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1))
                                DoCast(pTarget, SINISTRER_KOMMANDANT_VAMPIRANSTURM, true);
                            events.RescheduleEvent(EVENT_SINISTRER_KOMMANDANT_VAMPIRANSTURM, urand(8000,12000));
                        }
                        break;
                    case RASENDE_MONSTROSITAET:
                        if (eventId == EVENT_RASENDE_MONSTROSITAET_SPALTEN)
                            DoCastVictim(RASENDE_MONSTROSITAET_SPALTEN);
                        events.RescheduleEvent(EVENT_RASENDE_MONSTROSITAET_SPALTEN, urand(5000,8000));
                        break;
                    case BASTIONSGARGOYLE:
                        if (eventId == EVENT_BASTIONSGARGOYLE_GIFT_SPUCKEN)
                            DoCastVictim(BASTIONSGARGOYLE_GIFT_SPUCKEN);
                        events.RescheduleEvent(EVENT_BASTIONSGARGOYLE_GIFT_SPUCKEN, urand(3000,5000));
                        break;
                    case BASTIONSDIENER:
                        if (eventId == EVENT_BASTIONSDIENER_GHOULSCHLITZEN)
                            DoCastVictim(BASTIONSDIENER_GHOULSCHLITZEN);
                        events.RescheduleEvent(EVENT_BASTIONSDIENER_GHOULSCHLITZEN, urand(3000,5000));
                        break;
                    case BASTIONSFROSTWYRM:
                        switch(eventId)
                        {
                            case EVENT_BASTIONSFROSTWYRM_SPALTEN:
                                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_INTERRUPT, true);
                                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_INTERRUPT_CAST, true);
                                DoCastVictim(BASTIONSFROSTWYRM_SPALTEN);
                                events.RescheduleEvent(EVENT_BASTIONSFROSTWYRM_SPALTEN, urand(3000,5000));
                                break;
                            case EVENT_BASTIONSFROSTWYRM_BLIZZARD:
                                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_INTERRUPT, false);
                                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_INTERRUPT_CAST, false);
                                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                    DoCast(pTarget, BASTIONSFROSTWYRM_BLIZZARD, true);
                                events.RescheduleEvent(EVENT_BASTIONSFROSTWYRM_BLIZZARD, urand(8000,12000));
                                break;
                            case EVENT_BASTIONSFROSTWYRM_FROSTATEM:
                                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_INTERRUPT, true);
                                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_INTERRUPT_CAST, true);
                                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1))
                                    DoCast(pTarget, BASTIONSFROSTWYRM_FROSTATEM, true);
                                events.RescheduleEvent(EVENT_BASTIONSFROSTWYRM_FROSTATEM, urand(8000,12000));
                                break;
                        }
                        break;
                    case TIERFUEHRER_DER_FROSTWAECHTER:
                        switch(eventId)
                        {
                            case EVENT_TIERFUEHRER_DER_FROSTWAECHTER_WELPEN_BEFEHLIGEN:
                                DoCast(TIERFUEHRER_DER_FROSTWAECHTER_WELPEN_BEFEHLIGEN);
                                events.RescheduleEvent(EVENT_TIERFUEHRER_DER_FROSTWAECHTER_WELPEN_BEFEHLIGEN, urand(8000,12000));
                                break;
                            case EVENT_TIERFUEHRER_DER_FROSTWAECHTER_ERSCHUETTENDER_SCHOCK:
                                DoCast(TIERFUEHRER_DER_FROSTWAECHTER_ERSCHUETTENDER_SCHOCK);
                                events.RescheduleEvent(EVENT_TIERFUEHRER_DER_FROSTWAECHTER_ERSCHUETTENDER_SCHOCK, urand(8000,12000));
                                break;
                        }
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_icc_raid_trashAI(pCreature);
    }
};

enum Texts
{
    // Highlord Tirion Fordring (at Light's Hammer)
    SAY_TIRION_INTRO_1              = 0,
    SAY_TIRION_INTRO_2              = 1,
    SAY_TIRION_INTRO_3              = 2,
    SAY_TIRION_INTRO_4              = 3,
    SAY_TIRION_INTRO_H_5            = 4,
    SAY_TIRION_INTRO_A_5            = 5,

    // The Lich King (at Light's Hammer)
    SAY_LK_INTRO_1                  = 0,
    SAY_LK_INTRO_2                  = 1,
    SAY_LK_INTRO_3                  = 2,
    SAY_LK_INTRO_4                  = 3,
    SAY_LK_INTRO_5                  = 4,

    // Highlord Bolvar Fordragon (at Light's Hammer)
    SAY_BOLVAR_INTRO_1              = 0,

    // High Overlord Saurfang (at Light's Hammer)
    SAY_SAURFANG_INTRO_1            = 15,
    SAY_SAURFANG_INTRO_2            = 16,
    SAY_SAURFANG_INTRO_3            = 17,
    SAY_SAURFANG_INTRO_4            = 18,

    // Muradin Bronzebeard (at Light's Hammer)
    SAY_MURADIN_INTRO_1             = 13,
    SAY_MURADIN_INTRO_2             = 14,
    SAY_MURADIN_INTRO_3             = 15,

    // Deathbound Ward
    SAY_TRAP_ACTIVATE               = 0,

    // Rotting Frost Giant
    EMOTE_DEATH_PLAGUE_WARNING      = 0,

    // Sister Svalna
    SAY_SVALNA_KILL_CAPTAIN         = 1, // happens when she kills a captain
    SAY_SVALNA_KILL                 = 4,
    SAY_SVALNA_CAPTAIN_DEATH        = 5, // happens when a captain resurrected by her dies
    SAY_SVALNA_DEATH                = 6,
    EMOTE_SVALNA_IMPALE             = 7,
    EMOTE_SVALNA_BROKEN_SHIELD      = 8,

    SAY_CROK_INTRO_1                = 0, // Ready your arms, my Argent Brothers. The Vrykul will protect the Frost Queen with their lives.
    SAY_ARNATH_INTRO_2              = 5, // Even dying here beats spending another day collecting reagents for that madman, Finklestein.
    SAY_CROK_INTRO_3                = 1, // Enough idle banter! Our champions have arrived - support them as we push our way through the hall!
    SAY_SVALNA_EVENT_START          = 0, // You may have once fought beside me, Crok, but now you are nothing more than a traitor. Come, your second death approaches!
    SAY_CROK_COMBAT_WP_0            = 2, // Draw them back to us, and we'll assist you.
    SAY_CROK_COMBAT_WP_1            = 3, // Quickly, push on!
    SAY_CROK_FINAL_WP               = 4, // Her reinforcements will arrive shortly, we must bring her down quickly!
    SAY_SVALNA_RESURRECT_CAPTAINS   = 2, // Foolish Crok. You brought my reinforcements with you. Arise, Argent Champions, and serve the Lich King in death!
    SAY_CROK_COMBAT_SVALNA          = 5, // I'll draw her attacks. Return our brothers to their graves, then help me bring her down!
    SAY_SVALNA_AGGRO                = 3, // Come, Scourgebane. I'll show the master which of us is truly worthy of the title of "Champion"!
    SAY_CAPTAIN_DEATH               = 0,
    SAY_CAPTAIN_RESURRECTED         = 1,
    SAY_CAPTAIN_KILL                = 2,
    SAY_CAPTAIN_SECOND_DEATH        = 3,
    SAY_CAPTAIN_SURVIVE_TALK        = 4,
    SAY_CROK_WEAKENING_GAUNTLET     = 6,
    SAY_CROK_WEAKENING_SVALNA       = 7,
    SAY_CROK_DEATH                  = 8,
};

enum Spells
{
    // Rotting Frost Giant
    SPELL_DEATH_PLAGUE              = 72879,
    SPELL_DEATH_PLAGUE_AURA         = 72865,
    SPELL_RECENTLY_INFECTED         = 72884,
    SPELL_DEATH_PLAGUE_KILL         = 72867,
    SPELL_STOMP                     = 64652,
    SPELL_ARCTIC_BREATH             = 72848,

    // Frost Freeze Trap
    SPELL_COLDFLAME_JETS            = 70460,

    // Alchemist Adrianna
    SPELL_HARVEST_BLIGHT_SPECIMEN   = 72155,
    SPELL_HARVEST_BLIGHT_SPECIMEN25 = 72162,

    // Crok Scourgebane
    SPELL_ICEBOUND_ARMOR            = 70714,
    SPELL_SCOURGE_STRIKE            = 71488,
    SPELL_DEATH_STRIKE              = 71489,

    // Sister Svalna
    SPELL_CARESS_OF_DEATH           = 70078,
    SPELL_IMPALING_SPEAR_KILL       = 70196,
    SPELL_REVIVE_CHAMPION           = 70053,
    SPELL_UNDEATH                   = 70089,
    SPELL_IMPALING_SPEAR            = 71443,
    SPELL_AETHER_SHIELD             = 71463,
    SPELL_HURL_SPEAR                = 71466,

    // Captain Arnath
    SPELL_DOMINATE_MIND             = 14515,
    SPELL_FLASH_HEAL_NORMAL         = 71595,
    SPELL_POWER_WORD_SHIELD_NORMAL  = 71548,
    SPELL_SMITE_NORMAL              = 71546,
    SPELL_FLASH_HEAL_UNDEAD         = 71782,
    SPELL_POWER_WORD_SHIELD_UNDEAD  = 71780,
    SPELL_SMITE_UNDEAD              = 71778,

    // Captain Brandon
    SPELL_CRUSADER_STRIKE           = 71549,
    SPELL_DIVINE_SHIELD             = 71550,
    SPELL_JUDGEMENT_OF_COMMAND      = 71551,
    SPELL_HAMMER_OF_BETRAYAL        = 71784,

    // Captain Grondel
    SPELL_CHARGE                    = 71553,
    SPELL_MORTAL_STRIKE             = 71552,
    SPELL_SUNDER_ARMOR              = 71554,
    SPELL_CONFLAGRATION             = 71785,

    // Captain Rupert
    SPELL_FEL_IRON_BOMB_NORMAL      = 71592,
    SPELL_MACHINE_GUN_NORMAL        = 71594,
    SPELL_ROCKET_LAUNCH_NORMAL      = 71590,
    SPELL_FEL_IRON_BOMB_UNDEAD      = 71787,
    SPELL_MACHINE_GUN_UNDEAD        = 71788,
    SPELL_ROCKET_LAUNCH_UNDEAD      = 71786,
};

// Helper defines
// Captain Arnath
#define SPELL_FLASH_HEAL        (IsUndead ? SPELL_FLASH_HEAL_UNDEAD : SPELL_FLASH_HEAL_NORMAL)
#define SPELL_POWER_WORD_SHIELD (IsUndead ? SPELL_POWER_WORD_SHIELD_UNDEAD : SPELL_POWER_WORD_SHIELD_NORMAL)
#define SPELL_SMITE             (IsUndead ? SPELL_SMITE_UNDEAD : SPELL_SMITE_NORMAL)

// Captain Rupert
#define SPELL_FEL_IRON_BOMB     (IsUndead ? SPELL_FEL_IRON_BOMB_UNDEAD : SPELL_FEL_IRON_BOMB_NORMAL)
#define SPELL_MACHINE_GUN       (IsUndead ? SPELL_MACHINE_GUN_UNDEAD : SPELL_MACHINE_GUN_NORMAL)
#define SPELL_ROCKET_LAUNCH     (IsUndead ? SPELL_ROCKET_LAUNCH_UNDEAD : SPELL_ROCKET_LAUNCH_NORMAL)

enum EventTypes
{
    // Highlord Tirion Fordring (at Light's Hammer)
    // The Lich King (at Light's Hammer)
    // Highlord Bolvar Fordragon (at Light's Hammer)
    // High Overlord Saurfang (at Light's Hammer)
    // Muradin Bronzebeard (at Light's Hammer)
    EVENT_TIRION_INTRO_2                = 1,
    EVENT_TIRION_INTRO_3                = 2,
    EVENT_TIRION_INTRO_4                = 3,
    EVENT_TIRION_INTRO_5                = 4,
    EVENT_LK_INTRO_1                    = 5,
    EVENT_TIRION_INTRO_6                = 6,
    EVENT_LK_INTRO_2                    = 7,
    EVENT_LK_INTRO_3                    = 8,
    EVENT_LK_INTRO_4                    = 9,
    EVENT_BOLVAR_INTRO_1                = 10,
    EVENT_LK_INTRO_5                    = 11,
    EVENT_SAURFANG_INTRO_1              = 12,
    EVENT_TIRION_INTRO_H_7              = 13,
    EVENT_SAURFANG_INTRO_2              = 14,
    EVENT_SAURFANG_INTRO_3              = 15,
    EVENT_SAURFANG_INTRO_4              = 16,
    EVENT_SAURFANG_RUN                  = 17,
    EVENT_MURADIN_INTRO_1               = 18,
    EVENT_MURADIN_INTRO_2               = 19,
    EVENT_MURADIN_INTRO_3               = 20,
    EVENT_TIRION_INTRO_A_7              = 21,
    EVENT_MURADIN_INTRO_4               = 22,
    EVENT_MURADIN_INTRO_5               = 23,
    EVENT_MURADIN_RUN                   = 24,

    // Rotting Frost Giant
    EVENT_DEATH_PLAGUE                  = 25,
    EVENT_STOMP                         = 26,
    EVENT_ARCTIC_BREATH                 = 27,

    // Frost Freeze Trap
    EVENT_ACTIVATE_TRAP                 = 28,

    // Crok Scourgebane
    EVENT_SCOURGE_STRIKE                = 29,
    EVENT_DEATH_STRIKE                  = 30,
    EVENT_HEALTH_CHECK                  = 31,
    EVENT_CROK_INTRO_3                  = 32,
    EVENT_START_PATHING                 = 33,

    // Sister Svalna
    EVENT_ARNATH_INTRO_2                = 34,
    EVENT_SVALNA_START                  = 35,
    EVENT_SVALNA_RESURRECT              = 36,
    EVENT_SVALNA_COMBAT                 = 37,
    EVENT_IMPALING_SPEAR                = 38,
    EVENT_AETHER_SHIELD                 = 39,

    // Captain Arnath
    EVENT_ARNATH_FLASH_HEAL             = 40,
    EVENT_ARNATH_PW_SHIELD              = 41,
    EVENT_ARNATH_SMITE                  = 42,
    EVENT_ARNATH_DOMINATE_MIND          = 43,

    // Captain Brandon
    EVENT_BRANDON_CRUSADER_STRIKE       = 44,
    EVENT_BRANDON_DIVINE_SHIELD         = 45,
    EVENT_BRANDON_JUDGEMENT_OF_COMMAND  = 46,
    EVENT_BRANDON_HAMMER_OF_BETRAYAL    = 47,

    // Captain Grondel
    EVENT_GRONDEL_CHARGE_CHECK          = 48,
    EVENT_GRONDEL_MORTAL_STRIKE         = 49,
    EVENT_GRONDEL_SUNDER_ARMOR          = 50,
    EVENT_GRONDEL_CONFLAGRATION         = 51,

    // Captain Rupert
    EVENT_RUPERT_FEL_IRON_BOMB          = 52,
    EVENT_RUPERT_MACHINE_GUN            = 53,
    EVENT_RUPERT_ROCKET_LAUNCH          = 54,
};

enum DataTypesICC
{
    DATA_DAMNED_KILLS       = 1,
};

enum Actions
{
    // Sister Svalna
    ACTION_KILL_CAPTAIN         = 1,
    ACTION_START_GAUNTLET       = 2,
    ACTION_RESURRECT_CAPTAINS   = 3,
    ACTION_CAPTAIN_DIES         = 4,
    ACTION_RESET_EVENT          = 5,
};

enum EventIds
{
    EVENT_AWAKEN_WARD_1 = 22900,
    EVENT_AWAKEN_WARD_2 = 22907,
    EVENT_AWAKEN_WARD_3 = 22908,
    EVENT_AWAKEN_WARD_4 = 22909,

    EVENT_RACHSUECHTIGER_FLEISCHERNTER_FALLE_1 = 22869, // GO_SPIRIT_ALARM_5 - Spell 70739
    EVENT_RACHSUECHTIGER_FLEISCHERNTER_FALLE_2 = 22870  // GO_SPIRIT_ALARM_6 - Spell 70740
};

class FrostwingVrykulSearcher
{
    public:
        FrostwingVrykulSearcher(Creature const* source, float range) : _source(source), _range(range) {}

        bool operator()(Unit* unit)
        {
            if (!unit->isAlive())
                return false;

            switch (unit->GetEntry())
            {
                case NPC_YMIRJAR_BATTLE_MAIDEN:
                case NPC_YMIRJAR_DEATHBRINGER:
                case NPC_YMIRJAR_FROSTBINDER:
                case NPC_YMIRJAR_HUNTRESS:
                case NPC_YMIRJAR_WARLORD:
                    break;
                default:
                    return false;
            }

            if (!unit->IsWithinDist(_source, _range, false))
                return false;

            return true;
        }

    private:
        Creature const* _source;
        float _range;
};

class FrostwingGauntletRespawner
{
    public:
        void operator()(Creature* creature)
        {
            switch (creature->GetOriginalEntry())
            {
                case NPC_YMIRJAR_BATTLE_MAIDEN:
                case NPC_YMIRJAR_DEATHBRINGER:
                case NPC_YMIRJAR_FROSTBINDER:
                case NPC_YMIRJAR_HUNTRESS:
                case NPC_YMIRJAR_WARLORD:
                    break;
                case NPC_CROK_SCOURGEBANE:
                case NPC_CAPTAIN_ARNATH:
                case NPC_CAPTAIN_BRANDON:
                case NPC_CAPTAIN_GRONDEL:
                case NPC_CAPTAIN_RUPERT:
                    creature->AI()->DoAction(ACTION_RESET_EVENT);
                    break;
                case NPC_SISTER_SVALNA:
                    creature->AI()->DoAction(ACTION_RESET_EVENT);
                    // return, this creature is never dead if event is reset
                    return;
                default:
                    return;
            }

            uint32 corpseDelay = creature->GetCorpseDelay();
            uint32 respawnDelay = creature->GetRespawnDelay();
            creature->SetCorpseDelay(1);
            creature->SetRespawnDelay(2);

            if (CreatureData const* data = creature->GetCreatureData())
                creature->SetPosition(data->posX, data->posY, data->posZ, data->orientation);
            creature->ForcedDespawn();

            creature->SetCorpseDelay(corpseDelay);
            creature->SetRespawnDelay(respawnDelay);
        }
};

class CaptainSurviveTalk : public BasicEvent
{
    public:
        explicit CaptainSurviveTalk(Creature const& owner) : _owner(owner) { }

        bool Execute(uint64 /*currTime*/, uint32 /*diff*/)
        {
            _owner.AI()->Talk(SAY_CAPTAIN_SURVIVE_TALK);
            return true;
        }

    private:
        Creature const& _owner;
};

// at Light's Hammer
class npc_highlord_tirion_fordring_lh : public CreatureScript
{
    public:
        npc_highlord_tirion_fordring_lh() : CreatureScript("npc_highlord_tirion_fordring_lh") { }

        struct npc_highlord_tirion_fordringAI : public ScriptedAI
        {
            npc_highlord_tirion_fordringAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript())
            {
            }

            void Reset()
            {
                _events.Reset();
                _theLichKing = 0;
                _bolvarFordragon = 0;
                _factionNPC = 0;
                _damnedKills = 0;
            }

            // IMPORTANT NOTE: This is triggered from per-GUID scripts
            // of The Damned SAI
            void SetData(uint32 type, uint32 data)
            {
                if (type == DATA_DAMNED_KILLS && data == 1)
                {
                    if (++_damnedKills == 2)
                    {
                        if (Creature* theLichKing = me->FindNearestCreature(NPC_THE_LICH_KING_LH, 150.0f))
                        {
                            if (Creature* bolvarFordragon = me->FindNearestCreature(NPC_HIGHLORD_BOLVAR_FORDRAGON_LH, 150.0f))
                            {
                                if (Creature* factionNPC = me->FindNearestCreature(_instance->GetData(DATA_TEAM_IN_INSTANCE) == HORDE ? NPC_SE_HIGH_OVERLORD_SAURFANG : NPC_SE_MURADIN_BRONZEBEARD, 50.0f))
                                {
                                    me->setActive(true);
                                    _theLichKing = theLichKing->GetGUID();
                                    theLichKing->setActive(true);
                                    _bolvarFordragon = bolvarFordragon->GetGUID();
                                    bolvarFordragon->setActive(true);
                                    _factionNPC = factionNPC->GetGUID();
                                    factionNPC->setActive(true);
                                }
                            }
                        }

                        if (!_bolvarFordragon || !_theLichKing || !_factionNPC)
                            return;

                        Talk(SAY_TIRION_INTRO_1);
                        _events.ScheduleEvent(EVENT_TIRION_INTRO_2, 4000);
                        _events.ScheduleEvent(EVENT_TIRION_INTRO_3, 14000);
                        _events.ScheduleEvent(EVENT_TIRION_INTRO_4, 18000);
                        _events.ScheduleEvent(EVENT_TIRION_INTRO_5, 31000);
                        _events.ScheduleEvent(EVENT_LK_INTRO_1, 35000);
                        _events.ScheduleEvent(EVENT_TIRION_INTRO_6, 51000);
                        _events.ScheduleEvent(EVENT_LK_INTRO_2, 58000);
                        _events.ScheduleEvent(EVENT_LK_INTRO_3, 74000);
                        _events.ScheduleEvent(EVENT_LK_INTRO_4, 86000);
                        _events.ScheduleEvent(EVENT_BOLVAR_INTRO_1, 100000);
                        _events.ScheduleEvent(EVENT_LK_INTRO_5, 108000);

                        if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == HORDE)
                        {
                            _events.ScheduleEvent(EVENT_SAURFANG_INTRO_1, 120000);
                            _events.ScheduleEvent(EVENT_TIRION_INTRO_H_7, 129000);
                            _events.ScheduleEvent(EVENT_SAURFANG_INTRO_2, 139000);
                            _events.ScheduleEvent(EVENT_SAURFANG_INTRO_3, 150000);
                            _events.ScheduleEvent(EVENT_SAURFANG_INTRO_4, 162000);
                            _events.ScheduleEvent(EVENT_SAURFANG_RUN, 170000);
                        }
                        else
                        {
                            _events.ScheduleEvent(EVENT_MURADIN_INTRO_1, 120000);
                            _events.ScheduleEvent(EVENT_MURADIN_INTRO_2, 124000);
                            _events.ScheduleEvent(EVENT_MURADIN_INTRO_3, 127000);
                            _events.ScheduleEvent(EVENT_TIRION_INTRO_A_7, 136000);
                            _events.ScheduleEvent(EVENT_MURADIN_INTRO_4, 144000);
                            _events.ScheduleEvent(EVENT_MURADIN_INTRO_5, 151000);
                            _events.ScheduleEvent(EVENT_MURADIN_RUN, 157000);
                        }
                    }
                }
            }

            void UpdateAI(uint32 const diff)
            {
                if (_damnedKills != 2)
                    return;

                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_TIRION_INTRO_2:
                            me->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                            break;
                        case EVENT_TIRION_INTRO_3:
                            Talk(SAY_TIRION_INTRO_2);
                            break;
                        case EVENT_TIRION_INTRO_4:
                            me->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                            break;
                        case EVENT_TIRION_INTRO_5:
                            Talk(SAY_TIRION_INTRO_3);
                            break;
                        case EVENT_LK_INTRO_1:
                            me->HandleEmoteCommand(EMOTE_ONESHOT_POINT_NOSHEATHE);
                            if (Creature* theLichKing = ObjectAccessor::GetCreature(*me, _theLichKing))
                                theLichKing->AI()->Talk(SAY_LK_INTRO_1);
                            break;
                        case EVENT_TIRION_INTRO_6:
                            Talk(SAY_TIRION_INTRO_4);
                            break;
                        case EVENT_LK_INTRO_2:
                            if (Creature* theLichKing = ObjectAccessor::GetCreature(*me, _theLichKing))
                                theLichKing->AI()->Talk(SAY_LK_INTRO_2);
                            break;
                        case EVENT_LK_INTRO_3:
                            if (Creature* theLichKing = ObjectAccessor::GetCreature(*me, _theLichKing))
                                theLichKing->AI()->Talk(SAY_LK_INTRO_3);
                            break;
                        case EVENT_LK_INTRO_4:
                            if (Creature* theLichKing = ObjectAccessor::GetCreature(*me, _theLichKing))
                                theLichKing->AI()->Talk(SAY_LK_INTRO_4);
                            break;
                        case EVENT_BOLVAR_INTRO_1:
                            if (Creature* bolvarFordragon = ObjectAccessor::GetCreature(*me, _bolvarFordragon))
                            {
                                bolvarFordragon->AI()->Talk(SAY_BOLVAR_INTRO_1);
                                bolvarFordragon->setActive(false);
                            }
                            break;
                        case EVENT_LK_INTRO_5:
                            if (Creature* theLichKing = ObjectAccessor::GetCreature(*me, _theLichKing))
                            {
                                theLichKing->AI()->Talk(SAY_LK_INTRO_5);
                                theLichKing->setActive(false);
                            }
                            break;
                        case EVENT_SAURFANG_INTRO_1:
                            if (Creature* saurfang = ObjectAccessor::GetCreature(*me, _factionNPC))
                                saurfang->AI()->Talk(SAY_SAURFANG_INTRO_1);
                            break;
                        case EVENT_TIRION_INTRO_H_7:
                            Talk(SAY_TIRION_INTRO_H_5);
                            break;
                        case EVENT_SAURFANG_INTRO_2:
                            if (Creature* saurfang = ObjectAccessor::GetCreature(*me, _factionNPC))
                                saurfang->AI()->Talk(SAY_SAURFANG_INTRO_2);
                            break;
                        case EVENT_SAURFANG_INTRO_3:
                            if (Creature* saurfang = ObjectAccessor::GetCreature(*me, _factionNPC))
                                saurfang->AI()->Talk(SAY_SAURFANG_INTRO_3);
                            break;
                        case EVENT_SAURFANG_INTRO_4:
                            if (Creature* saurfang = ObjectAccessor::GetCreature(*me, _factionNPC))
                                saurfang->AI()->Talk(SAY_SAURFANG_INTRO_4);
                            break;
                        case EVENT_MURADIN_RUN:
                        case EVENT_SAURFANG_RUN:
                            if (Creature* factionNPC = ObjectAccessor::GetCreature(*me, _factionNPC))
                                factionNPC->GetMotionMaster()->MovePath(factionNPC->GetDBTableGUIDLow()*10, false);
                            me->setActive(false);
                            _damnedKills = 3;
                            break;
                        case EVENT_MURADIN_INTRO_1:
                            if (Creature* muradin = ObjectAccessor::GetCreature(*me, _factionNPC))
                                muradin->AI()->Talk(SAY_MURADIN_INTRO_1);
                            break;
                        case EVENT_MURADIN_INTRO_2:
                            if (Creature* muradin = ObjectAccessor::GetCreature(*me, _factionNPC))
                                muradin->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
                            break;
                        case EVENT_MURADIN_INTRO_3:
                            if (Creature* muradin = ObjectAccessor::GetCreature(*me, _factionNPC))
                                muradin->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                            break;
                        case EVENT_TIRION_INTRO_A_7:
                            Talk(SAY_TIRION_INTRO_A_5);
                            break;
                        case EVENT_MURADIN_INTRO_4:
                            if (Creature* muradin = ObjectAccessor::GetCreature(*me, _factionNPC))
                                muradin->AI()->Talk(SAY_MURADIN_INTRO_2);
                            break;
                        case EVENT_MURADIN_INTRO_5:
                            if (Creature* muradin = ObjectAccessor::GetCreature(*me, _factionNPC))
                                muradin->AI()->Talk(SAY_MURADIN_INTRO_3);
                            break;
                        default:
                            break;
                    }
                }
            }

        private:
            EventMap _events;
            InstanceScript* const _instance;
            uint64 _theLichKing;
            uint64 _bolvarFordragon;
            uint64 _factionNPC;
            uint16 _damnedKills;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetIcecrownCitadelAI<npc_highlord_tirion_fordringAI>(creature);
        }
};

class npc_rotting_frost_giant : public CreatureScript
{
    public:
        npc_rotting_frost_giant() : CreatureScript("npc_rotting_frost_giant") { }

        struct npc_rotting_frost_giantAI : public ScriptedAI
        {
            npc_rotting_frost_giantAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void Reset()
            {
                _events.Reset();
                _events.ScheduleEvent(EVENT_DEATH_PLAGUE, 15000);
                _events.ScheduleEvent(EVENT_STOMP, urand(5000, 8000));
                _events.ScheduleEvent(EVENT_ARCTIC_BREATH, urand(10000, 15000));
            }

            void JustDied(Unit* /*killer*/)
            {
                _events.Reset();
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_DEATH_PLAGUE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
                            {
                                Talk(EMOTE_DEATH_PLAGUE_WARNING, target->GetGUID());
                                DoCast(target, SPELL_DEATH_PLAGUE);
                            }
                            _events.ScheduleEvent(EVENT_DEATH_PLAGUE, 15000);
                            break;
                        case EVENT_STOMP:
                            DoCastVictim(SPELL_STOMP);
                            _events.ScheduleEvent(EVENT_STOMP, urand(15000, 18000));
                            break;
                        case EVENT_ARCTIC_BREATH:
                            DoCastVictim(SPELL_ARCTIC_BREATH);
                            _events.ScheduleEvent(EVENT_ARCTIC_BREATH, urand(26000, 33000));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetIcecrownCitadelAI<npc_rotting_frost_giantAI>(creature);
        }
};

class npc_frost_freeze_trap : public CreatureScript
{
    public:
        npc_frost_freeze_trap() : CreatureScript("npc_frost_freeze_trap") { }

        struct npc_frost_freeze_trapAI: public Scripted_NoMovementAI
        {
            npc_frost_freeze_trapAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
            }

            void DoAction(int32 const action)
            {
                switch (action)
                {
                    case 1000:
                    case 11000:
                        _events.ScheduleEvent(EVENT_ACTIVATE_TRAP, uint32(action));
                        break;
                    case ACTION_STOP_TRAPS:
                        me->RemoveAurasDueToSpell(SPELL_COLDFLAME_JETS);
                        _events.CancelEvent(EVENT_ACTIVATE_TRAP);
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 const diff)
            {
                _events.Update(diff);

                if (_events.ExecuteEvent() == EVENT_ACTIVATE_TRAP)
                {
                    DoCast(me, SPELL_COLDFLAME_JETS);
                    _events.ScheduleEvent(EVENT_ACTIVATE_TRAP, 22000);
                }
            }

        private:
            EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetIcecrownCitadelAI<npc_frost_freeze_trapAI>(creature);
        }
};

class npc_alchemist_adrianna : public CreatureScript
{
    public:
        npc_alchemist_adrianna() : CreatureScript("npc_alchemist_adrianna") { }

        bool OnGossipHello(Player* player, Creature* creature)
        {
            if (!creature->FindCurrentSpellBySpellId(SPELL_HARVEST_BLIGHT_SPECIMEN) && !creature->FindCurrentSpellBySpellId(SPELL_HARVEST_BLIGHT_SPECIMEN25))
                if (player->HasAura(SPELL_ORANGE_BLIGHT_RESIDUE) && player->HasAura(SPELL_GREEN_BLIGHT_RESIDUE))
                    creature->CastSpell(creature, SPELL_HARVEST_BLIGHT_SPECIMEN, false);
            return false;
        }
};

class boss_sister_svalna : public CreatureScript
{
    public:
        boss_sister_svalna() : CreatureScript("boss_sister_svalna") { }

        struct boss_sister_svalnaAI : public BossAI
        {
            boss_sister_svalnaAI(Creature* creature) : BossAI(creature, DATA_SISTER_SVALNA),
                _isEventInProgress(false)
            {
            }

            void InitializeAI()
            {
                if (!me->isDead())
                    Reset();

                me->SetReactState(REACT_PASSIVE);
            }

            void Reset()
            {
                _Reset();
                me->SetReactState(REACT_DEFENSIVE);
                _isEventInProgress = false;
            }

            void JustDied(Unit* /*killer*/)
            {
                _JustDied();
                Talk(SAY_SVALNA_DEATH);

                uint64 delay = 1;
                for (uint32 i = 0; i < 4; ++i)
                {
                    if (Creature* crusader = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_CAPTAIN_ARNATH + i)))
                    {
                        if (crusader->isAlive() && crusader->GetEntry() == crusader->GetCreatureData()->id)
                        {
                            crusader->m_Events.AddEvent(new CaptainSurviveTalk(*crusader), crusader->m_Events.CalculateTime(delay));
                            delay += 6000;
                        }
                    }
                }
            }

            void EnterCombat(Unit* /*attacker*/)
            {
                _EnterCombat();
                if (Creature* crok = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_CROK_SCOURGEBANE)))
                    crok->AI()->Talk(SAY_CROK_COMBAT_SVALNA);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1);
                events.ScheduleEvent(EVENT_SVALNA_COMBAT, 9000);
                events.ScheduleEvent(EVENT_IMPALING_SPEAR, urand(40000, 50000));
                events.ScheduleEvent(EVENT_AETHER_SHIELD, urand(100000, 110000));
            }

            void KilledUnit(Unit* victim)
            {
                switch (victim->GetTypeId())
                {
                    case TYPEID_PLAYER:
                        Talk(SAY_SVALNA_KILL);
                        break;
                    case TYPEID_UNIT:
                        switch (victim->GetEntry())
                        {
                            case NPC_CAPTAIN_ARNATH:
                            case NPC_CAPTAIN_BRANDON:
                            case NPC_CAPTAIN_GRONDEL:
                            case NPC_CAPTAIN_RUPERT:
                                Talk(SAY_SVALNA_KILL_CAPTAIN);
                                break;
                            default:
                                break;
                        }
                        break;
                    default:
                        break;
                }
            }

            void JustReachedHome()
            {
                _JustReachedHome();
                me->SetReactState(REACT_PASSIVE);
            }

            void DoAction(int32 const action)
            {
                switch (action)
                {
                    case ACTION_KILL_CAPTAIN:
                        me->CastCustomSpell(SPELL_CARESS_OF_DEATH, SPELLVALUE_MAX_TARGETS, 1, me, true);
                        break;
                    case ACTION_START_GAUNTLET:
                        me->setActive(true);
                        _isEventInProgress = true;
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE | UNIT_FLAG_PASSIVE);
                        events.ScheduleEvent(EVENT_SVALNA_START, 25000);
                        break;
                    case ACTION_RESURRECT_CAPTAINS:
                        events.ScheduleEvent(EVENT_SVALNA_RESURRECT, 7000);
                        break;
                    case ACTION_CAPTAIN_DIES:
                        Talk(SAY_SVALNA_CAPTAIN_DEATH);
                        break;
                    case ACTION_RESET_EVENT:
                        me->setActive(false);
                        Reset();
                        break;
                    default:
                        break;
                }
            }

            void SpellHit(Unit* caster, SpellInfo const* spell)
            {
                if (spell->Id == SPELL_HURL_SPEAR && me->HasAura(SPELL_AETHER_SHIELD))
                {
                    me->RemoveAurasDueToSpell(SPELL_AETHER_SHIELD);
                    Talk(EMOTE_SVALNA_BROKEN_SHIELD, caster->GetGUID());
                }
            }

            void SpellHitTarget(Unit* target, SpellInfo const* spell)
            {
                switch (spell->Id)
                {
                    case SPELL_REVIVE_CHAMPION:
                        if (!_isEventInProgress)
                            break;
                        _isEventInProgress = false;
                        me->setActive(false);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE | UNIT_FLAG_PASSIVE);
                        break;
                    case SPELL_IMPALING_SPEAR_KILL:
                        me->Kill(target);
                        break;
                    case SPELL_IMPALING_SPEAR:
                        if (TempSummon* summon = target->SummonCreature(NPC_IMPALING_SPEAR, *target))
                        {
                            Talk(EMOTE_SVALNA_IMPALE, target->GetGUID());
                            summon->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_UNK1 | 0x4000);
                            summon->CastCustomSpell(VEHICLE_SPELL_RIDE_HARDCODED, SPELLVALUE_BASE_POINT0, 1, target, false);
                        }
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim() && !_isEventInProgress)
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SVALNA_START:
                            Talk(SAY_SVALNA_EVENT_START);
                            break;
                        case EVENT_SVALNA_RESURRECT:
                            Talk(SAY_SVALNA_RESURRECT_CAPTAINS);
                            me->CastSpell(me, SPELL_REVIVE_CHAMPION, false);
                            break;
                        case EVENT_SVALNA_COMBAT:
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1);
                            me->SetReactState(REACT_DEFENSIVE);
                            Talk(SAY_SVALNA_AGGRO);
                            break;
                        case EVENT_IMPALING_SPEAR:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true, -SPELL_IMPALING_SPEAR))
                                DoCast(target, SPELL_IMPALING_SPEAR);
                            events.ScheduleEvent(EVENT_IMPALING_SPEAR, urand(20000, 25000));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            bool _isEventInProgress;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetIcecrownCitadelAI<boss_sister_svalnaAI>(creature);
        }
};

class npc_crok_scourgebane : public CreatureScript
{
    public:
        npc_crok_scourgebane() : CreatureScript("npc_crok_scourgebane") { }

        struct npc_crok_scourgebaneAI : public npc_escortAI
        {
            npc_crok_scourgebaneAI(Creature* creature) : npc_escortAI(creature),
                _instance(creature->GetInstanceScript()), _respawnTime(creature->GetRespawnDelay()),
                _corpseDelay(creature->GetCorpseDelay())
            {
                SetDespawnAtEnd(false);
                SetDespawnAtFar(false);
                _isEventActive = false;
                _isEventDone = _instance->GetBossState(DATA_SISTER_SVALNA) == DONE;
                _didUnderTenPercentText = false;
            }

            void Reset()
            {
                _events.Reset();
                _events.ScheduleEvent(EVENT_SCOURGE_STRIKE, urand(7500, 12500));
                _events.ScheduleEvent(EVENT_DEATH_STRIKE, urand(25000, 30000));
                me->SetReactState(REACT_DEFENSIVE);
                _didUnderTenPercentText = false;
                _wipeCheckTimer = 1000;
            }

            void DoAction(int32 const action)
            {
                if (action == ACTION_START_GAUNTLET)
                {
                    if (_isEventDone || !me->isAlive())
                        return;

                    _isEventActive = true;
                    _isEventDone = true;
                    // Load Grid with Sister Svalna
                    me->GetMap()->LoadGrid(4356.71f, 2484.33f);
                    if (Creature* svalna = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_SISTER_SVALNA)))
                        svalna->AI()->DoAction(ACTION_START_GAUNTLET);
                    Talk(SAY_CROK_INTRO_1);
                    _events.ScheduleEvent(EVENT_ARNATH_INTRO_2, 7000);
                    _events.ScheduleEvent(EVENT_CROK_INTRO_3, 14000);
                    _events.ScheduleEvent(EVENT_START_PATHING, 37000);
                    me->setActive(true);
                    for (uint32 i = 0; i < 4; ++i)
                        if (Creature* crusader = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_CAPTAIN_ARNATH + i)))
                            crusader->AI()->DoAction(ACTION_START_GAUNTLET);
                }
                else if (action == ACTION_RESET_EVENT)
                {
                    _isEventActive = false;
                    _isEventDone = _instance->GetBossState(DATA_SISTER_SVALNA) == DONE;
                    me->setActive(false);
                    _aliveTrash.clear();
                    _currentWPid = 0;
                }
            }

            void SetGUID(uint64 const& guid, int32 type/* = 0*/)
            {
                if (type == ACTION_VRYKUL_DEATH)
                {
                    _aliveTrash.erase(guid);
                    if (_aliveTrash.empty())
                    {
                        SetEscortPaused(false);
                        if (_currentWPid == 4 && _isEventActive)
                        {
                            _isEventActive = false;
                            me->setActive(false);
                            Talk(SAY_CROK_FINAL_WP);
                            if (Creature* svalna = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_SISTER_SVALNA)))
                                svalna->AI()->DoAction(ACTION_RESURRECT_CAPTAINS);
                        }
                    }
                }
            }

            void WaypointReached(uint32 waypointId)
            {
                switch (waypointId)
                {
                    // pause pathing until trash pack is cleared
                    case 0:
                        Talk(SAY_CROK_COMBAT_WP_0);
                        if (!_aliveTrash.empty())
                            SetEscortPaused(true);
                        break;
                    case 1:
                        Talk(SAY_CROK_COMBAT_WP_1);
                        if (!_aliveTrash.empty())
                            SetEscortPaused(true);
                        break;
                    case 4:
                        if (_aliveTrash.empty() && _isEventActive)
                        {
                            _isEventActive = false;
                            me->setActive(false);
                            Talk(SAY_CROK_FINAL_WP);
                            if (Creature* svalna = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_SISTER_SVALNA)))
                                svalna->AI()->DoAction(ACTION_RESURRECT_CAPTAINS);
                        }
                        break;
                    default:
                        break;
                }
            }

            void WaypointStart(uint32 waypointId)
            {
                _currentWPid = waypointId;
                switch (waypointId)
                {
                    case 0:
                    case 1:
                    case 4:
                    {
                        // get spawns by home position
                        float minY = 2600.0f;
                        float maxY = 2650.0f;
                        if (waypointId == 1)
                        {
                            minY -= 50.0f;
                            maxY -= 50.0f;
                            // at waypoints 1 and 2 she kills one captain
                            if (Creature* svalna = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_SISTER_SVALNA)))
                                svalna->AI()->DoAction(ACTION_KILL_CAPTAIN);
                        }
                        else if (waypointId == 4)
                        {
                            minY -= 100.0f;
                            maxY -= 100.0f;
                        }

                        // get all nearby vrykul
                        std::list<Creature*> temp;
                        FrostwingVrykulSearcher check(me, 80.0f);
                        Trinity::CreatureListSearcher<FrostwingVrykulSearcher> searcher(me, temp, check);
                        me->VisitNearbyGridObject(80.0f, searcher);

                        _aliveTrash.clear();
                        for (std::list<Creature*>::iterator itr = temp.begin(); itr != temp.end(); ++itr)
                            if ((*itr)->GetHomePosition().GetPositionY() < maxY && (*itr)->GetHomePosition().GetPositionY() > minY)
                                _aliveTrash.insert((*itr)->GetGUID());
                        break;
                    }
                    // at waypoints 1 and 2 she kills one captain
                    case 2:
                        if (Creature* svalna = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_SISTER_SVALNA)))
                            svalna->AI()->DoAction(ACTION_KILL_CAPTAIN);
                        break;
                    default:
                        break;
                }
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage)
            {
                // check wipe
                if (!_wipeCheckTimer)
                {
                    _wipeCheckTimer = 1000;
                    Player* player = NULL;
                    Trinity::AnyPlayerInObjectRangeCheck check(me, 60.0f);
                    Trinity::PlayerSearcher<Trinity::AnyPlayerInObjectRangeCheck> searcher(me, player, check);
                    me->VisitNearbyWorldObject(60.0f, searcher);
                    // wipe
                    if (!player)
                    {
                        damage *= 100;
                        if (damage >= me->GetHealth())
                        {
                            FrostwingGauntletRespawner respawner;
                            Trinity::CreatureWorker<FrostwingGauntletRespawner> worker(me, respawner);
                            me->VisitNearbyGridObject(333.0f, worker);
                            Talk(SAY_CROK_DEATH);
                        }
                        return;
                    }
                }

                if (HealthBelowPct(10))
                {
                    if (!_didUnderTenPercentText)
                    {
                        _didUnderTenPercentText = true;
                        if (_isEventActive)
                            Talk(SAY_CROK_WEAKENING_GAUNTLET);
                        else
                            Talk(SAY_CROK_WEAKENING_SVALNA);
                    }

                    damage = 0;
                    DoCast(me, SPELL_ICEBOUND_ARMOR);
                    _events.ScheduleEvent(EVENT_HEALTH_CHECK, 1000);
                }
            }

            void UpdateEscortAI(uint32 const diff)
            {
                if (_wipeCheckTimer <= diff)
                    _wipeCheckTimer = 0;
                else
                    _wipeCheckTimer -= diff;

                if (!UpdateVictim() && !_isEventActive)
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_ARNATH_INTRO_2:
                            if (Creature* arnath = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_CAPTAIN_ARNATH)))
                                arnath->AI()->Talk(SAY_ARNATH_INTRO_2);
                            break;
                        case EVENT_CROK_INTRO_3:
                            Talk(SAY_CROK_INTRO_3);
                            break;
                        case EVENT_START_PATHING:
                            Start(true, true);
                            break;
                        case EVENT_SCOURGE_STRIKE:
                            DoCastVictim(SPELL_SCOURGE_STRIKE);
                            _events.ScheduleEvent(EVENT_SCOURGE_STRIKE, urand(10000, 14000));
                            break;
                        case EVENT_DEATH_STRIKE:
                            if (HealthBelowPct(20))
                                DoCastVictim(SPELL_DEATH_STRIKE);
                            _events.ScheduleEvent(EVENT_DEATH_STRIKE, urand(5000, 10000));
                            break;
                        case EVENT_HEALTH_CHECK:
                            if (HealthAbovePct(15))
                            {
                                me->RemoveAurasDueToSpell(SPELL_ICEBOUND_ARMOR);
                                _didUnderTenPercentText = false;
                            }
                            else
                            {
                                me->DealHeal(me, me->CountPctFromMaxHealth(5));
                                _events.ScheduleEvent(EVENT_HEALTH_CHECK, 1000);
                            }
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

            bool CanAIAttack(Unit const* target) const
            {
                // do not see targets inside Frostwing Halls when we are not there
                return (me->GetPositionY() > 2660.0f) == (target->GetPositionY() > 2660.0f);
            }

        private:
            EventMap _events;
            std::set<uint64> _aliveTrash;
            InstanceScript* _instance;
            uint32 _currentWPid;
            uint32 _wipeCheckTimer;
            uint32 const _respawnTime;
            uint32 const _corpseDelay;
            bool _isEventActive;
            bool _isEventDone;
            bool _didUnderTenPercentText;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetIcecrownCitadelAI<npc_crok_scourgebaneAI>(creature);
        }
};

struct npc_argent_captainAI : public ScriptedAI
{
    public:
        npc_argent_captainAI(Creature* creature) : ScriptedAI(creature), Instance(creature->GetInstanceScript()), _firstDeath(true)
        {
            FollowAngle = PET_FOLLOW_ANGLE;
            FollowDist = PET_FOLLOW_DIST;
            IsUndead = false;
        }

        void JustDied(Unit* /*killer*/)
        {
            if (_firstDeath)
            {
                _firstDeath = false;
                Talk(SAY_CAPTAIN_DEATH);
            }
            else
                Talk(SAY_CAPTAIN_SECOND_DEATH);
        }

        void KilledUnit(Unit* victim)
        {
            if (victim->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_CAPTAIN_KILL);
        }

        void DoAction(int32 const action)
        {
            if (action == ACTION_START_GAUNTLET)
            {
                if (Creature* crok = ObjectAccessor::GetCreature(*me, Instance->GetData64(DATA_CROK_SCOURGEBANE)))
                {
                    me->SetReactState(REACT_DEFENSIVE);
                    FollowAngle = me->GetAngle(crok) + me->GetOrientation();
                    FollowDist = me->GetDistance2d(crok);
                    me->GetMotionMaster()->MoveFollow(crok, FollowDist, FollowAngle, MOTION_SLOT_IDLE);
                }

                me->setActive(true);
            }
            else if (action == ACTION_RESET_EVENT)
            {
                _firstDeath = true;
            }
        }

        void EnterCombat(Unit* /*target*/)
        {
            me->SetHomePosition(*me);
            if (IsUndead)
                DoZoneInCombat();
        }

        bool CanAIAttack(Unit const* target) const
        {
            // do not see targets inside Frostwing Halls when we are not there
            return (me->GetPositionY() > 2660.0f) == (target->GetPositionY() > 2660.0f);
        }

        void EnterEvadeMode()
        {
            // not yet following
            if (me->GetMotionMaster()->GetMotionSlotType(MOTION_SLOT_IDLE) != TARGETED_MOTION_TYPE || IsUndead)
            {
                ScriptedAI::EnterEvadeMode();
                return;
            }

            if (!_EnterEvadeMode())
                return;

            if (!me->GetVehicle())
            {
                me->GetMotionMaster()->Clear(false);
                if (Creature* crok = ObjectAccessor::GetCreature(*me, Instance->GetData64(DATA_CROK_SCOURGEBANE)))
                    me->GetMotionMaster()->MoveFollow(crok, FollowDist, FollowAngle, MOTION_SLOT_IDLE);
            }

            Reset();
        }

        void SpellHit(Unit* /*caster*/, SpellInfo const* spell)
        {
            if (spell->Id == SPELL_REVIVE_CHAMPION && !IsUndead)
            {
                IsUndead = true;
                me->setDeathState(JUST_ALIVED);
                uint32 newEntry = 0;
                switch (me->GetEntry())
                {
                    case NPC_CAPTAIN_ARNATH:
                        newEntry = NPC_CAPTAIN_ARNATH_UNDEAD;
                        break;
                    case NPC_CAPTAIN_BRANDON:
                        newEntry = NPC_CAPTAIN_BRANDON_UNDEAD;
                        break;
                    case NPC_CAPTAIN_GRONDEL:
                        newEntry = NPC_CAPTAIN_GRONDEL_UNDEAD;
                        break;
                    case NPC_CAPTAIN_RUPERT:
                        newEntry = NPC_CAPTAIN_RUPERT_UNDEAD;
                        break;
                    default:
                        return;
                }

                Talk(SAY_CAPTAIN_RESURRECTED);
                me->UpdateEntry(newEntry, Instance->GetData(DATA_TEAM_IN_INSTANCE), me->GetCreatureData());
                DoCast(me, SPELL_UNDEATH, true);
            }
        }

    protected:
        EventMap Events;
        InstanceScript* Instance;
        float FollowAngle;
        float FollowDist;
        bool IsUndead;

    private:
        bool _firstDeath;
};

class npc_captain_arnath : public CreatureScript
{
    public:
        npc_captain_arnath() : CreatureScript("npc_captain_arnath") { }

        struct npc_captain_arnathAI : public npc_argent_captainAI
        {
            npc_captain_arnathAI(Creature* creature) : npc_argent_captainAI(creature)
            {
            }

            void Reset()
            {
                Events.Reset();
                Events.ScheduleEvent(EVENT_ARNATH_FLASH_HEAL, urand(4000, 7000));
                Events.ScheduleEvent(EVENT_ARNATH_PW_SHIELD, urand(8000, 14000));
                Events.ScheduleEvent(EVENT_ARNATH_SMITE, urand(3000, 6000));
                if (Is25ManRaid() && IsUndead)
                    Events.ScheduleEvent(EVENT_ARNATH_DOMINATE_MIND, urand(22000, 27000));
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                Events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = Events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_ARNATH_FLASH_HEAL:
                            if (Creature* target = FindFriendlyCreature())
                                DoCast(target, SPELL_FLASH_HEAL);
                            Events.ScheduleEvent(EVENT_ARNATH_FLASH_HEAL, urand(6000, 9000));
                            break;
                        case EVENT_ARNATH_PW_SHIELD:
                        {
                            std::list<Creature*> targets = DoFindFriendlyMissingBuff(40.0f, SPELL_POWER_WORD_SHIELD);
                            std::list<Creature*>::iterator itr = targets.begin();
                            std::advance(itr, urand(0, targets.size() - 1));
                            DoCast(*itr, SPELL_POWER_WORD_SHIELD);
                            Events.ScheduleEvent(EVENT_ARNATH_PW_SHIELD, urand(15000, 20000));
                            break;
                        }
                        case EVENT_ARNATH_SMITE:
                            DoCastVictim(SPELL_SMITE);
                            Events.ScheduleEvent(EVENT_ARNATH_SMITE, urand(4000, 7000));
                            break;
                        case EVENT_ARNATH_DOMINATE_MIND:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
                                DoCast(target, SPELL_DOMINATE_MIND);
                            Events.ScheduleEvent(EVENT_ARNATH_DOMINATE_MIND, urand(28000, 37000));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            Creature* FindFriendlyCreature() const
            {
                Creature* target = NULL;
                Trinity::MostHPMissingInRange u_check(me, 60.0f, 0);
                Trinity::CreatureLastSearcher<Trinity::MostHPMissingInRange> searcher(me, target, u_check);
                me->VisitNearbyGridObject(60.0f, searcher);
                return target;
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetIcecrownCitadelAI<npc_captain_arnathAI>(creature);
        }
};

class npc_captain_brandon : public CreatureScript
{
    public:
        npc_captain_brandon() : CreatureScript("npc_captain_brandon") { }

        struct npc_captain_brandonAI : public npc_argent_captainAI
        {
            npc_captain_brandonAI(Creature* creature) : npc_argent_captainAI(creature)
            {
            }

            void Reset()
            {
                Events.Reset();
                Events.ScheduleEvent(EVENT_BRANDON_CRUSADER_STRIKE, urand(6000, 10000));
                Events.ScheduleEvent(EVENT_BRANDON_DIVINE_SHIELD, 500);
                Events.ScheduleEvent(EVENT_BRANDON_JUDGEMENT_OF_COMMAND, urand(8000, 13000));
                if (IsUndead)
                    Events.ScheduleEvent(EVENT_BRANDON_HAMMER_OF_BETRAYAL, urand(25000, 30000));
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                Events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = Events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BRANDON_CRUSADER_STRIKE:
                            DoCastVictim(SPELL_CRUSADER_STRIKE);
                            Events.ScheduleEvent(EVENT_BRANDON_CRUSADER_STRIKE, urand(6000, 12000));
                            break;
                        case EVENT_BRANDON_DIVINE_SHIELD:
                            if (HealthBelowPct(20))
                                DoCast(me, SPELL_DIVINE_SHIELD);
                            Events.ScheduleEvent(EVENT_BRANDON_DIVINE_SHIELD, 500);
                            break;
                        case EVENT_BRANDON_JUDGEMENT_OF_COMMAND:
                            DoCastVictim(SPELL_JUDGEMENT_OF_COMMAND);
                            Events.ScheduleEvent(EVENT_BRANDON_JUDGEMENT_OF_COMMAND, urand(8000, 13000));
                            break;
                        case EVENT_BRANDON_HAMMER_OF_BETRAYAL:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
                                DoCast(target, SPELL_HAMMER_OF_BETRAYAL);
                            Events.ScheduleEvent(EVENT_BRANDON_HAMMER_OF_BETRAYAL, urand(45000, 60000));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetIcecrownCitadelAI<npc_captain_brandonAI>(creature);
        }
};

class npc_captain_grondel : public CreatureScript
{
    public:
        npc_captain_grondel() : CreatureScript("npc_captain_grondel") { }

        struct npc_captain_grondelAI : public npc_argent_captainAI
        {
            npc_captain_grondelAI(Creature* creature) : npc_argent_captainAI(creature)
            {
            }

            void Reset()
            {
                Events.Reset();
                Events.ScheduleEvent(EVENT_GRONDEL_CHARGE_CHECK, 500);
                Events.ScheduleEvent(EVENT_GRONDEL_MORTAL_STRIKE, urand(8000, 14000));
                Events.ScheduleEvent(EVENT_GRONDEL_SUNDER_ARMOR, urand(3000, 12000));
                if (IsUndead)
                    Events.ScheduleEvent(EVENT_GRONDEL_CONFLAGRATION, urand(12000, 17000));
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                Events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = Events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_GRONDEL_CHARGE_CHECK:
                            if (CanCast(me->getVictim(), sSpellMgr->GetSpellInfo(SPELL_CHARGE)))
                                DoCastVictim(SPELL_CHARGE);
                            Events.ScheduleEvent(EVENT_GRONDEL_CHARGE_CHECK, 500);
                            break;
                        case EVENT_GRONDEL_MORTAL_STRIKE:
                            DoCastVictim(SPELL_MORTAL_STRIKE);
                            Events.ScheduleEvent(EVENT_GRONDEL_MORTAL_STRIKE, urand(10000, 15000));
                            break;
                        case EVENT_GRONDEL_SUNDER_ARMOR:
                            DoCastVictim(SPELL_SUNDER_ARMOR);
                            Events.ScheduleEvent(EVENT_GRONDEL_SUNDER_ARMOR, urand(5000, 17000));
                            break;
                        case EVENT_GRONDEL_CONFLAGRATION:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                                DoCast(target, SPELL_CONFLAGRATION);
                            Events.ScheduleEvent(EVENT_GRONDEL_CONFLAGRATION, urand(10000, 15000));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetIcecrownCitadelAI<npc_captain_grondelAI>(creature);
        }
};

class npc_captain_rupert : public CreatureScript
{
    public:
        npc_captain_rupert() : CreatureScript("npc_captain_rupert") { }

        struct npc_captain_rupertAI : public npc_argent_captainAI
        {
            npc_captain_rupertAI(Creature* creature) : npc_argent_captainAI(creature)
            {
            }

            void Reset()
            {
                Events.Reset();
                Events.ScheduleEvent(EVENT_RUPERT_FEL_IRON_BOMB, urand(15000, 20000));
                Events.ScheduleEvent(EVENT_RUPERT_MACHINE_GUN, urand(25000, 30000));
                Events.ScheduleEvent(EVENT_RUPERT_ROCKET_LAUNCH, urand(10000, 15000));
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                Events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = Events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_RUPERT_FEL_IRON_BOMB:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, SPELL_FEL_IRON_BOMB);
                            Events.ScheduleEvent(EVENT_RUPERT_FEL_IRON_BOMB, urand(15000, 20000));
                            break;
                        case EVENT_RUPERT_MACHINE_GUN:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1))
                                DoCast(target, SPELL_MACHINE_GUN);
                            Events.ScheduleEvent(EVENT_RUPERT_MACHINE_GUN, urand(25000, 30000));
                            break;
                        case EVENT_RUPERT_ROCKET_LAUNCH:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1))
                                DoCast(target, SPELL_ROCKET_LAUNCH);
                            Events.ScheduleEvent(EVENT_RUPERT_ROCKET_LAUNCH, urand(10000, 15000));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetIcecrownCitadelAI<npc_captain_rupertAI>(creature);
        }
};

class npc_frostwing_vrykul : public CreatureScript
{
    public:
        npc_frostwing_vrykul() : CreatureScript("npc_frostwing_vrykul") { }

        struct npc_frostwing_vrykulAI : public SmartAI
        {
            npc_frostwing_vrykulAI(Creature* creature) : SmartAI(creature)
            {
            }

            bool CanAIAttack(Unit const* target) const
            {
                // do not see targets inside Frostwing Halls when we are not there
                return (me->GetPositionY() > 2660.0f) == (target->GetPositionY() > 2660.0f) && SmartAI::CanAIAttack(target);
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_frostwing_vrykulAI(creature);
        }
};

class npc_impaling_spear : public CreatureScript
{
    public:
        npc_impaling_spear() : CreatureScript("npc_impaling_spear") { }

        struct npc_impaling_spearAI : public CreatureAI
        {
            npc_impaling_spearAI(Creature* creature) : CreatureAI(creature)
            {
            }

            void Reset()
            {
                me->SetReactState(REACT_PASSIVE);
                _vehicleCheckTimer = 500;
            }

            void UpdateAI(uint32 const diff)
            {
                if (_vehicleCheckTimer <= diff)
                {
                    _vehicleCheckTimer = 500;
                    if (!me->GetVehicle())
                        me->DespawnOrUnsummon(100);
                }
                else
                    _vehicleCheckTimer -= diff;
            }

            uint32 _vehicleCheckTimer;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_impaling_spearAI(creature);
        }
};

class spell_icc_stoneform : public SpellScriptLoader
{
    public:
        spell_icc_stoneform() : SpellScriptLoader("spell_icc_stoneform") { }

        class spell_icc_stoneform_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_icc_stoneform_AuraScript);

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Creature* target = GetTarget()->ToCreature())
                {
                    target->SetReactState(REACT_PASSIVE);
                    target->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_OOC_NOT_ATTACKABLE);
                    target->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_CUSTOM_SPELL_02);
                }
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Creature* target = GetTarget()->ToCreature())
                {
                    target->SetReactState(REACT_AGGRESSIVE);
                    target->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_OOC_NOT_ATTACKABLE);
                    target->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
                }
            }

            void Register()
            {
                OnEffectApply += AuraEffectApplyFn(spell_icc_stoneform_AuraScript::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
                OnEffectRemove += AuraEffectRemoveFn(spell_icc_stoneform_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_icc_stoneform_AuraScript();
        }
};

class spell_icc_sprit_alarm : public SpellScriptLoader
{
    public:
        spell_icc_sprit_alarm() : SpellScriptLoader("spell_icc_sprit_alarm") { }

        class spell_icc_sprit_alarm_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_icc_sprit_alarm_SpellScript);

            InstanceScript * instance;

            void SpieleGeistalarm()
            {
                GetCaster()->PlayDistanceSound(17274);
                instance->DoSendNotifyToInstance("FALLE AUSGELÖST!");
            }

            void SpawnAdds()
            {
                SpieleGeistalarm();

                // Anzahl der Adds aus den Fallen GO_SPIRIT_ALARM_5 + GO_SPIRIT_ALARM_6
                uint8 NumAdds = 0;

                switch(instance->instance->GetDifficulty())
                {
                    case RAID_DIFFICULTY_10MAN_NORMAL:
                    case RAID_DIFFICULTY_10MAN_HEROIC:
                        NumAdds = 10;
                        break;
                    case RAID_DIFFICULTY_25MAN_NORMAL:
                    case RAID_DIFFICULTY_25MAN_HEROIC:
                        NumAdds = 25;
                        break;
                }

                Position pos = FallenAddsWegPunkte[SPAWNPUNKT];

                for (uint8 i=0; i<NumAdds; ++i)
                {
                    if (TempSummon * pAdd = instance->instance->SummonCreature(RACHSUECHTIGER_FLEISCHERNTER, pos))
                    {   // Eigentlich müssten sie als Gruppe Wegpunkte ablaufen, nachdem sie am HOME Punkt 10 Sek. gewartet haben.
                        // Leider habe ich gerade keinen Schimmer, wie ich aus TmpSpawns eine Gruppe erstellen kann, und diese auch noch steuern, geschweige denn Wegpunkte geben kann... :-(
                        // Also erst einmal spawnen, und einfach nach Hause gehen lassen. ;)
                        pAdd->SetTempSummonType(TEMPSUMMON_DEAD_DESPAWN);

                        if (i) // Das erste Add direkt am HOME lassen.
                            switch(urand(0,1))
                            {
                                case 0:
                                    pAdd->SetHomePosition(FallenAddsWegPunkte[HOME].m_positionX+float(urand(0,8)), FallenAddsWegPunkte[HOME].m_positionY-float(urand(0,8)),
                                        FallenAddsWegPunkte[HOME].m_positionZ, FallenAddsWegPunkte[HOME].m_orientation);
                                    break;
                                case 1:
                                    pAdd->SetHomePosition(FallenAddsWegPunkte[HOME].m_positionX-float(urand(0,8)), FallenAddsWegPunkte[HOME].m_positionY+float(urand(0,8)),
                                        FallenAddsWegPunkte[HOME].m_positionZ, FallenAddsWegPunkte[HOME].m_orientation);
                                    break;
                            }
                        // Ausgehend vom vorherigen Add, einen Random HOME Punkt für das nächste setzen, damit nicht alle auf einem Haufen hocken. ;)
                        pAdd->GetNearPosition(pos, 8.0f, float(urand(0,360)));

                        if (!pAdd->isInCombat())
                            pAdd->GetMotionMaster()->MoveTargetedHome();
                    }
                }
            }

            void HandleEvent(SpellEffIndex effIndex)
            {
                instance = GetCaster()->GetInstanceScript();
                if (!instance)
                    return;

                uint32 trapId = 0;

                switch (GetSpellInfo()->Effects[effIndex].MiscValue)
                {
                    case EVENT_AWAKEN_WARD_1: trapId = GO_SPIRIT_ALARM_1; break;
                    case EVENT_AWAKEN_WARD_2: trapId = GO_SPIRIT_ALARM_2; break;
                    case EVENT_AWAKEN_WARD_3: trapId = GO_SPIRIT_ALARM_3; break;
                    case EVENT_AWAKEN_WARD_4: trapId = GO_SPIRIT_ALARM_4; break;

                    case EVENT_RACHSUECHTIGER_FLEISCHERNTER_FALLE_1:
                        trapId = GO_SPIRIT_ALARM_5;
                        SpawnAdds();
                        break;
                    case EVENT_RACHSUECHTIGER_FLEISCHERNTER_FALLE_2:
                        trapId = GO_SPIRIT_ALARM_6;
                        SpawnAdds();
                        break;

                    default:
                        return;
                }

                if (GameObject * trap = GetCaster()->FindNearestGameObject(trapId, 10.0f))
                    trap->SetRespawnTime(trap->GetGOInfo()->trap.autoCloseTime);

                bool gefunden = false;
                std::list<Creature*> wards;
                GetCaster()->GetCreatureListWithEntryInGrid(wards, NPC_DEATHBOUND_WARD, 150.0f);
                wards.sort(Trinity::ObjectDistanceOrderPred(GetCaster()));

                for (std::list<Creature*>::iterator itr = wards.begin(); itr != wards.end(); ++itr)
                {
                    if ((*itr)->isAlive() && (*itr)->HasAura(SPELL_STONEFORM))
                    {
                        switch(trapId)
                        {
                            // Die Wachen den korrekten Fallen zuordnen!
                            case GO_SPIRIT_ALARM_1:
                                if (uint32((*itr)->GetPositionY()) == TODESGEWEIHTER_WAECHTER_Y_FALLE_1)
                                    gefunden = true;
                                break;
                            case GO_SPIRIT_ALARM_2:
                                if (uint32((*itr)->GetPositionY()) == TODESGEWEIHTER_WAECHTER_Y_FALLE_2)
                                    gefunden = true;
                                break;
                            case GO_SPIRIT_ALARM_3:
                                if (uint32((*itr)->GetPositionY()) == TODESGEWEIHTER_WAECHTER_Y_FALLE_3)
                                    gefunden = true;
                                break;
                            case GO_SPIRIT_ALARM_4:
                                if (uint32((*itr)->GetPositionY()) == TODESGEWEIHTER_WAECHTER_Y_FALLE_4)
                                    gefunden = true;
                                break;
                            default:
                                gefunden = false;
                                break;
                        }

                        if (gefunden)
                        {
                            SpieleGeistalarm();

                            (*itr)->AI()->Talk(SAY_TRAP_ACTIVATE);
                            (*itr)->RemoveAurasDueToSpell(SPELL_STONEFORM);
                            if (Unit* target = (*itr)->SelectNearestTarget(150.0f))
                                (*itr)->AI()->AttackStart(target);
                            else
                            {
                                (*itr)->GetMotionMaster()->Clear();
                                (*itr)->SetDefaultMovementType(WAYPOINT_MOTION_TYPE);
                                (*itr)->GetMotionMaster()->InitDefault();
                            }
                            return;
                        }
                    }
                }
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_icc_sprit_alarm_SpellScript::HandleEvent, EFFECT_2, SPELL_EFFECT_SEND_EVENT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_icc_sprit_alarm_SpellScript();
        }
};

class DeathPlagueTargetSelector
{
    public:
        explicit DeathPlagueTargetSelector(Unit* caster) : _caster(caster) {}

        bool operator()(Unit* unit)
        {
            if (unit == _caster)
                return true;

            if (unit->GetTypeId() != TYPEID_PLAYER)
                return true;

            if (unit->HasAura(SPELL_RECENTLY_INFECTED) || unit->HasAura(SPELL_DEATH_PLAGUE_AURA))
                return true;

            return false;
        }

    private:
        Unit* _caster;
};

class spell_frost_giant_death_plague : public SpellScriptLoader
{
    public:
        spell_frost_giant_death_plague() : SpellScriptLoader("spell_frost_giant_death_plague") { }

        class spell_frost_giant_death_plague_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_frost_giant_death_plague_SpellScript);

            bool Load()
            {
                _failed = false;
                return true;
            }

            // First effect
            void CountTargets(std::list<Unit*>& unitList)
            {
                unitList.remove(GetCaster());
                _failed = unitList.empty();
            }

            // Second effect
            void FilterTargets(std::list<Unit*>& unitList)
            {
                // Select valid targets for jump
                unitList.remove_if(DeathPlagueTargetSelector(GetCaster()));
                if (!unitList.empty())
                {
                    std::list<Unit*>::iterator itr = unitList.begin();
                    std::advance(itr, urand(0, unitList.size()-1));
                    Unit* target = *itr;
                    unitList.clear();
                    unitList.push_back(target);
                }

                unitList.push_back(GetCaster());
            }

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                if (GetHitUnit() != GetCaster())
                    GetCaster()->CastSpell(GetHitUnit(), SPELL_DEATH_PLAGUE_AURA, true);
                else if (_failed)
                    GetCaster()->CastSpell(GetCaster(), SPELL_DEATH_PLAGUE_KILL, true);
            }

            void Register()
            {
                OnUnitTargetSelect += SpellUnitTargetFn(spell_frost_giant_death_plague_SpellScript::CountTargets, EFFECT_0, TARGET_UNIT_AREA_ALLY_SRC);
                OnUnitTargetSelect += SpellUnitTargetFn(spell_frost_giant_death_plague_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_AREA_ALLY_SRC);
                OnEffect += SpellEffectFn(spell_frost_giant_death_plague_SpellScript::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
            }

            bool _failed;
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_frost_giant_death_plague_SpellScript();
        }
};

class spell_icc_harvest_blight_specimen : public SpellScriptLoader
{
    public:
        spell_icc_harvest_blight_specimen() : SpellScriptLoader("spell_icc_harvest_blight_specimen") { }

        class spell_icc_harvest_blight_specimen_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_icc_harvest_blight_specimen_SpellScript);

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                GetHitUnit()->RemoveAurasDueToSpell(uint32(GetEffectValue()));
            }

            void HandleQuestComplete(SpellEffIndex /*effIndex*/)
            {
                GetHitUnit()->RemoveAurasDueToSpell(uint32(GetEffectValue()));
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_icc_harvest_blight_specimen_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
                OnEffect += SpellEffectFn(spell_icc_harvest_blight_specimen_SpellScript::HandleQuestComplete, EFFECT_1, SPELL_EFFECT_QUEST_COMPLETE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_icc_harvest_blight_specimen_SpellScript();
        }
};

class AliveCheck
{
    public:
        bool operator()(Unit* unit)
        {
            return unit->isAlive();
        }
};

class spell_svalna_revive_champion : public SpellScriptLoader
{
    public:
        spell_svalna_revive_champion() : SpellScriptLoader("spell_svalna_revive_champion") { }

        class spell_svalna_revive_champion_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_svalna_revive_champion_SpellScript);

            void RemoveAliveTarget(std::list<Unit*>& unitList)
            {
                unitList.remove_if(AliveCheck());
                Trinity::RandomResizeList(unitList, 2);
            }

            void Register()
            {
                OnUnitTargetSelect += SpellUnitTargetFn(spell_svalna_revive_champion_SpellScript::RemoveAliveTarget, EFFECT_0, TARGET_UNIT_AREA_ENTRY_DST);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_svalna_revive_champion_SpellScript();
        }
};

class spell_svalna_remove_spear : public SpellScriptLoader
{
    public:
        spell_svalna_remove_spear() : SpellScriptLoader("spell_svalna_remove_spear") { }

        class spell_svalna_remove_spear_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_svalna_remove_spear_SpellScript);

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                if (Creature* target = GetHitCreature())
                    target->DespawnOrUnsummon();
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_svalna_remove_spear_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_svalna_remove_spear_SpellScript();
        }
};

class at_icc_saurfang_portal : public AreaTriggerScript
{
    public:
        at_icc_saurfang_portal() : AreaTriggerScript("at_icc_saurfang_portal") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/)
        {
            InstanceScript* instance = player->GetInstanceScript();
            if (!instance || instance->GetBossState(DATA_DEATHBRINGER_SAURFANG) != DONE)
                return true;

            player->TeleportTo(631, 4126.35f, 2769.23f, 350.963f, 0.0f);

            if (instance->GetData(DATA_COLDFLAME_JETS) == NOT_STARTED)
            {
                // Process relocation now, to preload the grid and initialize traps
                player->GetMap()->PlayerRelocation(player, 4126.35f, 2769.23f, 350.963f, 0.0f);

                instance->SetData(DATA_COLDFLAME_JETS, IN_PROGRESS);
                std::list<Creature*> traps;
                GetCreatureListWithEntryInGrid(traps, player, NPC_FROST_FREEZE_TRAP, 120.0f);
                traps.sort(Trinity::ObjectDistanceOrderPred(player));
                bool instant = false;
                for (std::list<Creature*>::iterator itr = traps.begin(); itr != traps.end(); ++itr)
                {
                    (*itr)->AI()->DoAction(instant ? 1000 : 11000);
                    instant = !instant;
                }
            }

            return true;
        }
};

class at_icc_shutdown_traps : public AreaTriggerScript
{
    public:
        at_icc_shutdown_traps() : AreaTriggerScript("at_icc_shutdown_traps") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/)
        {
            if (InstanceScript* instance = player->GetInstanceScript())
                if (instance->GetData(DATA_COLDFLAME_JETS) == IN_PROGRESS)
                    instance->SetData(DATA_COLDFLAME_JETS, DONE);
            return true;
        }
};

class at_icc_start_blood_quickening : public AreaTriggerScript
{
    public:
        at_icc_start_blood_quickening() : AreaTriggerScript("at_icc_start_blood_quickening") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/)
        {
            if (InstanceScript* instance = player->GetInstanceScript())
                if (instance->GetData(DATA_BLOOD_QUICKENING_STATE) == NOT_STARTED)
                    instance->SetData(DATA_BLOOD_QUICKENING_STATE, IN_PROGRESS);
            return true;
        }
};

class at_icc_start_frostwing_gauntlet : public AreaTriggerScript
{
    public:
        at_icc_start_frostwing_gauntlet() : AreaTriggerScript("at_icc_start_frostwing_gauntlet") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/)
        {
            if (InstanceScript* instance = player->GetInstanceScript())
                if (Creature* crok = ObjectAccessor::GetCreature(*player, instance->GetData64(DATA_CROK_SCOURGEBANE)))
                    crok->AI()->DoAction(ACTION_START_GAUNTLET);
            return true;
        }
};

void AddSC_icecrown_citadel()
{
    new npc_highlord_tirion_fordring_lh();
    new npc_rotting_frost_giant();
    new npc_frost_freeze_trap();
    new npc_alchemist_adrianna();
    new boss_sister_svalna();
    new npc_crok_scourgebane();
    new npc_captain_arnath();
    new npc_captain_brandon();
    new npc_captain_grondel();
    new npc_captain_rupert();
    new npc_frostwing_vrykul();
    new npc_impaling_spear();
    new spell_icc_stoneform();
    new spell_icc_sprit_alarm();
    new spell_frost_giant_death_plague();
    new spell_icc_harvest_blight_specimen();
    new spell_trigger_spell_from_caster("spell_svalna_caress_of_death", SPELL_IMPALING_SPEAR_KILL);
    new spell_svalna_revive_champion();
    new spell_svalna_remove_spear();
    new at_icc_saurfang_portal();
    new at_icc_shutdown_traps();

    new mob_icc_raid_trash();

    new at_icc_start_blood_quickening();
    new at_icc_start_frostwing_gauntlet();
}
