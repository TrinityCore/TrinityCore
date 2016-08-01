--
DELETE FROM `gameobject_loot_template` WHERE `Entry` IN (15561, 22937);
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(15561, 17411, 0, 100, 1, 1, 0, 1, 1, 'Gameobject Steamsaw contains item Steamsaw'),
(22937, 34102, 0, 100, 1, 1, 0, 1, 3, 'Gameobject Loose Rock contains item Fjord Grub');

DELETE FROM `spell_dbc` WHERE `Id` IN (95818,91203,91182,90062,94710,101170,91127,89978,94552,87003,87523,87477,83137,84192,84205,83737,83854,95940,85448,100562,99730);
INSERT INTO `spell_dbc` (`Id`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `CastingTimeIndex`, `DurationIndex`, `RangeIndex`, `SchoolMask`, `SpellAuraOptionsId`, `SpellCastingRequirementsId`, `SpellCategoriesId`, `SpellClassOptionsId`, `SpellEquippedItemsId`, `SpellLevelsId`, `SpellTargetRestrictionsId`, `SpellInterruptsId`, `Comment`) VALUES
(95818,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,38,0,0,0,0,0,0,0, 'Quest 14435 reward serverside spell'),
(91203,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,38,0,0,0,0,0,0,0, 'Quest 14121,14122,14123,14124 reward serverside spell'),
(91182,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,38,0,0,0,0,0,0,0, 'Quest 14070,24520 reward serverside spell'),
(90062,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,38,0,0,0,0,0,0,0, 'Quest 14007,14008,14009,14010,14011,14012,14013 reward serverside spell'),
(94710,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,38,0,0,0,0,0,0,0, 'Quest 13980 reward serverside spell'),
(101170,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,38,0,0,0,0,0,0,0, 'Quest 29203 reward serverside spell'),
(91127,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,38,0,0,0,0,0,0,0, 'Quest 24503,28414 reward serverside spell'),
(89978,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,38,0,0,0,0,0,0,0, 'Quest 28346 reward serverside spell'),
(94552,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,38,0,0,0,0,0,0,0, 'Quest 28170 reward serverside spell'),
(87003,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,38,0,0,0,0,0,0,0, 'Quest 27744 reward serverside spell'),
(87523,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,38,0,0,0,0,0,0,0, 'Quest 25807 reward serverside spell'),
(87477,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,38,0,0,0,0,0,0,0, 'Quest 25491,25502,25520 reward serverside spell'),
(83137,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,38,0,0,0,0,0,0,0, 'Quest 24864 reward serverside spell'),
(84192,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,38,0,0,0,0,0,0,0, 'Quest 26938 reward serverside spell'),
(84205,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,38,0,0,0,0,0,0,0, 'Quest 27089,27090 reward serverside spell'),
(83737,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,38,0,0,0,0,0,0,0, 'Quest 27038 reward serverside spell'),
(83854,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,38,0,0,0,0,0,0,0, 'Quest 27060 reward serverside spell'),
(95940,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,38,0,0,0,0,0,0,0, 'Quest 27329,27330 reward serverside spell'),
(85448,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,38,0,0,0,0,0,0,0, 'Quest 27516 reward serverside spell'),
(100562,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,38,0,0,0,0,0,0,0, 'Quest 29338 reward serverside spell'),
(99730,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,38,0,0,0,0,0,0,0, 'Quest 29328 reward serverside spell');
