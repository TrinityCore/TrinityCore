-- 
DELETE FROM `spell_area` WHERE `spell`=37475 AND `area`=3781;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES
(37475, 3781, 10607, 0, 0, 0, 2, 1, 10, 11);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=37466;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 37466, 0, 0, 1, 0, 37475, 0, 0, 0, 0, 0, "", "Understanding Ravenspeech require the player having the aura 'Soul Attraction'");
