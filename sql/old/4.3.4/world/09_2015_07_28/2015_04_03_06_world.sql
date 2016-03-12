-- Baelmon the Hound-Master SAI
SET @ENTRY  := 19747;
SET @SPELL1 := 39218; -- Baelmon Channeling (no duration)
SET @SPELL2 := 11443; -- Cripple
SET @SPELL3 := 31598; -- Rain of Fire
SET @SPELL4 := 39272; -- Summon Wrath Hound
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid` IN (@ENTRY*100,@ENTRY*100+1,@ENTRY*100+2,@ENTRY*100+3,@ENTRY*100+4);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,53,0,@ENTRY,1,0,0,2,1,0,0,0,0,0,0,0,'Baelmon the Hound-Master - On Spawn - Load Path'),
(@ENTRY,0,1,2,40,0,100,0,3,@ENTRY,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Baelmon the Hound-Master - Reach wp 3 - pause path'),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Baelmon the Hound-Master - Reach wp 3 - run script'),
(@ENTRY,0,3,4,40,0,100,0,6,@ENTRY,0,0,54,21000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Baelmon the Hound-Master - Reach wp 6 - pause path'),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,80,@ENTRY*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Baelmon the Hound-Master - Reach wp 6 - run script'),
(@ENTRY,0,5,6,40,0,100,0,7,@ENTRY,0,0,54,49000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Baelmon the Hound-Master - Reach wp 7 - pause path'),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,80,@ENTRY*100+2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Baelmon the Hound-Master - Reach wp 7 - run script'),
(@ENTRY,0,7,8,40,0,100,0,10,@ENTRY,0,0,54,8000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Baelmon the Hound-Master - Reach wp 10 - pause path'),
(@ENTRY,0,8,0,61,0,100,0,0,0,0,0,80,@ENTRY*100+3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Baelmon the Hound-Master - Reach wp 10 - run script'),
(@ENTRY,0,9,10,40,0,100,0,11,@ENTRY,0,0,54,300000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Baelmon the Hound-Master - Reach wp 11 - pause path'),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,80,@ENTRY*100+4,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Baelmon the Hound-Master - Reach wp 11 - run script'),
(@ENTRY,0,11,0,0,0,100,0,5000,9000,18000,25000,11,@SPELL2,0,0,0,0,0,2,0,0,0,0,0,0,0,'Baelmon the Hound-Master - combat - cast spell'),
(@ENTRY,0,12,0,0,0,100,0,20000,25000,25000,30000,11,@SPELL3,0,0,0,0,0,2,0,0,0,0,0,0,0,'Baelmon the Hound-Master - combat - cast spell'),
(@ENTRY,0,13,14,0,0,100,0,35000,40000,40000,45000,11,@SPELL4,0,0,0,0,0,1,0,0,0,0,0,0,0,'Baelmon the Hound-Master - combat - cast spell'),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,'Baelmon the Hound-Master - combat - Say4'),
(@ENTRY*100,9,0,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Baelmon the Hound-Master - Script - say 0'),
(@ENTRY*100+1,9,0,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.485496, 'Baelmon the Hound-Master - Script - turn to'),
(@ENTRY*100+1,9,1,0,0,0,100,0,5000,5000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.513274, 'Baelmon the Hound-Master - Script - turn to'),
(@ENTRY*100+1,9,2,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Baelmon the Hound-Master - Script - say 1'),
(@ENTRY*100+1,9,3,0,0,0,100,0,0,0,0,0,12,21837,8,0,0,0,0,8,0,0,0,2282.145,5380.948,148.3864,3.060301, 'Baelmon the Hound-Master - Script - summon Summoned Wrath Hound'),
(@ENTRY*100+2,9,0,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.480334, 'Baelmon the Hound-Master - Script - turn to'),
(@ENTRY*100+2,9,1,0,0,0,100,0,2000,2000,0,0,11,@SPELL1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Baelmon the Hound-Master - Script - cast spell'),
(@ENTRY*100+2,9,2,0,0,0,100,0,46000,46000,0,0,28,@SPELL1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Baelmon the Hound-Master - Script - Stop Channeling'),
(@ENTRY*100+3,9,0,0,0,0,100,0,2000,2000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Baelmon the Hound-Master - Script - say 2'),
(@ENTRY*100+4,9,0,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.480334, 'Baelmon the Hound-Master - Script - turn to'),
(@ENTRY*100+4,9,1,0,0,0,100,0,2000,2000,0,0,11,@SPELL1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Baelmon the Hound-Master - Script - cast spell'),
(@ENTRY*100+4,9,2,0,0,0,100,0,296000,296000,0,0,28,@SPELL1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Baelmon the Hound-Master - Script - Stop Channeling'),
(@ENTRY,0,15,0,4,0,100,0,0,0,0,0,1, 3,0,0,0,0,0,2,0,0,0,0,0,0,0,'Summoned Wrath Hound - on aggro - Say3');

-- waypoints for Baelmon the Hound-Master
DELETE FROM `waypoints` WHERE `entry` IN (@ENTRY); 
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,2251.221,5415.110,144.5944, 'Baelmon the Hound-Master'),
(@ENTRY,2,2253.267,5422.193,144.3444, 'Baelmon the Hound-Master'),
(@ENTRY,3,2251.017,5425.398,144.3444, 'Baelmon the Hound-Master'),
(@ENTRY,4,2250.168,5418.636,144.3444, 'Baelmon the Hound-Master'),
(@ENTRY,5,2263.631,5399.851,145.9176, 'Baelmon the Hound-Master'),
(@ENTRY,6,2273.678,5402.083,146.9626, 'Baelmon the Hound-Master'),
(@ENTRY,7,2270.231,5394.729,145.4702, 'Baelmon the Hound-Master'),
(@ENTRY,8,2264.036,5400.769,146.0911, 'Baelmon the Hound-Master'),
(@ENTRY,9,2234.945,5428.808,144.3444, 'Baelmon the Hound-Master'),
(@ENTRY,10,2223.490,5426.155,144.3497, 'Baelmon the Hound-Master'),
(@ENTRY,11,2270.231,5394.729,145.4702, 'Baelmon the Hound-Master');

-- NPC talk text insert from sniff 
DELETE FROM `creature_text` WHERE `entry`=@ENTRY; 
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextID`) VALUES 
(@ENTRY,0,0, 'Make ready the chambers, another ally will soon join our ranks!',14,0,100,0,0,0, 'Baelmon the Hound-Master', 19416),
(@ENTRY,1,0, 'Our ally has arrived!  Clear the way to the materialization chamber!',14,0,100,0,0,0, 'Baelmon the Hound-Master', 19417),
(@ENTRY,2,0, 'Now, proceed to the translocator. Forge Camp Wrath awaits your arrival!',14,0,100,0,0,0, 'Baelmon the Hound-Master', 19418),
(@ENTRY,3,0, 'Prepare yourself for eternal torture, mortal!',14,0,100,0,0,0, 'Baelmon the Hound-Master', 20366),
(@ENTRY,3,1, 'WHAT?! Who dares to disturb the Burning Legion?',14,0,100,0,0,0, 'Baelmon the Hound-Master', 20365),
(@ENTRY,3,2, 'I shall enjoy the smell of the grease from your marrow crackling over the fire!',14,0,100,0,0,0, 'Baelmon the Hound-Master', 20368),
(@ENTRY,3,3, 'Nothing will prevent your doom!',14,0,100,0,0,0, 'Baelmon the Hound-Master', 20367),
(@ENTRY,3,4, 'You DARE to attack me?!',14,0,100,0,0,0, 'Baelmon the Hound-Master', 20369),
(@ENTRY,3,5, 'You will suffer slowly until the end of time for this affront!',14,0,100,0,0,0, 'Baelmon the Hound-Master', 20370),
(@ENTRY,4,0, 'Release the hounds!',14,0,100,0,0,0, 'Baelmon the Hound-Master', 20395);

