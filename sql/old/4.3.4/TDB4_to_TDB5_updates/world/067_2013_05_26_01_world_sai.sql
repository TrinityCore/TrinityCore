SET @THANE          := 29919;
SET @SPELL          := 31696;
SET @B_STRIKE       := 58460;
SET @REND           := 16509;
SET @P_SMASH        := 60868;
SET @EVENT          := 19490;

DELETE FROM `disables` WHERE `sourceType`=0 AND `entry` IN (@SPELL);
INSERT INTO `disables`(`sourceType`,`entry`,`flags`,`comment`) VALUES
(0,@SPELL,64,'Ignore LOS on Thane');

DELETE FROM `event_scripts` WHERE `id`=@EVENT;
INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES
(@EVENT,0,15,53799,4,29919,30,0,0,0);

DELETE FROM `creature_text` WHERE `entry` IN (@THANE);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@THANE,1,0, 'By order of Duke Lankral, Commander of the Knights of the Ebon Blade, Vanquisher of the Scourge and Conquerer of The Shadow Vault, you are hearby served notice to cease and desist from all activities providing materiel assistance, vrykul, and any other type of support to the Lich King. Failure to comply will result in your immediate destruction. My messenger will serve as the instrument of my will. What is your decision?',12,0,100,0,0,0,'Thane'),
(@THANE,2,0, 'What is this?',14,0,100,0,0,0,'Thane'),
(@THANE,3,0, 'My answer? Here''s my answer, little messenger!',14,0,100,0,0,0,'Thane'),
(@THANE,4,0, 'I will feed you to the dogs!',14,0,100,0,0,0,'Thane');

UPDATE `creature_template` SET AIName='SmartAI' WHERE entry = @THANE;
DELETE FROM `smart_scripts` WHERE source_type=0 AND entryorguid = @THANE;
DELETE FROM `smart_scripts` WHERE source_type=9 AND entryorguid = @THANE*100;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@THANE,0,0,1,4,0,100,0,0,0,0,0,1,2,12000,0,0,0,0,1,0,0,0,0,0,0,0,'Thane - On spellhit - Say text2'),
(@THANE,0,1,2,61,0,100,0,0,0,0,0,18,33685504,0,0,0,0,0,1,0,0,0,0,0,0,0,'Thane - On Link - Set Unit Flags'),
(@THANE,0,2,0,61,0,100,0,0,0,0,0,84,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Thane - On Link - Make player say Text1'),
(@THANE,0,3,0,52,0,100,0,2,@THANE,0,0,1,3,4000,0,0,0,0,1,0,0,0,0,0,0,0,'Thane - On Text2 over - Say Text3'),
(@THANE,0,4,5,52,0,100,0,3,@THANE,0,0,1,4,4000,0,0,0,0,1,0,0,0,0,0,0,0,'Thane - On Text3 over - Say Text4'),
(@THANE,0,5,0,61,0,100,0,0,0,0,0,19,33685504,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Thane - On Link - Remove unit flags'),
(@THANE,0,6,0,0,0,100,0,4000,7000,4000,7000,11,@B_STRIKE,0,0,0,0,0,5,0,0,0,0,0,0,0,'Thane - In Combat - Cast Brutal Strike'),
(@THANE,0,7,0,0,0,100,0,4000,15000,4000,15000,11,@REND,0,0,0,0,0,5,0,0,0,0,0,0,0,'Thane - In Combat - Cast Rend'),
(@THANE,0,8,0,0,0,100,0,12000,25000,12000,25000,11,@P_SMASH,0,0,0,0,0,5,0,0,0,0,0,0,0,'Thane - In Combat - Cast Powerful Smash');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 13 AND `SourceEntry`=@SPELL;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13,1,@SPELL,0,0,31,0,3,@THANE,0,0,0,'','Shadow Decree hits only Thane');
