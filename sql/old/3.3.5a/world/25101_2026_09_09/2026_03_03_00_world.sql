-- Snowpacked Icicle Target
UPDATE `creature_template` SET `ScriptName` = 'npc_snowpacked_icicle_target' WHERE `entry` = 33174;

-- Messed up friends
UPDATE `creature_template` SET `ScriptName` = 'npc_hodir_druid' WHERE `entry` = 32901;
UPDATE `creature_template` SET `ScriptName` = 'npc_hodir_shaman' WHERE `entry` = 32900;

-- Priest
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 62809;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,62809,0,0,31,0,3,32893,0,0,0,0,"","Group 0: Spell 'Great Heal' (Effect 0) targets creature 'Missy Flamecuffs'"),
(13,1,62809,0,1,31,0,3,32897,0,0,0,0,"","Group 1: Spell 'Great Heal' (Effect 0) targets creature 'Field Medic Penny'"),
(13,1,62809,0,2,31,0,3,32900,0,0,0,0,"","Group 2: Spell 'Great Heal' (Effect 0) targets creature 'Elementalist Avuun'"),
(13,1,62809,0,3,31,0,3,32901,0,0,0,0,"","Group 3: Spell 'Great Heal' (Effect 0) targets creature 'Ellie Nightfeather'"),
(13,1,62809,0,4,31,0,3,32941,0,0,0,0,"","Group 4: Spell 'Great Heal' (Effect 0) targets creature 'Tor Greycloud'"),
(13,1,62809,0,5,31,0,3,32946,0,0,0,0,"","Group 5: Spell 'Great Heal' (Effect 0) targets creature 'Veesha Blazeweaver'"),
(13,1,62809,0,6,31,0,3,32948,0,0,0,0,"","Group 6: Spell 'Great Heal' (Effect 0) targets creature 'Battle-Priest Eliza'"),
(13,1,62809,0,7,31,0,3,32950,0,0,0,0,"","Group 7: Spell 'Great Heal' (Effect 0) targets creature 'Spiritwalker Yona'"),
(13,1,62809,0,8,31,0,3,33325,0,0,0,0,"","Group 8: Spell 'Great Heal' (Effect 0) targets creature 'Eivi Nightfeather'"),
(13,1,62809,0,9,31,0,3,33326,0,0,0,0,"","Group 10: Spell 'Great Heal' (Effect 0) targets creature 'Field Medic Jessi'"),
(13,1,62809,0,10,31,0,3,33327,0,0,0,0,"","Group 11: Spell 'Great Heal' (Effect 0) targets creature 'Sissy Flamecuffs'"),
(13,1,62809,0,11,31,0,3,33328,0,0,0,0,"","Group 12: Spell 'Great Heal' (Effect 0) targets creature 'Elementalist Mahfuun'"),
(13,1,62809,0,12,31,0,3,33330,0,0,0,0,"","Group 13: Spell 'Great Heal' (Effect 0) targets creature 'Battle-Priest Gina'"),
(13,1,62809,0,13,31,0,3,33331,0,0,0,0,"","Group 14: Spell 'Great Heal' (Effect 0) targets creature 'Amira Blazeweaver'"),
(13,1,62809,0,14,31,0,3,33332,0,0,0,0,"","Group 15: Spell 'Great Heal' (Effect 0) targets creature 'Spiritwalker Tara'"),
(13,1,62809,0,15,31,0,3,33333,0,0,0,0,"","Group 16: Spell 'Great Heal' (Effect 0) targets creature 'Kar Greycloud'");

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_hodir_dispel_magic';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(63499, 'spell_hodir_dispel_magic');

-- Shaman
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_hodir_storm_cloud_primer';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(62797, 'spell_hodir_storm_cloud_primer');

-- Mage
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 64543;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,64543,0,0,31,0,3,32926,0,0,0,0,"","Group 0: Spell 'Melt Ice' (Effect 0) targets creature 'Flash Freeze'"),
(13,1,64543,0,1,31,0,3,32938,0,0,0,0,"","Group 1: Spell 'Melt Ice' (Effect 0) targets creature 'Flash Freeze'");

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_hodir_melt_ice';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(64543, 'spell_hodir_melt_ice');

-- Toasty Fire
UPDATE `creature_template` SET `unit_flags` = 33554432, `flags_extra` = `flags_extra` &~ 2 WHERE `entry` = 33342;

-- Flash Freeze (Init)
UPDATE `creature_template` SET `ScriptName` = 'npc_flash_freeze_init' WHERE `entry` = 32938;

