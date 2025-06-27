UPDATE `creature_template` SET `ainame`='SmartAI' WHERE `entry` IN(24283);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(24283) AND `source_type`=0;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(2428300) AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24283,0,0,0,20,1,100,0,11328,0,0,0,80,2428300,2,0,0,0,0,1,0,0,0,0,0,0,0,'Peppy Wrongnozzle - On Quest Reward (Mission: Forsaken Intel)  - Run Script'),
(24283,0,1,0,25,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Peppy Wrongnozzle - On Spawn - Set Phase 1'),
(24283,0,2,0,1,1,100,0,8000,10000,8000,10000,5,92,0,0,0,0,0,1,0,0,0,0,0,0,0,'Peppy Wrongnozzle - OOC (Phase 1) - Play emote OneShotEatNoSheathe'),
(2428300,9,0,0,0,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Peppy Wrongnozzle - Script - Set Phase 2'), 
(2428300,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Peppy Wrongnozzle - Script - Face Player '), -- 19:35:27.323
(2428300,9,2,0,0,0,100,0,0,0,0,0,71,0,0,2200,3698,0,0,1,0,0,0,0,0,0,0,'Peppy Wrongnozzle - Script - Equip item 2200 to Slot 1 & 3698 to slot 2'), -- 19:35:27.573
(2428300,9,3,0,0,0,100,0,700,700,0,0,17,133,0,0,0,0,0,1,0,0,0,0,0,0,0,'Peppy Wrongnozzle - Script - Set Emote state 133'), -- 19:35:29.226
(2428300,9,4,0,0,0,100,0,5000,5000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Peppy Wrongnozzle - Script - Set Emote state 0'), -- 19:35:34.405
(2428300,9,5,0,0,0,100,0,1300,1300,0,0,71,0,0,2705,0,0,0,1,0,0,0,0,0,0,0,'Peppy Wrongnozzle - Script - Equip item 2705 to Slot 1 & Unequip slot 2'), -- 19:35:35.638
(2428300,9,6,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Peppy Wrongnozzle - Script - Say Line 0'), -- 19:35:35.638
(2428300,9,7,0,0,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Peppy Wrongnozzle - Script - Set Phase 1'), 
(2428300,9,8,0,0,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Peppy Wrongnozzle - Script - Evade'); 

DELETE FROM `creature_template_addon` WHERE `entry`=24283;
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(24283, 0, 0x0, 0x101, '35777'); -- 24283 - 35777

DELETE FROM `creature_text` WHERE `entry`IN(24283);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(24283, 0, 0, 'Right, that should do it. I think ...hic.', 12, 7, 100, 396, 0, 0, 23086, 'Peppy Wrongnozzle to Player');
