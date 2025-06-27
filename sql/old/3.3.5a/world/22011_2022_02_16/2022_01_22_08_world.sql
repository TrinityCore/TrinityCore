--
DELETE FROM `spell_target_position` WHERE `ID` IN (34727,34730,34731,34732,34733,34734,34735,34736,34737,34739);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `VerifiedBuild`) VALUES
(34727,0,553,26,419,-25,5.096362,14007),
(34731,0,553,56,428,-25,4.782202,14007),
(34733,0,553,94,416,-27,4.049164,14007),
(34734,0,553,94,376,-27,2.9147,14007),
(34736,0,553,66,353,-26,1.815143,14007),
(34739,0,553,33,366,-25,1.186824,14007);

UPDATE `creature_template` SET `ScriptName` = 'npc_warp_splinter_sapling' WHERE `entry` = 19949;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 34742;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,34742,0,0,31,0,3,19949,0,0,0,0,"","Group 0: Spell 'Ancestral Life' (Effect 0) targets creature 'Sapling'");
