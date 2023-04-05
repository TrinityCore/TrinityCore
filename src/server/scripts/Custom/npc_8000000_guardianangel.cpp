//成功
/*
to world db:

//INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_class`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `WidgetSetID`, `WidgetSetUnitConditionID`, `RegenHealth`, `mechanic_immune_mask`, `spell_school_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES (8000000, 0, 0, 0, 0, 0, 'Mysterious Angel', 'Mysterious Angel', 'The Savior', NULL, NULL, 0, 60, 60, 8, 0, 0, 35, 1, 1, 1.14286, 1, 0, 0, 0, 0, 1, 1, 2, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 'GuardianAngel', 36949);
//上句出错
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_class`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`,`HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `WidgetSetID`, `WidgetSetUnitConditionID`, `RegenHealth`, `mechanic_immune_mask`, `spell_school_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES(8000000, 0, 0, 0, 0, 0, 'Mysterious Angel', 'Mysterious Angel', 'The Savior', NULL, NULL, 0, 60, 60, 8, 0, 0, 35, 1, 1, 1.14286, 1, 0, 0, 0, 0, 1, 1, 2, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 'GuardianAngel', 36949);
INSERT INTO `creature_template_model` (`CreatureID`, `Idx`, `CreatureDisplayID`, `DisplayScale`, `Probability`, `VerifiedBuild`) VALUES (8000000, 0, 97824, 1, 1, 36949);

to worldserver.conf:

###################################################################################################
#
#	e.g.: 2175, 2261, 2369 are Exile Reach
#

GuardianAngel.Enable = 1
GuardianAngel.Minutes.For.Assist = 1
GuardianAngel.AllowedMapIDs = "2175, 2261, 2369"

#
###################################################################################################

*/

#include <wtypes.h>
#include "Creature.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "Config.h"
#include "Chat.h"
#include "ScriptedGossip.h"
#include "GameTime.h"
#include "PhasingHandler.h"
#include "ScriptedCreature.h"
#include "GossipDef.h"
#include "Object.h"

class GuardianAngel_Spawn : public PlayerScript
{
public:
    GuardianAngel_Spawn() : PlayerScript("GuardianAngel_Spawn") { }

    void SummonGuardianAngel(Player* player)
    {
        // if the guardian angle enabled in config
        if (sConfigMgr->GetBoolDefault("GuardianAngel.Enable", true))
        {
            // we get the mapids
            std::string allowedmapids = sConfigMgr->GetStringDefault("GuardianAngel.AllowedMapIDs", "");
            std::stringstream allowedmapidsstream(allowedmapids);
            std::string temp;
            std::unordered_set<int> allowedmapids_;

            bool guardianangelwatchinghere = false;

            // we check the mapids
            while (std::getline(allowedmapidsstream, temp, ','))
                allowedmapids_.insert(atol(temp.c_str()));
            for (auto allowedmap = allowedmapids_.begin(); allowedmap != allowedmapids_.end(); ++allowedmap)
            {
                UINT number = *(allowedmap);
                if (player->GetMapId() == number) guardianangelwatchinghere = true;
                //debug to check mapids in config...yes i tested it and successfully gets multiple ids!!! yeey
                //ChatHandler(player->GetSession()).PSendSysMessage("Actual mapids from config: %s",(std::to_string(number)));
            }

            // if player is on the specified maps the guardian angel watches lol
            if (guardianangelwatchinghere)
            {
                // summon guardian angel for a while
                //uint32 minutesforassist = sConfigMgr->GetIntDefault("GuardianAngel.Minutes.For.Assist", 1);
                //TempSummon* npc = player->SummonCreature(8000000, player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, minutesforassist * 60000, ObjectGuid::Empty);//ObjectGuid privateObjectOwner /* = ObjectGuid::Empty */
                //暂时注释看看
                //这个是新的,但是启用这句后,生成的最后报错
                //报错内容如下
                //严重性	代码	说明	项目	文件	行	禁止显示状态
                //错误	LNK2019	无法解析的外部符号 "public: class TempSummon * __cdecl WorldObject::SummonCreature(unsigned int,float,float,float,float,enum TempSummonType,unsigned int,class ObjectGuid)" (? SummonCreature@WorldObject@@QEAAPEAVTempSummon@@IMMMMW4TempSummonType@@IVObjectGuid@@@Z)，函数 "public: void __cdecl GuardianAngel_Spawn::SummonGuardianAngel(class Player *)" (? SummonGuardianAngel@GuardianAngel_Spawn@@QEAAXPEAVPlayer@@@Z) 中引用了该符号	D : \Program Files(x86)\WOWDIY\TrinityCore\out\build\x64 - Debug\TrinityCore	D : \Program Files(x86)\WOWDIY\TrinityCore\out\build\x64 - Debug\scripts.lib(npc_8000000_guardianangel.cpp.obj)	1

                //player->SummonCreature(8000000, player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, minutesforassist * 60000, ObjectGuid::Empty);//ObjectGuid privateObjectOwner /* = ObjectGuid::Empty */
                //我尝试的,还是不行,一样报错

                //原本的类型
                //Creature* npc = player->SummonCreature(8000000, player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, minutesforassist * 60000, ObjectGuid::Empty);//ObjectGuid privateObjectOwner /* = ObjectGuid::Empty */   //, ObjectGuid::Empty
                //此处临时注释
                //此处是大问题,参数不匹配,新增旧模板,但是不起作用
            }

        }
    }


