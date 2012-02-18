UPDATE `creature_template` SET `flags_extra`=`flags_extra`|128|2 WHERE `entry` IN (19871); -- World Trigger (World Trigger (Not Immune NPC))

DELETE FROM `game_event_creature` WHERE `guid` IN (62848,62849) AND `eventEntry`=11;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES 
(11, 62848),
(11, 62849);
