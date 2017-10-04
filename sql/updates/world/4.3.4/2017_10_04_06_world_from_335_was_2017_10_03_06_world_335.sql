/*
-- 
UPDATE `quest_template` SET `RewardFactionID1`=469, `AllowableRaces`=1101 WHERE `ID`=5237;
UPDATE `quest_template` SET `RewardFactionID2`=67, `AllowableRaces`=690 WHERE `ID`=5238;

DELETE FROM `creature_queststarter` WHERE `quest` IN (5237, 5238);
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES
(10837, 5238),
(10838, 5237);

DELETE FROM `creature_questender` WHERE `quest` IN (5237, 5238);
INSERT INTO `creature_questender` (`id`, `quest`) VALUES
(10837, 5238),
(10838, 5237);

DELETE FROM `quest_template_addon` WHERE `ID` IN (5237,5238);
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES
(5238, 0, 0, 0, 5236, 0, 0, 101, 86400, 0, 0, 0, 0, 0, 0, 0, 0),
(5237, 0, 0, 0, 5226, 0, 0, 107, 86400, 0, 0, 0, 0, 0, 0, 0, 0);

UPDATE `quest_offer_reward` SET `RewardText`="$N, your successful re-engineering of the cauldrons is a tremendous victory for us!$B$B<The commander clears his throat and begins to bellow loudly.>$B$BLet all within my presence hear: for service to the Kingdom of Stormwind and to the Alliance above and beyond the call of duty - in the face of overwhelming odds and incredible danger, might I add - I give $N this, and I extend upon $Ghim:her; our undying gratitude as a true hero of the Alliance. Cheers, I say!" WHERE `ID`=5237;
UPDATE `quest_offer_reward` SET `RewardText`="$N, your successful re-engineering of the cauldrons is a tremendous victory for us!$B$B<The high executor clears his throat and begins to bellow loudly.>$B$BLet all within my presence hear: for service to the Forsaken and to the Horde as a whole above and beyond what was expected - in the face of overwhelming odds and incredible danger, might I add - I give $N this, and I extend upon $Ghim:her; our undying gratitude as a true hero of the Horde. Huzzah!" WHERE `ID`=5238;
*/
