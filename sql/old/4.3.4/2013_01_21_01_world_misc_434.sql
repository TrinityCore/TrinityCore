-- NPC Hira Snowdawn no longer sells Tome of Cold Weather Flight
UPDATE `creature_template` SET `ScriptName`='' WHERE `entry`=31238;
DELETE FROM `gossip_menu_option` WHERE `menu_id`=10723 AND `id`=1;
DELETE FROM `npc_vendor` WHERE `entry`=31238 AND `item`=49177;
