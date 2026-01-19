UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `VerifiedBuild`=64978 WHERE (`Entry`=54787 AND `DifficultyID` IN (0, 1)) OR (`Entry`=57779 AND `DifficultyID` IN (0, 1)); -- 54787, 57779 (Huo) - Sessile, CanSwim, Floating

UPDATE `creature` SET `PhaseId`= 632 WHERE `guid` IN (450608); 
UPDATE `creature` SET `PhaseId`= 631, `StringId` = 'Huo_Pre_Ignition' WHERE `guid` IN (450607); 

DELETE FROM `phase_area` WHERE `PhaseId` IN (631, 632);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(5849, 631, 'Cosmetic - Huo, Pre-Ignition'),
(5849, 632, 'Cosmetic - Huo, Post-Ignition');

DELETE FROM `conditions` WHERE (`SourceGroup` IN (631, 632)) AND (`SourceEntry` = 5849);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 631, 5849, 0, 0, 47, 0, 29422, 9, 0, '', 0, 0, 0, '', 'Allow phase 631 if quest 29422 state not taken / in progress'),

(26, 632, 5849, 0, 0, 47, 0, 29422, 66, 0, '', 0, 0, 0, '', 'Allow phase 632 if quest 29422 state completed / rewarded');

DELETE FROM `spell_script_names` WHERE `spell_id` IN (102522, 109090, 109095, 109105, 109109);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(102522, 'spell_fan_the_flames'),
(109090, 'spell_fan_the_flames_throw_wood_and_all_blow_air'),
(109095, 'spell_fan_the_flames_throw_wood_and_all_blow_air'),
(109105, 'spell_fan_the_flames_throw_wood_and_all_blow_air'),
(109109, 'spell_fan_the_flames_throw_wood_and_all_blow_air');

UPDATE `quest_template_addon` SET `ScriptName`= 'quest_29422_huo_the_spirit_of_fire', `NextQuestID`=29423 WHERE `ID` IN (29422);
