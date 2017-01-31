-- Fjord Turkey SAI - Cleanup and re-add the old SAI with the new event.
DELETE FROM `smart_scripts` WHERE `entryorguid`=24746 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(24746,0,0,1,8,0,100,0,44323,0,0,0,11,44327,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Fjord Turkey - On Spellhit - Cast spell on invoker'),
(24746,0,1,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Fjord Turkey - On Spellhit - Despawn'),
(24746,0,2,0,6,0,100,0,0,0,0,0,11,25281,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Fjord Turkey - Upon death - Cast Turkey Marker');

UPDATE `creature_template` SET `faction_A`=189,`faction_H`=189 WHERE `entry`=29594; -- Angry Turkey
UPDATE `smart_scripts` SET `event_type`=1,`event_flags`=1,`action_type`=49,`action_param1`=0,`action_param2`=0,`target_type`=21,`target_param1`=20,`comment`= 'Angry Turkey - On spawn attack summoner' WHERE `entryorguid`=29594 AND `source_type`=0;
