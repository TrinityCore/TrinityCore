#include "bot_ai.h"
//#include "botmgr.h"
//#include "Group.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
/*
Rogue NpcBot (reworked by Graff onlysuffering@gmail.com)
Complete - 25% maybe...
TODO:
*/
#define DMGMIN              1
#define DMGMAX              2
#define MAX_COMBO_POINTS    5
#define EVISCERATE_MAX_RANK 12
const uint32 EVSCRDamage[EVISCERATE_MAX_RANK+1][MAX_COMBO_POINTS+1][DMGMAX+1] =
{
    { { 0,0,0 }, { 0,0,0 },     { 0,0,0 },      { 0,0,0 },       { 0,0,0 },       { 0,0,0 }       },
    { { 0,0,0 }, { 0,6,11 },    { 0,12,16 },    { 0,17,22 },     { 0,22,28 },     { 0,28,34 }     },
    { { 0,0,0 }, { 0,14,23 },   { 0,26,34 },    { 0,37,46 },     { 0,48,58 },     { 0,60,70 }     },
    { { 0,0,0 }, { 0,25,49 },   { 0,45,59 },    { 0,64,79 },     { 0,83,99 },     { 0,103,119 }   },
    { { 0,0,0 }, { 0,41,62 },   { 0,73,93 },    { 0,104,125 },   { 0,135,157 },   { 0,167,189 }   },
    { { 0,0,0 }, { 0,60,91 },   { 0,106,136 },  { 0,151,182 },   { 0,196,228 },   { 0,242,274 }   },
    { { 0,0,0 }, { 0,93,138 },  { 0,165,209 },  { 0,236,281 },   { 0,307,353 },   { 0,379,425 }   },
    { { 0,0,0 }, { 0,144,213 }, { 0,255,323 },  { 0,365,434 },   { 0,475,545 },   { 0,586,656 }   },
    { { 0,0,0 }, { 0,199,296 }, { 0,351,447 },  { 0,502,599 },   { 0,653,751 },   { 0,805,903 }   },
    { { 0,0,0 }, { 0,224,333 }, { 0,395,503 },  { 0,565,674 },   { 0,735,845 },   { 0,906,1016 }  },
    { { 0,0,0 }, { 0,245,366 }, { 0,431,551 },  { 0,616,737 },   { 0,801,923 },   { 0,987,1109 }  },
    { { 0,0,0 }, { 0,405,614 }, { 0,707,915 },  { 0,1008,1217 }, { 0,1309,1519 }, { 0,1611,1821 } },
    { { 0,0,0 }, { 0,497,752 }, { 0,868,1122 }, { 0,1238,1493 }, { 0,1608,1864 }, { 0,1979,2235 } }
};
#define RUPTURE_MAX_RANK    9
const uint32 RuptureDamage[RUPTURE_MAX_RANK+1][MAX_COMBO_POINTS+1] =
{
    { 0, 0,   0,   0,    0,    0    },
    { 0, 41,  61,  86,   114,  147  },
    { 0, 61,  91,  128,  170,  219  },
    { 0, 89,  131, 182,  240,  307  },
    { 0, 129, 186, 254,  331,  419  },
    { 0, 177, 256, 350,  457,  579  },
    { 0, 273, 381, 506,  646,  803  },
    { 0, 325, 461, 620,  800,  1003 },
    { 0, 489, 686, 914,  1171, 1459 },
    { 0, 581, 816, 1088, 1395, 1739 }
};

class rogue_bot : public CreatureScript
{
public:
    rogue_bot() : CreatureScript("rogue_bot") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new rogue_botAI(creature);
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        return bot_minion_ai::OnGossipHello(player, creature, 0);
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
    {
        if (bot_minion_ai* ai = creature->GetBotMinionAI())
            return ai->OnGossipSelect(player, creature, sender, action);
        return true;
    }

    bool OnGossipSelectCode(Player* player, Creature* creature, uint32 sender, uint32 action, char const* code)
    {
        if (bot_minion_ai* ai = creature->GetBotMinionAI())
            return ai->OnGossipSelectCode(player, creature, sender, action, code);
        return true;
    }

    struct rogue_botAI : public bot_minion_ai
    {
        rogue_botAI(Creature* creature) : bot_minion_ai(creature)
        {
            _botclass = BOT_CLASS_ROGUE;
        }

        bool doCast(Unit* victim, uint32 spellId, bool triggered = false)
        {
            //TC_LOG_ERROR("entities.unit","trying to cast spell %u", spellId);
            if (CheckBotCast(victim, spellId, BOT_CLASS_ROGUE) != SPELL_CAST_OK)
            {
                //TC_LOG_ERROR("entities.unit","failed to cast spell %u with error %u", spellId, CheckBotCast(victim, spellId, BOT_CLASS_ROGUE));
                return false;
            }
            return bot_ai::doCast(victim, spellId, triggered);
        }

