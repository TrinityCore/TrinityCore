-- Creature templates
UPDATE `creature_template` SET `unit_flags3`=524288 WHERE `entry`=38456; -- Frozen Orb
UPDATE `creature_template` SET `unit_flags3`=524288 WHERE `entry`=38461; -- Toravon Frozen Orb Stalker
UPDATE `creature_template` SET `unit_flags3`=524288 WHERE `entry`=34049; -- Tempest Minion
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=38433; -- Toravon the Ice Watcher
UPDATE `creature_template` SET `speed_run`=1.142857193946838378, `unit_flags3`=16777217 WHERE `entry`=34230; -- Emalon Controller
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857193946838378 WHERE `entry`=35013; -- Koralon the Flame Watcher
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=32353; -- Archavon Warder
UPDATE `creature_template` SET `unit_flags3`=16777217 WHERE `entry`=36093; -- Vault Stalker
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857193946838378 WHERE `entry`=33993; -- Emalon the Storm Watcher

-- Difficulties
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=14 AND `Entry` IN (32780));

UPDATE `creature_template_difficulty` SET `ContentTuningID`=1016, `StaticFlags1`=536871168, `VerifiedBuild`=54762 WHERE (`Entry`=38461 AND `DifficultyID`=0); -- 38461 (Toravon Frozen Orb Stalker) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=3, `LevelScalingDeltaMax`=3, `ContentTuningID`=1016, `VerifiedBuild`=54762 WHERE (`Entry`=38456 AND `DifficultyID`=0); -- 38456 (Frozen Orb) - 
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=1016, `StaticFlags1`=`StaticFlags1`|268435456, `VerifiedBuild`=54762 WHERE (`Entry`=34049 AND `DifficultyID`=0); -- 34049 (Tempest Minion) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=3, `LevelScalingDeltaMax`=3, `ContentTuningID`=1016, `VerifiedBuild`=54762 WHERE (`Entry`=31125 AND `DifficultyID`=0); -- 31125 (Archavon the Stone Watcher) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1016, `StaticFlags1`=536871168, `VerifiedBuild`=54762 WHERE (`Entry`=38439 AND `DifficultyID`=0); -- 38439 (Toravon Stalker) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=3, `LevelScalingDeltaMax`=3, `ContentTuningID`=1016, `VerifiedBuild`=54762 WHERE (`Entry`=38433 AND `DifficultyID`=0); -- 38433 (Toravon the Ice Watcher) - 
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=1016, `StaticFlags1`=`StaticFlags1`|268435456, `VerifiedBuild`=54762 WHERE (`Entry`=38482 AND `DifficultyID`=0); -- 38482 (Frost Warder) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1016, `StaticFlags1`=536871168, `VerifiedBuild`=54762 WHERE (`Entry`=34230 AND `DifficultyID`=0); -- 34230 (Emalon Controller) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1016, `StaticFlags1`=536870912, `VerifiedBuild`=54762 WHERE (`Entry`=35015 AND `DifficultyID`=0); -- 35015 (Burning Breath Koralon Stalker) - Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=3, `LevelScalingDeltaMax`=3, `ContentTuningID`=1016, `VerifiedBuild`=54762 WHERE (`Entry`=35013 AND `DifficultyID`=0); -- 35013 (Koralon the Flame Watcher) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1016, `VerifiedBuild`=54762 WHERE (`Entry`=32353 AND `DifficultyID`=0); -- 32353 (Archavon Warder) - 
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0, `VerifiedBuild`=54762 WHERE (`Entry`=32780 AND `DifficultyID`=0); -- 32780 (Invisible Stalker (All Phases)) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1016, `StaticFlags1`=536871168, `VerifiedBuild`=54762 WHERE (`Entry`=36093 AND `DifficultyID`=0); -- 36093 (Vault Stalker) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=1016, `StaticFlags1`=`StaticFlags1`|268435456, `VerifiedBuild`=54762 WHERE (`Entry`=35143 AND `DifficultyID`=0); -- 35143 (Flame Warder) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=3, `LevelScalingDeltaMax`=3, `ContentTuningID`=1016, `VerifiedBuild`=54762 WHERE (`Entry`=33993 AND `DifficultyID`=0); -- 33993 (Emalon the Storm Watcher) - 
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=1016, `StaticFlags1`=`StaticFlags1`|268435456, `VerifiedBuild`=54762 WHERE (`Entry`=33998 AND `DifficultyID`=0); -- 33998 (Tempest Minion) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=1016, `StaticFlags1`=`StaticFlags1`|268435456, `VerifiedBuild`=54762 WHERE (`Entry`=34015 AND `DifficultyID`=0); -- 34015 (Tempest Warder) - CanSwim
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=40206 WHERE (`Entry`=33998 AND `DifficultyID`=4); -- Tempest Minion
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=37041 WHERE (`Entry`=32353 AND `DifficultyID`=4); -- Archavon Warder
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=48286, `TypeFlags2`=128 WHERE (`Entry`=38433 AND `DifficultyID`=4); -- Toravon the Ice Watcher
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=35642, `TypeFlags2`=128 WHERE (`Entry`=31125 AND `DifficultyID`=4); -- Archavon the Stone Watcher
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=40316 WHERE (`Entry`=34049 AND `DifficultyID`=4); -- Tempest Minion
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=40197, `TypeFlags2`=128 WHERE (`Entry`=33993 AND `DifficultyID`=4); -- Emalon the Storm Watcher
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=48372 WHERE (`Entry`=38482 AND `DifficultyID`=4); -- Frost Warder
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=40244 WHERE (`Entry`=34015 AND `DifficultyID`=4); -- Tempest Warder
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=48331 WHERE (`Entry`=38456 AND `DifficultyID`=4); -- Frozen Orb
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=42555, `TypeFlags2`=128 WHERE (`Entry`=35013 AND `DifficultyID`=4); -- Koralon the Flame Watcher
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=42898 WHERE (`Entry`=35143 AND `DifficultyID`=4); -- Flame Warder
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=3, `LevelScalingDeltaMax`=3, `ContentTuningID`=1016, `VerifiedBuild`=54762 WHERE (`Entry`=38456 AND `DifficultyID`=4); -- 38456 (Frozen Orb) - 
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=1016, `StaticFlags1`=`StaticFlags1`|268435456, `VerifiedBuild`=54762 WHERE (`Entry`=34049 AND `DifficultyID`=4); -- 34049 (Tempest Minion) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=3, `LevelScalingDeltaMax`=3, `ContentTuningID`=1016, `StaticFlags2`=0, `VerifiedBuild`=54762 WHERE (`Entry`=31125 AND `DifficultyID`=4); -- 31125 (Archavon the Stone Watcher) - 
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=3, `LevelScalingDeltaMax`=3, `ContentTuningID`=1016, `StaticFlags2`=0, `VerifiedBuild`=54762 WHERE (`Entry`=38433 AND `DifficultyID`=4); -- 38433 (Toravon the Ice Watcher) - 
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=1016, `StaticFlags1`=`StaticFlags1`|268435456, `VerifiedBuild`=54762 WHERE (`Entry`=38482 AND `DifficultyID`=4); -- 38482 (Frost Warder) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=3, `LevelScalingDeltaMax`=3, `ContentTuningID`=1016, `StaticFlags2`=0, `VerifiedBuild`=54762 WHERE (`Entry`=35013 AND `DifficultyID`=4); -- 35013 (Koralon the Flame Watcher) - 
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=3, `LevelScalingDeltaMax`=3, `ContentTuningID`=1016, `StaticFlags2`=0, `VerifiedBuild`=54762 WHERE (`Entry`=33993 AND `DifficultyID`=4); -- 33993 (Emalon the Storm Watcher) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1016, `VerifiedBuild`=54762 WHERE (`Entry`=32353 AND `DifficultyID`=4); -- 32353 (Archavon Warder) - 
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=1016, `StaticFlags1`=`StaticFlags1`|268435456, `VerifiedBuild`=54762 WHERE (`Entry`=34015 AND `DifficultyID`=4); -- 34015 (Tempest Warder) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=1016, `StaticFlags1`=`StaticFlags1`|268435456, `VerifiedBuild`=54762 WHERE (`Entry`=35143 AND `DifficultyID`=4); -- 35143 (Flame Warder) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=1016, `StaticFlags1`=`StaticFlags1`|268435456, `VerifiedBuild`=54762 WHERE (`Entry`=33998 AND `DifficultyID`=4); -- 33998 (Tempest Minion) - CanSwim

