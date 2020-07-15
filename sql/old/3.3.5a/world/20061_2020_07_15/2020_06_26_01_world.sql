--
SET @GUID := 150145; -- 3

-- Spell 34444 is used by player after 34445
UPDATE `quest_template_addon` SET `SourceSpellID` = 0 WHERE `ID` = 10211;

-- A'dal SAI (rewrite and re-order actions)
UPDATE `smart_scripts` SET `target_type` = 7, `target_param1` = 0 WHERE `entryorguid` = 1848100 AND `source_type` = 9 AND `id` IN (0,1,2,3);

-- Removed the spell 'Blessing of A'dal' since is used only after turning in quest
-- https://www.wowhead.com/spell=35076/blessing-of-adal#comments
-- Confirmed by https://youtu.be/gvEYGFP4Kfc?t=42
SET @ID := 18481;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID*100+1 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,20,0,100,0,11007,0,0,0,80,@ID*100+0,2,0,0,0,0,1,0,0,0,0,0,0,0,"A'dal - On Quest 'Kael'thas and the Verdant Sphere' Finished - Run Script"),
(@ID,0,1,0,20,0,100,0,10210,0,0,0,80,@ID*100+1,2,0,0,0,0,1,0,0,0,0,0,0,0,"A'dal - On Quest 'A'dal' Finished - Run Script"),
(@ID,0,2,0,19,0,100,0,13082,0,0,0,11,53141,0,0,0,0,0,7,0,0,0,0,0,0,0,"A'dal - On Quest 'The Boon of A'dal' Taken - Cast 'Portal Effect: Dalaran'"),

(@ID*100+1,9,0,0,0,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"A'dal - On Script - Store Targetlist"),
(@ID*100+1,9,1,0,0,0,100,0,0,0,0,0,100,1,0,0,0,0,0,19,18166,0,0,0,0,0,0,"A'dal - On Script - Send Target 1 (Khadgar)"),
(@ID*100+1,9,2,0,0,0,100,0,0,0,0,0,45,0,1,0,0,0,0,19,18166,0,0,0,0,0,0,"A'dal - On Script - Set Data 0 1 (Khadgar)");

