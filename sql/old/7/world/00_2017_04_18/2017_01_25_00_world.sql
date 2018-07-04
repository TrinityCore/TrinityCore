-- Quests and quest givers removed in patch 7.0.3
-- Blood elf starting area (Sunstrider Isle)

-- The following NPCs are no longer quest givers:
UPDATE `creature_template` SET `npcflag` = `npcflag`& ~2 WHERE `entry` IN
(15279,  -- Julia Sunstriker <Mage Trainer>
 15280,  -- Jesthenis Sunstriker <Paladin Trainer>
 15283,  -- Summoner Teli'Larien <Warlock Trainer>
 15284,  -- Matron Arena <Priest Trainer>
 15285,  -- Pathstalker Kariel <Rogue Trainer>
 15513,  -- Ranger Sallina <Hunter Trainer>
 43010,  -- Delios Silverblade <Warrior Trainer>
 63332); -- Pao <Monk Trainer>

-- Magistrix Erona (15278) no longer starts these quests:
DELETE FROM `creature_queststarter` WHERE `id`= 15278 AND `quest` IN
(8328,  -- Quest:Mage Training
 8329,  -- Quest:Warrior Training
 8563,  -- Quest:Warlock Training
 8564,  -- Quest:Priest Training
 9392,  -- Quest:Rogue Training
 9393,  -- Quest:Hunter Training
 9676); -- Quest:Paladin Training

-- These NPCs no longer start the following obsolete quests:
DELETE FROM `creature_queststarter` WHERE `id`= 15279 AND `quest`= 10068; -- Julia Sunstriker <Mage Trainer>, Quest:Frost Nova
DELETE FROM `creature_queststarter` WHERE `id`= 15280 AND `quest`= 10069; -- Jesthenis Sunstriker <Paladin Trainer>, Quest:Ways of the Light
DELETE FROM `creature_queststarter` WHERE `id`= 15283 AND `quest`= 10073; -- Summoner Teli'Larien <Warlock Trainer>, Quest:Curruption
DELETE FROM `creature_queststarter` WHERE `id`= 15284 AND `quest`= 10072; -- Matron Arena <Priest Trainer>, Quest:Learning the Word
DELETE FROM `creature_queststarter` WHERE `id`= 15285 AND `quest`= 10071;  -- Pathstalker Kariel <Rogue Trainer>, Quest:Evisceration
DELETE FROM `creature_queststarter` WHERE `id`= 15513 AND `quest`= 10070; -- Ranger Sallina <Hunter Trainer>, Quest:Steady Shot
DELETE FROM `creature_queststarter` WHERE `id`= 43010 AND `quest`= 27091; -- Delios Silverblade <Warrior Trainer>, Quest:Charge
DELETE FROM `creature_queststarter` WHERE `id`= 63332 AND `quest`= 31171; -- Pao <Monk Trainer>, Quest:Tiger Palm

-- Well Watcher Solanian (15295) also gives these 2 extra quest IDs for existing quests 8330, 8345:
DELETE FROM `creature_queststarter` WHERE `id`= 15295 AND `quest` IN (37442,37443);
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES
(15295, 37442), -- The Shrine of Dath'Remar (also 8345)
(15295, 37443); -- Solanian's Belongings (also 8330)

-- These NPCs no longer end the following obsolete quests:
DELETE FROM `creature_questender` WHERE `id`= 15279 AND `quest` IN (8328,10068); -- Julia Sunstriker <Mage Trainer>, Quest:Mage Training & Frost Nova
DELETE FROM `creature_questender` WHERE `id`= 15280 AND `quest` IN (9676,10069); -- Jesthenis Sunstriker <Paladin Trainer>, Quest:Paladin Training & Ways of the Light
DELETE FROM `creature_questender` WHERE `id`= 15283 AND `quest` IN (8344,8563,10073); -- Summoner Teli'Larien <Warlock Trainer>, Quests:Windows to the Source,Warlock Training,Curruption
DELETE FROM `creature_questender` WHERE `id`= 15284 AND `quest` IN (8564,10072); -- Matron Arena <Priest Trainer>, Quest:Priest Training & Learning the Word
DELETE FROM `creature_questender` WHERE `id`= 15285 AND `quest` IN (9392,10071); -- Pathstalker Kariel <Rogue Trainer>, Quest:Rogue Training & Evisceration
DELETE FROM `creature_questender` WHERE `id`= 15513 AND `quest` IN (9393,10070); -- Ranger Sallina <Hunter Trainer>, Quest:Hunter Training & Steady Shot
DELETE FROM `creature_questender` WHERE `id`= 43010 AND `quest` IN (8329, 27091); -- Delios Silverblade <Warrior Trainer>, Quest:Warrior Training & Charge
DELETE FROM `creature_questender` WHERE `id`= 63332 AND `quest` IN (31170, 31171); -- Pao <Monk Trainer>, Quest:Monk Training & Tiger Palm

-- These quests are obsolete and need to be disabled:
DELETE FROM `disables` WHERE `sourceType`= 1 AND `entry` IN (8328,8329,8344,8563,8564,9392,9393,9676,10068,10069,10070,10071,10072,10073,27091,31170,31171,37441);
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,  8328, 0, '', '', 'Obsolete quest: Mage Training'),
(1,  8329, 0, '', '', 'Obsolete quest: Warrior Training'),
(1,  8344, 0, '', '', 'Obsolete quest: Windows to the Source'),
(1,  8563, 0, '', '', 'Obsolete quest: Warlock Training'),
(1,  8564, 0, '', '', 'Obsolete quest: Priest Training'),
(1,  9392, 0, '', '', 'Obsolete quest: Rogue Training'),
(1,  9393, 0, '', '', 'Obsolete quest: Hunter Training'),
(1,  9676, 0, '', '', 'Obsolete quest: Paladin Training'),
(1, 10068, 0, '', '', 'Obsolete quest: Frost Nova'),
(1, 10069, 0, '', '', 'Obsolete quest: Ways of the Light'),
(1, 10070, 0, '', '', 'Obsolete quest: Steady Shot'),
(1, 10071, 0, '', '', 'Obsolete quest: Evisceration'),
(1, 10072, 0, '', '', 'Obsolete quest: Learning the Word'),
(1, 10073, 0, '', '', 'Obsolete quest: Curruption'),
(1, 27091, 0, '', '', 'Obsolete quest: Charge'),
(1, 31170, 0, '', '', 'Obsolete quest: Monk Training'),
(1, 31171, 0, '', '', 'Obsolete quest: Tiger Palm'),
(1, 37441, 0, '', '', 'Obsolete quest: Solanian\'s Belongings'); -- Replaced by Quest ID 37443
