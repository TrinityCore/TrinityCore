-- by canewadar
-- https://www.wowhead.com/quest=47434/restraining-order

-- Pterrordax Hatchling SAI
SET @ENTRY := 126611;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,10,0,100,1,1,4,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Pterrordax Hatchling - Within 1-4 Range Out of Combat LoS - Run Script (No Repeat)");

-- Actionlist SAI
SET @ENTRY := 12661100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,33,126611,0,0,0,0,0,7,0,0,0,0,0,0,0,"Pterrordax Hatchling - On Script - Quest Credit ''"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,114,126611,0,0,0,0,0,1,0,0,0,0,10,5,0,"Pterrordax Hatchling - On Script"),
(@ENTRY,9,2,0,0,0,100,0,2000,2000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pterrordax Hatchling - On Script - Despawn Instant");

-- Pterrordax only works for people that have the quest
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=0 AND `SourceEntry`=126611 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=9 AND `ConditionTarget`=0 AND `ConditionValue1`=47434 AND `ConditionValue2`=0 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES (22, 0, 126611, 0, 0, 9, 0, 47434, 0, 0, 0, 0, 0, '', '');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=1 AND `SourceEntry`=126611 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=9 AND `ConditionTarget`=0 AND `ConditionValue1`=47434 AND `ConditionValue2`=0 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES (22, 1, 126611, 0, 0, 9, 0, 47434, 0, 0, 0, 0, 0, '', '');


-- add missing kill credit so the smart action call kill credit does work


DELETE FROM `creature_template` WHERE `entry`=133397;
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES (133397, 0, 0, 0, 0, 0, 'Finale Sequence Kill Credit', NULL, NULL, NULL, NULL, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1.14286, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, '', 0);
DELETE FROM `creature_template` WHERE `entry`=133372;
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES (133372, 0, 0, 0, 0, 0, 'Questgivers Followed', NULL, NULL, NULL, NULL, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1.14286, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, '', 0);
DELETE FROM `creature_template` WHERE `entry`=133061;
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES (133061, 0, 0, 0, 0, 0, 'Janagalar Strategy Kill Credit', NULL, NULL, NULL, NULL, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1.14286, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, '', 0);
DELETE FROM `creature_template` WHERE `entry`=133060;
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES (133060, 0, 0, 0, 0, 0, 'Cala Strategy Kill Credit', NULL, NULL, NULL, NULL, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1.14286, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, '', 0);
DELETE FROM `creature_template` WHERE `entry`=131833;
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES (131833, 0, 0, 0, 0, 0, 'Ben\'jin Followed Kill Credit', NULL, NULL, NULL, NULL, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1.14286, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, '', 0);
DELETE FROM `creature_template` WHERE `entry`=133166;
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES (133166, 0, 0, 0, 0, 0, 'Benjin Actually Enraged Kill Credit', NULL, NULL, NULL, NULL, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1.14286, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, '', 0);
DELETE FROM `creature_template` WHERE `entry`=131080;
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES (131080, 0, 0, 0, 0, 0, 'Ben\'jin Enraged Kill Credit', NULL, NULL, NULL, NULL, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1.14286, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, '', 0);


-- https://www.wowhead.com/quest=50297/the-head-of-her-enemy
update `npc_spellclick_spells` set `cast_flags` = 1 where `npc_entry` in (133300);

-- https://www.wowhead.com/quest=50268/give-it-a-little-juice#videos:id=138762
update `npc_spellclick_spells` set `cast_flags` = 1 where `npc_entry` in (133167);

-- https://www.wowhead.com/quest=50150/setting-the-mood
update `npc_spellclick_spells` set `cast_flags` = 1 where `npc_entry` in (132628, 132629);

-- animkit 13036 --sound 117774 and 117780

DELETE FROM `waypoints` WHERE `entry`=13092200 AND `pointid`=0;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES (13092200, 0, -837.073, 274.256, 174.805, 'X: -837.0726 Y: 274.2562 Z: 174.8055');
DELETE FROM `waypoints` WHERE `entry`=13092200 AND `pointid`=1;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES (13092200, 1, -833.573, 273.256, 174.805, '-833.5726 Y: 273.2562 Z: 174.8055');
DELETE FROM `waypoints` WHERE `entry`=13092200 AND `pointid`=2;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES (13092200, 2, -830.573, 2725060, 175.055, '-830.5726 Y: 272.5062 Z: 175.0555');
DELETE FROM `waypoints` WHERE `entry`=13092201 AND `pointid`=0;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES (13092201, 0, -830.68, 280.464, 174.131, '-830.5726 Y: 272.5062 Z: 175.0555');
DELETE FROM `waypoints` WHERE `entry`=13092201 AND `pointid`=1;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES (13092201, 1, -825.587, 274.162, 174.968, '-830.5726 Y: 272.5062 Z: 175.0555');
DELETE FROM `waypoints` WHERE `entry`=13092201 AND `pointid`=2;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES (13092201, 2, -825.587, 275.662, 174.718, '-830.5726 Y: 272.5062 Z: 175.0555');
DELETE FROM `waypoints` WHERE `entry`=13092201 AND `pointid`=3;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES (13092201, 3, -825.087, 278.662, 174.718, '-830.5726 Y: 272.5062 Z: 175.0555');


-- quest 49810 https://www.wowhead.com/quest=49810/monstrous-matchmaker with a hackfix cuz spell isn'T castable at the second dino. No dialogue cuz i don't have access to creature_text and no spell cuz i don't know the id.

-- missing gobject hackfix spawn because it's not in the sniffs :(
DELETE FROM `gameobject` WHERE `guid`=210407272;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `ScriptName`, `VerifiedBuild`) VALUES (210407272, 279244, 1642, 8499, 9598, '0', 0, 0, 0, -1, -842.119, 275.512, 174.143, 0, 0, 0, 0, 1, 120, 255, 1, 0, '', 27377);

