-- 
DELETE FROM `smart_scripts` WHERE `entryorguid`=15420 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1542000 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15420, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Prospector Anvilward - On Respawn - Set Event Phase 1"),
(15420, 0, 1, 0, 1, 1, 100, 0, 10000, 10000, 270000, 330000, 0, 80, 1542000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Prospector Anvilward - Out of Combat - Run Script (Phase 1)"),
(15420, 0, 2, 3, 62, 0, 100, 0, 21311, 0, 0, 0, 0, 53, 0, 15420, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Prospector Anvilward - On Gossip Option 0 Selected - Start Waypoint"),
(15420, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Prospector Anvilward - On Gossip Option 0 Selected - Close Gossip"),
(15420, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 0, 83, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Prospector Anvilward - On Gossip Option 0 Selected - Remove Npc Flag Gossip"),
(15420, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Prospector Anvilward - On Gossip Option 0 Selected - Set Event Phase 0"),
(15420, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Prospector Anvilward - On Gossip Option 0 Selected - Say Line 0"),
(15420, 0, 7, 8, 40, 0, 100, 0, 8, 15420, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Prospector Anvilward - On Waypoint 8 Reached - Say Line 1"),
(15420, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 24, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Prospector Anvilward - On Waypoint 8 Reached - Set Faction 24"),
(1542000, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Prospector Anvilward - Out Of Combat - Say Line 2"),
(1542000, 9, 1, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 15405, 50, 0, 0, 0, 0, 0, 0, "Prospector Anvilward - Out Of Combat - Say Line 0 (Ley-Keeper Caidanis)");

DELETE FROM `waypoints` WHERE `entry`=15420 AND `pointid` IN (7, 8);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(15420, 7, 9289.319336, -6657.801270, 31.828445, "Prospector Anvilward"),
(15420, 8, 9289.892578, -6657.924316, 31.827124, "Prospector Anvilward");
