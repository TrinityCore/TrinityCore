-- Delete all existing Rockjaw Invader spawns
DELETE FROM `creature` WHERE `id`=37070;
-- Add coin to Rockjaw Invader
UPDATE `creature_template_difficulty` SET `GoldMin`=1, `GoldMax`=7 WHERE `Entry`=37070;
-- Prevent Coldridge Mountaineer from entering combat with Rockjaw Invaders
UPDATE `creature_template` SET `flags_extra`=2 WHERE `entry`=853;
-- Add Script to Joren Ironstock
UPDATE `creature_template` SET `ScriptName`='npc_joren_ironstock' WHERE `entry`=37081;

-- Add spairing to Rockjaw Invaders, Coldridge Defenders, and Joren Ironstock
DELETE FROM `creature_template_sparring` WHERE `Entry` IN (37070,37177,37081);
INSERT INTO `creature_template_sparring` (`Entry`,`NoNPCDamageBelowHealthPct`) VALUES
(37070,85),
(37177,85),
(37081,85);
