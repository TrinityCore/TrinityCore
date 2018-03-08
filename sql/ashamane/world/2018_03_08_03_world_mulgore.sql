DELETE FROM spell_script_names WHERE scriptname = "spell_mulgore_funeral_offering";
INSERT INTO spell_script_names VALUES
(71898, "spell_mulgore_funeral_offering");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 71898;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `Comment`) VALUES
('13', '2', '71898', '31', '3', '38438', 'Mulgore - Funeral Offering'); 
