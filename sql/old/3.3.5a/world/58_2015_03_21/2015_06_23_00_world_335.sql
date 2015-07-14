-- areatrigger_teleport
ALTER TABLE `areatrigger_teleport`
CHANGE `id` `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
CHANGE `name` `Name` TEXT CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL;

-- battleground_template
ALTER TABLE `battleground_template`
CHANGE `id` `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0';

-- creature_equip_template
ALTER TABLE `creature_equip_template`
CHANGE `entry` `CreatureID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
CHANGE `id` `ID` TINYINT(3) UNSIGNED NOT NULL DEFAULT '1',
CHANGE `itemEntry1` `ItemID1` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
CHANGE `itemEntry2` `ItemID2` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
CHANGE `itemEntry3` `ItemID3` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0';

-- creature_formations
ALTER TABLE `creature_formations`
CHANGE `leaderGUID` `leaderGUID` INT(10) UNSIGNED NOT NULL DEFAULT '0',
CHANGE `memberGUID` `memberGUID` INT(10) UNSIGNED NOT NULL DEFAULT '0';

-- creature_model_info
ALTER TABLE `creature_model_info`
CHANGE `modelid` `DisplayID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
CHANGE `bounding_radius` `BoundingRadius` FLOAT NOT NULL DEFAULT '0',
CHANGE `combat_reach` `CombatReach` FLOAT NOT NULL DEFAULT '0',
CHANGE `gender` `Gender` TINYINT(3) UNSIGNED NOT NULL DEFAULT '2',
CHANGE `modelid_other_gender` `DisplayID_Other_Gender` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0';

-- gameobject_template
ALTER TABLE `gameobject_template`
CHANGE `data0`  `Data0`  INT(10) UNSIGNED NOT NULL DEFAULT '0',
CHANGE `data1`  `Data1`  INT(11) NOT NULL DEFAULT '0',
CHANGE `data2`  `Data2`  INT(10) UNSIGNED NOT NULL DEFAULT '0',
CHANGE `data3`  `Data3`  INT(10) UNSIGNED NOT NULL DEFAULT '0',
CHANGE `data4`  `Data4`  INT(10) UNSIGNED NOT NULL DEFAULT '0',
CHANGE `data5`  `Data5`  INT(10) UNSIGNED NOT NULL DEFAULT '0',
CHANGE `data6`  `Data6`  INT(11) NOT NULL DEFAULT '0',
CHANGE `data7`  `Data7`  INT(10) UNSIGNED NOT NULL DEFAULT '0',
CHANGE `data8`  `Data8`  INT(10) UNSIGNED NOT NULL DEFAULT '0',
CHANGE `data9`  `Data9`  INT(10) UNSIGNED NOT NULL DEFAULT '0',
CHANGE `data10` `Data10` INT(10) UNSIGNED NOT NULL DEFAULT '0',
CHANGE `data11` `Data11` INT(10) UNSIGNED NOT NULL DEFAULT '0',
CHANGE `data12` `Data12` INT(10) UNSIGNED NOT NULL DEFAULT '0',
CHANGE `data13` `Data13` INT(10) UNSIGNED NOT NULL DEFAULT '0',
CHANGE `data14` `Data14` INT(10) UNSIGNED NOT NULL DEFAULT '0',
CHANGE `data15` `Data15` INT(10) UNSIGNED NOT NULL DEFAULT '0',
CHANGE `data16` `Data16` INT(10) UNSIGNED NOT NULL DEFAULT '0',
CHANGE `data17` `Data17` INT(10) UNSIGNED NOT NULL DEFAULT '0',
CHANGE `data18` `Data18` INT(10) UNSIGNED NOT NULL DEFAULT '0',
CHANGE `data19` `Data19` INT(10) UNSIGNED NOT NULL DEFAULT '0',
CHANGE `data20` `Data20` INT(10) UNSIGNED NOT NULL DEFAULT '0',
CHANGE `data21` `Data21` INT(10) UNSIGNED NOT NULL DEFAULT '0',
CHANGE `data22` `Data22` INT(10) UNSIGNED NOT NULL DEFAULT '0',
CHANGE `data23` `Data23` INT(10) UNSIGNED NOT NULL DEFAULT '0';

-- lfg_entrances -> lfg_dungeon_template
RENAME TABLE `lfg_entrances` TO `lfg_dungeon_template`;

-- npc_text
ALTER TABLE `npc_text`
CHANGE `prob0` `Probability0` FLOAT NOT NULL DEFAULT '0',
CHANGE `prob1` `Probability1` FLOAT NOT NULL DEFAULT '0',
CHANGE `prob2` `Probability2` FLOAT NOT NULL DEFAULT '0',
CHANGE `prob3` `Probability3` FLOAT NOT NULL DEFAULT '0',
CHANGE `prob4` `Probability4` FLOAT NOT NULL DEFAULT '0',
CHANGE `prob5` `Probability5` FLOAT NOT NULL DEFAULT '0',
CHANGE `prob6` `Probability6` FLOAT NOT NULL DEFAULT '0',
CHANGE `prob7` `Probability7` FLOAT NOT NULL DEFAULT '0';

