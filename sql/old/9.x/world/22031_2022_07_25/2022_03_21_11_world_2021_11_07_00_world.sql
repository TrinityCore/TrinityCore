--
DELETE FROM `waypoints` WHERE `entry` IN (29858,29859,29860);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (29858,29859,29860) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(29858,0,0,0,11,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lady Nightswood - On Spawn - Say Line 0"),
(29858,0,1,0,11,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,19,29851,0,0,0,0,0,0,0,"Lady Nightswood - On Spawn - Start Attack (General Lightsbane)"),
(29858,0,2,0,7,0,100,0,0,0,0,0,0,41,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lady Nightswood - On Evade - Delayed Despawn"),
(29858,0,3,0,0,0,100,0,10000,15000,13000,18000,0,11,5884,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Lady Nightswood - In Combat - Cast 'Banshee Curse'"),
(29858,0,4,0,0,0,100,0,15000,20000,15000,20000,0,11,16838,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lady Nightswood - In Combat - Cast 'Banshee Shriek'"),
-- The Leaper: Jump 27770 NYI, on aggro
(29859,0,0,0,11,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Leaper - On Spawn - Say Line 0"),
(29859,0,1,0,11,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,19,29851,0,0,0,0,0,0,0,"The Leaper - On Spawn - Start Attack (General Lightsbane)"),
(29859,0,2,0,7,0,100,0,0,0,0,0,0,41,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Leaper - On Evade - Delayed Despawn"),
(29859,0,3,0,0,0,100,0,5000,10000,5000,10000,0,11,60195,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"The Leaper - In Combat - Cast 'Sinister Strike'"),
(29859,0,4,0,0,0,100,0,10000,15000,10000,15000,0,11,60177,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Leaper - In Combat - Cast 'Hunger For Blood'"),

(29860,0,0,0,11,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Vile - On Spawn - Say Line 0"),
(29860,0,1,0,11,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,19,29851,0,0,0,0,0,0,0,"Vile - On Spawn - Start Attack (General Lightsbane)"),
(29860,0,2,0,7,0,100,0,0,0,0,0,0,41,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Vile - On Evade - Delayed Despawn"),
(29860,0,3,0,0,0,100,0,5000,10000,10000,15000,0,11,6253,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Vile - In Combat - Cast 'Backhand'"),
(29860,0,4,0,0,0,100,0,15000,20000,10000,20000,0,11,56646,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Vile - In Combat - Cast 'Enrage'"),
(29860,0,5,0,0,0,100,0,5000,10000,15000,15000,0,11,37548,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Vile - In Combat - Cast 'Taunt'");

DELETE FROM `smart_scripts` WHERE `entryorguid` = 29840 AND `source_type` = 0 AND `id` IN (2,3,4);
DELETE FROM `smart_scripts` WHERE `entryorguid` = 29769 AND `source_type` = 0 AND `id` IN (3,4);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(29840,0,2,0,0,0,100,0,5000,10000,5000,10000,0,11,60195,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"The Leaper - In Combat - Cast 'Sinister Strike'"),
(29840,0,3,0,0,0,100,0,10000,15000,10000,15000,0,11,60177,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Leaper - In Combat - Cast 'Hunger For Blood'"),

(29769,0,3,0,0,0,100,0,5000,10000,10000,15000,0,11,6253,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Vile - In Combat - Cast 'Backhand'"),
(29769,0,4,0,0,0,100,0,15000,20000,10000,20000,0,11,56646,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Vile - In Combat - Cast 'Enrage'");

DELETE FROM `smart_scripts` WHERE `entryorguid` = 29851 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2985100 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(29851,0,0,0,11,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"General Lightsbane - On Spawn - Say Line 0"),
(29851,0,1,0,11,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"General Lightsbane - On Spawn - Start Attack Owner"),
(29851,0,2,0,4,0,100,0,0,0,0,0,0,80,2985100,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"General Lightsbane - On Aggro - Run Script"),
(29851,0,3,0,7,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"General Lightsbane - On Evade - Despawn"),
(29851,0,4,0,0,0,100,0,5000,10000,5000,10000,0,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"General Lightsbane - In Combat - Cast 'Cleave'"),
(29851,0,5,0,0,0,100,0,10000,15000,10000,10000,0,11,60186,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"General Lightsbane - In Combat - Cast 'Plague Strike'"),
(29851,0,6,0,0,0,100,0,20000,20000,20000,20000,0,11,60160,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"General Lightsbane - In Combat - Cast 'Death and Decay'"),

(2985100,9,0,0,0,0,100,0,7000,7000,0,0,0,12,29860,1,300000,0,0,0,8,0,0,0,0,8551.562,2654.033,652.4367,6.0737457275390625,"General Lightsbane - Script - Summon Vile"),
(2985100,9,1,0,0,0,100,0,10000,10000,0,0,0,12,29858,1,300000,0,0,0,8,0,0,0,0,8598.224,2670.0774,652.4367,4.433136463165283203,"General Lightsbane - Script - Summon Lady Nightswood"),
(2985100,9,2,0,0,0,100,0,10000,10000,0,0,0,12,29859,1,300000,0,0,0,8,0,0,0,0,8556.31,2633.7283,652.4367,0.349065840244293212,"General Lightsbane - Script - Summon The Leaper");

UPDATE `event_scripts` SET `delay` = 0, `x` = 8578.525, `y` = 2642.0154, `z` = 652.3538, `o` = 5.433159351348876953 WHERE `id` = 19423;