        void StartAttack(Unit* u, bool force = false)
        {
            if (GetBotCommandState() == COMMAND_ATTACK && !force) return;
            Aggro(u);
            SetBotCommandState(COMMAND_ATTACK);
            OnStartAttack(u);
            GetInPosition(force);
        }

        void EnterCombat(Unit* u) { bot_minion_ai::EnterCombat(u); }
        void Aggro(Unit*) { }
        void AttackStart(Unit*) { }
        void KilledUnit(Unit*) { }
        void EnterEvadeMode(EvadeReason /*why*/) { bot_minion_ai::EnterEvadeMode(); }
        void MoveInLineOfSight(Unit* u) { bot_minion_ai::MoveInLineOfSight(u); }
        void JustDied(Unit* u) { comboPoints = 0; tempComboPoints = 0; bot_minion_ai::JustDied(u); }
        void DoNonCombatActions(uint32 /*diff*/)
        {}

        //This method should be used to emulate energy usage reduction
        void modenergy(int32 mod, bool set = false)
        {
            //can't set enery to -x (2 cases)
            if (set && mod < 0)
                return;
            if (mod < 0 && energy < uint32(abs(mod)))
            {
                mod = 0;
                set = true;
            }

            if (set)
                energy = mod;
            else
                energy += mod;

            energy = std::min<uint32>(energy, 100);
            me->SetPower(POWER_ENERGY, energy);
        }

        uint32 getenergy()
        {
            energy = me->GetPower(POWER_ENERGY);
            return energy;
        }

        void UpdateAI(uint32 diff)
        {
            me->SetMaxPower(POWER_ENERGY, me->GetCreatePowers(POWER_ENERGY)); 
            ReduceCD(diff);
            if (!GlobalUpdate(diff))
                return;
            CheckAttackState();
            CheckAuras();
            if (wait == 0)
                wait = GetWait();
            else
                return;
            BreakCC(diff);
            if (CCed(me)) return;

            if (Potion_cd <= diff && GetHealthPCT(me) < 67)
            {
                temptimer = GC_Timer;
                if (doCast(me, HEALINGPOTION))
                {
                    Potion_cd = POTION_CD;
                    GC_Timer = temptimer;
                }
            }

            if (!me->IsInCombat())
                DoNonCombatActions(diff);

            if (!CheckAttackTarget(BOT_CLASS_ROGUE))
                return;

            Attack(diff);
        }

