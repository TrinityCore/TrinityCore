#include "bot_ai.h"
#include "botmgr.h"
#include "Group.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SpellAuraEffects.h"
#include "Map.h"
//#include "WorldSession.h"
/*
Paladin NpcBot (reworked by Graff onlysuffering@gmail.com)
Complete - Around 45-50%
TODO: Tanking, Shield Abilities, Auras
*/
class paladin_bot : public CreatureScript
{
public:
    paladin_bot() : CreatureScript("paladin_bot") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new paladin_botAI(creature);
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

    struct paladin_botAI : public bot_minion_ai
    {
        paladin_botAI(Creature* creature) : bot_minion_ai(creature)
        {
            _botclass = BOT_CLASS_PALADIN;
        }

        bool doCast(Unit* victim, uint32 spellId, bool triggered = false)
        {
            if (CheckBotCast(victim, spellId, BOT_CLASS_PALADIN) != SPELL_CAST_OK)
                return false;
            return bot_ai::doCast(victim, spellId, triggered);
        }

        void HOFGroup(Player* pTarget, uint32 diff)
        {
            if (!IsSpellReady(HOF_1, diff) || IAmFree() || IsCasting() || Rand() > 60)
                return;

            if (Group* pGroup = pTarget->GetGroup())
            {
                for (GroupReference* itr = pGroup->GetFirstMember(); itr != NULL; itr = itr->next())
                {
                    Player* tPlayer = itr->GetSource();
                    if (!tPlayer) continue;
                    if (HOFTarget(tPlayer, diff))
                        return;
                }
                for (GroupReference* itr = pGroup->GetFirstMember(); itr != NULL; itr = itr->next())
                {
                    Player* tPlayer = itr->GetSource();
                    if (!tPlayer || !tPlayer->HaveBot()) continue;
                    BotMap const* map = tPlayer->GetBotMgr()->GetBotMap();
                    for (BotMap::const_iterator it = map->begin(); it != map->end(); ++it)
                    {
                        Creature* cre = it->second;
                        if (!cre || !cre->IsInWorld()) continue;
                        if (HOFTarget(cre, diff))
                            return;
                    }
                }
            }
        }

        bool HOFTarget(Unit* target, uint32 diff)
        {
            if (!target || target->isDead()) return false;
            if (!IsSpellReady(HOF_1, diff)) return false;
            if (target->ToCreature() && Rand() > 25) return false;
            if (me->GetExactDist(target) > 30) return false;//too far away
            if (HasAuraName(target, HOF_1)) return false;     //Alredy has HOF

            Unit::AuraMap const &auras = target->GetOwnedAuras();
            for (Unit::AuraMap::const_iterator i = auras.begin(); i != auras.end(); ++i)
            {
                Aura* aura = i->second;
                if (aura->IsPassive()) continue;//most
                if (aura->GetDuration() < 2000) continue;
                if (AuraApplication* app = aura->GetApplicationOfTarget(target->GetGUID()))
                    if (app->IsPositive()) continue;
                SpellInfo const* spellInfo = aura->GetSpellInfo();
                if (spellInfo->AttributesEx & SPELL_ATTR0_HIDDEN_CLIENTSIDE) continue;
                //if (spellInfo->AttributesEx & SPELL_ATTR1_DONT_DISPLAY_IN_AURA_BAR) continue;
                if (me->getLevel() >= 40 && (spellInfo->GetAllEffectsMechanicMask() & (1<<MECHANIC_STUN)))
                {
                    if (doCast(target, GetSpell(HOF_1)))
                        return true;
                }
       /*else */if (spellInfo->GetAllEffectsMechanicMask() & (1<<MECHANIC_SNARE) ||
                    spellInfo->GetAllEffectsMechanicMask() & (1<<MECHANIC_ROOT))
                {
                    uint32 spell = GetSpell(CLEANSE_1) &&
                        (spellInfo->Dispel == DISPEL_MAGIC ||
                        spellInfo->Dispel == DISPEL_DISEASE ||
                        spellInfo->Dispel == DISPEL_POISON) ? GetSpell(CLEANSE_1) : GetSpell(HOF_1);

                    if (doCast(target, spell))
                        return true;
                }
            }
            return false;
        }

        void HOSGroup(Player* hTarget, uint32 diff)
        {
            if (!IsSpellReady(HOS_1, diff) || IAmFree() || IsCasting() || Rand() > 30)
                return;

            if (Group* pGroup = hTarget->GetGroup())
            {
                bool bots = false;
                float threat;
                for (GroupReference* itr = pGroup->GetFirstMember(); itr != NULL; itr = itr->next())
                {
                    Player* HOSPlayer = itr->GetSource();
                    if (!HOSPlayer) continue;
                    if (HOSPlayer->HaveBot())
                        bots = true;
                    if (HOSPlayer->isDead()) continue;
                    if (IsTank(HOSPlayer)) continue; //tanks do not need it
                    if (!HOSPlayer->IsInWorld() || master->GetMap() != HOSPlayer->FindMap() || me->GetExactDist(HOSPlayer) > 30) continue;
                    if (HasAuraName(HOSPlayer, HOS_1)) continue;
                    AttackerSet h_attackers = HOSPlayer->getAttackers();
                    if (h_attackers.empty()) continue;
                    for (AttackerSet::iterator iter = h_attackers.begin(); iter != h_attackers.end(); ++iter)
                    {
                        if (!(*iter)) continue;
                        if ((*iter)->isDead()) continue;
                        if (!(*iter)->CanHaveThreatList()) continue;
                        threat = (*iter)->GetThreatManager().getThreat(HOSPlayer);
                        if (threat < 25.f) continue;//too small threat
                        if ((*iter)->getAttackers().size() < 2) continue;//would be useless
                        if (HOSPlayer->GetDistance((*iter)) > 10) continue;
                        if (HOSTarget(HOSPlayer, diff))
                            return;
                    }//end for
                }//end for
                if (!bots) return;
                for (GroupReference* itr = pGroup->GetFirstMember(); itr != NULL; itr = itr->next())
                {
                    Player* pl = itr->GetSource();
                    if (!pl) continue;
                    if (!pl->HaveBot()) continue;
                    if (master->GetMap() != pl->FindMap()) continue;
                    if (!pl->IsInWorld() || pl->IsBeingTeleported()) continue;
                    BotMap const* map = pl->GetBotMgr()->GetBotMap();
                    for (BotMap::const_iterator it = map->begin(); it != map->end(); ++it)
                    {
                        Creature* cre = it->second;
                        if (!cre || cre->isDead()) continue;
                        if (IsTank(cre)) continue;
                        if (me->GetExactDist(cre) > 30) continue;
                        if (HasAuraName(cre, HOS_1)) continue; //Alredy has HOS
                        AttackerSet h_attackers = cre->getAttackers();
                        if (h_attackers.empty()) continue;
                        for (AttackerSet::iterator iter = h_attackers.begin(); iter != h_attackers.end(); ++iter)
                        {
                            if (!(*iter)) continue;
                            if ((*iter)->isDead()) continue;
                            if (!(*iter)->CanHaveThreatList()) continue;
                            threat = (*iter)->GetThreatManager().getThreat(cre);
                            if (threat < 25.f) continue;//too small threat
                            if ((*iter)->getAttackers().size() < 2) continue;//would be useless
                            if (cre->GetDistance((*iter)) > 10) continue;
                            if (HOSTarget(cre, diff))
                                return;
                        }//end for
                    }//end for
                }//end for
            }//end if
        }

