UPDATE `creature_template` SET `ScriptName`='npc_chained_spirit' WHERE `entry`=52156;
UPDATE `creature_template` SET `ScriptName`='npc_ohgan' WHERE `entry`=52157;

DELETE FROM `creature` WHERE `id`=52156;

DELETE FROM `spell_script_names` WHERE `spell_id` IN (96682,96776,96761,96821,96721,96722,96724,96740,28471);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(96682,'spell_mandokir_decapitate'),
(96776,'spell_mandokir_bloodletting'),
(96761,'spell_mandokir_devastating_slam'),
(96821,'spell_mandokir_spirit_vengeance_cancel'),
(96721,'spell_mandokir_ohgan_orders'),
(96722,'spell_mandokir_ohgan_orders_trigger'),
(96724,'spell_mandokir_reanimate_ohgan'),
(96740,'spell_mandokir_devastating_slam_damage'),
(28471,'spell_clear_all');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`IN (96724,96721);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 3, 96724, 0, 0, 31, 0, 3, 52157, 0, 0, 0, 0, '', 'Earth Spike - Ohgan'),
(13, 1, 96721, 0, 0, 31, 0, 3, 52156, 0, 0, 0, 0, '', 'Ohgan''s Orders - Chained Spirit');

DELETE FROM `achievement_criteria_data` WHERE `criteria_id`=16848;
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(16848,11,0,0,'achievement_ohganot_so_fast'),
(16848,12,1,0,'');
