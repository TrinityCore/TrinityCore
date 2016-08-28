--
SET @FIRSTTROUGH := 36727;
SET @SECONDTROUGH := 37155;
SET @THIRDTROUGH := 37156;
SET @BURNEFFECT := 42345;
SET @SPELLTHROWTORCH := 69228;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=@SPELLTHROWTORCH;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,@SPELLTHROWTORCH,0,0,31,0,3,@THIRDTROUGH, 0,0,"","Throw Torch target Third Trough"),
(13,1,@SPELLTHROWTORCH,0,1,31,0,3,@SECONDTROUGH,0,0,"","Throw Torch target Second Trough"),
(13,1,@SPELLTHROWTORCH,0,2,31,0,3,@FIRSTTROUGH, 0,0,"","Throw Torch target First Trough");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@FIRSTTROUGH;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@SECONDTROUGH;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@THIRDTROUGH;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@FIRSTTROUGH  AND `source_type`=0 AND `id` in (0,1);
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SECONDTROUGH AND `source_type`=0 AND `id` in (0,1);
DELETE FROM `smart_scripts` WHERE `entryorguid`=@THIRDTROUGH  AND `source_type`=0 AND `id` in (0,1);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@FIRSTTROUGH,0,0,1,8,0,100,0,@SPELLTHROWTORCH,0,0,0,33,@FIRSTTROUGH,0,0,0,0,0,7,0,0,0,0,0,0,0,"First Trough - On Spellhit 'Throw Torch' - Quest Credit 'Feed of Evil'"),
(@FIRSTTROUGH,0,1,0,61,0,100,0,@SPELLTHROWTORCH,0,0,0,11,@BURNEFFECT,0,0,0,0,0,1,0,0,0,0,0,0,0,"First Trough - On Spellhit 'Throw Torch' - Cast 'Cosmetic - Flame Patch'"),
(@SECONDTROUGH,0,0,1,8,0,100,0,@SPELLTHROWTORCH,0,0,0,33,@SECONDTROUGH,0,0,0,0,0,7,0,0,0,0,0,0,0,"Second Trough - On Spellhit 'Throw Torch' - Quest Credit 'Feed of Evil'"),
(@SECONDTROUGH,0,1,0,61,0,100,0,@SPELLTHROWTORCH,0,0,0,11,@BURNEFFECT,0,0,0,0,0,1,0,0,0,0,0,0,0,"Second Trough - On Spellhit 'Throw Torch' - Cast 'Cosmetic - Flame Patch'"),
(@THIRDTROUGH,0,0,1,8,0,100,0,@SPELLTHROWTORCH,0,0,0,33,@THIRDTROUGH,0,0,0,0,0,7,0,0,0,0,0,0,0,"Third Trough - On Spellhit 'Throw Torch' - Quest Credit 'Feed of Evil'"),
(@THIRDTROUGH,0,1,0,61,0,100,0,@SPELLTHROWTORCH,0,0,0,11,@BURNEFFECT,0,0,0,0,0,1,0,0,0,0,0,0,0,"Third Trough - On Spellhit 'Throw Torch' - Cast 'Cosmetic - Flame Patch'");
