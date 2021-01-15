DELETE FROM `creature_text` WHERE `entry` =19228 AND `groupid`IN(47,48);
DELETE FROM `creature_text` WHERE `entry` =19228 AND `groupid`=0 AND `id`=4;

INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(19228, 0, 4, 'Whoa!  Is all that applause for me?  Thanks for coming out!', 12, 0, 100, 6, 0, 0, 'Perry Gatner',16326),
(19228, 47, 0, 'Used to be you couldn''t trust a goblin...', 12, 0, 100, 1, 0, 0, 'Perry Gatner',16671),
(19228, 48, 0, 'Who am I kiddin''? If you trade with goblins you''d better have iron plating in your coinpurse.', 12, 0, 100, 6, 0, 0, 'Perry Gatner',16672);

DELETE FROM `smart_scripts` WHERE `entryorguid`=1927115 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(1927115, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 47, 0, 0, 0, 0, 0, 19, 19228, 0, 0, 0, 0, 0, 0, 'Albert Quarksprocket - - Script 15 - Say Line 47 (Perry Gatner'),
(1927115, 9, 1, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 48, 0, 0, 0, 0, 0, 19, 19228, 0, 0, 0, 0, 0, 0, 'Albert Quarksprocket - - Script 15 - Say Line 48 (Perry Gatner');

UPDATE `smart_scripts` SET `action_param3`=192715 WHERE  `entryorguid`=19271 AND `source_type`=0 AND `id`=13;
