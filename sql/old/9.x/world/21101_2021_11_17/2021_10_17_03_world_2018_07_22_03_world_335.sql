-- 
-- Stone Watcher of Norgannon
UPDATE `gossip_menu` SET `TextID`=1676 WHERE `MenuID`=57001;
UPDATE `gossip_menu` SET `TextID`=1675 WHERE `MenuID`=57002;

DELETE FROM `creature_text` WHERE `CreatureID`=7918;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(7918,0,0,"Salutations!  I am a guardian of entry.  Please use the proper discs for access to Uldum.",12,0,100,0,0,0,4049,0,"Stone Watcher of Norgannon"),
(7918,1,0,"Your discs will be returned to you once you access the pedestal.",12,0,100,0,0,0,4065,0,"Stone Watcher of Norgannon");

DELETE FROM `smart_scripts` WHERE `entryorguid`=7918 AND `source_type`=0 AND `id` IN (2,3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7918,0,2,0,11,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stone Watcher of Norgannon - On Spawn - Say Line 0"),
(7918,0,3,0,62,0,100,0,57005,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stone Watcher of Norgannon - On Gossip Option Selected - Say Line 1");
