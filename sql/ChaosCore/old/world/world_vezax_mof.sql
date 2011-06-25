UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask` &~ 1024 WHERE `entry` IN (33113,34003);
DELETE FROM `spell_script_names` WHERE `spell_id`=63278;
INSERT INTO `spell_script_names` VALUE (63278, 'spell_general_vezax_mark_of_the_faceless_drain');