        void Attack(uint32 diff)
        {
            opponent = me->GetVictim();
            if (opponent)
            {
                if (!IsCasting())
                    StartAttack(opponent, true);
            }
            else
                return;

            comboPoints = std::min<uint8>(comboPoints, 5);
            //AttackerSet m_attackers = master->getAttackers();
            AttackerSet b_attackers = me->getAttackers();
            float dist = me->GetExactDist(opponent);
            float meleedist = me->GetDistance(opponent);
            //TC_LOG_ERROR("entities.unit","rogue has %u energy", getenergy());
            //Blade Flurry (434 deprecated)
            if (IsSpellReady(BLADE_FLURRY_1, diff, false) && HasRole(BOT_ROLE_DPS) && meleedist <= 5 &&
                Rand() < 30 && getenergy() >= 25 && FindSplashTarget(7, opponent))
            {
                temptimer = GC_Timer;
                if (doCast(me, GetSpell(BLADE_FLURRY_1)))
                {
                    GC_Timer = temptimer;
                    return;
                }
            }

            if (MoveBehind(*opponent))
                wait = 5;

            //KICK
            if (IsSpellReady(KICK_1, diff, false) && meleedist <= 5 && Rand() < 80 && getenergy() >= 25 &&
                opponent->IsNonMeleeSpellCast(false))
            {
                temptimer = GC_Timer;
                if (doCast(opponent, GetSpell(KICK_1)))
                {
                    GC_Timer = temptimer;
                    //return;
                }
            }
            //SHADOWSTEP
            if (IsSpellReady(SHADOWSTEP_1, diff, false) && HasRole(BOT_ROLE_DPS) && dist < 25 &&
                (opponent->GetVictim() != me || opponent->GetTypeId() == TYPEID_PLAYER) &&
                Rand() < 30 && getenergy() >= 10)
            {
                temptimer = GC_Timer;
                if (doCast(opponent, GetSpell(SHADOWSTEP_1)))
                {
                    GC_Timer = temptimer;
                    //return;
                }
            }
            //BACKSTAB
            if (IsSpellReady(BACKSTAB_1, diff) && HasRole(BOT_ROLE_DPS) && meleedist <= 5 && comboPoints < 4 &&
                /*Rand() < 90 && */getenergy() >= 60 && !opponent->HasInArc(M_PI, me))
            {
                if (doCast(opponent, GetSpell(BACKSTAB_1)))
                    return;
            }
            //SINISTER STRIKE
            //TC_LOG_ERROR("entities.unit","rogue has sinisterstrike ready value of %u, and diff is %u and sinistrike strike id is %u and combopoints of %u and has role dps of %u and melee distance of %u", IsSpellReady(SINISTER_STRIKE_1, diff), diff, SINISTER_STRIKE_1, comboPoints,HasRole(BOT_ROLE_DPS), (unsigned int) meleedist);
            if (IsSpellReady(SINISTER_STRIKE_1, diff) && HasRole(BOT_ROLE_DPS) && meleedist <= 5 && comboPoints < 5 &&
                /*Rand() < 25 &&*/ getenergy() >= 45)
            {
                //TC_LOG_ERROR("entities.unit","passed sinister strike checks");
                if (doCast(opponent, GetSpell(SINISTER_STRIKE_1)))
                {
                    //TC_LOG_ERROR("entities.unit","passed docast for sinister strike");
                    return;
                }
            }
            //SLICE AND DICE
            if (IsSpellReady(SLICE_DICE_1, diff) && HasRole(BOT_ROLE_DPS) && dist < 20 && comboPoints > 1 && getenergy() >= 25 &&
                (b_attackers.size() <= 1 || !IsSpellReady(BLADE_FLURRY_1, diff)) && Rand() < 30)
            {
                if (doCast(opponent, GetSpell(SLICE_DICE_1)))
                    return;
            }
            //KIDNEY SHOT
            if (IsSpellReady(KIDNEY_SHOT_1, diff) && meleedist <= 5 && comboPoints > 0 &&
                !CCed(opponent) && getenergy() >= 25 && ((Rand() < 15 + comboPoints*15 && opponent->GetVictim() == me && comboPoints > 2) || opponent->IsNonMeleeSpellCast(false)))
            {
                if (doCast(opponent, GetSpell(KIDNEY_SHOT_1)))
                    return;
            }
            //EVISCERATE
            if (IsSpellReady(EVISCERATE_1, diff) && HasRole(BOT_ROLE_DPS) && meleedist <= 5 && comboPoints > 2 &&
                getenergy() >= 35 && Rand() < comboPoints*15)
            {
                uint32 EVISCERATE = GetSpell(EVISCERATE_1);
                SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(EVISCERATE);
                uint8 rank = spellInfo->GetRank();
                float ap = me->GetTotalAttackPowerValue(BASE_ATTACK);
                float combo = float(comboPoints);
                int32 damage = int32(urand(EVSCRDamage[rank][comboPoints][DMGMIN], EVSCRDamage[rank][comboPoints][DMGMAX]));//base damage
                damage += irand(int32(ap*combo*0.03f), int32(ap*combo*0.07f));//ap bonus

                currentSpell = EVISCERATE;
                me->CastCustomSpell(opponent, EVISCERATE, &damage, NULL, NULL, false);
                return;
            }
            //MUTILATE
            //if (isTimerReady(Mutilate_Timer) && energy>60)
            //{
            //    // TODO: calculate correct dmg for mutilate (dont forget poison bonus)
            //    // for now use same formula as evicerate
            //    uint32 base_attPower = me->GetUInt32Value(UNIT_FIELD_ATTACK_POWER);
            //    //float minDmg = me->GetFloatValue(UNIT_FIELD_MINDAMAGE);
            //    float minDmg = me->GetWeaponDamageRange(BASE_ATTACK, MINDAMAGE);
            //    int damage = irand(int32(base_attPower*7*0.03f),int32(base_attPower*7*0.08f))+minDmg+me->getLevel();

            //    // compensate for lack of attack power
            //    damage = damage*(rand()%4+1);

            //    me->CastCustomSpell(opponent, MUTILATE, &damage, NULL, NULL, false, NULL, NULL);

            //    //doCast (me, MUTILATE);
            //    Mutilate_Timer = 10;
            //    comboPoints+=3;
            //    energy -= 60;
            //}

            //RUPTURE
            if (IsSpellReady(RUPTURE_1, diff) && HasRole(BOT_ROLE_DPS) && meleedist <= 5 && comboPoints > 3 && getenergy() >= 25 &&
                opponent->GetHealth() > me->GetMaxHealth()/3 && Rand() < (50 + 70 * opponent->isMoving()))
            {
                uint32 RUPTURE = GetSpell(RUPTURE_1);
                //no damage range for rupture
                SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(RUPTURE);
                uint8 rank = spellInfo->GetRank();
                float ap = me->GetTotalAttackPowerValue(BASE_ATTACK);
                float AP_per_combo[6] = {0.0f, 0.015f, 0.024f, 0.03f, 0.03428571f, 0.0375f};
                float divider[6] = {0.0f, 4.f, 5.f, 6.f, 7.f, 8.f};//duration/2 = number of ticks
                int32 damage = int32(RuptureDamage[rank][comboPoints]/divider[comboPoints]);//base damage
                damage += int32(ap*AP_per_combo[comboPoints]);//ap bonus is strict - applied to every tick

                currentSpell = RUPTURE;
                me->CastCustomSpell(opponent, RUPTURE, &damage, NULL, NULL, false);
                return;
            }
            //DISMANTLE
            if (IsSpellReady(DISMANTLE_1, diff, false) && meleedist <= 5 && opponent->GetTypeId() == TYPEID_PLAYER &&
                Rand() < 20 && getenergy() >= 25 && !CCed(opponent) && !opponent->HasAuraType(SPELL_AURA_MOD_DISARM) &&
                (opponent->ToPlayer()->GetWeaponForAttack(BASE_ATTACK) || opponent->ToPlayer()->GetWeaponForAttack(RANGED_ATTACK)))
            {
                temptimer = GC_Timer;
                if (doCast(opponent, GetSpell(DISMANTLE_1)))
                {
                    GC_Timer = temptimer;
                    return;
                }
            }
        }

