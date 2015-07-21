UPDATE `creature_text` SET `TextRange`=2 WHERE  `entry`=16128 AND `groupid` IN(1,2,3,4,5,6,7);
UPDATE `creature_text` SET `TextRange`=2 WHERE  `entry`=30007 AND `groupid`=14 AND `id`=0;

UPDATE `smart_scripts` SET `link`=27 WHERE  `entryorguid`=18471 AND `source_type`=0 AND `id`=23 AND `link`=0;

DELETE FROM `smart_scripts` WHERE `entryorguid`=18471 AND `source_type`=0 AND `id`=27;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(18471, 0, 27, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 12, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Gurgthock - On Data Set 15 15 - Say');

DELETE FROM `creature_text` WHERE `entry`=18471 AND `groupid`=12;
DELETE FROM `creature_text` WHERE `entry`=22941;

INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(18471, 12, 0, '$n has defeated the hero of the Warmaul, Mogor! All hail $n!', 12, 0, 100, 15, 0, 0, 15482, 2, 'Gurgthock'),
(22941, 0, 0, 'All hail, $n, the new $G King : Queen; of the ogres!!!', 12, 0, 100, 0, 0, 0, 20791, 2, 'Mog''dorg the Wizened');

UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` =22941;
DELETE FROM `smart_scripts` WHERE `entryorguid` =22941 AND `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(22941, 0, 0, 0, 20, 0, 100, 0, 11000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Mog''dorg the Wizened - On Quest Complete (Into the Soulgrinder) - Say');
