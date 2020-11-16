-- Flik & his frog
DELETE FROM `waypoint_data` WHERE `id` IN (1376810);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(1376810,1,-1527.0554,162.43452,-7.6678085,0,0,1,0,0,0),
(1376810,2,-1519.4049,170.44824,-7.6946683,0,0,1,0,0,0),
(1376810,3,-1508.2561,183.55574,-7.6946683,0,0,1,0,0,0),
(1376810,4,-1498.1364,178.80792,-7.6678076,0,0,1,0,0,0),
(1376810,5,-1492.0419,184.92522,-7.6678076,0,0,1,0,0,0),
(1376810,6,-1484.2388,188.02425,-7.6678076,0,0,1,0,0,0),
(1376810,7,-1477.6945,182.4646,-7.6678076,0,0,1,0,0,0),
(1376810,8,-1470.6246,175.57527,-7.6678076,0,0,1,0,0,0),
(1376810,9,-1470.0273,184.64192,-7.6678076,0,0,1,0,0,0),
(1376810,10,-1465.0334,190.30692,-7.6677995,0,0,1,0,0,0),
(1376810,11,-1461.2782,199.08371,-7.6677995,0,0,1,0,0,0),
(1376810,12,-1459.0747,207.99756,-7.667806,0,0,1,0,0,0),
(1376810,13,-1469.8142,212.23557,-7.6831884,0,0,1,0,0,0),
(1376810,14,-1480.438,216.46582,-7.6831884,0,0,1,0,0,0),
(1376810,15,-1485.2087,209.65779,-7.6831884,0,0,1,0,0,0),
(1376810,16,-1487.1512,197.81549,-7.6678076,0,0,1,0,0,0),
(1376810,17,-1493.4016,188.09909,-7.6678076,0,0,1,0,0,0),
(1376810,18,-1501.0374,182.45679,-7.6946683,0,0,1,0,0,0),
(1376810,19,-1511.0964,176.22987,-7.6946683,0,0,1,0,0,0),
(1376810,20,-1522.9888,169.60506,-7.6946683,0,0,1,0,0,0),
(1376810,21,-1534.5083,168.5881,-7.7289877,0,0,1,0,0,0),
(1376810,22,-1544.6705,172.59908,-7.7289877,0,0,1,0,0,0),
(1376810,23,-1550.4026,166.76416,-7.7289877,0,0,1,0,0,0),
(1376810,24,-1557.5946,172.08545,-7.7289877,0,0,1,0,0,0),
(1376810,25,-1566.9341,170.4624,-7.6678085,0,0,1,0,0,0),
(1376810,26,-1569.5573,162.50226,-7.7115445,0,0,1,0,0,0),
(1376810,27,-1577.2268,156.30441,-7.7115445,0,0,1,0,0,0),
(1376810,28,-1572.6919,148.14977,-7.7115445,0,0,1,0,0,0),
(1376810,29,-1573.7439,131.02667,-8.011875,0,0,1,0,0,0),
(1376810,30,-1580.9238,119.60346,-9.636875,0,0,1,0,0,0),
(1376810,31,-1590.7731,115.08236,-12.511875,0,0,1,0,0,0),
(1376810,32,-1605.3788,120.04511,-16.19824,0,0,1,0,0,0),
(1376810,33,-1619.9913,120.508,-17.82324,0,0,1,0,0,0),
(1376810,34,-1626.4371,113.33784,-17.82324,0,0,1,0,0,0),
(1376810,35,-1615.3619,115.06055,-17.82324,0,0,1,0,0,0),
(1376810,36,-1605.8744,123.10845,-15.69824,0,0,1,0,0,0),
(1376810,37,-1595.7502,112.46634,-12.761875,0,0,1,0,0,0),
(1376810,38,-1592.1553,98.393936,-10.5600605,0,0,1,0,0,0),
(1376810,39,-1577.2955,87.81063,-9.0600605,0,0,1,0,0,0),
(1376810,40,-1564.7849,94.98942,-5.924779,0,0,1,0,0,0),
(1376810,41,-1566.5446,103.44608,-2.807179,0,0,1,0,0,0),
(1376810,42,-1579.2997,108.94814,-9.511875,0,0,1,0,0,0),
(1376810,43,-1580.6135,124.35615,-9.261875,0,0,1,0,0,0),
(1376810,44,-1569.3239,133.97426,-7.8365445,0,0,1,0,0,0),
(1376810,45,-1568.1815,143.68088,-7.7115445,0,0,1,0,0,0),
(1376810,46,-1558.552,141.94455,-7.682179,0,0,1,0,0,0),
(1376810,47,-1557.5627,152.3049,-7.682179,0,0,1,0,0,0),
(1376810,48,-1544.1437,152.57048,-7.682179,0,0,1,0,0,0),
(1376810,49,-1537.4874,162.0988,-7.682179,0,0,1,0,0,0);

