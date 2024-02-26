-- 
-- Circle of Binding
DELETE FROM `gameobject` WHERE `id`=180105;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES 
(2134506, 180105, 0, 0, 0, 1, 1, -11823.3, 1244.24, 2.02101, 2.63221, 0, 0, 0.967741, 0.251949, 300, 0, 1, 0);

DELETE FROM `waypoints` WHERE `entry` IN (14910, 14911, 14912);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(14910, 1, -11826.5, 1249.88, 2.45471, 'Exzhal'),
(14910, 2, -11830.1, 1253.57, 2.25573, 'Exzhal'),
(14910, 3, -11832.6, 1255.68, 2.21323, 'Exzhal'),
(14910, 4, -11829.2, 1253.21, 2.25743, 'Exzhal'),
(14910, 5, -11825.7, 1250.48, 2.46781, 'Exzhal'),
(14910, 6, -11828.2, 1246.82, 2.31921, 'Exzhal'),
(14910, 7, -11827.8, 1246.61, 2.30972, 'Exzhal'),
(14911, 1, -11826.1, 1250.66, 2.45186, 'Enforcer'),
(14911, 2, -11827.9, 1252.08, 2.36752, 'Enforcer'),
(14911, 3, -11835.8, 1258.33, 2.14388, 'Enforcer'),
(14911, 4, -11834.8, 1257.81, 2.14911, 'Enforcer'),
(14912, 1, -11831.626953,1253.9940, 2.2721, 'Captured Hakkari Zealot'),
(14912, 2, -11825.442383,1250.7995, 2.4607, 'Captured Hakkari Zealot'),
(14912, 3, -11823.367188,1244.3104, 2.0318, 'Captured Hakkari Zealot');

-- Exzhal SAI
SET @ENTRY := 14910;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,1800000,1800000,53,0,14910,0,0,0,0,1,0,0,0,0,0,0,0,"Exzhal - Out of Combat - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,3,14910,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Exzhal - On Waypoint 3 Reached - Run Script"),
(@ENTRY,0,2,0,40,0,100,0,7,14910,0,0,80,@ENTRY*100+01,0,0,0,0,0,1,0,0,0,0,0,0,0,"Exzhal - On Waypoint 7 Reached - Run Script");

-- Actionlist SAI
SET @ENTRY := 1491000;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 0"),
(@ENTRY,9,2,0,0,0,100,0,3000,3000,0,0,1,0,0,0,0,0,0,19,14911,20,0,0,0,0,0,"On Script - Say Line 0");

