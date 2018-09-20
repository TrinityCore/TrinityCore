-- 
-- Nimboya
DELETE FROM `creature_text` WHERE `CreatureID`=2497;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2497,0,0,"%s searches through the skulls...",16,0,100,0,0,0,732,0,"Nimboya"),
(2497,1,0,"%s continues searching, placing more skulls in his crate.",16,0,100,0,0,0,733,0,"Nimboya"),
(2497,2,0,"I am done inspecting the skulls, $n, and I am relieved.  Yenniku is not among them...",12,1,100,1,0,0,734,0,"Nimboya"),
(2497,3,0,"Ah, good $n.  Now let us see what tale these heads tell...",12,1,100,1,0,0,735,0,"Nimboya"),
(2497,4,0,"%s begins chanting...",16,0,100,0,0,0,736,0,"Nimboya"),
(2497,5,0,"There, $n.  You may now speak to the Bloodscalp chief and his witchdoctor.",12,1,100,1,0,0,740,0,"Nimboya");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2497;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2497 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (249700,249701) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2497,0,0,0,20,0,100,0,582,0,0,0,80,249700,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nimboya - On Quest 'Headhunting' Finished - Run Script 1"),
(2497,0,1,0,38,0,100,0,1,1,0,0,80,249701,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nimboya - On Data Set - Run Script 2"),
(249700,9,0,0,0,0,100,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nimboya - On Script 1 - Remove Npc Flag Questgiver+Gossip"),
(249700,9,1,0,0,0,100,0,1000,1000,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nimboya - On Script 1 - Set Emote State 69"),
(249700,9,2,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nimboya - On Script 1 - Say Line 0"),
(249700,9,3,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Nimboya - On Script 1 - Say Line 1"),
(249700,9,4,0,0,0,100,0,4000,4000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nimboya - On Script 1 - Set Emote State 0"),
(249700,9,5,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,"Nimboya - On Script 1 - Say Line 2"),
(249700,9,6,0,0,0,100,0,0,0,0,0,82,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nimboya - On Script 1 - Add Npc Flag Questgiver+Gossip"),
(249701,9,0,0,0,0,100,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nimboya - On Script 2 - Remove Npc Flag Questgiver+Gossip"),
(249701,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.70599,"Nimboya - On Script 2 - Set Orientation"),
(249701,9,2,0,0,0,100,0,0,0,0,0,1,3,0,0,0,0,0,7,0,0,0,0,0,0,0,"Nimboya - On Script 2 - Say Line 3"),
(249701,9,3,0,0,0,100,0,4000,4000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nimboya - On Script 2 - Say Line 4"),
(249701,9,4,0,0,0,100,0,0,0,0,0,11,5017,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nimboya - On Script 2 - Cast Divining Trance"),
(249701,9,5,0,0,0,100,0,7000,7000,0,0,1,5,0,0,0,0,0,7,0,0,0,0,0,0,0,"Nimboya - On Script 2 - Say Line 5"),
(249701,9,6,0,0,0,100,0,5000,5000,0,0,82,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nimboya - On Script 2 - Add Npc Flag Questgiver+Gossip"),
(249701,9,7,0,0,0,100,0,5000,5000,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nimboya - On Script 2 - Set Orientation");

-- Bubbling Cauldron
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=2076;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2076 AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=207600 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2076,1,0,0,20,0,100,0,584,0,0,0,80,207600,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bubbling Cauldron - On Quest 'Bloodscalp Clan Heads' Finished - Run Script"),
(207600,9,0,0,0,0,100,0,0,0,0,0,105,16,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bubbling Cauldron - On Script - Add Gameobject Flag"),
(207600,9,1,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,2497,0,0,0,0,0,0,"Bubbling Cauldron - On Script - Set Data"),
(207600,9,2,0,0,0,100,0,11000,11000,0,0,106,16,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bubbling Cauldron - On Script - Remove Gameobject Flag");
