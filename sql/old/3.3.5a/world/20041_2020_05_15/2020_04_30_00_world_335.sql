-- Faire Cannon Trigger should spawn only if Darkmoon Faire is active
DELETE FROM `game_event_creature` WHERE `guid` IN (111084,111094);
INSERT INTO `game_event_creature` (`eventEntry`,`guid`) VALUES
(4,111084),
(3,111094);
