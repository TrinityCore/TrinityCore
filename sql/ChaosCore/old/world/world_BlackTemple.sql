-- ++++ Prequest ++++
-- Title ID
update quest_template set CharTitleId = 64 where entry = 10985;
-- Einige Anpassungen
UPDATE `creature_template` SET scriptname = 'npc_xiri' where entry = 18528;

-- ***********
-- ++++ Trashmobs++++
-- ***********
update creature_template set scriptname = 'npc_black_temple' where entry = 22878;
UPDATE `creature_template` SET `mechanic_immune_mask` = 648249343 WHERE `entry` = 22878;
update creature_template set scriptname = 'npc_black_temple' where entry = 22883;
update creature_template set scriptname = 'npc_black_temple' where entry = 22873;
UPDATE `creature_template` SET `mechanic_immune_mask` = 111362047 WHERE `entry` = 22873;
update creature_template set scriptname = 'npc_black_temple' where entry = 22877;
update creature_template set scriptname = 'npc_black_temple' where entry = 22884;
update creature_template set scriptname = 'npc_black_temple' where entry = 22875;
UPDATE `creature_template` SET `mechanic_immune_mask` = 33561923 WHERE `entry` = 22875;
update creature_template set minlevel = 73  , maxlevel = 73  , faction_A = 1813  , faction_H = 1813  , unit_flags = 33554434, scriptname = 'mob_coilskar_geyser' where entry = 23080;
update creature_template set scriptname = 'npc_black_temple' where entry = 22876;
update creature_template set scriptname = 'npc_black_temple' where entry = 22885;
update creature_template set scriptname = 'npc_black_temple' where entry = 22874;
update creature_template set scriptname = 'npc_black_temple' where entry = 23028;
update creature_template set scriptname = 'npc_black_temple' where entry = 22963;
update creature_template set scriptname = 'npc_black_temple' where entry = 23030;
update creature_template set scriptname = 'npc_black_temple' where entry = 23330;
update creature_template set scriptname = 'npc_black_temple' where entry = 22960;
UPDATE `creature_template` SET `mechanic_immune_mask` = 614678523 WHERE `entry` = 22960;
update creature_template set scriptname = 'npc_black_temple' where entry = 22954;
update creature_template set scriptname = 'npc_black_temple' where entry = 22855;
update creature_template set scriptname = 'npc_black_temple' where entry = 22844;
update creature_template set scriptname = 'npc_black_temple' where entry = 22849;
update creature_template set scriptname = 'npc_black_temple' where entry = 22847;
update creature_template set scriptname = 'npc_black_temple' where entry = 22845;
update creature_template set scriptname = 'npc_black_temple' where entry = 22896;
update creature_template set scriptname = 'npc_black_temple' where entry = 22894;
update creature_template set scriptname = 'npc_black_temple' where entry = 23374;
update creature_template set scriptname = 'npc_black_temple' where entry = 22846;
update creature_template set scriptname = 'npc_black_temple' where entry = 22848;
update creature_template set scriptname = 'npc_black_temple' where entry = 23337;
update creature_template set scriptname = 'npc_black_temple' where entry = 22853;
UPDATE `creature_template` SET `mechanic_immune_mask` = 33554689 WHERE `entry` = 22853;
update creature_template set scriptname = 'npc_black_temple' where entry = 23339;
update creature_template set scriptname = 'npc_black_temple' where entry = 22869;
update creature_template set scriptname = "npc_black_temple" where entry = 22957;
update `creature_template` SET `minlevel` = 72  , `maxlevel` = 72  , `faction_A` = 1813  , `faction_H` = 1813 WHERE `entry` = 23436;
update creature_template set scriptname = "npc_black_temple" where entry = 22962;
update creature_template set scriptname = 'npc_black_temple' where entry = 22956;
update creature_template set scriptname = 'npc_black_temple' where entry = 22964;
update creature_template set scriptname = 'npc_black_temple' where entry = 22955;
update creature_template set scriptname = 'npc_black_temple' where entry = 22939;
update creature_template set scriptname = 'npc_black_temple' where entry = 22965;
update creature_template set scriptname = 'npc_black_temple' where entry = 22959;

update creature_template set scriptname = 'npc_black_temple' where entry = 23399;
update creature_template set scriptname = 'npc_black_temple' where entry = 23398;
update creature_template set scriptname = 'npc_black_temple' where entry = 23401;

update creature_template set scriptname = 'npc_black_temple' where entry = 23402;
update creature_template set scriptname = 'npc_black_temple' where entry = 23397;
update creature_template set scriptname = 'npc_black_temple' where entry = 23403;
update creature_template set scriptname = 'npc_black_temple' where entry = 23400;
update creature_template set scriptname = 'npc_black_temple' where entry = 23394;
update creature_template set scriptname = 'npc_black_temple' where entry = 23429;
update `creature_template` SET `minlevel` = 72  , `maxlevel` = 72  , `faction_A` = 16  , `faction_H` = 16, `unit_flags` = 33554818 WHERE `entry` = 23429;

update creature_template set scriptname = 'npc_black_temple' where entry = 23172;
update creature_template set scriptname = 'npc_black_temple' where entry = 22945;
update creature_template set scriptname = 'npc_black_temple' where entry = 23047;
update creature_template set scriptname = 'npc_black_temple' where entry = 22879;
update spell_proc_event set procFlags = 131072, procEx = 0 where entry = 41034;
update creature_template set scriptname = 'npc_black_temple' where entry = 22882;
update creature_template set scriptname = 'npc_black_temple' where entry = 22880;
update creature_template set scriptname = 'npc_black_temple' where entry = 23369;
update `creature_template` SET `minlevel` = 72  , `maxlevel` = 72  , `faction_A` = 1813  , `faction_H` = 1813 WHERE `entry` = 23436;
update creature_template set scriptname = 'npc_black_temple' where entry = 23018;
update creature_template set scriptname = 'npc_black_temple' where entry = 23083;
update creature_template set scriptname = 'npc_black_temple' where entry = 22953;
update creature_template set scriptname = 'npc_black_temple' where entry = 23049;
delete from creature_loot_template where item in (32609,32592,32591,32590,32589,32526) and entry = 23147;
update creature_template set scriptname = 'npc_black_temple' where entry = 23196;
delete from spell_scripts where id = 41213;
insert into spell_scripts (id,delay,command,datalong) values (41213,0,15,41214);
update creature_template set scriptname = 'npc_black_temple' where entry = 23236;
update creature_template set scriptname = 'npc_black_temple' where entry = 23235;
update creature_template set scriptname = 'npc_black_temple' where entry = 23237;
update creature_template set scriptname = 'npc_black_temple' where entry = 23232;
update creature_template set scriptname = 'npc_black_temple' where entry = 23222;
update creature_template set scriptname = 'npc_black_temple' where entry = 23239;
update creature_template set scriptname = 'npc_black_temple' where entry = 23223;

-- Scriptnames
update creature_template set scriptname = 'blade_of_azzinoth' where entry = 22996;
UPDATE `creature_template` SET `ScriptName`='npc_fel_geyser' WHERE `entry`=23254;