        bool HOSTarget(Unit* target, uint32 diff)
        {
            if (!target || target->isDead()) return false;
            if (!IsSpellReady(HOS_1, diff) || Rand() > 50) return false;
            if (IsTank(target)) return false; //tanks do not need it
            if (IsCasting()) return false; //I'm busy casting
            if (me->GetExactDist(target) > 30) return false; //too far away
            if (HasAuraName(target, HOS_1)) return false; //Alredy has HOS

            AttackerSet h_attackers = target->getAttackers();
            if (h_attackers.empty()) return false; //no aggro
            float threat;
            uint8 Tattackers = 0;
            for (AttackerSet::iterator iter = h_attackers.begin(); iter != h_attackers.end(); ++iter)
            {
                if (!(*iter)) continue;
                if ((*iter)->isDead()) continue;
                if (!(*iter)->CanHaveThreatList()) continue;
                threat = (*iter)->GetThreatManager().getThreat(target);
                if (threat < 25.f) continue; //too small threat
                if ((*iter)->getAttackers().size() < 2) continue;//would be useless
                if (target->GetDistance((*iter)) <= 10)
                    Tattackers++;
            }
            if (Tattackers > 0 && doCast(target, GetSpell(HOS_1)))
            {
                for (AttackerSet::iterator iter = h_attackers.begin(); iter != h_attackers.end(); ++iter)
                    if ((*iter)->GetThreatManager().getThreat(target) > 0.f)
                        (*iter)->GetThreatManager().ModifyThreatByPercent(target, -(30 + 50*(target->HasAura(586)))); //Fade
                return true;
            }
            return false;
        }
        //Holy_Shock setup (Modify HERE)
        bool HS(Unit* target, uint32 diff)
        {
            if (!target || target->isDead()) return false;
            if (!IsSpellReady(HOLY_SHOCK_1, diff)) return false;
            if (IsCasting()) return false;
            if (target->GetTypeId() == TYPEID_PLAYER && (target->IsCharmed() || target->isPossessed()))
                return false; //do not damage friends under control
            if (me->GetExactDist(target) > 40) return false;

            if (doCast(target, GetSpell(HOLY_SHOCK_1)))
            {
                if (urand(1,100) <= 20) //Daybreak: 20% to not trigger HS CD, only GCD
                    ResetSpellCooldown(HOLY_SHOCK_1);
                return true;
            }
            return false;
        }

        bool HealTarget(Unit* target, uint8 hp, uint32 diff)
        {
            if (!HasRole(BOT_ROLE_HEAL)) return false;
            if (!target || target->isDead()) return false;
            if (hp > 97) return false;
            //sLog->outBasic("HealTarget() by %s on %s", me->GetName().c_str(), target->GetName().c_str());
            if (Rand() > 40 + 20*target->IsInCombat() + 50*master->GetMap()->IsRaid()) return false;
            if (me->GetExactDist(target) > 35) return false;
            if (IsCasting()) return false;
            if (IsSpellReady(HAND_OF_PROTECTION_1, diff, false) && target->GetTypeId() == TYPEID_PLAYER &&
                IsInBotParty(target) &&
                ((hp < 30 && !target->getAttackers().empty()) || (hp < 50 && target->getAttackers().size() > 3)) &&
                me->GetExactDist(target) < 30 &&
                !HasAuraName(target, HAND_OF_PROTECTION_1) &&
                !HasAuraName(target, FORBEARANCE_AURA))
            {
                if (doCast(target, GetSpell(HAND_OF_PROTECTION_1)))
                {
                    BotWhisper("BOP on you!", target->ToPlayer());

                    //debug
                    if (!HasAuraName(target, FORBEARANCE_AURA))
                        me->AddAura(FORBEARANCE_AURA, target);
                    if (HasAuraName(target, FORBEARANCE_AURA) && !HasAuraName(target, HAND_OF_PROTECTION_1))
                        me->AddAura(GetSpell(HAND_OF_PROTECTION_1), target);
                }
                return true;
            }
            else if (hp < 20 && !HasAuraName(target, HAND_OF_PROTECTION_1))
            {
                // 20% to cast loh, else just do a Shock
                switch (rand()%3)
                {
                    case 1:
                        if (IsSpellReady(LAY_ON_HANDS_1, diff, false) && hp < 20 &&
                            target->GetTypeId() == TYPEID_PLAYER &&
                            (target->IsInCombat() || !target->getAttackers().empty()) &&
                            !HasAuraName(target, FORBEARANCE_AURA))
                        {
                            if (doCast(target, GetSpell(LAY_ON_HANDS_1)))
                            {
                                BotWhisper("Lay of Hands on you!", target->ToPlayer());
                                return true;
                            }
                        }
                    case 2:
                        if (GC_Timer > diff) return false;
                        if (doCast(target, GetSpell(FLASH_OF_LIGHT_1), me->HasAura(THE_ART_OF_WAR_BUFF)))
                            return true;
                    case 3:
                        if (GC_Timer > diff) return false;
                        if (HS(target, diff))
                            return true;
                }
            }

            Unit* u = target->GetVictim();
            if (IsSpellReady(SACRED_SHIELD_1, diff) && !IAmFree() && target->GetTypeId() == TYPEID_PLAYER &&
                (hp < 65 || target->getAttackers().size() > 1 || (u && u->GetMaxHealth() > target->GetMaxHealth()*10 && target->IsInCombat())) &&
                !HasAuraName(target, SACRED_SHIELD_1) && IsInBotParty(target))
            {
                Unit* aff = FindAffectedTarget(GetSpell(SACRED_SHIELD_1), me->GetGUID(), 50, 1);//use players since we cast only on them
                if ((!aff || (aff->getAttackers().empty() && !IsTank(aff))) &&
                    doCast(target, GetSpell(SACRED_SHIELD_1)))
                    return true;
            }
            if ((hp < 85 || GetLostHP(target) > 6000))
                if (HS(target, diff))
                    return true;
            if ((hp > 35 && (hp < 75 || GetLostHP(target) > 8000)) || (!GetSpell(FLASH_OF_LIGHT_1) && hp < 85))
                if (doCast(target, GetSpell(HOLY_LIGHT_1)))
                    return true;
            if ((hp < 90 || GetLostHP(target) > 1500))
                if (doCast(target, GetSpell(FLASH_OF_LIGHT_1), me->HasAura(THE_ART_OF_WAR_BUFF)))
                    return true;
            return false;
        }//end HealTarget

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
        void JustDied(Unit* u) { bot_minion_ai::JustDied(u); }

