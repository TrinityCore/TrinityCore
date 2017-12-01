--
UPDATE `creature_template` SET `faction` = 16 WHERE `entry` = 48815;
UPDATE `creature` SET `PhaseId` = 0 WHERE `id` IN (28390,28391);
UPDATE `creature` SET `PhaseGroup` = 0 WHERE `id` = 49284;
DELETE FROM `game_event_creature` WHERE `guid` NOT IN (SELECT `guid` FROM `creature`);

