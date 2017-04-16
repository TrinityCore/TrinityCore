-- 
UPDATE `creature_template` SET `InhabitType`=4, `flags_extra`=`flags_extra`|128 WHERE `entry` IN (38936,39093);
DELETE FROM `vehicle_template_accessory` WHERE `entry` IN (38936);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(38936,13158,0,0,'lieutenant Sanders', 8, 0);
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (38936);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(38936, 46598, 0, 0);
DELETE FROM `creature` WHERE `id`=13158;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (38936);
DELETE FROM `smart_scripts` WHERE `entryorguid`=38936 AND source_type=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(38936,0,0,0,1,0,100,1,0,0,0,0,11,73444,0,0,0,0,0,1,0,0,0,0,0,0,0,'lieutenant Sanders noose - Ooc no repeat - cast Sanders Foot Noose');
--
