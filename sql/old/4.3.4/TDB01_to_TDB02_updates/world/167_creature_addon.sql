DELETE FROM `creature_addon` WHERE `guid` IN (218331, 218332, 218333, 218334);
INSERT INTO `creature_addon` (`guid`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(218331, 0, 0x0, 0x1, 425, ''), -- Temple Shadowlancer
(218332, 0, 0x0, 0x1, 375, ''), -- Temple Runecaster
(218333, 0, 0x0, 0x1, 376, ''), -- Temple Swiftstalker
(218334, 0, 0x0, 0x1, 474, ''); -- Temple Fireshaper
