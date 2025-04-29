-- More Blizz like intro for quest "Cave Mushrooms".

-- Correct emote
UPDATE `creature_text` SET `Emote`=25 WHERE `CreatureID`=3583 AND `GroupID`=0;

DELETE FROM `smart_scripts` WHERE `entryorguid`=358300 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES

-- Barithras Moonshade Timed Scripts
(358300,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Barithras Moonshade - On Script - Set Orientation Invoker"),
(358300,9,1,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Barithras Moonshade - On Script - Say Line 1"),
(358300,9,2,0,0,0,100,0,5000,5000,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,5.25,"Barithras Moonshade - On Script - Set Orientation"),
(358300,9,3,0,0,0,100,0,500,500,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Barithras Moonshade - On Script - Say Line 0"),
(358300,9,4,0,0,0,100,0,5000,5000,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Barithras Moonshade - On Script - Set Orientation Home Position");
