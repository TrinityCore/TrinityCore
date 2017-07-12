--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (43369, -43369, -68347);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(43369, 68347, 0, "Worg Disguise"),
(-43369, -68347, 0, "Worg Disguise"),
(-68347, -43369, 0, "Worg Disguise");
