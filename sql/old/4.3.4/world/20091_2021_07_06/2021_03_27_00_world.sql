-- The Maelstrom pre-quests
DELETE FROM `quest_template_addon` WHERE `ID` IN (27722, 27727, 27443, 27398, 27203, 27123, 26245, 26246, 26244, 26247, 27136, 26248, 26249, 26251, 26250, 26258, 26256, 26261, 26260, 27007, 27010, 27061, 28866, 26768, 26766, 26771, 26861, 26857, 26876);
INSERT INTO `quest_template_addon` (`ID`, `ExclusiveGroup`, `PrevQuestID`, `NextQuestID`, `BreadCrumbForQuestId`, `SpecialFlags`) VALUES
-- OPTIONAL QUESTLINE
-- Heroe's Call, Warchief's Command and zone specific breadcrumbs leading to the next breadcrumb chain
(27722, 27722, 0, 27203, 0, 0),
(27727, 27722, 0, 27203, 0, 0),
(27443, 27722, 0, 27203, 0, 0),
(27398, 27722, 0, 27203, 0, 0),
-- The Maelstrom
(27203, 0, 0, 27123, 0, 0),
-- Deepholm, Realm of Earth
(27123, 0, 27203, 0, 0, 0),

-- FIRST PILLAR FRAGMENT
-- Group A: Gunship Down, Captain's Log, The Earth Claims All, Elemental Energy
(26245, -26245, 0, 26247, 0, 0),
(26246, -26245, 0, 26247, 0, 0),
(26244, -26245, 0, 26247, 0, 0),
-- 27136 - The Earth Claims All is an optional quest

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

-- Maelstrom Fire Target Bunny trigger flag
UPDATE `creature_template` SET `flags_extra`= 128 WHERE `entry`= 48202;

-- Areatrigger Credits
DELETE FROM `areatrigger_involvedrelation` WHERE `id` IN (6126, 6221);
INSERT INTO `areatrigger_involvedrelation` (`id`, `quest`) VALUES
(6126, 26258),
(6221, 27007);

UPDATE `quest_template_addon` SET `ProvidedItemCount`= 1 WHERE `ID` IN (26248, 26861, 26766, 26771, 26876, 27136);