        void UpdateAI(uint32 diff)
        {
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
            //HOFTarget(me, diff);//self stun cure goes FIRST
            if (CCed(me)) return;

            if (Potion_cd <= diff && GetManaPCT(me) < 30)
            {
                temptimer = GC_Timer;
                if (doCast(me, MANAPOTION))
                {
                    Potion_cd = POTION_CD;
                    GC_Timer = temptimer;
                }
            }
            if (GetManaPCT(me) < 40 && IsSpellReady(DIVINE_PLEA_1, diff, false))
                if (doCast(me, GetSpell(DIVINE_PLEA_1)))
                    return;

            CureTarget(me, GetSpell(CLEANSE_1), diff); //maybe unnecessary but this goes FIRST
            HOFTarget(master, diff); //maybe unnecessary
            CureTarget(master, GetSpell(CLEANSE_1), diff); //maybe unnecessary
            BuffAndHealGroup(master, diff);
            HOSTarget(master, diff);
            CureGroup(master, GetSpell(CLEANSE_1), diff);
            HOFGroup(master, diff);
            HOSGroup(master, diff);

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
            //buff
            if (IsSpellReady(SEAL_OF_COMMAND_1, diff, false) && Rand() < 20 && !HasAuraName(me, SEAL_OF_COMMAND_1) &&
                doCast(me, GetSpell(SEAL_OF_COMMAND_1)))
                GC_Timer = 500;

            // Heal myself
            if (GetHealthPCT(me) < 80)
                HealTarget(me, GetHealthPCT(me), diff);

            if (!CheckAttackTarget(BOT_CLASS_PALADIN))
                return;

            Repentance(diff);
            //Counter(diff);
            DoNormalAttack(diff);
        }

        void DoNonCombatActions(uint32 diff)
        {
            if (GC_Timer > diff || me->IsMounted() || IsCasting())
                return;

            RezGroup(GetSpell(REDEMPTION_1), master);

            if (Feasting())
                return;

            //aura
            if (master->IsAlive() && me->GetExactDist(master) < 20)
            {
                uint8 myAura;
                uint32 DEVOTION_AURA = GetSpell(DEVOTION_AURA_1);
                uint32 CONCENTRATION_AURA = GetSpell(CONCENTRATION_AURA_1);

                if (me->HasAura(DEVOTION_AURA, me->GetGUID()))
                    myAura = DEVOTIONAURA;
                else if (me->HasAura(CONCENTRATION_AURA, me->GetGUID()))
                    myAura = CONCENTRATIONAURA;
                else
                    myAura = NOAURA;

                if (myAura != NOAURA)
                    return; //do not bother

                Aura* concAura = master->GetAura(CONCENTRATION_AURA);
                Aura* devAura = master->GetAura(DEVOTION_AURA);
                if (devAura && concAura) return;
                if (devAura && devAura->GetCasterGUID() == me->GetGUID()) return;
                if (concAura && concAura->GetCasterGUID() == me->GetGUID()) return;

                if ((master->getClass() == BOT_CLASS_MAGE ||
                    master->getClass() == BOT_CLASS_PRIEST ||
                    master->getClass() == BOT_CLASS_WARLOCK ||
                    master->getClass() == BOT_CLASS_DRUID || devAura) &&
                    !concAura &&
                    doCast(me, CONCENTRATION_AURA))
                {
                    /*GC_Timer = 800;*/
                    return;
                }
                if (!devAura && doCast(me, DEVOTION_AURA))
                {
                    /*GC_Timer = 800;*/
                    return;
                }
            }
        }