-- made them immune to pc cuz they tried attacking nearby mobs
update `creature_template` set `unit_flags` = 520 where entry in(131043,136058);

-- Jangalar's Voodoo Totem SAI
SET @ENTRY := 131043;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,0,75,0,100,1,0,130921,20,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Jangalar's Voodoo Totem - On Distance To Creature - Run Script (No Repeat)"),
(@ENTRY,0,2,0,75,0,100,1,0,130922,20,0,80,@ENTRY*100+01,2,0,0,0,0,1,0,0,0,0,0,0,0,"Jangalar's Voodoo Totem - On Distance To Creature - Run Script (No Repeat)"),
(@ENTRY,0,3,0,11,0,100,0,0,0,0,0,18,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jangalar's Voodoo Totem - On Respawn - Set Flag Disable Movement"),
(@ENTRY,0,4,0,60,0,100,0,15000,15000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jangalar's Voodoo Totem - On Update - Despawn Instant"),
(@ENTRY,0,5,0,11,0,100,0,0,0,0,0,75,266928,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jangalar's Voodoo Totem - On Respawn - Add Aura ''");

-- Actionlist SAI
SET @ENTRY := 13104300;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,2000,2000,0,0,33,130921,0,0,0,0,0,23,0,0,0,0,0,0,0,"Jangalar's Voodoo Totem - On Script - Quest Credit ''"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,11,267421,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jangalar's Voodoo Totem - On Script - Cast '<Spell not found!>'"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,11,258950,0,0,0,0,0,19,130921,40,0,0,0,0,0,"Jangalar's Voodoo Totem - On Script - Cast '<Spell not found!>'");

-- Actionlist SAI
SET @ENTRY := 13104301;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,2000,2000,0,0,33,130922,0,0,0,0,0,23,0,0,0,0,0,0,0,"Jangalar's Voodoo Totem - On Script - Quest Credit ''"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,11,267440,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jangalar's Voodoo Totem - On Script - Cast ''"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,11,258950,0,0,0,0,0,19,130922,40,0,0,0,0,0,"Jangalar's Voodoo Totem - On Script - Cast ''");

-- Projection of Jangalar SAI
SET @ENTRY := 136058;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Projection of Jangalar - Out of Combat - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,1,0,100,1,0,0,0,0,11,267431,0,0,0,0,0,1,0,0,0,0,0,0,0,"Projection of Jangalar - Out of Combat - Cast '' (No Repeat)"),
(@ENTRY,0,2,0,1,0,100,1,0,0,0,0,41,13000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Projection of Jangalar - Out of Combat - Despawn In 13000 ms (No Repeat)");

-- Projection of Jangalar SAI
SET @ENTRY := 136067;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Projection of Jangalar - Out of Combat - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,1,0,100,1,0,0,0,0,11,267431,0,0,0,0,0,1,0,0,0,0,0,0,0,"Projection of Jangalar - Out of Combat - Cast '' (No Repeat)"),
(@ENTRY,0,2,0,1,0,100,1,0,0,0,0,41,13000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Projection of Jangalar - Out of Combat - Despawn In 13000 ms (No Repeat)");


-- Added the spells to some mobs that got farmed cuz the spawns are kinda fucked up
-- Faithless Sandscout SAI
SET @ENTRY := 122745;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4000,3000,5000,11,255741,0,0,0,0,0,2,0,0,0,0,0,0,0,"Faithless Sandscout - In Combat - Cast ''"),
(@ENTRY,0,1,0,0,0,100,0,2000,4000,1000,6000,11,268072,0,0,0,0,0,2,0,0,0,0,0,0,0,"Faithless Sandscout - In Combat - Cast ''");

-- Faithless Aggressor SAI
SET @ENTRY := 123863;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,3000,2000,6000,11,255741,0,0,0,0,0,2,0,0,0,0,0,0,0,"Faithless Aggressor - In Combat - Cast ''"),
(@ENTRY,0,1,0,0,0,100,0,1000,3000,2000,6000,11,258945,0,0,0,0,0,2,0,0,0,0,0,0,0,"Faithless Aggressor - In Combat - Cast ''");

-- Faithless Aggressor SAI
SET @ENTRY := 123864;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,3000,2000,6000,11,255741,0,0,0,0,0,2,0,0,0,0,0,0,0,"Faithless Aggressor - In Combat - Cast ''"),
(@ENTRY,0,1,0,0,0,100,0,1000,3000,2000,6000,11,258945,0,0,0,0,0,2,0,0,0,0,0,0,0,"Faithless Aggressor - In Combat - Cast ''");

-- Faithless Champion SAI
SET @ENTRY := 123865;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,6000,11000,11,261716,0,0,0,0,0,2,0,0,0,0,0,0,0,"Faithless Champion - In Combat - Cast ''"),
(@ENTRY,0,1,0,0,0,100,0,1000,4000,2000,7000,11,255741,0,0,0,0,0,2,0,0,0,0,0,0,0,"Faithless Champion - In Combat - Cast ''");

-- Faithless Skycaller SAI
SET @ENTRY := 122746;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,2000,4000,11,258889,0,0,0,0,0,2,0,0,0,0,0,0,0,"Faithless Skycaller - In Combat - Cast ''");

-- fixed a quest chain chapter 3 of story
update `quest_template_addon` set `PrevQuestId` = 47445 where `ID` = 47423;

-- https://www.wowhead.com/quest=47438/picking-a-side

update `npc_spellclick_spells` set `cast_flags` = 1 where `npc_entry` in (138425, 138424);