        void ApplyClassDamageMultiplierMelee(int32& damage, SpellNonMeleeDamage& /*damageinfo*/, SpellInfo const* spellInfo, WeaponAttackType /*attackType*/, bool& crit) const
        {
            uint32 spellId = spellInfo->Id;
            uint8 lvl = me->getLevel();
            float fdamage = float(damage);
            //1) apply additional crit chance. This additional chance roll will replace original (balance safe)
            if (!crit)
            {
                float aftercrit = 0.f;
                //Puncturing Wounds: 30% additional critical chance for Backstab
                if (lvl >= 15 && spellId == GetSpell(BACKSTAB_1))
                    aftercrit += 30.f;
                //Puncturing Wounds: 15% additional critical chance for Mutilate
                else if (spellId == GetSpell(MUTILATE_1))
                    aftercrit += 15.f;
                //Glyph of Eviscerate: 10% additional critical chance for Eviscerate
                else if (spellId == GetSpell(EVISCERATE_1))
                    aftercrit += 10.f;
                //Improved Ambush: 60% additional critical chance for Ambush
                //else if (spellId == AMBUSH)
                //    crit_chance += 60.f;
                if (lvl >= 50 && spellInfo->HasEffect(SPELL_EFFECT_ADD_COMBO_POINTS) && me->HasAura(TURN_THE_TABLES_EFFECT))
                    aftercrit += 6.f;

                //second roll (may be illogical)
                if (aftercrit > 0.f)
                    crit = roll_chance_f(aftercrit);
            }

            //2) apply bonus damage mods
            float pctbonus = 0.0f;
            if (crit)
            {
                //!!!Melee spell damage is not yet critical, all reduced by half
                //Lethality: 30% crit damage bonus for non-stealth combo-generating abilities (on 25 lvl)
                if (lvl >= 25 && !(spellInfo->Attributes & SPELL_ATTR0_ONLY_STEALTHED) &&
                    spellInfo->HasEffect(SPELL_EFFECT_ADD_COMBO_POINTS))
                    pctbonus += 0.15f;
            }
            //Shadowstep: 20% bonus damage to all abilities once
            //if (shadowstep == true)
            //{
            //    shadowstep = false;
            //    me->RemoveAurasDueToSpell(SHADOWSTEP_EFFECT_DAMAGE);
            //    pctbonus += 0.2f;
            //}
            //Find Weakness: 6% bonus damage to all abilities
            if (lvl >= 45)
                pctbonus += 0.06f;
            //DeathDealer set bonus: 15% damage bonus for Eviscerate
            if (lvl >= 60 && spellId == GetSpell(EVISCERATE_1))
                pctbonus += 0.15f;
            //Imoroved Eviscerate: 20% damage bonus for Eviscerate
            if (spellId == GetSpell(EVISCERATE_1))
                pctbonus += 0.2f;
            //Opportunity: 20% damage bonus for Backstab, Mutilate, Garrote and Ambush
            if (spellId == GetSpell(BACKSTAB_1) || spellId == GetSpell(MUTILATE_1)/* ||
                spellId == GARROTE || spellId == AMBUSH*/)
                pctbonus += 0.2f;
            //Aggression: 15% damage bonus for Sinister Strike, Backstab and Eviscerate
            if (lvl >= 30 && (spellId == GetSpell(SINISTER_STRIKE_1) || spellId == GetSpell(BACKSTAB_1) || spellId == GetSpell(EVISCERATE_1)))
                pctbonus += 0.15f;
            //Blood Spatter: 30% bonus damage for Rupture and Garrote
            if (lvl >= 15 && (spellId == GetSpell(RUPTURE_1)/* || spellId == GARROTE*/))
                pctbonus += 0.3f;
            //Serrated Blades: 30% bonus damage for Rupture
            if (lvl >= 20 && spellId == GetSpell(RUPTURE_1))
                pctbonus += 0.3f;
            //Surprise Attacks: 10% bonus damage for Sinister Strike, Backstab, Shiv, Hemmorhage and Gouge
            if (lvl >= 50 && (spellId == GetSpell(SINISTER_STRIKE_1) || spellId == GetSpell(BACKSTAB_1)/* ||
                spellId == SHIV || spellId == HEMMORHAGE || spellId == GOUGE*/))
                pctbonus += 0.1f;

            damage = int32(fdamage * (1.0f + pctbonus));
        }