        bool BuffTarget(Unit* target, uint32 diff)
        {
            if (!target || target->isDead() || GC_Timer > diff || Rand() > 30) return false;
            if (me->IsInCombat() && !master->GetMap()->IsRaid()) return false;
            if (me->GetExactDist(target) > 30) return false;
            //if (HasAuraName(target, BLESSING_OF_WISDOM_1, me->GetGUID()) ||
            //    HasAuraName(target, BLESSING_OF_KINGS_1, me->GetGUID()) ||
            //    HasAuraName(target, BLESSING_OF_SANCTUARY_1, me->GetGUID()) ||
            //    HasAuraName(target, BLESSING_OF_MIGHT_1, me->GetGUID()))
            //    return false;
            //if (HasAuraName(target, "Greater Blessing of Wisdom", me->GetGUID()) ||
            //    HasAuraName(target, "Greater Blessing of Might", me->GetGUID()) ||
            //    HasAuraName(target, "Greater Blessing of Kings", me->GetGUID()) ||
            //    HasAuraName(target, "Greater Blessing of Sanctuary", me->GetGUID()))
            //    return false;

            uint32 mask = GetBlessingsMask(target);

            //already has my blessing
            if (mask & SPECIFIC_BLESSING_MY_BLESSING)
                return false;

            uint32 BLESSING_OF_WISDOM = GetSpell(BLESSING_OF_WISDOM_1);
            uint32 BLESSING_OF_KINGS = GetSpell(BLESSING_OF_KINGS_1);
            uint32 BLESSING_OF_SANCTUARY = GetSpell(BLESSING_OF_SANCTUARY_1);
            uint32 BLESSING_OF_MIGHT = GetSpell(BLESSING_OF_MIGHT_1);

            bool wisdom = (mask & SPECIFIC_BLESSING_WISDOM);
            bool kings = (mask & SPECIFIC_BLESSING_KINGS);
            bool sanctuary = (mask & SPECIFIC_BLESSING_SANCTUARY);
            bool might = (mask & SPECIFIC_BLESSING_MIGHT);

            //bool wisdom = HasAuraName(target, BLESSING_OF_WISDOM_1) || HasAuraName(target, GREATER_BLESSING_OF_WISDOM_1);
            //bool kings = HasAuraName(target, BLESSING_OF_KINGS_1) || HasAuraName(target, GREATER_BLESSING_OF_KINGS_1);
            //bool sanctuary = HasAuraName(target, BLESSING_OF_SANCTUARY_1) || HasAuraName(target, GREATER_BLESSING_OF_SANCTUARY_1);
            //bool might = (HasAuraName(target, BLESSING_OF_MIGHT_1) || HasAuraName(target, GREATER_BLESSING_OF_MIGHT_1) || HasAuraName(target, BATTLESHOUT_1));

            uint8 Class = 0;
            if (target->GetTypeId() == TYPEID_PLAYER)
                Class = target->getClass();
            else if (Creature* cre = target->ToCreature())
                Class = cre->GetBotAI() ? cre->GetBotAI()->GetPlayerClass() : cre->getClass();

            switch (Class)
            {
                case BOT_CLASS_PRIEST:
                    if (BLESSING_OF_WISDOM && !wisdom && doCast(target, BLESSING_OF_WISDOM))
                        return true;
                    else if (BLESSING_OF_KINGS && !kings && doCast(target, BLESSING_OF_KINGS))
                        return true;
                    else if (BLESSING_OF_SANCTUARY && !sanctuary && doCast(target, BLESSING_OF_SANCTUARY))
                        return true;
                    break;
                case BOT_CLASS_DEATH_KNIGHT:
                case BOT_CLASS_WARRIOR:
                case BOT_CLASS_PALADIN:
                case BOT_CLASS_ROGUE:
                case BOT_CLASS_HUNTER:
                case BOT_CLASS_SHAMAN:
                    if (BLESSING_OF_KINGS && !kings && doCast(target, BLESSING_OF_KINGS))
                        return true;
                    else if (BLESSING_OF_MIGHT && !might && doCast(target, BLESSING_OF_MIGHT))
                        return true;
                    else if (BLESSING_OF_SANCTUARY && !sanctuary && doCast(target, BLESSING_OF_SANCTUARY))
                        return true;
                    else if (BLESSING_OF_WISDOM && !wisdom && target->getPowerType() == POWER_MANA && doCast(target, BLESSING_OF_WISDOM))
                        return true;
                    break;
                default:
                    if (BLESSING_OF_KINGS && !kings && doCast(target, BLESSING_OF_KINGS))
                        return true;
                    else if (BLESSING_OF_WISDOM && !wisdom && target->getPowerType() == POWER_MANA && doCast(target, BLESSING_OF_WISDOM))
                        return true;
                    else if (BLESSING_OF_SANCTUARY && !sanctuary && doCast(target, BLESSING_OF_SANCTUARY))
                        return true;
                    else if (BLESSING_OF_MIGHT && !might && doCast(target, BLESSING_OF_MIGHT))
                        return true;
                    break;
            }
            return false;
        }

        void Repentance(uint32 diff, Unit* target = NULL)
        {
            temptimer = GC_Timer;
            if (target)
            {
                if (IsSpellReady(REPENTANCE_1, diff, false, 25000) && doCast(target, GetSpell(REPENTANCE_1)))
                {}
            }
            else if (IsSpellReady(REPENTANCE_1, diff, false))
            {
                Unit* u = FindStunTarget();
                if (u && u->GetVictim() != me && doCast(u, GetSpell(REPENTANCE_1)))
                {}
            }
            GC_Timer = temptimer;
        }

        void Counter(uint32 diff)
        {
            if (IsCasting())
                return;
            if (Rand() > 60)
                return;

            Unit* target = IsSpellReady(REPENTANCE_1, diff, false, 25000) ? FindCastingTarget(20, 0, false, REPENTANCE_1) : NULL;
            if (target)
                Repentance(diff, target); //first check repentance
            else if (IsSpellReady(TURN_EVIL_1, diff, false, 1500))
            {
                target = FindCastingTarget(20, 0, false, TURN_EVIL_1);
                temptimer = GC_Timer;
                if (target && doCast(target, GetSpell(TURN_EVIL_1), true))
                    GC_Timer = temptimer;
            }
            else if (IsSpellReady(HOLY_WRATH_1, diff, false, 8000) && HasRole(BOT_ROLE_DPS))
            {
                target = FindCastingTarget(8, 0, false, TURN_EVIL_1); //here we check target as with turn evil cuz of same requirements
                temptimer = GC_Timer;
                if (target && doCast(me, GetSpell(HOLY_WRATH_1)))
                    GC_Timer = temptimer;
            }
            else if (IsSpellReady(HAMMER_OF_JUSTICE_1, diff, /*true*/false, 7000))
            {
                target = FindCastingTarget(10);
                if (target && doCast(opponent, GetSpell(HAMMER_OF_JUSTICE_1)))
                {}
            }
        }

        void TurnEvil(uint32 diff)
        {
            if (!IsSpellReady(TURN_EVIL_1, diff) || IsCasting() || Rand() > 50 ||
                FindAffectedTarget(GetSpell(TURN_EVIL_1), me->GetGUID(), 50))
                return;
            Unit* target = FindUndeadCCTarget(20, TURN_EVIL_1);
            if (target &&
                (target != me->GetVictim() || GetHealthPCT(me) < 70 || target->GetVictim() == master) &&
                doCast(target, GetSpell(TURN_EVIL_1), true))
                return;
            else
            if ((opponent->GetCreatureType() == CREATURE_TYPE_UNDEAD || opponent->GetCreatureType() == CREATURE_TYPE_DEMON) &&
                !CCed(opponent) &&
                opponent->GetVictim() && !IsTank(opponent->GetVictim()) && opponent->GetVictim() != me &&
                GetHealthPCT(me) < 90 &&
                doCast(opponent, GetSpell(TURN_EVIL_1), true))
                return;
        }

        void Wrath(uint32 diff)
        {
            if (!IsSpellReady(HOLY_WRATH_1, diff) || !HasRole(BOT_ROLE_DPS) || Rand() > 50)
                return;
            if ((opponent->GetCreatureType() == CREATURE_TYPE_UNDEAD || opponent->GetCreatureType() == CREATURE_TYPE_DEMON) &&
                me->GetExactDist(opponent) <= 8 && doCast(me, GetSpell(HOLY_WRATH_1)))
            {}
            else
            {
                Unit* target = FindUndeadCCTarget(8, GetSpell(HOLY_WRATH_1));
                if (target && doCast(me, GetSpell(HOLY_WRATH_1)))
                {}
            }
        }

