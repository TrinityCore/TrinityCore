-- 
-- Fix quests Incense for the Festival Scorchlings and Incense for the Summer Scorchlings 
DELETE FROM `creature_queststarter` WHERE `quest`=11964;
-- SAI for Festival Talespinner
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=16818;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=16818;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(16818,0,0,0,19,0,100,0,11966,0,0,0,11,46826,0,0,0,0,0,7,0,0,0,0,0,0,0,'Festival Talespinner - On target quest accepted - Cast Flame Keeper Breadcrumb');
-- SAI for Festival Loremaster
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=16817;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=16817;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(16817,0,0,0,19,0,100,0,11964,0,0,0,11,46825,0,0,0,0,0,7,0,0,0,0,0,0,0,'Festival Loremaster - On target quest accepted - Cast Flame Warden Breadcrumb');
-- Whisp of Ragnaros flag not selectable
UPDATE `creature_template` SET `unit_flags`=33554432 WHERE `entry`=26502;
-- SAI for Festival Schorchling
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=26520;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=26520;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=2652000;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26520,0,0,0,8,0,100,0,47104,0,0,0,80,2652000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Festival Scorchling - On spell hit - Run script '),
(2652000,9,1,0,0,0,100,0,0,0,0,0,1,0,2000,0,0,0,0,21,3,0,0,0,0,0,0,'Festival Scorchling - Action list - Say text 0'),
(2652000,9,2,0,0,0,100,0,1000,1000,0,0,1,1,1000,0,0,0,0,1,0,0,0,0,0,0,0,'Festival Scorchling - Action list - Say text 1'),
(2652000,9,3,0,0,0,100,0,2000,2000,0,0,11,47114,0,0,0,0,0,1,0,0,0,0,0,0,0,'Festival Scorchling - Action list - Cast grow'),
(2652000,9,4,0,0,0,100,0,0,0,0,0,1,2,2000,0,0,0,0,1,0,0,0,0,0,0,0,'Festival Scorchling - Action list - Say text 2'),
(2652000,9,5,0,0,0,100,0,3000,3000,0,0,11,47114,0,0,0,0,0,1,0,0,0,0,0,0,0,'Festival Scorchling - Action list - Cast grow'),
(2652000,9,6,0,0,0,100,0,0,0,0,0,1,3,2000,0,0,0,0,1,0,0,0,0,0,0,0,'Festival Scorchling - Action list - Say text 3'),
(2652000,9,7,0,0,0,100,0,3000,3000,0,0,11,47114,0,0,0,0,0,1,0,0,0,0,0,0,0,'Festival Scorchling - Action list - Cast grow'),
(2652000,9,8,0,0,0,100,0,0,0,0,0,1,4,2000,0,0,0,0,1,0,0,0,0,0,0,0,'Festival Scorchling - Action list - Say text 4'),
(2652000,9,9,0,0,0,100,0,1000,1000,0,0,1,5,1000,0,0,0,0,1,0,0,0,0,0,0,0,'Festival Scorchling - Action list - Say text 5'),
(2652000,9,10,0,0,0,100,0,2000,2000,0,0,11,47114,0,0,0,0,0,1,0,0,0,0,0,0,0,'Festival Scorchling - Action list - Cast grow'),
(2652000,9,11,0,0,0,100,0,0,0,0,0,1,6,2000,0,0,0,0,1,0,0,0,0,0,0,0,'Festival Scorchling - Action list - Say text 6'),
(2652000,9,12,0,0,0,100,0,3000,3000,0,0,11,47114,0,0,0,0,0,1,0,0,0,0,0,0,0,'Festival Scorchling - Action list - Cast grow'),
(2652000,9,13,0,0,0,100,0,0,0,0,0,1,7,2000,0,0,0,0,1,0,0,0,0,0,0,0,'Festival Scorchling - Action list - Say text 7'),
(2652000,9,14,0,0,0,100,0,0,0,0,0,11,47120,0,0,0,0,0,1,0,0,0,0,0,0,0,'Festival Scorchling - Action list - Summon Whisp of Ragnaros'),
(2652000,9,15,0,0,0,100,0,0,0,0,0,75,45889,0,0,0,0,0,11,26502,10,0,0,0,0,0,'Festival Scorchling - Action list - Aura Scorchling Blast'),
(2652000,9,16,0,0,0,100,0,3000,3000,0,0,11,47114,0,0,0,0,0,1,0,0,0,0,0,0,0,'Festival Scorchling - Action list - Cast grow'),
(2652000,9,17,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,11,26502,10,0,0,0,0,0,'Festival Scorchling - Action list - Despawn Whisp of Ragnaros '),
(2652000,9,18,0,0,0,100,0,0,0,0,0,1,8,2000,0,0,0,0,1,0,0,0,0,0,0,0,'Festival Scorchling - Action list - Say text 8'),
(2652000,9,19,0,0,0,100,0,0,0,0,0,11,47114,0,0,0,0,0,1,0,0,0,0,0,0,0,'Festival Scorchling - Action list - Cast grow'),
(2652000,9,20,0,0,0,100,0,0,0,0,0,1,9,1000,0,0,0,0,1,0,0,0,0,0,0,0,'Festival Scorchling - Action list - Say text 9'),
(2652000,9,21,0,0,0,100,0,1000,1000,0,0,11,46660,0,0,0,0,0,1,0,0,0,0,0,0,0,'Festival Scorchling - Action list - Cast Extinguished'),
(2652000,9,22,0,0,0,100,0,0,0,0,0,28,47114,0,0,0,0,0,1,0,0,0,0,0,0,0,'Festival Scorchling - Action list - Remove aura from grow'),
(2652000,9,23,0,0,0,100,0,3000,3000,0,0,1,10,2000,0,0,0,0,1,0,0,0,0,0,0,0,'Festival Scorchling - Action list - Say text 10');
-- Festival Scorchling texts
DELETE FROM `creature_text` WHERE `entry`= 26520;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(26520,0,0,'Thank you again, $n, for this delectable incense.',12,0,100,1,1000,0,'Festival Scorchling',25699),
(26520,1,0,'%s devours the incense.  It\'s ravenous!',16,0,100,1,1000,0,'Festival Scorchling',25717),
(26520,2,0,'So good! So packed with energy!',12,0,100,1,1000,0,'Festival Scorchling',25718),
(26520,3,0,'It has everything a growing scorchling needs!',12,0,100,1,1000,0,'Festival Scorchling',25719),
(26520,4,0,'I can feel the power SURGING within me!',12,0,100,1,1000,0,'Festival Scorchling',25730),
(26520,5,0,'%s bellows with laughter!',16,0,100,1,1000,0,'Festival Scorchling',25720),
(26520,6,0,'Now! Finally! Our plans can take effect!',12,0,100,1,1000,0,'Festival Scorchling',25721),
(26520,7,0,'KNEEL, LITTLE MORTAL! KNEEL BEFORE THE MIGHT OF THE HERALD OF RAGNAROS!',12,0,100,1,1000,0,'Festival Scorchling',25722),
(26520,8,0,'YOU WILL ALL PERISH IN FLAMES!',12,0,100,1,1000,0,'Festival Scorchling',25723),
(26520,9,0,'%s blinks...',16,0,100,1,1000,0,'Festival Scorchling',25724),
(26520,10,0,'Ah. I was merely jesting...',12,0,100,1,1000,0,'Festival Scorchling',25725);
-- SAI for Summer Schorchling
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=26401;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=26401;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=2640100;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26401,0,0,0,8,0,100,0,47104,0,0,0,80,2640100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Summer Scorchling - On spell hit - Start script'),
(2640100,9,1,0,0,0,100,0,0,0,0,0,1,0,2000,0,0,0,0,21,3,0,0,0,0,0,0,'Summer Scorchling - Action list - Say text 0'),
(2640100,9,2,0,0,0,100,0,1000,1000,0,0,1,1,1000,0,0,0,0,1,0,0,0,0,0,0,0,'Summer Scorchling - Action list - Say text 1'),
(2640100,9,3,0,0,0,100,0,2000,2000,0,0,11,47114,0,0,0,0,0,1,0,0,0,0,0,0,0,'Summer Scorchling - Action list - Cast grow'),
(2640100,9,4,0,0,0,100,0,0,0,0,0,1,2,2000,0,0,0,0,1,0,0,0,0,0,0,0,'Summer Scorchling - Action list - Say text 2'),
(2640100,9,5,0,0,0,100,0,3000,3000,0,0,11,47114,0,0,0,0,0,1,0,0,0,0,0,0,0,'Actionlist - Action 5 - Cast grow'),
(2640100,9,6,0,0,0,100,0,0,0,0,0,1,3,2000,0,0,0,0,1,0,0,0,0,0,0,0,'Summer Scorchling - Action list - Say text 3'),
(2640100,9,7,0,0,0,100,0,3000,3000,0,0,11,47114,0,0,0,0,0,1,0,0,0,0,0,0,0,'Summer Scorchling - Action list - Cast grow'),
(2640100,9,8,0,0,0,100,0,0,0,0,0,1,4,2000,0,0,0,0,1,0,0,0,0,0,0,0,'Summer Scorchling - Action list - Say text 4'),
(2640100,9,9,0,0,0,100,0,1000,1000,0,0,1,5,1000,0,0,0,0,1,0,0,0,0,0,0,0,'Summer Scorchling - Action list - Say text 5'),
(2640100,9,10,0,0,0,100,0,2000,2000,0,0,11,47114,0,0,0,0,0,1,0,0,0,0,0,0,0,'Summer Scorchling - Action list - Cast grow'),
(2640100,9,11,0,0,0,100,0,0,0,0,0,1,6,2000,0,0,0,0,1,0,0,0,0,0,0,0,'Summer Scorchling - Action list - Say text 6'),
(2640100,9,12,0,0,0,100,0,3000,3000,0,0,11,47114,0,0,0,0,0,1,0,0,0,0,0,0,0,'Summer Scorchling - Action list - Cast grow'),
(2640100,9,13,0,0,0,100,0,0,0,0,0,1,7,2000,0,0,0,0,1,0,0,0,0,0,0,0,'Summer Scorchling - Action list - Say text 7'),
(2640100,9,14,0,0,0,100,0,0,0,0,0,11,47120,0,0,0,0,0,1,0,0,0,0,0,0,0,'Summer Scorchling - Action list - Summon Whisp of Ragnaros'),
(2640100,9,15,0,0,0,100,0,0,0,0,0,75,45889,0,0,0,0,0,11,26502,10,0,0,0,0,0,'Summer Scorchling - Action list - Aura Scorchling Blast'),
(2640100,9,16,0,0,0,100,0,3000,3000,0,0,11,47114,0,0,0,0,0,1,0,0,0,0,0,0,0,'Summer Scorchling - Action list - Cast grow'),
(2640100,9,17,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,11,26502,10,0,0,0,0,0,'Summer Scorchling - Action list - Despawn Whisp of Ragnaros '),
(2640100,9,18,0,0,0,100,0,0,0,0,0,1,8,2000,0,0,0,0,1,0,0,0,0,0,0,0,'Summer Scorchling - Action list - Say text 8'),
(2640100,9,19,0,0,0,100,0,0,0,0,0,11,47114,0,0,0,0,0,1,0,0,0,0,0,0,0,'Summer Scorchling - Action list - Cast grow'),
(2640100,9,20,0,0,0,100,0,0,0,0,0,1,9,1000,0,0,0,0,1,0,0,0,0,0,0,0,'Summer Scorchling - Action list - Say text 9'),
(2640100,9,21,0,0,0,100,0,1000,1000,0,0,11,46660,0,0,0,0,0,1,0,0,0,0,0,0,0,'Summer Scorchling - Action list - Cast Extinguished'),
(2640100,9,22,0,0,0,100,0,0,0,0,0,28,47114,0,0,0,0,0,1,0,0,0,0,0,0,0,'Summer Scorchling - Action list - Remove aura from grow'),
(2640100,9,23,0,0,0,100,0,3000,3000,0,0,1,10,2000,0,0,0,0,1,0,0,0,0,0,0,0,'Summer Scorchling - Action list - Say text 10');
-- Summer Scorchling texts
DELETE FROM `creature_text` WHERE `entry`= 26401;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(26401,0,0,'Thank you again, $n, for this delectable incense.',12,0,100,1,1000,0,'Summer Scorchling',25699),
(26401,1,0,'%s devours the incense.  It\'s ravenous!',16,0,100,1,1000,0,'Summer Scorchling',25717),
(26401,2,0,'So good! So packed with energy!',12,0,100,1,1000,0,'Summer Scorchling',25718),
(26401,3,0,'It has everything a growing scorchling needs!',12,0,100,1,1000,0,'Summer Scorchling',25719),
(26401,4,0,'I can feel the power SURGING within me!',12,0,100,1,1000,0,'Summer Scorchling',25730),
(26401,5,0,'%s bellows with laughter!',16,0,100,1,1000,0,'Summer Scorchling',25720),
(26401,6,0,'Now! Finally! Our plans can take effect!',12,0,100,1,1000,0,'Summer Scorchling',25721),
(26401,7,0,'KNEEL, LITTLE MORTAL! KNEEL BEFORE THE MIGHT OF THE HERALD OF RAGNAROS!',12,0,100,1,1000,0,'Summer Scorchling',25722),
(26401,8,0,'YOU WILL ALL PERISH IN FLAMES!',12,0,100,1,1000,0,'Summer Scorchling',25723),
(26401,9,0,'%s blinks...',16,0,100,1,1000,0,'Summer Scorchling',25724),
(26401,10,0,'Ah. I was merely jesting...',12,0,100,1,1000,0,'Summer Scorchling',25725);

-- Add conditions for spell Scorchling Gets Incense
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=47104;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition` ,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,47104,0,1,31,0,3,26520,0,0,0,'','Scorchling gets incense can hit Festival Scorchling'),
(13,1,47104,0,2,31,0,3,26401,0,0,0,'','Scorchling gets incense can hit Summer Scorchling');
