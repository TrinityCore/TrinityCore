DELETE FROM `npc_spellclick_spells` WHERE `spell_id` IN (52447);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `quest_start`, `quest_start_active`, `quest_end`, `cast_flags`) VALUES
(28833, 52447, 12701, 1, 12701, 1); -- Scarlet Cannon Master

UPDATE creature_template SET spell1=52435,spell2=52576,spell5=52588,VehicleId=79,speed=0 WHERE entry = 28833;
UPDATE `creature_template` SET vehicleid=138 WHERE (`entry`='28817');

UPDATE `gameobject_template` SET `ScriptName`='go_inconspicuous_mine_car' WHERE (`entry`='190767');
UPDATE `creature_template` SET `ScriptName`='npc_scarlet_miner_cart' WHERE (`entry`='28817');
UPDATE `creature_template` SET `ScriptName`='npc_scarlet_miner' WHERE (`entry`='28841');
