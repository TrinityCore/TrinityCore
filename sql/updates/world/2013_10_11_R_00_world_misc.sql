-- Grauf wird durch Skript gespawnt
DELETE FROM `creature` WHERE `guid`=126052;
DELETE FROM `linked_respawn` WHERE `guid`=126052;
DELETE FROM `creature_addon` WHERE `guid`=126052;

-- Skript-Name für Grauf
UPDATE `creature_template` SET `ScriptName` = 'npc_grauf' WHERE `entry` = 26893;

-- Text für Grauf
DELETE FROM `creature_text` WHERE `entry`=26693 AND `groupid`=2 AND `type`=41;
DELETE FROM `creature_text` WHERE `entry`=26693 AND `groupid`=4 AND `type`=41;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(26893, 2, 0, '%s in within range of the harpoon launchers!', 41, 0, 100, 0, 0, 0, 'Grauf EMOTE_RANGE'),
(26893, 1, 0, '%s takes a deep breath.', 41, 0, 100, 0, 0, 0, 'Grauf EMOTE_BREATH');

DELETE FROM `spell_target_position` WHERE `id` = 61790;
INSERT INTO `spell_target_position` (`id`, `effIndex`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES 
('61790', '0', '575', '476.799', '-511.167', '104.723', '0');

DELETE FROM `spelldifficulty_dbc` WHERE `spellid0` = 50228;
INSERT INTO `spelldifficulty_dbc` (`id`, `spellid0`, `spellid1`, `spellid2`, `spellid3`) VALUES 
('50228', '50228', '59322', '0', '0');

