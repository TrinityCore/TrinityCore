-- Questchain
DELETE FROM `quest_template_addon` WHERE `ID` IN (26245, 26246, 26244, 26247, 27136, 26248, 26249, 26251, 26250, 26258, 26256, 26261, 26260, 27007, 27010, 27061, 28866, 26768, 26766, 26771, 26861, 26857, 26876);
INSERT INTO `quest_template_addon` (`ID`, `ExclusiveGroup`, `PrevQuestID`, `NextQuestID`, `BreadCrumbForQuestId`, `SpecialFlags`) VALUES
-- Group A: Gunship Down, Captain's Log, The Earth Claims All, Elemental Energy
(26245, -26245, 0, 26247, 0, 0),
(26246, -26245, 26415, 26247, 0, 0), -- Serverside Quest which unlocks this Quest
(26244, -26245, 0, 26247, 0, 0),
-- 27136 - Elemental Energy is an optional quest

-- Group B: The Admiral's Cabin, All Our Friends Are Dead!
(26249, 0, 26247, 0, 0, 0),
(26248, 0, 26247, 0, 0, 0),
-- Group B2: Take no Prisoners, On Second Thought, Take One Prisoner
(26251, 0, 26248, 0, 0, 0),
(26250, 0, 26248, 0, 0, 0),

-- Group C: Deathwing's Fall
(26258, 0, 26255, 0, 0, 2), -- This quest needs special flags as it's being completed by an area trigger event
-- Group C1: Bleed the Bloodshaper
(26256, 0, 26258, 0, 0, 0),
-- Group C2: Question the Slaves
(26261, 0, 26256, 26260, 0, 0),
-- Group C3: The Forgemaster's Log
(26260, 0, 26261, 0, 0, 0),
-- Group C4: Silvermarsh Rendezvous
(27007, 0, 26260, 27010, 0, 2),
-- Group C5: Quicksilver Submersion
(27010, 0, 27007, 27061, 0, 0),
-- Group C6: The Twilight Overlook
(27061, 0, 27010, 0, 0, 0),
-- Group D: Into the Stonecore, To Catch a Dragon, Big Game, Big Bait
(28866, 0, 27061, 0, 0, 0),
(26768, -26768, 27061, 26771, 0, 0),
(26766, -26768, 27061, 26771, 0, 0),
-- Group D1: Abyssion's Minions, Block the Gates
(26861, -26861, 26771, 26876, 0, 0),
(26857, -26861, 26771, 26876, 0, 0),
-- Group D2: The World Pillar Fragment
(26876, 0, 0, 0, 0, 0);

-- Remove old PrevQuests
UPDATE `quest_template_addon` SET `PrevQuestID` = 0 WHERE `ID` = 27203; -- gets available with Chromietime Cataclysm
UPDATE `quest_template_addon` SET `PrevQuestID` = 0 WHERE `ID` = 26409; -- is available without pre-quest
