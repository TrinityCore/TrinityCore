SET @BAT := 23959;
SET @BUNNY := 24230;

UPDATE `creature_template` SET `AIName`='SmartAI', `flags_extra`=`flags_extra`|128 WHERE `entry`=@BUNNY;
UPDATE `creature_template` SET `inhabitType`=4, `AIName`='SmartAI' WHERE `entry`=@BAT;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@BAT,@BUNNY) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@BAT,0,0,0,38,0,100,0,0,1,0,0,69,1,0,0,0,0,0,19,@BUNNY,50,0,0,0,0,0,'Darkclaw Bat - On data set 0 1 - Move to position'),
(@BAT,0,1,0,34,0,100,0,0,1,0,0,45,0,1,0,0,0,0,19,@BUNNY,5,0,0,0,0,0,'Darkclaw Bat - On movement inform - Spellcast Scare the Guano Out of Them!: Cast Spell 1 On Target''s Master'),
(@BUNNY,0,0,1,54,0,100,0,0,0,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Firecracker Bunny - Just summoned - Root'),
(@BUNNY,0,1,0,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,19,@BAT,50,0,0,0,0,0,'Firecracker Bunny - Just summoned - Set data 0 1 Darkclaw Bat'),
(@BUNNY,0,2,0,38,0,100,0,0,1,0,0,11,62068,0,0,0,0,0,1,0,0,0,0,0,0,0,'Firecracker Bunny - On spellhit Scare the Guano Out of Them!: Cast Spell 1 On Target''s Master - Crosscast owner Scare the Guano Out of Them!: Cast Spell 1 On Target''s Master'),
(@BUNNY,0,3,0,8,0,100,0,62068,0,0,0,86,43307,0,23,0,0,0,0,0,0,0,0,0,0,0,'Firecracker Bunny - On spellhit Scare the Guano Out of Them!: Cast Spell 1 On Target''s Master - Crosscast owner Scare the Guano Out of Them!: Cast Spell 1 On Target''s Master');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=43307;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,43307,0,0,31,0,3,@BUNNY,0,0,0,'','Spell Scare the Guano Out of Them!: Summon Darkclaw Guano targets Firecracker Bunny');
