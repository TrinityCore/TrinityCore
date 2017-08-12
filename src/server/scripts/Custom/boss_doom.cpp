#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum Spells {

    SPELL_VRAZUMA = 26540,
    SPELL_NEMOTA = 65542,
    SPELL_SLOVOTBOL = 68089,
    SPELL_SLOVOSILISHIT = 54322,
    SPELL_HEAL = 61965,
    SPELL_AOEFEAR = 50497,

    SPELL_FROSTBOLT = 71318,
    SPELL_ARCANEBLAST = 61693,
    SPELL_ARCANEB = 57912,
    SPELL_PRILIV = 12051,
//warlock
            SPELL_METAMORPH = 47241,
    SPELL_KOSTER = 50589,
    SPELL_SHADOWBOLT = 69973,
    SPELL_PORCHA = 68134,
    SPELL_AGONIYA = 59772,
//tresh
            SPELL_MANASHIELD = 70842,
    SPELL_DUSTDECAY = 71001,
    SPELL_SHADOBOLT = 71254,
};

class boss_chaoscontrol : public CreatureScript {
public:
    boss_chaoscontrol() : CreatureScript("boss_chaoscontrol") {}

    CreatureAI *GetAI(Creature *creature) const {
        return new boss_chaoscontrolAI(creature);
    }

    struct boss_chaoscontrolAI : public ScriptedAI {
        boss_chaoscontrolAI(Creature *creature) : ScriptedAI(creature) {}

        uint32 Vrazuma_Timer;
        uint32 Nemota_Timer;
        uint32 Slovotbol_Timer;
        uint32 Slovosilishit_Timer;
        uint32 Heal_Timer;
        uint32 Aoefear_Timer;
        uint32 Frostbolt_Timer;
        uint32 Arcaneblast_Timer;
        uint32 Arcaneb_Timer;
        uint32 Priliv_Timer;
        uint32 Metamorph_Timer;
        uint32 Koster_Timer;
        uint32 Shadowbolt_Timer;
        uint32 Porcha_Timer;
        uint32 Agonia_Timer;
        uint32 Tresh_Timer;

        void Reset() {
            Vrazuma_Timer = 20000;
            Nemota_Timer = 30000;
            Slovotbol_Timer = 40000;
            Slovosilishit_Timer = 25000;
            Heal_Timer = 30000;
            Aoefear_Timer = 19000;
            Frostbolt_Timer = 8000;
            Arcaneblast_Timer = 20000;
            Arcaneb_Timer = 35000;
            Priliv_Timer = 21000;
            Metamorph_Timer = 35000;
            Koster_Timer = 36000;
            Shadowbolt_Timer = 18000;
            Porcha_Timer = 15000;
            Agonia_Timer = 45000;
            Tresh_Timer = 70000;
        }

        void EnterCombat(Unit * /*who*/) {
        }

        void SummonTresh(Unit *victim) {
            if (Creature *Tresh = DoSpawnCreature(900001, float(irand(-9, 9)), float(irand(-9, 9)), 0, 0,
                                                  TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 700000))
                Tresh->AI()->AttackStart(victim);
        }

