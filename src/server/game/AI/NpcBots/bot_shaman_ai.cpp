#include "bot_ai.h"
#include "botmgr.h"
#include "Group.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "Totem.h"
#include "CreatureAIImpl.h"
#include "Map.h"
/*
Shaman NpcBot (reworked by Graff onlysuffering@gmail.com)
Complete - around 30%
TODO:
*/
enum TotemSlot
{
    T_FIRE  = 0,//m_SummonSlot[1]
    T_EARTH = 1,//m_SummonSlot[2]
    T_WATER = 2,//m_SummonSlot[3]
    T_AIR   = 3,//m_SummonSlot[4]
    MAX_TOTEMS
};
struct TotemParam
{
    TotemParam() : effradius(0.f) {}
    Position pos;
    float effradius;
};
class shaman_bot : public CreatureScript
{
public:
    shaman_bot() : CreatureScript("shaman_bot") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new shaman_botAI(creature);
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

    struct shaman_botAI : public bot_minion_ai
    {
        shaman_botAI(Creature* creature) : bot_minion_ai(creature)
        {
            _botclass = BOT_CLASS_SHAMAN;
        }

        bool doCast(Unit* victim, uint32 spellId, bool triggered = false)
        {
            if (CheckBotCast(victim, spellId, BOT_CLASS_SHAMAN) != SPELL_CAST_OK)
                return false;

            bool maelstrom = false;
            if (!triggered)
                maelstrom = (MaelstromCount >= 5 &&
                (spellId == GetSpell(LIGHTNING_BOLT_1) || spellId == GetSpell(CHAIN_LIGHTNING_1) ||
                spellId == GetSpell(HEALING_WAVE_1) || spellId == GetSpell(LESSER_HEALING_WAVE_1) ||
                spellId == GetSpell(CHAIN_HEAL_1) || spellId == GetSpell(HEX_1)));

            triggered |= maelstrom;

            bool result = bot_ai::doCast(victim, spellId, triggered, me->GetGUID());

            if (result && maelstrom)
            {
                MaelstromCount = 0;
                me->RemoveAurasDueToSpell(MAELSTROM_WEAPON_BUFF, ObjectGuid::Empty, 0, AURA_REMOVE_BY_EXPIRE);
            }

            return result;
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
        void JustDied(Unit* u) { bot_minion_ai::JustDied(u); }

        bool Shielded(Unit* target) const
        {
            return
                (HasAuraName(target, WATER_SHIELD_1) ||
                HasAuraName(target, EARTH_SHIELD_1) ||
                HasAuraName(target, LIGHTNING_SHIELD_1));
        }

        void CheckBloodlust(uint32 diff)
        {
            if (!IsSpellReady(BLOODLUST_1, diff, false) || me->GetDistance(master) > 18 || IsCasting() || Rand() > 15)
                return;
            if (!me->IsInCombat() || !master->IsInCombat())
                return;

            if (HasAuraName(master, BLOODLUST_1))
            {
                SetSpellCooldown(BLOODLUST_1, 3000); //fail
                return;
            }

            if (Unit* u = me->GetVictim())
            {
                Creature* cre = u->ToCreature();
                if (u->GetMaxHealth() > me->GetHealth() * 2 ||
                    (cre && (cre->IsDungeonBoss() || cre->isWorldBoss())) ||
                    me->getAttackers().size() + master->getAttackers().size() > 5)
                {
                    temptimer = GC_Timer;
                    if (doCast(me, GetSpell(BLOODLUST_1)))
                    {
                        SetSpellCooldown(BLOODLUST_1, 300000); //5 minutes
                        GC_Timer = temptimer;
                        return;
                    }
                }
            }

            SetSpellCooldown(BLOODLUST_1, 2000); //fail
        }

        void CheckTotems(uint32 diff)
        {
            //update rate
            if (Rand() > 25)
                return;
            //Unsummon
            for (uint8 i = 0; i != MAX_TOTEMS; ++i)
            {
                if (_totems[i].first != 0)
                {
                    if (master->GetDistance2d(_totems[i].second.pos.m_positionX, _totems[i].second.pos.m_positionY) > _totems[i].second.effradius &&
                        me->GetDistance2d(_totems[i].second.pos.m_positionX, _totems[i].second.pos.m_positionY) > _totems[i].second.effradius)
                    {
                        Unit* to = ObjectAccessor::FindConnectedPlayer(ObjectGuid(_totems[i].first));
                        if (!to)
                        {
                            _totems[i].first = 0;
                            //TC_LOG_ERROR("entities.player", "%s has lost totem in slot %u! Despawned normally?", me->GetName().c_str(), i);
                            continue;
                        }

                        to->ToTotem()->UnSummon();
                    }
                }
            }
            if (GC_Timer > diff || IsCasting() || me->GetDistance(master) > 15 || Feasting())
                return;
            //Summon
            //TODO: role-based totems (attack/heal)
            if (me->IsInCombat())
            {
                if (GetSpell(WINDFURY_TOTEM_1) && !_totems[T_AIR].first && !master->m_SummonSlot[T_AIR+1])
                {
                    temptimer = GC_Timer;
                    if (doCast(me, GetSpell(WINDFURY_TOTEM_1)))
                    {
                        if (me->getLevel() >= 57)
                            GC_Timer = temptimer;
                        return;
                    }
                }

                if (!_totems[T_EARTH].first && !master->m_SummonSlot[T_EARTH+1])
                {
                    if (GetSpell(STRENGTH_OF_EARTH_TOTEM_1))
                    {
                        temptimer = GC_Timer;
                        if (doCast(me, GetSpell(STRENGTH_OF_EARTH_TOTEM_1)))
                        {
                            if (me->getLevel() >= 57)
                                GC_Timer = temptimer;
                            return;
                        }
                    }
                    else if (GetSpell(STONESKIN_TOTEM_1))
                    {
                        temptimer = GC_Timer;
                        if (doCast(me, GetSpell(STONESKIN_TOTEM_1)))
                        {
                            if (me->getLevel() >= 57)
                                GC_Timer = temptimer;
                            return;
                        }
                    }
                }

                if (!_totems[T_FIRE].first && !master->m_SummonSlot[T_FIRE+1])
                {
                    if (IsSpellReady(TOTEM_OF_WRATH_1, diff, false))
                    {
                        temptimer = GC_Timer;
                        if (doCast(me, GetSpell(TOTEM_OF_WRATH_1)))
                        {
                            //bot's poor AI cannot use totems wisely so just reduce CD on this
                            //SetSpellCooldown(TOTEM_OF_WRATH_1, 30000); //30 sec, old 5 min
                            if (me->getLevel() >= 57)
                                GC_Timer = temptimer;
                            return;
                        }
                    }
                    else if (IsSpellReady(SEARING_TOTEM_1, diff, false))
                    {
                        if (Unit* u = me->GetVictim())
                        {
                            if (HasRole(BOT_ROLE_DPS) && me->GetExactDist(u) < (u->isMoving() ? 10 : 25))
                            {
                                temptimer = GC_Timer;
                                if (doCast(me, GetSpell(SEARING_TOTEM_1)))
                                {
                                    if (me->getLevel() >= 57)
                                        GC_Timer = temptimer;
                                    return;
                                }
                            }
                        }
                    }
                }
            }
            if (!me->isMoving() && !master->isMoving())
            {
                if (!_totems[T_WATER].first && !master->m_SummonSlot[T_WATER+1])
                {
                    uint8 manapct = GetManaPCT(master);
                    uint8 hppct = GetHealthPCT(master);
                    if (GetSpell(HEALINGSTREAM_TOTEM_1) && hppct < 98 && master->getPowerType() != POWER_MANA &&
                        (hppct < 25 || manapct > hppct))
                    {
                        temptimer = GC_Timer;
                        if (doCast(me, GetSpell(HEALINGSTREAM_TOTEM_1)))
                        {
                            GC_Timer = temptimer;
                            return;
                        }
                    }
                    else if (GetSpell(MANASPRING_TOTEM_1) && (manapct < 97 || GetManaPCT(me) < 90))
                    {
                        temptimer = GC_Timer;
                        if (doCast(me, GetSpell(MANASPRING_TOTEM_1)))
                        {
                            GC_Timer = temptimer;
                            return;
                        }
                    }
                }
            }
        }

        void CheckThunderStorm(uint32 diff)
        {
            if (!IsSpellReady(THUNDERSTORM_1, diff, false) || !HasRole(BOT_ROLE_DPS) || IsCasting() || Rand() > 25)
                return;

            //case 1: low mana
            if (GetManaPCT(me) < 15)
            {
                temptimer = GC_Timer;
                if (doCast(me, GetSpell(THUNDERSTORM_1)))
                    GC_Timer = temptimer;
                return;
            }

            //case 2: knock attackers
            if (IsTank()) //pretty stupid idea I think
                return;

            //AttackerSet m_attackers = master->getAttackers();
            AttackerSet b_attackers = me->getAttackers();
            if (b_attackers.empty())
                return;

            uint8 tCount = 0;
            for (AttackerSet::iterator iter = b_attackers.begin(); iter != b_attackers.end(); ++iter)
            {
                if (!(*iter)) continue;
                if (me->GetExactDist((*iter)) > 9) continue;
                if (CCed(*iter)) continue;
                if (me->IsValidAttackTarget(*iter))
                {
                    ++tCount;
                    break;
                }
            }

            if (tCount > 0)
            {
                temptimer = GC_Timer;
                if (doCast(me, GetSpell(THUNDERSTORM_1)))
                    GC_Timer = temptimer;
                return;
            }
        }

        void CheckManaTide(uint32 diff)
        {
            if (!IsSpellReady(MANA_TIDE_TOTEM_1, diff, false) || IAmFree() || IsCasting() || Rand() > 20)
                return;

            Group* group = master->GetGroup();
            if (!group)
                return;

            uint8 LMPcount = 0;
            uint8 members = group->GetMembersCount();
            for (GroupReference* itr = group->GetFirstMember(); itr != NULL; itr = itr->next())
            {
                Player* tPlayer = itr->GetSource();
                if (!tPlayer || !tPlayer->IsInWorld() || tPlayer->GetMapId() != me->GetMapId() ||
                    (!tPlayer->IsAlive() && !tPlayer->HaveBot())) continue;
                if (me->GetExactDist(tPlayer) > 20) continue;
                if (tPlayer->getPowerType() != POWER_MANA) continue;
                if (GetManaPCT(tPlayer) < 35)
                {
                    ++LMPcount;
                    if (LMPcount > 3 || LMPcount > members / 3) break;
                }
                if (tPlayer->HaveBot())
                {
                    BotMap const* map = tPlayer->GetBotMgr()->GetBotMap();
                    for (BotMap::const_iterator it = map->begin(); it != map->end(); ++it)
                    {
                        Creature* bot = it->second;
                        if (bot && bot->IsInWorld() && bot->getPowerType() == POWER_MANA &&
                            bot->GetExactDist(me) < 20 && GetManaPCT(bot) < 35)
                        {
                            ++LMPcount;
                            if (LMPcount > 3 || LMPcount > members / 3) break;
                        }
                    }
                }
            }

            if (LMPcount > 3 || LMPcount > members / 3)
            {
                if (_totems[T_WATER].first != 0)
                {
                    Unit* to = ObjectAccessor::FindConnectedPlayer(ObjectGuid(_totems[T_WATER].first));
                    if (!to)
                        _totems[T_WATER].first = 0;
                    else
                        to->ToTotem()->UnSummon();
                }
                if (doCast(me, GetSpell(MANA_TIDE_TOTEM_1)))
                    return;
            }

            SetSpellCooldown(MANA_TIDE_TOTEM_1, 3000); //fail
        }

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
            CheckThunderStorm(diff);
            BreakCC(diff);
            if (CCed(me)) return;

            CheckHexy(diff);
            CheckEarthy(diff);

            if (Potion_cd <= diff && GetManaPCT(me) < 30)
            {
                temptimer = GC_Timer;
                if (doCast(me, MANAPOTION))
                {
                    Potion_cd = POTION_CD;
                    GC_Timer = temptimer;
                }
            }

            CheckBloodlust(diff);
            BuffAndHealGroup(master, diff);
            CureGroup(master, CURE_TOXINS, diff);
            CheckManaTide(diff);
            CheckTotems(diff);

            if (master->IsInCombat() || me->IsInCombat())
                CheckDispel(diff);

            if (!me->IsInCombat())
                DoNonCombatActions(diff);
            //buff myself
            if (GetSpell(LIGHTNING_SHIELD_1) && !IsTank() && !Shielded(me))
            {
                temptimer = GC_Timer;
                if (doCast(me, GetSpell(LIGHTNING_SHIELD_1)))
                    GC_Timer = temptimer;
            }
            //heal myself
            if (GetHealthPCT(me) < 80)
                HealTarget(me, GetHealthPCT(me), diff);

            if (!CheckAttackTarget(BOT_CLASS_SHAMAN))
                return;

            CheckHexy2(diff);

            //Counter(diff);
            DoNormalAttack(diff);
        }

