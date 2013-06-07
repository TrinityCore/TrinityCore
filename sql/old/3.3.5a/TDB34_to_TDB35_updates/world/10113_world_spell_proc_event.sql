-- Allow any mage spell to drop Fingers of Frost charge
UPDATE `spell_proc_event` SET `SchoolMask` = 0x54, `SpellFamilyMask0` = 0x28E212F7, `SpellFamilyMask1` = 0x00119048 WHERE `entry` = 74396;

-- Let Nature's Grace proc only from non-periodic magic spells
UPDATE `spell_proc_event` SET `SchoolMask` = 0x48, `SpellFamilyName` = 7, `SpellFamilyMask0` = 0x00000067, `SpellFamilyMask1` = 0x03800002 WHERE `entry` IN (16880, 61345, 61346);
