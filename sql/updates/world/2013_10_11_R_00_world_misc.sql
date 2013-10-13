DELETE FROM `creature` WHERE `guid`=126052;
DELETE FROM `linked_respawn` WHERE `guid`=126052;
DELETE FROM `creature_addon` WHERE `guid`=126052;

UPDATE `creature_template` SET `ScriptName` = 'npc_grauf' WHERE `entry` = 26893;

DELETE FROM `creature_text` WHERE `entry`=26693 AND `groupid`=2 AND `type`=41;
DELETE FROM `creature_text` WHERE `entry`=26693 AND `groupid`=4 AND `type`=41;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(26893, 2, 0, '%s in within range of the harpoon launchers!', 41, 0, 100, 0, 0, 0, 'Grauf EMOTE_RANGE');

INSERT INTO `world`.`spell_target_position` (`id`, `effIndex`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES 
('61790', '0', '575', '480.84', '-511.95', '104.72', '2.71');