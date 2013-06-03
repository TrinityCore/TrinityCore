-- Kandrostrasz <Brood of Alexstrasza> (15503) quests RequiredClasses fix by nelegalno
UPDATE `quest_template` SET `RequiredClasses` = 1 WHERE `Id` IN (8559,8560); -- Warrior
UPDATE `quest_template` SET `RequiredClasses` = 2 WHERE `Id` IN (8629,8655); -- Paladin
UPDATE `quest_template` SET `RequiredClasses` = 4 WHERE `Id` IN (8626,8658); -- Hunter
UPDATE `quest_template` SET `RequiredClasses` = 8 WHERE `Id` IN (8637,8640); -- Rogue
UPDATE `quest_template` SET `RequiredClasses` = 16 WHERE `Id` IN (8593,8596); -- Priest
UPDATE `quest_template` SET `RequiredClasses` = 64 WHERE `Id` IN (8621,8624); -- Shaman
UPDATE `quest_template` SET `RequiredClasses` = 128 WHERE `Id` IN (8631,8634); -- Mage
UPDATE `quest_template` SET `RequiredClasses` = 256 WHERE `Id` IN (8660,8663); -- Warlock
UPDATE `quest_template` SET `RequiredClasses` = 1024 WHERE `Id` IN (8665,8668); -- Druid

-- Andorgos <Brood of Malygos> (15502) quests RequiredClasses fix by nelegalno
UPDATE `quest_template` SET `RequiredClasses` = 1 WHERE `Id` IN (8544,8561); -- Warrior
UPDATE `quest_template` SET `RequiredClasses` = 2 WHERE `Id` IN (8628,8630); -- Paladin
UPDATE `quest_template` SET `RequiredClasses` = 4 WHERE `Id` IN (8657,8659); -- Hunter
UPDATE `quest_template` SET `RequiredClasses` = 8 WHERE `Id` IN (8639,8641); -- Rogue
UPDATE `quest_template` SET `RequiredClasses` = 16 WHERE `Id` IN (8592,8594); -- Priest
UPDATE `quest_template` SET `RequiredClasses` = 64 WHERE `Id` IN (8602,8623); -- Shaman
UPDATE `quest_template` SET `RequiredClasses` = 128 WHERE `Id` IN (8625,8632); -- Mage
UPDATE `quest_template` SET `RequiredClasses` = 256 WHERE `Id` IN (8662,8664); -- Warlock
UPDATE `quest_template` SET `RequiredClasses` = 1024 WHERE `Id` IN (8667,8669); -- Druid

-- Craftsman Wilhelm <Brotherhood of the Light> (16376) NPCs quests
UPDATE `quest_template` SET `RequiredClasses` = 3 WHERE `Id` IN (9234,9235,9236); -- Warrior, Paladin
UPDATE `quest_template` SET `RequiredClasses` = 68 WHERE `Id` IN (9244,9245,9246); -- Hunter, Shaman
UPDATE `quest_template` SET `RequiredClasses` = 400 WHERE `Id` IN (9238,9239,9240); -- Priest, Mage, Warlock
UPDATE `quest_template` SET `RequiredClasses` = 1032 WHERE `Id` IN (9241,9242,9243); -- Rogue, Druid

-- Zanza the Restless (15042) NPCs quests
UPDATE `quest_template` SET `RequiredClasses` = 1 WHERE `Id` = 8184; -- Warrior
UPDATE `quest_template` SET `RequiredClasses` = 2 WHERE `Id` = 8185; -- Paladin
UPDATE `quest_template` SET `RequiredClasses` = 4 WHERE `Id` = 8187; -- Hunter
UPDATE `quest_template` SET `RequiredClasses` = 8 WHERE `Id` = 8186; -- Rogue
UPDATE `quest_template` SET `RequiredClasses` = 16 WHERE `Id` = 8191; -- Priest
UPDATE `quest_template` SET `RequiredClasses` = 64 WHERE `Id` = 8188; -- Shaman
UPDATE `quest_template` SET `RequiredClasses` = 128 WHERE `Id` = 8189; -- Mage
UPDATE `quest_template` SET `RequiredClasses` = 256 WHERE `Id` = 8190; -- Warlock
UPDATE `quest_template` SET `RequiredClasses` = 1024 WHERE `Id` = 8192; -- Druid

-- Vethsera <Brood of Ysera> (15504) quests RequiredClasses fix by nelegalno
UPDATE `quest_template` SET `RequiredClasses` = 1 WHERE `Id` = 8562; -- Warrior
UPDATE `quest_template` SET `RequiredClasses` = 2 WHERE `Id` = 8627; -- Paladin
UPDATE `quest_template` SET `RequiredClasses` = 4 WHERE `Id` = 8656; -- Hunter
UPDATE `quest_template` SET `RequiredClasses` = 8 WHERE `Id` = 8638; -- Rogue
UPDATE `quest_template` SET `RequiredClasses` = 16 WHERE `Id` = 8603; -- Priest
UPDATE `quest_template` SET `RequiredClasses` = 64 WHERE `Id` = 8622; -- Shaman
UPDATE `quest_template` SET `RequiredClasses` = 128 WHERE `Id` = 8633; -- Mage
UPDATE `quest_template` SET `RequiredClasses` = 256 WHERE `Id` = 8661; -- Warlock
UPDATE `quest_template` SET `RequiredClasses` = 1024 WHERE `Id` = 8666; -- Druid
