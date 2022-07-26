--
DELETE FROM `smart_scripts` WHERE `entryorguid` = 9098 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(9098,0,0,0,0,0,100,0,0,0,1100,3000,0,11,13748,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Scarshield Spellbinder - In Combat CMC - Cast 'Arcane Bolt'"),
(9098,0,1,0,0,0,100,0,5000,15000,15000,20000,0,11,15785,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Scarshield Spellbinder - In Combat - Cast 'Mana Burn'"),
(9098,0,2,0,13,0,100,0,10000,20000,0,0,0,11,15122,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Scarshield Spellbinder - Target Casting - Cast 'Counterspell'"),
(9098,0,3,0,16,0,100,0,15123,30,3000,6000,0,11,15123,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Scarshield Spellbinder - On Friendly Unit Missing Buff 'Resist Fire' - Cast 'Resist Fire'");

UPDATE `smart_scripts` SET `event_type` = 0, `event_param3` = 2300, `event_param4` = 3900, `action_type` = 11, `action_param1` = 10277, `action_param2` = 64, `action_param3` = 0, `action_param4` = 0, `target_type` = 2, `comment` = "Horde Axe Thrower - In Combat CMC - Cast 'Throw'" WHERE `entryorguid` = 9458 AND `source_type` = 0 AND `id` = 0;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 9523 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(9523,0,0,0,11,0,100,0,0,0,0,0,0,89,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kolkar Stormseer - On Respawn - Start Random Movement"),
(9523,0,1,0,0,0,100,0,0,0,3400,4800,0,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Kolkar Stormseer - In Combat CMC - Cast 'Lightning Bolt'"),
(9523,0,2,0,0,0,100,0,10000,15000,15000,20000,0,11,6535,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Kolkar Stormseer - In Combat - Cast 'Lightning Cloud'");
