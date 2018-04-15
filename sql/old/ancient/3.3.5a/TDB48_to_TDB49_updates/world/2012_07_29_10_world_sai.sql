-- [Q] Measuring Warp Energies

DELETE FROM `creature_ai_scripts` WHERE `creature_id` IN(20333,20336,20337,20338);
UPDATE `creature_template` SET AIName='SmartAI' WHERE `entry` IN (20333,20336,20337,20338);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (20333,20336,20337,20338);
INSERT INTO `smart_scripts` VALUES
(20333,0,0,0,8,0,100,0,35113,0,0,0,33,20333,0,0,0,0,0,7,0,0,0,0,0,0,0,"Northern Pipe Credit Marker - Spellhit - Credit"),
(20336,0,0,0,8,0,100,0,35113,0,0,0,33,20336,0,0,0,0,0,7,0,0,0,0,0,0,0,"Eastern Pipe Credit Marker - Spellhit - Credit"),
(20337,0,0,0,8,0,100,0,35113,0,0,0,33,20337,0,0,0,0,0,7,0,0,0,0,0,0,0,"Southern Pipe Credit Marker - Spellhit - Credit"),
(20338,0,0,0,8,0,100,0,35113,0,0,0,33,20338,0,0,0,0,0,7,0,0,0,0,0,0,0,"Western Pipe Credit Marker - Spellhit - Credit");

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=35113;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 35113, 0, 0, 31, 0, 3, 20333, 0, 0, 0, '', "Spell Search NPC 20333"),
(13, 1, 35113, 0, 1, 31, 0, 3, 20336, 0, 0, 0, '', "Spell Search NPC 20336"),
(13, 1, 35113, 0, 2, 31, 0, 3, 20337, 0, 0, 0, '', "Spell Search NPC 20337"),
(13, 1, 35113, 0, 3, 31, 0, 3, 20338, 0, 0, 0, '', "Spell Search NPC 20338");

UPDATE `creature` SET `position_x`=3214.92, `position_y`=4065.25, `position_z`=106.16 WHERE `id`=20333;
UPDATE `creature` SET `position_x`=2755.55, `position_y`=3863.32, `position_z`=142.27 WHERE `id`=20336;
UPDATE `creature` SET `position_x`=2819.01, `position_y`=4351.10, `position_z`=144.97 WHERE `id`=20337;
UPDATE `creature` SET `position_x`=2947.31, `position_y`=4327.47, `position_z`=154.02 WHERE `id`=20338;
