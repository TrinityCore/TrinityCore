UPDATE `creature_template` SET `unit_flags`='0',`mechanic_immune_mask`='650854399',`ScriptName`='npc_generic_gate_add' WHERE `entry`='69175'; 
UPDATE `creature_template` SET `unit_flags`='0',`mechanic_immune_mask`='650854399',`ScriptName`='npc_generic_gate_add' WHERE `entry`='69173';
UPDATE `creature_template` SET `unit_flags`='0',`mechanic_immune_mask`='650854399',`ScriptName`='npc_generic_gate_add' WHERE `entry`='69172'; 
UPDATE `creature_template` SET `unit_flags`='0',`mechanic_immune_mask`='650854399',`ScriptName`='npc_generic_gate_add' WHERE `entry`='69164'; 
UPDATE `creature_template` SET `unit_flags`='0',`mechanic_immune_mask`='650854399',`ScriptName`='npc_generic_gate_add' WHERE `entry`='69314';
UPDATE `creature_template` SET `unit_flags`='0',`mechanic_immune_mask`='650854399',`ScriptName`='npc_generic_gate_add' WHERE `entry`='69167'; 
UPDATE `creature_template` SET `unit_flags`='0',`mechanic_immune_mask`='650854399',`ScriptName`='npc_generic_gate_add' WHERE `entry`='69178';
UPDATE `creature_template` SET `unit_flags`='0',`mechanic_immune_mask`='650854399',`ScriptName`='npc_generic_gate_add' WHERE `entry`='69185'; 
UPDATE `creature_template` SET `unit_flags`='0',`mechanic_immune_mask`='650854399',`ScriptName`='npc_generic_gate_add' WHERE `entry`='69184'; 
UPDATE `creature_template` SET `unit_flags`='0',`mechanic_immune_mask`='650854399',`ScriptName`='npc_generic_gate_add' WHERE `entry`='69177'; 
UPDATE `creature_template` SET `unit_flags`='0',`mechanic_immune_mask`='650854399',`ScriptName`='npc_generic_gate_add' WHERE `entry`='69176'; 
UPDATE `creature_template` SET `unit_flags`='0',`mechanic_immune_mask`='650854399',`ScriptName`='npc_generic_gate_add' WHERE `entry`='69168'; 
UPDATE `creature_template` SET `unit_flags`='0',`mechanic_immune_mask`='650854399',`ScriptName`='npc_generic_gate_add' WHERE `entry`='69169';
UPDATE `creature_template` SET `unit_flags`='0',`mechanic_immune_mask`='650854399',`ScriptName`='npc_zandalari_dinomancer' WHERE `entry`='69221';
UPDATE `creature_template` SET `ScriptName`='npc_sand_trap' WHERE `entry`='69346';
UPDATE `creature_template` SET `ScriptName`='npc_living_poison' WHERE `entry`='69313';
UPDATE `creature_template` SET `ScriptName`='npc_lightning_nova_totem' WHERE `entry`='69215';
UPDATE `gameobject_template` SET `data10`='0',`ScriptName`='go_orb_of_control' WHERE `entry`='218374';
INSERT INTO `creature_template` (`entry`,`KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `exp_unk`, `faction`, `npcflag`, `npcflag2`, `speed_walk`, `speed_run`, `speed_fly`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `Health_mod`, `Mana_mod`, `Mana_mod_extra`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `VignetteId`, `flags_extra`, `ScriptName`, `WDBVerified`) values('90010','0','0','11686','0','0','0','Horridon Gate Controller','','','0','95','95','4','0','14','0','0','6','2.14286','1.14286','1','0','0','0','0','0','1','2000','2000','1','33554432','2099200','0','0','0','0','0','0','0','0','0','10','17826816','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','','0','7','1','1','1','1','1','0','0','0','0','0','0','0','197','1','0','0','0','0','npc_horridon_gate_controller','1');
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `isActive`) values(NULL ,'90010','1098','6622','6705','16632','1','0','0','5428.45','5748.39','129.605','1.51679','604800','0','0','466730','1000','0','0','0','0','0','0');
INSERT INTO `vehicle_template_accessory` (`EntryOrAura`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) values('69177','69176','0','8','Amani Warbear','6','30000');
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) values('69177','65343','0','0');


 
 
