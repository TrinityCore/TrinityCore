SET @CGUID := 86984;

DELETE FROM `creature` WHERE `id`=24110 AND `guid` BETWEEN @CGUID+0 AND @CGUID+31;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 24110, 571, 1, 1, 2480.52, -405.0309, 31.25292, 1.954769, 120, 0, 0), -- 24110 (Area: 4181)
(@CGUID+1, 24110, 571, 1, 1, 2485.832, -406.4011, 38.64569, 1.937315, 120, 0, 0), -- 24110 (Area: 4181)
(@CGUID+2, 24110, 571, 1, 1, 2483.247, -405.9387, 35.05476, 4.991642, 120, 0, 0), -- 24110 (Area: 4181)
(@CGUID+3, 24110, 571, 1, 1, 2477.307, -404.4191, 27.71297, 2.530727, 120, 0, 0), -- 24110 (Area: 4181)
(@CGUID+4, 24110, 571, 1, 1, 2490.05, -404.6198, 27.34736, 0, 120, 0, 0), -- 24110 (Area: 4181)
(@CGUID+5, 24110, 571, 1, 1, 2486.804, -396.4983, 37.61678, 6.248279, 120, 0, 0), -- 24110 (Area: 4181)
(@CGUID+6, 24110, 571, 1, 1, 2473.764, -403.68, 23.80915, 3.246312, 120, 0, 0), -- 24110 (Area: 4181)
(@CGUID+7, 24110, 571, 1, 1, 2489.167, -395.6806, 28.83605, 0.01745329, 120, 0, 0), -- 24110 (Area: 4181)
(@CGUID+8, 24110, 571, 1, 1, 2488.105, -403.3663, 35.30573, 2.80998, 120, 0, 0), -- 24110 (Area: 4181)
(@CGUID+9, 24110, 571, 1, 1, 2457.642, -389.6918, 23.55255, 6.143559, 120, 0, 0), -- 24110 (Area: 4181)
(@CGUID+10, 24110, 571, 1, 1, 2469.61, -402.5246, 21.45798, 4.08407, 120, 0, 0), -- 24110 (Area: 4181)
(@CGUID+11, 24110, 571, 1, 1, 2454.252, -397.5855, 51.25713, 0.03490658, 120, 0, 0), -- 24110 (Area: 4181)
(@CGUID+12, 24110, 571, 1, 1, 2457.418, -405.3847, 30.72205, 6.213372, 120, 0, 0), -- 24110 (Area: 4181)
(@CGUID+13, 24110, 571, 1, 1, 2483.101, -393.8391, 43.72463, 2.897247, 120, 0, 0), -- 24110 (Area: 4181)
(@CGUID+14, 24110, 571, 1, 1, 2455.441, -395.9613, 42.66463, 0.05235988, 120, 0, 0), -- 24110 (Area: 4181)
(@CGUID+15, 24110, 571, 1, 1, 2454.66, -404.776, 48.54633, 6.143559, 120, 0, 0), -- 24110 (Area: 4181)
(@CGUID+16, 24110, 571, 1, 1, 2458.783, -404.1076, 23.79817, 6.265732, 120, 0, 0), -- 24110 (Area: 4181)
(@CGUID+17, 24110, 571, 1, 1, 2458.11, -410.4796, 22.85155, 6.195919, 120, 0, 0), -- 24110 (Area: 4181)
(@CGUID+18, 24110, 571, 1, 1, 2481.292, -393.944, 40.58387, 4.171337, 120, 0, 0), -- 24110 (Area: 4181)
(@CGUID+19, 24110, 571, 1, 1, 2457.773, -397.1545, 31.50192, 6.195919, 120, 0, 0), -- 24110 (Area: 4181)
(@CGUID+20, 24110, 571, 1, 1, 2469.01, -396.4393, 25.475, 0.2792527, 120, 0, 0), -- 24110 (Area: 4181)
(@CGUID+21, 24110, 571, 1, 1, 2478.411, -394.4479, 36.02073, 4.223697, 120, 0, 0), -- 24110 (Area: 4181)
(@CGUID+22, 24110, 571, 1, 1, 2456.78, -389.8281, 32.9614, 0, 120, 0, 0), -- 24110 (Area: 4181)
(@CGUID+23, 24110, 571, 1, 1, 2460.665, -399.6276, 19.7543, 3.089233, 120, 0, 0), -- 24110 (Area: 4181)
(@CGUID+24, 24110, 571, 1, 1, 2476.166, -394.8342, 31.92243, 1.27409, 120, 0, 0), -- 24110 (Area: 4181)
(@CGUID+25, 24110, 571, 1, 1, 2455.731, -404.8611, 40.88202, 6.213372, 120, 0, 0), -- 24110 (Area: 4181)
(@CGUID+26, 24110, 571, 1, 1, 2460.889, -401.5321, 19.4641, 5.131268, 120, 0, 0), -- 24110 (Area: 4181)
(@CGUID+27, 24110, 571, 1, 1, 2464.679, -397.7112, 21.8534, 5.113815, 120, 0, 0), -- 24110 (Area: 4181)
(@CGUID+28, 24110, 571, 1, 1, 2464.713, -401.7634, 19.7663, 0.06981317, 120, 0, 0), -- 24110 (Area: 4181)
(@CGUID+29, 24110, 571, 1, 1, 2456.293, -412.3963, 29.24669, 6.073746, 120, 0, 0), -- 24110 (Area: 4181)
(@CGUID+30, 24110, 571, 1, 1, 2472.812, -395.45, 28.40558, 3.368485, 120, 0, 0), -- 24110 (Area: 4181)
(@CGUID+31, 24110, 571, 1, 1, 2458.6, -396.5036, 23.42054, 6.248279, 120, 0, 0); -- 24110 (Area: 4181)

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=28013;
UPDATE `creature_template` SET `AIName`='' WHERE  `entry`=28013;
DELETE FROM `creature` WHERE  `id`=28013;

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` BETWEEN -@CGUID-31 AND -@CGUID-0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-@CGUID-0, 0, 0, 1, 8, 0, 100, 0, 48455, 0, 0, 0, 11, 50290, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Fire Upon the Waters: Sail Burning Kill Credit\''),
(-@CGUID-0, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 48522, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Sinner''s Folly Fire Bunny: Periodic Fire Aura\''),
(-@CGUID-1, 0, 0, 1, 8, 0, 100, 0, 48455, 0, 0, 0, 11, 50290, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Fire Upon the Waters: Sail Burning Kill Credit\''),
(-@CGUID-1, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 48522, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Sinner''s Folly Fire Bunny: Periodic Fire Aura\''),
(-@CGUID-2, 0, 0, 1, 8, 0, 100, 0, 48455, 0, 0, 0, 11, 50290, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Fire Upon the Waters: Sail Burning Kill Credit\''),
(-@CGUID-2, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 48522, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Sinner''s Folly Fire Bunny: Periodic Fire Aura\''),
(-@CGUID-3, 0, 0, 1, 8, 0, 100, 0, 48455, 0, 0, 0, 11, 50290, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Fire Upon the Waters: Sail Burning Kill Credit\''),
(-@CGUID-3, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 48522, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Sinner''s Folly Fire Bunny: Periodic Fire Aura\''),
(-@CGUID-4, 0, 0, 1, 8, 0, 100, 0, 48455, 0, 0, 0, 11, 50290, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Fire Upon the Waters: Sail Burning Kill Credit\''),
(-@CGUID-4, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 48522, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Sinner''s Folly Fire Bunny: Periodic Fire Aura\''),
(-@CGUID-5, 0, 0, 1, 8, 0, 100, 0, 48455, 0, 0, 0, 11, 50290, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Fire Upon the Waters: Sail Burning Kill Credit\''),
(-@CGUID-5, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 48522, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Sinner''s Folly Fire Bunny: Periodic Fire Aura\''),
(-@CGUID-6, 0, 0, 1, 8, 0, 100, 0, 48455, 0, 0, 0, 11, 50290, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Fire Upon the Waters: Sail Burning Kill Credit\''),
(-@CGUID-6, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 48522, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Sinner''s Folly Fire Bunny: Periodic Fire Aura\''),
(-@CGUID-7, 0, 0, 1, 8, 0, 100, 0, 48455, 0, 0, 0, 11, 50290, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Fire Upon the Waters: Sail Burning Kill Credit\''),
(-@CGUID-7, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 48522, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Sinner''s Folly Fire Bunny: Periodic Fire Aura\''),
(-@CGUID-8, 0, 0, 1, 8, 0, 100, 0, 48455, 0, 0, 0, 11, 50290, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Fire Upon the Waters: Sail Burning Kill Credit\''),
(-@CGUID-8, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 48522, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Sinner''s Folly Fire Bunny: Periodic Fire Aura\''),
(-@CGUID-9, 0, 0, 1, 8, 0, 100, 0, 48455, 0, 0, 0, 11, 50290, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Fire Upon the Waters: Sail Burning Kill Credit\''),
(-@CGUID-9, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 48522, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Sinner''s Folly Fire Bunny: Periodic Fire Aura\''),
(-@CGUID-10, 0, 0, 1, 8, 0, 100, 0, 48455, 0, 0, 0, 11, 50290, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Fire Upon the Waters: Sail Burning Kill Credit\''),
(-@CGUID-10, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 48522, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Sinner''s Folly Fire Bunny: Periodic Fire Aura\''),
(-@CGUID-11, 0, 0, 1, 8, 0, 100, 0, 48455, 0, 0, 0, 11, 50290, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Fire Upon the Waters: Sail Burning Kill Credit\''),
(-@CGUID-11, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 48522, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Sinner''s Folly Fire Bunny: Periodic Fire Aura\''),
(-@CGUID-12, 0, 0, 1, 8, 0, 100, 0, 48455, 0, 0, 0, 11, 50290, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Fire Upon the Waters: Sail Burning Kill Credit\''),
(-@CGUID-12, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 48522, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Sinner''s Folly Fire Bunny: Periodic Fire Aura\''),
(-@CGUID-13, 0, 0, 1, 8, 0, 100, 0, 48455, 0, 0, 0, 11, 50290, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Fire Upon the Waters: Sail Burning Kill Credit\''),
(-@CGUID-13, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 48522, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Sinner''s Folly Fire Bunny: Periodic Fire Aura\''),
(-@CGUID-14, 0, 0, 1, 8, 0, 100, 0, 48455, 0, 0, 0, 11, 50290, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Fire Upon the Waters: Sail Burning Kill Credit\''),
(-@CGUID-14, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 48522, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Sinner''s Folly Fire Bunny: Periodic Fire Aura\''),
(-@CGUID-15, 0, 0, 1, 8, 0, 100, 0, 48455, 0, 0, 0, 11, 50290, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Fire Upon the Waters: Sail Burning Kill Credit\''),
(-@CGUID-15, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 48522, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Sinner''s Folly Fire Bunny: Periodic Fire Aura\''),
(-@CGUID-16, 0, 0, 1, 8, 0, 100, 0, 48455, 0, 0, 0, 11, 50290, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Fire Upon the Waters: Sail Burning Kill Credit\''),
(-@CGUID-16, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 48522, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Sinner''s Folly Fire Bunny: Periodic Fire Aura\''),
(-@CGUID-17, 0, 0, 1, 8, 0, 100, 0, 48455, 0, 0, 0, 11, 50290, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Fire Upon the Waters: Sail Burning Kill Credit\''),
(-@CGUID-17, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 48522, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Sinner''s Folly Fire Bunny: Periodic Fire Aura\''),
(-@CGUID-18, 0, 0, 1, 8, 0, 100, 0, 48455, 0, 0, 0, 11, 50290, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Fire Upon the Waters: Sail Burning Kill Credit\''),
(-@CGUID-18, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 48522, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Sinner''s Folly Fire Bunny: Periodic Fire Aura\''),
(-@CGUID-19, 0, 0, 1, 8, 0, 100, 0, 48455, 0, 0, 0, 11, 50290, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Fire Upon the Waters: Sail Burning Kill Credit\''),
(-@CGUID-19, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 48522, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Sinner''s Folly Fire Bunny: Periodic Fire Aura\''),
(-@CGUID-20, 0, 0, 1, 8, 0, 100, 0, 48455, 0, 0, 0, 11, 50290, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Fire Upon the Waters: Sail Burning Kill Credit\''),
(-@CGUID-20, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 48522, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Sinner''s Folly Fire Bunny: Periodic Fire Aura\''),
(-@CGUID-21, 0, 0, 1, 8, 0, 100, 0, 48455, 0, 0, 0, 11, 50290, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Fire Upon the Waters: Sail Burning Kill Credit\''),
(-@CGUID-21, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 48522, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Sinner''s Folly Fire Bunny: Periodic Fire Aura\''),
(-@CGUID-22, 0, 0, 1, 8, 0, 100, 0, 48455, 0, 0, 0, 11, 50290, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Fire Upon the Waters: Sail Burning Kill Credit\''),
(-@CGUID-22, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 48522, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Sinner''s Folly Fire Bunny: Periodic Fire Aura\''),
(-@CGUID-23, 0, 0, 1, 8, 0, 100, 0, 48455, 0, 0, 0, 11, 50290, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Fire Upon the Waters: Sail Burning Kill Credit\''),
(-@CGUID-23, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 48522, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Sinner''s Folly Fire Bunny: Periodic Fire Aura\''),
(-@CGUID-24, 0, 0, 1, 8, 0, 100, 0, 48455, 0, 0, 0, 11, 50290, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Fire Upon the Waters: Sail Burning Kill Credit\''),
(-@CGUID-24, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 48522, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Sinner''s Folly Fire Bunny: Periodic Fire Aura\''),
(-@CGUID-25, 0, 0, 1, 8, 0, 100, 0, 48455, 0, 0, 0, 11, 50290, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Fire Upon the Waters: Sail Burning Kill Credit\''),
(-@CGUID-25, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 48522, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Sinner''s Folly Fire Bunny: Periodic Fire Aura\''),
(-@CGUID-26, 0, 0, 1, 8, 0, 100, 0, 48455, 0, 0, 0, 11, 50290, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Fire Upon the Waters: Sail Burning Kill Credit\''),
(-@CGUID-26, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 48522, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Sinner''s Folly Fire Bunny: Periodic Fire Aura\''),
(-@CGUID-27, 0, 0, 1, 8, 0, 100, 0, 48455, 0, 0, 0, 11, 50290, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Fire Upon the Waters: Sail Burning Kill Credit\''),
(-@CGUID-27, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 48522, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Sinner''s Folly Fire Bunny: Periodic Fire Aura\''),
(-@CGUID-28, 0, 0, 1, 8, 0, 100, 0, 48455, 0, 0, 0, 11, 50290, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Fire Upon the Waters: Sail Burning Kill Credit\''),
(-@CGUID-28, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 48522, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Sinner''s Folly Fire Bunny: Periodic Fire Aura\''),
(-@CGUID-29, 0, 0, 1, 8, 0, 100, 0, 48455, 0, 0, 0, 11, 50290, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Fire Upon the Waters: Sail Burning Kill Credit\''),
(-@CGUID-29, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 48522, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Sinner''s Folly Fire Bunny: Periodic Fire Aura\''),
(-@CGUID-30, 0, 0, 1, 8, 0, 100, 0, 48455, 0, 0, 0, 11, 50290, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Fire Upon the Waters: Sail Burning Kill Credit\''),
(-@CGUID-30, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 48522, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Sinner''s Folly Fire Bunny: Periodic Fire Aura\''),
(-@CGUID-31, 0, 0, 1, 8, 0, 100, 0, 48455, 0, 0, 0, 11, 50290, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Fire Upon the Waters: Sail Burning Kill Credit\''),
(-@CGUID-31, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 48522, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny Large - On Spellhit \'Apothecary\'s Burning Water\' - Cast \'Sinner''s Folly Fire Bunny: Periodic Fire Aura\'');

UPDATE `conditions` SET `ConditionValue2`=24110, `Comment`='Fire Upon the Waters - spell to ELM General Purpose Bunny Large' WHERE  `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=48455 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=0 AND `ConditionValue1`=3 AND `ConditionValue2`=28013 AND `ConditionValue3`=0;
