-- 
DELETE FROM `creature_template_addon` WHERE `entry` IN (30382,30383);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(30382, 0, 0, 0, 0, 0, '54500'),
(30383, 0, 0, 0, 0, 0, '54500');

DELETE FROM `spell_area` WHERE `spell`=56582 AND `area`=4431;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES
(56582, 4431, 12880, 12973, 0, 0, 2, 1, 74, 1);
