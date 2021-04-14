DELETE FROM `creature_text` WHERE `entry` IN(27210,27951,27202,27203,27246);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(27210, 0, 0, 'Now I''ll show you the REAL power of the Onslaught!', 12, 0, 100, 0, 0, 14192, 'High General Abbendis',27593),
(27951, 0, 0, 'Kill them Abbendis! Do not fail me!', 14, 0, 100, 25, 0, 14198, 'Admiral Barean Westwind',27354),
(27951, 1, 0, 'The grand admiral studies you a moment through narrowed eyes.', 16, 0, 100, 0, 0, 0, 'Admiral Barean Westwind',27355),
(27951, 2, 0, 'You served your purpose.', 12, 0, 100, 0, 0, 14199, 'Admiral Barean Westwind',27357),
(27951, 3, 0, 'I will see you in Icecrown, weakling... if you live that long!', 12, 0, 100, 0, 0, 14200, 'Admiral Barean Westwind',27358),
(27203, 0, 0, 'Be purified by steel!', 12, 0, 100, 0, 0, 0, 'Onslaught Footman',26404),
(27203, 0, 1, 'By the Light!', 12, 0, 100, 0, 0, 0, 'Onslaught Footman',26403),
(27203, 0, 2, 'In the name of the Light!', 12, 0, 100, 0, 0, 0, 'Onslaught Footman',26402),
(27203, 0, 3, 'You will be cleansed!', 12, 0, 100, 0, 0, 0, 'Onslaught Footman',26401),
(27202, 0, 0, 'Abbendis will see you purged!', 12, 0, 100, 0, 0, 0, 'Onslaught Raven Priest',26399),
(27202, 0, 1, 'You are impure!', 12, 0, 100, 0, 0, 0, 'Onslaught Raven Priest',26393),
(27202, 0, 2, 'Gah! What are you doing?', 12, 0, 100, 5, 0, 7256, 'Onslaught Raven Priest',26637),
(27202, 1, 0, 'I sense the taint of this land in you, footman.  Report to the Bishop before the start of your next shift.', 12, 0, 100, 0, 0, 0, 'Onslaught Raven Priest',26256),
(27202, 1, 1, 'Your protection is strong, child.  Continue your work.', 12, 0, 100, 0, 0, 0, 'Onslaught Raven Priest',26390),
(27202, 1, 2, 'The Grand Admiral himself has come to see to our dedication.  If I see you slacking on your post again, I will gut you myself.', 12, 0, 100, 0, 0, 0, 'Onslaught Raven Priest',26655),
(27202, 1, 3, 'You require the Bishop''s blessing.  Go to him soon.', 12, 0, 100, 0, 0, 0, 'Onslaught Raven Priest',26391),
(27202, 2, 0, 'HELP! HELP! THIS $g MAN : WOMAN; HAS STOLEN MY IMAGE!', 12, 0, 100, 0, 0, 0, 'Onslaught Raven Priest',26543),
(27246, 0, 0, 'It is good that you have come my child.  The Light''s protection has worn thin on you.', 12, 0, 100, 0, 0, 0, 'Bishop Street',26271),
(27246, 1, 0, 'It is done.  Serve the Light well.', 12, 0, 100, 0, 0, 0, 'Bishop Street',26272),
(27246, 2, 0, 'How dare you interrupt our righteous work?!', 12, 0, 100, 0, 0, 0, 'Bishop Street',26405);

UPDATE `creature_template` SET `unit_flags`=32768 WHERE  `entry`=27951;

UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` =27951;
DELETE FROM `smart_scripts` WHERE `entryorguid` =27951 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` =27210 AND `source_type`=0 AND `id`>2;
DELETE FROM `smart_scripts` WHERE `entryorguid` =27203 AND `source_type`=0 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid` =27202 AND `source_type`=0 AND `id`>13;
DELETE FROM `smart_scripts` WHERE `entryorguid` =27246 AND `source_type`=0 AND `id`>10;

UPDATE `smart_scripts` SET `action_type`=1, `action_param1`=2,`target_type`=7, `comment`='Onslaught Raven Priest - On Spellhit \'Banshee\'s Magic Mirror\' - Say (No Repeat)' WHERE  `entryorguid`=27202 AND `source_type`=0 AND `id`=12 AND `link`=0;


DELETE FROM `smart_scripts` WHERE `entryorguid` IN(2795100,2795101,2795102) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(27951, 0, 0, 1, 25, 0, 100, 0, 0, 0, 0, 0, 20, 0,0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Admiral Barean Westwind - On Reset - Disable Auto Attack'),
(27951, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 21, 0,0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Admiral Barean Westwind - On Reset - Disable Combat Movement'),
(27951, 0, 2, 0, 38, 0, 100, 0, 2, 2, 0, 0, 28, 50161,0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Admiral Barean Westwind - On Data Set 2 2 - Remove Aura Protection Sphere'),
(27951, 0, 3, 4,  4, 0, 100, 0, 0, 0, 0, 0, 11, 50161,0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Admiral Barean Westwind - On Agro - Cast Protection Sphere'),
(27951, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 2795100,2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Admiral Barean Westwind - On Agro - Run Script 1'),
(27951, 0, 5, 0, 38, 0, 100, 0, 1, 1, 0, 0, 80, 2795101,2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Admiral Barean Westwind - On Data Set 1 1 - Run Script 2'),
(27951, 0, 6, 0, 40, 0, 100, 0, 6, 27951, 0, 0, 1, 3,0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Admiral Barean Westwind - On Reached WP6 - Say Line 4'),
(27951, 0, 7, 0, 40, 0, 100, 0, 26, 27951, 0, 0, 80, 2795102,2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Admiral Barean Westwind - On Reached WP26 - Run Script 3'),
(27951, 0, 8, 0, 11, 0, 100, 0, 0, 0, 0, 0, 19, 768,0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Admiral Barean Westwind - On Respawn - Remove Unit flags immune to pc/npc'),
(27951, 0, 9, 0, 38, 0, 100, 0, 3, 3, 0, 0, 49, 0,0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Admiral Barean Westwind - On Data Set 3 3 - Enter combat (Stored Target)'),
(27210, 0, 3, 0, 6, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 27951, 0, 0, 0, 0, 0, 0, 'High General Abbendis - On Death - Set Data 1 1 on Admiral Barean Westwind '),
(27210, 0, 4, 0, 7, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 19, 27951, 0, 0, 0, 0, 0, 0, 'High General Abbendis - On Evade - Set Data 2 2 on Admiral Barean Westwind '),
(27210, 0, 5, 6, 4, 0, 100, 0, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'High General Abbendis - On Agro - Store Targetlist'),
(27210, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 100, 1, 0, 0, 0, 0, 0, 19, 27951, 0, 0, 0, 0, 0, 0, 'High General Abbendis - On Agro - Send Target Targetlist to Admiral Barean Westwind'),
(27210, 0, 7, 0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 3, 3, 0, 0, 0, 0, 19, 27951, 0, 0, 0, 0, 0, 0, 'High General Abbendis - On Agro - Set Data 3 3 on Admiral Barean Westwind'),
(27210, 0, 8, 0,11, 0, 100, 1, 0, 0, 0, 0, 70, 0, 0, 0, 0, 0, 0, 10, 85322, 27951, 0, 0, 0, 0, 0, 'High General Abbendis - On Respawn - Respawn Admiral Barean Westwind '),
(27203, 0, 1, 0, 4, 0, 30, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Onslaught Footman - On Agro - Say'),
(27202, 0, 14, 0, 4, 0, 30, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Onslaught Raven Priest - On Aggro - Say'),
(27202, 0, 15, 0, 1, 0, 50, 0, 0, 45000, 60000, 90000, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Onslaught Raven Priest - OOC - Say'),
(27246, 0, 11, 0, 10, 0, 100, 0, 0, 40, 45000, 55000, 1, 0, 7000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bishop Street - OOC Los - Say Line 1'),
(27246, 0, 12, 0, 52, 0, 100, 0, 0, 27246, 0, 0, 1, 1, 7000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bishop Street - On Text Over Line 1 - Say Line 2'),
(27246, 0, 13, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 2, 7000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bishop Street - On Agro Say Line 3'),
(2795100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0,0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Admiral Barean Westwind - Script 1 - Say Line 1'),
(2795100, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 0,0, 0, 0, 0, 0, 19, 27210, 0, 0, 0, 0, 0, 0, 'Admiral Barean Westwind - Script 1 - Say Line 1 (High General Abbendis)'),
(2795101, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 18, 768,0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Admiral Barean Westwind - Script 2 - Set Unit Flags Immune to NPC/PC'),
(2795101, 9, 1, 0, 0, 0, 100, 0, 100, 100, 0, 0, 11, 50161,0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Admiral Barean Westwind - Script 2 - Cast Protection Spear'),
(2795101, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 66, 0,0, 0, 0, 0, 0, 21, 50, 0, 0, 0, 0, 0, 0, 'Admiral Barean Westwind - Script 2 - Face Player'),
(2795101, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1,0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Admiral Barean Westwind - Script 2 - Say Line 2'),
(2795101, 9, 4, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 66, 0,0, 0, 0, 0, 0, 19, 27210, 0, 0, 0, 0, 0, 0, 'Admiral Barean Westwind - Script 2 - Face High General Abbendis'),
(2795101, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0,90, 8,0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Admiral Barean Westwind - Script 2 - Set Kneel'),
(2795101, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 2,0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Admiral Barean Westwind - Script 2 - Say Line 3'),
(2795101, 9, 7, 0, 0, 0, 100, 0, 5000, 5000, 0, 0,91, 8,0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Admiral Barean Westwind - Script 2 - Set Stand'),
(2795101, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0,53, 0,27951, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Admiral Barean Westwind - Script 2 - Start WP'),
(2795102, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 34427,0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Admiral Barean Westwind - Script 3 - Cast Ethereal Teleport'),
(2795102, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 41, 0,0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Admiral Barean Westwind - Script 3 - Despawn');
DELETE FROM `creature_template_addon` WHERE `entry` IN (27202);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(27202, 0, 0x0, 0x1, '48154'); -- 27202 - 48154

DELETE FROM `waypoints` WHERE `entry` IN(27951);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(27951,1, 2663.62, -359.1632, 144.224,'Admiral Barean Westwind'),
(27951,2, 2664.87, -358.9132, 143.724,'Admiral Barean Westwind'),
(27951,3, 2666.12, -358.6632, 143.224,'Admiral Barean Westwind'),
(27951,4, 2667.12, -358.4132, 142.724,'Admiral Barean Westwind'),
(27951,5, 2668.37, -358.4132, 142.474,'Admiral Barean Westwind'),
(27951,6, 2669.62, -358.1632, 142.224,'Admiral Barean Westwind'),
(27951,7, 2671.12, -357.9132, 141.724,'Admiral Barean Westwind'),
(27951,8, 2679.87, -356.6632, 141.724,'Admiral Barean Westwind'),
(27951,9, 2684.62, -355.9132, 141.724,'Admiral Barean Westwind'),
(27951,10, 2691.62, -355.1632, 141.724,'Admiral Barean Westwind'),
(27951,11, 2698.62, -354.1632, 141.724,'Admiral Barean Westwind'),
(27951,12, 2705.87, -353.1632, 141.724,'Admiral Barean Westwind'),
(27951,13, 2714.12, -351.9132, 141.724,'Admiral Barean Westwind'),
(27951,14, 2715.37, -351.6632, 141.724,'Admiral Barean Westwind'),
(27951,15, 2717.62, -351.4132, 141.724,'Admiral Barean Westwind'),
(27951,16, 2717.798, -351.4926, 141.4669,'Admiral Barean Westwind'),
(27951,17, 2718.548, -351.2426, 141.4669,'Admiral Barean Westwind'),
(27951,18, 2719.298, -353.4926, 141.4669,'Admiral Barean Westwind'),
(27951,19, 2720.548, -355.2426, 141.4669,'Admiral Barean Westwind'),
(27951,20, 2720.86, -355.3831, 141.4667,'Admiral Barean Westwind'),
(27951,21, 2722.36, -357.8831, 141.4667,'Admiral Barean Westwind'),
(27951,22, 2723.61, -357.6331, 141.4667,'Admiral Barean Westwind'),
(27951,23, 2726.86, -357.3831, 141.4667,'Admiral Barean Westwind'),
(27951,24, 2731.61, -356.6331, 141.4667,'Admiral Barean Westwind'),
(27951,25, 2733.86, -356.3831, 141.4667,'Admiral Barean Westwind'),
(27951,26, 2736.61, -355.8831, 141.4667,'Admiral Barean Westwind');

UPDATE `creature` SET `spawndist`=5 WHERE  `guid`=143217;
