-- 
DELETE FROM `game_event_creature` WHERE `eventEntry` = 25 AND `guid` IN (28458, 86825, 86826);
DELETE FROM `game_event_pool` WHERE `eventEntry`=25 AND `pool_entry`=1004;
INSERT INTO `game_event_pool` (`eventEntry`, `pool_entry`) VALUES (25, 1004);
