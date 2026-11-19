UPDATE `conditions` SET `SourceEntry`=230335 WHERE `SourceTypeOrReferenceId`=32 AND `SourceGroup`=8 AND `SourceEntry`=79470;
UPDATE `conditions` SET `ConditionValue1`=261021 WHERE `ConditionTypeOrReference`=48 AND `ConditionValue1`=11221 AND `ConditionValue2`=0;
UPDATE `conditions` SET `ConditionValue1`=261022, `ConditionValue2`=0 WHERE `ConditionTypeOrReference`=48 AND `ConditionValue1`=11221 AND `ConditionValue2`=1;
UPDATE `conditions` SET `ConditionValue1`=263462 WHERE `ConditionTypeOrReference`=48 AND `ConditionValue1`=12592 AND `ConditionValue2`=0;
UPDATE `conditions` SET `ConditionValue1`=2483, `ConditionValue2`=50 WHERE `SourceTypeOrReferenceId`=4 AND `SourceEntry`=46110 AND `ConditionTypeOrReference`=7;
UPDATE `conditions` SET `ConditionValue1`=2512, `ConditionValue2`=1 WHERE `SourceTypeOrReferenceId`=1 AND `SourceEntry`=46108 AND `ConditionTypeOrReference`=7;
UPDATE `conditions` SET `ConditionValue1`=2514 WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry`=29515 AND `ConditionTypeOrReference`=7;
UPDATE `conditions` SET `ConditionValue1`=170 WHERE `ConditionTypeOrReference`=26 AND `ConditionValue1`=2;

DELETE FROM `conditions` WHERE `ConditionTypeOrReference`=48 AND `ConditionValue1`=0;
DELETE FROM `conditions` WHERE `ConditionTypeOrReference`=7 AND `ConditionValue1`=129;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=1 AND `SourceEntry` IN (9293, 13523, 28276, 28277, 28558, 29669, 29672, 29673, 29674, 29675, 37331, 37332, 37333, 37334);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (9455, 17698, 29705, 29727, 30232, 33831, 50524, 58836, 67303, 67304, 67305, 67306, 67307, 67308, 67328, 67755, 67756, 67757, 68614, 68798, 69294, 72031, 72032, 72033, 72273, 72456, 72527, 72746, 72747, 72748, 72850, 72851, 72852, 72868, 72869, 73785, 73786, 73787, 74270, 74271, 74272, 74318, 74319, 74320, 74321, 74323, 74758, 75464, 76379, 79614, 79781, 82192, 88354);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry` IN (56453, 60089);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceGroup`=31897;

DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=29512;
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(1, 29512, 0, '', '', 'Deprecated quest: Putting the Carnies Back Together Again');
