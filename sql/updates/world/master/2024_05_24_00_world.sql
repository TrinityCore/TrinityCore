-- Creature templates
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=31393; -- Crystal Wyrm
UPDATE `creature_template` SET `unit_flags3`=67108864 WHERE `entry`=31404; -- Azure Manabeast
UPDATE `creature_template` SET `unit_flags3`=8388608 WHERE `entry`=32375; -- Warmage Yurias
UPDATE `creature_template` SET `unit_flags3`=8388608 WHERE `entry`=32369; -- Warmage Sarina
UPDATE `creature_template` SET `unit_flags3`=8388608 WHERE `entry`=32372; -- Warmage Ilsudria
UPDATE `creature_template` SET `unit_flags3`=8388608 WHERE `entry`=32371; -- Warmage Halister
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=31139; -- Pustulent Horror
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=32602; -- Dalaran Visitor
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=30281; -- Silver Covenant Hippogryph
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=35984; -- Sunreaver Dragonhawk
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=30861; -- Unbound Ancient

-- Difficulties
UPDATE `creature_template_difficulty` SET `ContentTuningID`=163, `VerifiedBuild`=52649 WHERE (`Entry`=33498 AND `DifficultyID`=0); -- 33498 (Maloric) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=163, `LootID`=33499, `VerifiedBuild`=52649 WHERE (`Entry`=33499 AND `DifficultyID`=0); -- 33499 (Skeletal Woodcutter) - 
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=52649 WHERE (`DifficultyID`=0 AND `Entry` IN (31393,31401,27306,31139,32325,32324,32321,30281,35984));
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=31404 AND `DifficultyID`=0); -- 31404 (Azure Manabeast) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0, `VerifiedBuild`=52649 WHERE (`Entry`=31403 AND `DifficultyID`=0); -- 31403 (Azure Spellweaver)
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0 WHERE (`Entry`=31402 AND `DifficultyID`=0);
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32375 AND `DifficultyID`=0); -- 32375 (Warmage Yurias) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32373 AND `DifficultyID`=0); -- 32373 (Gatekeeper Melindra) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32369 AND `DifficultyID`=0); -- 32369 (Warmage Sarina) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32374 AND `DifficultyID`=0); -- 32374 (Librarian Belleford) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32372 AND `DifficultyID`=0); -- 32372 (Warmage Ilsudria) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32371 AND `DifficultyID`=0); -- 32371 (Warmage Halister) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32717 AND `DifficultyID`=0); -- 32717 (Drool) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456 WHERE (`Entry`=32441 AND `DifficultyID`=0);
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=106887 AND `DifficultyID`=0); -- 106887 (Cravitz Lorent) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32700 AND `DifficultyID`=0); -- 32700 (Halga Steelbarrow) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0 WHERE (`Entry`=34244 AND `DifficultyID`=0);
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32602 AND `DifficultyID`=0); -- 32602 (Dalaran Visitor) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=24, `LevelScalingDeltaMax`=24, `ContentTuningID`=371, `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=66618 AND `DifficultyID`=0); -- 66618 (Stitch) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=24, `LevelScalingDeltaMax`=24, `ContentTuningID`=371, `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=66616 AND `DifficultyID`=0); -- 66616 (Mort) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=31231 AND `DifficultyID`=0); -- 31231 (Lost Shandaral Spirit) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=24, `LevelScalingDeltaMax`=24, `ContentTuningID`=371, `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=66619 AND `DifficultyID`=0); -- 66619 (Spooky Strangler) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=163, `VerifiedBuild`=52649 WHERE (`Entry`=66636 AND `DifficultyID`=0); -- 66636 (Nearly Headless Jacob) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=881, `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=30271 AND `DifficultyID`=0); -- 30271 (Galendror Whitewing) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=163, `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=30241 AND `DifficultyID`=0); -- 30241 (Lanudal Silverhart) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=163, `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=30257 AND `DifficultyID`=0); -- 30257 (Scout Yribria) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=163, `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=30261 AND `DifficultyID`=0); -- 30261 (Scout Captain Daelin) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=163, `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=30255 AND `DifficultyID`=0); -- 30255 (Aniduria) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=163, `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=30244 AND `DifficultyID`=0); -- 30244 (Miura Brightweaver) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=163, `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=30263 AND `DifficultyID`=0); -- 30263 (Silver Covenant Horseman) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=163, `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=30238 AND `DifficultyID`=0); -- 30238 (Silver Covenant Scout) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=30865 AND `DifficultyID`=0); -- 30865 (Shandaral Warrior Spirit) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=31123 AND `DifficultyID`=0); -- 31123 (Shandaral Spirit Wolf) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=30864 AND `DifficultyID`=0); -- 30864 (Shandaral Hunter Spirit) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=30868 AND `DifficultyID`=0); -- 30868 (Unbound Corrupter) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=163, `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=30254 AND `DifficultyID`=0); -- 30254 (Marisalira) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=881, `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=30269 AND `DifficultyID`=0); -- 30269 (Skymaster Baeric) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=163, `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=30239 AND `DifficultyID`=0); -- 30239 (Alanura Firecloud) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=163, `DamageModifier`=4.6, `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=30259 AND `DifficultyID`=0); -- 30259 (Scout Captain Elsia) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=163, `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=30256 AND `DifficultyID`=0); -- 30256 (Scout Ordimbral) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=163, `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=30253 AND `DifficultyID`=0); -- 30253 (Felindel Sunhammer) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=30856 AND `DifficultyID`=0); -- 30856 (Unbound Trickster) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=163, `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=30265 AND `DifficultyID`=0); -- 30265 (Sunreaver Hawkrider) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=30863 AND `DifficultyID`=0); -- 30863 (Shandaral Druid Spirit) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=163, `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=30233 AND `DifficultyID`=0); -- 30233 (Sunreaver Scout) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=30862 AND `DifficultyID`=0); -- 30862 (Unbound Ent) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=30860 AND `DifficultyID`=0); -- 30860 (Unbound Dryad) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=31041 AND `DifficultyID`=0); -- 31041 (Dispirited Ent) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=30861 AND `DifficultyID`=0); -- 30861 (Unbound Ancient) - CanSwim

DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=1 AND `Entry` IN (33499,33498,30271,30269,30265,30263,30261,30259,30257,30256,30255,30254,30253,30244,30241,30239,30238,30233,66636,66619,66618,66616,106887,61143,35984,32717,32700,32602,32375,32374,32373,32372,32371,32369,32325,32324,32321,31404,31403,31401,31393,31231,31139,31123,31041,30868,30865,30864,30863,30862,30861,30860,30856,30281,27306,15214));

DELETE FROM `creature_questitem` WHERE `CreatureEntry`=33499 AND `DifficultyID`=1;

-- Models
UPDATE `creature_model_info` SET `VerifiedBuild`=52649 WHERE `DisplayID` IN (28643, 11078, 24176, 24910, 27586, 27519, 25250, 27947, 27948, 27946, 27945, 27807, 28193, 30311, 69759, 23515, 23521, 1037, 193, 27720, 27882, 27923, 23517, 27929, 27919, 2541, 1004, 28200, 45628, 45629, 27518, 45630, 45260, 26911, 22474, 26891, 26900, 26908, 26898, 26896, 26888, 26886, 26887, 26885, 27368, 27366, 27364, 27367, 27482, 27365, 9590, 26879, 26897, 26910, 29695, 26892, 26907, 26899, 26889, 27358, 26878, 26877, 27360, 26880, 10621, 27572, 27451, 27478);

-- Gameobject templates
UPDATE `gameobject_template` SET `VerifiedBuild`=52649 WHERE `entry` IN (194394, 194393, 209869, 192911, 192912, 209868, 207493, 192909, 192908, 192910, 192062, 192891, 189980, 192061, 194540, 192709, 194213, 192894, 192063);

UPDATE `gameobject_questitem` SET `VerifiedBuild`=52649 WHERE (`Idx`=0 AND `GameObjectEntry` IN (194213,192911,192909,192910,192912,192908));
