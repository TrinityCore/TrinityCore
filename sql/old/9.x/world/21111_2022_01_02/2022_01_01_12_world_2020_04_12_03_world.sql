-- 
UPDATE `smart_scripts` SET `target_x`=8187.2265, `target_y`=3514.9526, `target_z`=626.187, `target_o`=0.003626 WHERE `entryorguid`=3113500 AND `source_type`=9 AND `id`=7;
UPDATE `smart_scripts` SET `target_x`=8196.7939, `target_y`=3538.6892, `target_z`=626.927, `target_o`=5.324698 WHERE `entryorguid`=3113500 AND `source_type`=9 AND `id`=8;
UPDATE `smart_scripts` SET `target_x`=8225.9111, `target_y`=3543.8002, `target_z`=627.512, `target_o`=4.327242 WHERE `entryorguid`=3113500 AND `source_type`=9 AND `id`=9;
UPDATE `smart_scripts` SET `target_x`=8245.8515, `target_y`=3514.6064, `target_z`=628.232, `target_o`=3.074531 WHERE `entryorguid`=3113500 AND `source_type`=9 AND `id`=10;
UPDATE `smart_scripts` SET `target_x`=8231.8750, `target_y`=3491.2070, `target_z`=627.441, `target_o`=2.383380 WHERE `entryorguid`=3113500 AND `source_type`=9 AND `id`=11;
UPDATE `smart_scripts` SET `target_x`=8202.6035, `target_y`=3490.6833, `target_z`=625.509, `target_o`=1.075695 WHERE `entryorguid`=3113500 AND `source_type`=9 AND `id`=12;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (31193,31191,31192,31196,31194) AND `source_type`=0 AND `id`=6;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (31195) AND `source_type`=0 AND `id`=7;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(31191, 0, 6, 0, 4, 0, 100, 0, 0, 0, 0, 0, 39, 70, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Father Jhadras - In aggro - Call for help'),
(31192, 0, 6, 0, 4, 0, 100, 0, 0, 0, 0, 0, 39, 70, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Masud '),
(31193, 0, 6, 0, 4, 0, 100, 0, 0, 0, 0, 0, 39, 70, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Geness Half-Soul '),
(31194, 0, 6, 0, 4, 0, 100, 0, 0, 0, 0, 0, 39, 70, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Talla '),
(31195, 0, 7, 0, 4, 0, 100, 0, 0, 0, 0, 0, 39, 70, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Eldreth '),
(31196, 0, 6, 0, 4, 0, 100, 0, 0, 0, 0, 0, 39, 70, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rith ');
