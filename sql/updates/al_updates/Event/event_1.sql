DELETE FROM `game_event` WHERE `eventEntry` IN (74, 75);
INSERT INTO `game_event` (`eventEntry`, `start_time`, `end_time`, `occurence`, `length`, `holiday`, `description`, `world_event`) VALUES
(74, '2011-09-28 19:00:00', '2011-09-28 19:45:00', 1440, 1400, 0, 'Тухлопузы Атакуют! Или Во Имя Короля Лича. - Орда', 0),
(75, '2011-09-28 19:00:00', '2011-09-28 19:45:00', 1440, 1400, 0, 'Гниломорды Атакуют! Или Во Имя Короля Лича. - Альянс', 0);

DELETE FROM `game_event_creature` WHERE `eventEntry` IN (74, 75);
REPLACE INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(74, 497300),
(74, 497301),
(75, 497302),
(75, 497303);

DELETE FROM `creature_template` WHERE `entry` IN (600600, 600601, 600602, 600603);
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES
(600600, 0, 0, 0, 0, 0, 31006, 31006, 31006, 0, 'Тухлопуз', '', '', 0, 83, 83, 2, 7, 7, 0, 1, 1.14286, 1, 3, 468, 702, 0, 175, 59.3, 2000, 2000, 1, 0, 8, 0, 0, 0, 0, 0, 374, 562, 140, 6, 108, 600600, 0, 0, 0, 0, 0, 0, 0, 0, 70138, 69165, 69195, 69279, 0, 0, 0, 0, 0, 0, 1053076, 1053076, 'EventAI', 0, 3, 625, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 651116543, 0, '', 1),
(600601, 0, 0, 0, 0, 0, 16568, 16568, 16568, 16568, 'Хранитель Тайн Орды', '', '', 0, 80, 80, 1, 1775, 1775, 2, 1, 1.14286, 1, 1, 231, 346, 0, 87, 3.7, 1500, 1500, 1, 1, 8, 0, 0, 0, 0, 0, 185, 277, 70, 10, 0, 0, 0, 0, 500, 500, 500, 500, 500, 500, 35076, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'EventAI', 1, 3, 1000, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 2, '', 1),
(600602, 0, 0, 0, 0, 0, 31005, 31005, 31005, 0, 'Гниломорд', '', '', 0, 83, 83, 2, 7, 7, 0, 1, 1.14286, 1, 3, 468, 702, 0, 175, 53.1, 2000, 2000, 1, 0, 8, 0, 0, 0, 0, 0, 374, 562, 140, 6, 108, 600602, 0, 0, 0, 0, 0, 0, 0, 0, 69789, 69508, 69674, 0, 0, 0, 0, 0, 0, 0, 1196250, 1196250, 'EventAI', 0, 3, 625, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 652165119, 0, '', 1),
(600603, 0, 0, 0, 0, 0, 16568, 16568, 16568, 16568, 'Хранитель Тайн Альянса', '', '', 0, 80, 80, 1, 1775, 1775, 2, 1, 1.14286, 1, 1, 231, 346, 0, 87, 3.7, 1500, 1500, 1, 1, 8, 0, 0, 0, 0, 0, 185, 277, 70, 10, 0, 0, 0, 0, 500, 500, 500, 500, 500, 500, 35076, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'EventAI', 1, 3, 1000, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 2, '', 1);

DELETE FROM `creature` WHERE `id` IN (600600, 600601, 600602, 600603);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(497300, 600600, 1, 1, 1, 0, 0, 1361.23, -4371.69, 26.1048, 0.131836, 86400, 0, 200003, 9412875, 0, 2, 0, 0, 0),
(497301, 600601, 1, 1, 1, 0, 0, 1283.38, -4375.03, 28.2248, 5.97452, 300, 0, 0, 9215000, 0, 0, 0, 0, 0),
(497302, 600602, 0, 1, 1, 0, 0, -9096.17, 409.337, 92.349, 0.672668, 86400, 0, 200004, 9412875, 0, 2, 0, 0, 0),
(497303, 600603, 0, 1, 1, 0, 0, -9166.86, 367.438, 88.2867, 6.27256, 300, 0, 0, 9215000, 0, 0, 0, 0, 0);

