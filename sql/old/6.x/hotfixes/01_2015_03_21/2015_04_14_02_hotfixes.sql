DELETE FROM `hotfix_data` WHERE (`TableHash`=599752208 AND `RecordID`=1789 AND `Timestamp`=1428969324) OR (`TableHash`=599752208 AND `RecordID`=1790 AND `Timestamp`=1428969324) OR (`TableHash`=599752208 AND `RecordID`=1791 AND `Timestamp`=1428969324) OR (`TableHash`=599752208 AND `RecordID`=1792 AND `Timestamp`=1428969324) OR (`TableHash`=599752208 AND `RecordID`=1793 AND `Timestamp`=1428969324) OR (`TableHash`=599752208 AND `RecordID`=1794 AND `Timestamp`=1428969324);
INSERT INTO `hotfix_data` (`TableHash`, `RecordID`, `Timestamp`, `Deleted`) VALUES
(599752208, 1789, 1428969324, 0), -- SpellEffectGroupSize - 1789 - 1789
(599752208, 1790, 1428969324, 0), -- SpellEffectGroupSize - 1790 - 1790
(599752208, 1791, 1428969324, 0), -- SpellEffectGroupSize - 1791 - 1791
(599752208, 1792, 1428969324, 0), -- SpellEffectGroupSize - 1792 - 1792
(599752208, 1793, 1428969324, 0), -- SpellEffectGroupSize - 1793 - 1793
(599752208, 1794, 1428969324, 0); -- SpellEffectGroupSize - 1794 - 1794

DELETE FROM `spell_effect_group_size` WHERE `ID` IN (1789, 1790, 1791, 1792, 1793, 1794);
INSERT INTO `spell_effect_group_size` (`ID`, `SpellEffectID`, `Size`, `VerifiedBuild`) VALUES
(1789, 241861, 1.25, 19865), -- 1789
(1790, 233592, 1.25, 19865), -- 1790
(1791, 229325, 1.43, 19865), -- 1791
(1792, 229326, 1.43, 19865), -- 1792
(1793, 249873, 1.43, 19865), -- 1793
(1794, 249874, 1.43, 19865); -- 1794
