-- Shipwreck Debris
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=186283;
DELETE FROM `smart_scripts` WHERE `entryorguid`=186283 AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (18628300,18628301) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(186283,1,0,0,8,0,100,0,42287,0,0,0,0,41,0,120,0,0,0,0,1,0,0,0,0,0,0,0,"Shipwreck Debris - On Spellhit 'Salvage Wreckage'  - Despawn"),
(186283,1,1,0,8,0,100,0,42287,0,0,0,0,41,0,120,0,0,0,0,20,186278,0,0,0,0,0,0,"Shipwreck Debris - On Spellhit 'Salvage Wreckage'  - Despawn Closest Gameobject 'Burning Wreckage'"),
(186283,1,2,0,8,0,100,0,42287,0,0,0,0,87,18628300,18628301,0,0,0,0,1,0,0,0,0,0,0,0,"Shipwreck Debris - On Spellhit 'Salvage Wreckage' - Run Random Script"),
(18628300,9,0,0,0,0,100,0,0,0,0,0,0,85,42289,0,0,0,0,0,7,0,0,0,0,0,0,0,"Shipwreck Debris - On Script - Invoker Cast 'Summon Mirefin Burrower'"),
(18628301,9,0,0,0,0,100,0,0,0,0,0,0,85,42288,0,0,0,0,0,7,0,0,0,0,0,0,0,"Shipwreck Debris - On Script - Invoker Cast 'Summon Salvaged Lockbox'");

DELETE FROM `spell_scripts` WHERE `id`=42287;

-- Mirefin Ambusher
UPDATE `creature_template` SET `unit_flags`=32768, `AIName`="SmartAI" WHERE `entry`=23701;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23701 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(23701,0,0,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Mirefin Ambusher - Between 0-15% Health - Flee For Assist (No Repeat)");
