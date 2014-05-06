-- Fix Q I'm Not Dead Yet! (13229 / 13221) by Rohlik
UPDATE `creature_template` SET `AIName` = 'SmartAI', `InhabitType` = 1 WHERE `entry` = 31279;
UPDATE `quest_template` SET `SpecialFlags` = 2 WHERE `Id` IN (13221, 13229);

DELETE FROM `db_script_string` WHERE `entry` IN (2000000507,2000000508);
DELETE FROM `waypoint_data` where id=3127900; -- We delete old WP data from DB
DELETE FROM `waypoint_scripts` WHERE id=31279;

-- Text for NPC Father Kamaros
DELETE from `creature_text` where `entry`=31279 AND `groupid` IN (1, 2, 3, 4);
INSERT INTO `creature_text` (`entry`, `groupid`, `text`, `type`, `probability`, `comment`) VALUES
(31279, 1, 'The Light''s blessing be upon you for aiding me in my time of need, $n.', 12, 100, 'Father Kamaros'),
(31279, 2, 'I''ve had my fill of this place. Let us depart.', 12, 100, 'Father Kamaros'),
(31279, 3, 'You must tell my brothers that live.', 12, 100, 'Father Kamaros'),
(31279, 4, 'I have you to thank for my life. I will return to my comrades and spread word of your bravery. Fight the Scourge with all the strength you can muster, and we will be by your side.', 12, 100, 'Father Kamaros');

-- SAI
DELETE FROM `smart_scripts` WHERE (`entryorguid`=31279 AND `source_type`=0);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(31279, 0, 0, 0, 4, 0, 100, 1, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Set Phase 1 on Aggro'),
(31279, 0, 1, 0, 4, 1, 100, 1, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stop Moving on Aggro'),
(31279, 0, 2, 0, 4, 1, 100, 1, 0, 0, 0, 0, 11, 25054, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cast bolt on Aggro'),
(31279, 0, 3, 0, 9, 1, 100, 0, 0, 40, 3400, 4700, 11, 25054, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cast bolt'),
(31279, 0, 4, 0, 9, 1, 100, 0, 40, 100, 0, 0, 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Start Moving when not in bolt Range'),
(31279, 0, 5, 0, 9, 1, 100, 0, 10, 15, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stop Moving at 15 Yards'),
(31279, 0, 6, 0, 9, 1, 100, 0, 0, 40, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stop Moving when in bolt Range'),
(31279, 0, 7, 0, 3, 1, 100, 0, 0, 15, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Set Phase 2 at 15% Mana'),
(31279, 0, 8, 0, 3, 2, 100, 0, 0, 15, 0, 0, 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Start Moving at 15% Mana'),
(31279, 0, 9, 0, 3, 2, 100, 0, 30, 100, 100, 100, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Set Phase 1 When Mana is above 30%'),
(31279, 0, 11, 0, 0, 1, 100, 0, 5000, 6200, 11700, 15600, 11, 17146, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Cast Shadow Word: Pain'),
(31279, 0, 12, 0, 2, 0, 100, 1, 0, 50, 0, 0, 11, 32595, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cast Power Word: Shield at 50% HP'),
(31279, 0, 13, 14, 19, 0, 100, 0, 0, 0, 0, 0, 75, 58921, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Father Kamaros - On accept Q - Cast Power Word Fortitude'),
(31279, 0, 14, 15, 61, 0, 100, 0, 0, 0, 0, 0, 1, 1, 4000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Father Kamaros - On accept Q - Start talking'),
(31279, 0, 15, 0, 52, 0, 100, 0, 1, 31279, 0, 0, 1, 2, 1000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Father Kamaros - On accept Q - After 4 sec start talking again'),
(31279, 0, 16, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 2, 1000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Father Kamaros - On accept Q - After 4 sec start talking again'),
(31279, 0, 17, 0, 52, 0, 100, 0, 2, 31279, 0, 0, 53, 0, 31279, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 'Father Kamaros - After 5 sec - WP load'),
(31279, 0, 18, 0, 40, 0, 100, 0, 13, 0, 0, 0, 1, 3, 2900, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Father Kamaros - On last WP point - Say something'),
(31279, 0, 19, 0, 52, 0, 100, 0, 3, 31279, 0, 0, 1, 4, 5000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Father Kamaros - On last WP point - Say something 2'),
(31279, 0, 20, 0, 52, 0, 100, 0, 4, 31279, 0, 0, 15, 13229, 0, 0, 0, 0, 0, 18, 30, 0, 0, 0, 0, 0, 0, 'Father Kamaros - On last WP point - Q complete(horde)'),
(31279, 0, 21, 0, 52, 0, 100, 0, 4, 31279, 0, 0, 15, 13221, 0, 0, 0, 0, 0, 18, 30, 0, 0, 0, 0, 0, 0, 'Father Kamaros - On last WP point - Q complete(ali)'),
(31279, 0, 22, 0, 52, 0, 100, 0, 4, 31279, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Father Kamaros - after final talking - despawn');

-- WP for NPC Father Kamaros
DELETE from `waypoints` where `entry`=31279;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(31279, 1,  6716.76, 3436.7,  682.197, 'Q I''m Not Dead Yet!'),
(31279, 2,  6724.09, 3433.56, 682.197, 'Q I''m Not Dead Yet!'),
(31279, 3,  6734.95, 3435.7,  681.87, 'Q I''m Not Dead Yet!'),
(31279, 4,  6766.36, 3464.42, 673.201, 'Q I''m Not Dead Yet!'),
(31279, 5,  6782.48, 3478.07, 674.097, 'Q I''m Not Dead Yet!'),
(31279, 6,  6789.64, 3484.14, 676.423, 'Q I''m Not Dead Yet!'),
(31279, 7,  6815.31, 3483.01, 685.829, 'Q I''m Not Dead Yet!'),
(31279, 9,  6875.41, 3479.14, 694.799, 'Q I''m Not Dead Yet!'),
(31279, 10, 6946.3,  3477.29, 708.832, 'Q I''m Not Dead Yet!'),
(31279, 11, 6980.65, 3468.12, 710.813, 'Q I''m Not Dead Yet!'),
(31279, 12, 7008.43, 3458.64, 696.751, 'Q I''m Not Dead Yet!'),
(31279, 13, 7042.92, 3438.07, 695.543, 'Q I''m Not Dead Yet!');
