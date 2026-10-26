--
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_mekgineer_steamrigger_summon_gnomes';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(31531, 'spell_mekgineer_steamrigger_summon_gnomes');

DELETE FROM `spell_target_position` WHERE `ID` IN (31528,31529,31530);
INSERT INTO `spell_target_position` (`ID`,`EffectIndex`,`MapID`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`VerifiedBuild`) VALUES
(31528,0,545,-315.56015,-164.80557,-7.7555575,1.251415848731994628,0),
(31529,0,545,-347.00745,-160.84607,-7.7555575,0.530080020427703857,0),
(31530,0,545,-329.94170,-113.43509,-7.7555575,5.497043132781982421,0);

UPDATE `creature_text` SET `Text` = "Tune 'em up good, boys!", `BroadcastTextId` = 14602 WHERE `CreatureID` = 17796 AND `GroupID` = 0 AND `ID` = 0;
