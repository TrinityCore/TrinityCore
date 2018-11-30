-- Captain Nials
UPDATE `creature_template` SET `npcflag`=2, `gossip_menu_id`=0 WHERE `entry`=2700;

UPDATE `smart_scripts` SET `action_param1`=2 WHERE `entryorguid`=270000 AND `source_type`=9 AND `id` IN (0,9);

-- Skuerto
UPDATE `creature_template` SET `npcflag`=2, `gossip_menu_id`=0 WHERE `entry`=2789;

-- Apprentice Kryten
-- DELETE FROM `gossip_menu` WHERE `MenuID`=2601 AND `TextID`=3294;

-- Navigator Mehran
UPDATE `npc_text` SET `em0_0`=0, `em0_1`=274 WHERE `ID`=12209;

-- Restless Apparition
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=23861;
