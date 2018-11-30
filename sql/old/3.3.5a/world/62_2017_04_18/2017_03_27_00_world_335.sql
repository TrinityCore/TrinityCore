
-- Franclorn Forgewright
SET @ENTRY := 8888;
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|0x400 WHERE `entry`=@ENTRY;

-- Gaeriyan
SET @ENTRY := 9299;
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|0x400 WHERE `entry`=@ENTRY;

-- Shroud of Death Spell
DELETE FROM `spell_script_names` WHERE spell_id=10848;
