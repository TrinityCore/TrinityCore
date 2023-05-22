--
DELETE FROM `spell_scripts` WHERE `id` = 56099;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 30169 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 3016900 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(30169,0,0,0,11,0,100,0,0,0,0,0,0,11,56073,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Smoldering Scrap Bunny - On Spawn - Cast 'Summon Smoldering Scrap'"),
(30169,0,1,0,8,0,100,1,56099,0,0,0,0,80,3016900,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Smoldering Scrap Bunny - On Spellhit 'Throw Ice' - Run Script (No Repeat)"),

(3016900,9,0,0,0,0,100,0,0,0,0,0,0,28,56118,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Smoldering Scrap Bunny - On Script - Remove Aura 'Smolder Smoke'"),
(3016900,9,1,0,0,0,100,0,0,0,0,0,0,11,56101,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Smoldering Scrap Bunny - On Script - Cast 'Summon Frozen Iron Scrap'"),
(3016900,9,2,0,0,0,100,0,0,0,0,0,0,11,56135,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Smoldering Scrap Bunny - On Script - Cast 'Frost Nova Effect'"),
-- Was Set Loot State, doesn't make it more bugged (see below) and correct action here
(3016900,9,3,0,0,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,20,192124,5,0,0,0,0,0,0,"Smoldering Scrap Bunny - On Script - Despawn Closest GameObject 'Smoldering Scrap'"),
-- 100000 in sniffs, but 100000 increases chance spell will be launched on wrong target (less available targets - better),
-- ideally despawn it instantly but we want to keep anim which lasts for 15 sec. According to comments Blizz too has problems with target
-- selector in this quest, maybe less serious. Removing condition for spell makes it only worse
(3016900,9,4,0,0,0,100,0,15000,15000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Smoldering Scrap Bunny - On Script - Despawn");

--
DELETE FROM `spell_scripts` WHERE `id` = 68052;

UPDATE `creature_text` SET `Emote` = 0 WHERE `CreatureID` = 35642 AND `GroupID` = 0;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 35642 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3564200,3564201) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(35642,0,0,0,11,0,100,0,0,0,0,0,0,80,3564200,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Jeeves - On Spawn - Run Script"),
(35642,0,1,0,8,0,100,0,68052,0,0,0,0,80,3564201,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Jeeves - On Spellhit 'Jeeves Goodbye' - Run Script"),

(3564200,9,0,0,0,0,100,0,0,0,0,0,0,11,68054,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Jeeves - On Script - Cast 'Pressing Engagement'"),
(3564200,9,1,0,0,0,100,0,1500,1500,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Jeeves - On Script - Set Orientation Owner"),

(3564201,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Jeeves - On Script - Say Line 0"),
(3564201,9,1,0,0,0,100,0,1500,1500,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Jeeves - On Script - Despawn");
