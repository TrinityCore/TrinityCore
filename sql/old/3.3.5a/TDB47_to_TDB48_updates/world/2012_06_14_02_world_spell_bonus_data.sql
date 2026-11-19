-- Death Knight
DELETE FROM `spell_bonus_data` WHERE `entry` IN(58621, 47632, 47633, 50444, 70890, 50526, 48982, 59754, 49184);
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES
(58621, 0, -1,  0.08,  -1, 'Death Knight - Glyph of Chains of Ice'),        -- Shouldn't scale with SP.
(47632, 0, -1,  0.15,  -1, 'Death Knight - Death Coil'),                    -- Shouldn't scale with SP.
(47633, 0, -1,  0.15,  -1, 'Death Knight - Death Coil (Heal)'),             -- Shouldn't scale with SP.
(50444, 0, -1,  0.105, -1, 'Death Knight - Corpse Explosion (Triggered)'),  -- Shouldn't scale with SP.
(70890, 0, -1, -1,     -1, 'Death Knight - Scourge Strike (Shadow)'),       -- Shouldn't scale with SP.
(50526, 0, -1, -1,     -1, 'Death Knight - Wandering Plague (Triggered)'),  -- Shouldn't scale with SP.
(48982, 0, -1, -1,     -1, 'Death Knight - Rune Tap'),                      -- Shouldn't scale with SP.
(59754, 0, -1, -1,     -1, 'Death Knight - Glyph of Rune Tap (Triggered)'), -- Shouldn't scale with SP.
(49184, 0, -1,  0.2,   -1, 'Death Knight - Howling Blast');                 -- Shouldn't scale with SP.

-- Druid
DELETE FROM `spell_bonus_data` WHERE `entry` IN(48450, 48451); -- Lifebloom Rank 2, Rank 3
DELETE FROM `spell_bonus_data` WHERE `entry` IN(48567, 48568); -- Lacerate Rank 2, Rank 3
DELETE FROM `spell_bonus_data` WHERE `entry` IN(33745, 9007);
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES
(33745, 0,  0,  0.01,   0.01, 'Druid - Lacerate ($AP*0.05/number of ticks)'), -- Direct damage should scale with AP, based on DrDamage addon(3.3.5a).
(9007, -1,  0, -1,      0.03, 'Druid - Pounce Bleed (Triggered)');            -- Shouldn't scale with SP. Increase AP coefficient, based on DrDamage addon(3.3.5a) and Wowwiki.com.

-- Hunter
DELETE FROM `spell_bonus_data` WHERE `entry` IN(56641, 42243, 3674, 19306, 1495, 63468, 136);
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES
(56641,  0, -1,  0.1,  -1,     'Hunter - Steady Shot'),                              -- Shouldn't scale with SP.
(42243,  0, -1,  0.0837, -1,   'Hunter - Volley (Triggered)'),                       -- Shouldn't scale with SP.
(3674,  -1,  0, -1,     0.023, 'Hunter - Black Arrow ($RAP*0.1 / number of ticks)'), -- Shouldn't scale with SP. Increase AP coefficient, based on DrDamage addon(3.3.5a).
(19306,  0, -1,  0.2,  -1,     'Hunter - Counterattack'),                            -- Shouldn't scale with SP.
(1495,   0, -1,  0.2,  -1,     'Hunter - Mongoose Bite'),                            -- Shouldn't scale with SP.
(63468, -1,  0, -1,    -1,     'Hunter - Piercing Shots'),                           -- Shouldn't scale with SP.
(136,   -1,  0, -1,    -1,     'Hunter - Mend Pet');                                 -- Shouldn't scale with SP.