-- npc_trainer
ALTER TABLE `npc_trainer`
CHANGE `entry` `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
CHANGE `spell` `SpellID` MEDIUMINT(8) NOT NULL DEFAULT '0',
CHANGE `spellcost` `MoneyCost` INT(10) UNSIGNED NOT NULL DEFAULT '0',
CHANGE `reqskill` `ReqSkillLine` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0',
CHANGE `reqskillvalue` `ReqSkillRank` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0',
CHANGE `reqlevel` `ReqLevel` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0';

-- page_text
ALTER TABLE `page_text`
CHANGE `entry` `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
CHANGE `text` `Text` LONGTEXT CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
CHANGE `next_page` `NextPageID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
CHANGE `VerifiedBuild` `VerifiedBuild` SMALLINT(5) NULL DEFAULT '0';

-- player_xp_for_level
ALTER TABLE `player_xp_for_level`
CHANGE `lvl` `Level` TINYINT(3) UNSIGNED NOT NULL,
CHANGE `xp_for_next_level` `Experience` INT(10) UNSIGNED NOT NULL;

-- points_of_interest
ALTER TABLE `points_of_interest`
CHANGE `entry` `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
CHANGE `x` `PositionX` FLOAT NOT NULL DEFAULT '0',
CHANGE `y` `PositionY` FLOAT NOT NULL DEFAULT '0',
CHANGE `icon` `Icon` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
CHANGE `flags` `Flags` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
CHANGE `data` `Data` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
CHANGE `icon_name` `Name` TEXT CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL;

-- quest_poi
ALTER TABLE `quest_poi`
CHANGE `questId` `QuestID` INT(10) UNSIGNED NOT NULL DEFAULT '0',
CHANGE `objIndex` `ObjectiveIndex` INT(11) NOT NULL DEFAULT '0',
CHANGE `mapid` `MapID` INT(10) UNSIGNED NOT NULL DEFAULT '0',
CHANGE `FloorId` `Floor` INT(10) UNSIGNED NOT NULL DEFAULT '0',
CHANGE `unk3` `Priority` INT(10) UNSIGNED NOT NULL DEFAULT '0',
CHANGE `unk4` `Flags` INT(10) UNSIGNED NOT NULL DEFAULT '0';

-- quest_poi_points
ALTER TABLE `quest_poi_points`
CHANGE `questId` `QuestID` INT(10) UNSIGNED NOT NULL DEFAULT '0',
CHANGE `id` `Idx1` INT(10) UNSIGNED NOT NULL DEFAULT '0',
CHANGE `idx` `Idx2` INT(10) UNSIGNED NOT NULL DEFAULT '0',
CHANGE `x` `X` INT(11) NOT NULL DEFAULT '0',
CHANGE `y` `Y` INT(11) NOT NULL DEFAULT '0';

