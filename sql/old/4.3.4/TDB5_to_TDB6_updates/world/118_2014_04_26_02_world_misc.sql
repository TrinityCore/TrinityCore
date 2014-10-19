SET @CGUID := 1011;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+12;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 29, 607, 3, 193, 841.921, -134.194, 196.838, 6.23082, 7200, 0, 0),

(@CGUID+1, 15214, 607, 3, 193, 1230.2, -67.941, 83.7716, 4.08407, 7200, 0, 0),
(@CGUID+2, 15214, 607, 3, 193, 1611.57, 73.0032, 8.14356, 2.05949, 7200, 0, 0),
(@CGUID+3, 15214, 607, 3, 193, 1623.94, -96.5658, 12.5011, 4.4855, 7200, 0, 0),

(@CGUID+4, 22515, 607, 3, 193, 1351.07, -87.6424, 43.4303, 0.191986, 7200, 0, 0),
(@CGUID+5, 22515, 607, 3, 193, 1357.35, -37.702, 46.4816, 5.3058, 7200, 0, 0),
(@CGUID+6, 22515, 607, 3, 193, 1363.41, -85.741, 48.9664, 0.593412, 7200, 0, 0),
(@CGUID+7, 22515, 607, 3, 193, 1364.28, -34.382, 42.9869, 4.7822, 7200, 0, 0),

(@CGUID+8, 23472, 607, 3, 193, 1043.52, -87.8507, 87.197, 2.96706, 7200, 0, 0),
(@CGUID+9, 23472, 607, 3, 193, 1193.76, 69.9405, 58.1295, 2.49582, 7200, 0, 0),
(@CGUID+10, 23472, 607, 3, 193, 1227.89, -235.458, 60.1112, 3.40339, 7200, 0, 0),
(@CGUID+11, 23472, 607, 3, 193, 1389.06, 102.941, 34.5742, 2.16421, 7200, 0, 0),
(@CGUID+12, 23472, 607, 3, 193, 1441.08, -240.594, 35.3471, 4.03171, 7200, 0, 0);


DELETE FROM `creature_text` WHERE `entry` IN (29, 29260, 29262, 22515);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(29, 1, 0, 'Let the battle for the Strand of the Ancients begin!', 41, 0, 100, 0, 0, 0, 'Kanrethad', 28844),
(29, 2, 0, 'Round 1 - Finished!', 41, 0, 100, 0, 0, 0, 'Kanrethad', 28989),

(29260, 1, 0, 'Sparklight''s vehicle emporium is open for business!', 14, 0, 100, 0, 0, 0, 'Rigger Sparklight', 30230),
(29262, 1, 0, 'Rigspark''s vehicle shop is open for business!', 14, 0, 100, 0, 0, 0, 'Gorgril Rigspark', 30229),

(22515, 1, 0, 'The Gate of the Blue Sapphire is under attack!', 41, 0, 100, 0, 0, 0, 'World Trigger - SOA - The Gate of the Blue Sapphire is under attack', 29296),
(22515, 2, 0, 'The Gate of the Green Emerald is under attack!', 41, 0, 100, 0, 0, 0, 'World Trigger - SOA - The Gate of the Green Emerald is under attack', 29297),
(22515, 3, 0, 'The Gate of the Red Sun is under attack!', 41, 0, 100, 0, 0, 0, 'World Trigger - SOA - The Gate of the Red Sun is under attack', 29298),
(22515, 4, 0, 'The Gate of the Purple Amethyst is under attack!', 41, 0, 100, 0, 0, 0, 'World Trigger - SOA - The Gate of the Purple Amethyst is under attack', 29299),
(22515, 5, 0, 'The Gate of the Yellow Moon is under attack!', 41, 0, 100, 0, 0, 0, 'World Trigger - SOA - The Gate of the Yellow Moon is under attack', 29300),

(22515, 6, 0, 'The Gate of the Yellow Moon was destroyed!', 41, 0, 100, 0, 0, 0, 'World Trigger - SOA - The Gate of the Yellow Moon was destroyed', 29304),
(22515, 7, 0, 'The Gate of the Purple Amethyst was destroyed!', 41, 0, 100, 0, 0, 0, 'World Trigger - SOA - The Gate of the Purple Amethyst was destroyed', 29305),
(22515, 8, 0, 'The Gate of the Red Sun was destroyed!', 41, 0, 100, 0, 0, 0, 'World Trigger - SOA - The Gate of the Red Sun was destroyed', 29306),
(22515, 9, 0, 'The Gate of the Green Emerald was destroyed!', 41, 0, 100, 0, 0, 0, 'World Trigger - SOA - The Gate of the Green Emerald was destroyed', 29307),
(22515, 10, 0, 'The Gate of the Blue Sapphire was destroyed!', 41, 0, 100, 0, 0, 0, 'World Trigger - SOA - The Gate of the Blue Sapphire was destroyed', 29308),

(22515, 11, 0, 'The Eastern Graveyard has been captured by the Alliance!', 41, 0, 100, 0, 0, 8212, 'World Trigger - SOA - The Eastern Graveyard has been captured by the Alliance', 29925),
(22515, 12, 0, 'The Western Graveyard has been captured by the Alliance!', 41, 0, 100, 0, 0, 8212, 'World Trigger - SOA - The Western Graveyard has been captured by the Alliance', 29926),
(22515, 13, 0, 'The Southern Graveyard has been captured by the Alliance!', 41, 0, 100, 0, 0, 8212, 'World Trigger - SOA - The Southern Graveyard has been captured by the Alliance', 29927),

(22515, 14, 0, 'The Eastern Graveyard has been captured by the Horde!', 41, 0, 100, 0, 0, 8174, 'World Trigger - SOA - The Eastern Graveyard has been captured by the Horde', 29928),
(22515, 15, 0, 'The Western Graveyard has been captured by the Horde!', 41, 0, 100, 0, 0, 8174, 'World Trigger - SOA - The Western Graveyard has been captured by the Horde', 29929),
(22515, 16, 0, 'The Southern Graveyard has been captured by the Horde!', 41, 0, 100, 0, 0, 8174, 'World Trigger - SOA - The Southern Graveyard has been captured by the Horde', 29930),

(22515, 17, 0, 'The relic chamber is under attack!', 41, 0, 100, 0, 0, 0, 'World Trigger - SOA - The relic chamber is under attack', 33072),
(22515, 18, 0, 'The chamber has been breached! The titan relic is vulnerable!', 41, 0, 100, 0, 0, 0, 'World Trigger - SOA - The chamber has been breached', 33073);

DELETE FROM `spell_area` WHERE `spell` IN (60027, 60028);
INSERT INTO `spell_area` (`spell`,`area`,`autocast`) VALUES
(60027, 4384, 1),
(60028, 4384, 1);

DELETE FROM `trinity_string` WHERE (`entry` BETWEEN 10059 AND 10062) OR (`entry` BETWEEN 10067 and 10073);
