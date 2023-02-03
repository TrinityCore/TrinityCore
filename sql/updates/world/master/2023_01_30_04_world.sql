-- Delete old portal to Blasted lands / Hellfire Peninsula
DELETE FROM `gameobject` WHERE `guid` IN (218904, 211298);

-- Update NPCflag for Winaestra
UPDATE `creature_template` SET `npcflag`=129 WHERE `entry`=16264; -- Winaestra
