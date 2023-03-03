/*
**************************
*    BfaCore Reforged    *
**************************
*/

-- Fix Quest 50239 (A Choice of Allies)
DELETE FROM `creature_queststarter` WHERE (`quest` = 50239) AND (`id` IN (126301));
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES
(126301, 50239);

DELETE FROM `creature_questender` WHERE (`quest` = 50239) AND (`id` IN (126301));
INSERT INTO `creature_questender` (`id`, `quest`) VALUES
(126301, 50239);

DELETE FROM `quest_objectives` WHERE (`QuestID` = 50239);
INSERT INTO `quest_objectives`(`ID`, `QuestID`, `Type`, `Order`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `ProgressBarWeight`, `Description`, `VerifiedBuild`) VALUES (396609, 50239, 2, 1, 0, 273855, 1, 0, 0, 0, NULL, 35662);
INSERT INTO `quest_objectives`(`ID`, `QuestID`, `Type`, `Order`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `ProgressBarWeight`, `Description`, `VerifiedBuild`) VALUES (396610, 50239, 2, 2, 1, 273853, 1, 0, 0, 0, NULL, 35662);
INSERT INTO `quest_objectives`(`ID`, `QuestID`, `Type`, `Order`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `ProgressBarWeight`, `Description`, `VerifiedBuild`) VALUES (396611, 50239, 2, 3, 2, 298865, 1, 0, 0, 0, NULL, 35662);
INSERT INTO `quest_objectives`(`ID`, `QuestID`, `Type`, `Order`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `ProgressBarWeight`, `Description`, `VerifiedBuild`) VALUES (396612, 50239, 2, 4, 3, 316736, 1, 0, 0, 0, NULL, 35662);
INSERT INTO `quest_objectives`(`ID`, `QuestID`, `Type`, `Order`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `ProgressBarWeight`, `Description`, `VerifiedBuild`) VALUES (396613, 50239, 2, 5, 4, 339222, 1, 0, 0, 0, NULL, 35662);

UPDATE `gameobject_template` SET `size` = 0.5, `type` = 22 WHERE (`entry` = 316736);
UPDATE `gameobject_template` SET `type` = 22, `size` = 0.5 WHERE (`entry` = 339222);
UPDATE `gameobject_template` SET `Data0` = 0 WHERE (`entry` = 273855);
UPDATE `gameobject_template` SET `Data0` = 0 WHERE (`entry` = 273853);
UPDATE `gameobject_template` SET `Data0` = 0 WHERE (`entry` = 298865);

DELETE FROM `gameobject` WHERE (`guid` = 3440000001527);
DELETE FROM `gameobject` WHERE (`guid` = 3440000001543);
INSERT INTO `gameobject`(`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `ScriptName`, `VerifiedBuild`) VALUES (3440000001527, 316736, 0, 0, 0, '0', 0, 0, 0, -1, -8145.9, 813.306, 75.9667, 3.94896, -0, -0, -0.919619, 0.392811, 300, 255, 1, 0, '', 37623);
INSERT INTO `gameobject`(`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `ScriptName`, `VerifiedBuild`) VALUES (3440000001543, 339222, 0, 0, 0, '0', 0, 0, 0, -1, -8152.94, 829.162, 75.9667, 4.34165, -0, -0, -0.825319, 0.564666, 300, 255, 1, 0, '', 37623);


-- Fix SmartAI for Quest 27210 (Traitors Among Us)
SET @ENTRY := 23602;
DELETE FROM smart_scripts WHERE entryOrGuid = 23602 AND source_type = 0;
UPDATE creature_template SET AIName="SmartAI" WHERE entry= @ENTRY;
INSERT INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o, comment) VALUES
(@ENTRY, 0, 0, 0, 25, 0, 100, 512, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On reset (e.g. after reaching home) - Self: Reset faction"),
(@ENTRY, 0, 1, 0, 1, 0, 100, 0, 0, 1, 30000, 40000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 30 - 40 seconds (0 - 0.001s initially) [OOC] - Self: Talk 0 to invoker"),
(@ENTRY, 0, 2, 3, 62, 0, 100, 0, 8762, 0, 0, 0, 11, 42203, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On gossip action 0 from menu 8762 selected - Self: Cast spell 42203 on Action invoker"),
(@ENTRY, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 33, 23602, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On link - Action invoker: Give kill credit Deserter Agitator"),
(@ENTRY, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On link - Action invoker: Close gossip"),
(@ENTRY, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 0, 5000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On link - Self: Despawn instantly respawn in 5000 seconds"),
(@ENTRY, 0, 6, 7, 8, 0, 100, 512, 42219, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On spell 42219 hit  - Self: Look at Action invoker"),
(@ENTRY, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On link - Action invoker: Talk 1 to invoker"),
(@ENTRY, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 87, 2360200, 2360201, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On link - Self: Call random timed action list: 2360200, 2360201, 0, 0, 0, 0");


-- Fix SmartAI for Quest 27239 (Survey Alcaz Island)
SET @ENTRY := 23704;
DELETE FROM smart_scripts WHERE entryOrGuid = 23704 AND source_type = 0;
UPDATE creature_template SET AIName="SmartAI" WHERE entry= @ENTRY;
INSERT INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o, comment) VALUES
(@ENTRY, 0, 0, 1, 62, 0, 100, 0, 8782, 0, 0, 0, 85, 42316, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On gossip action 0 from menu 8782 selected -  Action invoker: Cast spell 42295 on self"),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On link - Action invoker: Close gossip");
-- Add Conditions Gossip can only see on Quest
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 15) AND (`SourceGroup` = 8782) AND (`SourceEntry` = 0) AND (`SourceId` = 0) AND (`ElseGroup` = 0) AND (`ConditionTypeOrReference` = 9) AND (`ConditionTarget` = 0) AND (`ConditionValue1` = 27239) AND (`ConditionValue2` = 0) AND (`ConditionValue3` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 8782, 0, 0, 0, 9, 0, 27239, 0, 0, 0, 0, 0, '', 'gossip only can sey you have quest 27239');