        void Counter(uint32 diff)
        {
            if (!IsSpellReady(WIND_SHEAR_1, diff, false) || Rand() > 60)
                return;

            Unit* u = me->GetVictim();
            if (u && u->IsNonMeleeSpellCast(false))
            {
                temptimer = GC_Timer;
                if (me->IsNonMeleeSpellCast(false))
                    me->InterruptNonMeleeSpells(false);
                if (doCast(u, GetSpell(WIND_SHEAR_1)))
                {
                    SetSpellCooldown(WIND_SHEAR_1, 5000); //improved
                    GC_Timer = temptimer;
                }
            }
            else if (Unit* target = FindCastingTarget(25))
            {
                temptimer = GC_Timer;
                if (me->IsNonMeleeSpellCast(false))
                    me->InterruptNonMeleeSpells(false);
                if (doCast(target, GetSpell(WIND_SHEAR_1)))
                    GC_Timer = temptimer;
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

            //AttackerSet m_attackers = master->getAttackers();
            //AttackerSet b_attackers = me->getAttackers();
            float dist = me->GetExactDist(opponent);
            float meleedist = me->GetDistance(opponent);

            if (MoveBehind(*opponent))
                wait = 5;

            if (IsCasting()) return;

            //STORMSTRIKE
            if (IsSpellReady(STORMSTRIKE_1, diff) && HasRole(BOT_ROLE_DPS) && meleedist <= 5 && IsMelee() && Rand() < 70)
            {
                if (doCast(opponent, GetSpell(STORMSTRIKE_1)))
                    return;
            }
            //SHOCKS
            if ((GetSpell(FLAME_SHOCK_1) || GetSpell(EARTH_SHOCK_1) || GetSpell(FROST_SHOCK_1)) &&
                IsSpellReady(FLAME_SHOCK_1, diff) && HasRole(BOT_ROLE_DPS) && dist < 25 && Rand() < 30)
            {
                temptimer = GC_Timer;

                bool canFlameShock = (GetSpell(FLAME_SHOCK_1) != 0);
                if (canFlameShock)
                {
                    if (Aura* fsh = opponent->GetAura(GetSpell(FLAME_SHOCK_1), me->GetGUID()))
                        if (fsh->GetDuration() > 3000)
                            canFlameShock = false;
                }

                if (canFlameShock)
                {
                    if (doCast(opponent, GetSpell(FLAME_SHOCK_1)))
                    {
                        GC_Timer = temptimer;
                        return;
                    }
                }
                else if (GetSpell(EARTH_SHOCK_1) || GetSpell(FROST_SHOCK_1))
                {
                    uint32 SHOCK = !GetSpell(FROST_SHOCK_1) ? GetSpell(EARTH_SHOCK_1) : RAND(GetSpell(EARTH_SHOCK_1), GetSpell(FROST_SHOCK_1));
                    if (SHOCK && !opponent->HasAuraWithMechanic((1<<MECHANIC_SNARE)|(1<<MECHANIC_ROOT)) &&
                        !opponent->HasAura(SHOCK))
                    {
                        if (doCast(opponent, SHOCK))
                        {
                            GC_Timer = temptimer;
                            return;
                        }
                    }
                }
            }
            //LAVA BURST
            if (IsSpellReady(LAVA_BURST_1, diff) && HasRole(BOT_ROLE_DPS) && dist < 30 && Rand() < 50)
            {
                if (doCast(opponent, GetSpell(LAVA_BURST_1)))
                    return;
            }

            if (GetManaPCT(me) < 15 || (MaelstromCount < 5 && IsMelee()))
                return;

            //CHAIN LIGHTNING
            if (IsSpellReady(CHAIN_LIGHTNING_1, diff) && HasRole(BOT_ROLE_DPS) && dist < 30 && Rand() < 80)
            {
                if (doCast(opponent, GetSpell(CHAIN_LIGHTNING_1)))
                    return;
            }
            //LIGHTNING BOLT
            if (IsSpellReady(LIGHTNING_BOLT_1, diff) && HasRole(BOT_ROLE_DPS) && dist < 30)
            {
                uint32 LIGHTNING_BOLT = GetSpell(LIGHTNING_BOLT_1);
                if (doCast(opponent, LIGHTNING_BOLT))
                    return;
            }
        }

        void CheckHexy(uint32 diff)
        {
            if (HexyCheckTimer <= diff)
            {
                Hexy = FindAffectedTarget(GetSpell(HEX_1), me->GetGUID());
                HexyCheckTimer = 2000;
            }
        }

        void CheckHexy2(uint32 diff)
        {
            if (Hexy == false && me->GetVictim() && IsSpellReady(HEX_1, diff, false))
            {
                if (Unit* target = FindPolyTarget(20, me->GetVictim()))
                {
                    if (doCast(target, GetSpell(HEX_1)))
                    {
                        Hexy = true;
                        HexyCheckTimer += 2000;
                    }
                }
            }
        }

        void CheckEarthy(uint32 diff)
        {
            if (EarthyCheckTimer <= diff)
            {
                Unit* u = FindAffectedTarget(GetSpell(EARTH_SHIELD_1), me->GetGUID(), 90.f, 3);
                Earthy = (u && (IsTank(u) || u == master));
                EarthyCheckTimer = 1000;
            }
        }

        void DoNonCombatActions(uint32 diff)
        {
            if (GC_Timer > diff || me->IsMounted() || IsCasting())
                return;

            RezGroup(GetSpell(ANCESTRAL_SPIRIT_1), master);

            if (Feasting()) return;

            if (Shielded(me) && Rand() < 25)
            {
                Aura* shield = NULL;
                uint32 SHIELD = HasRole(BOT_ROLE_DPS) ? GetSpell(LIGHTNING_SHIELD_1) : 0;
                if (SHIELD)
                    shield = me->GetAura(SHIELD);
                if (!shield && IsTank() && GetSpell(EARTH_SHIELD_1))
                {
                    SHIELD = GetSpell(EARTH_SHIELD_1);
                    shield = me->GetAura(SHIELD);
                }
                if (!shield && GetSpell(WATER_SHIELD_1))
                {
                    SHIELD = GetSpell(WATER_SHIELD_1);
                    shield = me->GetAura(SHIELD);
                }
                if (shield && shield->GetCharges() < 5)
                {
                    temptimer = GC_Timer;
                    if (doCast(me, SHIELD))
                    {
                        GC_Timer = temptimer;
                        return;
                    }
                }
            }
        }

        bool BuffTarget(Unit* target, uint32 diff)
        {
            if (!GetSpell(WATER_WALKING_1) && !GetSpell(WATER_BREATHING_1) && !GetSpell(EARTH_SHIELD_1))
                return false;

            if (GC_Timer > diff || !target || !target->IsAlive() || Rand() > 40)
                return false;

            if (GetSpell(EARTH_SHIELD_1) && Earthy == false && (target == master || IsTank(target)) &&
                (target->IsInCombat() || !target->isMoving()) &&
                me->GetExactDist(target) < 40 && Rand() < 75)
            {
                bool cast = !Shielded(target);
                if (!cast)
                    if (Aura* eShield = target->GetAura(GetSpell(EARTH_SHIELD_1)))
                        if (eShield->GetCharges() < 5)
                            cast = true;
                if (cast && doCast(target, GetSpell(EARTH_SHIELD_1)))
                {
                    Earthy = true;
                    //GC_Timer = 800;
                    return true;
                }
            }

            if (me->GetExactDist(target) > 30) return false;
            if (me->IsInCombat() && !master->GetMap()->IsRaid()) return false;

            if (target->HasUnitMovementFlag(MOVEMENTFLAG_SWIMMING))
            {
                //bots don't need water breathing
                if (GetSpell(WATER_BREATHING_1) && target->GetTypeId() == TYPEID_PLAYER &&
                    !target->HasAuraType(SPELL_AURA_WATER_BREATHING) &&
                    doCast(target, GetSpell(WATER_BREATHING_1)))
                {
                    //GC_Timer = 800;
                    return true;
                }
                //water walking breaks on any damage
                if (GetSpell(WATER_WALKING_1) && target->getAttackers().empty() &&
                    !target->HasAuraType(SPELL_AURA_WATER_WALK) &&
                    doCast(target, GetSpell(WATER_WALKING_1)))
                {
                    //GC_Timer = 800;
                    return true;
                }
            }
            return false;
        }

        void CheckDispel(uint32 diff)
        {
            if (!IsSpellReady(PURGE_1, diff, false) || IsCasting() || Rand() > 35)
                return;

            Unit* target = FindHostileDispelTarget();
            if (target && doCast(target, GetSpell(PURGE_1)))
            {}

            SetSpellCooldown(PURGE_1, 2000); //fail
        }

        bool HealTarget(Unit* target, uint8 hp, uint32 diff)
        {
            if (!HasRole(BOT_ROLE_HEAL))
                return false;
            if (hp > 97)
                return false;
            if (!target || !target->IsAlive() || me->GetExactDist(target) > 40)
                return false;
            if (Rand() > 50 + 20*target->IsInCombat() + 50*master->GetMap()->IsRaid())
                return false;

            //PLACEHOLDER: Instant spell req. interrupt current spell

            if (IsCasting()) return false;

            if (IsSpellReady(LESSER_HEALING_WAVE_1, diff) &&
                ((hp > 70 && hp < 85) || hp < 50 || GetLostHP(target) > 1800) && Rand() < 75)
            {
                if (doCast(target, GetSpell(LESSER_HEALING_WAVE_1)))
                    return true;
            }
            if (IsSpellReady(HEALING_WAVE_1, diff) &&
                hp > 40 && (hp < 75 || GetLostHP(target) > 4000) && Rand() < 65)
            {
                if (doCast(target, GetSpell(HEALING_WAVE_1)))
                    return true;
            }
            if (IsSpellReady(CHAIN_HEAL_1, diff) &&
                ((hp > 40 && hp < 90) || GetLostHP(target) > 1300) && Rand() < 120)
            {
                if (IsSpellReady(RIPTIDE_1, diff, false) && (hp < 85 || GetLostHP(target) > 2500) &&
                    !target->HasAura(GetSpell(RIPTIDE_1)))
                {
                    temptimer = GC_Timer;
                    if (doCast(target, GetSpell(RIPTIDE_1), true))
                    {
                        if (doCast(target, GetSpell(CHAIN_HEAL_1)))
                        {
                            GC_Timer = temptimer;
                            return true;
                        }
                    }
                }
                else if (doCast(target, GetSpell(CHAIN_HEAL_1)))
                    return true;
            }

            return false;
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
                ////Incite: 15% additional critical chance for Cleave, Heroic Strike and Thunder Clap
                //if (lvl >= 15 && spellId == CLEAVE /*|| spellId == HEROICSTRIKE || spellId == THUNDERCLAP*/)
                //    aftercrit += 15.f;

                //second roll (may be illogical)
                if (aftercrit > 0.f)
                    crit = roll_chance_f(aftercrit);
            }

            //2) apply bonus damage mods
            float pctbonus = 0.0f;
            if (crit)
            {
                //!!!Melee spell damage is not yet critical, all reduced by half
                //Elemental Fury (part 2): 50% additional crit damage bonus for Nature, Fire and Frost (all) spells
                if (lvl >= 21)
                    pctbonus += 0.25f;
            }

            //SHAMAN_T8_ENCHANCEMENT_2P_BONUS: 20% bonus damage for Lava Lash and Stormstrike
            if (lvl >= 60 &&
                (spellId == STORMSTRIKE_DAMAGE || spellId == STORMSTRIKE_DAMAGE_OFFHAND/* || spellId == LAVA_LASH*/))
                pctbonus += 0.2f;

            //custom bonus to make stormstrike useful
            if (spellId == STORMSTRIKE_DAMAGE || spellId == STORMSTRIKE_DAMAGE_OFFHAND)
                pctbonus += 1.0f;

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
                //Call of Thunder: 5% additional critical chance for Lightning Bolt, Chain Lightning and Thunderstorm
                if (lvl >= 30 &&
                    (spellId == GetSpell(LIGHTNING_BOLT_1) ||
                    spellId == GetSpell(CHAIN_LIGHTNING_1) ||
                    spellId == GetSpell(THUNDERSTORM_1)))
                    aftercrit += 5.f;
                //Tidal Mastery (part 2): 5% additional critical chance for lightning spells
                if (lvl >= 25 && (SPELL_SCHOOL_MASK_NATURE & spellInfo->GetSchoolMask()))
                    aftercrit += 5.f;

                if (aftercrit > 0.f)
                    crit = roll_chance_f(aftercrit);
            }

