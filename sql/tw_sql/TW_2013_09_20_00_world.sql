DELETE FROM `creature` WHERE `guid` IN (400000); -- Spawn Coren Direbrew
INSERT INTO `creature` (`guid`,`id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) VALUES
('400000','23872','230','1','1','0','0','890.931','-130.817','-49.7464','5.22232','86400','0','0','302400','0','0');

UPDATE `creature_template` SET `npcflag`=3,`faction_A`=35,`faction_H`=35,`ScriptName`='npc_coren_direbrew',`flags_extra`=0 WHERE `entry` = 23872;
UPDATE `creature_template` SET `ScriptName` = 'npc_brewmaiden' WHERE `entry` IN (26822,26764);
