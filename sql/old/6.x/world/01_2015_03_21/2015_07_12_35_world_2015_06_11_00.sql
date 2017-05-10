-- Set correct npcflag for NPC ID 21283, Megzeg Nukklebust
-- He is neither a vendor nor repair NPC
UPDATE `creature_template` SET `npcflag` = 3 WHERE `entry`= 21283;
UPDATE `creature_template_addon` SET `bytes2` = 257 WHERE `entry`= 21283;