            //2) apply bonus damage mods
            float pctbonus = 0.0f;
            if (crit)
            {
                //!!!spell damage is not yet critical and will be multiplied by 1.5
                //so we should put here bonus damage mult /1.5
                //Elemental Fury (part 2): 50% additional crit damage bonus for Nature, Fire and Frost (all) spells
                if (lvl >= 21)
                    pctbonus += 0.333f;
                //Lava Flows (part 1): 24% additional crit damage bonus for Lava Burst
                if (lvl >= 50 && spellId == GetSpell(LAVA_BURST_1))
                    pctbonus += 0.16f;
            }
            //Concussion: 5% bonus damage for Lightning Bolt, Chain Lightning, Thunderstorm, Lava Burst and Shocks
            if (lvl >= 10 &&
                (spellId == GetSpell(LIGHTNING_BOLT_1) ||
                spellId == GetSpell(CHAIN_LIGHTNING_1) ||
                spellId == GetSpell(THUNDERSTORM_1) ||
                spellId == GetSpell(LAVA_BURST_1) ||
                spellId == GetSpell(EARTH_SHOCK_1) ||
                spellId == GetSpell(FROST_SHOCK_1) ||
                spellId == GetSpell(FLAME_SHOCK_1)))
                pctbonus += 0.05f;
            //Call of Flame (part 2): 6% bonus damage for Lava burst
            if (lvl >= 15 && spellId == GetSpell(LAVA_BURST_1))
                pctbonus += 0.06f;
            //Storm, Earth and fire (part 3): 60% bonus damage for Flame Shock (periodic damage in fact but who cares?)
            if (lvl >= 40 && spellId == GetSpell(FLAME_SHOCK_1))
                pctbonus += 0.6f;
            //Booming Echoes (part 2): 20% bonus damage for Flame Shock and Frost Shock (direct damage)
            if (lvl >= 45 &&
                (spellId == GetSpell(FLAME_SHOCK_1) ||
                spellId == GetSpell(FROST_SHOCK_1)))
                pctbonus += 0.2f;
            //Improved Shields (part 1): 15% bonus damage for Lightning Shield orbs
            if (lvl >= 15 && spellInfo->IsRankOf(sSpellMgr->GetSpellInfo(LIGHTNING_SHIELD_DAMAGE_1)))
                pctbonus += 0.15f;