-- Actionlist SAI
SET @ENTRY := 1491001;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,14911,20,0,0,0,0,0,"Exzhal - On Script - Set Data 1 1"),
(@ENTRY,9,1,0,0,0,100,0,11000,11000,0,0,45,2,2,0,0,0,0,19,14911,20,0,0,0,0,0,"Exzhal - On Script - Set Data 2 2"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,45,2,2,0,0,0,0,19,14912,20,0,0,0,0,0,"Exzhal - On Script - Set Data 2 2"),
(@ENTRY,9,3,0,0,0,100,0,2000,2000,0,0,1,1,2000,0,0,0,0,1,0,0,0,0,0,0,0,"Exzhal - On Script - Say Line 1"),
(@ENTRY,9,4,0,0,0,100,0,5000,5000,0,0,1,0,2000,0,0,0,0,19,14912,20,0,0,0,0,0,"Exzhal - On Script - Say Line 0"),
(@ENTRY,9,5,0,0,0,100,0,5000,5000,0,0,1,2,2000,0,0,0,0,1,0,0,0,0,0,0,0,"Exzhal - On Script - Say Line 2"),
(@ENTRY,9,6,0,0,0,100,0,0,0,0,0,45,3,3,0,0,0,0,19,14912,20,0,0,0,0,0,"Exzhal - On Script - Set Data 3 3"),
(@ENTRY,9,7,0,0,0,100,0,5000,5000,0,0,1,3,2000,0,0,0,0,1,0,0,0,0,0,0,0,"Exzhal - On Script - Say Line 3"),
(@ENTRY,9,8,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,19,14912,20,0,0,0,0,0,"Exzhal - On Script - Say Line 1"),
(@ENTRY,9,9,0,0,0,100,0,5000,5000,0,0,1,4,2000,0,0,0,0,1,0,0,0,0,0,0,0,"Exzhal - On Script - Say Line 4"),
(@ENTRY,9,10,0,0,0,100,0,5000,5000,0,0,1,2,2000,0,0,0,0,19,14912,20,0,0,0,0,0,"Exzhal - On Script - Say Line 2"),
(@ENTRY,9,11,0,0,0,100,0,2000,2000,0,0,1,3,2000,0,0,0,0,19,14912,20,0,0,0,0,0,"Exzhal - On Script - Say Line 3"),
(@ENTRY,9,12,0,0,0,100,0,5000,5000,0,0,1,5,2000,0,0,0,0,1,0,0,0,0,0,0,0,"Exzhal - On Script - Say Line 5"),
(@ENTRY,9,13,0,0,0,100,0,5000,5000,0,0,1,2,2000,0,0,0,0,19,14912,20,0,0,0,0,0,"Exzhal - On Script - Say Line 2"),
(@ENTRY,9,14,0,0,0,100,0,2000,2000,0,0,1,4,2000,0,0,0,0,19,14912,20,0,0,0,0,0,"Exzhal - On Script - Say Line 4"),
(@ENTRY,9,15,0,0,0,100,0,5000,5000,0,0,1,5,2000,0,0,0,0,19,14912,20,0,0,0,0,0,"Exzhal - On Script - Say Line 5"),
(@ENTRY,9,16,0,0,0,100,0,5000,5000,0,0,1,6,2000,0,0,0,0,1,0,0,0,0,0,0,0,"Exzhal - On Script - Say Line 6"),
(@ENTRY,9,17,0,0,0,100,0,5000,5000,0,0,1,6,2000,0,0,0,0,19,14912,20,0,0,0,0,0,"Exzhal - On Script - Say Line 6"),
(@ENTRY,9,18,0,0,0,100,0,2000,2000,0,0,1,7,2000,0,0,0,0,19,14912,20,0,0,0,0,0,"Exzhal - On Script - Say Line 7"),
(@ENTRY,9,19,0,0,0,100,0,5000,5000,0,0,1,8,2000,0,0,0,0,19,14912,20,0,0,0,0,0,"Exzhal - On Script - Say Line 8"),
(@ENTRY,9,20,0,0,0,100,0,5000,5000,0,0,1,9,2000,0,0,0,0,19,14912,20,0,0,0,0,0,"Exzhal - On Script - Say Line 9"),
(@ENTRY,9,21,0,0,0,100,0,5000,5000,0,0,1,7,2000,0,0,0,0,1,0,0,0,0,0,0,0,"Exzhal - On Script - Say Line 7"),
(@ENTRY,9,22,0,0,0,100,0,5000,5000,0,0,1,2,2000,0,0,0,0,19,14912,20,0,0,0,0,0,"Exzhal - On Script - Say Line 2"),
(@ENTRY,9,23,0,0,0,100,0,2000,2000,0,0,1,10,2000,0,0,0,0,19,14912,20,0,0,0,0,0,"Exzhal - On Script - Say Line 10"),
(@ENTRY,9,24,0,0,0,100,0,5000,5000,0,0,1,11,2000,0,0,0,0,19,14912,20,0,0,0,0,0,"Exzhal - On Script - Say Line 11"),
(@ENTRY,9,25,0,0,0,100,0,5000,5000,0,0,1,12,2000,0,0,0,0,19,14912,20,0,0,0,0,0,"Exzhal - On Script - Say Line 12"),
(@ENTRY,9,26,0,0,0,100,0,2000,2000,0,0,1,13,2000,0,0,0,0,19,14912,20,0,0,0,0,0,"Exzhal - On Script - Say Line 13"),
(@ENTRY,9,27,0,0,0,100,0,5000,5000,0,0,1,8,2000,0,0,0,0,1,0,0,0,0,0,0,0,"Exzhal - On Script - Say Line 8"),
(@ENTRY,9,28,0,0,0,100,0,5000,5000,0,0,1,14,2000,0,0,0,0,19,14912,20,0,0,0,0,0,"Exzhal - On Script - Say Line 14"),
(@ENTRY,9,29,0,0,0,100,0,4000,4000,0,0,11,23950,0,0,0,0,0,1,0,0,0,0,0,0,0,"Exzhal - On Script - Cast 'Exzhal Searches for Wild Gods DND'"),
(@ENTRY,9,30,0,0,0,100,0,4000,4000,0,0,1,9,2000,0,0,0,0,1,0,0,0,0,0,0,0,"Exzhal - On Script - Say Line 9"),
(@ENTRY,9,31,0,0,0,100,0,5000,5000,0,0,1,15,2000,0,0,0,0,19,14912,20,0,0,0,0,0,"Exzhal - On Script - Say Line 15"),
(@ENTRY,9,32,0,0,0,100,0,5000,5000,0,0,1,16,2000,0,0,0,0,19,14912,20,0,0,0,0,0,"Exzhal - On Script - Say Line 16"),
(@ENTRY,9,33,0,0,0,100,0,5000,5000,0,0,1,17,2000,0,0,0,0,19,14912,20,0,0,0,0,0,"Exzhal - On Script - Say Line 17"),
(@ENTRY,9,34,0,0,0,100,0,2000,2000,0,0,45,4,4,0,0,0,0,19,14911,20,0,0,0,0,0,"Exzhal - On Script - Set Data 4 4");

