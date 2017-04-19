
-- Franclorn Forgewright
SET @ENTRY := 8888;
UPDATE `creature_template` SET `npcflag`=`npcflag`&~0x8000 WHERE `entry`=@ENTRY;

-- Gaeriyan
SET @ENTRY := 9299;
UPDATE `creature_template` SET `npcflag`=`npcflag`&~0x8000 WHERE `entry`=@ENTRY;
UPDATE `creature_template_addon` SET `auras`='10848' WHERE `entry`=@ENTRY;

-- Shroud of Death Spell
DELETE FROM `spell_script_names` WHERE spell_id=10848;
INSERT INTO `spell_script_names` VALUES(10848, 'spell_gen_shroud_of_death');
