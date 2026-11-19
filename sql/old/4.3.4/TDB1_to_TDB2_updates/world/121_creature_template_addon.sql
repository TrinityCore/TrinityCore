UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry`=42716;
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry`=40350;

DELETE FROM `creature_template_addon` WHERE `entry` IN (42885, 42801, 42681, 42682, 42809, 43681, 43082, 42684, 42716);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(42885, 0, 0x0, 0x1, ''), -- Twilight Saboteur
(42801, 0, 0x0, 0x1, ''), -- Mor'norokk the Hateful
(42681, 0, 0x0, 0x1, '29266'), -- Slain Crew Member - Permanent Feign Death
(42682, 0, 0x0, 0x1, '29266'), -- Slain Crew Member - Permanent Feign Death
(42809, 0, 0x0, 0x1, ''), -- Generic Trigger Vehicle LAB
(43681, 0, 0x0, 0x1, '80661'), -- Moody's Blood - Permanent Feign Death
(43082, 0, 0x0, 0x1, '80523 81742'), -- First Mate Moody - Drunk Driving, Generic Quest Invisibility Detection 14
(42684, 0, 0x0, 0x1, ''), -- Stormcaller Mylra
(42716, 0, 0x3000000, 0x1, ''); -- Stormbeak
