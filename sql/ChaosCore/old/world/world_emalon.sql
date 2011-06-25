DELETE FROM `spell_script_names` WHERE `spell_id`=64218;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(64218, 'spell_overcharge_targeting');

DELETE FROM `conditions` WHERE `SourceEntry`=64218 AND `SourceTypeOrReferenceId`=13 AND `ConditionTypeOrReference`=18;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`Comment`) VALUES
(13,64218,18,1,33998, 'Emalon - Overcharge');