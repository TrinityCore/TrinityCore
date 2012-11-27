 /*
 *Flame orb AI by saqirmdev
 */

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "Player.h"

enum Spells
{
    SPELL_FLAME_SPHERE_SPAWN_EFFECT     = 55891, // cast from creature_template_addon (needed cast before entering world)
    SPELL_FLAME_ORB_VISUAL              = 71706,
    SPELL_FLAME_ORB                     = 71714,
	SPELL_FLAME_ORB_EXPLODE             = 83619,
    SPELL_FLAMES                        = 71393,
    SPELL_FLAME_SPHERE_DEATH_EFFECT     = 55947,
    SPELL_FLAME_ORB_PROC                = 71756,
    SPELL_FLAME_ORB_PERIODIC            = 57750

};

enum Actions
{
    ACTION_ORB_CHASE     = 1,
    ACTION_ORB_STAND     = 2

};

class spell_mage_flame_orb : public CreatureScript
{
    public:
        spell_mage_flame_orb() : CreatureScript("spell_mage_flame_orb") { }

        struct spell_mage_flame_orbAI : public ScriptedAI
        {
            spell_mage_flame_orbAI(Creature* creature) : ScriptedAI(creature)
            {
                _despawnTimer = 15000;
            }

            void Reset()
            {
                me->CastSpell(me, SPELL_FLAME_ORB_VISUAL, true);
                me->CastSpell(me, SPELL_FLAME_ORB_PROC, true);
                me->CastSpell(me, SPELL_FLAME_ORB_PERIODIC, true);
				me->AI()->DoAction(ACTION_ORB_CHASE);
               
            }

            void MovementInform(uint32 type, uint32 id)
            {
                if (type == CHASE_MOTION_TYPE && id == GUID_LOPART(_chaseGUID) && _chaseGUID)
                {
                    me->RemoveAurasDueToSpell(SPELL_FLAME_ORB_PERIODIC);
                    DoCast(me, SPELL_FLAMES);
                    _despawnTimer = 1000;
                    _chaseGUID = 0;
                }
            }

            void SetGUID(uint64 guid, int32 /*type*/)
            {
                _chaseGUID = guid;
            }

            void DoAction(int32 const action)
            {
                if (action == ACTION_ORB_CHASE)
                    if (Player* target = ObjectAccessor::GetPlayer(*me, _chaseGUID))
                    {
                        me->ClearUnitState(UNIT_STATE_CASTING | UNIT_STATE_STUNNED);
                        if (target && me->Attack(target, true))
                            me->GetMotionMaster()->MoveChase(target, 1.0f);
                    }
            }

            void DamageDealt(Unit* /*target*/, uint32& damage, DamageEffectType damageType)
            {
                if (damageType != SPELL_DIRECT_DAMAGE)
                    return;
            }

            void UpdateAI(uint32 const diff)
            {
                if (!_despawnTimer)
                    return;

                if (_despawnTimer <= diff)
                {
                    _despawnTimer = 0;
                    DoCast(me, SPELL_FLAME_SPHERE_DEATH_EFFECT);
                }
                else
                    _despawnTimer -= diff;

				if (_despawnTimer <= 100)
					if (me->HasAura(54734) || me->HasAura(18460) || me->HasAura(18459))
					   me->CastSpell(me, SPELL_FLAME_ORB_EXPLODE, true);
            }

        private:
            uint64 _chaseGUID;
            InstanceScript* _instance;
            uint32 _despawnTimer;
        };
};

class spell_mage_frostfire_orb : public CreatureScript
{
    public:
        spell_mage_frostfire_orb() : CreatureScript("spell_mage_frostfire_orb") { }

        struct spell_mage_frostfire_orbAI : public ScriptedAI
        {
            spell_mage_frostfire_orbAI(Creature* creature) : ScriptedAI(creature)
            {
                _despawnTimer = 15000;
            }

            void Reset()
            {
                me->CastSpell(me, SPELL_FLAME_ORB_VISUAL, true);
                me->CastSpell(me, SPELL_FLAME_ORB_PROC, true);
                me->CastSpell(me, SPELL_FLAME_ORB_PERIODIC, true);
				me->AI()->DoAction(ACTION_ORB_CHASE);
               
            }

            void MovementInform(uint32 type, uint32 id)
            {
                if (type == CHASE_MOTION_TYPE && id == GUID_LOPART(_chaseGUID) && _chaseGUID)
                {
                    me->RemoveAurasDueToSpell(SPELL_FLAME_ORB_PERIODIC);
                    DoCast(me, SPELL_FLAMES);
                    _despawnTimer = 1000;
                    _chaseGUID = 0;
                }
            }

            void SetGUID(uint64 guid, int32 /*type*/)
            {
                _chaseGUID = guid;
            }

            void DoAction(int32 const action)
            {
                if (action == ACTION_ORB_CHASE)
                    if (Player* target = ObjectAccessor::GetPlayer(*me, _chaseGUID))
                    {
                        me->ClearUnitState(UNIT_STATE_CASTING | UNIT_STATE_STUNNED);
                        if (target && me->Attack(target, true))
                            me->GetMotionMaster()->MoveChase(target, 1.0f);
                    }
            }

            void DamageDealt(Unit* /*target*/, uint32& damage, DamageEffectType damageType)
            {
                if (damageType != SPELL_DIRECT_DAMAGE)
                    return;
            }

            void UpdateAI(uint32 const diff)
            {
                if (!_despawnTimer)
                    return;

                if (_despawnTimer <= diff)
                {
                    _despawnTimer = 0;
                    DoCast(me, SPELL_FLAME_SPHERE_DEATH_EFFECT);
                }
                else
                    _despawnTimer -= diff;

				if (_despawnTimer <= 100)
					if (me->HasAura(54734) || me->HasAura(18460) || me->HasAura(18459))
					   me->CastSpell(me, SPELL_FLAME_ORB_EXPLODE, true);
            }

        private:
            uint64 _chaseGUID;
            InstanceScript* _instance;
            uint32 _despawnTimer;
        };
};

void AddSC_Flame_orb()
{
  new spell_mage_flame_orb();
  new spell_mage_frostfire_orb();
}