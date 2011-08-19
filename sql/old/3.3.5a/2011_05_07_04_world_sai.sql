-- Quest: A Mammoth Undertaking (12607)
UPDATE `creature_template` SET `VehicleId`=206,`AIName`='SmartAI',`spell1`=51660,`speed_run`=0.95238 WHERE `entry`=28379;
DELETE FROM `smart_scripts` WHERE `entryorguid`=28379 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(28379,0,0,0,31,0,100,0,51660,0,0,0,41,0,0,0,0,0,0,22,0,0,0,0,0,0,0, 'Shattertusk Mammoth - On Spell Hit - Despawn');

DELETE FROM `npc_spellclick_spells` where `npc_entry`=28379;
INSERT INTO `npc_spellclick_spells`(`npc_entry`,`spell_id`,`quest_start`,`quest_start_active`,`quest_end`,`cast_flags`,`aura_required`,`aura_forbidden`,`user_type`) values 
(28379,51658,12607,1,12607,0,0,0,0);

DELETE FROM `creature_template_addon` WHERE `entry`=28379;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(28379,0,0,1,0, NULL); -- Shattertusk Mammoth
