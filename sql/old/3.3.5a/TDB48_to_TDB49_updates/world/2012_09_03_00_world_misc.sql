-- Cold Hearted (12856)

SET @NPC_CAPTIVE_DRAKE        := 29708; -- Captive Proto-Drake
SET @NPC_FREED_DRAKE          := 29709; -- Freed Proto-Drake
SET @NPC_PRISONER             := 29639; -- Brunnhildar Prisoner
SET @NPC_LIBERATED            := 29734; -- Liberated Brunnhildar

SET @SPELL_SUM_FREE_DRAKE     := 55028; -- Summon Freed Proto-Drake
SET @SPELL_ICE_SHARD          := 55046; -- Ice Shard (Rank 3)
SET @SPELL_FREE_PRISONER      := 55048; -- Free Brunnhildar Prisoner
SET @AURA_IMPRISONMENT        := 54894; -- Icy Imprisonment


UPDATE `creature_template` SET `speed_walk`=1,`speed_run`=1.14286,`spell1`=@SPELL_ICE_SHARD,`HoverHeight`=4,`unit_flags`=0x1000008,`InhabitType`=4,`ScriptName`='npc_freed_protodrake' WHERE `entry`=@NPC_FREED_DRAKE;
UPDATE `creature_template` SET `unit_flags`=33554432,`AIName`='SmartAI' WHERE `entry`=@NPC_LIBERATED;

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=@NPC_CAPTIVE_DRAKE;
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`,`user_type`) VALUES
(@NPC_CAPTIVE_DRAKE,@SPELL_SUM_FREE_DRAKE,1,0);

DELETE FROM `creature_template_addon` WHERE `entry`=@NPC_FREED_DRAKE;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`auras`) VALUES
(@NPC_FREED_DRAKE,0,0x3000000,0x1,'55034 61183');

DELETE FROM `creature_text` WHERE `entry`=@NPC_FREED_DRAKE;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@NPC_FREED_DRAKE,0,0,'Return to Brunnhildar Village!',42,0,100,0,0,0,'Freed Proto-Drake'),
(@NPC_FREED_DRAKE,0,1,'The proto-drake smells freedom and flies homeward!',41,0,100,0,0,0,'Freed Proto-Drake');

DELETE FROM `spell_scripts` WHERE `id`=@SPELL_FREE_PRISONER;
INSERT INTO `spell_scripts` (`id`,`effIndex`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(@SPELL_FREE_PRISONER,0,0,14,@AURA_IMPRISONMENT,0,0,0,0,0,0);

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@NPC_LIBERATED;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC_LIBERATED,0,0,0,54,0,100,0,0,0,0,0,41,30000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Liberated Brunnhildar - On Spawn - Despawn in 30 seconds');
