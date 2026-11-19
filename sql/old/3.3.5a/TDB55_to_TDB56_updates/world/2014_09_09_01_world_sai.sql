UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` =25969;
DELETE FROM `smart_scripts` WHERE `entryorguid` =25969 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(25969, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 11, 46340, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jenny - On Just Summoned - Cast Crates Carried'),
(25969, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jenny - On Just Summoned - Set Passive'),
(25969, 0, 2, 0, 32, 0, 100, 0, 50, 20000, 3000, 5000, 11, 46342, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jenny - On Damage - Cast Drop Crate'),
(25969, 0, 3, 0, 23, 0, 100, 0, 46340, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jenny - On Has No Aura (Crates Carried) - Despawn'),
(25969, 0, 4, 0, 75, 0, 100, 0, 0, 25849, 30, 0, 11, 46358, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'Jenny - Within 30 yards of Fezzix Geartwist - Give Kill credit');
