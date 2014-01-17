-- If He Cannot Be Turned (12896 + 12897)
UPDATE `quest_template` SET `PrevQuestId`=12893 WHERE `Id` IN (12896,12897);
-- Get the Key (12949)
UPDATE `quest_template` SET `PrevQuestId`=12939 WHERE `Id`=12949;
-- Leave Our Mark (12995)
UPDATE `quest_template` SET `PrevQuestId`=13084 WHERE `Id`=12995;
-- Vandalizing Jotunheim (13084) / Crush Dem Vrykuls! (12992)
UPDATE `quest_template` SET `NextQuestId`=13085,`ExclusiveGroup`=-13085 WHERE `Id` IN (13084,12992);
-- Intelligence Gathering (12838) / From Their Corpses, Rise! (12813)
UPDATE `quest_template` SET `PrevQuestId`=12807 WHERE `Id` IN (12838,12813);
-- No Fly Zone (12815)
UPDATE `quest_template` SET `PrevQuestId`=12814 WHERE `Id`=12815;
-- Eliminate the Competition (12955)
UPDATE `quest_template` SET `PrevQuestId`=12938 WHERE `Id`=12955;
-- Deep in the Bowels of The Underhalls (13042)
UPDATE `quest_template` SET `PrevQuestId`=12999 WHERE `Id`=13042;
-- Battle at Valhalas: Fallen Heroes (13214)
UPDATE `quest_template` SET `PrevQuestId`=13213 WHERE `Id`=13214;
