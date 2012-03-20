-- Blood in the Water (12810)

SET @NPC_RAVENOUS_JAWS   := 29392; -- Ravenous Jaws
SET @SPELL_BLOOD         := 47172; -- Cosmetic - Underwater Blood (no sound)
SET @SPELL_GORE_BLADDER  := 6509; -- Gore Bladder
SET @SPELL_CANCEL_BLOOD  := 26568; -- Ravenous Jaws: Cancel Blood Cosmetic Aura

-- Ravenous Jaws
UPDATE `creature_template` SET `AIName`='SmartAI',`InhabitType`=2 WHERE `entry`=@NPC_RAVENOUS_JAWS;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@NPC_RAVENOUS_JAWS;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC_RAVENOUS_JAWS,0,0,0,0,0,100,0,5000,8000,11300,13400,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Thrash'),
(@NPC_RAVENOUS_JAWS,0,1,0,6,0,100,0,0,0,0,0,11,@SPELL_BLOOD,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Cosmetic');

DELETE FROM `spell_script_names` WHERE `spell_id` IN (@SPELL_GORE_BLADDER,@SPELL_CANCEL_BLOOD);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(@SPELL_GORE_BLADDER,'spell_item_gore_bladder'),
(@SPELL_CANCEL_BLOOD,'spell_cancel_blood_aura');