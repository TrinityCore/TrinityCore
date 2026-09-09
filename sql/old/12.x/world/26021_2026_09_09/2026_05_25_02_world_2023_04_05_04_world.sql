-- Ritual Channeler immune to stuns
DELETE FROM `creature_immunities` WHERE `ID`=-205;
INSERT INTO `creature_immunities`
SELECT -205,`SchoolMask`,`DispelTypeMask`,`MechanicsMask`|4096,`Effects`,`Auras`,`ImmuneAoE`,`ImmuneChain`,`Comment`
FROM `creature_immunities` WHERE `ID`=-71;

UPDATE `creature_template` SET `CreatureImmunitiesId`=-205 WHERE `entry` IN (27281,30804);
