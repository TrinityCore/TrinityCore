DELETE FROM `gameobject_template` WHERE `entry` IN (375546 /*Archaeologist's Cart*/, 375544 /*Wooden Figurine*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(375546, 5, 73176, 'Archaeologist\'s Cart', '', '', '', 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 57564), -- Archaeologist's Cart
(375544, 10, 406, 'Wooden Figurine', '', '', '', 1.5, 259, 0, 0, 3000, 0, 1, 0, 0, 0, 0, 367069, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 95570, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 57564); -- Wooden Figurine

UPDATE `gameobject_template` SET `Data0`=77, `VerifiedBuild`=58558 WHERE `entry`=193166; -- Meeting Stone
UPDATE `gameobject_template` SET `Data0`=77, `VerifiedBuild`=58558 WHERE `entry`=193166; -- Meeting Stone
UPDATE `gameobject_template` SET `Data0`=77, `VerifiedBuild`=58558 WHERE `entry`=193166; -- Meeting Stone
UPDATE `gameobject_template` SET `ContentTuningId`=65, `VerifiedBuild`=58558 WHERE `entry`=191303; -- Firethorn
UPDATE `gameobject_template` SET `size`=3, `VerifiedBuild`=58158 WHERE `entry`=185950; -- Simon Game Aura Red Large
UPDATE `gameobject_template` SET `size`=3, `VerifiedBuild`=58158 WHERE `entry`=185949; -- Simon Game Aura Green Large
UPDATE `gameobject_template` SET `size`=3, `VerifiedBuild`=58158 WHERE `entry`=185948; -- Simon Game Aura Blue Large
UPDATE `gameobject_template` SET `Data22`=5793, `VerifiedBuild`=58158 WHERE `entry`=185214; -- Fermented Seed Beer Keg
UPDATE `gameobject_template` SET `Data0`=70, `VerifiedBuild`=58158 WHERE `entry`=184462; -- Meeting Stone
UPDATE `gameobject_template` SET `Data22`=5793, `VerifiedBuild`=58158 WHERE `entry`=185213; -- Ripe Moonshine Keg
UPDATE `gameobject_template` SET `Data0`=70, `VerifiedBuild`=58158 WHERE `entry`=184462; -- Meeting Stone
UPDATE `gameobject_template` SET `Data22`=5793, `VerifiedBuild`=58158 WHERE `entry`=185214; -- Fermented Seed Beer Keg
UPDATE `gameobject_template` SET `Data22`=5793, `VerifiedBuild`=58158 WHERE `entry`=185213; -- Ripe Moonshine Keg
UPDATE `gameobject_template` SET `Data5`=0, `VerifiedBuild`=58158 WHERE `entry`=184729; -- The Thunderspike
UPDATE `gameobject_template` SET `displayId`=408, `VerifiedBuild`=58158 WHERE `entry` IN (3916, 3914, 3921, 3920, 3918, 3917, 174953, 3919); -- Burning Embers
UPDATE `gameobject_template` SET `displayId`=201, `VerifiedBuild`=58158 WHERE `entry` IN (3933, 3932, 3930, 3923, 3922, 3928, 3927, 3924, 3915, 3931, 3926, 3925, 3913, 3934); -- Blazing Fire
UPDATE `gameobject_template` SET `displayId`=654, `VerifiedBuild`=58158 WHERE `entry` IN (3929, 3912); -- Blazing Fire
UPDATE `gameobject_template` SET `Data1`=0, `VerifiedBuild`=58158 WHERE `entry`=185211; -- Cursed Egg
UPDATE `gameobject_template` SET `size`=0.560000002384185791, `Data0`=4, `Data1`=10, `Data2`=2061, `VerifiedBuild`=57916 WHERE `entry`=181488; -- Bonfire
UPDATE `gameobject_template` SET `Data6`=0, `VerifiedBuild`=57564 WHERE `entry`=185016; -- Shadow Council Magic Device 01
UPDATE `gameobject_template` SET `type`=1, `Data2`=3000, `VerifiedBuild`=57564 WHERE `entry`=177746; -- Ghost Magnet
UPDATE `gameobject_template` SET `name`='Dweller\'s Crate', `VerifiedBuild`=56713 WHERE `entry`=202065; -- "Damsel's" "Purse"
UPDATE `gameobject_template` SET `Data0`=42, `VerifiedBuild`=56713 WHERE `entry`=178829; -- Meeting Stone
UPDATE `gameobject_template` SET `Data6`=0, `VerifiedBuild`=56713 WHERE `entry`=205891; -- Highvale Records
UPDATE `gameobject_template` SET `Data6`=0, `VerifiedBuild`=56713 WHERE `entry`=205890; -- Highvale Report
UPDATE `gameobject_template` SET `Data6`=0, `VerifiedBuild`=56713 WHERE `entry`=205892; -- Highvale Notes
UPDATE `gameobject_template` SET `Data6`=0, `VerifiedBuild`=56713 WHERE `entry`=205891; -- Highvale Records
UPDATE `gameobject_template` SET `Data4`=1, `Data6`=0, `Data7`=1, `Data9`=1, `Data14`=1, `VerifiedBuild`=56713 WHERE `entry`=204945; -- Explosive Trap
UPDATE `gameobject_template` SET `castBarCaption`='Pouring', `Data6`=0, `Data14`=39286, `VerifiedBuild`=56713 WHERE `entry`=202567; -- Keg of Ol' Barkerstout
UPDATE `gameobject_template` SET `Data6`=0, `VerifiedBuild`=56713 WHERE `entry`=202571; -- Bael'dun Fortress Schematics
UPDATE `gameobject_template` SET `Data6`=0, `VerifiedBuild`=56713 WHERE `entry`=202570; -- Mysterious Cheese
UPDATE `gameobject_template` SET `castBarCaption`='Activating', `Data6`=27700, `VerifiedBuild`=56713 WHERE `entry`=202562; -- Emergency Fire Valve
UPDATE `gameobject_template` SET `Data6`=0, `VerifiedBuild`=55639 WHERE `entry`=202453; -- Big Haunch of Stormsnout Meat
UPDATE `gameobject_template` SET `Data6`=0, `VerifiedBuild`=55639 WHERE `entry`=202461; -- Captured Tower Banner - Alliance
UPDATE `gameobject_template` SET `Data0`=16, `VerifiedBuild`=55262 WHERE `entry`=178884; -- Meeting Stone
UPDATE `gameobject_template` SET `Data6`=0, `VerifiedBuild`=55262 WHERE `entry`=204587; -- Narkk's Handbombs
UPDATE `gameobject_template` SET `Data6`=0, `VerifiedBuild`=55262 WHERE `entry`=204586; -- Bloodsail Rope
UPDATE `gameobject_template` SET `Data6`=0, `VerifiedBuild`=55262 WHERE `entry`=204585; -- Blackwater Rope
UPDATE `gameobject_template` SET `Data4`=1, `Data6`=0, `Data18`=81, `VerifiedBuild`=55262 WHERE `entry`=204572; -- Pirate Ship
UPDATE `gameobject_template` SET `Data4`=1, `Data6`=0, `Data18`=81, `VerifiedBuild`=55262 WHERE `entry`=204571; -- Pirate Ship
UPDATE `gameobject_template` SET `Data4`=1, `Data6`=0, `Data18`=81, `VerifiedBuild`=55262 WHERE `entry`=204570; -- Pirate Ship
UPDATE `gameobject_template` SET `Data4`=1, `Data6`=0, `Data18`=81, `VerifiedBuild`=55262 WHERE `entry`=204569; -- Pirate Ship
UPDATE `gameobject_template` SET `Data4`=1, `Data6`=0, `Data18`=81, `VerifiedBuild`=55262 WHERE `entry`=204568; -- Pirate Ship
UPDATE `gameobject_template` SET `Data4`=1, `Data6`=0, `Data18`=93, `VerifiedBuild`=55262 WHERE `entry`=204567; -- Pirate Ship
UPDATE `gameobject_template` SET `Data4`=1, `Data6`=0, `Data18`=92, `VerifiedBuild`=55262 WHERE `entry`=204566; -- Pirate Ship (Riptide)
UPDATE `gameobject_template` SET `Data4`=1, `Data6`=0, `Data18`=91, `VerifiedBuild`=55262 WHERE `entry`=204565; -- Pirate Ship (Damsel's Luck)
UPDATE `gameobject_template` SET `Data3`=9258, `VerifiedBuild`=55141 WHERE `entry`=188139; -- Ice Stone

DELETE FROM `gameobject_questitem` WHERE (`Idx`=1 AND `GameObjectEntry`=184815) OR (`Idx`=0 AND `GameObjectEntry` IN (205891,205890,205892));
INSERT INTO `gameobject_questitem` (`GameObjectEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(184815, 1, 30525, 58158), -- Sealed Coffin
(205891, 0, 61973, 56713), -- Highvale Records
(205890, 0, 61972, 56713), -- Highvale Report
(205892, 0, 61974, 56713); -- Highvale Notes

UPDATE `gameobject_questitem` SET `ItemId`=30525, `VerifiedBuild`=58158 WHERE (`GameObjectEntry`=184810 AND `Idx`=1); -- Sealed Coffin
UPDATE `gameobject_questitem` SET `ItemId`=58957, `VerifiedBuild`=55141 WHERE (`GameObjectEntry`=204388 AND `Idx`=1); -- Blackrock Coffer
UPDATE `gameobject_questitem` SET `ItemId`=58956, `VerifiedBuild`=55141 WHERE (`GameObjectEntry`=204388 AND `Idx`=0); -- Blackrock Coffer
