-- Leria Nightwind(61837) should be sitting in a high chair state.

DELETE FROM `creature_addon` WHERE `guid` = '403564' ;

INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES ('403564', '0', '0', '0', '0', '426', '0');
