-- Vehicle and summon spell(summon npc 28788) for Acherus Deathcharger
UPDATE creature_template SET `spell1`=52362, `VehicleId`=200 WHERE `entry`=28782;

-- ScriptName for dark rider
UPDATE creature_template SET `ScriptName`='npc_ros_dark_rider' WHERE `entry`=28768;

-- Spellclick spell to mount deathcharger
DELETE FROM npc_spellclick_spells WHERE `npc_entry`=28782;
INSERT INTO npc_spellclick_spells (`npc_entry`, `spell_id`, `quest_id`, `quest_status`, `cast_flags`) VALUES
(28782, 52280, 12687, 3, 1);