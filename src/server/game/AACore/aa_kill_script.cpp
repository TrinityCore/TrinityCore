#include "ScriptMgr.h"
#include "ObjectMgr.h"
#include "Language.h"
#include "DisableMgr.h"
#include "WorldSession.h"
#include "Player.h"
#include "Group.h"
#include "Pet.h"
#include "ObjectAccessor.h"

using namespace std;

class aa_kill_script : public PlayerScript
{
private:
    // pve 击杀怪物触发
    void KillCreature(Unit* killer, Creature* killed) {
        if (!killer || !killer->IsInWorld() || !killed || !killed->IsInWorld() || killed->IsTotem() || killed->IsPet()) {
            return;
        }

        //析构参数
        ObjectGuid guid;
        aaCenter.m_aiTimes.erase(guid);
        aaCenter.m_aiGGTimes.erase(guid);

        try {
            Player *player = killer->ToPlayer();
            Player *looter = ObjectAccessor::FindPlayer(killed->GetCreatorGUID());
            if (looter && looter->IsInWorld()) {
                player = looter;
            } else {
                if (Creature *creature = killer->ToCreature()) {
                    if (creature->IsPet()) {
                        Pet *pet = creature->ToPet();
                        player = pet->GetOwner();
                    }
                }
            }
            if (!player || player->GetTypeId() != TYPEID_PLAYER) {
                return;
            }
            if (killed->GetTypeId() == TYPEID_UNIT) {
                AA_Creature_Exp econf = aaCenter.aa_creature_exps[killed->GetEntry()];
                if (econf.creatureid > 0) {
                    // 军衔经验 斗气经验 巅峰经验 成长经验
                    {
                        uint32 axp = 0;
                        if (econf.expjx > 0) {
                            axp += econf.expjx;
                        }
                        if (axp > 0) {
                            aaCenter.GiveJXXP(player, axp);
                        }
                    }
                    {
                        uint32 axp = 0;
                        if (econf.expdq > 0) {
                            axp += econf.expdq;
                        }
                        if (axp > 0) {
                            aaCenter.GiveDQXP(player, axp);
                        }
                    }
                    {
                        uint32 axp = 0;
                        if (econf.expdf > 0) {
                            axp += econf.expdf;
                        }
                        if (axp > 0) {
                            aaCenter.GiveDFXP(player, axp);
                        }
                    }
                    {
                        if (aaCenter.aa_world_confs[57].value1 == 1) {
                            uint32 axp = 0;
                            if (econf.expcz > 0) {
                                axp += econf.expcz;
                            }
                            if (axp > 0) {
                                aaCenter.GiveCZXP(player, axp);
                            }
                        }
                    }
                }
            }
            AA_Creature c_conf = aaCenter.aa_creatures[killed->aa_id];
            uint32 pid = player->GetAreaId();
            if (player->GetGroup()) {
                if (c_conf.reward_dz > 0 && c_conf.reward_dz_chance > 0) {
                    if (Player* p = ObjectAccessor::FindPlayer(player->GetGroup()->GetLeaderGUID())) {
                        if (p->IsInWorld()) {
                            uint32 dzid = p->GetAreaId();
                            if (pid == dzid) {
                                if (roll_chance_f(c_conf.reward_dz_chance)) {
                                    aaCenter.M_Reward(p, c_conf.reward_dz);
                                }
                            }
                        }
                    }
                }
                if (c_conf.reward_dw > 0 && c_conf.reward_dw_chance > 0) {
                    Group::MemberSlotList const& members = player->GetGroup()->GetMemberSlots();
                    bool isOk = true;
                    for (Group::MemberSlotList::const_iterator itr = members.begin(); itr != members.end(); ++itr)
                    {
                        if (Player* p = ObjectAccessor::FindPlayer((*itr).guid)) {
                            if (!p->IsInWorld()) {
                                continue;
                            }
                            uint32 dwid = p->GetAreaId();
                            //队员和击杀者不在同一区域，不享受奖励
                            if (pid != dwid) {
                                continue;
                            }
                            //有队长奖励，就没有队伍奖励
                            if (player->GetGroup()->GetLeaderGUID() == (*itr).guid && c_conf.reward_dz > 0 && c_conf.reward_dz_chance > 0) {
                                continue;
                            }
                            if (roll_chance_f(c_conf.reward_dw_chance)) {
                                aaCenter.M_Reward(p, c_conf.reward_dw);
                            }
                        }
                    }
                }
            }
            else {//没有队伍，才有击杀奖励
                if (c_conf.reward > 0 && c_conf.reward_chance > 0) {
                    if (roll_chance_f(c_conf.reward_chance)) {
                        aaCenter.M_Reward(player, c_conf.reward);
                    }
                }
            }
            if (c_conf.tanchuang > 0) {
                aaCenter.AA_EventStart(player, c_conf.tanchuang);
            }
            if (c_conf.notice > 0) {
                AA_Message aa_message;
                aa_message.target_creature = killed;
                AA_Notice aa_notice = aaCenter.aa_notices[c_conf.notice];
                aaCenter.AA_SendNotice(player, aa_notice, true, aa_message);
            }
        } catch (std::exception const& e) { }
    }
    void KillPlayer(Unit* killer, Player* killed) {
        if (!killer || !killer->IsInWorld() || !killed || !killed->IsInWorld()) {
            return;
        }
        //副本死亡次数限制x，超出次数限制，传到出生地
        if (aaCenter.AA_VerifyCode("a101b")) {
            if (Map *map = killed->GetMap()) {
                AA_Map_Player_Conf conf = aaCenter.AA_GetAA_Map_Player_Conf(killed);
                if (conf.dietime > 0) {
                    ObjectGuid::LowType guidlow = killed->GetGUID().GetCounter();
                    uint32 dietime = 0;
                    if (conf.m_mapmoshi == 0) {
                        aaCenter.aa_pmapvalues[conf.m_mapid][guidlow][0] += 1;
                        dietime = aaCenter.aa_pmapvalues[conf.m_mapid][guidlow][0];
                    } else if (conf.m_mapmoshi == 1) {
                        aaCenter.aa_pzonevalues[conf.m_mapid][guidlow][0] += 1;
                        dietime = aaCenter.aa_pzonevalues[conf.m_mapid][guidlow][0];
                    } else if (conf.m_mapmoshi == 2) {
                        aaCenter.aa_pareavalues[conf.m_mapid][guidlow][0] += 1;
                        dietime = aaCenter.aa_pareavalues[conf.m_mapid][guidlow][0];
                    } else if (conf.m_mapmoshi == 3) {
                        aaCenter.aa_pinstancevalues[conf.m_mapid][guidlow][0] += 1;
                        dietime = aaCenter.aa_pinstancevalues[conf.m_mapid][guidlow][0];
                    }
                    aaCenter.AA_UpdateValueBools(conf.m_mapid, conf.m_mapmoshi, true, guidlow);
                    if (dietime >= conf.dietime) {
                        aaCenter.AA_SendMessage(killed, 2, "|cff00FFFF[系统提示]|cffFF0000你的死亡次数已用尽，你被传出区域。|r");
                        aaCenter.AA_SendMessage(killed, 2, "|cff00FFFF[系统提示]|cffFF0000你的死亡次数已用尽，你被传出区域。|r");
                        aaCenter.AA_SendMessage(killed, 2, "|cff00FFFF[系统提示]|cffFF0000你的死亡次数已用尽，你被传出区域。|r");
                        killed->TeleportTo(killed->m_homebind.GetMapId(), killed->m_homebind.GetPositionX(), killed->m_homebind.GetPositionY(), killed->m_homebind.GetPositionZ(), killed->m_homebind.GetOrientation());
                    }
                }
            }
        }
        //狂暴模式
        if (aaCenter.aa_world_confs[83].value1 > 0) {
            //击杀狂暴者奖励
            //狂暴者被击杀，如果不在限制地图，取消光环
            if (Player *p = killer->ToPlayer()) {
                if (killed->isKuangbao) {
                    bool isOk = false;
                    if (aaCenter.aa_world_confs[83].value2 != "0" && aaCenter.aa_world_confs[83].value2 != "1") {
                        std::vector<int32> areaIds; areaIds.clear();
                        aaCenter.AA_StringToVectorInt(aaCenter.aa_world_confs[83].value2, areaIds, ",");
                        isOk = std::find(areaIds.begin(), areaIds.end(), killed->GetAreaId()) != areaIds.end();
                    }
                    if (!isOk) { //不在限制地图
                        killed->RemoveAura(aaCenter.aa_world_confs[83].value1);
                        if (aaCenter.aa_world_confs[84].value2 != "") {
                            aaCenter.AA_DoCommand(p, aaCenter.aa_world_confs[84].value2.c_str());
                        }
                        //狂暴者被击杀提示
                        AA_Message aa_message;
                        aa_message.target_player = p;
                        AA_Notice notice = aaCenter.aa_notices[24];
                        aaCenter.AA_SendNotice(killed, notice, false, aa_message);
                        killed->isKuangbao = false;
                    }
                }
            }
        }
    }
    void KilledByPlayer(Player* killer, Unit* killed)
    {
        if (!killer || !killer->IsInWorld() || !killed || !killed->IsInWorld()) {
            return;
        }
        if (aaCenter.AA_VerifyCode("a101b")) {//副本通关奖励x，副本通关公告x，Boss击杀公告
            //获取所击杀的怪物的经验
            //TODO 副本进度，需要保存DB
            Player *player = killer->ToPlayer();
            if (Creature *creature = killed->ToCreature()) {
                if (creature->IsPet()) {
                    return;
                }
                Player* looter = ObjectAccessor::FindPlayer(creature->GetCreatorGUID());
                if (looter && looter->IsInWorld()) {
                    player = looter;
                }
            }

            if (!player) {
                return;
            }
            //1设置地图进度经验
            //2设置进度奖励状态
            //3发放奖励
            if (player->GetAreaId() == killed->GetAreaId()) {
                if (Map *map = killed->GetMap()) {
                    AA_Map_Player_Conf conf = aaCenter.AA_GetAA_Map_Player_Conf(player);
                    if (conf.jindu_exp != "" && conf.jindu_exp != "0") {
                        uint32 rank = 0;
                        if (Creature *creture = killed->ToCreature()) {
                            rank = creture->GetCreatureTemplate()->rank;
                        } else if (Player *player = killed->ToPlayer()) {
                            rank = 999;
                        }
                        uint32 exp = 0;
                        std::map<int32, int32> exps; exps.clear();
                        aaCenter.AA_StringToMap(conf.jindu_exp, exps);
                        exp = exps[rank];
                        if (conf.m_mapmoshi == 0) {
                            aaCenter.aa_mmapvalues[conf.m_mapid][2] += exp;
                            conf.m_jindu_exp = aaCenter.aa_mmapvalues[conf.m_mapid][2];
                        } else if (conf.m_mapmoshi == 1) {
                            aaCenter.aa_mzonevalues[conf.m_mapid][2] += exp;
                            conf.m_jindu_exp = aaCenter.aa_mzonevalues[conf.m_mapid][2];
                        } else if (conf.m_mapmoshi == 2) {
                            aaCenter.aa_mareavalues[conf.m_mapid][2] += exp;
                            conf.m_jindu_exp = aaCenter.aa_mareavalues[conf.m_mapid][2];
                        } else if (conf.m_mapmoshi == 3) {
                            aaCenter.aa_minstancevalues[conf.m_mapid][2] += exp;
                            conf.m_jindu_exp = aaCenter.aa_minstancevalues[conf.m_mapid][2];
                        }
                    }
                    std::map<int32, int32> rewards; rewards.clear();
                    if (conf.jindu_reward != "" && conf.jindu_reward != "0") {
                        aaCenter.AA_StringToMap(conf.jindu_reward, rewards);
                    }
                    //获取当前应该奖励的经验
                    std::map<int32, int32> reward_duixiangs; reward_duixiangs.clear();
                    if (conf.jindu_reward_duixiang != "" && conf.jindu_reward_duixiang != "0") {
                        aaCenter.AA_StringToMap(conf.jindu_reward_duixiang, reward_duixiangs);
                    }
                    if (rewards.size() > 0) {
                        uint32 maxexp = 0;
                        for (auto itr : rewards) {
                            if (itr.second == 0) {
                                continue;
                            }
                            maxexp = maxexp >= (uint32)itr.first ? maxexp : (uint32)itr.first;
                            if (conf.m_jindu_exp >= (uint32)itr.first && conf.m_jindu_status[itr.first] == 0) {
                                if (conf.m_mapmoshi == 0) {
                                    aaCenter.aa_mmapbools[conf.m_mapid][itr.first] = 1;
                                } else if (conf.m_mapmoshi == 1) {
                                    aaCenter.aa_mzonebools[conf.m_mapid][itr.first] = 1;
                                } else if (conf.m_mapmoshi == 2) {
                                    aaCenter.aa_mareabools[conf.m_mapid][itr.first] = 1;
                                } else if (conf.m_mapmoshi == 3) {
                                    aaCenter.aa_minstancebools[conf.m_mapid][itr.first] = 1;
                                }
                                conf.m_jindu_status[itr.first] = 1;
                                aaCenter.AA_UpdateValueBools(conf.m_mapid, conf.m_mapmoshi, false);
                                Map::PlayerList const& players = map->GetPlayers();
                                for (Map::PlayerList::const_iterator i = players.begin(); i != players.end(); ++i)
                                {
                                    if (Player* player = i->GetSource())
                                    {
                                        if (player->IsInWorld()) {
                                            if (player->GetAreaId() == killed->GetAreaId()) {
                                                aaCenter.M_Reward(player, itr.second);
                                                if (conf.jindu_notice > 0) {
                                                    AA_Message aa_message;
                                                    AA_Notice notice = aaCenter.aa_notices[conf.jindu_notice];
                                                    aaCenter.AA_SendNotice(player, notice, false, aa_message);
                                                }
                                                if (reward_duixiangs[itr.first] > 0) {
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (conf.m_jindu_exp >= maxexp) {
                            if (conf.m_mapmoshi == 0) {
                                aaCenter.aa_mmapvalues[conf.m_mapid][2] = 0;
                                for (auto iter : aaCenter.aa_mmapbools[conf.m_mapid])
                                    aaCenter.aa_mmapbools[conf.m_mapid][iter.first] = 0;
                            } else if (conf.m_mapmoshi == 1) {
                                aaCenter.aa_mzonevalues[conf.m_mapid][2] = 0;
                                for (auto iter : aaCenter.aa_mzonebools[conf.m_mapid])
                                    aaCenter.aa_mzonebools[conf.m_mapid][iter.first] = 0;
                            } else if (conf.m_mapmoshi == 2) {
                                aaCenter.aa_mareavalues[conf.m_mapid][2] = 0;
                                for (auto iter : aaCenter.aa_mareabools[conf.m_mapid])
                                    aaCenter.aa_mareabools[conf.m_mapid][iter.first] = 0;
                            } else if (conf.m_mapmoshi == 3) {
//                                aaCenter.aa_minstancevalues[conf.m_mapid][2] = 0;
//                                for (auto iter : aaCenter.aa_pinstancebools[conf.m_mapid][guidlow])
//                                    aaCenter.aa_pinstancebools[conf.m_mapid][guidlow][iter.first] = 0;
                            }
                            aaCenter.AA_UpdateValueBools(conf.m_mapid, conf.m_mapmoshi, false);
                        }
                    }
                    aaCenter.AA_UpdateValueBools(conf.m_mapid, conf.m_mapmoshi, true);
                }
            }
        }
    }
    
public:
    aa_kill_script() : PlayerScript("aa_kill_script") { }
    
    // pvp 人杀了人
    void OnPVPKill(Player* killer, Player* killed) override
    {
        if (!killer || !killer->IsInWorld() || !killed || !killed->IsInWorld() || killer == killed) {
            return;
        }
        KillPlayer(killer, killed);
        KilledByPlayer(killer, killed);
        // 被杀触发
        try {
            if (!aaCenter.aa_lianshas.empty()) {
                // 连杀奖励
                {
                    uint32 count = killer->liansha + 1;
                    AA_Liansha conf = aaCenter.aa_lianshas[count];
                    if (conf.quyu_liansha == "") {
                        conf = aaCenter.aa_lianshas[999];
                    }
                    if (conf.quyu_liansha != "") {
                        std::vector<int32> areaIds; areaIds.clear();
                        aaCenter.AA_StringToVectorInt(conf.quyu_liansha, areaIds, ",");
                        if (std::find(areaIds.begin(), areaIds.end(), killer->GetAreaId()) != areaIds.end() || conf.quyu_liansha == "-1") {
                            killer->liansha = killer->liansha + 1;
                            if (killer->liansha > 0) {
                                if (conf.reward_liansha > 0) {
                                    aaCenter.M_Reward(killer, conf.reward_liansha);
                                }
                                if (conf.notice_liansha > 0) {
                                    AA_Message aa_message;
                                    aa_message.target_player = killed;
                                    AA_Notice notice = aaCenter.aa_notices[conf.notice_liansha];
                                    aaCenter.AA_SendNotice(killer, notice, true, aa_message);
                                } else {
                                    AA_Message aa_message;
                                    aa_message.target_player = killed;
                                    AA_Notice notice = aaCenter.aa_notices[6];
                                    aaCenter.AA_SendNotice(killer, notice, true, aa_message);
                                }
                            } else {
                                AA_Message aa_message;
                                aa_message.target_player = killed;
                                AA_Notice notice = aaCenter.aa_notices[6];
                                aaCenter.AA_SendNotice(killer, notice, true, aa_message);
                            }
                        }
                    }
                }
                // 终结奖励
                {
                    if (killed->liansha > 0) {
                        AA_Liansha conf = aaCenter.aa_lianshas[killed->liansha];
                        if (conf.quyu_zhongjie == "") {
                            conf = aaCenter.aa_lianshas[999];
                        }
                        if (conf.quyu_zhongjie != "") {
                            std::vector<int32> areaIds; areaIds.clear();
                            aaCenter.AA_StringToVectorInt(conf.quyu_zhongjie, areaIds, ",");
                            if (std::find(areaIds.begin(), areaIds.end(), killer->GetAreaId()) != areaIds.end() || conf.quyu_zhongjie == "-1") {
                                if (conf.reward_zhongjie > 0) {
                                    aaCenter.M_Reward(killer, conf.reward_zhongjie);
                                }
                                if (conf.notice_zhongjie > 0) {
                                    AA_Message aa_message;
                                    aa_message.target_player = killed;
                                    AA_Notice notice = aaCenter.aa_notices[conf.notice_zhongjie];
                                    aaCenter.AA_SendNotice(killer, notice, true, aa_message);
                                }
                                killed->liansha = 0;
                            }
                        }
                    }
                }
            } else {
                AA_Message aa_message;
                aa_message.target_player = killed;
                AA_Notice notice = aaCenter.aa_notices[6];
                aaCenter.AA_SendNotice(killer, notice, true, aa_message);
            }
        } catch (std::exception const& e) { }
    }
    // pve 怪物被宠物击杀
    void OnCreatureKilledByPet(Player* PetOwner, Creature* killed) override
    {
        if (!PetOwner || !PetOwner->IsInWorld() || !killed || !killed->IsInWorld()) {
            return;
        }
        KillCreature(PetOwner, killed);
        KilledByPlayer(PetOwner, killed);
    }
    // pve 怪物自杀
    void OnCreatureKilledBySelf(Creature* killer) override
    {
        if (!killer || !killer->IsInWorld()) {
            return;
        }
        KillCreature(killer, killer);
    }
    // pve 怪物被人击杀
    void OnCreatureKill(Player* killer, Creature* killed) override
    {
        if (!killer || !killer->IsInWorld() || !killed || !killed->IsInWorld()) {
            return;
        }
        KillCreature(killer, killed);
        KilledByPlayer(killer, killed);
    }
    // pve 人被怪物杀触发
    void OnPlayerKilledByCreature(Creature* killer, Player* killed) override
    {
        if (!killer || !killer->IsInWorld() || !killed || !killed->IsInWorld()) {
            return;
        }
        KillPlayer(killer, killed);
        AA_Message aa_message;
        aa_message.target_creature = killer;
        AA_Notice notice = aaCenter.aa_notices[5];
        aaCenter.AA_SendNotice(killed, notice, true, aa_message);
    }
};

void AddAA_Kill_Script()
{
    new aa_kill_script();
}
