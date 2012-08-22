ALTER TABLE `instance_template` CHANGE `allowMount` `allowMount` tinyint(3) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `ip2nation` CHANGE `ip` `ip` int(10) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `item_loot_template` CHANGE `mincountOrRef` `mincountOrRef` mediumint(8) NOT NULL DEFAULT '1';
ALTER TABLE `item_set_names` CHANGE `WDBVerified` `WDBVerified` smallint(6) NOT NULL DEFAULT '1';
ALTER TABLE `item_template` CHANGE `spellcharges_1` `spellcharges_1` smallint(6) NULL DEFAULT NULL;
ALTER TABLE `item_template` CHANGE `spellcharges_2` `spellcharges_2` smallint(6) NULL DEFAULT NULL;
ALTER TABLE `item_template` CHANGE `spellcharges_3` `spellcharges_3` smallint(6) NULL DEFAULT NULL;
ALTER TABLE `item_template` CHANGE `spellcharges_4` `spellcharges_4` smallint(6) NULL DEFAULT NULL;
ALTER TABLE `item_template` CHANGE `spellcharges_5` `spellcharges_5` smallint(6) NULL DEFAULT NULL;
ALTER TABLE `item_template` CHANGE `BagFamily` `BagFamily` mediumint(8) NOT NULL DEFAULT '0';
ALTER TABLE `item_template` CHANGE `TotemCategory` `TotemCategory` mediumint(8) NOT NULL DEFAULT '0';
ALTER TABLE `item_template` CHANGE `socketContent_1` `socketContent_1` mediumint(8) NOT NULL DEFAULT '0';
ALTER TABLE `item_template` CHANGE `socketContent_2` `socketContent_2` mediumint(8) NOT NULL DEFAULT '0';
ALTER TABLE `item_template` CHANGE `socketContent_3` `socketContent_3` mediumint(8) NOT NULL DEFAULT '0';
ALTER TABLE `item_template` CHANGE `socketBonus` `socketBonus` mediumint(8) NOT NULL DEFAULT '0';
ALTER TABLE `item_template` CHANGE `GemProperties` `GemProperties` mediumint(8) NOT NULL DEFAULT '0';
ALTER TABLE `item_template` CHANGE `WDBVerified` `WDBVerified` smallint(6) NULL DEFAULT '1';
ALTER TABLE `item_template` CHANGE `ScalingStatValue` `ScalingStatValue` int(10) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `mail_loot_template` CHANGE `mincountOrRef` `mincountOrRef` mediumint(8) NOT NULL DEFAULT '1';
ALTER TABLE `milling_loot_template` CHANGE `mincountOrRef` `mincountOrRef` mediumint(8) NOT NULL DEFAULT '1';
ALTER TABLE `npc_spellclick_spells` CHANGE `user_type` `user_type` smallint(5) unsigned NOT NULL DEFAULT '0' COMMENT 'relation with summoner: 0-no 1-friendly 2-raid 3-party player can click';
ALTER TABLE `outdoorpvp_template` CHANGE `TypeId` `TypeId` tinyint(3) unsigned NOT NULL;
ALTER TABLE `page_text` CHANGE `WDBVerified` `WDBVerified` smallint(6) NULL DEFAULT '1';
ALTER TABLE `pet_name_generation` CHANGE `half` `half` tinyint(3) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `pickpocketing_loot_template` CHANGE `mincountOrRef` `mincountOrRef` mediumint(8) NOT NULL DEFAULT '1';
ALTER TABLE `player_factionchange_achievement` CHANGE `alliance_id` `alliance_id` int(10) unsigned NOT NULL; -- also changed to unsigned
ALTER TABLE `player_factionchange_achievement` CHANGE `horde_id` `horde_id` int(10) unsigned NOT NULL; -- also changed to unsigned
ALTER TABLE `player_factionchange_items` CHANGE `race_A` `race_A` int(10) unsigned NOT NULL; -- also changed to unsigned
ALTER TABLE `player_factionchange_items` CHANGE `alliance_id` `alliance_id` int(10) unsigned NOT NULL; -- also changed to unsigned
ALTER TABLE `player_factionchange_items` CHANGE `race_H` `race_H` int(10) unsigned NOT NULL; -- also changed to unsigned
ALTER TABLE `player_factionchange_items` CHANGE `horde_id` `horde_id` int(10) unsigned NOT NULL; -- also changed to unsigned
ALTER TABLE `player_factionchange_reputations` CHANGE `alliance_id` `alliance_id` int(10) unsigned NOT NULL; -- also changed to unsigned
ALTER TABLE `player_factionchange_reputations` CHANGE `horde_id` `horde_id` int(10) unsigned NOT NULL; -- also changed to unsigned
ALTER TABLE `player_factionchange_spells` CHANGE `alliance_id` `alliance_id` int(10) unsigned NOT NULL; -- also changed to unsigned
ALTER TABLE `player_factionchange_spells` CHANGE `horde_id` `horde_id` int(10) unsigned NOT NULL; -- also changed to unsigned
ALTER TABLE `player_xp_for_level` CHANGE `lvl` `lvl` tinyint(3) unsigned NOT NULL; -- also changed from int to tinyint
ALTER TABLE `playercreateinfo_action` CHANGE `action` `action` int(10) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `playercreateinfo_item` CHANGE `amount` `amount` tinyint(4) NOT NULL DEFAULT '1';
ALTER TABLE `playercreateinfo_spell_custom` DROP `Active`; -- delete field, it's not used anywhere
ALTER TABLE `prospecting_loot_template` CHANGE `mincountOrRef` `mincountOrRef` mediumint(8) NOT NULL DEFAULT '1';
ALTER TABLE `quest_poi` CHANGE `objIndex` `objIndex` int(11) NOT NULL DEFAULT '0';
ALTER TABLE `quest_poi_points` CHANGE `x` `x` int(11) NOT NULL DEFAULT '0';
ALTER TABLE `quest_poi_points` CHANGE `y` `y` int(11) NOT NULL DEFAULT '0';
ALTER TABLE `quest_template` CHANGE `RequiredFactionValue1` `RequiredFactionValue1` mediumint(8) NOT NULL DEFAULT '0';
ALTER TABLE `quest_template` CHANGE `RequiredFactionValue2` `RequiredFactionValue2` mediumint(8) NOT NULL DEFAULT '0';
ALTER TABLE `quest_template` CHANGE `RequiredMinRepValue` `RequiredMinRepValue` mediumint(8) NOT NULL DEFAULT '0';
ALTER TABLE `quest_template` CHANGE `RequiredMinRepValue` `RequiredMinRepValue` mediumint(8) NOT NULL DEFAULT '0';
ALTER TABLE `quest_template` CHANGE `RequiredMaxRepValue` `RequiredMaxRepValue` mediumint(8) NOT NULL DEFAULT '0';
ALTER TABLE `quest_template` CHANGE `PrevQuestId` `PrevQuestId` mediumint(8) NOT NULL DEFAULT '0';
ALTER TABLE `quest_template` CHANGE `NextQuestId` `NextQuestId` mediumint(8) NOT NULL DEFAULT '0';
ALTER TABLE `quest_template` CHANGE `ExclusiveGroup` `ExclusiveGroup` mediumint(8) NOT NULL DEFAULT '0';
ALTER TABLE `quest_template` CHANGE `RewardSpellCast` `RewardSpellCast` int(11) NOT NULL DEFAULT '0';
ALTER TABLE `quest_template` CHANGE `RewardHonor` `RewardHonor` int(11) NOT NULL DEFAULT '0';
ALTER TABLE `quest_template` CHANGE `RewardXPId` `RewardXPId` tinyint(3) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `quest_template` CHANGE `RewardFactionValueId1` `RewardFactionValueId1` mediumint(8) NOT NULL DEFAULT '0';
ALTER TABLE `quest_template` CHANGE `RewardFactionValueId2` `RewardFactionValueId2` mediumint(8) NOT NULL DEFAULT '0';
ALTER TABLE `quest_template` CHANGE `RewardFactionValueId3` `RewardFactionValueId3` mediumint(8) NOT NULL DEFAULT '0';
ALTER TABLE `quest_template` CHANGE `RewardFactionValueId4` `RewardFactionValueId4` mediumint(8) NOT NULL DEFAULT '0';
ALTER TABLE `quest_template` CHANGE `RewardFactionValueId5` `RewardFactionValueId5` mediumint(8) NOT NULL DEFAULT '0';
ALTER TABLE `quest_template` CHANGE `RewardFactionValueIdOverride1` `RewardFactionValueIdOverride1` mediumint(8) NOT NULL DEFAULT '0';
ALTER TABLE `quest_template` CHANGE `RewardFactionValueIdOverride2` `RewardFactionValueIdOverride2` mediumint(8) NOT NULL DEFAULT '0';
ALTER TABLE `quest_template` CHANGE `RewardFactionValueIdOverride3` `RewardFactionValueIdOverride3` mediumint(8) NOT NULL DEFAULT '0';
ALTER TABLE `quest_template` CHANGE `RewardFactionValueIdOverride4` `RewardFactionValueIdOverride4` mediumint(8) NOT NULL DEFAULT '0';
ALTER TABLE `quest_template` CHANGE `RewardFactionValueIdOverride5` `RewardFactionValueIdOverride5` mediumint(8) NOT NULL DEFAULT '0';
ALTER TABLE `quest_template` CHANGE `RequiredNpcOrGo1` `RequiredNpcOrGo1` mediumint(8) NOT NULL DEFAULT '0';
ALTER TABLE `quest_template` CHANGE `RequiredNpcOrGo2` `RequiredNpcOrGo2` mediumint(8) NOT NULL DEFAULT '0';
ALTER TABLE `quest_template` CHANGE `RequiredNpcOrGo3` `RequiredNpcOrGo3` mediumint(8) NOT NULL DEFAULT '0';
ALTER TABLE `quest_template` CHANGE `RequiredNpcOrGo4` `RequiredNpcOrGo4` mediumint(8) NOT NULL DEFAULT '0';
ALTER TABLE `quest_template` CHANGE `Unknown0` `Unknown0` tinyint(3) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `quest_template` CHANGE `DetailsEmoteDelay1` `DetailsEmoteDelay1` int(10) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `quest_template` CHANGE `DetailsEmoteDelay2` `DetailsEmoteDelay2` int(10) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `quest_template` CHANGE `DetailsEmoteDelay3` `DetailsEmoteDelay3` int(10) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `quest_template` CHANGE `DetailsEmoteDelay4` `DetailsEmoteDelay4` int(10) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `quest_template` CHANGE `OfferRewardEmoteDelay1` `OfferRewardEmoteDelay1` int(10) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `quest_template` CHANGE `OfferRewardEmoteDelay2` `OfferRewardEmoteDelay2` int(10) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `quest_template` CHANGE `OfferRewardEmoteDelay3` `OfferRewardEmoteDelay3` int(10) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `quest_template` CHANGE `OfferRewardEmoteDelay4` `OfferRewardEmoteDelay4` int(10) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `quest_template` CHANGE `WDBVerified` `WDBVerified` smallint(6) NOT NULL DEFAULT '1';
