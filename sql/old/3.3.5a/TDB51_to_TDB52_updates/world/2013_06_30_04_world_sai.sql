-- The Black Knight's Curse (14016) quest trigger SAI by nelegalno based on C++ script by Sherriff: http://pastebin.com/1ExVqtLe
SET @TRIGGER := 34735;

UPDATE `creature_template` SET ainame='SmartAI' WHERE `entry`=@TRIGGER;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@TRIGGER AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@TRIGGER, 0, 0, 1, 10, 0, 100, 0, 1, 5, 5000, 5000, 12, 35116, 4, 60000, 0, 0, 0, 8, 0, 0, 0, 8451.91, 459.163, 596.072, 0.80, "Link - SummonCreature Cult Saboteur"),
(@TRIGGER, 0, 1, 0, 61, 0, 100, 0, 0, 0,    0,    0, 12, 35127, 4, 60000, 0, 0, 0, 8, 0, 0, 0, 8456.20, 458.904, 596.072, 1.55, "Link - SummonCreature Cult Assassin");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=@TRIGGER AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,@TRIGGER,0,0, 9,0,14016, 0,0,0,0,'',"Execute SAI only if player is on The Black Knight's Curse quest"),
(22,1,@TRIGGER,0,0,29,0,35127,50,0,1,0,'',"Execute SAI only if no Cult Assassin within 50y of Black Knight's Grave");

-- Written by Sherriff: http://pastebin.com/gkSqDc52
-- Add text
DELETE FROM `creature_text` WHERE `entry`=35116;
INSERT INTO `creature_text` VALUES 
(35116,0,0, "What do you think you're doing?",12,0,0,1,0,0, ''),
(35116,1,0, "You're too late to stop our plan.",12,0,0,1,0,0, ''),
(35116,2,0, "See to it that I'm not followed.",12,0,0,1,0,0, '');

DELETE FROM `creature_text` WHERE `entry`=35127;
INSERT INTO `creature_text` VALUES 
(35127,0,0, "Gladly",12,0,1,0,0,0, '');

-- SAI
UPDATE `creature_template` SET ainame='SmartAI' WHERE `entry`= 35116;
UPDATE `creature_template` SET ainame='SmartAI' WHERE `entry`= 35127;

DELETE FROM `smart_scripts` WHERE `entryorguid`=35116;
INSERT INTO `smart_scripts` VALUES
-- need add (The saboteur ports out, via spell)
(35116, 0, 0, 0, 54, 0, 100, 1, 0, 0, 0, 0, 71, 0, 0, 3334, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,''), -- Equip shovel ID: 3334 ?
(35116, 0, 1, 0, 38, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,''),
(35116, 0, 2, 0, 1, 1, 100, 1, 5000, 5000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,'');

DELETE FROM `smart_scripts` WHERE `entryorguid`=35127;
DELETE FROM `smart_scripts` WHERE `entryorguid`=35127*100;
INSERT INTO `smart_scripts` VALUES
(35127, 0, 0, 1, 54,0,100,0,0,0,0,0,80,35127*100,0,2,0,0,0,1,0,0,0,0,0,0,0,""),
(35127, 0, 1, 0, 61,0,100,0,0,0,0,0,17,68,0,0,0,0,0,1,0,0,0,0,0,0,0,""),
-- script
(35127*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,''),
(35127*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,''),
(35127*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,''),
(35127*100, 9, 3, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 11, 35116, 20, 0, 0, 0, 0, 0,''),
(35127*100, 9, 4, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 11, 35116, 20, 0, 0, 0, 0, 0,''),
(35127*100, 9, 5, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 11, 35116, 20, 0, 0, 0, 0, 0,''),
(35127*100, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 0, 0, 0, 0, 0, 0, 11, 35116, 20, 0, 0, 0, 0, 0,''),
(35127*100, 9, 7, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,''),
(35127*100, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,''),
(35127*100, 9, 9, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 2, 14, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,''),
(35127*100, 9, 10, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,''), -- emote 0 or roar?
-- combat
(35127, 0, 2, 0, 0, 0, 100, 0, 3000, 4000, 14000, 15000, 11, 60842, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0,''),
(35127, 0, 3, 0, 0, 0, 100, 0, 1000, 2000, 7000, 8000, 11, 14873, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0,''),
-- on death(quest credit)
(35127, 0, 4, 0, 6, 0, 100, 1, 0, 0, 0, 0, 85, 66785, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0,'');