            damage = int32(fdamage * (1.0f + pctbonus));
        }

        void ApplyClassDamageMultiplierHeal(Unit const* /*victim*/, float& heal, SpellInfo const* spellInfo, DamageEffectType damagetype, uint32 stack) const
        {
            uint32 spellId = spellInfo->Id;
            uint8 lvl = me->getLevel();
            float pctbonus = 0.0f;
            float flat_mod = 0.0f;

            //Healing Way: 25% bonus healing for Healing Wave
            if (lvl >= 30 && spellId == GetSpell(HEALING_WAVE_1))
                pctbonus += 0.25f;
            //Purification: 10% bonus healing for all spells
            if (lvl >= 35)
                pctbonus += 0.1f;
            //Nature's Blessing: 15% of Intellect to healing
            if (lvl >= 45)
                flat_mod += me->GetTotalStatValue(STAT_INTELLECT) * 1.0f * me->CalculateDefaultCoefficient(spellInfo, damagetype) * stack * 1.88f * me->CalculateLevelPenalty(spellInfo) * stack;
            //Improved Chain Heal: 20% bonus healing for Chain Heal
            if (lvl >= 45 && spellId == GetSpell(CHAIN_HEAL_1))
                pctbonus += 0.2f;
            //Improved Earth Shield: 10% bonus healing for Earth Shield
            //Glyph of Earth Shield: 20% bonus healing for Earth Shield
            if (lvl >= 50 && spellId == EARTH_SHIELD_HEAL)
                pctbonus += 0.1f + 0.2f;
            //Improved Shields (part 3): 15% bonus healing for Earth Shield
            if (lvl >= 15 && spellId == EARTH_SHIELD_HEAL)
                pctbonus += 0.15f;
            //Tidal Waves (part 2): 20% bonus (from spellpower) for Healing Wave and 10% bonus (from spellpower) for Lesser Healing Wave
            if (lvl >= 55)
            {
                if (spellId == GetSpell(HEALING_WAVE_1))
                    flat_mod += spellpower * 0.2f * me->CalculateDefaultCoefficient(spellInfo, damagetype) * stack * 1.88f * me->CalculateLevelPenalty(spellInfo) * stack;
                else if (spellId == GetSpell(LESSER_HEALING_WAVE_1))
                    flat_mod += spellpower * 0.1f * me->CalculateDefaultCoefficient(spellInfo, damagetype) * stack * 1.88f * me->CalculateLevelPenalty(spellInfo) * stack;
            }

            heal = heal * (1.0f + pctbonus) + flat_mod;
        }

