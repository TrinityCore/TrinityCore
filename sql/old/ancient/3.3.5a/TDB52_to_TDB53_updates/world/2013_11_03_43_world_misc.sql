-- DB/Quest: Fix: Wooly Justice (12707)
SET @MEDALLION := 52596; -- Spell: Medallion of Mam'toth
SET @MAMMOTH   := 28851; -- NPC: Enraged Mammoth
SET @TRAMPLE   := 52603; -- Spell: Trample
SET @T_AURA    := 52607; -- Spell: Enraged Mammoth: Trample Aura for On Death Kill Credit
SET @DISCIPLE  := 28861; -- NPC: Mam'toth Disciple
SET @CREDIT    := 28876; -- NPC: Mam'toth Disciple Kill Credit Bunny

-- Add SAI for Enraged Mammoth
UPDATE `creature_template` SET `AIName`='SmartAI',`spell1`=52601,`spell2`=@TRAMPLE WHERE `entry`=@MAMMOTH;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@MAMMOTH AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@MAMMOTH,0,0,0,8,0,100,0,@MEDALLION,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Enraged Mammoth - On hit by spell from medallion - Change faction to friendly'),
(@MAMMOTH,0,1,0,1,0,100,0,10000,10000,10000,10000,2,1924,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Enraged Mammoth - On OOC for 10 sec - Change faction to back to normal'),
(@MAMMOTH,0,2,0,1,0,100,0,10000,10000,10000,10000,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Enraged Mammoth - On OOC for 10 sec - DESPAWN');

-- Add SAI for Mam'toth disciple
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@DISCIPLE;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@DISCIPLE AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@DISCIPLE,0,0,0,6,0,100,0,0,0,0,0,33,@CREDIT,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Mam''toth disciple - On death - Give credit to invoker, if Tampered'),
(@DISCIPLE,0,1,0,25,0,100,0,0,0,0,0,28,@T_AURA,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Mam''toth disciple - On reset - Remove aura from trample');

-- Add conditions for spell Medallion of Mam'toth
DELETE FROM `conditions` WHERE `SourceEntry`=@MEDALLION AND `SourceTypeOrReferenceId`=17;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(17,0,@MEDALLION,0,0,31,1,3,@MAMMOTH,0,0,0,'', 'Medallion of Mam''toth can hit only Enraged Mammoths');

-- Add conditions for spell Trample
DELETE FROM `conditions` WHERE `SourceEntry`=@TRAMPLE AND `SourceTypeOrReferenceId`=13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13,1,@TRAMPLE,0,0,31,0,3,@DISCIPLE,0,0,0,'', 'Trample effect 1 can hit only hit disciple of Mam''toth'),
(13,2,@TRAMPLE,0,0,31,0,3,@DISCIPLE,0,0,0,'', 'Trample effect 2 can hit only hit disciple of Mam''toth');

-- Add conditions for smart_event 0 of Mam'toth disciple
DELETE FROM `conditions` WHERE `SourceEntry`=@DISCIPLE AND `SourceTypeOrReferenceId`=22;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22,1,@DISCIPLE,0,0,1,1,@T_AURA,0,0,0,0,'', 'Mam''toth disciple 1st event is valid only, if has Tampered aura credit');

-- Add conditions for spell Trample Aura
DELETE FROM `conditions` WHERE `SourceEntry`=@T_AURA AND `SourceTypeOrReferenceId`=13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13,1,@T_AURA,0,0,31,0,3,@DISCIPLE,0,0,0,'', 'TAura effect can hit only Disciple of Mam''toth');
