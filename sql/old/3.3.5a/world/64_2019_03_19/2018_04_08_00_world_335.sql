-- 
DELETE FROM `quest_template_addon` WHERE `ID` IN (6042,6022,6133,6135,6136,6163,6144,14349,14350);
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES
(6022,0,0,0,0,6136,-6133,0,0,0,0,0,0,0,0,1,0),
(6042,0,0,0,0,6135,-6133,0,0,0,0,0,0,0,0,0,0),
(6133,0,0,0,0,6135,-6133,0,0,0,0,0,0,0,0,0,0),
(6135,0,0,0,0,6144,-6135,0,0,0,0,0,0,0,0,0,0),
(6136,0,0,0,0,6163,-6135,0,0,0,0,0,0,0,0,0,0),
(6144,0,0,0,0,14350,0,0,0,0,0,0,0,0,0,0,0),
(14350,0,0,0,0,6146,0,0,0,0,0,0,0,0,0,0,0);

DELETE FROM `disables` WHERE `sourceType`=1 AND `entry` IN (14349,6145);
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(1,14349,0,"","","Deprecated quest"),
(1,6145,0,"","","Deprecated quest");

UPDATE `quest_template` SET `RewardNextQuest`=0 WHERE `ID`=6144;
UPDATE `quest_offer_reward` SET `RewardText`="The Grand Crusader sits safely in the Scarlet Bastion while his forces pour into our lands, desecrate our structures and monuments and murder our people.$B$BThe time has come to deal with this pest. You will become the instrument of our reckoning." WHERE `ID`=6144;
