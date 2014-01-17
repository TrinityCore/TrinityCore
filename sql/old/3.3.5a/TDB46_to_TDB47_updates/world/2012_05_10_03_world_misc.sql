 -- Remove obsolete requirement 'cooking profession' from quest 'Beer Basted Boar Ribs' (thx tifkat) closes #5198
UPDATE `quest_template` SET `RequiredSkillId`=0, `RequiredSkillPoints`=0 WHERE `Id`=384;

-- Fix proc for Death's Verdict/Choice (author: kandera) closes #6041
UPDATE `spell_proc_event` SET `procFlags` = 0, `procEx` = `procEx`|262144 WHERE `entry` in (67702, 67771);

-- Disables quest "Desperate Research" for all factions author trista closes #5285
DELETE FROM `disables` WHERE `sourceType` = 1 AND `entry` in (12782,12783,12811,12784,12752,12775,12777,12753,12808,12772);
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,12782,0,0,0,'Disable quest from Scourge Invasion for Blood Elves'),
(1,12783,0,0,0,'Disable quest from Scourge Invasion for Orcs'),
(1,12811,0,0,0,'Disable quest from Scourge Invasion for Trolls'),
(1,12784,0,0,0,'Disable quest from Scourge Invasion for Tauren'),
(1,12752,0,0,0,'Disable quest from Scourge Invasion for undead'),
(1,12775,0,0,0,'Disable quest from Scourge Invasion for Human'),
(1,12777,0,0,0,'Disable quest from Scourge Invasion for Draenei'),
(1,12753,0,0,0,'Disable quest from Scourge Invasion for Dwarves'),
(1,12808,0,0,0,'Disable quest from Scourge Invasion for Gnomes'),
(1,12772,0,0,0,'Disable quest from Scourge Invasion for Night Elves');
-- Disables scourge invasion connected quests listed below
DELETE FROM `disables` WHERE `sourceType` = 1 AND `entry` in (12788,12812,12785,12786,12787,12774,12776,12771,12809,12773);
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,12788,0,0,0,'Disable quest from Scourge Invasion for Blood Elves'),
(1,12812,0,0,0,'Disable quest from Scourge Invasion for Orcs'),
(1,12785,0,0,0,'Disable quest from Scourge Invasion for Trolls'),
(1,12786,0,0,0,'Disable quest from Scourge Invasion for Tauren'),
(1,12787,0,0,0,'Disable quest from Scourge Invasion for undead'),
(1,12774,0,0,0,'Disable quest from Scourge Invasion for Human'),
(1,12776,0,0,0,'Disable quest from Scourge Invasion for Draenei'),
(1,12771,0,0,0,'Disable quest from Scourge Invasion for Dwarves'),
(1,12809,0,0,0,'Disable quest from Scourge Invasion for Gnomes'),
(1,12773,0,0,0,'Disable quest from Scourge Invasion for Night Elves');

-- Limit Bloodgem Shard use to Netherstorm Cristal Target author: nelegalno closes #4165
DELETE FROM `conditions` WHERE (`SourceEntry`=34367 AND `SourceTypeOrReferenceId`=17 AND `ConditionTypeOrReference`=29);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,34367,0,29,19421,15,0,64,'','Limit Bloodgem Shard use to Netherstorm Cristal Target');

