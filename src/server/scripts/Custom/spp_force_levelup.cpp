/*
 * Made by ConanHUN for Single Player Project - Ashamane (legion) repack
 */

#include "Config.h"
#include "Player.h"

class spp_custom_starting : public PlayerScript
{
public:
    spp_custom_starting() : PlayerScript("spp_custom_starting") { }

    void OnLogin(Player* p_Player, bool /*firstLogin*/)
    {
        if (sConfigMgr->GetBoolDefault("Force.Starting.Level", false))//强制升级
        {
            if (p_Player->getLevel() >= 1)
            {
                p_Player->SetLevel(sConfigMgr->GetIntDefault("Force.Starting.Level.Value", 10));//大于1级直接升10,原先为110级
            }

            if (p_Player->GetMapId() == 648)
            {
                p_Player->LearnSpell(77534, true); // Pack Hobgoblin
            }

            if (p_Player->GetMapId() == 654)
            {
                p_Player->LearnSpell(72792, true); // Learn Racials
                p_Player->LearnSpell(72857, true); // Learn Two Forms
                p_Player->LearnSpell(95759, true); // Learn Darkflight
            }

            if (p_Player->getRace() == RACE_PANDAREN_NEUTRAL)
            {
                //p_Player->ShowNeutralPlayerFactionSelectUI();//中立玩家选择阵营UI,暂时不知道新语法
            }
        }

        if (sConfigMgr->GetBoolDefault("Force.Teleport", false))//强制传送
        {
            int force_teleport_map = sConfigMgr->GetIntDefault("Force.Teleport.Map", 0);
            int force_teleport_x = sConfigMgr->GetIntDefault("Force.Teleport.X", 0);
            int force_teleport_y = sConfigMgr->GetIntDefault("Force.Teleport.Y", 0);
            int force_teleport_z = sConfigMgr->GetIntDefault("Force.Teleport.Z", 0);
            int force_teleport_o = sConfigMgr->GetIntDefault("Force.Teleport.O", 0);

            p_Player->TeleportTo(force_teleport_map, force_teleport_x, force_teleport_y, force_teleport_z, force_teleport_o);
        }

        ObjectAccessor::SaveAllPlayers();
    }
};

void AddSC_custom_starting()
{
    new spp_custom_starting;
}
