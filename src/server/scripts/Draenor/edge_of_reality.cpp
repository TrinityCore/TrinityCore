/*
    uwow.biz
*/

#include "LFGMgr.h"
#include "Position.h"
#include "GameObject.h"

//179523
class spell_launch_voidtalon_scenario : public SpellScript
{
    PrepareSpellScript(spell_launch_voidtalon_scenario);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Player* player = GetCaster()->ToPlayer();
        if (!player)
            return;

        std::set<uint32> Slot;
        Slot.insert(907);
        sLFGMgr->JoinLfg(player, lfg::LfgRoles::PLAYER_ROLE_DAMAGE, Slot);

        if (auto go = player->FindNearestGameObject(239828, 10.0f))
        {
            go->SetRespawnTime(0);
            go->Delete();
        }
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_launch_voidtalon_scenario::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_voidtalon_backup : public AuraScript
{
    PrepareAuraScript(spell_voidtalon_backup);

    Position pos;
    uint16 mapid;

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Player* player = GetCaster()->ToPlayer();
        if (!player)
            return;

        pos.m_positionX = player->GetPositionX();
        pos.m_positionY = player->GetPositionY();
        pos.m_positionZ = player->GetPositionZ();
        //pos.m_orientation = player->GetOrientation();
        mapid = player->GetMapId();
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Player* player = GetCaster()->ToPlayer();
        if (!player)
            return;

        if (player->GetMapId() == 1455);
            //  player->TeleportTo(mapid, &pos);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_voidtalon_backup::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_voidtalon_backup::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_edge_of_reality()
{
    RegisterSpellScript(spell_launch_voidtalon_scenario);
    RegisterAuraScript(spell_voidtalon_backup);
}