DELETE FROM `spelldifficulty_dbc` WHERE `id` = 50414;
INSERT INTO `spelldifficulty_dbc` (`id`, `spellid0`, `spellid1`) VALUES
(50414, 50414, 59009); -- Curse of Blood

UPDATE `creature_template` SET `ScriptName` = 'npc_risen_drakkari_bat_rider' WHERE `entry` IN (26638, 31351);
UPDATE `creature_template` SET `AIName` = 'NullAI' WHERE `entry` = 27490;
UPDATE `creature_template` SET `unit_flags` = 64 WHERE `entry` = 31339;
