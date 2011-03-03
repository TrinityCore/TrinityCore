// Copyright 2010-2011 by WarHead (United Worlds of MaNGOS)

#include "ScriptPCH.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "icecrown_citadel.h"

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
/* SIEHE TRINITY STUFF !
        VERROTTENDER_FROSTRIESE                                         = 38490,
        VERROTTENDER_FROSTRIESE_STAMPFEN                                = 64652,
        VERROTTENDER_FROSTRIESE_TODESSEUCHE                             = 72865,
*/
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
    EVENT_VERROTTENDER_FROSTRIESE_STAMPFEN,
    EVENT_VERROTTENDER_FROSTRIESE_TODESSEUCHE,
    EVENT_TIERFUEHRER_DER_FROSTWAECHTER_WELPEN_BEFEHLIGEN,
    EVENT_TIERFUEHRER_DER_FROSTWAECHTER_ERSCHUETTENDER_SCHOCK
};

class mob_icc_raid_trash : public CreatureScript
{
public:
    mob_icc_raid_trash() : CreatureScript("mob_icc_raid_trash") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_icc_raid_trashAI(pCreature);
    }

    struct mob_icc_raid_trashAI: public ScriptedAI
    {
        mob_icc_raid_trashAI(Creature *c) : ScriptedAI(c)
        {
            // Bestimmen welcher NPC ein Caster ist (wegen korrektem Movement!)
            switch(c->GetEntry())
            {
                case AUFERSTANDENER_DIENER_DER_TODESSPRECHER:
                case DIENER_DER_TODESSPRECHER:
                case SINISTRER_ERZMAGIER:
                case SINISTRER_ADLIGER:
                    // Default Castranges
                    c->m_isCaster = true;
                    break;
                case DIENER_DES_THRONS:
                case BRUTHUETER_DER_NERUBAR:
                case JUENGER_DER_TODESSPRECHER:
                case KNECHT_DER_TODESSPRECHER:
                case SEUCHENWISSENSCHAFTLER:
                    c->m_isCaster = true;
                    c->m_CasterDefaultMaxCombatRange = 39;
                    break;
                case BASTIONSGARGOYLE:
                    c->m_isCaster = true;
                    c->m_CasterDefaultMaxCombatRange = 44;
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

            // Funzt nit! Wird wild in der Gegend rumgecastet. :-(
/*            switch(me->GetEntry())
            {
                case SINISTRER_ERZMAGIER:
                case SINISTRER_ADLIGER:
                case SINISTRER_BLUTRITTER:
                    DoCast(SINISTRER_ERZMAGIER_ESSENZ_ENTZIEHEN);
                    break;
            }*/
        }

        void JustReachedHome()
        {
            // Funzt nit! Wird wild in der Gegend rumgecastet. :-(
/*            switch(me->GetEntry())
            {
                case SINISTRER_ERZMAGIER:
                case SINISTRER_ADLIGER:
                case SINISTRER_BLUTRITTER:
                    DoCast(SINISTRER_ERZMAGIER_ESSENZ_ENTZIEHEN);
                    break;
            }*/
        }

        void DamageTaken(Unit* pDoneBy, uint32 &uiDamage)
        {
            switch(me->GetEntry())
            {
                case DIE_VERDAMMTEN:
                    if (!DieVerdammtenZerschmKnochen && uiDamage >= me->GetHealth())
                    {
                        DoCast(DIE_VERDAMMTEN_ZERSCHMETTERTE_KNOCHEN);
                        DieVerdammtenZerschmKnochen = true;
                    }

                    if (!DieVerdammtenKnochenwirbel && me->HealthBelowPctDamaged(urand(25,75), uiDamage))
                    {
                        DoCast(me, DIE_VERDAMMTEN_KNOCHENWIRBEL, true);
                        DieVerdammtenKnochenwirbel = true;
                    }
                    break;
                case EITERNDER_SCHRECKEN:
                    if (!EiternderSchreckenBombe && me->HealthBelowPctDamaged(15, uiDamage))
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
            events.ScheduleEvent(EVENT_VERROTTENDER_FROSTRIESE_STAMPFEN, urand(3000,5000));
            events.ScheduleEvent(EVENT_VERROTTENDER_FROSTRIESE_TODESSEUCHE, urand(8000,10000));
            events.ScheduleEvent(EVENT_TIERFUEHRER_DER_FROSTWAECHTER_WELPEN_BEFEHLIGEN, urand(5000,10000));
            events.ScheduleEvent(EVENT_TIERFUEHRER_DER_FROSTWAECHTER_ERSCHUETTENDER_SCHOCK, urand(3000,5000));

            switch(me->GetEntry())
            {
                case HOHEPRIESTER_DER_TODESSPRECHER: DoCast(HOHEPRIESTER_DER_TODESSPRECHER_AURA_DER_DUNKELHEIT); break;
                case SINISTRER_BLUTRITTER: DoCast(SINISTRER_BLUTRITTER_VAMPIRAURA); break;
                case SINISTRER_KOMMANDANT: DoCast(SINISTRER_KOMMANDANT_SCHLACHTRUF); break;
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
                                if (Unit *Schrecken = (Unit*)GetClosestCreatureWithEntry(me, EITERNDER_SCHRECKEN, 80.0f, true))
                                {
                                    me->SetFacing(0, Schrecken);
                                    DoCast(Schrecken, SEUCHENWISSENSCHAFTLER_SEUCHENSTROM);
                                }
                                events.RescheduleEvent(EVENT_SEUCHENWISSENSCHAFTLER_SEUCHENSTROM, urand(35000,45000));
                            }
                        }
                        break;
                }
                return;
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
                                if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                                    DoCast(pTarget, BRUTHUETER_DER_NERUBAR_FANGNETZ, true);
                                events.RescheduleEvent(EVENT_BRUTHUETER_DER_NERUBAR_FANGNETZ, 10000);
                                break;
                            case EVENT_BRUTHUETER_DER_NERUBAR_GRUFTSKARABAEEN:
                                if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
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
                            if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                                DoCast(pTarget, HOHEPRIESTER_DER_TODESSPRECHER_DUNKLE_ABRECHNUNG, true);
                            events.RescheduleEvent(EVENT_HOHEPRIESTER_DER_TODESSPRECHER_DUNKLE_ABRECHNUNG, 15000);
                        }
                        break;
                    case BOTIN_DER_VALKYR:
                        if (eventId == EVENT_BOTIN_DER_VALKYR_ABGETRENNTE_ESSENZ)
                        {
                            if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                                DoCast(pTarget, BOTIN_DER_VALKYR_ABGETRENNTE_ESSENZ, true);
                            events.RescheduleEvent(EVENT_BOTIN_DER_VALKYR_ABGETRENNTE_ESSENZ, 6000);
                        }
                        break;
                    case VERSEUCHTE_MONSTROSITAET:
                        switch(eventId)
                        {
                            case EVENT_VERSEUCHTE_MONSTROSITAET_GEISSELHAKEN:
                                if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
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
                                /* Crasht den Server!!!
                                if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 1))
                                    DoCast(pTarget, SEUCHENWISSENSCHAFTLER_MUTATIONSAUSLOESENDES_SPRAY);
                                events.RescheduleEvent(EVENT_SEUCHENWISSENSCHAFTLER_MUTATIONSAUSLOESENDES_SPRAY, urand(8000,10000));
                                */
                                break;
                            case EVENT_SEUCHENWISSENSCHAFTLER_SEUCHENSCHLAG:
                                DoCast(SEUCHENWISSENSCHAFTLER_SEUCHENSCHLAG);
                                events.RescheduleEvent(EVENT_SEUCHENWISSENSCHAFTLER_SEUCHENSCHLAG, urand(5000,10000));
                                break;
                        }
                        break;
                    case RACHSUECHTIGER_FLEISCHERNTER:
                        if (eventId == EVENT_RACHSUECHTIGER_FLEISCHERNTER_EINGESPRUNGENER_GESICHTSZERMALMER)
                        {
                            if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 1))
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
                                if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 1))
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
                                if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                                    DoCast(pTarget, SINISTRER_ERZMAGIER_MAGIE_VERSTAERKEN, true);
                                events.RescheduleEvent(EVENT_SINISTRER_ERZMAGIER_MAGIE_VERSTAERKEN, urand(10000,15000));
                                break;
                        }
                        break;
                    case SINISTRER_ADLIGER:
                        switch(eventId)
                        {
                            case EVENT_SINISTRER_ADLIGER_KETTEN_DES_SCHATTENS:
                                if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 1))
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
                                if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 1))
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
                            if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 1))
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
                                if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                                    DoCast(pTarget, BASTIONSFROSTWYRM_BLIZZARD, true);
                                events.RescheduleEvent(EVENT_BASTIONSFROSTWYRM_BLIZZARD, urand(8000,12000));
                                break;
                            case EVENT_BASTIONSFROSTWYRM_FROSTATEM:
                                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_INTERRUPT, true);
                                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_INTERRUPT_CAST, true);
                                if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 1))
                                    DoCast(pTarget, BASTIONSFROSTWYRM_FROSTATEM, true);
                                events.RescheduleEvent(EVENT_BASTIONSFROSTWYRM_FROSTATEM, urand(8000,12000));
                                break;
                        }
                        break;
                    /* SIEHE TRINITY STUFF !
                    case VERROTTENDER_FROSTRIESE:
                        switch(eventId)
                        {
                            case EVENT_VERROTTENDER_FROSTRIESE_STAMPFEN:
                                DoCast(VERROTTENDER_FROSTRIESE_STAMPFEN);
                                events.RescheduleEvent(EVENT_VERROTTENDER_FROSTRIESE_STAMPFEN, urand(8000,12000));
                                break;
                            case EVENT_VERROTTENDER_FROSTRIESE_TODESSEUCHE:
                                if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                                    DoCast(pTarget, VERROTTENDER_FROSTRIESE_TODESSEUCHE, true);
                                events.RescheduleEvent(EVENT_VERROTTENDER_FROSTRIESE_TODESSEUCHE, urand(10000,15000));
                                break;
                        }
                        break;
                    */
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

};