-- Mage
DELETE FROM `spell_bonus_data` WHERE `entry`=7269; -- Arcane Missiles Triggered Spell Rank 2
DELETE FROM `spell_bonus_data` WHERE `entry` IN(133, 44614, 44457, 44461);
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES
(133,    1,       0,   -1, -1, 'Mage - Fireball'),                                -- DoT componenet shouldn't scale.
(44614,  0.8571,  0,   -1, -1, 'Mage - Frostfire Bolt'),                          -- DoT componenet shouldn't scale.
(44457, -1,       0.2, -1, -1, 'Mage - Living Bomb ($SP*0.8 / number of ticks)'), -- Direct damage bonus correction.
(44461,  0.4286, -1,   -1, -1, 'Mage - Living Bomb (Triggered)');                 -- Direct damage bonus correction.

-- Paladin
DELETE FROM `spell_bonus_data` WHERE `entry` IN(633, 54158, 20467, 20187, 31803, 53742, 31804, 53733);
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES
(633,    0,     -1,      -1,     -1,      'Paladin - Lay on Hands'),               -- Shouldn't scale with SP.
(54158,  0.27,  -1,       0.175, -1,      'Paladin - Judgement (Seal of Light, Seal of Wisdom, Seal of Justice)'), -- Increase coefficient, based on Wowwiki.com.
(20467,  0.14,  -1,       0.115, -1,      'Paladin - Judgement of Command'),       -- Decrease coefficient, based on Wowwiki.com.
(20187,  0.355, -1,       0.225, -1,      'Paladin - Judgement of Righteousness'), -- Increase coefficient, based on Wowwiki.com.
(31803, -1,      0.0132, -1,      0.0252, 'Paladin - Holy Vengeance'),             -- Decrease coefficient, based on DrDamage addon(3.3.5a) and Wowwiki.com.
(53742, -1,      0.0132, -1,      0.0252, 'Paladin - Blood Corruption'),           -- Decrease coefficient, based on DrDamage addon(3.3.5a) and Wowwiki.com.
(31804,  0.24,  -1,       0.15,  -1,      'Paladin - Judgement of Vengeance'),     -- Increase coefficient, based on Wowwiki.com.
(53733,  0.24,  -1,       0.15,  -1,      'Paladin - Judgement of Corruption');    -- Increase coefficient, based on Wowwiki.com.

-- Priest
DELETE FROM `spell_bonus_data` WHERE `entry` IN(52983, 52954, 58985); -- Penance Heal Rank 2, Rank 3, Rank 4
DELETE FROM `spell_bonus_data` WHERE `entry` IN(52998, 52999, 53000); -- Penance Hurt Rank 2, Rank 3, Rank 4
DELETE FROM `spell_bonus_data` WHERE `entry` IN(7001);
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES
(7001, -1, 0.626, -1, -1, 'Priest - Lightwell Renew ($SP*1.878 / number of ticks)'); -- Increase coefficient, based on DrDamage addon(3.3.5a).

-- Rogue
DELETE FROM `spell_bonus_data` WHERE `entry` IN(819, 11353, 11354, 25349, 26968, 27187, 57969, 57970); -- Deadly Poison Rank 2, Rank 3, etc.
DELETE FROM `spell_bonus_data` WHERE `entry` IN(8685, 8689, 11335, 11336, 11337, 26890, 57964, 57965); -- Instant Poison Rank 2, Rank 3, etc.
DELETE FROM `spell_bonus_data` WHERE `entry` IN(13222, 13223, 13224, 27189, 57974, 57975); -- Wound Poison Rank 2, Rank 3, etc.
DELETE FROM `spell_bonus_data` WHERE `entry` IN(32645, 2098, 703, 1776, 1943, 8680, 26688, 13218);
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES
(32645, 0, -1, -1,    -1,    'Rogue - Envenom'),           -- Shouldn't scale with SP.
(2098,  0, -1, -1,    -1,    'Rogue - Eviscerate'),        -- Shouldn't scale with SP.
(703,  -1,  0, -1,     0.07, 'Rogue - Garrote'),           -- Shouldn't scale with SP.
(1776,  0, -1,  0.21, -1,    'Rogue - Gouge'),             -- Shouldn't scale with SP.
(1943, -1,  0, -1,    -1,    'Rogue - Rupture'),           -- Shouldn't scale with SP.
(8680,  0, -1,  0.1,  -1,    'Rogue - Instant Poison'),    -- Shouldn't scale with SP.
(26688, 0, -1,  0,    -1,    'Rogue - Anesthetic Poison'), -- Shouldn't scale with SP nor AP.
(13218, 0, -1,  0.04, -1,    'Rogue - Wound Poison');      -- Shouldn't scale with SP.

 -- Warlock Healthstones Shouldn't scale with SP.
