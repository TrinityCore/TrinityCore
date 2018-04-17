-- Eredar Bloodmage SAI
SET @ENTRY := 117782;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4500,21000,23000,11,235222,0,0,0,0,0,5,0,0,0,0,0,0,0,"Eredar Bloodmage -  IC Timer - Cast Blood Siphon.");

DELETE FROM spell_script_names WHERE scriptname = "spell_gen_eredar_bloodmage_blood_siphon";
INSERT INTO spell_script_names VALUES
(235222, "spell_gen_eredar_bloodmage_blood_siphon");

DELETE FROM spell_script_names WHERE scriptname = "spell_gen_eredar_bloodmage_blood_siphon_damage";
INSERT INTO spell_script_names VALUES
(235232, "spell_gen_eredar_bloodmage_blood_siphon_damage");
