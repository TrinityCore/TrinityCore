-- Prince Liam Greymane: one line every 20.6 s, 61.8 s per round
DELETE FROM `smart_scripts` WHERE `entryorguid`=34850 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(34850,0,0,0,60,0,100,0,5000,5000,61800,61800,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Prince Liam Greymane - On Update - Say Line 0'),
(34850,0,1,0,60,0,100,0,25600,25600,61800,61800,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Prince Liam Greymane - On Update - Say Line 1'),
(34850,0,2,0,60,0,100,0,46200,46200,61800,61800,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Prince Liam Greymane - On Update - Say Line 2');

-- Panicked Citizen: the eight cowering ones now and then ask about the rooftops
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-376247,-376249,-376252,-376313,-376333,-376341,-376354,-376355) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-376247,0,0,0,1,0,10,0,10000,60000,60000,60000,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Panicked Citizen - Out of Combat - Say Line 0'),
(-376249,0,0,0,1,0,10,0,10000,60000,60000,60000,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Panicked Citizen - Out of Combat - Say Line 0'),
(-376252,0,0,0,1,0,10,0,10000,60000,60000,60000,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Panicked Citizen - Out of Combat - Say Line 0'),
(-376313,0,0,0,1,0,10,0,10000,60000,60000,60000,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Panicked Citizen - Out of Combat - Say Line 0'),
(-376333,0,0,0,1,0,10,0,10000,60000,60000,60000,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Panicked Citizen - Out of Combat - Say Line 0'),
(-376341,0,0,0,1,0,10,0,10000,60000,60000,60000,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Panicked Citizen - Out of Combat - Say Line 0'),
(-376354,0,0,0,1,0,10,0,10000,60000,60000,60000,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Panicked Citizen - Out of Combat - Say Line 0'),
(-376355,0,0,0,1,0,10,0,10000,60000,60000,60000,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Panicked Citizen - Out of Combat - Say Line 0');

-- Panicked Citizen at the gate: fixed 161 s conversation with the gate guard
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-376285,-376310) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4408600 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-376285,0,0,0,1,0,100,0,1000,6000,6000,9000,0,10,1,5,18,20,430,0,1,0,0,0,0,0,0,0,0,'Panicked Citizen - Out of Combat - Play Random Emote (1, 5, 18, 20, 430)'),
(-376285,0,1,0,1,0,100,0,0,0,161000,161000,0,80,4408600,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Panicked Citizen - Out of Combat - Run Script'),
(4408600,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Panicked Citizen - Actionlist - Say Line 0'),
(4408600,9,1,0,0,0,100,0,40000,40000,0,0,0,1,1,0,0,0,0,0,10,376310,34864,0,0,0,0,0,0,'Panicked Citizen - Actionlist - Say Line 1 (Gilneas City Guard)'),
(4408600,9,2,0,0,0,100,0,16000,16000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Panicked Citizen - Actionlist - Say Line 1'),
(4408600,9,3,0,0,0,100,0,33000,33000,0,0,0,1,2,0,0,0,0,0,10,376310,34864,0,0,0,0,0,0,'Panicked Citizen - Actionlist - Say Line 2 (Gilneas City Guard)'),
(4408600,9,4,0,0,0,100,0,25000,25000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Panicked Citizen - Actionlist - Say Line 2'),
(4408600,9,5,0,0,0,100,0,28000,28000,0,0,0,1,1,0,0,0,0,0,10,376310,34864,0,0,0,0,0,0,'Panicked Citizen - Actionlist - Say Line 1 (Gilneas City Guard)');

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` IN (34850, 34851, 34864, 44086);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(34850, 0, 0, 'Stand ready, guards!  We don''t know how many intruders we''re dealing with, but the Headlands are overrun and we''re cut off from the harbor towns.  Expect to be outnumbered.', 12, 0, 100, 1, 0, 19614, 36124, 0, 'Prince Liam Greymane'),
(34850, 1, 0, 'I want the perimeter secured and the gates manned by two guards at all times.  No one gets in, no one gets out.', 12, 0, 100, 1, 0, 19615, 36125, 0, 'Prince Liam Greymane'),
(34850, 2, 0, 'We protected Gilneas from the Scourge.  We protected Gilneas during the Northgate rebellion.  We will protect Gilneas from whatever this new threat may be.', 12, 0, 100, 25, 0, 19616, 36126, 0, 'Prince Liam Greymane'),
(34851, 0, 0, 'What... what are those things on the rooftops?', 12, 0, 100, 0, 0, 0, 39313, 0, 'Panicked Citizen'),
(34864, 0, 0, 'No one''s allowed to leave. Prince Liam''s orders.', 12, 0, 100, 1, 0, 0, 44373, 0, 'Gilneas City Guard'),
(34864, 1, 0, 'It isn''t safe to leave, there''s something lurking out there in the woods.', 12, 0, 100, 1, 0, 0, 44374, 0, 'Gilneas City Guard to Panicked Citizen'),
(34864, 2, 0, 'Stay calm. We have everything under control.', 12, 0, 100, 1, 0, 0, 44375, 0, 'Gilneas City Guard to Panicked Citizen'),
(44086, 0, 0, 'What''s going on? I thought I saw something on the rooftops.', 12, 0, 100, 0, 0, 0, 44379, 0, 'Panicked Citizen to Gilneas City Guard'),
(44086, 1, 0, 'You can''t do this to us!', 12, 0, 100, 0, 0, 0, 44377, 0, 'Panicked Citizen to Gilneas City Guard'),
(44086, 2, 0, 'My children are in Stormglen alone! I have to get to them!', 12, 0, 100, 0, 0, 0, 44378, 0, 'Panicked Citizen to Gilneas City Guard');

-- Gilneas City Guard, Slain Guard: rooted without the hover animation
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000100 WHERE `Entry` IN (34864, 39095) AND `DifficultyID`=0; -- Sessile, CanSwim
