
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`IN(-53017);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(-53017, 48330, 0,'On Indisposed Expiring - Cast Create Amberseeds');
UPDATE `smart_scripts` SET `target_type`=12, `target_param1`=1 WHERE  `entryorguid`=28747 AND `source_type`=0 AND `id`=6 AND `link`=0;UPDATE `smart_scripts` SET `target_type`=12, `target_param1`=1 WHERE  `entryorguid`=28748 AND `source_type`=0 AND `id`=5 AND `link`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=28747 AND `source_type`=0 AND `id`=7;DELETE FROM `smart_scripts` WHERE `entryorguid`=28748 AND `source_type`=0 AND `id`=6;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(28747, 0, 7, 0, 4, 0, 100, 0, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Quetz\'lun Worshipper - On Agro - Store Targetlist'),
(28748, 0, 6, 0, 4, 0, 100, 0, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Serpent-Touched Berserker - On Agro - Store Targetlist');
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 26560 AND `spell_effect`=18280;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`)
VALUES (26560, 18280, 0, 'Summon Lord-Commander Arete');
UPDATE `smart_scripts` SET `event_param1`=12 WHERE  `entryorguid`=31279 AND `source_type`=0 AND `id`=18 AND `link`=0;
