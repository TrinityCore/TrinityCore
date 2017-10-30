#include <ScriptPCH.h>
#include <ScriptMgr.h>

#include <Player.h>
#include <Creature.h>
#include <Pet.h>
#include <Unit.h>
#include <GameEventMgr.h>

class spell_lunar_festival_invitation : public SpellScriptLoader
{
public:
    spell_lunar_festival_invitation() : SpellScriptLoader("spell_lunar_festival_invitation") { }

    class spell_lunar_festival_invitation_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_lunar_festival_invitation_SpellScript);

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
                if (Player* player = caster->ToPlayer())
                    player->TeleportTo(1, 7585.24f, -2214.63f, 472.17f, 5.54f);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_lunar_festival_invitation_SpellScript::HandleDummy, EFFECT_1, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_lunar_festival_invitation_SpellScript();
    }
};

void AddSC_event_lunar_festival()
{
    new spell_lunar_festival_invitation();
};
