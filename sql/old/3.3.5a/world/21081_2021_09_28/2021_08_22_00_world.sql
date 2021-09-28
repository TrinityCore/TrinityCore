-- Do not override flags if same value is already used in proto
UPDATE `creature` SET `unit_flags` = 0 WHERE `guid` IN (40134,43489,43490,79288,79291,116594,132313);

-- 23666,23667,23670
UPDATE `creature` SET `unit_flags` = `unit_flags` &~ (536870912|262144) WHERE `id` IN (23666,23667,23670);

-- Warsong Battleguard
UPDATE `creature_addon` SET `bytes1` = 0, `bytes2` = 1 WHERE `guid` IN (110370,110378);
UPDATE `creature` SET `unit_flags` = 33536, `dynamicflags` = 0 WHERE `guid` IN (110369,110370,110371,110378,110379,110380,110381,110382,110383,110384,110386,110389,110390) AND `id` = 25242;

-- Warsong Marksman
UPDATE `creature_addon` SET `bytes2` = 1 WHERE `guid` IN (110540,110541,110544,110545,110546,110547,110551,110552,110553,110554);
UPDATE `creature` SET `unit_flags` = 33536 WHERE `guid` IN (110540,110541,110544,110545,110546,110547,110551,110552,110553,110554) AND `id` = 25244;

-- Marsh Caribou
UPDATE `creature` SET `unit_flags` = `unit_flags` &~ (536870912|262144) WHERE `id` = 25680;

--
UPDATE `creature` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `id` IN (31098,31094,28610,28939,28940,28941,28942);
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144) WHERE `entry` = 31094;

-- Ruby Keeper
UPDATE `creature_template` SET `unit_flags` = 0 WHERE `entry` = 27530;
UPDATE `creature` SET `unit_flags` = 0, `dynamicflags` = 0 WHERE `guid` IN (48254,48256,48257,108311,108312,108315,108316,108317,108318) AND `id` = 27530;
UPDATE `creature_template_addon` SET `bytes2` = 1, `auras` = '49132 55795 61204' WHERE `entry` = 27530;

DELETE FROM `creature_addon` WHERE `guid` IN (48254,48256,48257,108311,108312,108315,108316,108317,108318);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(48254,0,0,50331648,1,0,3,'49132 55795 61204'),
(48256,0,0,50331648,1,0,3,'49132 55795 61204'),
(48257,0,0,50331648,1,0,3,'49132 55795 61204'),
(108311,0,0,50331648,1,0,3,'49132 55795 61204'),
(108312,0,0,50331648,1,0,3,'49132 55795 61204'),
(108315,0,0,50331648,1,0,3,'49132 55795 61204'),
(108316,0,0,50331648,1,0,3,'49132 55795 61204'),
(108317,0,0,50331648,1,0,3,'49132 55795 61204'),
(108318,0,0,50331648,1,0,3,'49132 55795 61204');

-- Servant of Freya
-- No idea which auras they uses, it's last case and I've had enough, creatures without aura can be identified later by remaining flags
UPDATE `creature` SET `unit_flags` = `unit_flags` &~ 536870912 WHERE `id` = 28320;

-- Should apply same set of flags
UPDATE `spell_script_names` SET `ScriptName` = 'spell_gen_feign_death_all_flags' WHERE `spell_id` = 55795 AND `ScriptName` = 'spell_falling_dragon_feign_death';