UPDATE `creature` SET `spawndist`=10, `MovementType`=1 WHERE `guid` IN (84894, 84893, 84896, 84897, 84898, 84895, 84889, 84892, 84886, 84890, 84891, 84885, 84883, 84882, 84879, 84880, 84878, 84877, 84876, 84874, 84872, 84873, 84865, 84867, 84871);

-- Summoned Wrath Hound SAI
SET @ENTRY  := 21837;
SET @SPELL1 := 22578; -- Glowy (Black)
SET @SPELL2 := 37312; -- Portal Exit Effect
SET @SPELL3 := 22911; -- Charge
SET @SPELL4 := 36406; -- Bouble Breath
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry` IN (@ENTRY, 22499);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`IN (@ENTRY, 22499);
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid` IN (@ENTRY*100,@ENTRY*100+1,@ENTRY*100+2);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,54,0,100,0,0,0,0,0,11,@SPELL1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Summoned Wrath Hound - On summon - cast aura'),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,53,0,@ENTRY,0,0,0,2,1,0,0,0,0,0,0,0,'Summoned Wrath Hound - On summon - Load Path'),
(@ENTRY,0,2,3,40,0,100,0,1,@ENTRY,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Summoned Wrath Hound - Reach wp 1 - pause path'),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Summoned Wrath Hound - Reach wp 1 - run script'),
(@ENTRY,0,4,5,40,0,100,0,7,@ENTRY,0,0,54,4000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Summoned Wrath Hound - Reach wp 7 - pause path'),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,80,@ENTRY*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Summoned Wrath Hound - Reach wp 7 - run script'),
(@ENTRY,0,6,7,40,0,100,0,22,@ENTRY,0,0,54,4000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Summoned Wrath Hound - Reach wp 22 - pause path'),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,80,@ENTRY*100+2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Summoned Wrath Hound - Reach wp 22 - run script'),
(@ENTRY,0,8,0,4,0,100,0,0,0,0,0,11,@SPELL3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Summoned Wrath Hound - on aggro - cast spell'),
(@ENTRY,0,9,0,0,0,100,0,4000,8000,6000,10000,11,@SPELL4,0,0,0,0,0,2,0,0,0,0,0,0,0,'Summoned Wrath Hound - combat - cast spell'),
(@ENTRY*100,9,0,0,0,0,100,0,4500,4500,0,0,11,@SPELL2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Summoned Wrath Hound - Script - cast spell'),
(@ENTRY*100+1,9,0,0,0,0,100,0,500,500,0,0,19,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Summoned Wrath Hound - Script - Set unit flags'),
(@ENTRY*100+2,9,0,0,0,0,100,0,4500,4500,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Summoned Wrath Hound - Script - despawn'),
-- Lesser Wrath Hound SAI
(22499,0,0,0,0,0,100,0,4000,8000,6000,10000,11,36406,0,0,0,0,0,2,0,0,0,0,0,0,0,'Lesser Wrath Hound- combat - cast spell'),
(22499,0,1,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,30,0,0,0,0,0,0,'Lesser Wrath Hound- Just Summoned - Start Attack');

-- waypoints for Baelmon the Hound-Master
DELETE FROM `waypoints` WHERE `entry` IN (@ENTRY); 
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,2268.924,5393.452,145.4471, 'Summoned Wrath Hound'),
(@ENTRY,2,2255.472,5407.068,145.0279, 'Summoned Wrath Hound'),
(@ENTRY,3,2243.098,5420.322,144.3444, 'Summoned Wrath Hound'),
(@ENTRY,4,2226.786,5438.047,144.3497, 'Summoned Wrath Hound'),
(@ENTRY,5,2211.937,5460.007,150.8571, 'Summoned Wrath Hound'),
(@ENTRY,6,2195.829,5463.447,153.6814, 'Summoned Wrath Hound'),
(@ENTRY,7,2188.094,5477.495,155.0914, 'Summoned Wrath Hound'),
(@ENTRY,8,2195.297,5464.697,153.6814, 'Summoned Wrath Hound'),
(@ENTRY,9,2208.225,5464.172,153.5997, 'Summoned Wrath Hound'),
(@ENTRY,10,2219.882,5446.347,144.3497, 'Summoned Wrath Hound'),
(@ENTRY,11,2210.560,5435.390,144.6450, 'Summoned Wrath Hound'),
(@ENTRY,12,2170.015,5423.634,144.2937, 'Summoned Wrath Hound'),
(@ENTRY,13,2142.269,5430.440,144.8000, 'Summoned Wrath Hound'),
(@ENTRY,14,2100.592,5447.438,145.3132, 'Summoned Wrath Hound'),
(@ENTRY,15,2046.968,5449.164,145.0331, 'Summoned Wrath Hound'),
(@ENTRY,16,2031.698,5416.583,144.7770, 'Summoned Wrath Hound'),
(@ENTRY,17,2009.996,5392.866,145.6075, 'Summoned Wrath Hound'),
(@ENTRY,18,1951.617,5362.657,148.1501, 'Summoned Wrath Hound'),
(@ENTRY,19,1958.205,5340.299,153.2451, 'Summoned Wrath Hound'),
(@ENTRY,20,1950.292,5312.918,154.0889, 'Summoned Wrath Hound'),
(@ENTRY,21,1960.221,5301.518,154.0889, 'Summoned Wrath Hound'),
(@ENTRY,22,1980.815,5314.191,156.4767, 'Summoned Wrath Hound');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=39218;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 4, 39218, 0, 31, 3, 20736, 0, 0, '', 'Baelmon Channeling target');

-- Blade's Edge - Legion - Invis Bunny update
UPDATE `creature_template` SET `InhabitType`=4,`flags_extra`=`flags_extra`|128 WHERE `entry`=20736;
-- Remove spawn
DELETE FROM `creature` WHERE `guid`=76416;
