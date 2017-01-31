-- [Q] Fel Spirits

-- Port Fel Spirit's EAI to creature_template_addon
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=22454;
DELETE FROM `creature_template_addon` WHERE `entry`=22454;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (22454,0,0,1,0,"39205");
UPDATE `creature_template` SET `AIName`='',`unit_flags`=32768,`baseattacktime`=2000 WHERE `entry`=22454;

-- Shattered Hand Berserker SAI
SET @ENTRY := 16878;
SET @SPELL_CHARGE := 35570;
SET @SPELL_ENRAGE := 8599;
SET @SPELL_SUMMON := 39206;
SET @SPELL_CONTRITION := 39184;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,11,@SPELL_CHARGE,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Berserker - On Aggro - Cast Charge"),
(@ENTRY,0,1,0,8,0,100,0,@SPELL_CONTRITION,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Berserker - On Spellhit - Set Phase 1"),
(@ENTRY,0,2,0,6,1,100,0,0,0,0,0,11,@SPELL_SUMMON,2,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Berserker - On Death (P1) - Cast Summon Fel Spirit"),
(@ENTRY,0,3,4,2,0,100,1,0,30,0,0,11,@SPELL_ENRAGE,1,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Berserker - At 30% HP - Cast Enrage"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Shattered Hand Berserker - At 30% HP - Say Line 0");
-- Text
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Shattered Hand Berserker");

-- Anchorite Relic Bunny SAI
SET @ENTRY := 22444;
SET @SPELL_CONTRITION := 39184;
UPDATE `creature_template` SET `AIName`='SmartAI',`exp`=2,`minlevel`=35,`maxlevel`=35,`baseattacktime`=2000,`unit_flags`=`unit_flags`|2048 WHERE `entry`=@ENTRY;
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@ENTRY,0,0,1,0, NULL);
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anchorite Relic Bunny - Just Summoned - Prevent Combat Movemenet"),
(@ENTRY,0,1,0,60,0,100,0,1000,3000,15000,20000,11,@SPELL_CONTRITION,0,0,0,0,0,11,16878,0,0,0,0,0,0,"Anchorite Relic Bunny - On Update - Cast Anchorite Contrition");

-- Condition for spell Anchorite Contrition
DELETE FROM  `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (@SPELL_CONTRITION,@SPELL_SUMMON);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,0,@SPELL_CONTRITION,0,18,1,16878,0,0,'',"Spell Anchorite Contrition targets Shattered Hand Berserker"),
(13,0,@SPELL_SUMMON,0,18,1,22444,0,0,'',"Spell Summon Fel Spirit targets Anchorite Relic Bunny");
