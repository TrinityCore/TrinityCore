SET @CGUID := 1251452;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+31;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 197944, 2444, 13646, 13646, '0', 0, 0, 0, 0, -5164.095703125, -3359.173583984375, 8.221406936645507812, 1.282459616661071777, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Crusty Seawing (Area: The Azure Span - Difficulty: 0)
(@CGUID+1, 197954, 2444, 13646, 13646, '0', 0, 0, 0, 0, -5138.86962890625, -3314.83154296875, -2.20530605316162109, 0.118801482021808624, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 47213), -- Scavenging Snipshell (Area: The Azure Span - Difficulty: 0)
(@CGUID+2, 197944, 2444, 13646, 13646, '0', 0, 0, 0, 0, -5082.0966796875, -3258.248046875, 12.79143142700195312, 2.994697093963623046, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Crusty Seawing (Area: The Azure Span - Difficulty: 0) (Auras: 391254 - Hearty)
(@CGUID+3, 197954, 2444, 13646, 13646, '0', 0, 0, 0, 0, -5108.91845703125, -3302.9306640625, -2.32772779464721679, 4.071191310882568359, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 47213), -- Scavenging Snipshell (Area: The Azure Span - Difficulty: 0) (Auras: 391254 - Hearty)
(@CGUID+4, 197944, 2444, 13646, 13646, '0', 0, 0, 0, 0, -5077.392578125, -3341.333251953125, 21.85686111450195312, 0.622016429901123046, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Crusty Seawing (Area: The Azure Span - Difficulty: 0)
(@CGUID+5, 197954, 2444, 13646, 13646, '0', 0, 0, 0, 0, -5109.46533203125, -3398.52783203125, 16.50407981872558593, 1.039258122444152832, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 47213), -- Scavenging Snipshell (Area: The Azure Span - Difficulty: 0) (Auras: 261553 - Bubblin')
(@CGUID+6, 197954, 2444, 13646, 13646, '0', 0, 0, 0, 0, -5161.26025390625, -3341.020751953125, 0.638962507247924804, 3.879286050796508789, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 47213), -- Scavenging Snipshell (Area: The Azure Span - Difficulty: 0)
(@CGUID+7, 197954, 2444, 13646, 13646, '0', 0, 0, 0, 0, -5094.671875, -3304.861083984375, -1.85252857208251953, 5.084334850311279296, 120, 4, 0, 112919, 0, 1, 0, 0, 0, 47213), -- Scavenging Snipshell (Area: The Azure Span - Difficulty: 0)
(@CGUID+8, 197944, 2444, 13646, 13646, '0', 0, 0, 0, 0, -5098.15185546875, -3314.365478515625, 2.211060285568237304, 5.181472301483154296, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Crusty Seawing (Area: The Azure Span - Difficulty: 0)
(@CGUID+9, 197944, 2444, 13646, 13646, '0', 0, 0, 0, 0, -5178.02783203125, -3341.954833984375, 10.11279487609863281, 3.492719650268554687, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Crusty Seawing (Area: The Azure Span - Difficulty: 0)
(@CGUID+10, 197954, 2444, 13646, 13646, '0', 0, 0, 0, 0, -5135.4482421875, -3329.9345703125, 2.634099006652832031, 0.286983370780944824, 120, 4, 0, 112919, 0, 1, 0, 0, 0, 47213), -- Scavenging Snipshell (Area: The Azure Span - Difficulty: 0)
(@CGUID+11, 197954, 2444, 13646, 13646, '0', 0, 0, 0, 0, -5048.2158203125, -3330.181884765625, -7.76671743392944335, 1.387470006942749023, 120, 4, 0, 112919, 0, 1, 0, 0, 0, 47213), -- Scavenging Snipshell (Area: The Azure Span - Difficulty: 0)
(@CGUID+12, 197954, 2444, 13646, 13646, '0', 0, 0, 0, 0, -5092.57470703125, -3318.84375, 0.422902554273605346, 0.569369435310363769, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 47213), -- Scavenging Snipshell (Area: The Azure Span - Difficulty: 0)
(@CGUID+13, 197954, 2444, 13646, 13646, '0', 0, 0, 0, 0, -5147.916015625, -3335.416015625, 2.145891904830932617, 4.095516204833984375, 120, 4, 0, 112919, 0, 1, 0, 0, 0, 47213), -- Scavenging Snipshell (Area: The Azure Span - Difficulty: 0)
(@CGUID+14, 197944, 2444, 13646, 13646, '0', 0, 0, 0, 0, -5091.08349609375, -3311.973876953125, 2.253691434860229492, 4.047852516174316406, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Crusty Seawing (Area: The Azure Span - Difficulty: 0)
(@CGUID+15, 197954, 2444, 13646, 13646, '0', 0, 0, 0, 0, -5105.2744140625, -3372.826416015625, 20.25764656066894531, 5.623720645904541015, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 47213), -- Scavenging Snipshell (Area: The Azure Span - Difficulty: 0) (Auras: 261553 - Bubblin')
(@CGUID+16, 197954, 2444, 13646, 13646, '0', 0, 0, 0, 0, -5107.59716796875, -3316.73681640625, 1.304745674133300781, 5.626110553741455078, 120, 4, 0, 112919, 0, 1, 0, 0, 0, 47213), -- Scavenging Snipshell (Area: The Azure Span - Difficulty: 0)
(@CGUID+17, 197944, 2444, 13646, 13646, '0', 0, 0, 0, 0, -5084.0810546875, -3318.868408203125, 11.92208194732666015, 3.901463508605957031, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Crusty Seawing (Area: The Azure Span - Difficulty: 0) (Auras: 391254 - Hearty)
(@CGUID+18, 197954, 2444, 13646, 13646, '0', 0, 0, 0, 0, -5125.84619140625, -3303.9296875, -3.34588909149169921, 0.869801878929138183, 120, 4, 0, 112919, 0, 1, 0, 0, 0, 47213), -- Scavenging Snipshell (Area: The Azure Span - Difficulty: 0)
(@CGUID+19, 197954, 2444, 13646, 13646, '0', 0, 0, 0, 0, -5077.451171875, -3311.33154296875, -3.82256388664245605, 5.171669960021972656, 120, 4, 0, 112919, 0, 1, 0, 0, 0, 47213), -- Scavenging Snipshell (Area: The Azure Span - Difficulty: 0)
(@CGUID+20, 197944, 2444, 13646, 13646, '0', 0, 0, 0, 0, -5152.455078125, -3315.5556640625, 7.666415691375732421, 1.505070090293884277, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Crusty Seawing (Area: The Azure Span - Difficulty: 0)
(@CGUID+21, 197944, 2444, 13646, 13646, '0', 0, 0, 0, 0, -5111.59716796875, -3359.505126953125, 21.76113128662109375, 1.553127884864807128, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Crusty Seawing (Area: The Azure Span - Difficulty: 0)
(@CGUID+22, 197954, 2444, 13646, 13646, '0', 0, 0, 0, 0, -5095.705078125, -3388.66845703125, 18.3708953857421875, 2.835742473602294921, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 47213), -- Scavenging Snipshell (Area: The Azure Span - Difficulty: 0) (Auras: 261553 - Bubblin')
(@CGUID+23, 197954, 2444, 13646, 13646, '0', 0, 0, 0, 0, -5120.44482421875, -3290.7412109375, -7.72952699661254882, 6.106476783752441406, 120, 4, 0, 112919, 0, 1, 0, 0, 0, 47213), -- Scavenging Snipshell (Area: The Azure Span - Difficulty: 0)
(@CGUID+24, 197979, 2444, 13646, 13646, '0', 19766, 0, 0, 1, -5086.91162109375, -3338.303955078125, 18.9729461669921875, 1.596655607223510742, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Captain Haab (Area: The Azure Span - Difficulty: 0)
(@CGUID+25, 197954, 2444, 13646, 13646, '0', 0, 0, 0, 0, -5074.03662109375, -3284.882080078125, -10.2686967849731445, 3.409809827804565429, 120, 4, 0, 112919, 0, 1, 0, 0, 0, 47213), -- Scavenging Snipshell (Area: The Azure Span - Difficulty: 0)
(@CGUID+26, 197944, 2444, 13646, 13646, '0', 0, 0, 0, 0, -5160.69287109375, -3320.515625, 7.195713043212890625, 2.313679218292236328, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Crusty Seawing (Area: The Azure Span - Difficulty: 0)
(@CGUID+27, 197944, 2444, 13646, 13646, '0', 0, 0, 0, 0, -5109.64599609375, -3308.755126953125, 1.870712757110595703, 5.878404140472412109, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Crusty Seawing (Area: The Azure Span - Difficulty: 0)
(@CGUID+28, 197954, 2444, 13646, 13646, '0', 0, 0, 0, 0, -5101.63427734375, -3391.709716796875, 16.89973068237304687, 1.430888652801513671, 120, 4, 0, 112919, 0, 1, 0, 0, 0, 47213), -- Scavenging Snipshell (Area: The Azure Span - Difficulty: 0)
(@CGUID+29, 197944, 2444, 13646, 13646, '0', 0, 0, 0, 0, -5058.171875, -3275.463623046875, 11.7849283218383789, 2.083724260330200195, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Crusty Seawing (Area: The Azure Span - Difficulty: 0)
(@CGUID+30, 197954, 2444, 13646, 13646, '0', 0, 0, 0, 0, -5098.837890625, -3286.4365234375, -7.97304248809814453, 1.803453326225280761, 120, 4, 0, 112919, 0, 1, 0, 0, 0, 47213), -- Scavenging Snipshell (Area: The Azure Span - Difficulty: 0)
(@CGUID+31, 198026, 2444, 13646, 13646, '0', 19762, 0, 0, 0, -5117.67724609375, -3255.354248046875, 0.090303517878055572, 0.298924922943115234, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 47213); -- Bait Fish (Area: The Azure Span - Difficulty: 0) (Auras: 392478 - Setting Bait Catch-Up [DNT])
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+31;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 3, 1, 0, 0, 0, 0, 0, ''), -- Crusty Seawing
(@CGUID+2, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, '391254'), -- Crusty Seawing - 391254 - Hearty
(@CGUID+3, 0, 0, 0, 1, 0, 0, 0, 0, 0, '391254'), -- Scavenging Snipshell - 391254 - Hearty
(@CGUID+4, 0, 0, 3, 1, 0, 0, 0, 0, 0, ''), -- Crusty Seawing
(@CGUID+5, 0, 0, 0, 1, 0, 0, 0, 0, 0, '261553'), -- Scavenging Snipshell - 261553 - Bubblin'
(@CGUID+8, 0, 0, 0, 1, 428, 0, 0, 0, 0, ''), -- Crusty Seawing
(@CGUID+9, 0, 0, 3, 1, 0, 0, 0, 0, 0, ''), -- Crusty Seawing
(@CGUID+14, 0, 0, 0, 1, 428, 0, 0, 0, 0, ''), -- Crusty Seawing
(@CGUID+15, 0, 0, 0, 1, 0, 0, 0, 0, 0, '261553'), -- Scavenging Snipshell - 261553 - Bubblin'
(@CGUID+17, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, '391254'), -- Crusty Seawing - 391254 - Hearty
(@CGUID+20, 0, 0, 3, 1, 0, 0, 0, 0, 0, ''), -- Crusty Seawing
(@CGUID+21, 0, 0, 3, 1, 0, 0, 0, 0, 0, ''), -- Crusty Seawing
(@CGUID+22, 0, 0, 0, 1, 0, 0, 0, 0, 0, '261553'), -- Scavenging Snipshell - 261553 - Bubblin'
(@CGUID+26, 0, 0, 3, 1, 0, 0, 0, 0, 0, ''), -- Crusty Seawing
(@CGUID+27, 0, 0, 3, 1, 0, 0, 0, 0, 0, ''), -- Crusty Seawing
(@CGUID+29, 0, 0, 3, 1, 0, 0, 0, 0, 0, ''); -- Crusty Seawing

-- Creature Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (197979, 198026, 198025);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(197979, 0, 0, 0, 0, 0, 17858, 0, 0, 0, ''), -- 197979 (Captain Haab)
(198026, 0, 0, 0, 1, 0, 0, 0, 0, 0, '392478'), -- 198026 (Bait Fish) - Setting Bait Catch-Up [DNT]
(198025, 0, 0, 0, 1, 0, 0, 0, 0, 0, '290717'); -- 198025 (Haab's Crew) - Ghost Visual Spawn Spell

-- Creature Template
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=14, `BaseAttackTime`=2000, `unit_flags`=67141632, `unit_flags2`=2048, `HoverHeight`=2 WHERE `entry`=198023; -- Mochoby
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=190, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=67110912, `unit_flags3`=16777216 WHERE `entry`=198026; -- Bait Fish
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=67, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=198025; -- Haab's Crew
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=35, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=34816 WHERE `entry`=197979; -- Captain Haab
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=16779264 WHERE `entry`=197954; -- Scavenging Snipshell
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=2136, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=197944; -- Crusty Seawing

-- Creature Equip
DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (198025,197979));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(198025, 1, 161445, 0, 0, 0, 0, 0, 0, 0, 0, 47213), -- Haab's Crew
(197979, 1, 161445, 0, 0, 0, 0, 0, 0, 0, 0, 47213); -- Captain Haab

-- Creature movement override
DELETE FROM `creature_movement_override` WHERE `SpawnId` IN (@CGUID+2, @CGUID+17);
INSERT INTO `creature_movement_override` (`SpawnId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(@CGUID+2, 0, 0, 1, 0, 0, 0, NULL),
(@CGUID+17, 0, 0, 1, 0, 0, 0, NULL);

-- Phasing
DELETE FROM `phase_name` WHERE `ID` IN (19766, 19762);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(19766, 'Cosmetic - See Captain Haab'),
(19762, 'Cosmetic - See Bait Fish');

DELETE FROM `phase_area` WHERE `AreaId` = 13646 AND `PhaseId` IN (19766, 19762);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(13646, 19766, 'Cosmetic - See Captain Haab'),
(13646, 19762, 'Cosmetic - See Bait Fish');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (19766, 19762) AND `SourceEntry` = 13646;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 19766, 13646, 0, 0, 47, 0, 72071, 8, 0, 1, 'Apply Phase 19766 if Quest 72071 is not in progress'),
(26, 19762, 13646, 0, 0, 47, 0, 72071, 8 | 2, 0, 0, 'Apply Phase 19762 if Quest 72071 is in progress | completed');

-- Update some SAI
UPDATE `smart_scripts` SET `event_phase_mask` = 0, `event_flags` = 1 WHERE `entryorguid` IN (196974, 196977, 196978, 196979, 196981) AND `id`= 0;
UPDATE `smart_scripts` SET `event_flags` = 0 WHERE `entryorguid` IN (196974, 196977, 196978, 196979, 196981) AND `id`IN (1, 2);

-- Quest stuff
DELETE FROM `quest_offer_reward` WHERE `ID` IN (72083, 72071);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(72083, 4, 0, 0, 0, 0, 0, 0, 0, 'No fish can resist me lucky lure, living or dead!', 47213), -- Me Lucky Lure
(72071, 0, 0, 0, 0, 0, 0, 0, 0, 'Now who\'s up one?', 47213); -- Round Two; Fish!

DELETE FROM `quest_poi` WHERE (`QuestID`=72071 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=72071 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=72071 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=72071 AND `BlobIndex`=0 AND `Idx1`=0);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `NavigationPlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(72071, 0, 3, 32, 0, 0, 2444, 2024, 0, 0, 0, 0, 0, 2282246, 0, 47213), -- Round Two, Fish!
(72071, 0, 2, 1, 431710, 198023, 2444, 2024, 0, 0, 0, 0, 0, 2282328, 0, 47213), -- Round Two, Fish!
(72071, 0, 1, 0, 431709, 198021, 2444, 2024, 0, 0, 0, 0, 0, 2282321, 0, 47213), -- Round Two, Fish!
(72071, 0, 0, -1, 0, 0, 2444, 2024, 0, 0, 0, 0, 0, 2282246, 0, 47213); -- Round Two; Fish!

UPDATE `quest_poi` SET `VerifiedBuild`=47213 WHERE (`QuestID`=72083 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=72083 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=72083 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=67700 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=67700 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=67700 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=67700 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=67298 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=67298 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=67298 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=67298 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=65064 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=65064 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=65064 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=65064 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=65064 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=64527 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=64106 AND `BlobIndex`=0 AND `Idx1`=5) OR (`QuestID`=64106 AND `BlobIndex`=3 AND `Idx1`=4) OR (`QuestID`=64106 AND `BlobIndex`=2 AND `Idx1`=3) OR (`QuestID`=64106 AND `BlobIndex`=1 AND `Idx1`=2) OR (`QuestID`=64106 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=64106 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=63949 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=63949 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=62719 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=62719 AND `BlobIndex`=2 AND `Idx1`=1) OR (`QuestID`=62719 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=62431 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=62431 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=56119 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=56119 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50601 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50599 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48641 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=42170 AND `BlobIndex`=0 AND `Idx1`=0);
DELETE FROM `quest_poi_points` WHERE (`QuestID`=72071 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=72071 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=72071 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=72071 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `Z`, `VerifiedBuild`) VALUES
(72071, 3, 0, -5087, -3338, 18, 47213), -- Round Two, Fish!
(72071, 2, 0, -5142, -3243, -14, 47213), -- Round Two, Fish!
(72071, 1, 0, -5117, -3255, 0, 47213), -- Round Two, Fish!
(72071, 0, 0, -5087, -3338, 18, 47213); -- Round Two; Fish!

UPDATE `quest_poi_points` SET `VerifiedBuild`=47213 WHERE (`QuestID`=72083 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=72083 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=72083 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=72083 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=72083 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=72083 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=72083 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=72083 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=72083 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=72083 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=72083 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=67700 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=67700 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=67700 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=67700 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=67298 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=67298 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=67298 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=67298 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=65064 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=65064 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=65064 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=65064 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=65064 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=65064 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=65064 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=65064 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=65064 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=65064 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=65064 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=65064 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=65064 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=65064 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=65064 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=65064 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=64527 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=64106 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=64106 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=64106 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=64106 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=64106 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=64106 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=63949 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=63949 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=62719 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=62719 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=62719 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=62431 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=62431 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=56119 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=56119 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50601 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50599 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48641 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=42170 AND `Idx1`=0 AND `Idx2`=0);

DELETE FROM `quest_details` WHERE `ID` IN (72071 /*Round Two, Fish!*/, 72083 /*Me Lucky Lure*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(72071, 1, 0, 0, 0, 0, 0, 0, 0, 47213), -- Round Two, Fish!
(72083, 1, 0, 0, 0, 0, 0, 0, 0, 47213); -- Me Lucky Lure

DELETE FROM `quest_request_items` WHERE `ID` IN (72071 /*Round Two, Fish!*/, 72083 /*Me Lucky Lure*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(72071, 0, 0, 0, 0, 'It\'s out there. I can feel it.', 47213), -- Round Two, Fish!
(72083, 1, 1, 0, 0, 'No, I don\'t know which one ate it. I was busy being dead at the time.', 47213); -- Me Lucky Lure

DELETE FROM `creature_queststarter` WHERE (`id`=197979 AND `quest` IN (72071,72083));
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(197979, 72071, 47213), -- Round Two, Fish! offered Captain Haab
(197979, 72083, 47213); -- Me Lucky Lure offered Captain Haab

DELETE FROM `creature_questender` WHERE (`id`=198025 AND `quest`=72071) OR (`id`=197979 AND `quest`=72083);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(198025, 72071, 47213), -- Round Two, Fish! ended by Haab's Crew
(197979, 72083, 47213); -- Me Lucky Lure ended by Captain Haab

DELETE FROM `quest_template_addon` WHERE `ID` = 72071;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(72071, 0, 0, 0, 72083, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

-- Scaling & Model
DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (198026,198025,197979,197944,197954));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(198026, 0, 0, 0, 2078, 47213),
(198025, 0, 0, 0, 2468, 47213),
(197979, 0, 0, 0, 2468, 47213),
(197944, 0, 0, 0, 2468, 47213),
(197954, 0, 0, 0, 2078, 47213);

UPDATE `creature_template_scaling` SET `VerifiedBuild`=47213 WHERE (`DifficultyID`=0 AND `Entry` IN (32639,32638,6491,198489));

DELETE FROM `creature_model_info` WHERE `DisplayID`=109787;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(109787, 0.690244972705841064, 1.5, 0, 47213);