-- Add missing formations and remove waypoints from Flik
UPDATE `creature_formations` SET `dist` = 2, `angle` = 360 WHERE `leaderGUID` = 137681 AND `memberGUID` = 137677;
UPDATE `creature` SET `position_x` = -1527.0554, `position_y` = 162.43452, `position_z` = -7.6678085 WHERE `guid` IN (137681,137677);
UPDATE `creature` SET `position_x` = -9502.26, `position_y` = 77.9182, `position_z` = 57.5324 WHERE `guid` IN (56624,56625);

DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 14860);
DELETE FROM `waypoint_data` WHERE `id` IN (436730,566250);
UPDATE `creature` SET `MovementType` = 0 WHERE `id` = 14860;

DELETE FROM `creature_formations` WHERE `leaderGUID` IN (56624,43672);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(56624,56624,0,0,515,0,0),
(56624,56625,2,360,515,0,0),
(43672,43672,0,0,515,0,0),
(43672,43673,2,360,515,0,0);

-- One of two Darkmoon Faire Carnie
UPDATE `creature` SET `position_x` = -1585.5924, `position_y` = 117.0877, `position_z` = -11.136875 WHERE `guid` IN (137686);
DELETE FROM `waypoint_data` WHERE `id` IN (1376860);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(1376860,1,-1585.5924,117.0877,-11.136875,0,0,0,0,0,0),
(1376860,2,-1618.5973,122.99528,-17.69824,0,0,0,0,0,0),
(1376860,3,-1633.6272,111.31844,-17.82324,0,0,0,0,0,0),
(1376860,4,-1633.1578,98.96647,-17.82324,0,0,0,0,0,0),
(1376860,5,-1628.5997,90.41924,-17.82324,0,0,0,0,0,0),
(1376860,6,-1625.1763,91.63919,-17.82324,0,0,0,0,0,0),
(1376860,7,-1626.3054,97.71352,-17.82324,0,0,0,0,0,0),
(1376860,8,-1627.5028,107.2822,-17.82324,0,0,0,0,0,0),
(1376860,9,-1611.2916,117.99957,-17.19824,0,0,0,0,0,0);

-- Silas Darkmoon & Burth
UPDATE `creature` SET `position_x` = -1584.4713, `position_y` = 116.63995, `position_z` = -10.886875 WHERE `guid` IN (137666,137667);
DELETE FROM `waypoint_data` WHERE `id` IN (1376660);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(1376660,1,-1584.4713,116.63995,-10.886875,0,0,0,0,0,0),
(1376660,2,-1590.0602,115.31747,-12.386875,0,0,0,0,0,0),
(1376660,3,-1607.0582,119.31391,-16.44824,0,0,0,0,0,0),
(1376660,4,-1619.5645,119.9997,-17.82324,0,0,0,0,0,0),
(1376660,5,-1624.3062,117.62275,-17.82324,0,0,0,0,0,0),
(1376660,6,-1618.8767,118.07926,-17.82324,0,0,0,0,0,0),
(1376660,7,-1603.9062,118.87109,-15.82324,0,0,0,0,0,0),
(1376660,8,-1588.8379,114.7561,-12.011875,0,0,0,0,0,0),
(1376660,9,-1582.073,117.58125,-9.886875,0,0,0,0,0,0),
(1376660,10,-1573.7708,131.88441,-8.011875,0,0,0,0,0,0),
(1376660,11,-1565.4547,141.4127,-7.682179,0,0,0,0,0,0),
(1376660,12,-1557.5063,149.92036,-7.682179,0,0,0,0,0,0),
(1376660,13,-1552.265,159.31714,-7.682179,0,0,0,0,0,0),
(1376660,14,-1556.0364,163.97966,-7.682179,0,0,0,0,0,0),
(1376660,15,-1561.0963,162.32056,-7.682179,0,0,0,0,0,0),
(1376660,16,-1562.7856,159.41843,-7.682179,0,0,0,0,0,0),
(1376660,17,-1565.7943,155.5774,-7.682179,0,60000,0,0,0,0),
(1376660,18,-1564.6301,157.11882,-7.682179,0,0,0,0,0,0),
(1376660,19,-1562.6594,160.10606,-7.682179,0,0,0,0,0,0),
(1376660,20,-1561.0983,162.60368,-7.682179,0,0,0,0,0,0),
(1376660,21,-1562.4436,168.99344,-7.7289877,0,0,0,0,0,0),
(1376660,22,-1568.7457,172.07948,-7.6678085,0,0,0,0,0,0),
(1376660,23,-1574.3779,168.00749,-7.6678085,0,0,0,0,0,0),
(1376660,24,-1576.4568,161.28665,-7.7115445,0,0,0,0,0,0),
(1376660,25,-1575.8666,152.67093,-7.7115445,0,0,0,0,0,0),
(1376660,26,-1573.1211,145.2289,-7.7115445,0,0,0,0,0,0),
(1376660,27,-1575.5566,134.64958,-7.8365445,0,0,0,0,0,0),
(1376660,28,-1575.642,134.25548,-7.8365445,0,90000,0,0,0,0),
(1376660,29,-1576.0245,132.38678,-7.886875,0,0,0,0,0,0),
(1376660,30,-1577.6501,125.99526,-8.761875,0,0,0,0,0,0);

