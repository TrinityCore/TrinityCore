-- scriptsupport for questaccept of [Q] Eranikus, Tyrant of the Dream
-- Malfurion Stormrage SAI
SET @ENTRY := 15362;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,54,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Malfurion Stormrage - On Just Summoned - Remove Npc Flag Questgiver"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Malfurion Stormrage - On Just Summoned - Run Script");

-- Actionlist SAI
SET @ENTRY := 1536200;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,3000,3000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 0"),
(@ENTRY,9,1,0,0,0,100,0,1500,1500,0,0,5,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Play Emote 2"),
(@ENTRY,9,2,0,0,0,100,0,2000,2000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 1"),
(@ENTRY,9,3,0,0,0,100,0,1000,1000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 2"),
(@ENTRY,9,4,0,0,0,100,0,2000,2000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 3"),
(@ENTRY,9,5,0,0,0,100,0,2000,2000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 4"),
(@ENTRY,9,6,0,0,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Add Npc Flag Questgiver");

DELETE FROM `creature_text` WHERE `entry`=15362;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(15362, 0, 0, 'The walls of the chamber tremble. Something is happening...', 16, 0, 100, 0, 0, 0, 11191, 0, 'Malfurion Stormrage'),
(15362, 1, 0, 'Be steadfast, champion. I know why it is that you are here and I know what it is that you seek. Eranikus will not give up the shard freely. He has been twisted... twisted by the same force that you seek to destroy.', 12, 0, 100, 0, 0, 0, 11193, 0, 'Malfurion Stormrage'),
(15362, 2, 0, 'Are you really surprised? Is it hard to believe that the power of an Old God could reach even inside the Dream? It is true - Eranikus, Tyrant of the Dream, wages a battle against us all. The Nightmare follows in his wake of destruction.', 12, 0, 100, 0, 0, 0, 11194, 0, 'Malfurion Stormrage'),
(15362, 3, 0, 'Understand this, Eranikus wants nothing more than to be brought to Azeroth from the Dream. Once he is out, he will stop at nothing to destroy my physical manifestation. This, however, is the only way in which you could recover the scepter shard.', 12, 0, 100, 0, 0, 0, 11195, 0, 'Malfurion Stormrage'),
(15362, 4, 0, 'You will bring him back into this world, champion.', 12, 0, 100, 0, 0, 0, 11196, 0, 'Malfurion Stormrage');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=1 AND `SourceEntry`=15362;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 1, 15362, 0, 0, 23, 0, 1477, 0, 0, 0, 0, 0, '', 'Malfurion Stormrage - Only run SAI in the Sunken Temple');