    // if the player getting killed by a mob
    void OnPlayerKilledByCreature(Creature* /*killer*/, Player* player)
    {
        SummonGuardianAngel(player);
    }

    // if the player getting killed by a player
    void OnPVPKill(Player* /*killer*/, Player* player)
    {
        SummonGuardianAngel(player);
    }


    // if the player getting low hp NOTWORKING??%?%
    void OnPlayerTakeDamage(Player* player, uint32 /*damage*/, SpellSchoolMask /*schoolMask*/)
    {
        if (player->GetHealthPct() <= 30)
        {
            SummonGuardianAngel(player);
        }
    }

    //working but u need multiple mobs
    void OnCreatureKill(Player* player /*killer*/, Creature* /*killed*/)
    {
        if (player->GetHealthPct() <= 30)
        {
            SummonGuardianAngel(player);
        }
    }

};


struct GuardianAngel : public ScriptedAI
{
    GuardianAngel(Creature* creature) : ScriptedAI(creature) { }
    //开始-此处为出错,解决不了,后注释的
    //          此处的WorldObject原先为Unit*
    void IsSummonedBy(WorldObject* summoner)  override   //<--临时注释 "// override" 原本应为override
    {
        if (Player* player = summoner->ToPlayer())
        {
            // npc whisper player
            me->Whisper("Hold on! I'll help you!", LANG_UNIVERSAL, player);
            me->CastSpell(me, 321425); // electro jump

            if (!player->IsAlive())  // if player is dead angel will ress and heal
            {
                me->AddDelayedEvent(4000, [this, player]() -> void
                    {
                        player->ResurrectPlayer(0.3f);
                        me->CastSpell(player, 345201); // guardian angel - healing for 60% and does aoe dmg
                    });

                me->AddDelayedEvent(8000, [this, player]() -> void
                    {
                        player->CastSpell(player, 345323, true); // 100% crit for 30sec
                        me->CastSpell(player, 287419, true); // angelic reneval - healing full hp

                        // add generic phase if player is on exile reach
                        if (player->GetMapId() == 2175)
                            if (!player->GetPhaseShift().HasPhase(12940))
                                PhasingHandler::AddPhase(player, 12940,true);
                    });

                me->AddDelayedEvent(12000, [this, player]() -> void
                    {
                        me->CastSpell(player, 325326, true); // ascended eruption - healing+aoedmg
                    });
                me->AddDelayedEvent(13000, [this, player]() -> void
                    {
                        me->CastSpell(player, 325326, true); // ascended eruption - healing+aoedmg
                    });
                me->AddDelayedEvent(14000, [this, player]() -> void
                    {
                        me->CastSpell(player, 325326, true); // ascended eruption - healing+aoedmg
                    });
            }
            else  // if player is alive angel will heal
            {
                me->CastSpell(player, 345201); // guardian angel - healing for 60% and does aoe dmg

                me->AddDelayedEvent(3000, [this, player]() -> void
                    {
                        me->CastSpell(player, 345201, true); // guardian angel - healing for 60% and does aoe dmg
                    });
                me->AddDelayedEvent(6000, [this, player]() -> void
                    {
                        me->CastSpell(player, 345201, true); // guardian angel - healing for 60% and does aoe dmg
                    });
                me->AddDelayedEvent(9000, [this, player]() -> void
                    {
                        me->CastSpell(player, 345201, true); // guardian angel - healing for 60% and does aoe dmg
                    });

                me->AddDelayedEvent(10000, [this, player]() -> void
                    {
                   //   me->ForcedDespawn();
                    });
            }

        }
    }
    //结束-此处为出错,解决不了,后注释的
  
