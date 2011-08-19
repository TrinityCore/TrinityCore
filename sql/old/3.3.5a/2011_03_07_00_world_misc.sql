UPDATE `creature_template_addon` SET `auras`=NULL WHERE `entry` IN (36558,35644); -- Argent mounts inside ToC5 shouldn't have any aura (for now)
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=36477; -- Krick isn't a vehicle
DELETE FROM `achievement_reward` WHERE `entry` IN (4784,4785); -- Revert Emblematic achiev rewards
UPDATE `creature_template` SET `faction_A`=35,`faction_H`=35 WHERE `entry`=35644; -- Argent Warhorse (faction depends on the players faction that starts ToC5 fight)
