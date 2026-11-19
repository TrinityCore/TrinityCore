-- Cult Plaguebringer <Cult of the Damned> SAI (tested)
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=24957;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=24957;
DELETE FROM `smart_scripts` WHERE `entryorguid`=24957;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(24957,0,0,0,1,0,100,0,1000,900000,500000,700000,11,45850,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Ghoul Summons OOC'),
(24957,0,2,0,0,0,30,0,1100,6300,8800,13800,11,50356,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Inject Plague on victim');

-- Cultist Necrolyte SAI (tested)
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=25651;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25651);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25651,0,0,0,11,0,100,0,0,0,0,0,11,45104,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Channelling on self when spawned'),
(25651,0,1,0,21,0,100,0,0,0,0,0,11,45104,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Channelling on self when reach home home'),
(25651,0,2,0,0,0,30,0,1000,2000,6000,8000,11,18266,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Curse of Agony on victim'),
(25651,0,3,0,0,0,70,0,3000,4000,3000,4000,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt on victim');

-- Azure Front Channel Stalker SAI (tested working)
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=31400;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-203457,-111746,-111726,-111742);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-203457,0,0,0,1,0,100,1,1000,1000,1000,1000,11,59044,2,0,0,0,0,10,111746,31400,0,0,0,0,0,'Cast Cosmetic - Crystalsong Tree Beam when spawned'),
(-111746,0,0,0,1,0,100,1,1000,1000,1000,1000,11,59044,2,0,0,0,0,10,111726,31400,0,0,0,0,0,'Cast Cosmetic - Crystalsong Tree Beam when spawned'),
(-111726,0,0,0,1,0,100,1,1000,1000,1000,1000,11,59044,2,0,0,0,0,10,111742,31400,0,0,0,0,0,'Cast Cosmetic - Crystalsong Tree Beam when spawned'),
(-111742,0,0,0,1,0,100,1,1000,1000,1000,1000,11,59044,2,0,0,0,0,10,203520,31400,0,0,0,0,0,'Cast Cosmetic - Crystalsong Tree Beam when spawned');

-- Wildhammer Scout SAI (tested)
-- Removes waypoint script error spamming at Wildhammer Stronghold
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=19384;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-69122,-69123,-69124,-69125,-69126,-69127);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-69122,0,0,0,1,0,100,0,1000,2000,3000,6000,11,33808,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shoot Gun every 3-6 sec'),
(-69123,0,0,0,1,0,100,0,1000,2000,3000,6000,11,33808,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shoot Gun every 3-6 sec'),
(-69124,0,0,0,1,0,100,0,3000,5000,3000,5000,11,33805,2,0,0,0,0,9,19388,0,25,0,0,0,0,'Cast Throw Hammer every 3-5 sec'),
(-69125,0,0,0,1,0,100,0,3000,5000,3000,5000,11,33806,2,0,0,0,0,9,19388,0,25,0,0,0,0,'Cast Throw Hammer every 3-5 sec'),
(-69126,0,0,0,1,0,100,0,1000,2000,3000,6000,11,33808,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shoot Gun every 3-6 sec'),
(-69127,0,0,0,1,0,100,0,1000,2000,3000,6000,11,33808,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shoot Gun every 3-6 sec');
DELETE FROM `waypoint_data` WHERE `id` IN (691220,691230,691240,691250,691260,691270);
DELETE FROM `waypoint_scripts` WHERE `id` BETWEEN 190 AND 214;
-- Wildhammer Stronghold Target Dummy Left & Wildhammer Stronghold Target Dummy Right are Triggers
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|128,`InhabitType`=7 WHERE `entry` IN (19387,19388);

-- Speech by Marrod Silvertongue, Fort Wildervar (Tested working)
SET @ENTRY := 24534;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@ENTRY*100;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,30000,50000,360000,360000,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Load script every 6 min ooc'),
(@ENTRY*100,9,0,0,0,0,100,0,8000,8000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Marrod Silvertongue Say text 0'),
(@ENTRY*100,9,1,0,0,0,100,0,2000,2000,0,0,5,21,0,0,0,0,0,9,24535,0,20,0,0,0,0,'Northrend Homesteader emote'),
(@ENTRY*100,9,2,0,0,0,100,0,8000,8000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Marrod Silvertongue Say text 1'),
(@ENTRY*100,9,3,0,0,0,100,0,2000,2000,0,0,5,21,0,0,0,0,0,9,24535,0,20,0,0,0,0,'Northrend Homesteader emote'),
(@ENTRY*100,9,4,0,0,0,100,0,8000,8000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Marrod Silvertongue Say text 2'),
(@ENTRY*100,9,5,0,0,0,100,0,2000,2000,0,0,5,21,0,0,0,0,0,9,24535,0,20,0,0,0,0,'Northrend Homesteader emote'),
(@ENTRY*100,9,6,0,0,0,100,0,8000,8000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Marrod Silvertongue Say text 3'),
(@ENTRY*100,9,7,0,0,0,100,0,2000,2000,0,0,5,21,0,0,0,0,0,9,24535,0,20,0,0,0,0,'Northrend Homesteader emote'),
(@ENTRY*100,9,8,0,0,0,100,0,8000,8000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,'Marrod Silvertongue Say text 4'),
(@ENTRY*100,9,9,0,0,0,100,0,2000,2000,0,0,5,4,0,0,0,0,0,9,24535,0,20,0,0,0,0,'Northrend Homesteader emote'),
(@ENTRY*100,9,10,0,0,0,100,0,8000,8000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,'Marrod Silvertongue Say text 5'),
(@ENTRY*100,9,11,0,0,0,100,0,2000,2000,0,0,5,4,0,0,0,0,0,9,24535,0,20,0,0,0,0,'Northrend Homesteader emote'),
(@ENTRY*100,9,12,0,0,0,100,0,8000,8000,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,'Marrod Silvertongue Say text 6'),
(@ENTRY*100,9,13,0,0,0,100,0,2000,2000,0,0,5,4,0,0,0,0,0,9,24535,0,20,0,0,0,0,'Northrend Homesteader emote'),
(@ENTRY*100,9,14,0,0,0,100,0,3000,3000,0,0,5,4,0,0,0,0,0,9,24535,0,20,0,0,0,0,'Northrend Homesteader emote');
-- NPC talk text insert from sniff
DELETE FROM `creature_text` WHERE `entry` IN (24534);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(24534,0,0, 'Welcome to Fort Wildervar, brave homesteaders! There''s a whole continent out there just waiting to be claimed!',0,7,100,1,0,0, 'Marrod Silvertongue'),
(24534,1,0, 'True, Northrend is a hard land, but our people are strong, hardy, and equal to the task!',0,7,100,0,0,0, 'Marrod Silvertongue'),
(24534,2,0, 'We will win this land with the sword, and break it with the plow! You are the men and women who will be remembered for taming the wild continent!',0,7,100,1,0,0, 'Marrod Silvertongue'),
(24534,3,0, 'But, you will not be alone out there. My men and I have prepared pack mules carrying the supplies you''ll need most.',0,7,100,1,0,0, 'Marrod Silvertongue'),
(24534,4,0, 'Axes, picks, seed, nails, food, blankets, water... it''s all there, waiting for you. I think you''ll find my prices quite reasonable, too.',0,7,100,25,0,0, 'Marrod Silvertongue'),
(24534,5,0, 'There are more than enough to go around. Should you need other goods, don''t hesitate to ask!',0,7,100,1,0,0, 'Marrod Silvertongue'),
(24534,6,0, 'Now, my loyal custo... err, friends, go forth and conquer this land for our people!',0,7,100,274,0,0, 'Marrod Silvertongue');
