DELETE FROM `creature_text` WHERE `entry`=21767;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`,`BroadcastTextID`) VALUES
(21767, 0, 0, 'What $r dare harm those of my flock?', 14, 0, 100, 0, 0, 0, 'Harbinger of the Raven',19398);

UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry`=21767;

DELETE FROM `smart_scripts` WHERE `entryorguid`=21767  AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21767,0,0,0,54,0,100,0,0,0,0,0,1,0,7000,0,0,0,0,1,0,0,0,0,0,0,0,'Harbinger of the Raven - On Just Summoned - Say Line 0'),
(21767,0,1,2,52,0,100,0,0,21767,0,0,11,37446,0,0,0,0,0,1,0,0,0,0,0,0,0,'Harbinger of the Raven - On Text Over Line 0 - Cast Ruuan ok Oracle Transformation'),
(21767,0,2,3,61,0,100,0,0,0,0,0,2,954,0,0,0,0,0,1,0,0,0,0,0,0,0,'Harbinger of the Raven - On Text Over Line 0 - Set Faction'),
(21767,0,3,0,61,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Harbinger of the Raven - On Text Over Line 0 - Set Hostile');
