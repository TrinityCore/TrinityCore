--
UPDATE `creature_template` SET `unit_flags` = 33554432, `ScriptName` = 'npc_warchiefs_portal' WHERE `entry` = 17611;
DELETE FROM `creature` WHERE `id` = 17611;

DELETE FROM `waypoints` WHERE `entry` = 17621;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `point_comment`) VALUES
(17621,1,312.5911,-84.185234,1.9369955,NULL,0,'Heathen Guard'),
(17621,2,301.18335,-83.94184,1.9370384,NULL,0,'Heathen Guard'),
(17621,3,289.016,-83.993065,1.9303827,NULL,0,'Heathen Guard'),
(17621,4,279.15543,-84.08081,2.189514,NULL,0,'Heathen Guard'),
(17621,5,274.1177,-84.06761,2.3095038,NULL,0,'Heathen Guard');

DELETE FROM `smart_scripts` WHERE `entryorguid` = 17621 AND `source_type` = 0 AND `id` IN (3,4);
DELETE FROM `smart_scripts` WHERE `entryorguid` = 17622 AND `source_type` = 0 AND `id` IN (5,6);
DELETE FROM `smart_scripts` WHERE `entryorguid` = 17623 AND `source_type` = 0 AND `id` IN (5,6);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17621,0,3,0,54,0,100,0,0,0,0,0,0,53,1,17621,0,0,0,0,1,0,0,0,0,0,0,0,0,"Heathen Guard - On Just Summoned - Start Waypoint"),
(17621,0,4,0,40,0,100,0,5,17621,0,0,0,38,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Heathen Guard - On Waypoint 5 Reached - Set In Combat With Zone"),

(17622,0,5,0,54,0,100,0,0,0,0,0,0,53,1,17621,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sharpshooter Guard - On Just Summoned - Start Waypoint"),
(17622,0,6,0,40,0,100,0,5,17621,0,0,0,38,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sharpshooter Guard - On Waypoint 5 Reached - Set In Combat With Zone"),

(17623,0,5,0,54,0,100,0,0,0,0,0,0,53,1,17621,0,0,0,0,1,0,0,0,0,0,0,0,0,"Reaver Guard - On Just Summoned - Start Waypoint"),
(17623,0,6,0,40,0,100,0,5,17621,0,0,0,38,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Reaver Guard - On Waypoint 5 Reached - Set In Combat With Zone");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (30751,30738);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,30751,0,0,31,0,3,20709,0,0,0,0,"","Group 0: Spell 'Blade Dance Charge' (Effect 0) targets creature 'Blade Dance Target'"),
(13,1,30738,0,0,31,0,3,20709,0,0,0,0,"","Group 0: Spell 'Blade Dance Targeting' (Effect 0) targets creature 'Blade Dance Target'");

DELETE FROM `creature_text` WHERE `CreatureID` = 16808 AND `GroupID` = 5;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(16808,5,0,"Cowards! You'll never draw me into the shadows!",14,0,100,0,0,0,18367,0,"kargath SAY_LEASH");

DELETE FROM `creature_summon_groups` WHERE `summonerId` = 16808;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`, `Comment`) VALUES
(16808,0,0,17611,336.707,-84.0521,1.99244,3.124140,8,0,"Warchief Kargath Bladefist - Group 0 - Warchief's Portal"),

(16808,0,1,17695,287.038,-88.1788,2.06635,2.443460,7,300000,"Warchief Kargath Bladefist - Group 1 - Shattered Hand Assassin"),
(16808,0,1,17695,167.829,-86.5578,1.99496,0.890118,7,300000,"Warchief Kargath Bladefist - Group 1 - Shattered Hand Assassin"),
(16808,0,1,17695,292.149,-82.2527,1.99739,2.932150,7,300000,"Warchief Kargath Bladefist - Group 1 - Shattered Hand Assassin"),
(16808,0,1,17695,172.682,-80.6569,2.08346,5.427970,7,300000,"Warchief Kargath Bladefist - Group 1 - Shattered Hand Assassin");

UPDATE `creature_template_addon` SET `auras` = '19818' WHERE `entry` = 16808;

DELETE FROM `creature` WHERE `guid` IN (86464,86465,86466);
DELETE FROM `spawn_group` WHERE `spawnType` = 0 AND `spawnId` IN (86464,86465,86466);
