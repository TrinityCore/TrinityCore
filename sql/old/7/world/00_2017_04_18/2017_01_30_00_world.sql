-- Quest and quest givers removed in patch 7.0.3
-- Human starting area (Northshire Valley)

-- Marshal Mcbride (197) no longer starts/ends these quests:
DELETE FROM `creature_queststarter` WHERE `id`= 197 AND `quest` IN
(3100,  -- Simple Letter
 3101,  -- Consecrated Letter
 3102,  -- Encrypted Letter
 3103,  -- Hallowed Letter
 3104,  -- Glyphic Letter
 3105,  -- Tainted Letter
26910); -- Etched Letter

DELETE FROM `creature_questender` WHERE `id`= 197 AND `quest` IN
(   7,  -- [DEPRECATED] Kobold Camp Cleanup
   15,  -- [DEPRECATED] Investigate Echo Ridge
   21,  -- [DEPRECATED] Skirmish at Echo Ridge
  783,  -- [DEPRECATED] A Threat Within
14032,  -- Kobold Camp Cleanup [Programming Test]
26392); -- Voucher of Bravery

-- These NPCs no longer start the following obsolete quests:
DELETE FROM `creature_queststarter` WHERE `id` = 198 AND `quest` = 26916; -- Khelden Bremen    <Mage Trainer>,    Quest:Mastering the Arcane
DELETE FROM `creature_queststarter` WHERE `id` = 375 AND `quest` = 26919; -- Priestess Anetta  <Priest Trainer>,  Quest:Learning the Word
DELETE FROM `creature_queststarter` WHERE `id` = 459 AND `quest` = 26914; -- Drusilla La Salle <Warlock Trainer>, Quest:Corruption
DELETE FROM `creature_queststarter` WHERE `id` = 911 AND `quest` = 26913; -- Llane Beshere     <Warrior Trainer>, Quest:Charging into Battle
DELETE FROM `creature_queststarter` WHERE `id` = 915 AND `quest` = 26915; -- Jorik Kerridan    <Rogue Trainer>,   Quest:The Deepest Cut
DELETE FROM `creature_queststarter` WHERE `id` = 925 AND `quest` = 26918; -- Brother Sammuel   <Paladin Trainer>, Quest:The Power of the Light
DELETE FROM `creature_queststarter` WHERE `id`= 43278 AND `quest`= 26917; -- Ashley Bank       <Hunter Trainer>,  Quest:The Hunter's Path

-- These NPCs no longer end the following obsolete quests:
DELETE FROM `creature_questender` WHERE `id` =  198 AND `quest` IN ( 3104,26916); -- Quests:Glyphic Letter,Mastering the Arcane
DELETE FROM `creature_questender` WHERE `id` =  375 AND `quest` IN ( 3103,26919); -- Quests:Hallowed Letter,Learning the Word
DELETE FROM `creature_questender` WHERE `id` =  459 AND `quest` IN ( 1598,3105,26151,26914); -- Quests:The Stolen Tome,Tainted Letter,Dark Letter,Corruption
DELETE FROM `creature_questender` WHERE `id` =  911 AND `quest` IN ( 3100,26913); -- Quests:Simple Letter,Charging into Battle
DELETE FROM `creature_questender` WHERE `id` =  915 AND `quest` IN ( 3102,26915); -- Quests:Encrypted Letter,The Deepest Cut
DELETE FROM `creature_questender` WHERE `id` =  925 AND `quest` IN ( 3101,26918); -- Quests:Consecrated Letter,The Power of the Light
DELETE FROM `creature_questender` WHERE `id`= 43278 AND `quest` IN (26910,26917); -- Quests:

-- These quests are obsolete and need to be disabled:
DELETE FROM `disables` WHERE `sourceType`= 1 AND `entry` IN (3100,3101,3102,3103,3104,3105,26910,26913,26914,26915,26916,26917,26918,26919);
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,  3100, 0, '', '', 'Obsolete quest: Simple Letter'),
(1,  3101, 0, '', '', 'Obsolete quest: Consecrated Letter'),
(1,  3102, 0, '', '', 'Obsolete quest: Encrypted Letter'),
(1,  3103, 0, '', '', 'Obsolete quest: Hallowed Letter'),
(1,  3104, 0, '', '', 'Obsolete quest: Glyphic Letter'),
(1,  3105, 0, '', '', 'Obsolete quest: Tainted Letter'),
(1, 26910, 0, '', '', 'Obsolete quest: Etched Letter'),
(1, 26913, 0, '', '', 'Obsolete quest: Charging into Battle'),
(1, 26914, 0, '', '', 'Obsolete quest: Corruption'),
(1, 26915, 0, '', '', 'Obsolete quest: The Deepest Cut'),
(1, 26916, 0, '', '', 'Obsolete quest: Mastering the Arcane'),
(1, 26917, 0, '', '', 'Obsolete quest: The Hunter\'s Path'),
(1, 26918, 0, '', '', 'Obsolete quest: The Power of the Light'),
(1, 26919, 0, '', '', 'Obsolete quest: Learning the Word');
