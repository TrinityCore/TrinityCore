-- Shakes O'Breen SAI
SET @ENTRY := 2610;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI', ScriptName='' WHERE `entry`=113531;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 113531  AND `source_type` = 1;

INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,3,19,0,100,0,667,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Shakes O'Breen - On Quest 'Death From Below' Taken - Run Script"),
(@ENTRY,0,1,0,6,0,100,0,0,0,0,0,6,667,0,0,0,0,0,18,30,0,0,0,0,0,0,"Shakes O'Breen - On Just Died - Fail Quest 'Death From Below'"),
(@ENTRY,0,2,0,11,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shakes O'Breen - On Respawn - Add Npc Flag Questgiver"),
(@ENTRY,0,3,4,61,0,100,0,667,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shakes O'Breen - On Quest 'Death From Below' Taken - Remove Npc Flag Questgiver"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shakes O'Breen - On Just Created - react agressive"),
(113531,1,0,0,64,0,100,0,0,0,0,0,51,0,0,0,0,0,0,11,2775,50,0,0,0,0,0,"Shakes O'Breen - On gossip hello - kill");

-- Actionlist SAI
SET @ENTRY := 261000;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shakes O'Breen - On Script - Say Line 0"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,106,4,0,0,0,0,0,14,210721,113531,0,0,0,0,0,"Shakes O'Breen - On Script - remove flag from gob "),
(@ENTRY,9,2,0,0,0,100,0,9000,9000,0,0,12,2775,1,60000,0,0,0,8,0,0,0,-2158.637939, -1967.593628, 15.347894, 5.525547,"Shakes O'Breen - On Script - Summon Creature 'Daggerspine Marauder'"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,12,2775,1,60000,0,0,0,8,0,0,0,-2161.894531, -1968.629517, 15.641345, 5.462712,"Shakes O'Breen - On Script - Summon Creature 'Daggerspine Marauder'"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,12,2775,1,60000,0,0,0,8,0,0,0,-2158.246582, -1965.681763, 15.063377, 5.600158,"Shakes O'Breen - On Script - Summon Creature 'Daggerspine Marauder'"),
(@ENTRY,9,5,0,0,0,100,0,0,0,0,0,12,2775,1,60000,0,0,0,8,0,0,0,-2158.358643, -1971.417480, 15.596241, 4.967206,"Shakes O'Breen - On Script - Summon Creature 'Daggerspine Marauder'"),
(@ENTRY,9,6,0,0,0,100,0,20000,20000,0,0,12,2775,1,60000,0,0,0,8,0,0,0,-2158.637939, -1967.593628, 15.347894, 5.525547,"Shakes O'Breen - On Script - Summon Creature 'Daggerspine Marauder'"),
(@ENTRY,9,7,0,0,0,100,0,0,0,0,0,12,2775,1,60000,0,0,0,8,0,0,0,-2161.894531, -1968.629517, 15.641345, 5.462712,"Shakes O'Breen - On Script - Summon Creature 'Daggerspine Marauder'"),
(@ENTRY,9,8,0,0,0,100,0,0,0,0,0,12,2775,1,60000,0,0,0,8,0,0,0,-2158.246582, -1965.681763, 15.063377, 5.600158,"Shakes O'Breen - On Script - Summon Creature 'Daggerspine Marauder'"),
(@ENTRY,9,9,0,0,0,100,0,3000,3000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shakes O'Breen - On Script - Say Line 1"),
(@ENTRY,9,10,0,0,0,100,0,15000,15000,0,0,12,2775,1,60000,0,0,0,8,0,0,0,-2158.637939, -1967.593628, 15.347894, 5.525547,"Shakes O'Breen - On Script - Summon Creature 'Daggerspine Marauder'"),
(@ENTRY,9,11,0,0,0,100,0,0,0,0,0,12,2775,1,60000,0,0,0,8,0,0,0,-2161.894531, -1968.629517, 15.641345, 5.462712,"Shakes O'Breen - On Script - Summon Creature 'Daggerspine Marauder'"),
(@ENTRY,9,12,0,0,0,100,0,0,0,0,0,105,4,0,0,0,0,0,14,210721,113531,0,0,0,0,0,"Shakes O'Breen - On Script - Add  Flag to gob "),
(@ENTRY,9,13,0,0,0,100,0,30000,30000,0,0,15,667,0,0,0,0,0,17,0,100,0,0,0,0,0,"Shakes O'Breen - On Script - Quest Credit 'Death From Below'"),
(@ENTRY,9,14,0,0,0,100,0,30000,30000,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shakes O'Breen - On Script - Add Npc Flag ");

-- Daggerspine Marauder SAI
SET @ENTRY := 2775;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,63,0,30,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daggerspine Marauder - On Just Created - Say Line 0"),
(@ENTRY,0,1,0,63,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-2086.070068, -2028.859985, 3.220880, 2.670350,"Daggerspine Marauder - On Just Created - go to pos"),
(@ENTRY,0,2,0,63,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daggerspine Marauder - On Just Created - react agressive"),
(@ENTRY,0,3,0,10,0,100,0,0,30,3000,3000,49,0,0,0,0,0,0,19,2610,30,0,0,0,0,0,"Daggerspine Marauder - OOCLOS - Attack start");

DELETE FROM `creature_text` WHERE `entry` IN (2775, 2610);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(2775, 0, 0, 'Nothing will stop us! You will die!', 14, 0, 100, 0, 0, 0, 855, 0, 'Daggerspine Marauder'),
(2775, 0, 1, 'You''ve plundered our treasures too long.  Prepare to meet your watery grave!', 14, 0, 100, 0, 0, 0, 854, 0, 'Daggerspine Marauder'),
(2610, 0, 0, 'All hands to battle stations! Naga incoming!', 14, 0, 100, 0, 0, 0, 6372, 0, 'Shakes Breen'),
(2610, 1, 0, 'If we can just hold them now, I am sure we will be in the clear.', 12, 0, 100, 0, 0, 0, 863, 0, 'Shakes Breen');
