UPDATE `creature_template` SET `ScriptName` = 'npc_gunship_cannon' WHERE `entry` = 36838;
UPDATE `creature_template` SET `ScriptName` = 'npc_gunship_cannon' WHERE `entry` = 36839;
-- Cannon template
UPDATE `creature_template` SET `exp` = 2, `VehicleId` = 554, `RegenHealth` = 0, `npcflag` = 16777216, `spell1` = 69399, `spell2` = 69401 WHERE entry = 36839;
UPDATE `creature_template` SET `exp` = 2, `VehicleId` = 554, `RegenHealth` = 0, `npcflag` = 16777216, `spell1` = 70172, `spell2` = 70174 WHERE entry = 36838;
DELETE FROM `npc_spellclick_spells` WHERE npc_entry IN (36838, 36839);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`) VALUES
('36838', '46598', '1'),
('36839', '46598', '1');
DELETE FROM `creature_template_addon` WHERE `entry` IN (36838, 36839);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(36838, 0, 0, 0, 1, 0, 69470),
(36839, 0, 0, 0, 1, 0, 69470);
UPDATE `creature_template` SET `difficulty_entry_1` = '38129',`difficulty_entry_2` = '38701', `difficulty_entry_3` = '38702' WHERE `entry` =37215;
UPDATE `creature_template` SET `faction_A` = 35, `faction_H` = 35, `minlevel` = 83, `maxlevel` = 83, `unit_flags` = 4, `flags_extra` = 2, `modelid1` = 1126, `modelid2` = 11686 WHERE `entry` IN (37215, 38129, 38701, 38702, 37540, 38128, 38699, 38700);

-- Fix for Cannons
UPDATE `creature_template` SET `difficulty_entry_1`=0 WHERE `entry`=36839 LIMIT 1;
UPDATE `creature_template` SET `speed_walk`=0 ,`speed_run`=0 WHERE `entry` IN (36839,36838);
