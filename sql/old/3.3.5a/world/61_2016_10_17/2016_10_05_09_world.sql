DELETE FROM `spell_proc` WHERE `SpellId` = -12317;
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(-12317, 0, 0, 0, 0, 0, 0, 0x1, 0, 0, 0, 0, 0, 0, 0);

UPDATE `spell_proc` SET `SpellTypeMask`=0x1 WHERE `SpellId` IN (
-29723, -- Sudden Death
71903,  -- Item - Shadowmourne Legendary
71540,  -- Item - Icecrown 10 Heroic Melee Trinket
71402,  -- Item - Icecrown 10 Normal Melee Trinket
72413,  -- Item - Icecrown Reputation Ring Melee
75455,  -- Item - Chamber of Aspects 25 Melee Trinket
75457,  -- Item - Chamber of Aspects 25 Heroic Melee Trinket
71404,  -- Item - Icecrown Dungeon Melee Trinket
67702,  -- Item - Coliseum 25 Normal Melee Trinket
67771,  -- Item - Coliseum 25 Heroic Melee Trinket
67672,  -- Coliseum 5 Melee Trinket
65013,  -- Pyrite Infusion
65020,  -- Mjolnir Runestone
65025,  -- Dark Matter
64786,  -- Comet's Trail
61618  -- Tentacles
);
