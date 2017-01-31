DELETE FROM `creature_queststarter` WHERE `id` IN (39679,39698,39700,39705,40855,41530);
UPDATE `creature_template` SET `AIName`='',`ScriptName`='boss_corla' WHERE `entry`=39679;
UPDATE `creature_template` SET `AIName`='',`ScriptName`='boss_karsh_steelbender' WHERE `entry`=39698;
UPDATE `creature_template` SET `AIName`='',`ScriptName`='boss_beauty' WHERE `entry`=39700;
UPDATE `creature_template` SET `AIName`='',`ScriptName`='boss_ascendant_lord_obsidius' WHERE `entry`=39705;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (53517,44764,44731);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(53517, 99325, 1, 0),
(44764, 86807, 1, 0),
(44731, 86807, 1, 0);
