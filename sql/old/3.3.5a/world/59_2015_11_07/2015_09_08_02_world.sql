--
UPDATE `creature_template` SET `type_flags`=`type_flags`|134217728  WHERE `npcflag`>16 AND `gossip_menu_id`!= 0;
