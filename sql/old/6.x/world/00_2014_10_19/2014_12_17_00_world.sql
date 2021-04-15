--
UPDATE `creature_text` SET `TextRange` = 3 WHERE `entry` = 15990 AND `groupid` IN (0, 2, 4);
DELETE FROM `creature_text` WHERE `entry` = 15990 AND `groupid` IN (13, 20);
DELETE FROM `creature_text` WHERE `entry` = 16980 AND `groupid` IN (1, 2, 3);
DELETE FROM `creature_text` WHERE `entry` = 15384 AND `groupid` = 0;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `TextRange`, `comment`) VALUES
(15990, 20, 0, 'Come, heroes... By the will of the Lich King, you shall be destroyed.', 14, 0, 100, 0, 0, 0, 12993, 3, 'Kel''Thuzad SAY_DIALOGUE_SAPPHIRON_KELTHUZAD4'),
(15990, 13, 0, 'Kel''Thuzad strikes!', 41, 0, 100, 0, 0, 0, 32803, 0, 'Kel''Thuzad EMOTE_PHASE_TWO'),
(16980, 1, 0, 'Soon we will eradicate the Alliance and Horde. Then the rest of Azeroth will fall before the might of my army.', 14, 0, 100, 0, 0, 14768, 12988, 3, 'The Lich King SAY_DIALOGUE_SAPPHIRON_LICHKING'),
(16980, 2, 0, 'Invaders... here?! DESTROY them, Kel''Thuzad! Naxxramas must not fall!', 14, 0, 100, 0, 0, 14769, 12989, 3, 'The Lich King SAY_DIALOGUE_SAPPHIRON_LICHKING2'),
(16980, 3, 0, 'Very well. Warriors of the frozen wastes, rise up! I command you to fight, kill and die for your master! Let none survive!', 14, 0, 100, 0, 0, 14770, 12994, 3, 'The Lich King SAY_ANSWER_REQUEST'),
(15384, 0, 0, 'A Guardian of Icecrown enters the fight!', 41, 0, 100, 0, 0, 0, 32804, 0, 'OLDWorld Trigger (DO NOT DELETE)');

-- Spawn some missing triggers and the Lich King dummy. Triggers are used to emote when a Guardian of Icecrown is spawned, currently not implemented.
SET @CGUID = 75082;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+5;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 16980, 533, 3, 1, 3762.382, -5115.862, 143.9382, 0.1919862, 7200, 0, 0), -- 16980 (Area: -1)
(@CGUID+1, 15384, 533, 3, 1, 3759.62, -5172.786, 143.8345, 5.148721, 7200, 0, 0), -- 15384 (Area: -1)
(@CGUID+2, 15384, 533, 3, 1, 3716.097, -5106.208, 141.373, 4.939282, 7200, 0, 0), -- 15384 (Area: -1)
(@CGUID+3, 15384, 533, 3, 1, 3777.213, -5066.177, 143.6412, 1.53589, 7200, 0, 0), -- 15384 (Area: -1)
(@CGUID+4, 15384, 533, 3, 1, 3732.598, -5028.03, 144.0342, 5.951573, 7200, 0, 0), -- 15384 (Area: -1)
(@CGUID+5, 15384, 533, 3, 1, 3700.7, -5182.372, 143.9172, 3.525565, 7200, 0, 0); -- 15384 (Area: -1)
