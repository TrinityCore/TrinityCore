DELETE FROM `spelldifficulty_dbc` WHERE `id` IN (49555, 49380, 49381);
INSERT INTO `spelldifficulty_dbc` (`id`, `spellid0`, `spellid1`) VALUES
(49555, 49555, 59807),
(49380, 49380, 59803),
(49381, 49381, 59805);

UPDATE `creature_template` SET `InhabitType` = 5 WHERE `entry` = 27724;

DELETE FROM `creature` WHERE `guid` > 127479 AND `guid` < 127489;
DELETE FROM `creature` WHERE `guid` > 127519 AND `guid` < 127539 AND `guid` != 127528;
DELETE FROM `creature_addon` WHERE `guid` > 127479 AND `guid` < 127489;
DELETE FROM `creature_addon` WHERE `guid` > 127519 AND `guid` < 127539 AND `guid` != 127528;

UPDATE `creature_template` SET `ScriptName` = 'npc_drakkari_invader' WHERE `entry` IN (27753, 27709);
