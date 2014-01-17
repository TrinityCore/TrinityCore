UPDATE `creature_template` SET `npcflag`=`npcflag`|16777216 WHERE `entry` IN (27894,28781,30234,33062); -- match npcflag with diffentries (that got updated on 2011_02_28_7)
UPDATE `creature_template` SET `VehicleId`=335 WHERE `entry`=34045; -- Salvaged Chopper (1)
UPDATE `creature_template` SET `VehicleId`=335 WHERE `entry`=31748; -- Hover Disk (1)
