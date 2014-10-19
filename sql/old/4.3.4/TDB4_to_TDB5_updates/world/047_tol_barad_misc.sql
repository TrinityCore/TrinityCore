UPDATE `creature_template` SET `flags_extra`=128 WHERE `entry`=47402; -- Tol Barad - The Restless Front - Quest Bunny
UPDATE `creature_template` SET `gossip_menu_id`=12419 WHERE `entry`=52015; -- Capitaine Jake Sones

-- Few quest items from armory - loot was "Guaranteed"
UPDATE `creature_template` SET `lootid`=`entry` WHERE `entry` IN (46507, 46569, 46582, 46586, 46597, 46630, 46641, 46643, 47130, 47642);
DELETE FROM `creature_loot_template` WHERE `entry` IN (46507, 46569, 46582, 46586, 46597, 46630, 46641, 46643, 47130, 47642);
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(46507, 62803, -100, 1, 0, 1, 1), -- Darkwood Broodmother
(46569, 62808, -100, 1, 0, 1, 1), -- Forgotten Ghoul
(46582, 62808, -100, 1, 0, 1, 1), -- Hungry Ghoul
(46586, 62808, -100, 1, 0, 1, 1), -- Wandering Soul
(46597, 62808, -100, 1, 0, 1, 1), -- Skeletal Beastmaster
(46630, 62811, -100, 1, 0, 1, 3), -- Accursed Longshoreman
(46641, 62811, -100, 1, 0, 1, 3), -- Ghastly Dockhand
(46643, 62811, -100, 1, 0, 1, 3), -- Accursed Shipbuilder
(47130, 62921, -100, 1, 0, 1, 3), -- Crazed Guard
(47642, 63047, -100, 1, 0, 3, 5); -- Rustberg Fisherman

DELETE FROM `pool_template` WHERE `entry` IN (372, 373, 374, 375, 376, 377, 378, 379);
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(372, 2, 'Commander Marcus Johnson - Daily Quests'),
(373, 2, 'Lieutenant Farnsworth - Daily Quests'),
(374, 2, 'Sergeant Gray - Daily Quests'),
(375, 2, 'Camp Coordinator Brack - Daily Quests'),
(376, 2, 'Commander Larmash - Daily Quests'),
(377, 2, '3rd Officer Kronkar - Daily Quests'),
(378, 2, 'Private Sarlosk - Daily Quests'),
(379, 2, 'Captain Prug - Daily Quests');

DELETE FROM `pool_quest` WHERE `entry` IN (27944, 27948, 27949, 27966, 27967, 27970, 27971, 27972, 27973, 27975, 27978, 27987, 27991, 27992, 28046, 28050, 28059, 28063, 28065, 28130, 28137, 28275, 28678, 28679, 28680, 28681, 28682, 28683, 28684, 28685, 28686, 28687, 28689, 28690, 28691, 28692, 28693, 28694, 28695, 28696, 28697, 28698, 28700, 28721);
INSERT INTO `pool_quest` (`entry`, `pool_entry`, `description`) VALUES
(28059, 372, 'Claiming The Keep'),
(28063, 372, 'Leave No Weapon Behind'),
(28065, 372, 'Walk A Mile In Their Shoes'),
(28130, 372, 'Not The Friendliest Town'),
(28137, 372, 'Teach A Man To Fish.... Or Steal'),
(27949, 373, 'The Forgotten'),
(27966, 373, 'Salvaging the Remains'),
(27967, 373, 'First Lieutenant Connor'),
(27992, 373, 'Magnets, How Do They Work?'),
(28046, 373, 'Finish The Job'),
(27973, 374, 'Watch Out For Splinters!'),
(27975, 374, 'WANTED: Foreman Wellson'),
(27978, 374, 'Ghostbuster'),
(27987, 374, 'Cannonball!'),
(27991, 374, 'Taking the Overlook Back'),
(28275, 374, 'Bombs Away!'),
(27944, 375, 'Thinning the Brood'),
(27948, 375, 'A Sticky Task'),
(27970, 375, 'Captain P. Harris'),
(27971, 375, 'Rattling Their Cages'),
(27972, 375, 'Boosting Morale'),
(28050, 375, 'Shark Tank'),
(28682, 376, 'Claiming The Keep'),
(28685, 376, 'Leave No Weapon Behind'),
(28686, 376, 'Not The Friendliest Town'),
(28687, 376, 'Teach A Man To Fish.... Or Steal'),
(28721, 376, 'Walk A Mile In Their Shoes'),
(28678, 377, 'Captain P. Harris'),
(28679, 377, 'Rattling Their Cages'),
(28680, 377, 'Boosting Morale'),
(28681, 377, 'Shark Tank'),
(28683, 377, 'Thinning the Brood'),
(28684, 377, 'A Sticky Task'),
(28694, 378, 'Watch Out For Splinters!'),
(28695, 378, 'WANTED: Foreman Wellson'),
(28696, 378, 'Bombs Away!'),
(28697, 378, 'Ghostbuster'),
(28698, 378, 'Cannonball!'),
(28700, 378, 'Taking the Overlook Back'),
(28689, 379, 'The Forgotten'),
(28690, 379, 'Salvaging the Remains'),
(28691, 379, 'First Lieutenant Connor'),
(28692, 379, 'Magnets, How Do They Work?'),
(28693, 379, 'Finish The Job');
