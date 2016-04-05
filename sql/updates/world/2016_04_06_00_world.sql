-- 
UPDATE `gameobject_template` SET `type`=6, `data3`=46961, `data5`=65000 WHERE `entry`=188187;

DELETE FROM `areatrigger_teleport` WHERE `id` IN (3654, 3650);
INSERT INTO `areatrigger_teleport` (`id`, `name`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`, `VerifiedBuild`) VALUES
(3654, "Barrens - Mor'shan Base Camp (Warsong Gulch - Horde Entrance)", 489, 1017.35, 1294.46, 343.308, 0, 0),
(3650, "Ashenvale - Silverwing Grove (Warsong Gulch - Alliance Entrance)", 489, 1448.83, 1606.72, 350.593, 0, 0);

DELETE FROM `instance_template` WHERE `map`=734;
INSERT INTO `instance_template` (`map`, `parent`, `script`, `allowMount`) VALUES (734, 0,'', 0);

DELETE FROM `lfg_dungeon_template` WHERE `dungeonId` IN (299, 310);
INSERT INTO `lfg_dungeon_template` (`dungeonId`, `name`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES
(299, "Prince Sarsarun", -9132.120117, 1599.280029, 26.848, 5.310858),
(310, "Prince Sarsarun", -9132.120117, 1599.280029, 26.848, 5.310858);

UPDATE `instance_encounters` SET `lastEncounterDungeon`=0 WHERE `entry`=793;

DELETE FROM `npc_text` WHERE `ID` IN (18618);
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `BroadcastTextID0`, `Probability0`, `em0_0`, `em0_1`, `VerifiedBuild`) VALUES
(18618, '', 'Oh, a visitor.  I don''t get many visitors out here.$B$BHungry? I''ve cooked MANY delightful things, my dear.$B$BNo, no, not the fish. Those are for when I can''t catch anything tastier, sweetling.', 54664, 1, 397, 396, 17658);

DELETE FROM `conditions` WHERE  `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=47320;

UPDATE `smart_scripts` SET `action_param1`=56332 WHERE `entryorguid`=4421 AND `id`=6 AND `source_type`=0;
UPDATE `smart_scripts` SET `action_param1`=21562 WHERE `entryorguid`=4517 AND `id`=0 AND `source_type`=0;
UPDATE `smart_scripts` SET `action_param1`=10577 WHERE `entryorguid`=4517 AND `id`=2 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11937 AND `id`=1 AND `source_type`=0;