-- Flash Freeze (Combat)
UPDATE `creature_template` SET `flags_extra` = `flags_extra` &~ (128|8192) WHERE `entry` IN (32926,33352);
UPDATE `creature_template` SET `ScriptName` = 'npc_flash_freeze_combat' WHERE `entry` = 32926;

-- Coolest Friends
UPDATE `creature_template` SET `unit_flags` = `unit_flags` |32768|512, `StringId` = 'HodirCoolestFriend' WHERE `entry` IN (32893,32897,32900,32901,32941,32946,32948,32950,33325,33326,33327,33328,33330,33331,33332,33333);

-- Hodir
DELETE FROM `creature_text` WHERE `CreatureID` = 32845 AND `GroupID` = 3;
UPDATE `creature_text` SET `Sound` = 15556 WHERE `CreatureID` = 32845 AND `GroupID` = 8;

UPDATE `spell_script_names` SET `ScriptName` = 'spell_hodir_biting_cold_area_aura' WHERE `ScriptName` = 'spell_biting_cold';
UPDATE `spell_script_names` SET `ScriptName` = 'spell_hodir_biting_cold_periodic' WHERE `ScriptName` = 'spell_biting_cold_dot';

DELETE FROM `spell_target_position` WHERE `ID` = 62501;
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `VerifiedBuild`) VALUES
(62501,0,603,2036.17,-201.843,432.687,3.14159,0);

UPDATE `gameobject_template_addon` SET `flags` = 16 WHERE `entry` IN (194201,194307,194308);
UPDATE `gameobject` SET `spawntimesecs` = 604800 WHERE `id` IN (194307,194308);

DELETE FROM `gameobject` WHERE `guid` IN (9908,9911) AND `id` IN (194200,194201);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `ScriptName`, `StringId`, `VerifiedBuild`) VALUES
(9908,194200,603,0,0,1,1,2036.169921875,-201.842605590820312,432.686798095703125,3.141592741012573242,0,0,-1,0,604800,255,1,'',NULL,0),
(9911,194201,603,0,0,2,1,2036.169921875,-201.842605590820312,432.686798095703125,3.141592741012573242,0,0,-1,0,604800,255,1,'',NULL,0);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_hodir_shatter_chest',
'spell_hodir_icicle',
'spell_hodir_icicle_force_cast',
'spell_hodir_flash_freeze',
'spell_hodir_freeze');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(65272, 'spell_hodir_shatter_chest'),
(63545, 'spell_hodir_icicle'),
(62476, 'spell_hodir_icicle_force_cast'),
(62477, 'spell_hodir_icicle_force_cast'),
(61968, 'spell_hodir_flash_freeze'),
(62469, 'spell_hodir_freeze');

-- Achievements
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (10259,10261,10247,10248,10452,10458,10258,10260,10223,10240,10241,10229,10238,10239) AND `type` IN (11,18);
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(10259,11,0,0,'achievement_cheese_the_freeze'),
(10261,11,0,0,'achievement_cheese_the_freeze'),
(10247,11,0,0,'achievement_getting_cold_in_here'),
(10248,11,0,0,'achievement_getting_cold_in_here'),
(10452,11,0,0,'achievement_this_cache_was_rare'),
(10458,11,0,0,'achievement_this_cache_was_rare'),
(10258,11,0,0,'achievement_i_have_the_coolest_friends'),
(10260,11,0,0,'achievement_i_have_the_coolest_friends'),
(10223,11,0,0,'achievement_staying_buffed_all_winter'),
(10240,11,0,0,'achievement_staying_buffed_all_winter'),
(10241,11,0,0,'achievement_staying_buffed_all_winter'),
(10229,11,0,0,'achievement_staying_buffed_all_winter_25'),
(10238,11,0,0,'achievement_staying_buffed_all_winter_25'),
(10239,11,0,0,'achievement_staying_buffed_all_winter_25');

-- First is replaced by spell scripts, last 2 are simply removed since are based on nothing \ or simply wrong
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (62821,61969,61990);

--
UPDATE `spell_dbc` SET `DurationIndex` = 327, `Effect2` = 6, `EffectImplicitTargetA1` = 22 /*18*/, `EffectImplicitTargetA2` = 22, `EffectImplicitTargetB1` = 15, /*16*/ `EffectImplicitTargetB2` = 15, `EffectApplyAuraName2` = 4, `EffectRadiusIndex2` = 28 WHERE `Id` = 64899;
