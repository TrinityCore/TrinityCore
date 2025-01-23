DELETE FROM `gameobject_template` WHERE `entry` IN (434538 /*Campfire*/, 434540 /*Bonfire*/, 434534 /*Campfire*/, 434546 /*Meeting Stone*/, 441831 /*Ghost Gate (Scale 12x)*/, 208934 /*Fandral's Flame*/, 208933 /*Fandral's Flame*/, 452222 /*Instance Portal (Raid 10/25 No Heroic)*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(434538, 8, 192, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 54737), -- Campfire
(434540, 8, 7748, 'Bonfire', '', '', '', 1, 4, 10, 2066, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 54737), -- Bonfire
(434534, 8, 192, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 54737), -- Campfire
(434546, 23, 5495, 'Meeting Stone', '', '', '', 1, 15, 255, 5095, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 54737), -- Meeting Stone
(441831, 5, 6391, 'Ghost Gate (Scale 12x)', '', '', '', 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 54737), -- Ghost Gate (Scale 12x)
(208934, 18, 10648, 'Fandral\'s Flame', '', '', '', 1, 3, 99759, 99750, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 58158), -- Fandral's Flame
(208933, 18, 10648, 'Fandral\'s Flame', '', '', '', 1, 3, 99751, 99750, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 58158), -- Fandral's Flame
(452222, 31, 74868, 'Instance Portal (Raid 10/25 No Heroic)', '', '', '', 1.5, 2, 216, 217, 216, 217, 83033, 0, 5, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 57359); -- Instance Portal (Raid 10/25 No Heroic)

UPDATE `gameobject_template` SET `castBarCaption`='', `Data8`=26543, `Data14`=0, `VerifiedBuild`=55006 WHERE `entry`=204360; -- Monstrous Clam
UPDATE `gameobject_template` SET `Data3`=9254, `VerifiedBuild`=55262 WHERE `entry`=188134; -- Ice Stone
UPDATE `gameobject_template` SET `Data3`=9255, `VerifiedBuild`=55262 WHERE `entry`=188135; -- Ice Stone
UPDATE `gameobject_template` SET `Data6`=0, `VerifiedBuild`=55262 WHERE `entry`=188130; -- Ice Stone
UPDATE `gameobject_template` SET `castBarCaption`='', `Data8`=26543, `Data14`=0, `VerifiedBuild`=55262 WHERE `entry`=204360; -- Monstrous Clam
UPDATE `gameobject_template` SET `Data6`=0, `VerifiedBuild`=58158 WHERE `entry`=208866; -- Return Portal
UPDATE `gameobject_template` SET `Data6`=0, `Data8`=0, `Data10`=1, `VerifiedBuild`=58158 WHERE `entry`=208808; -- Ice Wall
UPDATE `gameobject_template` SET `IconName`='LootAll', `castBarCaption`='Looting', `Data6`=0, `Data8`=29193, `Data14`=37733, `VerifiedBuild`=58158 WHERE `entry`=208430; -- Timeless Eye
UPDATE `gameobject_template` SET `Data6`=0, `VerifiedBuild`=58158 WHERE `entry`=208932; -- Portal to Coldarra
UPDATE `gameobject_template` SET `Data6`=0, `VerifiedBuild`=58158 WHERE `entry`=208507; -- Nexus Runes
UPDATE `gameobject_template` SET `IconName`='Interact', `Data4`=1, `Data6`=1, `VerifiedBuild`=58158 WHERE `entry`=209106; -- Timeless Eye
UPDATE `gameobject_template` SET `Data6`=0, `VerifiedBuild`=58158 WHERE `entry`=208868; -- Nether Vortex
UPDATE `gameobject_template` SET `Data6`=0, `VerifiedBuild`=58158 WHERE `entry`=208865; -- Return Portal
UPDATE `gameobject_template` SET `Data6`=0, `VerifiedBuild`=54737 WHERE `entry`=184856; -- Box C
UPDATE `gameobject_template` SET `Data20`=80, `Data25`=1096, `VerifiedBuild`=54525 WHERE `entry`=202238; -- Deathbringer's Cache
UPDATE `gameobject_template` SET `Data20`=80, `VerifiedBuild`=54525 WHERE `entry`=202177; -- Gunship Armory
UPDATE `gameobject_template` SET `Data1`=85, `VerifiedBuild`=55639 WHERE `entry`=186668; -- Explosive Trap

DELETE FROM `gameobject_questitem` WHERE (`GameObjectEntry`=208430 AND `Idx`=0);
INSERT INTO `gameobject_questitem` (`GameObjectEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(208430, 0, 69238, 58158); -- Timeless Eye
