SET @ENTRY_MINIGOB = 32838;
SET @GUID_MINIGOB  = 44457;
SET @EVENT_ID      = 33;

-- mail loot
DELETE FROM `mail_loot_template` WHERE `entry`=264;
INSERT INTO `mail_loot_template` (`entry`, `item`) VALUES
(264, 44817);

-- creature script
UPDATE `creature_template` SET `ScriptName`='npc_minigob_manabonk' WHERE `entry`=@ENTRY_MINIGOB;
-- creature spawn
DELETE FROM `creature` WHERE `guid`=@GUID_MINIGOB;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@GUID_MINIGOB, @ENTRY_MINIGOB, 571, 1, 1, 0, 1, 5877.88, 662.895, 644.53, 1.66366, 300, 0, 0, 3367, 8139, 0, 0, 0, 0);


-- game event to spawn the npc
DELETE FROM `game_event` WHERE `eventEntry`=@EVENT_ID;
INSERT INTO `game_event` (`eventEntry`, `start_time`, `end_time`, `occurence`, `length`, `description`) VALUES
(@EVENT_ID, '2011-03-22 00:10:00', '2020-03-22 00:00:00', 30, 5, 'Dalaran: Minigob');
DELETE FROM `game_event_creature` WHERE `guid`=@GUID_MINIGOB;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(@EVENT_ID, @GUID_MINIGOB);
