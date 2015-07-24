UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE  `entry`=193424;
DELETE FROM `smart_scripts` WHERE `entryorguid`=193424 AND `source_type`=1;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(193424, 1, 0, 1, 62, 0, 100, 0, 10111, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Eye of Dominion - On Gossip Option 0 Selected - Close Gossip'),
(193424, 1, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 85, 58106, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Eye of Dominion - On Gossip Option 0 Selected - Invoker Cast Forcecast: Control Lithe Stalker'),
(193424, 1, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 85, 58037, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Eye of Dominion - On Gossip Option 0 Selected - Invoker Cast Control Lithe Stalker');

UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry` =30895;
DELETE FROM `smart_scripts` WHERE `entryorguid` =30895 AND `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(30895, 0, 0, 0, 27, 0, 100, 1, 0, 0, 0, 0, 11, 58117, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lithe Stalker - On Passenger Boarded - Cast Force Reaction: Scourge'),
(30895, 0, 1, 0, 28, 0, 100, 1, 0, 0, 0, 0, 28, 58117, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lithe Stalker - On Passenger Removed - Remove Aura Force Reaction: Scourge');

UPDATE `creature_template` SET `spell1`=57882, `spell2`=58203, `spell3`=58282, `spell4`=58283 WHERE  `entry`=30895;
