-- areatrigger for the shadow throne
delete from `areatrigger_scripts` where `entry` = 5605
insert into `areatrigger_scripts` (`entry`,`scriptname`) values (5605,'at_shadow_throne');

-- jaina's equipment
delete from `creature_equip_template` where `entry` = 36955 and `id` = 1
insert into `creature_equip_template` (`entry`, `id`, `itementry1`, `itementry2`,`itementry3`) values (36955,1,2177,12869,0);

-- jaina's gossip menu (the same one from sylvanas)
update `creature_template` set `gossip_menu_id` = 10909 where `entry` = 36955;

-- jaina's scriptai part 2
update `creature_template` set `ScriptName` = 'npc_jaina_or_sylvanas_escape_hor' where `entry` = 36955;

-- Sylvanas scriptai part 2
update `creature_template` set `ScriptName` = 'npc_jaina_or_sylvanas_escape_hor' where `entry` = 37554;

-- Raging Gnoul scriptai
update `creature_template` set `ScriptName` = 'npc_raging_gnoul' where `entry` = 36940;

-- Risen Witch Doctor scriptai
update `creature_template` set `ScriptName` = 'npc_risen_witch_doctor' where `entry` = 36941;

-- Lumbering Abomination scriptai
update `creature_template` set `ScriptName` = 'npc_lumbering_abomination' where `entry` = 37069;

-- Spell Curse of Doom Witch Doctor
delete from `spelldifficulty_dbc` where `id` in (70144,70144);
insert into `spelldifficulty_dbc`(`id`,`spellid0`,`spellid1`) values (70144,70144,70183);

-- Spell Shadow Bolt Volley Witch Doctor
delete from `spelldifficulty_dbc` where `id` in (70145,70145);
insert into `spelldifficulty_dbc`(`id`,`spellid0`,`spellid1`) values (70145,70145,70184);

-- Spell Shadow Bolt Witch Doctor
delete from `spelldifficulty_dbc` where `id` in (70080,70080);
insert into `spelldifficulty_dbc`(`id`,`spellid0`,`spellid1`) values (70080,70080,70182);
