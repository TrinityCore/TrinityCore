-- Nature's Grasp and Inner fire, need proc only with damage. It fix wrong proc with sap.
DELETE FROM `spell_proc` WHERE `SpellId` IN (-16689,-588);
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(-16689,0,0,0,0,0,0,1,0,0,0,0,0,0,0),
(-588,0,0,0,0,0,0,1,0,0,0,0,0,0,0);