        void ApplyClassCritMultiplierHeal(Unit const* /*victim*/, float& crit_chance, SpellInfo const* /*spellInfo*/, SpellSchoolMask schoolMask, WeaponAttackType /*attackType*/) const
        {
            //uint32 spellId = spellInfo->Id;
            uint8 lvl = me->getLevel();
            float aftercrit = 0.0f;

            //Tidal Mastery (part 1): 5% additional critical chance for healing spells
            if (lvl >= 25 && (schoolMask & SPELL_SCHOOL_MASK_NATURE))
                aftercrit += 5.f;
            //Blessing of the Eternals: 4% additional critical chance for all spells
            if (lvl >= 45)
                aftercrit += 4.f;

            crit_chance += aftercrit;
        }

        void OnBotDespawn(Creature* summon)
        {
            if (!summon)
            {
                UnsummonAll();
                return;
            }

            TempSummon* totem = summon->ToTempSummon();
            if (!totem || !totem->ToTotem())
            {
                TC_LOG_ERROR("entities.player", "SummonedCreatureDespawn(): Shaman bot %s has despawned summon %s which is not a temp summon or not a totem...", me->GetName().c_str(), summon->GetName().c_str());
                return;
            }

            int8 slot = -1;
            switch (totem->m_Properties->Id)
            {
                case SUMMON_TYPE_TOTEM_FIRE:
                    slot = T_FIRE;
                    break;
                case SUMMON_TYPE_TOTEM_EARTH:
                    slot = T_EARTH;
                    break;
                case SUMMON_TYPE_TOTEM_WATER:
                    slot = T_WATER;
                    break;
                case SUMMON_TYPE_TOTEM_AIR:
                    slot = T_AIR;
                    break;
                default:
                    TC_LOG_ERROR("entities.player", "SummonedCreatureDespawn(): Shaman bot %s has despawned totem %s with unknown type %u", me->GetName().c_str(), summon->GetName().c_str(), totem->m_Properties->Id);
                    return;
            }

            _totems[slot].first = 0;
        }