        /*
        void OwnerAttacked(Unit* target)
        {
            if (Player* player = me->GetOwner()->ToPlayer())
            {
                // if the player can't hold
                if (player->GetHealthPct() <= 30)
                {
                    me->CastSpell(me, 325326, true);
                    player->CastSpell(player, 287419, true);
                }

                me->CastSpell(player, 347223); // fanatical barrier

                // do some attacking lol
                events.ScheduleEvent(339450, 3s); // anima burst
                events.ScheduleEvent(158431, 5s); // blinding flash

            }
        }

        void ExecuteEvent(uint32 eventId)
        {
            switch (eventId)
            {
            case 339450:
                me->CastSpell(me->SelectNearestHostileUnitInAggroRange(), 339450);
                events.Repeat(3s, 4s);
                break;

            case 158431:
                me->CastSpell(me, 158431);
                events.Repeat(5s, 10s);
                break;
            }
        }
 */
    
//开始-此处为出错,解决不了,后注释的
    bool OnGossipHello(Player* player)  override
    {
        ClearGossipMenuFor(player);
        AddGossipItemFor(player, GossipOptionNpc::PetitionVendor,"Heal pls!", GOSSIP_SENDER_MAIN,0);
                               //此处的GossipOptionNpc::PetitionVendor原先为:GOSSIP_ICON_TALK
        AddGossipItemFor(player, GossipOptionNpc::PetitionVendor, "Did you bring some food?", GOSSIP_SENDER_MAIN, 1);
        AddGossipItemFor(player, GossipOptionNpc::PetitionVendor, "Can you repair my armor?", GOSSIP_SENDER_MAIN, 2);
        AddGossipItemFor(player, GossipOptionNpc::PetitionVendor, "Follow me!", GOSSIP_SENDER_MAIN, 3);
        SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, me->GetGUID());
        return true;
    }

    bool GossipSelect(Player* player, uint32 /*sender*/, uint32 action) //override
    {
        switch (action)
        {
        case 0:

            me->CastSpell(me, 325326, true); // just for the effect
            player->CastSpell(player, 287419, true); // angelic reneval - healing full hp

            CloseGossipMenuFor(player);
            break;
        case 1:
            player->CastSpell(player, 304971, true);
            player->AddItem(80610, 5);

            CloseGossipMenuFor(player);
            break;
        case 2:
            me->CastSpell(me, 324427);
            player->DurabilityRepairAll(false, 0, false);
            CloseGossipMenuFor(player);
            break;
        case 3:

            me->CastSpell(player, 342317);
            me->GetMotionMaster()->MoveFollow(player, PET_FOLLOW_DIST, player->GetFollowAngle());
            me->SetOwnerGUID(player->GetGUID());
            CloseGossipMenuFor(player);
            break;
        }
        return true;
    }
    //出错-此处为出错,解决不了,后注释的


};

void AddSC_GuardianAngel()  //此处为检查脚本需要在加载器中加载的地方
{
    new GuardianAngel_Spawn;
    RegisterCreatureAI(GuardianAngel);
}
