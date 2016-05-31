UPDATE `achievement_criteria_data` SET `ScriptName`='achievement_has_orphan_out' WHERE `ScriptName`='achievement_school_of_hard_knocks';
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (6641,6642,6643,6644,6651,6652,6653,6654,6655,6656,6657,6659,10391,12398);
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`) VALUES
(6641,16,201,0,''), -- School of Hard Knocks
(6642,16,201,0,''), -- School of Hard Knocks
(6643,16,201,0,''), -- School of Hard Knocks
(6644,16,201,0,''), -- School of Hard Knocks
(6651,11,0,0, 'achievement_has_orphan_out'), -- Bad Example
(6651,16,201,0,''), -- Bad Example
(6652,11,0,0, 'achievement_has_orphan_out'), -- Bad Example
(6652,16,201,0,''), -- Bad Example
(6653,11,0,0, 'achievement_has_orphan_out'), -- Bad Example
(6653,16,201,0,''), -- Bad Example
(6654,11,0,0, 'achievement_has_orphan_out'), -- Bad Example
(6654,16,201,0,''), -- Bad Example
(6655,11,0,0, 'achievement_has_orphan_out'), -- Bad Example
(6655,16,201,0,''), -- Bad Example
(6656,11,0,0, 'achievement_has_orphan_out'), -- Bad Example
(6656,16,201,0,''), -- Bad Example
(6657,11,0,0, 'achievement_has_orphan_out'), -- Bad Example
(6657,16,201,0,''), -- Bad Example
(6659,11,0,0, 'achievement_has_orphan_out'), -- Hail To The King, Baby
(6659,16,201,0,''), -- Hail To The King, Baby
(10391,11,0,0, 'achievement_has_orphan_out'), -- Home Alone
(10391,16,201,0,''), -- Home Alone
(12398,11,0,0, 'achievement_has_orphan_out'), -- Daily Chores
(12398,16,201,0,''); -- Daily Chores

DELETE FROM `disables` WHERE `entry` IN (6641,6642,6643,6644,6651,6652,6653,6654,6655,6656,6657,6659,10391,12398) AND `sourceType`=4;
