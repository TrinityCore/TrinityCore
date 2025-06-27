SET @CGUID       := 12460;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`=32800;

UPDATE `quest_template_addon` SET `PrevQuestID`=13117 WHERE  `ID`IN(13221,13229);
UPDATE `quest_template_addon` SET `PrevQuestID`=13144 WHERE  `ID`IN(13481,13482);

UPDATE `quest_template_addon` SET `ExclusiveGroup`=13221 WHERE  `ID`IN(13221,13482);
UPDATE `quest_template_addon` SET `ExclusiveGroup`=13229 WHERE  `ID`IN(13229,13481);

DELETE FROM `creature` WHERE `id` =32800;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 32800, 571, 1, 64, 6717.831, 3452.021, 683.7534, 4.625123, 120, 0, 0); -- 32800 (Area: 4531) (Auras: 32595 - 32595) 

DELETE FROM `creature_template_addon` WHERE `entry`=32800;
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(32800, 0, 0x8, 0x1, '32595'); -- 32800 - 32595

DELETE FROM `smart_scripts` WHERE `entryorguid`=32800 AND `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(32800, 0, 0, 0, 4, 0, 100, 1, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Father Kamaros - On Aggro - Set Event Phase 1 (No Repeat)'),
(32800, 0, 1, 0, 4, 1, 100, 1, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Father Kamaros - On Aggro - Disable Combat Movement (No Repeat)'),
(32800, 0, 2, 0, 4, 1, 100, 1, 0, 0, 0, 0, 11, 25054, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Father Kamaros - On Aggro - Cast \'Holy Smite\' (No Repeat)'),
(32800, 0, 3, 0, 9, 1, 100, 0, 0, 40, 3400, 4700, 11, 25054, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Father Kamaros - Within 0-40 Range - Cast \'Holy Smite\' (No Repeat)'),
(32800, 0, 4, 0, 9, 1, 100, 0, 40, 100, 0, 0, 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Father Kamaros - Within 40-100 Range - Enable Combat Movement (No Repeat)'),
(32800, 0, 5, 0, 9, 1, 100, 0, 10, 15, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Father Kamaros - Within 10-15 Range - Disable Combat Movement (No Repeat)'),
(32800, 0, 6, 0, 9, 1, 100, 0, 0, 40, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Father Kamaros - Within 0-40 Range - Disable Combat Movement (No Repeat)'),
(32800, 0, 7, 0, 3, 1, 100, 0, 0, 15, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Father Kamaros - Between 0-15% Mana - Set Event Phase 2 (No Repeat)'),
(32800, 0, 8, 0, 3, 2, 100, 0, 0, 15, 0, 0, 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Father Kamaros - Between 0-15% Mana - Enable Combat Movement (No Repeat)'),
(32800, 0, 9, 0, 3, 2, 100, 0, 30, 100, 100, 100, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Father Kamaros - Between 30-100% Mana - Set Event Phase 1 (No Repeat)'),
(32800, 0, 11, 0, 0, 1, 100, 0, 5000, 6200, 11700, 15600, 11, 17146, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Father Kamaros - In Combat - Cast \'Shadow Word: Pain\' (No Repeat)'),
(32800, 0, 12, 0, 2, 0, 100, 1, 0, 50, 0, 0, 11, 32595, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Father Kamaros - Between 0-50% Health - Cast \'Power Word: Shield\' (No Repeat)'),
(32800, 0, 13, 14, 19, 0, 100, 0, 0, 0, 0, 0, 75, 58921, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Father Kamaros - On Quest Taken - Add Aura \'Power Word: Fortitude\''),
(32800, 0, 14, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 1, 4000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Father Kamaros - On Quest Taken - Say Line 1'),
(32800, 0, 15, 16, 52, 0, 100, 0, 1, 32800, 0, 0, 1, 2, 1000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Father Kamaros - On Text 1 Over - Say Line 2'),
(32800, 0, 16, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 2, 1000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Father Kamaros - On Quest Taken - Say Line 2'),
(32800, 0, 17, 0, 52, 0, 100, 0, 2, 32800, 0, 0, 53, 0, 31279, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 'Father Kamaros - On Text 2 Over - Start Waypoint'),
(32800, 0, 18, 0, 40, 0, 100, 0, 12, 0, 0, 0, 1, 3, 2900, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Father Kamaros - On Waypoint 13 Reached - Say Line 3'),
(32800, 0, 19, 0, 52, 0, 100, 0, 3, 32800, 0, 0, 1, 4, 5000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Father Kamaros - On Text 3 Over - Say Line 4'),
(32800, 0, 20, 0, 52, 0, 100, 0, 4, 32800, 0, 0, 15, 13481, 0, 0, 0, 0, 0, 18, 30, 0, 0, 0, 0, 0, 0, 'Father Kamaros - On Text 4 Over - Quest Credit Lets Get Out of Here!'),
(32800, 0, 21, 0, 52, 0, 100, 0, 4, 32800, 0, 0, 15, 13482, 0, 0, 0, 0, 0, 18, 30, 0, 0, 0, 0, 0, 0, 'Father Kamaros - On Text 4 Over - Quest Credit Lets Get Out of Here!'),
(32800, 0, 22, 0, 52, 0, 100, 0, 4, 32800, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Father Kamaros - On Text 4 Over - Despawn In 1000 ms');

DELETE FROM `creature_text` WHERE `entry`=32800;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(32800, 1, 0, 'The Light''s blessing be upon you for aiding me in my time of need, $N.', 12, 0, 100, 0, 0, 0, 31941, 'Father Kamaros to Player'),
(32800, 2, 0, 'I''ve had my fill of this place. Let us depart.', 12, 0, 100, 1, 0, 0, 31942, 'Father Kamaros to Player'),
(32800, 3, 0, 'You must tell my brothers that I live.', 12, 0, 100, 1, 0, 0, 31944, 'Father Kamaros to Player'),
(32800, 4, 0, 'I have you to thank for my life. I will return to my comrades and spread word of your bravery. Fight the Scourge with all the strength you can muster, and we will be by your side.', 12, 0, 100, 2, 0, 0, 31943, 'Father Kamaros to Player');
