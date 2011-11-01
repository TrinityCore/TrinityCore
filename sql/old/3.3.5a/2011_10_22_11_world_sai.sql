-- Withered Corpse SAI
SET @ENTRY := 20561;
SET @SPELL_PROTECTORATE_IGNITER := 35372;
UPDATE `creature_template` SET `AIName`='SmartAI',`unit_flags`=`unit_flags`|388 WHERE `entry`=@ENTRY;
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@ENTRY,0,0,1,0,"29266"); -- Emote death spell (Permanent Feign Death)
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,0,@SPELL_PROTECTORATE_IGNITER,0,0,0,33,20561,0,0,0,0,0,7,0,0,0,0,0,0,0,"Withered Corpse - On Spellhit - Give Quest Credit"),
(@ENTRY,0,1,0,8,0,100,0,@SPELL_PROTECTORATE_IGNITER,0,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Corpse - On Spellhit - Die");

-- Protector Igniter can only be used inside Access Shaft Zeon
-- We are not removing the previous one, just adding an extra check
DELETE FROM `conditions` WHERE `SourceEntry`=35372 AND `ConditionValue1`=3880;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,35372,0,23,3880,0,0,0,'',"Protector Igniter can only be used inside Access Shaft Zeon");