        void DoNormalAttack(uint32 diff)
        {
            opponent = me->GetVictim();
            if (opponent)
            {
                if (!IsCasting())
                    StartAttack(opponent, true);
            }
            else
                return;

            Counter(diff);
            TurnEvil(diff);

            if (MoveBehind(*opponent))
                wait = 5;

            //HAMMER OF WRATH //custom GCD check
            if (IsSpellReady(HOW_1, diff, false) && GC_Timer <= 300 && HasRole(BOT_ROLE_DPS) && Rand() < 30 && GetHealthPCT(opponent) < 19 &&
                me->GetExactDist(opponent) < 30)
            {
                temptimer = GC_Timer;
                if (doCast(opponent, GetSpell(HOW_1)))
                {
                    GC_Timer = temptimer;
                    return;
                }
            }
            //HAND OF RECKONING //No GCD
            Unit* u = opponent->GetVictim();
            if (IsSpellReady(HANDOFRECKONING_1, diff, false) && me->GetExactDist(opponent) < 30 &&
                HasRole(BOT_ROLE_DPS) && u && u != me && !IsTank(u) && Rand() < 50 &&
                (IsInBotParty(u) || IsTank()))
            {
                Creature* cre = opponent->ToCreature();
                temptimer = GC_Timer;
                if (((cre && cre->isWorldBoss() && !IsMeleeClass(u->getClass())) ||
                    GetHealthPCT(u) < GetHealthPCT(me) - 5 || IsTank()) &&
                    doCast(opponent, GetSpell(HANDOFRECKONING_1)))
                {
                    GC_Timer = temptimer;
                    return;
                }
            }

            if (IsSpellReady(HAMMER_OF_JUSTICE_1, diff) && !CCed(opponent) &&
                me->GetExactDist(opponent) < 10 && Rand() < 20)
            {
                if (doCast(opponent, GetSpell(HAMMER_OF_JUSTICE_1)))
                    return;
            }

            if (IsSpellReady(JUDGEMENT_1, diff) && HasRole(BOT_ROLE_DPS) && me->GetExactDist(opponent) < 10 &&
                Rand() < 50 && me->HasAura(GetSpell(SEAL_OF_COMMAND_1)))
            {
                if (doCast(opponent, GetSpell(JUDGEMENT_1)))
                    return;
            }

            if (IsSpellReady(CONSECRATION_1, diff) && HasRole(BOT_ROLE_DPS) && me->GetDistance(opponent) < 7 &&
                !opponent->isMoving() && Rand() < 50)
            {
                if (doCast(me, GetSpell(CONSECRATION_1)))
                    return;
            }

            if (IsSpellReady(AVENGING_WRATH_1, diff, false) && HasRole(BOT_ROLE_DPS) &&
                opponent->GetHealth() > (master->GetMaxHealth()*2)/3 && Rand() < 25)
            {
                temptimer = GC_Timer;
                if (doCast(me, GetSpell(AVENGING_WRATH_1)))
                {
                    GC_Timer = temptimer;
                    return;
                }
            }

            if (IsSpellReady(CRUSADER_STRIKE_1, diff) && HasRole(BOT_ROLE_DPS) && me->GetDistance(opponent) < 5)
            {
                if (doCast(opponent, GetSpell(CRUSADER_STRIKE_1)))
                    return;
            }

            if (IsSpellReady(EXORCISM_1, diff) && HasRole(BOT_ROLE_DPS) && me->GetExactDist(opponent) < 30 &&
                (!IsTank() || opponent->GetVictim() == me || opponent->IsVehicle() || opponent->ToPlayer()))
            {
                if (doCast(opponent, GetSpell(EXORCISM_1), me->HasAura(THE_ART_OF_WAR_BUFF)))
                    return;
            }

            Wrath(diff);

            if (IsSpellReady(DIVINE_STORM_1, diff) && HasRole(BOT_ROLE_DPS) && me->GetExactDist(opponent) < 7)
            {
                if (doCast(opponent, GetSpell(DIVINE_STORM_1)))
                    return;
            }
        }

        void ApplyClassDamageMultiplierMelee(uint32& /*damage*/, CalcDamageInfo& /*damageinfo*/) const {}

        void ApplyClassDamageMultiplierMelee(int32& damage, SpellNonMeleeDamage& /*damageinfo*/, SpellInfo const* spellInfo, WeaponAttackType /*attackType*/, bool& crit) const
        {
            uint32 spellId = spellInfo->Id;
            uint8 lvl = me->getLevel();
            float fdamage = float(damage);
            //1) apply additional crit chance. This additional chance roll will replace original (balance safe)
            if (!crit)
            {
                float aftercrit = 0.f;
                //Fanaticism: 18% additional critical chance for all Judgements (not shure which check is right)
                if (lvl >= 45 && (spellInfo->GetCategory() == SPELLCATEGORY_JUDGEMENT || spellInfo->GetSpellSpecific() == SPELL_SPECIFIC_JUDGEMENT))
                    aftercrit += 18.f;

                if (aftercrit > 0.f)
                    crit = roll_chance_f(aftercrit);
            }

            //2) apply bonus damage mods
            float pctbonus = 0.0f;
            //if (crit)
            //{
            //}
            //Sanctity of Battle: 15% bonus damage for Exorcism and Crusader Strike
            if (lvl >= 25 && spellId == GetSpell(EXORCISM_1))
                pctbonus += 0.15f;
            //The Art of War (damage part): 10% bonus damage for Judgements, Crusader Strike and Divine Storm
            if (lvl >= 40 &&
                (spellInfo->GetCategory() == SPELLCATEGORY_JUDGEMENT ||
                spellInfo->GetSpellSpecific() == SPELL_SPECIFIC_JUDGEMENT ||
                spellId == GetSpell(CRUSADER_STRIKE_1) ||
                spellId == GetSpell(DIVINE_STORM_1)))
                pctbonus += 0.1f;
            //Judgements of the Pure (damage part): 25% bonus damage for Judgements and Seals
            if (lvl >= 50 &&
                (spellInfo->GetCategory() == SPELLCATEGORY_JUDGEMENT ||
                spellInfo->GetSpellSpecific() == SPELL_SPECIFIC_JUDGEMENT ||
                spellInfo->GetSpellSpecific() == SPELL_SPECIFIC_SEAL ||
                spellId == JUDGEMENT_OF_COMMAND_DAMAGE))
                pctbonus += 0.25f;

            damage = int32(fdamage * (1.0f + pctbonus));
        }

