UPDATE `creature_template` SET `dynamicflags` = 8 WHERE `entry` IN (49355,49356);
DELETE FROM `creature_addon` WHERE `guid` IN (346863,346864);
INSERT INTO `creature_addon` VALUES
(346863, 0, 0, 65544, 1, 0, NULL),
(346864, 0, 0, 65544, 1, 0, NULL);

UPDATE `creature_template` SET `ScriptName` = 'npc_eye_of_acherus' WHERE `entry` = '28511';