        void DamageDealt(Unit* victim, uint32& damage, DamageEffectType damageType)
        {
            uint32 WOUND_POISON = GetSpell(WOUND_POISON_1);
            uint32 MIND_NUMBING_POISON = GetSpell(MIND_NUMBING_POISON_1);
            if (!WOUND_POISON && !MIND_NUMBING_POISON)
                return;

            if (damageType == DIRECT_DAMAGE || damageType == SPELL_DIRECT_DAMAGE)
            {
                if (victim && me->GetExactDist(victim) <= 40)
                {
                    switch (rand()%2)
                    {
                        case 0:
                            break;
                        case 1:
                        {
                            switch (rand()%2)
                            {
                                case 0:
                                    if (WOUND_POISON)
                                    {
                                        currentSpell = WOUND_POISON;
                                        DoCast(victim, WOUND_POISON, true);
                                    }
                                    break;
                                case 1:
                                    if (MIND_NUMBING_POISON)
                                    {
                                        currentSpell = MIND_NUMBING_POISON;
                                        DoCast(victim, MIND_NUMBING_POISON, true);
                                    }
                                    break;
                            }
                        }
                    }
                }
            }

            bot_ai::DamageDealt(victim, damage, damageType);
        }

        void SpellHit(Unit* caster, SpellInfo const* spell)
        {
            OnSpellHit(caster, spell);
        }

