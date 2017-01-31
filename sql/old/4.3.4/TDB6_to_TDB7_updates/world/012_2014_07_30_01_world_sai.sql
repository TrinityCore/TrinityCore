UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`='' WHERE `entry` IN(15402,15958);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(15402, 15958) and `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(1540200,1540201,1540202) AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15402, 0, 0, 0, 20, 0, 100, 0, 8487, 0, 0, 0, 80, 1540200, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Apprentice Mirveda - On Quest Rewarded (Corrupted Soil)  - Run Script'),
(15402, 0, 1, 2, 19, 0, 100, 0, 8488, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Apprentice Mirveda - On Quest Accept (Unexpected Results)  - Store Targetlist'),
(15402, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 1540201, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Apprentice Mirveda - On Quest Accept (Unexpected Results)  - Run Script'),
(15402, 0, 3, 0, 0, 0, 100, 0, 1000, 1000, 5000, 8000, 11, 20811, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Apprentice Mirveda - IC - Cast Fireball'),
(15402, 0, 4, 0, 6, 1, 100, 0, 0, 0, 0, 0, 6, 8488, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Apprentice Mirveda - On Death (Phase 1) - Fail Quest Unexpected Results'),
(15402, 0, 5, 6, 7, 1, 100, 0, 0, 0, 0, 0, 15, 8488, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Apprentice Mirveda - OOC (Phase 4) - Complete Quest Unexpected Results (Phase 3)'),
(15402, 0, 6, 0, 61, 8, 100, 0, 0, 0, 0, 0, 80, 1540202, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Apprentice Mirveda - Linked with Previous Event - Run Script (Phase 3)'),
(15402, 0, 7, 0, 11, 0, 100, 0, 0, 0, 0, 0, 18, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Apprentice Mirveda - On Spawn - Set Immune to NPC'),
(15958, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gharsul the Remorseless - On Just Summoned - Set Phase 2'),
(15958, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 1, 15958, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 'Gharsul the Remorseless - On Just Summoned - Start WP'),
(15958, 0, 2, 3, 40, 0, 100, 0, 1, 15958, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gharsul the Remorseless - On Reached WP1 - Set Home position'),
(15958, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gharsul the Remorseless - On Reached WP1 - Set react state agressive'),
(15958, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 19, 15402, 0, 0, 0, 0, 0, 0, 'Gharsul the Remorseless - On Reached WP1 - Attack Apprentice Mirveda'),

-- Script does not need to cast 29535 Quest - Apprentice Mirveda - Test Soil as this spell is cast as rewardspellcast from quest_Template and having it in script just makes the npc cast it twice instead of once
(1540200, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Apprentice Mirveda - Script 1 - Set NPC Flags'),
(1540200, 9, 1, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Apprentice Mirveda - Script 1 - Say Line 1'),
(1540200, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Apprentice Mirveda - Script 1 - Set NPC Flags'),
(1540201, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Apprentice Mirveda - Script 2 - Set NPC Flags'),
(1540201, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 2, 232, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Apprentice Mirveda - Script 2 - Set Faction'),
(1540201, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 19, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Apprentice Mirveda - Script 2 - Remove Unit Flags Immune to NPC'),
(1540201, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Apprentice Mirveda - Script 2 - Set Phase 1'),
(1540201, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 107, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Apprentice Mirveda - Script 2 - Summon Summon Group 0'),
(1540202, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Apprentice Mirveda - Script 3 - Set NPC Flags'),
(1540202, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 2, 1604, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Apprentice Mirveda - Script 3 - Set Faction'),
(1540202, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 18, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Apprentice Mirveda - Script 3 - Add Unit Flags Immune to NPC'),
(1540202, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Apprentice Mirveda - Script 3 - Set Phase 0');

DELETE FROM `smart_scripts` WHERE `entryorguid`=15656 AND `source_type`=0 AND `id`>1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(15656, 0, 2, 3, 54, 0, 100, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Angershade - On Just Summoned - Set Phase 2'),
(15656, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 1, 15656, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 'Angershade - On Just Summoned - Start WP'),
(15656, 0, 4, 5, 40, 0, 100, 0, 1, 15656, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Angershade - On Reached WP1 - Set Home position'),
(15656, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Angershade - On Reached WP1 - Set react state agressive'),
(15656, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 19, 15402, 0, 0, 0, 0, 0, 0, 'Angershade - On Reached WP1 - Attack Apprentice Mirveda');

DELETE FROM `creature_summon_groups` WHERE `summonerId`=15402;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`) VALUES 
(15402, 0, 0, 15958, 8749.505, -7132.595, 35.31983, 3.816502, 1, 180000), -- Gharsul the Remorseless
(15402, 0, 0, 15656, 8755.38, -7131.521, 35.30957, 3.816502, 1, 180000), -- Angershade
(15402, 0, 0, 15656, 8753.199, -7125.975, 35.31986, 3.816502, 1, 180000); -- Angershade

DELETE FROM `waypoints` WHERE `entry` IN(15958,15656);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(15958, 1, 8706.201172, -7157.467773, 44.203865, 'Gharsul the Remorseless'),
(15656, 1, 8705.161133, -7155.801270, 44.329075, 'Angershade');
