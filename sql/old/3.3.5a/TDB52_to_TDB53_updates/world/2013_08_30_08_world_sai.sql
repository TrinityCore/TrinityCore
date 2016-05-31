-- Deeprun Rat Roundup (6661)

SET @QUEST                 := 6661;  -- Random Comment
SET @NPC_RAT               := 13016; -- Deeprun Rat
SET @NPC_ENTHRALLED_RAT    := 13017; -- Enthralled Deeprun Rat
SET @NPC_MONTY             := 12997; -- Monty <Rat Extermination Specialist>
SET @SPELL_FLUTE           := 21050; -- Melodious Rapture
SET @SPELL_FLUTE_VISUAL    := 21051; -- Melodious Rapture Visual (DND)
SET @SPELL_BASH            := 21052; -- Monty Bashes Rats (DND)

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@NPC_RAT;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@NPC_ENTHRALLED_RAT;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@NPC_MONTY;

UPDATE `creature_model_info` SET `bounding_radius`=1,`combat_reach`=1,`gender`=2 WHERE `modelid`=1141; -- Deeprun Rat
-- Addon data for creature 13016 (Deeprun Rat)
DELETE FROM `creature_template_addon` WHERE `entry`=@NPC_RAT;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@NPC_RAT,0,0,1,0, ''); -- Deeprun Rat

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@NPC_RAT,@NPC_ENTHRALLED_RAT,@NPC_MONTY);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC_RAT,0,0,1,8,0,100,1,@SPELL_FLUTE,0,0,0,12,@NPC_ENTHRALLED_RAT,2,120000,0,0,0,1,0,0,0,0,0,0,0,'Deeprun Rat - On Spellhit - Summon Enthralled Rat'),
(@NPC_RAT,0,1,0,61,0,100,0,0,0,0,0,41,100,1,0,0,0,0,1,0,0,0,0,0,0,0,'Deeprun Rat - On link - Despawn'),
--
(@NPC_ENTHRALLED_RAT,0,0,1,54,0,100,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deeprun Rat - Just summoned - Update Faction'),
(@NPC_ENTHRALLED_RAT,0,1,2,61,0,100,0,0,0,0,0,33,@NPC_ENTHRALLED_RAT,0,0,0,0,0,21,5,0,0,0,0,0,0,'Deeprun Rat - On Link - Give Q credit'),
(@NPC_ENTHRALLED_RAT,0,2,3,61,0,100,0,0,0,0,0,11,@SPELL_FLUTE_VISUAL,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deeprun Rat - On Link - Set Flute Visual'),
(@NPC_ENTHRALLED_RAT,0,3,4,61,0,100,0,0,0,0,0,29,0,0,0,0,0,0,21,5,0,0,0,0,0,0,'Deeprun Rat - On Link - Follow Player'),
(@NPC_ENTHRALLED_RAT,0,4,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deeprun Rat - On LInk- Set Phase 1'),
(@NPC_ENTHRALLED_RAT,0,5,0,8,1,100,0,@SPELL_BASH,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deeprun Rat - On Spellhit - Despawn'),
--
(@NPC_MONTY,0,0,1,20,0,100,0,@QUEST,0,0,0,11,@SPELL_BASH,0,0,0,0,0,1,0,0,0,0,0,0,0,'Monty - On Reward Quest - Cast Bash'),
(@NPC_MONTY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Monty - On Reward Quest - Talk');

DELETE FROM `creature_text` WHERE `entry`=@NPC_MONTY;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(@NPC_MONTY,0,0,'Into the box me pretties! Thats it. One by one ye go.',12,0,0,0,0,0,'Monty');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=@SPELL_BASH;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,@SPELL_BASH,0,0,31,0,3,@NPC_ENTHRALLED_RAT,0,0,0,'','Spell Bash target rats');
