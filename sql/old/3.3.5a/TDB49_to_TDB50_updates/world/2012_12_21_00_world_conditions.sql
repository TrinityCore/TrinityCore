DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (76092,75313,54047,46937,46936,46904,46903,45404,45226,45222,44608,44499,/*42178,*/40968,36546,26373,24731,11195);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 76092, 0, 0, 31, 0, 5, 193963, 0, 0, 0, 0, '', '[DND] Lil'' XT - Toy Train Set'),
(13, 1, 75313, 0, 0, 31, 0, 5, 202880, 0, 0, 0, 0, '', 'Bang Ritual Gong - Ritual Gong'),
(13, 1, 54047, 0, 0, 31, 0, 5, 191445, 0, 0, 0, 0, '', 'Light Lamp - Lamp Post'),
(13, 1, 46937, 0, 0, 31, 0, 5, 179786, 0, 0, 0, 0, '', 'Check Flag Cap - Warsong Flag'),
(13, 1, 46936, 0, 0, 31, 0, 5, 179830, 0, 0, 0, 0, '', 'Check Flag Cap - Silverwing Flag'),
(13, 1, 46904, 0, 0, 31, 0, 5, 181332, 0, 0, 0, 0, '', 'Light Bonfire (Art Kit) - Flame of Stormwind'),
(13, 1, 46903, 0, 0, 31, 0, 5, 187962, 0, 0, 0, 0, '', 'Stamp Out Bonfire (Art Kit) - Horde Bonfire'),
(13, 2, 45404, 0, 0, 31, 0, 5, 187432, 0, 0, 0, 0, '', 'Crush Under Foot - Alliance Flag'),
(13, 2, 45226, 0, 0, 31, 0, 5, 187359, 0, 0, 0, 0, '', 'Banging the Gong - Strange Gong'),
(13, 2, 45222, 0, 0, 31, 0, 5, 187359, 0, 0, 0, 0, '', 'Zul''aman Object Visual - Strange Gong'), -- correct?
(13, 2, 44608, 0, 0, 31, 0, 3, 24829, 0, 0, 0, 0, '', 'Rocket Jump - Transport Bot D1->D2'),
(13, 2, 44499, 0, 0, 31, 0, 5, 186957, 0, 0, 0, 0, '', 'Iron Rune Construct Credit 01 - unknown'),
-- (13, 1, 42178, 0, 0, 31, 0, 5, 186249, 0, 0, 0, 0, '', 'Headless Horseman - Invisible Campfire, Remove - unknown'), -- missing gameObject
(13, 2, 40968, 0, 0, 31, 0, 5, 185921, 0, 0, 0, 0, '', 'Bash''ir Crystalforge: Create 1 Flask - Bash''ir Crystalforge'),
(13, 2, 40968, 0, 0, 31, 0, 5, 185922, 0, 0, 0, 0, '', 'Bash''ir Crystalforge: Create 1 Flask - Crystalforge controller'),
(13, 2, 36546, 0, 0, 31, 0, 5, 184715, 0, 0, 0, 0, '', 'Boil Bleeding Hollow Blood - Cursed Cauldron'),
(13, 2, 26373, 0, 0, 31, 0, 3, 15892, 0, 0, 0, 0, '', 'Lunar Invitation - Lunar Festival Emissary'),
(13, 1, 24731, 0, 0, 31, 0, 3, 15218, 0, 0, 0, 0, '', 'Fire Cannon - Darkmoon Faire Cannon'),
(13, 2, 24731, 0, 0, 31, 0, 5, 180452, 0, 0, 0, 0, '', 'Fire Cannon - Blastenheimer 5000 Ultra Cannon'),
(13, 1, 11195, 0, 0, 31, 0, 5, 146084, 0, 0, 0, 0, '', 'Blow Zul''Farrak Door - End Door');
