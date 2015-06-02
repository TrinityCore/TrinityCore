--
UPDATE `npc_text` SET `text0_0`="$N, you are ready for the ultimate task.  The fiery runes etched on the floor of the molten core are conduits to the realm of fire, and their presence is both an affront to us and a source of power for the Firelords.  They must be extinguished!$B$BTo extinguish a rune, take a vial of aqual quintessence.  Pour it on the rune and its flame will go out, rendering it useless and weakening our enemy!", `BroadcastTextID0`=8703 WHERE `id`=6158;
DELETE FROM `gossip_menu` WHERE `entry`=5032;
UPDATE `creature_template` SET `npcflag`=2, `gossip_menu_id`=0 WHERE `entry`=241; 

UPDATE `creature_template` SET `gossip_menu_id`=11611 WHERE `entry`=240;
DELETE FROM `gossip_menu` WHERE `entry`=6159;
DELETE FROM `npc_text` WHERE `ID`=6157;
