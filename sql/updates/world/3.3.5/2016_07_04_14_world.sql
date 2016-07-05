--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (26022, 26023);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(26022, 61417, 2, "Pursuit of Justice Mounted Movement Speed Increase"),
(26023, 61418, 2, "Pursuit of Justice Mounted Movement Speed Increase");
