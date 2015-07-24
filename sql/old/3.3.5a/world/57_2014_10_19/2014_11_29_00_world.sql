DELETE FROM `creature_text` WHERE `entry`=19228 AND `groupid` IN(49,50);
DELETE FROM `creature_text` WHERE `entry`=19228 AND `groupid` =0 and `id`=6;

INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(19228, 49, 0, 'Is it just me, or is the Horde about the ugliest enemy we could find?', 12, 7, 100, 6, 0, 0, 16678, 'Perry Gatner'),
(19228, 50, 0, 'Just so you guys don''t feel left out, all I said was how attractive the blood elves are.  It loses something in the translation.', 12, 1, 100, 6, 0, 0, 16679, 'Perry Gatner'),
(19228, 0, 6, 'Are you ready to laugh!', 12, 0, 100, 5, 0, 0, 16329, 'Perry Gatner');

DELETE FROM `smart_scripts` WHERE `entryorguid`=1927116 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(1927116, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 47, 0, 0, 0, 0, 0, 19, 19228, 0, 0, 0, 0, 0, 0, 'Albert Quarksprocket - - Script 16 - Say Line 49 (Perry Gatner'),
(1927116, 9, 1, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 48, 0, 0, 0, 0, 0, 19, 19228, 0, 0, 0, 0, 0, 0, 'Albert Quarksprocket - - Script 16 - Say Line 50 (Perry Gatner');

UPDATE `smart_scripts` SET `action_param4`=1927116 WHERE  `entryorguid`=19271 AND `source_type`=0 AND `id`=15;