        void OnBotSummon(Creature* summon)
        {
            TempSummon* totem = summon->ToTempSummon();
            if (!totem || !totem->ToTotem())
            {
                //TC_LOG_ERROR("entities.player", "OnBotSummon(): Shaman bot %s has summoned creature %s which is not a temp summon or not a totem...", me->GetName().c_str(), summon->GetName().c_str());
                return;
            }

            totem->SetCreatorGUID(me->GetGUID());

            int8 slot = -1;
            switch (totem->m_Properties->Id)
            {
                case SUMMON_TYPE_TOTEM_FIRE:
                    slot = T_FIRE;
                    break;
                case SUMMON_TYPE_TOTEM_EARTH:
                    slot = T_EARTH;
                    break;
                case SUMMON_TYPE_TOTEM_WATER:
                    slot = T_WATER;
                    break;
                case SUMMON_TYPE_TOTEM_AIR:
                    slot = T_AIR;
                    break;
                default:
                    TC_LOG_ERROR("entities.player", "OnBotSummon(): Shaman bot %s has summoned totem %s with unknown type %u", me->GetName().c_str(), summon->GetName().c_str(), totem->m_Properties->Id);
                    return;
            }

            float radius = 0.f;
            if (SpellInfo const* info = sSpellMgr->GetSpellInfo(summon->m_spells[0]))
                if (SpellRadiusEntry const* entry = info->Effects[0].RadiusEntry)
                    radius = entry->RadiusMax;

            _totems[slot].first = summon->GetGUID();
            _totems[slot].second.pos.Relocate(*summon);
            _totems[slot].second.effradius = std::max<float>(radius, 20.f) + 5.f;

            //TC_LOG_ERROR("entities.player", "shaman bot: summoned %s (type %u) at x='%f', y='%f', z='%f'",
            //    summon->GetName().c_str(), slot, _totems[slot].second.GetPositionX(), _totems[slot].second.GetPositionY(), _totems[slot].second.GetPositionZ());

            summon->SetDisplayId(me->GetModelForTotem(PlayerTotemType(totem->m_Properties->Id)));
            master->m_SummonSlot[++slot].Clear();
        }

        void SpellHit(Unit* caster, SpellInfo const* spell)
        {
            uint32 spellId = spell->Id;

            //Maelstrom Weapon improved: 10% to gain full stack and 30% to add an extra stack
            if (spellId == MAELSTROM_WEAPON_BUFF)
            {
                if (Aura* mwb = me->GetAura(MAELSTROM_WEAPON_BUFF))
                {
                    uint32 stacks = mwb->GetStackAmount();
                    if (stacks < 5)
                    {
                        if (urand(1,100) <= 10)
                            mwb->ModStackAmount(5);
                        if (urand(1,100) <= 30)
                            mwb->ModStackAmount(1);
                    }

                    MaelstromCount = mwb->GetStackAmount();
                }

                MaelstromTimer = 30000; //30 sec duration then reset
            }

            OnSpellHit(caster, spell);
        }

        void SpellHitTarget(Unit* target, SpellInfo const* spell)
        {
            uint32 spellId = spell->Id;
            //Shields improvement, replaces Static Shock (part 2) and Improved Earth Shield (part 1)
            if (spellId == GetSpell(LIGHTNING_SHIELD_1) ||
                spellId == GetSpell(EARTH_SHIELD_1)/* ||
                spellId == GetSpell(WATER_SHIELD_1)*/)
            {
                if (Aura* shield = target->GetAura(spellId, me->GetGUID()))
                {
                    shield->SetCharges(shield->GetCharges() + 12);
                }
            }
            //Lightning Overload: 20% cast SAME spell with no mana! make sure this does not proc on itself!
            if (me->getLevel() >= 40 && (spellId == GetSpell(LIGHTNING_SHIELD_1) || spellId == GetSpell(CHAIN_LIGHTNING_1)))
            {
                bool cast = (urand(1,100) <= 20);
                if (spellId == GetSpell(LIGHTNING_BOLT_1))
                {
                    if (LOvBolt == false)
                    {
                        if (cast)
                        {
                            LOvBolt = true;
                            me->CastSpell(target, spellId, true);
                        }
                    }
                    else
                        LOvBolt = false;
                }
                if (spellId == GetSpell(CHAIN_LIGHTNING_1))
                {
                    if (LOvChain == false)
                    {
                        if (cast)
                        {
                            LOvChain = true;
                            me->CastSpell(target, spellId, true);
                        }
                    }
                    else
                        LOvChain = false;
                }
            }
            if (spellId == GetSpell(STORMSTRIKE_1))
            {
                //Windfury: 10% chance
                if (WindfuryTimer == 0 && me->getLevel() >= 30)
                {
                    if (urand(0,100) < 10)
                        WindfuryTimer = 1000;

                    if (WindfuryTimer > 0)
                        me->CastSpell(target, WINDFURY_PROC, true);
                }
            }
        }