-- Zandalar Enforcer SAI
SET @ENTRY := 14911;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100+1 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,0,1,1,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Zandalar Enforcer - On Data Set 1 1 - Action list"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Zandalar Enforcer - Action list - Set Run Off"),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,9,0,0,0,0,0,0,20,180104,20,0,0,0,0,0,"Zandalar Enforcer - Action list - Activate Gameobject"),
(@ENTRY*100,9,2,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,14912,20,0,0,0,0,0,"Zandalar Enforcer - Action list - Set Data 1 1"),
(@ENTRY*100,9,3,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Zandalar Enforcer - Action list - Say Line 1"),
(@ENTRY*100,9,4,0,0,0,100,0,3000,3000,0,0,69,0,0,0,0,0,0,8,0,0,0,-11821.7031, 1246.4638, 2.250135,3.80639,"Zandalar Enforcer - Action list - Move To Position"),
(@ENTRY*100,9,5,0,0,0,100,0,3000,3000,0,0,32,0,0,0,0,0,0,20,180104,40,0,0,0,0,0,"Zandalar Enforcer - Action list - Close cage"),
(@ENTRY,0,1,0,38,0,100,0,2,2,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.80639,"Zandalar Enforcer - On Data Set 2 2 - Set Orientation"),
(@ENTRY,0,2,0,38,0,100,0,4,4,0,0,80,@ENTRY*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Zandalar Enforcer - On Data Set 4 4 - Action list"),
(@ENTRY*100+1,9,0,0,0,0,100,0,2000,2000,0,0,5,37,0,0,0,0,0,1,0,0,0,0,0,0,0,"Zandalar Enforcer - Action list - Play Emote 37"),
(@ENTRY*100+1,9,1,0,0,0,100,0,500,500,0,0,51,0,0,0,0,0,0,19,14912,20,0,0,0,0,0,"Zandalar Enforcer - Action list - Kill Target"),
(@ENTRY*100+1,9,2,0,0,0,100,0,1000,1000,0,0,1,2,2000,0,0,0,0,1,0,0,0,0,0,0,0,"Zandalar Enforcer - Action list - Say Line 2"),
(@ENTRY*100+1,9,3,0,0,0,100,0,2000,2000,0,0,53,0,14911,0,0,0,0,1,0,0,0,0,0,0,0,"Zandalar Enforcer - Action list - Start Waypoint");

-- Captured Hakkari Zealot SAI
SET @ENTRY := 14912;
-- Captured Hakkari Zealot set respawntime 60 seconds
UPDATE `creature` SET `spawntimesecs`='60' WHERE  `id`=@ENTRY;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,38,0,100,0,1,1,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Hakkari Zealot - On Data Set 1 1 - Set Run Off"),
(@ENTRY,0,1,0,61,0,100,0,1,1,0,0,53,0,14912,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Hakkari Zealot - On Data Set 1 1 - Start Waypoint"),
(@ENTRY,0,2,0,38,0,100,0,2,2,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.589020,"Captured Hakkari Zealot - On Data Set 2 2 - Set Orientation"),
(@ENTRY,0,3,0,38,0,100,0,3,3,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Hakkari Zealot - On Data Set 3 3 - Set Flag Standstate Kneel"),
(@ENTRY,0,4,0,6,0,100,0,0,0,0,0,41,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Hakkari Zealot - On Just Died - Despawn In 5000 ms");

DELETE FROM `creature_text` WHERE `creatureid` IN (14911, 14910, 14912) ;
INSERT INTO `creature_text` (`creatureid`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES 
(14911, 0, 0, 'Right away, Servitor.', 12, 14, 100, 1, 0, 0, 10307, 'Zandalar Enforcer'),
(14911, 1, 0, 'Move!', 12, 14, 100, 0, 0, 0, 10308, 'Zandalar Enforcer'),
(14911, 2, 0, '%s spits on the corpse of the fallen zealot.', 16, 0, 100, 0, 0, 0, 10336, 'Zandalar Enforcer'),
(14910, 0, 0, 'Guard, Bring forth the prisoner. Place him in the Circle of Binding.', 14, 0, 100, 1, 0, 0, 10306, 'Exzhal'),
(14910, 1, 0, 'Kneel, heathen.', 12, 14, 100, 1, 0, 0, 10309, 'Exzhal'),
(14910, 2, 0, 'I said KNEEL!', 14, 0, 100, 1, 0, 0, 10311, 'Exzhal'),
(14910, 3, 0, 'Do you know who I am, zealot?', 12, 0, 100, 1, 0, 0, 10312, 'Exzhal'),
(14910, 4, 0, 'I could crush you with but a single motion. Do not anger me.', 12, 0, 100, 1, 0, 0, 10314, 'Exzhal'),
(14910, 5, 0, 'So Hakkar has returned?', 12, 0, 100, 1, 0, 0, 10317, 'Exzhal'),
(14910, 6, 0, 'We will never allow it... We have banished him from our world before and we will banish him again.', 12, 0, 100, 1, 0, 0, 10320, 'Exzhal'),
(14910, 7, 0, 'Times have changed. The young races will join us. You will never succeed.', 14, 0, 100, 1, 0, 0, 10325, 'Exzhal'),
(14910, 8, 0, 'The Primal Gods? Impossible!', 12, 0, 100, 1, 0, 0, 10330, 'Exzhal'),
(14910, 9, 0, '%s uses his index finger to make a cutting motion across his neck.', 16, 0, 100, 0, 0, 0, 10332, 'Exzhal'),
(14912, 0, 0, 'Curious. A Servitor of Rastakhan that does not know the Hakkari do not converse in the old tongue?', 12, 1, 100, 0, 0, 0, 10310, 'Captured Hakkari Zealot'),
(14912, 1, 0, 'You are a fool, soon to forfeit his life. No?', 12, 1, 100, 0, 0, 0, 10313, 'Captured Hakkari Zealot'),
(14912, 2, 0, '%s laughs.', 16, 0, 100, 11, 0, 0, 2047, 'Captured Hakkari Zealot'),
(14912, 3, 0, 'How pathetic. I am infused with the power of the Soulflayer. I fear nothing but the wrath of the almighty Hakkar. I serve no one but my master, Jin.', 12, 0, 100, 1, 0, 0, 10316, 'Captured Hakkari Zealot'),
(14912, 4, 0, 'Do you really need to ask? Can you not feel him? Has the almighty King Rastakhan sent his Servitor and Hand here on a mission of diplomacy?', 12, 0, 100, 1, 0, 0, 10318, 'Captured Hakkari Zealot'),
(14912, 5, 0, 'Oh yes, old one, Hakkar has returned. Soon the world shall crumble beneath his might. Consumed. Left in ruin...', 12, 0, 100, 1, 0, 0, 10319, 'Captured Hakkari Zealot'),
(14912, 6, 0, '%s laughs maniacally.', 16, 0, 100, 11, 0, 0, 10321, 'Captured Hakkari Zealot'),
(14912, 7, 0, 'FOOL! Do you purport to have even one-tenth of the power you held during the Uprising? The nations were united and still were nearly consumed by a shadow of Hakkar. You stand no chance.', 12, 0, 100, 1, 0, 0, 10322, 'Captured Hakkari Zealot'),
(14912, 8, 0, 'And now, even those nations that you would have called allies have recoiled and joined forces with us... Yes, old one, do not look so surprised.', 12, 0, 100, 1, 0, 0, 10323, 'Captured Hakkari Zealot'),
(14912, 9, 0, 'Bloodscalp, Sandfury, Skullsplitter, Vilebranch and Witherbark. They all pledge their allegiance to Jin - their souls to Hakkar. You have lost.', 12, 0, 100, 1, 0, 0, 10324, 'Captured Hakkari Zealot'),
(14912, 10, 0, 'The young races? The infants? Humans? Orcs? Dwarves? You expect to defeat the Hakkari? To destroy a GOD?', 12, 0, 100, 1, 0, 0, 10326, 'Captured Hakkari Zealot'),
(14912, 11, 0, 'It shall NEVER happen. We are legion. We are united. Where are your heroes? Vol''jin sits in sanctuary at the side of the young Warchief, unaware. Zul''jin missing, probably dead.', 12, 0, 100, 1, 0, 0, 10327, 'Captured Hakkari Zealot'),
(14912, 12, 0, 'And... do you expect to defeat the Primal Gods?', 12, 0, 100, 1, 0, 0, 10328, 'Captured Hakkari Zealot'),
(14912, 13, 0, '%s smirks.', 16, 0, 100, 0, 0, 0, 10329, 'Captured Hakkari Zealot'),
(14912, 14, 0, 'Is it? Call out to them, Servitor.', 12, 0, 100, 1, 0, 0, 10331, 'Captured Hakkari Zealot'),
(14912, 15, 0, 'Where are your Gods now? WHERE, SERVITOR?', 12, 0, 100, 1, 0, 0, 10333, 'Captured Hakkari Zealot'),
(14912, 16, 0, 'Strike me down. I shall be reborn... Even more powerful...', 12, 0, 100, 1, 0, 0, 10334, 'Captured Hakkari Zealot'),
(14912, 17, 0, '%s drops his shoulders and exposes his neck.', 16, 0, 100, 0, 0, 0, 10335, 'Captured Hakkari Zealot');
