UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` IN(33877,33761,33861,33862);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(33877,33761,33861,33862)  AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(19455501,19455503)  AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(19455501, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 104, 16, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Archivum Console - Script 2 - Set Go Flags '),
(19455501, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 19, 33874, 0, 0, 0, 0, 0, 0, 'Archivum Console - Script 2 - Say Text Line 3 on Archivum System '),
(19455501, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 33876, 3, 67000, 0, 0, 0, 8, 0, 0, 0, 1438.32, 118.523, 425.434, 0, 'Archivum Console - Script 2 - Spawn Freya Image '),
(19455501, 9, 3, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 19, 33874, 0, 0, 0, 0, 0, 0, 'Archivum Console - Script 2 - Say Text Line 4 on Archivum System '),
(19455501, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 33861, 3, 58000, 0, 0, 0, 8, 0, 0, 0, 1435.8, 118.855, 425.881, 0, 'Archivum Console - Script 2 - Spawn Elder Brightleaf Image'),
(19455501, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 33862, 3, 58000, 0, 0, 0, 8, 0, 0, 0, 1435.71, 120.41, 425.823, 0, 'Archivum Console - Script 2 - Spawn Elder Stonebark Image'),
(19455501, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 33761, 3, 58000, 0, 0, 0, 8, 0, 0, 0, 1435.77, 117.288, 425.838, 0, 'Archivum Console - Script 2 - Spawn Elder Ironbark Image'),
(19455501, 9, 7, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 19, 33874, 0, 0, 0, 0, 0, 0, 'Archivum Console - Script 2 - Say Text Line 5 on Archivum System '),
(19455501, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 33761, 0, 0, 0, 0, 0, 0, 'Archivum Console - Script 2 - Set Data on Elder Brightleaf Image'),
(19455501, 9, 9, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 6, 0, 0, 0, 0, 0, 19, 33874, 0, 0, 0, 0, 0, 0, 'Archivum Console - Script 2 - Say Text Line 6 on Archivum System '),
(19455501, 9, 10, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 33862, 0, 0, 0, 0, 0, 0, 'Archivum Console - Script 2 - Set Data on Elder Stonebark Image'),
(19455501, 9, 11, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 7, 0, 0, 0, 0, 0, 19, 33874, 0, 0, 0, 0, 0, 0, 'Archivum Console - Script 2 - Say Text Line 7 on Archivum System'),
(19455501, 9, 12, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 33861, 0, 0, 0, 0, 0, 0, 'Archivum Console - Script 2 - Set Data on Elder Ironbranch Image'),
(19455501, 9, 13, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 8, 0, 0, 0, 0, 0, 19, 33874, 0, 0, 0, 0, 0, 0, 'Archivum Console - Script 2 - Say Text Line 8 on Archivum System'),
(19455501, 9, 14, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 19, 33761, 0, 0, 0, 0, 0, 0, 'Archivum Console - Script 2 - Set Data on Elder Brightleaf Image'),
(19455501, 9, 15, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 19, 33862, 0, 0, 0, 0, 0, 0, 'Archivum Console - Script 2 - Set Data on Elder Stonebark Image'),
(19455501, 9, 16, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 19, 33861, 0, 0, 0, 0, 0, 0, 'Archivum Console - Script 2 - Set Data on Elder Ironbranch Image'),
(19455501, 9, 17, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 9, 0, 0, 0, 0, 0, 19, 33874, 0, 0, 0, 0, 0, 0, 'Archivum Console - Script 2 - Say Text Line 9 on Archivum System'),
(19455501, 9, 18, 0, 0, 0, 100, 0, 13000, 13000, 0, 0, 104, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Archivum Console - Script 2 - Set Go Flags '),
(19455503, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 104, 16, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Archivum Console - Script 4 - Set Go Flags '),
(19455503, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 15, 0, 0, 0, 0, 0, 19, 33874, 0, 0, 0, 0, 0, 0, 'Archivum Console - Script 4 - Say Text Line 15 on Archivum System '),
(19455503, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 33878, 3, 40000, 0, 0, 0, 8, 0, 0, 0, 1436.22, 118.364, 425.789, 0, 'Archivum Console - Script 4 - Spawn Thorim Image'),
(19455503, 9, 3, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 16, 0, 0, 0, 0, 0, 19, 33874, 0, 0, 0, 0, 0, 0, 'Archivum Console - Script 4 - Say Text Line 16 on Archivum System '),
(19455503, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 33877, 3, 31000, 0, 0, 0, 8, 0, 0, 0, 1436.14, 120.3, 425.839, 4.95674, 'Archivum Console - Script 4 - Spawn Sif Image'),
(19455503, 9, 5, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 33877, 0, 0, 0, 0, 0, 0, 'Archivum Console - Script 4 - Set Data on Sif Image'),
(19455503, 9, 6, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 17, 0, 0, 0, 0, 0, 19, 33874, 0, 0, 0, 0, 0, 0, 'Archivum Console - Script 4 - Say Text Line 17 on Archivum System '),
(19455503, 9, 7, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 18, 0, 0, 0, 0, 0, 19, 33874, 0, 0, 0, 0, 0, 0, 'Archivum Console - Script 4 - Say Text Line 18 on Archivum System '),
(19455503, 9, 8, 0, 0, 0, 100, 0, 13000, 13000, 0, 0, 104, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Archivum Console - Script 4 - Set Go Flags '),
(33761,0,0,0,38,0,100,0,1,1,0,0,11,64201,0,0,0,0,0,1,0,0,0,0,0,0,0,'Elder Brightleaf Image - On Data Set - Cast Sunbeam'),
(33862,0,0,0,38,0,100,0,1,1,0,0,11,64228,0,0,0,0,0,1,0,0,0,0,0,0,0,'Elder Stonebark Image - On Data Set - Cast Ground Tremor'),
(33861,0,0,0,38,0,100,0,1,1,0,0,11,64229,0,0,0,0,0,1,0,0,0,0,0,0,0,'Elder Ironbranch Image - On Data Set - Cast Iron Roots'),
(33761,0,1,0,38,0,100,0,2,2,0,0,11,64269,0,0,0,0,0,19,33876,0,0,0,0,0,0,'Elder Brightleaf Image - On Data Set - Cast Hologram Freya Channel'),
(33862,0,1,0,38,0,100,0,2,2,0,0,11,64269,0,0,0,0,0,19,33876,0,0,0,0,0,0,'Elder Stonebark Image - On Data Set - Cast Hologram Freya Channel'),
(33861,0,1,0,38,0,100,0,2,2,0,0,11,64269,0,0,0,0,0,19,33876,0,0,0,0,0,0,'Elder Ironbranch Image - On Data Set - Cast Hologram Freya Channel'),
(33877,0,0,0,38,0,100,0,1,1,0,0,11,64324,0,0,0,0,0,19,33878,0,0,0,0,0,0,'Sif Image - On Data Set - Cast Hologram Sif Channel');

UPDATE `gossip_menu_option` SET `BoxBroadcastTextID`=0 WHERE  `menu_id`=10368;