        void SpellHitTarget(Unit* target, SpellInfo const* spell)
        {
            uint32 spellId = spell->Id;

            //combo points use up
            if (spellId == GetSpell(SLICE_DICE_1))
            {
                SetSpellCooldown(SLICE_DICE_1, 15000 + (tempComboPoints-1)*4500); //no initial cooldown
                GC_Timer = 800;

                if (Aura* dice = me->GetAura(GetSpell(SLICE_DICE_1)))
                {
                    uint32 dur = dice->GetDuration();
                    dur += tempComboPoints * 3000; //use cp
                    dur += 6000; // Glyph of Slice and Dice
                    dur = (dur * 3) / 2; //Improved Slice and Dice
                    dice->SetDuration(dur);
                    dice->SetMaxDuration(dur);
                }
            }
            else if (spellId == GetSpell(RUPTURE_1))
            {
                SetSpellCooldown(RUPTURE_1, 8000 + (tempComboPoints-1)*2000 + 4000); //no initial cooldown
                GC_Timer = 800;

                if (Aura* rupture = target->GetAura(GetSpell(RUPTURE_1), me->GetGUID()))
                {
                    uint32 dur = rupture->GetDuration() + tempComboPoints*2000; //use cp
                    dur += 4000; //Glyph of Rupture
                    rupture->SetDuration(dur);
                    rupture->SetMaxDuration(dur);
                }
            }
            else if (spellId == GetSpell(KIDNEY_SHOT_1))
            {
                if (Aura* kidney = target->GetAura(GetSpell(KIDNEY_SHOT_1), me->GetGUID()))
                {
                    uint32 dur = kidney->GetDuration() + tempComboPoints*1000;
                    kidney->SetDuration(dur);
                    kidney->SetMaxDuration(dur);
                }
            }

            if (currentSpell == 0)
                return;

            //BONUS CP MANAGEMENT

            //if (spellId == EVISCERATE || spellId == KIDNEY_SHOT || spellId == SLICE_DICE || spellId == RUPTURE/* || spellId == EXPOSE_ARMOR || spellId == ENVENOM*/)
            //Relentless Strikes
            if (spell->NeedsComboPoints())
            {
                //std::ostringstream msg;
                //msg << "casting ";
                //if (spellId == EVISCERATE)
                //    msg << "Eviscerate, ";
                //else if (spellId == RUPTURE)
                //    msg << "Rupture, ";
                //else if (spellId == SLICE_DICE)
                //    msg << "Slice and Dice, ";
                //else if (spellId == KIDNEY_SHOT)
                //    msg << "Kidney Shot, ";
                ////else if (spellId == EXPOSE_ARMOR)
                ////    msg << "Expose Armor, ";
                ////else if (spellId == ENVENOM)
                ////    msg << "Envenom, ";
                //msg << "combo points: " << uint32(std::min<uint32>(comboPoints,5));
                //me->MonsterWhisper(msg.str().c_str(), master->GetGUID());
                if (irand(0, 99) < 20 * (comboPoints > 5 ? 5 : comboPoints))
                {
                    currentSpell = RELENTLESS_STRIKES_EFFECT;
                    DoCast(me, RELENTLESS_STRIKES_EFFECT, true);
                }
                tempComboPoints = comboPoints;
                //CP adding effects are handled before actual finisher so use temp value
                //std::ostringstream msg2;
                //msg2 << "cp set to 0";
                if (tempAddCP)
                {
                    //msg2 << " + " << uint32(tempAddCP) << " (temp)";
                    comboPoints = tempAddCP;
                    tempAddCP = 0;
                }
                else
                    comboPoints = 0;
                //me->MonsterWhisper(msg2.str().c_str(), master->GetGUID());
            }
            else if (spellId == GetSpell(SINISTER_STRIKE_1) ||
                spellId == GetSpell(BACKSTAB_1)/* ||
                spellId == GOUGE ||
                spellId == HEMORRHAGE*/)
            {
                ++comboPoints;
                //std::ostringstream msg;
                //msg << "1 cp generated ";
                //if (spellId == SINISTER_STRIKE)
                //    msg << "(Sinister Strike)";
                //else if (spellId == BACKSTAB)
                //    msg << "(Backstab)";
                //msg << " set to " << uint32(comboPoints);
                //if (tempAddCP)
                //    msg << " + " << uint32(tempAddCP) << " (triggered)";
                //me->MonsterWhisper(msg.str().c_str(), master->GetGUID());
                if (tempAddCP)
                {
                    comboPoints += tempAddCP;
                    tempAddCP = 0;
                }
            }
            else if (spellId == GetSpell(MUTILATE_1)/* ||
                spellId == AMBUSH*/)
            {
                comboPoints += 2;
                //std::ostringstream msg;
                //msg << "2 cp generated (Mutilate), set to " << uint32(comboPoints);
                //if (tempAddCP)
                //    msg << " + " << uint32(tempAddCP) << " (triggered)";
                //me->MonsterWhisper(msg.str().c_str(), master->GetGUID());
                if (tempAddCP)
                {
                    comboPoints += tempAddCP;
                    tempAddCP = 0;
                }
            }
            else if (spellId == SEAL_FATE_EFFECT || spellId == RUTHLESSNESS_EFFECT)
            {
                ++tempAddCP;
                //std::ostringstream msg;
                //msg << "1 temp cp generated ";
                //if (spellId == SEAL_FATE_EFFECT)
                //    msg << "(Seal Fate)";
                //else if (spellId == RUTHLESSNESS_EFFECT)
                //    msg << "(Ruthleness)";
                //me->MonsterWhisper(msg.str().c_str(), master->GetGUID());
            }

            //Glyph of Sinister Strike (20% to add cp on hit)
            //Seal Fate means crit so this glyph is enabled from lvl 35)
            //as addition always add cp on ss crit
            if (currentSpell == GetSpell(SINISTER_STRIKE_1) && (spellId == SEAL_FATE_EFFECT || urand(0,100) >= 20))
            {
                ++tempAddCP;
                //me->MonsterWhisper("1 temp cp generated (glyph of SS)", master->GetGUID());
            }

            //ENERGY COST REDUCTION

            if (spellId == GetSpell(SINISTER_STRIKE_1))
            {
                //Improved Sinister Strike
                //instead of restoring energy we should override current value
                if (me->getLevel() >= 10)
                    modenergy(-40, true);//45 - 5
            }
            //Slaughter from the Shadows energy restore
            //instead of restoring energy we should override current value
            if (me->getLevel() >= 55)
            {
                if (spellId == GetSpell(BACKSTAB_1)/* || spellId == AMBUSH*/)
                    modenergy(-40, true);
                //else if (spellId == HEMORRHAGE)
                //    modenergy(-30, true);
            }

            //OTHER

            if (spellId == GetSpell(EVISCERATE_1))
            {
                //Eviscerate speedup
                GC_Timer = 800;

                //Serrated Blades: Eviscerate has 20% chance per cp to refresh Rupture
                //getting cheaty - remove roll
                //getting cheaty - increase duration
                //if (irand(0, 99) < 20 * (comboPoints > 5 ? 5 : comboPoints))
                {
                    if (Aura* rupture = target->GetAura(GetSpell(RUPTURE_1), me->GetGUID()))
                    {
                        int32 dur = rupture->GetMaxDuration() + 2000;
                        dur = std::min<int32>(dur, 30000);
                        rupture->SetDuration(dur);
                        rupture->SetMaxDuration(dur);
                        SetSpellCooldown(RUPTURE_1, dur - 2000); //no initial cooldown
                    }
                }
            }

            //Cut to the Chase: Eviscerate and Envenom will refresh Slice and Dice duration
            //getting cheaty - increase duration
            if (spellId == GetSpell(EVISCERATE_1)/* || spellId == ENVENOM*/)
            {
                if (Aura* dice = me->GetAura(GetSpell(SLICE_DICE_1)))
                {
                    int32 dur = dice->GetMaxDuration() + 2000;
                    dur = std::min<int32>(dur, 59000);
                    dice->SetDuration(dur);
                    dice->SetMaxDuration(dur);
                    SetSpellCooldown(SLICE_DICE_1, dur - 2000); //no initial cooldown
                }
            }

            //Murderous Intent: When Backstabbing enemy that is below 35% hp, instantly restoring 30 energy
            if (spellId == GetSpell(BACKSTAB_1))
            {
                if (target->HealthBelowPct(35))
                {
                    //since talent doesn't work just restore energy manually
                    //DoCast(me, MURDEROUS_INTENT_EFFECT, true);
                    modenergy(30);
                }
            }

            //Waylay
            if ((spellId == GetSpell(BACKSTAB_1)/* || spellId == AMBUSH*/) &&
                me->getLevel() >= 20)
            {
                DoCast(target, WAYLAY_EFFECT, true);
            }

            //if (spellId == SHADOWSTEP)
            //{
            //    Shadowstep_eff_Timer = 10000;
            //    shadowstep = true;
            //}

            //move behind on Kidney Shot and Gouge (optionally)
            if (spellId == GetSpell(KIDNEY_SHOT_1)/* || spellId == GOUGE*/)
                if (MoveBehind(*target))
                    wait = 3;

            if (spellId == currentSpell)
                currentSpell = 0;
        }

