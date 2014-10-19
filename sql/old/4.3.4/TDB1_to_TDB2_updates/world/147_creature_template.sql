-- Fix Trainer flags
UPDATE `creature_template` SET `npcflag`=83 WHERE `entry`=7406; -- Oglethorpe Obnoticus
UPDATE `creature_template` SET `npcflag`=83 WHERE `entry`=7944; -- Tinkmaster Overspark
UPDATE `creature_template` SET `npcflag`=81 WHERE `entry`=8126; -- Nixx Sprocketspring
UPDATE `creature_template` SET `npcflag`=81 WHERE `entry`=8738; -- Vazario Linkgrease


-- Fix some incorrect gossips flags
UPDATE `gossip_menu_option` SET `option_id`=5, `npc_option_npcflag`=16 WHERE `option_text` LIKE '%Train me%' OR `option_text` LIKE '%the ways of the Light%';
