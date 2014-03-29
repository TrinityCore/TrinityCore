-- Vile Like Fire! (13071)

SET @NPC_DRAKE            := 30272; -- Njorndar Proto-Drake (not mount)
SET @NPC_DRAKE_MOUNT      := 30564; -- Njorndar Proto-Drake
SET @NPC_FIRE_BUNNY       := 30599; -- Vile Like Fire! Fire Bunny
SET @NPC_CREDIT           := 30576; -- Vile Like Fire! Kill Credit Bunny
SET @SPELL_MOUNT          := 57401; -- Njorndar Proto-Drake
SET @SPELL_STRAFE         := 7769; -- Strafe Jotunheim Building
SET @AURA_OUT_OF_AREA     := 57404; -- Out of Jotunheim! (mount out of area)
SET @SPELL_SPREAD_FIRE    := 57469; -- Vile Like Fire!: Spread the Fire
SET @SPELL_FIRE           := 7448; -- Vile Like Fire!: Fire

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=@NPC_DRAKE;
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`,`user_type`) VALUES
(@NPC_DRAKE,@SPELL_MOUNT,1,0);

UPDATE `creature_template` SET `npcflag`=16777216,`faction_A`=190,`faction_H`=190 WHERE `entry`=@NPC_DRAKE;
UPDATE `creature_template` SET `AIName`='SmartAI',`minlevel`=80,`maxlevel`=80,`exp`=2,`unit_flags`=8,`HoverHeight`=2.25,`InhabitType`=4,`spell1`=57493,`spell3`=7769 WHERE `entry`=@NPC_DRAKE_MOUNT;

DELETE FROM `creature_template_addon` WHERE `entry`=@NPC_DRAKE_MOUNT;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@NPC_DRAKE_MOUNT,0,0,50331648,1,0,'57403'); -- 57403: Flight

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (@SPELL_STRAFE,@SPELL_SPREAD_FIRE);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,@SPELL_STRAFE,0,0,31,0,3,@NPC_CREDIT,0,0,0,'','Strafe Jotunheim Building targets Kill Credit Bunny'),
(13,1,@SPELL_SPREAD_FIRE,0,0,31,0,3,@NPC_CREDIT,0,0,0,'','Spread the Fire targets Kill Credit Bunny'),
(13,1,@SPELL_SPREAD_FIRE,0,1,31,0,3,@NPC_FIRE_BUNNY,0,0,0,'','Spread the Fire targets Kill Credit Bunny');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=@SPELL_SPREAD_FIRE;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(@SPELL_SPREAD_FIRE,@SPELL_FIRE,1,'Spread Fire triggers Fire');

UPDATE `creature_template` SET `flags_extra`=128 WHERE `entry`=@NPC_FIRE_BUNNY;
UPDATE `creature_template` SET `AIName`='SmartAI',`flags_extra`=128 WHERE `entry`=@NPC_CREDIT;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@NPC_DRAKE_MOUNT;

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (@NPC_CREDIT,@NPC_DRAKE_MOUNT);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC_CREDIT,0,0,0,23,0,100,0,@SPELL_FIRE,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'On no aura - Set phase 1'),
(@NPC_CREDIT,0,1,2,8,1,100,0,@SPELL_STRAFE,0,0,0,11,@SPELL_SPREAD_FIRE,0,0,0,0,0,1,0,0,0,0,0,0,0,'On spellhit - Cast Spread Fire'),
(@NPC_CREDIT,0,2,3,61,1,100,0,0,0,0,0,45,0,1,0,0,0,0,7,0,0,0,0,0,0,0,'On link - Set data'),
(@NPC_CREDIT,0,3,0,61,1,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Set phase 1'),
--
(@NPC_DRAKE_MOUNT,0,0,0,38,0,100,0,0,1,0,0,33,@NPC_CREDIT,0,0,0,0,0,23,0,0,0,0,0,0,0,'On Data - Give killcredit owner');

DELETE FROM `conditions` WHERE `SourceEntry` = 57402;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(17, 1, 57402, 0, 0, 23, 0, 4526, 0, 0, 0, 0, 0, '', 'Dismount player when not in intended zone');
