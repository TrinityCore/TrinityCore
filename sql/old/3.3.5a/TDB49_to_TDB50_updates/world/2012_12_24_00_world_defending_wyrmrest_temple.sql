-- Add support for quest Defending Wyrmrest Temple ID: 12372 and support for achievement Rapid Defence
-- Based on nelegalno and Nay updates
-- Indexes
-- NPCs
SET @Defender := 27629;
SET @AzureDrake := 27682;
SET @AzureDragon := 27608;
-- Spells
SET @SPELL_AZURE_ON_DEATH_FORCE_WHISPER := 50287;

-- Update Defender template from sniffs
UPDATE `creature_template` SET `HoverHeight`=4,`npcflag`=1,`unit_flags`=unit_flags|0x00000200|0x00000300,`spell1`=49161,`spell2`=49243,`spell3`=49263,`spell4`=49264,`spell5`=49367,`InhabitType`=4 WHERE `entry`=@Defender;

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (49367,49370);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry` IN (49161,49243,49367);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ScriptName`,`Comment`) VALUES
(13,1,49367,0,0,31,0,3,27698,0,0,0,'','Spell can hit only Defending Wyrmrest Temple Kill Credit Bunny'),
(13,1,49370,0,0,31,0,3,27698,0,0,0,'','Spell can hit only Defending Wyrmrest Temple Kill Credit Bunny'),
(17,0,49367,0,0,29,0,27698,80,0,0,0,'','Temple Kill Credit Bunny must be in 80 yards to be able to cast Destibilize and less for smth to happen'),
(17,0,49161,0,0,31,1,3,27608,0,0,0,'','Spell Flame Breath target Azure Dragon'),
(17,0,49161,0,1,31,1,3,27682,0,0,0,'','Spell Flame Breath target Azure Drake'),
(17,0,49161,0,2,31,1,3,27629,0,0,0,'','Spell Flame Breath can target mounted by enemey faction player Defender'),
(17,0,49243,0,0,31,1,3,27608,0,0,0,'','Spell Immolation can target Azure Dragon'),
(17,0,49243,0,1,31,1,3,27682,0,0,0,'','Spell Immolation can target Azure Drake'),
(17,0,49243,0,1,31,1,3,27629,0,0,0,'','Spell Immolation can target mounted by enemey faction player Defender');

-- Remove unblizzlike npc_spell_sclick that is handled by spell now
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=27629;

-- Addon data
DELETE FROM `creature_template_addon` WHERE `entry`=27629;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(27629,0,0,33554432,1,0,50069);

-- Convert EAI to SAI and fix some timings
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@AzureDragon,@AzureDrake);
DELETE FROM `creature_ai_scripts` WHERE `creature_id` IN (@AzureDragon,@AzureDrake);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@AzureDragon,@AzureDrake) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@AzureDragon,0,0,0,0,0,100,0,500,4000,3700,4500,11,49111,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Azure Dragon - IC - Cast Frost Breath'),
(@AzureDragon,0,1,0,6,0,100,0,0,0,0,0,11,@SPELL_AZURE_ON_DEATH_FORCE_WHISPER,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Azure Dragon - On death - Cast force whisper spell on invoker (hack need to be replaced by 11'),
(@AzureDrake,0,0,0,0,0,100,0,500,4000,3700,4500,11,49317,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Azure Drake - IC - Cast Frost Breath'),
(@AzureDrake,0,1,0,6,0,100,0,0,0,0,0,11,@SPELL_AZURE_ON_DEATH_FORCE_WHISPER,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Azure Drake - On death - Cast force whisper spell on invoker');
-- No need to condition them, stuff will happen only if send to drake otherwise would be plain result

-- Texts
DELETE FROM `creature_text` WHERE `entry`=@Defender;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
-- On player mounted or creature hit by mounting spell
(@Defender,0,0,'Are you ready for battle, $c?',15,0,100,0,0,0, 'Wyrmrest Defender'),
(@Defender,0,1,'Take us into battle, $n!',15,0,100,0,0,0, 'Wyrmrest Defender'),
(@Defender,0,2,'Shall we destabilize the shrine first or disable the enemy?',15,0,100,0,0,0, 'Wyrmrest Defender'),
(@Defender,0,3,'We''ve been expecting you, $n. Now we have the upper hand.',15,0,100,0,0,0, 'Wyrmrest Defender'),
(@Defender,0,4,'I can''t believe the blues would attack us. Let''s give some of it back!',15,0,100,0,0,0, 'Wyrmrest Defender'),
(@Defender,0,5,'Let''s defend the temple!',15,0,100,0,0,0, 'Wyrmrest Defender'),
(@Defender,0,6,'Where to first?',15,0,100,0,0,0, 'Wyrmrest Defender'),
(@Defender,0,7,'Your reputation precedes you, $n. This should be interesting.',15,0,100,0,0,0, 'Wyrmrest Defender'),
-- On Azure Drake/Dragon kill
(@Defender,1,0,'I never thought that I''d be riding into battle with a $r on my back.',15,0,100,0,0,0, 'Wyrmrest Defender'),
(@Defender,1,1,'Another blue down. We make a great team!',15,0,100,0,0,0, 'Wyrmrest Defender'),
(@Defender,1,2,'With you and I working together, this battle will be over in no time.',15,0,100,0,0,0, 'Wyrmrest Defender'),
(@Defender,1,3,'Malygos has clearly gone insane.',15,0,100,0,0,0, 'Wyrmrest Defender'),
(@Defender,1,4,'Nice one, kid.',15,0,100,0,0,0, 'Wyrmrest Defender'),
(@Defender,1,5,'I''ve never seen anything like this before. I''m glad that you''re here.',15,0,100,0,0,0, 'Wyrmrest Defender'),
(@Defender,1,6,'I''m glad you saw that one!',15,0,100,0,0,0, 'Wyrmrest Defender'),
(@Defender,1,7,'Just hang on. We''ll get through this.',15,0,100,0,0,0, 'Wyrmrest Defender'),
-- Below 30% HP
(@Defender,2,0,'We should get out of here. I need to heal!',42,0,100,0,3000,0, 'Wyrmrest Defender');

-- Remove achievement "Rapid Defence" out of disables
DELETE FROM `disables` WHERE `sourceType`=4 AND `entry`=3924;

-- Insert spell_script_name
DELETE FROM `spell_script_names` WHERE `spell_id`=@SPELL_AZURE_ON_DEATH_FORCE_WHISPER;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(@SPELL_AZURE_ON_DEATH_FORCE_WHISPER, 'spell_q12372_azure_on_death_force_whisper');
