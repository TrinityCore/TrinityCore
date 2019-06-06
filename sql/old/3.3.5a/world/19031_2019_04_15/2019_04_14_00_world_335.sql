-- 
DELETE FROM `creature` WHERE `guid` IN (62028,62029);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`,`spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) VALUES
(62028, 15745, 0, 1, 1, 0, 0, -4912.68, -976.28, 501.533, 2.49582, 300, 0, 0, 0, 0, 0),
(62029, 15746, 1, 1, 1, 0, 0, 1628.577, -4414.487, 16.036, 6.108823, 300, 0, 0, 0, 0, 0);

DELETE FROM `creature_text` WHERE `CreatureID` =15745;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES 
(15745, 8, 0, 'Presents for everyone! Father Winter''s put gifts under the tree for all.', 14, 0, 100, 0, 0, 0, 11430, 'Greatfather Winters Helper');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`IN (15745);
DELETE FROM `smart_scripts` WHERE `entryorguid`=15745 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15745,0,0,0,1,0,100,0,3000,15000,600000,600000,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Greatfather Winters Helper - OOC - Say');

DELETE FROM `game_event_creature` WHERE `guid` IN (62028,62029) AND `eventEntry`=52;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES 
(52, 62028),(52, 62029);
