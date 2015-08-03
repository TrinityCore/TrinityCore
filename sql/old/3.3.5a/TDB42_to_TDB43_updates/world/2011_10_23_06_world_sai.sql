-- Sundered Rumbler SAI
SET @ENTRY := 18881;
SET @SPELL_SUMMON_SUNDERED_SHARD := 35310;
SET @SPELL_CREATE_ELEMENTAL_POWER := 34525;
SET @SPELL_ELEMENTAL_POWERDER_EXTRACTOR := 34520;
UPDATE `creature_template` SET `AIName`='SmartAI',`dmgschool`=3 WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,1,@SPELL_ELEMENTAL_POWERDER_EXTRACTOR,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sundered Rumbler - On Spellhit - Set Phase 1"),
(@ENTRY,0,1,0,6,1,100,0,0,0,0,0,11,@SPELL_CREATE_ELEMENTAL_POWER,2,0,0,0,0,1,0,0,0,0,0,0,0,"Sundered Rumbler - On Death - Cast Create Elemental Power"),
(@ENTRY,0,2,0,2,0,100,1,0,10,0,0,11,@SPELL_SUMMON_SUNDERED_SHARD,1,0,0,0,0,1,0,0,0,0,0,0,0,"Sundered Rumbler - At 10% HP - Cast Summon Sundered Shard");

-- Warp Aberration SAI
SET @ENTRY := 18865;
SET @SPELL_WARP_STORM := 36577;
SET @SPELL_ARCANE_SHIELD := 36640;
SET @SPELL_CREATE_ELEMENTAL_POWER := 34525;
SET @SPELL_ELEMENTAL_POWERDER_EXTRACTOR := 34520;
UPDATE `creature_template` SET `AIName`='SmartAI',`dmgschool`=6 WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,11,@SPELL_ARCANE_SHIELD,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warp Aberration - On Aggro - Cast Arcane Shield"),
(@ENTRY,0,1,0,8,0,100,1,@SPELL_ELEMENTAL_POWERDER_EXTRACTOR,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warp Aberration - On Spellhit - Set Phase 1"),
(@ENTRY,0,2,0,6,1,100,0,0,0,0,0,11,@SPELL_CREATE_ELEMENTAL_POWER,2,0,0,0,0,1,0,0,0,0,0,0,0,"Warp Aberration - On Death - Cast Create Elemental Power"),
(@ENTRY,0,3,0,0,0,100,0,2500,5000,30000,35000,11,@SPELL_WARP_STORM,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warp Aberration - In Combat - Cast Warp Storm");

-- Warp Storm SAI
SET @ENTRY := 21322;
SET @SPELL_WARP_STORM := 36580;
UPDATE `creature_template` SET `AIName`='SmartAI',`modelid1`=18402,`unit_flags`=33554822 WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,1,1000,1000,1000,1000,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warp Storm - On Just Summoned - Prevent Combat Movement"),
(@ENTRY,0,1,0,4,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warp Storm - On Aggro - Stop Auto Attack"),
(@ENTRY,0,2,0,0,0,100,0,1000,2000,3000,5000,11,@SPELL_WARP_STORM,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warp Storm - In Combat - Cast Warp Storm");

-- Conditions for quest item
DELETE FROM `conditions` WHERE `SourceEntry` IN (28547) AND `ConditionValue2` IN (18881,18865);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(18,0,28547,0,24,1,18881,0,0,"","Item Elemental Power Extractor can only be used if target is Sundered Rumbler"),
(18,0,28547,0,24,1,18865,0,0,"","Item Elemental Power Extractor can only be used if target is Warp Aberration");