        void DamageTaken(Unit* u, uint32& /*damage*/)
        {
            if (!u->IsInCombat() && !me->IsInCombat())
                return;
            OnOwnerDamagedBy(u);
        }

        void OwnerAttackedBy(Unit* u)
        {
            OnOwnerDamagedBy(u);
        }

        void Reset()
        {
            comboPoints = 0;
            tempComboPoints = 0;
            tempAddCP = 0;

            tempDICE = false;
            //shadowstep = false;

            me->setPowerType(POWER_ENERGY);
            //10 energy gained per stack
            DefaultInit();

            RefreshAura(GLADIATOR_VIGOR, 10);
            me->SetMaxPower(POWER_ENERGY, me->GetCreatePowers(POWER_ENERGY)); 
            me->SetPower(POWER_ENERGY, me->GetMaxPower(POWER_ENERGY));
        }

        void ReduceCD(uint32 /*diff*/)
        {
            //if (Shadowstep_eff_Timer > diff)        Shadowstep_eff_Timer -= diff;
            //else if (shadowstep)                    shadowstep = false;
        }

        void InitSpells()
        {
            uint8 lvl = me->getLevel();
            InitSpellMap(BACKSTAB_1);
            InitSpellMap(SINISTER_STRIKE_1);
            InitSpellMap(SLICE_DICE_1);
            InitSpellMap(EVISCERATE_1);
            InitSpellMap(KICK_1);
            InitSpellMap(RUPTURE_1);
            InitSpellMap(KIDNEY_SHOT_1);
            lvl >= 50 ? InitSpellMap(MUTILATE_1) : RemoveSpell(MUTILATE_1);
            lvl >= 50 ? InitSpellMap(SHADOWSTEP_1) : RemoveSpell(SHADOWSTEP_1);
            InitSpellMap(DISMANTLE_1);
            lvl >= 30 ? InitSpellMap(BLADE_FLURRY_1) : RemoveSpell(BLADE_FLURRY_1);

            InitSpellMap(WOUND_POISON_1);
            InitSpellMap(MIND_NUMBING_POISON_1);
        }

