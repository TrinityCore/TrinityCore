--
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`='' WHERE `entry` =29811;
DELETE FROM `smart_scripts` WHERE `entryorguid` =29811;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(29811,0,0,1,62,0,100,0,9843,0,0,0,15,12864,0,0,0,0,0,7,0,0,0,0,0,0,0,'Frostborn Scout - On Gossip Select - Give Quest Credit'),
(29811,0,1,0,61,0,100,0,0,0,0,0,41,30000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Frostborn Scout - Linked with Previous Event - Despawn'),
(29811,0,2,0,25,0,100,0,0,0,0,0,90,7,0,0,0,0,0,1,0,0,0,0,0,0,0,'Frostborn Scout - On Spawn - Set Bytes 1');