        void ApplyClassDamageMultiplierSpell(int32& damage, SpellNonMeleeDamage& /*damageinfo*/, SpellInfo const* spellInfo, WeaponAttackType /*attackType*/, bool& crit) const
        {
            uint32 spellId = spellInfo->Id;
            uint8 lvl = me->getLevel();
            float fdamage = float(damage);
            //1) apply additional crit chance. This additional chance roll will replace original (balance safe)
            if (!crit)
            {
                float aftercrit = 0.f;
                //Sanctified Wrath: 50% additional critical chance for Hammer of Wrath
                if (lvl >= 45 && spellId == GetSpell(HOW_1))
                    aftercrit += 50.f;
                //Holy Power: 5% additional critical chance for Holy spells
                if (lvl >= 35 && (spellInfo->GetSchoolMask() & SPELL_SCHOOL_MASK_HOLY))
                    aftercrit += 5.f;

                if (aftercrit > 0.f)
                    crit = roll_chance_f(aftercrit);
            }

            //2) apply bonus damage mods
            float pctbonus = 0.0f;
            //if (crit)
            //{
            //}

            //Judgements of the Pure (damage part): 25% bonus damage for Judgements and Seals
            if (lvl >= 50 &&
                (spellInfo->GetCategory() == SPELLCATEGORY_JUDGEMENT ||
                spellInfo->GetSpellSpecific() == SPELL_SPECIFIC_JUDGEMENT ||
                spellInfo->GetSpellSpecific() == SPELL_SPECIFIC_SEAL ||
                spellId == JUDGEMENT_OF_COMMAND_DAMAGE))
                pctbonus += 0.25f;

            damage = int32(fdamage * (1.0f + pctbonus));
        }

        void ApplyClassDamageMultiplierHeal(Unit const* /*victim*/, float& heal, SpellInfo const* spellInfo, DamageEffectType /*damagetype*/, uint32 /*stack*/) const
        {
            uint32 spellId = spellInfo->Id;
            uint8 lvl = me->getLevel();
            float pctbonus = 0.0f;
            float flat_mod = 0.0f;

            //Healing Light: 12% bonus healing for Holy Light, Flash of Light and Holy Shock
            if (lvl >= 15 &&
                (spellId == GetSpell(HOLY_LIGHT_1) ||
                spellId == GetSpell(FLASH_OF_LIGHT_1) ||
                spellId == GetSpell(HOLY_SHOCK_1)))
                pctbonus += 0.12f;

            heal = heal * (1.0f + pctbonus) + flat_mod;
        }

        void ApplyClassCritMultiplierHeal(Unit const* /*victim*/, float& crit_chance, SpellInfo const* spellInfo, SpellSchoolMask schoolMask, WeaponAttackType /*attackType*/) const
        {
            uint32 spellId = spellInfo->Id;
            uint8 lvl = me->getLevel();
            float aftercrit = 0.0f;

            //Sanctified Light: 6% additional critical chance for Holy Light and Holy Shock
            if (lvl >= 30 && (spellId == GetSpell(HOLY_LIGHT_1) || spellId == GetSpell(HOLY_SHOCK_1)))
                aftercrit += 6.f;
            //Holy Power: 5% additional critical chance for Holy spells
            if (lvl >= 35 && (schoolMask & SPELL_SCHOOL_MASK_HOLY))
                aftercrit += 5.f;

            crit_chance += aftercrit;
        }

        void SpellHitTarget(Unit* target, SpellInfo const* spell)
        {
            uint32 spellId = spell->Id;

            if ((spellId == GetSpell(EXORCISM_1) || spellId == GetSpell(FLASH_OF_LIGHT_1)) &&
                me->HasAura(THE_ART_OF_WAR_BUFF))
            {
                //Art of War: consume buff
                me->RemoveAura(THE_ART_OF_WAR_BUFF, ObjectGuid::Empty, 0, AURA_REMOVE_BY_EXPIRE);
            }

            if (spellId == GetSpell(HOF_1))
            {
                //Guardian's Favor part 2 (handled separately)
                if (Aura* hof = target->GetAura(spellId, me->GetGUID()))
                {
                    uint32 dur = hof->GetDuration() + 4000;
                    hof->SetDuration(dur);
                    hof->SetMaxDuration(dur);
                }
            }

            //if (!IAmFree())
            {
                if (spellId == GetSpell(BLESSING_OF_KINGS_1) || spellId == GetSpell(BLESSING_OF_MIGHT_1) ||
                    spellId == GetSpell(BLESSING_OF_WISDOM_1) || spellId == GetSpell(BLESSING_OF_SANCTUARY_1))
                {
                    //Blessings duration 1h
                    if (Aura* bless = target->GetAura(spellId, me->GetGUID()))
                    {
                        uint32 dur = HOUR * IN_MILLISECONDS;
                        bless->SetDuration(dur);
                        bless->SetMaxDuration(dur);
                    }
                }
            }
        }

        void SpellHit(Unit* caster, SpellInfo const* spell)
        {
            OnSpellHit(caster, spell);
        }

        void DamageTaken(Unit* u, uint32& /*damage*/)
        {
            if (!u->IsInCombat() && !me->IsInCombat())
                return;
            OnOwnerDamagedBy(u);
        }

        void DamageDealt(Unit* victim, uint32& damage, DamageEffectType damageType)
        {
            //Custom OnHit() handlers

            if (damageType == DIRECT_DAMAGE)
            {
                //The Art of War: 20% on autoattack
                if (me->getLevel() >= 33)
                    if (urand(1,100) <= 20)
                        me->CastSpell(me, THE_ART_OF_WAR_BUFF, true);
            }

            bot_ai::DamageDealt(victim, damage, damageType);
        }

        void HealReceived(Unit* healer, uint32& heal)
        {
            //Spiritual Attunement
            if (heal && me->getLevel() >= 40 && healer != me && HasRole(BOT_ROLE_TANK) && GetLostHP(me))
            {
                if (int32 basepoints = int32(CalculatePct(std::min<int32>(heal, GetLostHP(me)), 10)))
                    me->CastCustomSpell(me, SPIRITUAL_ATTUNEMENT_ENERGIZE, &basepoints, NULL, NULL, true);
            }

            //bot_ai::HealReceived(healer, heal);
        }