DELETE FROM `creature_addon` WHERE `guid` in (497300, 497301, 497302,497303);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(497300, 200003, 0, 0, 0, 0, 43905),
(497302, 200004, 0, 0, 0, 0, 43905);

DELETE FROM `creature_loot_template` WHERE (`entry`=600600);
INSERT INTO `creature_loot_template` VALUES 
(600600, 43954, 15, 1, 0, 1, 1),
(600600, 49284, 15, 1, 0, 1, 1);

DELETE FROM `creature_loot_template` WHERE (`entry`=600602);
INSERT INTO `creature_loot_template` VALUES 
(600602, 43954, 15, 1, 0, 1, 1),
(600602, 49284, 15, 1, 0, 1, 1);

UPDATE `creature_template` SET `equipment_id`=2478 WHERE `entry` IN (600600, 600602);

DELETE FROM `waypoint_data` WHERE `id` = 200003;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `delay`, `move_flag`, `action`, `action_chance`, `wpguid`) VALUES
(200003, 1, 1362.4, -4371.97, 26.0964, 0, 0, 0, 100, 0),
(200003, 2, 1333.34, -4376.58, 26.2038, 0, 0, 0, 100, 0),
(200003, 3, 1314.87, -4386.8, 26.243, 0, 0, 0, 100, 0),
(200003, 4, 1302.79, -4391.84, 26.2661, 0, 0, 0, 100, 0),
(200003, 5, 1298.78, -4384.45, 26.2652, 0, 0, 0, 100, 0),
(200003, 6, 1346.38, -4375.33, 26.1684, 0, 0, 0, 100, 0),
(200003, 7, 1397.62, -4367.45, 25.463, 0, 0, 0, 100, 0),
(200003, 8, 1427.92, -4362.56, 25.4626, 0, 0, 0, 100, 0),
(200003, 9, 1432.94, -4387.72, 25.4626, 0, 0, 0, 100, 0),
(200003, 10, 1436.2, -4420.79, 25.4626, 0, 0, 0, 100, 0),
(200003, 11, 1437.17, -4422.78, 25.4626, 0, 0, 0, 100, 0),
(200003, 12, 1456.06, -4420.69, 25.4626, 0, 0, 0, 100, 0),
(200003, 13, 1479.92, -4417.59, 25.4625, 0, 0, 0, 100, 0),
(200003, 14, 1494.54, -4415.36, 23.1295, 0, 0, 0, 100, 0),
(200003, 15, 1509.05, -4413.92, 19.6759, 0, 0, 0, 100, 0),
(200003, 16, 1525.31, -4412.31, 14.2132, 0, 0, 0, 100, 0),
(200003, 17, 1547.77, -4421.82, 10.0675, 0, 0, 0, 100, 0),
(200003, 18, 1563.09, -4429.53, 7.52508, 0, 0, 0, 100, 0),
(200003, 19, 1588.11, -4438.52, 6.09392, 0, 0, 0, 100, 0),
(200003, 20, 1611, -4431.95, 9.53724, 0, 0, 0, 100, 0),
(200003, 21, 1628.89, -4420.48, 15.8086, 0, 0, 0, 100, 0),
(200003, 22, 1652.11, -4413.02, 16.9157, 0, 0, 0, 100, 0),
(200003, 23, 1663.42, -4412.82, 17.3201, 0, 0, 0, 100, 0),
(200003, 24, 1663.42, -4412.82, 17.3201, 0, 0, 0, 100, 0),
(200003, 25, 1676.47, -4395.09, 20.4213, 0, 0, 0, 100, 0),
(200003, 26, 1666.5, -4381.12, 23.8903, 0, 0, 0, 100, 0),
(200003, 27, 1657.6, -4370.93, 23.954, 0, 0, 0, 100, 0),
(200003, 28, 1655.89, -4359.36, 24.6769, 0, 0, 0, 100, 0),
(200003, 29, 1645.46, -4363.11, 24.297, 0, 0, 0, 100, 0),
(200003, 30, 1634.8, -4369.81, 28.6722, 0, 0, 0, 100, 0),
(200003, 31, 1629.87, -4372.76, 31.3716, 0, 0, 0, 100, 0),
(200003, 32, 1612.74, -4381.58, 24.2817, 0, 0, 0, 100, 0),
(200003, 33, 1621.81, -4386.21, 26.591, 0, 0, 0, 100, 0),
(200003, 34, 1631.82, -4391.48, 24.7735, 0, 0, 0, 100, 0),
(200003, 35, 1640.69, -4387.93, 24.7797, 0, 0, 0, 100, 0),
(200003, 36, 1651.16, -4390.95, 21.8571, 0, 0, 0, 100, 0),
(200003, 37, 1644.62, -4406.14, 17.4134, 0, 0, 0, 100, 0),
(200003, 38, 1631.09, -4418.35, 16.4429, 0, 0, 0, 100, 0),
(200003, 39, 1622.18, -4430.24, 12.2226, 0, 0, 0, 100, 0),
(200003, 40, 1611.69, -4435.07, 8.69846, 0, 0, 0, 100, 0),
(200003, 41, 1593.14, -4439.12, 6.13377, 0, 0, 0, 100, 0),
(200003, 42, 1577.9, -4434.86, 6.0876, 0, 0, 0, 100, 0),
(200003, 43, 1558.32, -4427, 8.24409, 0, 0, 0, 100, 0),
(200003, 44, 1549.66, -4423.53, 9.84635, 0, 0, 0, 100, 0),
(200003, 45, 1533.31, -4416.97, 12.3029, 0, 0, 0, 100, 0),
(200003, 46, 1520.86, -4411.97, 15.7599, 0, 0, 0, 100, 0),
(200003, 47, 1504.01, -4414.4, 21.1862, 0, 0, 0, 100, 0),
(200003, 48, 1490.67, -4415.58, 23.5942, 0, 0, 0, 100, 0),
(200003, 49, 1484.03, -4415.75, 24.7482, 0, 0, 0, 100, 0),
(200003, 50, 1467.83, -4419.78, 25.4625, 0, 0, 0, 100, 0),
(200003, 51, 1452.94, -4421.92, 25.4625, 0, 0, 0, 100, 0),
(200003, 52, 1440.7, -4423.68, 25.4625, 0, 0, 0, 100, 0),
(200003, 53, 1438.85, -4423.95, 25.4625, 0, 0, 0, 100, 0),
(200003, 54, 1435.06, -4417.03, 25.4625, 0, 0, 0, 100, 0),
(200003, 55, 1433.7, -4404.68, 25.4625, 0, 0, 0, 100, 0),
(200003, 56, 1433.52, -4393.29, 25.4625, 0, 0, 0, 100, 0),
(200003, 57, 1430.73, -4366.73, 25.4625, 0, 0, 0, 100, 0),
(200003, 58, 1411.72, -4366.01, 25.4625, 0, 0, 0, 100, 0),
(200003, 59, 1386.06, -4367.83, 27.242, 0, 0, 0, 100, 0),
(200003, 60, 1377.13, -4369.3, 26.0262, 0, 0, 0, 100, 0),
(200003, 61, 1362.71, -4372.14, 26.0915, 0, 0, 0, 100, 0);

