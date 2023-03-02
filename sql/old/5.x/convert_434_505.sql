DELETE FROM `spell_proc_event` WHERE entry in (78228,33191,79133,16235,16176,79134);
ALTER TABLE `spell_proc_event` DROP COLUMN `effectmask`;
ALTER TABLE `spell_bonus_data` DROP COLUMN `damage_bonus`;
ALTER TABLE `spell_bonus_data` DROP COLUMN `heal_bonus`;
ALTER TABLE `instance_template` DROP COLUMN `bossCount`;
ALTER TABLE player_levelstats CHANGE sta sta INT(5);
ALTER TABLE player_levelstats CHANGE agi agi INT(5);
ALTER TABLE player_levelstats CHANGE str str INT(5);
ALTER TABLE player_levelstats CHANGE inte inte INT(5);
ALTER TABLE player_levelstats CHANGE spi spi INT(5);

DROP TABLE IF EXISTS `spell_dbc`;
CREATE TABLE `spell_dbc` (
  `Id` int(10) unsigned NOT NULL,
  `Dispel` int(10) unsigned NOT NULL DEFAULT '0',
  `Mechanic` int(10) unsigned NOT NULL DEFAULT '0',
  `Attributes` int(10) unsigned NOT NULL DEFAULT '0',
  `AttributesEx` int(10) unsigned NOT NULL DEFAULT '0',
  `AttributesEx2` int(10) unsigned NOT NULL DEFAULT '0',
  `AttributesEx3` int(10) unsigned NOT NULL DEFAULT '0',
  `AttributesEx4` int(10) unsigned NOT NULL DEFAULT '0',
  `AttributesEx5` int(10) unsigned NOT NULL DEFAULT '0',
  `AttributesEx6` int(10) unsigned NOT NULL DEFAULT '0',
  `AttributesEx7` int(10) unsigned NOT NULL DEFAULT '0',
  `Stances` int(10) unsigned NOT NULL DEFAULT '0',
  `StancesNot` int(10) unsigned NOT NULL DEFAULT '0',
  `Targets` int(10) unsigned NOT NULL DEFAULT '0',
  `CastingTimeIndex` int(10) unsigned NOT NULL DEFAULT '1',
  `AuraInterruptFlags` int(10) unsigned NOT NULL DEFAULT '0',
  `ProcFlags` int(10) unsigned NOT NULL DEFAULT '0',
  `ProcChance` int(10) unsigned NOT NULL DEFAULT '0',
  `ProcCharges` int(10) unsigned NOT NULL DEFAULT '0',
  `MaxLevel` int(10) unsigned NOT NULL DEFAULT '0',
  `BaseLevel` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellLevel` int(10) unsigned NOT NULL DEFAULT '0',
  `DurationIndex` int(10) unsigned NOT NULL DEFAULT '0',
  `RangeIndex` int(10) unsigned NOT NULL DEFAULT '1',
  `StackAmount` int(10) unsigned NOT NULL DEFAULT '0',
  `EquippedItemClass` int(11) NOT NULL DEFAULT '-1',
  `EquippedItemSubClassMask` int(11) NOT NULL DEFAULT '0',
  `EquippedItemInventoryTypeMask` int(11) NOT NULL DEFAULT '0',
  `Effect1` int(10) unsigned NOT NULL DEFAULT '0',
  `Effect2` int(10) unsigned NOT NULL DEFAULT '0',
  `Effect3` int(10) unsigned NOT NULL DEFAULT '0',
  `EffectDieSides1` int(11) NOT NULL DEFAULT '0',
  `EffectDieSides2` int(11) NOT NULL DEFAULT '0',
  `EffectDieSides3` int(11) NOT NULL DEFAULT '0',
  `EffectRealPointsPerLevel1` float NOT NULL DEFAULT '0',
  `EffectRealPointsPerLevel2` float NOT NULL DEFAULT '0',
  `EffectRealPointsPerLevel3` float NOT NULL DEFAULT '0',
  `EffectBasePoints1` int(11) NOT NULL DEFAULT '0',
  `EffectBasePoints2` int(11) NOT NULL DEFAULT '0',
  `EffectBasePoints3` int(11) NOT NULL DEFAULT '0',
  `EffectMechanic1` int(10) unsigned NOT NULL DEFAULT '0',
  `EffectMechanic2` int(10) unsigned NOT NULL DEFAULT '0',
  `EffectMechanic3` int(10) unsigned NOT NULL DEFAULT '0',
  `EffectImplicitTargetA1` int(10) unsigned NOT NULL DEFAULT '0',
  `EffectImplicitTargetA2` int(10) unsigned NOT NULL DEFAULT '0',
  `EffectImplicitTargetA3` int(10) unsigned NOT NULL DEFAULT '0',
  `EffectImplicitTargetB1` int(10) unsigned NOT NULL DEFAULT '0',
  `EffectImplicitTargetB2` int(10) unsigned NOT NULL DEFAULT '0',
  `EffectImplicitTargetB3` int(10) unsigned NOT NULL DEFAULT '0',
  `EffectRadiusIndex1` int(10) unsigned NOT NULL DEFAULT '0',
  `EffectRadiusIndex2` int(10) unsigned NOT NULL DEFAULT '0',
  `EffectRadiusIndex3` int(10) unsigned NOT NULL DEFAULT '0',
  `EffectApplyAuraName1` int(10) unsigned NOT NULL DEFAULT '0',
  `EffectApplyAuraName2` int(10) unsigned NOT NULL DEFAULT '0',
  `EffectApplyAuraName3` int(10) unsigned NOT NULL DEFAULT '0',
  `EffectAmplitude1` int(11) NOT NULL DEFAULT '0',
  `EffectAmplitude2` int(11) NOT NULL DEFAULT '0',
  `EffectAmplitude3` int(11) NOT NULL DEFAULT '0',
  `EffectMultipleValue1` float NOT NULL DEFAULT '0',
  `EffectMultipleValue2` float NOT NULL DEFAULT '0',
  `EffectMultipleValue3` float NOT NULL DEFAULT '0',
  `EffectMiscValue1` int(11) NOT NULL DEFAULT '0',
  `EffectMiscValue2` int(11) NOT NULL DEFAULT '0',
  `EffectMiscValue3` int(11) NOT NULL DEFAULT '0',
  `EffectMiscValueB1` int(11) NOT NULL DEFAULT '0',
  `EffectMiscValueB2` int(11) NOT NULL DEFAULT '0',
  `EffectMiscValueB3` int(11) NOT NULL DEFAULT '0',
  `EffectTriggerSpell1` int(10) unsigned NOT NULL DEFAULT '0',
  `EffectTriggerSpell2` int(10) unsigned NOT NULL DEFAULT '0',
  `EffectTriggerSpell3` int(10) unsigned NOT NULL DEFAULT '0',
  `EffectSpellClassMaskA1` int(10) unsigned NOT NULL DEFAULT '0',
  `EffectSpellClassMaskA2` int(10) unsigned NOT NULL DEFAULT '0',
  `EffectSpellClassMaskA3` int(10) unsigned NOT NULL DEFAULT '0',
  `EffectSpellClassMaskB1` int(10) unsigned NOT NULL DEFAULT '0',
  `EffectSpellClassMaskB2` int(10) unsigned NOT NULL DEFAULT '0',
  `EffectSpellClassMaskB3` int(10) unsigned NOT NULL DEFAULT '0',
  `EffectSpellClassMaskC1` int(10) unsigned NOT NULL DEFAULT '0',
  `EffectSpellClassMaskC2` int(10) unsigned NOT NULL DEFAULT '0',
  `EffectSpellClassMaskC3` int(10) unsigned NOT NULL DEFAULT '0',
  `MaxTargetLevel` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellFamilyName` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellFamilyFlags1` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellFamilyFlags2` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellFamilyFlags3` int(10) unsigned NOT NULL DEFAULT '0',
  `MaxAffectedTargets` int(10) unsigned NOT NULL DEFAULT '0',
  `DmgClass` int(10) unsigned NOT NULL DEFAULT '0',
  `PreventionType` int(10) unsigned NOT NULL DEFAULT '0',
  `DmgMultiplier1` float NOT NULL DEFAULT '0',
  `DmgMultiplier2` float NOT NULL DEFAULT '0',
  `DmgMultiplier3` float NOT NULL DEFAULT '0',
  `AreaGroupId` int(11) NOT NULL DEFAULT '0',
  `SchoolMask` int(10) unsigned NOT NULL DEFAULT '0',
  `Comment` text NOT NULL,
  PRIMARY KEY (`Id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Custom spell.dbc entries';

ALTER TABLE `creature` ADD COLUMN `isActive` tinyint(1) unsigned NOT NULL DEFAULT '0' AFTER `dynamicflags`;
ALTER TABLE `gameobject` ADD COLUMN `isActive` tinyint(1) unsigned NOT NULL DEFAULT '0' AFTER `state`;
ALTER TABLE `creature_template` ADD COLUMN `speed_fly` float NOT NULL DEFAULT '1.14286' COMMENT 'Result of 8.0/7.0, most common value' AFTER `speed_run`;

ALTER TABLE `locales_quest`
ADD COLUMN `Title_loc9` text AFTER `Title_loc8`,
ADD COLUMN `Title_loc10` text AFTER `Title_loc9`,
ADD COLUMN `Details_loc9` text AFTER `Details_loc8`,
ADD COLUMN `Details_loc10` text AFTER `Details_loc9`,
ADD COLUMN `Objectives_loc9` text AFTER `Objectives_loc8`,
ADD COLUMN `Objectives_loc10` text AFTER `Objectives_loc9`,
ADD COLUMN `OfferRewardText_loc9` text AFTER `OfferRewardText_loc8`,
ADD COLUMN `OfferRewardText_loc10` text AFTER `OfferRewardText_loc9`,
ADD COLUMN `RequestItemsText_loc9` text AFTER `RequestItemsText_loc8`,
ADD COLUMN `RequestItemsText_loc10` text AFTER `RequestItemsText_loc9`,
ADD COLUMN `EndText_loc9` text AFTER `EndText_loc8`,
ADD COLUMN `EndText_loc10` text AFTER `EndText_loc9`,
ADD COLUMN `CompletedText_loc9` text AFTER `CompletedText_loc8`,
ADD COLUMN `CompletedText_loc10` text AFTER `CompletedText_loc9`,
ADD COLUMN `ObjectiveText1_loc9` text AFTER `ObjectiveText1_loc8`,
ADD COLUMN `ObjectiveText1_loc10` text AFTER `ObjectiveText1_loc9`,
ADD COLUMN `ObjectiveText2_loc9` text AFTER `ObjectiveText2_loc8`,
ADD COLUMN `ObjectiveText2_loc10` text AFTER `ObjectiveText2_loc9`,
ADD COLUMN `ObjectiveText3_loc9` text AFTER `ObjectiveText3_loc8`,
ADD COLUMN `ObjectiveText3_loc10` text AFTER `ObjectiveText3_loc9`,
ADD COLUMN `ObjectiveText4_loc9` text AFTER `ObjectiveText4_loc8`,
ADD COLUMN `ObjectiveText4_loc10` text AFTER `ObjectiveText4_loc9`,
ADD COLUMN `QuestGiverTextWindow_loc9` text AFTER `QuestGiverTextWindow_loc8`,
ADD COLUMN `QuestGiverTextWindow_loc10` text AFTER `QuestGiverTextWindow_loc9`,
ADD COLUMN `QuestGiverTargetName_loc9` text AFTER `QuestGiverTargetName_loc8`,
ADD COLUMN `QuestGiverTargetName_loc10` text AFTER `QuestGiverTargetName_loc9`,
ADD COLUMN `QuestTurnTextWindow_loc9` text AFTER `QuestTurnTextWindow_loc8`,
ADD COLUMN `QuestTurnTextWindow_loc10` text AFTER `QuestTurnTextWindow_loc9`,
ADD COLUMN `QuestTurnTargetName_loc9` text AFTER `QuestTurnTargetName_loc8`,
ADD COLUMN `QuestTurnTargetName_loc10` text AFTER `QuestTurnTargetName_loc9`;

ALTER TABLE `locales_npc_text`
ADD COLUMN  `Text8_0_loc1` longtext AFTER `Text7_1_loc10`,
ADD COLUMN  `Text8_0_loc2` longtext AFTER `Text8_0_loc1`,
ADD COLUMN  `Text8_0_loc3` longtext AFTER `Text8_0_loc2`,
ADD COLUMN  `Text8_0_loc4` longtext AFTER `Text8_0_loc3`,
ADD COLUMN  `Text8_0_loc5` longtext AFTER `Text8_0_loc4`,
ADD COLUMN  `Text8_0_loc6` longtext AFTER `Text8_0_loc5`,
ADD COLUMN  `Text8_0_loc7` longtext AFTER `Text8_0_loc6`,
ADD COLUMN  `Text8_0_loc8` longtext AFTER `Text8_0_loc7`,
ADD COLUMN  `Text8_0_loc9` longtext AFTER `Text8_0_loc8`,
ADD COLUMN  `Text8_0_loc10` longtext AFTER `Text8_0_loc9`,
ADD COLUMN  `Text8_1_loc1` longtext AFTER `Text8_0_loc10`,
ADD COLUMN  `Text8_1_loc2` longtext AFTER `Text8_1_loc1`,
ADD COLUMN  `Text8_1_loc3` longtext AFTER `Text8_1_loc2`,
ADD COLUMN  `Text8_1_loc4` longtext AFTER `Text8_1_loc3`,
ADD COLUMN  `Text8_1_loc5` longtext AFTER `Text8_1_loc4`,
ADD COLUMN  `Text8_1_loc6` longtext AFTER `Text8_1_loc5`,
ADD COLUMN  `Text8_1_loc7` longtext AFTER `Text8_1_loc6`,
ADD COLUMN  `Text8_1_loc8` longtext AFTER `Text8_1_loc7`,
ADD COLUMN  `Text8_1_loc9` longtext AFTER `Text8_1_loc8`,
ADD COLUMN  `Text8_1_loc10` longtext AFTER `Text8_1_loc9`,
ADD COLUMN  `Text9_0_loc1` longtext AFTER `Text8_1_loc10`,
ADD COLUMN  `Text9_0_loc2` longtext AFTER `Text9_0_loc1`,
ADD COLUMN  `Text9_0_loc3` longtext AFTER `Text9_0_loc2`,
ADD COLUMN  `Text9_0_loc4` longtext AFTER `Text9_0_loc3`,
ADD COLUMN  `Text9_0_loc5` longtext AFTER `Text9_0_loc4`,
ADD COLUMN  `Text9_0_loc6` longtext AFTER `Text9_0_loc5`,
ADD COLUMN  `Text9_0_loc7` longtext AFTER `Text9_0_loc6`,
ADD COLUMN  `Text9_0_loc8` longtext AFTER `Text9_0_loc7`,
ADD COLUMN  `Text9_0_loc9` longtext AFTER `Text9_0_loc8`,
ADD COLUMN  `Text9_0_loc10` longtext AFTER `Text9_0_loc9`,
ADD COLUMN  `Text9_1_loc1` longtext AFTER `Text9_0_loc10`,
ADD COLUMN  `Text9_1_loc2` longtext AFTER `Text9_1_loc1`,
ADD COLUMN  `Text9_1_loc3` longtext AFTER `Text9_1_loc2`,
ADD COLUMN  `Text9_1_loc4` longtext AFTER `Text9_1_loc3`,
ADD COLUMN  `Text9_1_loc5` longtext AFTER `Text9_1_loc4`,
ADD COLUMN  `Text9_1_loc6` longtext AFTER `Text9_1_loc5`,
ADD COLUMN  `Text9_1_loc7` longtext AFTER `Text9_1_loc6`,
ADD COLUMN  `Text9_1_loc8` longtext AFTER `Text9_1_loc7`,
ADD COLUMN  `Text9_1_loc9` longtext AFTER `Text9_1_loc8`,
ADD COLUMN  `Text9_1_loc10` longtext AFTER `Text9_1_loc9`;


ALTER TABLE `locales_achievement_reward`
ADD COLUMN  `subject_loc9` varchar(100) NOT NULL DEFAULT '' AFTER `subject_loc8`,
ADD COLUMN  `subject_loc10` varchar(100) NOT NULL DEFAULT '' AFTER `subject_loc9`,
ADD COLUMN  `text_loc9` text AFTER `text_loc8`,
ADD COLUMN  `text_loc10` text AFTER `text_loc9`;

ALTER TABLE `db_script_string`
ADD COLUMN  `content_loc9` text AFTER `content_loc8`,
ADD COLUMN  `content_loc10` text AFTER `content_loc9`;
ALTER TABLE `script_texts`
ADD COLUMN  `content_loc9` text AFTER `content_loc8`,
ADD COLUMN  `content_loc10` text AFTER `content_loc9`;
ALTER TABLE `trinity_string`
ADD COLUMN  `content_loc9` text AFTER `content_loc8`,
ADD COLUMN  `content_loc10` text AFTER `content_loc9`;
ALTER TABLE `custom_texts`
ADD COLUMN  `content_loc9` text AFTER `content_loc8`,
ADD COLUMN  `content_loc10` text AFTER `content_loc9`;

DROP TABLE IF EXISTS `lfg_dungeon_rewards`;
CREATE TABLE `lfg_dungeon_rewards` (
  `dungeonId` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Dungeon entry from dbc',
  `maxLevel` tinyint(3) unsigned NOT NULL DEFAULT '0' COMMENT 'Max level at which this reward is rewarded',
  `firstQuestId` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Quest id with rewards for first dungeon this day',
  `firstMoneyVar` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Money multiplier for completing the dungeon first time in a day with less players than max',
  `firstXPVar` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Experience multiplier for completing the dungeon first time in a day with less players than max',
  `otherQuestId` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Quest id with rewards for Nth dungeon this day',
  `otherMoneyVar` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Money multiplier for completing the dungeon Nth time in a day with less players than max',
  `otherXPVar` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Experience multiplier for completing the dungeon Nth time in a day with less players than max',
  PRIMARY KEY (`dungeonId`,`maxLevel`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
