-- 
-- DB/Quest: The Earthbinder
-- Tola'thion SAI
SET @ENTRY := 19293;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,10349,0,0,0,45,1,0,0,0,0,0,19,19294,50,0,0,0,0,0,"Tola'thion - On Quest 'The Earthbinder' Taken - Set Data 1 0");

-- Earthbinder Galandria Nightbreeze SAI
SET @ENTRY := 19294;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,0,1,0,0,0,1,0,0,0,0,0,0,21,100,0,0,0,0,0,0,"Earthbinder Galandria Nightbreeze - On Data Set 1 0 - Say Line 0"),
(@ENTRY,0,1,2,20,0,100,0,10349,0,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Earthbinder Galandria Nightbreeze - On Quest 'The Earthbinder' Finished - Run Script"),
(@ENTRY,0,2,5,61,0,100,0,10349,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Earthbinder Galandria Nightbreeze - On Quest 'The Earthbinder' Finished - Set Active On"),
(@ENTRY,0,3,0,38,0,100,0,2,0,0,0,80,@ENTRY*100+01,0,0,0,0,0,1,0,0,0,0,0,0,0,"Earthbinder Galandria Nightbreeze - On Data Set 2 0 - Run Script"),
(@ENTRY,0,4,0,11,0,100,0,0,0,0,0,81,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Earthbinder Galandria Nightbreeze - On Respawn - Set Npc Flags Gossip & Questgiver"),
(@ENTRY,0,5,0,61,0,100,0,10349,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Earthbinder Galandria Nightbreeze - On Quest 'The Earthbinder' Finished - Set Run Off");

-- Actionlist SAI
SET @ENTRY := 1929400;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,3000,3000,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Earthbinder Galandria Nightbreeze - On Script - Set Npc Flag "),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,21,50,0,0,0,0,0,0,"Earthbinder Galandria Nightbreeze - On Script - Set Orientation Closest Player"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Earthbinder Galandria Nightbreeze - On Script - Say Line 1"),
(@ENTRY,9,3,0,0,0,100,0,6000,6000,0,0,69,0,0,0,0,0,0,8,0,0,0,-286.7666,4729.429,18.4418,1.727876,"Earthbinder Galandria Nightbreeze - On Script - Move To Position"),
(@ENTRY,9,4,0,0,0,100,0,11000,11000,0,0,5,16,0,0,0,0,0,1,0,0,0,0,0,0,0,"Earthbinder Galandria Nightbreeze - On Script - Play Emote 16"),
(@ENTRY,9,5,0,0,0,100,0,3000,3000,0,0,5,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Earthbinder Galandria Nightbreeze - On Script - Play Emote 0"),
(@ENTRY,9,6,0,0,0,100,0,0,0,0,0,50,184450,60,0,0,0,0,8,0,0,0,-287.0193,4731.628,18.21704,2.583081,"Earthbinder Galandria Nightbreeze - On Script - Summon Gameobject 'Crimson Crystal Shard'"),
(@ENTRY,9,7,0,0,0,100,0,4000,4000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Earthbinder Galandria Nightbreeze - On Script - Say Line 2"),
(@ENTRY,9,8,0,0,0,100,0,0,0,0,0,12,20599,3,60000,1,0,0,8,0,0,0,-288.1897,4733.63,18.29823,5.044002,"Earthbinder Galandria Nightbreeze - On Script - Summon Creature 'Lured Colossus'");

-- Actionlist SAI
SET @ENTRY := 1929401;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-294.765991,4715.080078,28.186199,0.209440,"On Script - Move To Position"),
(@ENTRY,9,1,0,0,0,100,0,13000,13000,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0.209440,"On Script - Set Orientation Home Position"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,81,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Npc Flags Gossip & Questgiver");

-- Lured Colossus SAI
SET @ENTRY := 20599;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,0,0,0,0,0,45,2,0,0,0,0,0,19,19294,50,0,0,0,0,0,"Lured Colossus - On Just Died - Set Data 2 0");

DELETE FROM `creature_text` WHERE `entry`=19294;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(19294, 0, 0, 'Up here on the hill, $n.', 15, 0, 100, 0, 0, 0, 18293, 0, 'Earthbinder Galandria Nightbreeze'),
(19294, 1, 0, 'I have an idea.  Let\'s plant this shard in the ground and see what happens', 12, 0, 100, 0, 0, 0, 18289, 0, 'Earthbinder Galandria Nightbreeze'),
(19294, 2, 0, 'The evil emanating from the crystal shard has lured one of the colossi.  Put it down quick!', 12, 0, 100, 0, 0, 0, 18291, 0, 'Earthbinder Galandria Nightbreeze');
