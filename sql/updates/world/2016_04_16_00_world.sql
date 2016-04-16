-- Forcecast Summon Amberleaf Troublemaker
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=114710;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 3, 114710, 0, 0, 31, 0, 4, 0, 0, 0, 0, 0, '', 'Forcecast Summon Amberleaf Troublemaker target Player');

DELETE FROM `spell_script_names` WHERE `ScriptName`="spell_summon_troublemaker";
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(114698, 'spell_summon_troublemaker');
