DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=0 AND `Entry` IN (241468,241467,241010,241008,240325,240324,240323,240322,240321,240320,240309,240308,240090,240012,239974,239945,237248,234505,234503,73873));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`) VALUES
(241468, 0, 2, 1, 1, 0, 0x0, 0), -- Zarstrasza
(241467, 0, 2, 1, 1, 0, 0x0, 0), -- Sylstrasza
(241010, 0, 3, 2.65000009536743164, 1, 0, 0x48, 0), -- Forgotten One
(241008, 0, 3, 1.5, 3367.75927734375, 0, 0x440, 0), -- Mana Void
(240325, 0, 3, 5, 1, 0, 0x40, 0), -- Shadowed Globule
(240324, 0, 3, 5, 1, 0, 0x40, 0), -- Glowing Globule
(240323, 0, 3, 5, 1, 0, 0x40, 0), -- Crimson Globule
(240322, 0, 3, 5, 1, 0, 0x40, 0), -- Cobalt Globule
(240321, 0, 3, 5, 1, 0, 0x40, 0), -- Dark Globule
(240320, 0, 3, 5, 1, 0, 0x40, 0), -- Acidic Globule
(240309, 0, 3, 25, 10, 0, 0x48, 0), -- Wyrmrest Defender
(240308, 0, 3, 25, 10, 0, 0x48, 0), -- Wyrmrest Defender
(240090, 0, 3, 4, 1, 0, 0x8, 0), -- Trop the Heroic
(240012, 0, 2, 1, 1, 0, 0x1000, 0), -- Dragon Soultaur
(239974, 0, 0, 1, 1, 0, 0x0, 0), -- Denaa Hollowbark
(239945, 0, 0, 1, 1, 0, 0x0, 0), -- Alania Hollowbark
(237248, 0, 0, 1, 1, 0, 0x0, 0), -- Joyous
(234505, 0, 3, 1, 1, 0, 0x0, 0), -- Sha-Touched Cloud Serpent
(234503, 0, 3, 1, 1, 0, 0x0, 0), -- Sha-Touched Riding Tiger
(73873, 0, 0, 1, 1, 0, 0x8000000, 0); -- Shop

UPDATE `creature_template_difficulty` SET `TypeFlags2`=128 WHERE (`Entry`=53695 AND `DifficultyID`=0); -- Rageface
UPDATE `creature_template_difficulty` SET `TypeFlags2`=128 WHERE (`Entry`=53694 AND `DifficultyID`=0); -- Riplimb
UPDATE `creature_template_difficulty` SET `TypeFlags2`=128 WHERE (`Entry`=41270 AND `DifficultyID`=0); -- Onyxia
UPDATE `creature_template_difficulty` SET `TypeFlags2`=128 WHERE (`Entry`=39625 AND `DifficultyID`=0); -- General Umbriss

DELETE FROM `creature_template` WHERE `entry` IN (234503 /*Sha-Touched Riding Tiger*/, 234505 /*Sha-Touched Cloud Serpent*/, 237248 /*Joyous*/, 239945 /*Alania Hollowbark*/, 239974 /*Denaa Hollowbark*/, 240012 /*Dragon Soultaur*/, 240090 /*Trop the Heroic*/, 240308 /*Wyrmrest Defender*/, 240309 /*Wyrmrest Defender*/, 240320 /*Acidic Globule*/, 240321 /*Dark Globule*/, 240322 /*Cobalt Globule*/, 240323 /*Crimson Globule*/, 240324 /*Glowing Globule*/, 240325 /*Shadowed Globule*/, 241008 /*Mana Void*/, 241010 /*Forgotten One*/, 241467 /*Sylstrasza*/, 241468 /*Zarstrasza*/, 73873 /*Shop*/);
INSERT INTO `creature_template` (`entry`, `Civilian`, `KillCredit1`, `KillCredit2`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `RequiredExpansion`, `VignetteID`, `unit_class`, `WidgetSetID`, `WidgetSetUnitConditionID`, `Classification`, `family`, `type`, `PetSpellDataId`, `RacialLeader`, `movementId`, `VerifiedBuild`) VALUES
(234503, 0, 0, 0, 'Sha-Touched Riding Tiger', NULL, NULL, NULL, NULL, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 60142), -- Sha-Touched Riding Tiger
(234505, 0, 0, 0, 'Sha-Touched Cloud Serpent', NULL, NULL, NULL, NULL, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 60142), -- Sha-Touched Cloud Serpent
(237248, 1, 0, 0, 'Joyous', NULL, NULL, NULL, NULL, 0, 0, 1, 0, 0, 0, 0, 12, 0, 0, 121, 60142), -- Joyous
(239945, 0, 0, 0, 'Alania Hollowbark', NULL, 'Molten Front Recruiter', NULL, NULL, 0, 0, 1, 0, 0, 0, 0, 7, 0, 0, 0, 60142), -- Alania Hollowbark
(239974, 0, 0, 0, 'Denaa Hollowbark', NULL, 'Molten Front Recruiter', NULL, NULL, 0, 0, 1, 0, 0, 0, 0, 7, 0, 0, 0, 60142), -- Denaa Hollowbark
(240012, 1, 0, 0, 'Dragon Soultaur', NULL, 'Dragon Soul Supplies', NULL, NULL, 0, 0, 8, 0, 0, 0, 0, 9, 0, 0, 0, 60142), -- Dragon Soultaur
(240090, 0, 0, 0, 'Trop the Heroic', NULL, NULL, NULL, NULL, 0, 0, 1, 0, 0, 1, 0, 7, 0, 0, 164, 60142), -- Trop the Heroic
(240308, 0, 0, 0, 'Wyrmrest Defender', NULL, NULL, NULL, NULL, 0, 0, 1, 0, 0, 1, 0, 7, 0, 0, 0, 60142), -- Wyrmrest Defender
(240309, 0, 0, 0, 'Wyrmrest Defender', NULL, NULL, NULL, NULL, 0, 0, 1, 0, 0, 1, 0, 7, 0, 0, 0, 60142), -- Wyrmrest Defender
(240320, 0, 0, 0, 'Acidic Globule', NULL, 'Blood of Shu\'ma', NULL, NULL, 0, 0, 1, 0, 0, 1, 0, 10, 0, 0, 89, 60142), -- Acidic Globule
(240321, 0, 0, 0, 'Dark Globule', NULL, 'Blood of Shu\'ma', NULL, NULL, 0, 0, 1, 0, 0, 1, 0, 10, 0, 0, 89, 60142), -- Dark Globule
(240322, 0, 0, 0, 'Cobalt Globule', NULL, 'Blood of Shu\'ma', NULL, NULL, 0, 0, 1, 0, 0, 1, 0, 10, 0, 0, 89, 60142), -- Cobalt Globule
(240323, 0, 0, 0, 'Crimson Globule', NULL, 'Blood of Shu\'ma', NULL, NULL, 0, 0, 1, 0, 0, 1, 0, 10, 0, 0, 89, 60142), -- Crimson Globule
(240324, 0, 0, 0, 'Glowing Globule', NULL, 'Blood of Shu\'ma', NULL, NULL, 0, 0, 1, 0, 0, 1, 0, 10, 0, 0, 89, 60142), -- Glowing Globule
(240325, 0, 0, 0, 'Shadowed Globule', NULL, 'Blood of Shu\'ma', NULL, NULL, 0, 0, 1, 0, 0, 1, 0, 10, 0, 0, 89, 60142), -- Shadowed Globule
(241008, 0, 0, 0, 'Mana Void', NULL, NULL, NULL, NULL, 0, 0, 1, 0, 0, 1, 0, 10, 0, 0, 70, 60142), -- Mana Void
(241010, 0, 0, 0, 'Forgotten One', NULL, NULL, NULL, NULL, 0, 0, 1, 0, 0, 1, 0, 10, 0, 0, 150, 60142), -- Forgotten One
(241467, 1, 0, 0, 'Sylstrasza', NULL, 'Obsidian Fragment Exchange', NULL, NULL, 0, 0, 8, 0, 0, 0, 0, 2, 0, 0, 0, 60142), -- Sylstrasza
(241468, 1, 0, 0, 'Zarstrasza', NULL, 'Obsidian Fragment Exchange', NULL, NULL, 0, 0, 8, 0, 0, 0, 0, 2, 0, 0, 0, 60142), -- Zarstrasza
(73873, 0, 0, 0, 'Shop', NULL, NULL, NULL, NULL, 0, 0, 1, 0, 0, 0, 0, 7, 0, 0, 0, 60142); -- Shop

UPDATE `creature_template` SET `name`='Lord Devrestrasz', `VerifiedBuild`=60142 WHERE `entry`=55476; -- Lord Afrasastrasz

DELETE FROM `creature_template_model` WHERE (`Idx`=0 AND `CreatureID` IN (241468,241467,241010,241008,240325,240324,240323,240322,240321,240320,240309,240308,240090,240012,239974,239945,237248,234505,234503,73873)) OR (`Idx`=1 AND `CreatureID` IN (241008,240309,240308)) OR (`Idx`=3 AND `CreatureID` IN (240309,240308)) OR (`Idx`=2 AND `CreatureID` IN (240309,240308));
INSERT INTO `creature_template_model` (`CreatureID`, `Idx`, `CreatureDisplayID`, `DisplayScale`, `Probability`, `VerifiedBuild`) VALUES
(241468, 0, 127918, 1, 1, 60142), -- Zarstrasza
(241467, 0, 28017, 0.800000011920928955, 1, 60142), -- Sylstrasza
(241010, 0, 27849, 1, 1, 60142), -- Forgotten One
(241008, 1, 1126, 1, 0, 60142), -- Mana Void
(241008, 0, 39369, 1, 1, 60142), -- Mana Void
(240325, 0, 39788, 1, 1, 60142), -- Shadowed Globule
(240324, 0, 39630, 1, 1, 60142), -- Glowing Globule
(240323, 0, 39629, 1, 1, 60142), -- Crimson Globule
(240322, 0, 39787, 1, 1, 60142), -- Cobalt Globule
(240321, 0, 39786, 1, 1, 60142), -- Dark Globule
(240320, 0, 39785, 1, 1, 60142), -- Acidic Globule
(240309, 3, 39610, 1, 1, 60142), -- Wyrmrest Defender
(240309, 2, 39606, 1, 1, 60142), -- Wyrmrest Defender
(240309, 1, 39600, 1, 1, 60142), -- Wyrmrest Defender
(240309, 0, 39599, 1, 1, 60142), -- Wyrmrest Defender
(240308, 3, 39619, 1, 1, 60142), -- Wyrmrest Defender
(240308, 2, 39618, 1, 1, 60142), -- Wyrmrest Defender
(240308, 1, 39614, 1, 1, 60142), -- Wyrmrest Defender
(240308, 0, 39613, 1, 1, 60142), -- Wyrmrest Defender
(240090, 0, 3037, 1, 1, 60142), -- Trop the Heroic
(240012, 0, 21471, 0.85000002384185791, 1, 60142), -- Dragon Soultaur
(239974, 0, 127435, 1, 1, 60142), -- Denaa Hollowbark
(239945, 0, 127433, 1, 1, 60142), -- Alania Hollowbark
(237248, 0, 126072, 0.035000000149011611, 1, 60142), -- Joyous
(234505, 0, 124486, 1, 0, 60142), -- Sha-Touched Cloud Serpent
(234503, 0, 124485, 1, 0, 60142), -- Sha-Touched Riding Tiger
(73873, 0, 11686, 1, 1, 60142); -- Shop