DELETE FROM `waypoint_data` WHERE `id` = 200004;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `delay`, `move_flag`, `action`, `action_chance`, `wpguid`) VALUES
(200004, 1, -9097.01, 409.367, 92.3939, 0, 0, 0, 100, 0),
(200004, 2, -9120.84, 392.057, 91.9093, 0, 0, 0, 100, 0),
(200004, 3, -9134.42, 382.194, 90.6079, 0, 0, 0, 100, 0),
(200004, 4, -9153.86, 364.875, 90.248, 0, 0, 0, 100, 0),
(200004, 5, -9155.3, 348.808, 88.3643, 0, 0, 0, 100, 0),
(200004, 6, -9146.97, 343.927, 90.2065, 0, 0, 0, 100, 0),
(200004, 7, -9127.11, 365.647, 92.5244, 0, 0, 0, 100, 0),
(200004, 8, -9118.98, 389.927, 91.9101, 0, 0, 0, 100, 0),
(200004, 9, -9105.45, 406.254, 92.645, 0, 0, 0, 100, 0),
(200004, 10, -9096.64, 410.19, 92.3365, 0, 0, 0, 100, 0),
(200004, 11, -9078.55, 426.207, 92.9823, 0, 0, 0, 100, 0),
(200004, 12, -9059.85, 438.073, 93.0566, 0, 0, 0, 100, 0),
(200004, 13, -9031.27, 460.064, 93.2307, 0, 0, 0, 100, 0),
(200004, 14, -9013.86, 473.877, 96.2061, 0, 0, 0, 100, 0),
(200004, 15, -8955.32, 520.31, 96.3555, 0, 0, 0, 100, 0),
(200004, 16, -8928.13, 495.325, 93.8439, 0, 0, 0, 100, 0),
(200004, 17, -8909.33, 504.716, 93.8489, 0, 0, 0, 100, 0),
(200004, 18, -8908.77, 514.073, 93.8403, 0, 0, 0, 100, 0),
(200004, 19, -8911.26, 517.921, 93.8552, 0, 0, 0, 100, 0),
(200004, 20, -8926.65, 539.43, 94.3071, 0, 0, 0, 100, 0),
(200004, 21, -8945.39, 560.883, 93.8228, 0, 0, 0, 100, 0),
(200004, 22, -8964.35, 566.625, 93.8417, 0, 0, 0, 100, 0),
(200004, 23, -8977.49, 553.676, 93.8454, 0, 0, 0, 100, 0),
(200004, 24, -8954.52, 521.583, 96.3564, 0, 0, 0, 100, 0),
(200004, 25, -8959.26, 516.456, 96.3564, 0, 0, 0, 100, 0),
(200004, 26, -9011.42, 475.548, 96.4658, 0, 0, 0, 100, 0),
(200004, 27, -9032.06, 459.048, 93.0561, 0, 0, 0, 100, 0),
(200004, 28, -9056.37, 440.432, 93.0561, 0, 0, 0, 100, 0),
(200004, 29, -9074.97, 425.408, 93.0561, 0, 0, 0, 100, 0),
(200004, 30, -9097.6, 408.591, 92.4451, 0, 0, 0, 100, 0);


