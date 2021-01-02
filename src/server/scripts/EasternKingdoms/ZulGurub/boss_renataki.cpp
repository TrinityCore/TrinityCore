/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "zulgurub.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"

enum Spells
{
    SPELL_AMBUSH = 34794,
    SPELL_THOUSANDBLADES = 34799
};

enum Misc
{
    EQUIP_ID_MAIN_HAND = 0 // was item display id 31818, but this id does not exist
};

class boss_renataki : public CreatureScript
{
    public:
        boss_renataki() : CreatureScript("boss_renataki") { }

        struct boss_renatakiAI : public BossAI
        {
            boss_renatakiAI(Creature* creature) : BossAI(creature, DATA_EDGE_OF_MADNESS)
            {
                Initialize();
            }

            void Initialize()
            {
                _invisibleTimer = urand(8000, 18000);
                _ambushTimer = 3000;
                _visibleTimer = 4000;
                _aggroTimer = urand(15000, 25000);
                _thousandBladesTimer = urand(4000, 8000);
                _invisible = false;
                _ambushed = false;
            }

            void Reset() override
            {
                _Reset();
                Initialize();
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (_invisibleTimer <= diff)
                {
                    me->InterruptSpell(CURRENT_GENERIC_SPELL);
                    SetEquipmentSlots(false, EQUIP_UNEQUIP, EQUIP_NO_CHANGE, EQUIP_NO_CHANGE);
                    me->SetDisplayId(11686);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    _invisible = true;
                    _invisibleTimer = urand(15000, 30000);
                }
                else
                    _invisibleTimer -= diff;

                if (_invisible)
                {
                    if (_ambushTimer <= diff)
                    {
                        if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f, true))
                        {
                            DoTeleportTo(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ());
                            DoCast(target, SPELL_AMBUSH);
                        }

                        _ambushed = true;
                        _ambushTimer = 3000;
                    }
                    else
                        _ambushTimer -= diff;
                }

                if (_ambushed)
                {
                    if (_visibleTimer <= diff)
                    {
                        me->InterruptSpell(CURRENT_GENERIC_SPELL);
                        me->SetDisplayId(15268);
                        SetEquipmentSlots(false, EQUIP_ID_MAIN_HAND, EQUIP_NO_CHANGE, EQUIP_NO_CHANGE);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        _invisible = false;
                        _visibleTimer = 4000;
                    }
                    else
                        _visibleTimer -= diff;
                }

                // Resetting some aggro so he attacks other gamers
                if (!_invisible)
                {
                    if (_aggroTimer <= diff)
                    {
                        if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f, true))
                        {
                            if (GetThreat(me->GetVictim()))
                                ModifyThreatByPercent(me->GetVictim(), -50);
                            AttackStart(target);
                        }

                        _aggroTimer = urand(7000, 20000);
                    }
                    else
                        _aggroTimer -= diff;

                    if (_thousandBladesTimer <= diff)
                    {
                        DoCastVictim(SPELL_THOUSANDBLADES);
                        _thousandBladesTimer = urand(7000, 12000);
                    }
                    else
                        _thousandBladesTimer -= diff;
                }

                DoMeleeAttackIfReady();
            }

        private:
            uint32 _invisibleTimer;
            uint32 _ambushTimer;
            uint32 _visibleTimer;
            uint32 _aggroTimer;
            uint32 _thousandBladesTimer;
            bool _invisible;
            bool _ambushed;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetZulGurubAI<boss_renatakiAI>(creature);
        }
};

void AddSC_boss_renataki()
{
    new boss_renataki();
}
