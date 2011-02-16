-- fix Junkboxes Needed quest available for all classes
UPDATE `quest_template` SET `ZoneOrSort` = '0'  WHERE `entry` = '8249';

-- fix mobs aggro for keldelar quest npc
UPDATE `quest_template` SET `SrcSpell` = '70974' WHERE `entry` =20439;
UPDATE `creature_template` SET `flags_extra` = '2' WHERE `entry` = 31885;
UPDATE `creature_template` SET `flags_extra` = '2' WHERE `entry` = 31886;
UPDATE `creature_template` SET `flags_extra` = '2' WHERE `entry` = 31557;
UPDATE `creature_template` SET `flags_extra` = '2' WHERE `entry` = 32419;
UPDATE `creature_template` SET `flags_extra` = '2' WHERE `entry` = 32420;
UPDATE `creature_template` SET `flags_extra` = '2' WHERE `entry` = 32253;
UPDATE `creature_template` SET `flags_extra` = '2' WHERE `entry` = 32415;
UPDATE `creature_template` SET `flags_extra` = '2' WHERE `entry` = 32412;
UPDATE `creature_template` SET `flags_extra` = '2' WHERE `entry` = 32251;
UPDATE `creature_template` SET `flags_extra` = '2' WHERE `entry` = 32252;

UPDATE `quest_template` SET `SrcSpell` = '70972' WHERE `entry` =24451;
UPDATE `creature_template` SET `flags_extra` = '2' WHERE `entry` = 35507;
UPDATE `creature_template` SET `flags_extra` = '2' WHERE `entry` = 31580;
UPDATE `creature_template` SET `flags_extra` = '2' WHERE `entry` = 31579;
UPDATE `creature_template` SET `flags_extra` = '2' WHERE `entry` = 35494;
UPDATE `creature_template` SET `flags_extra` = '2' WHERE `entry` = 37942;
UPDATE `creature_template` SET `flags_extra` = '2' WHERE `entry` = 33964;  
