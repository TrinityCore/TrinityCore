-- Reconnaissance Flight (12671)
-- additions
SET @PLANE          := 28710; -- Vic's Flying Machine
SET @SPELL_PLANE    := 52256; -- Vic's Flying Machine Validate (must have condition to target player)
SET @SPELL_LAND     := 52226; -- Land Flying Machine
SET @GOB_LANDING    := 190708; -- Landing Pad Focus
SET @SPELL_AGGRO    := 52259; -- Vic's Flying Machine Aggro Dummy
SET @NPC_SCREECHER  := 28170; -- Frosthowl Screecher
SET @SPELL_SBOLT    := 52257; -- Shadow Bolt

UPDATE `creature_template` SET InhabitType='4' WHERE `entry`=@PLANE;
DELETE FROM `vehicle_template_accessory` WHERE `entry`=@PLANE;

DELETE FROM `conditions` WHERE (`SourceEntry`=@SPELL_LAND AND `SourceTypeOrReferenceId`=17) OR (`SourceEntry` IN (@SPELL_AGGRO,@SPELL_SBOLT) AND `SourceTypeOrReferenceId`=13);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
-- because vehicles ignore spell focus we add an extra condition to fill in for this
(17,0,@SPELL_LAND,0,0,30,0,@GOB_LANDING,10,0,0,0,0,'','Requires Landing Pad Focus near to cast Land Flying Machine'),
(13,1,@SPELL_AGGRO,0,0,31,0,3,@NPC_SCREECHER,0,0,0,0,'','Vic''s Flying Machine Aggro Dummy to Frosthowl Screecher'),
(13,1,@SPELL_SBOLT,0,0,31,0,3,@PLANE,0,0,0,0,'','Shadow Bolt to Vic''s Flying Machine');

-- Frosthowl Screecher
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@NPC_SCREECHER;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC_SCREECHER,0,0,0,0,0,100,0,0,0,3000,4000,11,52257,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt');
