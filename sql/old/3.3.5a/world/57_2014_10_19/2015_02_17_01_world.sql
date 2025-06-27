--
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2248200,2203800) AND `source_type`=9 AND `id` IN (2, 3, 4);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2248200, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mature Bone Sifter - Script - Set Agressive'),
(2248200, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 19, 33554432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mature Bone Sifter - Script - Remove UnitFlag'),
(2248200, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mature Bone Sifter - Script - Root'),
(2203800, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hai shulud <The Bone Emperor> - Script - Set Agressive'),
(2203800, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 19, 33554432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hai shulud <The Bone Emperor> - Script - Remove UnitFlag'),
(2203800, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hai shulud <The Bone Emperor> - Script - Root');

DELETE FROM `smart_scripts` WHERE `entryorguid`=16968 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16968,0,0,1,4,0,100,0,0,0,0,0,19,33554432,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tunneler - On Aggro - Remove UNIT_FLAG_NOT_SELECTABLE'),
(16968,0,1,2,61,0,100,0,0,0,0,0,28,29147,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tunneler - Link With Previous - Remove Tunnel Bore Passive'),
(16968,0,2,3,61,0,100,0,0,0,0,0,11,37752,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tunneler - Link With Previous - Cast Stand'),
(16968,0,3,0,61,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tunneler - Link With Previous - Root'),
(16968,0,4,5,25,0,100,0,0,0,0,0,11,29147,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tunneler - Spawn/Respawn/OOC - Cast Tunnel Bore Passive'),
(16968,0,5,6,61,0,100,0,0,0,0,0,18,33554432,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tunneler - Link With Previous Set UNIT_FLAG_NOT_SELECTABLE'),
(16968,0,6,0,61,0,100,0,0,0,0,0,11,37751,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tunneler - Link With Previous - Cast Submerge'),
(16968,0,7,0,0,0,100,0,1000,1000,2100,4500,11,31747,0,0,0,0,0,2,0,0,0,0,0,0,0,'Tunneler - In Combat - Cast Poison'),
(16968,0,8,0,0,0,100,0,10400,10400,45000,50000,11,32738,0,0,0,0,0,2,0,0,0,0,0,0,0,'Tunneler - In Combat - Cast Bore'),
(16968,0,9,0,2,0,100,0,0,30,8000,8000,11,32714,1,0,0,0,0,1,0,0,0,0,0,0,0,"Tunneler - Between 0-30% Health - Cast 8599");

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=21849;
DELETE FROM `smart_scripts` WHERE `entryorguid`=21849 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21849,0,0,1,4,0,100,0,0,0,0,0,19,33554432,0,0,0,0,0,1,0,0,0,0,0,0,0,'Bone Crawler - On Aggro - Remove UNIT_FLAG_NOT_SELECTABLE'),
(21849,0,1,2,61,0,100,0,0,0,0,0,28,38885,0,0,0,0,0,1,0,0,0,0,0,0,0,'Bone Crawler - Link With Previous - Remove Tunnel Bore Passive'),
(21849,0,2,3,61,0,100,0,0,0,0,0,11,37752,0,0,0,0,0,1,0,0,0,0,0,0,0,'Bone Crawler - Link With Previous - Cast Stand'),
(21849,0,3,0,61,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Bone Crawler - Link With Previous - Root'),
(21849,0,4,5,25,0,100,0,0,0,0,0,11,38885,0,0,0,0,0,1,0,0,0,0,0,0,0,'Bone Crawler - Spawn/Respawn/OOC - Cast Tunnel Bore Passive'),
(21849,0,5,6,61,0,100,0,0,0,0,0,18,33554432,0,0,0,0,0,1,0,0,0,0,0,0,0,'Bone Crawler - Link With Previous Set UNIT_FLAG_NOT_SELECTABLE'),
(21849,0,6,0,61,0,100,0,0,0,0,0,11,37751,0,0,0,0,0,1,0,0,0,0,0,0,0,'Bone Crawler - Link With Previous - Cast Submerge'),
(21849,0,7,0,0,0,100,0,1000,1000,2100,4500,11,31747,0,0,0,0,0,2,0,0,0,0,0,0,0,'Bone Crawler - In Combat - Cast Poison'),
(21849,0,8,0,0,0,100,0,10400,10400,45000,50000,11,32738,0,0,0,0,0,2,0,0,0,0,0,0,0,'Bone Crawler - In Combat - Cast Bore');
