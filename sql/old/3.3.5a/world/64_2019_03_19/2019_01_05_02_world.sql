-- Valithria Dreamwalker fixes
DELETE FROM `creature` WHERE `id`=37868;
DELETE FROM `creature_summon_groups` WHERE `summonerId`=38752;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`) VALUES
-- Group All Difficulty
(38752,0,1,37868,4222.86,2504.58,364.96,3.90954,8,0), -- Risen Archmage
(38752,0,1,37868,4223.4 ,2465.11,364.952,2.3911,8,0), -- Risen Archmage
-- Group 10 Man
(38752,0,2,37868,4230.44,2478.56,364.953,2.93215,8,0), -- Risen Archmage
(38752,0,2,37868,4230.53,2490.22,364.957,3.36849,8,0), -- Risen Archmage
-- Group 25 man
(38752,0,3,37868,4185.29,2464.01,364.87,0.798137,8,0), -- Risen Archmage
(38752,0,3,37868,4183.7 ,2503.93,364.879,5.50843,8,0); -- Risen Archmage

UPDATE `creature` SET `phaseMask`=20 WHERE `id` IN(38421,37950);
UPDATE `creature_template` SET `flags_extra`=2 WHERE `entry`=37950;
UPDATE `conditions` SET `ConditionValue2`=37950 WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN(72031,72032,72033,71946);