-- Path of xx and A Change of Heart (Ashen Band rings) author: studioworks closes #2544
UPDATE `quest_template` SET `PrevQuestId`=0 WHERE `id` IN
(24827,24834,24835,24823,24828,24829,25239,25240,25242,24826,24832,24833,24825,24830,24831,24819,24820,24821,24822,24836,24837,24838,24839,24840,24841,24842,24843,24844,24845,24846,24847,25246,25247,25248,25249);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry` IN
-- Paths
(24827,24834,24835,24823,24828,24829,25239,25240,25242,24826,24832,24833,24825,24830,24831,
-- A Change of Heart
24819,24820,24821,24822,24836,24837,24838,24839,24840,24841,24842,24843,24844,24845,24846,24847,25246,25247,25248,25249);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`Comment`) VALUES
-- Path of Courage
(19,0,24827,0,2,50375,1,0,'Path of Courage 1'),
(19,0,24834,0,2,50388,1,0,'Path of Courage 2'),
(19,0,24835,0,2,50403,1,0,'Path of Courage 3'),
-- Path of Destruction
(19,0,24823,0,2,50384,1,0,'Path of Destruction 1'),
(19,0,24828,0,2,50377,1,0,'Path of Destruction 2'),
(19,0,24829,0,2,50397,1,0,'Path of Destruction 3'),
-- Path of Might
(19,0,25239,0,2,52569,1,0,'Path of Might 1'),
(19,0,25240,0,2,52570,1,0,'Path of Might 2'),
(19,0,25242,0,2,52571,1,0,'Path of Might 3'),
-- Path of Vengeance
(19,0,24826,0,2,50376,1,0,'Path of Vengeance 1'),
(19,0,24832,0,2,50387,1,0,'Path of Vengeance 2'),
(19,0,24833,0,2,50401,1,0,'Path of Vengeance 3'),
-- Path of Wisdom
(19,0,24825,0,2,50378,1,0,'Path of Wisdom 1'),
(19,0,24830,0,2,50386,1,0,'Path of Wisdom 2'),
(19,0,24831,0,2,50399,1,0,'Path of Wisdom 3'),
-- A Change of Heart
(19,0,24819,0,2,50377,1,0,'A Change of Heart'),
(19,0,24820,0,2,50376,1,0,'A Change of Heart'),
(19,0,24821,0,2,50375,1,0,'A Change of Heart'),
(19,0,24822,0,2,50378,1,0,'A Change of Heart'),
(19,0,24836,0,2,50384,1,0,'A Change of Heart'),
(19,0,24837,0,2,50386,1,0,'A Change of Heart'),
(19,0,24838,0,2,50387,1,0,'A Change of Heart'),
(19,0,24839,0,2,50388,1,0,'A Change of Heart'),
(19,0,24840,0,2,50397,1,0,'A Change of Heart'),
(19,0,24841,0,2,50399,1,0,'A Change of Heart'),
(19,0,24842,0,2,50401,1,0,'A Change of Heart'),
(19,0,24843,0,2,50403,1,0,'A Change of Heart'),
(19,0,24844,0,2,50398,1,0,'A Change of Heart'),
(19,0,24845,0,2,50400,1,0,'A Change of Heart'),
(19,0,24846,0,2,50402,1,0,'A Change of Heart'),
(19,0,24847,0,2,50404,1,0,'A Change of Heart'),
(19,0,25246,0,2,52572,1,0,'A Change of Heart'),
(19,0,25247,0,2,52569,1,0,'A Change of Heart'),
(19,0,25248,0,2,52570,1,0,'A Change of Heart'),
(19,0,25249,0,2,52571,1,0,'A Change of Heart');

-- spawn farmer torp author: zxbiohazardzx closes #6256
SET @guid := 42652;
DELETE FROM `creature` WHERE `guid`=@guid;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`)
VALUES
(@guid,25607,571,1,1,2886.325,6385.55,92.96985,1.4512,120); -- Farmer Torp

-- Disgusting Oozeling aura author: gecko32 closes #6197
UPDATE `creature_template_addon` SET `auras`='25163' WHERE `entry`=15429;
-- Mr. Chilly
-- Add aura chilly for Periodic slide
DELETE FROM `creature_template_addon` WHERE `entry`=29726;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(29726, 0, 0, 0, 0, 0, '61811');

-- Update to Change <name> to $n in page text author: gecko32 closes #5930
UPDATE `page_text` SET `text`='This proof of deed is to verify that $n slew Margol the Rager, scourge of the searing gorge.$B$BThe Ironforge museum recognizes this achievement and thanks the bearer for their generous contribution.$B$B-Head Curator Thorius Stonetender' WHERE `entry`=1231;

-- Update frost shock and you to only be for shamans. author: whit33r closes #4727
UPDATE `quest_template` SET `RequiredClasses`=64 WHERE `id` = 7505;

-- fixes ashen band of destruction proc author: kandera
DELETE FROM `spell_proc_event` WHERE `entry` = 72417;
INSERT INTO `spell_proc_event` (`entry`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`procFlags`,`procEx`,`ppmRate`,`CustomChance`,`Cooldown`) VALUES
(72417,0,0,0,0,0,327680,0,0,0,60);

-- fixes quest credit from Fel reaver no thanks! author: tREAk & shlomi1515 closes #3715
UPDATE `spell_dbc` SET `Effect1`=16,`EffectMiscValue1`=10855 WHERE `id`=38758;
DELETE FROM `creature_ai_scripts` WHERE creature_id=22293;

-- fix areatrigger for wickerman camp author: boomper closes #3549
DELETE FROM `areatrigger_involvedrelation` WHERE `id` =3991;
INSERT INTO `areatrigger_involvedrelation` (`id`, `quest`)
VALUES (3991,1658);

-- yous have da darkrune should be daily author: kaelima closes #3457
UPDATE `quest_template` SET `SpecialFlags` = `SpecialFlags` | 1 WHERE `id` = 11027;

-- fix infinite corruptor loot id author: vincent-michael
UPDATE `creature_template` SET `lootid` = 32313 WHERE `entry` =32313;
