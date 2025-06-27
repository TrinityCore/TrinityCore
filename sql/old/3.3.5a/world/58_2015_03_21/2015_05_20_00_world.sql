--
-- Argent Champion SAI mechanic
SET @Arg_Champion := 33707;
SET @Script := 3370700;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`IN (@Arg_Champion, 33518);
UPDATE `creature_template_addon` SET  `auras`='63501 62852 64723' WHERE `entry`= @Arg_Champion;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@Arg_Champion, 33518) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@Script;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Arg_Champion,0,0,0,25,0,100,0,0,0,0,0,28,64223,0,0,0,0,0,1,0,0,0,0,0,0,0,'Arg Champion - On Reset - Remove auras from Defend'),
(@Arg_Champion,0,1,0,63,0,100,0,0,0,0,0,80,@Script,2,0,0,0,0,1,0,0,0,0,0,0,0,'Arg Champion - Just created - Call timed actionlist'),
(@Arg_Champion,0,2,0,52,0,100,0,0,@Arg_Champion,0,0,11,63010,0,0,0,0,0,7,0,0,0,0,0,0,0,'Arg Champion - On text over - Cast Charge'),
(@Arg_Champion,0,3,0,0,0,100,0,0,0,1500,4000,11,62544,0,0,0,0,0,2,0,0,0,0,0,0,0,'Arg Champion - IC - Cast Thrust'),
(@Arg_Champion,0,4,0,9,0,100,0,5,5,4000,7000,11,62575,0,0,0,0,0,2,0,0,0,0,0,0,0,'Arg Champion - On more than 5 yard range - Cast Shield-Breaker'),
(@Arg_Champion,0,5,0,0,0,100,0,9000,11000,9000,10000,46,20,0,0,0,0,0,1,0,0,0,0,0,0,0,'Arg Champion - IC - Move forward 20 yards'),
(@Arg_Champion,0,6,7,9,0,100,0,9,15,3000,3000,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'Arg Champion - On 10-12 yard range - Cast Charge'),
(@Arg_Champion,0,7,0,61,0,100,0,0,0,0,0,11,62575,0,0,0,0,0,2,0,0,0,0,0,0,0,'Arg Champion - Linked with previous event - Cast Shield-Breaker'),
(@Arg_Champion,0,8,9,2,0,100,1,1,6,60000,60000,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,'Arg Champion - On HP% between 1% and 6% - Change faction to 35'),
(@Arg_Champion,0,9,10,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,19,33518,100,0,0,0,0,0,'Arg Champion - On HP% between 1% and 6% - set data'),
(@Arg_Champion,0,10,11,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,21,50,0,0,0,0,0,0,'Arg Champion - Linked with previous event - Say text'),
(@Arg_Champion,0,11,0,61,0,100,0,0,0,0,0,41,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Arg Champion - Linked with previous event - Despawn in 3 sec'),
(@Arg_Champion,0,12,13,5,0,100,0,60000,60000,1,0,1,1,0,0,0,0,0,21,50,0,0,0,0,0,0,'Arg Champion - On player killed - Say text'),
(@Arg_Champion,0,13,0,61,0,100,0,0,0,0,0,41,4000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Arg Champion - Linked with previous event - Despawn in 1 ms'),
-- Timed actionlist 1
(@Script,9,0,0,0,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Arg Champion - Script 1 - Set run ON'),
(@Script,9,1,0,0,0,100,0,0,0,0,0,42,0,1,0,0,0,0,1,0,0,0,0,0,0,0,'Arg Champion - Script 1 - Set INVINCIBILITY'),
(@Script,9,2,0,0,0,100,0,0,0,0,0,11,62719,0,0,0,0,0,1,0,0,0,0,0,0,0,'Arg Champion - Script 1 - Cast Defend on self/Layer 1/'),
(@Script,9,3,0,0,0,100,0,0,0,0,0,11,62719,0,0,0,0,0,1,0,0,0,0,0,0,0,'Arg Champion - Script 1 - Cast Defend on self/Layer 2/'),
(@Script,9,4,0,0,0,100,0,0,0,0,0,11,62719,0,0,0,0,0,1,0,0,0,0,0,0,0,'Arg Champion - Script 1 - Cast Defend on self/Layer 3/'),
(@Script,9,5,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,8562.076172, 1115.047119, 556.787231, 2.587977,'Arg Champion - Script 1 - Move to pos'), 
(@Script,9,6,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Arg Champion - Script 1 - Set run Off'),
(@Script,9,7,0,0,0,100,0,0,0,0,0,11,64223,0,0,0,0,0,1,0,0,0,0,0,0,0,'Arg Champion - Script 1 - Cast aura TriggerS for Defend /10 sec one/'),
(@Script,9,8,0,0,0,100,0,3500,3500,0,0,2,14,0,0,0,0,0,1,0,0,0,0,0,0,0,'Arg Champion - Script 1 - Change faction to 14'),
(@Script,9,9,0,0,0,100,0,0,0,0,0,1,0,1500,0,0,0,0,21,50,0,0,0,0,0,0,'Arg Champion - Script 1 - Say text'),
(33518, 0, 0, 1, 62, 0, 100, 0, 10343, 0, 0, 0, 11, 63171, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Squire Danny  -On gossip select, summons Argent Champion" ),
(33518, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Squire Danny - On gossip select - Close gossip" ),
(33518, 0, 2, 0, 61,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Squire Danny  - Linked with previous event - store target'),
(33518, 0, 3, 0, 38,0,100,0,0,1,0,0,85,63516,0,0,0,0,0,12,1,0,0,0,0,0,0,'Squire Danny  - On data set - cast quest credit');

-- Argent Champions texts
DELETE FROM `creature_text` WHERE `entry`= @Arg_Champion;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@Arg_Champion,0,1,'Ready yourself!',12,0,100,1,1000,0,'Argent Champion',33753),
(@Arg_Champion,0,2,'Prepare yourself!',12,0,100,1,1000,0,'Argent Champion',33750),
(@Arg_Champion,0,3,'On your guard!',12,0,100,1,1000,0,'Argent Champion',33752),
(@Arg_Champion,0,4,'On your guard!',12,0,100,1,1000,0,'Argent Champion',33756),
(@Arg_Champion,0,5,'Let it begin!',12,0,100,1,1000,0,'Argent Champion',33758),
(@Arg_Champion,0,6,'Argent Champion is looking winded!',12,0,100,1,1000,0,'Argent Champion',0),
(@Arg_Champion,1,7,'Victory is mine!',12,0,100,1,1000,0,'Argent Champion',33771),
(@Arg_Champion,1,8,'It seems you still need more practice. Perhaps another time.',12,0,100,1,1000,0,'Argent Champion',33763),
(@Arg_Champion,1,9,'I have won. Better luck another time, friend.',12,0,100,1,1000,0,'Argent Champion',33773),
(@Arg_Champion,1,10,'I am afraid you will need more practice to defeat me.',12,0,100,1,1000,0,'Argent Champion',33772),
(@Arg_Champion,2,11,'I yield to you.',12,0,100,1,1000,0,'Argent Champion',33767),
(@Arg_Champion,2,12,'That was a well fought battle. I yield to you.',12,0,100,1,1000,0,'Argent Champion',33776),
(@Arg_Champion,2,13,'It would seem I underestimated your skills. Well done..',12,0,100,1,1000,0,'Argent Champion',33768),
(@Arg_Champion,2,14,'I have been defeated. Good fight!',12,0,100,1,1000,0,'Argent Champion',33868);

DELETE FROM `spell_target_position` WHERE `id`=63137;
INSERT INTO `spell_target_position` (`id`, `effIndex`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES 
(63137, 0, 571, 8542.52, 1083.690, 556.406, 1.3862);
