-- Spell Scripts
DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_pal_judgement',
 'spell_pal_zeal',
 'spell_pal_selfless_healer',
 'spell_pal_crusader_might',
 'spell_pal_righteous_protector',
 'spell_pal_moment_of_glory',
 'spell_pal_righteous_verdict'); 
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(20271, 'spell_pal_judgement'),             -- Judgement Ret       (20271)
(275779, 'spell_pal_judgement'),            -- Judgement Prot      (275779)
(269569, 'spell_pal_zeal'),                 -- Zeal                (269569)
(85804, 'spell_pal_selfless_healer'),       -- Selfless Healer     (85804)
(196926, 'spell_pal_crusader_might'),       -- Cruader's Might     (196926)
(204074, 'spell_pal_righteous_protector'),  -- Righteous Protector (204074)
(327193, 'spell_pal_moment_of_glory'),      -- Moment of Glory     (327193)
(267610, 'spell_pal_righteous_verdict');    -- Righteous Verdict   (267610)

-- Spell Procs -- 
DELETE FROM `spell_proc` WHERE `SpellId` IN
(269569,    -- Zeal               (269569)
 269571,    -- Zeal               (269571)
 326732,    -- Empyrean Power     (326732)
 326733,    -- Empyrean Power     (326733)
 85804,     -- Selfless Healer    (85804)
 114250,    -- Selfless Healer    (114250)
 280373,    -- Redoubt            (280373)
 327193,    -- Moment of Glory    (327193)
 183778,    -- Judgment of Light  (183778)
 196926,    -- Cruader's Might    (196926)
 267610     -- Righteous Verdict  (267610)
);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(269569,0,10,0x00800000,0x0,0x0,0x0,0x10,1,2,0x403,0,0,0,0,0,0),    -- Zeal               (269569), Proc on judgement trigger zeal effect
(269571,1,0,0x0,0x0,0x0,0x0,0x4,1,1,0x403,0x10,14,0,0,0,0),         -- Zeal               (269571), Proc on auto attack to consume zeal effect
(326732,0,10,0x0,0x00008000,0x0,0x0,0x10,1,2,0x403,0,0,0,15,0,0),   -- Empyrean Power     (326732), Proc to trigger only on crusader strike
(326733,0,10,0x0,0x00020000,0x0,0x0,0x10,1,2,0x403,0x8,0,0,0,0,0),  -- Empyrean Power     (326733), Proc to consume Empryean Power (Divine Storm 53385)
(85804,0,10,0x0,0x0,0x0,0x0,0x15510,7,1,0x403,0x4,0,0,0,0,0),       -- Selfless Healer    (85804),  Proc on power spending abilitis
(114250,0,10,0x40000000,0x0,0x0,0x0,0x4000,2,2,0x403,0,0,0,0,0,1),  -- Selfless Healer    (114250), Proc to consume on Flash of Light (19750)
(280373,0,10,0x0,0x00100000,0x0,0x0,0x10,1,1,0,0,0,0,0,0,0),        -- Redoubt            (280373), proc to trigge from Shield of the Righteous (53600)
(327193,0,10,0x00004000,0x0,0x0,0x0,0x10000,1,1,0x403,0,0,0,0,0,0), -- Moment of Glory    (327193), proc to consume on Avenger's Shield (31935)
(183778,0,10,0x00800000,0x0,0x0,0x0,0x10,1,2,0x403,0,0,0,0,0,0),    -- Judgment of Light  (183778), proc to trigger from Judgement
(196926,0,10,0x0,0x00008000,0x0,0x0,0x10,1,2,0x403,0,0,0,0,0,0),    -- Cruader's Might    (196926), proc to trigger from Crusader Strike
(267610,0,10,0x0,0x00001000,0x0,0x0,0x10,1,2,0x403,0,0,0,0,0,0);    -- Righteous Verdict  (267610), proc to trigger from Templar's Verdict (224266)

-- Spell Areatriggers --
DELETE FROM `spell_areatrigger` WHERE (`AreaTriggerId`=9228);
INSERT INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `VerifiedBuild`) VALUES
(4488, 9228, 0, 0, 0, 0, 0, 0, 0, 0, 12000, 37474); -- for Consecration (26573)
