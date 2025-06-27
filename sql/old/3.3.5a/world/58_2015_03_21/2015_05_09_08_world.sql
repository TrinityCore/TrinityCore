--
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (29489, 29490);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (29489, 29490) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2949000, 2949001) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(29489, 0, 0, 0, 6, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Captain Welsington- On Death - Say text 1'),
(29489, 0, 1, 0, 9, 0, 100, 0, 8, 25000, 8000, 12000, 11, 20615, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0,0,'Captain Welsington - On 8-25 yard range - cast Intercept'),
(29489, 0, 2, 0, 0, 0, 100, 0, 3000, 7000, 5000, 10000, 11, 16856, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0,0,'Captain Welsington- IC - cast Mortal Strike'),
(29490, 0, 0, 0, 6, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Captain Hartford - On Death - Say text 1'),
(29490, 0, 1, 0, 9, 0, 100, 0, 0, 25000, 3000, 4000, 87, 2949000, 2949001, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Captain Hartford - On 1-25 yard range - Random action list'),
(2949000, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 20823, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0,0,'Captain Hartford - action list - cast Fireball'),
(2949001, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 20822, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0,0,'Captain Hartford - action list - cast Frostbolt'),
(29490, 0, 2, 0, 0, 0, 100, 0, 5000, 10000, 10000, 15000, 11, 11831, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0,0,'Captain Hartford - IC - cast Frost Nova');

DELETE FROM `creature_text` WHERE `entry` IN (29489, 29490);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextId`) VALUES
(29489,0,0,'Archbishop Landgren must know! Aaaaaagggghhhh.....!',12,0,100,0,0,0,'Captain Welsington', 30161),
(29490,0,0,'I don''t know where the grand admiral is. Go to hell!',12,0,100,0,0,0,'Captain Hartford', 30146);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN (29489, 29490);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,29489,0,0,9,0,12840,0,0,0,0,0,'','Captain Welsington- On Death - Say text 1 require quest 12840 taken'),
(22,1,29490,0,0,9,0,12840,0,0,0,0,0,'','Captain Hartford - On Death - Say text 1 require quest 12840 taken');
