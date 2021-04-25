--
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (14508) AND `source_type`=0 AND `id` =5;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(14508,0,5,0,40,0,100,0,15,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Short John Mithril - On Waypoint 15 Reached - Set Run On");

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (14508,14823);
INSERT INTO `creature_template_movement` (`CreatureId`,`Ground`,`Swim`,`Flight`,`Rooted`,`Chase`,`Random`,`InteractionPauseTimer`) VALUES
(14508,1,1,0,0,0,0,0),
(14823,1,1,0,0,0,0,20000);

-- Remove custom pauses
DELETE FROM `smart_scripts` WHERE `event_type` = 64 AND `action_type` = 54;
