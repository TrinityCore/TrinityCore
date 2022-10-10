-- Spell Scripts
DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_dru_incapacitating_roar',
 'spell_dru_stampeding_roar',
 'spell_dru_thrash',
 'spell_dru_thrash_aura',
 'spell_dru_berserk',
 'spell_dru_brambles',
 'spell_dru_barkskin',
 'spell_dru_bristling_fur',
 'spell_dru_tiger_dash',
 'spell_dru_galactic_guardian',
 'spell_dru_earthwarden');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(99, 'spell_dru_incapacitating_roar'),      -- Incapacitating Roar (99)
(106898, 'spell_dru_stampeding_roar'),      -- Stampeding Roar (106898)
(77758, 'spell_dru_thrash'),                -- Thrash (77758)
(192090, 'spell_dru_thrash_aura'),          -- Thrash (192090)
(50334, 'spell_dru_berserk'),               -- Berserk (50334)
(203953, 'spell_dru_brambles'),             -- Berserk (50334)
(22812, 'spell_dru_barkskin'),              -- Brambles (203953)
(155835, 'spell_dru_bristling_fur'),        -- Bristling Fur (155835)
(252216, 'spell_dru_tiger_dash'),           -- Tiger Dash (252216)
(203964, 'spell_dru_galactic_guardian'),    -- Galactic Guardian (203964)
(203974, 'spell_dru_earthwarden');          -- Earthwarden (203974)

-- Spell Procs
DELETE FROM `spell_proc` WHERE `SpellId` IN 
(135288,  -- Tooth and Claw    (135288)
 135286,  -- Tooth and Claw    (135286)
 155578,  -- Guardian Of Elune (155578)
 203974,  -- Earthwarden       (203974)
 48484,   -- Infected Wounds   (48484)
 345208); -- Infected Wounds   (345208)
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(135288, 1, 0, 0x0, 0x0, 0x0, 0x0, 0x4, 1, 2, 0x403, 0, 2, 0, 20, 0, 0),                -- Tooth and Claw    (135288), proc on auto attack
(135286, 0, 7, 0x800, 0x0, 0x0, 0x0, 0x10, 1, 2, 0x403, 0x8, 0, 0, 0, 0, 0),            -- Tooth and Claw    (135286), proc on Maul
(155578, 0, 7, 0x0, 0x40, 0x0, 0x0, 0x10, 1, 2, 0x403, 0, 0, 0, 0, 0, 0),               -- Guardian Of Elune (155578), proc on Mangle
(203974, 0, 7, 0x0, 0x0, 0x08000000, 0x40000000, 0x10, 1, 1, 0x403, 0, 0, 0, 0, 0, 0),  -- Earthwarden       (203974), proc on Thrash
(48484,  1, 7, 0x1000, 0, 0, 0, 0x10, 1, 1, 0x403, 0, 0, 0, 100, 0, 0),                 -- Infected Wounds   (48484) , proc on Rake
(345208, 1, 7, 0x800, 0x40, 0, 0, 0x10, 1, 1, 0x403, 0, 0, 0, 100, 0, 0);               -- Infected Wounds   (345208), proc on Mangle and Maul
