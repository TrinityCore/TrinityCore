-- Move EPL tower gryphon master to SAI
DELETE FROM `gossip_menu_option` WHERE menu_id = 7379;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES
(7379, 0, 0, 'Take me to Northpass Tower.',13562,1,1,0,0,0,0,NULL,0),
(7379, 1, 0, 'Take me to Eastwall Tower.',13563,1,1,0,0,0,0,NULL,0),
(7379, 2, 0, 'Take me to Crown Guard Tower.',13564,1,1,0,0,0,0,NULL,0);

-- Creating a new SmartAI script for [Creature] ENTRY 17209 (name: William Kielar)

-- Table creature_template
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 17209;

-- Table smart_scripts
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 17209);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17209, 0, 0, 3, 62, 0, 100, 0, 7379, 0, 0, 0, 52, 494, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'William Kielar - On Gossip Option 0 Selected - Activate Taxi Path 494'),
(17209, 0, 1, 3, 62, 0, 100, 0, 7379, 1, 0, 0, 52, 495, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'William Kielar - On Gossip Option 1 Selected - Activate Taxi Path 495'),
(17209, 0, 2, 3, 62, 0, 100, 0, 7379, 2, 0, 0, 52, 496, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'William Kielar - On Gossip Option 2 Selected - Activate Taxi Path 496'),
(17209, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'William Kielar - On Gossip Option 0 Selected - Close Gossip');