UPDATE `creature_formations` SET `dist` = 5, `angle` = 360 WHERE `leaderGUID` = 137666 AND `memberGUID` = 137667;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (14823,-137666) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1482300 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-137666,0,0,0,34,0,100,0,2,17,0,0,0,80,1482300,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Silas Darkmoon - On Reached Point 17 - Run Script"),
(-137666,0,1,0,34,0,100,0,2,28,0,0,0,80,1482300,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Silas Darkmoon - On Reached Point 28 - Run Script"),

(1482300,9,0,0,0,0,100,0,5000,5000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Silas Darkmoon - On Script - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID` = 14823;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
-- Azeroth
(14823,0,0,"Everyone enjoying themselves so far?  That's great!  Welcome to the Darkmoon Faire, the greatest show on all of Azeroth!  Make sure that you speak with Yebb and his friends here while you're taking in Neblegear's Darkmoon Zoo Bizarre.",12,0,100,0,0,0,10153,0,"Silas Darkmoon"),
(14823,0,1,"Come one, come all.  Welcome to the Darkmoon Faire!  Don't be shy.  Step right up to Lhara and buy yourself an exotic artifact from far off lands.  If you're one of the lucky few who have found Darkmoon Cards, have a word with Professor Paleo.  Hungry?  Thirsty?  You're in luck!  Refreshments are available right here from Sylannia and Stamp.  I recommend the Darkmoon Special Reserve to wash down some Red Hot Wings.  And if the future is what you seek, then run, don't walk, to speak with Sayge.",12,0,100,0,0,0,10154,0,"Silas Darkmoon"),
(14823,0,2,"Welcome one and all to the Darkmoon Faire, the greatest event in all the world!  We have it all... delicious food, strong drink, exotic artifacts, fortunes read, amazing prizes and excitement without end!  Don't forget to turn in your Darkmoon Faire Prize Tickets to Gelvas Grimegate!  All it takes is five or more and you're on your way to the most wondrous prizes on all of Azeroth.  Everybody is a winner!",12,0,100,0,0,0,10155,0,"Silas Darkmoon"),
(14823,0,3,"Welcome one and all to the greatest show on all of Azeroth... the Darkmoon Faire!  Adventure and excitement await, don't be shy!  Mysteries and prizes for both the young and the old are here for the taking.  And be sure to speak with the professor about any Darkmoon Cards that you have come across during your travels!",12,0,100,0,0,0,10156,0,"Silas Darkmoon"),
(14823,0,4,"Greetings friends, and welcome to the greatest show on Azeroth!$B$BPlease, step right up and take in all we have to offer.  Ride the rides and see the sights!  Amaze at the wonders that the Darkmoon Faire has uncovered in this vast and mysterious world!  We have spared no expense in bringing you excitement that children of all ages will delight in!",12,0,100,0,0,0,10157,0,"Silas Darkmoon"),
(14823,0,5,"Come one, come all!  Welcome to the Darkmoon Faire!  Do you crave adventure?  Do you seek exotic and mysterious treasures?  Then look no further!  You, my friend, have come to the right place!  Dive right in and take part in all that the Faire has to offer!  We'll be at this location all week, so be sure to tell your friends and loved ones!",12,0,100,0,0,0,10158,0,"Silas Darkmoon"),
(14823,0,6,"We're back and better than ever!  It's the Darkmoon Faire friend, and it's your lucky day!  Sparing no expense, we've gathered wonders and treats from around the world for your delight.  Whether you're young or old, rich or poor, the Darkmoon Faire has it all!  Be sure to turn in your Darkmoon Faire Prize Tickets to Gelvas Grimegate, and choose from several exotic and wondrous prizes!",12,0,100,0,0,0,10160,0,"Silas Darkmoon"),
-- Outland
(14823,1,0,"Come one, come all.  Welcome to the Darkmoon Faire!  Don't be shy.  Step right up to Lhara and buy yourself an exotic artifact from far off lands.  If you're one of the lucky few who have found Darkmoon Cards, have a word with Professor Paleo.  Hungry?  Thirsty?  You're in luck!  Refreshments are available right here from Sylannia and Stamp.  I recommend the Darkmoon Special Reserve to wash down some Red Hot Wings.  And if the future is what you seek, then run, don't walk, to speak with Sayge.",12,0,100,0,0,0,10154,0,"Silas Darkmoon"),
(14823,1,1,"Come one, come all!  Welcome to the Darkmoon Faire!  Do you crave adventure?  Do you seek exotic and mysterious treasures?  Then look no further!  You, my friend, have come to the right place!  Dive right in and take part in all that the Faire has to offer!  We'll be at this location all week, so be sure to tell your friends and loved ones!",12,0,100,0,0,0,10158,0,"Silas Darkmoon"),
(14823,1,2,"We're back and better than ever!  It's the Darkmoon Faire friend, and it's your lucky day!  Sparing no expense, we've gathered wonders and treats from around the world for your delight.  Whether you're young or old, rich or poor, the Darkmoon Faire has it all!  Be sure to turn in your Darkmoon Faire Prize Tickets to Gelvas Grimegate, and choose from several exotic and wondrous prizes!",12,0,100,0,0,0,10160,0,"Silas Darkmoon"),
-- Well, well, well, someone forgot to change this one for Outland
(14823,1,3,"Welcome one and all to the greatest show on all of Azeroth... the Darkmoon Faire!  Adventure and excitement await, don't be shy!  Mysteries and prizes for both the young and the old are here for the taking.  And be sure to speak with the professor about any Darkmoon Cards that you have come across during your travels!",12,0,100,0,0,0,22541,0,"Silas Darkmoon"),
-- And again
(14823,1,4,"Greetings friends, and welcome to the greatest show on Azeroth!$B$BPlease, step right up and take in all we have to offer.  Ride the rides and see the sights!  Amaze at the wonders that the Darkmoon Faire has uncovered in this vast and mysterious world!  We have spared no expense in bringing you excitement that children of all ages will delight in!",12,0,100,0,0,0,22542,0,"Silas Darkmoon"),
(14823,1,5,"Everyone enjoying themselves so far?  That's great!  Welcome to the Darkmoon Faire, the greatest show in all of Outland!  Make sure that you speak with Yebb and his friends here while you're taking in Neblegear's Darkmoon Zoo Bizarre.",12,0,100,0,0,0,22543,0,"Silas Darkmoon"),
(14823,1,6,"Welcome one and all to the Darkmoon Faire, the greatest event in all the worlds!  We have it all... delicious food, strong drink, exotic artifacts, fortunes read, amazing prizes and excitement without end!  Don't forget to turn in your Darkmoon Faire Prize Tickets to Gelvas Grimegate!  All it takes is five or more and you're on your way to the most wondrous prizes in all of Outland.  Everybody is a winner!",12,0,100,0,0,0,22544,0,"Silas Darkmoon");

-- Scripts for other creatures

-- Say not on LoS but OOC, seems like this is more correct. Even if it's LoS it'll cause spam because we have no initial timers.
-- Create similar scripts for other creatures & remove old incomplete hacky implementation
UPDATE `smart_scripts` SET `event_type` = 1, `event_param1` = 0, `event_param2` = 240000, `event_param3` = 180000, `event_param4` = 240000, `event_param5` = 0, `target_type` = 1, `comment` = "Sayge - Out of Combat - Say Line 0" WHERE `entryorguid` = 14822 AND `source_type` = 0 AND `id` = 0;

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` IN (14828,14844,14845,14846,14847,14849,14860);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (14828,14844,14845,14846,14847,14849,14860) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(14828,0,0,0,1,0,100,0,0,240000,180000,240000,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Gelvas Grimegate - Out of Combat - Say Line 0"),
(14844,0,0,0,1,0,100,0,0,240000,180000,240000,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sylannia - Out of Combat - Say Line 0"),
(14845,0,0,0,1,0,100,0,0,240000,180000,240000,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stamp Thunderhorn - Out of Combat - Say Line 0"),
(14846,0,0,0,1,0,100,0,0,240000,180000,240000,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lhara - Out of Combat - Say Line 0"),
(14847,0,0,0,1,0,100,0,0,240000,180000,240000,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Professor Thaddeus Paleo - Out of Combat - Say Line 0"),
(14849,0,0,0,1,0,100,0,0,240000,180000,240000,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Darkmoon Faire Carnie - Out of Combat - Say Line 0"),
(14849,0,1,0,1,0,100,0,0,240000,180000,240000,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Darkmoon Faire Carnie - Out of Combat - Say Line 1"),
(14849,0,2,0,1,0,100,0,0,240000,180000,240000,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Darkmoon Faire Carnie - Out of Combat - Say Line 2"),
(14860,0,0,0,1,0,100,0,0,240000,180000,240000,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Flik - Out of Combat - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID` IN (14828,14844,14845,14846,14847,14849,14860);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(14828,0,0,"Tickets! Redeem your Darkmoon Prize Tickets here!  Wondrous and exotic prizes are waiting for you!",12,0,100,0,0,0,10149,0,"Gelvas Grimegate"),
(14828,0,1,"Mysterious prizes await the adventurous.  Step right up, step right up!",12,0,100,0,0,0,10150,0,"Gelvas Grimegate"),
(14828,0,2,"Five tickets or five hundred, it doesn't matter friend, everybody is a winner!",12,0,100,0,0,0,10151,0,"Gelvas Grimegate"),
(14828,0,3,"Prizes!  Get your prizes right here!  Get over here and turn in your Darkmoon Prize Tickets for valuable prizes!",12,0,100,0,0,0,10152,0,"Gelvas Grimegate"),
(14844,0,0,"Cheap beer!  Get your cheap beer right here!",12,0,100,0,0,0,10129,0,"Sylannia"),
(14844,0,1,"Huzzah for the tipper!  Step right up and get your delicious, cold drinks right here!",12,0,100,0,0,0,10130,0,"Sylannia"),
(14844,0,2,"Just in... another batch of Darkmoon Special Reserve.  Come get yours before they're all gone!",12,0,100,0,0,0,10131,0,"Sylannia"),
(14844,0,3,"You there!  Yes you!  You look thirsty.  Get over here, I have just what you need!",12,0,100,0,0,0,10132,0,"Sylannia"),
(14845,0,0,"Step right up!  Get your red hot wings right here!",12,0,100,0,0,0,10133,0,"Stamp Thunderhorn"),
(14845,0,1,"Darkmoon Dogs fresh off the grill.  Come and get 'em while they're hot!",12,0,100,0,0,0,10134,0,"Stamp Thunderhorn"),
(14845,0,2,"You've got money and we've got food.  What are you waiting for?!",12,0,100,0,0,0,10135,0,"Stamp Thunderhorn"),
(14845,0,3,"For a limited time only, crunchy frog available exclusively here at the Darkmoon Faire.",12,0,100,0,0,0,10136,0,"Stamp Thunderhorn"),
(14846,0,0,"Every item that I have for sale I acquired myself.  You have my personal guarantee of authenticity.",12,0,100,0,0,0,10141,0,"Lhara"),
(14846,0,1,"Darkmoon Faire Cards?  See the Professor here for those.",12,0,100,0,0,0,10142,0,"Lhara"),
(14846,0,2,"Come and take a look at my wares while you still can.  We're here all week, and then we're off to some far off land.",12,0,100,0,0,0,10143,0,"Lhara"),
(14846,0,3,"Have you any idea what I go through to bring these incomparable valuables to sell?  Come see them all for yourself!",12,0,100,0,0,0,10144,0,"Lhara"),
(14847,0,0,"Have a completed Darkmoon deck? Turn it in here!",12,0,100,0,0,0,10137,0,"Professor Thaddeus Paleo"),
(14847,0,1,"Come speak with me if you have any Darkmoon Faire Cards.",12,0,100,0,0,0,10138,0,"Professor Thaddeus Paleo"),
(14847,0,2,"Darkmoon decks! Turn them in here!",12,0,100,0,0,0,10139,0,"Professor Thaddeus Paleo"),
(14847,0,3,"Have you any Darkmoon Faire cards?  Come speak with me to learn more about them if you dare!",12,0,100,0,0,0,10140,0,"Professor Thaddeus Paleo"),
(14849,0,0,"Can't you see I've got work to do here?",12,0,100,0,0,0,10058,0,"Darkmoon Faire Carnie"),
(14849,0,1,"Faire's a coming!",12,0,100,0,0,0,10059,0,"Darkmoon Faire Carnie"),
(14849,0,2,"That's right friend!  The Darkmoon Faire is going to be right here.  Just as soon as I unload those huge wagons, put up all the tents, erect the zoo and pour the drinks.  Make sure you come back!",12,0,100,0,0,0,10060,0,"Darkmoon Faire Carnie"),
(14849,0,3,"Won't be long now until the Darkmoon Faire opens.  Come back later and check to see if we're done.",12,0,100,0,0,0,10061,0,"Darkmoon Faire Carnie"),
(14849,1,0,"Sure are a lot of litter bugs around here.",12,0,100,0,0,0,10118,0,"Darkmoon Faire Carnie"),
(14849,1,1,"Having a good time?",12,0,100,0,0,0,10119,0,"Darkmoon Faire Carnie"),
(14849,1,2,"Don't forget to buy refreshments and souvenirs!",12,0,100,0,0,0,10120,0,"Darkmoon Faire Carnie"),
(14849,1,3,"The Darkmoon Faire is the greatest event on all of Azeroth!",12,0,100,0,0,0,10121,0,"Darkmoon Faire Carnie"),
(14849,2,0,"Sure are a lot of litter bugs around here.",12,0,100,0,0,0,10118,0,"Darkmoon Faire Carnie"),
(14849,2,1,"Having a good time?",12,0,100,0,0,0,10119,0,"Darkmoon Faire Carnie"),
(14849,2,2,"Don't forget to buy refreshments and souvenirs!",12,0,100,0,0,0,10120,0,"Darkmoon Faire Carnie"),
-- Not sure about this one
(14849,2,3,"The Darkmoon Faire is the greatest event in all of Outland!",12,0,100,0,0,0,22546,0,"Darkmoon Faire Carnie"),
(14860,0,0,"Hey, someone help me catch this thing!",12,0,100,0,0,0,10145,0,"Flik"),
(14860,0,1,"It's getting away!",12,0,100,0,0,0,10146,0,"Flik"),
(14860,0,2,"Get back here!",12,0,100,0,0,0,10147,0,"Flik"),
(14860,0,3,"Frogs and leather balls for sale!",12,0,100,0,0,0,10148,0,"Flik");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 14849 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,14849,0,0,12,1,23,0,0,0,0,0,"","Group 0: Execute SAI (Action 0) if event 'Darkmoon Faire Building (Elwynn Forest)' is active"),
(22,1,14849,0,1,12,1,71,0,0,0,0,0,"","Group 1: Execute SAI (Action 0) if event 'Darkmoon Faire Building (Mulgore)' is active"),
(22,1,14849,0,2,12,1,77,0,0,0,0,0,"","Group 2: Execute SAI (Action 0) if event 'Darkmoon Faire Building (Terokkar Forest)' is active"),
(22,2,14849,0,0,12,1,4,0,0,0,0,0,"","Group 0: Execute SAI (Action 1) if event 'Darkmoon Faire (Elwynn Forest)' is active"),
(22,2,14849,0,1,12,1,5,0,0,0,0,0,"","Group 1: Execute SAI (Action 1) if event 'Darkmoon Faire (Mulgore)' is active"),
(22,3,14849,0,0,12,1,3,0,0,0,0,0,"","Group 0: Execute SAI (Action 2) if event 'Darkmoon Faire (Terokkar Forest)' is active");

-- Old scripts
UPDATE `creature` SET `MovementType` = 0 WHERE `id` IN (14822,14828,14846,14847);
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (14822,14828,14844,14845,14846,14847));
DELETE FROM `waypoint_scripts` WHERE `id` IN (29,27,42,28,47,30,215,314);
DELETE FROM `waypoint_data` WHERE `id` IN (436790,436710,494460,454760);
UPDATE `waypoint_data` SET `action` = 0 WHERE `action` IN (215,314);
