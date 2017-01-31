DELETE FROM `creature_equip_template` WHERE `itemEntry3` IN (89315, 8192, 16777215);
DELETE FROM `creature_equip_template` WHERE `itemEntry2`=43171;

-- Other spells were wrong
DELETE FROM `npc_trainer` WHERE `entry`=200301;
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES
(200301, 34092, 2500000, 762, 150, 60), -- Expert Riding
(200301, 33392, 500000, 762, 75, 40), -- Journeyman Riding
(200301, 33389, 40000, 0, 0, 20), -- Apprentice Riding
(200301, 34093, 50000000, 762, 225, 70), -- Artisan Riding
(200301, 54198, 5000000, 762, 225, 68), -- Cold Weather Flying
(200301, 90269, 2500000, 762, 225, 60), -- Flight Master's License
(200301, 90266, 50000000, 762, 300, 80); -- Master Riding

UPDATE `creature_template` SET `npcflag`=49 WHERE `entry` IN (16279, 16679, 16680, 43004, 49793);
UPDATE `creature_template` SET `npcflag`=51 WHERE `entry` IN (16681, 3033, 3034, 43870);
UPDATE `creature_template` SET `npcflag`=81 WHERE `entry`=19180;