-- Khadgar SAI
SET @ID := 18166;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID*100+0 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,38,0,100,0,0,1,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"Khadgar - On Data Set 0 1 - Say Line 0"),
(@ID,0,1,0,19,0,100,0,10211,0,0,0,80,@ID*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Khadgar - On Quest 'City of Light' Taken - Run Script"),

(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,11,34445,0,0,0,0,0,7,0,0,0,0,0,0,0,"Khadgar - On Script - Cast 'Trigger Khadgar's Servant'"),
-- Hack, it must be done in spell script (spell 34445)
(@ID*100+0,9,1,0,0,0,100,0,0,0,0,0,86,34444,0,7,0,0,0,7,0,0,0,0,0,0,0,"Khadgar - On Script - Cross Cast 'Summon Khadgar's Servant'"),
(@ID*100+0,9,2,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Khadgar - On Script - Say Line 1");

-- Khadgar's Servant SAI
SET @ID := 19685;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN @ID*100+0 AND @ID*100+6 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,54,0,100,0,0,0,0,0,80,@ID*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Khadgar's Servant - On Just Summoned - Run Script"),
(@ID,0,1,0,40,0,100,0,9,0,0,0,80,@ID*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Khadgar's Servant - On Waypoint 9 Reached - Run Script"),
(@ID,0,2,0,40,0,100,0,24,0,0,0,80,@ID*100+2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Khadgar's Servant - On Waypoint 24 Reached - Run Script"),
(@ID,0,3,0,40,0,100,0,52,0,0,0,80,@ID*100+3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Khadgar's Servant - On Waypoint 52 Reached - Run Script"),
(@ID,0,4,0,40,0,100,0,63,0,0,0,80,@ID*100+4,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Khadgar's Servant - On Waypoint 63 Reached - Run Script"),
(@ID,0,5,0,40,0,100,0,75,0,0,0,80,@ID*100+5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Khadgar's Servant - On Waypoint 75 Reached - Run Script"),
(@ID,0,6,0,40,0,100,0,79,0,0,0,80,@ID*100+6,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Khadgar's Servant - On Waypoint 79 Reached - Run Script"),

-- Stop follow owner, he's guardian now
(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,29,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Khadgar's Servant - On Script - Stop Follow"),
-- Hack, seems like the only way to really stop follow for guardians is
-- to stop it by action above and then move creature to some point
(@ID*100+0,9,1,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Khadgar's Servant - On Script - Move To Self"),
(@ID*100+0,9,2,0,0,0,100,0,8000,8000,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Khadgar's Servant - On Script - Say Line 0"),
(@ID*100+0,9,3,0,0,0,100,0,5000,5000,0,0,53,0,19685,0,0,0,0,1,0,0,0,0,0,0,0,0,"Khadgar's Servant - On Script - Start Waypoint"),

(@ID*100+1,9,0,0,0,0,100,0,0,0,0,0,54,25000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Khadgar's Servant - On Script - Pause Waypoint"),
(@ID*100+1,9,1,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Khadgar's Servant - On Script - Say Line 1"),
(@ID*100+1,9,2,0,0,0,100,0,6000,6000,0,0,1,2,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Khadgar's Servant - On Script - Say Line 2"),
(@ID*100+1,9,3,0,0,0,100,0,8000,8000,0,0,1,3,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Khadgar's Servant - On Script - Say Line 3"),
(@ID*100+1,9,4,0,0,0,100,0,6000,6000,0,0,1,4,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Khadgar's Servant - On Script - Say Line 4"),

(@ID*100+2,9,0,0,0,0,100,0,0,0,0,0,54,20000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Khadgar's Servant - On Script - Pause Waypoint"),
(@ID*100+2,9,1,0,0,0,100,0,0,0,0,0,1,5,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Khadgar's Servant - On Script - Say Line 5"),
(@ID*100+2,9,2,0,0,0,100,0,5000,5000,0,0,1,6,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Khadgar's Servant - On Script - Say Line 6"),
(@ID*100+2,9,3,0,0,0,100,0,8000,8000,0,0,1,7,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Khadgar's Servant - On Script - Say Line 7"),

(@ID*100+3,9,0,0,0,0,100,0,0,0,0,0,54,33000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Khadgar's Servant - On Script - Pause Waypoint"),
(@ID*100+3,9,1,0,0,0,100,0,0,0,0,0,1,8,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Khadgar's Servant - On Script - Say Line 8"),
(@ID*100+3,9,2,0,0,0,100,0,8000,8000,0,0,1,9,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Khadgar's Servant - On Script - Say Line 9"),
(@ID*100+3,9,3,0,0,0,100,0,8000,8000,0,0,1,10,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Khadgar's Servant - On Script - Say Line 10"),
(@ID*100+3,9,4,0,0,0,100,0,8000,8000,0,0,1,11,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Khadgar's Servant - On Script - Say Line 11"),

(@ID*100+4,9,0,0,0,0,100,0,0,0,0,0,54,20000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Khadgar's Servant - On Script - Pause Waypoint"),
(@ID*100+4,9,1,0,0,0,100,0,0,0,0,0,1,12,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Khadgar's Servant - On Script - Say Line 12"),
(@ID*100+4,9,2,0,0,0,100,0,12000,12000,0,0,1,13,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Khadgar's Servant - On Script - Say Line 13"),

(@ID*100+5,9,0,0,0,0,100,0,0,0,0,0,54,22000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Khadgar's Servant - On Script - Pause Waypoint"),
(@ID*100+5,9,1,0,0,0,100,0,0,0,0,0,1,14,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Khadgar's Servant - On Script - Say Line 14"),
(@ID*100+5,9,2,0,0,0,100,0,7000,7000,0,0,1,15,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Khadgar's Servant - On Script - Say Line 15"),
(@ID*100+5,9,3,0,0,0,100,0,8000,8000,0,0,1,16,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Khadgar's Servant - On Script - Say Line 16"),
(@ID*100+5,9,4,0,0,0,100,0,7000,7000,0,0,1,17,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Khadgar's Servant - On Script - Say Line 17"),

(@ID*100+6,9,0,0,0,0,100,0,0,0,0,0,54,23000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Khadgar's Servant - On Script - Pause Waypoint"),
(@ID*100+6,9,1,0,0,0,100,0,7000,7000,0,0,1,18,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Khadgar's Servant - On Script - Say Line 18"),
(@ID*100+6,9,2,0,0,0,100,0,9000,9000,0,0,1,19,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Khadgar's Servant - On Script - Say Line 19"),
(@ID*100+6,9,3,0,0,0,100,0,12000,12000,0,0,1,20,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Khadgar's Servant - On Script - Say Line 20"),
(@ID*100+6,9,4,0,0,0,100,0,10000,10000,0,0,1,21,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Khadgar's Servant - On Script - Say Line 21"),
(@ID*100+6,9,5,0,0,0,100,0,6000,6000,0,0,11,34443,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Khadgar's Servant - On Script - Cast 'Tour Complete'"),
(@ID*100+6,9,6,0,0,0,100,0,4000,4000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Khadgar's Servant - On Script - Despawn");

DELETE FROM `script_waypoint` WHERE `entry` = 19685;
DELETE FROM `waypoints` WHERE `entry` = 19685;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(19685,1,-1856.7291,5412.545,-12.428734,"Khadgar's Servant"),
(19685,2,-1851.104,5399.949,-12.428146,"Khadgar's Servant"),
(19685,3,-1847.482,5389.796,-12.428139,"Khadgar's Servant"),
(19685,4,-1827.3976,5348.053,-12.42815,"Khadgar's Servant"),
(19685,5,-1821.0642,5335.8955,-12.42815,"Khadgar's Servant"),
(19685,6,-1802.9408,5316.994,-12.42815,"Khadgar's Servant"),
(19685,7,-1798.6168,5309.4126,-14.128704,"Khadgar's Servant"),
(19685,8,-1788.5541,5293.4414,-24.505981,"Khadgar's Servant"),
(19685,9,-1779.5438,5277.361,-34.690746,"Khadgar's Servant"),
(19685,10,-1771.0858,5261.3037,-38.817463,"Khadgar's Servant"),
(19685,11,-1759.6964,5259.905,-40.20918,"Khadgar's Servant"),
(19685,12,-1753.8544,5260.21,-40.20918,"Khadgar's Servant"),
(19685,13,-1747.248,5259.636,-40.20918,"Khadgar's Servant"),
(19685,14,-1746.0751,5253.2456,-42.85606,"Khadgar's Servant"),
(19685,15,-1742.3296,5243.56,-46.769466,"Khadgar's Servant"),
(19685,16,-1730.8258,5236.6045,-49.55395,"Khadgar's Servant"),
(19685,17,-1683.7133,5220.5083,-49.08398,"Khadgar's Servant"),
(19685,18,-1670.9059,5217.952,-46.45898,"Khadgar's Servant"),
(19685,19,-1652.6665,5226.6304,-44.08592,"Khadgar's Servant"),
(19685,20,-1634.3944,5250.019,-40.897358,"Khadgar's Servant"),
(19685,21,-1630.9922,5271.961,-41.013546,"Khadgar's Servant"),
(19685,22,-1626.7494,5289.8457,-40.59592,"Khadgar's Servant"),
(19685,23,-1621.2554,5297.61,-40.20918,"Khadgar's Servant"),
(19685,24,-1614.4084,5298.0903,-40.20918,"Khadgar's Servant"),
(19685,25,-1632.7439,5300.1255,-40.20918,"Khadgar's Servant"),
(19685,26,-1643.0891,5308.961,-40.20918,"Khadgar's Servant"),
(19685,27,-1653.7859,5315.9053,-40.20918,"Khadgar's Servant"),
(19685,28,-1659.5901,5336.533,-45.95236,"Khadgar's Servant"),
(19685,29,-1662.5231,5352.865,-45.892548,"Khadgar's Servant"),
(19685,30,-1648.3981,5373.665,-45.754517,"Khadgar's Servant"),
(19685,31,-1642.712,5388.85,-45.504517,"Khadgar's Servant"),
(19685,32,-1644.5186,5403.5293,-44.493343,"Khadgar's Servant"),
(19685,33,-1646.4899,5413.0654,-45.243343,"Khadgar's Servant"),
(19685,34,-1653.3834,5421.3716,-43.112034,"Khadgar's Servant"),
(19685,35,-1666.6986,5426.2163,-38.837574,"Khadgar's Servant"),
(19685,36,-1688.5514,5425.893,-35.175846,"Khadgar's Servant"),
(19685,37,-1713.5116,5426.5933,-21.384369,"Khadgar's Servant"),
(19685,38,-1736.4636,5427.166,-12.428154,"Khadgar's Servant"),
(19685,39,-1740.6917,5401.8325,-12.428154,"Khadgar's Servant"),
(19685,40,-1745.5271,5378.9697,-12.428154,"Khadgar's Servant"),
(19685,41,-1762.5303,5368.7065,-12.428154,"Khadgar's Servant"),
(19685,42,-1775.9219,5363.033,-12.42815,"Khadgar's Servant"),
(19685,43,-1796.6299,5352.968,-12.42815,"Khadgar's Servant"),
(19685,44,-1819.3346,5335.0957,-12.42815,"Khadgar's Servant"),
(19685,45,-1846.719,5328.497,-12.428154,"Khadgar's Servant"),
(19685,46,-1860.551,5321.537,-12.428154,"Khadgar's Servant"),
(19685,47,-1879.4563,5312.3325,-12.428154,"Khadgar's Servant"),
(19685,48,-1887.5878,5318.0654,-10.759747,"Khadgar's Servant"),
(19685,49,-1891.0618,5339.536,0.9520931,"Khadgar's Servant"),
(19685,50,-1897.5068,5326.246,1.2132931,"Khadgar's Servant"),
(19685,51,-1912.0924,5287.3804,1.5652809,"Khadgar's Servant"),
(19685,52,-1916.7811,5270.458,3.3536053,"Khadgar's Servant"),
(19685,53,-1923.3287,5270.8525,3.6359081,"Khadgar's Servant"),
(19685,54,-1927.7502,5278.948,-0.23987198,"Khadgar's Servant"),
(19685,55,-1928.264,5297.987,-11.442955,"Khadgar's Servant"),
(19685,56,-1922.1162,5313.118,-12.428154,"Khadgar's Servant"),
(19685,57,-1923.5797,5337.27,-12.428158,"Khadgar's Servant"),
(19685,58,-1927.2803,5350.631,-12.428154,"Khadgar's Servant"),
(19685,59,-1956.068,5388.3394,-12.428158,"Khadgar's Servant"),
(19685,60,-1969.9077,5433.6436,-12.428154,"Khadgar's Servant"),
(19685,61,-1977.7777,5448.807,-12.428154,"Khadgar's Servant"),
(19685,62,-1951.7997,5458.225,0.9233341,"Khadgar's Servant"),
(19685,63,-1966.2068,5463.945,1.1968708,"Khadgar's Servant"),
(19685,64,-1957.9502,5462.5312,1.0414124,"Khadgar's Servant"),
(19685,65,-1953.9803,5461.978,0.9717388,"Khadgar's Servant"),
(19685,66,-1951.378,5464.6187,0.7884636,"Khadgar's Servant"),
(19685,67,-1970.6925,5486.3354,-12.428154,"Khadgar's Servant"),
(19685,68,-1960.5685,5504.846,-12.428158,"Khadgar's Servant"),
(19685,69,-1922.1747,5535.598,-12.428154,"Khadgar's Servant"),
(19685,70,-1885.1937,5545.7783,-12.428154,"Khadgar's Servant"),
(19685,71,-1857.5562,5548.6274,-12.428154,"Khadgar's Servant"),
(19685,72,-1840.5497,5540.975,-10.218967,"Khadgar's Servant"),
(19685,73,-1836.9247,5522.585,0.94164085,"Khadgar's Servant"),
(19685,74,-1834.1553,5524.043,1.0545769,"Khadgar's Servant"),
(19685,75,-1830.9613,5531.5635,1.2079754,"Khadgar's Servant"),
(19685,76,-1831.6431,5526.3687,1.111126,"Khadgar's Servant"),
(19685,77,-1838.75,5505.8076,0.85694885,"Khadgar's Servant"),
(19685,78,-1845.4235,5485.2446,0.8564892,"Khadgar's Servant"),
(19685,79,-1847.9873,5477.499,0.85691833,"Khadgar's Servant");

UPDATE `creature_text` SET `comment` = "Khadgar's Servant" WHERE `CreatureID` = 19685;

-- Haggard War Veteran
-- Missing spawns
DELETE FROM `creature` WHERE `guid` IN (@GUID+0,@GUID+1,@GUID+2);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `MovementType`) VALUES
(@GUID+0, 19684, 530, 1, 1, 0, -1853.81, 5129.783, -38.854, 2.015334, 300, 0, 2), -- 
(@GUID+1, 19684, 530, 1, 1, 0, -1834.7545, 5355.983, -12.344798, 5.65486, 300, 0, 2), -- 
(@GUID+2, 19684, 530, 1, 1, 0, -1568.29, 5139.5, -23.9051, 2.54298, 300, 0, 2); -- 170028

DELETE FROM `creature_addon` WHERE `guid` IN (@GUID+0,@GUID+1,@GUID+2);
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@GUID+0,(@GUID+0)*10,0,1,0,''),
(@GUID+1,(@GUID+1)*10,0,1,0,''),
(@GUID+2,(@GUID+2)*10,0,1,0,'');

DELETE FROM `waypoint_data` WHERE `id` IN ((@GUID+0)*10,(@GUID+1)*10,(@GUID+2)*10);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
((@GUID+0)*10, 1, -1853.810, 5129.783, -38.854, 1.794635, 180000,0,0,100,0),
((@GUID+0)*10, 2, -1852.098, 5112.867, -38.875, 4.614215, 0,0,0,100,0),
((@GUID+0)*10, 3, -1854.521, 5075.556, -33.129, 4.629922, 0,0,0,100,0),
((@GUID+0)*10, 4, -1858.051, 5038.752, -27.035, 4.602435, 0,0,0,100,0),
((@GUID+0)*10, 5, -1861.358, 5013.369, -22.824, 4.574946, 0,0,0,100,0),
((@GUID+0)*10, 6, -1858.051, 5038.752, -27.035, 4.602435, 0,0,0,100,0),
((@GUID+0)*10, 7, -1854.521, 5075.556, -33.129, 4.629922, 0,0,0,100,0),
((@GUID+0)*10, 8, -1852.098, 5112.867, -38.875, 4.614215, 0,0,0,100,0),
((@GUID+1)*10, 1, -1834.7545, 5355.983, -12.344798, 5.651, 180000,0,0,100,0),
((@GUID+1)*10, 2, -1856.9169, 5330.034, -12.427, 4.005531, 0,0,0,100,0),
((@GUID+1)*10, 3, -1871.6191, 5312.819, -12.427, 4.005531, 0,0,0,100,0),
((@GUID+1)*10, 4, -1890.5996, 5288.959, -12.427, 4.076217, 0,0,0,100,0),
((@GUID+1)*10, 5, -1903.5646, 5270.025, 0.35275, 4.072291, 0,0,0,100,0),
((@GUID+1)*10, 6, -1920.8806, 5255.520, 6.69293, 4.358962, 0,0,0,100,0),
((@GUID+1)*10, 7, -1933.0880, 5221.805, 14.4307, 4.370744, 0,0,0,100,0),
((@GUID+1)*10, 8, -1944.6090, 5187.949, 16.8348, 4.386452, 0,0,0,100,0),
((@GUID+1)*10, 9, -1955.4442, 5154.369, 17.2905, 4.366816, 0,0,0,100,0),
((@GUID+1)*10, 10, -1944.6090, 5187.949, 16.8348, 4.386452, 0,0,0,100,0),
((@GUID+1)*10, 11, -1933.0880, 5221.805, 14.4307, 4.370744, 0,0,0,100,0),
((@GUID+1)*10, 12, -1920.8806, 5255.520, 6.69293, 4.358962, 0,0,0,100,0),
((@GUID+1)*10, 13, -1903.5646, 5270.025, 0.35275, 4.072291, 0,0,0,100,0),
((@GUID+1)*10, 14, -1890.5996, 5288.959, -12.427, 4.076217, 0,0,0,100,0),
((@GUID+1)*10, 15, -1871.6191, 5312.819, -12.427, 4.005531, 0,0,0,100,0),
((@GUID+1)*10, 16, -1856.9169, 5330.034, -12.427, 4.005531, 0,0,0,100,0),
((@GUID+2)*10, 1, -1568.29, 5139.5, -23.9051, 0, 0, 0,0,100,0),
((@GUID+2)*10, 2, -1628.91, 5181.64, -36.080, 0, 0, 0,0,100,0),
((@GUID+2)*10, 3, -1634.13, 5185.49, -37.146, 0, 0, 0,0,100,0),
((@GUID+2)*10, 4, -1660.66, 5198.37, -38.855, 3.173009, 180000, 0, 0,100,0),
((@GUID+2)*10, 5, -1634.13, 5185.49, -37.146, 0, 0, 0,0,100,0),
((@GUID+2)*10, 6, -1628.91, 5181.64, -36.080, 0, 0, 0,0,100,0);

DELETE FROM `smart_scripts` WHERE `entryorguid` = 4426 AND `source_type` = 2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4426,2,0,1,46,0,100,0,4426,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Areatrigger (Terrace of Light) - On Trigger - Store Targetlist"),
(4426,2,1,2,61,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,19,19684,30,0,0,0,0,0,0,"Areatrigger (Terrace of Light) - On Link - Send Target 1 (Haggard War Veteran)"),
(4426,2,2,0,61,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,19,19684,30,0,0,0,0,0,0,"Areatrigger (Terrace of Light) - On Link - Set Data 0 1 (Haggard War Veteran)");

DELETE FROM `areatrigger_scripts` WHERE `entry` = 4426;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(4426,"SmartTrigger");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 4426 AND `SourceId` = 2;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,4426,2,0,9,0,10211,0,0,0,0,0,"","Group 0: Execute SAI (Action 0) if player has taken quest 'City of Light'");

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 19684;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 19684 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(19684,0,0,0,38,0,100,0,0,1,60000,60000,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Haggard War Veteran - On Data Set 0 1 - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID` = 19684;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
-- 0 probably used in waypoint script by creature in -1955.3021 5184.2227 16.977425
(19684,0,0,"The market sure looks busy today.",12,0,100,0,0,0,17235,0,"Haggard War Veteran"),
(19684,0,1,"Look at those crazy kids running around.  Not a care in the world.",12,0,100,0,0,0,17236,0,"Haggard War Veteran"),
(19684,0,2,"What manner of creature is that?  Looks like a purple goblin.",12,0,100,0,0,0,17237,0,"Haggard War Veteran"),
(19684,1,0,"Khadgar himself is showing you around?  You must have made a good impression, $n.",12,0,100,0,0,0,17283,0,"Haggard War Veteran");

-- Sha'nir
DELETE FROM `smart_scripts` WHERE `entryorguid` = 4425 AND `source_type` = 2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4425,2,0,0,46,0,100,0,4425,0,0,0,0,45,0,1,0,0,0,0,19,18597,0,0,0,0,0,0,0,"Areatrigger (Lower City) - On Trigger - Set Data 0 1 (Sha'nir)");

DELETE FROM `areatrigger_scripts` WHERE `entry` = 4425;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(4425,"SmartTrigger");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 4425 AND `SourceId` = 2;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,4425,2,0,9,0,10211,0,0,0,0,0,"","Group 0: Execute SAI (Action 0) if player has taken quest 'City of Light'");

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 18597;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 18597 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1859700 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(18597,0,0,0,38,0,100,0,0,1,60000,60000,0,80,1859700,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sha'nir - On Data Set 0 1 - Run Script"), -- 02:53:29.000
(1859700,9,0,0,0,0,100,0,6000,6000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sha'nir - On Script - Say Line 0"); -- 02:53:35.000

DELETE FROM `creature_text` WHERE `CreatureID` = 18597;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(18597,0,0,"A newcomer to Shattrath!  Make sure to drop by later.  We can always use a hand with the injured.",12,0,100,0,0,0,17282,0,"Sha'nir");

-- Iz'zard & Arcanist Adyria
DELETE FROM `smart_scripts` WHERE `entryorguid` = 4428 AND `source_type` = 2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4428,2,0,0,46,0,100,0,4428,0,0,0,0,45,0,1,0,0,0,0,19,18622,0,0,0,0,0,0,0,"Areatrigger (Lower City) - On Trigger - Set Data 0 1 (Iz'zard)");

DELETE FROM `areatrigger_scripts` WHERE `entry` = 4428;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(4428,"SmartTrigger");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 4428 AND `SourceId` = 2;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,4428,2,0,9,0,10211,0,0,0,0,0,"","Group 0: Execute SAI (Action 0) if player has taken quest 'City of Light'");

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 18622;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 18622 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1862200 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(18622,0,0,0,38,0,100,0,0,1,60000,60000,0,80,1862200,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Iz'zard - On Data Set 0 1 - Run Script"), -- 02:54:32.000
(1862200,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Iz'zard - On Script - Say Line 0"), -- 02:54:32.000
(1862200,9,1,0,0,0,100,0,6000,6000,0,0,0,1,0,0,0,0,0,0,19,18596,0,0,0,0,0,0,0,"Iz'zard - On Script - Say Line 0 (Arcanist Adyria)"); -- 02:54:38.000

DELETE FROM `creature_text` WHERE `CreatureID` IN (18622,18596);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(18622,0,0,"Be mindful of what you say, this one's being shown around by Khadgar's pet.",12,0,100,0,0,0,17284,0,"Iz'zard"),
(18596,0,0,"Are you joking?  I'm a Scryer, I always watch what I say.  More enemies than allies in this city, it seems.",12,0,100,0,0,0,17285,0,"Arcanist Adyria");



-- Aldor Anchorite
DELETE FROM `smart_scripts` WHERE `entryorguid` = 4429 AND `source_type` = 2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4429,2,0,1,46,0,100,0,4429,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Areatrigger (Terrace of Light) - On Trigger - Store Targetlist"),
(4429,2,1,2,61,0,100,0,0,0,0,0,0,12,19142,8,0,0,0,0,8,0,0,0,0,-1890.9529,5338.5063,1.0447,4.939281,"Areatrigger (Terrace of Light) - On Link - Summon Creature 'Aldor Anchorite'"),
(4429,2,2,0,61,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,19,19142,100,0,0,0,0,0,0,"Areatrigger (Terrace of Light) - On Link - Send Target 1 (Aldor Anchorite)");

DELETE FROM `areatrigger_scripts` WHERE `entry` = 4429;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(4429,"SmartTrigger");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 4429 AND `SourceId` = 2;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,4429,2,0,9,0,10211,0,0,0,0,0,"","Group 0: Execute SAI (Action 0) if player has taken quest 'City of Light'"),
(22,1,4429,2,0,29,0,19142,100,0,1,0,0,"","Group 0: Execute SAI (Action 0) if creature 'Aldor Anchorite' is not near");

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 19142;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 19142 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(19142,0,0,0,54,0,100,0,0,0,0,0,0,53,0,19142,0,0,0,2,1,0,0,0,0,0,0,0,0,"Aldor Anchorite - On Just Summoned - Start Waypoint"),
(19142,0,1,0,40,0,100,0,1,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Aldor Anchorite - On Waypoint 1 Reached - Say Line 0"),
(19142,0,2,0,40,0,100,0,7,0,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Aldor Anchorite - On Waypoint 7 Reached - Despawn (1000)");

DELETE FROM `creature_text` WHERE `CreatureID` = 19142;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(19142,0,0,"Light be with you, $n.  And welcome to Shattrath.",12,0,100,0,0,0,17286,0,"Aldor Anchorite");

DELETE FROM `waypoints` WHERE `entry` = 19142;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(19142,1,-1888.4237,5326.354,-3.825138,"Aldor Anchorite"),
(19142,2,-1887.8665,5322.0596,-7.4228554,"Aldor Anchorite"),
(19142,3,-1885.7524,5312.7925,-12.428154,"Aldor Anchorite"),
(19142,4,-1880.2937,5306.304,-12.428154,"Aldor Anchorite"),
(19142,5,-1871.0533,5302.632,-12.428154,"Aldor Anchorite"),
(19142,6,-1846.2037,5304.3022,-12.428154,"Aldor Anchorite"),
(19142,7,-1834.7722,5303.1914,-12.428154,"Aldor Anchorite");

-- Scryer Arcanist
DELETE FROM `smart_scripts` WHERE `entryorguid` = 4430 AND `source_type` = 2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4430,2,0,1,46,0,100,0,4430,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Areatrigger (Terrace of Light) - On Trigger - Store Targetlist"),
(4430,2,1,2,61,0,100,0,0,0,0,0,0,12,18547,8,0,0,0,0,8,0,0,0,0,-2011.0538,5479.285,3.8012,0.104719,"Areatrigger (Terrace of Light) - On Link - Summon Creature 'Scryer Arcanist'"),
(4430,2,2,0,61,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,19,18547,100,0,0,0,0,0,0,"Areatrigger (Terrace of Light) - On Link - Send Target 1 (Scryer Arcanist)");

DELETE FROM `areatrigger_scripts` WHERE `entry` = 4430;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(4430,"SmartTrigger");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 4430 AND `SourceId` = 2;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,4430,2,0,9,0,10211,0,0,0,0,0,"","Group 0: Execute SAI (Action 0) if player has taken quest 'City of Light'"),
(22,1,4430,2,0,29,0,18547,100,0,1,0,0,"","Group 0: Execute SAI (Action 0) if creature 'Scryer Arcanist' is not near");

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 18547;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 18547 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(18547,0,0,0,54,0,100,0,0,0,0,0,0,53,0,18547,0,0,0,2,1,0,0,0,0,0,0,0,0,"Scryer Arcanist - On Just Summoned - Start Waypoint"),
(18547,0,1,0,40,0,100,0,2,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Scryer Arcanist - On Waypoint 2 Reached - Say Line 0"),
(18547,0,2,0,40,0,100,0,11,0,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Scryer Arcanist - On Waypoint 11 Reached - Despawn (1000)");

DELETE FROM `creature_text` WHERE `CreatureID` = 18547;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(18547,0,0,"We're rather selective of who we befriend, $n.  You think you have what it takes?",12,0,100,0,0,0,17287,0,"Scryer Arcanist");

DELETE FROM `waypoints` WHERE `entry` = 18547;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(18547,1,-1984.6294,5469.5337,0.9833431,"Scryer Arcanist"),
(18547,2,-1969.3099,5464.869,1.2419147,"Scryer Arcanist"),
(18547,3,-1957.1414,5460.9097,1.0112228,"Scryer Arcanist"),
(18547,4,-1935.9397,5453.796,0.85699654,"Scryer Arcanist"),
(18547,5,-1919.1415,5447.9434,0.85645866,"Scryer Arcanist"),
(18547,6,-1914.0087,5445.4805,0.85712814,"Scryer Arcanist"),
(18547,7,-1910.4358,5435.6807,1.0386486,"Scryer Arcanist"),
(18547,8,-1915.1366,5424.12,1.7555523,"Scryer Arcanist"),
(18547,9,-1916.685,5417.044,2.154705,"Scryer Arcanist"),
(18547,10,-1908.1824,5399.165,2.3604717,"Scryer Arcanist"),
(18547,11,-1910.6818,5390.2026,2.254301,"Scryer Arcanist"); -- probably incomplete, no despawn packet
