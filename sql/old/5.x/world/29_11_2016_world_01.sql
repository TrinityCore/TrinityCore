SET @SI_ENTRY = 49869;
SET @BBW_ENTRY = 49871;
SET @MMCB_ENTRY = 197;
SET @H_ENTRY = 448;
SET @BUNNY_ENTRY = 45979;
SET @SIS_ENTRY = 50047;

UPDATE `creature` SET `MovementType`=0,`spawndist`=0 WHERE `id`=@H_ENTRY;
UPDATE `creature` SET `MovementType`=0,`spawndist`=0 WHERE `id`=@BUNNY_ENTRY;
DELETE FROM `creature_template_addon` WHERE `entry` = @BUNNY_ENTRY;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(@BUNNY_ENTRY, 0, 0, 0, 1, 0, '88755');
UPDATE `creature_template` SET `AIName`="" WHERE `entry`=@SIS_ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SIS_ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SIS_ENTRY*100 AND `source_type`=9;
UPDATE `creature_template` SET `AIName`="", `scriptname`="npc_hogger" WHERE `entry`=@H_ENTRY;
UPDATE `creature_template` SET `scriptname`="npc_blackrock_battle_worg" WHERE `entry`=@BBW_ENTRY;
UPDATE `creature_template` SET `AIName`="", `scriptname`="npc_marshal_mcbride" WHERE `entry`=@MMCB_ENTRY;
DELETE FROM `creature_text` WHERE `entry` IN (@SI_ENTRY, @MMCB_ENTRY, @H_ENTRY, @SIS_ENTRY);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(@SI_ENTRY, 1, 0, 'Come, monsters! We will crush you!', 14, 0, 100, 0, 0, 0, 'Stormwind Infantry - Yell'),
(@SI_ENTRY, 1, 1, 'I\'ll kill a hundred more of your battle worgs!', 14, 0, 100, 0, 0, 0, 'Stormwind Infantry - Yell'),
(@SI_ENTRY, 1, 2, 'Look alive, men! There are orcs and worgs about!', 14, 0, 100, 0, 0, 0, 'Stormwind Infantry - Yell'),
(@SI_ENTRY, 1, 3, 'Your filthy dogs won\'t be enough!', 14, 0, 100, 0, 0, 0, 'Stormwind Infantry - Yell'),
(@SI_ENTRY, 1, 4, 'Your worgs are no match for the might of Stormwind!', 14, 0, 100, 0, 0, 0, 'Stormwind Infantry - Yell'),
(@MMCB_ENTRY, 0, 0, 'You are dismissed, $N.', 12, 0, 100, 113, 0, 0, 'Marshal McBride');
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=@SIS_ENTRY;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(@SIS_ENTRY, 93072, 1, 0),
(@SIS_ENTRY, 93097, 0, 0);
DELETE FROM `creature_involvedrelation` WHERE `id` = @SIS_ENTRY;
