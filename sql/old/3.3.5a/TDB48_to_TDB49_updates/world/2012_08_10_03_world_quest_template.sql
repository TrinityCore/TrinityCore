-- Zandalar Tribe Quests Required Class/Race fix by nelegalno

-- Maywiki of Zuldazar Quests Required Class
UPDATE `quest_template` SET `RequiredClasses` = 64 WHERE `Id` IN (8056,8074,8075,8116,8117,8118,8119); -- Shaman
UPDATE `quest_template` SET `RequiredClasses` = 1024 WHERE `Id` IN (8057,8064,8065,8110,8111,8112,8113); -- Druid

-- Al'tabim the All-Seeing Quests Required Class
UPDATE `quest_template` SET `RequiredClasses` = 16 WHERE `Id` IN (8049,8050,8051,8052,8061,8070,8071); -- Priest
UPDATE `quest_template` SET `RequiredClasses` = 128 WHERE `Id` IN (8060,8068,8069,8101,8102,8103,8104); -- Mage
UPDATE `quest_template` SET `RequiredClasses` = 256 WHERE `Id` IN (8059,8076,8077,8106,8107,8108,8109); -- Warlock

-- Falthir the Sightless Quests Required Class
UPDATE `quest_template` SET `RequiredClasses` = 4 WHERE `Id` IN (8062,8066,8067,8145,8146,8147,8148); -- Hunter
UPDATE `quest_template` SET `RequiredClasses` = 8 WHERE `Id` IN (8063,8072,8073,8141,8142,8143,8144); -- Rogue
UPDATE `quest_template` SET `RequiredRaces` = 152 WHERE `Id` = 8144; -- Night Elf, Undead and Troll

-- Jin'rokh the Breaker
UPDATE `quest_template` SET `RequiredRaces` = 513 WHERE `Id` = 8048; -- Human and Blood Elf
