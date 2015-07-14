--
UPDATE `smart_scripts` SET `action_param1`=58955, `action_param2`=0, `target_type`=7, `Comment`="Dying Soldier - On Spell hit - Cast 'Alliance Quest Aura'" WHERE `entryorguid`=31304 AND `source_type`=0 AND `id`=6;
UPDATE `smart_scripts` SET `action_param1`=3240, `action_param2`=2, `target_type`=1, `Comment`="Dying Soldier - On Spellhit 'Finish It' - Cast 'Bloody Explosion'" WHERE `entryorguid`=31304 AND `source_type`=0 AND `id`=7;
UPDATE `smart_scripts` SET `action_param1`=0 WHERE `entryorguid`=31304 AND `source_type`=0 AND `id`=9;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (31273) AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(31273, 0, 1, 0, 25, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dying Berserker - On Reset - set react passif');
