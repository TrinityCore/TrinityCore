--
UPDATE `quest_template` SET `AllowableRaces` = 512 WHERE `ID` = 9489; -- Cleansing the Scar
UPDATE `quest_template_addon` SET `NextQuestID` = 0, `ExclusiveGroup` = 0 WHERE `ID` = 9489; -- Cleansing the Scar
UPDATE `quest_template` SET `AllowableRaces` = 1024 WHERE `ID` = 9586; -- Help Tavara
UPDATE `quest_template_addon` SET `NextQuestID` = 0, `ExclusiveGroup` = 0 WHERE `ID` = 9586; -- Help Tavara
UPDATE `quest_template` SET `AllowableRaces` = 16 WHERE `ID` = 5651; -- In Favor of Darkness
UPDATE `quest_template_addon` SET `NextQuestID` = 5650, `ExclusiveGroup` = 0 WHERE `ID` = 5651; -- In Favor of Darkness
UPDATE `quest_template` SET `AllowableRaces` = 16 WHERE `ID` = 5650; -- Garments of Darkness
UPDATE `quest_template` SET `AllowableRaces` = 128 WHERE `ID` = 5649; -- In Favor of Spirituality
UPDATE `quest_template_addon` SET `ExclusiveGroup` = 0 WHERE `ID` = 5649; -- In Favor of Spirituality
UPDATE `quest_template` SET `AllowableRaces` = 128 WHERE `ID` = 5648; -- Garments of Spirituality
UPDATE `quest_template_addon` SET `PrevQuestID` = 5649 WHERE `ID` = 5648; -- Garments of Spirituality
UPDATE `quest_template` SET `AllowableRaces` = 1 WHERE `ID` = 5623; -- In Favor of the Light
UPDATE `quest_template_addon` SET `ExclusiveGroup` = 0 WHERE `ID` = 5623; -- In Favor of the Light
UPDATE `quest_template` SET `AllowableRaces` = 1 WHERE `ID` = 5624; -- Garments of Light
UPDATE `quest_template_addon` SET `PrevQuestID` = 5623 WHERE `ID` = 5624; -- Garments of Light
UPDATE `quest_template` SET `AllowableRaces` = 4 WHERE `ID` = 5626; -- In Favor of the Light
UPDATE `quest_template_addon` SET `NextQuestID` = 5625, `ExclusiveGroup` = 0 WHERE `ID` = 5626; -- In Favor of the Light
UPDATE `quest_template` SET `AllowableRaces` = 4 WHERE `ID` = 5625; -- Garments of Light
