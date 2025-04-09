-- Remove bleed immunity from some npc
UPDATE `creature_template` SET `CreatureImmunitiesId`=0 WHERE `entry` IN (
36, -- Harvest Golem
114, -- Harvest Watcher
19166, -- Tempest-Forge Patroller
4952, -- Theramore Combat Dummy
4957); -- Theramore Combat Dummy 4

UPDATE `creature_immunities` SET `MechanicsMask`=`MechanicsMask`&~32768 WHERE `ID` IN (-134,-204);

UPDATE `creature_template` SET `CreatureImmunitiesId`=-183 WHERE `entry`=20041; -- Crystalcore Sentinel
