--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry`=10302;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 10302, 0, 0, 8, 0, 9280, 0, 0, 0, 0, 0, "", "Quest 'Volatile Mutations' is available only if quest 'Replenishing the Healing Crystals' (Draenei-only version) is rewarded OR"),
(19, 0, 10302, 0, 1, 8, 0, 9369, 0, 0, 0, 0, 0, "", "Quest 'Volatile Mutations' is available only if quest 'Replenishing the Healing Crystals' (non-Draenei version) is rewarded");

DELETE FROM `quest_template_addon` WHERE `ID`=9358;
INSERT INTO `quest_template_addon` (`ID`, `BreadcrumbForQuestId`) VALUES
(9358, 9252);
UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE `ID` IN (8490, 9395);
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=10302 WHERE `ID`=9371;
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=364 WHERE `ID`=363;
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=12188 WHERE `ID`=12181;
UPDATE `quest_template_addon` SET `ExclusiveGroup`=10183 WHERE `ID` IN (11036, 11037, 11040, 11042, 10183);
DELETE FROM `quest_template_addon` WHERE `ID`=11039;
INSERT INTO `quest_template_addon` (`ID`, `PrevQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RequiredMinRepFaction`, `RequiredMinRepValue`) VALUES
(11039, 10211, 10183, 10189, 934, 3000);
UPDATE `quest_template_addon` SET `PrevQuestID`=10211, `ExclusiveGroup`=10183, `BreadcrumbForQuestId`=10241 WHERE `ID`=11038;
UPDATE `quest_template_addon` SET `PrevQuestId`=10211 WHERE `ID` IN (10189, 10243);

UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=8468;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=1, `Emote4`=15 WHERE `ID`=11864;
UPDATE `quest_offer_reward` SET `Emote1`=15, `Emote2`=66 WHERE `ID`=8885;