        void UpdateAI(const uint32 diff) {
//Return since we have no target
            if (!UpdateVictim())
                return;

            if (Vrazuma_Timer <= diff) {
                if (Unit *target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                    DoCast(target, SPELL_VRAZUMA);

                Vrazuma_Timer = 20000;
            } else Vrazuma_Timer -= diff;

            if (Nemota_Timer <= diff) {
                if (Unit *target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                    DoCast(target, SPELL_NEMOTA);

                Nemota_Timer = 10000;
            } else Nemota_Timer -= diff;

            if (Slovotbol_Timer <= diff) {
                if (Unit *target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                    DoCast(target, SPELL_SLOVOTBOL);

                Slovotbol_Timer = 10000;
            } else Slovotbol_Timer -= diff;

            if (Slovosilishit_Timer <= diff) {
                DoCast(me, SPELL_SLOVOSILISHIT);
                Slovosilishit_Timer = 25000;
            } else Slovosilishit_Timer -= diff;

            if (Heal_Timer <= diff) {
                DoCast(me, SPELL_HEAL);
                Heal_Timer = 29000;
            } else Heal_Timer -= diff;

            if (Aoefear_Timer <= diff) {
                if (urand(0, 9) < 2)
                    DoCast(me->GetVictim(), SPELL_AOEFEAR);

                Aoefear_Timer = 15000;
            } else Aoefear_Timer -= diff;

            if (Frostbolt_Timer <= diff) {
                if (Unit *target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                    DoCast(target, SPELL_FROSTBOLT);

                Frostbolt_Timer = 7000;
            } else Frostbolt_Timer -= diff;

            if (Arcaneblast_Timer <= diff) {
                if (Unit *target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                    DoCast(target, SPELL_ARCANEBLAST);

                Arcaneblast_Timer = 21000;
            } else Arcaneblast_Timer -= diff;

            if (Arcaneb_Timer <= diff) {
                if (Unit *target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                    DoCast(target, SPELL_ARCANEB);

                Arcaneb_Timer = 15000;
            } else Arcaneb_Timer -= diff;

            if (Priliv_Timer <= diff) {
                DoCast(me, SPELL_PRILIV);
                Priliv_Timer = 26000;
            } else Priliv_Timer -= diff;

            if (Metamorph_Timer <= diff) {
                DoCast(me, SPELL_METAMORPH);
                Metamorph_Timer = 30000;
            } else Metamorph_Timer -= diff;

            if (Koster_Timer <= diff) {
                DoCast(me, SPELL_KOSTER);
                Koster_Timer = 31000;
            } else Koster_Timer -= diff;

            if (Shadowbolt_Timer <= diff) {
                if (Unit *target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                    DoCast(target, SPELL_SHADOWBOLT);

                Shadowbolt_Timer = 32000;
            } else Shadowbolt_Timer -= diff;

            if (Porcha_Timer <= diff) {
                if (Unit *target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                    DoCast(target, SPELL_PORCHA);

                Porcha_Timer = 47000;
            } else Porcha_Timer -= diff;

            if (Agonia_Timer <= diff) {
                if (Unit *target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                    DoCast(target, SPELL_AGONIYA);

                Agonia_Timer = 50000;
            } else Agonia_Timer -= diff;

            if (Tresh_Timer <= diff) {
                SummonTresh(me->GetVictim());
                SummonTresh(me->GetVictim());
                SummonTresh(me->GetVictim());

                Tresh_Timer = 70000;
            } else Tresh_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

class mob_tresh : public CreatureScript {
public:
    mob_tresh() : CreatureScript("mob_tresh") {}

    CreatureAI *GetAI(Creature *creature) const {
        return new mob_treshAI(creature);
    }

    struct mob_treshAI : public ScriptedAI {
        mob_treshAI(Creature *creature) : ScriptedAI(creature) {}

        uint32 Manashield_Timer;
        uint32 Dustdecay_Timer;
        uint32 Shadobolt_Timer;

        void Reset() {
            Manashield_Timer = 180000; //если не убить моба за 3 минуты моб станет бессмертным
            Dustdecay_Timer = 30000;
            Shadobolt_Timer = 10000;
        }

        void UpdateAI(const uint32 diff) {
//Return since we have no target
            if (!UpdateVictim())
                return;

            if (Manashield_Timer <= diff) {
                DoCast(me, SPELL_MANASHIELD);
                Manashield_Timer = 180000;
            } else Manashield_Timer -= diff;

            if (Dustdecay_Timer <= diff) {
                if (Unit *target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                    DoCast(target, SPELL_DUSTDECAY);

                Dustdecay_Timer = 19000;
            } else Dustdecay_Timer -= diff;

            if (Shadobolt_Timer <= diff) {
                if (Unit *target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                    DoCast(target, SPELL_SHADOBOLT);

                Shadobolt_Timer = 10000;
            } else Shadobolt_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_chaoscontrol() {
    new boss_chaoscontrol();
    new mob_tresh();
}