-- quest_template
ALTER TABLE `quest_template`
CHANGE `Id` `ID` mediumint(8) unsigned NOT NULL DEFAULT '0',
CHANGE `Level` `QuestLevel` smallint(3) NOT NULL DEFAULT '1',
CHANGE `ZoneOrSort` `QuestSortID` smallint(6) NOT NULL DEFAULT '0',
CHANGE `Type` `QuestType` smallint(5) unsigned NOT NULL DEFAULT '0',
CHANGE `SuggestedPlayers` `SuggestedGroupNum` tinyint(3) unsigned NOT NULL DEFAULT '0',
CHANGE `RewardTitleId` `RewardTitle` tinyint(3) unsigned NOT NULL DEFAULT '0',
CHANGE `RewardItemId1` `RewardItem1` mediumint(8) unsigned NOT NULL DEFAULT '0',
CHANGE `RewardItemId2` `RewardItem2` mediumint(8) unsigned NOT NULL DEFAULT '0',
CHANGE `RewardItemId3` `RewardItem3` mediumint(8) unsigned NOT NULL DEFAULT '0',
CHANGE `RewardItemId4` `RewardItem4` mediumint(8) unsigned NOT NULL DEFAULT '0',
CHANGE `RewardItemCount1` `RewardAmount1` smallint(5) unsigned NOT NULL DEFAULT '0',
CHANGE `RewardItemCount2` `RewardAmount2` smallint(5) unsigned NOT NULL DEFAULT '0',
CHANGE `RewardItemCount3` `RewardAmount3` smallint(5) unsigned NOT NULL DEFAULT '0',
CHANGE `RewardItemCount4` `RewardAmount4` smallint(5) unsigned NOT NULL DEFAULT '0',
CHANGE `RewardChoiceItemId1` `RewardChoiceItemID1` mediumint(8) unsigned NOT NULL DEFAULT '0',
CHANGE `RewardChoiceItemId2` `RewardChoiceItemID2` mediumint(8) unsigned NOT NULL DEFAULT '0',
CHANGE `RewardChoiceItemId3` `RewardChoiceItemID3` mediumint(8) unsigned NOT NULL DEFAULT '0',
CHANGE `RewardChoiceItemId4` `RewardChoiceItemID4` mediumint(8) unsigned NOT NULL DEFAULT '0',
CHANGE `RewardChoiceItemId5` `RewardChoiceItemID5` mediumint(8) unsigned NOT NULL DEFAULT '0',
CHANGE `RewardChoiceItemId6` `RewardChoiceItemID6` mediumint(8) unsigned NOT NULL DEFAULT '0',
CHANGE `RewardChoiceItemCount1` `RewardChoiceItemQuantity1` smallint(5) unsigned NOT NULL DEFAULT '0',
CHANGE `RewardChoiceItemCount2` `RewardChoiceItemQuantity2` smallint(5) unsigned NOT NULL DEFAULT '0',
CHANGE `RewardChoiceItemCount3` `RewardChoiceItemQuantity3` smallint(5) unsigned NOT NULL DEFAULT '0',
CHANGE `RewardChoiceItemCount4` `RewardChoiceItemQuantity4` smallint(5) unsigned NOT NULL DEFAULT '0',
CHANGE `RewardChoiceItemCount5` `RewardChoiceItemQuantity5` smallint(5) unsigned NOT NULL DEFAULT '0',
CHANGE `RewardChoiceItemCount6` `RewardChoiceItemQuantity6` smallint(5) unsigned NOT NULL DEFAULT '0',
CHANGE `RewardFactionId1` `RewardFactionID1` smallint(5) unsigned NOT NULL DEFAULT '0' COMMENT 'faction id from Faction.dbc in this case',
CHANGE `RewardFactionId2` `RewardFactionID2` smallint(5) unsigned NOT NULL DEFAULT '0' COMMENT 'faction id from Faction.dbc in this case',
CHANGE `RewardFactionId3` `RewardFactionID3` smallint(5) unsigned NOT NULL DEFAULT '0' COMMENT 'faction id from Faction.dbc in this case',
CHANGE `RewardFactionId4` `RewardFactionID4` smallint(5) unsigned NOT NULL DEFAULT '0' COMMENT 'faction id from Faction.dbc in this case',
CHANGE `RewardFactionId5` `RewardFactionID5` smallint(5) unsigned NOT NULL DEFAULT '0' COMMENT 'faction id from Faction.dbc in this case',
CHANGE `RewardFactionValueId1` `RewardFactionValue1` mediumint(8) NOT NULL DEFAULT '0',
CHANGE `RewardFactionValueId2` `RewardFactionValue2` mediumint(8) NOT NULL DEFAULT '0',
CHANGE `RewardFactionValueId3` `RewardFactionValue3` mediumint(8) NOT NULL DEFAULT '0',
CHANGE `RewardFactionValueId4` `RewardFactionValue4` mediumint(8) NOT NULL DEFAULT '0',
CHANGE `RewardFactionValueId5` `RewardFactionValue5` mediumint(8) NOT NULL DEFAULT '0',
CHANGE `RewardFactionValueIdOverride1` `RewardFactionOverride1` mediumint(8) NOT NULL DEFAULT '0',
CHANGE `RewardFactionValueIdOverride2` `RewardFactionOverride2` mediumint(8) NOT NULL DEFAULT '0',
CHANGE `RewardFactionValueIdOverride3` `RewardFactionOverride3` mediumint(8) NOT NULL DEFAULT '0',
CHANGE `RewardFactionValueIdOverride4` `RewardFactionOverride4` mediumint(8) NOT NULL DEFAULT '0',
CHANGE `RewardFactionValueIdOverride5` `RewardFactionOverride5` mediumint(8) NOT NULL DEFAULT '0',
CHANGE `Title` `LogTitle` text,
CHANGE `Objectives` `LogDescription` text,
CHANGE `Details` `QuestDescription` text,
CHANGE `CompletedText` `QuestCompletionLog` text;

-- spell_target_position
ALTER TABLE `spell_target_position`
CHANGE `id` `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0' COMMENT 'Identifier',
CHANGE `effIndex` `EffectIndex` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0',
CHANGE `target_map` `MapID` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0',
CHANGE `target_position_x` `PositionX` FLOAT NOT NULL DEFAULT '0',
CHANGE `target_position_y` `PositionY` FLOAT NOT NULL DEFAULT '0',
CHANGE `target_position_z` `PositionZ` FLOAT NOT NULL DEFAULT '0',
CHANGE `target_orientation` `Orientation` FLOAT NOT NULL DEFAULT '0';
