-- That spell has nothing to do with damaging spells, moreover it will never work like that
DELETE FROM `spell_script_names` WHERE `ScriptName` = "spell_ticking_time_bomb";

UPDATE `creature_template` SET `unit_flags` = 33554432, `unit_flags2` = 32, `flags_extra` = `flags_extra` | 0x00002000 WHERE `entry` IN (29684,31816);
UPDATE `creature_template` SET `minlevel` = 73, `maxlevel` = 73 WHERE `entry` = 32246;
UPDATE `creature_template` SET `minlevel` = 73, `maxlevel` = 73, `speed_run` = 0.857143, `unit_flags` = 33554432, `unit_flags2` = 32, `AIName` = "SmartAI", `flags_extra` = `flags_extra` | 0x00002000 WHERE `entry` = 34307;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (29684,32246,34307) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2968400,3224600,3430700) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- No idea what was the point, first two are used in single dungeon and fist one even has difficulty entry but it's not even used,
-- instead creature summons second creature in heroic with different damaging spell
(29684,0,0,0,54,0,100,0,0,0,0,0,0,80,2968400,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ticking Bomb - On Just Summoned - Run Script"),
(32246,0,0,0,54,0,100,0,0,0,0,0,0,80,3224600,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ticking Time Bomb - On Just Summoned - Run Script"),
(34307,0,0,0,54,0,100,0,0,0,0,0,0,80,3430700,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Time Bomb - On Just Summoned - Run Script"),

-- That spell creates dynamic object (bomb) and for some reason is heavily delayed like in other similar scripts. Because of that after 
-- bomb(missile) reaches destination, there is 2 sec delay before bomb will appear visually(creature itself has no model). Kinda blizzlike bug
(2968400,9,0,0,0,0,100,0,2000,2000,0,0,0,11,54955,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ticking Bomb - On Script - Cast 'Ticking Bomb'"),
(2968400,9,1,0,0,0,100,0,0,0,0,0,0,11,61393,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ticking Bomb - On Script - Cast 'Ticking Bomb'"),
(2968400,9,2,0,0,0,100,0,2500,2500,0,0,0,11,61393,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ticking Bomb - On Script - Cast 'Ticking Bomb'"),
(2968400,9,3,0,0,0,100,0,2500,2500,0,0,0,11,54954,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ticking Bomb - On Script - Cast 'Explosion'"),
(2968400,9,4,0,0,0,100,0,0,0,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ticking Bomb - On Script - Delayed Despawn"),

(3224600,9,0,0,0,0,100,0,2000,2000,0,0,0,11,59686,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ticking Time Bomb - On Script - Cast 'Ticking Time Bomb'"),
(3224600,9,1,0,0,0,100,0,0,0,0,0,0,11,61393,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ticking Time Bomb - On Script - Cast 'Ticking Bomb'"),
(3224600,9,2,0,0,0,100,0,2500,2500,0,0,0,11,61393,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ticking Time Bomb - On Script - Cast 'Ticking Bomb'"),
(3224600,9,3,0,0,0,100,0,2500,2500,0,0,0,11,59687,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ticking Time Bomb - On Script - Cast 'Explosion'"),
(3224600,9,4,0,0,0,100,0,0,0,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ticking Time Bomb - On Script - Delayed Despawn"),

(3430700,9,0,0,0,0,100,0,2000,2000,0,0,0,11,59686,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Time Bomb - On Script - Cast 'Ticking Time Bomb'"),
(3430700,9,1,0,0,0,100,0,0,0,0,0,0,11,61393,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Time Bomb - On Script - Cast 'Ticking Bomb'"),
(3430700,9,2,0,0,0,100,0,2500,2500,0,0,0,11,61393,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Time Bomb - On Script - Cast 'Ticking Bomb'"),
(3430700,9,3,0,0,0,100,0,2500,2500,0,0,0,11,65129,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Time Bomb - On Script - Cast 'Explosion'"),
(3430700,9,4,0,0,0,100,0,0,0,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Time Bomb - On Script - Delayed Despawn");