        void ApplyClassPassives()
        {
            uint8 level = master->getLevel();

            RefreshAura(COMBAT_POTENCY5, level >= 70 ? 2 : level >= 55 ? 1 : 0);
            RefreshAura(COMBAT_POTENCY4, level >= 52 && level < 55 ? 1 : 0);
            RefreshAura(COMBAT_POTENCY3, level >= 49 && level < 52 ? 1 : 0);
            RefreshAura(COMBAT_POTENCY2, level >= 47 && level < 49 ? 1 : 0);
            RefreshAura(COMBAT_POTENCY1, level >= 45 && level < 47 ? 1 : 0);
            RefreshAura(SEAL_FATE5, level >= 35 ? 1 : 0);
            RefreshAura(SEAL_FATE4, level >= 32 && level < 35 ? 1 : 0);
            RefreshAura(SEAL_FATE3, level >= 29 && level < 32 ? 1 : 0);
            RefreshAura(SEAL_FATE2, level >= 27 && level < 29 ? 1 : 0);
            RefreshAura(SEAL_FATE1, level >= 25 && level < 27 ? 1 : 0);
            RefreshAura(VITALITY, level >= 70 ? 3 : level >= 55 ? 2 : level >= 40 ? 1 : 0);
            RefreshAura(TURN_THE_TABLES, level >= 55 ? 1 : 0);
            RefreshAura(DEADLY_BREW, level >= 40 ? 1 : 0);
            RefreshAura(BLADE_TWISTING1, level >= 35 ? 1 : 0);
            RefreshAura(QUICK_RECOVERY2, level >= 35 ? 1 : 0);
            RefreshAura(QUICK_RECOVERY1, level >= 30 && level < 35 ? 1 : 0);
            RefreshAura(IMPROVED_KIDNEY_SHOT, level >= 30 ? 1 : 0);
            RefreshAura(GLYPH_BACKSTAB, level >= 10 ? 1 : 0);
            RefreshAura(SURPRISE_ATTACKS, level >= 10 ? 1 : 0);
            RefreshAura(ROGUE_VIGOR, level >= 25 ? 2 : level >= 20 ? 1 : 0);
        }

    private:
        uint32 energy;
        uint8 comboPoints, tempComboPoints, tempAddCP;
        bool tempDICE/*, shadowstep*/;

        enum RogueBaseSpells
        {
            BACKSTAB_1                          = 53,
            SINISTER_STRIKE_1                   = 1752,
            SLICE_DICE_1                        = 5171,
            EVISCERATE_1                        = 2098,
            KICK_1                              = 1766,
            RUPTURE_1                           = 1943,
            KIDNEY_SHOT_1                       = 408,
  /*Talent*/MUTILATE_1                          = 1329,
  /*Talent*/SHADOWSTEP_1                        = 36554,
            DISMANTLE_1                         = 51722,
            BLADE_FLURRY_1                      = 13877,
        //Special
            WOUND_POISON_1                      = 13218,
            MIND_NUMBING_POISON_1               = 5760
        };

        enum RoguePassives
        {
            //Talents
            SEAL_FATE1                          = 14189,
            SEAL_FATE2                          = 14190,
            SEAL_FATE3                          = 14193,
            SEAL_FATE4                          = 14194,
            SEAL_FATE5                          = 14195,
            COMBAT_POTENCY1                     = 35541,
            COMBAT_POTENCY2                     = 35550,
            COMBAT_POTENCY3                     = 35551,
            COMBAT_POTENCY4                     = 35552,
            COMBAT_POTENCY5                     = 35553,
            QUICK_RECOVERY1                     = 31244,
            QUICK_RECOVERY2                     = 31245,
            BLADE_TWISTING1                     = 31124,
            //BLADE_TWISTING2                     = 31126,
            VITALITY                            = 61329,//rank 3
            DEADLY_BREW                         = 51626,//rank 2
            IMPROVED_KIDNEY_SHOT                = 14176,//rank 3
            TURN_THE_TABLES                     = 51629,//rank 3
            SURPRISE_ATTACKS                    = 32601,
            ROGUE_VIGOR                         = 14983,
            //Other
            //ROGUE_ARMOR_ENERGIZE/*Deathmantle*/ = 27787,
            GLADIATOR_VIGOR                     = 21975,
            GLYPH_BACKSTAB                      = 56800
        };

        enum RogueSpecial
        {
            RELENTLESS_STRIKES_EFFECT           = 14181,
            RUTHLESSNESS_EFFECT                 = 14157,
            SEAL_FATE_EFFECT                    = 14189,
            //SHADOWSTEP_EFFECT_DAMAGE            = 36563,
            TURN_THE_TABLES_EFFECT              = 52910,//'rank 3'
            WAYLAY_EFFECT                       = 51693,
            //434
            MURDEROUS_INTENT_EFFECT             = 79132
        };
    };
};

void AddSC_rogue_bot()
{
    new rogue_bot();
}