/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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
//* Deprogramming                (DONE)
//* Securing the Ramparts        (DONE)
//* Residue Rendezvous           (DONE)
//* Blood Quickening                    // AreaTrigger 5729 starts the timer, pulling BQ before it runs out means success
//* Respite for a Tormented Soul

enum Texts
{
    // Rotting Frost Giant
    EMOTE_DEATH_PLAGUE_WARNING  = 0,
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
};

enum Events
{
    // Rotting Frost Giant
    EVENT_DEATH_PLAGUE      = 1,
    EVENT_STOMP             = 2,
    EVENT_ARCTIC_BREATH     = 3,

    // Frost Freeze Trap
    EVENT_ACTIVATE_TRAP     = 4,
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
                events.Reset();
                events.ScheduleEvent(EVENT_DEATH_PLAGUE, 15000);
                events.ScheduleEvent(EVENT_STOMP, urand(5000, 8000));
                events.ScheduleEvent(EVENT_ARCTIC_BREATH, urand(10000, 15000));
            }

            void JustDied(Unit* /*killer*/)
            {
                events.Reset();
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_DEATH_PLAGUE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
                            {
                                Talk(EMOTE_DEATH_PLAGUE_WARNING, target->GetGUID());
                                DoCast(target, SPELL_DEATH_PLAGUE);
                            }
                            events.ScheduleEvent(EVENT_DEATH_PLAGUE, 15000);
                            break;
                        case EVENT_STOMP:
                            DoCastVictim(SPELL_STOMP);
                            events.ScheduleEvent(EVENT_STOMP, urand(15000, 18000));
                            break;
                        case EVENT_ARCTIC_BREATH:
                            DoCastVictim(SPELL_ARCTIC_BREATH);
                            events.ScheduleEvent(EVENT_ARCTIC_BREATH, urand(26000, 33000));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_rotting_frost_giantAI(creature);
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

            void DoAction(const int32 action)
            {
                switch (action)
                {
                    case 1000:
                    case 11000:
                        events.ScheduleEvent(EVENT_ACTIVATE_TRAP, uint32(action));
                        break;
                    case ACTION_STOP_TRAPS:
                        me->RemoveAurasDueToSpell(SPELL_COLDFLAME_JETS);
                        events.CancelEvent(EVENT_ACTIVATE_TRAP);
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(const uint32 diff)
            {
                events.Update(diff);

                if (events.ExecuteEvent() == EVENT_ACTIVATE_TRAP)
                {
                    DoCast(me, SPELL_COLDFLAME_JETS);
                    events.ScheduleEvent(EVENT_ACTIVATE_TRAP, 22000);
                }
            }

        private:
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_frost_freeze_trapAI(creature);
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

class DeathPlagueTargetSelector
{
    public:
        DeathPlagueTargetSelector(Unit* _caster) : caster(_caster) {}

        bool operator()(Unit* unit)
        {
            if (unit == caster)
                return true;

            if (unit->GetTypeId() != TYPEID_PLAYER)
                return true;

            if (unit->HasAura(SPELL_RECENTLY_INFECTED) || unit->HasAura(SPELL_DEATH_PLAGUE_AURA))
                return true;

            return false;
        }

        Unit* caster;
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
                failed = false;
                return true;
            }

            // First effect
            void CountTargets(std::list<Unit*>& unitList)
            {
                unitList.remove(GetCaster());
                failed = unitList.empty();
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
                else if (failed)
                    GetCaster()->CastSpell(GetCaster(), SPELL_DEATH_PLAGUE_KILL, true);
            }

            void Register()
            {
                OnUnitTargetSelect += SpellUnitTargetFn(spell_frost_giant_death_plague_SpellScript::CountTargets, EFFECT_0, TARGET_UNIT_AREA_ALLY_SRC);
                OnUnitTargetSelect += SpellUnitTargetFn(spell_frost_giant_death_plague_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_AREA_ALLY_SRC);
                OnEffect += SpellEffectFn(spell_frost_giant_death_plague_SpellScript::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
            }

            bool failed;
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

            void HandleQuestComplete(SpellEffIndex effIndex)
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

void AddSC_icecrown_citadel()
{
    new npc_rotting_frost_giant();
    new npc_frost_freeze_trap();
    new npc_alchemist_adrianna();
    new spell_frost_giant_death_plague();
    new spell_icc_harvest_blight_specimen();
    new at_icc_saurfang_portal();
    new at_icc_shutdown_traps();

    new mob_icc_raid_trash();
}
