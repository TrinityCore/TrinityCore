--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=46085;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 46085, 0, 0, 30, 0, 187982, 2, 0, 0, 0, 0, "", "Place Fake Fur can only be cast within 2 yards of Caribou Trap"),
(17, 0, 46085, 0, 1, 30, 0, 187995, 2, 0, 0, 0, 0, "", "Place Fake Fur can only be cast within 2 yards of Caribou Trap"),
(17, 0, 46085, 0, 2, 30, 0, 187996, 2, 0, 0, 0, 0, "", "Place Fake Fur can only be cast within 2 yards of Caribou Trap"),
(17, 0, 46085, 0, 3, 30, 0, 187997, 2, 0, 0, 0, 0, "", "Place Fake Fur can only be cast within 2 yards of Caribou Trap"),
(17, 0, 46085, 0, 4, 30, 0, 187998, 2, 0, 0, 0, 0, "", "Place Fake Fur can only be cast within 2 yards of Caribou Trap"),
(17, 0, 46085, 0, 5, 30, 0, 187999, 2, 0, 0, 0, 0, "", "Place Fake Fur can only be cast within 2 yards of Caribou Trap"),
(17, 0, 46085, 0, 6, 30, 0, 188000, 2, 0, 0, 0, 0, "", "Place Fake Fur can only be cast within 2 yards of Caribou Trap"),
(17, 0, 46085, 0, 7, 30, 0, 188001, 2, 0, 0, 0, 0, "", "Place Fake Fur can only be cast within 2 yards of Caribou Trap"),
(17, 0, 46085, 0, 8, 30, 0, 188002, 2, 0, 0, 0, 0, "", "Place Fake Fur can only be cast within 2 yards of Caribou Trap"),
(17, 0, 46085, 0, 9, 30, 0, 188003, 2, 0, 0, 0, 0, "", "Place Fake Fur can only be cast within 2 yards of Caribou Trap"),
(17, 0, 46085, 0, 10, 30, 0, 188004, 2, 0, 0, 0, 0, "", "Place Fake Fur can only be cast within 2 yards of Caribou Trap"),
(17, 0, 46085, 0, 11, 30, 0, 188005, 2, 0, 0, 0, 0, "", "Place Fake Fur can only be cast within 2 yards of Caribou Trap"),
(17, 0, 46085, 0, 12, 30, 0, 188006, 2, 0, 0, 0, 0, "", "Place Fake Fur can only be cast within 2 yards of Caribou Trap"),
(17, 0, 46085, 0, 13, 30, 0, 188007, 2, 0, 0, 0, 0, "", "Place Fake Fur can only be cast within 2 yards of Caribou Trap"),
(17, 0, 46085, 0, 14, 30, 0, 188008, 2, 0, 0, 0, 0, "", "Place Fake Fur can only be cast within 2 yards of Caribou Trap");

UPDATE `item_template` SET `ScriptName`="" WHERE `entry`=35127;
DELETE FROM `spell_script_names` WHERE `ScriptName`="spell_q11865_place_fake_fur";
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(46085, "spell_q11865_place_fake_fur");