        void OwnerAttackedBy(Unit* u)
        {
            OnOwnerDamagedBy(u);
        }

        void Reset()
        {
            DefaultInit();
        }

        void ReduceCD(uint32 /*diff*/)
        {
        }

        void InitSpells()
        {
            uint8 lvl = me->getLevel();
            InitSpellMap(FLASH_OF_LIGHT_1);
            InitSpellMap(HOLY_LIGHT_1);
            InitSpellMap(LAY_ON_HANDS_1);
            InitSpellMap(SACRED_SHIELD_1);
  /*Talent*/lvl >= 40 ? InitSpellMap(HOLY_SHOCK_1) : RemoveSpell(HOLY_SHOCK_1);
            InitSpellMap(CLEANSE_1);
            InitSpellMap(REDEMPTION_1);
            InitSpellMap(HAMMER_OF_JUSTICE_1);
  /*Talent*/lvl >= 45 ? InitSpellMap(REPENTANCE_1) : RemoveSpell(REPENTANCE_1);
            InitSpellMap(TURN_EVIL_1);
            InitSpellMap(HOLY_WRATH_1);
            InitSpellMap(EXORCISM_1);
  /*Talent*/lvl >= 25 ? InitSpellMap(SEAL_OF_COMMAND_1) : RemoveSpell(SEAL_OF_COMMAND_1);
  /*Talent*/lvl >= 20 ? InitSpellMap(CRUSADER_STRIKE_1) : RemoveSpell(CRUSADER_STRIKE_1);
            InitSpellMap(JUDGEMENT_1);
            InitSpellMap(CONSECRATION_1);
  /*Talent*/lvl >= 60 ? InitSpellMap(DIVINE_STORM_1) : RemoveSpell(DIVINE_STORM_1);
            InitSpellMap(HOW_1);
            InitSpellMap(AVENGING_WRATH_1);
            InitSpellMap(BLESSING_OF_MIGHT_1);
            InitSpellMap(BLESSING_OF_WISDOM_1);
            InitSpellMap(BLESSING_OF_KINGS_1);
  /*Talent*/lvl >= 30 ? InitSpellMap(BLESSING_OF_SANCTUARY_1) : RemoveSpell(BLESSING_OF_SANCTUARY_1);
            InitSpellMap(DEVOTION_AURA_1);
            InitSpellMap(CONCENTRATION_AURA_1);
            InitSpellMap(DIVINE_PLEA_1);
            InitSpellMap(HAND_OF_PROTECTION_1);
            InitSpellMap(HOF_1);
            InitSpellMap(HOS_1);
            InitSpellMap(HANDOFRECKONING_1);

 /*SPECIAL*/InitSpellMap(ARDENT_DEFENDER_HEAL, true);
        }

        void ApplyClassPassives()
        {
            uint8 level = master->getLevel();

            //RefreshAura(SPELLDMG, /*level >= 78 ? 5 : level >= 75 ? 4 */level >= 55 ? 3 : level >= 35 ? 2 : level >= 15 ? 1 : 0);
            //RefreshAura(SPELLDMG2, level >= 55 ? 3 : level >= 35 ? 2 : level >= 15 ? 1 : 0);
            RefreshAura(PURE, level >= 55 ? 1 : 0);
            RefreshAura(WISE, level >= 35 ? 1 : 0);
            RefreshAura(RECKONING5, level >= 50 ? 1 : 0);
            RefreshAura(RECKONING4, level >= 45 && level < 50 ? 1 : 0);
            RefreshAura(RECKONING3, level >= 40 && level < 45 ? 1 : 0);
            RefreshAura(RECKONING2, level >= 35 && level < 40 ? 1 : 0);
            RefreshAura(RECKONING1, level >= 30 && level < 35 ? 1 : 0);
            RefreshAura(VENGEANCE3, level >= 30 ? 1 : 0);
            RefreshAura(VENGEANCE2, level >= 27 && level < 30 ? 1 : 0);
            RefreshAura(VENGEANCE1, level >= 25 && level < 27 ? 1 : 0);
            RefreshAura(SHOFL3, level >= 60 ? 1 : 0);
            RefreshAura(SHOFL2, level >= 55 && level < 60 ? 1 : 0);
            RefreshAura(SHOFL1, level >= 50 && level < 55 ? 1 : 0);
            RefreshAura(SACRED_CLEANSING, level >= 45 ? 1 : 0);
            RefreshAura(DIVINE_PURPOSE, level >= 35 ? 1 : 0);
            RefreshAura(VINDICATION2, level >= 25 ? 1 : 0);
            RefreshAura(VINDICATION1, level >= 20 && level < 25 ? 1 : 0);
            RefreshAura(LAYHANDS, level >= 30 ? 1 : 0);
            RefreshAura(FANATICISM, level >= 20 ? 2 : 0);
            RefreshAura(ARDENT_DEFENDER, level >= 40 ? 1 : 0);
            RefreshAura(ILLUMINATION, level >= 20 ? 1 : 0);
            RefreshAura(INFUSION_OF_LIGHT, level >= 55 ? 1 : 0); //NYI
            RefreshAura(REDOUBT3, level >= 68 ? 2 : level >= 55 ? 1 : 0);
            RefreshAura(REDOUBT2, level >= 50 && level < 55 ? 1 : 0);
            RefreshAura(REDOUBT1, level >= 45 && level < 50 ? 1 : 0);
            RefreshAura(GLYPH_HOLY_LIGHT, level >= 15 ? 1 : 0);
        }

        bool CanUseManually(uint32 basespell) const
        {
            switch (basespell)
            {
                case FLASH_OF_LIGHT_1:
                case HOLY_LIGHT_1:
                case LAY_ON_HANDS_1:
                case HOF_1:
                case SACRED_SHIELD_1:
                case HOLY_SHOCK_1:
                case CLEANSE_1:
                case HAND_OF_PROTECTION_1:
                case HOS_1:
                case SEAL_OF_COMMAND_1:
                case DIVINE_PLEA_1:
                case AVENGING_WRATH_1:
                case BLESSING_OF_MIGHT_1:
                case BLESSING_OF_WISDOM_1:
                case BLESSING_OF_KINGS_1:
                case BLESSING_OF_SANCTUARY_1:
                    return true;
                default:
                    return false;
            }
        }

    private:

        //uint32 GetBlessingsMask(Unit const*) const
        //Scans target for auras which are related to paladin's blessings
        //(even if aura is just incompatible with one)
        //returns applied blessings mask
        //used for finding out which blessings target lacks
        uint32 GetBlessingsMask(Unit const* target) const
        {
            uint32 mask = 0;

            bool blessing;
            Unit::AuraApplicationMap const& aurapps = target->GetAppliedAuras();
            for (Unit::AuraApplicationMap::const_iterator itr = aurapps.begin(); itr != aurapps.end(); ++itr)
            {
                blessing = true;
                switch (itr->second->GetBase()->GetSpellInfo()->GetFirstRankSpell()->Id)
                {
                    case BLESSING_OF_WISDOM_1:
                    case GREATER_BLESSING_OF_WISDOM_1:
                        mask |= SPECIFIC_BLESSING_WISDOM;
                        break;
                    case BLESSING_OF_KINGS_1:
                    case GREATER_BLESSING_OF_KINGS_1:
                        mask |= SPECIFIC_BLESSING_KINGS;
                        break;
                    case BLESSING_OF_SANCTUARY_1:
                    case GREATER_BLESSING_OF_SANCTUARY_1:
                        mask |= SPECIFIC_BLESSING_SANCTUARY;
                        break;
                    case BLESSING_OF_MIGHT_1:
                    case GREATER_BLESSING_OF_MIGHT_1:
                    case BATTLESHOUT_1:
                        mask |= SPECIFIC_BLESSING_MIGHT;
                        break;
                    default:
                        blessing = false; //next aura
                        break;
                }

                if (blessing && itr->second->GetBase()->GetCasterGUID() == me->GetGUID())
                    mask |= SPECIFIC_BLESSING_MY_BLESSING;
            }

            return mask;
        }

        enum PaladinBaseSpells// all orignals
        {
            FLASH_OF_LIGHT_1                    = 19750,
            HOLY_LIGHT_1                        = 635,
            LAY_ON_HANDS_1                      = 633,
            REDEMPTION_1                        = 7328,
            HOF_1  /*Hand of Freedom*/          = 1044,
            SACRED_SHIELD_1                     = 53601,
            HOLY_SHOCK_1                        = 20473,
            CLEANSE_1                           = 4987,
            HAND_OF_PROTECTION_1                = 1022,
            HOS_1 /*Hand of salvation*/         = 1038,
            SEAL_OF_COMMAND_1                   = 20375,
            HANDOFRECKONING_1                   = 62124,
            DIVINE_PLEA_1                       = 54428,
            REPENTANCE_1                        = 20066,
            TURN_EVIL_1                         = 10326,
            CRUSADER_STRIKE_1                   = 35395,
            JUDGEMENT_1                         = 20271,
            CONSECRATION_1                      = 26573,
            HAMMER_OF_JUSTICE_1                 = 853,
            DIVINE_STORM_1                      = 53385,
            HOW_1   /*Hammer of Wrath*/         = 24275,
            EXORCISM_1                          = 879,
            HOLY_WRATH_1                        = 2812,
            AVENGING_WRATH_1                    = 31884,
            BLESSING_OF_MIGHT_1                 = 19740,
            BLESSING_OF_WISDOM_1                = 19742,
            BLESSING_OF_KINGS_1                 = 20217,
            BLESSING_OF_SANCTUARY_1             = 20911,
            DEVOTION_AURA_1                     = 465,
            CONCENTRATION_AURA_1                = 19746
        };
        enum PaladinPassives
        {
        //Talents
            DIVINE_PURPOSE                      = 31872,
            PURE/*Judgements of the Pure*/      = 54155,
            WISE/*Judgements of the Wise*/      = 31878,
            SACRED_CLEANSING                    = 53553,//rank 3
            RECKONING1                          = 20177,
            RECKONING2                          = 20179,
            RECKONING3                          = 20181,
            RECKONING4                          = 20180,
            RECKONING5                          = 20182,
            VINDICATION1                        = 9452 ,//rank 1
            VINDICATION2                        = 26016,//rank 2
            LAYHANDS  /*Improved LOH rank 2*/   = 20235,
            FANATICISM                          = 31881,//rank 3
            //RIGHTEOUS_VENGEANCE1                = 53380,//rank 1
            //RIGHTEOUS_VENGEANCE2                = 53381,//rank 2
            //RIGHTEOUS_VENGEANCE3                = 53382,//rank 3
            VENGEANCE1                          = 20049,//rank 1
            VENGEANCE2                          = 20056,//rank 2
            VENGEANCE3                          = 20057,//rank 3
            SHOFL1      /*Sheath of Light*/     = 53501,//rank 1
            SHOFL2                              = 53502,//rank 2
            SHOFL3                              = 53503,//rank 3
            ARDENT_DEFENDER                     = 31852,//rank 3
            ILLUMINATION                        = 20215,//rank 5
            INFUSION_OF_LIGHT                   = 53576,//rank 2
            REDOUBT1                            = 20127,//rank 3
            REDOUBT2                            = 20130,//rank 3
            REDOUBT3                            = 20135,//rank 3
        //Glyphs
            GLYPH_HOLY_LIGHT                    = 54937
        //other
            //SPELLDMG/*Arcane Instability-mage*/ = 15060,//rank3 3% dam/crit
            //SPELLDMG2/*Earth and Moon - druid*/ = 48511 //rank3 6% dam
        };

        enum PaladinSpecial
        {
            NOAURA                              = 0,
            DEVOTIONAURA                        = 1,
            CONCENTRATIONAURA                   = 2,

            THE_ART_OF_WAR_BUFF                 = 59578,
            FORBEARANCE_AURA                    = 25771,

            GREATER_BLESSING_OF_MIGHT_1         = 25782,
            GREATER_BLESSING_OF_WISDOM_1        = 25894,
            GREATER_BLESSING_OF_KINGS_1         = 25898,
            GREATER_BLESSING_OF_SANCTUARY_1     = 25899,
            BATTLESHOUT_1                       = 6673,

            ARDENT_DEFENDER_HEAL                = 66235,
            JUDGEMENT_OF_COMMAND_DAMAGE         = 20467,
            SPIRITUAL_ATTUNEMENT_ENERGIZE       = 31786,

            SPECIFIC_BLESSING_WISDOM            = 0x01,
            SPECIFIC_BLESSING_KINGS             = 0x02,
            SPECIFIC_BLESSING_SANCTUARY         = 0x04,
            SPECIFIC_BLESSING_MIGHT             = 0x08,
            SPECIFIC_BLESSING_MY_BLESSING       = 0x10
        };
    };
};

void AddSC_paladin_bot()
{
    new paladin_bot();
}