-- Models
UPDATE `creature_model_info` SET `BoundingRadius`=0.400000005960464477, `CombatReach`=0.400000005960464477, `VerifiedBuild`=54762 WHERE `DisplayID`=31096;
UPDATE `creature_model_info` SET `VerifiedBuild`=54762 WHERE `DisplayID` IN (26967, 26693, 11686, 16925);
UPDATE `creature_model_info` SET `BoundingRadius`=7.209354400634765625, `VerifiedBuild`=54762 WHERE `DisplayID`=31089;
UPDATE `creature_model_info` SET `BoundingRadius`=7.463489532470703125, `VerifiedBuild`=54762 WHERE `DisplayID`=29524;
UPDATE `creature_model_info` SET `BoundingRadius`=6.22840118408203125, `VerifiedBuild`=54762 WHERE `DisplayID`=27108;
UPDATE `creature_model_info` SET `BoundingRadius`=4.00119638442993164, `VerifiedBuild`=54762 WHERE `DisplayID`=26384;
UPDATE `creature_template_model` SET `VerifiedBuild`=54762 WHERE (`Idx`=1 AND `CreatureID` IN (38461,34230,32780,38439,35015,36093)) OR (`Idx`=0 AND `CreatureID` IN (38461,34230,34049,38433,32780,38456,38439,32353,35015,33998,34015,38482,36093,35143));