DELETE FROM `spell_bonus_data` WHERE `entry` IN (6262, 23468, 23469, 6263, 23470, 23471, 5720, 23472, 23473, 5723, 23474, 23475, 11732, 23476, 23477, 27235, 27236, 27237, 47874, 47873, 47872, 47875, 47876, 47877);
INSERT INTO `spell_bonus_data` (`entry`,`direct_bonus`,`dot_bonus`,`ap_bonus`,`ap_dot_bonus`,`comments`) VALUES
(6262,  0, -1, 0, -1, 'Warlock - HS - Minor Healthstone (with 0/2 Improved Healthstone)'),
(23468, 0, -1, 0, -1, 'Warlock - HS - Minor Healthstone (with 1/2 Improved Healthstone)'),
(23469, 0, -1, 0, -1, 'Warlock - HS - Minor Healthstone (with 2/2 Improved Healthstone)'),
(6263,  0, -1, 0, -1, 'Warlock - HS - Lesser Healthstone (with 0/2 Improved Healthstone)'),
(23470, 0, -1, 0, -1, 'Warlock - HS - Lesser Healthstone (with 1/2 Improved Healthstone)'),
(23471, 0, -1, 0, -1, 'Warlock - HS - Lesser Healthstone (with 2/2 Improved Healthstone)'),
(5720,  0, -1, 0, -1, 'Warlock - HS - Healthstone (with 0/2 Improved Healthstone)'),
(23472, 0, -1, 0, -1, 'Warlock - HS - Healthstone (with 1/2 Improved Healthstone)'),
(23473, 0, -1, 0, -1, 'Warlock - HS - Healthstone (with 2/2 Improved Healthstone)'),
(5723,  0, -1, 0, -1, 'Warlock - HS - Greater Healthstone (with 0/2 Improved Healthstone)'),
(23474, 0, -1, 0, -1, 'Warlock - HS - Greater Healthstone (with 1/2 Improved Healthstone)'),
(23475, 0, -1, 0, -1, 'Warlock - HS - Greater Healthstone (with 2/2 Improved Healthstone)'),
(11732, 0, -1, 0, -1, 'Warlock - HS - Major Healthstone (with 0/2 Improved Healthstone)'),
(23476, 0, -1, 0, -1, 'Warlock - HS - Major Healthstone (with 1/2 Improved Healthstone)'),
(23477, 0, -1, 0, -1, 'Warlock - HS - Major Healthstone (with 2/2 Improved Healthstone)'),
(27235, 0, -1, 0, -1, 'Warlock - HS - Master Healthstone (with 0/2 Improved Healthstone)'),
(27236, 0, -1, 0, -1, 'Warlock - HS - Master Healthstone (with 1/2 Improved Healthstone)'),
(27237, 0, -1, 0, -1, 'Warlock - HS - Master Healthstone (with 2/2 Improved Healthstone)'),
(47874, 0, -1, 0, -1, 'Warlock - HS - Demonic Healthstone (with 0/2 Improved Healthstone)'),
(47873, 0, -1, 0, -1, 'Warlock - HS - Demonic Healthstone (with 1/2 Improved Healthstone)'),
(47872, 0, -1, 0, -1, 'Warlock - HS - Demonic Healthstone (with 2/2 Improved Healthstone)'),
(47875, 0, -1, 0, -1, 'Warlock - HS - Fel Healthstone (with 0/2 Improved Healthstone)'),
(47876, 0, -1, 0, -1, 'Warlock - HS - Fel Healthstone (with 1/2 Improved Healthstone)'),
(47877, 0, -1, 0, -1, 'Warlock - HS - Fel Healthstone (with 2/2 Improved Healthstone)');
