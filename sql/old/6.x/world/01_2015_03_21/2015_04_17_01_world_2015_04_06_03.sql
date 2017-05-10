UPDATE `gameobject_template` SET `AIName`='', `ScriptName`='', `data2`=13685, `data3`=3000, `data5`=1 WHERE `entry`=184729;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=21319;

DELETE FROM `event_scripts` WHERE id IN (13685);
INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES
(13685, 1, 10, 21319, 90000, 0, 1316.469, 6686.669, -18.59028, 1.072638);

DELETE FROM `smart_scripts` WHERE `entryorguid`=184729 AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=21319 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(21319, 0, 0, 1, 63, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 21, 20, 0, 0, 0, 0, 0,0,'Gor Grimgut- Just Summoned - Talk'),
(21319, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 20, 0, 0, 0, 0, 0,0,'Gor Grimgut- Just Summoned - Attack'),
(21319, 0, 2, 0, 0, 0, 100, 0, 3000, 5000, 7000, 10000, 75, 35492, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0,0,'Gor Grimgut - In Combat - Cast Exhaustion'),
(21319, 0, 3, 0, 0, 0, 100, 0, 10000, 12000, 12000, 15000, 11, 35491, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0,0,'Gor Grimgut - In Combat - Cast Furious Rage');

DELETE FROM `creature_text` WHERE `entry` IN (21319);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(21319, 0, 0, 'Puny $r cannot lift spear.  Gor lift spear!', 12, 0, 100, 0, 0, 0, 18980, 0, 'Gor Grimgut'),
(21319, 0, 1, 'Hah!  The Thunderspike is mine.  Die!', 12, 0, 100, 0, 0, 0, 18979, 0, 'Gor Grimgut');