        void DamageDealt(Unit* victim, uint32& damage, DamageEffectType damageType)
        {
            if (victim == me)
                return;

            if (damageType == DIRECT_DAMAGE)
            {
                //Windfury: 10% chance
                if (WindfuryTimer == 0 && me->getLevel() >= 30)
                {
                    if (urand(0,100) < 10)
                        WindfuryTimer = 1000;

                    if (WindfuryTimer > 0)
                        me->CastSpell(victim, WINDFURY_PROC, true);
                }
            }

            bot_ai::DamageDealt(victim, damage, damageType);
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

        void UnsummonAll()
        {
            for (uint8 i = 0; i != MAX_TOTEMS; ++i)
            {
                if (_totems[i].first != 0)
                {
                    Unit* to = ObjectAccessor::FindConnectedPlayer(ObjectGuid(_totems[i].first));
                    if (!to)
                    {
                        //TC_LOG_ERROR("entities.player", "%s has no totem in slot %u during remove!", me->GetName().c_str(), i);
                        continue;
                    }
                    to->ToTotem()->UnSummon();
                }
            }
        }

        void Reset()
        {
            HexyCheckTimer = 3000;
            EarthyCheckTimer = 2000;
            MaelstromTimer = 0;
            WindfuryTimer = 0;

            MaelstromCount = 0;

            Hexy = false;
            Earthy = false;
            LOvBolt = false;
            LOvChain = false;

            DefaultInit();
        }

        void ReduceCD(uint32 diff)
        {
            if (HexyCheckTimer > diff)          HexyCheckTimer -= diff;
            if (EarthyCheckTimer > diff)        EarthyCheckTimer -= diff;

            if (MaelstromTimer > diff)          MaelstromTimer -= diff;
            else if (MaelstromCount > 0)        MaelstromCount = 0;

            if (WindfuryTimer > diff)           WindfuryTimer -= diff;
            else                                WindfuryTimer = 0;
        }

        void InitSpells()
        {
            uint8 lvl = me->getLevel();
            InitSpellMap(HEALING_WAVE_1);
            InitSpellMap(CHAIN_HEAL_1);
            InitSpellMap(LESSER_HEALING_WAVE_1);
  /*Talent*/lvl >= 60 ? InitSpellMap(RIPTIDE_1) : RemoveSpell(RIPTIDE_1);
            InitSpellMap(ANCESTRAL_SPIRIT_1);
            CURE_TOXINS = lvl >= 39 ? InitSpell(me, CLEANSE_SPIRIT_1) : InitSpell(me, CURE_TOXINS_1);
            InitSpellMap(CURE_TOXINS);
            InitSpellMap(FLAME_SHOCK_1);
            InitSpellMap(EARTH_SHOCK_1);
            InitSpellMap(FROST_SHOCK_1);
  /*Talent*/lvl >= 40 ? InitSpellMap(STORMSTRIKE_1) : RemoveSpell(STORMSTRIKE_1);
            InitSpellMap(LIGHTNING_BOLT_1);
            InitSpellMap(CHAIN_LIGHTNING_1);
            InitSpellMap(LAVA_BURST_1);
  /*Talent*/lvl >= 60 ? InitSpellMap(THUNDERSTORM_1) : RemoveSpell(THUNDERSTORM_1);
            InitSpellMap(LIGHTNING_SHIELD_1);
  /*Talent*/lvl >= 50 ? InitSpellMap(EARTH_SHIELD_1) : RemoveSpell(EARTH_SHIELD_1);
     /*NYI*///InitSpellMap(WATER_SHIELD_1);
            InitSpellMap(WATER_BREATHING_1);
            InitSpellMap(WATER_WALKING_1);
  /*CUSTOM*/lvl >= 60 ? InitSpellMap(BLOODLUST_1) : RemoveSpell(BLOODLUST_1);
            InitSpellMap(PURGE_1);
            InitSpellMap(WIND_SHEAR_1);
            InitSpellMap(HEX_1);
   /*Quest*/lvl >= 10 ? InitSpellMap(STONESKIN_TOTEM_1) : RemoveSpell(STONESKIN_TOTEM_1);
            InitSpellMap(HEALINGSTREAM_TOTEM_1);
            InitSpellMap(MANASPRING_TOTEM_1);
   /*Quest*/lvl >= 10 ? InitSpellMap(SEARING_TOTEM_1) : RemoveSpell(SEARING_TOTEM_1);
            InitSpellMap(WINDFURY_TOTEM_1);
            InitSpellMap(STRENGTH_OF_EARTH_TOTEM_1);
  /*Talent*/lvl >= 50 ? InitSpellMap(TOTEM_OF_WRATH_1) : RemoveSpell(TOTEM_OF_WRATH_1);
  /*Talent*/lvl >= 40 ? InitSpellMap(MANA_TIDE_TOTEM_1) : RemoveSpell(MANA_TIDE_TOTEM_1);
        }

        void ApplyClassPassives()
        {
            uint8 level = master->getLevel();

            RefreshAura(ELEMENTAL_WARDING, level >= 58 ? 2 : level >= 15 ? 1 : 0);
            RefreshAura(ELEMENTAL_DEVASTATION3, level >= 18 ? 1 : 0);
            RefreshAura(ELEMENTAL_DEVASTATION2, level >= 15 && level < 18 ? 1 : 0);
            RefreshAura(ELEMENTAL_DEVASTATION1, level >= 12 && level < 15 ? 1 : 0);
            RefreshAura(ANCESTRAL_KNOWLEDGE, level >= 30 ? 3 : level >= 20 ? 2 : level >= 10 ? 1 : 0);
            RefreshAura(TOUGHNESS, level >= 25 ? 1 : 0);
            RefreshAura(FLURRY5, level >= 29 ? 1 : 0);
            RefreshAura(FLURRY4, level >= 28 && level < 29 ? 1 : 0);
            RefreshAura(FLURRY3, level >= 27 && level < 28 ? 1 : 0);
            RefreshAura(FLURRY2, level >= 26 && level < 27 ? 1 : 0);
            RefreshAura(FLURRY1, level >= 25 && level < 26 ? 1 : 0);
            RefreshAura(WEAPON_MASTERY, level >= 50 ? 3 : level >= 40 ? 2 : level >= 30 ? 1 : 0);
            RefreshAura(STATIC_SHOCK, level >= 45 ? 2 : level >= 41 ? 1 : 0);
            RefreshAura(ANCESTRAL_HEALING, level >= 20 ? 1 : 0);
            RefreshAura(ANCESTRAL_AWAKENING, level >= 50 ? 1 : 0);
            RefreshAura(SHAMAN_T10_RESTO_4P, level >= 70 ? 1 : 0);
            RefreshAura(MAELSTROM_WEAPON5, level >= 70 ? 2 : level >= 60 ? 1 : 0);
            RefreshAura(MAELSTROM_WEAPON4, level >= 55 && level < 60 ? 1 : 0);
            RefreshAura(MAELSTROM_WEAPON3, level >= 50 && level < 55 ? 1 : 0);
            RefreshAura(MAELSTROM_WEAPON2, level >= 45 && level < 50 ? 1 : 0);
            RefreshAura(MAELSTROM_WEAPON1, level >= 40 && level < 45 ? 1 : 0);
            RefreshAura(UNLEASHED_RAGE, level >= 40 ? 1 : 0);
            RefreshAura(IMPROVED_STORMSTRIKE, level >= 40 ? 1 : 0);
            RefreshAura(ELEMENTAL_OATH, level >= 40 ? 1 : 0);
            RefreshAura(EARTHLIVING_WEAPON_PASSIVE_6, level >= 70 ? 3 : 0);
            RefreshAura(EARTHLIVING_WEAPON_PASSIVE_5, level >= 50 && level < 70 ? 3 : 0);
            RefreshAura(EARTHLIVING_WEAPON_PASSIVE_4, level >= 30 && level < 50 ? 3 : 0);
        }

        bool CanUseManually(uint32 basespell) const
        {
            switch (basespell)
            {
                case HEALING_WAVE_1:
                case CHAIN_HEAL_1:
                case LESSER_HEALING_WAVE_1:
                case RIPTIDE_1:
                case CURE_TOXINS_1:
                case CLEANSE_SPIRIT_1:
                case BLOODLUST_1:
                case WATER_SHIELD_1:
                case MANA_TIDE_TOTEM_1:
                    return true;
                default:
                    return false;
            }
        }

    private:
        typedef std::pair<uint64 /*guid*/, TotemParam /*param*/> BotTotem;
        BotTotem _totems[MAX_TOTEMS];
        uint32 CURE_TOXINS;
        //Timers
        uint32 HexyCheckTimer, EarthyCheckTimer, MaelstromTimer, WindfuryTimer;
        uint8 MaelstromCount;
        bool Hexy, Earthy, LOvChain, LOvBolt;

        enum ShamanBaseSpells
        {
            HEALING_WAVE_1                      = 331,
            CHAIN_HEAL_1                        = 1064,
            LESSER_HEALING_WAVE_1               = 8004,
            RIPTIDE_1                           = 61295,
            ANCESTRAL_SPIRIT_1                  = 2008,
            CURE_TOXINS_1                       = 526,
            CLEANSE_SPIRIT_1                    = 51886,
            FLAME_SHOCK_1                       = 8050,
            EARTH_SHOCK_1                       = 8042,
            FROST_SHOCK_1                       = 8056,
            STORMSTRIKE_1                       = 17364,
            LIGHTNING_BOLT_1                    = 403,
            CHAIN_LIGHTNING_1                   = 421,
            LAVA_BURST_1                        = 51505,
            THUNDERSTORM_1                      = 51490,
            LIGHTNING_SHIELD_1                  = 324,
            EARTH_SHIELD_1                      = 974,
            WATER_SHIELD_1                      = 52127,
            WATER_BREATHING_1                   = 131,
            WATER_WALKING_1                     = 546,
            //BLOODLUST_1                         = 54516,//custom, moved to specials
            PURGE_1                             = 370,
            WIND_SHEAR_1                        = 57994,
            HEX_1                               = 51514,
            STONESKIN_TOTEM_1                   = 8071,
            HEALINGSTREAM_TOTEM_1               = 5394,
            MANASPRING_TOTEM_1                  = 5675,
            SEARING_TOTEM_1                     = 3599,
            WINDFURY_TOTEM_1                    = 8512,
            STRENGTH_OF_EARTH_TOTEM_1           = 8075,
            TOTEM_OF_WRATH_1                    = 30706,
            MANA_TIDE_TOTEM_1                   = 16190
        };

        enum ShamanPassives
        {
            //Elemental
            ELEMENTAL_DEVASTATION1              = 30160,
            ELEMENTAL_DEVASTATION2              = 29179,
            ELEMENTAL_DEVASTATION3              = 29180,
            ELEMENTAL_WARDING                   = 28998,//rank 3
            ELEMENTAL_OATH                      = 51470,//rank 2
            //Enchancement
            ANCESTRAL_KNOWLEDGE                 = 17489,//rank 5
            TOUGHNESS                           = 16309,//rank 5
            FLURRY1                             = 16256,
            FLURRY2                             = 16281,
            FLURRY3                             = 16282,
            FLURRY4                             = 16283,
            FLURRY5                             = 16284,
            WEAPON_MASTERY                      = 29086,//rank 3
            UNLEASHED_RAGE                      = 30809,//rank 3
            STATIC_SHOCK                        = 51527,//rank 3
            IMPROVED_STORMSTRIKE                = 51522,//rank 2
            MAELSTROM_WEAPON1                   = 51528,
            MAELSTROM_WEAPON2                   = 51529,
            MAELSTROM_WEAPON3                   = 51530,
            MAELSTROM_WEAPON4                   = 51531,
            MAELSTROM_WEAPON5                   = 51532,
            //Restoration
            ANCESTRAL_HEALING                   = 16240,//rank 3
            ANCESTRAL_AWAKENING                 = 51558,//rank 3
            //Special
            SHAMAN_T10_RESTO_4P                 = 70808 //Chain Heal HoT
        };

        enum ShamanSpecial
        {
            //2 extra white attacks
            //100 yd
            //"Increases attack power for 1.50 sec"
            //Warning! can proc even from itself!
            WINDFURY_PROC                       = 32910,
            //"Increases melee,ranged and spell casting speed by 35%
            //for all party members. Lasts 20 sec."
            //250 mana, 20 yd
            //affects raid
            //no penalty
            BLOODLUST_1                         = 54516,
            //20% chance to put HoT on healed target over 12 sec
            EARTHLIVING_WEAPON_PASSIVE_4        = 52005,//348 base hp
            EARTHLIVING_WEAPON_PASSIVE_5        = 52007,//456 base hp
            EARTHLIVING_WEAPON_PASSIVE_6        = 52008,//652 base hp

            MAELSTROM_WEAPON_BUFF               = 53817,
            STORMSTRIKE_DAMAGE                  = 32175,
            STORMSTRIKE_DAMAGE_OFFHAND          = 32176,

            LIGHTNING_SHIELD_DAMAGE_1           = 26364,
            EARTH_SHIELD_HEAL                   = 379
        };
    };
};


void AddSC_shaman_bot()
{
    new shaman_bot();
}
