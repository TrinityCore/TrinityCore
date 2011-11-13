-- Template updates for creature 30560 (The RP-GG)
UPDATE `creature_template` SET `npcflag`=`npcflag`|16777216 WHERE `entry`=30560; -- The RP-GG
-- Addon data for creature 30560 (The RP-GG)
DELETE FROM `creature_template_addon` WHERE `entry`=30560;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(30560,0,0,1,0, NULL); -- The RP-GG
 
-- Fixing spawntime for creature 30560 (The RP-GG)
UPDATE `creature` SET `spawntimesecs`=60 WHERE `id`=30560;

-- Spellclick data for creature 30560 (The RP-GG)
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=30560;
INSERT INTO `npc_spellclick_spells` VALUES
(30560,57347,0,0,0,1,0,57348,1);
