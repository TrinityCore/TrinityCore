DELETE FROM `creature_text` WHERE `entry` IN(26531,24525);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(26531, 0, 0, '%s is entranced by the sun''s reflection on Zeh''gehn''s knife.', 16, 0, 100, 0, 0, 0, 'Mesmerized Frog'),
(26531, 1, 0, '%s croaks eagerly while directing its gaze to the docked ship.', 16, 0, 100, 0, 0, 0, 'Mesmerized Frog'),
(24525, 0, 0, 'Ku into me carver, ye ugly croaker!  Ku and show me who dares cross me brethren!', 12, 0, 100, 0, 0, 0, 'Zeh''gehn'),
(24525, 1, 0, 'Dis a rankin'' set, mon, no scurvy dog gonna kass-kass me buckos an'' walk aweh! ', 12, 0, 100, 0, 0, 0, 'Zeh''gehn');

UPDATE `creature_template` SET AIName='SmartAI' WHERE `entry`=24525;
DELETE FROM `smart_scripts` WHERE (`entryorguid`=24525 AND `source_type`=0);
DELETE FROM `smart_scripts` WHERE (`entryorguid`=2452500 AND `source_type`=9);

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(24525, 0, 0, 0, 20, 0, 100, 0, 11476, 0, 0, 0, 80, 2452500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zeh''gehn - On Quest reward A Carver and a Croaker  - Run Script'),
(2452500, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 26531, 1, 30000, 0, 0, 0, 8, 0, 0, 0, -133.458, -3545.554, 2.894682, 4.520403, 'Zeh''gehn - Script  - Spawn Mesmerized Frog'),
(2452500, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zeh''gehn - Script - Say Line 1'),
(2452500, 9, 2, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 26531, 0, 0, 0, 0, 0, 0, 'Zeh''gehn - Script - Say Line 1 (Mesmerized Frog)'),
(2452500, 9, 3, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 26531, 0, 0, 0, 0, 0, 0, 'Zeh''gehn - Script - Say Line 2 (Mesmerized Frog)'),
(2452500, 9, 4, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zeh''gehn - Script - Say Line 2');

UPDATE `creature_template` SET `AIName`='SmartAI',`npcflag`=16777216 WHERE `entry`=26503;
DELETE FROM `smart_scripts` WHERE `entryorguid`=26503;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26503,0,1,2,73,0,100,0,47121,0,0,0,56,35803,1,0,0,0,0,7,0,0,0,0,0,0,0,'Scalawag Frog - On Spellclick - Add Item Scalawag Frog'),
(26503,0,2,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Scalawag Frog - Linked with Previous Event - Despawn');

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=26503;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
(26503, 47121, 0, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceGroup`=26503;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(18, 26503, 47121, 0, 0, 9, 0, 11476, 0, 0, 0, 0, 0, '', 'Required quest active for spellclick');

UPDATE `creature_text` SET `BroadcastTextID`=25732 WHERE  `entry`=26531 AND `groupid`=0 AND `id`=0;
UPDATE `creature_text` SET `BroadcastTextID`=25733 WHERE  `entry`=26531 AND `groupid`=1 AND `id`=0;
UPDATE `creature_text` SET `BroadcastTextID`=25734 WHERE  `entry`=24525 AND `groupid`=0 AND `id`=0;
UPDATE `creature_text` SET `BroadcastTextID`=23581 WHERE  `entry`=24525 AND `groupid`=1 AND `id`=0;
UPDATE `smart_scripts` SET `target_type`=1, `target_param1`=0 WHERE  `entryorguid`=36913 AND `source_type`=0 AND `id`=2;
