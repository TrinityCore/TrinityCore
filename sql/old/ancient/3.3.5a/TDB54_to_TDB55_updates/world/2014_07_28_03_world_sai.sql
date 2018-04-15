

-- Quest 9667 "Saving Princess Stillpine" 24099
-- Princess Stillpine Cage SAI
SET @ENTRY  := 181928; -- GO entry
SET @ENTRY2 := 17682; -- NPC entry

UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI',`ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=1 AND `entryorguid`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@ENTRY*100;

INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,1,70,0,100,0,2,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Princess Stillpine Cage - On StateChange 0 - Store target'),
(@ENTRY,1,1,2,61,0,100,0,0,0,0,0,100,1,0,0,0,0,0,19,@ENTRY2,0,0,0,0,0,0, 'Princess Stillpine Cage - On StateChange 0 - Send target'),
(@ENTRY,1,2,3,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,19,@ENTRY2,0,0,0,0,0,0,'Princess Stillpine Cage - On StateChange 0 - Set data 0 1 for entry 17682'),
(@ENTRY,1,3,0,61,0,100,0,0,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Princess Stillpine Cage - Run Script - Quest credit'),
(@ENTRY*100,9,0,0,0,0,100,0,5000,5000,0,0,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Princess Stillpine Cage - Script - Reset GO');

-- Princess Stillpine SAI
SET @SPELL := 31003;  -- Opening Princess Stillpine's Cage
UPDATE `creature` SET `spawntimesecs`=120 WHERE `guid`=63442;
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry`=@ENTRY2;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY2;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@ENTRY2*100;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY2,0,0,1,38,0,100,0,0,1,0,0,80,@ENTRY2*100,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Princess Stillpine - On dataset - run script'),
(@ENTRY2,0,1,0,61,0,100,0,0,0,0,0,33,@ENTRY2,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Princess Stillpine - On dataset - run script'),
(@ENTRY2,0,2,0,25,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Princess Stillpine - On reset - add questgiver flag'),
(@ENTRY2,0,3,0,40,0,100,0,16,@ENTRY2,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Princess Stillpine - On Reached WP15 - Despawn'),
(@ENTRY2*100,9,0,0,0,0,100,0,100,100,100,100,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Princess Stillpine - Script - Remove questgiver flag'),
(@ENTRY2*100,9,1,0,0,0,100,0,2000,2000,2000,2000,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,'Princess Stillpine - Script - Say 0'),
(@ENTRY2*100,9,2,0,0,0,100,0,3000,3000,3000,3000,53,1,@ENTRY2,0,0,0,0,1,0,0,0,0,0,0,0,'Princess Stillpine - Script - Load path');

-- Waypoints for Princess Stillpine (From sniff)
DELETE FROM `waypoints` WHERE `entry`=@ENTRY2;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES

(@ENTRY2,1,-2548.469, -12304.25, 13.79256, 'Princess Stillpine'),
(@ENTRY2,2,-2548.579, -12304.57, 13.88506, 'Princess Stillpine'),
(@ENTRY2,3,-2550.079, -12304.57, 13.63506, 'Princess Stillpine'),
(@ENTRY2,4,-2555.079, -12305.82, 13.13506, 'Princess Stillpine'),
(@ENTRY2,5,-2564.135, -12308.1, 12.65816, 'Princess Stillpine'),
(@ENTRY2,6,-2600.635, -12304.1, 11.90816, 'Princess Stillpine'),
(@ENTRY2,7,-2600.886, -12303.71, 11.80368, 'Princess Stillpine'),
(@ENTRY2,8,-2602.636, -12303.71, 11.55368, 'Princess Stillpine'),
(@ENTRY2,9,-2612.636, -12299.71, 12.05368, 'Princess Stillpine'),
(@ENTRY2,10,-2614.386, -12299.46, 12.55368, 'Princess Stillpine'),
(@ENTRY2,11,-2617.386, -12298.21, 13.05368, 'Princess Stillpine'),
(@ENTRY2,12,-2620.136, -12297.21, 13.55368, 'Princess Stillpine'),
(@ENTRY2,13,-2626.813, -12294.75, 13.78559, 'Princess Stillpine'),
(@ENTRY2,14,-2635.313, -12289.5, 13.03559, 'Princess Stillpine'),
(@ENTRY2,15,-2647.063, -12282.5, 12.53559, 'Princess Stillpine'),
(@ENTRY2,16,-2657.313, -12276.25, 12.03559, 'Princess Stillpine');

-- NPC talk text insert from sniff
DELETE FROM `creature_text` WHERE `entry` IN(@ENTRY2,17702) AND `groupid`=0;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextID`) VALUES
(@ENTRY2,0,0, 'Thank you for saving me, $N! My father will be delighted!',12,0,100,0,0,0, 'Princess Stillpine',14323),
(17702, 0, 0, 'Face the wrath of Bristlelimb!', 14, 0, 100, 0, 0, 0, 'High Chief Bristlelimb',14322);

UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` IN(17320,17321,17702);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(17320,17321,17702) AND `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17320,0,0,0,0,0,100,0,5000,15000,60000,75000,11,32968,0,0,0,0,0,1,0,0,0,0,0,0,0,'Bristlelimb Shaman - IC - Cast Scorching Totem'),
(17320,0,1,0,0,0,100,0,0,3000,11000,15000,11,32967,0,0,0,0,0,2,0,0,0,0,0,0,0,'Bristlelimb Shaman - IC - Cast Flame Shock'),
(17320,0,2,0,6,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,84085,17702,0,0,0,0,0,'Bristlelimb Shaman - On Death - Set Data High Chief Bristlelimb'),
(17321,0,0,0,9,0,100,0,0,5,3000,7000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,'Bristlelimb Warrior - IC - Cast Strike'),
(17321,0,1,0,6,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,84085,17702,0,0,0,0,0,'Bristlelimb Warriot - On Death - Set Data High Chief Bristlelimb'),
(17702,0,0,1,25,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'High Chief Bristlelimb - On Reset - Set Invisible'),
(17702,0,1,0,61,0,100,0,0,0,0,0,18,768,0,0,0,0,0,1,0,0,0,0,0,0,0,'High Chief Bristlelimb - On Reset - Set Unit Flags Immune to NPC/PC'),
(17702,0,2,3,38,0,20,0,1,1,0,0,47,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'High Chief Bristlelimb - On Data Set - Set Visible'),
(17702,0,3,4,61,0,100,0,0,0,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,'High Chief Bristlelimb - On Data set - Remove Unit Flags Immune to NPC/PC'),
(17702,0,4,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'High Chief Bristlelimb - On Data set - Say'),
(17702,0,5,0,4,0,100,0,0,0,0,0,11,20753,0,0,0,0,0,1,0,0,0,0,0,0,0,'High Chief Bristlelimb - On Agro - Cast Demoralizing Roar'),
(17702,0,6,0,9,0,100,0,0,5,3000,5000,11,15793,0,0,0,0,0,2,0,0,0,0,0,0,0,'High Chief Bristlelimb - IC - Cast Maul');
