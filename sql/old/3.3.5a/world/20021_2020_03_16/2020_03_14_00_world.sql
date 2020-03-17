-- 
UPDATE `creature_template_addon` SET `auras`="" WHERE `entry` =8547;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (8547,8558,8556,8546) AND `source_type`=0 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (8561,8553,8419,7028,5650,4812) AND `source_type`=0 AND `id`=3;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (5648,4811) AND `source_type`=0 AND `id`=4;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (7026) AND `source_type`=0 AND `id`=2;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (18639) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(8547, 0, 1, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, 11, 8734, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Death Cultist - On reset - Cast Blackfathom Channeling'),
(18639, 0, 0, 0, 0, 0, 100, 2, 0, 1000, 2400, 3800, 0, 11, 12471, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Cabal Spellbinder - Within 0-40 Range - Cast 'Shadow Bolt' (No Repeat) (Normal Dungeon)"),
(18639, 0, 1, 0, 0, 0, 100, 4, 0, 1000, 2400, 3800, 0, 11, 15472, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Cabal Spellbinder - Within 0-40 Range - Cast 'Shadow Bolt' (No Repeat) (Heroic Dungeon)"),
(18639, 0, 2, 0, 0, 0, 100, 6, 5000, 10000, 20000, 30000, 0, 11, 33502, 1, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, "Cabal Spellbinder - In Combat - Cast 'Brain Wash' (Phase 1) (No Repeat) (Dungeon)"),
(18639, 0, 3, 0, 13, 0, 100, 6, 7000, 9000, 0, 0, 0, 11, 32691, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Cabal Spellbinder - Target Casting - Cast 'Spell Shock' (Phase 1) (No Repeat) (Dungeon)"),
(18639, 0, 4, 0, 23, 0, 100, 1, 8734, 1, 0, 0, 0, 11, 8734, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Cabal Spellbinder - On Has aura - Cast Blackfathom Channeling"),
(8561, 0, 3, 0, 23, 0, 100, 1, 8734, 1, 0, 0, 0, 11, 8734, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Mossflayer Shadowhunter - On Has aura - Cast Blackfathom Channeling"),
(8558, 0, 1, 0, 23, 0, 100, 1, 8734, 1, 0, 0, 0, 11, 8734, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Crypt Slayer - On Has aura - Cast Blackfathom Channeling"),
(8556, 0, 1, 0, 23, 0, 100, 1, 8734, 1, 0, 0, 0, 11, 8734, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Crypt Walker - On Has aura - Cast Blackfathom Channeling"),
(8553, 0, 3, 0, 23, 0, 100, 1, 8734, 1, 0, 0, 0, 11, 8734, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Necromancer - On Has aura - Cast Blackfathom Channeling"),
(8546, 0, 1, 0, 23, 0, 100, 1, 8734, 1, 0, 0, 0, 11, 8734, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Dark Adept - On Has aura - Cast Blackfathom Channeling"),
(8419, 0, 3, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, 11, 8734, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Twilight Idolater - On reset - Cast Blackfathom Channeling'),
(7028, 0, 3, 0, 23, 0, 100, 1, 8734, 1, 0, 0, 0, 11, 8734, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Blackrock Warlock - On Has aura - Cast Blackfathom Channeling"),
(7026, 0, 2, 0, 23, 0, 100, 1, 8734, 1, 0, 0, 0, 11, 8734, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Blackrock Sorcerer - On Has aura - Cast Blackfathom Channeling"),
(5650, 0, 3, 0, 23, 0, 100, 1, 8734, 1, 0, 0, 0, 11, 8734, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sandfury Witch Doctor- On Has aura - Cast Blackfathom Channeling"),
(5648, 0, 4, 0, 23, 0, 100, 1, 8734, 1, 0, 0, 0, 11, 8734, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sandfury Shadowcaster - On Has aura - Cast Blackfathom Channeling"),
(4812, 0, 3, 0, 23, 0, 100, 1, 8734, 1, 0, 0, 0, 11, 8734, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Twilight Loreseeker - On Has aura - Cast Blackfathom Channeling"),
(4811, 0, 4, 0, 23, 0, 100, 1, 8734, 1, 0, 0, 0, 11, 8734, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Twilight Aquamancer - On Has aura - Cast Blackfathom Channeling");