DELETE FROM `creature_questrelation` WHERE `quest` = 600600;
DELETE FROM `gameobject_questrelation` WHERE `quest` = 600600;
UPDATE `item_template` SET `StartQuest`=0 WHERE `StartQuest` = 600600;
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES (600601, 600600);
UPDATE `creature_template` SET `npcflag`=`npcflag`|2 WHERE `entry` = 600601;
DELETE FROM `creature_involvedrelation` WHERE `quest` = 600600;
DELETE FROM `gameobject_involvedrelation` WHERE `quest` = 600600;
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES (4949, 600600);
UPDATE `creature_template` SET `npcflag`=`npcflag`|2 WHERE `entry`=4949;
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES (600601, 600600);
UPDATE `creature_template` SET `npcflag`=`npcflag`|2 WHERE `entry`=600601;
DELETE FROM `quest_template` WHERE `entry` = 600600;

DELETE FROM `creature_questrelation` WHERE `quest` = 600601;
DELETE FROM `gameobject_questrelation` WHERE `quest` = 600601;
UPDATE `item_template` SET `StartQuest`=0 WHERE `StartQuest` = 600601;
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES (600603, 600601);
UPDATE `creature_template` SET `npcflag`=`npcflag`|2 WHERE `entry` = 600603;
DELETE FROM `creature_involvedrelation` WHERE `quest` = 600601;
DELETE FROM `gameobject_involvedrelation` WHERE `quest` = 600601;
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES (29611, 600601);
UPDATE `creature_template` SET `npcflag`=`npcflag`|2 WHERE `entry`=29611;
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES (600603, 600601);
UPDATE `creature_template` SET `npcflag`=`npcflag`|2 WHERE `entry`=600603;
DELETE FROM `quest_template` WHERE `entry` = 600601;
INSERT INTO `quest_template` (`entry`, `Method`, `ZoneOrSort`, `SkillOrClassMask`, `MinLevel`, `MaxLevel`, `QuestLevel`, `Type`, `RequiredRaces`, `RequiredSkillValue`, `RepObjectiveFaction`, `RepObjectiveValue`, `RepObjectiveFaction2`, `RepObjectiveValue2`, `RequiredMinRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepFaction`, `RequiredMaxRepValue`, `SuggestedPlayers`, `LimitTime`, `QuestFlags`, `SpecialFlags`, `CharTitleId`, `PlayersSlain`, `BonusTalents`, `RewardArenaPoints`, `PrevQuestId`, `NextQuestId`, `ExclusiveGroup`, `NextQuestInChain`, `RewXPId`, `SrcItemId`, `SrcItemCount`, `SrcSpell`, `Title`, `Details`, `Objectives`, `OfferRewardText`, `RequestItemsText`, `EndText`, `CompletedText`, `ObjectiveText1`, `ObjectiveText2`, `ObjectiveText3`, `ObjectiveText4`, `ReqItemId1`, `ReqItemId2`, `ReqItemId3`, `ReqItemId4`, `ReqItemId5`, `ReqItemId6`, `ReqItemCount1`, `ReqItemCount2`, `ReqItemCount3`, `ReqItemCount4`, `ReqItemCount5`, `ReqItemCount6`, `ReqSourceId1`, `ReqSourceId2`, `ReqSourceId3`, `ReqSourceId4`, `ReqSourceCount1`, `ReqSourceCount2`, `ReqSourceCount3`, `ReqSourceCount4`, `ReqCreatureOrGOId1`, `ReqCreatureOrGOId2`, `ReqCreatureOrGOId3`, `ReqCreatureOrGOId4`, `ReqCreatureOrGOCount1`, `ReqCreatureOrGOCount2`, `ReqCreatureOrGOCount3`, `ReqCreatureOrGOCount4`, `ReqSpellCast1`, `ReqSpellCast2`, `ReqSpellCast3`, `ReqSpellCast4`, `RewChoiceItemId1`, `RewChoiceItemId2`, `RewChoiceItemId3`, `RewChoiceItemId4`, `RewChoiceItemId5`, `RewChoiceItemId6`, `RewChoiceItemCount1`, `RewChoiceItemCount2`, `RewChoiceItemCount3`, `RewChoiceItemCount4`, `RewChoiceItemCount5`, `RewChoiceItemCount6`, `RewItemId1`, `RewItemId2`, `RewItemId3`, `RewItemId4`, `RewItemCount1`, `RewItemCount2`, `RewItemCount3`, `RewItemCount4`, `RewRepFaction1`, `RewRepFaction2`, `RewRepFaction3`, `RewRepFaction4`, `RewRepFaction5`, `RewRepValueId1`, `RewRepValueId2`, `RewRepValueId3`, `RewRepValueId4`, `RewRepValueId5`, `RewRepValue1`, `RewRepValue2`, `RewRepValue3`, `RewRepValue4`, `RewRepValue5`, `RewHonorAddition`, `RewHonorMultiplier`, `unk0`, `RewOrReqMoney`, `RewMoneyMaxLevel`, `RewSpell`, `RewSpellCast`, `RewMailTemplateId`, `RewMailDelaySecs`, `PointMapId`, `PointX`, `PointY`, `PointOpt`, `DetailsEmote1`, `DetailsEmote2`, `DetailsEmote3`, `DetailsEmote4`, `DetailsEmoteDelay1`, `DetailsEmoteDelay2`, `DetailsEmoteDelay3`, `DetailsEmoteDelay4`, `IncompleteEmote`, `CompleteEmote`, `OfferRewardEmote1`, `OfferRewardEmote2`, `OfferRewardEmote3`, `OfferRewardEmote4`, `OfferRewardEmoteDelay1`, `OfferRewardEmoteDelay2`, `OfferRewardEmoteDelay3`, `OfferRewardEmoteDelay4`, `StartScript`, `CompleteScript`, `WDBVerified`) VALUES
(600600, 2, 0, 0, 80, 0, 80, 62, 690, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4160, 1, 0, 0, 0, 25, 0, 0, 0, 0, 0, 0, 0, 0, 'Во имя Короля-Лича!', 'Профессор Мерзацид проводит свои новые ужасные эксперименты над всем живым, и в качестве новой цели он выбирает предводителя Орды Тралла. Он отправил своего создания Тухлопуза захватить Тралла и привести его к себе в лабораторию в Цитадель Ледяной Короны.', 'Найти и уничтожить Тухлопуза в столице Орды Оргриммар.', 'Вы выполнили задание, и защитили своего предводителя от гибели. Возьмите это в знак его вечной благодарности вам.', '', 'Защитить своего короля любой ценой!', NULL, 'Убить нападающего на Тралла Тухлопуза в Оргриммаре.', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 600600, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 49426, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 24966, 24966, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(600601, 2, 0, 0, 80, 0, 80, 62, 1101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4160, 1, 0, 0, 0, 25, 0, 0, 0, 0, 0, 0, 0, 0, 'Во имя Короля-Лича!', 'Профессор Мерзацид проводит свои новые ужасные эксперименты над всем живым, и в качестве новой цели он выбирает предводителя Альянса Короля Вариана Ринна. Он отправил своего создания Гниломорда захватить Короля Штормграда и привести его к себе в лабораторию в Цитадель Ледяной Короны.', 'Найти и уничтожить Гниломорда в столице Альянса Штормград.', 'Вы выполнили задание, и защитили своего предводителя от гибели. Возьмите это в знак его вечной благодарности вам.', '', 'Защитить своего Короля любой ценой!', NULL, 'Убить нападающего на Короля Вариана Ринна Гниломорда в Штормграде.', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 600602, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 49426, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 24966, 24966, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1);


DELETE FROM `creature_ai_scripts` WHERE `creature_id` = 600600;
DELETE FROM `creature_ai_scripts` WHERE `creature_id` = 600602;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` = '600600';
DELETE FROM `smart_scripts` WHERE `source_type`= '0' AND `entryorguid`= '600600';
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(600600, 0, 0, 0, 1, 0, 100, 0, 5000, 45000, 20000, 45000, 1, 1, 0, 0, 0, 0, 0, 18, 20, 0, 0, 0, 0, 0, 0, 'YTDB:'),
(600600, 0, 1, 0, 2, 0, 100, 0, 80, 80, 10000, 11000, 12, 31194, 2, 5, 0, 1, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'YTDB:'),
(600600, 0, 2, 0, 0, 0, 100, 0, 10000, 11000, 11000, 12000, 11, 71547, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'YTDB:'),
(600600, 0, 3, 2, 61, 0, 100, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'YTDB:'),
(600600, 0, 4, 0, 0, 0, 100, 0, 15000, 16000, 10000, 11000, 11, 50497, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'YTDB:'),
(600600, 0, 5, 4, 0, 0, 100, 0, 16000, 17000, 10000, 11000, 11, 36778, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'YTDB:'),
(600600, 0, 6, 4, 0, 0, 100, 0, 16000, 17000, 10000, 11000, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'YTDB:'),
(600600, 0, 7, 0, 0, 0, 100, 0, 600000, 601000, 1740000, 1741000, 11, 47008, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'YTDB:'),
(600600, 0, 8, 7, 0, 0, 100, 0, 600000, 601000, 1740000, 1741000, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'YTDB:'),
(600600, 0, 9, 0, 1, 0, 100, 0, 10000, 15000, 20000, 25000, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'YTDB:)'),
(600600, 0, 10, 9, 1, 0, 100, 0, 10000, 15000, 20000, 25000, 11, 67468, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'YTDB:');

DELETE FROM `creature_text` WHERE `entry`= '600600';
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(600600, 1, 0, 'Мой хозяин Мерзоцид приказал мне доставить к нему вашего Короля, чем я сейчас и займусь... \r\nНикто не сможет меня остановить, ведь я не знаю что такое страх!', 12, 0, 100, 0, 1, 0, 'Comment'),
(600600, 1, 1, 'Я убью ВСЕХ кто попытается меня остановить!!!', 12, 0, 100, 0, 1, 0, 'Comment'),
(600600, 2, 0, 'Я слышу волю моего хозяина...', 12, 0, 100, 0, 1, 0, 'Comment'),
(600600, 2, 1, 'Да прийдет за вами смерть...', 12, 0, 100, 0, 1, 0, 'Comment'),
(600600, 2, 2, 'Я вижу... Смерть! Она пришла за вами...', 12, 0, 100, 0, 1, 0, 'Comment'),
(600600, 3, 0, 'Вы никуда от меня не убежите... Ваши души станут моими навсегда!', 12, 0, 100, 0, 1, 0, 'Comment'),
(600600, 4, 0, 'Мне надоело с вами возиться... У меня есть более важные дела! Да придет за вами смерть!', 12, 0, 100, 0, 1, 0, 'Comment'),
(600600, 5, 1, 'Что-то мне поплохело после вчерашнего застолья...', 12, 0, 100, 0, 1, 0, 'Comment'),
(600600, 5, 2, 'Что-то скрипнуло в грудях не помру ли я на днях...', 12, 0, 100, 0, 1, 0, 'Comment'),
(600600, 5, 3, 'Ну и что я тут забыл, и так штормит после вчерашнего застолья...', 12, 0, 100, 0, 1, 0, 'Comment');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` = '600602';
DELETE FROM `smart_scripts` WHERE `source_type`= '0' AND `entryorguid`= '600602';
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(600602, 0, 0, 0, 1, 0, 100, 0, 5000, 45000, 20000, 45000, 1, 1, 0, 0, 0, 0, 0, 18, 20, 0, 0, 0, 0, 0, 0, 'YTDB:'),
(600602, 0, 1, 0, 2, 0, 100, 0, 80, 80, 10000, 11000, 12, 31194, 2, 5, 0, 1, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'YTDB:'),
(600602, 0, 2, 0, 0, 0, 100, 0, 10000, 11000, 11000, 12000, 11, 71547, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'YTDB:'),
(600602, 0, 3, 2, 61, 0, 100, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'YTDB:'),
(600602, 0, 4, 0, 0, 0, 100, 0, 15000, 16000, 10000, 11000, 11, 50497, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'YTDB:'),
(600602, 0, 5, 4, 0, 0, 100, 0, 16000, 17000, 10000, 11000, 11, 36778, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'YTDB:'),
(600602, 0, 6, 4, 0, 0, 100, 0, 16000, 17000, 10000, 11000, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'YTDB:'),
(600602, 0, 7, 0, 0, 0, 100, 0, 600000, 601000, 1740000, 1741000, 11, 47008, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'YTDB:'),
(600602, 0, 8, 7, 0, 0, 100, 0, 600000, 601000, 1740000, 1741000, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'YTDB:'),
(600602, 0, 9, 0, 1, 0, 100, 0, 10000, 15000, 20000, 25000, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'YTDB:)'),
(600602, 0, 10, 9, 1, 0, 100, 0, 10000, 15000, 20000, 25000, 11, 67468, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'YTDB:');

DELETE FROM `creature_text` WHERE `entry`= '600602';
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(600602, 1, 0, 'Мой хозяин Мерзоцид приказал мне доставить к нему вашего Короля, чем я сейчас и займусь... \r\nНикто не сможет меня остановить, ведь я не знаю что такое страх!', 12, 0, 100, 0, 1, 0, 'Comment'),
(600602, 1, 1, 'Я убью ВСЕХ кто попытается меня остановить!!!', 12, 0, 100, 0, 1, 0, 'Comment'),
(600602, 2, 0, 'Я слышу волю моего хозяина...', 12, 0, 100, 0, 1, 0, 'Comment'),
(600602, 2, 1, 'Да прийдет за вами смерть...', 12, 0, 100, 0, 1, 0, 'Comment'),
(600602, 2, 2, 'Я вижу... Смерть! Она пришла за вами...', 12, 0, 100, 0, 1, 0, 'Comment'),
(600602, 3, 0, 'Вы никуда от меня не убежите... Ваши души станут моими навсегда!', 12, 0, 100, 0, 1, 0, 'Comment'),
(600602, 4, 0, 'Мне надоело с вами возиться... У меня есть более важные дела! Да придет за вами смерть!', 12, 0, 100, 0, 1, 0, 'Comment'),
(600602, 5, 1, 'Что-то мне поплохело после вчерашнего застолья...', 12, 0, 100, 0, 1, 0, 'Comment'),
(600602, 5, 2, 'Что-то скрипнуло в грудях не помру ли я на днях...', 12, 0, 100, 0, 1, 0, 'Comment'),
(600602, 5, 3, 'Ну и что я тут забыл, и так штормит после вчерашнего застолья...', 12, 0, 100, 0, 1, 0, 'Comment');
